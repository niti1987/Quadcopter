/*
 *  rimSIMDScalarDouble2.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 1/19/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SIMD_SCALAR_DOUBLE_2_H
#define INCLUDE_RIM_SIMD_SCALAR_DOUBLE_2_H


#include "rimMathConfig.h"


#include "rimSIMDScalar.h"
#include "rimSIMDScalarBool4.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class representing a 4-component 32-bit floating-point SIMD scalar.
/**
  * This specialization of the SIMDScalar class uses a 128-bit value to encode
  * 4 32-bit floating-point values. All basic arithmetic operations are supported,
  * plus a subset of standard scalar operations: abs(), min(), max(), sqrt().
  */
template <>
class RIM_ALIGN(16) SIMDScalar<Float64,2>
{
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Type Declarations
			
			
			
			
			/// Define the type for a 2x double scalar structure.
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
			typedef __m128d SIMDDouble2;
#endif
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructor
			
			
			
			
#if RIM_USE_SIMD && (defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0))
			/// Create a new 2D scalar with the specified 2D SIMD scalar value.
			RIM_FORCE_INLINE SIMDScalar( SIMDDouble2 simdScalar )
				:	v( simdScalar )
			{
			}
#endif
			
			
			
			
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new 2D SIMD scalar with all elements left uninitialized.
			RIM_FORCE_INLINE SIMDScalar()
			{
			}
			
			
			
			
			/// Create a new 2D SIMD scalar with all elements equal to the specified value.
			RIM_FORCE_INLINE SIMDScalar( Float64 value )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = _mm_set1_pd( value );
#else
				a = b = value;
#endif
			}
			
			
			
			
			/// Create a new 2D SIMD scalar with the elements equal to the specified 2 values.
			RIM_FORCE_INLINE SIMDScalar( Float64 newA, Float64 newB )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				// The parameters are reversed to keep things consistent with loading from an address.
				v = _mm_set_pd( newB, newA );
#else
				a = newA;
				b = newB;
#endif
			}
			
			
			
			
			/// Create a new 2D SIMD scalar from the first 4 values stored at specified pointer's location.
			RIM_FORCE_INLINE SIMDScalar( const Float64* array )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = _mm_load_pd( array );
#else
				a = array[0];
				b = array[1];
#endif
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Copy Constructor
			
			
			
			
			/// Create a new SIMD scalar with the same contents as another.
			/**
			  * This shouldn't have to be overloaded, but for some reason the compiler (GCC)
			  * optimizes SIMD code better with it overloaded. Before, the compiler would
			  * store the result of a SIMD operation on the stack before transfering it to
			  * the destination, resulting in an extra 8+ load/stores per computation.
			  */
			RIM_FORCE_INLINE SIMDScalar( const SIMDScalar& other )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = other.v;
#else
				a = other.a;
				b = other.b;
#endif
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of one SIMDScalar object to another.
			/**
			  * This shouldn't have to be overloaded, but for some reason the compiler (GCC)
			  * optimizes SIMD code better with it overloaded. Before, the compiler would
			  * store the result of a SIMD operation on the stack before transfering it to
			  * the destination, resulting in an extra 8+ load/stores per computation.
			  */
			RIM_FORCE_INLINE SIMDScalar& operator = ( const SIMDScalar& other )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = other.v;
#else
				a = other.a;
				b = other.b;
#endif
				return *this;
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Accessor Methods
			
			
			
			
			/// Get a reference to the value stored at the specified component index in this scalar.
			RIM_FORCE_INLINE Float64& operator [] ( Index i )
			{
				return x[i];
			}
			
			
			
			
			/// Get the value stored at the specified component index in this scalar.
			RIM_FORCE_INLINE Float64 operator [] ( Index i ) const
			{
				return x[i];
			}
			
			
			
			
			/// Get a pointer to the first element in this scalar.
			/**
			  * The remaining values are in the next 3 locations after the
			  * first element.
			  */
			RIM_FORCE_INLINE const Float64* toArray() const
			{
				return x;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Compare two 2D SIMD scalars component-wise for equality.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * If each corresponding pair of components is equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator == ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar<Bool,4>( _mm_cmpeq_pd( v, scalar.v ) );
#else
				return SIMDScalar<Bool,4>( a == scalar.a, b == scalar.b );
#endif
			}
			
			
			
			
			/// Compare this scalar to a single floating point value for equality.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components is equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator == ( const Float64 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar<Bool,4>( _mm_cmpeq_pd( v, _mm_set1_pd( value ) ) );
