/*
 *  rimGraphicsRenderer.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/27/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_RENDERER_H


#include "rimGraphicsRenderersConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Renderers Namespace  **************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which serves as a basic interface for a high-level graphcs renderer.
class Renderer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a renderer object.
			virtual ~Renderer()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Render Method
			
			
			
			
			/// Do the main rendering for this renderer.
			/**
			  * The default implementation has no effect. Subclasses can override
			  * this method to do their main rendering operations. The actual function of this
			  * method is defined by the subclass.
			  */
			virtual void render()
			{
			}
			
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Renderers Namespace  ****************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_RENDERER_H
