/*
 *  rimThreadPriority.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 7/29/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_THREAD_PRIORITY_H
#define INCLUDE_RIM_THREAD_PRIORITY_H


#include "rimThreadsConfig.h"


#include "../rimData.h"


//##########################################################################################
//***************************  Start Rim Threads Namespace  ********************************
RIM_THREADS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An enum class which specifies the different execution priorities that a thread can have.
class ThreadPriority
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Thread Priority Enum Definition
			
			
			
			
			/// An enum type which represents the types of thread scheduling priority.
			typedef enum Enum
			{
				/// The default thread priority.
				DEFAULT,
				
				/// A thread priority for processes that don't need to be run often.
				LOW,
				
				/// A thread priority for processes with priority between low and high.
				MEDIUM,
				
				/// A thread priority for processes that need to be run often.
				HIGH,
				
				/// A thread priority used for time-critical processing with strict real-time requirements.
				TIME_CRITICAL
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new thread priority with the DEFAULT thread priority.
			RIM_INLINE ThreadPriority()
				:	type( DEFAULT )
			{
			}
			
			
			
			
			/// Create a new thread priority with the specified thread priority enum value.
			RIM_INLINE ThreadPriority( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this thread priority type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the thread priority.
			data::String toString() const;
			
			
			
			
			/// Convert this thread priority into a string representation.
			RIM_FORCE_INLINE operator data::String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value which indicates the type of thread priority.
			Enum type;
			
			
			
};




//##########################################################################################
//***************************  End Rim Threads Namespace  **********************************
RIM_THREADS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_THREAD_PRIORITY_H