#else
				return SIMDScalar<Bool,4>( a == value, b == value );
#endif
			}
			
			
			
			
			
			/// Compare two 2D SIMD scalars component-wise for inequality
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * If each corresponding pair of components is not equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator != ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar<Bool,4>( _mm_cmpneq_pd( v, scalar.v ) );
#else
				return SIMDScalar<Bool,4>( a != scalar.a, b != scalar.b );
#endif
			}
			
			
			
			
			/// Compare this scalar to a single floating point value for inequality.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components is not equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator != ( const Float64 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar<Bool,4>( _mm_cmpneq_pd( v, _mm_set1_pd( value ) ) );
#else
				return SIMDScalar<Bool,4>( a != value, b != value );
#endif
			}
			
			
			
			
			/// Perform a component-wise less-than comparison between this and another 2D SIMD scalar.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component less than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator < ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar<Bool,4>( _mm_cmplt_pd( v, scalar.v ) );
#else
				return SIMDScalar<Bool,4>( a < scalar.a, b < scalar.b );
#endif
			}
			
			
			
			
			/// Perform a component-wise less-than comparison between this 2D SIMD scalar and an expanded scalar.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component less than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator < ( const Float64 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar<Bool,4>( _mm_cmplt_pd( v, _mm_set1_pd( value ) ) );
#else
				return SIMDScalar<Bool,4>( a < value, b < value );
#endif
			}
			
			
			
			
			/// Perform a component-wise greater-than comparison between this an another 2D SIMD scalar.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator > ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar<Bool,4>( _mm_cmpgt_pd( v, scalar.v ) );
#else
				return SIMDScalar<Bool,4>( a > scalar.a, b > scalar.b );
#endif
			}
			
			
			
			
			/// Perform a component-wise greater-than comparison between this 2D SIMD scalar and an expanded scalar.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator > ( const Float64 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar<Bool,4>( _mm_cmpgt_pd( v, _mm_set1_pd( value ) ) );
#else
				return SIMDScalar<Bool,4>( a > value, b > value );
#endif
			}
			
			
			
			
			/// Perform a component-wise less-than-or-equal-to comparison between this an another 2D SIMD scalar.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component less than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator <= ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar<Bool,4>( _mm_cmple_pd( v, scalar.v ) );
#else
				return SIMDScalar<Bool,4>( a <= scalar.a, b <= scalar.b );
#endif
			}
			
			
			
			
			/// Perform a component-wise less-than-or-equal-to comparison between this 2D SIMD scalar and an expanded scalar.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component less than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator <= ( const Float64 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar<Bool,4>( _mm_cmple_pd( v, _mm_set1_pd( value ) ) );
#else
				return SIMDScalar<Bool,4>( a <= value, b <= value );
#endif
			}
			
			
			
			
			
			/// Perform a component-wise greater-than-or-equal-to comparison between this an another 2D SIMD scalar.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator >= ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar<Bool,4>( _mm_cmpge_pd( v, scalar.v ) );
#else
				return SIMDScalar<Bool,4>( a >= scalar.a, b >= scalar.b );
#endif
			}
			
			
			
			
			/// Perform a component-wise greater-than-or-equal-to comparison between this 2D SIMD scalar and an expanded scalar.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator >= ( const Float64 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar<Bool,4>( _mm_cmpge_pd( v, _mm_set1_pd( value ) ) );
#else
				return SIMDScalar<Bool,4>( a >= value, b >= value );
#endif
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sum Method
			
			
			
			
			RIM_FORCE_INLINE Float64 sum() const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(3,0)
				return SIMDScalar( _mm_hadd_pd( v, v ) ).a;
#else
				return a + b;
