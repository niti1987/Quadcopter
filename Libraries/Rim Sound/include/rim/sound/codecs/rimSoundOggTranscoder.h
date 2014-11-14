/*
 *  rimSoundOggTranscoder.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/8/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_OGG_TRANSCODER_H
#define INCLUDE_RIM_SOUND_OGG_TRANSCODER_H


#include "rimSoundCodecsConfig.h"


#include "rimSoundTranscoder.h"


//##########################################################################################
//*************************  Start Rim Sound Codecs Namespace  *****************************
RIM_SOUND_CODECS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which provides the interface for objects that encode and decode sound data.
class OggTranscoder : public SoundTranscoder
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Format Accessor Methods
			
			
			
			
			/// Return an object which represents the resource format that this transcoder can read and write.
			virtual ResourceFormat getResourceFormat() const;
			
			
			
			
			/// Return an object which represents the format that this transcoder can encode and decode.
			virtual SoundFormat getFormat() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Encoding Methods
			
			
			
			
			/// Return whether or not this transcoder is able to encode the specified resource.
			virtual Bool canEncode( const SoundResource& resource ) const;
			
			
			
			
			/// Save the specified sound resource at the specified ID location.
			/**
			  * The method returns whether or not the resource was successfully written.
			  */
			virtual Bool encode( const ResourceID& identifier, const SoundResource& sound );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Decoding Methods
			
			
			
			
			/// Return whether or not the specified identifier refers to a valid resource for this transcoder.
			/**
			  * If the identifier represents a valid resource, TRUE is returned. Otherwise,
			  * if the resource is not valid, FALSE is returned.
			  */
			virtual Bool canDecode( const ResourceID& identifier ) const;
			
			
			
			
			/// Load the sound pointed to by the specified identifier.
			/**
			  * The caller can supply a pointer to a resource manager which can be used
			  * to manage the creation of child resources.
			  *
			  * If the method fails, the return value will be NULL.
			  */
			virtual Pointer<SoundResource> decode( const ResourceID& identifier, ResourceManager* manager = NULL );
			
			
			
			
};




//##########################################################################################
//*************************  End Rim Sound Codecs Namespace  *******************************
RIM_SOUND_CODECS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_OGG_TRANSCODER_H
