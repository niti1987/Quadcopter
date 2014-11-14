/*
 *  rimPhysicsInertiaTensor.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 6/6/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_INERTIA_TENSOR_H
#define INCLUDE_RIM_PHYSICS_INERTIA_TENSOR_H


#include "rimPhysicsUtilitiesConfig.h"


//##########################################################################################
//**********************  Start Rim Physics Utilities Namespace  ***************************
RIM_PHYSICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




/// Transform an inertia tensor for an object with a given mass by the specified translation.
template < typename T >
RIM_INLINE Matrix3D<T> transformInertiaTensor( const Matrix3D<T>& I, T mass, const Vector3D<T>& translation )
{
	// Translate matrix using the 3D parallel axis theorem.
	return Matrix3D<T>(	I.x.x + mass*( translation.y*translation.y + translation.z*translation.z ),
						I.y.x - mass*translation.x*translation.y,
						I.z.x - mass*translation.x*translation.z,
						I.x.y - mass*translation.y*translation.x,
						I.y.y + mass*( translation.z*translation.z + translation.x*translation.x ),
						I.z.y - mass*translation.y*translation.z,
						I.x.z - mass*translation.z*translation.x,
						I.y.z - mass*translation.z*translation.y,
						I.z.z + mass*( translation.y*translation.y + translation.z*translation.z ) );
}




/// Transform an inertia tensor by the specified rotation matrix.
template < typename T >
RIM_INLINE Matrix3D<T> transformInertiaTensor( const Matrix3D<T>& I, const Matrix3D<T>& orientation )
{
	return orientation*I*orientation.transpose();
}




/// Transform an inertia tensor for an object with a given mass by the specified orientation and translation.
template < typename T >
RIM_INLINE Matrix3D<T> transformInertiaTensor( const Matrix3D<T>& I, T mass,
											const Matrix3D<T>& orientation, const Vector3D<T>& translation )
{
	// rotate, then translate matrix
	return transformInertiaTensor( transformInertiaTensor( I, orientation ), mass, translation );
}




//##########################################################################################
//**********************  End Rim Physics Utilities Namespace  *****************************
RIM_PHYSICS_UTILITES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_INERTIA_TENSOR_H
