/*
 *  rimGraphicsTexture.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_TEXTURE_H
#define INCLUDE_RIM_GRAPHICS_TEXTURE_H


#include "rimGraphicsTexturesConfig.h"


#include "rimGraphicsTextureFormat.h"
#include "rimGraphicsTextureFilterType.h"
#include "rimGraphicsTextureWrapType.h"
#include "rimGraphicsTextureFace.h"


//##########################################################################################
//**********************  Start Rim Graphics Textures Namespace  ***************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents an image stored on the graphics hardware.
/**
  * A texture can be either 1D, 2D, 3D, or a cube map (six 2D faces), with
  * any common texture format (Alpha, Gray, RGB, RGBA, etc.).
  */
class Texture : public ContextObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return the number of dimensions in this texture, usually 1, 2, or 3.
			virtual Size getDimensionCount() const = 0;
			
			
			
			
			/// Return the size of the texture along the X direction (dimension 0).
			RIM_INLINE Size getWidth() const
			{
				return this->getSize( 0 );
			}
			
			
			
			
			/// Return the size of the texture along the Y direction (dimension 1).
			RIM_INLINE Size getHeight() const
			{
				return this->getSize( 1 );
			}
			
			
			
			
			/// Return the size of the texture along the Z direction (dimension 2).
			RIM_INLINE Size getDepth() const
			{
				return this->getSize( 2 );
			}
			
			
			
			
			/// Return the size of the texture along the specified dimension index.
			/**
			  * Indices start from 0 and count to d-1 for a texture with d dimensions.
			  * The method returns a size of 1 for all out-of-bounds dimensions.
			  */
			virtual Size getSize( Index dimension ) const = 0;
			
			
			
			
			/// Return the total number of texels in the texture.
			Size getTexelCount() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Face Accessor Methods
			
			
			
			
			/// Return the number of faces that this texture has.
			/**
			  * A normal texture will have 1 face, while a cube map texture will have
			  * 6 faces.
			  */
			RIM_INLINE Size getFaceCount() const
			{
				if ( this->isACubeMap() )
					return 6;
				else
					return 1;
			}
			
			
			
			
			/// Return whether or not this texture is a cube map texture.
			virtual Bool isACubeMap() const = 0;
			
			
			
			
			/// Return whether or not the specified face is valid for this texture.
			RIM_INLINE Bool isValidFace( TextureFace face ) const
			{
				return face == TextureFace::FRONT || this->isACubeMap();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Format Accessor Method
			
			
			
			
			/// Return a object which represents the internal storage format for the texture.
			virtual TextureFormat getFormat() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Data Accessor Methods
			
			
			
			
			/// Get the texture's image data for the specified face index with the data in the default pixel type.
			/**
			  * If the face type is not equal to TextureFace::FRONT and the texture is not a cube map
			  * texture, the method can fail and FALSE is returned. Otherwise, the method succeeds and
			  * TRUE is returned.
			  */
			RIM_INLINE Bool getImage( Image& image, TextureFace face = TextureFace::FRONT, Index mipmapLevel = 0 ) const
			{
				return this->getImage( image, this->getFormat().getPixelFormat(), face, mipmapLevel );
			}
			
			
			
			
			/// Get the texture's image data for the specified face index with the data in the specified pixel type.
			/**
			  * If the face type is not equal to TextureFace::FRONT and the texture is not a cube map
			  * texture, an empty image with UNDEFINED pixel type is returned.
			  */
			virtual Bool getImage( Image& image, const PixelFormat& pixelType,
									TextureFace face = TextureFace::FRONT, Index mipmapLevel = 0 ) const = 0;
			
			
			
			
			/// Replace the current contents of the texture with the specified image.
			/**
			  * If the image's pixel type is not compatable with the current type of the
			  * texture, or if the face index is not equal to TextureFace::FRONT and the texture
			  * is not a cube map texture, or if an invalid mipmap level is specified,
			  * FALSE is returned indicating failure and the method has no effect.
			  * Otherwise, the method succeeds and TRUE is returned.
			  */
			RIM_INLINE Bool setImage( const Image& newImage, TextureFace face = TextureFace::FRONT,
										Index mipmapLevel = 0 )
			{
				return this->setImage( newImage, TextureFormat(newImage.getPixelFormat()), face, mipmapLevel );
			}
			
			
			
			
			/// Replace the current contents of the texture with the specified image.
			/**
			  * If the image's pixel type is not compatable with the current type of the
			  * texture, or if the face index is not equal to TextureFace::FRONT and the texture
			  * is not a cube map texture, or if an invalid mipmap level is specified,
			  * FALSE is returned indicating failure and the method has no effect.
			  * Otherwise, the method succeeds and TRUE is returned.
			  */
			virtual Bool setImage( const Image& newImage, TextureFormat newTextureFormat,
									TextureFace face = TextureFace::FRONT, Index mipmapLevel = 0 ) = 0;
			
			
			
			
			/// Update a region of the texture with the specified image.
			RIM_INLINE Bool updateImage( const Image& newImage, Int position,
										TextureFace face = TextureFace::FRONT, Index mipmapLevel = 0 )
			{
				return this->updateImage( newImage, Vector3i( position, 0, 0 ), face, mipmapLevel );
			}
			
			
			
			
			/// Update a region of the texture with the specified image.
			RIM_INLINE Bool updateImage( const Image& newImage, const Vector2i& position,
										TextureFace face = TextureFace::FRONT, Index mipmapLevel = 0 )
			{
				return this->updateImage( newImage, Vector3i( position, 0 ), face, mipmapLevel );
			}
			
			
			
			
			/// Update a region of the texture with the specified image.
			/**
			  * This method replaces some of the pixels that are currently part of the texture
			  * with the pixels stored in the specified image. The texture is replaced with the
			  * image starting at the specified position in pixels from its lower left corner.
			  * 
			  * If the updated pixels will lie outside of the texture's area, or if the
			  * image's pixel type is not compatable with the current type of the
			  * texture, or if the face index is not equal to TextureFace::FRONT and the texture
			  * is not a cube map texture, FALSE is returned indicating failure and the method
			  * has no effect. Otherwise, the method succeeds and TRUE is returned.
			  */
			virtual Bool updateImage( const Image& newImage, const Vector3i& position,
									TextureFace face = TextureFace::FRONT, Index mipmapLevel = 0 ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Clear Method
			
			
			
			
			/// Clear this texture's image using the specified clear color component for the given face and mipmap level.
			/**
			  * This method initializes every texel of the texture with the specified
			  * color component for every texture component.
			  *
			  * The method returns whether or not the clear operation was successful.
			  */
			virtual Bool clear( Float channelColor, TextureFace face = TextureFace::FRONT,
								Index mipmapLevel = 0 ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Wrap Type Accessor Methods
			
			
			
			
			/// Get the type of texture wrapping to do when texture coordinates are outside of the range [0,1].
			virtual TextureWrapType getWrapType() const = 0;
			
			
			
			
			/// Set the type of texture wrapping to do when texture coordinates are outside of the range [0,1].
			virtual Bool setWrapType( const TextureWrapType& newWrapType ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Minification Filter Type Accessor Methods
			
			
			
			
			/// Get the type of texture filtering which is used when the texture is reduced in size.
			virtual TextureFilterType getMinificationFilterType() const = 0;
			
			
			
			
			/// Set the type of texture filtering which is used when the texture is reduced in size.
			virtual Bool setMinificationFilterType( const TextureFilterType& newMinificationFilterType ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Magnification Filter Type Accessor Methods
			
			
			
			
			/// Get the type of texture filtering which is used when the texture is increased in size.
			virtual TextureFilterType getMagnificationFilterType() const = 0;
			
			
			
			
			/// Set the type of texture filtering which is used when the texture is increased in size.
			virtual Bool setMagnificationFilterType( const TextureFilterType& newMagnificationFilterType ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mipmap Accessor Methods
			
			
			
			
			/// Generate smaller mipmaps of the texture from the largest texture image (level 0).
			/**
			  * This method automatically scales down the largest mipmap level (level 0) for
			  * each of the smaller mipmap levels (>1), replacing any previous mipmap information.
			  */
			virtual Bool generateMipmaps() = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Residency Accessor Methods
			
			
			
			
			/// Return whether or not the texture is currently in memory on the GPU.
			virtual Bool isResident() const = 0;
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Constructor
			
			
			
			
			/// Create a new texture which is associated with the specified graphics context.
			RIM_INLINE Texture( const devices::GraphicsContext* newContext )
				:	ContextObject( newContext )
			{
			}
			
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Textures Namespace  *****************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_TEXTURE_H
