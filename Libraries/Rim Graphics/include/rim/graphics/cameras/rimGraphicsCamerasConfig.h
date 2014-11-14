/*
 *  rimGraphicsCamerasConfig.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/28/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_CAMERAS_CONFIG_H
#define INCLUDE_RIM_GRAPHICS_CAMERAS_CONFIG_H


#include "../rimGraphicsConfig.h"


#include "../rimGraphicsUtilities.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GRAPHICS_CAMERAS_NAMESPACE_START
	#define RIM_GRAPHICS_CAMERAS_NAMESPACE_START		RIM_GRAPHICS_NAMESPACE_START namespace cameras {
#endif




#ifndef RIM_GRAPHICS_CAMERAS_NAMESPACE_END
	#define RIM_GRAPHICS_CAMERAS_NAMESPACE_END		}; RIM_GRAPHICS_NAMESPACE_END
#endif




//##########################################################################################
//***********************  Start Rim Graphics Cameras Namespace  ***************************
RIM_GRAPHICS_CAMERAS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




using rim::graphics::util::BoundingCone;
using rim::graphics::util::Transformable;
using rim::graphics::util::Viewport;
using rim::graphics::util::ViewVolume;




//##########################################################################################
//***********************  End Rim Graphics Cameras Namespace  *****************************
RIM_GRAPHICS_CAMERAS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_CAMERAS_CONFIG_H
