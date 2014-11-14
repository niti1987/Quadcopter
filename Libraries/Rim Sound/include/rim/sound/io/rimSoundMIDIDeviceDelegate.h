/*
 *  rimSoundMIDIDeviceDelegate.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 4/2/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_MIDI_DEVICE_DELEGATE_H
#define INCLUDE_RIM_SOUND_MIDI_DEVICE_DELEGATE_H


#include "rimSoundIOConfig.h"


//##########################################################################################
//***************************  Start Rim Sound IO Namespace  *******************************
RIM_SOUND_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class MIDIDevice;



/// Define a short name for the type of the function object that is used to recieve MIDI from MIDIDevice objects.
/**
  * The implementor of the function can then use the given MIDI messages to perform some action.
  */
typedef Function<void ( MIDIDevice& device, const MIDIBuffer& messages )> MIDIInputCallback;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve MIDIDevice events.
/**
  * Any device-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the device
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, the device simply ignores it.
  */
class MIDIDeviceDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	MIDI Device Delegate Callback Functions
			
			
			
			
			/// A function object which is called whenever the device provides input MIDI messages.
			MIDIInputCallback inputCallback;
			
			
			
			
			/// A function object which is called whenever the MIDI device is added to the system.
			Function<void ( MIDIDevice& device )> added;
			
			
			
			
			/// A function object which is called whenever the MIDI device is removed from the system.
			Function<void ( MIDIDevice& device )> removed;
			
			
			
};




//##########################################################################################
//***************************  End Rim Sound IO Namespace  *********************************
RIM_SOUND_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_MIDI_DEVICE_DELEGATE_H
