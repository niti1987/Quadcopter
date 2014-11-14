/*
 *  rimGraphicsMaterialsConfig.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/28/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_MATERIALS_CONFIG_H
#define INCLUDE_RIM_GRAPHICS_MATERIALS_CONFIG_H


#include "../rimGraphicsConfig.h"


#include "../rimGraphicsShaders.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GRAPHICS_MATERIALS_NAMESPACE_START
	#define RIM_GRAPHICS_MATERIALS_NAMESPACE_START		RIM_GRAPHICS_NAMESPACE_START namespace materials {
#endif




#ifndef RIM_GRAPHICS_MATERIALS_NAMESPACE_END
	#define RIM_GRAPHICS_MATERIALS_NAMESPACE_END		}; RIM_GRAPHICS_NAMESPACE_END
#endif




//##########################################################################################
//**********************  Start Rim Graphics Materials Namespace  **************************
RIM_GRAPHICS_MATERIALS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


using rim::graphics::shaders::ShaderPass;
using rim::graphics::shaders::GenericShaderPass;


//##########################################################################################
//**********************  End Rim Graphics Materials Namespace  ****************************
RIM_GRAPHICS_MATERIALS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_MATERIALS_CONFIG_H
