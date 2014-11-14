/*
 *  rimGraphicsSceneRendererConfiguration.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 7/8/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SCENE_RENDERER_CONFIGURATION_H
#define INCLUDE_RIM_GRAPHICS_SCENE_RENDERER_CONFIGURATION_H


#include "rimGraphicsRenderersConfig.h"


#include "rimGraphicsSceneRendererFlags.h"


//##########################################################################################
//**********************  Start Rim Graphics Renderers Namespace  **************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates the configuration for a scene renderer.
class SceneRendererConfiguration
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a scene renderer configuration with the default configuration.
			RIM_INLINE SceneRendererConfiguration()
				:	flags( DEFAULT_FLAGS ),
					maxNumSpotLights( math::max<Size>() ),
					maxNumPointLights( math::max<Size>() ),
					maxNumDirectionalLights( math::max<Size>() ),
					maxNumShadows( math::max<Size>() ),
					lightDebugColor( 1.0f, 1.0f, 0.0f, 1.0f ),
					cameraDebugColor( 0.0f, 0.0f, 1.0f, 1.0f ),
					objectDebugColor( 1.0f, 1.0f, 1.0f, 1.0f ),
					shapeDebugColor( 0.0f, 1.0f, 1.0f, 1.0f ),
					boundingBoxDebugColor( 1.0f, 0.0f, 0.0f, 1.0f )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// An object containing boolean configuration flags for a scene renderer.
			SceneRendererFlags flags;
			
			
			/// The maximum number of spot lights that can be used to illuminate an object.
			Size maxNumSpotLights;
			
			
			/// The maximum number of point lights that can be used to illuminate an object.
			Size maxNumPointLights;
			
			
			/// The maximum number of directional lights that can be used to illuminate an object.
			Size maxNumDirectionalLights;
			
			
			/// The maximum number of light shadows that can be rendered for a scene.
			Size maxNumShadows;
			
			
			/// The color to use when drawing debug info for lights.
			Color4f lightDebugColor;
			
			
			/// The color to use when drawing debug info for cameras.
			Color4f cameraDebugColor;
			
			
			/// The color to use when drawing debug info for objects.
			Color4f objectDebugColor;
			
			
			/// The color to use when drawing debug info for shapes.
			Color4f shapeDebugColor;
			
			
			/// The color to use when drawing debug bounding boxes.
			Color4f boundingBoxDebugColor;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// An integer containing the OR-ed default scene renderer flags.
			static const UInt32 DEFAULT_FLAGS = SceneRendererFlags::OBJECTS_ENABLED | SceneRendererFlags::LIGHTS_ENABLED |
												SceneRendererFlags::SHADOWS_ENABLED;
			
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Renderers Namespace  ****************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SCENE_RENDERER_CONFIGURATION_H
