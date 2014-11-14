/*
 *  rimWorkerThread.h
 *  Rim Threads
 *
 *  Created by Carl Schissler on 10/31/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_WORKER_THREAD_H
#define INCLUDE_RIM_WORKER_THREAD_H


#include "rimThreadsConfig.h"


#include "rimBasicThread.h"
#include "rimMutex.h"


//##########################################################################################
//***************************  Start Rim Threads Namespace  ********************************
RIM_THREADS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which creates a thread that performs a series of jobs.
/**
  * A worker thread is a thread that runs in the background until a job is submitted
  * to it. At this point it starts executing the job (a function object) on its thread.
  * After the job is finished, the worker thread checks to see if there are any more
  * jobs available. If so, it continues processing. Otherwise, it goes to sleep
  * until a new job is added.
  */
class WorkerThread : public BasicThread
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new worker thread object with no jobs queued.
			WorkerThread();
			
			
			
			
			/// Create a copy of the specified worker thread, getting a copy of its remaining jobs.
			/**
			  * If the other worker thread is already running, the newly created worker thread
			  * starts its processing thread. Thus, both worker threads may continue to process
			  * the same jobs until they finish.
			  */
			WorkerThread( const WorkerThread& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this worker thread. The current job finishes but the remaining jobs go unprocessed.
			/**
			  * The destructor does not return until the worker thread terminates.
			  */
			~WorkerThread();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the jobs of another thread to this thread and match the thread's state.
			/**
			  * If the other worker thread is already running, the newly created worker thread
			  * starts its processing thread. Thus, both worker threads may continue to process
			  * the same jobs until they finish.
			  */
			WorkerThread& operator = ( const WorkerThread& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Worker Thread State Control
			
			
			
			
			/// Start this worker thread's processing loop, processing any queued jobs.
			RIM_INLINE void start()
			{
				BasicThread::startThread();
			}
			
			
			
			
			/// Wait for the worker thread to finish processing all of its jobs and return.
			RIM_INLINE void join()
			{
				BasicThread::joinThread();
			}
			
			
			
			
			/// Request that the worker thread should stop processing after its current job and return.
			void requestStop();
			
			
			
			
			/// Request that the worker thread should return after finishing all queued jobs.
			void requestFinish();
			
			
			
			
			/// Return whether or not the worker thread has been requested to stop processing and return.
			Bool stopIsRequested() const;
			
			
			
			
			/// Return whether or not the worker thread has been requested to finish processing and return.
			Bool finishIsRequested() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Job Accessor Methods
			
			
			
			
			/// Return the number of jobs that are currently in this work thread's job queue.
			Size getJobCount() const;
			
			
			
			
			/// Add the specified function call object to the list of jobs for this thread to perform.
			/**
			  * The given function will be called whenever the worker thread is able
			  * to execute the new job and all other jobs with higher priority have been
			  * completed. The function allows the user to specify a priority for the new job
			  * which indicates how soon this job should run. Jobs with the highest priority numbers
			  * are run first.
			  */
			void addJob( const lang::FunctionCall<void ( void* )>& job, Int priority = 1 );
			
			
			
			
			/// Clear all jobs from this worker thread.
			/**
			  * This removes all jobs that have not yet been executed from the worker thread's
			  * job queue. The job which is currently being processed is not affected.
			  */
			void clearJobs();
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Virtual Run Function
			
			
			
			
			/// The method called by BasicThread as the entry point for a new worker thread.
			virtual void run();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Job Class Declaration
			
			
			
			
			/// A class which encapsulates a single job for this worker thread.
			class Job
			{
				public:
					
					
					/// Create a new worker thread job object which runs the given function call with its priority.
					RIM_INLINE Job( const lang::FunctionCall<void ( void* )>& newJob, Int newPriority )
						:	priority( newPriority ),
							job( newJob )
					{
					}
					
					
					/// Return whether or not this job has a higher priority than another job.
					RIM_INLINE Bool operator < ( const Job& other ) const
					{
						return priority < other.priority;
					}
					
					
					/// The priority of this job.
					/**
					  * A higher priority means that the job will preempt other jobs with lower
					  * priorities.
					  */
					Int priority;
					
					
					/// A function call object specifying what job to perform on the thread.
					lang::FunctionCall<void ( void* )> job;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A queue of the jobs that this worker thread should perform, sorted by priority.
			util::PriorityQueue<Job> jobs;
			
			
			
			
			/// A mutex object used to provide thread synchronization for access to the queue of jobs.
			mutable Mutex jobMutex;
			
			
			
			
			/// A mutex used to protect the current state of the worker thread from unsafe access.
			mutable Mutex threadStateMutex;
			
			
			
			
			/// A boolean flag indicating that the user requested that this worker thread halt job processing and return.
			Bool stopRequested;
			
			
			
			
			/// A boolean flag indicating that the user requested that this worker thread finish job processing and return.
			Bool finishRequested;
			
			
			
};




//##########################################################################################
//***************************  End Rim Threads Namespace  **********************************
RIM_THREADS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_WORKER_THREAD_H
