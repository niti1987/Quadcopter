/*
 *  rimSound.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 5/8/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_H
#define INCLUDE_RIM_SOUND_H


#include "sound/rimSoundConfig.h"


#include "sound/rimSoundUtilities.h"
#include "sound/rimSoundDevices.h"
#include "sound/rimSoundFilters.h"
#include "sound/rimSoundIO.h"


//##########################################################################################
//****************************  Start Rim Sound Namespace  *********************************
RIM_SOUND_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



using namespace rim::sound::util;
using namespace rim::sound::filters;
using namespace rim::sound::devices;
using namespace rim::sound::io;



//##########################################################################################
//****************************  End Rim Sound Namespace  ***********************************
RIM_SOUND_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_H
