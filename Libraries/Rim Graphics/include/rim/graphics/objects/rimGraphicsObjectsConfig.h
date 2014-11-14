/*
 *  rimGraphicsObjectsConfig.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 5/16/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_OBJECTS_CONFIG_H
#define INCLUDE_RIM_GRAPHICS_OBJECTS_CONFIG_H


#include "../rimGraphicsConfig.h"


#include "../rimGraphicsShapes.h"
#include "../rimGraphicsUtilities.h"
#include "../rimGraphicsCameras.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GRAPHICS_OBJECTS_NAMESPACE_START
	#define RIM_GRAPHICS_OBJECTS_NAMESPACE_START		RIM_GRAPHICS_NAMESPACE_START namespace objects {
#endif




#ifndef RIM_GRAPHICS_OBJECTS_NAMESPACE_END
	#define RIM_GRAPHICS_OBJECTS_NAMESPACE_END		}; RIM_GRAPHICS_NAMESPACE_END
#endif




//##########################################################################################
//************************  Start Rim Graphics Objects Namespace  **************************
RIM_GRAPHICS_OBJECTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


using rim::graphics::shapes::GraphicsShape;
using rim::graphics::shapes::MeshChunk;
using rim::graphics::util::BoundingCone;
using rim::graphics::cameras::ViewVolume;



//##########################################################################################
//************************  End Rim Graphics Objects Namespace  ****************************
RIM_GRAPHICS_OBJECTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_OBJECTS_CONFIG_H
