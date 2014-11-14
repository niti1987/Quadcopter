/*
 *  rimGraphicsPixelFormat.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/1/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_PIXEL_FORMAT_H
#define INCLUDE_RIM_GRAPHICS_PIXEL_FORMAT_H


#include "rimGraphicsDevicesConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Devices Namespace  ***************************
RIM_GRAPHICS_DEVICES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which describes the attributes of a framebuffer pixel format when creating a GraphicsContext.
class RenderedPixelFormat
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a pixel format object with the specified attributes.
			RIM_INLINE RenderedPixelFormat( Size newNumBitsPerChannel = 8, Size newNumDepthBits = 24,
									Size newNumStencilBits = 0, Size newNumBitsPerAccumulationChannel = 0,
									Size newNumAASamples = 0 )
				:	numBitsPerChannel( newNumBitsPerChannel ),
					numDepthBits( newNumDepthBits ),
					numStencilBits( newNumStencilBits ),
					numBitsPerAccumulationChannel( newNumBitsPerAccumulationChannel ),
					numAASamples( newNumAASamples )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The number of bits to use for each channel of the pixel format.
			Size numBitsPerChannel;
			
			
			
			
			/// The number of bits to use for each pixel of the depth buffer.
			Size numDepthBits;
			
			
			
			
			/// The number of bits to use for each pixel of the stencil buffer.
			Size numStencilBits;
			
			
			
			
			/// The number of bits to use for each channel of the accumulation buffer.
			Size numBitsPerAccumulationChannel;
			
			
			
			
			/// The number of anti-aliasing samples to use.
			Size numAASamples;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Devices Namespace  *****************************
RIM_GRAPHICS_DEVICES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_PIXEL_FORMAT_H
