/*
 *  rimSIMDScalarInt64_2.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 9/21/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SIMD_SCALAR_INT_64_2_H
#define INCLUDE_RIM_SIMD_SCALAR_INT_64_2_H


#include "rimMathConfig.h"


#include "rimSIMDScalar.h"


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
class RIM_ALIGN(16) SIMDScalar<Int64,2>
{
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Type Declarations
			
			
			
			
			/// Define the type for a 2x double scalar structure.
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
			typedef __m128d SIMDDouble;
			typedef __m128i SIMDInt64;
#endif
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructor
			
			
			
			
#if RIM_USE_SIMD && (defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0))
			/// Create a new 2D scalar with the specified 2D SIMD scalar value.
			RIM_FORCE_INLINE SIMDScalar( SIMDInt64 simdScalar )
				:	v( simdScalar )
			{
			}
			
			/// Create a new 2D scalar with the specified 2D SIMD scalar value.
			RIM_FORCE_INLINE SIMDScalar( SIMDDouble simdScalar )
				:	vDouble( simdScalar )
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
			RIM_FORCE_INLINE SIMDScalar( Int64 value )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
#if defined(RIM_PLATFORM_64_BIT)
				v = _mm_set1_epi64x( value );
#else
				a = b = value;
#endif
#else
				a = b = value;
#endif
			}
			
			
			
			
			/// Create a new 2D SIMD scalar with the elements equal to the specified 2 values.
			RIM_FORCE_INLINE SIMDScalar( Int64 newA, Int64 newB )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				// The parameters are reversed to keep things consistent with loading from an address.
#if defined(RIM_PLATFORM_64_BIT)
				v = _mm_set_epi64x( newB, newA );
#else
				a = newA;
				b = newB;
#endif
#else
				a = newA;
				b = newB;
#endif
			}
			
			
			
			
			/// Create a new 2D SIMD scalar from the first 4 values stored at specified pointer's location.
			RIM_FORCE_INLINE SIMDScalar( const Int64* array )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = _mm_load_si128( (const SIMDInt64*)array );
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
		//******	Load Methods
			
			
			
			
			RIM_FORCE_INLINE static SIMDScalar load( const Int64* array )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_load_pd( (const Float64*)array ) );
#else
				return SIMDScalar( array[0], array[1], array[2], array[3] );
#endif
			}
			
			
			
			
			RIM_FORCE_INLINE static SIMDScalar loadUnaligned( const Int64* array )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_loadu_pd( (const Float64*)array ) );
#else
				return SIMDScalar( array[0], array[1] );
#endif
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Store Methods
			
			
			
			
			RIM_FORCE_INLINE void store( Int64* destination ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				_mm_store_pd( (Float64*)destination, vDouble );
#else
				destination[0] = a;
				destination[1] = b;
#endif
			}
			
			
			
			
			RIM_FORCE_INLINE void storeUnaligned( Int64* destination ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				_mm_storeu_pd( (Float64*)destination, vDouble );
#else
				destination[0] = a;
				destination[1] = b;
#endif
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Accessor Methods
			
			
			
			
			/// Get a reference to the value stored at the specified component index in this scalar.
			RIM_FORCE_INLINE Int64& operator [] ( Index i )
			{
				return x[i];
			}
			
			
			
			
			/// Get the value stored at the specified component index in this scalar.
			RIM_FORCE_INLINE Int64 operator [] ( Index i ) const
			{
				return x[i];
			}
			
			
			
			
			/// Get a pointer to the first element in this scalar.
			/**
			  * The remaining values are in the next 3 locations after the
			  * first element.
			  */
			RIM_FORCE_INLINE const Int64* toArray() const
			{
				return x;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Logical Operators
			
			
			
			
			/// Return the bitwise NOT of this 4D SIMD vector.
			RIM_FORCE_INLINE SIMDScalar operator ~ () const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_xor_si128( v, _mm_set1_epi32( 0xFFFFFFFF ) ) );
