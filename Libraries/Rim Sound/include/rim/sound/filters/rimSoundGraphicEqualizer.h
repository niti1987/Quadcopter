/*
 *  rimSoundGraphicEqualizer.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 11/30/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_GRAPHIC_EQUALIZER_H
#define INCLUDE_RIM_SOUND_GRAPHIC_EQUALIZER_H


#include "rimSoundFiltersConfig.h"


#include "rimSoundFilter.h"
#include "rimSoundParametricFilter.h"
#include "rimSoundGainFilter.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that implements a 31-band graphic equalizer with variable-width filters.
/**
  * This class provides a set of 31 variable-width parametric filters at fixed frequencies
  * spaced at 1/3 octave intervals. Each filter has its own gain control and the width
  * of all filters can be adjusted together.
  */
class GraphicEqualizer : public SoundFilter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default 31-band graphic equalizer with all bands with a gain of 0dB.
			GraphicEqualizer();
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Output Gain Accessor Methods
			
			
			
			
			/// Return the linear output gain for this graphic equalizer.
			RIM_INLINE Gain getOutputGain() const
			{
				return gainFilter.getGain();
			}
			
			
			
			
			/// Return the output gain in decibels for this graphic equalizer.
			RIM_INLINE Gain getOutputGainDB() const
			{
				return gainFilter.getGainDB();
			}
			
			
			
			
			/// Set the linear output gain for this graphic equalizer.
			RIM_INLINE void setOutputGain( Gain newGain )
			{
				lockMutex();
				gainFilter.setGain( newGain );
				unlockMutex();
			}
			
			
			
			
			/// Set the output gain in decibels for this graphic equalizer.
			RIM_INLINE void setOutputGainDB( Gain newGain )
			{
				lockMutex();
				gainFilter.setGainDB( newGain );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Frequency Accessor Methods
			
			
			
			
			/// Return the number of filters (frequency bands) that this graphic equalizer has.
			RIM_INLINE Size getFilterCount() const
			{
				return filters.getSize();
			}
			
			
			
			
			/// Return the frequency of the filter at the specified index.
			/**
			  * If the specified filter index is invalid, a frequency of 0 Hz is returned.
			  */
			RIM_INLINE Float getFilterFrequency( Index filterIndex ) const
			{
				return filters[filterIndex].getFrequency();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Gain Accessor Methods
			
			
			
			
			/// Return the linear gain of the graphic EQ filter at the specified index.
			/**
			  * If the specified filter index is invalid, a gain of 0 is returned.
			  */
			RIM_INLINE Gain getFilterGain( Index filterIndex ) const
			{
				if ( filterIndex >= filters.getSize() )
					return Gain(0);
				else
					return filters[filterIndex].getGain();
			}
			
			
			
			
			/// Return the gain in decibels of the graphic EQ filter at the specified index.
			/**
			  * If the specified filter index is invalid, a gain of -infinity is returned.
			  */
			RIM_INLINE Gain getFilterGainDB( Index filterIndex ) const
			{
				if ( filterIndex >= filters.getSize() )
					return math::negativeInfinity<Float>();
				else
					return filters[filterIndex].getGainDB();
			}
			
			
			
			
			/// Set the linear gain of the graphic EQ filter at the specified index.
			/**
			  * If the specified filter index is invalid, the method has no effect.
			  */
			RIM_INLINE void setFilterGain( Index filterIndex, Gain newGain )
			{
				lockMutex();
				
				if ( filterIndex < filters.getSize() )
					filters[filterIndex].setGain( newGain );
				
				unlockMutex();
			}
			
			
			
			
			/// Set the gain in decibels of the graphic EQ filter at the specified index.
			/**
			  * If the specified filter index is invalid, the method has no effect.
			  */
			RIM_INLINE void setFilterGainDB( Index filterIndex, Gain newGain )
			{
				lockMutex();
				
				if ( filterIndex < filters.getSize() )
					filters[filterIndex].setGainDB( newGain );
				
				unlockMutex();
			}
			
			
			
			
			/// Reset all frequency bands to have a gain of 0dB, making the graphic equalizer have a flat response.
			void setFlat();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Bandwith Accessor Methods
			
			
			
			
			/// Return the Q factor used for all filters that make up this graphic equalizer.
			/**
			  * This value controls the width of the boost or cut that a filter produces.
			  * A smaller Q indicates a wider filter, while a larger Q indicates a narrower filter.
			  */
			RIM_INLINE Float getFilterQ() const
			{
				// Return the Q of the first filter since they should all be the same
				return filters[0].getQ();
			}
			
			
			
			
			/// Set the Q factor used for all filters that make up this graphic equalizer.
			/**
			  * This value controls the width of the boost or cut that a filter produces.
			  * A smaller Q indicates a wider filter, while a larger Q indicates a narrower filter.
			  *
			  * The new Q value is clamped to the range [0, +infinity].
			  */
			void setFilterQ( Float newQ );
			
			
			
			
			/// Return the octave bandwidth used for all filters that make up this graphic equalizer.
			/**
			  * This value controls the width of the boost or cut that a filter produces.
			  * A larger bandwidth indicates a wider filter, while a smaller bandwidth
			  * indicates a narrower filter.
			  *
			  * The default bandwidth is 1/3 of an octave.
			  */
			RIM_INLINE Float getFilterBandwidth() const
			{
				// Return the bandwidth of the first filter since they should all be the same
				return filters[0].getBandwidth();
			}
			
			
			
			
			/// Set the octave bandwidth used for all filters that make up this graphic equalizer.
			/**
			  * This value controls the width of the boost or cut that a filter produces.
			  * A larger bandwidth indicates a wider filter, while a smaller bandwidth
			  * indicates a narrower filter.
			  *
			  * The default bandwidth is 1/3 of an octave.
			  */
			void setFilterBandwidth( Float newBandwidth );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Attribute Accessor Methods
			
			
			
			
			/// Return a human-readable name for this parametric filter.
			/**
			  * The method returns the string "Parametric Filter".
			  */
			virtual UTF8String getName() const;
			
			
			
			
			/// Return the manufacturer name of this parametric filter.
			/**
			  * The method returns the string "Headspace Sound".
			  */
			virtual UTF8String getManufacturer() const;
			
			
			
			
			/// Return an object representing the version of this parametric filter.
			virtual SoundFilterVersion getVersion() const;
			
			
			
			
			/// Return an object which describes the category of effect that this filter implements.
			/**
			  * This method returns the value SoundFilterCategory::EQUALIZER.
			  */
			virtual SoundFilterCategory getCategory() const;
			
			
			
			
			/// Return whether or not this graphic equalizer can process audio data in-place.
			/**
			  * This method always returns TRUE, graphic equalizers can process audio data in-place.
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
			
			
			
			
			/// A string indicating the human-readable name of this graphic equalizer.
			static const UTF8String NAME;
			
			
			
			
			/// A string indicating the manufacturer name of this graphic equalizer.
			static const UTF8String MANUFACTURER;
			
			
			
			
			/// An object indicating the version of this graphic equalizer.
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
		//******	Private Stream Reset Method
			
			
			
			
			/// A method which is called whenever the filter's stream of audio is being reset.
			/**
			  * This method allows the filter to reset all parameter interpolation
			  * and processing to its initial state to avoid coloration from previous
			  * audio or parameter values.
			  */
			virtual void resetStream();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Filter Processing Methods
			
			
			
			
			/// Apply this parametric filter to the samples in the input frame and place them in the output frame.
			virtual SoundFilterResult processFrame( const SoundFilterFrame& inputFrame,
													SoundFilterFrame& outputFrame, Size numSamples );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// Define the number of parametric filters to use for a graphic equalizer.
			static const Size NUMBER_OF_FILTERS = 31;
			
			
			
			
			/// An array of the standard filter frequencies used for a 31-band graphic equalizer.
			static const Float FILTER_FREQUENCIES[NUMBER_OF_FILTERS];
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An array of the filters that make up this graphic equalizer.
			StaticArray<ParametricFilter,NUMBER_OF_FILTERS> filters;
			
			
			
			
			/// A simple filter that applies a gain factor to the output of the graphic equalizer.
			GainFilter gainFilter;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_GRAPHIC_EQUALIZER_H
