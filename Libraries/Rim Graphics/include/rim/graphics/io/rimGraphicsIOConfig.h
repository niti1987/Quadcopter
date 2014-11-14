/*
 *  rimGraphicsIOConfig.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 5/16/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_IO_CONFIG_H
#define INCLUDE_RIM_GRAPHICS_IO_CONFIG_H


#include "../rimGraphicsConfig.h"


#include "../rimGraphicsUtilities.h"
#include "../rimGraphicsBase.h"
#include "../rimGraphicsObjects.h"
#include "../rimGraphicsScenes.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GRAPHICS_IO_NAMESPACE_START
	#define RIM_GRAPHICS_IO_NAMESPACE_START		RIM_GRAPHICS_NAMESPACE_START namespace io {
#endif




#ifndef RIM_GRAPHICS_IO_NAMESPACE_END
	#define RIM_GRAPHICS_IO_NAMESPACE_END		}; RIM_GRAPHICS_NAMESPACE_END
#endif




//##########################################################################################
//**************************  Start Rim Graphics IO Namespace  *****************************
RIM_GRAPHICS_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




using namespace rim::graphics::shapes;

using rim::graphics::objects::GraphicsObject;
using rim::graphics::objects::ObjectCuller;

using rim::graphics::lights::Light;
using rim::graphics::lights::LightCuller;

using rim::graphics::cameras::Camera;

using rim::graphics::scenes::GraphicsScene;

using rim::graphics::devices::GraphicsContext;




//##########################################################################################
//**************************  End Rim Graphics IO Namespace  *******************************
RIM_GRAPHICS_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_IO_CONFIG_H
