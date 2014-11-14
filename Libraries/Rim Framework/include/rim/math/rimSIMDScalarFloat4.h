


#ifndef INCLUDE_RIM_SIMD_SCALAR_FLOAT_4_H
#define INCLUDE_RIM_SIMD_SCALAR_FLOAT_4_H


#include "rimMathConfig.h"


#include "rimVector3D.h"
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
class RIM_ALIGN(16) SIMDScalar<Float32,4>
{
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Type Declarations
			
			
			
			
			/// Define the type for a 4x float scalar structure.
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
			typedef RIM_ALTIVEC_VECTOR float SIMDScalar4;
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
			typedef __m128 SIMDScalar4;
#endif
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructor
			
			
			
			
#if RIM_USE_SIMD && (defined(RIM_SIMD_ALTIVEC) || defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0))
			/// Create a new 4D scalar with the specified 4D SIMD scalar value.
			RIM_FORCE_INLINE SIMDScalar( SIMDScalar4 simdScalar )
				:	v( simdScalar )
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
			RIM_FORCE_INLINE SIMDScalar( Float32 value )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				v = (SIMDScalar4)(value);
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				v = _mm_set1_ps( value );
#else
				a = b = c = d = value;
#endif
			}
			
			
			
			
			/// Create a new 4D SIMD scalar with the elements equal to the specified 4 values.
			RIM_FORCE_INLINE SIMDScalar( Float32 newA, Float32 newB, Float32 newC, Float32 newD )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				v = (SIMDScalar4)( newA, newB, newC, newD );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				// The parameters are reversed to keep things consistent with loading from an address.
				v = _mm_set_ps( newD, newC, newB, newA );
#else
				a = newA;
				b = newB;
				c = newC;
				d = newD;
#endif
			}
			
			
			
			
			/// Create a new 4D SIMD scalar with the first 3 elements equal to the specified vector's components.
			/**
			  * The last element of the SIMD scalar is initialized to 0.
			  */
			RIM_FORCE_INLINE SIMDScalar( const Vector3D<Float32>& vector )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				v = (SIMDScalar4)( vector.x, vector.y, vector.z, Float32(0) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				// The parameters are reversed to keep things consistent with loading from an address.
				v = _mm_set_ps( Float32(0), vector.z, vector.y, vector.x );
#else
				a = vector.x;
				b = vector.y;
				c = vector.z;
				d = 0;
#endif
			}
			
			
			
			
			/// Create a new 4D SIMD scalar from the first 4 values stored at specified aligned pointer's location.
			RIM_FORCE_INLINE SIMDScalar( const Float32* array )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				a = array[0];
				b = array[1];
				c = array[2];
				d = array[3];
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				v = _mm_load_ps( array );
#else
				a = array[0];
				b = array[1];
				c = array[2];
				d = array[3];
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
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				v = other.v;
#else
				a = other.a;
				b = other.b;
				c = other.c;
				d = other.d;
#endif
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Load Methods
			
			
			
			
			RIM_FORCE_INLINE static SIMDScalar load( const Float32* array )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( array[0], array[1], array[2], array[3] );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar( _mm_load_ps( array ) );
#else
				return SIMDScalar( array[0], array[1], array[2], array[3] );
#endif
			}
			
			
			
			
			RIM_FORCE_INLINE static SIMDScalar loadUnaligned( const Float32* array )
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( array[0], array[1], array[2], array[3] );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar( _mm_loadu_ps( array ) );
#else
				return SIMDScalar( array[0], array[1], array[2], array[3] );
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
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				v = other.v;
#else
				a = other.a;
				b = other.b;
				c = other.c;
				d = other.d;
