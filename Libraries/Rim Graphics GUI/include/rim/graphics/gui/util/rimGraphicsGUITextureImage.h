/*
 *  rimGraphicsGUITextureImage.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 3/21/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_TEXTURE_IMAGE_H
#define INCLUDE_RIM_GRAPHICS_GUI_TEXTURE_IMAGE_H


#include "rimGraphicsGUIUtilitiesConfig.h"


#include "rimGraphicsGUIImage.h"


//##########################################################################################
//*******************  Start Rim Graphics GUI Utilities Namespace  *************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a rectangular region of a texture and its associated display size.
/**
  * A texture image provides a way to specify a region within a texture where
  * a 2D image is located, as well as the final size with which it should be
  * displayed. Since a Texture is defined to be stored on the graphics hardware,
  * rendering a TextureImage is faster than a normal Image stored in CPU memory.
  */
class TextureImage : GUIImage
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new texture image which has no source texture and 0 size.
			TextureImage();
			
			
			
			
			/// Create a new texture image which uses the specified source texture.
			/**
			  * The display size for the image is set to be the same size as the
			  * image and the UV texture coordinate bounds are set to use the entire
			  * area of the texture. If the specified texture is NULL, the new texture image
			  * has 0 size and is not valid.
			  */
			TextureImage( const Resource<Texture>& newTexture );
			
			
			
			
			/// Create a new texture image which uses the specified source texture and has the given UV bounds.
			/**
			  * The display size for the image is calculated based on the number of texels
			  * encompassed by the given UV coordinate bounds.
			  * If the specified texture is NULL, the new texture image
			  * has 0 size and is not valid.
			  */
			TextureImage( const Resource<Texture>& newTexture, const AABB2f& newUVBounds );
			
			
			
			
			/// Create a new image which uses the specified source texture and has the given UV bounds and display size.
			/**
			  * If the specified texture is NULL, the new texture image is not valid.
			  */
			TextureImage( const Resource<Texture>& newTexture, const AABB2f& newUVBounds,
						const Vector2f& newSize );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Accessor Methods
			
			
			
			
			/// Return a pointer to the texture which this texture image uses as its image source.
			RIM_INLINE const Resource<Texture>& getTexture() const
			{
				return texture;
			}
			
			
			
			
			/// Set a pointer to the texture which this texture image uses as its image source.
			/**
			  * If the specified texture is NULL, the new texture image is not valid.
			  */
			RIM_INLINE void setTexture( const Resource<Texture>& newTexture )
			{
				texture = newTexture;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	UV Bounding Box Accessor Methods
			
			
			
			
			/// Return a 2D bounding box within the texture's UV coordinates (0 to 1) where the image is located.
			RIM_INLINE const AABB2f& getUVBounds() const
			{
				return uvBounds;
			}
			
			
			
			
			/// Set the 2D bounding box within the texture's UV coordinates (0 to 1) where the image is located.
			RIM_INLINE void setUVBounds( const AABB2f& newUVBounds )
			{
				uvBounds = newUVBounds;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Validity Accessor Methods
			
			
			
			
			/// Return whether or not this texture image is valid and can be used for rendering.
			virtual Bool isValid() const
			{
				return !texture.isNull();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Drawing Method
			
			
			
			
			/// Draw this image using the specified renderer to the given bounding box on the screen.
			virtual Bool drawSelf( GUIRenderer& renderer, const AABB2f& pixelBounds,
									const Color4f& color = Color4f::WHITE ) const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// A pointer to the texture which contains the data for this texture image.
			Resource<Texture> texture;
			
			
			
			
			/// A 2D bounding box within the texture's UV coordinates (0 to 1) where the image is located.
			AABB2f uvBounds;
			
			
			
};




//##########################################################################################
//*******************  End Rim Graphics GUI Utilities Namespace  ***************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_TEXTURE_IMAGE_H
