/*
 *  rimGraphicsDevice.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/1/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_DEVICE_H
#define INCLUDE_RIM_GRAPHICS_DEVICE_H


#include "rimGraphicsDevicesConfig.h"


#include "rimGraphicsContext.h"
#include "rimGraphicsContextFlags.h"
#include "rimGraphicsPixelFormat.h"
#include "rimGraphicsDeviceType.h"


//##########################################################################################
//***********************  Start Rim Graphics Devices Namespace  ***************************
RIM_GRAPHICS_DEVICES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents an interface to a graphics device driver.
/**
  * Specialized implementations inherit from this interface to provide
  * a way to provide uniform access to their underlying drivers. For instance,
  * there could be a class OpenGLDevice which inherits from GraphicsDevice
  * and represents an OpenGL device driver.
  */
class GraphicsDevice
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a graphics device, releasing all of its resources and internal state.
			virtual ~GraphicsDevice()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Context Creation Method
			
			
			
			
			/// Create a new context for this graphics device with the specified framebuffer pixel format and flags.
			/**
			  * This method chooses a pixel format for the context which most closely matches
			  * the specified pixel format and flags. A pointer to the created context is
			  * returned. If the returned pointer is NULL, the context creation failed.
			  */
			virtual Pointer<GraphicsContext> createContext( const Pointer<RenderView>& targetView,
															const RenderedPixelFormat& pixelFormat,
															const GraphicsContextFlags& flags ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Device Capabilities Accessor Methods
			
			
			
			
			/// Return whether or not the specified pixel format and flags are supported by this device.
			/**
			  * If they are supported as-is, the method returns TRUE indicating that the format
			  * is supported by this device.
			  *
			  * If the format is not entirely supported but can be approximated
			  * (i.e. different bit depth) and the strict flag is not set, the
			  * supported format which most closely matches the specified format is written to the
			  * output pixel format and flags. TRUE is returned.
			  *
			  * Otherwise, if the format cannot be approximated or if the strict flag is set,
			  * FALSE is returned indicating that the format is not supported. This means that
			  * creating a device context with these settings would fail.
			  */
			virtual Bool checkFormat( RenderedPixelFormat& pixelFormat, GraphicsContextFlags& flags,
									Bool strict = false ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Type Accessor Method
			
			
			
			
			/// Return an object which indicates the type of this graphics device.
			virtual GraphicsDeviceType getType() const = 0;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Devices Namespace  *****************************
RIM_GRAPHICS_DEVICES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_DEVICE_H
