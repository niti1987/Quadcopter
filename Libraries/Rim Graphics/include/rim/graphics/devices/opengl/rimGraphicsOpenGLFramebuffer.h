/*
 *  rimGraphicsOpenGLFramebuffer.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/11/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_OPENGL_FRAMEBUFFER_H
#define INCLUDE_RIM_GRAPHICS_OPENGL_FRAMEBUFFER_H


#include "rimGraphicsOpenGLConfig.h"


//##########################################################################################
//********************  Start Rim Graphics Devices OpenGL Namespace  ***********************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which enables render-to-texture for OpenGL by specifying textures and their attachment points.
class OpenGLFramebuffer : public Framebuffer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this framebuffer and all associated state.
			~OpenGLFramebuffer();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Target Texture Accessor Methods
			
			
			
			
			/// Return the total number of attached target textures for this framebuffer.
			virtual Size getTargetCount() const;
			
			
			
			
			/// Return the total number of attached target textures with the specified attachment type for this framebuffer.
			virtual Size getTargetCount( FramebufferAttachment::Type attachmentType ) const;
			
			
			
			
			/// Return the texture which is attached at the specified framebuffer attachment point.
			/**
			  * If there is no target texture for that attachment point, a NULL texture resource
			  * is returned.
			  */
			virtual Resource<Texture> getTarget( const FramebufferAttachment& attachment ) const;
			
			
			
			
			/// Return whether or not this framebuffer has a valid texture attached to the specified attachment point.
			virtual Bool hasTarget( const FramebufferAttachment& attachment ) const;
			
			
			
			
			/// Set the target texture for the specified framebuffer attachment point.
			/**
			  * If the specified Texture is valid and supports the specified texture face,
			  * and if the specified attachment point is supported and valid, the texture
			  * is used as the target for the specified attachment point and TRUE is returned
			  * indicating success. Otherwise, FALSE is returned indicating failure, leaving
			  * the framebuffer unchanged.
			  */
			virtual Bool setTarget( const FramebufferAttachment& attachment, const Resource<Texture>& newTarget,
									TextureFace face = TextureFace::FRONT );
			
			
			
			
			/// Remove any previously attached texture from the specified framebuffer attachment point.
			/**
			  * If a texture was successfully removed, TRUE is returned. Otherwise, FALSE is
			  * returned, indicating that no texture target was removed.
			  */
			virtual Bool removeTarget( const FramebufferAttachment& attachment );
			
			
			
			
			/// Remove all attached target textures with the specified attachment type from this framebuffer.
			virtual void removeTargets( FramebufferAttachment::Type attachmentType );
			
			
			
			
			/// Remove all attached target textures from this framebuffer.
			virtual void clearTargets();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Target Texture Face Accessor Methods
			
			
			
			
			/// Return an object representing which face of the texture at the specified attachment point is being used.
			/**
			  * If there is no texture at that attachment point, and UNDEFINED texture face
			  * is returned. Otherwise, the texture face that is being used is returned.
			  * This will be FRONT, unless the texture is a cube map.
			  */
			virtual TextureFace getTargetFace( const FramebufferAttachment& attachment );
			
			
			
			
			/// Set the face of the texture at the specified attachment point that is being used.
			/**
			  * If there is no texture at that attachment point or if the attached texture
			  * doesn't support the specified face type, FALSE is returned and the target
			  * face is not changed. Otherwise, the framebuffer uses the specified texture
			  * face for the attachment point and returns TRUE.
			  */
			virtual Bool setTargetFace( const FramebufferAttachment& attachment, TextureFace newFace );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Framebuffer Size Accessor Methods
			
			
			
			
			/// Return the minimum size of the framebuffer in pixels along the specified dimension index.
			/**
			  * This method finds the smallest size of the attached textures along the given dimension.
			  * Indices start from 0 and count to d-1 for a framebuffer with d dimensions.
			  * Since framebuffers are almost always 1D or 2D, dimension indices greater than 1 will
			  * result in a size of 1 being returned, since even a 1x1 framebuffer has a 3D depth
			  * of 1 pixel.
			  *
			  * If there are no attached textures, 0 is returned.
			  */
			virtual Size getMinimumSize( Index dimension ) const;
			
			
			
			
			/// Return the maximum size of the framebuffer in pixels along the specified dimension index.
			/**
			  * This method finds the largest size of the attached textures along the given dimension.
			  * Indices start from 0 and count to d-1 for a framebuffer with d dimensions.
			  * Since framebuffers are almost always 1D or 2D, dimension indices greater than 1 will
			  * result in a size of 1 being returned, since even a 1x1 framebuffer has a 3D depth
			  * of 1 pixel.
			  *
			  * If there are no attached textures, 0 is returned.
			  */
			virtual Size getMaximumSize( Index dimension ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Framebuffer Validity Accessor Method
			
			
			
			
			/// Return whether or not the framebuffer is valid and can be used as a render target.
			/**
			  * A framebuffer may not be valid if it has no target textures, has an incomplete
			  * set of target textures (missing a required attachment), or if some of the target textures
			  * have an unsupported format.
			  */
			virtual Bool isValid() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Framebuffer ID Accessor Method
			
			
			
			
			/// Get a unique integral identifier for this framebuffer.
			RIM_INLINE OpenGLID getID() const
			{
				return framebufferID;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Definitions
			
			
			
			
			/// A class which stores an association between a framebuffer attachment and its target texture.
			class Target
			{
				public:
					
					/// Create a new target texture which uses the specified texture and face for a framebuffer attachment.
					RIM_INLINE Target( const FramebufferAttachment& newAttachment,
										const Resource<Texture>& newTexture, TextureFace newFace )
						:	attachment( newAttachment ),
							texture( newTexture ),
							face( newFace )
					{
					}
					
					
					/// An object representing the location where this target is attached.
					FramebufferAttachment attachment;
					
					
					/// The texture which is to be used as the target for an attachment point.
					Resource<Texture> texture;
					
					
					/// An object indicating the face of the texture to use for the attachment point.
					TextureFace face;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Friend Class Declaration
			
			
			
			
			/// Declare the OpenGLContext class as a friend so that it can create instances of this class.
			friend class OpenGLContext;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructor
			
			
			
			
			/// Create an empty framebuffer for the specified context with no attachements.
			OpenGLFramebuffer( const GraphicsContext* context );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Bind the specified target texture and face to the specified attachment point of the OpenGL FBO.
			/**
			  * The method returns whether or not the bind operation was successful.
			  */
			Bool bindTarget( const FramebufferAttachment& attachment,
							const Resource<Texture>& newTarget, TextureFace face );
			
			
			
			
			/// Unbind the specified target texture from a framebuffer attachment point.
			void unbindTarget( const Target& target );
			
			
			
			
			/// Update and inform OpenGL of the buffers that should be drawn to.
			void updateDrawBufferStatus();
			
			
			
			
			/// Find the index of any target texture for the specified attachment point.
			RIM_FORCE_INLINE Bool findTargetForAttachment( const FramebufferAttachment& attachment, Index& index ) const;
			
			
			
			
			/// Get the OpenGL enum value for the specified cube map face.
			RIM_INLINE static Bool getGLCubeMapFace( const TextureFace& face, OpenGLEnum& glFace );
			
			
			
			
			/// Get the OpenGL enum value for the specified attachment point.
			RIM_INLINE static Bool getGLAttachmentPoint( const FramebufferAttachment& attachment,
														OpenGLEnum& glAttachment );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The OpenGL ID for the framebuffer object associated with this Framebuffer.
			OpenGLID framebufferID;
			
			
			
			
			/// A list of targets associated with this framebuffer.
			ArrayList<Target> targets;
			
			
			
};




//##########################################################################################
//********************  End Rim Graphics Devices OpenGL Namespace  *************************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_OPENGL_FRAMEBUFFER_H
