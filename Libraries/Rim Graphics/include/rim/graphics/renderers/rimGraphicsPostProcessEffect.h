/*
 *  rimGraphicsPostProcessEffect.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/22/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_POST_PROCESS_EFFECT_H
#define INCLUDE_RIM_GRAPHICS_POST_PROCESS_EFFECT_H


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
/// A class that encapsulates the information needed for rendering a post-process effect.
/**
  * A post-process effect is defined by a shader pass that contains the buffers,
  * textures, and shaders needed for rendering, a range of vertex indices in those buffers,
  * and a viewport for the effect.
  *
  * A post process effect is by default rendered to the main render target, but
  * can optionally be rendered to a different render target if one is specified.
  */
class PostProcessEffect
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a post process effect that renders the specified shader pass to the main framebuffer.
			RIM_INLINE PostProcessEffect( const Pointer<ShaderPass>& newShaderPass,
											const BufferRange& newBufferRange )
				:	shaderPass( newShaderPass ),
					bufferRange( newBufferRange )
			{
			}
			
			
			
			
			/// Create a post process effect that renders the specified shader pass to the given framebuffer target.
			RIM_INLINE PostProcessEffect( const Pointer<Framebuffer>& newTarget,
										const Pointer<ShaderPass>& newShaderPass,
										const BufferRange& newBufferRange )
				:	target( newTarget ),
					shaderPass( newShaderPass ),
					bufferRange( newBufferRange )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Pass Accessor Methods
			
			
			
			
			/// Return a pointer to the shader pass that is used to render this post process effect.
			RIM_INLINE const Pointer<ShaderPass>& getShaderPass() const
			{
				return shaderPass;
			}
			
			
			
			
			/// Set a pointer to the shader pass that is used to render this post process effect.
			/**
			  * The method returns whether or not the specified shader pass is valid and can be used
			  * for rendering.
			  */
			RIM_INLINE Bool setShaderPass( const Pointer<ShaderPass>& newShaderPass )
			{
				shaderPass = newShaderPass;
				
				return shaderPass.isSet();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Range Accessor Methods
			
			
			
			
			/// Return a reference to the buffer range for this mesh chunk.
			/**
			  * If the mesh chunk has an index buffer, the valid range refers to the indices
			  * which should be used when drawing the chunk. Otherwise, the range refers
			  * to the valid contiguous range of vertices to use.
			  */
			RIM_FORCE_INLINE const BufferRange& getBufferRange() const
			{
				return bufferRange;
			}
			
			
			
			
			/// Set the buffer range for this mesh chunk.
			/**
			  * If the mesh chunk has an index buffer, the valid range refers to the indices
			  * which should be used when drawing the chunk. Otherwise, the range refers
			  * to the valid contiguous range of vertices to use.
			  */
			RIM_FORCE_INLINE void setBufferRange( const BufferRange& newBufferRange )
			{
				bufferRange = newBufferRange;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Render Target Accessor Methods
			
			
			
			
			/// Return a pointer to the render target that is used to output this post process effect.
			/**
			  * If the pointer is NULL, the post process renderer uses the main render target instead.
			  */
			RIM_INLINE const Pointer<Framebuffer>& getTarget() const
			{
				return target;
			}
			
			
			
			
			/// Set a pointer to the render target that is used to output this post process effect.
			/**
			  * If the pointer is NULL, the post process renderer uses the main render target instead.
			  */
			RIM_INLINE void setTarget( const Pointer<Framebuffer>& newTarget )
			{
				target = newTarget;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Viewport Accessor Methods
			
			
			
			
			/// Return the viewport on the screen where the shader pass should be rendered.
			/**
			  * The shader pass is rendered to this rectangular area on the screen.
			  * The default viewport covers the entire screen.
			  */
			RIM_INLINE const Viewport& getViewport() const
			{
				return viewport;
			}
			
			
			
			
			/// Set the viewport on the screen where the shader pass should be rendered.
			/**
			  * The shader pass is rendered to this rectangular area on the screen.
			  * The default viewport covers the entire screen.
			  */
			RIM_INLINE void setViewport( const Viewport& newViewport )
			{
				viewport = newViewport;
			}
			
			
			
			
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The shader pass that is being used to render this post process effect.
			Pointer<ShaderPass> shaderPass;
			
			
			
			
			/// An object describing the range of vertices to use from the shader pass.
			BufferRange bufferRange;
			
			
			
			
			/// A pointer to the framebuffer render target for this post process renderer, or NULL.
			Pointer<Framebuffer> target;
			
			
			
			
			/// The viewport on the screen where the shader pass should be rendered.
			/**
			  * The shader pass is rendered to this rectangular area on the screen.
			  * The default viewport covers the entire screen.
			  */
			Viewport viewport;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Renderers Namespace  ****************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_POST_PROCESS_EFFECT_H
