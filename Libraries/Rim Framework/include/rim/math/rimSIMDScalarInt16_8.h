/*
 * Project:     Rim Framework
 * 
 * File:        rim/math/SIMDScalarInt16_8.h
 * 
 * Version:     1.0.0
 * 
 * Contents:    rim::math::SIMDScalar class specialization for an 8x16-bit integer SIMD data type.
 * 
 * License:
 * 
 *     Copyright (C) 2010-12 Carl Schissler.
 *     All rights reserved.
 * 
 * 
 * Contact Information:
 *     
 *     Please send all bug reports and other contact to:
 *     Carl Schissler
 *     carl.schissler@gmail.com
 * 
 */


#ifndef INCLUDE_RIM_SIMD_SCALAR_INT_16_8_H
#define INCLUDE_RIM_SIMD_SCALAR_INT_16_8_H


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
/// A class representing a 8-component 16-bit signed-integer SIMD scalar.
/**
  * This specialization of the SIMDScalar class uses a 128-bit value to encode
  * 8 16-bit signed-integer values. All basic arithmetic operations are supported,
  * plus a subset of standard scalar operations: abs(), min(), max(), sqrt().
  */
template <>
class RIM_ALIGN(16) SIMDScalar<Int16,8>
{
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Type Declarations
			
			
			
			
			/// Define the type for a 4x float scalar structure.
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
			typedef RIM_ALTIVEC_VECTOR short SIMDInt16;
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE)
	#if RIM_SSE_VERSION_IS_SUPPORTED(1,0)
			typedef __m128 SIMDInt16Float;
	#endif
	
	#if RIM_SSE_VERSION_IS_SUPPORTED(2,0)
			typedef __m128i SIMDInt16;
	#endif
#endif
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructor
			
			
			
			
#if RIM_USE_SIMD && (defined(RIM_SIMD_ALTIVEC) || defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0))
			/// Create a new 4D vector with the specified 4D SIMD vector value.
			RIM_FORCE_INLINE SIMDScalar( SIMDInt16 simdScalar )
				:	v( simdScalar )
			{
			}
#endif

#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
			/// Create a new 4D vector with the specified 4D SIMD vector value.
			RIM_FORCE_INLINE SIMDScalar( SIMDInt16Float simdScalar )
				:	vFloat( simdScalar )
			{
			}
#endif
			
			
			
			
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new 4D SIMD scalar with all elements left uninitialized.
			RIM_FORCE_INLINE SIMDScalar()
			{
			}
			
			
			
			
			/// Create a new 4D SIMD scalar with all elements equal to the specified value.
			RIM_FORCE_INLINE SIMDScalar( Int16 value )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				v = (SIMDInt16)(value);
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = _mm_set1_epi16( value );
#else
				a = b = c = d = e = f = g = h = value;
#endif
			}
			
			
			
			
			/// Create a new 4D SIMD scalar with the elements equal to the specified 4 values.
			RIM_FORCE_INLINE SIMDScalar( Int16 newA, Int16 newB, Int16 newC, Int16 newD, Int16 newE, Int16 newF, Int16 newG, Int16 newH )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				v = (SIMDInt16)( newA, newB, newC, newD, newE, newF, newG, newH );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				// The parameters are reversed to keep things consistent with loading from an address.
				v = _mm_set_epi16( newH, newG, newF, newE, newD, newC, newB, newA );
#else
				a = newA;	b = newB;	c = newC;	d = newD;
				e = newE;	f = newF;	g = newG;	h = newH;
#endif
			}
			
			
			
			
			/// Create a new 4D SIMD scalar from the first 4 values stored at specified pointer's location.
			RIM_FORCE_INLINE SIMDScalar( const Int16* array )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				a = array[0];	b = array[1];	c = array[2];	d = array[3];
				e = array[4];	f = array[5];	g = array[6];	h = array[7];
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = _mm_load_si128( (const SIMDInt16*)array );
#else
				a = array[0];	b = array[1];	c = array[2];	d = array[3];
				e = array[4];	f = array[5];	g = array[6];	h = array[7];
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
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				v = other.v;
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = other.v;
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				vFloat = other.vFloat;
#else
				a = other.a;	b = other.b;	c = other.c;	d = other.d;
				e = other.e;	f = other.f;	g = other.g;	h = other.h;
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
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				v = other.v;
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = other.v;
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				vFloat = other.vFloat;
#else
				a = other.a;	b = other.b;	c = other.c;	d = other.d;
				e = other.e;	f = other.f;	g = other.g;	h = other.h;
