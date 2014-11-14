/*
 *  rimGraphicsAssetsConfig.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/11/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_ASSETS_CONFIG_H
#define INCLUDE_RIM_GRAPHICS_ASSETS_CONFIG_H


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




#ifndef RIM_GRAPHICS_ASSETS_NAMESPACE_START
	#define RIM_GRAPHICS_ASSETS_NAMESPACE_START		RIM_GRAPHICS_NAMESPACE_START namespace assets {
#endif




#ifndef RIM_GRAPHICS_ASSETS_NAMESPACE_END
	#define RIM_GRAPHICS_ASSETS_NAMESPACE_END		}; RIM_GRAPHICS_NAMESPACE_END
#endif




//##########################################################################################
//***********************  Start Rim Graphics Assets Namespace  ****************************
RIM_GRAPHICS_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


using rim::assets::AssetType;
using rim::assets::AssetTypeTranscoder;
using rim::assets::AssetTranscoder;
using rim::assets::AssetObject;


using rim::graphics::scenes::GraphicsScene;
using rim::graphics::objects::GraphicsObject;
using rim::graphics::objects::GraphicsObjectFlags;

using rim::graphics::materials::GenericMaterial;
using rim::graphics::materials::GenericMaterialTechnique;

using rim::graphics::shaders::GenericShaderPass;

using rim::graphics::cameras::Camera;
using rim::graphics::cameras::OrthographicCamera;
using rim::graphics::cameras::PerspectiveCamera;


using rim::graphics::lights::Light;
using rim::graphics::lights::LightFlags;
using rim::graphics::lights::SpotLight;
using rim::graphics::lights::PointLight;
using rim::graphics::lights::DirectionalLight;


using rim::graphics::shapes::GraphicsShape;
using rim::graphics::shapes::GenericMeshShape;
using rim::graphics::shapes::GenericMeshGroup;
using rim::graphics::shapes::GenericSphereShape;
using rim::graphics::shapes::GenericCylinderShape;
using rim::graphics::shapes::GenericCapsuleShape;
using rim::graphics::shapes::GenericBoxShape;



//##########################################################################################
//***********************  End Rim Graphics Assets Namespace  ******************************
RIM_GRAPHICS_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_ASSETS_CONFIG_H
