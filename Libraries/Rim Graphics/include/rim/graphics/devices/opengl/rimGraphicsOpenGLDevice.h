/*
 *  rimGraphicsOpenGLDevice.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/1/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_OPENGL_DEVICE_H
#define INCLUDE_RIM_GRAPHICS_OPENGL_DEVICE_H


#include "rimGraphicsOpenGLConfig.h"


//##########################################################################################
//********************  Start Rim Graphics Devices OpenGL Namespace  ***********************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents an interface to an OpenGL device driver.
/**
  * This class allows the user to create OpenGL contexts for an OpenGL device
  * which can then be used for rendering.
  */
class OpenGLDevice : public GraphicsDevice
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Context Creation Method
			
			
			
			
			/// Create a new context for this graphics device with the specified framebuffer pixel format and flags.
			virtual Pointer<GraphicsContext> createContext( const Pointer<RenderView>& targetView,
															const RenderedPixelFormat& pixelFormat,
															const GraphicsContextFlags& flags );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Device Capabilities Accessor Methods
			
			
			
			
			/// Return whether or not the specified pixel format and flags are supported by this device.
			virtual Bool checkFormat( RenderedPixelFormat& pixelFormat, GraphicsContextFlags& flags,
									Bool strict = false ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Type Accessor Method
			
			
			
			
			/// Return an object which indicates the type of this graphics device.
			virtual GraphicsDeviceType getType() const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			
			
			
			
			
};




//##########################################################################################
//********************  End Rim Graphics Devices OpenGL Namespace  *************************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_OPENGL_DEVICE_H
