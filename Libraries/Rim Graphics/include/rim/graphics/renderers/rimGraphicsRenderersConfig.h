/*
 *  rimGraphicsRenderersConfig.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 5/16/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_RENDERERS_CONFIG_H
#define INCLUDE_RIM_GRAPHICS_RENDERERS_CONFIG_H


#include "../rimGraphicsConfig.h"


#include "../rimGraphicsBase.h"
#include "../rimGraphicsScenes.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GRAPHICS_RENDERERS_NAMESPACE_START
	#define RIM_GRAPHICS_RENDERERS_NAMESPACE_START		RIM_GRAPHICS_NAMESPACE_START namespace renderers {
#endif




#ifndef RIM_GRAPHICS_RENDERERS_NAMESPACE_END
	#define RIM_GRAPHICS_RENDERERS_NAMESPACE_END		}; RIM_GRAPHICS_NAMESPACE_END
#endif




//##########################################################################################
//**********************  Start Rim Graphics Renderers Namespace  **************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



using rim::graphics::shapes::Skeleton;
using rim::graphics::shapes::MeshChunk;
using namespace rim::graphics::lights;
using namespace rim::graphics::cameras;
using namespace rim::graphics::scenes;
using namespace rim::graphics::objects;
using rim::graphics::devices::GraphicsContext;
using rim::graphics::textures::ShadowMap;



//##########################################################################################
//**********************  End Rim Graphics Renderers Namespace  ****************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_RENDERERS_CONFIG_H
