/*
 *  rimSIMDVector3D.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 7/12/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SIMD_VECTOR_3D_H
#define INCLUDE_RIM_SIMD_VECTOR_3D_H


#include "rimMathConfig.h"


#include "rimVector3D.h"
#include "rimSIMDScalar.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




template < typename T, Size width >
class SIMDVector3D;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a set of 3D vectors stored in a SIMD-compatible format.
/**
  * This class is used to store and operate on a set of 3D vectors
  * in a SIMD fashion. The vectors are stored in a structure-of-arrays format
  * that accelerates SIMD operations.
  */
template < typename T >
class RIM_ALIGN(16) SIMDVector3D<T,4>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a quad 3D SIMD vector with all vector components equal to zero.
			RIM_FORCE_INLINE SIMDVector3D()
				:	x(),
					y(),
					z()
			{
			}
			
			
			
			
			/// Create a quad 3D SIMD vector with all of the four vectors equal to the specified vector.
			RIM_FORCE_INLINE SIMDVector3D( const Vector3D<T>& vector )
				:	x( vector.x ),
					y( vector.y ),
					z( vector.z )
			{
			}
			
			
			
			
			/// Create a quad 3D SIMD vector with each of the four vectors equal to the specified vector.
			RIM_FORCE_INLINE SIMDVector3D( const Vector3D<T>& v1, const Vector3D<T>& v2,
										const Vector3D<T>& v3, const Vector3D<T>& v4 )
#if !RIM_USE_SIMD || RIM_USE_SIMD && defined(RIM_SIMD_ALTIVEC) || defined(RIM_SIMD_SSE) && !RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				:	x( v1.x, v2.x, v3.x, v4.x ),
					y( v1.y, v2.y, v3.y, v4.y ),
					z( v1.z, v2.z, v3.z, v4.z )
