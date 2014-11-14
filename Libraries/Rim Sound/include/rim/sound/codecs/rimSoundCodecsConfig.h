/*
 *  rimSoundCodecsConfig.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 7/31/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_CODECS_CONFIG_H
#define INCLUDE_RIM_SOUND_CODECS_CONFIG_H


#include "../rimSoundConfig.h"


#include "../rimSoundUtilities.h"
#include "../filters/rimSoundSampleRateConverter.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_SOUND_CODECS_NAMESPACE
	#define RIM_SOUND_CODECS_NAMESPACE codecs
#endif




#ifndef RIM_SOUND_CODECS_NAMESPACE_START
	#define RIM_SOUND_CODECS_NAMESPACE_START		RIM_SOUND_NAMESPACE_START namespace RIM_SOUND_CODECS_NAMESPACE {
#endif




#ifndef RIM_SOUND_CODECS_NAMESPACE_END
	#define RIM_SOUND_CODECS_NAMESPACE_END		}; RIM_SOUND_NAMESPACE_END
#endif




RIM_SOUND_NAMESPACE_START
/// A namespace containing classes which encode and decode sound from various sound file types.
namespace RIM_SOUND_CODECS_NAMESPACE {
};
RIM_SOUND_NAMESPACE_END




//##########################################################################################
//*************************  Start Rim Sound Codecs Namespace  *****************************
RIM_SOUND_CODECS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



using rim::sound::util::Sample8;
using rim::sound::util::Sample16;
using rim::sound::util::Sample24;
using rim::sound::util::Sample32;
using rim::sound::util::Sample64;
using rim::sound::util::Sample32f;
using rim::sound::util::Sample64f;

using rim::sound::util::Gain;
using rim::sound::util::SampleRate;
using rim::sound::util::SampleType;
using rim::sound::util::SoundBuffer;
using rim::sound::util::SharedSoundBuffer;
using rim::sound::util::SharedBufferPool;
using rim::sound::util::SoundResource;


using rim::sound::util::SoundInputStream;
using rim::sound::util::SoundOutputStream;


using rim::sound::util::MIDIMessage;
using rim::sound::util::MIDIEvent;
using rim::sound::util::MIDIBuffer;
using rim::sound::util::MIDIInputStream;
using rim::sound::util::MIDIOutputStream;


using rim::sound::filters::SampleRateConverter;



//##########################################################################################
//*************************  End Rim Sound Codecs Namespace  *******************************
RIM_SOUND_CODECS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_CODECS_CONFIG_H
