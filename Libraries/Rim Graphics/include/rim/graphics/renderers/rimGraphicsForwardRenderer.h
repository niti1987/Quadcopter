/*
 *  rimGraphicsForwardRenderer.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 5/16/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_FORWARD_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_FORWARD_RENDERER_H


#include "rimGraphicsRenderersConfig.h"


#include "rimGraphicsSceneRenderer.h"
#include "rimGraphicsShadowMapRenderer.h"
#include "rimGraphicsImmediateRenderer.h"


//##########################################################################################
//**********************  Start Rim Graphics Renderers Namespace  **************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that uses forward rendering techniques to draw a graphics scene.
class ForwardRenderer : public SceneRenderer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a forward renderer for the specified context with no viewport layout to render.
			ForwardRenderer( const Pointer<GraphicsContext>& newContext );
			
			
			
			
			/// Create a forward renderer which renderers the specified viewport layout.
			ForwardRenderer( const Pointer<GraphicsContext>& newContext,
							const Pointer<ViewportLayout>& newViewportLayout );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Render Method
			
			
			
			
			/// Render all of the cameras in this renderer's scene to the current framebuffer.
			virtual void render();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Graphics Context Accessor Methods
			
			
			
			
			/// Return a pointer to the graphics context that is currently being used to render with.
			RIM_INLINE const Pointer<GraphicsContext>& getContext() const
			{
				return context;
			}
			
			
			
			
			/// Set a pointer to the graphics context that should be used to render with.
			RIM_INLINE void setContext( const Pointer<GraphicsContext>& newContext )
			{
				context = newContext;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Viewport Layout Accessor Methods
			
			
			
			
			/// Return a pointer to the viewport layout that is currently being rendered.
			virtual Pointer<ViewportLayout> getViewportLayout() const;
			
			
			
			
			/// Set a pointer to the viewport layout that should be rendered.
			virtual void setViewportLayout( const Pointer<ViewportLayout>& newViewportLayout );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			class MeshChunkDepth
			{
				public:
					
					RIM_INLINE MeshChunkDepth( const MeshChunk* newChunk, const MaterialTechnique* newTechnique, Real newDepth )
						:	chunk( newChunk ),
							technique( newTechnique ),
							depth( newDepth )
					{
					}
					
					
					RIM_INLINE Bool operator < ( const MeshChunkDepth& other ) const
					{
						return depth > other.depth;
					}
					
					
					/// A pointer to the chunk that has this depth.
					const MeshChunk* chunk;
					
					/// A pointer to the material technique used to render this chunk.
					const MaterialTechnique* technique;
					
					/// The distance away from the camera along the view direction of this chunk.
					Real depth;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			RIM_FORCE_INLINE void drawMeshChunk( const MeshChunk& chunk, const MaterialTechnique& technique,
												const Pointer<LightCuller>& lightCuller, const Pointer<Camera>& camera );
			
			
			
			
			
			/// Fill this object's global attribute set with data needed for the specified shader pass.
			void fillGlobalAttributeSet( const ShaderPass& shaderPass, const MeshChunk& chunk,
										const VertexBufferList* vertexBuffers, const Pointer<Camera>& camera );
			
			
			
			
			
			void drawDebug( const ViewportLayout::CameraView& cameraView );
			
			
			
			static void drawDebugObjects( ImmediateRenderer& immediate, const GraphicsObject& object );
			static void drawDebugShapes( ImmediateRenderer& immediate, const GraphicsObject& object );
			static void drawDebugBoundingBoxes( ImmediateRenderer& immediate, const GraphicsObject& object );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the graphics context which this renderer is rendering to.
			Pointer<GraphicsContext> context;
			
			
			
			
			/// The set of current global shader binding data.
			ShaderBindingData globalBindingData;
			
			
			
			
			/// A temporary buffer of visible lights in the scene.
			LightBuffer visibleLights;
			
			
			
			
			/// A temporary list of mesh chunks in the scene.
			ArrayList<MeshChunk> meshChunks;
			
			
			
			
			/// A temporary list of transparent mesh chunks indices in the scene.
			ArrayList<MeshChunkDepth> transparentChunks;
			
			
			
			
			/// An object which handles rendering shadow maps for this renderer.
			ShadowMapRenderer shadowMapRenderer;
			
			
			
			
			/// An object that handles rendering debug info.
			ImmediateRenderer immediateRenderer;
			
			
			
			
			/// A pointer to the viewport layout that is currently being rendered.
			Pointer<ViewportLayout> viewportLayout;
			
			
			
			
			/// A matrix used as temporary rendering state representing the current projection matrix.
			Matrix4 projectionMatrix;
			
			
			
			
			/// A matrix used as temporary rendering state representing the current camera transformation matrix.
			Matrix4 cameraTransformMatrix;
			
			
			
			
			/// A matrix used as temporary rendering state representing the current inverse camera transformation matrix.
			Matrix4 inverseCameraTransformMatrix;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Renderers Namespace  ****************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_FORWARD_RENDERER_H
