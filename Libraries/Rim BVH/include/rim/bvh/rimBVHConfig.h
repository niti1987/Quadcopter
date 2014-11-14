/*
 *  rimBVHConfig.h
 *  Rim BVH
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_BVH_CONFIG_H
#define INCLUDE_RIM_BVH_CONFIG_H


#include "rim/rimFramework.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_BVH_NAMESPACE_START
	#define RIM_BVH_NAMESPACE_START		RIM_NAMESPACE_START namespace bvh {
#endif




#ifndef RIM_BVH_NAMESPACE_END
	#define RIM_BVH_NAMESPACE_END		}; RIM_NAMESPACE_END
#endif




//##########################################################################################
//*****************************  Start Rim BVH Namespace  **********************************
RIM_BVH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


using rim::math::Vector2D;
using rim::math::Vector2f;
using rim::math::Vector2d;

using rim::math::Vector3D;
using rim::math::Vector3f;
using rim::math::Vector3d;

using rim::math::Transform3f;

using rim::math::AABB1D;
using rim::math::AABB1f;
using rim::math::AABB1d;


using rim::math::AABB2D;
using rim::math::AABB2f;
using rim::math::AABB2d;

using rim::math::AABB3D;
using rim::math::AABB3f;
using rim::math::AABB3d;

using rim::math::Ray3D;
using rim::math::Ray3f;


using rim::math::SIMDFloat4;
using rim::math::SIMDInt4;


typedef rim::math::SIMDVector3D<Float32,4> SIMDVector3f;
typedef rim::math::SIMDRay3D<Float32,4> SIMDRay3f;
typedef rim::math::SIMDAABB3D<Float32,4> SIMDAABB3f;
typedef rim::math::SIMDTriangle3D<Float32,4> SIMDTriangle3f;
typedef rim::math::SIMDPlane3D<Float32,4> SIMDPlane3f;


//##########################################################################################
//*****************************  End Rim BVH Namespace  ************************************
RIM_BVH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_BVH_CONFIG_H
