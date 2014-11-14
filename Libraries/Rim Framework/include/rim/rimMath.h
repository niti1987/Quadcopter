/*
 *  rimMath.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 4/20/07.
 *  Copyright 2007 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_MATH_H
#define INCLUDE_RIM_MATH_H


#include "math/rimMathConfig.h"


#include "math/rimScalarMath.h"
#include "math/rimArrayMath.h"


#include "math/rimAABB1D.h"
#include "math/rimAABB2D.h"
#include "math/rimAABB3D.h"


#include "math/rimVector2D.h"
#include "math/rimVector3D.h"
#include "math/rimVector4D.h"
#include "math/rimVectorND.h"

#include "math/rimMatrix2D.h"
#include "math/rimMatrix3D.h"
#include "math/rimMatrix4D.h"
#include "math/rimMatrixND.h"
#include "math/rimMatrix.h"

#include "math/rimQuaternion.h"

#include "math/rimTransform2D.h"
#include "math/rimTransform3D.h"


#include "math/rimRay2D.h"
#include "math/rimRay3D.h"


#include "math/rimPlane2D.h"
#include "math/rimPlane3D.h"


#include "math/rimFixed.h"
#include "math/rimComplex.h"


// SIMD Scalar/Vector Classes.
#include "math/rimSIMD.h"

#include "math/rimMathPrimitives.h"

#include "math/rimUniformDistribution.h"
#include "math/rimNormalDistribution.h"
#include "math/rimExponentialDistribution.h"
#include "math/rimPoissonDistribution.h"


#include "math/rimFFT.h"
#include "math/rimConvolution.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




// 1D Bounding Box Type Definitions.
typedef AABB1D<int>			AABB1i;
typedef AABB1D<float>		AABB1f;
typedef AABB1D<double>		AABB1d;




// 2D Bounding Box Type Definitions.
typedef AABB2D<int>			AABB2i;
typedef AABB2D<float>		AABB2f;
typedef AABB2D<double>		AABB2d;




// 3D Bounding Box Type Definitions.
typedef AABB3D<int>			AABB3i;
typedef AABB3D<float>		AABB3f;
typedef AABB3D<double>		AABB3d;




// 2D Matrix Type Definitions.
typedef Matrix2D<int>		Matrix2i;
typedef Matrix2D<float>		Matrix2f;
typedef Matrix2D<double>	Matrix2d;




// 3D Matrix Type Definitions.
typedef Matrix3D<int>		Matrix3i;
typedef Matrix3D<float>		Matrix3f;
typedef Matrix3D<double>	Matrix3d;




// 4D Matrix Type Definitions.
typedef Matrix4D<int>		Matrix4i;
typedef Matrix4D<float>		Matrix4f;
typedef Matrix4D<double>	Matrix4d;




// Quaternion Type Definitions.
typedef Quaternion<int>		Quaternioni;
typedef Quaternion<float>	Quaternionf;
typedef Quaternion<double>	Quaterniond;




// 2D Vector Type Definitions.
typedef Vector2D<int>		Vector2i;
typedef Vector2D<float>		Vector2f;
typedef Vector2D<double>	Vector2d;




// 3D Vector Type Definitions.
typedef Vector3D<int>		Vector3i;
typedef Vector3D<float>		Vector3f;
typedef Vector3D<double>	Vector3d;




// 4D Vector Type Definitions.
typedef Vector4D<int>		Vector4i;
typedef Vector4D<float>		Vector4f;
typedef Vector4D<double>	Vector4d;




// 2D Plane Type Definitions.
typedef Plane2D<int> Plane2i;
typedef Plane2D<float> Plane2f;
typedef Plane2D<double> Plane2d;




// 3D Plane Type Definitions.
typedef Plane3D<int> Plane3i;
typedef Plane3D<float> Plane3f;
typedef Plane3D<double> Plane3d;




// 2D Ray Type Definitions.
typedef Ray2D<int>		Ray2i;
typedef Ray2D<float>	Ray2f;
typedef Ray2D<double>	Ray2d;




// 3D Ray Type Definitions.
typedef Ray3D<int>		Ray3i;
typedef Ray3D<float>	Ray3f;
typedef Ray3D<double>	Ray3d;




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#ifdef RIM_MATH_NAMESPACE_START
	#undef RIM_MATH_NAMESPACE_START
#endif




#ifdef RIM_MATH_NAMESPACE_END
	#undef RIM_MATH_NAMESPACE_END
#endif


#endif	// INCLUDE_RIM_MATH_H
