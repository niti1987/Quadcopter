/*
 *  rimSIMDRay3D.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 7/12/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SIMD_RAY_3D_H
#define INCLUDE_RIM_SIMD_RAY_3D_H


#include "rimMathConfig.h"


#include "rimRay3D.h"
#include "rimSIMDVector3D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




template < typename T, Size width >
class SIMDRay3D;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a set of 3D rays stored in a SIMD-compatible format.
/**
  * This class is used to store and operate on a set of 3D rays
  * in a SIMD fashion. The rays are stored in a structure-of-arrays format
  * that accelerates SIMD operations. Each ray is specified by an origin
  * point and a direction vector.
  */
template < typename T >
class RIM_ALIGN(16) SIMDRay3D<T,4>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a SIMD ray with N copies of the specified ray for a SIMD width of N.
			RIM_FORCE_INLINE SIMDRay3D( const Ray3D<T>& ray )
				:	origin( ray.origin ),
					direction( ray.direction )
			{
			}
			
			
			
			
			/// Create a SIMD ray with the 4 rays it contains equal to the specified rays.
			RIM_FORCE_INLINE SIMDRay3D( const Ray3D<T>& ray1, const Ray3D<T>& ray2,
										const Ray3D<T>& ray3, const Ray3D<T>& ray4 )
				:	origin( ray1.origin, ray2.origin, ray3.origin, ray4.origin ),
					direction( ray1.direction, ray2.direction, ray3.direction, ray4.direction )
			{
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
			
			
			
			
			/// A SIMD 3D vector indicating the origin of the ray(s).
			SIMDVector3D<T,4> origin;
			
			
			
			
			/// A SIMD 3D vector indicating the direction of the ray(s).
			SIMDVector3D<T,4> direction;
			
			
			
			
};




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SIMD_RAY_3D_H
