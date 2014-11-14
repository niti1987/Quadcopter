/*
 *  rimPixelFormat.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/30/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PIXEL_TYPE_H
#define INCLUDE_RIM_PIXEL_TYPE_H


#include "rimImagesConfig.h"


//##########################################################################################
//****************************  Start Rim Images Namespace  ********************************
RIM_IMAGES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class representing the type of a pixel: its underlying component type and number of channels.
class PixelFormat
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Pixel Type Enum Declaration
			
			
			
			
			typedef enum Enum
			{
				/// An undefined pixel type.
				UNDEFINED,
				
				
				//******************************************************************
				// RGB Pixel Types.
				
				
				/// An RGB pixel type with 8 bits per component.
				R8_G8_B8,
				
				/// An RGB pixel type with 16 bits per component.
				R16_G16_B16,
				
				/// An RGB pixel type with 16 floating-point bits per component.
				R16F_G16F_B16F,
				
				/// An RGB pixel type with 32 floating-point bits per component.
				R32F_G32F_B32F,
				
				
				/// An RGB pixel type with 8 bits per component.
				RGB = R8_G8_B8,
				
				/// An RGB pixel type with 8 bits per component.
				RGB8 = R8_G8_B8,
				
				/// An RGB pixel type with 16 bits per component.
				RGB16 = R16_G16_B16,
				
				/// An RGB pixel type with 16 floating-point bits per component.
				RGB16F = R16F_G16F_B16F,
				
				/// An RGB pixel type with 32 floating-point bits per component.
				RGB32F = R32F_G32F_B32F,
				
				
				//******************************************************************
				// RGBA Pixel Types.
				
				
				/// An RGBA pixel type with 8 bits per component.
				R8_G8_B8_A8,
				
				/// An RGBA pixel type with 16 bits per component.
				R16_G16_B16_A16,
				
				/// An RGBA pixel type with 16 floating-point bits per component.
				R16F_G16F_B16F_A16F,
				
				/// An RGBA pixel type with 32 floating-point bits per component.
				R32F_G32F_B32F_A32F,
				
				
				/// An RGBA pixel type with 8 bits per component.
				RGBA = R8_G8_B8_A8,
				
				/// An RGBA pixel type with 8 bits per component.
				RGBA8 = R8_G8_B8_A8,
				
				/// An RGBA pixel type with 16 bits per component.
				RGBA16 = R16_G16_B16_A16,
				
				/// An RGBA pixel type with 16 floating-point bits per component.
				RGBA16F = R16F_G16F_B16F_A16F,
				
				/// An RGBA pixel type with 32 floating-point bits per component.
				RGBA32F = R32F_G32F_B32F_A32F,
				
				
				//******************************************************************
				// Grayscale Pixel Types.
				
				
				/// A single-channel pixel with 8 bits per component.
				GRAY8,
				
				/// A single-channel pixel with 8 bits per component.
				GRAY = GRAY8,
				
				/// A single-channel pixel with 16 bits per component.
				GRAY16,
				
				/// A single-channel pixel with 16 floating-point bits per component.
				GRAY16F,
				
				/// A single-channel pixel with 32 floating-point bits per component.
				GRAY32F,
				
				
				//******************************************************************
				// Grayscale + Alpha Pixel Types.
				
				
				/// A dual-channel pixel with 8 bits per component.
				GRAY8_ALPHA8,
				
				/// A dual-channel pixel with 16 bits per component.
				GRAY16_ALPHA16,
				
				/// A dual-channel pixel with 16 floating-point bits per component.
				GRAY16F_ALPHA16F,
				
				/// A dual-channel pixel with 32 floating-point bits per component.
				GRAY32F_ALPHA32F
				
				
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a pixel type object with an UNDEFINED pixel type.
			RIM_INLINE PixelFormat()
				:	type( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a pixel type object from the specified pixel type Enum.
			RIM_INLINE PixelFormat( PixelFormat::Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this light type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Per-Pixel Size Accessor Methods
			
			
			
			
			/// Get the number of bits required for each pixel of this pixel type.
			RIM_INLINE Size getSizeInBits() const
			{
				return this->getSizeInBytes() << 3;
			}
			
			
			
			
			/// Get the number of bytes required for each pixel of this pixel type.
			Size getSizeInBytes() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Property Accessor Methods
			
			
			
			
			/// Return the primitive type used for each channel of this pixel type.
			/**
			  * Channel indices start at 0 and go up to N-1 for N channels. If the
			  * specified channel index is outside of the valid range, the primitive
			  * UNDEFINED will be returned.
			  */
			PrimitiveType getChannelType( Index channelIndex ) const;
			
			
			
			
			/// Get the size in bits for each channel of this pixel type.
			/**
			  * Channel indices start at 0 and go up to N-1 for N channels. If the
			  * specified channel index is outside of the valid range, size of 0
			  * will be returned.
			  */
			RIM_INLINE Size getChannelSizeInBits( Index channelIndex ) const
			{
				return this->getChannelType( channelIndex ).getSizeInBits();
			}
			
			
			
			
			/// Get the size in bytes for each channel of this pixel type.
			/**
			  * Channel indices start at 0 and go up to N-1 for N channels. If the
			  * specified channel index is outside of the valid range, size of 0
			  * will be returned.
			  */
			RIM_INLINE Size getChannelSizeInBytes( Index channelIndex ) const
			{
				return this->getChannelType( channelIndex ).getSizeInBytes();
			}
			
			
			
			
			/// Return the number of channels that this pixel type has.
			Size getChannelCount() const;
			
			
			
			
			/// Return whether or not this pixel type has an alpha (transparency) channel.
			Bool hasAlpha() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Pixel Type String Conversion Methods
			
			
			
			
			/// Return a string representation of the pixel type.
			String toString() const;
			
			
			
			
			/// Convert this pixel type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value specifying the pixel type.
			Enum type;
			
			
			
};




//##########################################################################################
//****************************  End Rim Images Namespace  **********************************
RIM_IMAGES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PIXEL_TYPE_H
