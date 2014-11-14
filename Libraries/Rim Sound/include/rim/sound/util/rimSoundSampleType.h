/*
 *  rimSoundSampleType.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_SAMPLE_TYPE_H
#define INCLUDE_RIM_SOUND_SAMPLE_TYPE_H


#include "rimSoundUtilitiesConfig.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An enum wrapper class which specifies the type of a sample of audio data.
/**
  * In addition to providing conversion operator to and from the underlying enum type,
  * the class also provides a way to query the size in bytes of a given sample type,
  * avoiding the need for an external switch statement.
  */
class SampleType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Type Enum Definition
			
			
			
			
			/// The underlying enum type which specifies the type of a sample of audio data.
			typedef enum Enum
			{
				/// An 8-bit signed integer sample, stored in native endian format.
				SAMPLE_8,
				
				/// A 16-bit signed integer sample, stored in native endian format.
				SAMPLE_16,
				
				/// A 24-bit signed integer sample, stored in native endian format.
				SAMPLE_24,
				
				/// A 32-bit signed integer sample, stored in native endian format.
				SAMPLE_32,
				
				/// A 64-bit signed integer sample, stored in native endian format.
				SAMPLE_64,
				
				/// A 32-bit floating point sample, stored in native endian format.
				SAMPLE_32F,
				
				/// A 64-bit floating point sample, stored in native endian format.
				SAMPLE_64F,
				
				/// An undefined/unsupported sample type.
				UNDEFINED
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new sample type with the undefined sample type enum value.
			RIM_INLINE SampleType()
				:	type( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new sample type with the specified sample type enum value.
			RIM_INLINE SampleType( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this sample type to an enum value.
			/**
			  * This operator is provided so that the SampleType object can be used
			  * directly in a switch statement without the need to explicitly access
			  * the underlying enum value.
			  * 
			  * @return the enum representation of this sample type.
			  */
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Size Accessor Methods
			
			
			
			
			/// Get the size in bytes that this sample type occupies.
			RIM_INLINE Size getSizeInBytes() const
			{
				switch ( type )
				{
					case SAMPLE_8:		return 1;
					case SAMPLE_16:		return 2;
					case SAMPLE_24:		return 3;
					case SAMPLE_32:
					case SAMPLE_32F:	return 4;
					case SAMPLE_64:
					case SAMPLE_64F:	return 8;
					default:			return 0;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Type Accessor Methods
			
			
			
			
			/// Return whether or not this sample type is an integer-based sample type.
			RIM_INLINE Bool isIntegral() const
			{
				switch ( type )
				{
					case SAMPLE_8:
					case SAMPLE_16:
					case SAMPLE_24:
					case SAMPLE_32:
					case SAMPLE_64:
						return true;
					default:
						return false;
				}
			}
			
			
			
			
			/// Return whether or not this sample type is a floating-point-based sample type.
			RIM_INLINE Bool isFloatingPoint() const
			{
				switch ( type )
				{
					case SAMPLE_32F:
					case SAMPLE_64F:
						return true;
					default:
						return false;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the sample type.
			data::String toString() const;
			
			
			
			
			/// Convert this sample type into a string representation.
			RIM_INLINE operator data::String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The underlying enum representing the type of sample for this SampleType object.
			Enum type;
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_SAMPLE_TYPE_H
