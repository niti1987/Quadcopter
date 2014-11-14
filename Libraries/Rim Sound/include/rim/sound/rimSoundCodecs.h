/*
 *  rimSoundCodecs.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 7/31/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_CODECS_H
#define INCLUDE_RIM_SOUND_CODECS_H


#include "codecs/rimSoundCodecsConfig.h"


#include "codecs/rimSoundFormat.h"
#include "codecs/rimSoundTranscoder.h"


// .wav format encoder/decoder
#include "codecs/rimSoundWaveDecoder.h"
#include "codecs/rimSoundWaveEncoder.h"
#include "codecs/rimSoundWaveTranscoder.h"


// .aif format encoder/decoder
#include "codecs/rimSoundAIFFDecoder.h"
#include "codecs/rimSoundAIFFEncoder.h"
#include "codecs/rimSoundAIFFTranscoder.h"


// .ogg format encoder/decoder
#include "codecs/rimSoundOggDecoder.h"
#include "codecs/rimSoundOggEncoder.h"
#include "codecs/rimSoundOggTranscoder.h"


#endif // INCLUDE_RIM_SOUND_CODECS_H
