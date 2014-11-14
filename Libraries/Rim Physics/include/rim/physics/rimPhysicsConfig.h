/*
 *  rimPhysicsConfig.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_CONFIG_H
#define INCLUDE_RIM_PHYSICS_CONFIG_H


#include "rim/rimFramework.h"
#include "rim/rimBVH.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_PHYSICS_USE_SIMD
	/// Define whether or not SIMD code is allowed in this physics library.
	/**
	  * A value of 0 indicates that SIMD code is disabled, while non-zero
	  * values indicate that SIMD code is enabled.
	  */
	#define RIM_PHYSICS_USE_SIMD 0
#endif




#ifndef RIM_PHYSICS_FIXED_MAX_NUM_COLLISION_POINTS
	/// Define whether or not to have a fixed maximum CollisionManifold size.
	/**
	  * Setting this to a non-zero value will cause collision manifolds to contain
	  * up to a maximum number of points. This can improve performance by avoiding
	  * dynamic allocations for each collision manifold. A zero value will allow
	  * any number of collision points per manifold.
	  */
	#define RIM_PHYSICS_FIXED_MAX_NUM_COLLISION_POINTS 1
#endif




//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_PHYSICS_NAMESPACE_START
	#define RIM_PHYSICS_NAMESPACE_START		RIM_NAMESPACE_START namespace physics {
#endif




#ifndef RIM_PHYSICS_NAMESPACE_END
	#define RIM_PHYSICS_NAMESPACE_END		}; RIM_NAMESPACE_END
#endif




//##########################################################################################
//***************************  Start Rim Physics Namespace  ********************************
RIM_PHYSICS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



typedef float Real;


using namespace rim::math;


typedef rim::math::Vector2D<Real> Vector2;
typedef rim::math::Matrix2D<Real> Matrix2;
typedef rim::math::AABB2D<Real> AABB2;
typedef rim::math::Transform2D<Real> Transform2;

typedef rim::math::Vector3D<Real> Vector3;
typedef rim::math::Matrix3D<Real> Matrix3;
typedef rim::math::AABB3D<Real> AABB3;
typedef rim::math::Transform3D<Real> Transform3;

typedef rim::math::Vector4D<Real> Vector4;
typedef rim::math::Matrix4D<Real> Matrix4;


typedef rim::math::Plane3D<Real> Plane3;


typedef rim::bvh::BoundingSphere<Real> BoundingSphere;


//##########################################################################################
//***************************  End Rim Physics Namespace  **********************************
RIM_PHYSICS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_CONFIG_H