#else
				return SIMDScalar( ~a, ~b );
#endif
			}
			
			
			
			
			/// Compute the bitwise AND of this 4D SIMD vector with another and return the result.
			RIM_FORCE_INLINE SIMDScalar operator & ( const SIMDScalar& vector ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_and_si128( v, vector.v ) );
#else
				return SIMDScalar( a & vector.a, b & vector.b );
#endif
			}
			
			
			
			
			/// Compute the bitwise OR of this 4D SIMD vector with another and return the result.
			RIM_FORCE_INLINE SIMDScalar operator | ( const SIMDScalar& vector ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_or_si128( v, vector.v ) );
#else
				return SIMDScalar( a | vector.a, b | vector.b );
#endif
			}
			
			
			
			
			/// Compute the bitwise XOR of this 4D SIMD vector with another and return the result.
			RIM_FORCE_INLINE SIMDScalar operator ^ ( const SIMDScalar& vector ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_xor_si128( v, vector.v ) );
#else
				return SIMDScalar( a ^ vector.a, b ^ vector.b );
#endif
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Logical Assignment Operators
			
			
			
			
			/// Compute the logical AND of this 4D SIMD vector with another and assign it to this vector.
			RIM_FORCE_INLINE SIMDScalar& operator &= ( const SIMDScalar& vector )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = _mm_and_si128( v, vector.v );
#else
				a &= vector.a;
				b &= vector.b;
#endif
				return *this;
			}
			
			
			
			
			/// Compute the logical OR of this 4D SIMD vector with another and assign it to this vector.
			RIM_FORCE_INLINE SIMDScalar& operator |= ( const SIMDScalar& vector )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = _mm_or_si128( v, vector.v );
#else
				a |= vector.a;
				b |= vector.b;
#endif
				return *this;
			}
			
			
			
			
			/// Compute the bitwise XOR of this 4D SIMD vector with another and assign it to this vector.
			RIM_FORCE_INLINE SIMDScalar& operator ^= ( const SIMDScalar& vector )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = _mm_xor_si128( v, vector.v );
#else
				a ^= vector.a;
				b ^= vector.b;
#endif
				return *this;
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
			RIM_FORCE_INLINE SIMDScalar operator == ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_cmpeq_pd( vDouble, scalar.vDouble ) );
#else
				return SIMDScalar( a == scalar.a, b == scalar.b );
#endif
			}
			
			
			
			
			/// Compare this scalar to a single floating point value for equality.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components is equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator == ( const Int64 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_cmpeq_pd( vDouble, _mm_set1_pd( *(const Float64*)&value ) ) );
#else
				return SIMDScalar( a == value, b == value );
#endif
			}
			
			
			
			
			
			/// Compare two 2D SIMD scalars component-wise for inequality
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * If each corresponding pair of components is not equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator != ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_cmpneq_pd( vDouble, scalar.vDouble ) );
#else
				return SIMDScalar( a != scalar.a, b != scalar.b );
#endif
			}
			
			
			
			
			/// Compare this scalar to a single floating point value for inequality.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components is not equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator != ( const Int64 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_cmpneq_pd( vDouble, _mm_set1_pd( *(const Float64*)&value ) ) );
#else
				return SIMDScalar( a != value, b != value );
