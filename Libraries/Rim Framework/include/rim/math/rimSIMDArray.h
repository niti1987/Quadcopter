/*
 *  rimSIMDArray.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 1/19/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SIMD_ARRAY_H
#define INCLUDE_RIM_SIMD_ARRAY_H


#include "rimMathConfig.h"


#include "rimScalarMath.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// The prototype for the SIMDArray class for wide SIMD operations.
/**
  * This class emulates aribitrary-width SIMD registers using an array of SIMD
  * values which are all processed in a vector fashion similar to normal SIMD values.
  * 
  * This template prototype is a scalar implementation of basic SIMD functionality.
  * Supported operations include all basic arithmetic operations
  * (+, -, *, /, +=, -=, *=, /=) and functions that operate on SIMDArray instances
  * to find the per-component result for abs(), min(), max(), and sqrt() operations.
  *
  * This implementation is provided as a fallback for when SIMD instructions are not
  * available and for completeness. On any given platform, specializations for this 
  * class/functions should be implemented which use real SIMD operations.
  */
template < typename T, Size width >
class SIMDArray
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			/// Create a scalar with it's elements equal to zero
			RIM_FORCE_INLINE SIMDArray()
			{
				for ( Index i = 0; i < width; i++ )
					x[i] = T(0);
			}
			
			
			
			
			/// Create a scalar with it's elements equal to zero
			RIM_FORCE_INLINE SIMDArray( T value )
			{
				for ( Index i = 0; i < width; i++ )
					x[i] = value;
			}
			
			
			
			
			/// Create a scalar with elements from the specified array.
			/**
			  * The array must be of length greater than or equal to the
			  * width of the scalar.
			  */
			RIM_FORCE_INLINE SIMDArray( const T* array )
			{
				for ( Index i = 0; i < width; i++ )
					x[i] = array[i];
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Accessor Methods
			
			
			
			
			/// Return an array representation of this scalar.
			RIM_FORCE_INLINE const T* toArray() const
			{
				return x;
			}
			
			
			
			
			/// Get the element at the specified index in the scalar.
			RIM_FORCE_INLINE T& get( Index i )
			{
				return x[i];
			}
			
			
			
			
			/// Get the element at the specified index in the scalar.
			RIM_FORCE_INLINE const T& get( Index i ) const
			{
				return x[i];
			}
			
			
			
			
			/// Get the element at the specified index in the scalar.
			RIM_FORCE_INLINE T& operator () ( Index i )
			{
				return x[i];
			}
			
			
			
			
			/// Get the element at the specified index in the scalar.
			RIM_FORCE_INLINE const T& operator () ( Index i ) const
			{
				return x[i];
			}
			
			
			
			
			/// Get the element at the specified index in the scalar.
			RIM_FORCE_INLINE T& operator [] ( Index i )
			{
				return x[i];
			}
			
			
			
			
			/// Get the element at the specified index in the scalar.
			RIM_FORCE_INLINE const T& operator [] ( Index i ) const
			{
				return x[i];
			}
			
			
			
			
			/// Set the element at the specified index in the scalar.
			RIM_FORCE_INLINE void set( Index i, T newX )
			{
				x[i] = newX;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sum Method
			
			
			
			
			/// Return the horizontal sum of all components of this SIMD scalar.
			RIM_FORCE_INLINE T sum() const
			{
				T total = T(0);
				
				for ( Index i = 0; i < width; i++ )
					total += x[i];
				
				return total;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Negation/Positivation Operators
			
			
			
			
			/// Negate every component of this scalar and return the result.
			RIM_FORCE_INLINE SIMDArray operator - () const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < width; i++ )
					result.x[i] = -x[i];
				
				return result;
			}
			
			
			
			
			/// 'Positivate' every component of this scalar, effectively returning a copy.
			RIM_FORCE_INLINE SIMDArray operator + () const
			{
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Operators
			
			
			
			
			/// Add a scalar to this scalar and return the resulting scalar.
			RIM_FORCE_INLINE SIMDArray operator + ( const SIMDArray& scalar ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < width; i++ )
					result.x[i] = x[i] + scalar.x[i];
				
				return result;
			}
			
			
			
			
			/// Add a scalar value to each component of this scalar and return the resulting scalar.
			RIM_FORCE_INLINE SIMDArray operator + ( const T& value ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < width; i++ )
					result.x[i] = x[i] + value;
				
				return result;
			}
			
			
			
			
			/// Subtract a scalar from this scalar and return the resulting scalar.
			RIM_FORCE_INLINE SIMDArray operator - ( const SIMDArray& scalar ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < width; i++ )
					result.x[i] = x[i] - scalar.x[i];
				
				return result;
			}
			
			
			
			
			/// Subtract a scalar value from each component of this scalar and return the resulting scalar.
			RIM_FORCE_INLINE SIMDArray operator - ( const T& value ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < width; i++ )
					result.x[i] = x[i] - value;
				
				return result;
			}
			
			
			
			
			/// Return the result of a component-wise scalar multiplication with this scalar.
			RIM_FORCE_INLINE SIMDArray operator * ( const SIMDArray& scalar ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < width; i++ )
					result.x[i] = x[i]*scalar.x[i];
				
				return result;
			}
			
			
			
			
			/// Multiply a scalar value by each component of this scalar and return the resulting scalar.
			RIM_FORCE_INLINE SIMDArray operator * ( const T& value ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < width; i++ )
					result.x[i] = x[i]*value;
				
				return result;
			}
			
			
			
			
			/// Divide each component of this scalar by a scalar value and return the resulting scalar.
			RIM_FORCE_INLINE SIMDArray operator / ( const T& value ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < width; i++ )
					result.x[i] = x[i] / value;
				
				return result;
			}
			
			
			
			
			/// Divide each component of this scalar by a scalar component and return the resulting scalar.
			RIM_FORCE_INLINE SIMDArray operator / ( const SIMDArray& scalar ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < width; i++ )
					result.x[i] = x[i] / scalar.x[i];
				
				return result;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Assignment Operators
			
			
			
			
			RIM_FORCE_INLINE SIMDArray& operator += ( const SIMDArray& v2 )
			{
				for ( Index i = 0; i < width; i++ )
					x[i] += v2.x[i];
				
				return *this;
			}
			
			
			
			
			RIM_FORCE_INLINE SIMDArray& operator += ( const T& value )
			{
				for ( Index i = 0; i < width; i++ )
					x[i] += value;
				
				return *this;
			}
			
			
			
			
			RIM_FORCE_INLINE SIMDArray& operator -= ( const SIMDArray& v2 )
			{
				for ( Index i = 0; i < width; i++ )
					x[i] -= v2.x[i];
				
				return *this;
			}
			
			
			
			
			RIM_FORCE_INLINE SIMDArray& operator -= ( const T& value )
			{
				for ( Index i = 0; i < width; i++ )
					x[i] -= value;
				
				return *this;
			}
			
			
			
			
			RIM_FORCE_INLINE SIMDArray& operator *= ( const SIMDArray& scalar )
			{
				for ( Index i = 0; i < width; i++ )
					x[i] *= scalar.x[i];
				
				return *this;
			}
			
			
			
			
			RIM_FORCE_INLINE SIMDArray& operator *= ( const T& value )
			{
				for ( Index i = 0; i < width; i++ )
					x[i] *= value;
				
				return *this;
			}
			
			
			
			
			RIM_FORCE_INLINE SIMDArray& operator /= ( const SIMDArray& scalar )
			{
				for ( Index i = 0; i < width; i++ )
					x[i] /= scalar.x[i];
				
				return *this;
			}
			
			
			
			
			RIM_FORCE_INLINE SIMDArray& operator /= ( const T& value )
			{
				for ( Index i = 0; i < width; i++ )
					x[i] /= value;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Required Alignment Accessor Methods
			
			
			
			
			/// Return the alignment required in bytes for objects of this type.
			/**
			  * For most SIMD types this value will be 16 bytes. If there is
			  * no alignment required, 0 is returned.
			  */
			RIM_FORCE_INLINE static Size getRequiredAlignment()
			{
				return 0;
			}
			
			
			
			
			/// Get the width of this scalar (number of components it has).
			RIM_FORCE_INLINE static Size getWidth()
			{
				return width;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The components of this SIMD scalar.
			T x[width];
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Function Declarations
			
			
			
			
			template < typename U, Size dim >
			friend SIMDArray<U,dim> operator + ( const U& value, const SIMDArray<T,dim>& scalar );
			
			template < typename U, Size dim >
			friend SIMDArray<U,dim> operator - ( const U& value, const SIMDArray<T,dim>& scalar );
			
			template < typename U, Size dim >
			friend SIMDArray<U,dim> operator * ( const U& value, const SIMDArray<T,dim>& scalar );
			
			template < typename U, Size dim >
			friend SIMDArray<U,dim> operator / ( const U& value, const SIMDArray<T,dim>& scalar );
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Associative SIMD Scalar Operators
//############		
//##########################################################################################
//##########################################################################################




/// Add a scalar value to each component of this scalar and return the resulting scalar.
template < typename T, Size width >
RIM_FORCE_INLINE SIMDArray<T,width> operator + ( const T& value, const SIMDArray<T,width>& scalar )
{
	SIMDArray<T,width> result;
	
	for ( Index i = 0; i < width; i++ )
		result.x[i] = value + scalar.x[i];
	
	return result;
}




/// Subtract a scalar value from each component of this scalar and return the resulting scalar.
template < typename T, Size width >
RIM_FORCE_INLINE SIMDArray<T,width> operator - ( const T& value, const SIMDArray<T,width>& scalar )
{
	SIMDArray<T,width> result;
	
	for ( Index i = 0; i < width; i++ )
		result.x[i] = value - scalar.x[i];
	
	return result;
}




/// Multiply a scalar value by each component of this scalar and return the resulting scalar.
template < typename T, Size width >
RIM_FORCE_INLINE SIMDArray<T,width> operator * ( const T& value, const SIMDArray<T,width>& scalar )
{
	SIMDArray<T,width> result;
	
	for ( Index i = 0; i < width; i++ )
		result.x[i] = value*scalar.x[i];
	
	return result;
}




/// Divide each component of this scalar by a scalar value and return the resulting scalar.
template < typename T, Size width >
RIM_FORCE_INLINE SIMDArray<T,width> operator / ( const T& value, const SIMDArray<T,width>& scalar )
{
	SIMDArray<T,width> result;
	
	for ( Index i = 0; i < width; i++ )
		result.x[i] = value / scalar.x[i];
	
	return result;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Free Vector Functions
//############		
//##########################################################################################
//##########################################################################################




/// Compute the absolute value of each component of the specified SIMD scalar and return the result.
template < typename T, Size width >
RIM_FORCE_INLINE SIMDArray<T,width> abs( const SIMDArray<T,width>& scalar )
{
	SIMDArray<T,width> result;
	
	for ( Index i = 0; i < width; i++ )
		result.x[i] = math::abs(scalar.x[i]);
	
	return result;
}




/// Compute the square root of each component of the specified SIMD scalar and return the result.
template < typename T, Size width >
RIM_FORCE_INLINE SIMDArray<T,width> sqrt( const SIMDArray<T,width>& scalar )
{
	SIMDArray<T,width> result;
	
	for ( Index i = 0; i < width; i++ )
		result.x[i] = math::sqrt(scalar.x[i]);
	
	return result;
}




/// Compute the minimum of each component of the specified SIMD scalars and return the result.
template < typename T, Size width >
RIM_FORCE_INLINE SIMDArray<T,width> min( const SIMDArray<T,width>& scalar1, const SIMDArray<T,width>& scalar2 )
{
	SIMDArray<T,width> result;
	
	for ( Index i = 0; i < width; i++ )
		result.x[i] = math::min( scalar1.x[i], scalar2.x[i] );
	
	return result;
}




/// Compute the maximum of each component of the specified SIMD scalars and return the result.
template < typename T, Size width >
RIM_FORCE_INLINE SIMDArray<T,width> max( const SIMDArray<T,width>& scalar1, const SIMDArray<T,width>& scalar2 )
{
	SIMDArray<T,width> result;
	
	for ( Index i = 0; i < width; i++ )
		result.x[i] = math::max( scalar1.x[i], scalar2.x[i] );
	
	return result;
}



//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SIMD_ARRAY_H
