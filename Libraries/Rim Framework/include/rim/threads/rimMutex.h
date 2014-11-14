/*
 *  Mutex.h
 *  GSound
 *
 *  Created by Carl Schissler on 3/22/11.
 *  Copyright 2011 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_MUTEX_H
#define INCLUDE_RIM_MUTEX_H


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
/// A class whose job is to provide a means of thread synchronization by exclusion.
/** 
  * The class is essentially a wrapper around the host platform's mutex facilities.
  * It allows threads to be synchronized so that access to data or other sensitive
  * items can be restricted to one thread at a time.
  *
  *	In order to use the class properly, call the lock() method to lock the
  * mutex and call the unlock() method to unlock it. The lock() method blocks
  * execution of the calling thread until the mutex has been released by another
  * thread. One can also query the state of the mutex (locked or unlocked) using
  * the method isUnlocked().
  */
class Mutex
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new mutex in the default state of not locked.
			Mutex();
			
			
			
			
			/// Create a copy of a Mutex object.
			/**
			  * The new mutex is created in the unlocked state and is independent
			  * of the other mutex. The effect is the same as the default constructor.
			  */
			Mutex( const Mutex& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a Mutex object, releasing all internal state.
			~Mutex();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign one Mutex to another.
			/**
			  * This operator releases any previous lock on this mutex and effectively results
			  * in a new mutex in the unlocked state. The new mutex is independent
			  * of the other mutex.
			  */
			Mutex& operator = ( const Mutex& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mutex Acquisition
			
			
			
			
			/// Wait until the Mutex is available for the current thread of execution.
			/**
			  * This method blocks the current thread until the signal is recieved
			  * that the Mutex has been released, at which time the Mutex is acquired
			  * by the current thread and the method returns. If the Mutex is available,
			  * the method returns immediately and the Mutex is acquired.
			  */
			void lock();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mutex Release
			
			
			
			
			/// Release the mutex so that another thread can acquire it.
			/**
			  * If the mutex is not already acquired, this method
			  * has no effect.
			  */
			void unlock();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mutex Status Accessor
			
			
			
			
			/// Get whether or not the mutex is available.
			/**
			  * If the mutex is free for acquisition, TRUE is returned. Otherwise
			  * FALSE is returned.
			  * 
			  * @return whether or not the mutex is available for acquisition.
			  */
			Bool isUnlocked() const;
			
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Mutex Wrapper Class Declaration
			
			
			
			
			/// A class which encapsulates internal platform-specific Mutex code.
			class MutexWrapper;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to a wrapper object containing the internal state of the Mutex.
			MutexWrapper* wrapper;
			
			
			
			
			
};




//##########################################################################################
//***************************  End Rim Threads Namespace  **********************************
RIM_THREADS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_MUTEX_H