#endif
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Load Methods
			
			
			
			
			RIM_FORCE_INLINE static SIMDScalar load( const Int16* array )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( array[0], array[1], array[2], array[3],
									array[4], array[5], array[6], array[7] );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar( _mm_load_si128( (const SIMDInt16*)array ) );
#else
				return SIMDScalar( array[0], array[1], array[2], array[3],
									array[4], array[5], array[6], array[7] );
#endif
			}
			
			
			
			
			RIM_FORCE_INLINE static SIMDScalar loadUnaligned( const Int16* array )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( array[0], array[1], array[2], array[3],
									array[4], array[5], array[6], array[7] );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar( _mm_loadu_si128( (const SIMDInt16*)array ) );
#else
				return SIMDScalar( array[0], array[1], array[2], array[3],
									array[4], array[5], array[6], array[7] );
#endif
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Store Method
			
			
			
			
			/// Store the contents of this SIMD scalar into the specified aligned destination pointer.
			RIM_FORCE_INLINE void store( Int16* destination ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				destination[0] = a;	destination[1] = b;	destination[2] = c;	destination[3] = d;
				destination[4] = e;	destination[5] = f;	destination[6] = g;	destination[7] = h;
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				_mm_store_si128( (SIMDInt16*)destination, v );
#else
				destination[0] = a;	destination[1] = b;	destination[2] = c;	destination[3] = d;
				destination[4] = e;	destination[5] = f;	destination[6] = g;	destination[7] = h;
#endif
			}
			
			
			
			
			/// Store the contents of this SIMD scalar into the specified unaligned destination pointer.
			RIM_FORCE_INLINE void storeUnaligned( Int16* destination ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				destination[0] = a;	destination[1] = b;	destination[2] = c;	destination[3] = d;
				destination[4] = e;	destination[5] = f;	destination[6] = g;	destination[7] = h;
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				_mm_storeu_si128( (SIMDInt16*)destination, v );
#else
				destination[0] = a;	destination[1] = b;	destination[2] = c;	destination[3] = d;
				destination[4] = e;	destination[5] = f;	destination[6] = g;	destination[7] = h;
#endif
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Accessor Methods
			
			
			
			
			/// Return a reference to the value stored at the specified component index in this scalar.
			RIM_FORCE_INLINE Int16& operator [] ( Index i )
			{
				return x[i];
			}
			
			
			
			
			/// Return the value stored at the specified component index in this scalar.
			RIM_FORCE_INLINE Int16 operator [] ( Index i ) const
			{
				return x[i];
			}
			
			
			
			
			/// Return a pointer to the first element in this scalar.
			/**
			  * The remaining values are in the next 7 locations after the
			  * first element.
			  */
			RIM_FORCE_INLINE const Int16* toArray() const
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
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_nor( v, v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_xor_si128( v, _mm_set1_epi16( Int16(0xFFFF) ) ) );
#else
				return SIMDScalar( ~a, ~b, ~c, ~d, ~e, ~f, ~g, ~h );
#endif
			}
			
			
			
			
			/// Compute the bitwise AND of this 4D SIMD vector with another and return the result.
			RIM_FORCE_INLINE SIMDScalar operator & ( const SIMDScalar& vector ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_and( v, vector.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_and_si128( v, vector.v ) );
#else
				return SIMDScalar( a & vector.a, b & vector.b, c & vector.c, d & vector.d,
									e & vector.e, f & vector.f, g & vector.g, h & vector.h );
#endif
			}
			
			
			
			
			/// Compute the bitwise OR of this 4D SIMD vector with another and return the result.
			RIM_FORCE_INLINE SIMDScalar operator | ( const SIMDScalar& vector ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_or( v, vector.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_or_si128( v, vector.v ) );
#else
				return SIMDScalar( a | vector.a, b | vector.b, c | vector.c, d | vector.d,
									e | vector.e, f | vector.f, g | vector.g, h | vector.h );
#endif
			}
			
			
			
			
			/// Compute the bitwise XOR of this 4D SIMD vector with another and return the result.
			RIM_FORCE_INLINE SIMDScalar operator ^ ( const SIMDScalar& vector ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_xor( v, vector.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_xor_si128( v, vector.v ) );
#else
				return SIMDScalar( a ^ vector.a, b ^ vector.b, c ^ vector.c, d ^ vector.d,
									e ^ vector.e, f ^ vector.f, g ^ vector.g, h ^ vector.h );
#endif
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Logical Assignment Operators
			
			
			
			
			/// Compute the logical AND of this 4D SIMD vector with another and assign it to this vector.
			RIM_FORCE_INLINE SIMDScalar& operator &= ( const SIMDScalar& vector )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				v = vec_and( v, vector.v );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = _mm_and_si128( v, vector.v );
#else
				a &= vector.a;	b &= vector.b;	c &= vector.c;	d &= vector.d;
				e &= vector.e;	f &= vector.f;	g &= vector.g;	h &= vector.h;
#endif
				return *this;
			}
			
			
			
			
			/// Compute the logical OR of this 4D SIMD vector with another and assign it to this vector.
			RIM_FORCE_INLINE SIMDScalar& operator |= ( const SIMDScalar& vector )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				v = vec_or( v, vector.v );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = _mm_or_si128( v, vector.v );
