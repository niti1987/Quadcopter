/*
 *  rimSoundInputStream.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 7/26/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_INPUT_STREAM_H
#define INCLUDE_RIM_SOUND_INPUT_STREAM_H


#include "rimSoundUtilitiesConfig.h"


#include "rimSoundBuffer.h"
#include "rimSoundSampleType.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which abstracts a read-only source of sound samples.
/**
  * This class serves as an interface for things like sound file input,
  * streaming input, etc. Reading from a SoundInputStream is very similar to reading
  * from a file.
  */
class SoundInputStream
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this sound input stream and release any resources associated with it.
			virtual ~SoundInputStream()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sound Reading Methods
			
			
			
			
			/// Read the specified number of samples from the input stream into the output buffer.
			/**
			  * This method attempts to read the specified number of samples from the stream
			  * into the input buffer. It then returns the total number of valid samples which
			  * were read into the output buffer. The samples are converted to the format
			  * stored in the input buffer (Sample32f). The input position in the stream
			  * is advanced by the number of samples that are read.
			  *
			  * This method enlarges the buffer to be at least as large as the number of requested
			  * samples, as well as makes sure it has as many channels as the stream has.
			  */
			Size read( SoundBuffer& inputBuffer, Size numSamples );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Seek Status Accessor Methods
			
			
			
			
			/// Return whether or not seeking is allowed in this input stream.
			virtual Bool canSeek() const = 0;
			
			
			
			
			/// Return whether or not this input stream's current position can be moved by the specified signed sample offset.
			/**
			  * This sample offset is specified as the number of sample frames to move
			  * in the stream - a frame is equal to one sample for each channel in the stream.
			  */
			virtual Bool canSeek( Int64 relativeSampleOffset ) const = 0;
			
			
			
			
			/// Move the current sample frame position in the stream by the specified signed amount.
			/**
			  * This method attempts to seek the position in the stream by the specified amount.
			  * The method returns the signed amount that the position in the stream was changed
			  * by. Thus, if seeking is not allowed, 0 is returned. Otherwise, the stream should
			  * seek as far as possible in the specified direction and return the actual change
			  * in position.
			  */
			virtual Int64 seek( Int64 relativeSampleOffset ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Size Accessor Methods
			
			
			
			
			/// Return the number of samples remaining in the sound input stream.
			/**
			  * The value returned must only be a lower bound on the total number of sample
			  * frames in the stream. For instance, if there are samples remaining, the method
			  * should return at least 1. If there are no samples remaining, the method should
			  * return 0. This behavior is allowed in order to support never-ending streams
			  * which might not have a defined endpoint.
			  */
			virtual SoundSize getSamplesRemaining() const = 0;
			
			
			
			
			/// Return whether or not this sound input stream has any samples remaining in the stream.
			RIM_INLINE Bool hasSamplesRemaining() const
			{
				return this->getSamplesRemaining() > SoundSize(0);
			}
			
			
			
			
			/// Return the current position of the stream in samples relative to the start of the stream.
			/**
			  * The returned value indicates the sample index of the current read
			  * position within the sound stream. For unbounded streams, this indicates
			  * the number of samples that have been read by the stream since it was opened.
			  */
			virtual SampleIndex getPosition() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Format Accessor Methods
			
			
			
			
			/// Return the number of channels that are in the sound input stream.
			/**
			  * This is the number of channels that will be read with each read call
			  * to the stream's read method.
			  */
			virtual Size getChannelCount() const = 0;
			
			
			
			
			/// Return the sample rate of the sound input stream's source audio data.
			/**
			  * Since some types of streams support variable sampling rates, this value
			  * is not necessarily the sample rate of all audio that is read from the stream.
			  * However, for most streams, this value represents the sample rate of the entire
			  * stream. One should always test the sample rate of the buffers returned by the
			  * stream to see what their sample rates are before doing any operations that assume
			  * a sampling rate.
			  */
			virtual SampleRate getSampleRate() const = 0;
			
			
			
			
			/// Return the actual sample type used in the stream.
			/**
			  * This is the format of the stream's source data. For instance, a file
			  * might be encoded with 8-bit, 16-bit or 24-bit samples. This value
			  * indicates that sample type. For formats that don't have a native sample type,
			  * such as those which use frequency domain encoding, this function should
			  * return SampleType::SAMPLE_32F, indicating that the stream's native format
			  * is 32-bit floating point samples.
			  */
			virtual SampleType getNativeSampleType() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Status Accessor Method
			
			
			
			
			/// Return whether or not the stream has a valid source of sound data.
			/**
			  * This method should return TRUE if everything is OK, but might return
			  * FALSE if the input stream is not valid (file not found, etc) or
			  * if the stream's data has improper format.
			  */
			virtual Bool isValid() const = 0;
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Sound Input Method
			
			
			
			
			/// Read the specified number of samples from the input stream into the output buffer.
			/**
			  * This method attempts to read the specified number of samples from the stream
			  * into the input buffer. It then returns the total number of valid samples which
			  * were read into the output buffer. The samples are converted to the format
			  * stored in the input buffer (Sample32f). The input position in the stream
			  * is advanced by the number of samples that are read.
			  *
			  * The implementor of this method should make sure to set the sample rate of the
			  * buffer to be the correct output sample rate.
			  */
			virtual Size readSamples( SoundBuffer& inputBuffer, Size numSamples ) = 0;
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_INPUT_STREAM_H
