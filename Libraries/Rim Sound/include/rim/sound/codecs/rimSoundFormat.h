/*
 *  rimSoundFormat.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/8/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_FORMAT_H
#define INCLUDE_RIM_SOUND_FORMAT_H


#include "rimSoundCodecsConfig.h"


//##########################################################################################
//*************************  Start Rim Sound Codecs Namespace  *****************************
RIM_SOUND_CODECS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An enum class representing the different kinds of sound encoding formats.
class SoundFormat
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Format Enum Declaration
			
			
			
			
			/// An enum type representing the different kinds of sound encoding formats.
			typedef enum Enum
			{
				/// An undefined sound format.
				UNDEFINED = ResourceFormat::UNDEFINED,
				
				/// The WAVE sound format.
				WAVE = ResourceFormat::WAVE,
				
				/// The Audio Interchange File Format (AIFF) sound format.
				AIFF = ResourceFormat::AIFF,
				
				/// The compressed OGG sound format.
				OGG = ResourceFormat::OGG,
				
				/// The compressed MPEG-3 sound format.
				MP3 = ResourceFormat::MP3,
				
				/// The MPEG-4 audio-only sound format.
				M4A = ResourceFormat::M4A,
				
				/// The Free Lossless Audio Codec (FLAC) sound format.
				FLAC = ResourceFormat::FLAC,
				
				/// The Core Audio Format (CAF) sound format.
				CAF = ResourceFormat::CAF
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an sound format object with an UNDEFINED sound format.
			RIM_INLINE SoundFormat()
				:	format( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a sound format object from the specified sound format Enum.
			RIM_INLINE SoundFormat( SoundFormat::Enum newFormat )
				:	format( newFormat )
			{
			}
			
			
			
			
			/// Create a sound format object from the specified resource format.
			SoundFormat( const ResourceFormat& newFormat );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this sound format to an enum value.
			RIM_INLINE operator Enum () const
			{
				return format;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sound Format Extension Accessor Method
			
			
			
			
			/// Return the standard file extension used for this sound format.
			UTF8String getExtension() const;
			
			
			
			
			/// Return a sound format which corresponds to the format with the given extension string.
			static SoundFormat getFormatForExtension( const UTF8String& extension );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sound Format String Conversion Methods
			
			
			
			
			/// Return a string representation of the sound format.
			String toString() const;
			
			
			
			
			/// Convert this sound format into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value specifying the sound format.
			Enum format;
			
			
			
};




//##########################################################################################
//*************************  End Rim Sound Codecs Namespace  *******************************
RIM_SOUND_CODECS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_FORMAT_H
