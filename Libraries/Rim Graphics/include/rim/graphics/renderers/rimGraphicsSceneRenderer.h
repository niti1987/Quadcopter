/*
 *  rimGraphicsSceneRenderer.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 3/21/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SCENE_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_SCENE_RENDERER_H


#include "rimGraphicsRenderersConfig.h"


#include "rimGraphicsRenderer.h"
#include "rimGraphicsViewportLayout.h"
#include "rimGraphicsSceneRendererFlags.h"
#include "rimGraphicsSceneRendererConfiguration.h"


//##########################################################################################
//**********************  Start Rim Graphics Renderers Namespace  **************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An interface for classes that draw graphics scenes.
class SceneRenderer : public Renderer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Viewport Layout Accessor Methods
			
			
			
			
			/// Return a pointer to the viewport layout that is currently being rendered.
			virtual Pointer<ViewportLayout> getViewportLayout() const = 0;
			
			
			
			
			/// Set a pointer to the viewport layout that should be rendered.
			virtual void setViewportLayout( const Pointer<ViewportLayout>& newViewportLayout ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Configuration Accessor Methods
			
			
			
			
			/// Return a reference to an object which contains the configuration of the scene renderer.
			RIM_INLINE SceneRendererConfiguration& getConfiguration()
			{
				return configuration;
			}
			
			
			
			
			/// Return an object which contains the configuration of the scene renderer.
			RIM_INLINE const SceneRendererConfiguration& getConfiguration() const
			{
				return configuration;
			}
			
			
			
			
			/// Set an object which contains the configuration of the scene renderer.
			RIM_INLINE void setConfiguration( const SceneRendererConfiguration& newConfiguration )
			{
				configuration = newConfiguration;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flags Accessor Methods
			
			
			
			
			/// Return a reference to an object which contains boolean parameters of the scene renderer.
			RIM_INLINE SceneRendererFlags& getFlags()
			{
				return configuration.flags;
			}
			
			
			
			
			/// Return an object which contains boolean parameters of the scene renderer.
			RIM_INLINE const SceneRendererFlags& getFlags() const
			{
				return configuration.flags;
			}
			
			
			
			
			/// Set an object which contains boolean parameters of the scene renderer.
			RIM_INLINE void setFlags( const SceneRendererFlags& newFlags )
			{
				configuration.flags = newFlags;
			}
			
			
			
			
			/// Return whether or not the specified boolan flag is set for this scene renderer.
			RIM_INLINE Bool flagIsSet( SceneRendererFlags::Flag flag ) const
			{
				return configuration.flags.isSet( flag );
			}
			
			
			
			
			/// Set whether or not the specified boolan flag is set for this scene renderer.
			RIM_INLINE void setFlag( SceneRendererFlags::Flag flag, Bool newIsSet = true )
			{
				configuration.flags.set( flag, newIsSet );
			}
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Data Members
			
			
			
			
			/// An object containing the configuration for this scene renderer.
			SceneRendererConfiguration configuration;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Renderers Namespace  ****************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SCENE_RENDERER_H
