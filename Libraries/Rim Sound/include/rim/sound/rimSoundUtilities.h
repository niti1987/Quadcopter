/*
 *  rimSoundUtilities.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 5/8/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_UTILITIES_H
#define INCLUDE_RIM_SOUND_UTILITIES_H


#include "util/rimSoundUtilitiesConfig.h"


// Sample Information
#include "util/rimSoundInt24.h"
#include "util/rimSoundSample.h"
#include "util/rimSoundSIMDSample.h"
#include "util/rimSoundSampleType.h"
#include "util/rimSoundSampleRate.h"


// Gain Utilities
#include "util/rimSoundGain.h"


// Speaker/Channel Configuration Management
#include "util/rimSoundChannelType.h"
#include "util/rimSoundChannelLayout.h"
#include "util/rimSoundChannelLayoutType.h"
#include "util/rimSoundPanDirection.h"


// Sound Buffer Management Classes
#include "util/rimSoundBuffer.h"
#include "util/rimSoundBufferQueue.h"
#include "util/rimSoundSharedBufferPool.h"
#include "util/rimSoundSharedSoundBuffer.h"


// Streaming Sound I/O Classes
#include "util/rimSoundInputStream.h"
#include "util/rimSoundOutputStream.h"


// Sound Resource Management
#include "util/rimSoundResource.h"


// MIDI Classes
#include "util/rimSoundMIDIMessage.h"
#include "util/rimSoundMIDIEvent.h"
#include "util/rimSoundMIDIBuffer.h"
#include "util/rimSoundMIDIInputStream.h"
#include "util/rimSoundMIDIOutputStream.h"


#include "util/rimSoundTimeSignature.h"
#include "util/rimSoundMIDITime.h"



#endif // INCLUDE_RIM_SOUND_UTILITIES_H
