/*
 *  rimGraphicsAnimationConfig.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 3/19/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_ANIMATION_CONFIG_H
#define INCLUDE_RIM_GRAPHICS_ANIMATION_CONFIG_H


#include "../rimGraphicsConfig.h"


#include "../rimGraphicsUtilities.h"
#include "../rimGraphicsCameras.h"
#include "../rimGraphicsLights.h"
#include "../rimGraphicsObjects.h"
#include "../rimGraphicsShapes.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GRAPHICS_ANIMATION_NAMESPACE_START
	#define RIM_GRAPHICS_ANIMATION_NAMESPACE_START		RIM_GRAPHICS_NAMESPACE_START namespace animation {
#endif




#ifndef RIM_GRAPHICS_ANIMATION_NAMESPACE_END
	#define RIM_GRAPHICS_ANIMATION_NAMESPACE_END		}; RIM_GRAPHICS_NAMESPACE_END
#endif




//##########################################################################################
//**********************  Start Rim Graphics Animation Namespace  **************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


using rim::graphics::lights::Light;
using rim::graphics::cameras::Camera;
using rim::graphics::objects::GraphicsObject;
using rim::graphics::shapes::GraphicsShape;



//##########################################################################################
//**********************  End Rim Graphics Animation Namespace  ****************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_ANIMATION_CONFIG_H
