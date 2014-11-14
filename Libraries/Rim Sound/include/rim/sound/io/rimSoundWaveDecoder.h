/*
 *  rimSoundWaveDecoder.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 7/31/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_WAVE_DECODER_H
#define INCLUDE_RIM_SOUND_WAVE_DECODER_H


#include "rimSoundIOConfig.h"


//##########################################################################################
//***************************  Start Rim Sound IO Namespace  *******************************
RIM_SOUND_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles streaming decoding of the PCM .WAV audio format.
/**
  * This class uses an abstract data stream for input, allowing it to decode
  * .WAV data from a file, network source, or other source.
  */
class WaveDecoder : public SoundInputStream
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new wave decoder which should decode the .WAV file at the specified path string.
			WaveDecoder( const UTF8String& pathToWaveFile );
			
			
			
			
			/// Create a new wave decoder which should decode the specified .WAV file.
			WaveDecoder( const File& waveFile );
			
			
			
			
			/// Create a new wave decoder which is decoding from the specified data input stream.
			/**
			  * The stream must already be open for reading and should point to the first byte of the wave
			  * file information. Otherwise, reading from the WAVE file will fail.
			  */
			WaveDecoder( const Pointer<DataInputStream>& waveStream );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Release all resources associated with this WaveDecoder object.
			~WaveDecoder();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	WAVE File Length Accessor Methods
			
			
			
			
			/// Get the length in samples of the WAVE file which is being decoded.
			RIM_INLINE SoundSize getLengthInSamples() const
			{
				return lengthInSamples;
			}
			
			
			
			
			/// Get the length in seconds of the WAVE file which is being decoded.
			RIM_INLINE Double getLengthInSeconds() const
			{
				return lengthInSamples*sampleRate;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Current Time Accessor Methods
			
			
			
			
			/// Get the index of the sample currently being read from the WAVE file.
			RIM_INLINE SampleIndex getCurrentSampleIndex() const
			{
				return currentSampleIndex;
			}
			
			
			
			
			/// Get the time in seconds within the WAVE file of the current read position of this decoder.
			RIM_INLINE Double getCurrentTime() const
			{
				return Double(currentSampleIndex / sampleRate);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Seek Status Accessor Methods
			
			
			
			
			/// Return whether or not seeking is allowed in this input stream.
			virtual Bool canSeek() const;
			
			
			
			
			/// Return whether or not this input stream's current position can be moved by the specified signed sample offset.
			/**
			  * This sample offset is specified as the number of sample frames to move
			  * in the stream - a frame is equal to one sample for each channel in the stream.
			  */
			virtual Bool canSeek( Int64 relativeSampleOffset ) const;
			
			
			
			
			/// Move the current sample frame position in the stream by the specified signed amount.
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
		//******	Stream Size Accessor Method
			
			
			
			
			/// Return the number of samples remaining in the sound input stream.
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
		//******	Decoder Format Accessor Methods
			
			
			
			
			/// Return the number of channels that are in the sound input stream.
			/**
			  * This is the number of channels that will be read with each read call
			  * to the stream's read method.
			  */
			virtual Size getChannelCount() const;
			
			
			
			
			/// Return the sample rate of the sound input stream's source audio data.
			/**
			  * Since some types of streams support variable sampling rates, this value
			  * is not necessarily the sample rate of all audio that is read from the stream.
			  * However, for most streams, this value represents the sample rate of the entire
			  * stream. One should always test the sample rate of the buffers returned by the
			  * stream to see what their sample rates are before doing any operations that assume
			  * a sampling rate.
			  */
			virtual SampleRate getSampleRate() const;
			
			
			
			
			/// Return the actual sample type used in the stream.
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
		//******	Decoder Status Accessor Method
			
			
			
			
			/// Return whether or not this wave decoder is reading a valid WAVE file.
			Bool isValid() const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Copy Operations
			
			
			
			
			/// Create a copy of the specified wave decoder.
			WaveDecoder( const WaveDecoder& other );

			
			
			
			
			/// Assign the current state of another WaveDecoder object to this WaveDecoder object.
			WaveDecoder& operator = ( const WaveDecoder& other );			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Sound Reading Method
			
			
			
			
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
		//******	Private Helper Methods
			
			
			
			
			/// Read the header of the wave file, starting from the current position.
			/**
			  * This method should only be called when the data input stream is first initialized
			  * and points to the first byte of the wave header.
			  */
			void openWaveFile();
			
			
			
			
			/// Return the number of bytes per sample (stored on disk) for the compression scheme.
			Size getBytesPerSample() const;

			
			
			
			
			static Int16 decodeALaw( UInt8 aLaw );
			
			
			
			
			static Int16 decodeMuLaw( UInt8 muLaw );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the data input stream from which we are decoding .WAV data.
			Pointer<DataInputStream> stream;
			
			
			
			
			/// A mutex object which provides thread synchronization for this wave decoder.
			/**
			  * This thread protects access to decoding parameters such as the current decoding
			  * position so that they are never accessed while audio is being decoded.
			  */
			mutable threads::Mutex decodingMutex;
			
			
			
			
			/// The number of channels in the WAVE file.
			Size numChannels;
			
			
			
			
			/// The sample rate of the WAVE file.
			SampleRate sampleRate;
			
			
			
			
			/// The type of sample in which the WAVE file is encoded.
			/**
			  * For PCM types this value is equal to the actual type of the encoded samples.
			  * For A-law and Mu-law encodings, this value indicates the size of the encoded,
			  * not the decoded samples.
			  */
			SampleType sampleType;
			
			
			
			
			/// The WAVE file encoding format.
			Index format;
			
			
			
			
			/// The length in samples of the WAVE file.
			SoundSize lengthInSamples;
			
			
			
			
			/// The index within the WAVE file of the current sample being read.
			SampleIndex currentSampleIndex;
			
			
			
			
			/// A boolean flag indicating whether or not this wave decoder is decoding a valid wave file.
			Bool validFile;
			
			
			
};




//##########################################################################################
//***************************  End Rim Sound IO Namespace  *********************************
RIM_SOUND_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_WAVE_DECODER_H
