/*
 *  rimSoundDeviceID.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_DEVICE_ID_H
#define INCLUDE_RIM_SOUND_DEVICE_ID_H


#include "rimSoundIOConfig.h"


//##########################################################################################
//***************************  Start Rim Sound IO Namespace  *******************************
RIM_SOUND_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which is used to encapsulate a unique identifier for a system sound device.
/**
  * This opaque type uses a platform-dependent internal representation which uniquelly
  * identifies a sound device.
  */
class SoundDeviceID
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Constants
			
			
			
			
			/// Define an instance of SoundDeviceID that represents an invalid device.
			static const SoundDeviceID INVALID_DEVICE;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this device ID represents the same device as another.
			RIM_INLINE Bool operator == ( const SoundDeviceID& other ) const
			{
				return deviceID == other.deviceID;
			}
			
			
			
			
			/// Return whether or not this device ID represents a different device than another.
			RIM_INLINE Bool operator != ( const SoundDeviceID& other ) const
			{
				return deviceID != other.deviceID;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Device Status Accessor Method
			
			
			
			
			/// Return whether or not this SoundDeviceID represents a valid device.
			/**
			  * This condition is met whenever the device ID is not equal to INVALID_DEVICE_ID.
			  */
			RIM_INLINE Bool isValid() const
			{
				return deviceID != INVALID_DEVICE_ID;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructor
			
			
			
			
#if defined(RIM_PLATFORM_WINDOWS)
			/// Create a SoundDeviceID object which represents the device with the specified device ID.
			RIM_INLINE explicit SoundDeviceID( const UTF16String& newDeviceID )
				:	deviceID( newDeviceID )
			{
			}
			
#else
			/// Create a SoundDeviceID object which represents the device with the specified device ID.
			RIM_INLINE explicit SoundDeviceID( UInt newDeviceID )
				:	deviceID( newDeviceID )
			{
			}
#endif
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Conversion Methods
			
			
			
			
#if defined(RIM_PLATFORM_WINDOWS)
			/// Return a const reference to the wide-character string uniquely representing a sound device.
			RIM_INLINE const UTF16String& getIDString() const
			{
				return deviceID;
			}
#else
			/// Convert this SoundDeviceID object to an unsigned integer which uniquely represents a sound device.
			RIM_INLINE operator UInt () const
			{
				return deviceID;
			}
#endif
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
#if defined(RIM_PLATFORM_WINDOWS)
			
			/// The underlying representation of a SoundDeviceID on windows, a UTF-16 encoded ID string.
			UTF16String deviceID;
			
			/// The reserved ID used to indicate an invalid device.
			static const UTF16String INVALID_DEVICE_ID;
			
#else
			
			/// The underlying representation of a SoundDeviceID, an unsigned integer.
			UInt deviceID;
			
			/// The reserved ID used to indicate an invalid device.
			static const UInt INVALID_DEVICE_ID = 0xFFFFFFFF;
			
#endif
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Declaration
			
			
			
			
			/// Declare the SoundDeviceManager a friend so that it can construct SoundDeviceID objects.
			friend class SoundDeviceManager;
			
			
			
			
			/// Declare the SoundDevice a friend so that it can construct SoundDeviceID objects.
			friend class SoundDevice;
			
			
			
};




//##########################################################################################
//***************************  End Rim Sound IO Namespace  *********************************
RIM_SOUND_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_DEVICE_ID_H
