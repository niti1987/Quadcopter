/*
 *  rimSignal.h
 *  Rim Threads
 *
 *  Created by Carl Schissler on 8/27/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SIGNAL_H
#define INCLUDE_RIM_SIGNAL_H


#include "rimThreadsConfig.h"


#include "../rimUtilities.h"


//##########################################################################################
//***************************  Start Rim Threads Namespace  ********************************
RIM_THREADS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a thread-to-thread signal event.
/**
  * This class allows a thread to wait for a given signal object. This will
  * halt the execution of that thread until another thread signals that the signal
  * has been raised. At that point the waiting thread wakes up and begins execution
  * again. A typical application of this class would be in produce-consumer systems
  * where one thread is waiting for data from another thread.
  */
class Signal
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new signal object.
			Signal();
			
			
			
			
			/// Create a copy of a signal object.
			/**
			  * This has the effect of linking the two signal objects - 
			  * whenever one is signaled, all listeners for the other
			  * receive the signal.
			  */
			Signal( const Signal& signal );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a signal object.
			/**
			  * This has the effect of signaling all listening
			  * threads that the signal has been sent. This is
			  * done in order to prevent deadlocks.
			  */
			~Signal();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign one signal to another.
			/**
			  * This has the effect of linking the two signal objects - 
			  * whenever one is signaled, all listeners for the other
			  * receive the signal.
			  */
			Signal& operator = ( const Signal& signal );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Signal/Listen Methods
			
			
			
			
			/// Send a signal to all listening threads.
			void signal();
			
			
			
			
			/// Wait until the signal is given by another thread.
			/**
			  * This method blocks the calling thread until another
			  * thread calls the signal() method on this object.
			  */
			void wait() const;
			
			
			
			
			/// Lock the mutex associated with this signal.
			void lock();
			
			
			
			
			/// Unlock this mutex associated with this signal.
			void unlock();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Signal Wrapper Class Declaration
			
			
			
			
			/// A class which encapsulates internal platform-specific Signal code.
			class SignalWrapper;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A wrapper of the internal platform-specific state of the signal.
			SignalWrapper* wrapper;
			
			
			
			
};




//##########################################################################################
//***************************  End Rim Threads Namespace  **********************************
RIM_THREADS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SIGNAL_H
