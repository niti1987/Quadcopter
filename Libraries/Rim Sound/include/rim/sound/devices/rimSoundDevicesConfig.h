/*
 *  rimSoundDevicesConfig.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_DEVICES_CONFIG_H
#define INCLUDE_RIM_SOUND_DEVICES_CONFIG_H


#include "../rimSoundConfig.h"


#include "../rimSoundUtilities.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_SOUND_DEVICES_NAMESPACE
	#define RIM_SOUND_DEVICES_NAMESPACE devices
#endif




#ifndef RIM_SOUND_DEVICES_NAMESPACE_START
	#define RIM_SOUND_DEVICES_NAMESPACE_START		RIM_SOUND_NAMESPACE_START namespace RIM_SOUND_DEVICES_NAMESPACE {
#endif




#ifndef RIM_SOUND_DEVICES_NAMESPACE_END
	#define RIM_SOUND_DEVICES_NAMESPACE_END		}; RIM_SOUND_NAMESPACE_END
#endif




RIM_SOUND_NAMESPACE_START
/// A namespace containing classes handling input and output from audio devicess.
namespace RIM_SOUND_DEVICES_NAMESPACE {
};
RIM_SOUND_NAMESPACE_END




//##########################################################################################
//************************  Start Rim Sound Devices Namespace  *****************************
RIM_SOUND_DEVICES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




using rim::sound::util::Sample32f;
using rim::sound::util::SampleRate;
using rim::sound::util::SampleType;
using rim::sound::util::SoundBuffer;
using rim::sound::util::MIDIMessage;
using rim::sound::util::MIDIEvent;
using rim::sound::util::MIDIBuffer;



//##########################################################################################
//************************  End Rim Sound Devices Namespace  *******************************
RIM_SOUND_DEVICES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_DEVICES_CONFIG_H
