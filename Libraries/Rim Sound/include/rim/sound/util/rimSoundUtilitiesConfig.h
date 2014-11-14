/*
 *  rimSoundUtilitiesConfig.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_UTILITIES_CONFIG_H
#define INCLUDE_RIM_SOUND_UTILITIES_CONFIG_H


#include "../rimSoundConfig.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_SOUND_UTILITIES_NAMESPACE
	#define RIM_SOUND_UTILITIES_NAMESPACE util
#endif




#ifndef RIM_SOUND_UTILITIES_NAMESPACE_START
	#define RIM_SOUND_UTILITIES_NAMESPACE_START		RIM_SOUND_NAMESPACE_START namespace RIM_SOUND_UTILITIES_NAMESPACE {
#endif




#ifndef RIM_SOUND_UTILITIES_NAMESPACE_END
	#define RIM_SOUND_UTILITIES_NAMESPACE_END		}; RIM_SOUND_NAMESPACE_END
#endif




RIM_SOUND_NAMESPACE_START
/// A namespace containing basic DSP framework classes for samples, buffers, and others types.
namespace RIM_SOUND_UTILITIES_NAMESPACE {
};
RIM_SOUND_NAMESPACE_END




//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




/// Define the type used to represent a sound sample that is a complex number.
typedef math::Complex<Float32> ComplexSample;




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_UTILITIES_CONFIG_H
