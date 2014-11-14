/*
 *  rimHalfFloat.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 1/6/11.
 *  Copyright 2011 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_HALF_FLOAT_H
#define INCLUDE_RIM_HALF_FLOAT_H


#include "rimLanguageConfig.h"


//##########################################################################################
//***************************  Start Rim Language Namespace  *******************************
RIM_LANGUAGE_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which emulates a 16-bit floating-point number.
/**
  * The class includes operator overloads for all standard arithmetic operators,
  * though the performance of these may be undesirable for intensive calculations
  * because they are emulated in software.
  */
class HalfFloat
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a HalfFloat object with the value 0.
			RIM_FORCE_INLINE HalfFloat()
				:	data( HalfFloat::ZERO )
			{
			}
			
			
			
			
			/// Create a HalfFloat object with the value of the specified byte.
			RIM_FORCE_INLINE HalfFloat( Byte value )
				:	data( floatToHalfFloat( Float(value) ) )
			{
			}
			
			
			
			
			/// Create a HalfFloat object with the value of the specified short number.
			RIM_FORCE_INLINE HalfFloat( Short value )
				:	data( floatToHalfFloat( Float(value) ) )
			{
			}
			
			
			
			
			/// Create a HalfFloat object with the value of the specified int number.
			RIM_FORCE_INLINE HalfFloat( Int value )
				:	data( floatToHalfFloat( Float(value) ) )
			{
			}
			
			
			
			
			/// Create a HalfFloat object with the value of the specified long number.
			RIM_FORCE_INLINE HalfFloat( Long value )
				:	data( floatToHalfFloat( Float(value) ) )
			{
			}
			
			
			
			
			/// Create a HalfFloat object with the value of the specified long-long number.
			RIM_FORCE_INLINE HalfFloat( LongLong value )
				:	data( floatToHalfFloat( Float(value) ) )
			{
			}
			
			
			
			
			/// Create a HalfFloat object with the value of the specified float number.
			RIM_FORCE_INLINE HalfFloat( Float value )
				:	data( floatToHalfFloat( value ) )
			{
			}
			
			
			
			
			/// Create a HalfFloat object with the value of the specified double number.
			RIM_FORCE_INLINE HalfFloat( Double value )
				:	data( floatToHalfFloat( Float(value) ) )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Assignment Operators
			
			
			
			
			/// Add another HalfFloat to this half float's value.
			RIM_FORCE_INLINE HalfFloat& operator += ( const HalfFloat& other )
			{
				*this = HalfFloat( Float(*this) + Float(other) );
				return *this;
			}
			
			
			
			
			/// Subtract another HalfFloat from this half float's value.
			RIM_FORCE_INLINE HalfFloat& operator -= ( const HalfFloat& other )
			{
				*this = HalfFloat( Float(*this) - Float(other) );
				return *this;
			}
			
			
			
			
			/// Multiply this half float's value by another HalfFloat.
			RIM_FORCE_INLINE HalfFloat& operator *= ( const HalfFloat& other )
			{
				*this = HalfFloat( Float(*this) * Float(other) );
				return *this;
			}
			
			
			
			
			/// Divide this half float's value by another HalfFloat.
			RIM_FORCE_INLINE HalfFloat& operator /= ( const HalfFloat& other )
			{
				*this = HalfFloat( Float(*this) / Float(other) );
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Operators
			
			
			
			
			/// Add another HalfFloat to this half float's value.
			RIM_FORCE_INLINE HalfFloat operator + ( const HalfFloat& other )
			{
				return HalfFloat( Float(*this) + Float(other) );
			}
			
			
			
			
			/// Subtract another HalfFloat from this half float's value.
			RIM_FORCE_INLINE HalfFloat operator - ( const HalfFloat& other )
			{
				return HalfFloat( Float(*this) - Float(other) );
			}
			
			
			
			
			/// Multiply this half float's value by another HalfFloat.
			RIM_FORCE_INLINE HalfFloat operator * ( const HalfFloat& other )
			{
				return HalfFloat( Float(*this) * Float(other) );
			}
			
			
			
			
			/// Divide this half float's value by another HalfFloat.
			RIM_FORCE_INLINE HalfFloat operator / ( const HalfFloat& other )
			{
				return HalfFloat( Float(*this) / Float(other) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Cast Operator
			
			
			
			/// Cast the half float object to a single-precision floating point number.
			RIM_FORCE_INLINE operator Float () const
			{
				return halfFloatToFloat( data );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Helper Methods
			
			
			
			
			/// Convert the specified single precision float number to a half precision float number.
			RIM_NO_INLINE static UInt16 floatToHalfFloat( Float floatValue )
			{
				// Catch special case floating point values.
				if ( math::isNAN( floatValue ) )
					return NOT_A_NUMBER;
				else if ( math::isInfinity( floatValue ) )
					return POSITIVE_INFINITY;
				else if ( math::isNegativeInfinity( floatValue ) )
					return NEGATIVE_INFINITY;
				
				UInt32 value = *((UInt32*)&floatValue);
				
				if ( floatValue == Float(0) )
					return UInt16( value >> 16 );
				else
				{
					// Start by computing the significand in half precision format.
					UInt16 output = UInt16((value & FLOAT_SIGNIFICAND_MASK) >> 13);
					
					register UInt32 exponent = ((value & FLOAT_EXPONENT_MASK) >> 23);
					
					// Check for subnormal numbers.
					if ( exponent != 0 )
					{
						// Check for overflow when converting large numbers, returning positive or negative infinity.
						if ( exponent > 142 )
							return UInt16((value & FLOAT_SIGN_MASK) >> 16) | UInt16(0x7C00);
						
						// Add the exponent of the half float, converting the offset binary formats of the representations.
						output |= (((exponent - 112) << 10) & HALF_FLOAT_EXPONENT_MASK);
					}
					
					// Add the sign bit.
					output |= UInt16((value & FLOAT_SIGN_MASK) >> 16);
					
					return output;
				}
			}
			
			
			
			
			/// Convert the specified half float number to a single precision float number.
			RIM_NO_INLINE static Float halfFloatToFloat( UInt16 halfFloat )
			{
				// Catch special case half floating point values.
				switch ( halfFloat )
				{
					case NOT_A_NUMBER:
						return math::nan<Float>();
					case POSITIVE_INFINITY:
						return math::infinity<Float>();
					case NEGATIVE_INFINITY:
						return math::negativeInfinity<Float>();
				}
				
				// Start by computing the significand in single precision format.
				UInt32 value = UInt32(halfFloat & HALF_FLOAT_SIGNIFICAND_MASK) << 13;
				
				register UInt32 exponent = UInt32(halfFloat & HALF_FLOAT_EXPONENT_MASK) >> 10;
				
				if ( exponent != 0 )
				{
					// Add the exponent of the float, converting the offset binary formats of the representations.
					value |= (((exponent - 15 + 127) << 23) & FLOAT_EXPONENT_MASK);
				}
				
				// Add the sign bit.
				value |= UInt32(halfFloat & HALF_FLOAT_SIGN_MASK) << 16;
				
				return *((Float*)&value);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The 16-bit data member that holds the half float's data.
			UInt16 data;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Constant Data Members
			
			
			
			
			/// A static constant for a half float with a value of zero.
			static const UInt16 ZERO = 0x0000;
			
			
			/// A static constant for a half float with a value of not-a-number.
			static const UInt16 NOT_A_NUMBER = 0xFFFF;
			
			
			/// A static constant for a half float with a value of positive infinity.
			static const UInt16 POSITIVE_INFINITY = 0x7C00;
			
			
			/// A static constant for a half float with a value of negative infinity.
			static const UInt16 NEGATIVE_INFINITY = 0xFC00;
			
			
			/// A mask which isolates the sign of a half float number.
			static const UInt16 HALF_FLOAT_SIGN_MASK = 0x8000;
			
			
			/// A mask which isolates the exponent of a half float number.
			static const UInt16 HALF_FLOAT_EXPONENT_MASK = 0x7C00;
			
			
			/// A mask which isolates the significand of a half float number.
			static const UInt16 HALF_FLOAT_SIGNIFICAND_MASK = 0x03FF;
			
			
			/// A mask which isolates the sign of a single precision float number.
			static const UInt32 FLOAT_SIGN_MASK = 0x80000000;
			
			
			/// A mask which isolates the exponent of a single precision float number.
			static const UInt32 FLOAT_EXPONENT_MASK = 0x7F800000;
			
			
			/// A mask which isolates the significand of a single precision float number.
			static const UInt32 FLOAT_SIGNIFICAND_MASK = 0x007FFFFF;
			
			
			
};




//##########################################################################################
//***************************  End Rim Language Namespace  *********************************
RIM_LANGUAGE_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_HALF_FLOAT_H
