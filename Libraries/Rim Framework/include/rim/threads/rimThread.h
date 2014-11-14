/*
 *  rimThread.h
 *  Rim Threads
 *
 *  Created by Carl Schissler on 11/7/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_THREAD_H
#define INCLUDE_RIM_THREAD_H


#include "rimThreadsConfig.h"


#include "rimBasicThread.h"


//##########################################################################################
//***************************  Start Rim Threads Namespace  ********************************
RIM_THREADS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that provides a function-based interface for creating threads.
template < typename Signature >
class FunctionThread : public BasicThread
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors / Destructor
			
			
			
			
			/// Create a default thread with no runnable to execute.
			RIM_INLINE FunctionThread()
				:	BasicThread(),
					function()
			{
			}
			
			
			
			
			/// Destroy and clean up the thread, stopping it if necessary.
			RIM_INLINE ~FunctionThread()
			{
				this->join();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Thread Instance Control
			
			
			
			
			/// Start the execution of a thread.
			/** 
			  * This method creates a new thread if the thread is not already running.
			  * The protected run() method of the thread class is then called. A user
			  * of the class can either constuct the thread with a runnable, 
			  * subclass Thread and override the run method, or pass a function in to be run.
			  * It is much more flexible to use a runnable or function than inheritance, 
			  * but either works equally well. if neither a runnable or function is 
			  * specified nor the run() method is overridden, then the thead does nothing.
			  * 
			  * @param runnable - a pointer to a class implementing the interface Runnable
			  */
			void start( const lang::FunctionCall<Signature>& aFunctionCall )
			{
				if ( !BasicThread::isRunning() )
				{
					function = lang::Pointer< lang::FunctionCall<Signature> >::construct( aFunctionCall );
					
					BasicThread::startThread();
				}
			}
			
			
			
			
			RIM_INLINE lang::Optional<typename lang::FunctionCall<Signature>::ReturnType> join()
			{
				BasicThread::joinThread();
				
				return returnValue;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Current Thread Control Methods
			
			
			
			
			/// Sleep the calling thread for the specified number of milliseconds.
			RIM_INLINE static void sleep( int milliseconds )
			{
				BasicThread::sleep( milliseconds );
			}
			
			
			
			
			/// Sleep the calling thread for the specified number of seconds.
			RIM_INLINE static void sleep( double seconds )
			{
				BasicThread::sleep( seconds );
			}
			
			
			
			
			/// Relinquish the calling thread's CPU time until it's rescheduled.
			RIM_INLINE static void yield()
			{
				BasicThread::yield();
			}
			
			
			
			
			/// Terminate the current calling thread
			RIM_INLINE static void exit()
			{
				BasicThread::exit();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	System Thread Info Methods
			
			
			
			
			/// Return the total number of available hardware threads on this system.
			RIM_INLINE static Size getCPUCount()
			{
				return BasicThread::getCPUCount();
			}
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Type Declarations
			
			
			
			
			/// A class which is used to facilitate accessing the return values of function threads.
			template < typename Sig, typename ReturnType >
			class ReturnValueWrapper
			{
				public:
					
					RIM_INLINE lang::Optional<ReturnType> operator () ( const lang::Pointer< lang::FunctionCall<Sig> >& function )
					{
						return (*function)();
					}
					
			};
			
			
			
			
			/// A class specialization which is used to handle void return values of function threads.
			template < typename Sig >
			class ReturnValueWrapper<Sig,void>
			{
				public:
					
					RIM_INLINE lang::Optional<void> operator () ( const lang::Pointer< lang::FunctionCall<Sig> >& function )
					{
						(*function)();
						
						return lang::Optional<void>();
					}
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Virtual Run Function
			
			
			
			
			/// Start the execution of subclass client code on a new thread.
			virtual void run()
			{
				if ( !function.isNull() )
				{
					ReturnValueWrapper<Signature, typename lang::FunctionCall<Signature>::ReturnType> wrapper;
					
					returnValue = wrapper( function );
				}
			}
			
			
			
			
	private:
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The function that is being run by the thread.
			lang::Pointer< lang::FunctionCall<Signature> > function;
			
			
			
			
			/// An object which stores the optionally-NULL return value for this thread.
			lang::Optional< typename lang::FunctionCall<Signature>::ReturnType > returnValue;
			
			
			
};




typedef FunctionThread<void()> Thread;




//##########################################################################################
//***************************  End Rim Threads Namespace  **********************************
RIM_THREADS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_THREAD_H
