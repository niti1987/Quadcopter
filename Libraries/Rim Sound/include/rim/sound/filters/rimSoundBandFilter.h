/*
 *  rimSoundBandFilter.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 11/29/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_BAND_FILTER_H
#define INCLUDE_RIM_SOUND_BAND_FILTER_H


#include "rimSoundFiltersConfig.h"


#include "rimSoundFilter.h"
#include "rimSoundCutoffFilter.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that implements a band-pass or band-reject filter of various types.
class BandFilter : public SoundFilter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Band Filter Type Enum Declaration
			
			
			
			
			/// An enum type that denotes a certain class of band filter.
			typedef enum Type
			{
				/// A type of band filter that uses a Bufferworth design.
				/**
				  * A Butterworth filter is a type of filter that is designed to be as flat as 
				  * possible in the passband with no ripple in the stopband. The filter is -3dB at the corner
				  * frequency.
				  */
				BUTTERWORTH = 0,
				
				/// A type of band filter that uses a Linkwitz-Riley design.
				/**
				  * A Linkwitz-Riley filter is a type of filter that is designed to be allpass when
				  * summed with a corresponding opposite filter at the crossover frequency.
				  * The filter is -6dB at the corner frequency.
				  *
				  * Linkwitz-Riley filters only support orders 2, 4, 6, and 8 because of their special properties.
				  * Attempting to use an invalid order will result in the next highest valid order being
				  * used.
				  */
				LINKWITZ_RILEY = 1,
				
				/// A type of band filter that uses a Chebyshev type I design.
				/**
				  * A Chebyshev type I filter is a filter that has a steeper rolloff but at the expense
				  * of ripple in the passband.
				  */
				CHEBYSHEV_I = 2,
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Direction Enum Declaration
			
			
			
			
			/// An enum type that specifies if a filter is high-pass or low-pass.
			typedef enum Direction
			{
				/// A type of filter that filters out all frequencies outside the cutoff frequencies.
				BAND_PASS = 0,
				
				/// A type of filter that filters out all frequencies between the cutoff frequencies.
				BAND_REJECT = 1
				
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default 1st order butterworth band pass filter with band frequencies at 0 Hz and 20000 Hz.
			BandFilter();
			
			
			
			
			/// Create a band filter with the specified type, direction, order, and corner frequencies.
			/**
			  * The filter order is clamped between 1 and the maximum allowed filter order,
			  * and the corner frequencies are clamped to the range of [0,+infinity].
			  */
			BandFilter( Type newFilterType, Direction newFilterDirection,
						Size newFilterOrder, Float newFrequency1, Float newFrequency2 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Type Accessor Methods
			
			
			
			
			/// Return the type of filter that is being used.
			/**
			  * Since different types of filters have different characteristics in frequency
			  * and phase response, this value allows the user to pick the filter type best
			  * suited for their needs.
			  */
			RIM_INLINE Type getType() const
			{
				return convertFilterType( highPass.getType() );
			}
			
			
			
			
			/// Set the type of filter that is being used.
			/**
			  * Since different types of filters have different characteristics in frequency
			  * and phase response, this value allows the user to pick the filter type best
			  * suited for their needs.
			  */
			RIM_INLINE void setType( Type newFilterType )
			{
				lockMutex();
				CutoffFilter::Type cutoffType = convertFilterType( newFilterType );
				highPass.setType( cutoffType );
				lowPass.setType( cutoffType );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Direction Accessor Methods
			
			
			
			
			/// Return the direction of the filter that is being used.
			/**
			  * This value determines whether the filter behaves as a high-pass
			  * or low-pass filter.
			  */
			RIM_INLINE Direction getDirection() const
			{
				return filterDirection;
			}
			
			
			
			
			/// Set the type of filter that is being used.
			/**
			  * This value determines whether the filter behaves as a high-pass
			  * or low-pass filter.
			  */
			RIM_INLINE void setDirection( Direction newFilterDirection )
			{
				lockMutex();
				filterDirection = newFilterDirection;
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Order Accessor Methods
			
			
			
			
			/// Return the order of this band filter.
			RIM_INLINE Size getOrder() const
			{
				return highPass.getOrder();
			}
			
			
			
			
			/// Set the order of this band filter.
			/**
			  * If the specified order is not supported by this filter, the closest
			  * order to the desired order is used.
			  *
			  * The new filter order is clamped betwee 1 and the maximum allowed filter order.
			  */
			RIM_INLINE void setOrder( Size newFilterOrder )
			{
				lockMutex();
				highPass.setOrder( newFilterOrder );
				lowPass.setOrder( newFilterOrder );
				unlockMutex();
			}
			
			
			
			
			/// Return the maximum filter order allowed.
			/**
			  * All created filters will have an order less than or equal to this value
			  * and it is impossible to set the order of a filter to be greater than this
			  * value.
			  */
			RIM_INLINE Size getMaximumOrder() const
			{
				return highPass.getMaximumOrder();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Corner Frequency Accessor Methods
			
			
			
			
			/// Return the first corner frequency of this band filter.
			/**
			  * This is the frequency at which the frequency begins to be cut off by the
			  * filter. This is usually the point at which the filter is -3dB down, but 
			  * can be -6dB or other for some filter types.
			  */
			RIM_INLINE Float getFrequency1() const
			{
				return frequency1;
			}
			
			
			
			
			/// Set the first corner frequency of this band filter.
			/**
			  * This is the frequency at which the frequency begins to be cut off by the
			  * filter. This is usually the point at which the filter is -3dB down, but 
			  * can be -6dB or other for some filter types.
			  *
			  * The new corner frequency is clamped to be in the range [0,+infinity].
			  */
			RIM_INLINE void setFrequency1( Float newCornerFrequency )
			{
				lockMutex();
				frequency1 = math::max( newCornerFrequency, Float(0) );
				unlockMutex();
			}
			
			
			
			
			/// Return the first corner frequency of this band filter.
			/**
			  * This is the frequency at which the frequency begins to be cut off by the
			  * filter. This is usually the point at which the filter is -3dB down, but 
			  * can be -6dB or other for some filter types.
			  */
			RIM_INLINE Float getFrequency2() const
			{
				return frequency2;
			}
			
			
			
			
			/// Set the first corner frequency of this band filter.
			/**
			  * This is the frequency at which the frequency begins to be cut off by the
			  * filter. This is usually the point at which the filter is -3dB down, but 
			  * can be -6dB or other for some filter types.
			  *
			  * The new corner frequency is clamped to be in the range [0,+infinity].
			  */
			RIM_INLINE void setFrequency2( Float newCornerFrequency )
			{
				lockMutex();
				frequency2 = math::max( newCornerFrequency, Float(0) );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Ripple Accessor Methods
			
			
			
			
			/// Return the ripple of this band filter in dB.
			/**
			  * This parameter is only used by the Chebyshev type I and type II filters.
			  * It determines the amount of ripple in the passband (for type I) or in
			  * the stopband (for type II). A smaller ripple results in a slower
			  * rolloff in the frequency response for any given filter order.
			  *
			  * The ripple amount is initially equal to 1 dB and must be greater than 0.
			  */
			RIM_INLINE Float getRipple() const
			{
				return highPass.getRipple();
			}
			
			
			
			
			/// Set the ripple of this band filter in dB.
			/**
			  * This parameter is only used by the Chebyshev type I and type II filters.
			  * It determines the amount of ripple in the passband (for type I) or in
			  * the stopband (for type II). A smaller ripple results in a slower
			  * rolloff in the frequency response for any given filter order.
			  *
			  * The ripple amount is initially equal to 1 dB and is clamped to be greater than 0.
			  */
			RIM_INLINE void setRipple( Float newRipple )
			{
				lockMutex();
				highPass.setRipple( newRipple );
				lowPass.setRipple( newRipple );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Attribute Accessor Methods
			
			
			
			
			/// Return a human-readable name for this band filter.
			/**
			  * The method returns the string "Band Filter".
			  */
			virtual UTF8String getName() const;
			
			
			
			
			/// Return the manufacturer name of this band filter.
			/**
			  * The method returns the string "Headspace Sound".
			  */
			virtual UTF8String getManufacturer() const;
			
			
			
			
			/// Return an object representing the version of this band filter.
			virtual SoundFilterVersion getVersion() const;
			
			
			
			
			/// Return an object which describes the category of effect that this filter implements.
			/**
			  * This method returns the value SoundFilterCategory::EQUALIZER.
			  */
			virtual SoundFilterCategory getCategory() const;
			
			
			
			
			/// Return whether or not this band filter can process audio data in-place.
			/**
			  * This method always returns TRUE, band filters can process audio data in-place.
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
			
			
			
			
			/// Get any special name associated with the specified value of an indexed parameter.
			virtual Bool getParameterValueName( Index parameterIndex, const FilterParameter& value, UTF8String& name ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Property Objects
			
			
			
			
			/// A string indicating the human-readable name of this band filter.
			static const UTF8String NAME;
			
			
			
			
			/// A string indicating the manufacturer name of this band filter.
			static const UTF8String MANUFACTURER;
			
			
			
			
			/// An object indicating the version of this band filter.
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
			
			
			
			
			/// Apply this band filter to the samples in the input frame and place them in the output frame.
			virtual SoundFilterResult processFrame( const SoundFilterFrame& inputFrame,
													SoundFilterFrame& outputFrame, Size numSamples );
			
			
			
			
			/// Convert the specified band filter type enum to a cutoff filter type enum.
			RIM_INLINE static CutoffFilter::Type convertFilterType( Type newType )
			{
				switch ( newType )
				{
					case BUTTERWORTH:
						return CutoffFilter::BUTTERWORTH;
					case LINKWITZ_RILEY:
						return CutoffFilter::LINKWITZ_RILEY;
					case CHEBYSHEV_I:
						return CutoffFilter::CHEBYSHEV_I;
				}
				
				return CutoffFilter::BUTTERWORTH;
			}
			
			
			
			
			/// Convert the specified cutoff filter type enum to a band filter type enum.
			RIM_INLINE static Type convertFilterType( CutoffFilter::Type newType )
			{
				switch ( newType )
				{
					case CutoffFilter::BUTTERWORTH:
						return BUTTERWORTH;
					case CutoffFilter::LINKWITZ_RILEY:
						return LINKWITZ_RILEY;
					case CutoffFilter::CHEBYSHEV_I:
						return CHEBYSHEV_I;
				}
				
				return BUTTERWORTH;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum representing the direction of this band filter.
			/**
			  * This value specifies whether the filter is a band-pass or band-reject filter.
			  */
			Direction filterDirection;
			
			
			
			
			/// A cutoff filter that filters out low frequencies for this band filter.
			CutoffFilter highPass;
			
			
			
			
			/// A cutoff filter that filters out high frequencies for this band filter.
			CutoffFilter lowPass;
			
			
			
			
			/// The first frequency which defines this band filter's pass-band or stop-band.
			Float frequency1;
			
			
			
			
			/// The second frequency which defines this band filter's pass-band or stop-band.
			Float frequency2;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_BAND_FILTER_H
