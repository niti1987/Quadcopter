/*
 *  rimGraphicsShadersConfig.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/28/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADERS_CONFIG_H
#define INCLUDE_RIM_GRAPHICS_SHADERS_CONFIG_H


#include "../rimGraphicsConfig.h"


#include "../rimGraphicsUtilities.h"
#include "../rimGraphicsTextures.h"
#include "../rimGraphicsBuffers.h"
#include "../devices/rimGraphicsContextObject.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GRAPHICS_SHADERS_NAMESPACE_START
	#define RIM_GRAPHICS_SHADERS_NAMESPACE_START		RIM_GRAPHICS_NAMESPACE_START namespace shaders {
#endif




#ifndef RIM_GRAPHICS_SHADERS_NAMESPACE_END
	#define RIM_GRAPHICS_SHADERS_NAMESPACE_END		}; RIM_GRAPHICS_NAMESPACE_END
#endif




//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




using rim::graphics::util::AttributeType;
using rim::graphics::util::AttributeValue;
using rim::graphics::util::RenderMode;
using rim::graphics::util::RenderFlags;


using rim::graphics::textures::Texture;
using rim::graphics::textures::GenericTexture;
using rim::graphics::textures::TextureFormat;
using rim::graphics::textures::TextureUsage;
using rim::graphics::textures::TextureType;


using rim::graphics::buffers::GenericBuffer;
using rim::graphics::buffers::VertexBuffer;
using rim::graphics::buffers::VertexUsage;


using rim::graphics::devices::ContextObject;




/// A type which represents the location of a shader variable within a linked shader program.
typedef UInt32 ShaderVariableLocation;




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADERS_CONFIG_H
