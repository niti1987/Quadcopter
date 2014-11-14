/*
 *  rimImageConverter.h
 *  Rim Images
 *
 *  Created by Carl Schissler on 3/25/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_IMAGE_CONVERTER_H
#define INCLUDE_RIM_IMAGE_CONVERTER_H


#include "rimImageIOConfig.h"


#include "rimImageFormat.h"
#include "rimImageTranscoder.h"
#include "rimImagesPNGTranscoder.h"
#include "rimImagesJPEGTranscoder.h"
#include "rimImagesBMPTranscoder.h"
#include "rimImagesTGATranscoder.h"


//##########################################################################################
//***************************  Start Rim Image IO Namespace  *******************************
RIM_IMAGE_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles encoding and decoding image data to/from various formats.
class ImageConverter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a default image converter which can encode or decode any of the basic image formats.
			/**
			  * In order to encode unsupported image formats, the user should create a class that
			  * inherits from ImageTranscoder and add it to this converter for the correct format.
			  */
			ImageConverter();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transcoder Accessor Methods
			
			
			
			
			/// Return the total number of transcoders that this image converter supports.
			RIM_INLINE Size getTranscoderCount() const
			{
				return transcoders.getSize();
			}
			
			
			
			
			/// Access the transcoder for the specified image format.
			/**
			  * If that format is supported by the converter, a pointer to transcoder for that
			  * format is set in the output pointer and TRUE is returned. Otherwise,
			  * there is no transcoder for that format and FALSE is returned indicating failure.
			  */
			Bool getTranscoder( ImageFormat format, Pointer<ImageTranscoder>& transcoder ) const;
			
			
			
			
			/// Add a new transcoder to this image converter.
			/**
			  * If transcoder pointer is not NULL, the transcoder is added to the converter
			  * for its format (accessed by calling getFormat() on the transcoder).
			  * If there already exists a transcoder for that format, it is replaced.
			  * The method returns whether or not the new transcoder was successfully added.
			  */
			Bool addTranscoder( const Pointer<ImageTranscoder>& newTranscoder );
			
			
			
			
			/// Remove the transcoder from this converter with the specified image format.
			/**
			  * If there is a transcoder with that format, it is removed and TRUE is returned.
			  * Otherwise, the converter is unchanged and FALSE is returned.
			  */
			Bool removeTranscoder( ImageFormat format );
			
			
			
			
			/// Remove all transcoders from this image converter.
			/**
			  * After this operation, the image converter will not be able to decode or
			  * encode images in any format until new transcoder objects are added to it.
			  */
			void clearTranscoders();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Encoding Methods
			
			
			
			
			/// Return whether or not an image can be encoded in the specified format.
			/**
			  * If TRUE is returned, the image is in a format that is compatible with this
			  * image converter. Otherwise, the image is not compatible and cannot be encoded.
			  */
			RIM_INLINE Bool canEncode( ImageFormat format, const Image& image,
									const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const
			{
				if ( !image.isValid() )
					return false;
				
				return this->canEncode( format, image.getPixelData().getPointer(), image.getPixelFormat(),
										image.getWidth(), image.getHeight(), parameters );
			}
			
			
			
			
			/// Return whether or not an image can be encoded in the specified format.
			/**
			  * The image is specified by a pointer to pixel data, dimensions, and pixel type.
			  *
			  * If TRUE is returned, the image is in a format that is compatible with this
			  * image converter. Otherwise, the image is not compatible and cannot be encoded.
			  */
			Bool canEncode( ImageFormat format, const UByte* pixelData,
							const PixelFormat& pixelType, Size width, Size height,
							const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const;
			
			
			
			
			/// Encode an image using the specified format and place the output in the specified data object.
			/**
			  * If the encoding succeeds, the encoded image data is placed in the
			  * Data object and TRUE is returned. Otherwise, FALSE is returned
			  * and no data is placed in the Data object.
			  */
			Bool encode( ImageFormat format, const Image& image, Data& data,
						const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const;
			
			
			
			
			/// Encode an image using the specified format and place the output in the specified data pointer.
			/**
			  * If the encoding succeeds, the function allocates the necessary output data
			  * array and places the pointer to that array in the output data pointer reference,
			  * the number of bytes in the output array is placed in the numBytes output reference,
			  * and TRUE is returned. Otherwise, FALSE is returned and no data is
			  * placed in the output references.
			  */
			RIM_INLINE Bool encode( ImageFormat format, const Image& image, UByte*& outputData, Size& numBytes,
									const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const
			{
				if ( !image.isValid() )
					return false;
				
				return this->encode( format, image.getPixelData().getPointer(), image.getPixelFormat(),
									image.getWidth(), image.getHeight(), outputData, numBytes, parameters );
			}
			
			
			
			
			/// Encode an image using the specified format and place the output in the specified data pointer.
			/**
			  * The image is specified by a pointer to pixel data, dimensions, and pixel type.
			  *
			  * If the encoding succeeds, the function allocates the necessary output data
			  * array and places the pointer to that array in the output data pointer reference,
			  * the number of bytes in the output array is placed in the numBytes output reference,
			  * and TRUE is returned. Otherwise, FALSE is returned and no data is
			  * placed in the output references.
			  */
			Bool encode( ImageFormat format, const UByte* pixelData,
						const PixelFormat& pixelType, Size width, Size height,
						UByte*& outputData, Size& numBytes,
						const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const;
			
			
			
			
			/// Encode an image using the specified format and send the output to the specified data output stream.
			/**
			  * If the encoding succeeds, the encoded image data is sent to the
			  * data output stream and TRUE is returned. Otherwise, FALSE is returned
			  * and no data is sent to the stream.
			  */
			RIM_INLINE Bool encode( ImageFormat format, const Image& image, DataOutputStream& stream,
									const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const
			{
				if ( !image.isValid() )
					return false;
				
				return this->encode( format, image.getPixelData().getPointer(), image.getPixelFormat(),
									image.getWidth(), image.getHeight(), stream, parameters );
			}
			
			
			
			
			/// Encode an image using the specified format and send the output to the specified data output stream.
			/**
			  * The image is specified by a pointer to pixel data, dimensions, and pixel type.
			  *
			  * If the encoding succeeds, the encoded image data is sent to the
			  * data output stream and TRUE is returned. Otherwise, FALSE is returned
			  * and no data is sent to the stream.
			  */
			Bool encode( ImageFormat format, const UByte* pixelData, const PixelFormat& pixelType,
						Size width, Size height, DataOutputStream& stream,
						const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const;
			
			
			
			
			/// Encode an image using the specified format, writing the output to the specified file path.
			/**
			  * The method encodes the image as the given format, or attempts to 
			  * guess the format if it is UNDEFINED.
			  *
			  * If the encoding succeeds, the encoded image data is sent to the
			  * file location and TRUE is returned. Otherwise, FALSE is returned
			  * and the file is not written.
			  */
			Bool encode( ImageFormat format, const Image& image, const UTF8String& filePath,
						const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const;
			
			
			
			
			/// Encode an image using an inferred format, writing the output to the specified file path.
			/**
			  * The method attempts to guess the output format for the image based on the file path extension.
			  *
			  * If the encoding succeeds, the encoded image data is sent to the
			  * file location and TRUE is returned. Otherwise, FALSE is returned
			  * and the file is not written.
			  */
			RIM_INLINE Bool encode( const Image& image, const UTF8String& filePath,
									const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const
			{
				return this->encode( ImageFormat::UNDEFINED, image, filePath, parameters );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Decoding Methods
			
			
			
			
			/// Return whether or not the specified data can be decoded.
			/**
			  * If the ImageFormat::UNDEFINED is specified, the method tries all possible
			  * decoders to see if any of them can decode the image data.
			  */
			RIM_INLINE Bool canDecode( ImageFormat format, const Data& data ) const
			{
				return this->canDecode( format, data.getPointer(), data.getSizeInBytes() );
			}
			
			
			
			
			/// Return whether or not the specified data can be decoded.
			/**
			  * If the ImageFormat::UNDEFINED is specified, the method tries all possible
			  * decoders to see if any of them can decode the image data.
			  */
			Bool canDecode( ImageFormat format, const UByte* inputData, Size inputDataSizeInBytes ) const;
			
			
			
			
			/// Decode the specified data and return an image.
			/**
			  * The image is returned in the specified output image reference.
			  * If the ImageFormat::UNDEFINED is specified, the method attempts to
			  * guess the format of the image.
			  *
			  * If the decoding succeeds, the function creates an image and places
			  * it in the image output reference paramter and TRUE is returned.
			  * Otherwise, if the decoding fails, FALSE is returned.
			  */
			RIM_INLINE Bool decode( ImageFormat format, const Data& data, Image& image ) const
			{
				return this->decode( format, data.getPointer(), data.getSizeInBytes(), image );
			}
			
			
			
			
			/// Decode the data from the specified data pointer and return an image.
			/**
			  * The image is returned in the specified output image reference.
			  * If the ImageFormat::UNDEFINED is specified, the method attempts to
			  * guess the format of the image.
			  *
			  * If the decoding succeeds, the function creates an image and places
			  * it in the image output reference paramter and TRUE is returned.
			  * Otherwise, if the decoding fails, FALSE is returned.
			  */
			Bool decode( ImageFormat format, const UByte* inputData, Size inputDataSizeInBytes, Image& image ) const;
			
			
			
			
			/// Decode the specified data and return an image.
			/**
			  * The image is returned as a pointer to pixel data, dimensions, and
			  * pixel type, all given as reference parameters. If the ImageFormat::UNDEFINED is
			  * specified, the method attempts to guess the format of the image.
			  *
			  * If the decoding succeeds, the function creates an image and places
			  * it in the image output reference paramter and TRUE is returned.
			  * Otherwise, if the decoding fails, FALSE is returned.
			  */
			RIM_INLINE Bool decode( ImageFormat format, const Data& data,
									UByte*& pixelData, PixelFormat& pixelType, Size& width, Size& height ) const
			{
				return this->decode( format, data.getPointer(), data.getSizeInBytes(),
									pixelData, pixelType, width, height );
			}
			
			
			
			
			/// Decode the data in the specified format from a data pointer and return an image.
			/**
			  * The image is returned as a pointer to pixel data, dimensions, and
			  * pixel type, all given as reference parameters. If the ImageFormat::UNDEFINED is
			  * specified, the method attempts to guess the format of the image.
			  *
			  * The decoding method can use the in/out parameter pixelType to hint at the
			  * desired pixel format for the output image. The decoder should try to match
			  * this format as closely as possible without degrading image quality.
			  *
			  * If the decoding succeeds, the function allocates the necessary space
			  * for the image's pixel data and places the pointer to that data
			  * in the output pixel data reference, along with the image's dimensions
			  * and pixel type, and TRUE is returned. Otherwise, if the decoding fails,
			  * FALSE is returned.
			  */
			Bool decode( ImageFormat format, const UByte* inputData, Size inputDataSizeInBytes,
						UByte*& pixelData, PixelFormat& pixelType, Size& width, Size& height ) const;
			
			
			
			
			/// Decode the data from the specified DataInputStream and return an image.
			/**
			  * The image is returned in the specified output image reference.
			  * If the ImageFormat::UNDEFINED is specified, the method attempts to
			  * guess the format of the image.
			  *
			  * If the decoding succeeds, the function creates an image and places
			  * it in the image output reference paramter and TRUE is returned.
			  * Otherwise, if the decoding fails, FALSE is returned.
			  */
			Bool decode( ImageFormat format, DataInputStream& stream, Image& image ) const;
			
			
			
			
			/// Decode image data in the specified format from a DataInputStream and return an image.
			/**
			  * The image is returned as a pointer to pixel data, dimensions, and
			  * pixel type, all given as reference parameters. If the ImageFormat::UNDEFINED is
			  * specified, the method attempts to guess the format of the image.
			  *
			  * The decoding method can use the in/out parameter pixelType to hint at the
			  * desired pixel format for the output image. The decoder should try to match
			  * this format as closely as possible without degrading image quality.
			  *
			  * If the decoding succeeds, the function allocates the necessary space
			  * for the image's pixel data and places the pointer to that data
			  * in the output pixel data reference, along with the image's dimensions
			  * and pixel type, and TRUE is returned. Otherwise, if the decoding fails,
			  * FALSE is returned.
			  */
			Bool decode( ImageFormat format, DataInputStream& stream,
						UByte*& pixelData, PixelFormat& pixelType, Size& width, Size& height ) const;
			
			
			
			
			/// Decode the image at the specified file path.
			/**
			  * The image is returned in the specified output image reference.
			  * The method decodes the image as the given format, or attempts to 
			  * guess the format if it is UNDEFINED.
			  *
			  * If the decoding succeeds, the function creates an image and places
			  * it in the image output reference paramter and TRUE is returned.
			  * Otherwise, if the decoding fails, FALSE is returned.
			  */
			Bool decode( ImageFormat format, const UTF8String& filePath, Image& image ) const;
			
			
			
			
			/// Decode the image at the specified file path.
			/**
			  * The image is returned in the specified output image reference.
			  * The method attempts to guess the format of the image based on the
			  * file type extension of the path.
			  *
			  * If the decoding succeeds, the function creates an image and places
			  * it in the image output reference paramter and TRUE is returned.
			  * Otherwise, if the decoding fails, FALSE is returned.
			  */
			Bool decode( const UTF8String& filePath, Image& image ) const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A map from image formats to image transcoders associated with those formats.
			HashMap< ImageFormat, Pointer<ImageTranscoder> > transcoders;
			
			
			
};




//##########################################################################################
//***************************  End Rim Image IO Namespace  *********************************
RIM_IMAGE_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_IMAGE_CONVERTER_H
