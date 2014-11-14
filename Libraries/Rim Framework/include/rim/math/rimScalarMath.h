/*
 *  rimScalarMath.h
 *  Rim Framework
 *	
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SCALAR_MATH_H
#define INCLUDE_RIM_SCALAR_MATH_H


#include "rimMathConfig.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


//##########################################################################################
//##########################################################################################
//############		
//############		Mathematical and Numeric Constants
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
RIM_FORCE_INLINE T pi()
{
	static const double PI = 3.14159265358979323846;
	
	return T(PI);
}




template < typename T >
RIM_FORCE_INLINE T e()
{
	static const double E = 2.71828182845904523536;
	
	return T(E);
}




//##########################################################################################
//##########################################################################################
//############		
//############		Numeric Limit Accessor Methods
//############		
//##########################################################################################
//##########################################################################################




/// Return the Not-A-Number representation for the templated type, or zero if it has none.
template < typename T >
RIM_FORCE_INLINE T nan()
{
	if ( std::numeric_limits<T>::has_quiet_NaN )
		return std::numeric_limits<T>::quiet_NaN();
	else
		return T(0);
}




/// Return the Infinity representation for the templated type, or the maximum value if it has none.
template < typename T >
RIM_FORCE_INLINE T infinity()
{
	if ( std::numeric_limits<T>::has_infinity )
		return std::numeric_limits<T>::infinity();
	else
		return std::numeric_limits<T>::max();
}




/// Return the Negative Infinity representation for the templated type, or the minimum value if it has none.
template < typename T >
RIM_FORCE_INLINE T negativeInfinity()
{
	if ( std::numeric_limits<T>::has_infinity )
		return -std::numeric_limits<T>::infinity();
	else
		return std::numeric_limits<T>::min();
}




/// Return the Negative Infinity representation for the templated type, or the minimum value if it has none.
template <>
RIM_FORCE_INLINE unsigned char negativeInfinity<unsigned char>()
{
	return std::numeric_limits<unsigned char>::min();
}




/// Return the Negative Infinity representation for the templated type, or the minimum value if it has none.
template <>
RIM_FORCE_INLINE unsigned short negativeInfinity<unsigned short>()
{
	return std::numeric_limits<unsigned short>::min();
}




/// Return the Negative Infinity representation for the templated type, or the minimum value if it has none.
template <>
RIM_FORCE_INLINE unsigned int negativeInfinity<unsigned int>()
{
	return std::numeric_limits<unsigned int>::min();
}




/// Return the Negative Infinity representation for the templated type, or the minimum value if it has none.
template <>
RIM_FORCE_INLINE unsigned long negativeInfinity<unsigned long>()
{
	return std::numeric_limits<unsigned long>::min();
}




/// Return the Negative Infinity representation for the templated type, or the minimum value if it has none.
template <>
RIM_FORCE_INLINE unsigned long long negativeInfinity<unsigned long long>()
{
	return std::numeric_limits<unsigned long long>::min();
}




/// Return the maximum allowable finite value for the template parameter type.
template < typename T >
RIM_FORCE_INLINE T max()
{
	return std::numeric_limits<T>::max();
}




/// Return the minimum allowable finite value for the template parameter type.
template < typename T >
RIM_FORCE_INLINE T min()
{
	return std::numeric_limits<T>::min();
}




/// Return the minimum allowable finite value for the template parameter type.
template <>
RIM_FORCE_INLINE float min<float>()
{
	return -std::numeric_limits<float>::max();
}




/// Return the minimum allowable finite value for the template parameter type.
template <>
RIM_FORCE_INLINE double min<double>()
{
	return -std::numeric_limits<double>::max();
}




/// Return the smallest deviation from the value 1 that the templated type can represent.
template < typename T >
RIM_FORCE_INLINE T epsilon()
{
	return T(1);
}



/// Return the smallest deviation from the value 1 that a float can represent.
template <>
RIM_FORCE_INLINE float epsilon()
{
	return std::numeric_limits<float>::epsilon();
}




/// Return the smallest deviation from the value 1 that a double can represent.
template <>
RIM_FORCE_INLINE double epsilon()
{
	return std::numeric_limits<double>::epsilon();
}




//##########################################################################################
//##########################################################################################
//############		
//############		Numeric Limit Comparison Methods
//############		
//##########################################################################################
//##########################################################################################




/// Get whether a number is equal to the representation of Infinity for its type.
template < typename T >
RIM_FORCE_INLINE bool isInfinity( T number )
{
	if ( std::numeric_limits<T>::has_infinity )
		return number == std::numeric_limits<T>::infinity();
	else
		return number == std::numeric_limits<T>::max();
}




/// Get whether a number is equal to the representation of Negative Infinity for its type.
template < typename T >
RIM_FORCE_INLINE bool isNegativeInfinity( T number )
{
	if ( std::numeric_limits<T>::has_infinity )
		return number == -std::numeric_limits<T>::infinity();
	else
		return number == std::numeric_limits<T>::min();
}




template <>
RIM_FORCE_INLINE bool isNegativeInfinity( unsigned char number )
{
	return false;
}




template <>
RIM_FORCE_INLINE bool isNegativeInfinity( unsigned short number )
{
	return false;
}




template <>
RIM_FORCE_INLINE bool isNegativeInfinity( unsigned int number )
{
	return false;
}




template <>
RIM_FORCE_INLINE bool isNegativeInfinity( unsigned long number )
{
	return false;
}




template <>
RIM_FORCE_INLINE bool isNegativeInfinity( unsigned long long number )
{
	return false;
}




/// Get whether a number is equal to Negative or Positive Infinity for its type.
template < typename T >
RIM_FORCE_INLINE bool isInfinite( T number )
{
	return math::isInfinity( number ) || math::isNegativeInfinity( number );
}




/// Get whether a number is finite.
template < typename T >
RIM_FORCE_INLINE bool isFinite( T number )
{
	return !isInfinite( number );
}




/// Get whether or not the specified number is Not-A-Number.
template < typename T >
RIM_FORCE_INLINE bool isNAN( T number )
{
	return number != number;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Value Kind Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
RIM_FORCE_INLINE bool isInteger()
{
	return false;
}




template <>
RIM_FORCE_INLINE bool isInteger<char>()
{
	return true;
}




template <>
RIM_FORCE_INLINE bool isInteger<unsigned char>()
{
	return true;
}




template <>
RIM_FORCE_INLINE bool isInteger<short>()
{
	return true;
}




template <>
RIM_FORCE_INLINE bool isInteger<unsigned short>()
{
	return true;
}




template <>
RIM_FORCE_INLINE bool isInteger<int>()
{
	return true;
}




template <>
RIM_FORCE_INLINE bool isInteger<unsigned int>()
{
	return true;
}




template <>
RIM_FORCE_INLINE bool isInteger<long>()
{
	return true;
}




template <>
RIM_FORCE_INLINE bool isInteger<unsigned long>()
{
	return true;
}




template <>
RIM_FORCE_INLINE bool isInteger<long long>()
{
	return true;
}




template <>
RIM_FORCE_INLINE bool isInteger<unsigned long long>()
{
	return true;
}




template < typename T >
RIM_FORCE_INLINE bool isInteger( T number )
{
	return isInteger<T>();
}




template < typename T >
RIM_FORCE_INLINE bool isFloatingPoint()
{
	return false;
}




template <>
RIM_FORCE_INLINE bool isFloatingPoint<float>()
{
	return true;
}




template <>
RIM_FORCE_INLINE bool isFloatingPoint<double>()
{
	return true;
}




template < typename T >
RIM_FORCE_INLINE bool isFloatingPoint( T number )
{
	return isFloatingPoint<T>();
}




//##########################################################################################
//##########################################################################################
//############		
//############		Absolute Value Methods
//############		
//##########################################################################################
//##########################################################################################




/// Return the absolute value of the specified number, such that the result is positive.
template < typename T >
RIM_FORCE_INLINE T abs( T number )
{
	return number < T(0) ? -number : number;
}




template <>
RIM_FORCE_INLINE float abs( float number )
{
	return std::abs( number );
}




template <>
RIM_FORCE_INLINE double abs( double number )
{
	return std::abs( number );
}




template <>
RIM_FORCE_INLINE unsigned char abs( unsigned char value )
{
	return value;
}




template <>
RIM_FORCE_INLINE unsigned short abs( unsigned short value )
{
	return value;
}




template <>
RIM_FORCE_INLINE unsigned int abs( unsigned int value )
{
	return value;
}




template <>
RIM_FORCE_INLINE unsigned long abs( unsigned long value )
{
	return value;
}




template <>
RIM_FORCE_INLINE unsigned long long abs( unsigned long long value )
{
	return value;
}





//##########################################################################################
//##########################################################################################
//############		
//############		Sign Determination Methods
//############		
//##########################################################################################
//##########################################################################################




/// Return -1 if the number is less than zero, 0 if it is zero, and 1 otherwise.
template < typename T >
RIM_FORCE_INLINE T sign( T number )
{
	return (T)((T(0) < number) - (number < T(0)));
}




template <>
RIM_FORCE_INLINE unsigned char sign( unsigned char value )
{
	return 1;
}




template <>
RIM_FORCE_INLINE unsigned short sign( unsigned short value )
{
	return 1;
}




template <>
RIM_FORCE_INLINE unsigned int sign( unsigned int value )
{
	return 1;
}




template <>
RIM_FORCE_INLINE unsigned long sign( unsigned long value )
{
	return 1;
}




template <>
RIM_FORCE_INLINE unsigned long long sign( unsigned long long value )
{
	return 1;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Equality Determination Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
RIM_FORCE_INLINE bool equals( T value1, T value2 )
{
	return value1 == value2;
}



template <>
RIM_FORCE_INLINE bool equals( float value1, float value2 )
{
	return math::abs(value1 - value2) < math::epsilon<float>();
}




template <>
RIM_FORCE_INLINE bool equals( double value1, double value2 )
{
	return math::abs(value1 - value2) < math::epsilon<double>();
}




template < typename T >
RIM_FORCE_INLINE bool fuzzyEquals( T value1, T value2, T epsilon )
{
	return math::abs(value1 - value2) < epsilon;
}




template < typename T >
RIM_FORCE_INLINE bool isZero( T value, T epsilon )
{
	return math::abs(value) < epsilon;
}




template < typename T >
RIM_FORCE_INLINE bool isZero( T value )
{
	return value == T(0);
}




template <>
RIM_FORCE_INLINE bool isZero( float value )
{
	return math::abs(value - 0.0f) < math::epsilon<float>();
}




template <>
RIM_FORCE_INLINE bool isZero( double value )
{
	return math::abs(value - 0.0) < math::epsilon<double>();
}





//##########################################################################################
//##########################################################################################
//############		
//############		Average Methods
//############		
//##########################################################################################
//##########################################################################################





template < typename T >
RIM_FORCE_INLINE T average( T value1, T value2 )
{
	return (value1 + value2) / T(2);
}




template <>
RIM_FORCE_INLINE float average( float value1, float value2 )
{
	return (value1 + value2) * 0.5f;
}




template <>
RIM_FORCE_INLINE double average( double value1, double value2 )
{
	return (value1 + value2) * 0.5;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Number Max/Min/Clamp Methods
//############		
//##########################################################################################
//##########################################################################################




/// Return the larger of two numbers.
template < typename T >
RIM_FORCE_INLINE T max( T value1, T value2 )
{
	return value1 > value2 ? value1 : value2;
}




/// Return the smaller of two numbers.
template < typename T >
RIM_FORCE_INLINE T min( T value1, T value2 )
{
	return value1 < value2 ? value1 : value2;
}




/// Return the result when the a number is constrainted to the interval [minimum, maximum].
template < typename T >
RIM_FORCE_INLINE T clamp( T number, T minimum, T maximum )
{
	return math::min( math::max( number, minimum ), maximum );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Number Floor, Ceiling, and Round Methods
//############		
//##########################################################################################
//##########################################################################################





/// Return the largest whole number smaller than the number parameter, as the same type.
template < typename T >
RIM_FORCE_INLINE T floor( T number )
{
	return number;
}




template <>
RIM_FORCE_INLINE float floor( float number )
{
	return std::floor( number );
}




template <>
RIM_FORCE_INLINE double floor( double number )
{
	return std::floor( number );
}




template < typename T >
RIM_FORCE_INLINE T ceiling( T number )
{
	return number;
}




template <>
RIM_FORCE_INLINE float ceiling( float number )
{
	return std::ceil( number );
}




template <>
RIM_FORCE_INLINE double ceiling( double number )
{
	return std::ceil( number );
}




template < typename T >
RIM_FORCE_INLINE T round( T value )
{
	return value;
}




template <>
RIM_FORCE_INLINE float round( float value )
{
	return math::floor( value + 0.5f );
}




template <>
RIM_FORCE_INLINE double round( double value )
{
	return math::floor( value + 0.5 );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Square Root Methods
//############		
//##########################################################################################
//##########################################################################################




namespace detail
{
	template < typename T >
	RIM_INLINE T recursiveSquareRoot( T n, T x1 )
	{
		T x2 = (x1 + n/x1) / T(2);
		
		if ( x1 - x2  < T(1) )
			return x2;
		else
			return recursiveSquareRoot( n, x2 );
	}
};




template < typename T >
RIM_FORCE_INLINE T sqrti( T value )
{
	if ( value < T(0) )
		return math::nan<T>();
	else
		return detail::recursiveSquareRoot( value, value );
}




template < typename T >
RIM_FORCE_INLINE T sqrt( T value )
{
	return (T)std::sqrt( (double)value );
}




template <>
RIM_FORCE_INLINE float sqrt( float value )
{
	return std::sqrt( value );
}




template <>
RIM_FORCE_INLINE double sqrt( double value )
{
	return std::sqrt( value );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Power Methods
//############		
//##########################################################################################
//##########################################################################################




/// Get the previous multiple of a base that is less than or equal to a specified number.
template < typename T >
RIM_FORCE_INLINE T previousMultiple( T number, T base )
{
	return math::floor( number / base )*base;
}




/// Get the next multiple of a base that is greater than or equal to a specified number.
template < typename T >
RIM_FORCE_INLINE T nextMultiple( T number, T base )
{
	T temp = math::floor( number / base )*base;
	
	return temp == number ? temp : temp + base;
}




/// Get the multiple of a base that the closest to a specified number.
template < typename T >
RIM_FORCE_INLINE T nearestMultiple( T number, T base )
{
	return math::round( number / base )*base;
}




/// Return the first power of two larger than the specified number.
template < typename T >
RIM_FORCE_INLINE T nextPowerOfTwo( T x )
{
	T powerOfTwo = T(1);
	
	while ( powerOfTwo < x )
		powerOfTwo *= T(2);
	
	return powerOfTwo;
}




/// Return the first power of two larger than the specified number.
template <>
RIM_FORCE_INLINE char nextPowerOfTwo( char x )
{
	x |= x >> 1;  // handle  2 bit numbers
	x |= x >> 2;  // handle  4 bit numbers
	x |= x >> 4;  // handle  8 bit numbers
	
	return x + 1;
}




/// Return the first power of two larger than the specified number.
template <>
RIM_FORCE_INLINE unsigned char nextPowerOfTwo( unsigned char x )
{
	x |= x >> 1;  // handle  2 bit numbers
	x |= x >> 2;  // handle  4 bit numbers
	x |= x >> 4;  // handle  8 bit numbers
	
	return x + 1;
}




/// Return the first power of two larger than the specified number.
template <>
RIM_FORCE_INLINE short nextPowerOfTwo( short x )
{
	x |= x >> 1;  // handle  2 bit numbers
	x |= x >> 2;  // handle  4 bit numbers
	x |= x >> 4;  // handle  8 bit numbers
	x |= x >> 8;  // handle 16 bit numbers
	
	return x + 1;
}




/// Return the first power of two larger than the specified number.
template <>
RIM_FORCE_INLINE unsigned short nextPowerOfTwo( unsigned short x )
{
	x |= x >> 1;  // handle  2 bit numbers
	x |= x >> 2;  // handle  4 bit numbers
	x |= x >> 4;  // handle  8 bit numbers
	x |= x >> 8;  // handle 16 bit numbers
	
	return x + 1;
}



/// Return the first power of two larger than the specified number.
template <>
RIM_FORCE_INLINE int nextPowerOfTwo( int x )
{
	x |= x >> 1;  // handle  2 bit numbers
	x |= x >> 2;  // handle  4 bit numbers
	x |= x >> 4;  // handle  8 bit numbers
	x |= x >> 8;  // handle 16 bit numbers
	x |= x >> 16; // handle 32 bit numbers
	
	return x + 1;
}



/// Return the first power of two larger than the specified number.
template <>
RIM_FORCE_INLINE unsigned int nextPowerOfTwo( unsigned int x )
{
	x |= x >> 1;  // handle  2 bit numbers
	x |= x >> 2;  // handle  4 bit numbers
	x |= x >> 4;  // handle  8 bit numbers
	x |= x >> 8;  // handle 16 bit numbers
	x |= x >> 16; // handle 32 bit numbers
	
	return x + 1;
}



/// Return the first power of two larger than the specified number.
template <>
RIM_FORCE_INLINE long nextPowerOfTwo( long x )
{
	x |= x >> 1;  // handle  2 bit numbers
	x |= x >> 2;  // handle  4 bit numbers
	x |= x >> 4;  // handle  8 bit numbers
	x |= x >> 8;  // handle 16 bit numbers
	x |= x >> 16; // handle 32 bit numbers
	
	return x + 1;
}



/// Return the first power of two larger than the specified number.
template <>
RIM_FORCE_INLINE unsigned long nextPowerOfTwo( unsigned long x )
{
	x |= x >> 1;  // handle  2 bit numbers
	x |= x >> 2;  // handle  4 bit numbers
	x |= x >> 4;  // handle  8 bit numbers
	x |= x >> 8;  // handle 16 bit numbers
	x |= x >> 16; // handle 32 bit numbers
	
	return x + 1;
}



/// Return the first power of two larger than the specified number.
template <>
RIM_FORCE_INLINE long long nextPowerOfTwo( long long x )
{
	x |= x >> 1;  // handle  2 bit numbers
	x |= x >> 2;  // handle  4 bit numbers
	x |= x >> 4;  // handle  8 bit numbers
	x |= x >> 8;  // handle 16 bit numbers
	x |= x >> 16; // handle 32 bit numbers
	x |= x >> 32; // handle 64 bit numbers
	
	return x + 1;
}



/// Return the first power of two larger than the specified number.
template <>
RIM_FORCE_INLINE unsigned long long nextPowerOfTwo( unsigned long long x )
{
	x |= x >> 1;  // handle  2 bit numbers
	x |= x >> 2;  // handle  4 bit numbers
	x |= x >> 4;  // handle  8 bit numbers
	x |= x >> 8;  // handle 16 bit numbers
	x |= x >> 16; // handle 32 bit numbers
	x |= x >> 32; // handle 64 bit numbers
	
	return x + 1;
}




/// Return whether or not the specified number is a power of 2.
template < typename T >
RIM_FORCE_INLINE Bool isPowerOfTwo( T number )
{
	return (number > 0) && ((number & (number - 1)) == 0);
}




namespace detail
{
	template < typename T >
	RIM_FORCE_INLINE bool multWillOverflow( T a, T b )
	{
		if ( a > 0 )
		{
			if ( b > 0 )
				return b > math::max<T>() / a;
			else if ( b < 0 )
				return b < math::min<T>() / a;
		}
		else if ( a < 0 )
		{
			if ( b > 0 )
				return a < math::min<T>() / b;
			else if ( b < 0 )
				return b < math::max<T>() / a;
		}
		
		return false;
	}
	
	
	
	
	template < typename T >
	RIM_FORCE_INLINE bool unsignedMultWillOverflow( T a, T b )
	{
		return b > math::max<T>() / a;
	}
	
	
	
	
	template < typename IntegerType >
	RIM_FORCE_INLINE IntegerType integerPower( IntegerType base, IntegerType power )
	{
		if ( power < 0 )
			return 0;
		
		IntegerType result = 1;
		
		for ( IntegerType i = 0; i < power; i++ )
		{
			// was there overflow for this numeric type?
			if ( multWillOverflow( result, base ) )
			{
				if ( base > 0 )
					return math::infinity<IntegerType>();
				else if ( power % 2 == 0 )
					return math::infinity<IntegerType>();
				else
					return math::negativeInfinity<IntegerType>();
			}
			
			result *= base;
		}
		
		return result;
	}
	
	
	
	
	template < typename IntegerType >
	RIM_FORCE_INLINE IntegerType unsignedIntegerPower( IntegerType base, IntegerType power )
	{
		IntegerType result = 1;
		
		for ( IntegerType i = 0; i < power; i++ )
		{
			// was there overflow for this numeric type?
			if ( unsignedMultWillOverflow( result, base ) )
				return math::infinity<IntegerType>();
			
			result *= base;
		}
		
		return result;
	}
}




template < typename T, typename U >
RIM_FORCE_INLINE T pow( T base, U power )
{
	return std::pow( base, power );
}




template <>
RIM_FORCE_INLINE char pow( char base, char power )
{
	return detail::integerPower( base, power );
}




template <>
RIM_FORCE_INLINE unsigned char pow( unsigned char base, unsigned char power )
{
	return detail::unsignedIntegerPower( base, power );
}




template <>
RIM_FORCE_INLINE short pow( short base, short power )
{
	return detail::integerPower( base, power );
}




template <>
RIM_FORCE_INLINE unsigned short pow( unsigned short base, unsigned short power )
{
	return detail::unsignedIntegerPower( base, power );
}




template <>
RIM_FORCE_INLINE int pow( int base, int power )
{
	return detail::integerPower( base, power );
}




template <>
RIM_FORCE_INLINE unsigned int pow( unsigned int base, unsigned int power )
{
	return detail::unsignedIntegerPower( base, power );
}




template <>
RIM_FORCE_INLINE long pow( long base, long power )
{
	return detail::integerPower( base, power );
}




template <>
RIM_FORCE_INLINE unsigned long pow( unsigned long base, unsigned long power )
{
	return detail::unsignedIntegerPower( base, power );
}




template <>
RIM_FORCE_INLINE long long pow( long long base, long long power )
{
	return detail::integerPower( base, power );
}




template <>
RIM_FORCE_INLINE unsigned long long pow( unsigned long long base, unsigned long long power )
{
	return detail::unsignedIntegerPower( base, power );
}




using std::exp;




template < typename T >
RIM_FORCE_INLINE T square( T value )
{
	return value*value;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Logarithm Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
RIM_FORCE_INLINE T ln( T value )
{
	return std::log( value );
}




template < typename T >
RIM_FORCE_INLINE T log10( T value )
{
	return std::log10( value );
}




namespace detail
{
	template < typename T, T base >
	RIM_FORCE_INLINE T intLog( T value )
	{
		if ( value <= T(0) )
		{
			return math::negativeInfinity<T>();
		}
		
		T power = 1;
		T i = 0;
		
		while ( power <= value )
		{
			power *= base;
			i++;
		}
		
		return i - 1;
	}
}




template <>
RIM_FORCE_INLINE short log10( short value )
{
	return detail::intLog<short,10>( value );
}




template <>
RIM_FORCE_INLINE unsigned short log10( unsigned short value )
{
	return detail::intLog<unsigned short,10>( value );
}




template <>
RIM_FORCE_INLINE int log10( int value )
{
	return detail::intLog<int,10>( value );
}




template <>
RIM_FORCE_INLINE unsigned int log10( unsigned int value )
{
	return detail::intLog<unsigned int,10>( value );
}




template <>
RIM_FORCE_INLINE long log10( long value )
{
	return detail::intLog<long,10>( value );
}




template <>
RIM_FORCE_INLINE unsigned long log10( unsigned long value )
{
	return detail::intLog<unsigned long,10>( value );
}




template <>
RIM_FORCE_INLINE long long log10( long long value )
{
	return detail::intLog<long long,10>( value );
}




template <>
RIM_FORCE_INLINE unsigned long long log10( unsigned long long value )
{
	return detail::intLog<unsigned long long,10>( value );
}





template < typename T >
RIM_FORCE_INLINE T log( T value, T base )
{
	double valueLog = math::log10( (double)value );
	double baseLog = math::log10( (double)base );
	
	if ( valueLog == 0.0 || baseLog == 0.0 )
		return T(0);
	else
		return T(valueLog / baseLog);
}





template <>
RIM_FORCE_INLINE float log( float value, float base )
{
	if ( base == 1.0f )
		return 0.0f;
	
	float valueLog = math::log10( value );
	float baseLog = math::log10( base );
	
	return valueLog / baseLog;
}





template < typename T >
RIM_FORCE_INLINE T log2( T value )
{
	return math::log( value, T(2) );
}




template <>
RIM_FORCE_INLINE float log2( float value )
{
	float valueLog = math::ln( value );
	float baseLog = math::ln(2.0f);
	
	return valueLog / baseLog;
}




template <>
RIM_FORCE_INLINE double log2( double value )
{
	double valueLog = math::ln( value );
	double baseLog = math::ln(2.0);
	
	return valueLog / baseLog;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Modulus Methods
//############		
//##########################################################################################
//##########################################################################################




/// Compute the remainder when the specified value is divided by the given divisor.
template < typename T >
RIM_INLINE T mod( T value, T divisor )
{
	return value % divisor;
}




/// Compute the remainder when the specified value is divided by the given divisor.
template <>
RIM_INLINE float mod( float value, float divisor )
{
	return std::fmod( value, divisor );
}




/// Compute the remainder when the specified value is divided by the given divisor.
template <>
RIM_INLINE double mod( double value, double divisor )
{
	return std::fmod( value, divisor );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Radian<->Degree Conversion Methods
//############		
//##########################################################################################
//##########################################################################################




RIM_FORCE_INLINE float radiansToDegrees( float number )
{
	return number * float(57.295779513082325);
}




RIM_FORCE_INLINE double radiansToDegrees( double number )
{
	return number * double(57.295779513082325);
}




RIM_FORCE_INLINE float degreesToRadians( float number )
{
	return number * float(0.017453292519943);
}




RIM_FORCE_INLINE double degreesToRadians( double number )
{
	return number * double(0.017453292519943);
}




//##########################################################################################
//##########################################################################################
//############		
//############		Trigonometric Function Methods
//############		
//##########################################################################################
//##########################################################################################




using std::sin;
using std::cos;
using std::tan;

using std::asin;
using std::acos;
using std::atan;

using std::asin;
using std::acos;
using std::atan;
using std::atan2;

using std::sinh;
using std::cosh;
using std::tanh;




//##########################################################################################
//##########################################################################################
//############		
//############		Other Trigonometric Functions
//############		
//##########################################################################################
//##########################################################################################




/// Compute and return the secant of the specified value.
template < typename T >
RIM_INLINE T sec( T value )
{
	return T(1) / math::cos(value);
}




/// Compute and return the cosecant of the specified value.
template < typename T >
RIM_INLINE T csc( T value )
{
	return T(1) / math::sin(value);
}




/// Compute and return the cotangent of the specified value.
template < typename T >
RIM_INLINE T cot( T value )
{
	return T(1) / math::tan(value);
}




/// Compute and return the secant of the specified value.
template < typename T >
RIM_INLINE T sech( T value )
{
	return T(1) / math::cosh(value);
}




/// Compute and return the cosecant of the specified value.
template < typename T >
RIM_INLINE T csch( T value )
{
	return T(1) / math::sinh(value);
}




/// Compute and return the cotangent of the specified value.
template < typename T >
RIM_INLINE T coth( T value )
{
	return T(1) / math::tanh(value);
}




//##########################################################################################
//##########################################################################################
//############		
//############		Inverse Hyperbolic Trig Functions
//############		
//##########################################################################################
//##########################################################################################




/// Compute and return the inverse hyperbolic sine of the specified value.
template < typename T >
RIM_INLINE T asinh( T value )
{
	if ( value >= T(0) )
		return math::ln(value + math::sqrt(value*value + T(1)));
	else
		return -math::ln(-value + math::sqrt(value*value + T(1)));
}




/// Compute and return the inverse hyperbolic cosine of the specified value.
template < typename T >
RIM_INLINE T acosh( T value )
{
	if ( value > T(1) )
		return math::ln(value + math::sqrt(value - T(1))*math::sqrt(value + T(1)));
	else
		return math::nan<T>();
}




/// Compute and return the inverse hyperbolic tangent of the specified value.
template < typename T >
RIM_INLINE T atanh( T value )
{
	if ( value >= T(0) )
	{
		if ( value >= T(1) )
			return math::nan<T>();
		
		return T(0.5)*(math::ln(T(1) + value) - math::ln(T(1) - value));
	}
	else
	{
		if ( value <= T(-1) )
			return math::nan<T>();
		
		return -T(0.5)*(math::ln(T(1) - value) - math::ln(T(1) + value));
	}
}




/// Compute and return the inverse hyperbolic secant of the specified value.
template < typename T >
RIM_INLINE T asech( T value )
{
	if ( value > T(0) && value <= T(1) )
		return math::ln( math::sqrt(T(-1) + T(1)/value)*math::sqrt(T(1) + T(1)/value) + T(1)/value );
	else
		return math::nan<T>();
}




/// Compute and return the inverse hyperbolic cosecant of the specified value.
template < typename T >
RIM_INLINE T acsch( T value )
{
	if ( value > T(0) )
		return math::ln( math::sqrt(T(1) + T(1)/(value*value)) + T(1)/value );
	else if ( value < T(0) )
		return math::ln( math::sqrt(T(1) + T(1)/(value*value)) + T(1)/value );
	else
		return math::nan<T>();
}




/// Compute and return the inverse hyperbolic cotangent of the specified value.
template < typename T >
RIM_INLINE T acoth( T value )
{
	if ( value > T(1) )
		return T(0.5)*(math::ln(T(1) + T(1)/value) - math::ln(T(1) - T(1)/value));
	else if ( value < T(-1) )
		return -T(0.5)*(math::ln(T(1) - T(1)/value) - math::ln(T(1) + T(1)/value));
	else
		return math::nan<T>();
}




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SCALAR_MATH_H
