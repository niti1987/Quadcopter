/*
 *  rimSoundDistortion.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/2/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_DISTORTION_H
#define INCLUDE_RIM_SOUND_DISTORTION_H


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
/// A class that provides different kinds of audio distortion using wave-shaping.
/**
  * The class uses a series of special non-linear functions to produce variable-hardness
  * distortion. The distortion produced can range from a basic soft clipping to very non-linear
  * hard clipping.
  */
class Distortion : public SoundFilter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distortion Type Enum Declaration
			
			
			
			
			/// Define the different kinds of distortion effects that this filter can produce.
			typedef enum Type
			{
				/// A kind of distortion where a smooth soft-clipping function is used.
				SOFT = 0,
				
				/// A kind of distortion where soft clipping is performed to the negative waveform and hard on the positive.
				HARD = 1,
				
				/// A kind of distortion which uses a soft-clipping function which is non-linear in the low amplitudes.
				/**
				  * This causes a constant distortion, even at low input levels.
				  */
				BREAKUP_1 = 2,
				
				/// A kind of distortion which uses a non-linear function which shorts out the signal after a certain input level.
				/**
				  * This causes a distortion where after the clipping threshold is reached, the output
				  * level begins to decrease, causing unusual distortion.
				  */
				BREAKUP_2 = 3
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new distortion filter with the default input and output gains of 1 and hardness of 0.
			Distortion();
			
			
			
			
			/// Create a new distortion filter with the default input and output gains of 1 and hardness of 0.
			Distortion( Type newType );
			
			
			
			
			/// Create an exact copy of another distortion filter.
			Distortion( const Distortion& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this distortion filter and clean up any resources.
			~Distortion();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of another distortion filter to this one.
			Distortion& operator = ( const Distortion& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distortion Type Accessor Methods
			
			
			
			
			/// Return the type of distortion that this distortion filter is using.
			RIM_INLINE Type getType() const
			{
				return type;
			}
			
			
			
			
			/// Return the type of distortion that this distortion filter is using.
			RIM_INLINE void setType( Type newType )
			{
				lockMutex();
				type = newType;
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Input Gain Accessor Methods
			
			
			
			
			/// Return the current linear input gain factor of this distortion filter.
			/**
			  * This is the gain applied to the input signal before being sent to the
			  * clipping function. A higher value will result in more noticeable clipping.
			  */
			RIM_INLINE Gain getInputGain() const
			{
				return targetInputGain;
			}
			
			
			
			
			/// Return the current input gain factor in decibels of this distortion filter.
			/**
			  * This is the gain applied to the input signal before being sent to the
			  * clipping function. A higher value will result in more noticeable clipping.
			  */
			RIM_INLINE Gain getInputGainDB() const
			{
				return util::linearToDB( targetInputGain );
			}
			
			
			
			
			/// Set the target linear input gain for this distortion filter.
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
			
			
			
			
			/// Set the target input gain in decibels for this distortion filter.
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
			
			
			
			
			/// Return the current linear output gain factor of this distortion filter.
			/**
			  * This is the gain applied to the signal after being sent to the
			  * clipping function. This value is used to modify the final level
			  * of the clipped signal.
			  */
			RIM_INLINE Gain getOutputGain() const
			{
				return targetOutputGain;
			}
			
			
			
			
			/// Return the current output gain factor in decibels of this distortion filter.
			/**
			  * This is the gain applied to the signal after being sent to the
			  * clipping function. This value is used to modify the final level
			  * of the clipped signal.
			  */
			RIM_INLINE Gain getOutputGainDB() const
			{
				return util::linearToDB( targetOutputGain );
			}
			
			
			
			
			/// Set the target linear output gain for this distortion filter.
			/**
			  * This is the gain applied to the signal after being sent to the
			  * clipping function. This value is used to modify the final level
			  * of the clipped signal.
			  */
			RIM_INLINE void setOutputGain( Gain newOutputGain )
			{
				lockMutex();
				targetOutputGain = newOutputGain;
				unlockMutex();
			}
			
			
			
			
			/// Set the target output gain in decibels for this distortion filter.
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
		//******	Mix Accessor Methods
			
			
			
			
			/// Return the ratio of input signal to distorted signal sent to the output of the distortion effect.
			/**
			  * Valid mix values are in the range [0,1].
			  * A mix value of 1 indicates that only the output of the distortion should be
			  * heard at the output, while a value of 0 indicates that only the input of the
			  * distortion should be heard at the output. A value of 0.5 indicates that both
			  * should be mixed together equally at -6dB.
			  */
			RIM_INLINE Gain getMix() const
			{
				return targetMix;
			}
			
			
			
			
			/// Set the ratio of input signal to distorted signal sent to the output of the distortion effect.
			/**
			  * Valid mix values are in the range [0,1].
			  * A mix value of 1 indicates that only the output of the distortion should be
			  * heard at the output, while a value of 0 indicates that only the input of the
			  * distortion should be heard at the output. A value of 0.5 indicates that both
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
		//******	Threshold Accessor Methods
			
			
			
			
			/// Return the linear full-scale value which indicates the maximum distorted output signal level.
			RIM_INLINE Gain getThreshold() const
			{
				return targetThreshold;
			}
			
			
			
			
			/// Return the logarithmic full-scale value which indicates the maximum distorted output signal level.
			RIM_INLINE Gain getThresholdDB() const
			{
				return util::linearToDB( targetThreshold );
			}
			
			
			
			
			/// Set the linear full-scale value which indicates the maximum distorted output signal level.
			/**
			  * The value is clamped to the valid range of [0,infinity] before being stored.
			  */
			RIM_INLINE void setThreshold( Gain newThreshold )
			{
				lockMutex();
				targetThreshold = math::max( newThreshold, Gain(0) );
				unlockMutex();
			}
			
			
			
			
			/// Set the logarithmic full-scale value which indicates the maximum distorted output signal level.
			RIM_INLINE void setThresholdDB( Gain newThresholdDB )
			{
				lockMutex();
				targetThreshold = util::dbToLinear( newThresholdDB );
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Clipping Hardness Accessor Methods
			
			
			
			
			/// Return the current hardness of this distortion filter's clipping function.
			/**
			  * The hardness of a distortion filter is a value between 0 and 1 indicating the linear full-scale
			  * threshold at which the saturation rolloff begins. Thus, a hardness of 0 will produce
			  * the smoothest transfer curve, while a hardness of 1 will approximate hard clipping.
			  */
			RIM_INLINE Float getHardness() const
			{
				return Float(1) - Float(1) / targetHardness;
			}
			
			
			
			
			/// Set the hardness of this distortion filter's clipping function.
			/**
			  * The hardness of a distortion filter is a value between 0 and 1 indicating the linear full-scale
			  * threshold at which the saturation rolloff begins. Thus, a hardness of 0 will produce
			  * the smoothest transfer curve, while a hardness of 1 will approximate hard clipping.
			  *
			  * The input hardness value is clamped between 0 and 1.
			  */
			RIM_INLINE void setHardness( Float newThreshold )
			{
				lockMutex();
				targetHardness = Float(1)/(Float(1) - math::clamp( newThreshold, MIN_HARDNESS, MAX_HARDNESS ));
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Low Pass Filter Attribute Accessor Methods
			
			
			
			
			/// Return whether or not this distortion filter's low pass filter is enabled.
			RIM_INLINE Bool getLowPassIsEnabled() const
			{
				return lowPassEnabled;
			}
			
			
			
			
			/// Set whether or not this distortion filter's low pass filter is enabled.
			RIM_INLINE void setLowPassIsEnabled( Bool newLowPassIsEnabled )
			{
				lockMutex();
				lowPassEnabled = newLowPassIsEnabled;
				unlockMutex();
			}
			
			
			
			
			/// Return the low pass filter frequency of this distortion filter.
			RIM_INLINE Float getLowPassFrequency() const
			{
				return lowPassFrequency;
			}
			
			
			
			
			/// Set the low pass filter frequency of this distortion filter.
			/**
			  * The new low pass frequency is clamped to the range [0,infinity].
			  */
			RIM_INLINE void setLowPassFrequency( Float newLowPassFrequency )
			{
				lockMutex();
				lowPassFrequency = math::max( newLowPassFrequency, Float(0) );
				unlockMutex();
			}
			
			
			
			
			/// Return the low pass filter order of this distortion filter.
			RIM_INLINE Size getLowPassOrder() const
			{
				return lowPassOrder;
			}
			
			
			
			
			/// Set the low pass filter order of this distortion filter.
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
		//******	Filter Attribute Accessor Methods
			
			
			
			
			/// Return a human-readable name for this distortion filter.
			/**
			  * The method returns the string "Distortion".
			  */
			virtual UTF8String getName() const;
			
			
			
			
			/// Return the manufacturer name of this distortion filter.
			/**
			  * The method returns the string "Headspace Sound".
			  */
			virtual UTF8String getManufacturer() const;
			
			
			
			
			/// Return an object representing the version of this distortion filter.
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
			
			
			
			
			/// Return the total number of generic accessible parameters this distortion filter has.
			virtual Size getParameterCount() const;
			
			
			
			
			/// Get information about the distortion filter parameter at the specified index.
			virtual Bool getParameterInfo( Index parameterIndex, FilterParameterInfo& info ) const;
			
			
			
			
			/// Get any special name associated with the specified value of an indexed parameter.
			virtual Bool getParameterValueName( Index parameterIndex, const FilterParameter& value, UTF8String& name ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Property Objects
			
			
			
			
			/// A string indicating the human-readable name of this distortion filter.
			static const UTF8String NAME;
			
			
			
			
			/// A string indicating the manufacturer name of this distortion filter.
			static const UTF8String MANUFACTURER;
			
			
			
			
			/// An object indicating the version of this distortion filter.
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
			
			
			
			
			/// Apply a distortion function to the samples in the input frame and write the output to the output frame.
			virtual SoundFilterResult processFrame( const SoundFilterFrame& inputFrame,
													SoundFilterFrame& outputFrame, Size numSamples );
			
			
			
			
			/// Apply the templated clipping function to the specified input buffer and put the result in the output buffer.
			template < Float (*clippingFunction)( Float /*input*/, Float /*threshold*/, Float /*inverseThreshold*/, Float /*hardness*/,
													Float /*inverseHardness*/, Float /*hardnessThreshold*/, Float /*hardnessOffset*/ ) >
			void processDistortion( const SoundBuffer& inputBuffer, SoundBuffer& outputBuffer, Size numSamples );
			
			
			
			
			/// Apply the templated clipping function to the specified input buffer and put the result in the output buffer.
			template < Float (*clippingFunction)( Float /*input*/, Float /*threshold*/, Float /*inverseThreshold*/, Float /*hardness*/,
													Float /*inverseHardness*/, Float /*hardnessThreshold*/, Float /*hardnessOffset*/ ) >
			void processDistortion( const SoundBuffer& inputBuffer, SoundBuffer& outputBuffer, Size numSamples,
									Gain inputGainChangePerSample, Float thresholdChangePerSample, Float hardnessChangePerSample );
			
			
			
			
			RIM_FORCE_INLINE static Float softClip( Float input, Float threshold, Float inverseThreshold, Float hardness,
													Float inverseHardness, Float hardnessThreshold, Float hardnessOffset )
			{
				if ( input > threshold*hardnessThreshold )
					return threshold*((inverseHardness*math::tanh(inverseThreshold*hardness*input - hardnessOffset)) + hardnessThreshold);
				else if ( input < -threshold*hardnessThreshold )
					return threshold*((inverseHardness*math::tanh(inverseThreshold*hardness*input + hardnessOffset)) - hardnessThreshold);
				else
					return input;
			}
			
			
			
			
			RIM_FORCE_INLINE static Float hardClip( Float input, Float threshold, Float inverseThreshold, Float hardness,
													Float inverseHardness, Float hardnessThreshold, Float hardnessOffset )
			{
				if ( input > threshold )
					return threshold;
				else if ( input < -threshold*hardnessThreshold )
					return threshold*((inverseHardness*math::tanh(inverseThreshold*hardness*input + hardnessOffset)) - hardnessThreshold);
				else
					return input;
			}
			
			
			
			
			RIM_FORCE_INLINE static Float breakup1( Float input, Float threshold, Float inverseThreshold, Float hardness,
													Float inverseHardness, Float hardnessThreshold, Float hardnessOffset )
			{
				Float scaledInput = inverseThreshold*input;
				
				if ( scaledInput < 0 )
					return -threshold*scaledInput*scaledInput / 
							math::pow( Float(1) + math::pow( -scaledInput, Float(2)*hardness ), inverseHardness );
				else
					return threshold*scaledInput*scaledInput /
							math::pow( Float(1) + math::pow( scaledInput, Float(2)*hardness ), inverseHardness );
			}
			
			
			
			
			/// Apply a clipping algorithm that has a 
			RIM_FORCE_INLINE static Float breakup2( Float input, Float threshold, Float inverseThreshold, Float hardness,
													Float inverseHardness, Float hardnessThreshold, Float hardnessOffset )
			{
				Float scaledInput = inverseThreshold*input;
				
				return threshold*scaledInput /
						math::pow( Float(1) + math::pow( math::abs(scaledInput), hardness*Float(2.5f) ),
									Float(1)/Float(2.5f) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The type of distortion effect that this distortion filter uses.
			Type type;
			
			
			
			
			/// The current linear input gain factor applied to all input audio before being clipped.
			Gain inputGain;
			
			
			
			
			/// The target linear input gain factor, used to smooth changes in the input gain.
			Gain targetInputGain;
			
			
			
			
			/// The current linear output gain factor applied to all input audio after being clipped.
			Gain outputGain;
			
			
			
			
			/// The target linear output gain factor, used to smooth changes in the output gain.
			Gain targetOutputGain;
			
			
			
			
			/// The current ratio of distorted to unaffected signal that is sent to the output.
			Float mix;
			
			
			
			
			/// The target mix, used to smooth changes in the mix parameter.
			Float targetMix;
			
			
			
			
			/// The current threshold which indicates the maximum distorted output level.
			Float threshold;
			
			
			
			
			/// The target threshold, used to smooth changes in the threshold parameter.
			Float targetThreshold;
			
			
			
			
			/// A value which affects how hard the clipping function is.
			/**
			  * This value ranges from 1 (indicating soft clipping), to infinity (very harsh clipping).
			  */
			Float hardness;
			
			
			
			
			/// The target hardness for this distortion filter, used to smooth changes in the clipping hardness.
			Float targetHardness;
			
			
			
			
			/// A low-pass filter used to smooth the output of the distortion.
			CutoffFilter* lowPass;
			
			
			
			
			/// The frequency at which the low pass filter for the distortion is at -3dB.
			Float lowPassFrequency;
			
			
			
			
			/// The order of the distortion's low pass filter that determines its slope.
			Size lowPassOrder;
			
			
			
			
			/// A boolean value indicating whether or not this distortion's low-pass filter is enabled.
			Bool lowPassEnabled;
			
			
			
			
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


#endif // INCLUDE_RIM_SOUND_DISTORTION_H
