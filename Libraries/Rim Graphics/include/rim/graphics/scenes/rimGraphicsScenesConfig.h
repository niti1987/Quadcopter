/*
 *  rimGraphicsScenesConfig.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 5/16/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SCENES_CONFIG_H
#define INCLUDE_RIM_GRAPHICS_SCENES_CONFIG_H


#include "../rimGraphicsConfig.h"


#include "../rimGraphicsUtilities.h"
#include "../rimGraphicsCameras.h"
#include "../rimGraphicsLights.h"
#include "../rimGraphicsObjects.h"
#include "../rimGraphicsAnimation.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GRAPHICS_SCENES_NAMESPACE_START
	#define RIM_GRAPHICS_SCENES_NAMESPACE_START		RIM_GRAPHICS_NAMESPACE_START namespace scenes {
#endif




#ifndef RIM_GRAPHICS_SCENES_NAMESPACE_END
	#define RIM_GRAPHICS_SCENES_NAMESPACE_END		}; RIM_GRAPHICS_NAMESPACE_END
#endif




//##########################################################################################
//************************  Start Rim Graphics Scenes Namespace  ***************************
RIM_GRAPHICS_SCENES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


using rim::graphics::objects::GraphicsObject;
using rim::graphics::objects::ObjectCuller;
using rim::graphics::lights::Light;
using rim::graphics::lights::LightCuller;
using rim::graphics::cameras::Camera;
using rim::graphics::animation::AnimationController;



//##########################################################################################
//************************  End Rim Graphics Scenes Namespace  *****************************
RIM_GRAPHICS_SCENES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SCENES_CONFIG_H
