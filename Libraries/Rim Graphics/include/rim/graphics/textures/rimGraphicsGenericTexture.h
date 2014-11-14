/*
 *  rimGraphicsGenericTexture.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/26/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GENERIC_TEXTURE_H
#define INCLUDE_RIM_GRAPHICS_GENERIC_TEXTURE_H


#include "rimGraphicsTexturesConfig.h"


#include "rimGraphicsTextureFormat.h"
#include "rimGraphicsTextureFilterType.h"
#include "rimGraphicsTextureWrapType.h"
#include "rimGraphicsTextureFace.h"
#include "rimGraphicsTextureType.h"


//##########################################################################################
//**********************  Start Rim Graphics Textures Namespace  ***************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents an image with associated sampling parameters.
/**
  * A texture can be either 1D, 2D, 3D, or a cube map (six 2D faces), with
  * any common texture format (Alpha, Gray, RGB, RGBA, etc.).
  */
class GenericTexture
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a 1D texture object with the specified pixel type and width and no pixel data.
			GenericTexture();
			
			
			
			
			/// Create a 1D or cube-map texture object with the specified pixel type and width and no pixel data.
			GenericTexture( Size width, Bool isCubeMap = false );
			
			
			
			
			/// Create a 2D texture object with the specified pixel type, width and height and no pixel data.
			GenericTexture( Size width, Size height );
			
			
			
			
			/// Create a 3D texture object with the specified pixel type, width, height and depth and no pixel data.
			GenericTexture( Size width, Size height, Size depth );
			
			
			
			
			/// Create a new texture object with the specified image for its front face.
			GenericTexture( const Resource<Image>& newImage );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return the number of dimensions in this texture, usually 1, 2, or 3.
			RIM_INLINE Size getDimensionCount() const
			{
				return numDimensions;
			}
			
			
			
			
			/// Return the size of the texture along the X direction (dimension 0).
			RIM_INLINE Size getWidth() const
			{
				return size[0];
			}
			
			
			
			
			/// Return the size of the texture along the Y direction (dimension 1).
			RIM_INLINE Size getHeight() const
			{
				return size[1];
			}
			
			
			
			
			/// Return the size of the texture along the Z direction (dimension 2).
			RIM_INLINE Size getDepth() const
			{
				return size[2];
			}
			
			
			
			
			/// Return the size of the texture along the specified dimension index.
			/**
			  * Indices start from 0 and count to d-1 for a texture with d dimensions.
			  * The method returns a size of 1 for all out-of-bounds dimensions.
			  */
			RIM_INLINE Size getSize( Index dimension ) const
			{
				if ( numDimensions == 0 )
					return 0;
				else if ( dimension >= numDimensions )
					return 1;
				else
					return size[dimension];
			}
			
			
			
			
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
				return faces.getSize();
			}
			
			
			
			
			/// Return whether or not this texture is a cube map texture.
			RIM_INLINE Bool isACubeMap() const
			{
				return cubeMap;
			}
			
			
			
			
			/// Return whether or not the specified face is valid for this texture.
			RIM_INLINE Bool isValidFace( TextureFace face ) const
			{
				return face == TextureFace::FRONT || cubeMap;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Data Accessor Methods
			
			
			
			
			/// Get the texture's image data for the specified face index.
			/**
			  * If the face type is not equal to TextureFace::FRONT and the texture is not a cube map
			  * texture, an empty image with UNDEFINED pixel type is returned.
			  */
			Bool getImage( Resource<Image>& image, TextureFace face = TextureFace::FRONT, Index mipmapLevel = 0 ) const;
			
			
			
			
			/// Replace the current contents of the texture with the specified image.
			/**
			  * If the image's pixel type is not compatable with the current type of the
			  * texture, or if the face index is not equal to TextureFace::FRONT and the texture
			  * is not a cube map texture, or if an invalid mipmap level is specified,
			  * FALSE is returned indicating failure and the method has no effect.
			  * Otherwise, the method succeeds and TRUE is returned.
			  */
			Bool setImage( const Resource<Image>& newImage, TextureFace face = TextureFace::FRONT, Index mipmapLevel = 0 );
			
			
			
			
			/// Update a region of the texture with the specified image.
			RIM_INLINE Bool updateImage( const Resource<Image>& newImage, Int position,
										TextureFace face = TextureFace::FRONT, Index mipmapLevel = 0 )
			{
				return this->updateImage( newImage, Vector3i( position, 0, 0 ), face, mipmapLevel );
			}
			
			
			
			
			/// Update a region of the texture with the specified image.
			RIM_INLINE Bool updateImage( const Resource<Image>& newImage, const Vector2i& position,
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
			Bool updateImage( const Resource<Image>& newImage, const Vector3i& position,
							TextureFace face = TextureFace::FRONT, Index mipmapLevel = 0 );
			
			
			
			
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
			Bool clear( Float channelColor, TextureFace face = TextureFace::FRONT,
						Index mipmapLevel = 0 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Wrap Type Accessor Methods
			
			
			
			
			/// Get the type of texture wrapping to do when texture coordinates are outside of the range [0,1].
			RIM_INLINE TextureWrapType getWrapType() const
			{
				return wrapType;
			}
			
			
			
			
			/// Set the type of texture wrapping to do when texture coordinates are outside of the range [0,1].
			RIM_INLINE void setWrapType( const TextureWrapType& newWrapType )
			{
				wrapType = newWrapType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Minification Filter Type Accessor Methods
			
			
			
			
			/// Get the type of texture filtering which is used when the texture is reduced in size.
			RIM_INLINE TextureFilterType getMinificationFilterType() const
			{
				return minificationFilterType;
			}
			
			
			
			
			/// Set the type of texture filtering which is used when the texture is reduced in size.
			RIM_INLINE void setMinificationFilterType( const TextureFilterType& newMinificationFilterType )
			{
				minificationFilterType = newMinificationFilterType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Magnification Filter Type Accessor Methods
			
			
			
			
			/// Return the type of texture filtering which is used when the texture is increased in size.
			RIM_INLINE TextureFilterType getMagnificationFilterType() const
			{
				return magnificationFilterType;
			}
			
			
			
			
			/// Set the type of texture filtering which is used when the texture is increased in size.
			RIM_INLINE void setMagnificationFilterType( const TextureFilterType& newMagnificationFilterType )
			{
				magnificationFilterType = newMagnificationFilterType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mipmap Accessor Methods
			
			
			
			
			/// Return the number of mipmaps that there are for the specified texture face.
			/**
			  * This number includes the main mipmap level 0.
			  */
			RIM_INLINE Size getMipmapCount( const TextureFace& face = TextureFace::FRONT ) const
			{
				if ( (Index)face < faces.getSize() )
					return faces[(Index)face].mipmaps.getSize();
				else
					return 0;
			}
			
			
			
			
			
			/// Generate smaller mipmaps of the texture from the largest texture image (level 0).
			/**
			  * This method automatically scales down the largest mipmap level (level 0) for
			  * each of the smaller mipmap levels (>1), replacing any previous mipmap information.
			  */
			Bool generateMipmaps();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Format Accessor Methods
			
			
			
			
			/// Return whether or not this generic texture has any face images that have an alpha channel.
			Bool hasAlpha() const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A class which stores information for a single face of a texture.
			class Face
			{
				public:
					
					
					/// A list of the mipmaps for this texture face.
					ShortArrayList< Resource<Image>, 1 > mipmaps;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The maximum number of dimensions that this texture can have.
			static const Size MAX_DIMENSION_COUNT = 3;
			
			
			
			
			/// The maximum number of faces that this texture can have.
			static const Size MAX_FACE_COUNT = 6;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The texture filtering type to use when reducing the size of a texture.
			TextureFilterType minificationFilterType;
			
			
			
			
			/// The texture filtering type to use when increasing the size of a texture.
			TextureFilterType magnificationFilterType;
			
			
			
			
			/// The type of texture wrapping to apply for texture coordinates outside the range [0,1].
			TextureWrapType wrapType;
			
			
			
			
			/// An integer value indicating the dimension of this texture (usually 1, 2 or 3).
			Size numDimensions;
			
			
			
			
			/// A boolean value indicating whether or not this texture is a cube map.
			Bool cubeMap;
			
			
			
			
			/// A fixed-size array which stores the size of this texture along each axis.
			StaticArray<Size,MAX_DIMENSION_COUNT> size;
			
			
			
			
			/// An array of the faces for this texture. Cube maps use 6 faces while other textures only use the first.
			Array<Face> faces;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Textures Namespace  *****************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GENERIC_TEXTURE_H
