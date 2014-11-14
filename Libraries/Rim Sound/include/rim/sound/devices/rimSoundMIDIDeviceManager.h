/*
 *  rimSoundMIDIDeviceManager.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 4/2/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_MIDI_DEVICE_MANAGER_H
#define INCLUDE_RIM_SOUND_MIDI_DEVICE_MANAGER_H


#include "rimSoundDevicesConfig.h"


#include "rimSoundMIDIDeviceID.h"
#include "rimSoundMIDIDeviceManagerDelegate.h"


//##########################################################################################
//************************  Start Rim Sound Devices Namespace  *****************************
RIM_SOUND_DEVICES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which queries the system for currently connected MIDI devices.
/**
  * It provides a platform-independent method of determining the number of MIDI
  * input and output devices and accessing those devices. It maintains an internal
  * list of the currently connected MIDI devices. One can query the class for
  * input and output device IDs which can be used to construct device objects.
  */
class MIDIDeviceManager
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a MIDI device manager.
			MIDIDeviceManager();
			
			
			
			
			/// Create a copy of a MIDI device manager.
			MIDIDeviceManager( const MIDIDeviceManager& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this MIDI device manager.
			~MIDIDeviceManager();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of one MIDI device manager to another.
			MIDIDeviceManager& operator = ( const MIDIDeviceManager& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Input Device Accessor Methods
			
			
			
			
			/// Get the number of connected MIDI input devices.
			Size getInputDeviceCount() const;
			
			
			
			
			/// Get an identifier for the MIDI input device at the specified index.
			/**
			  * If the specified index is out-of-bounds, MIDIDeviceID::INVALID_DEVICE
			  * is returned.
			  */
			MIDIDeviceID getInputDeviceID( Index deviceIndex ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Output Device Accessor Methods
			
			
			
			
			/// Get the number of connected MIDI output devices.
			Size getOutputDeviceCount() const;
			
			
			
			
			/// Get an identifier for the MIDI output device at the specified index.
			/**
			  * If the specified index is out-of-bounds, MIDIDeviceID::INVALID_DEVICE
			  * is returned.
			  */
			MIDIDeviceID getOutputDeviceID( Index deviceIndex ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Default Device Accessor Methods
			
			
			
			
			/// Get an identifier for the default system MIDI input device.
			/**
			  * If there is no default input device, MIDIDeviceID::INVALID_DEVICE is
			  * returned.
			  */
			MIDIDeviceID getDefaultInputDeviceID() const;
			
			
			
			
			/// Get an identifier for the default system MIDI output device.
			/**
			  * If there is no default output device, MIDIDeviceID::INVALID_DEVICE is
			  * returned.
			  */
			MIDIDeviceID getDefaultOutputDeviceID() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return a reference to the delegate object which is responding to events for this device manager.
			RIM_INLINE const MIDIDeviceManagerDelegate& getDelegate() const
			{
				return delegate;
			}
			
			
			
			
			/// Replace the delegate object which is responding to events for this device manager.
			void setDelegate( const MIDIDeviceManagerDelegate& newDelegate );
			
			
			
			
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
			
			
			
			
			/// Refresh all of the connected MIDI devices to make sure that they are still there.
			Bool refreshDevices();
			
			
			
			
			/// Refresh the current default input device if a notification was received that it changed.
			Bool refreshDefaultInputDevice();
			
			
			
			
			/// Refresh the current default output device if a notification was received that it changed.
			Bool refreshDefaultOutputDevice();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An array of the IDs for every input device currently connected.
			ArrayList<MIDIDeviceID> inputDevices;
			
			
			
			
			/// An array of the IDs for every output device currently connected.
			ArrayList<MIDIDeviceID> outputDevices;
			
			
			
			
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
			
			
			
			
			/// A pointer to a class which holds information related to platform-specific MIDI APIs.
			Wrapper* wrapper;
			
			
			
			
			/// An object which responds to events for this MIDI device manager.
			MIDIDeviceManagerDelegate delegate;
			
			
			
			
			/// Whether or not this device manager has cached all of the available input/ouptut devices yet.
			Bool hasCachedDevices;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Devices Namespace  *******************************
RIM_SOUND_DEVICES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_MIDI_DEVICE_MANAGER_H
