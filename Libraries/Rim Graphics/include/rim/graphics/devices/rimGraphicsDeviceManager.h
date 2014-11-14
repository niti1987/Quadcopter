/*
 *  rimGraphicsDeviceManager.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/1/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_DEVICE_MANAGER_H
#define INCLUDE_RIM_GRAPHICS_DEVICE_MANAGER_H


#include "rimGraphicsDevicesConfig.h"


#include "rimGraphicsDevice.h"
#include "rimGraphicsDeviceType.h"


//##########################################################################################
//***********************  Start Rim Graphics Devices Namespace  ***************************
RIM_GRAPHICS_DEVICES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which enumerates the available kinds of graphics devices for this system.
/**
  * This allows the user to pick an arbitrary GraphicsDevice and use it for rendering.
  * For instance, the device manager might support 2 devices: one for OpenGL and another
  * for Direct3D. The user can pick a device at run time and use it.
  */
class GraphicsDeviceManager
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new graphics device manager which inspects the available system graphics devices.
			GraphicsDeviceManager();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this graphics device manager and release all associated resources.
			virtual ~GraphicsDeviceManager();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Device Accessor Methods
			
			
			
			
			/// Return the total number of graphics devices that this manager is aware of.
			Size getDeviceCount() const;
			
			
			
			
			/// Return a pointer to the graphics device at the specified index in the device manager.
			/**
			  * If an invalid device index is specified, a NULL pointer is returned.
			  */
			Pointer<GraphicsDevice> getDevice( Index deviceIndex ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Default Device Accessor Method
			
			
			
			
			/// Return a pointer to the default graphics device for this system.
			/**
			  * If there are no devices present which could be the default, a NULL pointer is returned.
			  */
			Pointer<GraphicsDevice> getDefaultDevice() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Device Type Methods
			
			
			
			
			/// Return a pointer to the graphics device on this system with the specified device type.
			/**
			  * If there are no devices present with that device type, a NULL pointer is returned.
			  */
			Pointer<GraphicsDevice> getDeviceWithType( const GraphicsDeviceType& newType ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Device Registration Methods
			
			
			
			
			/// Register the specified graphics device pointer with this device manager.
			/**
			  * This allows the user to make the manager aware of new types of devices
			  * that it might not be aware of. The method returns whether or not the specified
			  * device was able to be registered. The method can fail if the new device
			  * pointer is NULL.
			  */
			virtual Bool registerDevice( const Pointer<GraphicsDevice>& newDevice );
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Helper Method
			
			
			
			
			/// Detect the devices that are available on this system and add them to the device list.
			virtual void detectDevices();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of pointers to graphics devices that are available on this system.
			ArrayList< Pointer<GraphicsDevice> > devices;
			
			
			
			
			/// A boolean value indicating whether or not the device manager has already determined the available devices.
			mutable Bool detectedDevices;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Devices Namespace  *****************************
RIM_GRAPHICS_DEVICES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_DEVICE_MANAGER_H
