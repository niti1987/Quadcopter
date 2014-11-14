/*
 *  rimGraphicsOpenGLTexture.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/2/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_OPENGL_TEXTURE_H
#define INCLUDE_RIM_GRAPHICS_OPENGL_TEXTURE_H


#include "rimGraphicsOpenGLConfig.h"


//##########################################################################################
//********************  Start Rim Graphics Devices OpenGL Namespace  ***********************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_START
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
class OpenGLTexture : public Texture
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a texture and all resources associated with it.
			~OpenGLTexture();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return the number of dimensions in this texture, usually 1, 2, or 3.
			virtual Size getDimensionCount() const;

			
			
			
			/// Return the size of the texture along the specified dimension index.
			virtual Size getSize( Index dimension ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Type Accessor Methods
			
			
			
			
			/// Return whether or not this texture is a cube map texture.
			virtual Bool isACubeMap() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Format Accessor Method
			
			
			
			
			/// Return a object which represents the internal storage format for the texture.
			virtual TextureFormat getFormat() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Data Accessor Methods
			
			
			
			
			/// Get the texture's image data for the specified face index with the data in the specified pixel type.
			virtual Bool getImage( Image& image, const PixelFormat& pixelType,
									TextureFace face = TextureFace::FRONT, Index mipmapLevel = 0 ) const;

			
			
			
			/// Replace the current contents of the texture with the specified image.
			virtual Bool setImage( const Image& newImage, TextureFormat newTextureFormat,
									TextureFace face = TextureFace::FRONT, Index mipmapLevel = 0 );

			
			
			
			/// Update a region of the texture with the specified image.
			virtual Bool updateImage( const Image& newImage, const Vector3i& position = Vector3i(),
									TextureFace face = TextureFace::FRONT, Index mipmapLevel = 0 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Clear Method
			
			
			
			
			/// Clear this texture's image using the specified clear color component for the given face and mipmap level.
			virtual Bool clear( Float channelColor, TextureFace face = TextureFace::FRONT,
								Index mipmapLevel = 0 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Wrap Type Accessor Methods
			
			
			
			
			/// Get the type of texture wrapping to do when texture coordinates are outside of the range [0,1].
			virtual TextureWrapType getWrapType() const;
			
			
			
			
			/// Set the type of texture wrapping to do when texture coordinates are outside of the range [0,1].
			virtual Bool setWrapType( const TextureWrapType& newWrapType );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Minification Filter Type Accessor Methods
			
			
			
			
			/// Get the type of texture filtering which is used when the texture is reduced in size.
			virtual TextureFilterType getMinificationFilterType() const;
			
			
			
			
			/// Set the type of texture filtering which is used when the texture is reduced in size.
			virtual Bool setMinificationFilterType( const TextureFilterType& newMinificationFilterType );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Magnification Filter Type Accessor Methods
			
			
			
			
			/// Get the type of texture filtering which is used when the texture is increased in size.
			virtual TextureFilterType getMagnificationFilterType() const;
			
			
			
			
			/// Set the type of texture filtering which is used when the texture is increased in size.
			virtual Bool setMagnificationFilterType( const TextureFilterType& newMagnificationFilterType );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mipmap Accessor Methods
			
			
			
			
			/// Generate smaller mipmaps of the texture from the largest texture image (level 0).
			virtual Bool generateMipmaps();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Residency Accessor Methods
			
			
			
			
			/// Return whether or not the texture is currently in memory on the GPU.
			virtual Bool isResident() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture ID Accessor Method
			
			
			
			
			/// Get a unique OpenGL integer identifier for this texture.
			RIM_INLINE OpenGLID getID() const
			{
				return textureID;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Friend Class Declaration
			
			
			
			
			/// Declare the OpenGLContext class as a friend so that it can create instances of this class.
			friend class OpenGLContext;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructors
			
			
			
			
			/// Create a 1D texture object with the specified pixel type and width and no pixel data.
			OpenGLTexture( const GraphicsContext* context );
			
			
			
			
			/// Create a 1D texture object with the specified pixel type and width and no pixel data.
			OpenGLTexture( const GraphicsContext* context, TextureFormat newTextureFormat,
							Size width, Bool isCubeMap = false );
			
			
			
			
			/// Create a 2D texture object with the specified pixel type, width and height and no pixel data.
			OpenGLTexture( const GraphicsContext* context, TextureFormat newTextureFormat,
							Size width, Size height );
			
			
			
			
			/// Create a 3D texture object with the specified pixel type, width, height and depth and no pixel data.
			OpenGLTexture( const GraphicsContext* context, TextureFormat newTextureFormat,
							Size width, Size height, Size depth );
			
			
			
			
			/// Create a new texture object with the specified image and texture format.
			OpenGLTexture( const GraphicsContext* context, const Image& newImage,
							TextureFormat newTextureFormat );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Allocate space for a texture with the specified format and size but with undefined pixel content.
			Bool setEmptyImage( TextureFormat newFormat, Size width, Size height, Size depth,
								Index mipmapLevel );
			
			
			
			
			/// Return an enum value representing the OpenGL pipeline to use for this texture.
			OpenGLEnum getGLTexturePipeline() const;
			
			
			
			
			/// Return an enum value representing the OpenGL pipeline to use for the given texture face.
			OpenGLEnum getGLTexturePipeline( TextureFace face ) const;
			
			
			
			
			/// Get the internal OpenGL texture format for the specified texture format.
			RIM_INLINE static Bool getGLInternalFormatForTextureFormat( const TextureFormat& format,
																		OpenGLEnum& glFormat );
			
			
			
			
			/// Get the OpenGL texture format for the specified texture format.
			RIM_INLINE static Bool getGLFormatForTextureFormat( const TextureFormat& format,
																OpenGLEnum& glFormat );
			
			
			
			
			/// Get the pixel component type for the specified pixel type.
			RIM_INLINE static Bool getGLPixelComponentType( const PixelFormat& pixelType, OpenGLEnum& glComponentType );
			
			
			
			
			/// Get the OpenGL enum value for the specified cube map face.
			RIM_INLINE static Bool getGLCubeMapFace( const TextureFace& face, OpenGLEnum& glFace );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The maximum number of dimensions that an OpenGL texture can have.
			static const Size MAX_DIMENSION_COUNT = 3;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The OpenGL ID uniquely representing this texture.
			OpenGLID textureID;
			
			
			
			
			/// An object representing the internal storage format for this texture.
			TextureFormat format;
			
			
			
			
			/// The type of texture wrapping to do when texture coordinates are outside of the range [0,1].
			TextureWrapType wrapType;
			
			
			
			
			/// The type of texture filtering to use when sampling a smaller version of this texture.
			TextureFilterType minificationFilterType;
			
			
			
			
			/// The type of texture filtering to use when sampling a smaller version of this texture.
			TextureFilterType magnificationFilterType;
			
			
			
			
			/// An integer value indicating the dimension of this texture (usually 1, 2 or 3).
			Size numDimensions;
			
			
			
			
			/// A fixed-size array which stores the size of this texture along each axis.
			StaticArray<Size,MAX_DIMENSION_COUNT> size;
			
			
			
			
			/// A boolean value indicating whether or not this texture is a cube map.
			Bool cubeMap;
			
			
			
			
			/// A boolean value indicating whether or not this texture is able to be used.
			Bool valid;
			
			
			
};




//##########################################################################################
//********************  End Rim Graphics Devices OpenGL Namespace  *************************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_OPENGL_TEXTURE_H
