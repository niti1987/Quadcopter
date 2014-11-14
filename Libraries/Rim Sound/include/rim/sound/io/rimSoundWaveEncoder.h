/*
 *  rimSoundWaveEncoder.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 7/31/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_WAVE_ENCODER_H
#define INCLUDE_RIM_SOUND_WAVE_ENCODER_H


#include "rimSoundIOConfig.h"


//##########################################################################################
//***************************  Start Rim Sound IO Namespace  *******************************
RIM_SOUND_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles streaming encoding of the PCM .WAV audio format.
/**
  * This class uses an abstract data stream for output, allowing it to encode
  * .WAV data to a file, network destination, or other destination.
  */
class WaveEncoder : public SoundOutputStream
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a .wav file encoder with the given number of channels and sample type.
			/**
			  * An encoder created by this constructor will write a .wav file with the specified
			  * number of channels and sample type. The default sample type is a 16-bit signed
			  * integer sample type. The encoder automatically detects the sample rate of the
			  * first incoming buffer of audio and uses that sample rate for the entire wave file.
			  */
			WaveEncoder( const UTF8String& newFilePath, Size numChannels,
						SampleType newSampleType = SampleType::SAMPLE_16 );
			
			
			
			
			/// Create a .wav file encoder with the given number of channels, sample type, and sample rate.
			/**
			  * An encoder created by this constructor will write a .wav file with the specified
			  * number of channels and sample type. The default sample type is a 16-bit signed
			  * integer sample type. The encoder uses the specified sample rate
			  * for all incoming audio, automatically sample rate converting any audio that doesn't
			  * match the output sample rate.
			  */
			WaveEncoder( const UTF8String& newFilePath, Size numChannels,
						SampleType newSampleType, SampleRate newSampleRate );
			
			
			
			
			/// Create a .wav file encoder with the given number of channels and sample type.
			/**
			  * An encoder created by this constructor will write a .wav file with the specified
			  * number of channels and sample type. The default sample type is a 16-bit signed
			  * integer sample type. The encoder automatically detects the sample rate of the
			  * first incoming buffer of audio and uses that sample rate for the entire wave file.
			  */
			WaveEncoder( const File& newFile, Size numChannels, SampleType newSampleType = SampleType::SAMPLE_16 );
			
			
			
			
			/// Create a .wav file encoder with the given number of channels, sample type, and sample rate.
			/**
			  * An encoder created by this constructor will write a .wav file with the specified
			  * number of channels and sample type. The default sample type is a 16-bit signed
			  * integer sample type. The encoder automatically uses the specified sample rate
			  * for all incoming audio, automatically sample rate converting any audio that doesn't
			  * match the output sample rate.
			  */
			WaveEncoder( const File& newFile, Size numChannels, SampleType newSampleType, SampleRate newSampleRate );
			
			
			
			
			/// Create a .wav stream encoder with the given number of channels and sample type.
			/**
			  * An encoder created by this constructor will write a .wav file with the specified
			  * number of channels and sample type. The default sample type is a 16-bit signed
			  * integer sample type. The encoder automatically detects the sample rate of the
			  * first incoming buffer of audio and uses that sample rate for the entire wave file.
			  */
			WaveEncoder( const Pointer<DataOutputStream>& outputStream, Size numChannels,
						SampleType newSampleType = SampleType::SAMPLE_16 );
			
			
			
			
			/// Create a .wav stream encoder with the given number of channels, sample type, and sample rate.
			/**
			  * An encoder created by this constructor will write a .wav file stream with the specified
			  * number of channels and sample type. The default sample type is a 16-bit signed
			  * integer sample type. The encoder automatically uses the specified sample rate
			  * for all incoming audio, automatically sample rate converting any audio that doesn't
			  * match the output sample rate.
			  */
			WaveEncoder( const Pointer<DataOutputStream>& outputStream, Size numChannels,
						SampleType newSampleType, SampleRate newSampleRate );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this wave encoder and release all associated resources.
			virtual ~WaveEncoder();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Flush Accessor Methods
			
			
			
			
			/// Flush all pending sound data to be encoded to the encoder's data output stream.
			virtual void flush();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Seeking Methods
			
			
			
			
			/// Return whether or not seeking is allowed by this wave file encoder.
			virtual Bool canSeek() const;
			
			
			
			
			/// Return if this wave encoder's current position can be moved by the specified signed sample offset.
			/**
			  * This sample offset is specified as the number of sample frames to move
			  * in the stream - a frame is equal to one sample for each channel in the stream.
			  */
			virtual Bool canSeek( Int64 relativeSampleOffset ) const;
			
			
			
			
			/// Move the current sample frame position of the encoder by the specified signed amount.
			/**
			  * This method attempts to seek the position of the encoder by the specified amount.
			  * The method returns the signed amount that the position in the stream was changed
			  * by. Thus, if seeking is not allowed, 0 is returned. Otherwise, the stream should
			  * seek as far as possible in the specified direction and return the actual change
			  * in position.
			  */
			virtual Int64 seek( Int64 relativeSampleOffset );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	WAVE File Length Accessor Methods
			
			
			
			
			/// Return the total number of samples that have been encoded by this wave encoder.
			RIM_INLINE SoundSize getLengthInSamples() const
			{
				return lengthInSamples;
			}
			
			
			
			
			/// Return the total length of sound in seconds that has been encoded by this wave encoder.
			RIM_INLINE Double getLengthInSeconds() const
			{
				return lengthInSamples / sampleRate;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Output Format Accessor Methods
			
			
			
			
			/// Return the number of channels that are being written by the wave encoder.
			/**
			  * This is the number of channels that should be provided to the write() method.
			  * If less than this number of channels is provided, silence is written for the
			  * other channels. Superfluous channels are ignored.
			  *
			  * This value is set in a constructor of the encoder and once set, is read-only.
			  */
			virtual Size getChannelCount() const;
			
			
			
			
			/// Return the sample rate at which this wave encoder is encoding.
			/**
			  * This is the sample rate to which all incoming sound data is converted to
			  * before being written to the output stream. The output sample rate can be
			  * set in the encoder's constructor. After contruction, the sample rate is
			  * read-only and cannot be changed. If not set during construction, the encoder
			  * can automatically auto-detect the sample rate of the first buffer of output audio
			  * and use that sample rate thenceforth. In that case, this method will return
			  * a sample rate of 0 until the incoming sample rate is detected.
			  */
			virtual SampleRate getSampleRate() const;
			
			
			
			
			/// Return the type of sample data that is being written by this wave encoder.
			/**
			  * This sample type is set when the encoder is first created but is read-only
			  * after construction. The default sample type is 16-bit signed integer samples.
			  */
			virtual SampleType getNativeSampleType() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Encoder Status Accessor Method
			
			
			
			
			/// Return whether or not this wave encoder is writing a valid WAVE file.
			virtual Bool isValid() const
			{
				return valid;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Copy Operations
			
			
			
			
			/// Create a copy of the specified wave encoder.
			WaveEncoder( const WaveEncoder& other );

			
			
			
			
			/// Assign the current state of another WaveEncoder object to this WaveEncoder object.
			WaveEncoder& operator = ( const WaveEncoder& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Sound Writing Method
			
			
			
			
			/// Write the specified number of samples from the output buffer to the data output stream.
			/**
			  * This method attempts to encode the specified number of samples to the stream
			  * from the output buffer. It then returns the total number of valid samples which
			  * were written to the wave file. The current write position in the stream
			  * is advanced by the number of samples that are written.
			  */
			virtual Size writeSamples( const SoundBuffer& outputBuffer, Size numSamples );
			
			
			
			
			/// Write the header of the wave file, starting at the current position in the data output stream.
			void writeHeader();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Return whether or not the specified sample type is supported by this wave encoder.
			RIM_INLINE static Bool sampleTypeIsValid( SampleType type )
			{
				return type == SampleType::SAMPLE_8 || type == SampleType::SAMPLE_16 ||
						type == SampleType::SAMPLE_24 || type == SampleType::SAMPLE_32 || 
						type == SampleType::SAMPLE_64 || type == SampleType::SAMPLE_32F ||
						type == SampleType::SAMPLE_64F;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the data output stream to which we are encoding .WAV data.
			Pointer<DataOutputStream> stream;
			
			
			
			
			/// A mutex object which provides thread synchronization for this wave encoder.
			/**
			  * This thread protects access to encoding parameters such as the current encoding
			  * position so that they are never accessed while audio is being encoded.
			  */
			mutable threads::Mutex encodingMutex;
			
			
			
			
			/// An object which handles conversion to the output sample rate if the input is mismatched.
			SampleRateConverter sampleRateConverter;
			
			
			
			
			/// The number of channels that are being written by the wave encoder.
			Size numChannels;
			
			
			
			
			/// The sample rate of the wave file which is being encoded.
			SampleRate sampleRate;
			
			
			
			
			/// The output sample type for the wave file.
			/**
			  * This is the representation of the encoded samples, usually
			  * 8-bit, 16-bit, or 24-bit signed integers.
			  */
			SampleType sampleType;
			
			
			
			
			/// The total length of the encoded wave file in samples.
			SoundSize lengthInSamples;
			
			
			
			
			/// The current position within the wave file where the encoder is encoding.
			SampleIndex currentSampleIndex;
			
			
			
			
			/// A boolean value indicating whether or not the encoder is currently writing a valid wave file.
			Bool valid;
			
			
			
			
			/// A boolean value indicating whether or not the encoder has written the wave file's header.
			Bool writtenHeader;
			
			
			
};




//##########################################################################################
//***************************  End Rim Sound IO Namespace  *********************************
RIM_SOUND_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_WAVE_ENCODER_H
