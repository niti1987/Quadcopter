/*
 *  rimSoundDeviceDelegate.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 4/2/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_DEVICE_DELEGATE_H
#define INCLUDE_RIM_SOUND_DEVICE_DELEGATE_H


#include "rimSoundIOConfig.h"


//##########################################################################################
//***************************  Start Rim Sound IO Namespace  *******************************
RIM_SOUND_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class SoundDevice;




/// Define a short name for the type of the function object that is used to recieve audio from SoundDevice objects.
/**
  * The implementor of the function can read the specified number of samples from the input buffer and
  * use them in some way.
  *
  * The given time represents the absolute time of the first sample in the buffer,
  * measured relative to the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
  */
typedef Function<void ( SoundDevice& device, const SoundBuffer& inputBuffer, Size numInputSamples, const Time& time )> SoundInputCallback;




/// Define a short name for the type of the function object that is used to send audio to SoundDevice objects for output.
/**
  * The implementor should write the specified number of samples to the output buffer for each channel
  * and then return the number of samples that were successfully written to the output buffer.
  *
  * The given time represents the absolute time of the first sample in the buffer,
  * measured relative to the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
  */
typedef Function<Size ( SoundDevice& device, SoundBuffer& outputBuffer, Size numOutputSamples, const Time& time )> SoundOutputCallback;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve SoundDevice events.
/**
  * Any device-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the device
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, the device simply ignores it.
  */
class SoundDeviceDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sound Device Delegate Callback Functions
			
			
			
			
			/// A function object which is called whenever the device provides input audio.
			/**
			  * This callback is called whenever the SoundDevice has audio that it has captured on its inputs.
			  * The implementor of the callback method can read the samples from the given input sound buffer.
			  *
			  * This method will be called from a separate thread (the audio processing thread)
			  * so any data accessed in the callback function should use proper thread synchonization
			  * to avoid unsafe access.
			  */
			SoundInputCallback inputCallback;
			
			
			
			
			/// A function object which is called whenever the device requests output audio.
			/**
			  * This callback is called whenever the SoundDevice needs output audio to send to the device.
			  * The implementor of the callback method should produce sound which is written to the output
			  * buffer for the requested number of samples. If the callback takes too long to process
			  * the samples for output, the result is that output buffers are dropped, producing choppy audio.
			  *
			  * This method will be called from a separate thread (the audio processing thread)
			  * so any data accessed in the callback function should use proper thread synchonization
			  * to avoid unsafe access.
			  */
			SoundOutputCallback outputCallback;
			
			
			
			
			/// A function called whenever the device detects that the user has taken too long to process audio I/O.
			/**
			  * When this happens, the device must drop input or output frames, causing glitchy audio.
			  * This callback exists so that the user can detect this event and reduce the audio thread
			  * processing load.
			  */
			Function<void ( SoundDevice& device )> processOverload;
			
			
			
			
			/// A function object which is called whenever the sound device is removed from the system.
			Function<void ( SoundDevice& device )> removed;
			
			
			
			
			/// A function object which is called whenever the sampling rate for a SoundDevice has changed.
			Function<void ( SoundDevice& device, SampleRate newSampleRate )> sampleRateChanged;
			
			
			
};




//##########################################################################################
//***************************  End Rim Sound IO Namespace  *********************************
RIM_SOUND_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_DEVICE_DELEGATE_H
