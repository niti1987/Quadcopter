/*
 *  rimSoundFilterCategory.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 7/11/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_FILTER_TYPE_H
#define INCLUDE_RIM_SOUND_FILTER_TYPE_H


#include "rimSoundFiltersConfig.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the kind of effect that a SoundFilter performs.
/**
  * This allows filters to report a category of effect which they belong to,
  * and allows filter hosts to sort filters by their type.
  */
class SoundFilterCategory
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parameter Type Enum Declaration
			
			
			
			
			/// An enum which specifies the different SoundFilter categories.
			typedef enum Enum
			{
				/// An undefined filter category, used when no other category fits.
				OTHER = 0,
				
				/// A category where the filter produces output audio from an internal source, such as a file.
				/**
				  * This category can include samplers and any filter that plays back audio, like an audio
				  * file player, MIDI file player, etc.
				  */
				PLAYBACK = 1,
				
				/// A category where the filter records input audio to a destination, such as a file or looping buffer.
				/**
				  * This category can include filters that record audio to a file, record loops, or other
				  * similar operations.
				  */
				RECORDING = 2,
				
				/// A category where the filter is used as a musical instrument, taking MIDI input data and producing output audio.
				/**
				  * This category can include synthesizers, virtual instruments, samplers, drum machines,
				  * etc.
				  */
				INSTRUMENT = 3,
				
				/// A category where the filter is used to do some sort of routing function.
				/**
				  * This category can include mixers, splitters, channel strips, processing graphs, etc.
				  */
				ROUTING = 4,
				
				/// A category where the filter is used to manipulate channel directionality.
				/**
				  * This category can include panners, HRTF effects, directional mixers, and stereo utilities.
				  */
				IMAGING = 5,
				
				/// A category where the filter is used to modify the frequency response of audio.
				/**
				  * This category can include single IIR filters, multi-band equalizers, linear phase equalizers,
				  * crossovers, graphic equalizers, wah effects, etc.
				  */
				EQUALIZER = 6,
				
				/// A category where the filter is used to control the dynamic range of audio.
				/**
				  * This category can include compressors, gates, limiters, gain riders, simple gain controls, etc.
				  */
				DYNAMICS = 7,
				
				/// A category where the filter is used to add some sort of distortion to the audio.
				/**
				  * This category can include overdrives, hard clipping effects, phase-based distortion, etc.
				  */
				DISTORTION = 8,
				
				/// A category where the filter is used to produce a delayed version of the audio.
				/**
				  * This category can include basic delays, stereo delays, etc.
				  */
				DELAY = 9,
				
				/// A category where the filter is used to produce a reverberant effect, used to model room acoustics.
				/**
				  * This category can include basic reverb effects, convolution reverb, and other reverb-
				  * based effects.
				  */
				REVERB = 10,
				
				/// A category where the filter is used to modulate the audio in some way.
				/**
				  * This category can include amplitude modulation effects (tremolo, ring modulation),
				  * pitch moduation effects (vibrato, flanger, chorus, phase), and other similar effects.
				  */
				MODULATION = 11,
				
				/// A category where the filter operates on the pitch information of the audio.
				/**
				  * This categeory can include pitch shifters, pitch correction, tuners,
				  * harmonizers, etc.
				  */
				PITCH = 12,
				
				/// A category where the filter is used to analyze the input audio.
				/**
				  * This category can include RTAs, tone generators, and other audio analysis tools.
				  */
				ANALYSIS = 13,
				
				/// A category where the filter is used to perform a low-level task that doesn't fit in another category.
				/**
				  * This category can include effects like sample rate conversion, convolution,
				  * phase controls, etc.
				  */
				UTILITY = 14
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new filter type object with the OTHER parameter type.
			RIM_INLINE SoundFilterCategory()
				:	type( OTHER )
			{
			}
			
			
			
			
			/// Create a new filter type object with the specified type enum value.
			RIM_INLINE SoundFilterCategory( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this filter type to an enum value.
			/**
			  * This operator is provided so that the SoundFilterCategory object can be used
			  * directly in a switch statement without the need to explicitly access
			  * the underlying enum value.
			  * 
			  * @return the enum representation of this filter type.
			  */
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the filter type.
			UTF8String toString() const;
			
			
			
			
			/// Convert this filter type into a string representation.
			RIM_INLINE operator UTF8String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value indicating the type of a SoundFilter.
			Enum type;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_FILTER_TYPE_H
