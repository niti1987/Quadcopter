/*
 *  rimGraphicsTexturesConfig.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/28/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_TEXTURES_CONFIG_H
#define INCLUDE_RIM_GRAPHICS_TEXTURES_CONFIG_H


#include "../rimGraphicsConfig.h"


#include "../rimGraphicsUtilities.h"
#include "../devices/rimGraphicsContextObject.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GRAPHICS_TEXTURES_NAMESPACE_START
	#define RIM_GRAPHICS_TEXTURES_NAMESPACE_START		RIM_GRAPHICS_NAMESPACE_START namespace textures {
#endif




#ifndef RIM_GRAPHICS_TEXTURES_NAMESPACE_END
	#define RIM_GRAPHICS_TEXTURES_NAMESPACE_END		}; RIM_GRAPHICS_NAMESPACE_END
#endif




//##########################################################################################
//**********************  Start Rim Graphics Textures Namespace  ***************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


using rim::images::Image;
using rim::images::PixelFormat;


using rim::graphics::devices::ContextObject;


//##########################################################################################
//**********************  End Rim Graphics Textures Namespace  *****************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_TEXTURES_CONFIG_H
