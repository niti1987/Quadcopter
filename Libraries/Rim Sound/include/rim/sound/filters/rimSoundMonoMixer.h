/*
 *  rimSoundMonoMixer.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/11/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_MONO_MIXER_H
#define INCLUDE_RIM_SOUND_MONO_MIXER_H


#include "rimSoundFiltersConfig.h"


#include "rimSoundFilter.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that mixes multiple input channels of audio to a single output channel.
/**
  * The mono mixer applies a linear gain factor to the channels equal to (1/N) where
  * N is the number of channels in the input buffer. This prevent signal overload
  * when the channels have lots of things in phase with each other.
  */
class MonoMixer : public SoundFilter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new mono mixer.
			RIM_INLINE MonoMixer()
				:	SoundFilter( 1, 1 )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Attribute Accessor Methods
			
			
			
			
			/// Return a human-readable name for this mono mixer.
			/**
			  * The method returns the string "Mono Mixer".
			  */
			virtual UTF8String getName() const;
			
			
			
			
			/// Return the manufacturer name of this mono mixer.
			/**
			  * The method returns the string "Headspace Sound".
			  */
			virtual UTF8String getManufacturer() const;
			
			
			
			
			/// Return an object representing the version of this mono mixer.
			virtual SoundFilterVersion getVersion() const;
			
			
			
			
			/// Return an object which describes the category of effect that this filter implements.
			/**
			  * This method returns the value SoundFilterCategory::IMAGING.
			  */
			virtual SoundFilterCategory getCategory() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Property Objects
			
			
			
			
			/// A string indicating the human-readable name of this mono mixer.
			static const UTF8String NAME;
			
			
			
			
			/// A string indicating the manufacturer name of this mono mixer.
			static const UTF8String MANUFACTURER;
			
			
			
			
			/// An object indicating the version of this mono mixer.
			static const SoundFilterVersion VERSION;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Filter Processing Method
			
			
			
			
			/// Mix the sound in the input buffer channels to the first channel of the output buffer.
			virtual SoundFilterResult processFrame( const SoundFilterFrame& inputFrame,
													SoundFilterFrame& outputFrame, Size numSamples );
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_MONO_MIXER_H
