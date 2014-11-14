/*
 *  rimSoundConfig.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_CONFIG_H
#define INCLUDE_RIM_SOUND_CONFIG_H


#include "rim/rimFramework.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Configuration
//############		
//##########################################################################################
//##########################################################################################




/// Define whether or not the sound library should use SIMD operations to accelerate sound processing.
/**
  * Setting the value to a non-zero value indicates that SIMD processing should be used.
  */
#define RIM_SOUND_USE_SIMD 1




//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_SOUND_NAMESPACE
	#define RIM_SOUND_NAMESPACE sound
#endif




#ifndef RIM_SOUND_NAMESPACE_START
	#define RIM_SOUND_NAMESPACE_START		RIM_NAMESPACE_START namespace RIM_SOUND_NAMESPACE {
#endif




#ifndef RIM_SOUND_NAMESPACE_END
	#define RIM_SOUND_NAMESPACE_END		}; RIM_NAMESPACE_END
#endif




RIM_NAMESPACE_START
/// The enclosing namespace for the sound library.
namespace RIM_SOUND_NAMESPACE {
};
RIM_NAMESPACE_END




//##########################################################################################
//****************************  Start Rim Sound Namespace  *********************************
RIM_SOUND_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




/// Define the type used to indicate the index of a sample within a sound.
typedef UInt64 SampleIndex;




/// Define the type used to indicate the size in samples of a sound.
typedef UInt64 SoundSize;




using rim::math::AABB1f;
using rim::math::Vector2f;
using rim::math::Vector3f;




//##########################################################################################
//****************************  End Rim Sound Namespace  ***********************************
RIM_SOUND_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_CONFIG_H
