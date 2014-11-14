/*
 *  rimSoundPitchShifter.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 4/2/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_PITCH_SHIFTER_H
#define INCLUDE_RIM_SOUND_PITCH_SHIFTER_H


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
/// A class that shifts the pitch of input audio up or down by a number of semitones.
/**
  * This classes uses an oversampled DTFT to shift the pitch of input audio up or
  * down.
  *
  * The pitch shifter allows the user to set the FFT buffer size in seconds,
  * controlling the approximate time-domain resolution of the effect. A larger buffer
  * size produces better frequency resolution but less time resolution, resulting in
  * transient smearing. A smaller buffer can produce frequency domain artifacts
  * due to the limited frequency resolution, but will have better transient response.
  * The buffer length also determines the approximate latency of the effect.
  *
  * Additionally, the shifter allows the user to control the oversampling factor
  * for the effect. A higher oversampling level produces better quality results but
  * at an exponential increase in CPU time. Higher oversampling amounts also can increase
  * the time-domain smearing of the effect.
  */
class PitchShifter : public SoundFilter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new pitch shifter with no pitch shift.
			PitchShifter();
			
			
			
			
			/// Create a new pitch shifter which shifts the input audio by the specified number of semitones.
			PitchShifter( Float newSemitoneShift );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Pitch Shift Accessor Methods
			
			
			
			
			/// Return the current pitch shift amount expressed as a frequency multiplier.
			RIM_INLINE Float getShift() const
			{
				return shift;
			}
			
			
			
			
			/// Set the pitch shift amount, expressed as a frequency multiplier.
			RIM_INLINE void setShift( Float newShift )
			{
				lockMutex();
				shift = math::max( newShift, Float(0) );
				unlockMutex();
			}
			
			
			
			
			/// Return the current pitch shift amount in signed semitones.
			RIM_INLINE Float getSemitoneShift() const
			{
				return Float(12)*math::ln( shift ) / math::ln(Float(2));
			}
			
			
			
			
			/// Set the current pitch shift amount in signed semitones.
			RIM_INLINE void setSemitoneShift( Float newSemitones )
			{
				lockMutex();
				shift = math::exp( math::ln(Float(2))*newSemitones / Float(12) );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Length Accessor Methods
			
			
			
			
			/// Return the length in seconds of the FFT buffer used when doing pitch shifting.
			/**
			  * A longer buffer will result in higher frequency-domain resolution but
			  * decreased time-domain resolution. During rendering, since FFT buffers must
			  * have a power-of-two size, the next largest power of two is used for the buffer
			  * size, calculated based on the current sample rate and buffer length in seconds.
			  */
			RIM_INLINE Float getBufferLength() const
			{
				return bufferLength;
			}
			
			
			
			
			/// Set the length in seconds of the FFT buffer used when doing pitch shifting.
			/**
			  * A longer buffer will result in higher frequency-domain resolution but
			  * decreased time-domain resolution. During rendering, since FFT buffers must
			  * have a power-of-two size, the next largest power of two is used for the buffer
			  * size, calculated based on the current sample rate and buffer length in seconds.
			  *
			  * The new buffer length is clamped to be greater than or equal to 0.
			  */
			RIM_INLINE void setBufferLength( Float newBufferLength )
			{
				lockMutex();
				bufferLength = math::max( newBufferLength, Float(0) );
				unlockMutex();
				this->reset();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Oversampling Accessor Methods
			
			
			
			
			/// Return the oversampling factor currently used by this pitch shifter.
			/**
			  * This number indicates the number of FFT passes that the shifter makes
			  * over the input audio. The more passes, the better quality the resulting
			  * shifted audio will be. However, an oversampling factor N will require
			  * approximately 2^N times as much time to process the effect.
			  *
			  * The default oversampling factor is 2.
			  */
			RIM_INLINE Size getOversampling() const
			{
				return math::log2( oversampling );
			}
			
			
			
			
			/// Set the oversampling factor currently used by this pitch shifter.
			/**
			  * This number indicates the number of FFT passes that the shifter makes
			  * over the input audio. The more passes, the better quality the resulting
			  * shifted audio will be. However, an oversampling factor N will require
			  * approximately 2^N times as much time to process the effect.
			  *
			  * The default oversampling factor is 2.
			  */
			RIM_INLINE void setOversampling( Size newOversampling )
			{
				lockMutex();
				oversampling = Size(1) << math::clamp( newOversampling, Size(1), Size(5) );
				unlockMutex();
				this->reset();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mix Accessor Methods
			
			
			
			
			/// Return the ratio of input signal to pitch shifted signal sent to the output of the pitch shifter.
			/**
			  * Valid mix values are in the range [0,1].
			  * A mix value of 1 indicates that only the output of the pitch shifter should be
			  * heard at the output, while a value of 0 indicates that only the input of the
			  * pitch shifter should be heard at the output. A value of 0.5 indicates that both
			  * should be mixed together equally at -6dB.
			  */
			RIM_INLINE Gain getMix() const
			{
				return targetMix;
			}
			
			
			
			
			/// Set the ratio of input signal to pitch shifted signal sent to the output of the pitch shifter.
			/**
			  * Valid mix values are in the range [0,1].
			  * A mix value of 1 indicates that only the output of the pitch shifter should be
			  * heard at the output, while a value of 0 indicates that only the input of the
			  * pitch shifter should be heard at the output. A value of 0.5 indicates that both
			  * should be mixed together equally at -6dB.
			  *
			  * The new mix value is clamped to the valid range of [0,1].
			  */
			RIM_INLINE void setMix( Gain newMix )
			{
				lockMutex();
				targetMix = math::clamp( newMix, Gain(0), Gain(1) );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Attribute Accessor Methods
			
			
			
			
			/// Return a human-readable name for this pitch shifter.
			/**
			  * The method returns the string "Pitch Shifter".
			  */
			virtual UTF8String getName() const;
			
			
			
			
			/// Return the manufacturer name of this pitch shifter.
			/**
			  * The method returns the string "Headspace Sound".
			  */
			virtual UTF8String getManufacturer() const;
			
			
			
			
			/// Return an object representing the version of this pitch shifter.
			virtual SoundFilterVersion getVersion() const;
			
			
			
			
			/// Return an object which describes the category of effect that this filter implements.
			/**
			  * This method returns the value SoundFilterCategory::PITCH.
			  */
			virtual SoundFilterCategory getCategory() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Latency Accessor Method
			
			
			
			
			/// Return a Time value indicating the latency of this pitch shifter in seconds.
			/**
			  * The latency of the pitch shifter is equal to the shifter's buffer length.
			  */
			virtual Time getLatency() const;
			
			
			
			
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
		//******	Public Static Property Objects
			
			
			
			
			/// A string indicating the human-readable name of this pitch shifter.
			static const UTF8String NAME;
			
			
			
			
			/// A string indicating the manufacturer name of this pitch shifter.
			static const UTF8String MANUFACTURER;
			
			
			
			
			/// An object indicating the version of this pitch shifter.
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
			
			
			
			
			/// Multiply the samples in the input frame by this pitch shifter's gain factor and place them in the output frame.
			virtual SoundFilterResult processFrame( const SoundFilterFrame& inputFrame,
													SoundFilterFrame& outputFrame, Size numSamples );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Data Class Declaration
			
			
			
			
			/// A class which stores persistant phase information for a channel of audio.
			class ChannelPhase
			{
				public:
					
					/// An array containing the last phase value computed for each FFT bin.
					/**
					  * This value is used to increase the accuracy of the FFT bin frequencies.
					  *
					  * This array is automatically allocated to be at least as large as (fftSize/2 + 1).
					  */
					Array<Float> lastPhases;
					
					/// An array containing the persistant total sum of the phase values computed for each FFT bin.
					/**
					  * This array is automatically allocated to be at least as large as (fftSize/2 + 1).
					  */
					Array<Float> phaseSum;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The current pitch shift amount, specified by the frequency scale factor.
			/**
			  * A shift of 2.0 means a shift up an octave, while a shift of 0.5 means
			  * a shift down an octave.
			  */
			Float shift;
			
			
			
			
			/// The ratio of input signal to compressed signal sent to the output of the compressor.
			/**
			  * The mix factor determines the ratio of the input signal (post input gain) to the
			  * shifted signal which is sent to the final output buffer. Thus, a mix factor
			  * of 1 indicates only the shifted signal is sent to the output. Likewise, a mix
			  * factor of 0 indicates that only the input signal is sent to the output.
			  */
			Gain mix;
			
			
			
			
			/// The target mix factor of the pitch shifter, used to smooth mix parameter changes.
			Gain targetMix;
			
			
			
			
			/// The length in seconds of the FFT buffer used when doing pitch shifting.
			/**
			  * A longer buffer will result in higher frequency-domain resolution but
			  * decreased time-domain resolution. During rendering, since FFT buffers must
			  * have a power-of-two size, the next largest power of two is used for the buffer
			  * size, calculated based on the current sample rate and buffer length in seconds.
			  */
			Float bufferLength;
			
			
			
			
			/// An object that buffers input audio for the pitch shifter so that power-of-two-sized FFT passes can be made.
			SoundBuffer inputQueue;
			
			
			
			
			/// An object that buffers output audio for the pitch shifter so that power-of-two-sized FFT passes can be made.
			SoundBuffer outputQueue;
			
			
			
			
			/// A sound buffer which stores the oversampling accumulated output of the pitch shifter.
			SoundBuffer accumulationBuffer;
			
			
			
			
			/// An array of complex samples that are used as a workspace for the pitch shifter's FFT.
			Array<ComplexSample> fftData;
			
			
			
			
			/// An array storing phase information for each channel that is processed.
			Array<ChannelPhase> channelPhases;
			
			
			
			
			/// An array containing the magnitudes for the shifted frequency binds.
			Array<Float> shiftedMagnitudes;
			
			
			
			
			/// An array containing the actual frequencies for the shifted frequency binds.
			Array<Float> shiftedFrequencies;
			
			
			
			
			/// An array containing the precomputed window function for an FFT frame.
			Array<Float> window;
			
			
			
			
			/// The current write position within the input queue for the input samples.
			Index currentInputWritePosition;
			
			
			
			
			/// The current read position within the input queue for the fft samples.
			Index currentFFTReadPosition;
			
			
			
			
			/// The current write position within the accumulation buffer and output queue for the fft samples.
			Index currentFFTWritePosition;
			
			
			
			
			/// The current read position within the input queue for the output samples, the 'dry' signal.
			Index currentInputReadPosition;
			
			
			
			
			/// The current read position within the output queue for the output samples, the 'wet' signal.
			Index currentOutputReadPosition;
			
			
			
			
			/// The sample rate of the last sample buffer processed.
			/**
			  * This value is used to detect when the sample rate of the audio stream has changed,
			  * and thus reinitialize the filter processing.
			  */
			SampleRate lastSampleRate;
			
			
			
			
			/// The amount of oversampling that should be done.
			/**
			  * A higher oversampling value will allow the pitch shifter to be more accurate and
			  * to preserve pitch relationships better, but will cost more processing speed.
			  */
			Size oversampling;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_PITCH_SHIFTER_H
