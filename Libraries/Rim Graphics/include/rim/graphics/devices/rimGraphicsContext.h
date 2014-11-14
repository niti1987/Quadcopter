/*
 *  rimGraphicsContext.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/1/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_CONTEXT_H
#define INCLUDE_RIM_GRAPHICS_CONTEXT_H


#include "rimGraphicsDevicesConfig.h"


#include "../rimGraphicsBase.h"
#include "rimGraphicsContextCapabilities.h"


//##########################################################################################
//***********************  Start Rim Graphics Devices Namespace  ***************************
RIM_GRAPHICS_DEVICES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


using rim::gui::RenderView;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents an instance of a graphics device renderer.
/**
  * Specialized implementations inherit from this interface to provide
  * a way to provide uniform access to their underlying drivers. For instance,
  * there could be a class OpenGLContext which inherits from GraphicsContext
  * and represents an OpenGL device driver context.
  */
class GraphicsContext
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a graphics context, releasing all of its resources and internal state.
			virtual ~GraphicsContext()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Target View Accessor Methods
			
			
			
			
			/// Return a pointer to the target render view which this context should render to.
			/**
			  * This view represents the area on the screen which this context is
			  * rendering to. If this method returns NULL, it means that there is
			  * no target render view and therefore the context will not be able
			  * to render anything.
			  */
			virtual Pointer<RenderView> getTargetView() const = 0;
			
			
			
			
			/// Set the target render view which this context should render to.
			/**
			  * This method effectively recreates the context for the given render view.
			  *
			  * Calling this method automatically resizes the context's viewport to
			  * fill the entire area of the specified target render view. The method
			  * returns whether or not the target view was successfully changed.
			  * The method will fail if the specified view pointer is NULL.
			  */
			virtual Bool setTargetView( const Pointer<RenderView>& newTargetView ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Context Validity Accessor Method
			
			
			
			
			/// Return whether or not this context is valid and can be used for rendering.
			/**
			  * Users should check the return value of this method after context creation
			  * to ensure that the context was successfully created.
			  */
			virtual Bool isValid() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Context Capabilities Accessor Methods
			
			
			
			
			/// Return an object which describes the different capabilities of this graphics context.
			virtual const GraphicsContextCapabilities& getCapabilities() const = 0;
			
			
			
			
			/// Return whether or not this graphics context supports the specified capabilities.
			/**
			  * This method allows testing for multiple capabilities at once. The function
			  * returns TRUE only if all of the specified capability flags are set.
			  */
			RIM_INLINE Bool hasCapabilities( const GraphicsContextCapabilities& capabilities )
			{
				return (this->getCapabilities() & capabilities) == capabilities;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Current Context Accessor Methods
			
			
			
			
			/// Return whether or not this context is the current context for the calling thread.
			virtual Bool isCurrent() = 0;
			
			
			
			
			/// Make this context the active context for the calling thread.
			/**
			  * If the method fails and this context is not able to be made the current
			  * context, FALSE is returned. Otherwise, TRUE is returned indicating success.
			  */
			virtual Bool makeCurrent() = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Swap Method
			
			
			
			
			/// Flush all rendering commands and swap the front buffer with the back buffer.
			/**
			  * This has the effect of displaying the frame which was just drawn
			  * using the context. In practice, the user should call this method
			  * after drawing each frame using the context. If v-sync is enabled, this method
			  * waits until the next vertical screen refresh to copy the front buffer
			  * to the back buffer.
			  *
			  * If the context is single-buffered, this method has no effect.
			  */
			virtual void swapBuffers() = 0;
			
			
			
			
			/// Return whether or not vertical screen refresh synchronization is enabled.
			virtual Bool getVSyncIsEnabled() const = 0;
			
			
			
			
			/// Set whether or not vertical screen refresh synchronization should be enabled.
			/**
			  * The method returns whether or not setting the V-Sync status was successful.
			  */
			virtual Bool setVSyncIsEnabled( Bool newVSync ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flush Methods
			
			
			
			
			/// Flush all rendering commands into the graphics pipeline.
			/**
			  * This method can be called to force all queued rendering commands
			  * to be executed immediately by the context.
			  */
			virtual void flush() = 0;
			
			
			
			
			/// Flush all rendering commands into the graphics pipeline and wait until they are complete.
			/**
			  * This method can be called to force all queued rendering commands
			  * to be executed immediately by the context. The method waits until
			  * all of the queued commands are executed and finish executing,
			  * then returns.
			  */
			virtual void finish() = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Render Mode Accessor Methods
			
			
			
			
			/// Return an object which contains information about the current state of the context's renderer.
			/**
			  * A context's render mode encapsulates various attributes of the fixed-function
			  * graphics pipeline, such as the blending mode, depth mode, and stencil
			  * mode.
			  */
			virtual RenderMode getRenderMode() const = 0;
			
			
			
			
			/// Set the mode of the context's renderer.
			/**
			  * If the method succeeds, the render mode of the context's graphics pipeline
			  * is set to have the requested state and TRUE is returned. Otherwise, if
			  * some part of the state was unable to be applied, FALSE is returned.
			  */
			virtual Bool setRenderMode( const RenderMode& newRenderMode ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Render Flags Accessor Methods
			
			
			
			
			/// Return an object which contains boolan flags for the current state of the context's renderer.
			/**
			  * These flags indicate the enabled/disabled state for various parts
			  * of the fixed-function graphics pipeline.
			  */
			virtual RenderFlags getRenderFlags() const = 0;
			
			
			
			
			/// Set an object which contains boolan flags for the current state of the context's renderer.
			/**
			  * If the method succeeds, the render flags of the context's graphics pipeline
			  * are set to have the requested state and TRUE is returned. Otherwise, if
			  * some part of the state was unable to be applied, FALSE is returned.
			  */
			virtual Bool setRenderFlags( const RenderFlags& newRenderFlags ) = 0;
			
			
			
			
			/// Return whether or not a certain render flag is currently set.
			virtual Bool getRenderFlagIsSet( RenderFlags::Flag flag ) const = 0;
			
			
			
			
			/// Set whether or not a certain render flag should be set.
			/**
			  * If the method succeeds, the render flags of the context's graphics pipeline
			  * are set so that the given flag has the specified value and TRUE is returned.
			  * Otherwise, if the state was unable to be applied, FALSE is returned.
			  */
			virtual Bool setRenderFlag( RenderFlags::Flag flag, Bool value = true ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Depth Mode Accessor Methods
			
			
			
			
			/// Return an object which contains information about the current state of the context's depth test pipeline.
			virtual DepthMode getDepthMode() const = 0;
			
			
			
			
			/// Set the mode of the context's depth test pipeline.
			/**
			  * If the method succeeds, the depth mode of the context's graphics pipeline
			  * is set to have the requested state and TRUE is returned. Otherwise, if
			  * some part of the state was unable to be applied, FALSE is returned.
			  */
			virtual Bool setDepthMode( const DepthMode& newDepthMode ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stencil Mode Accessor Methods
			
			
			
			
			/// Return an object which contains information about the current state of the context's stencil test pipeline.
			virtual StencilMode getStencilMode() const = 0;
			
			
			
			
			/// Set the mode of the context's stencil test pipeline.
			/**
			  * If the method succeeds, the stencil mode of the context's graphics pipeline
			  * is set to have the requested state and TRUE is returned. Otherwise, if
			  * some part of the state was unable to be applied, FALSE is returned.
			  */
			virtual Bool setStencilMode( const StencilMode& newStencilMode ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Blend Mode Accessor Methods
			
			
			
			
			/// Return an object which contains information about the current state of the context's blending pipeline.
			virtual BlendMode getBlendMode() const = 0;
			
			
			
			
			/// Set the mode of the context's blending pipeline.
			/**
			  * If the method succeeds, the blending mode of the context's graphics pipeline
			  * is set to have the requested state and TRUE is returned. Otherwise, if
			  * some part of the state was unable to be applied, FALSE is returned.
			  */
			virtual Bool setBlendMode( const BlendMode& newBlendMode ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Line Width Accessor Methods
			
			
			
			
			/// Return the width in pixels to use when rendering lines.
			virtual Float getLineWidth() const = 0;
			
			
			
			
			/// Set the width in pixels to use when rendering lines.
			/**
			  * If the method succeeds, the line width of the context's graphics pipeline
			  * is set to have the requested size in pixels and TRUE is returned. Otherwise, if
			  * the line width was unable to be set, FALSE is returned.
			  */
			virtual Bool setLineWidth( Float newLineWidth ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point Size Accessor Methods
			
			
			
			
			/// Return the size in pixels to use when rendering points.
			virtual Float getPointSize() const = 0;
			
			
			
			
			/// Set the size in pixels to use when rendering points.
			/**
			  * If the method succeeds, the point size of the context's graphics pipeline
			  * is set to have the requested size in pixels and TRUE is returned. Otherwise, if
			  * the point size was unable to be set, FALSE is returned.
			  */
			virtual Bool setPointSize( Float newPointSize ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Viewport Accessor Methods
			
			
			
			
			/// Return an object representing the current viewport for this graphics context.
			/**
			  * This is the rectangular area of the context's target view which is being rendered to
			  * by the context. Coordinates are specified where (0,0) is the lower left-corner of the
			  * screen, and (1,1) is the upper-right corner.
			  */
			virtual Viewport getViewport() const = 0;
			
			
			
			
			/// Set the viewport to use for this graphics context.
			/**
			  * This is the rectangular area of the context's target view which is being rendered to
			  * by the context. Coordinates are specified where (0,0) is the lower left-corner of the
			  * screen, and (1,1) is the upper-right corner.
			  *
			  * The method returns whether or not the viewport change operation was successful.
			  */
			virtual Bool setViewport( const Viewport& newViewport ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Scissor Test Accessor Methods
			
			
			
			
			/// Return an object representing the current scissor test for this graphics context.
			/**
			  * This is the rectangular area of the context's target view which is being rendered to
			  * by the context. The scissor rectangle allows the user to clip rendering to a
			  * rectangular region within a viewport without affecting the screen-space viewport transformation.
			  *
			  * Coordinates are specified where (0,0) is the lower left-corner of the
			  * screen, and (1,1) is the upper-right corner.
			  */
			virtual ScissorTest getScissorTest() const = 0;
			
			
			
			
			/// Set an object representing the current scissor test for this graphics context.
			/**
			  * This is the rectangular area of the context's target view which is being rendered to
			  * by the context. The scissor rectangle allows the user to clip rendering to a
			  * rectangular region within a viewport without affecting the screen-space viewport transformation.
			  *
			  * Coordinates are specified where (0,0) is the lower left-corner of the
			  * screen, and (1,1) is the upper-right corner.
			  *
			  * The method returns whether or not the scissor test change operation was successful.
			  */
			virtual Bool setScissorTest( const ScissorTest& newScissorTest ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Framebuffer Clearing Methods
			
			
			
			
			/// Clear the contents of the color buffer, writing the specified color to every pixel.
			virtual void clearColorBuffer( const Color4d& clearColor ) = 0;
			
			
			
			
			/// Clear the contents of the depth buffer, writing the specified depth to every pixel.
			virtual void clearDepthBuffer( Double clearDepth ) = 0;
			
			
			
			
			/// Clear the contents of the stencil buffer, writing the specified integer value to every pixel.
			/**
			  * This integer value is masked so that the final N-bit stencil value contains the lower-order
			  * N bits of the specified integer.
			  */
			virtual void clearStencilBuffer( Int clearStencil ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Framebuffer Read Methods
			
			
			
			
			/// Read an image corresponding to the entire contents of the context's current color buffer.
			/**
			  * The color buffer is read from and its contents are placed in the output image parameter
			  * with the specified pixel type. If the pixel type is incompatible with the framebuffer
			  * format, or if the read operation failed, FALSE is returned and no image is retrieved.
			  * Otherwise, TRUE is returned and the method succeeds.
			  */
			virtual Bool readColorBuffer( const PixelFormat& pixelType, Image& image ) const = 0;
			
			
			
			
			/// Read an image corresponding to the specified contents of the context's current color buffer.
			/**
			  * The color buffer is read from and its contents are placed in the output image parameter
			  * with the specified pixel type. If the pixel type is incompatible with the framebuffer
			  * format, or if the read operation failed, FALSE is returned and no image is retrieved.
			  * Otherwise, TRUE is returned and the method succeeds.
			  *
			  * This method reads the framebuffer pixels that are in the given bounding box and
			  * creates an image with the width and height of the box. Coordinates are specified so that
			  * (0,0) is the lower left corner of the context. If the bounding box is outside the
			  * range of the framebuffer, it is clamped to the edge of the framebuffer.
			  */
			virtual Bool readColorBuffer( const PixelFormat& pixelType, Image& image, const AABB2i& bounds ) const = 0;
			
			
			
			
			/// Read an image corresponding to the entire contents of the context's current depth buffer.
			/**
			  * The depth buffer is read from and its contents are placed in the output image parameter
			  * with the specified pixel type. If the pixel type is incompatible with the depthframebuffer
			  * format, or if the read operation failed, FALSE is returned and no image is retrieved.
			  * Otherwise, TRUE is returned and the method succeeds.
			  */
			virtual Bool readDepthBuffer( const PixelFormat& pixelType, Image& image ) const = 0;
			
			
			
			
			/// Read an image corresponding to the specified contents of the context's current depth buffer.
			/**
			  * The depth buffer is read from and its contents are placed in the output image parameter
			  * with the specified pixel type. If the pixel type is incompatible with the depth framebuffer
			  * format, or if the read operation failed, FALSE is returned and no image is retrieved.
			  * Otherwise, TRUE is returned and the method succeeds.
			  *
			  * This method reads the framebuffer pixels that are in the given bounding box and
			  * creates an image with the width and height of the box. Coordinates are specified so that
			  * (0,0) is the lower left corner of the context. If the bounding box is outside the
			  * range of the framebuffer, it is clamped to the edge of the framebuffer.
			  */
			virtual Bool readDepthBuffer( const PixelFormat& pixelType, Image& image, const AABB2i& bounds ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Framebuffer Binding Methods
			
			
			
			
			/// Return a 2D vector containing the size in pixels of the currently bound framebuffer.
			virtual Vector2D<Size> getFramebufferSize() const = 0;
			
			
			
			
			/// Return a pointer to the currently bound framebuffer object.
			/**
			  * A NULL return value indicates that no external framebuffer object is bound
			  * to the context and that all drawing commands are being rendered to the main
			  * screen (target view).
			  */
			virtual Pointer<Framebuffer> getFramebuffer() const = 0;
			
			
			
			
			/// Set the currently bound framebuffer object.
			/**
			  * If the specified framebuffer is not valid, the method has no effect and
			  * FALSE is returned. Otherwise, the framebuffer binding succeeds, it replaces
			  * the previously bound framebuffer, and TRUE is returned.
			  *
			  * If a NULL framebuffer pointer is specified, the previously bound
			  * framebuffer is unbound and the main target view is bound as the
			  * framebuffer instead and TRUE is returned.
			  */
			virtual Bool bindFramebuffer( const Pointer<Framebuffer>& newFramebuffer ) = 0;
			
			
			
			
			/// Unbind the previously bound framebuffer, restoring the main screen as the target.
			/**
			  * The previously bound framebuffer is unbound and the main target view is bound as the
			  * framebuffer instead and TRUE is returned.
			  */
			virtual void unbindFramebuffer() = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Drawing Methods
			
			
			
			
			/// Draw the specified shader pass, indexing vertices using a range of the given index buffer.
			/**
			  * If the shader binding data pointer is not NULL, shader binding data is taken from
			  * the data object, rather than the shader pass, and used in drawing the shader pass.
			  * The specified shader data object should use the same bindings and data format as the specified shader
			  * pass. It is used to provide scene-specific drawing information (such as lights) for the
			  * shader pass without modifying the shader pass.
			  *
			  * The method returns whether or not the draw command was successfully executed.
			  */
			virtual Bool draw( const ShaderPass& shaderPass, const IndexBuffer& indices,
								const BufferRange& bufferRange,
								const ShaderBindingData* shaderData = NULL ) = 0;
			
			
			
			
			/// Draw the specified shader pass, using a range of vertices from the shader pass's vertex buffers.
			/**
			  * If the shader binding data pointer is not NULL, shader binding data is taken from
			  * the data object, rather than the shader pass, and used in drawing the shader pass.
			  * The specified shader data object should use the same bindings and data format as the specified shader
			  * pass. It is used to provide scene-specific drawing information (such as lights) for the
			  * shader pass without modifying the shader pass.
			  *
			  * The method returns whether or not the draw command was successfully executed.
			  */
			virtual Bool draw( const ShaderPass& shaderPass, const BufferRange& bufferRange,
								const ShaderBindingData* shaderData = NULL ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Buffer Creation Methods
			
			
			
			
			/// Create a vertex attribute buffer with undefined attribute type and capacity.
			virtual Pointer<VertexBuffer> createVertexBuffer( 
													const HardwareBufferUsage& newUsage = HardwareBufferUsage::STATIC ) = 0;
			
			
			
			
			/// Create a vertex attribute buffer with the specified attribute type and capacity.
			/**
			  * The contents of the created buffer are undefined.
			  */
			virtual Pointer<VertexBuffer> createVertexBuffer( const AttributeType& attributeType, Size capacity,
													const HardwareBufferUsage& newUsage = HardwareBufferUsage::STATIC ) = 0;
			
			
			
			
			/// Create a vertex attribute buffer with the specified attributes, attribute type and capacity.
			/**
			  * This method uses data from the given attribute pointer to initialize the hardware
			  * buffer up to the specified capacity.
			  */
			virtual Pointer<VertexBuffer> createVertexBuffer( const void* attributes,
													const AttributeType& attributeType, Size capacity,
													const HardwareBufferUsage& newUsage = HardwareBufferUsage::STATIC ) = 0;
			
			
			
			
			/// Create a vertex attribute buffer with the same capacity as the specified buffer's number of attributes.
			RIM_INLINE Pointer<VertexBuffer> createVertexBuffer( const GenericBuffer& attributes,
													const HardwareBufferUsage& newUsage = HardwareBufferUsage::STATIC )
			{
				return this->createVertexBuffer( attributes.getPointer(), attributes.getAttributeType(),
													attributes.getSize(), newUsage );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Index Buffer Creation Methods
			
			
			
			
			/// Create an index buffer with undefined attribute type and capacity.
			virtual Pointer<IndexBuffer> createIndexBuffer( const HardwareBufferUsage& newUsage = HardwareBufferUsage::STATIC ) = 0;
			
			
			
			
			/// Create an index buffer with the specified attribute type and capacity.
			/**
			  * The contents of the created buffer are undefined.
			  */
			virtual Pointer<IndexBuffer> createIndexBuffer( const PrimitiveType& indexType, Size capacity,
												const HardwareBufferUsage& newUsage = HardwareBufferUsage::STATIC ) = 0;
			
			
			
			
			/// Create an index buffer with the specified attributes, attribute type and capacity.
			/**
			  * This method uses data from the given pointer to initialize the hardware
			  * buffer up to the specified capacity. The attribute buffer must have enough space
			  * for all of the requested attributes.
			  */
			virtual Pointer<IndexBuffer> createIndexBuffer( const void* indices,
												const PrimitiveType& indexType, Size capacity,
												const HardwareBufferUsage& newUsage = HardwareBufferUsage::STATIC ) = 0;
			
			
			
			
			/// Create an index buffer with the same capacity as the specified buffer's number of indices.
			RIM_INLINE Pointer<IndexBuffer> createIndexBuffer( const GenericBuffer& indices,
												const HardwareBufferUsage& newUsage = HardwareBufferUsage::STATIC )
			{
				if ( !indices.getAttributeType().isAScalar() )
					return Pointer<IndexBuffer>();
				
				return this->createIndexBuffer( indices.getPointer(), indices.getAttributeType().getPrimitiveType(),
												indices.getSize(), newUsage );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Creation Methods
			
			
			
			
			/// Create a default uninitialized texture with undefined format and size.
			/**
			  * If the creation fails, a NULL pointer is returned.
			  */
			virtual Pointer<Texture> createTexture() = 0;
			
			
			
			
			/// Create a 1D texture with the specified internal format and size with undefined pixel data.
			/**
			  * If the creation fails, a NULL pointer is returned.
			  */
			virtual Pointer<Texture> createTexture1D( TextureFormat format, Size width ) = 0;
			
			
			
			
			/// Create a 2D texture with the specified internal format and size with undefined pixel data.
			/**
			  * If the creation fails, a NULL pointer is returned.
			  */
			virtual Pointer<Texture> createTexture2D( TextureFormat format, Size width, Size height ) = 0;
			
			
			
			
			/// Create a 3D texture with the specified internal format and size with undefined pixel data.
			/**
			  * If the creation fails, a NULL pointer is returned.
			  */
			virtual Pointer<Texture> createTexture3D( TextureFormat format, Size width, Size height, Size depth ) = 0;
			
			
			
			
			/// Create a 2D cube map texture with the specified internal format and size with undefined pixel data.
			/**
			  * Each face of the cube texture will be the specified size in each dimension.
			  *
			  * If the creation fails, a NULL pointer is returned.
			  */
			virtual Pointer<Texture> createTextureCube( TextureFormat format, Size width ) = 0;
			
			
			
			
			/// Create a texture for the specified image which uses an inferred internal texture format.
			/**
			  * If the creation fails, a NULL pointer is returned.
			  */
			RIM_INLINE Pointer<Texture> createTexture( const Image& image )
			{
				return this->createTexture( image, TextureFormat(image.getPixelFormat()) );
			}
			
			
			
			
			/// Create a texture for the specified image which has the given internal texture format.
			/**
			  * Since an image can have any number of dimensions, this method allows the user
			  * to create any-dimension textures with a single interface.
			  *
			  * If the creation fails, a NULL pointer is returned.
			  */
			virtual Pointer<Texture> createTexture( const Image& image, TextureFormat format ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Framebuffer Creation Methods
			
			
			
			
			/// Create a new framebuffer object for this context.
			/**
			  * If the creation fails, a NULL pointer is returned.
			  */
			virtual Pointer<Framebuffer> createFramebuffer() = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Creation Methods
			
			
			
			
			/// Create and compile a new shader with the specified type and source code.
			/**
			  * The shader type is used to influence how the shader's source code is
			  * interpreted when compiled. If the shader type or language is unsupported,
			  * or if the shader does not succesfully compile, the method fails and NULL is returned.
			  */
			virtual Pointer<Shader> createShader( const ShaderType& newShaderType, const ShaderSourceString& newSource,
												const ShaderLanguage& newLanguage = ShaderLanguage::DEFAULT ) = 0;
			
			
			
			
			/// Create a new shader program object with no attached shaders.
			virtual Pointer<ShaderProgram> createShaderProgram() = 0;
			
			
			
			
			/// Create a new shader program object that uses the specified shader program source code.
			/**
			  * The context uses the source code and configuration in the specified generic program object
			  * to create a new shader program object. If the program compilation or the method
			  * fails, a NULL shader program is returned.
			  */
			virtual Pointer<ShaderProgram> createShaderProgram( const GenericShaderProgram& programSource ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Pass Creation Methods
			
			
			
			
			/// Create and return a shader pass object for the given shader program and rendering mode.
			/**
			  * The new shader pass uses the specified shader program and rendering mode and has no bindings.
			  * If the method fails, a NULL pointer is returned.
			  */
			virtual Pointer<ShaderPass> createShaderPass( const Pointer<ShaderProgram>& program, const RenderMode& renderMode ) = 0;
			
			
			
			
			/// Create and return a shader pass object for the given shader pass source code.
			/**
			  * The context compiles the specified shader pass source code (if possible) and
			  * and uses it to create a shader pass. If the method fails,
			  * a NULL shader pass is returned.
			  */
			virtual Pointer<ShaderPass> createShaderPass( const Pointer<ShaderPassSource>& shaderPassSource ) = 0;
			
			
			
			
			/// Create and return a shader pass object for the given generic shader pass.
			/**
			  * The context picks the best source code version from the specified generic shader pass
			  * and uses it to create a shader pass. If the method fails,
			  * a NULL shader pass is returned.
			  */
			virtual Pointer<ShaderPass> createShaderPass( const GenericShaderPass& genericShaderPass ) = 0;
			
			
			
			
			/// Return a pointer to the most compatible shader pass source version for the specified generic shader pass.
			/**
			  * The context picks the best source code version from the specified generic shader pass
			  * and returns a pointer to it. If the method fails, a NULL shader pass is returned.
			  */
			virtual Pointer<ShaderPassSource> getBestShaderPassSource( const GenericShaderPass& genericShaderPass ) = 0;
			
			
			
			
			/// Create and return a default shader pass source object for the given shader pass usage.
			/**
			  * The context creates a new default shader pass source object
			  * which renders geometry using the given type of shader pass usage. If the method fails,
			  * a NULL shader pass source is returned.
			  */
			virtual Pointer<ShaderPassSource> getDefaultShaderPassSource( const ShaderPassUsage& usage ) = 0;
			
			
			
			
			/// Create and return a default shader pass object for the given shader pass usage.
			/**
			  * The context creates a new default shader pass object
			  * which renders geometry using the given type of shader pass usage. If the method fails,
			  * a NULL shader pass is returned.
			  */
			virtual Pointer<ShaderPass> createDefaultShaderPass( const ShaderPassUsage& usage ) = 0;
			
			
			
			
			/// Recompile the specified shader pass object with the current state of its parameter configuration.
			/**
			  * This method uses the shader pass's source object if available, plus the shader pass's current
			  * configuration to recompile the shader pass. The shader pass's attribute bindings are reset
			  * for the new shader program (but their values are kept if possible).
			  *
			  * The method returns whether or not the recompilation was successful. If the compilation
			  * fails, the orignal shader pass is unmodified.
			  */
			virtual Bool recompileShaderPass( const Pointer<ShaderPass>& shaderPass ) = 0;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Devices Namespace  *****************************
RIM_GRAPHICS_DEVICES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_CONTEXT_H
