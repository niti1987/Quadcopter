/*
 *  rimSoundBuffer.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_BUFFER_H
#define INCLUDE_RIM_SOUND_BUFFER_H


#include "rimSoundUtilitiesConfig.h"


#include "rimSoundSample.h"
#include "rimSoundSIMDSample.h"
#include "rimSoundSampleRate.h"
#include "rimSoundChannelLayout.h"
#include "rimSoundChannelLayoutType.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class representing a buffer of multichannel audio data.
/**
  * A SoundBuffer class contains zero or more non-interleaved channels of audio data.
  * All channels are the same length. The class will not allocate any memory for audio
  * data unless the number of channels and length of the buffer are non-zero, saving
  * unnecessary allocations. The class also uses a fixed-size internal array of channel
  * pointers, avoiding channel array allocations for small numbers of channels.
  *
  * The sampling rate of the audio contained in a SoundBuffer is stored in each instance
  * of the class. This sampling rate may be changed without affecting the samples stored
  * in the buffer, resulting in a pitch shifting effect when interpreted at the new sample
  * rate.
  *
  * The starting samples for each channel in a buffer are guaranteed to be 16-byte aligned
  * which allows efficient SIMD processing of channel data.
  */
class SoundBuffer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a SoundBuffer object with zero channels of zero samples each.
			/**
			  * No memory is allocated until the number of channels is set to a non-zero value
			  * using the setChannelCount() method.
			  *
			  * The default sampling rate of 44.1 kHz is used.
			  *
			  * The channel layout for this buffer is by default ChannelLayout::UNDEFINED.
			  */
			RIM_INLINE SoundBuffer()
				:	channels( channelArray ),
					numChannels( 0 ),
					numSamples( 0 ),
					channelCapacity( FIXED_CHANNEL_ARRAY_SIZE ),
					sampleCapacity( 0 ),
					sampleRate( 44100 ),
					layoutType( ChannelLayout::UNDEFINED ),
					layout( NULL )
			{
				// Set all channel pointer to NULL.
				for ( Index i = 0; i < FIXED_CHANNEL_ARRAY_SIZE; i++ )
					channels[i] = NULL;
			}
			
			
			
			
			/// Create a SoundBuffer object with the specified number of channels.
			/**
			  * The buffer is initially of length 0, meaning that no channel data will be
			  * allocated until the size of the buffer is set to a value greater than 0.
			  *
			  * The default sampling rate of 44.1 kHz is used. The channel layout for this buffer
			  * is by default ChannelLayout::UNDEFINED.
			  *
			  * @param newNumChannels - the number of channels that this sound buffers should have.
			  */
			SoundBuffer( Size newNumChannels );
			
			
			
			
			/// Create a SoundBuffer object with the specified number of channels and buffer size.
			/**
			  * This constructor allows the user to specify the desired sample rate of the sound
			  * contained in the buffer, with a default value of 44.1 kHz.
			  *
			  * The channel layout for this buffer is by default ChannelLayout::UNDEFINED.
			  * 
			  * @param newNumChannels - the number of channels that this sound buffers should have.
			  * @param newNumSamples - the length in samples that this buffer should have.
			  * @param newSampleRate - the sample rate to use for the audio contained in this buffer.
			  */
			SoundBuffer( Size newNumChannels, Size newNumSamples, SampleRate newSampleRate = 44100 );
			
			
			
			
			/// Create a SoundBuffer object which uses the specified predefined channel layout type.
			/**
			  * The channel layout type determines the total number of channels in the buffer,
			  * as well as their types. The buffer is initially of length 0, meaning
			  * that no channel data will be allocated until the size of the buffer is set
			  * to a value greater than 0.
			  *
			  * The default sampling rate of 44.1 kHz is used.
			  */
			SoundBuffer( ChannelLayoutType newLayoutType );
			
			
			
			
			/// Create a SoundBuffer object which uses the specified channel layout type, size, and sample rate.
			/**
			  * The channel layout type determines the total number of channels in the buffer,
			  * as well as their types.
			  *
			  * The default sampling rate of 44.1 kHz is used.
			  */
			SoundBuffer( ChannelLayoutType newLayoutType, Size newNumSamples, SampleRate newSampleRate = 44100 );
			
			
			
			
			/// Create a SoundBuffer object which uses the specified channel layout.
			/**
			  * The channel layout determines the total number of channels in the buffer,
			  * as well as their types. The buffer is initially of length 0, meaning
			  * that no channel data will be allocated until the size of the buffer is set
			  * to a value greater than 0.
			  *
			  * The default sampling rate of 44.1 kHz is used.
			  */
			SoundBuffer( const ChannelLayout& newLayout );
			
			
			
			
			/// Create a SoundBuffer object which uses the specified channel layout, size, and sample rate.
			/**
			  * The channel layout determines the total number of channels in the buffer,
			  * as well as their types.
			  *
			  * The default sampling rate of 44.1 kHz is used.
			  */
			SoundBuffer( const ChannelLayout& newLayout, Size newNumSamples, SampleRate newSampleRate = 44100 );
			
			
			
			
			/// Create an exact copy of the specified SoundBuffer.
			/**
			  * @param other - the SoundBuffer object whose state is to be copied.
			  */
			SoundBuffer( const SoundBuffer& other );
			
			
			
			
			/// Create a copy of the specified SoundBuffer, using at most the specified number of samples.
			/**
			  * @param other - the SoundBuffer object whose state is to be copied.
			  * @param numSamples - the number of samples to copy from the specified sound buffer.
			  */
			SoundBuffer( const SoundBuffer& other, Size numSamples );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a SoundBuffer object.
			/**
			  * All internally allocated data is released.
			  */
			~SoundBuffer();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Copy the contents of one SoundBuffer object into this SoundBuffer object.
			/**
			  * All previously existing internal state is released and new state
			  * allocated to exactly replicate the specified SoundBuffer object.
			  *
			  * @param other - the SoundBuffer object whose state should replace this SoundBuffer's.
			  * @return a reference to this SoundBuffer object, allowing assignment chaining.
			  */
			SoundBuffer& operator = ( const SoundBuffer& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Layout Type Accessor Methods
			
			
			
			
			/// Return a semantic type for this buffer's channel layout.
			/**
			  * This value can be used to figure out how to interpret the buffer's
			  * channel layout.
			  */
			RIM_INLINE ChannelLayoutType getLayoutType() const
			{
				return layoutType;
			}
			
			
			
			
			/// Set the semantic type for this buffer's channel layout.
			/**
			  * This value can be used to figure out how to interpret the buffer's
			  * channel layout. This method does not modify the contents or layout
			  * of the buffer, only the semantic type tag is changed.
			  */
			RIM_INLINE void setLayoutType( ChannelLayoutType newLayoutType )
			{
				layoutType = newLayoutType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Layout Accessor Methods
			
			
			
			
			/// Return a reference to an object describing this buffer's channel layout.
			RIM_INLINE const ChannelLayout& getLayout() const
			{
				if ( layout == NULL )
					layout = newSharedLayout( numChannels );
				
				return layout->layout;
			}
			
			
			
			
			/// Replace the current channel layout of this sound buffer with the specified one.
			/**
			  * This method may resize the number of channels in the buffer so that it
			  * is at least the number of channels in the specified layout.
			  */
			void setLayout( const ChannelLayout& newLayout );
			
			
			
			
			/// Replace the current channel layout of this sound buffer with a predefined layout of the given type.
			/**
			  * This method may resize the number of channels in the buffer so that it
			  * is at least the number of channels in the specified layout.
			  */
			void setLayout( ChannelLayoutType newLayoutType );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Count Accessor Methods
			
			
			
			
			/// Get the number of channels that this SoundBuffer object has.
			/**
			  * @return the number of channels that this sound buffer has.
			  */
			RIM_INLINE Size getChannelCount() const
			{
				return numChannels;
			}
			
			
			
			
			/// Set the number of channels that this SoundBuffer object has.
			/**
			  * Changing the number of channels entails reallocating the internal
			  * array of channels and is a potentially expensive operation.
			  * 
			  * @param newNumberOfChannels - the new number of channels that this SoundBuffer object should have.
			  */
			void setChannelCount( Size newNumChannels );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Type Accessor Methods
			
			
			
			
			/// Return an object representing the semantic type of the channel at the specified index.
			/**
			  * If the given channel index is invalid, the ChannelType::UNDEFINED type is
			  * returned.
			  */
			RIM_INLINE ChannelType getChannelType( Index channelIndex ) const
			{
				if ( layout == NULL || channelIndex >= numChannels )
					return ChannelType::UNDEFINED;
				else
					return layout->layout.getChannelType( channelIndex );
			}
			
			
			
			
			/// Set the semantic type of the channel at the specified index.
			/**
			  * If the given channel index is invalid, the method has no effect.
			  */
			RIM_INLINE void setChannelType( Index channelIndex, ChannelType newType )
			{
				if ( channelIndex < numChannels )
				{
					if ( layout == NULL )
						layout = newSharedLayout( numChannels );
					
					layout->layout.setChannelType( channelIndex, newType );
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Position Accessor Methods
			
			
			
			
			/// Return a reference to the channel position at the specified index.
			/**
			  * If the channel index is invalid or if the speaker is not positional,
			  * the vector (0,0,0) is returned.
			  */
			RIM_INLINE const Vector3f& getChannelPosition( Index channelIndex ) const
			{
				if ( layout == NULL || channelIndex >= numChannels )
					return Vector3f::ZERO;
				else
					return layout->layout.getChannelPosition( channelIndex );
			}
			
			
			
			
			/// Set the position of the channel's speaker at the specified index.
			RIM_INLINE void setChannelPosition( Index channelIndex, const Vector2f& newPosition )
			{
				if ( channelIndex < numChannels )
				{
					if ( layout == NULL )
						layout = newSharedLayout( numChannels );
					
					layout->layout.setChannelPosition( channelIndex, newPosition );
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return the number of samples that this SoundBuffer object is holding.
			/**
			  * @return the number of samples that this SoundBuffer object is holding.
			  */
			RIM_INLINE Size getSize() const
			{
				return numSamples;
			}
			
			
			
			
			/// Set the number of samples that this SoundBuffer object is holding.
			/**
			  * This method reallocates the internal channel buffers if necessary
			  * to hold the specified number of samples. If the specified size is less
			  * than the current size, no memory may be reallocated if not necessary.
			  * The existing samples in the old buffer are coppied over to the new buffer
			  * if one is allocated. The remaining new samples are uninitialized and have
			  * undefined contents.
			  *
			  * @param newSize - the new number of samples that this SoundBuffer should hold.
			  */
			void setSize( Size newSize );
			
			
			
			
			/// Return the number of bytes of memory allocate by this sound buffer.
			RIM_INLINE Size getSizeInBytes() const
			{
				return sizeof(SoundBuffer) + channelCapacity*sizeof(Sample32f*) + numChannels*sampleCapacity*sizeof(Sample32f);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Rate Accessor Methods
			
			
			
			
			/// Return the sampling rate of this sound buffer in samples per second.
			RIM_INLINE SampleRate getSampleRate() const
			{
				return sampleRate;
			}
			
			
			
			
			/// Set the sampling rate of this sound buffer in samples per second.
			/**
			  * This method does not alter the channel count, the number of samples, or any of the
			  * samples in the buffer. It simply sets the sampling rate at which the buffer's
			  * samples should be interpreted.
			  */
			RIM_INLINE void setSampleRate( SampleRate newSampleRate )
			{
				sampleRate = newSampleRate;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Start/End Accessor Methods
			
			
			
			
			/// Get a pointer to the first sample within the channel with the specified index.
			/**
			  * If the specified channel index is not within the valid bounds of channel
			  * indices, an assertion is raised.
			  * 
			  * @param channelIndex - the channel whose start pointer should be accessed.
			  * @return a pointer to the first sample of the specified channel within this SoundBuffer.
			  */
			RIM_INLINE Sample32f* getChannelStart( Index channelIndex )
			{
				RIM_DEBUG_ASSERT_MESSAGE( channelIndex < numChannels, "Cannot access channel at invalid index in sound buffer." );
				
				return channels[channelIndex];
			}
			
			
			
			
			/// Get a pointer to the first sample within the channel with the specified index.
			/**
			  * If the specified channel index is not within the valid bounds of channel
			  * indices, an assertion is raised.
			  * 
			  * @param channelIndex - the channel whose start pointer should be accessed.
			  * @return a pointer to the first sample of the specified channel within this SoundBuffer.
			  */
			RIM_INLINE const Sample32f* getChannelStart( Index channelIndex ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( channelIndex < numChannels, "Cannot access channel at invalid index in sound buffer." );
				
				return channels[channelIndex];
			}
			
			
			
			
			/// Get a pointer to just past the last sample within the channel with the specified index.
			/**
			  * If the specified channel index is not within the valid bounds of channel
			  * indices, an assertion is raised.
			  * 
			  * @param channelIndex - the channel whose end pointer should be accessed.
			  * @return a pointer to the first sample after the end of the specified channel.
			  */
			RIM_INLINE Sample32f* getChannelEnd( Index channelIndex )
			{
				RIM_DEBUG_ASSERT_MESSAGE( channelIndex < numChannels, "Cannot access channel at invalid index in sound buffer." );
				
				return channels[channelIndex] + numSamples;
			}
			
			
			
			
			/// Get a pointer to just past the last sample within the channel with the specified index.
			/**
			  * If the specified channel index is not within the valid bounds of channel
			  * indices, an assertion is raised.
			  * 
			  * @param channelIndex - the channel whose end pointer should be accessed.
			  * @return a pointer to the first sample after the end of the specified channel.
			  */
			RIM_INLINE const Sample32f* getChannelEnd( Index channelIndex ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( channelIndex < numChannels, "Cannot access channel at invalid index in sound buffer." );
				
				return channels[channelIndex] + numSamples;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Zero Methods
			
			
			
			
			/// Zero-out the entire contents of this SoundBuffer.
			RIM_INLINE void zero()
			{
				this->zero( 0, numSamples );
			}
			
			
			
			
			/// Zero-out a range of the contents of this SoundBuffer.
			/**
			  * This method writes zero to every sample of every channel in this SoundBuffer
			  * starting at the specified sample start index and ending numSamples past
			  * that index.
			  * 
			  * @param startIndex - the first sample to be zero-d out in the SoundBuffer object.
			  * @param numSamplesToZero - the number of samples to be zero-d out after the start index.
			  */
			void zero( Index startIndex, Size numSamplesToZero );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Copy Methods
			
			
			
			
			/// Copy the specified number of samples from each channel of this buffer to the output buffer.
			/**
			  * The method interleaves the channel samples in the output buffer. The output
			  * buffer must be at least as large as the number of requested samples multiplied
			  * by the number of channels in this SoundBuffer.
			  * 
			  * If the supplied buffer pointer is NULL, the method return immediately and has no effect.
			  * If the number of samples in this SoundBuffer is less than the specified
			  * number of requested samples, the number of requested samples is clamped to the
			  * size of the SoundBuffer.
			  *
			  * The method returns the total number of samples copied to the output buffer per channel.
			  */
			Size copyToInterleavedBuffer( Sample32f* output, Size numSamplesToCopy ) const;
			
			
			
			
			/// Copy the contents of this buffer to the other specified sound buffer.
			/**
			  * The method returns the total number of samples per channel actually copied
			  * from this buffer.
			  */
			RIM_INLINE Size copyTo( SoundBuffer& other ) const
			{
				return this->copyTo( other, numSamples );
			}
			
			
			
			
			/// Copy the specified number of samples from this buffer to the other specified sound buffer.
			/**
			  * The other buffer is enlarged to hold the contents of this buffer if necessary
			  * and as many samples as possible, up to the specified number of samples, are copied
			  * to the other buffer. The method returns the total number of samples per channel
			  * actually copied from this buffer.
			  */
			Size copyTo( SoundBuffer& other, Size numSamplesToCopy ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Mix Methods
			
			
			
			
			/// Mix the contents of this buffer with the other specified sound buffer.
			/**
			  * This method overwrites the contents of the other buffer with the mixed output.
			  * The method returns the total number of samples per channel actually mixed
			  * from this buffer.
			  *
			  * If the other buffer is smaller than the number of samples from this buffer,
			  * only that many samples are mixed (truncating the other samples).
			  */
			RIM_INLINE Size mixTo( SoundBuffer& other ) const
			{
				return this->mixTo( other, numSamples );
			}
			
			
			
			
			/// Mix the specified number of samples from this buffer with the other specified sound buffer.
			/**
			  * This method overwrites the contents of the other buffer with the mixed output.
			  * The method returns the total number of samples per channel actually mixed
			  * from this buffer.
			  *
			  * If the other buffer is smaller than the number of samples from this buffer,
			  * only that many samples are mixed (truncating the other samples). If there
			  * is a mismatch in the number of buffer channels, as many channels as possible
			  * are mixed with the output buffer.
			  */
			Size mixTo( SoundBuffer& other, Size numSamples ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Gain Methods
			
			
			
			
			/// Apply the specified linear gain factor to all samples in this buffer, modifying it.
			/**
			  * This method has the effect of multiplying all samples in the buffer by
			  * the specified gain factor.
			  */
			RIM_INLINE void applyGain( Gain linearGain )
			{
				this->applyGain( linearGain, numSamples );
			}
			
			
			
			
			/// Apply the specified linear gain factor to the specified number of samples in this buffer, modifying it.
			/**
			  * This method has the effect of multiplying the specified number of samples in the buffer by
			  * the specified gain factor.
			  */
			void applyGain( Gain linearGain, Size numSamples );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Polarity Methods
			
			
			
			
			/// Invert the polarity for the all of the samples in the buffer.
			RIM_INLINE void invertPolarity()
			{
				this->invertPolarity( numSamples );
			}
			
			
			
			
			/// Invert the polarity for the specified number of samples in the buffer.
			void invertPolarity( Size numSamples );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Format Accessor Methods
			
			
			
			
			/// Copy the format of this buffer to the other specified buffer.
			/**
			  * This method ensures that the specified buffer has the same sample rate,
			  * channel layout, number of channels, and size as this buffer.
			  */
			RIM_INLINE void copyFormatTo( SoundBuffer& other ) const
			{
				this->copyFormatTo( other, numSamples );
			}
			
			
			
			
			/// Copy the format of this buffer to the other specified buffer.
			/**
			  * This method ensures that the specified buffer has the same sample rate,
			  * channel layout, and number of channels as this buffer. In addition, the
			  * specified buffer is enlarged to be at least as large as the specified
			  * minimum number of samples.
			  */
			void copyFormatTo( SoundBuffer& other, Size minimumNumberOfSamples ) const;
			
			
			
			
			
			/// Set the format of this buffer, so that it has the specified number of channels and samples.
			void setFormat( Size newNumChannels, Size newNumSamples );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which adds a reference count to a ChannelLayout object to allow sharing among SoundBuffer objects.
			class SharedChannelLayout
			{
				public:
					
					/// Create a new shared channel layout with no channels.
					RIM_INLINE SharedChannelLayout()
						:	layout(),
							referenceCount( 1 )
					{
					}
					
					
					/// Create a new shared channel layout with the specified number of channels.
					RIM_INLINE SharedChannelLayout( Size newNumChannels )
						:	layout( newNumChannels ),
							referenceCount( 1 )
					{
					}
					
					
					/// Create a new shared channel layout with the specified predefined layout type.
					RIM_INLINE SharedChannelLayout( ChannelLayoutType newType )
						:	layout( newType ),
							referenceCount( 1 )
					{
					}
					
					
					/// Create a new shared channel layout with a copy the specified layout.
					RIM_INLINE SharedChannelLayout( const ChannelLayout& newLayout )
						:	layout( newLayout ),
							referenceCount( 1 )
					{
					}
					
					
					/// A channel layout object which is being shared among buffers.
					ChannelLayout layout;
					
					
					/// The total number of SoundBuffer objects that have a reference to this shared channel layout.
					Size referenceCount;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Methods
			
			
			
			
			/// Initialize the specified number of channels of the SoundBuffer to have the given size.
			RIM_FORCE_INLINE void initializeChannels( Size newNumChannels, Size newNumSamples );
			
			
			
			
			/// Initialize this buffer with the specified channel layout and given size.
			RIM_FORCE_INLINE void initializeChannels( const ChannelLayout& channelLayout, Size newNumSamples );
			
			
			
			
			/// Initialize this buffer using the contents of the specified buffer and number of samples.
			RIM_FORCE_INLINE void initializeCopyBuffer( const SoundBuffer& buffer, Size newNumSamples );
			
			
			
			
			/// Release the data allocated to all channels in this SoundBuffer object.
			void releaseChannels();
			
			
			
			
			/// Acquire a reference to the specified shared channel layout for this buffer.
			RIM_INLINE void acquireLayout( SharedChannelLayout* sharedLayout )
			{
				layout = sharedLayout;
				
				if ( layout != NULL )
					layout->referenceCount++;
			}
			
			
			
			
			/// Release this buffer's handle to its channel layout.
			RIM_INLINE void releaseLayout();
			
			
			
			
			/// Copy this buffer's layout if it is shared with any other buffers.
			RIM_INLINE void makeLayoutUnique()
			{
				if ( layout != NULL && layout->referenceCount > 1 )
					layout = rim::util::construct<SharedChannelLayout>( layout->layout );
			}
			
			
			
			
			/// Create a new shared channel layout for the specified number of channels.
			static SharedChannelLayout* newSharedLayout( Size numChannels );
			
			
			
			
			/// Return a pointer to a predefined shared channel layout corresponding to the given layout type.
			RIM_FORCE_INLINE static SharedChannelLayout* getPredefinedLayout( ChannelLayoutType type );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The number of channels that are held as part of the buffer's fixed-size channel array.
			static const Size FIXED_CHANNEL_ARRAY_SIZE = 2;
			
			
			
			
			/// A predefined shared channel layout for the ChannelLayout::MONO layout type.
			static SharedChannelLayout* monoLayout;
			
			
			
			
			/// A predefined shared channel layout for the ChannelLayout::STEREO layout type.
			static SharedChannelLayout* stereoLayout;
			
			
			
			
			/// A predefined shared channel layout for the ChannelLayout::QUAD layout type.
			static SharedChannelLayout* quadLayout;
			
			
			
			
			/// A predefined shared channel layout for the ChannelLayout::SURROUND_5_1 layout type.
			static SharedChannelLayout* surround5_1Layout;
			
			
			
			
			/// A predefined shared channel layout for the ChannelLayout::SURROUND_7_1 layout type.
			static SharedChannelLayout* surround7_1Layout;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the samples for each channel of this buffer.
			Sample32f** channels;
			
			
			
			
			/// The number of channels in this SoundBuffer.
			Size numChannels;
			
			
			
			
			/// The number of valid samples in each channel of this SoundBuffer.
			Size numSamples;
			
			
			
			
			/// The total allocated capacity for this SoundBuffer's array of channels.
			Size channelCapacity;
			
			
			
			
			/// The total allocated number of samples for each channel of this SoundBuffer.
			Size sampleCapacity;
			
			
			
			
			/// The sampling rate of the audio contained in this SoundBuffer.
			SampleRate sampleRate;
			
			
			
			
			/// An object which specifies the semantic type of this buffer's channel layout.
			ChannelLayoutType layoutType;
			
			
			
			
			/// An object describing the channel layout of this SoundBuffer.
			/**
			  * This points to a reference-counted channel layout which allows the
			  * same layout to be shared between multiple buffers. This was done
			  * because the ChannelLayout object is non-trivial to copy and because
			  * that is a common operation in audio processing and so must be avoided.
			  *
			  * This layout uses copy-on-write semantics to determine if a new layout should
			  * be created.
			  */
			mutable SharedChannelLayout* layout;
			
			
			
			
			/// A fixed-size array of a small number of channels for this buffer.
			/**
			  * Until the capacity of this channel array is exceeded, the sound buffer
			  * uses this array to store the channel sample pointers, avoiding an allocation.
			  */
			Sample32f* channelArray[FIXED_CHANNEL_ARRAY_SIZE];
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_BUFFER_H
