/*
 *  rimSoundSharedBufferInfo.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/1/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_SHARED_BUFFER_INFO_H
#define INCLUDE_RIM_SOUND_SHARED_BUFFER_INFO_H


#include "rimSoundUtilitiesConfig.h"


#include "rimSoundBuffer.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which holds information about a shared sound buffer buffer.
/**
  * This class is an internal class and shouldn't be used directly.
  */
class SharedBufferInfo
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructor
			
			
			
			
			/// Create a new shared sound buffer information structure with the specified buffer attributes.
			RIM_INLINE SharedBufferInfo( Size numChannels, Size numSamples, SampleRate sampleRate )
				:	buffer( numChannels, numSamples, sampleRate ),
					referenceCount( 0 )
			{
			}
			
			
			
			
	private:
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The sound buffer that is being shared.
			SoundBuffer buffer;
			
			
			
			
			/// A integer value indicating whether or not this shared buffer is currently in use.
			/**
			  * If the value is 0, there are no outstanding references to the shared buffer,
			  * otherwise this value indicates the number of shared references to the buffer.
			  */
			Index referenceCount;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Friend Class Declarations
			
			
			
			
			/// Declare the SharedBufferPool class as a friend so that it can create instances of this class.
			friend class SharedBufferPool;
			
			
			
			
			/// Declare the SharedSoundBuffer class as a friend so that it can modify private data of this class.
			friend class SharedSoundBuffer;
			
			
			
};





//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_SHARED_BUFFER_INFO_H
