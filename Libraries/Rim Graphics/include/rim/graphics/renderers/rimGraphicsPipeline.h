/*
 *  rimGraphicsPipeline.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/22/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_PIPELINE_H
#define INCLUDE_RIM_GRAPHICS_PIPELINE_H


#include "rimGraphicsRenderersConfig.h"


#include "rimGraphicsRenderer.h"


//##########################################################################################
//**********************  Start Rim Graphics Renderers Namespace  **************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that performs a sequence of rendering operations.
class GraphicsPipeline : public Renderer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new graphics pipeline with no renderers.
			GraphicsPipeline();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Rendering Method
			
			
			
			
			/// Render each of the renderers in order for this pipeline.
			virtual void render();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Renderer Accessor Methods
			
			
			
			
			/// Return the number of renderers that this graphics pipeline renders.
			RIM_INLINE Size getRendererCount() const
			{
				return renderers.getSize();
			}
			
			
			
			
			/// Return a pointer to the renderer at the specified index in this pipeline.
			RIM_INLINE const Pointer<Renderer>& getRenderer( Index rendererIndex ) const
			{
				return renderers[rendererIndex];
			}
			
			
			
			
			/// Add a new renderer to this renderer that is rendered after the previously added renderers.
			/**
			  * The method returns whether or not the renderer was successfully added.
			  * The method fails if the renderer is NULL or is invalid.
			  */
			Bool addRenderer( const Pointer<Renderer>& newRenderer );
			
			
			
			
			/// Insert a new renderer to this renderer that is rendered at the specified index.
			/**
			  * The method returns whether or not the renderer was successfully added.
			  * The method fails if the renderer is NULL or is invalid.
			  */
			Bool insertRenderer( Index rendererIndex, const Pointer<Renderer>& newRenderer );
			
			
			
			
			/// Remove the renderer at the specified index in this graphics pipeline.
			/**
			  * The method returns whether or not the renderer was successfully removed.
			  */
			Bool removeRenderer( Index rendererIndex );
			
			
			
			
			/// Remove the specified renderer from this graphics pipeline.
			/**
			  * The method returns whether or not the renderer was successfully removed.
			  */
			Bool removeRenderer( const Renderer* renderer );
			
			
			
			
			/// Remove all renderers from this post processes renderer.
			void clearRenderers();
			
			
			
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the renderers that are rendered in order by this pipeline.
			ArrayList< Pointer<Renderer> > renderers;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Renderers Namespace  ****************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_PIPELINE_H
