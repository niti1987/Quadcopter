/*
 *  rimGraphicsFramebuffer.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 10/8/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_FRAMEBUFFER_H
#define INCLUDE_RIM_GRAPHICS_FRAMEBUFFER_H


#include "rimGraphicsTexturesConfig.h"


#include "rimGraphicsTexture.h"
#include "rimGraphicsTextureFace.h"
#include "rimGraphicsFramebufferAttachment.h"


//##########################################################################################
//**********************  Start Rim Graphics Textures Namespace  ***************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which enables render-to-texture by specifying textures and their attachment points.
/**
  * A Framebuffer object contains a set of associations between rendering framebuffer
  * attachment points and textures which are to be used for render-to-texture. This
  * framebuffer object can then be used as a render target, where the output of rendering
  * will be sent to the texture targets specified here rather than the main screen.
  */
class Framebuffer : public ContextObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Target Texture Accessor Methods
			
			
			
			
			/// Return the total number of attached target textures for this framebuffer.
			virtual Size getTargetCount() const = 0;
			
			
			
			
			/// Return the total number of attached target textures with the specified attachment type for this framebuffer.
			virtual Size getTargetCount( FramebufferAttachment::Type attachmentType ) const = 0;
			
			
			
			
			/// Return the texture which is attached at the specified framebuffer attachment point.
			/**
			  * If there is no target texture for that attachment point, a NULL texture resource
			  * is returned.
			  */
			virtual Resource<Texture> getTarget( const FramebufferAttachment& attachment ) const = 0;
			
			
			
			
			/// Return whether or not this framebuffer has a valid texture attached to the specified attachment point.
			virtual Bool hasTarget( const FramebufferAttachment& attachment ) const = 0;
			
			
			
			
			/// Set the target texture for the specified framebuffer attachment point.
			/**
			  * If the specified Texture is valid and supports the specified texture face,
			  * and if the specified attachment point is supported and valid, the texture
			  * is used as the target for the specified attachment point and TRUE is returned
			  * indicating success. Otherwise, FALSE is returned indicating failure, leaving
			  * the framebuffer unchanged.
			  */
			virtual Bool setTarget( const FramebufferAttachment& attachment, const Resource<Texture>& newTarget,
									TextureFace face = TextureFace::FRONT ) = 0;
			
			
			
			
			/// Remove any previously attached texture from the specified framebuffer attachment point.
			/**
			  * If a texture was successfully removed, TRUE is returned. Otherwise, FALSE is
			  * returned, indicating that no texture target was removed.
			  */
			virtual Bool removeTarget( const FramebufferAttachment& attachment ) = 0;
			
			
			
			
			/// Remove all attached target textures with the specified attachment type from this framebuffer.
			virtual void removeTargets( FramebufferAttachment::Type attachmentType ) = 0;
			
			
			
			
			/// Remove all attached target textures from this framebuffer.
			virtual void clearTargets() = 0;
			
			
			
			
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
			virtual TextureFace getTargetFace( const FramebufferAttachment& attachment ) = 0;
			
			
			
			
			/// Set the face of the texture at the specified attachment point that is being used.
			/**
			  * If there is no texture at that attachment point or if the attached texture
			  * doesn't support the specified face type, FALSE is returned and the target
			  * face is not changed. Otherwise, the framebuffer uses the specified texture
			  * face for the attachment point and returns TRUE.
			  */
			virtual Bool setTargetFace( const FramebufferAttachment& attachment, TextureFace newFace ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Framebuffer Size Accessor Methods
			
			
			
			
			/// Return the minimum size of the framebuffer in pixels along the X direction.
			/**
			  * This method finds the smallest size of the attached textures along the X direction.
			  *
			  * If there are no attached textures, 0 is returned.
			  */
			RIM_INLINE Size getWidth() const
			{
				return this->getSize( 0 );
			}
			
			
			
			
			/// Return the minimum size of the framebuffer in pixels along the Y direction.
			/**
			  * This method finds the smallest size of the attached textures along the Y direction.
			  *
			  * If there are no attached textures, 0 is returned.
			  */
			RIM_INLINE Size getHeight() const
			{
				return this->getSize( 1 );
			}
			
			
			
			
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
			RIM_INLINE Size getSize( Index dimension ) const
			{
				return this->getMinimumSize( dimension );
			}
			
			
			
			
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
			virtual Size getMinimumSize( Index dimension ) const = 0;
			
			
			
			
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
			virtual Size getMaximumSize( Index dimension ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Framebuffer Viewport Accessor Methods
			
			
			
			
			/// Return a 2D AABB object which covers the rectangular screen area shared by all target textures.
			/**
			  * If some of the target textures have different sizes, it uses the largest
			  * viewport, starting the lower left corner of all textures, where all textures
			  * have texels.
			  */
			RIM_INLINE AABB2f getViewport() const
			{
				return AABB2f( Float(0), Float(this->getWidth()), Float(0), Float(this->getHeight()) );
			}
			
			
			
			
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
			virtual Bool isValid() const = 0;
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Constructor
			
			
			
			
			/// Create an empty framebuffer for the given context with no attached textures.
			RIM_INLINE Framebuffer( const devices::GraphicsContext* context )
				:	ContextObject( context )
			{
			}
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Textures Namespace  *****************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_FRAMEBUFFER_H
