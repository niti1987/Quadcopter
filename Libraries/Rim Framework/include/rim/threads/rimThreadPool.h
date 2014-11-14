/*
 *  ThreadPool.h
 *  Rim Threads
 *
 *  Created by Carl Schissler on 10/31/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_THREAD_POOL_H
#define INCLUDE_RIM_THREAD_POOL_H


#include "rimThreadsConfig.h"


#include "rimBasicThread.h"
#include "rimMutex.h"
#include "rimSemaphore.h"
#include "rimAtomics.h"


//##########################################################################################
//***************************  Start Rim Threads Namespace  ********************************
RIM_THREADS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which executes jobs on a set of worker threads.
class ThreadPool
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a thread pool which has no threads and no jobs queued.
			ThreadPool();
			
			
			
			
			/// Create a new thread pool which has the specified number of execution threads.
			ThreadPool( Size newNumberOfThreads );
			
			
			
			
			/// Create a thread pool with the same queued jobs and number of threads as another thread pool.
			ThreadPool( const ThreadPool& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Finish the current job being processed by each worker thread then destroy the thread pool.
			~ThreadPool();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the queued jobs of another thread pool and copy the number of threads to this thread pool.
			ThreadPool& operator = ( const ThreadPool& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Thread Management Methods
			
			
			
			
			/// Return the number of threads that are currently executing as part of this thread pool.
			Size getThreadCount() const;




			/// Set the desired number of threads that should be in this thread pool.
			void setThreadCount( Size numThreads );
			
			
			
			
			/// Add a new worker thread to this thread pool.
			void addThread();
			
			
			
			
			/// Wait for a thread to finish processing and remove it from the queue.
			void removeThread();
			
			
			
			
			/// Return the index of the thread in this thread pool corresponding to the calling thread, or -1 if no match found.
			Index getCurrentThreadIndex() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Job Management Methods
			
			
			
			
			/// Return the total number of jobs that are queued to be executed by this thread pool.
			Size getJobCount() const;
			
			
			
			
			/// Add the specified job function call to this thread pool, executing with the given priority.
			/**
			  * The method allows the user to specify an integer ID for the job, that is
			  * used to differentiate between different job sets that have different deadlines
			  * on separate threads. The user can then wait for all jobs or just jobs with that ID to finish.
			  */
			template < typename Signature >
			void addJob( const lang::FunctionCall<Signature>& job, Index jobID = 0, Int priority = 1 )
			{
				jobMutex.lock();
				
				// Find the index of this job ID in the list of of job IDs.
				Index jobIDIndex = createJobIDIndex( jobID );
				
				// Add the new job to the job queue.
				jobs.add( SortableJob( lang::Pointer<JobBase>( util::construct<Job<Signature> >( job, jobIDIndex, priority ) ) ) );
				
				// Atomically update the number of unfinished jobs.
				atomic::incrementAndRead( jobIDs[jobIDIndex].numUnfinishedJobs );
				atomic::incrementAndRead( numUnfinishedJobs );
				
				jobMutex.unlock();
				
				// Notify a worker that there is a job ready.
				jobSemaphore.up();
			}
			
			
			
			
			/// Wait for all of the jobs queued in this thread pool for the specified job ID to finish.
			void finishJob( Index jobID );
			
			
			
			
			/// Wait for all of the jobs queued in this thread pool to finish before returning.
			void finishJobs();
			
			
			
			
			/// Remove all currently queued jobs from this thread pool.
			void clearJobs();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Thread Priority Accessor Methods
			
			
			
			
			/// Return the thread priority that is used for all of the threads in this pool.
			RIM_INLINE ThreadPriority getPriority() const
			{
				return priority;
			}
			
			
			
			
			/// Set the thread priority that is used for all of the threads in this pool.
			/**
			  * The method returns whether or not the priority was successfully changed.
			  */
			Bool setPriority( const ThreadPriority& newPriority );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations
			
			
			
			
			/// A class which represents a single worker thread that is a part of this pool.
			class Worker;
			
			
			
			
			
			/// A class which represents the base class a single generic job for this thread pool.
			class JobBase
			{
				public:
					
					/// Create a new thread job object with the given priority.
					RIM_INLINE JobBase( Index newJobIDIndex, Int newPriority )
						:	jobIDIndex( newJobIDIndex ),
							priority( newPriority )
					{
					}
					
					
					/// Destroy this job.
					virtual ~JobBase()
					{
					}
					
					
					/// Execute this job on the calling thread.
					virtual void execute() = 0;
					
					
					/// Return whether or not this job has a higher priority than another job.
					RIM_INLINE Bool operator < ( const JobBase& other ) const
					{
						return priority < other.priority;
					}
					
					
					/// The priority of this job.
					/**
					  * A higher priority means that the job will preempt other jobs with lower
					  * priorities.
					  */
					Int priority;
					
					
					/// The index of this job's ID, used to group it with other jobs.
					Index jobIDIndex;
					
			};
			
			
			
			
			/// A class which encapsulates a single job for this thread pool.
			template < typename Signature >
			class Job : public JobBase
			{
				public:
					
					/// Create a new  thread job object which runs the given function call with its priority.
					RIM_INLINE Job( const lang::FunctionCall<Signature>& newJob, Index newJobIDIndex, Int newPriority )
						:	JobBase( newJobIDIndex, newPriority ),
							job( newJob )
					{
					}
					
					
					/// Execute this job on the calling thread.
					virtual void execute()
					{
						job();
					}
					
					
					/// A function call object specifying what job to perform on the thread.
					lang::FunctionCall<Signature> job;
					
					
			};
			
			
			
			
			/// A proxy object which stores a pointer to a generic job and allows sorting based on job priority.
			class SortableJob
			{
				public:
					
					/// Create a new sortable job object corresponding to the specified job.
					RIM_INLINE SortableJob( const lang::Pointer<JobBase>& newJob )
						:	job( newJob )
					{
					}
					
					/// Return whether or not this job has a higher priority than another job.
					RIM_INLINE Bool operator < ( const SortableJob& other ) const
					{
						return (*job) < (*other.job);
					}
					
					
					/// A pointer to the job which this sortable job is a part of.
					lang::Pointer<JobBase> job;
					
			};
			
			
			
			
			/// A class that keeps track of information needed for a particular job ID.
			class JobID
			{
				public:
					
					RIM_INLINE JobID( Index newJobID )
						:	jobID( newJobID ),
							numUnfinishedJobs( 0 )
					{
					}
					
					/// The ID of the job.
					Index jobID;
					
					/// The number of unfinished jobs there are for this job ID.
					Size numUnfinishedJobs;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Find and return the index of the JobID object with the given job ID, creating a new one if necessary.
			Index createJobIDIndex( Index jobID );
			
			
			
			
			/// Find and return the index of the JobID object with the given job ID.
			/**
			  * If no such job ID is found, the method returns -1.
			  */
			Index findJobIDIndex( Index jobID ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the threads that are currently part of this thread pool and are executing jobs.
			util::ArrayList<Worker*> threads;
			
			
			
			
			/// A queue of jobs to be performed by the thread pool.
			util::PriorityQueue<SortableJob> jobs;
			
			
			
			
			/// A list of the currently pending job IDs.
			util::ArrayList<JobID> jobIDs;
			
			
			
			
			/// A semaphore which counts the number of jobs that are currently queued and synchronizes job access.
			Semaphore jobSemaphore;
			
			
			
			
			/// A mutex that sychronizes access to the queue of jobs for this thread pool.
			mutable Mutex jobMutex;
			
			
			
			
			/// A mutex that sychronizes access to the list of worker threads for this thread pool.
			mutable Mutex threadMutex;
			
			
			
			
			/// The total number of queued jobs that have not yet completed.
			Size numUnfinishedJobs;
			
			
			
			
			/// The thread priority to use for all of the threads in this pool.
			ThreadPriority priority;
			
			
			
};




//##########################################################################################
//***************************  End Rim Threads Namespace  **********************************
RIM_THREADS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_THREAD_POOL_H
