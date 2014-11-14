/*
 *  rimGain.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 3/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GAIN_H
#define INCLUDE_RIM_GAIN_H


#include "rimSoundUtilitiesConfig.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




/// Define the type to represent a linear gain coefficient.
typedef Float32 Gain;




/// Convert the specfied linear gain ratio to a logarithmic gain in decibels.
RIM_FORCE_INLINE Gain linearToDB( Gain linearGain )
{
	return Gain(20)*math::log10( linearGain );
}




/// Convert the specfied logarithmic gain in decibels to a linear gain ratio.
RIM_FORCE_INLINE Gain dbToLinear( Gain dbGain )
{
	return math::pow( Gain(10), dbGain/Gain(20) );
}




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GAIN_H
