/*
 *  rimSoundSampler.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_SAMPLER_H
#define INCLUDE_RIM_SOUND_SAMPLER_H


#include "rimSoundFiltersConfig.h"


#include "rimSoundFilter.h"
#include "rimSoundSampleRateConverter.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that allows the user to trigger multiple sound stream to be played.
/**
  * These triggered streams are then played back using the provided parameters
  * and mixed together at the output of the sampler. The streams are automatically
  * mapped to the output channel layout and sample rate converted to the output
  * sample rate if necessary.
  */
class Sampler : public SoundFilter, public SoundInputStream
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new sampler which has no streams currently playing and the default maximum number of streams.
			/**
			  * The sampler has the default stereo output channel layout and output sample rate of
			  * 44100 kHz.
			  */
			Sampler();
			
			
			
			
			/// Create a new sampler which has no streams currently playing and the specified attributes.
			/**
			  * This constructor allows the user to specify the output channel layout for the sampler,
			  * the output sample rate, and the maximum number of simultaneously playing streams.
			  *
			  * If the specified sample rate is less than or equal to zero, the default sample rate of
			  * 44100 kHz is used instead.
			  */
			Sampler( const ChannelLayout& newOutputChannelLayout, SampleRate newSampleRate = SampleRate(44100),
					Size newMaxSimultaneousStreams = Size(100) );
			
			
			
			
			/// Create a copy of the specified sampler with all stream playback state exactly the same.
			Sampler( const Sampler& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this sampler and any associated resources.
			~Sampler();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the entire state of another sampler to this one, including stream playback state.
			Sampler& operator = ( const Sampler& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Count Limit Accessor Methods
			
			
			
			
			/// Return the maximum number of simultaneous streams that this sampler is allowed to play.
			/**
			  * If an attempt is made to play a stream using a sampler that is at its maximum capacity will
			  * cause the sampler to replace the previously playing stream with the lowest priority
			  * and/or the oldest age.
			  */
			RIM_INLINE Size getMaximumNumberOfStreams() const
			{
				return maxSimultaneousStreams;
			}
			
			
			
			
			/// Set the maximum number of simultaneous streams that this sampler is allowed to play.
			/**
			  * If an attempt is made to play a stream using a sampler that is at its maximum capacity will
			  * cause the sampler to replace the previously playing stream with the lowest priority
			  * and/or the oldest age.
			  */
			RIM_INLINE void setMaximumNumberOfStreams( Size newMaxNumberOfStreams )
			{
				maxSimultaneousStreams = newMaxNumberOfStreams;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Accessor Methods
			
			
			
			
			/// Return the total number of streams that are currently playing in this sampler.
			RIM_INLINE Size getStreamCount() const
			{
				return numPlayingStreams;
			}
			
			
			
			
			/// Play a sound stream with the specified parameters.
			/**
			  * This method attempts to play the specified stream if the stream
			  * pointer is not NULL. If the maximum number of simultaneously playing streams
			  * is already playing, the new stream replaces the stream with the smallest
			  * priority which is already playing. If no stream has a smaller priority,
			  * the new stream is ignored.
			  *
			  * The method returns 0 if playing the stream failed, otherwise, the returned
			  * integer indicates an ID for the newly playing stream which can be used to modify
			  * its parameters during playback.
			  */
			Index playStream( const Pointer<SoundInputStream>& newStream, Bool loop = false, Int priority = 1,
							Gain gain = Gain(1.0), const PanDirection& pan = PanDirection(),
							SoundFilter* insert = NULL );
			
			
			
			
			/// Stop playing and remove the stream with the specified ID from this sampler.
			Bool removeStream( Index streamID );
			
			
			
			
			/// Stop playing and remove the stream with the specified stream pointer from this sampler.
			Bool removeStream( const SoundInputStream* stream );
			
			
			
			
			/// Remove and stop playing all currently playing streams from this sampler.
			void clearStreams();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Playback State Accessor Methods
			
			
			
			
			/// Return whether or not the stream with the specified ID is currently playing.
			/**
			  * If TRUE is returned, the stream with that ID is playing. If FALSE is returned
			  * the stream must be paused. The method returns FALSE if an invalid stream ID
			  * is specified.
			  */
			RIM_INLINE Bool getStreamIsPlaying( Index streamID ) const
			{
				Index streamIndex = streamID - 1;
				
				if ( streamIndex < streams.getSize() && !streams[streamIndex].stream.isNull() )
					return streams[streamIndex].playingEnabled;
				else
					return false;
			}
			
			
			
			
			/// Set whether or not the stream with the specified ID is currently playing.
			/**
			  * If the new playback state is FALSE, not playing, the stream with that ID
			  * is paused but kept active until it is played again. Any paused stream will
			  * still be counted as a playing stream, so it is important to either restart
			  * or remove any streams that shouldn't be a part of the sampler anymore because
			  * they will not be removed automatically.
			  */
			RIM_INLINE void setStreamIsPlaying( Index streamID, Bool newIsPlaying )
			{
				Index streamIndex = streamID - 1;
				
				lockMutex();
				
				if ( streamIndex < streams.getSize() && !streams[streamIndex].stream.isNull() )
					streams[streamIndex].playingEnabled = newIsPlaying;
				
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Looping State Accessor Methods
			
			
			
			
			/// Return whether or not the stream with the specified ID is currently playing.
			/**
			  * If TRUE is returned, the stream with that ID is looping. If FALSE is returned
			  * the stream does not loop. The method returns FALSE if an invalid stream ID
			  * is specified.
			  */
			RIM_INLINE Bool getStreamIsLooping( Index streamID ) const
			{
				Index streamIndex = streamID - 1;
				
				if ( streamIndex < streams.getSize() && !streams[streamIndex].stream.isNull() )
					return streams[streamIndex].loopingEnabled;
				else
					return false;
			}
			
			
			
			
			/// Set whether or not the stream with the specified ID is currently looping.
			/**
			  * If the new looping state is FALSE, not looping, the stream with that ID
			  * will continue to play until its end is reached, where it will be removed
			  * from the sampler. If the new looping state is TRUE, the stream will continue
			  * to play and loop until it is paused or removed from the sampler.
			  */
			RIM_INLINE void setStreamIsLooping( Index streamID, Bool newIsLooping )
			{
				Index streamIndex = streamID - 1;
				
				lockMutex();
				
				if ( streamIndex < streams.getSize() && !streams[streamIndex].stream.isNull() )
					streams[streamIndex].loopingEnabled = newIsLooping && streams[streamIndex].stream->canSeek();
				
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Priority Accessor Methods
			
			
			
			
			/// Return an integer representing the priority of the stream with the specified ID.
			/**
			  * This number controls what happens when the sampler's maximum number of simultaneous
			  * streams is reached. Streams with a larger priority cannot be replaced by streams
			  * with a smaller priority, and the sampler always replaces the stream with the lowest
			  * priority first. If an invalid stream ID is specified, the priority 0 is returned.
			  */
			RIM_INLINE Int getStreamPriority( Index streamID ) const
			{
				Index streamIndex = streamID - 1;
				
				if ( streamIndex < streams.getSize() && !streams[streamIndex].stream.isNull() )
					return streams[streamIndex].priority;
				else
					return 0;
			}
			
			
			
			
			/// Set the priority of the stream with the specified ID.
			/**
			  * This number controls what happens when the sampler's maximum number of simultaneous
			  * streams is reached. Streams with a larger priority cannot be replaced by streams
			  * with a smaller priority, and the sampler always replaces the stream with the lowest
			  * priority first.
			  */
			RIM_INLINE void setStreamPriority( Index streamID, Bool newPriority )
			{
				Index streamIndex = streamID - 1;
				
				lockMutex();
				
				if ( streamIndex < streams.getSize() && !streams[streamIndex].stream.isNull() )
					streams[streamIndex].priority = newPriority;
				
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Gain Accessor Methods
			
			
			
			
			/// Return the linear gain applied to the stream with the specified ID.
			/**
			  * If the specified ID is invalid, a gain of 1 is returned.
			  */
			RIM_INLINE Gain getStreamGain( Index streamID ) const
			{
				Index streamIndex = streamID - 1;
				
				if ( streamIndex < streams.getSize() && !streams[streamIndex].stream.isNull() )
					return streams[streamIndex].targetGain;
				else
					return Gain(1.0);
			}
			
			
			
			
			/// Set the linear gain applied to the stream with the specified ID.
			/**
			  * If the specified ID is invalid, the method has no effect.
			  */
			RIM_INLINE void setStreamGain( Index streamID, Gain newGain )
			{
				Index streamIndex = streamID - 1;
				
				lockMutex();
				
				if ( streamIndex < streams.getSize() && !streams[streamIndex].stream.isNull() )
					streams[streamIndex].targetGain = newGain;
				
				unlockMutex();
			}
			
			
			
			
			/// Return the gain in decibels applied to the stream with the specified ID.
			/**
			  * If the specified ID is invalid, a gain of 0 dB is returned.
			  */
			RIM_INLINE Gain getStreamGainDB( Index streamID ) const
			{
				Index streamIndex = streamID - 1;
				
				if ( streamIndex < streams.getSize() && !streams[streamIndex].stream.isNull() )
					return util::linearToDB( streams[streamIndex].targetGain );
				else
					return Gain(0);
			}
			
			
			
			
			/// Set the gain in decibels applied to the stream with the specified ID.
			/**
			  * If the specified ID is invalid, the method has no effect.
			  */
			RIM_INLINE void setStreamGainDB( Index streamID, Gain newDBGain )
			{
				Index streamIndex = streamID - 1;
				
				lockMutex();
				
				if ( streamIndex < streams.getSize() && !streams[streamIndex].stream.isNull() )
					streams[streamIndex].targetGain = util::dbToLinear( newDBGain );
				
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Pan Accessor Methods
			
			
			
			
			/// Return the panning direction for the stream with the specified ID.
			/**
			  * This direction pans the stream within the output buffer's channel layout
			  * in order to localize the stream in the stereo (or surround) field.
			  *
			  * If the specified ID is invalid, the default forward panning direction is returned.
			  */
			RIM_INLINE const PanDirection& getStreamPan( Index streamID ) const
			{
				Index streamIndex = streamID - 1;
				
				if ( streamIndex < streams.getSize() && !streams[streamIndex].stream.isNull() )
					return streams[streamIndex].pan;
				else
					return UNDEFINED_STREAM_PAN;
			}
			
			
			
			
			/// Set the panning direction for the stream with the specified ID.
			/**
			  * This direction pans the stream within the output buffer's channel layout
			  * in order to localize the stream in the stereo (or surround) field.
			  *
			  * If the specified ID is invalid, the method has no effect.
			  */
			RIM_INLINE void setStreamPan( Index streamID, const PanDirection& newPan )
			{
				Index streamIndex = streamID - 1;
				
				lockMutex();
				
				if ( streamIndex < streams.getSize() && !streams[streamIndex].stream.isNull() )
					streams[streamIndex].pan = newPan;
				
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Insert Accessor Methods
			
			
			
			
			/// Return a pointer to the filter insert for the stream with the specified ID.
			/**
			  * This filter (if not NULL) is used to affect the stream's sound before it is
			  * panned within the sampler's output channel layout and mixed to the output buffer
			  * with any applied gain. This allows the user to individually affect each stream's
			  * sound.
			  *
			  * If the specified ID is invalid, NULL is returned.
			  */
			RIM_INLINE SoundFilter* getStreamInsert( Index streamID ) const
			{
				Index streamIndex = streamID - 1;
				
				if ( streamIndex < streams.getSize() && !streams[streamIndex].stream.isNull() )
					return streams[streamIndex].insert;
				else
					return NULL;
			}
			
			
			
			
			/// Set a pointer to the filter insert for the stream with the specified ID.
			/**
			  * This filter (if not NULL) is used to affect the stream's sound before it is
			  * panned within the sampler's output channel layout and mixed to the output buffer
			  * with any applied gain. This allows the user to individually affect each stream's
			  * sound.
			  *
			  * If the specified ID is invalid, the method has no effect.
			  */
			RIM_INLINE void setStreamInsert( Index streamID, SoundFilter* newInsert )
			{
				Index streamIndex = streamID - 1;
				
				lockMutex();
				
				if ( streamIndex < streams.getSize() && !streams[streamIndex].stream.isNull() )
					streams[streamIndex].insert = newInsert;
				
				unlockMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Output Channel Layout Accessor Methods
			
			
			
			
			/// Return a reference to an object which describes the output channel format for this sampler.
			RIM_INLINE const ChannelLayout& getOutputChannelLayout() const
			{
				return outputChannelLayout;
			}
			
			
			
			
			/// Change the output channel format for this sampler.
			void setOutputChannelLayout( const ChannelLayout& newChannelLayout );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Output Sample Rate Accessor Methods
			
			
			
			
			/// Return the output sample rate for this sampler.
			/**
			  * The default sample rate is 44100 kHz.
			  */
			RIM_INLINE SampleRate getOutputSampleRate() const
			{
				return outputSampleRate;
			}
			
			
			
			
			/// Set the output sample rate for this sampler.
			/**
			  * If the new sample rate is less than or equal to 0, the method
			  * fails and has no effect.
			  * The default sample rate is 44100 kHz.
			  */
			void setOutputSampleRate( SampleRate newSampleRate );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Seek Status Accessor Methods
			
			
			
			
			/// Return whether or not seeking is allowed in this input stream.
			virtual Bool canSeek() const;
			
			
			
			
			/// Return whether or not this input stream's current position can be moved by the specified signed sample offset.
			virtual Bool canSeek( Int64 relativeSampleOffset ) const;
			
			
			
			
			/// Move the current sample frame position in the stream by the specified signed amount.
			virtual Int64 seek( Int64 relativeSampleOffset );
			
			
			
			
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
			virtual SoundSize getSamplesRemaining() const;
			
			
			
			
			/// Return the current position of the stream in samples relative to the start of the stream.
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
			
			
			
			
			/// Return the number of channels that are in the sound input stream.
			virtual Size getChannelCount() const;
			
			
			
			
			/// Return the sample rate of the sound input stream's source audio data.
			virtual SampleRate getSampleRate() const;
			
			
			
			
			/// Return the actual sample type used in the stream.
			virtual SampleType getNativeSampleType() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Status Accessor Method
			
			
			
			
			/// Return whether or not the stream has a valid source of sound data.
			virtual Bool isValid() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Attribute Accessor Methods
			
			
			
			
			/// Return a human-readable name for this sampler.
			/**
			  * The method returns the string "Sampler".
			  */
			virtual UTF8String getName() const;
			
			
			
			
			/// Return the manufacturer name of this sampler.
			/**
			  * The method returns the string "Headspace Sound".
			  */
			virtual UTF8String getManufacturer() const;
			
			
			
			
			/// Return an object representing the version of this sampler.
			virtual SoundFilterVersion getVersion() const;
			
			
			
			
			/// Return an object which describes the category of effect that this filter implements.
			/**
			  * This method returns the value SoundFilterCategory::PLAYBACK.
			  */
			virtual SoundFilterCategory getCategory() const;
			
			
			
			
			/// Return whether or not this sampler can process audio data in-place.
			/**
			  * This method always returns TRUE, sampler can process audio data in-place.
			  */
			virtual Bool allowsInPlaceProcessing() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Property Objects
			
			
			
			
			/// A string indicating the human-readable name of this sampler.
			static const UTF8String NAME;
			
			
			
			
			/// A string indicating the manufacturer name of this sampler.
			static const UTF8String MANUFACTURER;
			
			
			
			
			/// An object indicating the version of this sampler.
			static const SoundFilterVersion VERSION;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which holds information about a currently queued sound stream.
			class StreamInfo
			{
				public:
					
					/// Create a new playback stream information object with the specified stream and playback state.
					RIM_INLINE StreamInfo( const Pointer<SoundInputStream>& newStream, Bool loop, Int newPriority,
											Gain newGain, const PanDirection& newPan, SoundFilter* newInsert )
						:	stream( newStream ),
							priority( newPriority ),
							gain( newGain ),
							targetGain( newGain ),
							pan( newPan ),
							insert( newInsert ),
							sampleRateConverter( NULL ),
							currentStreamPosition( 0 ),
							playingEnabled( true ),
							loopingEnabled( loop )
					{
					}
					
					
					/// A sound stream which provides the audio for this playback slot.
					Pointer<SoundInputStream> stream;
					
					
					/// An integer representing the priority of this stream.
					Int priority;
					
					
					/// A linear gain factor which is applied to the stream's audio during playback.
					Gain gain;
					
					
					/// The target linear gain factor which is used to interpolate changes in the playback gain.
					Gain targetGain;
					
					
					/// An object representing how this stream should be panned in the output channel configuration.
					PanDirection pan;
					
					
					/// An optionally NULL pointer to a filter which is inserted on this stream's output (pre gain and pan).
					SoundFilter* insert;
					
					
					/// A pointer to an object (sometimes NULL) which handles sample rate conversion for this stream.
					SampleRateConverter* sampleRateConverter;
					
					
					/// A mix matrix which stores the current channel mix matrix of the stream panning.
					ChannelMixMatrix channelGains;
					
					
					/// A mix matrix which stores the target channel mix matrix of the stream panning.
					ChannelMixMatrix targetChannelGains;
					
					
					/// The current position within the stream, relative to the stream's starting position.
					SampleIndex currentStreamPosition;
					
					
					/// A boolean value indicating whether or not the sampler should be playing the stream.
					Bool playingEnabled;
					
					
					/// A boolean value indicating whether or not the sampler should be looping the stream.
					Bool loopingEnabled;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Filter Processing Methods
			
			
			
			
			/// Play the specified number of samples from the sound input stream and place them in the output frame.
			virtual SoundFilterResult processFrame( const SoundFilterFrame& inputFrame,
													SoundFilterFrame& outputFrame, Size numSamples );
			
			
			
			
			/// Read the specified number of samples from the input stream into the output buffer.
			virtual Size readSamples( SoundBuffer& outputBuffer, Size numSamples );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The default maximum number of simultaneously playing streams.
			static const Size DEFAULT_MAX_NUMBER_OF_STREAMS = 100;
			
			
			
			
			/// An object representing the pan direction of an invalid stream.
			static const PanDirection UNDEFINED_STREAM_PAN;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of all of the slots for streams that can play as part of this sampler.
			ArrayList<StreamInfo> streams;
			
			
			
			
			/// An object describing the output channel layout for this sampler.
			ChannelLayout outputChannelLayout;
			
			
			
			
			/// The output sample rate for this sampler.
			SampleRate outputSampleRate;
			
			
			
			
			/// The total number of streams in the sampler which are currently playing.
			Size numPlayingStreams;
			
			
			
			
			/// An integer representing the maximum number of simultaneously playing streams.
			Size maxSimultaneousStreams;
			
			
			
			
			/// A boolean value indicating whether or not the sampler should be playing any stream.
			Bool globalPlayingEnabled;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_SAMPLER_H
