/*
 *  rimGraphics.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 5/8/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_H
#define INCLUDE_RIM_GRAPHICS_H


#include "graphics/rimGraphicsConfig.h"


// Image and Texture classes
#include "graphics/rimGraphicsUtilities.h"

// Geometry data buffer classes
#include "graphics/rimGraphicsBuffers.h"

// Shader classes
#include "graphics/rimGraphicsShaders.h"

// Texture classes
#include "graphics/rimGraphicsTextures.h"

// Camera classes
#include "graphics/rimGraphicsCameras.h"

// Object class
#include "graphics/rimGraphicsObjects.h"

// Shape classes
#include "graphics/rimGraphicsShapes.h"

// Light classes
#include "graphics/rimGraphicsLights.h"

// Animation classes
#include "graphics/rimGraphicsAnimation.h"

// Scene classes
#include "graphics/rimGraphicsScenes.h"

// Device classes
#include "graphics/rimGraphicsDevices.h"

// Renderer classes
#include "graphics/rimGraphicsRenderers.h"

// I/O classes
#include "graphics/rimGraphicsIO.h"

// Asset classes
#include "graphics/rimGraphicsAssets.h"



//##########################################################################################
//**************************  Start Rim Graphics Namespace  ********************************
RIM_GRAPHICS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


using namespace rim::graphics::util;
using namespace rim::graphics::shaders;
using namespace rim::graphics::textures;
using namespace rim::graphics::materials;
using namespace rim::graphics::buffers;
using namespace rim::graphics::shapes;
using namespace rim::graphics::cameras;
using namespace rim::graphics::lights;
using namespace rim::graphics::objects;
using namespace rim::graphics::scenes;
using namespace rim::graphics::renderers;
using namespace rim::graphics::devices;
using namespace rim::graphics::io;
using namespace rim::graphics::assets;
using namespace rim::graphics::animation;


//##########################################################################################
//**************************  End Rim Graphics Namespace  **********************************
RIM_GRAPHICS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_H