#endif
			}
			
			
			
			
			/// Perform a component-wise less-than comparison between this and another 2D SIMD scalar.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component less than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator < ( const SIMDScalar& scalar ) const
			{/*
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_cmplt_epi64( v, scalar.v ) );
#else*/
				return SIMDScalar( a < scalar.a, b < scalar.b );
//#endif
			}
			
			
			
			
			/// Perform a component-wise less-than comparison between this 2D SIMD scalar and an expanded scalar.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component less than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator < ( const Int64 value ) const
			{/*
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_cmplt_epi64( v, _mm_set1_epi64( __m64(value) ) ) );
#else*/
				return SIMDScalar( a < value, b < value );
//#endif
			}
			
			
			
			
			/// Perform a component-wise greater-than comparison between this an another 2D SIMD scalar.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator > ( const SIMDScalar& scalar ) const
			{/*
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_cmpgt_epi64( v, scalar.v ) );
#else*/
				return SIMDScalar( a > scalar.a, b > scalar.b );
//#endif
			}
			
			
			
			
			/// Perform a component-wise greater-than comparison between this 2D SIMD scalar and an expanded scalar.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator > ( const Int64 value ) const
			{/*
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_cmpgt_epi64( v, _mm_set1_epi64( __m64(value) ) ) );
#else*/
				return SIMDScalar( a > value, b > value );
//#endif
			}
			
			
			
			
			/// Perform a component-wise less-than-or-equal-to comparison between this an another 2D SIMD scalar.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component less than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator <= ( const SIMDScalar& scalar ) const
			{/*
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_or_pd( _mm_cmplt_epi64( v, scalar.v ),
													_mm_cmpeq_pd( vDouble, scalar.vDouble ) ) );
#else*/
				return SIMDScalar( a <= scalar.a, b <= scalar.b );
//#endif
			}
			
			
			
			
			/// Perform a component-wise less-than-or-equal-to comparison between this 2D SIMD scalar and an expanded scalar.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component less than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator <= ( const Int64 value ) const
			{/*
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_or_pd( _mm_cmplt_epi64( v, _mm_set1_epi64( __m64(value) ) ),
													_mm_cmpeq_pd( vDouble, _mm_set1_epi64( __m64(value) ) ) );
#else*/
				return SIMDScalar( a <= value, b <= value );
//#endif
			}
			
			
			
			
			
			/// Perform a component-wise greater-than-or-equal-to comparison between this an another 2D SIMD scalar.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator >= ( const SIMDScalar& scalar ) const
			{/*
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_or_pd( _mm_cmpgt_epi64( v, scalar.v ),
													_mm_cmpeq_pd( vDouble, scalar.vDouble ) ) );
#else*/
				return SIMDScalar( a <= scalar.a, b <= scalar.b );
//#endif
			}
			
			
			
			
			/// Perform a component-wise greater-than-or-equal-to comparison between this 2D SIMD scalar and an expanded scalar.
			/**
			  * Return a 2D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator >= ( const Int64 value ) const
			{/*
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_or_pd( _mm_cmpgt_epi64( v, _mm_set1_epi64( __m64(value) ) ),
													_mm_cmpeq_pd( vDouble, _mm_set1_epi64( __m64(value) ) ) );
#else*/
				return SIMDScalar( a >= value, b >= value );
//#endif
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shifting Operators
			
			
			
			
			/// Shift each component of the SIMD scalar to the left by the specified amount of bits.
			/**
			  * This method shifts the contents of each component to the left by the specified
			  * amount of bits and inserts zeros.
			  * 
			  * @param bitShift - the number of bits to shift this SIMD scalar by.
			  * @return the shifted SIMD scalar.
			  */
			RIM_FORCE_INLINE SIMDScalar operator << ( Int32 bitShift ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_slli_epi64( v, bitShift ) );
#else
				return SIMDScalar( a << bitShift, b << bitShift, c << bitShift, d << bitShift );
#endif
			}
			
			
			
			
			/// Shift each component of the SIMD scalar to the right by the specified amount of bits.
			/**
			  * This method shifts the contents of each component to the right by the specified
			  * amount of bits and sign extends the original values..
			  * 
			  * @param bitShift - the number of bits to shift this SIMD scalar by.
			  * @return the shifted SIMD scalar.
			  */
			RIM_FORCE_INLINE SIMDScalar operator >> ( Int32 bitShift ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_sub_epi64( _mm_setzero_si128(), _mm_srli_epi64( v, bitShift ) ) );