#endif
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Store Method
			
			
			
			
			RIM_FORCE_INLINE void store( Float64* destination ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				_mm_store_pd( destination, v );
#else
				destination[0] = a;
				destination[1] = b;
#endif
			}
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Negation/Positivation Operators
			
			
			
			
			/// Negate a scalar.
			/** 
			  * This method negates every component of this 2D SIMD scalar
			  * and returns the result, leaving this scalar unmodified.
			  * 
			  * @return the negation of the original scalar.
			  */
			RIM_FORCE_INLINE SIMDScalar operator - () const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_sub_pd( _mm_set1_pd(Float64(0)), v ) );
#else
				return SIMDScalar( -a, -b );
#endif
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Operators
			
			
			
			
			
			/// Add this scalar to another and return the result.
			/** 
			  * This method adds another scalar to this one, component-wise,
			  * and returns this addition. It does not modify either of the original
			  * scalars.
			  * 
			  * @param scalar - The scalar to add to this one.
			  * @return The addition of this scalar and the parameter.
			  */
			RIM_FORCE_INLINE SIMDScalar operator + ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_add_pd( v, scalar.v ) );
#else
				return SIMDScalar( a + scalar.a, b + scalar.b );
#endif
			}
			
			
			
			
			/// Add a value to every component of this scalar.
			/** 
			  * This method adds the value parameter to every component
			  * of the scalar, and returns a scalar representing this result.
			  * It does not modifiy the original scalar.
			  * 
			  * @param value - The value to add to all components of this scalar.
			  * @return The resulting scalar of this addition.
			  */
			RIM_FORCE_INLINE SIMDScalar operator + ( const Float64 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_add_pd( v, _mm_set1_pd(value) ) );
#else
				return SIMDScalar( a + value, b + value );
#endif
			}
			
			
			
			
			/// Subtract a scalar from this scalar component-wise and return the result.
			/** 
			  * This method subtracts another scalar from this one, component-wise,
			  * and returns this subtraction. It does not modify either of the original
			  * scalars.
			  * 
			  * @param scalar - The scalar to subtract from this one.
			  * @return The subtraction of the the parameter from this scalar.
			  */
			RIM_FORCE_INLINE SIMDScalar operator - ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_sub_pd( v, scalar.v ) );
#else
				return SIMDScalar( a - scalar.a, b - scalar.b );
#endif
			}
			
			
			
			
			/// Subtract a value from every component of this scalar.
			/** 
			  * This method subtracts the value parameter from every component
			  * of the scalar, and returns a scalar representing this result.
			  * It does not modifiy the original scalar.
			  * 
			  * @param value - The value to subtract from all components of this scalar.
			  * @return The resulting scalar of this subtraction.
			  */
			RIM_FORCE_INLINE SIMDScalar operator - ( const Float64 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_sub_pd( v, _mm_set1_pd(value) ) );
#else
				return SIMDScalar( a - value, b - value );
#endif
			}
			
			
			
			
			/// Multiply component-wise this scalar and another scalar.
			/** 
			  * This operator multiplies each component of this scalar
			  * by the corresponding component of the other scalar and
			  * returns a scalar representing this result. It does not modify
			  * either original scalar.
			  * 
			  * @param scalar - The scalar to multiply this scalar by.
			  * @return The result of the multiplication.
			  */
			RIM_FORCE_INLINE SIMDScalar operator * ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_mul_pd( v, scalar.v ) );
#else
				return SIMDScalar( a*scalar.a, b*scalar.b );
#endif
			}
			
			
			
			
			/// Multiply every component of this scalar by a value and return the result.
			/** 
			  * This method multiplies the value parameter with every component
			  * of the scalar, and returns a scalar representing this result.
			  * It does not modifiy the original scalar.
			  * 
			  * @param value - The value to multiplly with all components of this scalar.
			  * @return The resulting scalar of this multiplication.
			  */
			RIM_FORCE_INLINE SIMDScalar operator * ( const Float64 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_mul_pd( v, _mm_set1_pd(value) ) );
#else
				return SIMDScalar( a*value, b*value );
#endif
			}
			
			
			
			
			/// Divide this scalar by another scalar component-wise.
			/** 
			  * This operator divides each component of this scalar
			  * by the corresponding component of the other scalar and
			  * returns a scalar representing this result. It does not modify
			  * either original scalar.
			  * 
			  * @param scalar - The scalar to multiply this scalar by.
			  * @return The result of the division.
			  */
			RIM_FORCE_INLINE SIMDScalar operator / ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_div_pd( v, scalar.v ) );