#endif
				return *this;
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Accessor Methods
			
			
			
			
			/// Get a reference to the value stored at the specified component index in this scalar.
			RIM_FORCE_INLINE Float32& operator [] ( Index i )
			{
				return x[i];
			}
			
			
			
			
			/// Get the value stored at the specified component index in this scalar.
			RIM_FORCE_INLINE Float32 operator [] ( Index i ) const
			{
				return x[i];
			}
			
			
			
			
			/// Get a pointer to the first element in this scalar.
			/**
			  * The remaining values are in the next 3 locations after the
			  * first element.
			  */
			RIM_FORCE_INLINE const Float32* toArray() const
			{
				return x;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Compare two 4D SIMD scalars component-wise for equality.
			/**
			  * Return a 4D scalar of integers indicating the result of the comparison.
			  * If each corresponding pair of components is equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator == ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar<Bool,4>( vec_cmpeq( v, scalar.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar<Bool,4>( _mm_cmpeq_ps( v, scalar.v ) );
#else
				return SIMDScalar<Bool,4>( a == scalar.a, b == scalar.b, c == scalar.c, d == scalar.d );
#endif
			}
			
			
			
			
			/// Compare this scalar to a single floating point value for equality.
			/**
			  * Return a 4D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components is equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator == ( const Float32 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar<Bool,4>( vec_cmpeq( v, (SIMDScalar4)(value) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar<Bool,4>( _mm_cmpeq_ps( v, _mm_set1_ps( value ) ) );
#else
				return SIMDScalar<Bool,4>( a == value, b == value, c == value, d == value );
#endif
			}
			
			
			
			
			
			/// Compare two 4D SIMD scalars component-wise for inequality
			/**
			  * Return a 4D scalar of integers indicating the result of the comparison.
			  * If each corresponding pair of components is not equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator != ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				const RIM_ALTIVEC_VECTOR bool temp = vec_cmpeq( v, scalar.v );
				return SIMDScalar<Bool,4>( vec_nor( temp, temp ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar<Bool,4>( _mm_cmpneq_ps( v, scalar.v ) );
#else
				return SIMDScalar<Bool,4>( a != scalar.a, b != scalar.b, c != scalar.c, d != scalar.d );
#endif
			}
			
			
			
			
			/// Compare this scalar to a single floating point value for inequality.
			/**
			  * Return a 4D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components is not equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator != ( const Float32 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				const RIM_ALTIVEC_VECTOR bool temp = vec_cmpeq( v, (SIMDScalar4)(value) );
				return SIMDScalar<Bool,4>( vec_nor( temp, temp ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar<Bool,4>( _mm_cmpneq_ps( v, _mm_set1_ps( value ) ) );
#else
				return SIMDScalar<Bool,4>( a != value, b != value, c != value, d != value );
#endif
			}
			
			
			
			
			/// Perform a component-wise less-than comparison between this an another 4D SIMD scalar.
			/**
			  * Return a 4D scalar of integers indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component less than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator < ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar<Bool,4>( vec_cmplt( v, scalar.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar<Bool,4>( _mm_cmplt_ps( v, scalar.v ) );
#else
				return SIMDScalar<Bool,4>( a < scalar.a, b < scalar.b, c < scalar.c, d < scalar.d );
#endif
			}
			
			
			
			
			/// Perform a component-wise less-than comparison between this 4D SIMD scalar and an expanded scalar.
			/**
			  * Return a 4D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component less than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator < ( const Float32 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar<Bool,4>( vec_cmplt( v, (SIMDScalar4)(value) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar<Bool,4>( _mm_cmplt_ps( v, _mm_set1_ps( value ) ) );
#else
				return SIMDScalar<Bool,4>( a < value, b < value, c < value, d < value );
#endif
			}
			
			
			
			
			/// Perform a component-wise greater-than comparison between this an another 4D SIMD scalar.
			/**
			  * Return a 4D scalar of integers indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator > ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar<Bool,4>( vec_cmpgt( v, scalar.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar<Bool,4>( _mm_cmpgt_ps( v, scalar.v ) );
#else
				return SIMDScalar<Bool,4>( a > scalar.a, b > scalar.b, c > scalar.c, d > scalar.d );
#endif
			}
			
			
			
			
			/// Perform a component-wise greater-than comparison between this 4D SIMD scalar and an expanded scalar.
			/**
			  * Return a 4D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator > ( const Float32 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar<Bool,4>( vec_cmpgt( v, (SIMDScalar4)(value) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar<Bool,4>( _mm_cmpgt_ps( v, _mm_set1_ps( value ) ) );
#else
				return SIMDScalar<Bool,4>( a > value, b > value, c > value, d > value );
#endif
			}
			
			
			
			
			/// Perform a component-wise less-than-or-equal-to comparison between this an another 4D SIMD scalar.
			/**
			  * Return a 4D scalar of integers indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component less than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator <= ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar<Bool,4>( vec_cmple( v, scalar.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar<Bool,4>( _mm_cmple_ps( v, scalar.v ) );
#else
				return SIMDScalar<Bool,4>( a <= scalar.a, b <= scalar.b, c <= scalar.c, d <= scalar.d );
#endif
			}
			
			
			
			
			/// Perform a component-wise less-than-or-equal-to comparison between this 4D SIMD scalar and an expanded scalar.
			/**
			  * Return a 4D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component less than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator <= ( const Float32 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar<Bool,4>( vec_cmple( v, (SIMDScalar4)(value) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar<Bool,4>( _mm_cmple_ps( v, _mm_set1_ps( value ) ) );
#else
				return SIMDScalar<Bool,4>( a <= value, b <= value, c <= value, d <= value );
#endif
			}
			
			
			
			
			
			/// Perform a component-wise greater-than-or-equal-to comparison between this an another 4D SIMD scalar.
			/**
			  * Return a 4D scalar of integers indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator >= ( const SIMDScalar& scalar ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar<Bool,4>( vec_cmpge( v, scalar.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar<Bool,4>( _mm_cmpge_ps( v, scalar.v ) );
#else
				return SIMDScalar<Bool,4>( a >= scalar.a, b >= scalar.b, c >= scalar.c, d >= scalar.d );
#endif
			}
			
			
			
			
			/// Perform a component-wise greater-than-or-equal-to comparison between this 4D SIMD scalar and an expanded scalar.
			/**
			  * Return a 4D scalar of integers indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDScalar<Bool,4> operator >= ( const Float32 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar<Bool,4>( vec_cmpge( v, (SIMDScalar4)(value) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar<Bool,4>( _mm_cmpge_ps( v, _mm_set1_ps( value ) ) );
#else
				return SIMDScalar<Bool,4>( a >= value, b >= value, c >= value, d >= value );
#endif
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sum Method
			
			
			
			
			RIM_FORCE_INLINE Float32 sum() const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return a + b + c + d;
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(3,0)
				__m128 temp = _mm_hadd_ps( v, v );
				return SIMDScalar( _mm_hadd_ps( temp, temp ) ).a;
#else
				return a + b + c + d;
#endif
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Store Methods
			
			
			
			
			RIM_FORCE_INLINE void store( Float32* destination ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				destination[0] = a;
				destination[1] = b;
				destination[2] = c;
				destination[3] = d;
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				_mm_store_ps( destination, v );
#else
				destination[0] = a;
				destination[1] = b;
				destination[2] = c;
				destination[3] = d;
#endif
			}
			
			
			
			
			RIM_FORCE_INLINE void storeUnaligned( Float32* destination ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				destination[0] = a;
				destination[1] = b;
				destination[2] = c;
				destination[3] = d;
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				_mm_storeu_ps( destination, v );
#else
				destination[0] = a;
				destination[1] = b;
				destination[2] = c;
				destination[3] = d;
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
				return SIMDScalar( vec_sub( (SIMDScalar4)(Float32(0)), v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar( _mm_sub_ps( _mm_set1_ps(Float32(0)), v ) );
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
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar( _mm_add_ps( v, scalar.v ) );
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
			RIM_FORCE_INLINE SIMDScalar operator + ( const Float32 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_add( v, (SIMDScalar4)(value) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar( _mm_add_ps( v, _mm_set1_ps(value) ) );
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
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar( _mm_sub_ps( v, scalar.v ) );
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
			RIM_FORCE_INLINE SIMDScalar operator - ( const Float32 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_sub( v, (SIMDScalar4)(value) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar( _mm_sub_ps( v, _mm_set1_ps(value) ) );
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
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_madd( v, scalar.v, (SIMDScalar4)(float(0)) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar( _mm_mul_ps( v, scalar.v ) );
#else
				return SIMDScalar( a*scalar.a, b*scalar.b, c*scalar.c, d*scalar.d );
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
			RIM_FORCE_INLINE SIMDScalar operator * ( const Float32 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_madd( v, (SIMDScalar4)(value),
												(SIMDScalar4)(Float32(0)) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar( _mm_mul_ps( v, _mm_set1_ps(value) ) );
#else
				return SIMDScalar( a*value, b*value, c*value, d*value );
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
#if GRIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				//Get the reciprocal estimate
				SIMDScalar4 reciprocalEstimate = vec_re( scalar.v );
				
				//One round of Newton-Raphson refinement
				SIMDScalar4 reciprocal = vec_madd( vec_nmsub( reciprocalEstimate, v, 
														(SIMDScalar4)(1) ), reciprocalEstimate, reciprocalEstimate );
				
				return SIMDScalar( vec_madd( v, reciprocal, ((SIMDScalar4)(0)) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar( _mm_div_ps( v, scalar.v ) );
#else
				return SIMDScalar( a/scalar.a, b/scalar.b, c/scalar.c, d/scalar.d );
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
			RIM_FORCE_INLINE SIMDScalar operator / ( const Float32 value ) const
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				return SIMDScalar( vec_madd( v, ((SIMDScalar4)(Float32(1) / value)), ((SIMDScalar4)(0)) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				return SIMDScalar( _mm_mul_ps( v, _mm_set1_ps(Float32(1) / value) ) );
#else
				Float32 inverse = Float32(1) / value;
				return SIMDScalar( a*inverse, b*inverse, c*inverse, d*inverse );
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
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				v = vec_add( v, scalar.v );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				v = _mm_add_ps( v, scalar.v );
#else
				a += scalar.a;
				b += scalar.b;
				c += scalar.c;
				d += scalar.d;
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
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				v = _mm_sub_ps( v, scalar.v );
#else
				a -= scalar.a;
				b -= scalar.b;
				c -= scalar.c;
				d -= scalar.d;
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
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				v = vec_madd( v, scalar.v, (SIMDScalar4)(Float32(0)) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				v = _mm_mul_ps( v, scalar.v );
#else
				a *= scalar.a;
				b *= scalar.b;
				c *= scalar.c;
				d *= scalar.d;
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
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
				a /= scalar.a;
				b /= scalar.b;
				c /= scalar.c;
				d /= scalar.d;
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				v = _mm_div_ps( v, scalar.v );
#else
				a /= scalar.a;
				b /= scalar.b;
				c /= scalar.c;
				d /= scalar.d;
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
#if RIM_USE_SIMD && (defined(RIM_SIMD_ALTIVEC) || defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0))
				return 16;
#else
				return 0;
#endif
			}
			
			
			
			
			/// Get the width of this scalar (number of components it has).
			RIM_FORCE_INLINE static Size getWidth()
			{
				return 4;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			RIM_ALIGN(16) union
			{
#if RIM_USE_SIMD && (defined(RIM_SIMD_ALTIVEC) || defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0))
				/// The 4D SIMD vector used internally.
				SIMDScalar4 v;
#endif
				
				struct
				{
					/// The A component of a 4D SIMD scalar.
					Float32 a;
					
					
					
					/// The B component of a 4D SIMD scalar.
					Float32 b;
					
					
					
					/// The C component of a 4D SIMD scalar.
					Float32 c;
					
					
					
					/// The D component of a 4D SIMD scalar.
					Float32 d;
				};
				
				
				/// The components of a 4D SIMD scalar in array format.
				Float32 x[4];
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
			
			template < UInt i1, UInt i2, UInt i3, UInt i4 >
			friend RIM_FORCE_INLINE SIMDScalar<Float32,4> shuffle( const SIMDScalar<Float32,4>& scalar1 );
			
			template < UInt i1, UInt i2, UInt i3, UInt i4 >
			friend RIM_FORCE_INLINE SIMDScalar<Float32,4> shuffle( const SIMDScalar<Float32,4>& scalar1,
																	const SIMDScalar<Float32,4>& scalar2 );
			
			friend RIM_FORCE_INLINE SIMDScalar<Float32,4> select( const SIMDScalar<Bool,4>& selector,
										const SIMDScalar<Float32,4>& scalar1, const SIMDScalar<Float32,4>& scalar2 );
			
			friend RIM_FORCE_INLINE SIMDScalar lows( const SIMDScalar& scalar );
			friend RIM_FORCE_INLINE SIMDScalar highs( const SIMDScalar& scalar );
			
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
RIM_FORCE_INLINE SIMDScalar<Float32,4> operator + ( const Float32 value, const SIMDScalar<Float32,4>& scalar )
{
	return SIMDScalar<Float32,4>(value) + scalar;
}




/// Subtract a scalar value from each component of this scalar and return the resulting scalar.
RIM_FORCE_INLINE SIMDScalar<Float32,4> operator - ( const Float32 value, const SIMDScalar<Float32,4>& scalar )
{
	return SIMDScalar<Float32,4>(value) - scalar;
}




/// Multiply a scalar value by each component of this scalar and return the resulting scalar.
RIM_FORCE_INLINE SIMDScalar<Float32,4> operator * ( const Float32 value, const SIMDScalar<Float32,4>& scalar )
{
	return SIMDScalar<Float32,4>(value) * scalar;
}




/// Divide each component of this scalar by a scalar value and return the resulting scalar.
RIM_FORCE_INLINE SIMDScalar<Float32,4> operator / ( const Float32 value, const SIMDScalar<Float32,4>& scalar )
{
	return SIMDScalar<Float32,4>(value) / scalar;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Free Vector Functions
//############		
//##########################################################################################
//##########################################################################################




/// Compute the absolute value of each component of the specified SIMD scalar and return the result.
RIM_FORCE_INLINE SIMDScalar<Float32,4> abs( const SIMDScalar<Float32,4>& scalar )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
	return SIMDScalar<Float32,4>( vec_abs( scalar.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
	RIM_ALIGN(16) const UInt32 absMask[4] = { 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF };
	return SIMDScalar<Float32,4>( _mm_and_ps( scalar.v, _mm_load_ps( reinterpret_cast<const Float32*>(absMask) ) ) );
#else
	return SIMDScalar<Float32,4>( math::abs(scalar.a), math::abs(scalar.b), math::abs(scalar.c), math::abs(scalar.d) );
#endif
}




/// Compute the ceiling of each component of the specified SIMD scalar and return the result.
/**
  * This method is emulated in software on x86 platforms where SSE 4.1 is not available.
  */
RIM_FORCE_INLINE SIMDScalar<Float32,4> ceiling( const SIMDScalar<Float32,4>& scalar )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
	return SIMDScalar<Float32,4>( vec_ceil( scalar.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(4,1)
	return SIMDScalar<Float32,4>( _mm_ceil_ps( scalar.v ) );
#else
	return SIMDScalar<Float32,4>( math::ceiling(scalar.a), math::ceiling(scalar.b), math::ceiling(scalar.c), math::ceiling(scalar.d) );
#endif
}




/// Compute the floor of each component of the specified SIMD scalar and return the result.
/**
  * This method is emulated in software on x86 platforms where SSE 4.1 is not available.
  */
RIM_FORCE_INLINE SIMDScalar<Float32,4> floor( const SIMDScalar<Float32,4>& scalar )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
	return SIMDScalar<Float32,4>( vec_floor( scalar.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(4,1)
	return SIMDScalar<Float32,4>( _mm_floor_ps( scalar.v ) );
#else
	return SIMDScalar<Float32,4>( math::floor(scalar.a), math::floor(scalar.b), math::floor(scalar.c), math::floor(scalar.d) );
#endif
}




/// Compute the square root of each component of the specified SIMD scalar and return the result.
RIM_FORCE_INLINE SIMDScalar<Float32,4> sqrt( const SIMDScalar<Float32,4>& scalar )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
	// Get the square root reciprocal estimate
	RIM_ALTIVEC_VECTOR float zero = (RIM_ALTIVEC_VECTOR float)(0);
	RIM_ALTIVEC_VECTOR float oneHalf = (RIM_ALTIVEC_VECTOR float)(0.5);
	RIM_ALTIVEC_VECTOR float one = (RIM_ALTIVEC_VECTOR float)(1.0);
	RIM_ALTIVEC_VECTOR float estimate = vec_rsqrte( scalar.v );
	
	// One round of Newton-Raphson refinement
	RIM_ALTIVEC_VECTOR float estimateSquared = vec_madd( estimate, estimate, zero );
	RIM_ALTIVEC_VECTOR float halfEstimate = vec_madd( estimate, oneHalf, zero );
	
	RIM_ALTIVEC_VECTOR float reciprocalSquareRoot = vec_madd( vec_nmsub( scalar.v, estimateSquared, one ), halfEstimate, estimate );
	
	return SIMDScalar<Float32,4>( vec_madd( scalar.v, reciprocalSquareRoot, (RIM_ALTIVEC_VECTOR float)(0) ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
	return SIMDScalar<Float32,4>( _mm_sqrt_ps( scalar.v ) );
#else
	return SIMDScalar<Float32,4>( math::sqrt(scalar.a), math::sqrt(scalar.b), math::sqrt(scalar.c), math::sqrt(scalar.d) );
#endif
}




/// Compute the minimum of each component of the specified SIMD scalars and return the result.
RIM_FORCE_INLINE SIMDScalar<Float32,4> min( const SIMDScalar<Float32,4>& scalar1, const SIMDScalar<Float32,4>& scalar2 )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
	return SIMDScalar<Float32,4>( vec_min( scalar1.v, scalar2.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
	return SIMDScalar<Float32,4>( _mm_min_ps( scalar1.v, scalar2.v ) );
#else
	return SIMDScalar<Float32,4>( math::min(scalar1.a, scalar2.a),
								math::min(scalar1.b, scalar2.b),
								math::min(scalar1.c, scalar2.c),
								math::min(scalar1.d, scalar2.d) );
#endif
}




/// Compute the maximum of each component of the specified SIMD scalars and return the result.
RIM_FORCE_INLINE SIMDScalar<Float32,4> max( const SIMDScalar<Float32,4>& scalar1, const SIMDScalar<Float32,4>& scalar2 )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
	return SIMDScalar<Float32,4>( vec_max( scalar1.v, scalar2.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
	return SIMDScalar<Float32,4>( _mm_max_ps( scalar1.v, scalar2.v ) );
#else
	return SIMDScalar<Float32,4>( math::max(scalar1.a, scalar2.a),
								math::max(scalar1.b, scalar2.b),
								math::max(scalar1.c, scalar2.c),
								math::max(scalar1.d, scalar2.d) );
#endif
}




/// Pick 4 elements from the specified SIMD scalar and return the result.
template < UInt i1, UInt i2, UInt i3, UInt i4 >
RIM_FORCE_INLINE SIMDScalar<Float32,4> shuffle( const SIMDScalar<Float32,4>& scalar )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
	return SIMDScalar<Float32,4>( scalar[i1], scalar[i2], scalar[i3], scalar[i4] );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
	return SIMDScalar<Float32,4>( _mm_shuffle_ps( scalar.v, scalar.v, _MM_SHUFFLE(i4, i3, i2, i1) ) );
#else
	return SIMDScalar<Float32,4>( scalar[i1], scalar[i2], scalar[i3], scalar[i4] );
#endif
}




/// Pick two elements from each SIMD scalar and return the result.
template < UInt i1, UInt i2, UInt i3, UInt i4 >
RIM_FORCE_INLINE SIMDScalar<Float32,4> shuffle( const SIMDScalar<Float32,4>& scalar1, const SIMDScalar<Float32,4>& scalar2 )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
	return SIMDScalar<Float32,4>( scalar1[i1], scalar1[i2], scalar2[i3], scalar2[i4] );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
	return SIMDScalar<Float32,4>( _mm_shuffle_ps( scalar1.v, scalar2.v, _MM_SHUFFLE(i4, i3, i2, i1) ) );
#else
	return SIMDScalar<Float32,4>( scalar1[i1], scalar1[i2], scalar2[i3], scalar2[i4] );
#endif
}




/// Select elements from the first SIMD scalar if the selector is TRUE, otherwise from the second.
RIM_FORCE_INLINE SIMDScalar<Float32,4> select( const SIMDScalar<Bool,4>& selector,
												const SIMDScalar<Float32,4>& scalar1, const SIMDScalar<Float32,4>& scalar2 )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
	return SIMDScalar<Float32,4>( vec_sel( scalar2.v, scalar1.v, selector.v ) );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
	// (((b^a) & selector) ^ a)
	return SIMDScalar<Float32,4>( _mm_xor_ps( scalar2.v, _mm_and_ps( selector.vFloat, _mm_xor_ps( scalar1.v, scalar2.v ) ) ) );
#else
	return SIMDScalar<Float32,4>( selector.a ? scalar1.a : scalar2.a,
								selector.b ? scalar1.b : scalar2.b,
								selector.c ? scalar1.c : scalar2.c,
								selector.d ? scalar1.d : scalar2.d );
#endif
}




/// Copy the first and third element of the specified SIMD scalar into the second and fourth places.
RIM_FORCE_INLINE SIMDScalar<Float32,4> lows( const SIMDScalar<Float32,4>& scalar )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
	return SIMDScalar<Float32,4>( scalar.a, scalar.a, scalar.c, scalar.c );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(3,0)
	return SIMDScalar<Float32,4>( _mm_moveldup_ps( scalar.v ) );
#else
	return SIMDScalar<Float32,4>( scalar.a, scalar.a, scalar.c, scalar.c );
#endif
}




/// Copy the second and fourth element of the specified SIMD scalar into the first and third places.
RIM_FORCE_INLINE SIMDScalar<Float32,4> highs( const SIMDScalar<Float32,4>& scalar )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
	return SIMDScalar<Float32,4>( scalar.b, scalar.b, scalar.d, scalar.d );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(3,0)
	return SIMDScalar<Float32,4>( _mm_movehdup_ps( scalar.v ) );
#else
	return SIMDScalar<Float32,4>( scalar.b, scalar.b, scalar.d, scalar.d );
#endif
}




/// Subtract the first and third elements and add the second and fourth.
RIM_FORCE_INLINE SIMDScalar<Float32,4> subAdd( const SIMDScalar<Float32,4>& scalar1, const SIMDScalar<Float32,4>& scalar2 )
{
#if RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC)
	return SIMDScalar<Float32,4>( scalar1.a - scalar2.a, scalar1.b + scalar2.b, scalar1.c - scalar2.c, scalar1.d + scalar2.d );
#elif RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(3,0)
	return SIMDScalar<Float32,4>( _mm_addsub_ps( scalar1.v, scalar2.v ) );
#else
	return SIMDScalar<Float32,4>( scalar1.a - scalar2.a, scalar1.b + scalar2.b, scalar1.c - scalar2.c, scalar1.d + scalar2.d );
#endif
}




//##########################################################################################
//##########################################################################################
//############		
//############		Typedefs
//############		
//##########################################################################################
//##########################################################################################








//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SIMD_SCALAR_FLOAT_4_H
