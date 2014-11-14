/*
 *  rimSoundMIDIDeviceID.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 4/2/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_MIDI_DEVICE_ID_H
#define INCLUDE_RIM_SOUND_MIDI_DEVICE_ID_H


#include "rimSoundDevicesConfig.h"


//##########################################################################################
//************************  Start Rim Sound Devices Namespace  *****************************
RIM_SOUND_DEVICES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which is used to encapsulate a unique identifier for a system MIDI device.
/**
  * This opaque type uses a platform-dependent internal representation which uniquelly
  * identifies a MIDI device.
  */
class MIDIDeviceID
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Constants
			
			
			
			
			/// Define an instance of MIDIDeviceID that represents an invalid device.
			static const MIDIDeviceID INVALID_DEVICE;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this device ID represents the same device as another.
			RIM_INLINE Bool operator == ( const MIDIDeviceID& other ) const
			{
				return deviceID == other.deviceID && input == other.input && output == other.output;
			}
			
			
			
			
			/// Return whether or not this device ID represents a different device than another.
			RIM_INLINE Bool operator != ( const MIDIDeviceID& other ) const
			{
				return deviceID != other.deviceID || input != other.input || output != other.output;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Device Status Accessor Methods
			
			
			
			
			/// Return whether or not this MIDIDeviceID represents a valid device.
			/**
			  * This condition is met whenever the device ID is not equal to INVALID_DEVICE_ID.
			  */
			RIM_INLINE Bool isValid() const
			{
				return deviceID != INVALID_DEVICE_ID;
			}
			
			
			
			
			/// Return whether or not this device ID represents a device capable of MIDI input.
			RIM_INLINE Bool isInput() const
			{
				return input;
			}
			
			
			
			
			/// Return whether or not this device ID represents a device capable of MIDI output.
			RIM_INLINE Bool isOutput() const
			{
				return output;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructor
			
			
			
			
#if defined(RIM_PLATFORM_APPLE)
	#if defined(RIM_PLATFORM_64_BIT)
			/// Create a MIDIDeviceID object which represents the device with the specified device ID.
			RIM_INLINE MIDIDeviceID( UInt32 newDeviceID, Bool newIsInput, Bool newIsOutput )
				:	deviceID( newDeviceID ),
					input( newIsInput ),
					output( newIsOutput )
			{
			}
	#else
			/// Create a MIDIDeviceID object which represents the device with the specified device ID.
			RIM_INLINE MIDIDeviceID( void* newDeviceID, Bool newIsInput, Bool newIsOutput )
				:	deviceID( newDeviceID ),
					input( newIsInput ),
					output( newIsOutput )
			{
			}
	#endif

#elif defined(RIM_PLATFORM_WINDOWS)
			RIM_INLINE MIDIDeviceID( UInt newDeviceID, Bool newIsInput, Bool newIsOutput )
				:	deviceID( newDeviceID ),
					input( newIsInput ),
					output( newIsOutput )
			{
			}
#endif
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Conversion Methods
			
			
			
			
#if defined(RIM_PLATFORM_APPLE)
	#if defined(RIM_PLATFORM_64_BIT)
			/// Convert this MIDIDeviceID object to a 32-bit integer which uniquely represents a MIDI device.
			RIM_INLINE UInt32 getInternalID() const
			{
				return deviceID;
			}
	#else
			/// Convert this MIDIDeviceID object to a pointer which uniquely represents a MIDI device.
			RIM_INLINE void* getInternalID() const
			{
				return deviceID;
			}
	#endif

#elif defined(RIM_PLATFORM_WINDOWS)
			/// Convert this MIDIDeviceID object to an integer which uniquely represents a MIDI device.
			RIM_INLINE UInt getInternalID() const
			{
				return deviceID;
			}
#endif
			
			
			
			
#if defined(RIM_PLATFORM_APPLE)
	#if defined(RIM_PLATFORM_64_BIT)
			/// Convert this MIDIDeviceID object to a 32-bit integer which uniquely represents a MIDI device.
			RIM_INLINE operator UInt32 () const
			{
				return deviceID;
			}
	#else
			/// Convert this MIDIDeviceID object to a pointer which uniquely represents a MIDI device.
			RIM_INLINE operator void* () const
			{
				return deviceID;
			}
	#endif

#elif defined(RIM_PLATFORM_WINDOWS)
			/// Convert this MIDIDeviceID object to an integer which uniquely represents a MIDI device.
			RIM_INLINE operator UInt () const
			{
				return deviceID;
			}
#endif
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
#if defined(RIM_PLATFORM_APPLE)
	#if defined(RIM_PLATFORM_64_BIT)
			/// The underlying representation of a MIDIDeviceID on 64-bit Mac OS X, a 32-bit integer.
			UInt32 deviceID;
			
			/// The reserved ID used to indicate an invalid device.
			static UInt32 INVALID_DEVICE_ID;
	#else
			/// The underlying representation of a MIDIDeviceID on 32-bit Mac OS X, a pointer.
			void* deviceID;
			
			/// The reserved ID used to indicate an invalid device.
			static void* INVALID_DEVICE_ID;
	#endif

#elif defined(RIM_PLATFORM_WINDOWS)
			/// The underlying representation of a MIDIDeviceID on Windows, an unsigned integer.
			UInt deviceID;
			
			/// The reserved ID used to indicate an invalid device.
			static UInt INVALID_DEVICE_ID;
#endif
			
			
			
			/// A boolean value indicating whether or not this device ID represents an input device.
			Bool input;
			
			
			
			
			/// A boolean value indicating whether or not this device ID represents an output device.
			Bool output;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Declaration
			
			
			
			
			/// Declare the MIDIDeviceManager a friend so that it can construct MIDIDeviceID objects.
			friend class MIDIDeviceManager;
			
			
			
			
			/// Declare the MIDIDevice a friend so that it can construct MIDIDeviceID objects.
			friend class MIDIDevice;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Devices Namespace  *******************************
RIM_SOUND_DEVICES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_MIDI_DEVICE_ID_H
