/*
 *  rimGraphicsImmediateRenderer.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 12/4/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_IMMEDIATE_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_IMMEDIATE_RENDERER_H


#include "rimGraphicsRenderersConfig.h"


#include "rimGraphicsRenderer.h"
#include "../rimGraphicsShapes.h"


//##########################################################################################
//**********************  Start Rim Graphics Renderers Namespace  **************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that emulates immediate-mode graphics rendering like older graphics APIs.
/**
  * An immediate renderer uses an internal OpenGL-like state machine build on top
  * of modern graphics rendering techniques. This style of rendering can be useful
  * for easily drawing debug information or quick prototyping. This renderer should
  * not be used for performance-sensitive rendering.
  */
class ImmediateRenderer : public Renderer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new immediate-mode renderer with no valid context to render to.
			ImmediateRenderer();
			
			
			
			
			/// Create a new immediate-mode renderer which uses the specified graphics context.
			ImmediateRenderer( const Pointer<GraphicsContext>& newContext );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this immediate renderer and release all associated resources.
			virtual ~ImmediateRenderer();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Context Accessor Methods
			
			
			
			
			/// Return a pointer to the graphics context which is being used to draw geometry.
			/**
			  * This pointer is NULL if the immediate renderer does not have a valid context.
			  */
			RIM_INLINE const Pointer<GraphicsContext>& getContext() const
			{
				return context;
			}
			
			
			
			
			/// Change the graphics context that should be used to draw geometry.
			/**
			  * This method resets any internal context-specific rendering state but keeps
			  * the previous drawing state (viewports, transformations, colors, normals, etc).
			  *
			  * The method returns whether or not the immediate-mode renderer was reinitialized
			  * successfully. A NULL or invalid context is allowed but will cause the method to return
			  * FALSE, causing the renderer to be unusable.
			  */
			Bool setContext( const Pointer<GraphicsContext>& newContext );
			
			
			
			
			/// Ensure that the context has the current rendering state for this immediate renderer.
			/**
			  * This method should be called before doing any immediate-mode rendering so that
			  * the context is ensured to have the same state as what is stored locally
			  * as part of the immediate-mode renderer. This information consists of the
			  * viewport, scissor viewport, and render mode attributes.
			  */
			void synchronizeContext();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Pass Accessor Methods
			
			
			
			
			/// Return the current shader pass for the renderer.
			RIM_INLINE const Pointer<ShaderPass>& getShaderPass() const
			{
				return shaderPass;
			}
			
			
			
			
			/// Replace the current shader pass for the renderer.
			/**
			  * This method may cause previously buffered drawing commands to be flushed to the screen.
			  */
			void setShaderPass( const Pointer<ShaderPass>& newShaderPass );
			
			
			
			
			/// Push the current shader pass onto the shader pass stack. The current shader pass is unchanged.
			/**
			  * Each call to pushShaderPass() should be paired with a call to popShaderPass(),
			  * otherwise the stack will continue to grow and produce undesired behavior.
			  */
			void pushShaderPass();
			
			
			
			
			/// Remove the last shader pass from the shader pass stack and make it the current shader pass.
			/**
			  * If there are no shader passes on the stack, the method sets the current shader pass
			  * to be the default shader pass.
			  */
			void popShaderPass();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Render Mode Accessor Methods
			
			
			
			
			/// Return the render mode object for the current shader pass.
			RIM_INLINE RenderMode& getRenderMode()
			{
				return shaderPass->getRenderMode();
			}
			
			
			
			
			/// Return the render mode object for the current shader pass.
			RIM_INLINE const RenderMode& getRenderMode() const
			{
				return shaderPass->getRenderMode();
			}
			
			
			
			
			/// Set the render mode object for the current shader pass.
			RIM_INLINE void setRenderMode( const RenderMode& newRenderMode ) const
			{
				shaderPass->setRenderMode( newRenderMode );
			}
			
			
			
			
			/// Push the current shader pass onto the shader pass stack. The current shader pass is unchanged.
			/**
			  * Each call to pushShaderPass() should be paired with a call to popShaderPass(),
			  * otherwise the stack will continue to grow and produce undesired behavior.
			  */
			void pushRenderMode();
			
			
			
			
			/// Remove the last render mode from the render mode stack and make the current shader pass use it.
			/**
			  * If there are no render modes on the stack, the method sets the current shader pass's mode
			  * to be the default render mode.
			  */
			void popRenderMode();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Viewport Accessor Methods
			
			
			
			
			/// Return the current viewport for the renderer.
			RIM_INLINE const Viewport& getViewport() const
			{
				return viewport;
			}
			
			
			
			
			/// Replace the current viewport for the renderer.
			/**
			  * This method changes the context's viewport if the context is valid
			  * and replaces the locally-stored current viewport regardless of whether
			  * or not the context is valid.
			  *
			  * This method may cause previously buffered drawing commands to be flushed to the screen.
			  */
			void setViewport( const Viewport& newViewport );
			
			
			
			
			/// Replace the current viewport for the renderer.
			/**
			  * This method changes the context's viewport if the context is valid
			  * and replaces the locally-stored current viewport regardless of whether
			  * or not the context is valid.
			  *
			  * This method may cause previously buffered drawing commands to be flushed to the screen.
			  */
			void setViewport( const AABB2f& newViewport )
			{
				this->setViewport( Viewport( newViewport ) );
			}
			
			
			
			
			/// Push the current viewport onto the viewport stack. The current viewport is unchanged.
			/**
			  * Each call to pushViewport() should be paired with a call to popViewport(),
			  * otherwise the stack will continue to grow and produce undesired behavior.
			  */
			void pushViewport();
			
			
			
			
			/// Remove the last viewport from the viewport stack and make it the current viewport.
			/**
			  * If there are no viewports on the stack, the method has no effect.
			  */
			void popViewport();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Scissor Viewport Accessor Methods
			
			
			
			
			/// Return the current scissor test for the renderer.
			RIM_INLINE const ScissorTest& getScissorTest() const
			{
				return scissorTest;
			}
			
			
			
			
			/// Replace the current scissor test for the renderer.
			/**
			  * This method changes the context's scissor test if the context is valid
			  * and replaces the locally-stored current scissor test regardless of whether
			  * or not the context is valid.
			  *
			  * This method may cause previously buffered drawing commands to be flushed to the screen.
			  */
			void setScissorTest( const ScissorTest& newScissorTest );
			
			
			
			
			/// Replace the current scissor test for the renderer.
			/**
			  * This method changes the context's scissor test if the context is valid
			  * and replaces the locally-stored current scissor test regardless of whether
			  * or not the context is valid.
			  *
			  * This method may cause previously buffered drawing commands to be flushed to the screen.
			  */
			void setScissorTest( const AABB2f& newScissorBounds, Bool enabled = true )
			{
				this->setScissorTest( ScissorTest( Viewport( newScissorBounds ), enabled ) );
			}
			
			
			
			
			/// Push the current scissor test onto the scissor test stack. The current scissor test is unchanged.
			/**
			  * Each call to pushScissorTest() should be paired with a call to popScissorTest(),
			  * otherwise the stack will continue to grow and produce undesired behavior.
			  */
			void pushScissorTest();
			
			
			
			
			/// Remove the last scissor test from the scissor test stack and make it the current one.
			/**
			  * If there are no scissor tests on the stack, the method has no effect.
			  */
			void popScissorTest();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Projection Matrix Accessor Methods
			
			
			
			
			/// Return the current projection matrix for the renderer.
			RIM_INLINE const Matrix4& getProjection() const
			{
				return projection;
			}
			
			
			
			
			/// Replace the current projection matrix for the renderer.
			/**
			  * This method may cause previously buffered drawing commands to be flushed to the screen.
			  */
			void setProjection( const Matrix4& newProjection );
			
			
			
			
			/// Replace the current projection matrix for the renderer with a 2D orthographic projection matrix.
			/**
			  * The resulting projection views the specified volume with its view direction
			  * down the negative Z axis. The z near and far planes are set to be 1 and -1,
			  * respectively.
			  */
			void setProjection( const AABB2& viewVolume );
			
			
			
			
			/// Replace the current projection matrix for the renderer with a 3D orthographic projection matrix.
			/**
			  * The resulting projection views the specified volume with its view direction
			  * down the negative Z axis.
			  */
			void setProjection( const AABB3& viewVolume );
			
			
			
			
			/// Push the current projection matrix onto the projection matrix stack. The current projection matrix is unchanged.
			/**
			  * Each call to pushProjection() should be paired with a call to popProjection(),
			  * otherwise the stack will continue to grow and produce undesired behavior.
			  */
			void pushProjection();
			
			
			
			
			/// Remove the last projection matrix from the projection matrix stack and make it the current projection matrix.
			/**
			  * If there are no projection matrixs on the stack, the method has no effect.
			  */
			void popProjection();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transform Matrix Accessor Methods
			
			
			
			
			/// Return the current transformation matrix for the renderer.
			RIM_INLINE const Matrix4& getTransform() const
			{
				return transformation;
			}
			
			
			
			
			/// Replace the current transformation matrix for the renderer.
			/**
			  * This method may cause previously buffered drawing commands to be flushed to the screen.
			  */
			void setTransform( const Matrix4& newTransform );
			
			
			
			
			/// Replace the current transformation for the renderer.
			/**
			  * This method may cause previously buffered drawing commands to be flushed to the screen.
			  */
			void setTransform( const Transform3& newTransform );
			
			
			
			
			/// Multiply the current transformation matrix for the renderer by another matrix.
			/**
			  * This method may cause previously buffered drawing commands to be flushed to the screen.
			  */
			void applyTransform( const Matrix4& newTransform );
			
			
			
			
			/// Multiply the current transformation matrix for the renderer by another transformation.
			/**
			  * This method may cause previously buffered drawing commands to be flushed to the screen.
			  */
			void applyTransform( const Transform3& newTransform );
			
			
			
			
			/// Push the current transformation matrix onto the transformation matrix stack. The current transformation matrix is unchanged.
			/**
			  * Each call to pushTransform() should be paired with a call to popTransform(),
			  * otherwise the stack will continue to grow and produce undesired behavior.
			  */
			void pushTransform();
			
			
			
			
			/// Remove the last transformation matrix from the transformation matrix stack and make it the current transformation matrix.
			/**
			  * If there are no transformation matrixs on the stack, the method has no effect.
			  */
			void popTransform();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Line Width Accessor Methods
			
			
			
			
			/// Return the width in pixels to use when rendering lines.
			Float getLineWidth() const;
			
			
			
			
			/// Set the width in pixels to use when rendering lines.
			void setLineWidth( Float newLineWidth );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point Size Accessor Methods
			
			
			
			
			/// Return the size in pixels to use when rendering points.
			Float getPointSize() const;
			
			
			
			
			/// Set the size in pixels to use when rendering points.
			void setPointSize( Float newPointSize );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constant Accessor Methods
			
			
			
			
			/// Get the constant value with the specified usage in the output parameter.
			/**
			  * The method returns whether or not the constant value was able to be retrieved.
			  */
			RIM_INLINE Bool getConstant( const ConstantUsage& usage, AttributeValue& value ) const
			{
				return constants.getConstant( usage, value );
			}
			
			
			
			
			/// Get the constant value with the specified usage in the template output parameter.
			/**
			  * The method returns whether or not the constant value was able to be retrieved.
			  */
			template < typename T >
			RIM_INLINE Bool getConstant( const ConstantUsage& usage, T& value ) const
			{
				return constants.getConstant( usage, &value );
			}
			
			
			
			
			/// Set the value of the specified constant usage for this renderer.
			/**
			  * The method returns whether or not the constant value was able to be set.
			  */
			RIM_INLINE Bool setConstant( const ConstantUsage& usage, const AttributeValue& value )
			{
				return constants.setConstant( usage, value );
			}
			
			
			
			
			/// Set the value of the specified constant usage for this renderer.
			/**
			  * The method returns whether or not the constant value was able to be set.
			  */
			template < typename T >
			RIM_INLINE Bool setConstant( const ConstantUsage& usage, const T& value )
			{
				return constants.setConstant( usage, &value );
			}
			
			
			
			
			/// Clear all constants that are currently set in this immediate renderer.
			/**
			  * This method should be called whenever the renderer does not need the
			  * previously stored constants anymore in order to reduce the memory used.
			  */
			RIM_INLINE void clearConstants()
			{
				constants.clearConstants();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Render Method
			
			
			
			
			/// Draw all previously buffered geometry to the screen.
			/**
			  * As drawing commands are submitted, the renderer buffers them internally
			  * until the rendering state is changed, necessitating flushing the commands.
			  * This method should be called after all commands are submitted, in order to
			  * ensure that any previously buffered commands are completely drawn.
			  */
			virtual void render();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Drawing Control Methods
			
			
			
			
			/// Start drawing the specified kind of primitive type.
			/**
			  * All subsequent vertex submissions will be interpreted as a sequence of
			  * primitives of this type. For example, if IndexedPrimitiveType::TRIANGLES
			  * is used, every 3 vertices correspond to a single triangle that is to be drawn.
			  *
			  * This method causes previously buffered drawing commands to be flushed to the screen
			  * as the rendering state is prepared for the new primitive type.
			  */
			void begin( const IndexedPrimitiveType& primitiveType );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Submission Methods
			
			
			
			
			/// Submit a 2D vertex with the given position to the immediate renderer.
			/**
			  * This vertex uses the last values for vertex color, normal texture coordinate, etc.
			  *
			  * 2D vertex positions are padded out to 4 components with the Z and W components 0 and 1
			  * when they are submitted.
			  */
			RIM_INLINE void vertex( const Vector2f& position )
			{
				this->vertex( Vector4f( position, 0, 1 ) );
			}
			
			
			
			
			/// Submit a 3D vertex with the given position to the immediate renderer.
			/**
			  * This vertex uses the last values for vertex color, normal texture coordinate, etc.
			  *
			  * 3D vertex positions are padded out to 4 components with the W component 1
			  * when they are submitted.
			  */
			RIM_INLINE void vertex( const Vector3f& position )
			{
				this->vertex( Vector4f( position, 1 ) );
			}
			
			
			
			
			/// Submit a 4D vertex with the given position to the immediate renderer.
			/**
			  * This vertex uses the last values for vertex color, normal texture coordinate, etc.
			  */
			void vertex( const Vector4f& position );
			
			
			
			
			/// Submit a 2D vertex with the given position to the immediate renderer.
			/**
			  * This vertex uses the last values for vertex color, normal texture coordinate, etc.
			  *
			  * 2D vertex positions are padded out to 4 components with the Z and W components 0 and 1
			  * when they are submitted.
			  */
			RIM_INLINE void vertex( Float x, Float y )
			{
				this->vertex( Vector2f( x, y ) );
			}
			
			
			
			
			/// Submit a 3D vertex with the given position to the immediate renderer.
			/**
			  * This vertex uses the last values for vertex color, normal texture coordinate, etc.
			  *
			  * 3D vertex positions are padded out to 4 components with the W component 1
			  * when they are submitted.
			  */
			RIM_INLINE void vertex( Float x, Float y, Float z )
			{
				this->vertex( Vector3f( x, y, z ) );
			}
			
			
			
			
			/// Submit a 4D vertex with the given position to the immediate renderer.
			/**
			  * This vertex uses the last values for vertex color, normal texture coordinate, etc.
			  */
			RIM_INLINE void vertex( Float x, Float y, Float z, Float w )
			{
				this->vertex( Vector4f( x, y, z, w ) );
			}
			
			
			
			
			/// Submit the specified number of 2D vertices from an array of vertices.
			/**
			  * All vertices uses the last values for vertex color, normal texture coordinate, etc.
			  */
			void vertices( const Vector2f* v, Size numVertices );
			
			
			
			
			/// Submit the specified number of 3D vertices from an array of vertices.
			/**
			  * All vertices uses the last values for vertex color, normal texture coordinate, etc.
			  */
			void vertices( const Vector3f* v, Size numVertices );
			
			
			
			
			/// Submit the specified number of 4D vertices from an array of vertices.
			/**
			  * All vertices uses the last values for vertex color, normal texture coordinate, etc.
			  */
			void vertices( const Vector4f* v, Size numVertices );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Normal Submission Methods
			
			
			
			
			/// Set the current normal of the immediate renderer as a 3-component vector.
			/**
			  * This value affects all subsequent draw calls until the method is called again.
			  */
			void normal( const Vector3f& normal );
			
			
			
			
			/// Set the current normal of the immediate renderer as a 3-component vector.
			/**
			  * This value affects all subsequent draw calls until the method is called again.
			  */
			RIM_INLINE void normal( Float nx, Float ny, Float nz )
			{
				this->normal( Vector3f( nx, ny, nz ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Texture Coordinate Submission Methods
			
			
			
			
			/// Set the current texture coordinate of the immediate renderer as a 2-component UV coordinate.
			/**
			  * This value affects all subsequent draw calls until the method is called again.
			  */
			void uv( const Vector2f& uv );
			
			
			
			
			/// Set the current texture coordinate of the immediate renderer as a 2-component UV coordinate.
			/**
			  * This value affects all subsequent draw calls until the method is called again.
			  */
			RIM_INLINE void uv( Float u, Float v )
			{
				this->uv( Vector2f( u, v ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Color Accessor Methods
			
			
			
			
			/// Set the current color of the immediate renderer as a 3-component RGB color.
			/**
			  * The color value is padded to 4 components with an alpha component of 1.
			  *
			  * This color affects all subsequent draw calls until the method is called again.
			  */
			void color( const Color3f& newColor );
			
			
			
			
			/// Set the current color of the immediate renderer as a 4-component RGBA color.
			/**
			  * This color affects all subsequent draw calls until the method is called again.
			  */
			void color( const Color4f& newColor );
			
			
			
			
			/// Set the current color of the immediate renderer as a 3-component RGB color.
			/**
			  * The color value is padded to 4 components with an alpha component of 1.
			  *
			  * This color affects all subsequent draw calls until the method is called again.
			  */
			RIM_INLINE void color( Float r, Float g, Float b )
			{
				this->color( Color3f( r, g, b ) );
			}
			
			
			
			
			/// Set the current color of the immediate renderer as a 3-component RGB color.
			/**
			  * The color value is padded to 4 components with an alpha component of 1.
			  *
			  * This color affects all subsequent draw calls until the method is called again.
			  */
			RIM_INLINE void color( Float r, Float g, Float b, Float a )
			{
				this->color( Color4f( r, g, b, a ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shape Drawing Methods
			
			
			
			
			/// Synchronously draw a sphere in the current coordinate frame with the given radius and current color.
			Bool sphere( const Vector3f& position, Float radius );
			
			
			
			
			/// Synchronously draw an axis-aligned box in the current coordinate frame with the current color.
			/**
			  * The box is drawn with filled sides.
			  */
			void box( const AABB3f& bounds );
			
			
			
			
			/// Synchronously draw an axis-aligned bounding box in the current coordinate frame with the current color.
			/**
			  * The box is drawn with edges only.
			  */
			void boundingBox( const AABB3f& bounds );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the graphics context which is being used to draw geometry.
			Pointer<GraphicsContext> context;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffering Data Members
			
			
			
			
			/// The current indexed primitive type that is being drawn.
			IndexedPrimitiveType primitiveType;
			
			
			
			
			/// The minimum number of vertices that can be fit into the buffers for the current primitive type.
			Size bufferLimit;
			
			
			
			
			/// The total number of vertices that have been buffered.
			Size numVertices;
			
			
			
			
			/// The size of the internal vertex buffers.
			Size bufferCapacity;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Position Data Members
			
			
			
			
			/// A pointer to the hardware buffer of vertex positions.
			Pointer<VertexBuffer> positionBuffer;
			
			
			
			
			/// A pointer to the current write position in the memory-mapped position buffer, or NULL if unmapped.
			Vector4f* positionPointer;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Normal Data Members
			
			
			
			
			/// A pointer to the hardware buffer of vertex normals.
			Pointer<VertexBuffer> normalBuffer;
			
			
			
			
			/// A pointer to the current write position in the memory-mapped normal buffer, or NULL if unmapped.
			Vector3f* normalPointer;
			
			
			
			
			/// The current normal vector that is being assigned to new vertices.
			Vector3f currentNormal;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	UV Data Members
			
			
			
			
			/// A pointer to the hardware buffer of vertex texture coordinates.
			Pointer<VertexBuffer> uvBuffer;
			
			
			
			
			/// A pointer to the current write position in the memory-mapped uv buffer, or NULL if unmapped.
			Vector2f* uvPointer;
			
			
			
			
			/// The current texture coordinate that is being assigned to new vertices.
			Vector2f currentUV;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Data Members
			
			
			
			
			/// A pointer to the hardware buffer of vertex colors.
			Pointer<VertexBuffer> colorBuffer;
			
			
			
			
			/// A pointer to the current write position in the memory-mapped color buffer, or NULL if unmapped.
			Color4f* colorPointer;
			
			
			
			
			/// The current color that is being assigned to new vertices.
			Color4f currentColor;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Viewport Data Members
			
			
			
			
			/// The current viewport.
			Viewport viewport;
			
			
			
			
			/// A stack of viewports that have been saved for later.
			ShortArrayList<Viewport,2> viewports;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Scissor Test Data Members
			
			
			
			
			/// The current scissor test.
			ScissorTest scissorTest;
			
			
			
			
			/// A stack of scissor tets that have been saved for later.
			ShortArrayList<ScissorTest,2> scissorTests;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Matrix Data Members
			
			
			
			
			/// The current projection matrix.
			Matrix4 projection;
			
			
			
			
			/// A stack of 4x4 projection matrices that have been saved for later.
			ShortArrayList<Matrix4,2> projections;
			
			
			
			
			/// The current transformation matrix.
			Matrix4 transformation;
			
			
			
			
			/// A stack of 4x4 transformation matrices that have been saved for later.
			ShortArrayList<Matrix4,4> transformations;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constant Data Members
			
			
			
			
			/// A buffer containing the currently set constants for this renderer.
			ConstantBuffer constants;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Pass Data Members
			
			
			
			
			/// The current shader pass.
			Pointer<ShaderPass> shaderPass;
			
			
			
			
			/// The default shader pass, for when the user has not specified one.
			Pointer<ShaderPass> defaultShaderPass;
			
			
			
			
			/// A stack of shader passes that have been saved for later.
			ShortArrayList<Pointer<ShaderPass>,4> shaderPasses;
			
			
			
			
			/// A stack of render modes that have been saved for later.
			ShortArrayList<RenderMode,4> renderModes;
			
			
			
			
			/// The default render mode.
			RenderMode defaultRenderMode;
			
			
			
			
			/// A set of global shader binding data.
			ShaderBindingData globalBindingData;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sphere Data Members
			
			
			
			
			/// A pointer to a sphere shape for drawing spheres.
			Pointer<shapes::SphereShape> sphereShape;
			
			
			
			
			/// The sphere shader pass.
			Pointer<ShaderPass> sphereShaderPass;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Renderers Namespace  ****************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_IMMEDIATE_RENDERER_H
