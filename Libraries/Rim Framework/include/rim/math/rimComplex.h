/*
 *  rimComplex.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 6/19/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_COMPLEX_H
#define INCLUDE_RIM_COMPLEX_H


#include "rimMathConfig.h"


#include "../data/rimBasicString.h"
#include "../data/rimBasicStringBuffer.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a complex number.
/**
  * Overloaded arithmetic operators are provided for all basic arithmetic operations
  * (+, -, *, /, +=, -=, *=, /=). The class allows any underlying type to be used
  * as the coefficients of the real and imaginary components of the complex number
  * via a template parameter.
  */
template < typename T >
class Complex
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a complex number with both real and imaginary parts equal to zero.
			RIM_FORCE_INLINE Complex()
				:	real( 0 ),
					imaginary( 0 )
			{
			}
			
			
			
			/// Create a complex number with the specified real component and zero imaginary component.
			RIM_FORCE_INLINE Complex( T newReal )
				:	real( newReal ),
					imaginary( 0 )
			{
			}
			
			
			
			/// Create a complex number with the specified real and imaginary components.
			RIM_FORCE_INLINE Complex( T newReal, T newImaginary )
				:	real( newReal ),
					imaginary( newImaginary )
			{
			}
			
			
			
			
			/// Create a complex number from another with different template parameter type.
			template < typename U >
			RIM_FORCE_INLINE Complex( const Complex<U>& other )
				:	real( other.real ),
					imaginary( other.imaginary )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Complex Number Operations
			
			
			
			
			/// Return the conjugate of this complex number.
			RIM_FORCE_INLINE Complex conjugate() const
			{
				return Complex( real, -imaginary );
			}
			
			
			
			
			/// Return the magnitude of this complex number.
			RIM_FORCE_INLINE T getMagnitude() const
			{
				return math::sqrt( real*real + imaginary*imaginary );
			}
			
			
			
			
			/// Return the phase of this complex number.
			RIM_FORCE_INLINE T getPhase() const
			{
				return math::atan2( imaginary, real );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this complex number is equal to another.
			RIM_FORCE_INLINE Bool operator == ( const Complex& other ) const
			{
				return real == other.real && imaginary == other.imaginary;
			}
			
			
			
			
			/// Return whether or not this complex number is equal to a real number.
			RIM_FORCE_INLINE Bool operator == ( T value ) const
			{
				return real == value && imaginary == T(0);
			}
			
			
			
			
			/// Return whether or not this complex number is not equal to another.
			RIM_FORCE_INLINE Bool operator != ( const Complex& other ) const
			{
				return real != other.real || imaginary != other.imaginary;
			}
			
			
			
			
			/// Return whether or not this complex number is not equal to a real number.
			RIM_FORCE_INLINE Bool operator != ( T value ) const
			{
				return real != value || imaginary != T(0);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Negation/Positivation Operators
			
			
			
			
			/// Return the negation of this complex number.
			RIM_FORCE_INLINE Complex operator - () const
			{
				return Complex( -real, -imaginary );
			}
			
			
			
			
			/// Return the positivation of this complex number.
			RIM_FORCE_INLINE Complex operator + () const
			{
				return Complex( real, imaginary );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Operators
			
			
			
			
			/// Return the sum of this complex number with a real number.
			RIM_FORCE_INLINE Complex operator + ( T value ) const
			{
				return Complex( real + value, imaginary );
			}
			
			
			
			
			/// Return the difference between this complex number a real number.
			RIM_FORCE_INLINE Complex operator - ( T value ) const
			{
				return Complex( real - value, imaginary );
			}
			
			
			
			
			/// Multiply this complex number by real number and return the resulting complex number.
			RIM_FORCE_INLINE Complex operator * ( T value ) const
			{
				return Complex( real*value, imaginary*value );
			}
			
			
			
			
			/// Divide this complex number by another and return the resulting complex number.
			RIM_FORCE_INLINE Complex operator / ( T value ) const
			{
				T inverseValue = T(1)/value;
				
				return Complex( real*inverseValue, imaginary*inverseValue );
			}
			
			
			
			
			/// Return the sum of this complex number with another.
			RIM_FORCE_INLINE Complex operator + ( const Complex& other ) const
			{
				return Complex( real + other.real, imaginary + other.imaginary );
			}
			
			
			
			
			/// Return the difference between this complex number and other.
			RIM_FORCE_INLINE Complex operator - ( const Complex& other ) const
			{
				return Complex( real - other.real, imaginary - other.imaginary );
			}
			
			
			
			
			/// Multiply this complex number with another and return the resulting complex number.
			RIM_FORCE_INLINE Complex operator * ( const Complex& other ) const
			{
				return Complex( real*other.real - imaginary*other.imaginary,
								imaginary*other.real + real*other.imaginary );
			}
			
			
			
			
			/// Divide this complex number by another and return the resulting complex number.
			RIM_FORCE_INLINE Complex operator / ( const Complex& other ) const
			{
				T inverseDenominator = T(1)/(other.real*other.real + other.imaginary*other.imaginary);
				
				return Complex( (real*other.real - imaginary*other.imaginary)*inverseDenominator,
								(imaginary*other.real + real*other.imaginary)*inverseDenominator );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Assignment Operators
			
			
			
			
			/// Add a real number to this complex number, modifying it.
			RIM_FORCE_INLINE Complex& operator += ( T value )
			{
				real += value;
				
				return *this;
			}
			
			
			
			
			/// Subtract a real number from this complex number, modifying it.
			RIM_FORCE_INLINE Complex& operator -= ( T value )
			{
				real -= value;
				
				return *this;
			}
			
			
			
			
			/// Multiply a real number with this complex number, modifying it.
			RIM_FORCE_INLINE Complex& operator *= ( T value )
			{
				real *= value;
				imaginary *= value;
				
				return *this;
			}
			
			
			
			
			/// Divide this complex number by a real number, modifying it.
			RIM_FORCE_INLINE Complex& operator /= ( T value )
			{
				T inverseValue = T(1)/value;
				
				real *= inverseValue;
				imaginary *= inverseValue;
				
				return *this;
			}
			
			
			
			
			/// Add a complex number to this complex number, modifying it.
			RIM_FORCE_INLINE Complex& operator += ( const Complex& other )
			{
				real += other.real;
				imaginary += other.imaginary;
				
				return *this;
			}
			
			
			
			
			/// Subtract a complex number from this complex number, modifying it.
			RIM_FORCE_INLINE Complex& operator -= ( const Complex& other )
			{
				real -= other.real;
				imaginary -= other.imaginary;
				
				return *this;
			}
			
			
			
			
			/// Multiply a complex number with this complex number, modifying it.
			RIM_FORCE_INLINE Complex& operator *= ( const Complex& other )
			{
				T realTemp = real*other.real - imaginary*other.imaginary;
				imaginary = imaginary*other.real + real*other.imaginary;
				real = realTemp;
				
				return *this;
			}
			
			
			
			
			/// Divide this complex number by another complex number, modifying it.
			RIM_FORCE_INLINE Complex& operator /= ( const Complex& other )
			{
				T inverseDenominator = T(1)/(other.real*other.real + other.imaginary*other.imaginary);
				
				T realTemp = (real*other.real - imaginary*other.imaginary)*inverseDenominator;
				imaginary = (imaginary*other.real + real*other.imaginary)*inverseDenominator;
				real = realTemp;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Conversion Methods
			
			
			
			
			/// Convert this complex number into a human-readable string representation.
			RIM_NO_INLINE data::String toString() const
			{
				data::StringBuffer buffer;
				
				buffer << real;
				
				if ( imaginary < T(0) )
					buffer << " - " << math::abs(imaginary) << 'i';
				else if ( imaginary > T(0) )
					buffer << " + " << math::abs(imaginary) << 'i';
				
				return buffer.toString();
			}
			
			
			
			
			/// Convert this complex number into a human-readable string representation.
			RIM_FORCE_INLINE operator data::String () const
			{
				return this->toString();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The real portion of the complex number.
			union
			{
				T real;
				T r;
			};
			
			
			
			/// The imaginary portion of the complex number.
			union
			{
				T imaginary;
				T i;
			};
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Commutative Comparison Operators
//############		
//##########################################################################################
//##########################################################################################




/// Return whether or not a real number is equal to a complex number.
template < typename T >
RIM_FORCE_INLINE Bool operator == ( T value, const Complex<T>& complex )
{
	return complex == value;
}




/// Return whether or not a real number is not equal to a complex number.
template < typename T >
RIM_FORCE_INLINE Bool operator != ( T value, const Complex<T>& complex )
{
	return complex != value;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Commutative Arithmetic Operators
//############		
//##########################################################################################
//##########################################################################################




/// Add a complex number to a real number and return the resulting complex number.
template < typename T >
RIM_FORCE_INLINE Complex<T> operator + ( T value, const Complex<T>& complex )
{
	return Complex<T>( value + complex.real, complex.imaginary );
}




/// Subtract a complex number from a real number and return the resulting complex number.
template < typename T >
RIM_FORCE_INLINE Complex<T> operator - ( T value, const Complex<T>& complex )
{
	return Complex<T>( value - complex.real, -complex.imaginary );
}




/// Multiply a real number by a complex number and return the resulting complex number.
template < typename T >
RIM_FORCE_INLINE Complex<T> operator * ( T value, const Complex<T>& complex )
{
	return Complex<T>( value*complex.real, value*complex.imaginary );
}




/// Divide a real number by a complex number and return the resulting complex number.
template < typename T >
RIM_FORCE_INLINE Complex<T> operator / ( T value, const Complex<T>& complex )
{
	return Complex<T>( value ) / complex;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Other Complex Number Functions
//############		
//##########################################################################################
//##########################################################################################




/// Return the absolute value (magnitude) of the specified complex number.
template < typename T >
RIM_FORCE_INLINE T abs( const Complex<T>& complex )
{
	return math::sqrt( complex.real*complex.real + complex.imaginary*complex.imaginary );
}




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_COMPLEX_H