#else
				a |= vector.a;	b |= vector.b;	c |= vector.c;	d |= vector.d;
				e |= vector.e;	f |= vector.f;	g |= vector.g;	h |= vector.h;
#endif
				return *this;
			}
			
			
			
			
			/// Compute the bitwise XOR of this 4D SIMD vector with another and assign it to this vector.
			RIM_FORCE_INLINE SIMDScalar& operator ^= ( const SIMDScalar& vector )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				v = vec_xor( v, vector.v );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = _mm_xor_si128( v, vector.v );
#else
				a ^= vector.a;	b ^= vector.b;	c ^= vector.c;	d ^= vector.d;
				e ^= vector.e;	f ^= vector.f;	g ^= vector.g;	h ^= vector.h;
#endif
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Compare two 4D SIMD scalars component-wise for equality.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * If each corresponding pair of components is equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator == ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_cmpeq( v, scalar.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_cmpeq_epi16( v, scalar.v ) );
#else
				return SIMDScalar( a == scalar.a, b == scalar.b, c == scalar.c, d == scalar.d,
									e == scalar.e, f == scalar.f, g == scalar.g, h == scalar.h );
#endif
			}
			
			
			
			
			/// Compare this scalar to a single floating point value for equality.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components is equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator == ( const Int16 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_cmpeq( v, (SIMDInt16)(value) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_cmpeq_epi16( v, _mm_set1_epi16(value) ) );
#else
				return SIMDScalar( a == value, b == value, c == value, d == value,
									e == value, f == value, g == value, h == value );
#endif
			}
			
			
			
			
			
			/// Compare two 4D SIMD scalars component-wise for inequality
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * If each corresponding pair of components is not equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator != ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				const SIMDInt16 temp = vec_cmpeq( v, scalar.v );
				return SIMDScalar( vec_nor( temp, temp ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_xor_si128( _mm_cmpeq_epi16( v, scalar.v ), _mm_set1_epi16( Int16(0xFFFF) ) ) );
#else
				return SIMDScalar( a != scalar.a, b != scalar.b, c != scalar.c, d != scalar.d,
									e != scalar.e, f != scalar.f, g != scalar.g, h != scalar.h );
#endif
			}
			
			
			
			
			/// Compare this scalar to a single floating point value for inequality.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components is not equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator != ( const Int16 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				const SIMDInt16 temp = vec_cmpeq( v, (SIMDInt16)(value) );
				return SIMDScalar( vec_nor( temp, temp ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_xor_si128( _mm_cmpeq_epi16( v, _mm_set1_epi16(value) ), _mm_set1_epi16( Int16(0xFFFF) ) ) );
#else
				return SIMDScalar( a != value, b != value, c != value, d != value,
									e != value, f != value, g != value, h != value );
#endif
			}
			
			
			
			
			/// Perform a component-wise less-than comparison between this an another 4D SIMD scalar.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component less than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator < ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_cmplt( v, scalar.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_cmplt_epi16( v, scalar.v ) );
