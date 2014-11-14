/*
 *  rimImageEncodingParameters.h
 *  Rim Images
 *
 *  Created by Carl Schissler on 5/14/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_IMAGE_ENCODING_PARAMETERS_H
#define INCLUDE_RIM_IMAGE_ENCODING_PARAMETERS_H


#include "rimImageIOConfig.h"


//##########################################################################################
//***************************  Start Rim Image IO Namespace  *******************************
RIM_IMAGE_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies how an image should be encoded.
class ImageEncodingParameters
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a set of image encoding parameters with the default values.
			RIM_INLINE ImageEncodingParameters()
				:	compression( 0 ),
					isInterlaced( false )
			{
			}
			
			
			
			
			/// Create a set of image encoding parameters with the the specified compression value.
			RIM_INLINE ImageEncodingParameters( Float newCompression )
				:	compression( newCompression ),
					isInterlaced( false )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Compression Amount Accessor Methods
			
			
			
			
			/// Return a floating point value between 0 and 1 indicating the amount of compression to use.
			/**
			  * If an image type supports compression, this value will determine the
			  * amount of compression that is used. A value of 0 indicates no compression
			  * or the lowest amount of compression and a value of 1 indicates that maximum
			  * compression is desired. If the image type does not support compression,
			  * this value is ignored. The default value is 0, indicating that no compression
			  * should be used.
			  */
			RIM_INLINE Float getCompression() const
			{
				return compression;
			}
			
			
			
			
			/// Set a value between 0 and 1 indicating the amount of compression to use.
			/**
			  * If an image type supports compression, this value will determine the
			  * amount of compression that is used. A value of 0 indicates no compression
			  * or the lowest amount of compression and a value of 1 indicates that maximum
			  * compression is desired. If the image type does not support compression,
			  * this value is ignored. The default value is 0, indicating that no compression
			  * should be used. The input value is clamped to the range of 0 to 1.
			  */
			RIM_INLINE void setCompression( Float newCompression )
			{
				compression = math::clamp( newCompression, Float(0), Float(1) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Interlace Type Accessor Methods
			
			
			
			
			/// Return whether or not the image should be encoded with interlaced scanlines.
			RIM_INLINE Bool getIsInterlaced() const
			{
				return isInterlaced;
			}
			
			
			
			
			/// Return whether or not the image should be encoded with interlaced scanlines.
			RIM_INLINE void setIsInterlaced( Bool newIsInterlaced )
			{
				isInterlaced = newIsInterlaced;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A value ranging from 0 to 1, indicating the amount of image compression to use.
			/**
			  * If an image type supports compression, this value will determine the
			  * amount of compression that is used. A value of 0 indicates no compression
			  * or the lowest amount of compression and a value of 1 indicates that maximum
			  * compression is desired. If the image type does not support compression,
			  * this value is ignored. The default value is 0, indicating that no compression
			  * should be used.
			  */
			Float compression;
			
			
			
			
			/// Whether or not the image should be interlaced.
			Bool isInterlaced;
			
			
			
};




//##########################################################################################
//***************************  End Rim Image IO Namespace  *********************************
RIM_IMAGE_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_IMAGE_ENCODING_PARAMETERS_H