#else
				return SIMDScalar( a >> bitShift, b >> bitShift, c >> bitShift, d >> bitShift );
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
				return SIMDScalar( _mm_sub_epi64( _mm_setzero_si128(), v ) );
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
				return SIMDScalar( _mm_add_epi64( v, scalar.v ) );
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
			RIM_FORCE_INLINE SIMDScalar operator + ( const Int64 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
#if defined(RIM_PLATFORM_64_BIT)
				return SIMDScalar( _mm_add_epi64( v, _mm_set1_epi64x( value ) ) );
#else
				return SIMDScalar( a + value, b + value );
#endif
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
				return SIMDScalar( _mm_sub_epi64( v, scalar.v ) );
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
			RIM_FORCE_INLINE SIMDScalar operator - ( const Int64 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
#if defined(RIM_PLATFORM_64_BIT)
				return SIMDScalar( _mm_sub_epi64( v, _mm_set1_epi64x( value ) ) );
#else
				return SIMDScalar( a - value, b - value );
#endif
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
				return SIMDScalar( a*scalar.a, b*scalar.b );
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
			RIM_FORCE_INLINE SIMDScalar operator * ( const Int64 value ) const
			{
				return SIMDScalar( a*value, b*value );
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
				return SIMDScalar( a/scalar.a, b/scalar.b );
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
			RIM_FORCE_INLINE SIMDScalar operator / ( const Int64 value ) const
			{
				return SIMDScalar( a/value, b/value );
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
				v = _mm_add_epi64( v, scalar.v );
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
				v = _mm_sub_epi64( v, scalar.v );
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
				a *= scalar.a;
				b *= scalar.b;
				
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
				a /= scalar.a;
				b /= scalar.b;
				
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
			
			
			
			
			/// Return whether or not this SIMD type is supported by the current CPU.
			RIM_FORCE_INLINE static Bool isSupported()
			{
				SIMDFlags flags = SIMDFlags::get();
				return (flags & SIMDFlags::SSE_2) != 0;
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
				SIMDInt64 v;
				SIMDDouble vDouble;
#endif
				
				struct
				{
					/// The A component of a 2D SIMD scalar.
					Int64 a;
					
					
					
					/// The B component of a 2D SIMD scalar.
					Int64 b;
				};
				
				
				/// The components of a 2D SIMD scalar in array format.
				Int64 x[2];
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Declarations
			
			
			
			
			template < typename T, Size width >
			friend class SIMDVector3D;
			
			
			/// Declare the floating point version of this class as a friend.
			friend class SIMDScalar<Float64,2>;
			
			
			friend RIM_FORCE_INLINE SIMDScalar abs( const SIMDScalar& scalar );
			friend RIM_FORCE_INLINE SIMDScalar min( const SIMDScalar& scalar1, const SIMDScalar& scalar2 );
			friend RIM_FORCE_INLINE SIMDScalar max( const SIMDScalar& scalar1, const SIMDScalar& scalar2 );
			
			template < UInt i1, UInt i2 >
			friend RIM_FORCE_INLINE SIMDScalar shuffle( const SIMDScalar& scalar1 );
			
			template < UInt i1, UInt i2 >
			friend RIM_FORCE_INLINE SIMDScalar shuffle( const SIMDScalar& scalar1, const SIMDScalar& scalar2 );
			
			friend RIM_FORCE_INLINE SIMDScalar select( const SIMDScalar& selector,
														const SIMDScalar& scalar1, const SIMDScalar& scalar2 );
			friend RIM_FORCE_INLINE SIMDScalar<Float64,2> select( const SIMDScalar& selector,
														const SIMDScalar<Float64,2>& scalar1, const SIMDScalar<Float64,2>& scalar2 );
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Associative SIMD Scalar Operators
//############		
//##########################################################################################
//##########################################################################################




/// Add a scalar value to each component of this scalar and return the resulting scalar.
RIM_FORCE_INLINE SIMDScalar<Int64,2> operator + ( const Int64 value, const SIMDScalar<Int64,2>& scalar )
{
	return SIMDScalar<Int64,2>(value) + scalar;
}




/// Subtract a scalar value from each component of this scalar and return the resulting scalar.
RIM_FORCE_INLINE SIMDScalar<Int64,2> operator - ( const Int64 value, const SIMDScalar<Int64,2>& scalar )
{
	return SIMDScalar<Int64,2>(value) - scalar;
}




/// Multiply a scalar value by each component of this scalar and return the resulting scalar.
RIM_FORCE_INLINE SIMDScalar<Int64,2> operator * ( const Int64 value, const SIMDScalar<Int64,2>& scalar )
{
	return SIMDScalar<Int64,2>(value) * scalar;
}




/// Divide each component of this scalar by a scalar value and return the resulting scalar.
RIM_FORCE_INLINE SIMDScalar<Int64,2> operator / ( const Int64 value, const SIMDScalar<Int64,2>& scalar )
{
	return SIMDScalar<Int64,2>(value) / scalar;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Free Vector Functions
//############		
//##########################################################################################
//##########################################################################################




/// Compute the absolute value of each component of the specified SIMD scalar and return the result.
RIM_FORCE_INLINE SIMDScalar<Int64,2> abs( const SIMDScalar<Int64,2>& scalar )
{
	return SIMDScalar<Int64,2>( math::abs(scalar.a), math::abs(scalar.b) );
}




/// Compute the minimum of each component of the specified SIMD scalars and return the result.
RIM_FORCE_INLINE SIMDScalar<Int64,2> min( const SIMDScalar<Int64,2>& scalar1, const SIMDScalar<Int64,2>& scalar2 )
{
	return SIMDScalar<Int64,2>( math::min(scalar1.a, scalar2.a),
								math::min(scalar1.b, scalar2.b) );
}




/// Compute the maximum of each component of the specified SIMD scalars and return the result.
RIM_FORCE_INLINE SIMDScalar<Int64,2> max( const SIMDScalar<Int64,2>& scalar1, const SIMDScalar<Int64,2>& scalar2 )
{
	return SIMDScalar<Int64,2>( math::max(scalar1.a, scalar2.a),
								math::max(scalar1.b, scalar2.b) );
}




/// Pick 2 elements from the specified SIMD scalar and return the result.
template < UInt i1, UInt i2 >
RIM_FORCE_INLINE SIMDScalar<Int64,2> shuffle( const SIMDScalar<Int64,2>& scalar )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
	return SIMDScalar<Int64,2>( _mm_shuffle_pd( scalar.v, scalar.v, _MM_SHUFFLE2(i2, i1) ) );
#else
	return SIMDScalar<Int64,2>( scalar[i1], scalar[i2] );
#endif
}




/// Pick one element from each SIMD scalar and return the result.
template < UInt i1, UInt i2 >
RIM_FORCE_INLINE SIMDScalar<Int64,2> shuffle( const SIMDScalar<Int64,2>& scalar1, const SIMDScalar<Int64,2>& scalar2 )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
	return SIMDScalar<Int64,2>( _mm_shuffle_pd( scalar1.v, scalar2.v, _MM_SHUFFLE2(i2, i1) ) );
#else
	return SIMDScalar<Int64,2>( scalar1[i1], scalar1[i2] );
#endif
}




/// Select elements from the first SIMD scalar if the selector is TRUE, otherwise from the second.
RIM_FORCE_INLINE SIMDScalar<Int64,2> select( const SIMDScalar<Int64,2>& selector,
												const SIMDScalar<Int64,2>& scalar1, const SIMDScalar<Int64,2>& scalar2 )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
	// (((b^a) & selector) ^ a)
	return SIMDScalar<Int64,2>( _mm_xor_pd( scalar2.vDouble, _mm_and_pd( selector.vDouble, _mm_xor_pd( scalar1.vDouble, scalar2.vDouble ) ) ) );
#else
	return SIMDScalar<Int64,2>( selector.a ? scalar1.a : scalar2.a,
								selector.b ? scalar1.b : scalar2.b );
#endif
}




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SIMD_SCALAR_INT_64_2_H
