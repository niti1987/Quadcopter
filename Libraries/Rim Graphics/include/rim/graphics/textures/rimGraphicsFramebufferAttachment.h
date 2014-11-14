/*
 *  rimGraphicsFramebufferAttachment.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 10/8/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_FRAMEBUFFER_ATTACHMENT_H
#define INCLUDE_RIM_GRAPHICS_FRAMEBUFFER_ATTACHMENT_H


#include "rimGraphicsTexturesConfig.h"


#include "rimGraphicsTextureFormat.h"


//##########################################################################################
//**********************  Start Rim Graphics Textures Namespace  ***************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies how a texture should be attached to a Framebuffer.
/**
  * Since a framebuffer has multiple kinds of bitplanes that can be rendered to,
  * it is necessary to specify how each texture that is attached to the framebuffer
  * is used. The 3 basic types of attachment points are color, depth, and stencil
  * attachments.
  */
class FramebufferAttachment
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Enum Declaration
			
			
			
			
			/// An enum which specifies the different types of framebuffer attachment points.
			typedef enum Type
			{
				/// An attachment point that is for a color texture.
				/**
				  * There can be multiple color attachment points (implementation defined maximum).
				  */
				COLOR,
				
				/// An attachment point that is for a depth texture.
				/**
				  * There can be only 1 depth attachment point which has index 0.
				  */
				DEPTH,
				
				/// An attachment point that is for a stencil texture.
				/**
				  * There can be only 1 stencil attachment point which has index 0.
				  */
				STENCIL,
				
				/// An undefined attachment point type.
				UNDEFINED
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new framebuffer attachment type with the specified type enum value and index 0.
			RIM_INLINE FramebufferAttachment( Type newType )
				:	type( newType ),
					index( 0 )
			{
			}
			
			
			
			
			/// Create a new framebuffer attachment type with the specified type enum value and index.
			/**
			  * If the specified attachment type is not COLOR, the specified index value is automatically
			  * set to 0 because multiple depth or stencil attachments are not supported.
			  */
			RIM_INLINE FramebufferAttachment( Type newType, Index newIndex )
				:	type( newType ),
					index( newType == COLOR ? newIndex : 0 )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attachment Type Accessor Methods
			
			
			
			
			/// Return the type of attachment point that this object refers to.
			RIM_INLINE Type getType() const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attachment Index Accessor Methods
			
			
			
			
			/// Return the index of the attachment point.
			/**
			  * This value allows the user to specify multiple color attachments.
			  * Multiple depth or stencil attachments are not supported, index 0 is
			  * the only allowed value.
			  */
			RIM_INLINE Index getIndex() const
			{
				return index;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this framebuffer attachment point is equal to another.
			RIM_INLINE Bool operator == ( const FramebufferAttachment& other ) const
			{
				return type == other.type && index == other.index;
			}
			
			
			
			
			/// Return whether or not this framebuffer attachment point is not equal to another.
			RIM_INLINE Bool operator != ( const FramebufferAttachment& other ) const
			{
				return type != other.type || index != other.index;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this framebuffer attachment point supports the specified texture format.
			Bool supportsFormat( TextureFormat format ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the framebuffer attachement type.
			String toString() const;
			
			
			
			
			/// Convert this framebuffer attachement type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Hash Code Accessor Methods
			
			
			
			
			/// Return a hash code generated for this framebuffer attachment point.
			RIM_INLINE Hash getHashCode() const
			{
				return Hash(type)*Hash(0x8DA6B343) ^ Hash(index)*Hash(0xD8163841);
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value which represents the texture face type.
			Type type;
			
			
			
			
			/// A value indicating the index of the framebuffer attachment point.
			/**
			  * This value allows the user to specify multiple color attachments.
			  * Multiple depth or stencil attachments are not supported, index 0 is
			  * the only allowed value.
			  */
			Index index;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Textures Namespace  *****************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_FRAMEBUFFER_ATTACHMENT_H
