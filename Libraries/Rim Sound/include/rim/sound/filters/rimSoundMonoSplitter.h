/*
 *  rimSoundMonoSplitter.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/11/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_MONO_SPLITTER_H
#define INCLUDE_RIM_SOUND_MONO_SPLITTER_H


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
/// A class that copies a single input channel into multiple output channels.
/**
  * This class takes the first channel of its input buffer and copies to a
  * user-defined number of channels in the output buffer.
  */
class MonoSplitter : public SoundFilter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new mono splitter with the default number of output channels, 1.
			RIM_INLINE MonoSplitter()
				:	SoundFilter( 1, 1 ),
					numOutputChannels( 1 )
			{
			}
			
			
			
			
			/// Create a new mono splitter which has the specified number of output channels.
			RIM_INLINE MonoSplitter( Size newNumOutputChannels )
				:	SoundFilter( 1, 1 ),
					numOutputChannels( math::max( newNumOutputChannels, Size(1) ) )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Output Channel Count Accessor Methods
			
			
			
			
			/// Return the total number of output channels that this mono splitter has.
			/**
			  * This is the number of channels that the first input channel is split into.
			  */
			RIM_INLINE Size getChannelCount() const
			{
				return numOutputChannels;
			}
			
			
			
			
			/// Set the total number of output channels that this mono splitter has.
			/**
			  * This is the number of channels that the first input channel is split into.
			  *
			  * The specified number of channels is clamped to be in the range [1,infinity].
			  */
			RIM_INLINE void setChannelCount( Size newNumOutputChannels )
			{
				numOutputChannels = math::max( newNumOutputChannels, Size(1) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Attribute Accessor Methods
			
			
			
			
			/// Return a human-readable name for this mono splitter.
			/**
			  * The method returns the string "Mono Splitter".
			  */
			virtual UTF8String getName() const;
			
			
			
			
			/// Return the manufacturer name of this mono splitter.
			/**
			  * The method returns the string "Headspace Sound".
			  */
			virtual UTF8String getManufacturer() const;
			
			
			
			
			/// Return an object representing the version of this mono splitter.
			virtual SoundFilterVersion getVersion() const;
			
			
			
			
			/// Return an object which describes the category of effect that this filter implements.
			/**
			  * This method returns the value SoundFilterCategory::IMAGING.
			  */
			virtual SoundFilterCategory getCategory() const;
			
			
			
			
			/// Return whether or not this splitter can process audio data in-place.
			/**
			  * This method always returns TRUE, splitters can process audio data in-place.
			  */
			virtual Bool allowsInPlaceProcessing() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Parameter Accessor Methods
			
			
			
			
			/// Return the total number of generic accessible parameters this filter has.
			virtual Size getParameterCount() const;
			
			
			
			
			/// Get information about the parameter at the specified index.
			virtual Bool getParameterInfo( Index parameterIndex, FilterParameterInfo& info ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Property Objects
			
			
			
			
			/// A string indicating the human-readable name of this mono splitter.
			static const UTF8String NAME;
			
			
			
			
			/// A string indicating the manufacturer name of this mono splitter.
			static const UTF8String MANUFACTURER;
			
			
			
			
			/// An object indicating the version of this mono splitter.
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
		//******	Private Filter Processing Method
			
			
			
			
			/// Split the sound in the first input buffer channel to as many output channels as necessary.
			virtual SoundFilterResult processFrame( const SoundFilterFrame& inputFrame,
													SoundFilterFrame& outputFrame, Size numSamples );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The number of channels into which the first input buffer channel is being split.
			Size numOutputChannels;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_MONO_SPLITTER_H
