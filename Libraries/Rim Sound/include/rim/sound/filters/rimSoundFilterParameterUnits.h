/*
 *  rimSoundFilterParameterUnits.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 8/21/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_FILTER_PARAMETER_UNITS_H
#define INCLUDE_RIM_SOUND_FILTER_PARAMETER_UNITS_H


#include "rimSoundFiltersConfig.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the units of a certain SoundFilter parameter.
/**
  * This value is used to determine how to display the filter parameter.
  * Units are available for commonly used DSP parameter types.
  */
class FilterParameterUnits
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parameter Type Enum Declaration
			
			
			
			
			/// An enum which specifies the allowed SoundFilter parameter types.
			typedef enum Enum
			{
				/// A undefined filter parameter unit type.
				UNDEFINED = 0,
				
				/// A generic parameter. Values are evenly distributed in the parameter's range.
				GENERIC = 1,
				
				/// The parameter is specified in terms of a decibel gain factor, relative to 0dB (full scale).
				DECIBELS = 2,
				
				/// The parameter's value is in terms of a percentage.
				PERCENT = 3,
				
				/// The parameter's value is specified as a ratio of two numbers.
				/**
				  * This unit type would typically be used for compressor or gate ratios.
				  */
				RATIO = 4,
				
				/// The parameter's value is specified in terms of seconds.
				SECONDS = 5,
				
				/// The parameter's value is specified in terms of milliseconds.
				MILLISECONDS = 6,
				
				/// The parameter's value is specified in terms of frequency (Hertz).
				HERTZ = 7,
				
				/// The parameter's value is specified in terms of a number of meters.
				METERS = 8,
				
				/// The parameter's value is specified in terms of a number of angular degrees.
				DEGREES = 9,
				
				/// An index parameter, representing a whole-number value.
				/**
				  * This unit type indicates that only integer values should be allowed for this
				  * filter parameter.
				  */
				INDEX = 10,
				
				/// The parameter's value is specified in terms of a number of samples.
				SAMPLES = 11,
				
				/// The parameter's value is specified in terms of a number of samples per second.
				SAMPLE_RATE = 12,
				
				/// The parameter's value is specified in terms of the number of beats per minute.
				BPM = 13,
				
				/// The parameter's value is specified in terms of a number of beats.
				BEATS = 14,
				
				/// The parameter's value is specified in terms of a number of cents (1/100th of a semitone).
				CENTS = 15,
				
				/// The parameter's value is specified in terms of a number of semitones.
				SEMITONES = 16,
				
				/// The parameter's value is specified in terms of a number of octaves.
				OCTAVES = 17,
				
				/// The parameter's value is specified in terms of a MIDI note number.
				/**
				  * Values are evenly distributed in the parameter's range. Values should range
				  * between 0 and 127 to be MIDI-compliant.
				  *
				  * This unit type indicates that only integer values should be allowed for this
				  * filter parameter.
				  */
				MIDI_NOTE_NUMBER = 18,
				
				/// The parameter's value is specified in terms of a MIDI control channel value.
				/**
				  * Values are evenly distributed in the parameter's range. Values should range
				  * between 0 and 127 to be MIDI-compliant.
				  */
				MIDI_CONTROL = 19
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new filter parameter units object with an UNDEFINED parameter units.
			RIM_INLINE FilterParameterUnits()
				:	units( (UByte)UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new filter parameter units object with the specified units enum value.
			RIM_INLINE FilterParameterUnits( Enum newUnits )
				:	units( (UByte)newUnits )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this filter parameter units type to an enum value.
			/**
			  * This operator is provided so that the FilterParameterUnits object can be used
			  * directly in a switch statement without the need to explicitly access
			  * the underlying enum value.
			  * 
			  * @return the enum representation of this parameter unit type.
			  */
			RIM_INLINE operator Enum () const
			{
				return (Enum)units;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representing the abbreviated name of this parameter units.
			/**
			  * For some parameter types, this method may return an empty string, indicating
			  * there is no valid abbreviation for this unit type (linear gain, for example).
			  */
			UTF8String getAbbreviation() const;
			
			
			
			
			/// Return a string representation of the parameter unit type.
			/**
			  * This string is the same as the 'long' representation for this
			  * unit type. This string will not contain any abbreviations and shouldn't
			  * be used for compact display.
			  */
			UTF8String toString() const;
			
			
			
			
			/// Convert this parameter unit type into a string representation.
			RIM_INLINE operator UTF8String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value indicating the unit type of a SoundFilter parameter.
			UByte units;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_FILTER_PARAMETER_UNITS_H
