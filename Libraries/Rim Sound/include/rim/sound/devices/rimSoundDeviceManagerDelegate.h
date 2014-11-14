/*
 *  rimSoundDeviceManagerDelegate.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 4/2/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_DEVICE_MANAGER_DELEGATE_H
#define INCLUDE_RIM_SOUND_DEVICE_MANAGER_DELEGATE_H


#include "rimSoundDevicesConfig.h"


//##########################################################################################
//************************  Start Rim Sound Devices Namespace  *****************************
RIM_SOUND_DEVICES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class SoundDeviceManager;
class SoundDeviceID;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve SoundDeviceManager events.
/**
  * Any device-manager-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the device manager
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, the device manager simply ignores it.
  */
class SoundDeviceManagerDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sound Device Manager Delegate Callback Functions
			
			
			
			
			/// A function object which is called whenever a new sound device is discovered by the system.
			/**
			  * This callback is called whenever a new sound device is connected or added to the
			  * system. This allows the user to use new sound devices as they are discovered.
			  *
			  * This method will be called from a separate thread (the audio processing thread)
			  * so any data accessed in the callback function should use proper thread synchonization
			  * to avoid unsafe access.
			  */
			Function<void ( SoundDeviceManager& manager, const SoundDeviceID& deviceID )> deviceAdded;
			
			
			
			
			/// A function object which is called whenever a sound device is removed from the system.
			/**
			  * This callback is called whenever a sound device is disconnected or removed from the
			  * system. This allows the user to know when devices are disconnected and to discontinue use
			  * of those devices.
			  *
			  * This method will be called from a separate thread (the audio processing thread)
			  * so any data accessed in the callback function should use proper thread synchonization
			  * to avoid unsafe access.
			  */
			Function<void ( SoundDeviceManager& manager, const SoundDeviceID& deviceID )> deviceRemoved;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Devices Namespace  *******************************
RIM_SOUND_DEVICES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_DEVICE_MANAGER_DELEGATE_H
