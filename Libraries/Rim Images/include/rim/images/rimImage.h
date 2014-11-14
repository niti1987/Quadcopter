/*
 *  rimImage.h
 *  Rim Images
 *
 *  Created by Carl Schissler on 11/8/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_IMAGE_H
#define INCLUDE_RIM_IMAGE_H


#include "rimImagesConfig.h"


#include "rimPixelFormat.h"


//##########################################################################################
//****************************  Start Rim Images Namespace  ********************************
RIM_IMAGES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class representing packed image pixel data stored in main memory.
/**
  * This class uses internal reference counting for the image's pixel
  * memory, allowing an instance of Image to be used as a value type
  * without significant performance penalties.
  */
class Image
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an image with no pixel data and an UNDEFINED pixel type.
			RIM_INLINE Image()
				:	pixelData(),
					pixelType( PixelFormat::UNDEFINED ),
					numDimensions( 0 )
			{
				size[0] = size[1] = size[2] = 0;
			}
			
			
			
			
			/// Create a 1D image object with the specified pixel data, pixel type and width.
			RIM_INLINE Image( const Data& newPixelData, const PixelFormat& newPixelFormat, Size width )
				:	pixelData( newPixelData ),
					pixelType( newPixelFormat ),
					numDimensions( 1 )
			{
				size[0] = width;
				size[1] = 1;
				size[2] = 1;
			}
			
			
			
			/// Create a 2D image object with the specified pixel data, pixel type, width and height.
			RIM_INLINE Image( const Data& newPixelData, const PixelFormat& newPixelFormat, Size width, Size height )
				:	pixelData( newPixelData ),
					pixelType( newPixelFormat ),
					numDimensions( 2 )
			{
				size[0] = width;
				size[1] = height;
				size[2] = 1;
			}
			
			
			
			
			/// Create a 3D image object with the specified pixel data, pixel type, width, height and depth.
			RIM_INLINE Image( const Data& newPixelData, const PixelFormat& newPixelFormat,
								Size width, Size height, Size depth )
				:	pixelData( newPixelData ),
					pixelType( newPixelFormat ),
					numDimensions( 3 )
			{
				size[0] = width;
				size[1] = height;
				size[2] = depth;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return the width of this image (size along dimension 0).
			/**
			  * If an image has no width, 0 is returned.
			  */
			RIM_INLINE Size getWidth() const
			{
				return size[0];
			}
			
			
			
			
			/// Return the height of this image (size along dimension 1).
			/**
			  * If an image has no height, 0 is returned. This can happen if
			  * this image is a 1-dimensional image.
			  */
			RIM_INLINE Size getHeight() const
			{
				return size[1];
			}
			
			
			
			
			/// Return the depth of this image (size along dimension 2).
			/**
			  * If an image has no depth, 0 is returned. This can happen if
			  * this image is a 1D or 2D image.
			  */
			RIM_INLINE Size getDepth() const
			{
				return size[2];
			}
			
			
			
			
			/// Get the size of the image along the specified dimension index.
			/**
			  * Indices start from 0 and count to d-1 for a image with d dimensions.
			  * If the specified dimension index is out of bounds, 1 is returned.
			  */
			RIM_INLINE Size getSize( Index dimension ) const
			{
				return dimension < numDimensions ? size[dimension] : 1;
			}
			
			
			
			
			/// Get the total number of pixels in the image.
			RIM_INLINE Size getPixelCount() const
			{
				Size numPixels = size[0];
				
				for ( Index i = 1; i < numDimensions; i++ )
					numPixels *= size[i];
				
				return numPixels;
			}
			
			
			
			
			/// Get the number of dimensions in this image, usually 1, 2, or 3.
			/**
			  * This number is defined as the highest dimension where the image's
			  * size is greater than 1 pixel.
			  */
			RIM_FORCE_INLINE Size getDimensionCount() const
			{
				return numDimensions;
			}
			
			
			
			
			/// Return the maximum number of dimenions that an image can support (usually 3).
			RIM_INLINE static Size getMaxNumberOfDimensions()
			{
				return MAX_DIMENSION_COUNT;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Data Accessor Methods
			
			
			
			
			/// Return a reference to an object which holds the pixel data for this image.
			RIM_FORCE_INLINE const Data& getPixelData() const
			{
				return pixelData;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Pixel Type Accessor Method
			
			
			
			
			/// Get the type of the image's pixels.
			RIM_FORCE_INLINE const PixelFormat& getPixelFormat() const
			{
				return pixelType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Validity Accessor Method
			
			
			
			
			/// Return whether or not this image has data that matches the image's pixel type.
			RIM_INLINE Bool isValid() const
			{
				// Compute the necessary size in bytes of the image.
				Size imageSizeInBytes = this->getPixelCount()*pixelType.getSizeInBytes();
				
				return pixelData.getSizeInBytes() == imageSizeInBytes;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Resizing Method
			
			
			
			
			/// Return a resized version of this image for the specified dimensions.
			Image resize( Size newWidth, Size newHeight = Size(1), Size newDepth = Size(1) ) const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < Size numChannels >
			static void resize2DImage( const void* pixels, Size width, Size height,
										void* output, Size newWidth, Size newHeight,
										const PixelFormat& pixelType );
			
			
			
			
			template < typename ChannelType, Size numChannels >
			static void resize2DImage( const ChannelType* pixels, Size width, Size height,
										ChannelType* output, Size newWidth, Size newHeight );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The maximum number of dimensions that an image can have.
			static const Size MAX_DIMENSION_COUNT = 3;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The pixel data, stored first by row, column, then pixel plane (depth).
			Data pixelData;
			
			
			
			
			/// The type of the image's pixels.
			PixelFormat pixelType;
			
			
			
			
			/// The dimensions of the image in pixels along each axis.
			/**
			  * Index 0 corresponds to the image's width, 1 to the height,
			  * 2 to the depth and so on.
			  */
			StaticArray<Size,MAX_DIMENSION_COUNT> size;
			
			
			
			
			/// The number of dimensions that this image has.
			Size numDimensions;
			
			
			
};




//##########################################################################################
//****************************  End Rim Images Namespace  **********************************
RIM_IMAGES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_IMAGE_H
