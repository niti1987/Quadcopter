/*
 *  rimSIMDPlane3D.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 7/12/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SIMD_PLANE_3D_H
#define INCLUDE_RIM_SIMD_PLANE_3D_H


#include "rimMathConfig.h"


#include "rimPlane3D.h"
#include "rimSIMDVector3D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A template prototype declaration for the SIMDPlane3D class.
/**
  * This class is used to store and operate on a set of N 3D planes
  * in a SIMD fashion. The planes are stored in a structure-of-arrays format
  * that accelerates SIMD operations. Each plane is specified by a normal and
  * origin offset.
  */
template < typename T, Size dimension >
class SIMDPlane3D;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A specialization for the SIMDPlane3D class that has a SIMD width of 4.
/**
  * This class is used to store and operate on a set of 4 3D planes
  * in a SIMD fashion. The planes are stored in a structure-of-arrays format
  * that accelerates SIMD operations. Each plane is specified by a normal and
  * origin offset.
  */
template < typename T >
class RIM_ALIGN(16) SIMDPlane3D<T,4>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a SIMD plane with N copies of the specified plane for a SIMD width of N.
			RIM_FORCE_INLINE SIMDPlane3D( const Plane3D<T>& plane )
				:	normal( plane.normal ),
					offset( plane.offset )
			{
			}
			
			
			
			
			/// Create a SIMD plane with the 4 planes it contains equal to the specified planes.
			RIM_FORCE_INLINE SIMDPlane3D( const Plane3D<T>& plane1, const Plane3D<T>& plane2,
											const Plane3D<T>& plane3, const Plane3D<T>& plane4 )
				:	normal( plane1.normal, plane2.normal, plane3.normal, plane4.normal ),
					offset( plane1.offset, plane2.offset, plane3.offset, plane4.offset )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point Distance Methods
			
			
			
			
			/// Get the perpendicular distance from the specified point to the plane.
			RIM_FORCE_INLINE SIMDScalar<T,4> getDistanceTo( const SIMDVector3D<T,4>& point ) const
			{
				return math::abs( math::dot( normal, point ) + offset );
			}
			
			
			
			
			/// Get the perpendicular distance from the specified point to the plane.
			RIM_FORCE_INLINE SIMDScalar<T,4> getSignedDistanceTo( const SIMDVector3D<T,4>& point ) const
			{
				return math::dot( normal, point ) + offset;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// A SIMD 3D vector indicating the normals of the planes.
			SIMDVector3D<T,4> normal;
			
			
			
			
			/// A SIMD scalar indicating the distance that the planes are offset from the origin.
			SIMDScalar<T,4> offset;
			
			
			
			
};




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SIMD_PLANE_3D_H
