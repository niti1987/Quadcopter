/*
 *  rimSoundParametricEqualizer.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 11/30/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_PARAMETRIC_EQUALIZER_H
#define INCLUDE_RIM_SOUND_PARAMETRIC_EQUALIZER_H


#include "rimSoundFiltersConfig.h"


#include "rimSoundFilter.h"
#include "rimSoundParametricFilter.h"
#include "rimSoundCutoffFilter.h"
#include "rimSoundShelfFilter.h"
#include "rimSoundGainFilter.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that provides a basic 5-band parametric EQ with additional high/low shelf/pass filters.
class ParametricEqualizer : public SoundFilter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default parametric equalizer with 5 parametric filter bands.
			ParametricEqualizer();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Output Gain Accessor Methods
			
			
			
			
			/// Return the linear output gain for this parametric equalizer.
			RIM_INLINE Gain getOutputGain() const
			{
				return gainFilter.getGain();
			}
			
			
			
			
			/// Return the output gain in decibels for this parametric equalizer.
			RIM_INLINE Gain getOutputGainDB() const
			{
				return gainFilter.getGainDB();
			}
			
			
			
			
			/// Set the linear output gain for this parametric equalizer.
			RIM_INLINE void setOutputGain( Gain newGain )
			{
				lockMutex();
				gainFilter.setGain( newGain );
				unlockMutex();
			}
			
			
			
			
			/// Set the output gain in decibels for this parametric equalizer.
			RIM_INLINE void setOutputGainDB( Gain newGain )
			{
				lockMutex();
				gainFilter.setGainDB( newGain );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parametric Filter Accessor Methods
			
			
			
			
			/// Return the number of parametric EQ filters that make up this parametric equalizer.
			RIM_INLINE Size getParametricCount() const
			{
				return parametrics.getSize();
			}
			
			
			
			
			/// Set the number of parametric EQ filters that make up this parametric equalizer.
			/**
			  * If the specified new number of parametric filters is less than the old number,
			  * the unnecessary filters are removed and deleted. If the new number is greater,
			  * the new frequency bands are initialzed to have the center frequency of 1000Hz.
			  */
			RIM_INLINE void setParametricCount( Size newNumberOfParametrics )
			{
				lockMutex();
				parametrics.setSize( newNumberOfParametrics );
				unlockMutex();
			}
			
			
			
			
			/// Return whether or not the parametric filter within this equalizer at the specified index is enabled.
			RIM_INLINE Bool getParametricIsEnabled( Index parametricIndex ) const
			{
				if ( parametricIndex < parametrics.getSize() )
					return parametrics[parametricIndex].isEnabled;
				else
					return false;
			}
			
			
			
			
			/// Set whether or not the parametric filter within this equalizer at the specified index is enabled.
			RIM_INLINE void setParametricIsEnabled( Index parametricIndex, Bool newIsEnabled )
			{
				lockMutex();
				if ( parametricIndex < parametrics.getSize() )
					parametrics[parametricIndex].isEnabled = newIsEnabled;
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parametric Filter Gain Accessor Methods
			
			
			
			
			/// Return the linear gain of the parametric filter within this equalizer at the specified index.
			RIM_INLINE Gain getParametricGain( Index parametricIndex ) const
			{
				if ( parametricIndex < parametrics.getSize() )
					return parametrics[parametricIndex].filter.getGain();
				else
					return Gain(0);
			}
			
			
			
			
			/// Return the gain in decibels of the parametric filter within this equalizer at the specified index.
			RIM_INLINE Gain getParametricGainDB( Index parametricIndex ) const
			{
				if ( parametricIndex < parametrics.getSize() )
					return parametrics[parametricIndex].filter.getGainDB();
				else
					return math::negativeInfinity<Gain>();
			}
			
			
			
			
			/// Set the linear gain of the parametric filter within this equalizer at the specified index.
			RIM_INLINE void setParametricGain( Index parametricIndex, Gain newGain )
			{
				lockMutex();
				if ( parametricIndex < parametrics.getSize() )
					parametrics[parametricIndex].filter.setGain( newGain );
				unlockMutex();
			}
			
			
			
			
			/// Set the gain in decibels of the parametric filter within this equalizer at the specified index.
			RIM_INLINE void setParametricGainDB( Index parametricIndex, Gain newGain )
			{
				lockMutex();
				if ( parametricIndex < parametrics.getSize() )
					parametrics[parametricIndex].filter.setGainDB( newGain );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parametric Filter Frequency Accessor Methods
			
			
			
			
			/// Return the center frequency of the parametric filter within this equalizer at the specified index.
			RIM_INLINE Float getParametricFrequency( Index parametricIndex ) const
			{
				if ( parametricIndex < parametrics.getSize() )
					return parametrics[parametricIndex].filter.getFrequency();
				else
					return Float(0);
			}
			
			
			
			
			/// Set the center frequency of the parametric filter within this equalizer at the specified index.
			RIM_INLINE void setParametricFrequency( Index parametricIndex, Float newFrequency )
			{
				lockMutex();
				if ( parametricIndex < parametrics.getSize() )
					parametrics[parametricIndex].filter.setFrequency( newFrequency );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parametric Filter Bandwidth Accessor Methods
			
			
			
			
			/// Return the Q factor of the parametric filter within this equalizer at the specified index.
			RIM_INLINE Float getParametricQ( Index parametricIndex ) const
			{
				if ( parametricIndex < parametrics.getSize() )
					return parametrics[parametricIndex].filter.getQ();
				else
					return Float(0);
			}
			
			
			
			
			/// Set the Q factor of the parametric filter within this equalizer at the specified index.
			RIM_INLINE void setParametricQ( Index parametricIndex, Float newQ )
			{
				lockMutex();
				if ( parametricIndex < parametrics.getSize() )
					parametrics[parametricIndex].filter.setQ( newQ );
				unlockMutex();
			}
			
			
			
			
			/// Return the bandwidth in octaves of the parametric filter within this equalizer at the specified index.
			RIM_INLINE Float getParametricBandwidth( Index parametricIndex ) const
			{
				if ( parametricIndex < parametrics.getSize() )
					return parametrics[parametricIndex].filter.getBandwidth();
				else
					return Float(0);
			}
			
			
			
			
			/// Set the bandwidth in octaves of the parametric filter within this equalizer at the specified index.
			RIM_INLINE void setParametricBandwidth( Index parametricIndex, Float newBandwidth )
			{
				lockMutex();
				if ( parametricIndex < parametrics.getSize() )
					parametrics[parametricIndex].filter.setBandwidth( newBandwidth );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	High-Pass Filter Frequency Accessor Methods
			
			
			
			
			/// Return the corner frequency of this parametric equalizer's high pass filter.
			RIM_INLINE Float getHighPassFrequency() const
			{
				return highPass.getFrequency();
			}
			
			
			
			
			/// Set the corner frequency of this parametric equalizer's high pass filter.
			RIM_INLINE void setHighPassFrequency( Float newFrequency )
			{
				lockMutex();
				highPass.setFrequency( newFrequency );
				unlockMutex();
			}
			
			
			
			
			/// Return the order of this parametric equalizer's high pass filter.
			RIM_INLINE Size getHighPassOrder() const
			{
				return highPass.getOrder();
			}
			
			
			
			
			/// Set the order of this parametric equalizer's high pass filter.
			RIM_INLINE void setHighPassOrder( Size newOrder )
			{
				lockMutex();
				highPass.setOrder( newOrder );
				unlockMutex();
			}
			
			
			
			
			/// Return whether or not the high pass filter of this parametric equalizer is enabled.
			RIM_INLINE Bool getHighPassIsEnabled() const
			{
				return highPassEnabled;
			}
			
			
			
			
			/// Set whether or not the high pass filter of this parametric equalizer is enabled.
			RIM_INLINE void setHighPassIsEnabled( Bool newIsEnabled )
			{
				lockMutex();
				highPassEnabled = newIsEnabled;
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Low-Pass Filter Attribute Accessor Methods
			
			
			
			
			/// Return the corner frequency of this parametric equalizer's low pass filter.
			RIM_INLINE Float getLowPassFrequency() const
			{
				return lowPass.getFrequency();
			}
			
			
			
			
			/// Set the corner frequency of this parametric equalizer's low pass filter.
			RIM_INLINE void setLowPassFrequency( Float newFrequency )
			{
				lockMutex();
				lowPass.setFrequency( newFrequency );
				unlockMutex();
			}
			
			
			
			
			/// Return the order of this parametric equalizer's low pass filter.
			RIM_INLINE Size getLowPassOrder() const
			{
				return lowPass.getOrder();
			}
			
			
			
			
			/// Set the order of this parametric equalizer's low pass filter.
			RIM_INLINE void setLowPassOrder( Size newOrder )
			{
				lockMutex();
				lowPass.setOrder( newOrder );
				unlockMutex();
			}
			
			
			
			
			/// Return whether or not the low pass filter of this parametric equalizer is enabled.
			RIM_INLINE Bool getLowPassIsEnabled() const
			{
				return lowPassEnabled;
			}
			
			
			
			
			/// Set whether or not the low pass filter of this parametric equalizer is enabled.
			RIM_INLINE void setLowPassIsEnabled( Bool newIsEnabled )
			{
				lockMutex();
				lowPassEnabled = newIsEnabled;
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Low Shelf Filter Attribute Accessor Methods
			
			
			
			
			/// Return the corner frequency of this parametric equalizer's low shelf filter.
			RIM_INLINE Float getLowShelfFrequency() const
			{
				return lowShelf.getFrequency();
			}
			
			
			
			
			/// Set the corner frequency of this parametric equalizer's low shelf filter.
			RIM_INLINE void setLowShelfFrequency( Float newFrequency )
			{
				lockMutex();
				lowShelf.setFrequency( newFrequency );
				unlockMutex();
			}
			
			
			
			
			/// Return the linear gain of this parametric equalizer's low shelf filter.
			RIM_INLINE Gain getLowShelfGain() const
			{
				return lowShelf.getGain();
			}
			
			
			
			
			/// Return the gain in decibels of this parametric equalizer's low shelf filter.
			RIM_INLINE Gain getLowShelfGainDB() const
			{
				return lowShelf.getGainDB();
			}
			
			
			
			
			/// Set the linear gain of this parametric equalizer's low shelf filter.
			RIM_INLINE void setLowShelfGain( Gain newGain )
			{
				lockMutex();
				lowShelf.setGain( newGain );
				unlockMutex();
			}
			
			
			
			
			/// Set the gain in decibels of this parametric equalizer's low shelf filter.
			RIM_INLINE void setLowShelfGainDB( Gain newGain )
			{
				lockMutex();
				lowShelf.setGainDB( newGain );
				unlockMutex();
			}
			
			
			
			
			/// Return the slope of this parametric equalizer's low shelf filter.
			RIM_INLINE Float getLowShelfSlope() const
			{
				return lowShelf.getGain();
			}

			
			
			
			/// Set the slope of this parametric equalizer's low shelf filter.
			RIM_INLINE void setLowShelfSlope( Float newSlope )
			{
				lockMutex();
				lowShelf.setSlope( newSlope );
				unlockMutex();
			}
			
			
			
			
			/// Return whether or not the low shelf filter of this parametric equalizer is enabled.
			RIM_INLINE Bool getLowShelfIsEnabled() const
			{
				return lowShelfEnabled;
			}
			
			
			
			
			/// Set whether or not the low shelf filter of this parametric equalizer is enabled.
			RIM_INLINE void setLowShelfIsEnabled( Bool newIsEnabled )
			{
				lockMutex();
				lowShelfEnabled = newIsEnabled;
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	High Shelf Filter Attribute Accessor Methods
			
			
			
			
			/// Return the corner frequency of this parametric equalizer's high shelf filter.
			RIM_INLINE Float getHighShelfFrequency() const
			{
				return highShelf.getFrequency();
			}
			
			
			
			
			/// Set the corner frequency of this parametric equalizer's high shelf filter.
			RIM_INLINE void setHighShelfFrequency( Float newFrequency )
			{
				lockMutex();
				highShelf.setFrequency( newFrequency );
				unlockMutex();
			}
			
			
			
			
			/// Return the linear gain of this parametric equalizer's high shelf filter.
			RIM_INLINE Gain getHighShelfGain() const
			{
				return highShelf.getGain();
			}
			
			
			
			
			/// Return the gain in decibels of this parametric equalizer's high shelf filter.
			RIM_INLINE Gain getHighShelfGainDB() const
			{
				return highShelf.getGainDB();
			}
			
			
			
			
			/// Set the linear gain of this parametric equalizer's high shelf filter.
			RIM_INLINE void setHighShelfGain( Gain newGain )
			{
				lockMutex();
				highShelf.setGain( newGain );
				unlockMutex();
			}
			
			
			
			
			/// Set the gain in decibels of this parametric equalizer's high shelf filter.
			RIM_INLINE void setHighShelfGainDB( Gain newGain )
			{
				lockMutex();
				highShelf.setGainDB( newGain );
				unlockMutex();
			}
			
			
			
			
			/// Return the slope of this parametric equalizer's high shelf filter.
			RIM_INLINE Float getHighShelfSlope() const
			{
				return highShelf.getGain();
			}

			
			
			
			/// Set the slope of this parametric equalizer's high shelf filter.
			RIM_INLINE void setHighShelfSlope( Float newSlope )
			{
				lockMutex();
				highShelf.setSlope( newSlope );
				unlockMutex();
			}
			
			
			
			
			/// Return whether or not the high shelf filter of this parametric equalizer is enabled.
			RIM_INLINE Bool getHighShelfIsEnabled() const
			{
				return highShelfEnabled;
			}
			
			
			
			
			/// Set whether or not the high shelf filter of this parametric equalizer is enabled.
			RIM_INLINE void setHighShelfIsEnabled( Bool newIsEnabled )
			{
				lockMutex();
				highShelfEnabled = newIsEnabled;
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Attribute Accessor Methods
			
			
			
			
			/// Return a human-readable name for this parametric equalizer.
			/**
			  * The method returns the string "Parametric Equalizer".
			  */
			virtual UTF8String getName() const;
			
			
			
			
			/// Return the manufacturer name of this parametric equalizer.
			/**
			  * The method returns the string "Headspace Sound".
			  */
			virtual UTF8String getManufacturer() const;
			
			
			
			
			/// Return an object representing the version of this parametric equalizer.
			virtual SoundFilterVersion getVersion() const;
			
			
			
			
			/// Return an object which describes the category of effect that this filter implements.
			/**
			  * This method returns the value SoundFilterCategory::EQUALIZER.
			  */
			virtual SoundFilterCategory getCategory() const;
			
			
			
			
			/// Return whether or not this parametric equalizer can process audio data in-place.
			/**
			  * This method always returns TRUE, parameteric equalizers can process audio data in-place.
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
			
			
			
			
			/// A string indicating the human-readable name of this parametric equalizer.
			static const UTF8String NAME;
			
			
			
			
			/// A string indicating the manufacturer name of this parametric equalizer.
			static const UTF8String MANUFACTURER;
			
			
			
			
			/// An object indicating the version of this parametric equalizer.
			static const SoundFilterVersion VERSION;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A class which holds information about a single band of parametric EQ.
			class ParametricFilterBand
			{
				public:
					
					/// Create a new parametric filter band, enabled by default.
					RIM_INLINE ParametricFilterBand()
						:	filter(),
							isEnabled( true )
					{
					}
					
					
					/// The parametric filter associated with this frequency band.
					ParametricFilter filter;
					
					
					/// A boolean value indicating whether or not this frequency band is enabled.
					Bool isEnabled;
					
					
			};
			
			
			
			
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
			
			
			
			
			/// Return whether or not the specified linear gain value is very close to unity gain.
			RIM_INLINE static Bool gainIsUnity( Gain linearGain )
			{
				return math::abs( Gain(1) - linearGain ) < 2*math::epsilon<Gain>();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// Define the default number of parametric filters that should make up a parametric equalizer.
			static const Size DEFAULT_NUMBER_OF_PARAMETRIC_FILTERS = 5;
			
			
			
			
			/// Define the default center frequencies of the parametric filters that make up this equalizer.
			static const Float DEFAULT_PARAMETRIC_FREQUENCIES[DEFAULT_NUMBER_OF_PARAMETRIC_FILTERS];
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A high pass filter for this parametric equalizer.
			CutoffFilter highPass;
			
			
			
			
			/// A low shelf filter for this parametric equalizer.
			ShelfFilter lowShelf;
			
			
			
			
			/// An array of the parametric filters that make up this parametric equalizer.
			Array<ParametricFilterBand> parametrics;
			
			
			
			
			/// A high shelf filter for this parametric equalizer.
			ShelfFilter highShelf;
			
			
			
			
			/// A low pass filter for this parametric equalizer.
			CutoffFilter lowPass;
			
			
			
			
			/// A master gain filter for this parametric equalizer.
			GainFilter gainFilter;
			
			
			
			
			/// A boolean value indicating whether or not the high pass filter is enabled.
			Bool highPassEnabled;
			
			
			
			
			/// A boolean value indicating whether or not the low pass filter is enabled.
			Bool lowPassEnabled;
			
			
			
			
			/// A boolean value indicating whether or not the low shelf filter is enabled.
			Bool lowShelfEnabled;
			
			
			
			
			/// A boolean value indicating whether or not the high shelf filter is enabled.
			Bool highShelfEnabled;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_PARAMETRIC_EQUALIZER_H