#else
				return SIMDScalar( a < scalar.a, b < scalar.b, c < scalar.c, d < scalar.d,
									e < scalar.e, f < scalar.f, g < scalar.g, h < scalar.h );
#endif
			}
			
			
			
			
			/// Perform a component-wise less-than comparison between this 4D SIMD scalar and an expanded scalar.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component less than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator < ( const Int16 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_cmplt( v, (SIMDInt16)(value) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_cmplt_epi16( v, _mm_set1_epi16(value) ) );
#else
				return SIMDScalar( a < value, b < value, c < value, d < value,
									e < value, f < value, g < value, h < value );
#endif
			}
			
			
			
			
			/// Perform a component-wise greater-than comparison between this an another 4D SIMD scalar.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator > ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_cmpgt( v, scalar.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_cmpgt_epi16( v, scalar.v ) );
#else
				return SIMDScalar( a > scalar.a, b > scalar.b, c > scalar.c, d > scalar.d,
									e > scalar.e, f > scalar.f, g > scalar.g, h > scalar.h );
#endif
			}
			
			
			
			
			/// Perform a component-wise greater-than comparison between this 4D SIMD scalar and an expanded scalar.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator > ( const Int16 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_cmpgt( v, (SIMDInt16)(value) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_cmpgt_epi16( v, _mm_set1_epi16(value) ) );
#else
				return SIMDScalar( a > value, b > value, c > value, d > value,
									e > value, f > value, g > value, h > value );
#endif
			}
			
			
			
			
			/// Perform a component-wise less-than-or-equal-to comparison between this an another 4D SIMD scalar.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component less than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator <= ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_cmple( v, scalar.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_or_si128( _mm_cmplt_epi16( v, scalar.v ),
														_mm_cmpeq_epi16( v, scalar.v ) ) );
#else
				return SIMDScalar( a <= scalar.a, b <= scalar.b, c <= scalar.c, d <= scalar.d,
									e <= scalar.e, f <= scalar.f, g <= scalar.g, h <= scalar.h );
#endif
			}
			
			
			
			
			/// Perform a component-wise less-than-or-equal-to comparison between this 4D SIMD scalar and an expanded scalar.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component less than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator <= ( const Int16 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_cmple( v, (SIMDInt16)(value) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				SIMDInt16 scalar = _mm_set1_epi16(value);
				return SIMDScalar( _mm_or_si128( _mm_cmplt_epi16( v, scalar ),
														_mm_cmpeq_epi16( v, scalar ) ) );
#else
				return SIMDScalar( a <= value, b <= value, c <= value, d <= value,
									e <= value, f <= value, g <= value, h <= value );
#endif
			}
			
			
			
			
			
			/// Perform a component-wise greater-than-or-equal-to comparison between this an another 4D SIMD scalar.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator >= ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_cmpge( v, scalar.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_or_si128( _mm_cmpgt_epi16( v, scalar.v ),
														_mm_cmpeq_epi16( v, scalar.v ) ) );
#else
				return SIMDScalar( a >= scalar.a, b >= scalar.b, c >= scalar.c, d >= scalar.d,
									e >= scalar.e, f >= scalar.f, g >= scalar.g, h >= scalar.h );
#endif
			}
			
			
			
			
			/// Perform a component-wise greater-than-or-equal-to comparison between this 4D SIMD scalar and an expanded scalar.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar operator >= ( const Int16 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_cmpge( v, (SIMDInt16)(value) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				SIMDInt16 scalar = _mm_set1_epi16(value);
				return SIMDScalar( _mm_or_si128( _mm_cmpgt_epi16( v, scalar ),
														_mm_cmpeq_epi16( v, scalar ) ) );
#else
				return SIMDScalar( a >= value, b >= value, c >= value, d >= value,
									e >= value, f >= value, g >= value, h >= value );