#else
				return SIMDScalar( a/scalar.a, b/scalar.b );
#endif
			}
			
			
			
			
			/// Divide every component of this scalar by a value and return the result.
			/** 
			  * This method Divides every component of the scalar by the value parameter, 
			  * and returns a scalar representing this result.
			  * It does not modifiy the original scalar.
			  * 
			  * @param value - The value to divide all components of this scalar by.
			  * @return The resulting scalar of this division.
			  */
			RIM_FORCE_INLINE SIMDScalar operator / ( const Float64 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_mul_pd( v, _mm_set1_pd(Float64(1) / value) ) );
#else
				Float64 inverse = Float64(1) / value;
				return SIMDScalar( a*inverse, b*inverse );
#endif
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Assignment Operators
			
			
			
			
			/// Add a scalar to this scalar, modifying this original scalar.
			/**
			  * This method adds another scalar to this scalar, component-wise,
			  * and sets this scalar to have the result of this addition.
			  * 
			  * @param scalar - The scalar to add to this scalar.
			  * @return A reference to this modified scalar.
			  */
			RIM_FORCE_INLINE SIMDScalar& operator += ( const SIMDScalar& scalar )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = _mm_add_pd( v, scalar.v );
#else
				a += scalar.a;
				b += scalar.b;
#endif
				return *this;
			}
			
			
			
			/// Subtract a scalar from this scalar, modifying this original scalar.
			/**
			  * This method subtracts another scalar from this scalar, component-wise,
			  * and sets this scalar to have the result of this subtraction.
			  * 
			  * @param scalar - The scalar to subtract from this scalar.
			  * @return A reference to this modified scalar.
			  */
			RIM_FORCE_INLINE SIMDScalar& operator -= ( const SIMDScalar& scalar )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = _mm_sub_pd( v, scalar.v );
#else
				a -= scalar.a;
				b -= scalar.b;
#endif
				return *this;
			}
			
			
			
			
			/// Multiply component-wise this scalar and another scalar and modify this scalar.
			/** 
			  * This operator multiplies each component of this scalar
			  * by the corresponding component of the other scalar and
			  * modifies this scalar to contain the result.
			  * 
			  * @param scalar - The scalar to multiply this scalar by.
			  * @return A reference to this modified scalar.
			  */
			RIM_FORCE_INLINE SIMDScalar& operator *= ( const SIMDScalar& scalar )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = _mm_mul_pd( v, scalar.v );
#else
				a *= scalar.a;
				b *= scalar.b;
#endif
				return *this;
			}
			
			
			
			
			/// Divide this scalar by another scalar component-wise and modify this scalar.
			/** 
			  * This operator divides each component of this scalar
			  * by the corresponding component of the other scalar and
			  * modifies this scalar to contain the result.
			  * 
			  * @param scalar - The scalar to divide this scalar by.
			  * @return A reference to this modified scalar.
			  */
			RIM_FORCE_INLINE SIMDScalar& operator /= ( const SIMDScalar& scalar )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = _mm_div_pd( v, scalar.v );
#else
				a /= scalar.a;
				b /= scalar.b;
#endif
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Required Alignment Accessor Methods
			
			
			
			
			/// Return the alignment required for objects of this type.
			/**
			  * For most SIMD types this value will be 16 bytes. If there is
			  * no alignment required, 0 is returned.
			  */
			RIM_FORCE_INLINE static Size getRequiredAlignment()
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return 16;
#else
				return 0;
