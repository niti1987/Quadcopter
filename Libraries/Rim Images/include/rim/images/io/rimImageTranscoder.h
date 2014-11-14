/*
 *  rimImageTranscoder.h
 *  Rim Engine
 *
 *  Created by Carl Schissler on 2/2/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_IMAGE_TRANSCODER_H
#define INCLUDE_RIM_IMAGE_TRANSCODER_H


#include "rimImageIOConfig.h"


#include "rimImageFormat.h"
#include "rimImageEncodingParameters.h"


//##########################################################################################
//***************************  Start Rim Image IO Namespace  *******************************
RIM_IMAGE_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An interface for an object which decodes and encodes images.
/**
  * The purpose of this interface is to provide a common interface
  * for classes which provide functionality to encode and decode 
  * images to and from their format and a simpler representation in memory.
  *
  * In general, one uses the encoding functionality by passing in a
  * reference to an image object already existing in memory to the encode() function.
  * The job of the encoder is then to covert the image object to an encoded 
  * stream of bytes, represented by a Data object.
  *
  * Similarly, the decode() method takes a data object and outputs an image object.
  * Finally, the last method, canDecode(), takes as a parameter a reference to a
  * data object and returns whether or not this data represents an encoded image that
  * the decoder can decode.
  */
class ImageTranscoder : public ResourceTranscoder<Image>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Format Accessor Methods
			
			
			
			
			/// Return an object which represents the resource type that this transcoder can read and write.
			virtual ResourceType getResourceType() const;
			
			
			
			
			/// Return an object which represents the format that this transcoder can encode and decode.
			virtual ImageFormat getFormat() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Encoding Methods
			
			
			
			
			/// Return whether or not this transcoder is able to encode the specified image.
			virtual Bool canEncode( const Image& image ) const;
			
			
			
			
			/// Return whether or not the specified image can be encoded using this transcoder.
			/**
			  * If TRUE is returned, the image is in a format that is compatible with this
			  * transcoder. Otherwise, the image is not compatible and cannot be encoded.
			  */
			RIM_INLINE Bool canEncode( const Image& image, const ImageEncodingParameters& parameters ) const
			{
				if ( !image.isValid() )
					return false;
				
				return this->canEncode( image.getPixelData().getPointer(), image.getPixelFormat(),
										image.getWidth(), image.getHeight(), parameters );
			}
			
			
			
			
			/// Return whether or not the specified image can be encoded using this transcoder.
			/**
			  * The image is specified by a pointer to pixel data, dimensions, and pixel type.
			  *
			  * If TRUE is returned, the image is in a format that is compatible with this
			  * transcoder. Otherwise, the image is not compatible and cannot be encoded.
			  */
			virtual Bool canEncode( const UByte* pixelData, const PixelFormat& pixelType, Size width, Size height,
									const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const = 0;
			
			
			
			
			/// Encode the specified image and send the output to the specified data output stream.
			/**
			  * If the encoding succeeds, the encoded image data is sent to the
			  * data output stream and TRUE is returned. Otherwise, FALSE is returned
			  * and no data is sent to the stream.
			  */
			RIM_INLINE Bool encode( const Image& image, DataOutputStream& stream,
									const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const
			{
				if ( !image.isValid() )
					return false;
				
				return this->encode( image.getPixelData().getPointer(), image.getPixelFormat(),
									image.getWidth(), image.getHeight(), stream, parameters );
			}
			
			
			
			
			/// Encode the specified image and place the output in the specified Data object.
			/**
			  * If the encoding succeeds, the encoded image data is placed in the
			  * Data object and TRUE is returned. Otherwise, FALSE is returned
			  * and no data is placed in the Data object.
			  */
			Bool encode( const Image& image, Data& data,
						const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const;
			
			
			
			
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
				if ( !image.isValid() )
					return false;
				
				return this->encode( image.getPixelData().getPointer(), image.getPixelFormat(),
									image.getWidth(), image.getHeight(), outputData, numBytes, parameters );
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
								const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const = 0;
			
			
			
			
			/// Encode the specified image and send the output to the specified data output stream.
			/**
			  * The image is specified by a pointer to pixel data, dimensions, and pixel type.
			  *
			  * If the encoding succeeds, the encoded image data is sent to the
			  * data output stream and TRUE is returned. Otherwise, FALSE is returned
			  * and no data is sent to the stream.
			  */
			virtual Bool encode( const UByte* pixelData, const PixelFormat& pixelType,
								Size width, Size height, DataOutputStream& stream,
								const ImageEncodingParameters& parameters = ImageEncodingParameters() ) const = 0;
			
			
			
			
			/// Save the specified image at the specified ID location.
			/**
			  * The method returns whether or not the resource was successfully written.
			  */
			virtual Bool encode( const ResourceID& identifier, const Image& image );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Decoding Methods
			
			
			
			
			/// Return whether or not the specified identifier refers to a valid image format for this transcoder.
			/**
			  * If the identifier represents a valid image format, TRUE is returned. Otherwise,
			  * if the resource is not valid, FALSE is returned.
			  */
			virtual Bool canDecode( const ResourceID& identifier ) const;
			
			
			
			
			/// Return whether or not the specified data can be decode using this transcoder.
			/**
			  * The transcoder examines the specified data and determines if the data specifies
			  * a valid image in the transcoder's format. If so, TRUE is returned.
			  * Otherwise, FALSE is returned.
			  */
			RIM_INLINE Bool canDecode( const Data& data ) const
			{
				return this->canDecode( data.getPointer(), data.getSizeInBytes() );
			}
			
			
			
			
			/// Return whether or not the specified data can be decode using this transcoder.
			/**
			  * The transcoder examines the specified data and determines if the data specifies
			  * a valid image in the transcoder's format. If so, TRUE is returned.
			  * Otherwise, FALSE is returned.
			  */
			virtual Bool canDecode( const UByte* inputData, Size inputDataSizeInBytes ) const = 0;
			
			
			
			
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
				return this->decode( data.getPointer(), data.getSizeInBytes(), image );
			}
			
			
			
			
			/// Decode the specified data and return an image.
			/**
			  * The image is returned as a pointer to pixel data, dimensions, and
			  * pixel type, all given as reference parameters.
			  *
			  * If the decoding succeeds, the function creates an image and places
			  * it in the image output reference paramter and TRUE is returned.
			  * Otherwise, if the decoding fails, FALSE is returned.
			  */
			RIM_INLINE Bool decode( const Data& data,
									UByte*& pixelData, PixelFormat& pixelType, Size& width, Size& height ) const
			{
				return this->decode( data.getPointer(), data.getSizeInBytes(), pixelData, pixelType, width, height );
			}
			
			
			
			
			/// Decode the data from the specified data pointer and return an image.
			/**
			  * The image is returned in the specified output image reference.
			  *
			  * If the decoding succeeds, the function creates an image and places
			  * it in the image output reference paramter and TRUE is returned.
			  * Otherwise, if the decoding fails, FALSE is returned.
			  */
			Bool decode( const UByte* inputData, Size inputDataSizeInBytes, Image& image ) const;
			
			
			
			
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
								UByte*& pixelData, PixelFormat& pixelType, Size& width, Size& height ) const = 0;
			
			
			
			
			/// Decode the data from the specified DataInputStream and return an image.
			/**
			  * The image is returned in the specified output image reference.
			  *
			  * If the decoding succeeds, the function creates an image and places
			  * it in the image output reference paramter and TRUE is returned.
			  * Otherwise, if the decoding fails, FALSE is returned.
			  */
			Bool decode( DataInputStream& stream, Image& image ) const;
			
			
			
			
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
								UByte*& pixelData, PixelFormat& pixelType, Size& width, Size& height ) const = 0;
			
			
			
			
			/// Load the image pointed to by the specified identifier.
			/**
			  * The caller can supply a pointer to a resource manager which can be used
			  * to manage the creation of child resources.
			  *
			  * If the method fails, the return value will be NULL.
			  */
			virtual Pointer<Image> decode( const ResourceID& identifier, ResourceManager* manager = NULL );
			
			
			
			
	private:
		
};




//##########################################################################################
//***************************  End Rim Image IO Namespace  *********************************
RIM_IMAGE_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_IMAGE_TRANSCODER_H
