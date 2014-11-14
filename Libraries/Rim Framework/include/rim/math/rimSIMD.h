/*
 *  rimSIMD.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 6/1/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SIMD_H
#define INCLUDE_RIM_SIMD_H


#include "rimMathConfig.h"


#include "rimSIMDConfig.h"
#include "rimSIMDTypes.h"
#include "rimSIMDFlags.h"

// SIMD Scalar/Vector Classes.
#include "rimSIMDScalar.h"
#include "rimSIMDScalarInt8_16.h"
#include "rimSIMDScalarInt16_8.h"
#include "rimSIMDScalarInt32_4.h"
#include "rimSIMDScalarInt64_2.h"
#include "rimSIMDScalarFloat32_4.h"
#include "rimSIMDScalarFloat64_2.h"

// SIMD Array Classes.
#include "rimSIMDArray.h"
#include "rimSIMDArrayInt32.h"
#include "rimSIMDArrayFloat32.h"
#include "rimSIMDArrayFloat64.h"

// SIMD Math Primitive Types
#include "rimSIMDVector3D.h"
#include "rimSIMDRay3D.h"
#include "rimSIMDAABB3D.h"
#include "rimSIMDPlane3D.h"
#include "rimSIMDTriangle3D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################







//##########################################################################################
//##########################################################################################
//############		
//############		Typedefs
//############		
//##########################################################################################
//##########################################################################################




// SIMD Scalar Type Definitions for the given primitive type.
typedef SIMDScalar<Float32,4>	SIMDFloat4;
typedef SIMDScalar<Float64,2>	SIMDDouble2;
typedef SIMDScalar<Int32,4>		SIMDInt4;




// SIMD Scalar Type Definitions for the default-width for the given primitive type.
typedef SIMDScalar<Float32,SIMDType<Float32>::MAX_WIDTH>	SIMDFloat;
typedef SIMDScalar<Float64,SIMDType<Float64>::MAX_WIDTH>	SIMDDouble;
typedef SIMDScalar<Int32,SIMDType<Int32>::MAX_WIDTH>		SIMDInt;




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SIMD_H