#endif
			}
			
			
			
			
			/// Get the width of this scalar (number of components it has).
			RIM_FORCE_INLINE static Size getWidth()
			{
				return 2;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			RIM_ALIGN(16) union
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				/// The 2D SIMD vector used internally.
				SIMDDouble2 v;
#endif
				
				struct
				{
					/// The A component of a 2D SIMD scalar.
					Float64 a;
					
					
					
					/// The B component of a 2D SIMD scalar.
					Float64 b;
				};
				
				
				/// The components of a 2D SIMD scalar in array format.
				Float64 x[2];
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Declarations
			
			
			
			
			template < typename T, Size width >
			friend class SIMDVector3D;
			
			
			
			friend RIM_FORCE_INLINE SIMDScalar abs( const SIMDScalar& scalar );
			friend RIM_FORCE_INLINE SIMDScalar ceiling( const SIMDScalar& scalar );
			friend RIM_FORCE_INLINE SIMDScalar floor( const SIMDScalar& scalar );
			friend RIM_FORCE_INLINE SIMDScalar sqrt( const SIMDScalar& scalar );
			friend RIM_FORCE_INLINE SIMDScalar min( const SIMDScalar& scalar1, const SIMDScalar& scalar2 );
			friend RIM_FORCE_INLINE SIMDScalar max( const SIMDScalar& scalar1, const SIMDScalar& scalar2 );
			
			template < UInt i1, UInt i2 >
			friend RIM_FORCE_INLINE SIMDScalar shuffle( const SIMDScalar& scalar1 );
			
			template < UInt i1, UInt i2 >
			friend RIM_FORCE_INLINE SIMDScalar shuffle( const SIMDScalar& scalar1, const SIMDScalar& scalar2 );
			
			friend RIM_FORCE_INLINE SIMDScalar select( const SIMDScalar<Bool,4>& selector,
														const SIMDScalar& scalar1, const SIMDScalar& scalar2 );
			
			friend RIM_FORCE_INLINE SIMDScalar subAdd( const SIMDScalar& scalar1, const SIMDScalar& scalar2 );
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Associative SIMD Scalar Operators
//############		
//##########################################################################################
//##########################################################################################




/// Add a scalar value to each component of this scalar and return the resulting scalar.
RIM_FORCE_INLINE SIMDScalar<Float64,2> operator + ( const Float64 value, const SIMDScalar<Float64,2>& scalar )
{
	return SIMDScalar<Float64,2>(value) + scalar;
}




/// Subtract a scalar value from each component of this scalar and return the resulting scalar.
RIM_FORCE_INLINE SIMDScalar<Float64,2> operator - ( const Float64 value, const SIMDScalar<Float64,2>& scalar )
{
	return SIMDScalar<Float64,2>(value) - scalar;
}




/// Multiply a scalar value by each component of this scalar and return the resulting scalar.
RIM_FORCE_INLINE SIMDScalar<Float64,2> operator * ( const Float64 value, const SIMDScalar<Float64,2>& scalar )
{
	return SIMDScalar<Float64,2>(value) * scalar;
}




/// Divide each component of this scalar by a scalar value and return the resulting scalar.
RIM_FORCE_INLINE SIMDScalar<Float64,2> operator / ( const Float64 value, const SIMDScalar<Float64,2>& scalar )
{
	return SIMDScalar<Float64,2>(value) / scalar;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Free Vector Functions
//############		
//##########################################################################################
//##########################################################################################




/// Compute the absolute value of each component of the specified SIMD scalar and return the result.
RIM_FORCE_INLINE SIMDScalar<Float64,2> abs( const SIMDScalar<Float64,2>& scalar )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
	RIM_ALIGN(16) const UInt64 absMask[2] = { UInt64(0x7FFFFFFFFFFFFFFFull), UInt64(0x7FFFFFFFFFFFFFFFull) };
	return SIMDScalar<Float64,2>( _mm_and_pd( scalar.v, _mm_load_pd( reinterpret_cast<const Float64*>(absMask) ) ) );
#else
	return SIMDScalar<Float64,2>( math::abs(scalar.a), math::abs(scalar.b) );
#endif
}




/// Compute the ceiling of each component of the specified SIMD scalar and return the result.
/**
  * This method is emulated in software on x86 platforms where SSE 4.1 is not available.
  */
RIM_FORCE_INLINE SIMDScalar<Float64,2> ceiling( const SIMDScalar<Float64,2>& scalar )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(4,1)
	return SIMDScalar<Float64,2>( _mm_ceil_pd( scalar.v ) );
#else
	return SIMDScalar<Float64,2>( math::ceiling(scalar.a), math::ceiling(scalar.b) );
#endif
}




/// Compute the floor of each component of the specified SIMD scalar and return the result.
/**
  * This method is emulated in software on x86 platforms where SSE 4.1 is not available.
  */
