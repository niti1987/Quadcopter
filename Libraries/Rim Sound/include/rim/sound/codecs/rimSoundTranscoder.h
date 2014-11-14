/*
 *  rimSoundTranscoder.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/8/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_TRANSCODER_H
#define INCLUDE_RIM_SOUND_TRANSCODER_H


#include "rimSoundCodecsConfig.h"


#include "rimSoundFormat.h"


//##########################################################################################
//*************************  Start Rim Sound Codecs Namespace  *****************************
RIM_SOUND_CODECS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which provides the interface for objects that encode and decode sound data.
class SoundTranscoder : public ResourceTranscoder<SoundResource>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Format Accessor Methods
			
			
			
			
			/// Return an object which represents the resource type that this transcoder can read and write.
			virtual ResourceType getResourceType() const;
			
			
			
			
			/// Return an object which represents the format that this transcoder can encode and decode.
			virtual SoundFormat getFormat() const = 0;
			
			
			
			
};




//##########################################################################################
//*************************  End Rim Sound Codecs Namespace  *******************************
RIM_SOUND_CODECS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_TRANSCODER_H
