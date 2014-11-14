/*
 *  rimMathConfig.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_MATH_CONFIG_H
#define INCLUDE_RIM_MATH_CONFIG_H


#include <cmath>
#include <limits>


#include "../rimConfig.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




/// Define the name of the math library namespace.
#ifndef RIM_MATH_NAMESPACE
	#define RIM_MATH_NAMESPACE math
#endif




#ifndef RIM_MATH_NAMESPACE_START
	#define RIM_MATH_NAMESPACE_START		RIM_NAMESPACE_START namespace RIM_MATH_NAMESPACE {
#endif




#ifndef RIM_MATH_NAMESPACE_END
	#define RIM_MATH_NAMESPACE_END		}; RIM_NAMESPACE_END
#endif




RIM_NAMESPACE_START
/// A namespace containing 2D, 3D, 4D, and multi-dimensional math classes with SIMD acceleration.
namespace RIM_MATH_NAMESPACE {
};
RIM_NAMESPACE_END




//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_MATH_CONFIG_H