RIM_FORCE_INLINE SIMDScalar<Float64,2> floor( const SIMDScalar<Float64,2>& scalar )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(4,1)
	return SIMDScalar<Float64,2>( _mm_floor_pd( scalar.v ) );
#else
	return SIMDScalar<Float64,2>( math::floor(scalar.a), math::floor(scalar.b) );
#endif
}




/// Compute the square root of each component of the specified SIMD scalar and return the result.
RIM_FORCE_INLINE SIMDScalar<Float64,2> sqrt( const SIMDScalar<Float64,2>& scalar )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
	return SIMDScalar<Float64,2>( _mm_sqrt_pd( scalar.v ) );
#else
	return SIMDScalar<Float64,2>( math::sqrt(scalar.a), math::sqrt(scalar.b) );
#endif
}




/// Compute the minimum of each component of the specified SIMD scalars and return the result.
RIM_FORCE_INLINE SIMDScalar<Float64,2> min( const SIMDScalar<Float64,2>& scalar1, const SIMDScalar<Float64,2>& scalar2 )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
	return SIMDScalar<Float64,2>( _mm_min_pd( scalar1.v, scalar2.v ) );
#else
	return SIMDScalar<Float64,2>( math::min(scalar1.a, scalar2.a),
								math::min(scalar1.b, scalar2.b) );
#endif
}




/// Compute the maximum of each component of the specified SIMD scalars and return the result.
RIM_FORCE_INLINE SIMDScalar<Float64,2> max( const SIMDScalar<Float64,2>& scalar1, const SIMDScalar<Float64,2>& scalar2 )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
	return SIMDScalar<Float64,2>( _mm_max_pd( scalar1.v, scalar2.v ) );
#else
	return SIMDScalar<Float64,2>( math::max(scalar1.a, scalar2.a),
								math::max(scalar1.b, scalar2.b) );
#endif
}




/// Pick 2 elements from the specified SIMD scalar and return the result.
template < UInt i1, UInt i2 >
RIM_FORCE_INLINE SIMDScalar<Float64,2> shuffle( const SIMDScalar<Float64,2>& scalar )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
	return SIMDScalar<Float64,2>( _mm_shuffle_pd( scalar.v, scalar.v, _MM_SHUFFLE2(i2, i1) ) );
#else
	return SIMDScalar<Float64,2>( scalar[i1], scalar[i2] );
#endif
}




/// Pick one element from each SIMD scalar and return the result.
template < UInt i1, UInt i2 >
RIM_FORCE_INLINE SIMDScalar<Float64,2> shuffle( const SIMDScalar<Float64,2>& scalar1, const SIMDScalar<Float64,2>& scalar2 )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
	return SIMDScalar<Float64,2>( _mm_shuffle_ps( scalar1.v, scalar2.v, _MM_SHUFFLE2(i2, i1) ) );
#else
	return SIMDScalar<Float64,2>( scalar1[i1], scalar1[i2] );
#endif
}




/// Select elements from the first SIMD scalar if the selector is TRUE, otherwise from the second.
RIM_FORCE_INLINE SIMDScalar<Float64,2> select( const SIMDScalar<Bool,4>& selector,
												const SIMDScalar<Float64,2>& scalar1, const SIMDScalar<Float64,2>& scalar2 )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
	// (((b^a) & selector) ^ a)
	return SIMDScalar<Float64,2>( _mm_xor_pd( scalar2.v, _mm_and_pd( selector.vDouble, _mm_xor_pd( scalar1.v, scalar2.v ) ) ) );
#else
	return SIMDScalar<Float64,2>( selector.a ? scalar1.a : scalar2.a,
								selector.b ? scalar1.b : scalar2.b );
#endif
}




/// Subtract the first and third elements and add the second and fourth.
RIM_FORCE_INLINE SIMDScalar<Float64,2> subAdd( const SIMDScalar<Float64,2>& scalar1, const SIMDScalar<Float64,2>& scalar2 )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(3,0)
	return SIMDScalar<Float64,2>( _mm_addsub_pd( scalar1.v, scalar2.v ) );
#else
	return SIMDScalar<Float64,2>( scalar1.a - scalar2.a, scalar1.b + scalar2.b );
#endif
}




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SIMD_SCALAR_DOUBLE_2_H
