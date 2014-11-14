/*
 *  rimSIMDTriangle3D.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 7/12/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SIMD_TRIANGLE_3D_H
#define INCLUDE_RIM_SIMD_TRIANGLE_3D_H


#include "rimMathConfig.h"


#include "rimVector3D.h"
#include "rimSIMDVector3D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A template prototype declaration for the SIMDAABB3D class.
/**
  * This class is used to store and operate on a set of N 3D triangles
  * in a SIMD fashion. The triangles are stored in a structure-of-arrays format
  * that accelerates SIMD operations. Each triangle is specified by 3 vertex
  * coordinates that indicate the vertices of the triangle.
  */
template < typename T, Size dimension >
class SIMDTriangle3D;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A specialization for the SIMDTriangle3D class that has a SIMD width of 4.
/**
  * This class is used to store and operate on a set of 4 3D triangles
  * in a SIMD fashion. The triangles are stored in a structure-of-arrays format
  * that accelerates SIMD operations. Each triangle is specified by 3 vertex
  * coordinates that indicate the vertices of the triangle.
  */
template < typename T >
class RIM_ALIGN(16) SIMDTriangle3D<T,4>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a SIMD triangle with N copies of the specified triangle for a SIMD width of N.
			RIM_FORCE_INLINE SIMDTriangle3D( const Vector3D<T>& newV0, const Vector3D<T>& newV1,
												const Vector3D<T>& newV2 )
				:	v0( newV0 ),
					v1( newV1 ),
					v2( newV2 )
			{
			}
			
			
			
			
			/// Create a SIMD ray with the 4 rays it contains equal to the specified rays.
			RIM_FORCE_INLINE SIMDTriangle3D( const SIMDVector3D<T,4>& newV0, const SIMDVector3D<T,4>& newV1,
												const SIMDVector3D<T,4>& newV2 )
				:	v0( newV0 ),
					v1( newV1 ),
					v2( newV2 )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The first vertex of the SIMD triangle.
			SIMDVector3D<T,4> v0;
			
			
			
			
			/// The second vertex of the SIMD triangle.
			SIMDVector3D<T,4> v1;
			
			
			
			
			/// The second vertex of the SIMD triangle.
			SIMDVector3D<T,4> v2;
			
			
			
			
};




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SIMD_TRIANGLE_3D_H