#endif
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
			RIM_FORCE_INLINE SIMDScalar operator << ( Int16 bitShift ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_sl( v, (SIMDInt16)(bitShift) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_slli_epi16( v, bitShift ) );
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
			RIM_FORCE_INLINE SIMDScalar operator >> ( Int16 bitShift ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_sra( v, (SIMDInt16)(bitShift) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_srai_epi16( v, bitShift ) );
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
			  * This method negates every component of this 4D SIMD scalar
			  * and returns the result, leaving this scalar unmodified.
			  * 
			  * @return the negation of the original scalar.
			  */
			RIM_FORCE_INLINE SIMDScalar operator - () const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_sub( (SIMDInt16)(0), v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_sub_epi16( _mm_set1_epi16(0), v ) );
#else
				return SIMDScalar( -a, -b, -c, -d );
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
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_add( v, scalar.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_add_epi16( v, scalar.v ) );
#else
				return SIMDScalar( a + scalar.a, b + scalar.b, c + scalar.c, d + scalar.d );
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
			RIM_FORCE_INLINE SIMDScalar operator + ( const Int16 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_add( v, (SIMDInt16)(value) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_add_epi16( v, _mm_set1_epi16(value) ) );
#else
				return SIMDScalar( a + value, b + value, c + value, d + value );
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
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_sub( v, scalar.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_sub_epi16( v, scalar.v ) );
#else
				return SIMDScalar( a - scalar.a, b - scalar.b, c - scalar.c, d - scalar.d );
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
			RIM_FORCE_INLINE SIMDScalar operator - ( const Int16 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_sub( v, (SIMDInt16)(value) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				return SIMDScalar( _mm_sub_epi16( v, _mm_set1_epi16(value) ) );
#else
				return SIMDScalar( a - value, b - value, c - value, d - value );
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
				return SIMDScalar( a*scalar.a, b*scalar.b, c*scalar.c, d*scalar.d, e*scalar.e, f*scalar.f, g*scalar.g, h*scalar.h );
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
			RIM_FORCE_INLINE SIMDScalar operator * ( const Int16 value ) const
			{
				return SIMDScalar( a*value, b*value, c*value, d*value, e*value, f*value, g*value, h*value );
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
				return SIMDScalar( a/scalar.a, b/scalar.b, c/scalar.c, d/scalar.d, e/scalar.e, f/scalar.f, g/scalar.g, h/scalar.h );
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
			RIM_FORCE_INLINE SIMDScalar operator / ( const Int16 value ) const
			{
				return SIMDScalar( a/value, b/value, c/value, d/value, e/value, f/value, g/value, h/value );
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
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				v = vec_add( v, scalar.v );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = _mm_add_epi16( v, scalar.v );
#else
				a += scalar.a;	b += scalar.b;	c += scalar.c;	d += scalar.d;
				e += scalar.e;	f += scalar.f;	g += scalar.g;	h += scalar.h;
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
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				v = vec_sub( v, scalar.v );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0)
				v = _mm_sub_epi16( v, scalar.v );
#else
				a -= scalar.a;	b -= scalar.b;	c -= scalar.c;	d -= scalar.d;
				e -= scalar.e;	f -= scalar.f;	g -= scalar.g;	h -= scalar.h;
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
				a *= scalar.a;	b *= scalar.b;	c *= scalar.c;	d *= scalar.d;
				e *= scalar.e;	f *= scalar.f;	g *= scalar.g;	h *= scalar.h;
				
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
				a /= scalar.a;	b /= scalar.b;	c /= scalar.c;	d /= scalar.d;
				e /= scalar.e;	f /= scalar.f;	g /= scalar.g;	h /= scalar.h;
				
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
#if RIM_USE_SIMD && (defined(RIM_SIMD_ALTIVEC) || defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0))
				return 16;
#else
				return 0;
#endif
			}
			
			
			
			
			/// Get the width of this scalar (number of components it has).
			RIM_FORCE_INLINE static Size getWidth()
			{
				return 8;
			}
			
			
			
			
			/// Return whether or not this SIMD type is supported by the current CPU.
			RIM_FORCE_INLINE static Bool isSupported()
			{
				SIMDFlags flags = SIMDFlags::get();
				return (flags & SIMDFlags::SSE_2) != 0 || (flags & SIMDFlags::ALTIVEC) != 0;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			RIM_ALIGN(16) union
			{
#if RIM_USE_SIMD && (defined(RIM_SIMD_ALTIVEC) || defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(2,0))
				/// The 4D SIMD vector used internally.
				SIMDInt16 v;
#endif

#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				/// A floating-point alias of the integer SIMD scalar.
				SIMDInt16Float vFloat;
#endif
				
				struct
				{
					/// The first component of a 8x16-bit SIMD integer.
					Int16 a;
					
					/// The second component of a 4D SIMD scalar.
					Int16 b;
					
					/// The third component of a 4D SIMD scalar.
					Int16 c;
					
					/// The fourth component of a 4D SIMD scalar.
					Int16 d;
					
					/// The fifth component of a 4D SIMD scalar.
					Int16 e;
					
					/// The sixth component of a 4D SIMD scalar.
					Int16 f;
					
					/// The seventh component of a 4D SIMD scalar.
					Int16 g;
					
					/// The eighth component of a 4D SIMD scalar.
					Int16 h;
				};
				
				
				/// The components of a 4D SIMD scalar in array format.
				Int16 x[8];
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Declarations
			
			
			
			
			template < typename T, Size width >
			friend class SIMDVector3D;
			
			
			
			friend RIM_FORCE_INLINE SIMDScalar abs( const SIMDScalar& scalar );
			friend RIM_FORCE_INLINE SIMDScalar sqrt( const SIMDScalar& scalar );
			friend RIM_FORCE_INLINE SIMDScalar min( const SIMDScalar& scalar1, const SIMDScalar& scalar2 );
			friend RIM_FORCE_INLINE SIMDScalar max( const SIMDScalar& scalar1, const SIMDScalar& scalar2 );
			
			template < UInt i1, UInt i2, UInt i3, UInt i4 >
			friend RIM_FORCE_INLINE SIMDScalar shuffle( const SIMDScalar& scalar1 );
			
			template < UInt i1, UInt i2, UInt i3, UInt i4 >
			friend RIM_FORCE_INLINE SIMDScalar shuffle( const SIMDScalar& scalar1, const SIMDScalar& scalar2 );
			
			
			friend RIM_FORCE_INLINE SIMDScalar select( const SIMDScalar& selector,
										const SIMDScalar& scalar1, const SIMDScalar& scalar2 );
			
			friend RIM_FORCE_INLINE SIMDScalar lows( const SIMDScalar& scalar );
			friend RIM_FORCE_INLINE SIMDScalar highs( const SIMDScalar& scalar );
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Associative SIMD Scalar Operators
//############		
//##########################################################################################
//##########################################################################################




/// Add a scalar value to each component of this scalar and return the resulting scalar.
RIM_FORCE_INLINE SIMDScalar<Int16,8> operator + ( const Int16 value, const SIMDScalar<Int16,8>& scalar )
{
	return SIMDScalar<Int16,8>(value) + scalar;
}




/// Subtract a scalar value from each component of this scalar and return the resulting scalar.
RIM_FORCE_INLINE SIMDScalar<Int16,8> operator - ( const Int16 value, const SIMDScalar<Int16,8>& scalar )
{
	return SIMDScalar<Int16,8>(value) - scalar;
}




/// Multiply a scalar value by each component of this scalar and return the resulting scalar.
RIM_FORCE_INLINE SIMDScalar<Int16,8> operator * ( const Int16 value, const SIMDScalar<Int16,8>& scalar )
{
	return SIMDScalar<Int16,8>(value) * scalar;
}




/// Divide each component of this scalar by a scalar value and return the resulting scalar.
RIM_FORCE_INLINE SIMDScalar<Int16,8> operator / ( const Int16 value, const SIMDScalar<Int16,8>& scalar )
{
	return SIMDScalar<Int16,8>(value) / scalar;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Free Vector Functions
//############		
//##########################################################################################
//##########################################################################################




/// Compute the absolute value of each component of the specified SIMD scalar and return the result.
RIM_FORCE_INLINE SIMDScalar<Int16,8> abs( const SIMDScalar<Int16,8>& scalar )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
	return SIMDScalar<Int16,8>( vec_abs( scalar.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE)
	return SIMDScalar<Int16,8>( math::abs(scalar.a), math::abs(scalar.b), math::abs(scalar.c), math::abs(scalar.d),
								math::abs(scalar.e), math::abs(scalar.f), math::abs(scalar.g), math::abs(scalar.h) );
#else
	return SIMDScalar<Int16,8>( math::abs(scalar.a), math::abs(scalar.b), math::abs(scalar.c), math::abs(scalar.d) );
#endif
}



/// Compute the minimum of each component of the specified SIMD scalars and return the result.
RIM_FORCE_INLINE SIMDScalar<Int16,8> min( const SIMDScalar<Int16,8>& scalar1, const SIMDScalar<Int16,8>& scalar2 )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
	return SIMDScalar<Int16,8>( vec_min( scalar1.v, scalar2.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE)
	return SIMDScalar<Int16,8>( math::min(scalar1.a, scalar2.a),
								math::min(scalar1.b, scalar2.b),
								math::min(scalar1.c, scalar2.c),
								math::min(scalar1.d, scalar2.d),
								math::min(scalar1.e, scalar2.e),
								math::min(scalar1.f, scalar2.f),
								math::min(scalar1.g, scalar2.g),
								math::min(scalar1.h, scalar2.h) );
#else
	return SIMDScalar<Int16,8>( math::min(scalar1.a, scalar2.a),
								math::min(scalar1.b, scalar2.b),
								math::min(scalar1.c, scalar2.c),
								math::min(scalar1.d, scalar2.d),
								math::min(scalar1.e, scalar2.e),
								math::min(scalar1.f, scalar2.f),
								math::min(scalar1.g, scalar2.g),
								math::min(scalar1.h, scalar2.h) );
#endif
}




/// Compute the maximum of each component of the specified SIMD scalars and return the result.
RIM_FORCE_INLINE SIMDScalar<Int16,8> max( const SIMDScalar<Int16,8>& scalar1, const SIMDScalar<Int16,8>& scalar2 )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
	return SIMDScalar<Int16,8>( vec_max( scalar1.v, scalar2.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE)
	return SIMDScalar<Int16,8>( math::max(scalar1.a, scalar2.a),
								math::max(scalar1.b, scalar2.b),
								math::max(scalar1.c, scalar2.c),
								math::max(scalar1.d, scalar2.d),
								math::max(scalar1.e, scalar2.e),
								math::max(scalar1.f, scalar2.f),
								math::max(scalar1.g, scalar2.g),
								math::max(scalar1.h, scalar2.h) );
#else
	return SIMDScalar<Int16,8>( math::max(scalar1.a, scalar2.a),
								math::max(scalar1.b, scalar2.b),
								math::max(scalar1.c, scalar2.c),
								math::max(scalar1.d, scalar2.d),
								math::max(scalar1.e, scalar2.e),
								math::max(scalar1.f, scalar2.f),
								math::max(scalar1.g, scalar2.g),
								math::max(scalar1.h, scalar2.h) );
#endif
}




/// Select elements from the first SIMD scalar if the selector is TRUE, otherwise from the second.
RIM_FORCE_INLINE SIMDScalar<Int16,8> select( const SIMDScalar<Int16,8>& selector,
												const SIMDScalar<Int16,8>& scalar1, const SIMDScalar<Int16,8>& scalar2 )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
	return SIMDScalar<Int16,8>( vec_sel( scalar2.v, scalar1.v, selector.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
	// (((b^a) & selector) ^ a)
	return SIMDScalar<Int16,8>( _mm_xor_ps( scalar2.vFloat,
										_mm_and_ps( selector.vFloat,
													_mm_xor_ps( scalar1.vFloat, scalar2.vFloat ) ) ) );
#else
	return SIMDScalar<Int16,8>( selector.a ? scalar1.a : scalar2.a,
								selector.b ? scalar1.b : scalar2.b,
								selector.c ? scalar1.c : scalar2.c,
								selector.d ? scalar1.d : scalar2.d,
								selector.e ? scalar1.e : scalar2.e,
								selector.f ? scalar1.f : scalar2.f,
								selector.g ? scalar1.g : scalar2.g,
								selector.h ? scalar1.h : scalar2.h );
#endif
}




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SIMD_SCALAR_INT_16_8_H
