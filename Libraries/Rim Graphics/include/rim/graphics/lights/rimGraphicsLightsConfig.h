/*
 *  rimGraphicsLightsConfig.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 5/16/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_LIGHTS_CONFIG_H
#define INCLUDE_RIM_GRAPHICS_LIGHTS_CONFIG_H


#include "../rimGraphicsConfig.h"


#include "../rimGraphicsUtilities.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GRAPHICS_LIGHTS_NAMESPACE_START
	#define RIM_GRAPHICS_LIGHTS_NAMESPACE_START		RIM_GRAPHICS_NAMESPACE_START namespace lights {
#endif




#ifndef RIM_GRAPHICS_LIGHTS_NAMESPACE_END
	#define RIM_GRAPHICS_LIGHTS_NAMESPACE_END		}; RIM_GRAPHICS_NAMESPACE_END
#endif




//##########################################################################################
//************************  Start Rim Graphics Lights Namespace  ***************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



using rim::graphics::util::ViewVolume;
using rim::graphics::util::BoundingCone;



//##########################################################################################
//************************  End Rim Graphics Lights Namespace  *****************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_LIGHTS_CONFIG_H
