/*
 *  rimOpenGLPixelFormat.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 5/25/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_OPENGL_PIXEL_FORMAT_H
#define INCLUDE_RIM_OPENGL_PIXEL_FORMAT_H


#include "rimGUIConfig.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which describes the attributes of an OpenGL framebuffer pixel format.
class OpenGLPixelFormat
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Pixel Format Flags Enum Declaration
			
			
			
			
			/// An enum type which describes the various boolean flags that a pixel format can have.
			typedef enum Flags
			{
				/// A flag indicating that double buffering should be used for the main framebuffer.
				DOUBLE_BUFFERED = 1,
				
				/// A flag indicating that the main framebuffer should have an alpha channel.
				ALPHA = 2,
				
				/// A flag indicating that multisample anti-aliasing should be used.
				MULTISAMPLE_AA = 4,
				
				/// A flag indicating that supersample anti-aliasing should be used.
				/**
				  * This flag overrides the MULTISAMPLE_AA flag if it is set.
				  */
				SUPERSAMPLE_AA = 8
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a default initialized OpenGL pixel format object.
			RIM_INLINE OpenGLPixelFormat()
				:	numBitsPerChannel( 8 ),
					numDepthBits( 32 ),
					numStencilBits( 0 ),
					numBitsPerAccumulationChannel( 0 ),
					numAASamples( 0 ),
					flags( DOUBLE_BUFFERED )
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
			
			
			
			
			/// A bitfield indicating various boolean attributes for this pixel format.
			UInt32 flags;
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_OPENGL_PIXEL_FORMAT_H
