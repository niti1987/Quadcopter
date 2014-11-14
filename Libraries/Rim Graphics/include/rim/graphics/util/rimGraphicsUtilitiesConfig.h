/*
 *  rimGraphicsUtilitesConfig.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/28/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_UTILITIES_CONFIG_H
#define INCLUDE_RIM_GRAPHICS_UTILITIES_CONFIG_H


#include "../rimGraphicsConfig.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GRAPHICS_UTILITIES_NAMESPACE_START
	#define RIM_GRAPHICS_UTILITIES_NAMESPACE_START		RIM_GRAPHICS_NAMESPACE_START namespace util {
#endif




#ifndef RIM_GRAPHICS_UTILITIES_NAMESPACE_END
	#define RIM_GRAPHICS_UTILITIES_NAMESPACE_END		}; RIM_GRAPHICS_NAMESPACE_END
#endif




//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


using rim::util::allocate;
using rim::util::deallocate;
using rim::util::construct;
using rim::util::destruct;
using rim::util::constructArray;
using rim::util::destructArray;


using rim::util::copy;

using rim::images::Color3D;
using rim::images::Color4D;


//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_UTILITIES_CONFIG_H
