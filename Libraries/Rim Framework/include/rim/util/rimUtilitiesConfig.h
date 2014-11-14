/*
 *  rimUtilitiesConfig.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_UTILITIES_CONFIG_H
#define INCLUDE_RIM_UTILITIES_CONFIG_H


#include "../rimConfig.h"


#include <cstdlib>
#include <new>


#include "../math/rimScalarMath.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




/// Define the name of the utility library namespace.
#ifndef RIM_UTILITIES_NAMESPACE
	#define RIM_UTILITIES_NAMESPACE util
#endif




#ifndef RIM_UTILITIES_NAMESPACE_START
	#define RIM_UTILITIES_NAMESPACE_START		RIM_NAMESPACE_START namespace RIM_UTILITIES_NAMESPACE {
#endif




#ifndef RIM_UTILITIES_NAMESPACE_END
	#define RIM_UTILITIES_NAMESPACE_END		}; RIM_NAMESPACE_END
#endif




RIM_NAMESPACE_START
/// A namespace containing data structure classes and memory manipulation methods.
namespace RIM_UTILITIES_NAMESPACE {
};
RIM_NAMESPACE_END




//##########################################################################################
//***************************  Start Rim Utilities Namespace  ******************************
RIM_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//##########################################################################################
//***************************  End Rim Utilities Namespace  ********************************
RIM_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_UTILITIES_CONFIG_H
