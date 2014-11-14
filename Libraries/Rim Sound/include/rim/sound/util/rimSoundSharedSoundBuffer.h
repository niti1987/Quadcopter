/*
 *  rimSoundSharedSoundBuffer.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/1/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_SHARED_SOUND_BUFFER_H
#define INCLUDE_RIM_SOUND_SHARED_SOUND_BUFFER_H


#include "rimSoundUtilitiesConfig.h"


#include "rimSoundSharedBufferInfo.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a temporary handle to a shared SoundBuffer.
/**
  * When this class is created, it obtains a handle to a shared sound buffer and
  * locks that buffer from being used elsewhere. Once this object goes out of scope
  * and is destructed, it releases its handle to that SoundBuffer, allowing its reuse.
  *
  * Therefore, it is an illegal operation to retain a pointer to the shared SoundBuffer
  * and use it after the associated SharedSoundBuffer instance has been destructed.
  */
class SharedSoundBuffer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Copy Constructor
			
			
			
			
			/// Declare the copy constructor private so that instances of this class cannot be copied.
			RIM_INLINE SharedSoundBuffer( const SharedSoundBuffer& other )
				:	bufferInfo( other.bufferInfo )
			{
				bufferInfo->referenceCount++;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this handle to a shared sound buffer, releasing it back to its pool.
			RIM_INLINE ~SharedSoundBuffer()
			{
				bufferInfo->referenceCount--;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Declare the assignment operator private so that instances of this class cannot be copied.
			RIM_INLINE SharedSoundBuffer& operator = ( const SharedSoundBuffer& other )
			{
				if ( this != &other )
				{
					bufferInfo->referenceCount--;
					bufferInfo = other.bufferInfo;
					bufferInfo->referenceCount++;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Accessor Method
			
			
			
			
			/// Return a reference to the underlying sound buffer that is being shared.
			RIM_INLINE SoundBuffer& getBuffer()
			{
				return bufferInfo->buffer;
			}
			
			
			
			
			/// Return a reference to the underlying sound buffer that is being shared.
			RIM_INLINE const SoundBuffer& getBuffer() const
			{
				return bufferInfo->buffer;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructors
			
			
			
			
			/// Create a new shared sound buffer for the specified sound buffer and buffer information structure.
			RIM_INLINE SharedSoundBuffer( SharedBufferInfo* newBufferInfo )
				:	bufferInfo( newBufferInfo )
			{
				bufferInfo->referenceCount++;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to private information about the shared sound buffer.
			SharedBufferInfo* bufferInfo;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Declarations
			
			
			
			
			/// Declare the SharedBufferPool class as a friend so that it can create instances of this class.
			friend class SharedBufferPool;
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_SHARED_SOUND_BUFFER_H
