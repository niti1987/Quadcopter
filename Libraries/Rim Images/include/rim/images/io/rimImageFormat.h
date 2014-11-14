/*
 *  rimImageFormat.h
 *  Rim Images
 *
 *  Created by Carl Schissler on 1/15/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_IMAGE_FORMAT_H
#define INCLUDE_RIM_IMAGE_FORMAT_H


#include "rimImageIOConfig.h"


//##########################################################################################
//***************************  Start Rim Image IO Namespace  *******************************
RIM_IMAGE_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An enum class representing the different kinds of image encoding formats.
class ImageFormat
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Format Enum Declaration
			
			
			
			
			/// An enum type representing the different kinds of image encoding formats.
			typedef enum Enum
			{
				/// An undefined image format.
				UNDEFINED = ResourceFormat::UNDEFINED,
				
				/// The uncompressed .bmp image file format.
				BMP = ResourceFormat::BMP,
				
				/// The lossily-compressed .jpg image file format.
				JPEG = ResourceFormat::JPEG,
				
				/// The losslessly-compressed .png image file format.
				PNG = ResourceFormat::PNG,
				
				/// The .tga image file format.
				TGA = ResourceFormat::TGA,
				
				/// The .tiff image file format.
				TIFF = ResourceFormat::TIFF,
				
				/// The .gif image file format.
				GIF = ResourceFormat::GIF,
				
				/// The JPEG 2000 image file format.
				JPEG_2000 = ResourceFormat::JPEG_2000,
				
				/// The DDS image/texture file format.
				DDS = ResourceFormat::DDS
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an image format object with an UNDEFINED image format.
			RIM_INLINE ImageFormat()
				:	format( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a pixel type object from the specified image format Enum.
			RIM_INLINE ImageFormat( ImageFormat::Enum newFormat )
				:	format( newFormat )
			{
			}
			
			
			
			
			/// Create a pixel type object from the specified image format Enum.
			ImageFormat( const ResourceFormat& newFormat );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this image format to an enum value.
			RIM_INLINE operator Enum () const
			{
				return format;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Format Extension Accessor Method
			
			
			
			
			/// Return the standard file extension used for this image format.
			UTF8String getExtension() const;
			
			
			
			
			/// Return an image format which corresponds to the format with the given extension string.
			static ImageFormat getFormatForExtension( const UTF8String& extension );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Format String Conversion Methods
			
			
			
			
			/// Return a string representation of the image format.
			String toString() const;
			
			
			
			
			/// Convert this image format into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value specifying the image format.
			Enum format;
			
			
			
};




//##########################################################################################
//***************************  End Rim Image IO Namespace  *********************************
RIM_IMAGE_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_IMAGE_FORMAT_H
