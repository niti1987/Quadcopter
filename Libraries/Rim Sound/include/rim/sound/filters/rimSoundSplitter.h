/*
 *  rimSoundSplitter.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/11/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_SPLITTER_H
#define INCLUDE_RIM_SOUND_SPLITTER_H


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
/// A class that copies a single input source of sound into multiple outputs.
class Splitter : public SoundFilter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new splitter with the default number of outputs, 1.
			RIM_INLINE Splitter()
				:	SoundFilter( 1, 1 )
			{
			}
			
			
			
			
			/// Create a new splitter which has the specified number of outputs.
			RIM_INLINE Splitter( Size numOutputs )
				:	SoundFilter( 1, numOutputs )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Output Count Accessor Methods
			
			
			
			
			/// Set the total number of outputs that this splitter can have.
			RIM_INLINE void setOutputCount( Size newNumOutputs )
			{
				SoundFilter::setOutputCount( newNumOutputs );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Attribute Accessor Methods
			
			
			
			
			/// Return a human-readable name for this splitter.
			/**
			  * The method returns the string "Splitter".
			  */
			virtual UTF8String getName() const;
			
			
			
			
			/// Return the manufacturer name of this splitter.
			/**
			  * The method returns the string "Headspace Sound".
			  */
			virtual UTF8String getManufacturer() const;
			
			
			
			
			/// Return an object representing the version of this splitter.
			virtual SoundFilterVersion getVersion() const;
			
			
			
			
			/// Return an object which describes the category of effect that this filter implements.
			/**
			  * This method returns the value SoundFilterCategory::ROUTING.
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
			
			
			
			
			/// A string indicating the human-readable name of this splitter.
			static const UTF8String NAME;
			
			
			
			
			/// A string indicating the manufacturer name of this splitter.
			static const UTF8String MANUFACTURER;
			
			
			
			
			/// An object indicating the version of this splitter.
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
			
			
			
			
			/// Split the sound in the first input buffer to as many output buffers as possible.
			virtual SoundFilterResult processFrame( const SoundFilterFrame& inputFrame,
													SoundFilterFrame& outputFrame, Size numSamples );
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_SPLITTER_H
