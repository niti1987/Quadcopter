/*
 *  Fixed.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 11/6/07.
 *  Copyrivalueht 2007 Rim Software. All rivaluehts reserved.
 *
 */

#ifndef INCLUDE_RIM_FIXED_H
#define INCLUDE_RIM_FIXED_H


#include "rimMathConfig.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a fixed-point number.
template < typename BaseType, Size fractionalBits >
class Fixed
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			RIM_FORCE_INLINE Fixed()
				:	value( BaseType(0) )
			{
			}
			
			
			
			
			RIM_FORCE_INLINE Fixed( float a )
				:	value( BaseType(a*FLOAT_SHIFT) )
			{
			}
			
			
			
			
			RIM_FORCE_INLINE Fixed( double a )
				:	value( BaseType(a*DOUBLE_SHIFT) )
			{
			}
			
			
			
			
			RIM_FORCE_INLINE Fixed( int a )
				:	value( BaseType(a) << fractionalBits )
			{
			}
			
			
			
			
			RIM_FORCE_INLINE Fixed( unsigned int a )
				:	value( BaseType(a) << fractionalBits )
			{
			}
			
			
			
			
			RIM_FORCE_INLINE Fixed( long a )
				:	value( BaseType(a) << fractionalBits )
			{
			}
			
			
			
			
			RIM_FORCE_INLINE Fixed( unsigned long a )
				:	value( BaseType(a) << fractionalBits )
			{
			}
			
			
			
			
			RIM_FORCE_INLINE Fixed( long long a )
				:	value( BaseType(a) << fractionalBits )
			{
			}
			
			
			
			
			RIM_FORCE_INLINE Fixed( unsigned long long a )
				:	value( BaseType(a) << fractionalBits )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			template < typename PrimitiveType >
			RIM_FORCE_INLINE Fixed& operator = ( PrimitiveType a )
			{
				value = Fixed(a).value;
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Type Conversion Operators
			
			
			
			
			RIM_FORCE_INLINE operator float () const
			{
				return float(value) * INVERSE_FLOAT_SHIFT;
			}
			
			
			
			
			RIM_FORCE_INLINE operator double () const
			{
				return double(value) * INVERSE_DOUBLE_SHIFT;
			}
			
			
			
			
			RIM_FORCE_INLINE operator int () const
			{
				return value >> fractionalBits;
			}
			
			
			
			
			RIM_FORCE_INLINE operator unsigned int () const
			{
				return value >> fractionalBits;
			}
			
			
			
			
			RIM_FORCE_INLINE operator long () const
			{
				return value >> fractionalBits;
			}
			
			
			
			
			RIM_FORCE_INLINE operator unsigned long () const
			{
				return value >> fractionalBits;
			}
			
			
			
			
			RIM_FORCE_INLINE operator long long () const
			{
				return value >> fractionalBits;
			}
			
			
			
			
			RIM_FORCE_INLINE operator unsigned long long () const
			{
				return value >> fractionalBits;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			RIM_FORCE_INLINE Bool operator == ( const Fixed& other ) const
			{
				return value == other.value;
			}
			
			
			
			
			RIM_FORCE_INLINE Bool operator != ( const Fixed& other ) const
			{
				return value != other.value;
			}
			
			
			
			
			RIM_FORCE_INLINE Bool operator <= ( const Fixed& other ) const
			{
				return value <= other.value;
			}
			
			
			
			
			RIM_FORCE_INLINE Bool operator >= ( const Fixed& other ) const
			{
				return value >= other.value;
			}
			
			
			
			
			RIM_FORCE_INLINE Bool operator < ( const Fixed& other ) const
			{
				return value < other.value;
			}
			
			
			
			
			RIM_FORCE_INLINE Bool operator > ( const Fixed& other ) const
			{
				return value > other.value;
			}
			
			
			
			
			template < typename PrimitiveType >
			RIM_FORCE_INLINE Bool operator == ( PrimitiveType other ) const
			{
				return value == Fixed(other).value;
			}
			
			
			
			
			template < typename PrimitiveType >
			RIM_FORCE_INLINE Bool operator != ( PrimitiveType other ) const
			{
				return value != Fixed(other).value;
			}
			
			
			
			
			template < typename PrimitiveType >
			RIM_FORCE_INLINE Bool operator <= ( PrimitiveType other ) const
			{
				return value <= Fixed(other).value;
			}
			
			
			
			
			template < typename PrimitiveType >
			RIM_FORCE_INLINE Bool operator >= ( PrimitiveType other ) const
			{
				return value >= Fixed(other).value;
			}
			
			
			
			
			template < typename PrimitiveType >
			RIM_FORCE_INLINE Bool operator < ( PrimitiveType other ) const
			{
				return value < Fixed(other).value;
			}
			
			
			
			
			template < typename PrimitiveType >
			RIM_FORCE_INLINE Bool operator > ( PrimitiveType other ) const
			{
				return value > Fixed(other).value;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sign Change Operators
			
			
			
			
			RIM_FORCE_INLINE Fixed operator + () const
			{
				return Fixed( value, 0 );
			}
			
			
			
			
			RIM_FORCE_INLINE Fixed operator - () const
			{ 
				return Fixed( -value, 0 );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Operators
			
			
			
			
			RIM_FORCE_INLINE Fixed operator + ( const Fixed& other ) const
			{
				return Fixed( value + other.value, 0 );
			}
			
			
			
			
			RIM_FORCE_INLINE Fixed operator - ( const Fixed& other ) const
			{
				return Fixed( value - other.value, 0 );
			}
			
			
			
			
			RIM_FORCE_INLINE Fixed operator * ( const Fixed& other ) const
			{
				return Fixed( (value * other.value) >> fractionalBits, 0 );
			}
			
			
			
			
			RIM_FORCE_INLINE Fixed operator / ( const Fixed& other ) const
			{
				return Fixed( BaseType((double(value) / double(other.value))*DOUBLE_SHIFT), 0 );
			}
			
			
			
			
			template < typename PrimitiveType >
			RIM_FORCE_INLINE Fixed operator + ( PrimitiveType value ) const
			{
				return (*this) + Fixed(value);
			}
			
			
			
			
			template < typename PrimitiveType >
			RIM_FORCE_INLINE Fixed operator - ( PrimitiveType value ) const
			{
				return (*this) - Fixed(value);
			}
			
			
			
			
			template < typename PrimitiveType >
			RIM_FORCE_INLINE Fixed operator * ( PrimitiveType value ) const
			{
				return (*this) * Fixed(value);
			}
			
			
			
			
			template < typename PrimitiveType >
			RIM_FORCE_INLINE Fixed operator / ( PrimitiveType value ) const
			{
				return (*this) / Fixed(value);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Assignment Operators
			
			
			
			
			RIM_FORCE_INLINE Fixed& operator += ( const Fixed& other ) const
			{
				value += other.value;
				
				return *this;
			}
			
			
			
			
			RIM_FORCE_INLINE Fixed& operator -= ( const Fixed& other ) const
			{
				value -= other.value;
				
				return *this;
			}
			
			
			
			
			RIM_FORCE_INLINE Fixed& operator *= ( const Fixed& other ) const
			{
				value = (value * other.value) >> fractionalBits;
				
				return *this;
			}
			
			
			
			
			RIM_FORCE_INLINE Fixed& operator /= ( const Fixed& other ) const
			{
				value = BaseType((double(value) / double(other.value))*DOUBLE_SHIFT);
				
				return *this;
			}
			
			
			
			
			template < typename PrimitiveType >
			RIM_FORCE_INLINE Fixed& operator += ( PrimitiveType value ) const
			{
				value = ((*this) + Fixed(value)).value;
				
				return *this;
			}
			
			
			
			
			template < typename PrimitiveType >
			RIM_FORCE_INLINE Fixed& operator -= ( PrimitiveType value ) const
			{
				value = ((*this) - Fixed(value)).value;
				
				return *this;
			}
			
			
			
			
			template < typename PrimitiveType >
			RIM_FORCE_INLINE Fixed& operator *= ( PrimitiveType value ) const
			{
				value = ((*this) * Fixed(value)).value;
				
				return *this;
			}
			
			
			
			
			template < typename PrimitiveType >
			RIM_FORCE_INLINE Fixed& operator /= ( PrimitiveType value ) const
			{
				value = ((*this) / Fixed(value)).value;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Conversion Methods
			
			
			
			
			/// Convert this vector into a human-readable string representation.
			RIM_NO_INLINE data::String toString() const
			{
				return data::String( (Double)(*this) );
			}
			
			
			
			
			/// Convert this vector into a human-readable string representation.
			RIM_FORCE_INLINE operator data::String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructor
			
			
			
			
			RIM_FORCE_INLINE Fixed( BaseType newValue, int )
				:	value( newValue )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Constants
			
			
			
			
			static const Size fractionalBits2 = fractionalBits*2;
			
			static const BaseType SHIFT = BaseType(1) << fractionalBits;
			
			static const float FLOAT_SHIFT;
			
			static const double DOUBLE_SHIFT;
			
			static const float INVERSE_FLOAT_SHIFT;
			
			static const double INVERSE_DOUBLE_SHIFT;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Member
			
			
			
			
			/// The underlying value which stores the fixed point number.
			BaseType value;
			
			
			
			
};




template < typename BaseType, Size fractionalBits >
const float Fixed<BaseType,fractionalBits>:: FLOAT_SHIFT = float(SHIFT);




template < typename BaseType, Size fractionalBits >
const double Fixed<BaseType,fractionalBits>:: DOUBLE_SHIFT = double(SHIFT);




template < typename BaseType, Size fractionalBits >
const float Fixed<BaseType,fractionalBits>:: INVERSE_FLOAT_SHIFT = 1.0f/FLOAT_SHIFT;




template < typename BaseType, Size fractionalBits >
const double Fixed<BaseType,fractionalBits>:: INVERSE_DOUBLE_SHIFT = 1.0/DOUBLE_SHIFT;




//##########################################################################################
//##########################################################################################
//############		
//############		Commutative Comparison Operators
//############		
//##########################################################################################
//##########################################################################################




template < typename PrimitiveType, typename BaseType, Size fractionalBits >
RIM_FORCE_INLINE Bool operator == ( PrimitiveType a, const Fixed<BaseType,fractionalBits>& b )
{
	return Fixed<BaseType,fractionalBits>(a) == b;
}




template < typename PrimitiveType, typename BaseType, Size fractionalBits >
RIM_FORCE_INLINE Bool operator != ( PrimitiveType a, const Fixed<BaseType,fractionalBits>& b )
{
	return Fixed<BaseType,fractionalBits>(a) != b;
}




template < typename PrimitiveType, typename BaseType, Size fractionalBits >
RIM_FORCE_INLINE Bool operator <= ( PrimitiveType a, const Fixed<BaseType,fractionalBits>& b )
{
	return Fixed<BaseType,fractionalBits>(a) <= b;
}




template < typename PrimitiveType, typename BaseType, Size fractionalBits >
RIM_FORCE_INLINE Bool operator >= ( PrimitiveType a, const Fixed<BaseType,fractionalBits>& b )
{
	return Fixed<BaseType,fractionalBits>(a) >= b;
}




template < typename PrimitiveType, typename BaseType, Size fractionalBits >
RIM_FORCE_INLINE Bool operator < ( PrimitiveType a, const Fixed<BaseType,fractionalBits>& b )
{
	return Fixed<BaseType,fractionalBits>(a) < b;
}




template < typename PrimitiveType, typename BaseType, Size fractionalBits >
RIM_FORCE_INLINE Bool operator > ( PrimitiveType a, const Fixed<BaseType,fractionalBits>& b )
{
	return Fixed<BaseType,fractionalBits>(a) > b;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Commutative Arithmetic Operators
//############		
//##########################################################################################
//##########################################################################################




template < typename PrimitiveType, typename BaseType, Size fractionalBits >
RIM_FORCE_INLINE Fixed<BaseType,fractionalBits> operator + ( PrimitiveType a, const Fixed<BaseType,fractionalBits>& b )
{
	return Fixed<BaseType,fractionalBits>(a) + b;
}




template < typename PrimitiveType, typename BaseType, Size fractionalBits >
RIM_FORCE_INLINE Fixed<BaseType,fractionalBits> operator - ( PrimitiveType a, const Fixed<BaseType,fractionalBits>& b )
{
	return Fixed<BaseType,fractionalBits>(a) - b;
}




template < typename PrimitiveType, typename BaseType, Size fractionalBits >
RIM_FORCE_INLINE Fixed<BaseType,fractionalBits> operator * ( PrimitiveType a, const Fixed<BaseType,fractionalBits>& b )
{
	return Fixed<BaseType,fractionalBits>(a) * b;
}




template < typename PrimitiveType, typename BaseType, Size fractionalBits >
RIM_FORCE_INLINE Fixed<BaseType,fractionalBits> operator / ( PrimitiveType a, const Fixed<BaseType,fractionalBits>& b )
{
	return Fixed<BaseType,fractionalBits>(a) / b;
}



//##########################################################################################
//##########################################################################################
//############		
//############		Commutative Arithmetic Assignment Operators
//############		
//##########################################################################################
//##########################################################################################




template < typename PrimitiveType, typename BaseType, Size fractionalBits >
RIM_FORCE_INLINE PrimitiveType& operator += ( PrimitiveType& a, const Fixed<BaseType,fractionalBits>& b )
{
	return a = (PrimitiveType)(Fixed<BaseType,fractionalBits>(a) + b);
}




template < typename PrimitiveType, typename BaseType, Size fractionalBits >
RIM_FORCE_INLINE PrimitiveType& operator -= ( PrimitiveType& a, const Fixed<BaseType,fractionalBits>& b )
{
	return a = (PrimitiveType)(Fixed<BaseType,fractionalBits>(a) - b);
}




template < typename PrimitiveType, typename BaseType, Size fractionalBits >
RIM_FORCE_INLINE PrimitiveType& operator *= ( PrimitiveType& a, const Fixed<BaseType,fractionalBits>& b )
{
	return a = (PrimitiveType)(Fixed<BaseType,fractionalBits>(a) * b);
}




template < typename PrimitiveType, typename BaseType, Size fractionalBits >
RIM_FORCE_INLINE PrimitiveType& operator /= ( PrimitiveType& a, const Fixed<BaseType,fractionalBits>& b )
{
	return a = (PrimitiveType)(Fixed<BaseType,fractionalBits>(a) / b);
}



//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_FIXED_H
