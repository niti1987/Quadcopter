/*
 *  rimSoundSaturator.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/8/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_SATURATOR_H
#define INCLUDE_RIM_SOUND_SATURATOR_H


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
/// A class that provides a way to saturate audio in a frequency-dependent manner.
/**
  * A Saturator consists of a 2-way crossover which splits the input audio into
  * low and high-frequency bands. Each band can then be saturated using a soft-clipping
  * function independently before being added back together to produce the output.
  *
  * This effect can be used to fatten up and even out low frequencies with extra harmonics
  * without adding nasty distortion. It emulates tape saturation on each frequency band
  * independently, giving the user more control over the final sound.
  *
  * The saturator uses an all-pass Linwitz-Riley crossover to split the audio into
  * frequency bands. The saturator allows the low-frequency band to also be low-pass
  * filtered using half of the crossover filter, producing cleaner low-frequency
  * output. Since 2N-order Linkwitz-Riley crossovers are the same as two N-order
  * Butterworth filters in series, the crossover uses the first low pass filter to
  * fliter out the high frequencies, then uses the second one after saturation to
  * filter out unwanted harmonics added by the saturation, producing a (mostly) all-pass
  * result.
  */
class Saturator : public SoundFilter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new saturator filter with the default input and output gains of 1.
			Saturator();
			
			
			
			
			/// Create an exact copy of another saturator.
			Saturator( const Saturator& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this saturator, releasing all associated resources.
			~Saturator();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of another saturator to this one.
			Saturator& operator = ( const Saturator& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Input Gain Accessor Methods
			
			
			
			
			/// Return the current linear input gain factor of this saturator filter.
			/**
			  * This is the gain applied to the input signal before being sent to the
			  * clipping function. A higher value will result in more noticeable clipping.
			  */
			RIM_INLINE Gain getInputGain() const
			{
				return targetInputGain;
			}
			
			
			
			
			/// Return the current input gain factor in decibels of this saturator filter.
			/**
			  * This is the gain applied to the input signal before being sent to the
			  * clipping function. A higher value will result in more noticeable clipping.
			  */
			RIM_INLINE Gain getInputGainDB() const
			{
				return util::linearToDB( targetInputGain );
			}
			
			
			
			
			/// Set the target linear input gain for this saturator filter.
			/**
			  * This is the gain applied to the input signal before being sent to the
			  * clipping function. A higher value will result in more noticeable clipping.
			  */
			RIM_INLINE void setInputGain( Gain newInputGain )
			{
				lockMutex();
				targetInputGain = newInputGain;
				unlockMutex();
			}
			
			
			
			
			/// Set the target input gain in decibels for this saturator filter.
			/**
			  * This is the gain applied to the input signal before being sent to the
			  * clipping function. A higher value will result in more noticeable clipping.
			  */
			RIM_INLINE void setInputGainDB( Gain newDBInputGain )
			{
				lockMutex();
				targetInputGain = util::dbToLinear( newDBInputGain );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Output Gain Accessor Methods
			
			
			
			
			/// Return the current linear output gain factor of this saturator filter.
			/**
			  * This is the gain applied to the signal after being sent to the
			  * clipping function. This value is used to modify the final level
			  * of the clipped signal.
			  */
			RIM_INLINE Gain getOutputGain() const
			{
				return targetOutputGain;
			}
			
			
			
			
			/// Return the current output gain factor in decibels of this saturator filter.
			/**
			  * This is the gain applied to the signal after being sent to the
			  * clipping function. This value is used to modify the final level
			  * of the clipped signal.
			  */
			RIM_INLINE Gain getOutputGainDB() const
			{
				return util::linearToDB( targetOutputGain );
			}
			
			
			
			
			/// Set the target linear output gain for this saturator filter.
			/**
			  * This is the gain applied to the signal after being sent to the
			  * clipping function. This value is used to modify the final level
			  * of the clipped signal.
			  */
			RIM_INLINE void setOutputGain( Gain newOutputGain )
			{
				lockMutex();
				targetInputGain = newOutputGain;
				unlockMutex();
			}
			
			
			
			
			/// Set the target output gain in decibels for this saturator filter.
			/**
			  * This is the gain applied to the signal after being sent to the
			  * clipping function. This value is used to modify the final level
			  * of the clipped signal.
			  */
			RIM_INLINE void setOutputGainDB( Gain newDBOutputGain )
			{
				lockMutex();
				targetOutputGain = util::dbToLinear( newDBOutputGain );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Crossover Filter Attribute Accessor Methods
			
			
			
			
			/// Return whether or not this saturator filter's crossover filter is enabled.
			RIM_INLINE Bool getCrossoverIsEnabled() const
			{
				return crossoverEnabled;
			}
			
			
			
			
			/// Set whether or not this saturator filter's crossover is enabled.
			RIM_INLINE void setCrossoverIsEnabled( Bool newCrossoverIsEnabled )
			{
				lockMutex();
				crossoverEnabled = newCrossoverIsEnabled;
				unlockMutex();
			}
			
			
			
			
			/// Return the low pass filter frequency of this saturator filter.
			RIM_INLINE Float getCrossoverFrequency() const
			{
				return crossoverFrequency;
			}
			
			
			
			
			/// Set the crossover frequency of this saturator filter.
			/**
			  * The default crossover frequency is 1000 Hz.
			  * 
			  * The new crossover frequency is clamped to the range [0,infinity].
			  */
			void setCrossoverFrequency( Float newCrossoverFrequency )
			{
				lockMutex();
				crossoverFrequency = math::max( newCrossoverFrequency, Float(0) );
				unlockMutex();
			}
			
			
			
			
			/// Return the filter order of this saturator filter's crossover.
			/**
			  * This value determines the slope of the crossover transition,
			  * with 6 dB/octave for each successive filter order. The default
			  * crossover order is 4.
			  */
			RIM_INLINE Size getCrossoverOrder() const
			{
				return crossoverOrder;
			}
			
			
			
			
			/// Set the crossover filter order of this saturator filter.
			/**
			  * This value determines the slope of the crossover transition,
			  * with 6 dB/octave for each successive filter order. The default
			  * crossover order is 4.
			  *
			  * Valid values are the even numbers 2, 4, 6, and 8. Other values
			  * are clamped to the range [2,8] and rounded up to the next highest
			  * even number.
			  */
			void setCrossoverOrder( Size newCrossoverOrder )
			{
				lockMutex();
				crossoverOrder = math::nextMultiple( math::clamp( newCrossoverOrder, Size(2), Size(8) ), Size(2) );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Low Effect Enabled Accessor Methods
			
			
			
			
			/// Return whether or not the low frequency saturation effect is enabled.
			/**
			  * If not enabled, the saturator just pass-throughs the low frequency audio.
			  */
			RIM_INLINE Bool getLowEffectIsEnabled() const
			{
				return lowEffectEnabled;
			}
			
			
			
			
			/// Set whether or not the low frequency saturation effect is enabled.
			/**
			  * If not enabled, the saturator just pass-throughs the low frequency audio.
			  */
			RIM_INLINE void setLowEffectIsEnabled( Bool newLowEffectEnabled )
			{
				lockMutex();
				lowEffectEnabled = newLowEffectEnabled;
				unlockMutex();
			}
			
			
			
			
			/// Return whether or not the low frequency saturation effect is enabled.
			RIM_INLINE Bool getLowFilterIsEnabled() const
			{
				return lowFilterEnabled;
			}
			
			
			
			
			/// Set whether or not the low frequency low pass filter is enabled.
			RIM_INLINE void setLowFilterIsEnabled( Bool newLowFilterEnabled )
			{
				lockMutex();
				lowFilterEnabled = newLowFilterEnabled;
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Low Drive Accessor Methods
			
			
			
			
			/// Return the current linear input gain factor for the low frequencies of the saturator.
			/**
			  * This is the gain applied to the low-frequency input signal before being sent to the
			  * clipping function. A higher value will result in more noticeable clipping.
			  */
			RIM_INLINE Gain getLowDrive() const
			{
				return targetLowDrive;
			}
			
			
			
			
			/// Return the current input gain in decibels for the low frequencies of the saturator.
			/**
			  * This is the gain applied to the low-frequency input signal before being sent to the
			  * clipping function. A higher value will result in more noticeable clipping.
			  */
			RIM_INLINE Gain getLowDriveDB() const
			{
				return util::linearToDB( targetLowDrive );
			}
			
			
			
			
			/// Set the current linear input gain factor for the low frequencies of the saturator.
			/**
			  * This is the gain applied to the low-frequency input signal before being sent to the
			  * clipping function. A higher value will result in more noticeable clipping.
			  */
			RIM_INLINE void setLowDrive( Gain newLowDrive )
			{
				lockMutex();
				targetLowDrive = newLowDrive;
				unlockMutex();
			}
			
			
			
			
			/// Set the current input gain in decibels for the low frequencies of the saturator.
			/**
			  * This is the gain applied to the low-frequency input signal before being sent to the
			  * clipping function. A higher value will result in more noticeable clipping.
			  */
			RIM_INLINE void setLowDriveDB( Gain newDBLowDrive )
			{
				lockMutex();
				targetLowDrive = util::dbToLinear( newDBLowDrive );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Low Gain Accessor Methods
			
			
			
			
			/// Return the current linear output gain factor for the low frequencies of the saturator.
			/**
			  * This is the gain applied to the low-frequency signal after being sent to the
			  * clipping function.
			  */
			RIM_INLINE Gain getLowGain() const
			{
				return targetLowOutputGain;
			}
			
			
			
			
			/// Return the current output gain in decibels for the low frequencies of the saturator.
			/**
			  * This is the gain applied to the low-frequency signal after being sent to the
			  * clipping function.
			  */
			RIM_INLINE Gain getLowGainDB() const
			{
				return util::linearToDB( targetLowOutputGain );
			}
			
			
			
			
			/// Set the current linear output gain factor for the low frequencies of the saturator.
			/**
			  * This is the gain applied to the low-frequency signal after being sent to the
			  * clipping function.
			  */
			RIM_INLINE void setLowGain( Gain newLowGain )
			{
				lockMutex();
				targetLowOutputGain = newLowGain;
				unlockMutex();
			}
			
			
			
			
			/// Set the current output gain in decibels for the low frequencies of the saturator.
			/**
			  * This is the gain applied to the low-frequency signal after being sent to the
			  * clipping function.
			  */
			RIM_INLINE void setLowGainDB( Gain newDBLowGain )
			{
				lockMutex();
				targetLowOutputGain = util::dbToLinear( newDBLowGain );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	High Effect Enabled Accessor Methods
			
			
			
			
			/// Return whether or not the high frequency saturation effect is enabled.
			/**
			  * If not enabled, the saturator just pass-throughs the high frequency audio.
			  */
			RIM_INLINE Bool getHighEffectIsEnabled() const
			{
				return highEffectEnabled;
			}
			
			
			
			
			/// Set whether or not the high frequency saturation effect is enabled.
			/**
			  * If not enabled, the saturator just pass-throughs the high frequency audio.
			  */
			RIM_INLINE void setHighEffectIsEnabled( Bool newHighEffectEnabled )
			{
				lockMutex();
				highEffectEnabled = newHighEffectEnabled;
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	High Drive Accessor Methods
			
			
			
			
			/// Return the current linear input gain factor for the high frequencies of the saturator.
			/**
			  * This is the gain applied to the high-frequency input signal before being sent to the
			  * clipping function. A higher value will result in more noticeable clipping.
			  */
			RIM_INLINE Gain getHighDrive() const
			{
				return targetHighDrive;
			}
			
			
			
			
			/// Return the current input gain in decibels for the high frequencies of the saturator.
			/**
			  * This is the gain applied to the high-frequency input signal before being sent to the
			  * clipping function. A higher value will result in more noticeable clipping.
			  */
			RIM_INLINE Gain getHighDriveDB() const
			{
				return util::linearToDB( targetHighDrive );
			}
			
			
			
			
			/// Set the current linear input gain factor for the high frequencies of the saturator.
			/**
			  * This is the gain applied to the high-frequency input signal before being sent to the
			  * clipping function. A higher value will result in more noticeable clipping.
			  */
			RIM_INLINE void setHighDrive( Gain newLowDrive )
			{
				lockMutex();
				targetHighDrive = newLowDrive;
				unlockMutex();
			}
			
			
			
			
			/// Set the current input gain in decibels for the high frequencies of the saturator.
			/**
			  * This is the gain applied to the high-frequency input signal before being sent to the
			  * clipping function. A higher value will result in more noticeable clipping.
			  */
			RIM_INLINE void setHighDriveDB( Gain newDBHighDrive )
			{
				lockMutex();
				targetHighDrive = util::dbToLinear( newDBHighDrive );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	High Gain Accessor Methods
			
			
			
			
			/// Return the current linear output gain factor for the high frequencies of the saturator.
			/**
			  * This is the gain applied to the high-frequency signal after being sent to the
			  * clipping function.
			  */
			RIM_INLINE Gain getHighGain() const
			{
				return targetHighOutputGain;
			}
			
			
			
			
			/// Return the current output gain in decibels for the high frequencies of the saturator.
			/**
			  * This is the gain applied to the high-frequency signal after being sent to the
			  * clipping function.
			  */
			RIM_INLINE Gain getHighGainDB() const
			{
				return util::linearToDB( targetHighOutputGain );
			}
			
			
			
			
			/// Set the current linear output gain factor for the high frequencies of the saturator.
			/**
			  * This is the gain applied to the high-frequency signal after being sent to the
			  * clipping function.
			  */
			RIM_INLINE void setHighGain( Gain newHighGain )
			{
				lockMutex();
				targetHighOutputGain = newHighGain;
				unlockMutex();
			}
			
			
			
			
			/// Set the current output gain in decibels for the high frequencies of the saturator.
			/**
			  * This is the gain applied to the high-frequency signal after being sent to the
			  * clipping function.
			  */
			RIM_INLINE void setHighGainDB( Gain newDBHighGain )
			{
				lockMutex();
				targetHighOutputGain = util::dbToLinear( newDBHighGain );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Low Pass Filter Attribute Accessor Methods
			
			
			
			
			/// Return whether or not this saturation filter's low pass filter is enabled.
			RIM_INLINE Bool getLowPassIsEnabled() const
			{
				return lowPassEnabled;
			}
			
			
			
			
			/// Set whether or not this saturation filter's low pass filter is enabled.
			RIM_INLINE void setLowPassIsEnabled( Bool newLowPassIsEnabled )
			{
				lockMutex();
				lowPassEnabled = newLowPassIsEnabled;
				unlockMutex();
			}
			
			
			
			
			/// Return the low pass filter frequency of this saturation filter.
			RIM_INLINE Float getLowPassFrequency() const
			{
				return lowPassFrequency;
			}
			
			
			
			
			/// Set the low pass filter frequency of this saturation filter.
			/**
			  * The new low pass frequency is clamped to the range [0,infinity].
			  */
			RIM_INLINE void setLowPassFrequency( Float newLowPassFrequency )
			{
				lockMutex();
				lowPassFrequency = math::max( newLowPassFrequency, Float(0) );
				unlockMutex();
			}
			
			
			
			
			/// Return the low pass filter order of this saturation filter.
			RIM_INLINE Size getLowPassOrder() const
			{
				return lowPassOrder;
			}
			
			
			
			
			/// Set the low pass filter order of this saturation filter.
			/**
			  * The new low pass order is clamped to the range [1,100].
			  */
			RIM_INLINE void setLowPassOrder( Size newLowPassOrder )
			{
				lockMutex();
				lowPassOrder = math::clamp( newLowPassOrder, Size(1), Size(100) );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Frequency Band Solo Accessor Methods
			
			
			
			
			/// Return whether or not the low frequency band is currently being soloed.
			RIM_INLINE Bool getLowsAreSoloed() const
			{
				return lowSolo;
			}
			
			
			
			
			/// Return whether or not the low frequency band is currently being soloed.
			RIM_INLINE void setLowsAreSoloed( Bool newLowsSoloed )
			{
				lowSolo = newLowsSoloed;
			}
			
			
			
			
			/// Return whether or not the high frequency band is currently being soloed.
			RIM_INLINE Bool getHighsAreSoloed() const
			{
				return highSolo;
			}
			
			
			
			
			/// Return whether or not the high frequency band is currently being soloed.
			RIM_INLINE void setHighsAreSoloed( Bool newHighsSoloed )
			{
				highSolo = newHighsSoloed;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Attribute Accessor Methods
			
			
			
			
			/// Return a human-readable name for this saturator filter.
			/**
			  * The method returns the string "Saturator".
			  */
			virtual UTF8String getName() const;
			
			
			
			
			/// Return the manufacturer name of this saturator filter.
			/**
			  * The method returns the string "Headspace Sound".
			  */
			virtual UTF8String getManufacturer() const;
			
			
			
			
			/// Return an object representing the version of this saturator filter.
			virtual SoundFilterVersion getVersion() const;
			
			
			
			
			/// Return an object which describes the category of effect that this filter implements.
			/**
			  * This method returns the value SoundFilterCategory::DISTORTION.
			  */
			virtual SoundFilterCategory getCategory() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Parameter Accessor Methods
			
			
			
			
			/// Return the total number of generic accessible parameters this saturator filter has.
			virtual Size getParameterCount() const;
			
			
			
			
			/// Get information about the saturator filter parameter at the specified index.
			virtual Bool getParameterInfo( Index parameterIndex, FilterParameterInfo& info ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Property Objects
			
			
			
			
			/// A string indicating the human-readable name of this saturator filter.
			static const UTF8String NAME;
			
			
			
			
			/// A string indicating the manufacturer name of this saturator filter.
			static const UTF8String MANUFACTURER;
			
			
			
			
			/// An object indicating the version of this saturator filter.
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
			
			
			
			
			/// Apply a saturator function to the samples in the input frame and write the output to the output frame.
			virtual SoundFilterResult processFrame( const SoundFilterFrame& inputFrame,
													SoundFilterFrame& outputFrame, Size numSamples );
			
			
			
			
			/// Apply an interpolated gain to the specified input sound buffer and place the result in the output buffer.
			RIM_INLINE static void applyGain( const SoundBuffer& inputBuffer, SoundBuffer& outputBuffer, Size numSamples,
											Gain startingGain, Gain gainChangePerSample, Gain& finalGain );
			
			
			
			
			/// Saturate the input buffer and place the result in the output buffer using the given parameters.
			RIM_INLINE static void saturate( const SoundBuffer& inputBuffer, SoundBuffer& outputBuffer, Size numSamples,
											Gain drive, Gain driveChangePerSample, Gain& finalDrive,
											Gain startingGain, Gain gainChangePerSample, Gain& finalGain );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A Butterworth low-pass filter which splits the low frequencies from the source audio before saturation.
			CutoffFilter preLowPass;
			
			
			
			
			/// A Butterworth low-pass filter which filters the output of the low frequency saturation.
			CutoffFilter postLowPass;
			
			
			
			
			/// The single Linkwitz-Riley high-pass filter which splits the high frequencies from the source audio.
			CutoffFilter highPass;
			
			
			
			
			/// A Butterworth low-pass filter which filters the output of the plugin.
			CutoffFilter* finalLowPass;
			
			
			
			
			/// The current linear input gain factor applied to all input audio before being clipped.
			Gain inputGain;
			
			
			
			
			/// The target linear input gain factor, used to smooth changes in the input gain.
			Gain targetInputGain;
			
			
			
			
			/// The current linear output gain factor applied to all output audio after being clipped.
			Gain outputGain;
			
			
			
			
			/// The target linear output gain factor, used to smooth changes in the output gain.
			Gain targetOutputGain;
			
			
			
			
			/// The current linear low-frequency gain factor applied before saturation.
			Gain lowDrive;
			
			
			
			
			/// The target linear low-frequency gain factor, used to smooth changes in the low drive.
			Gain targetLowDrive;
			
			
			
			
			/// The current linear low-frequency gain factor applied after saturation.
			Gain lowOutputGain;
			
			
			
			
			/// The target linear low-frequency gain factor, used to smooth changes in the low-frequency gain.
			Gain targetLowOutputGain;
			
			
			
			
			/// The current linear high-frequency gain factor applied before saturation.
			Gain highDrive;
			
			
			
			
			/// The target linear high-frequency gain factor, used to smooth changes in the high drive.
			Gain targetHighDrive;
			
			
			
			
			/// The current linear high-frequency gain factor applied after saturation.
			Gain highOutputGain;
			
			
			
			
			/// The target linear high-frequency gain factor, used to smooth changes in the high-frequency gain.
			Gain targetHighOutputGain;
			
			
			
			
			/// The split frequency of the crossover filter for the saturator.
			Float crossoverFrequency;
			
			
			
			
			/// The order of the saturator's crossover filter that determines its slope.
			Size crossoverOrder;
			
			
			
			
			/// The frequency at which the low pass filter for the saturator is at -3dB.
			Float lowPassFrequency;
			
			
			
			
			/// The order of the saturator's low pass filter that determines its slope.
			Size lowPassOrder;
			
			
			
			
			/// A boolean value indicating whether or not this saturator's low-pass filter is enabled.
			Bool lowPassEnabled;
			
			
			
			
			/// A boolean value indicating whether or not this saturator's low-frequency clipping effect is active.
			Bool lowEffectEnabled;
			
			
			
			
			/// A boolean value indicating whether or not the low frequencies are low pass filtered after saturation.
			Bool lowFilterEnabled;
			
			
			
			
			/// A boolean value indicating whether or not the low frequency band should be solo-d.
			Bool lowSolo;
			
			
			
			
			/// A boolean value indicating whether or not this saturator's high-frequency clipping effect is active.
			Bool highEffectEnabled;
			
			
			
			
			/// A boolean value indicating whether or not the low frequency band should be solo-d.
			Bool highSolo;
			
			
			
			
			/// A boolean value indicating whether or not this saturator's crossover is enabled.
			Bool crossoverEnabled;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The minimum allowed hardness for a distortion filter, 0.
			static const Float MIN_HARDNESS;
			
			
			
			/// The maximum allowed hardness for a distortion filter, a value close to 1.
			static const Float MAX_HARDNESS;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_SATURATOR_H
