/*
 *  rimGraphicsPostProcessRenderer.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/22/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_POST_PROCESS_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_POST_PROCESS_RENDERER_H


#include "rimGraphicsRenderersConfig.h"


#include "rimGraphicsRenderer.h"
#include "rimGraphicsPostProcessEffect.h"


//##########################################################################################
//**********************  Start Rim Graphics Renderers Namespace  **************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that renders a sequence of post-process effects.
class PostProcessRenderer : public Renderer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new post process renderer for the given context with no effects to render.
			PostProcessRenderer( const Pointer<GraphicsContext>& newContext );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Rendering Method
			
			
			
			
			/// Render the post-process effects for this renderer.
			virtual void render();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Effect Accessor Methods
			
			
			
			
			/// Return the number of post-process effects that this post process renderer renders.
			RIM_INLINE Size getEffectCount() const
			{
				return effects.getSize();
			}
			
			
			
			
			/// Return a pointer to the post-process effect at the specified index in this renderer.
			RIM_INLINE const Pointer<PostProcessEffect>& getEffect( Index effectIndex ) const
			{
				return effects[effectIndex];
			}
			
			
			
			
			/// Add a new post-process effect to this renderer that is rendered after the previously added effects.
			/**
			  * The method returns whether or not the effect was successfully added.
			  * The method fails if the effect is NULL or is invalid.
			  */
			Bool addEffect( const Pointer<PostProcessEffect>& newEffect );
			
			
			
			
			/// Insert a new post-process effect to this renderer that is rendered at the specified index.
			/**
			  * The method returns whether or not the effect was successfully added.
			  * The method fails if the effect is NULL or is invalid.
			  */
			Bool insertEffect( Index effectIndex, const Pointer<PostProcessEffect>& newEffect );
			
			
			
			
			/// Remove the effect at the specified index in this post process renderer.
			/**
			  * The method returns whether or not the effect was successfully removed.
			  */
			Bool removeEffect( Index effectIndex );
			
			
			
			
			/// Remove the specified effect from this post process renderer.
			/**
			  * The method returns whether or not the effect was successfully removed.
			  */
			Bool removeEffect( const PostProcessEffect* effect );
			
			
			
			
			/// Remove all effects from this post processes renderer.
			void clearEffects();
			
			
			
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the graphics context this post process renderer is using.
			Pointer<GraphicsContext> context;
			
			
			
			
			/// A list of the post process effects that should be rendered by this renderer, in order.
			ArrayList< Pointer<PostProcessEffect> > effects;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Renderers Namespace  ****************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_POST_PROCESS_RENDERER_H
