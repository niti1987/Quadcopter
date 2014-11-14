/*
 *  rimSoundThreadedStreamRecorder.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 8/16/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_THREADED_STREAM_RECORDER_H
#define INCLUDE_RIM_SOUND_THREADED_STREAM_RECORDER_H


#include "rimSoundFiltersConfig.h"


#include "rimSoundFilter.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that handles recording audio data to a streaming sound destination on a different thread.
/**
  * This class takes a pointer to a SoundOutputStream and then records sound
  * to that stream when the recorder is set to the 'record' mode. This class spawns
  * a new thread which sends the data to the SoundOutputStream when it is recieved
  * by the processing thread. Since encoding data with a SoundOutputStream can be slower
  * than real time (often due to disk throughput), this class prevents recording stalls
  * or dropped frames that can occur if recording and encoding are on the same thread.
  */
class ThreadedStreamRecorder : public SoundFilter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default threaded sound stream recorder without any stream to record to.
			/**
			  * The constructed object will not do any recording until it has a valid
			  * stream object.
			  */
			ThreadedStreamRecorder();
			
			
			
			
			/// Create a threaded sound stream recorder which records to the specified sound output stream.
			/**
			  * If the supplied stream is NULL or invalid, the stream recorder records no sound.
			  * All recording occurs relative to the initial position within the stream.
			  */
			ThreadedStreamRecorder( const Pointer<SoundOutputStream>& newStream );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a threaded sound stream recorder and release all resources associated with it.
			~ThreadedStreamRecorder();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Accessor Methods
			
			
			
			
			/// Return a const pointer to the SoundOutputStream which is being written to.
			/**
			  * If there is no sound output stream set or if the stream is not valid, a NULL
			  * pointer is returned, indicating the problem.
			  */
			const SoundOutputStream* getStream() const;
			
			
			
			
			/// Set the SoundOutputStream which this recorder should use as a sound destination.
			/**
			  * If the supplied pointer is NULL, the sound recorder is deactivated and doesn't
			  * record any more audio. Otherwise, the recorder resets its current recording
			  * position and starts recording to the current position in the stream.
			  * Thus, all recording occurs relative to the initial position
			  * within the stream.
			  */
			void setStream( const Pointer<SoundOutputStream>& newStream );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Recording Accessor Methods
			
			
			
			
			/// Return whether or not this threaded sound recorder is current recording audio.
			Bool isRecording() const;
			
			
			
			
			/// Set whether or not this threaded sound recorder should be recording its input sound.
			/**
			  * The method returns whether or not recording will occurr, based on the type 
			  * of SoundOutputSream which this player has and the requested playback
			  * state.
			  */
			Bool setIsRecording( Bool newIsRecording );
			
			
			
			
			/// Tell the threaded sound recorder to start recording sound from the current position.
			/**
			  * The method returns whether or not recording will occurr, based on the type 
			  * of SoundInputStream that this player has.
			  */
			Bool record();
			
			
			
			
			/// Stop recording sound and keep the record head at the last position.
			void stop();
			
			
			
			
			/// Reset the recording position to the first position within the stream.
			/**
			  * The method returns whether or not the rewind operation was successul.
			  * For SoundOutputStream objects that don't allow seeking, this method
			  * will always fail. This method does not affect the recording state of the
			  * recorder, thus rewinding will cause the recording to jump to the beginning
			  * of the stream if the recorder is currently recording.
			  */
			Bool rewind();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Attribute Accessor Methods
			
			
			
			
			/// Return a human-readable name for this threaded stream recorder.
			/**
			  * The method returns the string "Threaded Stream Recorder".
			  */
			virtual UTF8String getName() const;
			
			
			
			
			/// Return the manufacturer name of this threaded stream recorder.
			/**
			  * The method returns the string "Headspace Sound".
			  */
			virtual UTF8String getManufacturer() const;
			
			
			
			
			/// Return an object representing the version of this threaded stream recorder.
			virtual SoundFilterVersion getVersion() const;
			
			
			
			
			/// Return an object which describes the category of effect that this filter implements.
			/**
			  * This method returns the value SoundFilterCategory::RECORDING.
			  */
			virtual SoundFilterCategory getCategory() const;
			
			
			
			
			/// Return whether or not this threaded stream recorder can process audio data in-place.
			/**
			  * This method always returns TRUE, threaded stream recorders can process audio data in-place.
			  */
			virtual Bool allowsInPlaceProcessing() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Property Objects
			
			
			
			
			/// A string indicating the human-readable name of this threadedstream recorder.
			static const UTF8String NAME;
			
			
			
			
			/// A string indicating the manufacturer name of this threaded stream recorder.
			static const UTF8String MANUFACTURER;
			
			
			
			
			/// An object indicating the version of this threaded stream recorder.
			static const SoundFilterVersion VERSION;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Copy Operations
			
			
			
			
			/// Create a copy of this threaded stream recorder and its state.
			/**
			  * Note, it is very important that there only be one stream recorder that
			  * is using a SoundOutputStream at a time. Thus this copy operation is declared
			  * private.
			  */
			ThreadedStreamRecorder( const ThreadedStreamRecorder& other );
			
			
			
			
			/// Create a copy of this threaded stream recorder and its state.
			/**
			  * Note, it is very important that there only be one stream recorder that
			  * is using a SoundOutputStream at a time. Thus this copy operation is declared
			  * private.
			  */
			ThreadedStreamRecorder& operator = ( const ThreadedStreamRecorder& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Filter Processing Methods
			
			
			
			
			/// Record the specified number of samples from the input frame to the sound output stream.
			virtual SoundFilterResult processFrame( const SoundFilterFrame& inputFrame,
													SoundFilterFrame& outputFrame, Size numSamples );
			
			
			
			
			/// Start taking audio out of the buffer queue and writing it to the output stream.
			void recordingThreadEntry();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A thread object which represents the current recording thread.
			threads::Thread recordingThread;
			
			
			
			
			/// A queue of buffers of sound data which is queued to be recorded.
			SoundBufferQueue queue;
			
			
			
			
			/// A pointer to the sound output stream to which this recorder is recording.
			Pointer<SoundOutputStream> stream;
			
			
			
			
			/// The current position within the stream, relative to the initial position within the stream.
			SampleIndex currentStreamPosition;
			
			
			
			
			/// The current maximum position that has been reached in the stream.
			/**
			  * This value allows the recorder to determine the total size of the stream
			  * indirectly by noting the positions within the sound stream where recording
			  * started and ended. The difference is the total length of the sound and it
			  * is used when rewinding in the stream.
			  */
			SoundSize currentStreamLength;
			
			
			
			
			/// A boolean value indicating whether or not the stream recorder should be recording input audio..
			Bool recordingEnabled;
			
			
			
			
			/// A boolean value indicating whether or not the sound stream supports seeking.
			Bool seekingAllowed;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_THREADED_STREAM_RECORDER_H
