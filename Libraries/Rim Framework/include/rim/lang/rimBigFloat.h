/*
 *  rimBigFloat.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/16/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_BIG_FLOAT_H
#define INCLUDE_RIM_BIG_FLOAT_H


#include "rimLanguageConfig.h"


//##########################################################################################
//***************************  Start Rim Language Namespace  *******************************
RIM_LANGUAGE_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which stores a high-precision floating point number.
/**
  * The precision should be at least great enough to accurately represent the
  * locations of objects on a galactic scale down to sub-millimeter precision.
  * The class uses a signed integer + signed fractional component representation
  * in order to enable high precision. The arithmetic operators defined for the
  * type are implemented so that there is minimal loss in precision.
  *
  * The class uses a template parameter type to specify the maximum value allowed
  * for the fractional component of the number. This determines the smallest and largest
  * values that the number is able to represent accurately. A bigger unit size will
  * allow bigger number to be represented at the expense of small-scale precision, while
  * a larger unit size will allow better small-scale precision at the expense of
  * the maximum range of the type.
  */
template < UInt unit = 1 >
class BigFloat
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			/// The type to use for the integer component of this big float.
			typedef Int64 IntegerType;
			
			
			
			
			/// The type to use for the fractional component of this big float.
			typedef Float32 FloatType;
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a BigFloat object with the value 0.
			RIM_FORCE_INLINE BigFloat()
				:	integer( 0 ),
					fraction( 0 )
			{
			}
			
			
			
			
			/// Create a BigFloat object with the value of the specified byte.
			RIM_FORCE_INLINE BigFloat( Byte value )
			{
				floatToBigFloat( (Float)value, integer, fraction );
			}
			
			
			
			
			/// Create a BigFloat object with the value of the specified short number.
			RIM_FORCE_INLINE BigFloat( Short value )
			{
				floatToBigFloat( (Float)value, integer, fraction );
			}
			
			
			
			
			/// Create a BigFloat object with the value of the specified int number.
			RIM_FORCE_INLINE BigFloat( Int value )
			{
				doubleToBigFloat( (Double)value, integer, fraction );
			}
			
			
			
			
			/// Create a BigFloat object with the value of the specified long number.
			RIM_FORCE_INLINE BigFloat( Long value )
			{
				doubleToBigFloat( (Double)value, integer, fraction );
			}
			
			
			
			
			/// Create a BigFloat object with the value of the specified long-long number.
			RIM_FORCE_INLINE BigFloat( LongLong value )
			{
				doubleToBigFloat( (Double)value, integer, fraction );
			}
			
			
			
			
			/// Create a BigFloat object with the value of the specified float number.
			RIM_FORCE_INLINE BigFloat( Float value )
			{
				floatToBigFloat( value, integer, fraction );
			}
			
			
			
			
			/// Create a BigFloat object with the value of the specified double number.
			RIM_FORCE_INLINE BigFloat( Double value )
			{
				doubleToBigFloat( value, integer, fraction );
			}
			
			
			
			
			/// Create a new big float which uses the specified integer and fractional components.
			RIM_FORCE_INLINE BigFloat( IntegerType newInteger, Float newFraction )
				:	integer( newInteger ),
					fraction( newFraction )
			{
				normalize( integer, fraction );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Assignment Operators
			
			
			
			
			/// Add another BigFloat to this big float's value.
			RIM_FORCE_INLINE BigFloat& operator += ( const BigFloat& other )
			{
				integer += other.integer;
				fraction += other.fraction;
				normalize( integer, fraction );
				
				return *this;
			}
			
			
			
			
			/// Subtract another BigFloat from this big float's value.
			RIM_FORCE_INLINE BigFloat& operator -= ( const BigFloat& other )
			{
				integer -= other.integer;
				fraction -= other.fraction;
				normalize( integer, fraction );
				
				return *this;
			}
			
			
			
			
			/// Multiply this big float's value by another BigFloat.
			RIM_FORCE_INLINE BigFloat& operator *= ( const BigFloat& other )
			{
				IntegerType i = integer*other.integer;
				FloatType f = fraction*other.fraction;
				Double d = Double(integer)*Double(other.fraction) + 
							Double(fraction)*Double(other.integer);
				
				IntegerType i2;
				FloatType f2;
				doubleToBigFloat( d, i2, f2 );
				integer = i + i2;
				fraction = f + f2;
				
				return *this;
			}
			
			
			
			
			/// Divide this big float's value by another BigFloat.
			RIM_FORCE_INLINE BigFloat& operator /= ( const BigFloat& other )
			{
				doubleToBigFloat( (Double)(*this) / (Double)other, integer, fraction );
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Operators
			
			
			
			
			/// Add another BigFloat to this big float's value.
			RIM_FORCE_INLINE BigFloat operator + ( const BigFloat& other )
			{
				IntegerType i = integer + other.integer;
				FloatType f = fraction + other.fraction;
				
				return BigFloat( i, f );
			}
			
			
			
			
			/// Subtract another BigFloat from this big float's value.
			RIM_FORCE_INLINE BigFloat operator - ( const BigFloat& other )
			{
				IntegerType i = integer - other.integer;
				FloatType f = fraction - other.fraction;
				
				return BigFloat( i, f );
			}
			
			
			
			
			/// Multiply this big float's value by another BigFloat.
			RIM_FORCE_INLINE BigFloat operator * ( const BigFloat& other )
			{
				IntegerType i = integer*other.integer;
				FloatType f = fraction*other.fraction;
				Double d = Double(integer)*Double(other.fraction) + 
							Double(fraction)*Double(other.integer);
				
				IntegerType i2;
				FloatType f2;
				doubleToBigFloat( d, i2, f2 );
				i += i2;
				f += f2;
				
				return BigFloat( i, f );
			}
			
			
			
			
			/// Divide this big float's value by another BigFloat.
			RIM_FORCE_INLINE BigFloat operator / ( const BigFloat& other )
			{
				return BigFloat( (Double)(*this) / (Double)other );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Internal Representation Accessor Methods
			
			
			
			
			/// Return the integral component of this big float.
			RIM_FORCE_INLINE IntegerType getInteger() const
			{
				return integer;
			}
			
			
			
			
			/// Set the integral component of this big float.
			RIM_FORCE_INLINE void setInteger( IntegerType newInteger )
			{
				integer = newInteger;
			}
			
			
			
			
			/// Return the fractional component of this big float.
			RIM_FORCE_INLINE FloatType getFraction() const
			{
				return fraction;
			}
			
			
			
			
			/// Set the fractional component of this big float.
			/**
			  * This causes the big float to be renormalized to make sure the fractional
			  * component is less than the unit size.
			  */
			RIM_FORCE_INLINE void setFraction( FloatType newFraction )
			{
				fraction = newFraction;
				normalize( integer, fraction );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Cast Operators
			
			
			
			/// Cast the big float object to a single-precision floating point number.
			RIM_FORCE_INLINE operator Float () const
			{
				return bigFloatToFloat( integer, fraction );
			}
			
			
			
			/// Cast the big float object to a double-precision floating point number.
			RIM_FORCE_INLINE operator Double () const
			{
				return bigFloatToDouble( integer, fraction );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Helper Methods
			
			
			
			
			/// Convert the specified single precision float number to a big float number.
			RIM_FORCE_INLINE static void floatToBigFloat( Float floatValue, IntegerType& integer, FloatType& fraction )
			{
				Float floor = math::floor( floatValue/(Float)unit );
				integer = IntegerType(floor);
				fraction = FloatType(floatValue - floor*unit);
			}
			
			
			
			
			/// Convert the specified double precision float number to a big float number.
			RIM_FORCE_INLINE static void doubleToBigFloat( Double doubleValue, IntegerType& integer, FloatType& fraction )
			{
				Double floor = math::floor( doubleValue/(Double)unit );
				integer = IntegerType(floor);
				fraction = FloatType(doubleValue - floor*unit);
			}
			
			
			
			
			/// Convert the specified big float number to a single precision float number.
			RIM_FORCE_INLINE static Float bigFloatToFloat( IntegerType integer, FloatType fraction )
			{
				return Float(integer)*Float(unit) + fraction;
			}
			
			
			
			
			/// Convert the specified big float number to a double precision float number.
			RIM_FORCE_INLINE static Double bigFloatToDouble( IntegerType integer, FloatType fraction )
			{
				return Double(integer)*Double(unit) + Double(fraction);
			}
			
			
			
			
			/// Normalize the specified big float so that the fractional component lies between 0 and 1.
			RIM_FORCE_INLINE static void normalize( IntegerType& integer, FloatType& fraction )
			{
				FloatType floor = math::floor( fraction/(Float)unit );
				integer += IntegerType(floor);
				fraction = FloatType(fraction - floor*unit);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The integer portion of the big floating point number.
			IntegerType integer;
			
			
			
			
			/// The fractional portion of the big floating point number.
			FloatType fraction;
			
			
			
			
};




//##########################################################################################
//***************************  End Rim Language Namespace  *********************************
RIM_LANGUAGE_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_BIG_FLOAT_H
