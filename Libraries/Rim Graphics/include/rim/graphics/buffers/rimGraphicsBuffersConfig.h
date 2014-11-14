/*
 *  rimGraphicsBuffersConfig.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/28/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_BUFFERS_CONFIG_H
#define INCLUDE_RIM_GRAPHICS_BUFFERS_CONFIG_H


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




#ifndef RIM_GRAPHICS_BUFFERS_NAMESPACE_START
	#define RIM_GRAPHICS_BUFFERS_NAMESPACE_START		RIM_GRAPHICS_NAMESPACE_START namespace buffers {
#endif




#ifndef RIM_GRAPHICS_BUFFERS_NAMESPACE_END
	#define RIM_GRAPHICS_BUFFERS_NAMESPACE_END		}; RIM_GRAPHICS_NAMESPACE_END
#endif




//##########################################################################################
//***********************  Start Rim Graphics Buffers Namespace  ***************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


using rim::graphics::util::AttributeType;
using rim::graphics::util::AttributeValue;


using rim::graphics::devices::ContextObject;


//##########################################################################################
//***********************  End Rim Graphics Buffers Namespace  *****************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_BUFFERS_CONFIG_H
