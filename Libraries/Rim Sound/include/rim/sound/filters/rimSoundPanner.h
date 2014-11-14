/*
 *  rimSoundPanner.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/13/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_PANNER_H
#define INCLUDE_RIM_SOUND_PANNER_H


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
/// A class that pans input sound around a 360 degree sound panning field.
/**
  * This class takes the input channel layout and pans that layout around
  * the output channel layout based on a 3D panning direction.
  */
class Panner : public SoundFilter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new sound panner with the default panning direction (forward).
			RIM_INLINE Panner()
				:	SoundFilter( 1, 1 ),
					pan()
			{
			}
			
			
			
			
			/// Create a new sound panner with the specified panning direction.
			RIM_INLINE Panner( const PanDirection& newPan )
				:	SoundFilter( 1, 1 ),
					pan( newPan )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Pan Accessor Methods
			
			
			
			
			/// Return the current panning direction of this sound panner.
			RIM_INLINE const PanDirection& getPan() const
			{
				return pan;
			}
			
			
			
			
			/// Set the current panning direction of this sound panner.
			RIM_INLINE void setPan( const PanDirection& newPan )
			{
				lockMutex();
				pan = newPan;
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Attribute Accessor Methods
			
			
			
			
			/// Return a human-readable name for this sound panner.
			/**
			  * The method returns the string "Panner".
			  */
			virtual UTF8String getName() const;
			
			
			
			
			/// Return the manufacturer name of this sound panner.
			/**
			  * The method returns the string "Headspace Sound".
			  */
			virtual UTF8String getManufacturer() const;
			
			
			
			
			/// Return an object representing the version of this sound panner.
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
			
			
			
			
			/// A string indicating the human-readable name of this panner.
			static const UTF8String NAME;
			
			
			
			
			/// A string indicating the manufacturer name of this panner.
			static const UTF8String MANUFACTURER;
			
			
			
			
			/// An object indicating the version of this panner.
			static const SoundFilterVersion VERSION;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Filter Processing Method
			
			
			
			
			/// Pan the input channel layout to the output channel layout.
			virtual SoundFilterResult processFrame( const SoundFilterFrame& inputFrame,
													SoundFilterFrame& outputFrame, Size numSamples );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object representing the current panning direction of this sound panner.
			PanDirection pan;
			
			
			
			
			/// An object which holds the current channel matrix mixing gains for each channel pairing.
			ChannelMixMatrix channelGains;
			
			
			
			
			/// An object which holds the target channel matrix mixing gains for each channel pairing.
			ChannelMixMatrix targetChannelGains;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_PANNER_H
