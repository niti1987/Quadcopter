/*
 *  rimSoundFiltersConfig.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_FILTERS_CONFIG_H
#define INCLUDE_RIM_SOUND_FILTERS_CONFIG_H


#include "../rimSoundConfig.h"


#include "../rimSoundUtilities.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_SOUND_FILTERS_NAMESPACE
	#define RIM_SOUND_FILTERS_NAMESPACE filters
#endif




#ifndef RIM_SOUND_FILTERS_NAMESPACE_START
	#define RIM_SOUND_FILTERS_NAMESPACE_START		RIM_SOUND_NAMESPACE_START namespace RIM_SOUND_FILTERS_NAMESPACE {
#endif




#ifndef RIM_SOUND_FILTERS_NAMESPACE_END
	#define RIM_SOUND_FILTERS_NAMESPACE_END		}; RIM_SOUND_NAMESPACE_END
#endif




RIM_SOUND_NAMESPACE_START
/// A namespace containing simple classes which do processing on buffers of audio.
namespace RIM_SOUND_FILTERS_NAMESPACE {
};
RIM_SOUND_NAMESPACE_END




//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




using rim::sound::util::Gain;
using rim::sound::util::Sample32f;
using rim::sound::util::Sample64f;
using rim::sound::util::ComplexSample;
using rim::sound::util::SampleRate;
using rim::sound::util::SampleType;
using rim::sound::util::SoundBuffer;
using rim::sound::util::SoundBufferQueue;
using rim::sound::util::SharedBufferPool;
using rim::sound::util::SharedSoundBuffer;
using rim::sound::util::PanDirection;
using rim::sound::util::ChannelLayout;
using rim::sound::util::ChannelMixMatrix;
using rim::sound::util::SoundInputStream;
using rim::sound::util::SoundOutputStream;
using rim::sound::util::SoundInputStream;
using rim::sound::util::SoundOutputStream;
using rim::sound::util::MIDIMessage;
using rim::sound::util::MIDIEvent;
using rim::sound::util::MIDIBuffer;
using rim::sound::util::MIDITime;




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_FILTERS_CONFIG_H
