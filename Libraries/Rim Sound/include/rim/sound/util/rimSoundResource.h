/*
 *  rimSoundResource.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_RESOURCE_H
#define INCLUDE_RIM_SOUND_RESOURCE_H


#include "rimSoundUtilitiesConfig.h"


#include "rimSoundInputStream.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents either a streaming or memory-resident sound resource.
/**
  * This class allows the user to reference a read-only source of sound data without
  * knowing its storage type. The source could be a memory-resident SoundBuffer which contains
  * the referenced sound data or the source could be a streaming source of data (i.e.
  * from a file). Thus, this allows both streaming and non-streaming sounds to be treated
  * the same.
  */
class SoundResource : public SoundInputStream
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new sound resource for the specified memory-resident sound buffer.
			/**
			  * This constructor copies the contents of the specified buffer into a new
			  * internal buffer.
			  */
			SoundResource( const SoundBuffer& buffer );
			
			
			
			
			/// Create a new sound resource for the specified memory-resident sound buffer.
			/**
			  * This constructor copies the specified number of samples from the specified
			  * buffer into a new internal buffer.
			  */
			SoundResource( const SoundBuffer& buffer, Size numSamples );
			
			
			
			
			/// Create a new sound resource for the specified sound input stream.
			/**
			  * This constructor allows the user to optionally specify if the data pointed
			  * to by the stream should be read entirely into memory, rather than being
			  * streamed in real time. The default is to use pure streaming.
			  */
			SoundResource( const Pointer<SoundInputStream>& stream, Bool memoryResident = false );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Stream Accessor Methods
			
			
			
			
			/// Return whether or not this resource has a streaming source of sound data.
			RIM_INLINE Bool hasStream() const
			{
				return !stream.isNull();
			}
			
			
			
			
			/// Return a pointer to this sound resource's streaming source of sound data.
			RIM_INLINE const Pointer<SoundInputStream>& getStream() const
			{
				return stream;
			}
			
			
			
			
			/// Return whether or not this resource has a memory-resident buffer of sound data.
			RIM_INLINE Bool hasBuffer() const
			{
				return !buffer.isNull();
			}
			
			
			
			
			/// Return a pointer to this sound resource's internal memory-resident buffer of sound data.
			RIM_INLINE const Pointer<SoundBuffer>& getBuffer() const
			{
				return buffer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resource Loading Methods
			
			
			
			
			/// Load this resource from its stream into a buffer, if possible.
			/**
			  * The method returns whether or not the resource was able to be loaded.
			  */
			Bool load();
			
			
			
			
			/// Destroy the buffer for this resource, and revert to using the stream.
			/**
			  * The method returns whether or not the resource was able to be unloaded.
			  * The method fails if there is no stream for the resource.
			  */
			Bool unload();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Seek Status Accessor Methods
			
			
			
			
			/// Return whether or not seeking is allowed in this sound resource input stream.
			virtual Bool canSeek() const;
			
			
			
			
			/// Return whether or not this resource stream's current position can be moved by the specified signed sample offset.
			/**
			  * This sample offset is specified as the number of sample frames to move
			  * in the stream - a frame is equal to one sample for each channel in the stream.
			  */
			virtual Bool canSeek( Int64 relativeSampleOffset ) const;
			
			
			
			
			/// Move the current sample frame position in the resource stream by the specified signed amount.
			/**
			  * This method attempts to seek the position in the stream by the specified amount.
			  * The method returns the signed amount that the position in the stream was changed
			  * by. Thus, if seeking is not allowed, 0 is returned. Otherwise, the stream should
			  * seek as far as possible in the specified direction and return the actual change
			  * in position.
			  */
			virtual Int64 seek( Int64 relativeSampleOffset );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Size Accessor Methods
			
			
			
			
			/// Return the number of samples remaining in the sound resource input stream.
			/**
			  * The value returned must only be a lower bound on the total number of sample
			  * frames in the stream. For instance, if there are samples remaining, the method
			  * should return at least 1. If there are no samples remaining, the method should
			  * return 0.
			  */
			virtual SoundSize getSamplesRemaining() const;
			
			
			
			
			/// Return the current position of the stream within itself.
			/**
			  * The returned value indicates the sample index of the current read
			  * position within the sound stream. For unbounded streams, this indicates
			  * the number of samples that have been read by the stream since it was opened.
			  */
			virtual SampleIndex getPosition() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Format Accessor Methods
			
			
			
			
			/// Return the number of channels that are in the sound resource input stream.
			/**
			  * This is the number of channels that will be read with each read call
			  * to the stream's read method.
			  */
			virtual Size getChannelCount() const;
			
			
			
			
			/// Return the sample rate of the sound resource input stream's source audio data.
			/**
			  * Since some types of streams support variable sampling rates, this value
			  * is not necessarily the sample rate of all audio that is read from the stream.
			  * However, for most streams, this value represents the sample rate of the entire
			  * stream. One should always test the sample rate of the buffers returned by the
			  * stream to see what their sample rates are before doing any operations that assume
			  * a sampling rate.
			  */
			virtual SampleRate getSampleRate() const;
			
			
			
			
			/// Return the actual sample type used in the resource stream.
			/**
			  * This is the format of the stream's source data. For instance, a file
			  * might be encoded with 8-bit, 16-bit or 24-bit samples. This value
			  * indicates that sample type. For formats that don't have a native sample type,
			  * such as those which use frequency domain encoding, this function should
			  * return SampleType::SAMPLE_32F, indicating that the stream's native format
			  * is 32-bit floating point samples.
			  */
			virtual SampleType getNativeSampleType() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Status Accessor Method
			
			
			
			
			/// Return whether or not the resource has a valid source of sound data.
			/**
			  * This method should return TRUE if everything is OK, but might return
			  * FALSE if the input stream is not valid (file not found, etc) or
			  * if the stream's data has improper format.
			  */
			virtual Bool isValid() const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Sound Input Method
			
			
			
			
			/// Read the specified number of samples from the input stream into the output buffer.
			/**
			  * This method attempts to read the specified number of samples from the stream
			  * into the input buffer. It then returns the total number of valid samples which
			  * were read into the output buffer. The samples are converted to the format
			  * stored in the input buffer (Sample32f). The input position in the stream
			  * is advanced by the number of samples that are read.
			  */
			virtual Size readSamples( SoundBuffer& inputBuffer, Size numSamples );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to a buffer which this resource is wrapping.
			Pointer<SoundBuffer> buffer;
			
			
			
			
			/// A pointer to a stream which this resource is wrapping.
			Pointer<SoundInputStream> stream;
			
			
			
			
			/// The current sample read index within the sound buffer which this resource is wrapping.
			Index currentPosition;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_RESOURCE_H
