/*
 *  rimSemaphore.h
 *  Rim Threads
 *
 *  Created by Carl Schissler on 4/16/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SEMAPHORE_H
#define INCLUDE_RIM_SEMAPHORE_H


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
/// A class which implements a count-based synchronization object.
class Semaphore
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new semaphore object with an initial value of 0.
			Semaphore();
			
			
			
			
			/// Create a new semaphore object with the specified initial value.
			Semaphore( UInt initialValue );
			
			
			
			
			/// Create a new semaphore with the same value as the specified semaphore.
			Semaphore( const Semaphore& semaphore );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a semaphore object.
			/**
			  * This has the effect of awakening all waiting
			  * threads. This is done in order to prevent deadlocks
			  * in the case of accidental destruction.
			  */
			~Semaphore();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign one semaphore to another.
			/**
			  * This awakens all threads currently waiting on the semaphore
			  * and gives the semaphore an initial value equal to the other
			  * semaphore's current value.
			  */
			Semaphore& operator = ( const Semaphore& semaphore );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Up/Down Methods
			
			
			
			
			/// Increase the value of the semaphore by 1.
			/**
			  * This awakens at most 1 thread which was suspended after a call
			  * to down() when the value of the semaphore was 0. The awoken thread
			  * then decreases the value of the semaphore by 1 and returns from
			  * down(). Threads are awoken in a first-in-first-out order: the first
			  * thread to start waiting on a call to down is the first awoken after
			  * a call to up().
			  */
			void up();
			
			
			
			
			/// Decrease the value of the semaphore by 1.
			/**
			  * If the value of the semaphore before the call to down() was 0,
			  * then the calling thread is blocked until another thread makes
			  * a call to up().
			  */
			void down();
			
			
			
			
			/// Awaken all threads that are waiting on the semaphore and set its value to 0.
			void reset();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value Accessor Method
			
			
			
			
			/// Get the current value of the semaphore.
			/**
			  * The returned value is always greater than or equal to zero.
			  *
			  * Since this method may be emulated on some platforms that don't support
			  * getting the semaphore value, sychronization is not guaranteed and so
			  * the returned value may not necessarily represent the current semaphore value.
			  */
			UInt getValue() const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Semaphore Wrapper Class Declaration
			
			
			
			
			/// A class which encapsulates internal platform-specific Semaphore code.
			class SemaphoreWrapper;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A wrapper of the internal platform-specific state of the semaphore.
			SemaphoreWrapper* wrapper;
			
			
			
			
};




//##########################################################################################
//***************************  End Rim Threads Namespace  **********************************
RIM_THREADS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SEMAPHORE_H
