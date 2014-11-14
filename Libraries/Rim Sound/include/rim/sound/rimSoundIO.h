/*
 *  rimSoundIO.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 7/31/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_IO_H
#define INCLUDE_RIM_SOUND_IO_H


#include "io/rimSoundIOConfig.h"


#include "io/rimSoundFormat.h"
#include "io/rimSoundTranscoder.h"


// .wav format encoder/decoder
#include "io/rimSoundWaveDecoder.h"
#include "io/rimSoundWaveEncoder.h"
#include "io/rimSoundWaveTranscoder.h"


// .aif format encoder/decoder
#include "io/rimSoundAIFFDecoder.h"
#include "io/rimSoundAIFFEncoder.h"
#include "io/rimSoundAIFFTranscoder.h"


// .ogg format encoder/decoder
#include "io/rimSoundOggDecoder.h"
#include "io/rimSoundOggEncoder.h"
#include "io/rimSoundOggTranscoder.h"


#endif // INCLUDE_RIM_SOUND_IO_H
