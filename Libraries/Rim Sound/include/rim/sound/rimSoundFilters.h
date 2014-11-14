/*
 *  rimSoundFilters.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 7/21/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_FILTERS_H
#define INCLUDE_RIM_SOUND_FILTERS_H


#include "filters/rimSoundFiltersConfig.h"


// Base Framework Classes
#include "filters/rimSoundFilterVersion.h"
#include "filters/rimSoundFilterFrame.h"
#include "filters/rimSoundFilterParameterInfo.h"
#include "filters/rimSoundFilterParameterType.h"
#include "filters/rimSoundFilterParameterValue.h"
#include "filters/rimSoundFilterParameterFlags.h"
#include "filters/rimSoundFilterParameter.h"
#include "filters/rimSoundFilterState.h"
#include "filters/rimSoundFilterPreset.h"
#include "filters/rimSoundFilter.h"


// Routing and Mixing Filters
#include "filters/rimSoundMixer.h"
#include "filters/rimSoundSplitter.h"
#include "filters/rimSoundFilterSeries.h"
#include "filters/rimSoundFilterGraph.h"


// Panning and Channel Mixing Filters
#include "filters/rimSoundPanner.h"
#include "filters/rimSoundMonoMixer.h"
#include "filters/rimSoundMonoSplitter.h"


// Equalization Filters
#include "filters/rimSoundCutoffFilter.h"
#include "filters/rimSoundBandFilter.h"
#include "filters/rimSoundShelfFilter.h"
#include "filters/rimSoundParametricFilter.h"
#include "filters/rimSoundCrossover.h"
#include "filters/rimSoundParametricEqualizer.h"
#include "filters/rimSoundGraphicEqualizer.h"
#include "filters/rimSoundConvolutionFilter.h"


// Delay Filters
#include "filters/rimSoundDelay.h"
#include "filters/rimSoundMultichannelDelay.h"


// Reverb Filters
#include "filters/rimSoundReverbFilter.h"


// Sound Sources/Destinations
#include "filters/rimSoundToneGenerator.h"
#include "filters/rimSoundStreamPlayer.h"
#include "filters/rimSoundStreamRecorder.h"
#include "filters/rimSoundThreadedStreamRecorder.h"
#include "filters/rimSoundSampler.h"


// Dynamics Filters
#include "filters/rimSoundGainFilter.h"
#include "filters/rimSoundCompressor.h"
#include "filters/rimSoundLimiter.h"
#include "filters/rimSoundExpander.h"


// Distortion Filters
#include "filters/rimSoundDistortion.h"
#include "filters/rimSoundSaturator.h"
#include "filters/rimSoundBitcrusher.h"


// Modulation Filters
#include "filters/rimSoundTremolo.h"
#include "filters/rimSoundVibrato.h"
#include "filters/rimSoundFlanger.h"


// Sample Rate Conversion / Pitch Shift Filters
#include "filters/rimSoundSampleRateConverter.h"
#include "filters/rimSoundPitchShifter.h"




#endif // INCLUDE_RIM_SOUND_FILTERS_H
