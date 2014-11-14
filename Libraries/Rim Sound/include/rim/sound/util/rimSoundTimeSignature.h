/*
 *  rimSoundTimeSignature.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 5/30/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_TIME_SIGNATURE_H
#define INCLUDE_RIM_SOUND_TIME_SIGNATURE_H


#include "rimSoundUtilitiesConfig.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a standard musical time signature.
/**
  * The numberator of the time signature indicates the number of beats per measure,
  * and the denominator indicates what note value represents a beat. The note value
  * is almost always a power of 2: 1, 2, 4, 8, 16, 32, etc.
  */
class TimeSignature
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default time signature representing 4/4 time.
			RIM_INLINE TimeSignature()
				:	numerator( 4 ),
					denominator( 4 )
			{
			}
			
			
			
			
			/// Create a new time signature with the specified time signature numberator and denominator.
			RIM_INLINE TimeSignature( UInt newNumerator, UInt newDenominator )
				:	numerator( newNumerator ),
					denominator( newDenominator )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Numerator and Denominator Accessor Methods
			
			
			
			
			/// Return the numerator value of this time signature, indicating the number of beats per measure.
			RIM_INLINE UInt getNumerator() const
			{
				return numerator;
			}
			
			
			
			
			/// Set the numerator value of this time signature, indicating the number of beats per measure.
			RIM_INLINE void setNumerator( UInt newNumerator )
			{
				numerator = UInt8(newNumerator);
			}
			
			
			
			
			/// Return the denominator value of this time signature, indicating which note value gets a beat.
			/**
			  * The note value is almost always a power of 2: 1, 2, 4, 8, 16, 32, etc.
			  */
			RIM_INLINE UInt getDenominator() const
			{
				return denominator;
			}
			
			
			
			
			/// Set the denominator value of this time signature, indicating which note value gets a beat.
			/**
			  * The note value is almost always a power of 2: 1, 2, 4, 8, 16, 32, etc.
			  */
			RIM_INLINE void setDenominator( UInt newDenominator )
			{
				denominator = UInt8(newDenominator);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the time signature, 'N/D'
			data::String toString() const
			{
				return String(numerator) + '/' + String(denominator);
			}
			
			
			
			
			/// Convert this time signature into a string representation, 'N/D'.
			RIM_INLINE operator data::String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The number of beats per measure of this time signature.
			UInt8 numerator;
			
			
			
			
			/// The note type that represents a beat, usually a power of two: 1, 2, 4, 8, 16, 32.
			UInt8 denominator;
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_TIME_SIGNATURE_H
