/*
 *  rimGraphicsShapesConfig.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/28/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHAPES_CONFIG_H
#define INCLUDE_RIM_GRAPHICS_SHAPES_CONFIG_H


#include "../rimGraphicsConfig.h"


#include "../rimGraphicsUtilities.h"
#include "../rimGraphicsMaterials.h"
#include "../rimGraphicsBuffers.h"
#include "../rimGraphicsCameras.h"
#include "../devices/rimGraphicsContext.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GRAPHICS_SHAPES_NAMESPACE_START
	#define RIM_GRAPHICS_SHAPES_NAMESPACE_START		RIM_GRAPHICS_NAMESPACE_START namespace shapes {
#endif




#ifndef RIM_GRAPHICS_SHAPES_NAMESPACE_END
	#define RIM_GRAPHICS_SHAPES_NAMESPACE_END		}; RIM_GRAPHICS_NAMESPACE_END
#endif




//##########################################################################################
//***********************  Start Rim Graphics Shapes Namespace  ****************************
RIM_GRAPHICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


using rim::graphics::util::AttributeType;

using namespace rim::graphics::buffers;
using namespace rim::graphics::materials;

using rim::graphics::cameras::Camera;

using rim::graphics::devices::GraphicsContext;


//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHAPES_CONFIG_H