#endif
			{
#if RIM_USE_SIMD && defined(RIM_SIMD_SSE) && RIM_SSE_VERSION_IS_SUPPORTED(1,0)
				
				__m128 xy10 = _mm_setzero_ps();
				__m128 zw10 = _mm_setzero_ps();
				__m128 xy32 = _mm_setzero_ps();
				__m128 zw32 = _mm_setzero_ps();
				
				xy10 = _mm_loadl_pi( xy10, (__m64*)&v1.x );
				zw10 = _mm_loadl_pi( zw10, (__m64*)&v1.z );
				xy10 = _mm_loadh_pi( xy10, (__m64*)&v2.x );
				zw10 = _mm_loadh_pi( zw10, (__m64*)&v2.z );
				
				xy32 = _mm_loadl_pi( xy32, (__m64*)&v3.x );
				zw32 = _mm_loadl_pi( zw32, (__m64*)&v3.z );
				xy32 = _mm_loadh_pi( xy32, (__m64*)&v4.x );
				zw32 = _mm_loadh_pi( zw32, (__m64*)&v4.z );
				
				x.v = _mm_shuffle_ps( xy10, xy32, _MM_SHUFFLE(2,0,2,0) );
				y.v = _mm_shuffle_ps( xy10, xy32, _MM_SHUFFLE(3,1,3,1) );
				z.v = _mm_shuffle_ps( zw10, zw32, _MM_SHUFFLE(2,0,2,0) );
#endif
			}
			
			
			
			
			/// Create a quad 3D SIMD vector with the specified X, Y, and Z SIMDScalars.
			RIM_FORCE_INLINE SIMDVector3D( const SIMDScalar<T,4>& newX, const SIMDScalar<T,4>& newY, const SIMDScalar<T,4>& newZ )
				:	x( newX ),
					y( newY ),
					z( newZ )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Magnitude Methods
			
			
			
			
			/// Return the 4-component SIMD scalar magnitude of this quad SIMD 3D vector.
			RIM_FORCE_INLINE SIMDScalar<T,4> getMagnitude() const
			{
				return math::sqrt( x*x + y*y + z*z );
			}
			
			
			
			
			/// Return the 4-component SIMD scalar squared magnitude of this quad SIMD 3D vector.
			RIM_FORCE_INLINE SIMDScalar<T,4> getMagnitudeSquared() const
			{
				return x*x + y*y + z*z;
			}
			
			
			
			
			/// Return a normalized copy of this quad SIMD 3D vector.
			RIM_FORCE_INLINE SIMDVector3D normalize() const
			{
				T inverseMagnitude = T(1) / math::sqrt( x*x + y*y + z*z );
				
				return SIMDVector3D( x*inverseMagnitude, y*inverseMagnitude, z*inverseMagnitude );
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Operators
			
			
			
			
			/// Compute and return the component-wise sum of this quad SIMD 3D vector with another.
			RIM_FORCE_INLINE SIMDVector3D operator + ( const SIMDVector3D& other ) const
			{
				return SIMDVector3D( x + other.x, y + other.y, z + other.z );
			}
			
			
			
			
			/// Compute and return the component-wise sum of this quad SIMD 3D vector with a quad SIMD scalar.
			RIM_FORCE_INLINE SIMDVector3D operator + ( const SIMDScalar<T,4>& quadScalar ) const
			{
				return SIMDVector3D( x + quadScalar, y + quadScalar, z + quadScalar );
			}
			
			
			
			
			/// Compute and return the component-wise difference of this quad SIMD 3D vector with another.
			RIM_FORCE_INLINE SIMDVector3D operator - ( const SIMDVector3D& other ) const
			{
				return SIMDVector3D( x - other.x, y - other.y, z - other.z );
			}
			
			
			
			
			/// Compute and return the component-wise difference of this quad SIMD 3D vector with a quad SIMD scalar.
			RIM_FORCE_INLINE SIMDVector3D operator - ( const SIMDScalar<T,4>& quadScalar ) const
			{
				return SIMDVector3D( x - quadScalar, y - quadScalar, z - quadScalar );
			}
			
			
			
			
			/// Compute and return the component-wise multiplication of this quad SIMD 3D vector with another.
			RIM_FORCE_INLINE SIMDVector3D operator * ( const SIMDVector3D& other ) const
			{
				return SIMDVector3D( x*other.x, y*other.y, z*other.z );
			}
			
			
			
			
			/// Compute and return the component-wise multiplication of this quad SIMD 3D vector with a quad SIMD scalar.
			RIM_FORCE_INLINE SIMDVector3D operator * ( const SIMDScalar<T,4>& quadScalar ) const
			{
				return SIMDVector3D( x*quadScalar, y*quadScalar, z*quadScalar );
			}
			
			
			
			
			/// Compute and return the component-wise quotient of this quad SIMD 3D vector divided by a quad SIMD scalar.
			RIM_FORCE_INLINE SIMDVector3D operator / ( const SIMDScalar<T,4>& quadScalar ) const
			{
				const SIMDScalar<T,4> inverseQuadScalar = T(1) / quadScalar;
				
				return SIMDVector3D( x*inverseQuadScalar, y*inverseQuadScalar, z*inverseQuadScalar );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Assignment Operators
			
			
			
			
			/// Compute the component-wise sum of this quad SIMD 3D vector with another and assign it to this vector.
			RIM_FORCE_INLINE SIMDVector3D& operator += ( const SIMDVector3D& other ) const
			{
				x += other.x;
				y += other.y;
				z += other.z;
				
				return *this;
			}
			
			
			
			
			/// Compute the component-wise sum of this quad SIMD 3D vector with a quad SIMD scalar and assign it to this vector.
			RIM_FORCE_INLINE SIMDVector3D& operator += ( const SIMDScalar<T,4>& quadScalar ) const
			{
				x += quadScalar;
				y += quadScalar;
				z += quadScalar;
				
				return *this;
			}
			
			
			
			
			/// Compute the component-wise difference of this quad SIMD 3D vector with another and assign it to this vector.
			RIM_FORCE_INLINE SIMDVector3D& operator -= ( const SIMDVector3D& other ) const
			{
				x -= other.x;
				y -= other.y;
				z -= other.z;
				
				return *this;
			}
			
			
			
			
			/// Compute the component-wise difference of this quad SIMD 3D vector with a quad SIMD scalar and assign it to this vector.
			RIM_FORCE_INLINE SIMDVector3D& operator -= ( const SIMDScalar<T,4>& quadScalar ) const
			{
				x -= quadScalar;
				y -= quadScalar;
				z -= quadScalar;
				
				return *this;
			}
			
			
			
			
			/// Compute the component-wise multiplication of this quad SIMD 3D vector with another and assign it to this vector.
			RIM_FORCE_INLINE SIMDVector3D& operator *= ( const SIMDVector3D& other ) const
			{
				x *= other.x;
				y *= other.y;
				z *= other.z;
				
				return *this;
			}
			
			
			
			
			/// Compute the component-wise multiplication of this quad SIMD 3D vector with a quad SIMD scalar and assign it to this vector.
			RIM_FORCE_INLINE SIMDVector3D& operator *= ( const SIMDScalar<T,4>& quadScalar ) const
			{
				x *= quadScalar;
				y *= quadScalar;
				z *= quadScalar;
				
				return *this;
			}
			
			
			
			
			/// Compute the component-wise quotient of this quad SIMD 3D vector divided by a quad SIMD scalar and assign it to this vector.
			RIM_FORCE_INLINE SIMDVector3D& operator /= ( const SIMDScalar<T,4>& quadScalar ) const
			{
				const SIMDScalar<T,4> inverseQuadScalar = T(1) / quadScalar;
				
				x *= inverseQuadScalar;
				y *= inverseQuadScalar;
				z *= inverseQuadScalar;
				
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
				return 16;
			}
			
			
			
			
			/// Get the width of this vector (number of 3D vectors it has).
			RIM_FORCE_INLINE static Size getWidth()
			{
				return 4;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The X component vector of this SIMDVector3D.
			RIM_ALIGN(16) SIMDScalar<T,4> x;
			
			
			
			
			/// The X component vector of this SIMDVector3D.
			RIM_ALIGN(16) SIMDScalar<T,4> y;
			
			
			
			
			/// The X component vector of this SIMDVector3D.
			RIM_ALIGN(16) SIMDScalar<T,4> z;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Free Vector Functions
//############		
//##########################################################################################
//##########################################################################################




/// Compute and return the dot product of two SIMD 3D vectors.
/** 
  * This method performs N standard dot product operations for a SIMD width
  * of N values per register and returns the result as an N-wide SIMD scalar.
  * 
  * @param vector1 - The first SIMD 3D vector of the dot product.
  * @param vector2 - The second SIMD 3D vector of the dot product.
  * @return The dot products of the two vector parameters.
  */
template < typename T, Size width >
RIM_FORCE_INLINE SIMDScalar<T,width> dot( const SIMDVector3D<T,width>& vector1,
										const SIMDVector3D<T,width>& vector2 )
{
	const SIMDVector3D<T,width> temp = vector1*vector2;
	
	return temp.x + temp.y + temp.z;
}




/// Compute and return the cross product of two SIMD 3D vectors.
/** 
  * This method performs N standard cross product operations for a SIMD width
  * of N values per register and returns the result as a SIMD 3D vector which
  * contains the results of all cross products.
  * 
  * @param vector1 - The first SIMD 3D vector of the cross product.
  * @param vector2 - The second SIMD 3D vector of the cross product.
  * @return The cross product vectors of the two vector parameters.
  */
template < typename T, Size width >
RIM_FORCE_INLINE SIMDVector3D<T,width> cross( const SIMDVector3D<T,width>& vector1,
											const SIMDVector3D<T,width>& vector2 )
{
	return SIMDVector3D<T,width>( vector1.y*vector2.z - vector1.z*vector2.y,
								vector1.z*vector2.x - vector1.x*vector2.z,
								vector1.x*vector2.y - vector1.y*vector2.x );
}





//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SIMD_VECTOR_3D_H
