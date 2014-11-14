/*
 *  rimGraphicsOpenGLContext.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/1/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_OPENGL_CONTEXT_H
#define INCLUDE_RIM_GRAPHICS_OPENGL_CONTEXT_H


#include "rimGraphicsOpenGLConfig.h"


//##########################################################################################
//********************  Start Rim Graphics Devices OpenGL Namespace  ***********************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents an instance of an OpenGL-based renderer.
class OpenGLContext : public GraphicsContext
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this OpenGL context and release all of its resources and internal state.
			~OpenGLContext();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Target View Accessor Methods
			
			
			
			
			/// Return a pointer to the target render view which this OpenGL context should render to.
			virtual Pointer<RenderView> getTargetView() const;
			
			
			
			
			/// Set the target render view which this OpenGL context should render to.
			virtual Bool setTargetView( const Pointer<RenderView>& newTargetView );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Context Validity Accessor Method
			
			
			
			
			/// Return whether or not this context is valid and can be used for rendering.
			/**
			  * Users should check the return value of this method after context creation
			  * to ensure that the context was successfully created.
			  */
			virtual Bool isValid() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Context Capabilities Accessor Methods
			
			
			
			
			/// Return an object which describes the different capabilities of this graphics context.
			virtual const GraphicsContextCapabilities& getCapabilities() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Current Context Accessor Methods
			
			
			
			
			/// Return whether or not this context is the current context for the calling thread.
			virtual Bool isCurrent();
			
			
			
			
			/// Make this context the active context for the calling thread.
			virtual Bool makeCurrent();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Swap Method
			
			
			
			
			/// Flush all rendering commands and swap the front buffer with the back buffer.
			virtual void swapBuffers();
			
			
			
			
			/// Return whether or not vertical screen refresh synchronization is enabled.
			virtual Bool getVSyncIsEnabled() const;
			
			
			
			
			/// Set whether or not vertical screen refresh synchronization should be enabled.
			/**
			  * The method returns whether or not setting the V-Sync status was successful.
			  */
			virtual Bool setVSyncIsEnabled( Bool newVSync );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flush Methods
			
			
			
			
			/// Flush all rendering commands into the graphics pipeline.
			virtual void flush();
			
			
			
			
			/// Flush all rendering commands into the graphics pipeline and wait until they are complete.
			virtual void finish();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Render Mode Accessor Methods
			
			
			
			
			/// Return an object which contains information about the current state of the context's renderer.
			virtual RenderMode getRenderMode() const;
			
			
			
			
			/// Set the mode of the context's renderer.
			virtual Bool setRenderMode( const RenderMode& newRenderMode );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Render Flags Accessor Methods
			
			
			
			
			/// Return an object which contains boolan flags for the current state of the context's renderer.
			virtual RenderFlags getRenderFlags() const;
			
			
			
			
			/// Set an object which contains boolan flags for the current state of the context's renderer.
			virtual Bool setRenderFlags( const RenderFlags& newRenderFlags );
			
			
			
			
			/// Return whether or not a certain render flag is currently set.
			virtual Bool getRenderFlagIsSet( RenderFlags::Flag flag ) const;
			
			
			
			
			/// Set whether or not a certain render flag should be set.
			virtual Bool setRenderFlag( RenderFlags::Flag flag, Bool value = true );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Depth Mode Accessor Methods
			
			
			
			
			/// Return an object which contains information about the current state of the context's depth test pipeline.
			virtual DepthMode getDepthMode() const;
			
			
			
			
			/// Set the mode of the context's depth test pipeline.
			virtual Bool setDepthMode( const DepthMode& newDepthMode );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stencil Mode Accessor Methods
			
			
			
			
			/// Return an object which contains information about the current state of the context's stencil test pipeline.
			virtual StencilMode getStencilMode() const;
			
			
			
			
			/// Set the mode of the context's stencil test pipeline.
			virtual Bool setStencilMode( const StencilMode& newStencilMode );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Blend Mode Accessor Methods
			
			
			
			
			/// Return an object which contains information about the current state of the context's blending pipeline.
			virtual BlendMode getBlendMode() const;
			
			
			
			
			/// Set the mode of the context's blending pipeline.
			virtual Bool setBlendMode( const BlendMode& newBlendMode );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Line Width Accessor Methods
			
			
			
			
			/// Return the width in pixels to use when rendering lines.
			virtual Float getLineWidth() const;
			
			
			
			
			/// Set the width in pixels to use when rendering lines.
			virtual Bool setLineWidth( Float newLineWidth );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point Size Accessor Methods
			
			
			
			
			/// Return the size in pixels to use when rendering points.
			virtual Float getPointSize() const;
			
			
			
			
			/// Set the size in pixels to use when rendering points.
			virtual Bool setPointSize( Float newPointSize );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Viewport Accessor Methods
			
			
			
			
			/// Return an object representing the current viewport for this OpenGL context.
			virtual Viewport getViewport() const;
			
			
			
			
			/// Set the viewport to use for this OpenGL context.
			virtual Bool setViewport( const Viewport& newViewport );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Scissor Test Accessor Methods
			
			
			
			
			/// Return an object representing the current scissor test for this graphics context.
			virtual ScissorTest getScissorTest() const;
			
			
			
			
			/// Set an object representing the current scissor test for this graphics context.
			virtual Bool setScissorTest( const ScissorTest& newScissorTest );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Framebuffer Clearing Methods
			
			
			
			
			/// Clear the contents of the color buffer, writing the specified color to every pixel.
			virtual void clearColorBuffer( const Color4d& clearColor );
			
			
			
			
			/// Clear the contents of the depth buffer, writing the specified depth to every pixel.
			virtual void clearDepthBuffer( Double clearDepth );
			
			
			
			
			/// Clear the contents of the stencil buffer, writing the specified integer value to every pixel.
			virtual void clearStencilBuffer( Int clearStencil );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Framebuffer Read Methods
			
			
			
			
			/// Read an image corresponding to the entire contents of the context's current color buffer.
			virtual Bool readColorBuffer( const PixelFormat& pixelType, Image& image ) const;
			
			
			
			
			/// Read an image corresponding to the specified contents of the context's current color buffer.
			virtual Bool readColorBuffer( const PixelFormat& pixelType, Image& image, const AABB2i& bounds ) const;
			
			
			
			
			/// Read an image corresponding to the entire contents of the context's current depth buffer.
			virtual Bool readDepthBuffer( const PixelFormat& pixelType, Image& image ) const;
			
			
			
			
			/// Read an image corresponding to the specified contents of the context's current depth buffer.
			virtual Bool readDepthBuffer( const PixelFormat& pixelType, Image& image, const AABB2i& bounds ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Framebuffer Binding Methods
			
			
			
			
			/// Return a 2D vector containing the size in pixels of the currently bound framebuffer.
			virtual Vector2D<Size> getFramebufferSize() const;
			
			
			
			
			/// Return a pointer to the currently bound framebuffer object.
			virtual Pointer<Framebuffer> getFramebuffer() const;
			
			
			
			
			/// Set the currently bound framebuffer object.
			virtual Bool bindFramebuffer( const Pointer<Framebuffer>& newFramebuffer );
			
			
			
			
			/// Unbind the previously bound framebuffer, restoring the main screen as the target.
			virtual void unbindFramebuffer();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Drawing Methods
			
			
			
			
			/// Draw the specified shader pass, indexing vertices using a range of the given index buffer.
			virtual Bool draw( const ShaderPass& shaderPass, const IndexBuffer& indices,
								const BufferRange& bufferRange,
								const ShaderBindingData* shaderData = NULL );
			
			
			
			
			/// Draw the specified shader pass, using a range of vertices from the shader pass's vertex buffers.
			virtual Bool draw( const ShaderPass& shaderPass, const BufferRange& bufferRange,
								const ShaderBindingData* shaderData = NULL );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Creation Methods
			
			
			
			
			/// Create a vertex attribute buffer with undefined attribute type and capacity.
			virtual Pointer<VertexBuffer> createVertexBuffer( 
													const HardwareBufferUsage& newUsage = HardwareBufferUsage::STATIC );
			
			
			
			
			/// Create a vertex attribute buffer with the specified attribute type and capacity.
			virtual Pointer<VertexBuffer> createVertexBuffer( const AttributeType& attributeType, Size capacity,
													const HardwareBufferUsage& newUsage = HardwareBufferUsage::STATIC );
			
			
			
			
			/// Create a vertex attribute buffer with the specified attributes, attribute type and capacity.
			virtual Pointer<VertexBuffer> createVertexBuffer( const void* attributes,
													const AttributeType& attributeType, Size capacity,
													const HardwareBufferUsage& newUsage = HardwareBufferUsage::STATIC );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Index Buffer Creation Methods
			
			
			
			
			/// Create an index buffer with undefined attribute type and capacity.
			virtual Pointer<IndexBuffer> createIndexBuffer( 
												const HardwareBufferUsage& newUsage = HardwareBufferUsage::STATIC );
			
			
			
			
			/// Create an index buffer with the specified attribute type and capacity.
			virtual Pointer<IndexBuffer> createIndexBuffer( const PrimitiveType& indexType, Size capacity,
												const HardwareBufferUsage& newUsage = HardwareBufferUsage::STATIC );
			
			
			
			
			/// Create an index buffer with the specified attributes, attribute type and capacity.
			virtual Pointer<IndexBuffer> createIndexBuffer( const void* indices,
												const PrimitiveType& indexType, Size capacity,
												const HardwareBufferUsage& newUsage = HardwareBufferUsage::STATIC );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Creation Methods
			
			
			
			
			/// Create a default uninitialized texture with undefined format and size.
			virtual Pointer<Texture> createTexture();
			
			
			
			
			/// Create a 1D texture with the specified internal format and size with undefined pixel data.
			virtual Pointer<Texture> createTexture1D( TextureFormat format, Size width );
			
			
			
			
			/// Create a 2D texture with the specified internal format and size with undefined pixel data.
			virtual Pointer<Texture> createTexture2D( TextureFormat format, Size width, Size height );
			
			
			
			
			/// Create a 3D texture with the specified internal format and size with undefined pixel data.
			virtual Pointer<Texture> createTexture3D( TextureFormat format, Size width, Size height, Size depth );
			
			
			
			
			/// Create a 2D cube map texture with the specified internal format and size with undefined pixel data.
			virtual Pointer<Texture> createTextureCube( TextureFormat format, Size width );
			
			
			
			
			/// Create a texture for the specified image which has the given internal texture format.
			virtual Pointer<Texture> createTexture( const Image& image, TextureFormat format );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Framebuffer Creation Methods
			
			
			
			
			/// Create a new framebuffer object for this context.
			virtual Pointer<Framebuffer> createFramebuffer();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Creation Methods
			
			
			
			
			/// Create a new shader with the specified type and source code.
			virtual Pointer<Shader> createShader( const ShaderType& newShaderType, const ShaderSourceString& newSource,
												const ShaderLanguage& newLanguage = ShaderLanguage::DEFAULT );
			
			
			
			
			/// Create a new shader program object.
			virtual Pointer<ShaderProgram> createShaderProgram();
			
			
			
			
			/// Create a new shader program object that uses the specified shader program source code.
			virtual Pointer<ShaderProgram> createShaderProgram( const GenericShaderProgram& programSource );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Pass Creation Methods
			
			
			
			
			/// Create and return a shader pass object for the given shader program and rendering mode.
			virtual Pointer<ShaderPass> createShaderPass( const Pointer<ShaderProgram>& program, const RenderMode& renderMode );
			
			
			
			
			/// Create and return a shader pass object for the given shader pass source code.
			virtual Pointer<ShaderPass> createShaderPass( const Pointer<ShaderPassSource>& shaderPassSource );
			
			
			
			
			/// Create and return a shader pass object for the given generic shader pass.
			virtual Pointer<ShaderPass> createShaderPass( const GenericShaderPass& genericShaderPass );
			
			
			
			
			/// Return a pointer to the most compatible shader pass source for the specified generic shader pass.
			virtual Pointer<ShaderPassSource> getBestShaderPassSource( const GenericShaderPass& genericShaderPass );
			
			
			
			
			/// Create and return a default shader pass source object for the given shader pass usage.
			virtual Pointer<ShaderPassSource> getDefaultShaderPassSource( const ShaderPassUsage& usage );
			
			
			
			
			/// Create and return a default shader pass object for the given shader pass usage.
			virtual Pointer<ShaderPass> createDefaultShaderPass( const ShaderPassUsage& usage );
			
			
			
			
			/// Recompile the specified shader pass object with the current state of its parameter configuration.
			virtual Bool recompileShaderPass( const Pointer<ShaderPass>& shaderPass );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Wrapper Class Declaration
			
			
			
			
			/// A class which wraps platform-specific state for this OpenGL context.
			class Wrapper;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Friend Class Declaration
			
			
			
			
			/// Declare the OpenGLDevice class as a friend so that it can create instances of this class.
			friend class OpenGLDevice;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructors
			
			
			
			
			/// Create a new OpenGL context which most closely matches the specified pixel format and flags.
			/**
			  * This constructor allows the user to share another context's resources with
			  * this context.
			  */
			OpenGLContext( const Pointer<RenderView>& targetView, const RenderedPixelFormat& pixelFormat,
							const GraphicsContextFlags& flags );
			
			
			
			
			/// Doesn't do anthing because you can't 'copy' OpenGL contexts.
			OpenGLContext( const OpenGLContext& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Assignment Operator
			
			
			
			
			/// Doesn't do anthing because you can't 'assign' OpenGL contexts.
			OpenGLContext& operator = ( const OpenGLContext& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Initialization Methods
			
			
			
			
			/// Initialize the OpenGL state to a reasonable default.
			void initializeOpenGL();
			
			
			
			
			/// Determine the capabilities of this OpenGL context and store the result.
			void determineCapabilities();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Binding Methods
			
			
			
			
			/// Bind the specified shader pass to the current draw context.
			Bool bindShaderPass( const ShaderPass& shaderPass, const ShaderBindingData* shaderData );
			
			
			
			
			/// Submit the specified constant binding to the current OpenGL state.
			RIM_FORCE_INLINE void submitConstantBinding( const ConstantVariable& binding, const void* value );
			
			
			
			
			/// Submit the specified texture binding to the current OpenGL state.
			RIM_FORCE_INLINE void submitTextureBinding( const TextureVariable& variable, Index& textureUnit,
														const Resource<Texture>* textures );
			
			
			
			
			/// Submit the specified vertex binding to the current OpenGL state.
			RIM_FORCE_INLINE void submitVertexBinding( const VertexBinding& binding, const Pointer<VertexBuffer>* buffers );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Render Mode Helper Methods
			
			
			
			
			/// Update the current OpenGL pipeline with the specified render mode.
			RIM_FORCE_INLINE Bool updateRenderMode( const RenderMode& newRenderMode, Bool forceSet = false );
			
			
			
			
			/// Update the current OpenGL pipeline with the specified render mode.
			/**
			  * This variant doesn't bother to update any pipeline state if the
			  * flag associated with that state is not enabled. For example, if
			  * blending is disabled, its state will not be updated, increasing performance.
			  */
			RIM_FORCE_INLINE Bool updateRenderModeFast( const RenderMode& newRenderMode );
			
			
			
			
			/// Update the current OpenGL pipeline with the specified render mode.
			RIM_FORCE_INLINE Bool updateRenderFlags( RenderFlags newFlags, Bool forceSet = false );
			
			
			
			
			/// Update the current OpenGL pipeline with the specified rasterization mode.
			RIM_FORCE_INLINE Bool updateRasterMode( const RasterMode& newRasterMode, Bool forceSet = false );
			
			
			
			
			/// Update the current OpenGL pipeline with the specified depth mode.
			RIM_FORCE_INLINE Bool updateDepthMode( const DepthMode& newDepthMode, Bool forceSet = false );
			
			
			
			
			/// Update the current OpenGL pipeline with the specified stencil mode.
			RIM_FORCE_INLINE Bool updateStencilMode( const StencilMode& newStencilMode, Bool forceSet = false );
			
			
			
			
			/// Update the current OpenGL pipeline with the specified blend mode.
			RIM_FORCE_INLINE Bool updateBlendMode( const BlendMode& newBlendMode, Bool forceSet = false );
			
			
			
			
			/// Update the current OpenGL pipeline with the specified alpha test.
			RIM_FORCE_INLINE Bool updateAlphaTest( const AlphaTest& newAlphaTest, Bool forceSet = false );
			
			
			
			
			/// Update the current OpenGL pipeline with the specified line width.
			RIM_FORCE_INLINE Bool updateLineWidth( Float newLineWidth, Bool forceSet = false );
			
			
			
			
			/// Update the current OpenGL pipeline with the specified point size.
			RIM_FORCE_INLINE Bool updatePointSize( Float newPointSize, Bool forceSet = false );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Uniform Specification Helper Methods
			
			
			
			
			/// Submit an integer uniform value with the specified variable location, array size, and type.
			RIM_FORCE_INLINE static void glUniformInt( ShaderVariableLocation location, Size count, const AttributeType& type, const GLint* value );
			
			
			
			
			/// Submit a floating point uniform value with the specified variable location, array size, and type.
			RIM_FORCE_INLINE static void glUniformFloat( ShaderVariableLocation location, Size count, const AttributeType& type, const GLfloat* value );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private OpenGL Enum Conversion Methods
			
			
			
			
			/// Convert the specified primitive type to an OpenGL index type enum.
			RIM_FORCE_INLINE static Bool getOpenGLIndexType( const PrimitiveType& type,
															OpenGLEnum& glIndexType );
			
			
			
			
			/// Convert the specified primitive type to an OpenGL primitve type enum.
			RIM_FORCE_INLINE static Bool getOpenGLPrimitiveType( const PrimitiveType& type,
																OpenGLEnum& glPrimitiveType );
			
			
			
			
			/// Convert the specified indexed primitive type to an OpenGL indexed primitve type enum.
			RIM_FORCE_INLINE static Bool getOpenGLIndexedPrimitiveType( const IndexedPrimitiveType& type,
																		OpenGLEnum& glPrimitiveType );
			
			
			
			
			/// Convert the specified stencil action to an OpenGL stencil action enum.
			RIM_FORCE_INLINE static Bool getOpenGLStencilAction( const StencilAction& action,
																OpenGLEnum& glStencilAction );
			
			
			
			
			/// Convert the specified blend factor to an OpenGL blend factor enum.
			RIM_FORCE_INLINE static Bool getOpenGLBlendFactor( const BlendFactor& factor,
															OpenGLEnum& glBlendFactor );
			
			
			
			
			/// Convert the specified blend function to an OpenGL blend function enum.
			RIM_FORCE_INLINE static Bool getOpenGLBlendFunction( const BlendFunction& function,
																OpenGLEnum& glBlendFunction );
			
			
			
			
			/// Convert the specified alpha test to an OpenGL alpha test enum.
			RIM_FORCE_INLINE static Bool getOpenGLAlphaTest( const AlphaTest& test,
															OpenGLEnum& glAlphaTest );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Return whether or not this OpenGL context supports the specified shading language.
			Bool supportsShaderLanguage( const ShaderLanguage& language );
			
			
			
			
			/// Return the combined GLSL version number for use in the #version preprocessor define.
			RIM_INLINE static Int getGLSLVersionNumber( const ShaderLanguageVersion& languageVersion );
			
			
			
			
			/// Create a shader pass using the specified compiled program and shader pass source code.
			Pointer<ShaderPass> createShaderPass( const Pointer<ShaderProgram>& program,
												const Pointer<ShaderPassSource>& source );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to a class which wraps this OpenGL context's internal platform-specific state.
			Wrapper* wrapper;
			
			
			
			
			/// An object representing the pixel format for the OpenGL context's main framebuffer.
			RenderedPixelFormat pixelFormat;
			
			
			
			
			/// An object representing the flags for the OpenGL context.
			GraphicsContextFlags flags;
			
			
			
			
			/// An object describing the capabilities of this OpenGL context.
			GraphicsContextCapabilities capabilities;
			
			
			
			
			/// The major version number of this OpenGL context.
			Index majorVersion;
			
			
			
			
			/// The minor version number of this OpenGL context.
			Index minorVersion;
			
			
			
			
			/// The highest supported GLSL version for this OpenGL context.
			ShaderLanguageVersion glslVersion;
			
			
			
			
			/// A pointer to the target view for this OpenGL context.
			Pointer<RenderView> targetView;
			
			
			
			
			/// An object representing the current viewport for this OpenGL context.
			Viewport viewport;
			
			
			
			
			/// An object representing the scissor test for this OpenGL context.
			ScissorTest scissorTest;
			
			
			
			
			/// An object representing the current render mode of this OpenGL context.
			RenderMode renderMode;
			
			
			
			
			/// The OpenGL ID for the current shader program.
			OpenGLID currentShaderID;
			
			
			
			
			/// A pointer to the currently bound framebuffer object.
			Pointer<Framebuffer> currentFramebuffer;
			
			
			
			
			/// A string buffer used to accumulate the final shader source code strings.
			StringBuffer sourceBuffer;
			
			
			
			
			/// A pointer to an object that contains a library of default shader passes.
			Pointer<ShaderPassLibrary> defaultShaderPassLibrary;
			
			
			
			
			/// A default 1D placeholder texture, a 1 pixel white square.
			Resource<Texture> defaultTexture1D;
			
			
			
			
			/// A default 2D placeholder texture, a 1x1 pixel white square.
			Resource<Texture> defaultTexture2D;
			
			
			
			
			/// A default 3D placeholder texture, a 1x1x1 pixel white square.
			Resource<Texture> defaultTexture3D;
			
			
			
			
			/// A default 2D placeholder depth texture, a 1x1 pixel square with depth = 1.
			Resource<Texture> defaultDepthTexture2D;
			
			
			
			
			/// A default cube map placeholder texture, a 1x1 pixel white cube.
			Resource<Texture> defaultTextureCube;
			
			
			
			
			/// A default cube map placeholder depth texture, a 1x1 pixel cube with depth = 1.
			Resource<Texture> defaultDepthTextureCube;
			
			
			
};




//##########################################################################################
//********************  End Rim Graphics Devices OpenGL Namespace  *************************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_OPENGL_CONTEXT_H
