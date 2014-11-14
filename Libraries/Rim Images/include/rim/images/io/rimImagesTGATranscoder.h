/*
 *  rimImagesTGATranscoder.h
 *  Rim Images
 *
 *  Created by Carl Schissler on 3/25/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_IMAGES_TGA_TRANSCODER_H
#define INCLUDE_RIM_IMAGES_TGA_TRANSCODER_H


#include "rimImageTranscoder.h"


//##########################################################################################
//***************************  Start Rim Image IO Namespace  *******************************
RIM_IMAGE_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles encoding and decoding image data to/from the Truevision TGA format (.tga)
class TGATranscoder : public ImageTranscoder
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Format Accessor Method
			
			
			
			
			/// Return an object which represents the resource format that this transcoder can read and write.
			virtual ResourceFormat getResourceFormat() const;
			
			
			
			
			/// Return an object which represents the format that this transcoder can encode and decode.
			virtual ImageFormat getFormat() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Encoding Methods
			
			
			
			
			/// Return whether or not the specified image can be encoded using this transcoder.
			/**
			  * If TRUE is returned, the image is in a format that is compatible with this
			  * transcoder. Otherwise, the image is not compatible and cannot be encoded.
			  */
			RIM_INLINE Bool canEncode( const Image& image,
									const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const
			{
				return ImageTranscoder::canEncode( image, parameters );
			}
			
			
			
			
			/// Return whether or not the specified image can be encoded using this transcoder.
			/**
			  * The image is specified by a pointer to pixel data, dimensions, and pixel type.
			  *
			  * If TRUE is returned, the image is in a format that is compatible with this
			  * transcoder. Otherwise, the image is not compatible and cannot be encoded.
			  */
			virtual Bool canEncode( const UByte* pixelData, const PixelFormat& pixelType, Size width, Size height,
									const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const;
			
			
			
			
			/// Encode the specified image and send the output to the specified data output stream.
			/**
			  * If the encoding succeeds, the encoded image data is sent to the
			  * data output stream and TRUE is returned. Otherwise, FALSE is returned
			  * and no data is sent to the stream.
			  */
			RIM_INLINE Bool encode( const Image& image, DataOutputStream& stream,
									const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const
			{
				return ImageTranscoder::encode( image, stream, parameters );
			}
			
			
			
			
			/// Encode the specified image and place the output in the specified Data object.
			/**
			  * If the encoding succeeds, the encoded image data is placed in the
			  * Data object and TRUE is returned. Otherwise, FALSE is returned
			  * and no data is placed in the Data object.
			  */
			RIM_INLINE Bool encode( const Image& image, Data& data,
						const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const
			{
				return ImageTranscoder::encode( image, data, parameters );
			}
			
			
			
			
			/// Encode the specified image and place the output in the specified data pointer.
			/**
			  * If the encoding succeeds, the function allocates the necessary output data
			  * array and places the pointer to that array in the output data pointer reference,
			  * the number of bytes in the output array is placed in the numBytes output reference,
			  * and TRUE is returned. Otherwise, FALSE is returned and no data is
			  * placed in the output references.
			  */
			RIM_INLINE Bool encode( const Image& image, UByte*& outputData, Size& numBytes,
									const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const
			{
				return ImageTranscoder::encode( image, outputData, numBytes, parameters );
			}
			
			
			
			
			/// Encode the specified image and place the output in the specified data pointer.
			/**
			  * The image is specified by a pointer to pixel data, dimensions, and pixel type.
			  *
			  * If the encoding succeeds, the function allocates the necessary output data
			  * array and places the pointer to that array in the output data pointer reference,
			  * the number of bytes in the output array is placed in the numBytes output reference,
			  * and TRUE is returned. Otherwise, FALSE is returned and no data is
			  * placed in the output references.
			  */
			virtual Bool encode( const UByte* pixelData, const PixelFormat& pixelType, Size width, Size height,
								UByte*& outputData, Size& numBytes,
								const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const;
			
			
			
			
			/// Encode the specified image and send the output to the specified data output stream.
			/**
			  * The image is specified by a pointer to pixel data, dimensions, and pixel type.
			  *
			  * If the encoding succeeds, the encoded image data is sent to the
			  * data output stream and TRUE is returned. Otherwise, FALSE is returned
			  * and no data is sent to the stream.
			  */
			virtual Bool encode( const UByte* pixelData, const PixelFormat& pixelType, Size width, Size height,
								DataOutputStream& stream, const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Decoding Methods
			
			
			
			
			/// Return whether or not the specified data can be decode using this transcoder.
			/**
			  * The transcoder examines the specified data and determines if the data specifies
			  * a valid image in the transcoder's format. If so, TRUE is returned.
			  * Otherwise, FALSE is returned.
			  */
			RIM_INLINE Bool canDecode( const Data& data ) const
			{
				return ImageTranscoder::canDecode( data );
			}
			
			
			
			
			/// Return whether or not the specified data can be decode using this transcoder.
			/**
			  * The transcoder examines the specified data and determines if the data specifies
			  * a valid image in the transcoder's format. If so, TRUE is returned.
			  * Otherwise, FALSE is returned.
			  */
			virtual Bool canDecode( const UByte* inputData, Size inputDataSizeInBytes ) const;
			
			
			
			
			/// Decode the specified data and return an image.
			/**
			  * The image is returned in the specified output image reference.
			  *
			  * If the decoding succeeds, the function creates an image and places
			  * it in the image output reference paramter and TRUE is returned.
			  * Otherwise, if the decoding fails, FALSE is returned.
			  */
			RIM_INLINE Bool decode( const Data& data, Image& image ) const
			{
				return ImageTranscoder::decode( data, image );
			}
			
			
			
			
			/// Decode the data from the specified data pointer and return an image.
			/**
			  * The image is returned in the specified output image reference.
			  *
			  * If the decoding succeeds, the function creates an image and places
			  * it in the image output reference paramter and TRUE is returned.
			  * Otherwise, if the decoding fails, FALSE is returned.
			  */
			RIM_INLINE Bool decode( const UByte* inputData, Size inputDataSizeInBytes, Image& image ) const
			{
				return ImageTranscoder::decode( inputData, inputDataSizeInBytes, image );
			}
			
			
			
			
			/// Decode the data from the specified DataInputStream and return an image.
			/**
			  * The image is returned in the specified output image reference.
			  *
			  * If the decoding succeeds, the function creates an image and places
			  * it in the image output reference paramter and TRUE is returned.
			  * Otherwise, if the decoding fails, FALSE is returned.
			  */
			RIM_INLINE Bool decode( DataInputStream& stream, Image& image ) const
			{
				return ImageTranscoder::decode( stream, image );
			}
			
			
			
			
			/// Decode the data from the specified DataInputStream and return an image.
			/**
			  * The image is returned as a pointer to pixel data, dimensions, and
			  * pixel type, all given as reference parameters.
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
			virtual Bool decode( DataInputStream& stream,
								UByte*& pixelData, PixelFormat& pixelType, Size& width, Size& height ) const;
			
			
			
			
			/// Decode the data from the specified data pointer and return an image.
			/**
			  * The image is returned as a pointer to pixel data, dimensions, and
			  * pixel type, all given as reference parameters.
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
			virtual Bool decode( const UByte* inputData, Size inputDataSizeInBytes,
								UByte*& pixelData, PixelFormat& pixelType, Size& width, Size& height ) const;
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations
			
			
			
			
			/// A class which handles streaming reads from a memory data buffer.
			class TGADataInputStream;
			
			
			
			
			/// A class which handles streaming writes to a memory data buffer.
			class TGADataOutputStream;
			
			
			
			
			/// A structure which contains the information in a TGA header.
			struct TGAHeader;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Decoding Helper Methods
			
			
			
			static Bool decodeHeader( const UByte* headerData, TGAHeader& header );
			
			
			static Bool encodeHeader( const TGAHeader& header, UByte* headerData );
			
			
			static Bool decodeColorMap( const UByte* colorMapData, const TGAHeader& header, UByte*& colorMap );
			
			
			static Bool getHeaderPixelFormat( const TGAHeader& header, PixelFormat& pixelType );
			
			
			static Size getPixelRunLength( const UByte* pixelData, Size bytesPerPixel, Size maximum );
			
			
			static Size getPixelRawLength( const UByte* pixelData, Size bytesPerPixel, Size maximum );
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Pixel Reading Methods
			
			
			RIM_INLINE static Index readColorMapIndex( const UByte* indexData, Size bytesPerIndex );
			
			
			RIM_INLINE static void read16BitColor( const UByte* colorData, UByte& red, UByte& green, UByte& blue );
			RIM_INLINE static void read24BitColor( const UByte* colorData, UByte& red, UByte& green, UByte& blue );
			RIM_INLINE static void read32BitColor( const UByte* colorData, UByte& red, UByte& green, UByte& blue, UByte& alpha );
			
			
			RIM_INLINE static void readRGBColor( const UByte* colorData, UByte& red, UByte& green, UByte& blue );
			RIM_INLINE static void readRGBAColor( const UByte* colorData, UByte& red, UByte& green, UByte& blue, UByte& alpha );
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Pixel Writing Methods
			
			
			RIM_INLINE static void write16BitColor( UByte red, UByte green, UByte blue, UByte* colorData );
			RIM_INLINE static void write24BitColor( UByte red, UByte green, UByte blue, UByte* colorData );
			RIM_INLINE static void write32BitColor( UByte red, UByte green, UByte blue, UByte alpha, UByte* colorData );
			
			RIM_INLINE static void writeRGBColor( UByte red, UByte green, UByte blue, UByte* colorData );
			RIM_INLINE static void writeRGBAColor( UByte red, UByte green, UByte blue, UByte alpha, UByte* colorData );
			
};




//##########################################################################################
//***************************  End Rim Image IO Namespace  *********************************
RIM_IMAGE_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_IMAGES_TGA_TRANSCODER_H
