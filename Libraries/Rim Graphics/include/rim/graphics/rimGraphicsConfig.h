/*
 *  rimGraphicsConfig.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_CONFIG_H
#define INCLUDE_RIM_GRAPHICS_CONFIG_H


#include "rim/rimFramework.h"
#include "rim/rimImages.h"
#include "rim/rimBVH.h"
#include "rim/rimGUI.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GRAPHICS_NAMESPACE_START
	#define RIM_GRAPHICS_NAMESPACE_START		RIM_NAMESPACE_START namespace graphics {
#endif




#ifndef RIM_GRAPHICS_NAMESPACE_END
	#define RIM_GRAPHICS_NAMESPACE_END		}; RIM_NAMESPACE_END
#endif




//##########################################################################################
//**************************  Start Rim Graphics Namespace  ********************************
RIM_GRAPHICS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



typedef float Real;


using rim::math::AABB2i;

using namespace rim::math;


typedef rim::math::Vector2D<Bool> Vector2b;
typedef rim::math::Vector3D<Bool> Vector3b;
typedef rim::math::Vector4D<Bool> Vector4b;



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


using rim::images::Color3f;
using rim::images::Color4f;
using rim::images::Color3d;
using rim::images::Color4d;
using rim::images::Image;
using rim::images::PixelFormat;


//##########################################################################################
//**************************  End Rim Graphics Namespace  **********************************
RIM_GRAPHICS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_CONFIG_H
