/*
 *  rimSoundDeviceManager.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_DEVICE_MANAGER_H
#define INCLUDE_RIM_SOUND_DEVICE_MANAGER_H


#include "rimSoundDevicesConfig.h"


#include "rimSoundDeviceID.h"
#include "rimSoundDeviceManagerDelegate.h"


//##########################################################################################
//************************  Start Rim Sound Devices Namespace  *****************************
RIM_SOUND_DEVICES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which queries the system for currently connected audio devices.
/**
  * It provides a platform-independent method of determining the number of audio
  * input and output devices and accessing those devices. It maintains an internal
  * list of the currently connected audio devices. One can query the class for
  * input and output device IDs which can be used to construct device objects.
  */
class SoundDeviceManager
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a sound device manager.
			SoundDeviceManager();
			
			
			
			
			/// Create a copy of a sound device manager.
			SoundDeviceManager( const SoundDeviceManager& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this sound device manager.
			~SoundDeviceManager();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of one sound device manager to another.
			SoundDeviceManager& operator = ( const SoundDeviceManager& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Output Device Accessor Methods
			
			
			
			
			/// Get the number of connected sound devices.
			Size getDeviceCount() const;
			
			
			
			
			/// Get an identifier for the sound device at the specified index.
			/**
			  * If the specified index is out-of-bounds, SoundDeviceID::INVALID_DEVICE
			  * is returned.
			  */
			SoundDeviceID getDeviceID( Index deviceIndex ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Default Device Accessor Methods
			
			
			
			
			/// Get an identifier for the default system sound input device.
			/**
			  * If there is no default input device, SoundDeviceID::INVALID_DEVICE is
			  * returned.
			  */
			SoundDeviceID getDefaultInputDeviceID() const;
			
			
			
			
			/// Get an identifier for the default system sound output device.
			/**
			  * If there is no default output device, SoundDeviceID::INVALID_DEVICE is
			  * returned.
			  */
			SoundDeviceID getDefaultOutputDeviceID() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return a reference to the delegate object which is responding to events for this device manager.
			RIM_INLINE const SoundDeviceManagerDelegate& getDelegate() const
			{
				return delegate;
			}
			
			
			
			
			/// Replace the delegate object which is responding to events for this device manager.
			void setDelegate( const SoundDeviceManagerDelegate& newDelegate );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which wraps OS-specific data needed by the device manager.
			class Wrapper;
			
			
			
			
			/// A class which allows the device manager to be notified when a device is connected or disconnected.
			class DeviceChangeNotifier;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Make sure that the device manager has all currently available devices cached.
			void cacheDevices();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Platform-Specific Methods
			
			
			
			
			/// Initialize up any platform-specific data for a newly-created device manager.
			Bool createManager();
			
			
			
			
			/// Clean up any platform-specific data before a device manager is destroyed.
			Bool destroyManager();
			
			
			
			
			/// Register any OS-specific callbacks which notify the class when devices are disconnected or connected.
			Bool registerDeviceUpdateCallbacks();
			
			
			
			
			/// Unregister any OS-specific callbacks which notify the class when devices are disconnected or connected.
			Bool unregisterDeviceUpdateCallbacks();
			
			
			
			
			/// Refresh all of the connected audio devices to make sure that they are still there.
			Bool refreshDevices();
			
			
			
			
			/// Refresh the current default input device if a notification was received that it changed.
			Bool refreshDefaultInputDevice();
			
			
			
			
			/// Refresh the current default output device if a notification was received that it changed.
			Bool refreshDefaultOutputDevice();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An array of the IDs for every input and output device currently connected.
			ArrayList<SoundDeviceID> devices;
			
			
			
			
			/// The index of the default input device within the array of input devices.
			Index defaultInputDeviceIndex;
			
			
			
			
			/// The index of the default output device within the array of output devices.
			Index defaultOutputDeviceIndex;
			
			
			
			
			/// A mutex which protects the lists of input and output device IDs from unsafe thread access.
			/**
			  * Since devices may be asynchronously connected or disconnected from the system,
			  * it is necessary to make sure that the device ID arrays are not modified while
			  * they are being accessed.
			  */
			mutable threads::Mutex deviceChangeMutex;
			
			
			
			
			/// A mutex which protects the delegate callbacks from being modified when they are being used.
			mutable threads::Mutex delegateChangeMutex;
			
			
			
			
			/// A pointer to a class which holds information related to platform-specific audio APIs.
			Wrapper* wrapper;
			
			
			
			
			/// An object which responds to events for this sound device manager.
			SoundDeviceManagerDelegate delegate;
			
			
			
			
			/// Whether or not this device manager has cached all of the available input/ouptut devices yet.
			Bool hasCachedDevices;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Devices Namespace  *******************************
RIM_SOUND_DEVICES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_DEVICE_MANAGER_H