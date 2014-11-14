/*
 *  rimGraphicsTextureFormat.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/22/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_TEXTURE_FORMAT_H
#define INCLUDE_RIM_GRAPHICS_TEXTURE_FORMAT_H


#include "rimGraphicsTexturesConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Textures Namespace  ***************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the internal format for a texture.
/**
  * This is the GPU-side semantic representation of the texture's
  * type and usage.
  */
class TextureFormat
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			typedef enum Enum
			{
				//********************************************************************************
				//********************************************************************************
				//********************************************************************************
				//******	Depth Texture Formats
				
				
				
				
				/// A depth texture in the GPU's native depth format.
				DEPTH,
				
				
				
				//********************************************************************************
				//********************************************************************************
				//********************************************************************************
				//******	Standard Texture Formats
				
				
				
				
				/// An 8-bits-per-pixel alpha-channel texture.
				ALPHA,
				
				/// An 8-bits-per-pixel grayscale (lightmap) texture.
				GRAYSCALE,
				
				/// An 8-bit grayscale (lightmap) texture with an 8-bit alpha channel.
				GRAYSCALE_ALPHA,
				
				/// An 8-bits-per-pixel intensity texture.
				/**
				  * This is like a lightmap but it affects the alpha channel as well.
				  */
				INTENSITY,
				
				/// An 8-bits-per-channel RGB texture.
				RGB,
				
				/// An 8-bits-per-channel RGB texture with an alpha channel.
				RGBA,
				
				
				
				
				//********************************************************************************
				//********************************************************************************
				//********************************************************************************
				//******	Floating Point Texture Formats
				
				
				
				
				/// A 16-bit floating-point alpha-channel texture.
				ALPHA_16F,
				
				/// A 16-bit floating-point grayscale (lightmap) texture.
				GRAYSCALE_16F,
				
				/// A 16-bit floating-point (lightmap) texture with a 16-bit floating-point alpha channel.
				GRAYSCALE_ALPHA_16F,
				
				/// A 16-bit floating-point intensity texture.
				/**
				  * This is like a lightmap but it affects the alpha channel as well.
				  */
				INTENSITY_16F,
				
				/// A 16-bits-per-channel floating-point RGB texture.
				RGB_16F,
				
				/// A 16-bits-per-channel floating-point RGB texture with an alpha channel.
				RGBA_16F,
				
				
				
				
				/// A 32-bit floating-point alpha-channel texture.
				ALPHA_32F,
				
				/// A 32-bit floating-point grayscale (lightmap) texture.
				GRAYSCALE_32F,
				
				/// A 32-bit floating-point (lightmap) texture with a 16-bit floating-point alpha channel.
				GRAYSCALE_ALPHA_32F,
				
				/// A 32-bit floating-point intensity texture.
				/**
				  * This is like a lightmap but it affects the alpha channel as well.
				  */
				INTENSITY_32F,
				
				/// A 32-bits-per-channel floating-point RGB texture.
				RGB_32F,
				
				/// A 32-bits-per-channel floating-point RGB texture with an alpha channel.
				RGBA_32F,
				
				
				
				
				//********************************************************************************
				//********************************************************************************
				//********************************************************************************
				//******	Compressed Texture Formats
				
				
				
				
				/// An 8-bits-per-pixel compressed alpha-channel texture.
				COMPRESSED_ALPHA,
				
				/// An 8-bits-per-pixel compressed grayscale (lightmap) texture.
				COMPRESSED_GRAYSCALE,
				
				/// An 8-bit compressed grayscale (lightmap) texture with an 8-bit alpha channel.
				COMPRESSED_GRAYSCALE_ALPHA,
				
				/// An 8-bits-per-pixel compressed intensity texture.
				/**
				  * This is like a lightmap but it affects the alpha channel as well.
				  */
				COMPRESSED_INTENSITY,
				
				/// An 8-bits-per-channel compressed RGB texture.
				COMPRESSED_RGB,
				
				/// An 8-bits-per-channel compressed RGB texture with an alpha channel.
				COMPRESSED_RGBA,
				
				
				
				
				//********************************************************************************
				//********************************************************************************
				//********************************************************************************
				//******	Undefined Texture Format
				
				
				/// An undefined texture format.
				UNDEFINED
				
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create an undefined texture format.
			RIM_INLINE TextureFormat()
				:	format( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a texture format object from an enum specifying the type of format.
			RIM_INLINE TextureFormat( Enum newFormat )
				:	format( newFormat )
			{
			}
			
			
			
			
			/// Create a texture format which can represent an image with the specified pixel type.
			TextureFormat( const PixelFormat& newPixelFormat );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Number Accessor Method
			
			
			
			
			/// Get the number of color channels that this texture format has.
			Size getChannelCount() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Compression Type Accessor Method
			
			
			
			
			/// Get whether or not this texture format is compressed.
			Bool isCompressed() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Precision Type Accessor Method
			
			
			
			
			/// Get whether or not this texture format uses floating point pixel data.
			Bool isFloatingPoint() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transparency Type Accessor Method
			
			
			
			
			/// Return whether or not this texture format can be transparent.
			Bool isTransparent() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Pixel Type Accessor Method
			
			
			
			
			/// Return an object which represents a pixel type compatible with this texture format.
			/**
			  * The returned pixel type should have enough precision and the correct
			  * number of channels to be able to store an image with this texture format.
			  *
			  * If there is no compatible pixel type, the PixelFormat::UNDEFINED value is returned.
			  */
			PixelFormat getPixelFormat() const;
			
			
			
			
			/// Return whether or not the specified pixel type is compatible with this texture format.
			Bool supportsPixelFormat( const PixelFormat& pixelType ) const
			{
				return this->getChannelCount() == pixelType.getChannelCount();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this texture format to an enum value.
			RIM_INLINE operator Enum () const
			{
				return format;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the texture format.
			String toString() const;
			
			
			
			
			/// Convert this texture format into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum which represents the type of texture format.
			Enum format;
			
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Textures Namespace  *****************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_TEXTURE_FORMAT_H
