/*
 *  rimSoundGainFilter.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 7/30/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_GAIN_FILTER_H
#define INCLUDE_RIM_SOUND_GAIN_FILTER_H


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
/// A class that applies a simple gain factor to input audio.
class GainFilter : public SoundFilter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new gain filter with unity gain (gain = 1).
			/**
			  * The new gain filter doesn't do anything to input audio since
			  * it is a unity gain. Set the gain factor to modify the output gain
			  * to something else.
			  */
			RIM_INLINE GainFilter()
				:	SoundFilter( 1, 1 ),
					gain( 1 ),
					targetGain( 1 )
			{
			}
			
			
			
			
			/// Create a new gain filter with the specified linear gain factor.
			RIM_INLINE GainFilter( Gain newGain )
				:	SoundFilter( 1, 1 ),
					gain( newGain ),
					targetGain( newGain )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Gain Accessor Methods
			
			
			
			
			/// Return the current linear gain factor of this gain filter.
			RIM_INLINE Gain getGain() const
			{
				return targetGain;
			}
			
			
			
			
			/// Return the current gain for this gain filter in decibels.
			RIM_INLINE Gain getGainDB() const
			{
				return util::linearToDB( targetGain );
			}
			
			
			
			
			/// Set the target linear gain for this gain filter.
			RIM_INLINE void setGain( Gain newGain )
			{
				lockMutex();
				targetGain = newGain;
				unlockMutex();
			}
			
			
			
			
			/// Set the target gain for this gain filter in decibels.
			RIM_INLINE void setGainDB( Gain newDBGain )
			{
				lockMutex();
				targetGain = util::dbToLinear( newDBGain );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Attribute Accessor Methods
			
			
			
			
			/// Return a human-readable name for this gain filter.
			/**
			  * The method returns the string "Gain Filter".
			  */
			virtual UTF8String getName() const;
			
			
			
			
			/// Return the manufacturer name of this gain filter.
			/**
			  * The method returns the string "Headspace Sound".
			  */
			virtual UTF8String getManufacturer() const;
			
			
			
			
			/// Return an object representing the version of this gain filter.
			virtual SoundFilterVersion getVersion() const;
			
			
			
			
			/// Return an object which describes the category of effect that this filter implements.
			/**
			  * This method returns the value SoundFilterCategory::DYNAMICS.
			  */
			virtual SoundFilterCategory getCategory() const;
			
			
			
			
			/// Return whether or not this gain filter can process audio data in-place.
			/**
			  * This method always returns TRUE, gain filter can process audio data in-place.
			  */
			virtual Bool allowsInPlaceProcessing() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Parameter Accessor Methods
			
			
			
			
			/// Return the total number of generic accessible parameters this filter has.
			virtual Size getParameterCount() const;
			
			
			
			
			/// Get information about the filter parameter at the specified index.
			virtual Bool getParameterInfo( Index parameterIndex, FilterParameterInfo& info ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Preset Accessor Methods
			
			
			
			
			/// Return the number of standard configuration presets that this gain filter has.
			virtual Size getPresetCount() const;
			
			
			
			
			/// Get the standard preset for this gain filter with the specified index.
			virtual Bool getPreset( Index presetIndex, SoundFilterPreset& preset ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Property Objects
			
			
			
			
			/// A string indicating the human-readable name of this gain filter.
			static const UTF8String NAME;
			
			
			
			
			/// A string indicating the manufacturer name of this gain filter.
			static const UTF8String MANUFACTURER;
			
			
			
			
			/// An object indicating the version of this gain filter.
			static const SoundFilterVersion VERSION;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Parameter Value Accessor Methods
			
			
			
			
			/// Place the value of the parameter at the specified index in the output parameter.
			virtual Bool getParameterValue( Index parameterIndex, FilterParameter& value ) const;
			
			
			
			
			/// Attempt to set the parameter value at the specified index.
			virtual Bool setParameterValue( Index parameterIndex, const FilterParameter& value );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Filter Processing Methods
			
			
			
			
			/// Multiply the samples in the input frame by this gain filter's gain factor and place them in the output frame.
			virtual SoundFilterResult processFrame( const SoundFilterFrame& inputFrame,
													SoundFilterFrame& outputFrame, Size numSamples );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The current linear gain factor applied to all input audio.
			Gain gain;
			
			
			
			
			/// The target output gain for this gain filter.
			/**
			  * This value allows smooth changes between different gain values.
			  */
			Gain targetGain;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_GAIN_FILTER_H
