/*
 *  rimSoundFilterFrame.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 8/15/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_FILTER_FRAME_H
#define INCLUDE_RIM_SOUND_FILTER_FRAME_H


#include "rimSoundFiltersConfig.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which provides all of the information needed for a SoundFilter to process sound data.
/**
  * Primarily, a filter frame holds an internal array of pointers to SoundBuffer objects
  * which represent the buffers for each filter input or output. These buffers are allowed
  * to be NULL, indicating that either the input at that index was not provided or
  * the output at that index is not needed.
  *
  * A filter frame uses a fixed-size internal array of pointers to SoundBuffer objects
  * but can also allocate a variable-sized array of buffer pointers if the capacity of
  * the fixed size array is exceeded. This is done for performance, so that an allocation
  * is not performed in most cases when using multiple buffers.
  *
  * A similar buffer scheme is used for MIDI data. All MIDI events that are part of a 
  * frame are specified with their timestamp relative to the main frame absolute timestamp,
  * rather than as absolute timestamps.
  *
  * Each filter frame has an associated absolute timestamp, measured relative to the
  * Epoch, 1970-01-01 00:00:00 +0000 (UTC). This allows the filter to detect breaks
  * in the sound timeline and react accordingly, or to synchronize sound processing,
  * such as with video.
  */
class SoundFilterFrame
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new sound filter frame which has no buffers and the default capacity.
			RIM_INLINE SoundFilterFrame()
				:	buffers( bufferArray ),
					numBuffers( 0 ),
					bufferCapacity( FIXED_BUFFER_ARRAY_SIZE ),
					midiBuffers( midiBufferArray ),
					numMIDIBuffers( 0 ),
					midiBufferCapacity( FIXED_MIDI_BUFFER_ARRAY_SIZE ),
					time()
			{
			}
			
			
			
			
			/// Create a new sound filter frame which has the specified number of buffers (initially all NULL).
			RIM_INLINE SoundFilterFrame( Size newNumBuffers )
				:	numBuffers( (UInt16)newNumBuffers ),
					bufferCapacity( (UInt16)math::max( newNumBuffers, FIXED_BUFFER_ARRAY_SIZE ) ),
					midiBuffers( midiBufferArray ),
					numMIDIBuffers( 0 ),
					midiBufferCapacity( FIXED_MIDI_BUFFER_ARRAY_SIZE ),
					time()
			{
				if ( bufferCapacity > FIXED_BUFFER_ARRAY_SIZE )
					buffers = rim::util::allocate<SoundBuffer*>( bufferCapacity );
				else
					buffers = bufferArray;
				
				this->setBuffersToNull();
			}
			
			
			
			
			/// Create a new sound filter frame which wraps a single SoundBuffer object pointer.
			RIM_INLINE SoundFilterFrame( SoundBuffer* newBuffer )
				:	buffers( bufferArray ),
					numBuffers( 1 ),
					bufferCapacity( FIXED_BUFFER_ARRAY_SIZE ),
					midiBuffers( midiBufferArray ),
					numMIDIBuffers( 0 ),
					midiBufferCapacity( FIXED_MIDI_BUFFER_ARRAY_SIZE ),
					time()
			{
				buffers[0] = newBuffer;
			}
			
			
			
			
			/// Create a new sound filter frame which wraps two SoundBuffer object pointers.
			RIM_INLINE SoundFilterFrame( SoundBuffer* newBuffer1, SoundBuffer* newBuffer2 )
				:	buffers( bufferArray ),
					numBuffers( 2 ),
					bufferCapacity( FIXED_BUFFER_ARRAY_SIZE ),
					midiBuffers( midiBufferArray ),
					numMIDIBuffers( 0 ),
					midiBufferCapacity( FIXED_MIDI_BUFFER_ARRAY_SIZE ),
					time()
			{
				buffers[0] = newBuffer1;
				buffers[1] = newBuffer2;
			}
			
			
			
			
			/// Create an exact copy of the specified filter frame, copying all of its buffer pointers.
			SoundFilterFrame( const SoundFilterFrame& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a sound filter frame and release all of its resources.
			RIM_INLINE ~SoundFilterFrame()
			{
				// Deallocate the buffer array if necessary.
				if ( buffers != bufferArray )
					rim::util::deallocate( buffers );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of the specified filter frame, including its buffer pointers.
			SoundFilterFrame& operator = ( const SoundFilterFrame& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Accessor Methods
			
			
			
			
			/// Get the number of buffers that this filter frame contains.
			RIM_INLINE Size getBufferCount() const
			{
				return numBuffers;
			}
			
			
			
			
			/// Change the size of the internal buffer array, padding any new buffer pointers with NULL.
			/**
			  * If the number of buffers is increasing, the new buffer pointers for the
			  * filter frame are set to NULL. Otherwise, if the number is decreasing, the extra
			  * buffer pointers are discarded.
			  */
			RIM_INLINE void setBufferCount( Size newNumBuffers )
			{
				// Resize the buffer array if necessary.
				if ( newNumBuffers > bufferCapacity )
					this->reallocateBuffers( newNumBuffers );
				
				// Set all extra buffer pointers to NULL.
				for ( Index i = numBuffers; i < newNumBuffers; i++ )
					buffers[i] = NULL;
				
				numBuffers = (UInt16)newNumBuffers;
			}
			
			
			
			
			/// Get the SoundBuffer within this filter frame at the specified index.
			/**
			  * If the specified buffer index is greater than or equal to the number
			  * of buffers in this filter frame, NULL is returned.
			  * 
			  * @param bufferIndex - the index of the buffer in this frame to access.
			  * @return a reference to the SoundBuffer at the specified index.
			  */
			RIM_INLINE SoundBuffer* getBuffer( Index bufferIndex )
			{
				if ( bufferIndex < numBuffers )
					return buffers[bufferIndex];
				else
					return NULL;
			}
			
			
			
			
			/// Get the SoundBuffer within this filter frame at the specified index.
			/**
			  * If the specified buffer index is greater than or equal to the number
			  * of buffers in this filter frame, NULL is returned.
			  * 
			  * @param bufferIndex - the index of the buffer in this frame to access.
			  * @return a reference to the SoundBuffer at the specified index.
			  */
			RIM_INLINE const SoundBuffer* getBuffer( Index bufferIndex ) const
			{
				if ( bufferIndex < numBuffers )
					return buffers[bufferIndex];
				else
					return NULL;
			}
			
			
			
			
			/// Replace the SoundBuffer pointer at the specified index with a new pointer.
			/**
			  * If the specified buffer index is invalid, the method has no effect.
			  */
			RIM_INLINE void setBuffer( Index bufferIndex, SoundBuffer* newBuffer )
			{
				if ( bufferIndex < numBuffers )
					buffers[bufferIndex] = newBuffer;
			}
			
			
			
			
			/// Add the specified buffer pointer to the end of this frame's list of buffers.
			RIM_INLINE void addBuffer( SoundBuffer* newBuffer )
			{
				if ( numBuffers == bufferCapacity )
					this->reallocateBuffers( bufferCapacity*2 );
				
				buffers[numBuffers] = newBuffer;
				numBuffers++;
			}
			
			
			
			
			/// Insert the specified buffer pointer at the specified index in this frame's list of buffers.
			RIM_INLINE void insertBuffer( Index newBufferIndex, SoundBuffer* newBuffer )
			{
				if ( numBuffers == bufferCapacity )
					this->reallocateBuffers( bufferCapacity*2 );
				
				for ( Index i = numBuffers; i > newBufferIndex; i-- )
					buffers[i] = buffers[i - 1];
				
				buffers[newBufferIndex] = newBuffer;
				numBuffers++;
			}
			
			
			
			
			/// Remove the buffer from this filter frame at the specified index.
			/**
			  * This method shifts all buffer pointers after the specified index
			  * back by one index to replace the removed buffer. If the specified
			  * buffer index is invalid, the method has no effect.
			  */
			RIM_INLINE void removeBuffer( Index bufferIndex )
			{
				if ( bufferIndex >= numBuffers )
					return;
				
				numBuffers--;
				
				for ( Index i = bufferIndex; i < numBuffers; i++ )
					buffers[i] = buffers[i + 1];
			}
			
			
			
			
			/// Remove all buffers from this filter frame.
			RIM_INLINE void clearBuffers()
			{
				numBuffers = 0;
			}
			
			
			
			
			/// Keep the current number of valid buffers the same, but set all buffer pointers to NULL.
			RIM_INLINE void setBuffersToNull()
			{
				for ( Index i = 0; i < numBuffers; i++ )
					buffers[i] = NULL;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	MIDI Buffer Accessor Methods
			
			
			
			
			/// Get the number of MIDI buffers that this filter frame contains.
			RIM_INLINE Size getMIDIBufferCount() const
			{
				return numMIDIBuffers;
			}
			
			
			
			
			/// Change the size of the internal MIDI buffer array, padding any new buffer pointers with NULL.
			/**
			  * If the number of MIDI buffers is increasing, the new buffer pointers for the
			  * filter frame are set to NULL. Otherwise, if the number is decreasing, the extra
			  * buffer pointers are discarded.
			  */
			RIM_INLINE void setMIDIBufferCount( Size newNumBuffers )
			{
				// Resize the buffer array if necessary.
				if ( newNumBuffers > midiBufferCapacity )
					this->reallocateMIDIBuffers( newNumBuffers );
				
				// Set all extra buffer pointers to NULL.
				for ( Index i = numMIDIBuffers; i < newNumBuffers; i++ )
					midiBuffers[i] = NULL;
				
				numMIDIBuffers = (UInt16)newNumBuffers;
			}
			
			
			
			
			/// Get the MIDI buffer within this filter frame at the specified index.
			/**
			  * If the specified buffer index is greater than or equal to the number
			  * of MIDI buffers in this filter frame, NULL is returned.
			  * 
			  * @param bufferIndex - the index of the MIDI buffer in this frame to access.
			  * @return a pointer to the MIDIBuffer at the specified index.
			  */
			RIM_INLINE MIDIBuffer* getMIDIBuffer( Index bufferIndex )
			{
				if ( bufferIndex < numMIDIBuffers )
					return midiBuffers[bufferIndex];
				else
					return NULL;
			}
			
			
			
			
			/// Get the MIDI buffer within this filter frame at the specified index.
			/**
			  * If the specified buffer index is greater than or equal to the number
			  * of MIDI buffers in this filter frame, NULL is returned.
			  * 
			  * @param bufferIndex - the index of the MIDI buffer in this frame to access.
			  * @return a pointer to the MIDIBuffer at the specified index.
			  */
			RIM_INLINE const MIDIBuffer* getMIDIBuffer( Index bufferIndex ) const
			{
				if ( bufferIndex < numMIDIBuffers )
					return midiBuffers[bufferIndex];
				else
					return NULL;
			}
			
			
			
			
			/// Replace the MIDI buffer pointer at the specified index with a new pointer.
			/**
			  * If the specified buffer index is invalid, the method has no effect.
			  */
			RIM_INLINE void setMIDIBuffer( Index bufferIndex, MIDIBuffer* newBuffer )
			{
				if ( bufferIndex < numMIDIBuffers )
					midiBuffers[bufferIndex] = newBuffer;
			}
			
			
			
			
			/// Add the specified MIDI buffer pointer to the end of this frame's list of MIDI buffers.
			RIM_INLINE void addMIDIBuffer( MIDIBuffer* newBuffer )
			{
				if ( numMIDIBuffers == midiBufferCapacity )
					this->reallocateMIDIBuffers( midiBufferCapacity*2 );
				
				midiBuffers[numMIDIBuffers] = newBuffer;
				numMIDIBuffers++;
			}
			
			
			
			
			/// Insert the specified MIDI buffer pointer at the specified index in this frame's list of MIDI buffers.
			RIM_INLINE void insertMIDIBuffer( Index newBufferIndex, MIDIBuffer* newBuffer )
			{
				if ( numMIDIBuffers == midiBufferCapacity )
					this->reallocateMIDIBuffers( midiBufferCapacity*2 );
				
				for ( Index i = numMIDIBuffers; i > newBufferIndex; i-- )
					midiBuffers[i] = midiBuffers[i - 1];
				
				midiBuffers[newBufferIndex] = newBuffer;
				numMIDIBuffers++;
			}
			
			
			
			
			/// Remove the MIDI buffer from this filter frame at the specified index.
			/**
			  * This method shifts all MIDI buffer pointers after the specified index
			  * back by one index to replace the removed buffer. If the specified
			  * buffer index is invalid, the method has no effect.
			  */
			RIM_INLINE void removeMIDIBuffer( Index bufferIndex )
			{
				if ( bufferIndex >= numMIDIBuffers )
					return;
				
				numMIDIBuffers--;
				
				for ( Index i = bufferIndex; i < numMIDIBuffers; i++ )
					midiBuffers[i] = midiBuffers[i + 1];
			}
			
			
			
			
			/// Remove all MIDI buffers from this filter frame.
			RIM_INLINE void clearMIDIBuffers()
			{
				numMIDIBuffers = 0;
			}
			
			
			
			
			/// Keep the current number of valid MIDI buffers the same, but set all buffer pointers to NULL.
			RIM_INLINE void setMIDIBuffersToNull()
			{
				for ( Index i = 0; i < numMIDIBuffers; i++ )
					midiBuffers[i] = NULL;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	MIDI Copy Method
			
			
			
			
			/// Copy this sound filter frame's MIDI data to another frame, replacing its MIDI data.
			/**
			  * This method is provided as a convenient way to pass through MIDI from an input
			  * frame to an output frame if the filter doesn't need to modify the MIDI data.
			  *
			  * The method iterates over the MIDI buffers in this frame and copies their contents
			  * to the corresponding MIDI buffer of the other frame if it exists, replacing
			  * the previous contents of the other buffer.
			  */
			void copyMIDITo( SoundFilterFrame& other ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Frame Time Accessor Methods
			
			
			
			
			/// Return the absolute time of the start of this filter frame.
			/**
			  * This is measured relative to the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
			  */
			RIM_INLINE const Time& getTime() const
			{
				return time;
			}
			
			
			
			
			/// Set the absolute time of the start of this filter frame.
			/**
			  * This is measured relative to the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
			  */
			RIM_INLINE void setTime( const Time& newTime )
			{
				time = newTime;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Frame Limit Accessor Methods
			
			
			
			
			/// Return the maximum number of sound buffers that a sound filter frame can have.
			RIM_INLINE static Size getMaximumNumberOfBuffers()
			{
				return Size(math::max<UInt16>());
			}
			
			
			
			
			/// Return the maximum number of MIDI buffers that a sound filter frame can have.
			RIM_INLINE static Size getMaximumNumberOfMIDIBuffers()
			{
				return Size(math::max<UInt16>());
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Method
			
			
			
			
			/// Double the capacity of the internal buffer array, copying the old buffer pointers.
			void reallocateBuffers( Size newCapacity );
			
			
			
			
			/// Double the capacity of the internal MIDI buffer array, copying the old buffer pointers.
			void reallocateMIDIBuffers( Size newCapacity );
			
			
			
			
			/// A helper method which copies all of the MIDI data to another filter frame.
			/**
			  * This allows the fast parts of copyMIDITo() to be inlined, while the longer
			  * code for copying (if there are any MIDI events) is in this method.
			  */
			void copyMIDIToInternal( SoundFilterFrame& other ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// Define the size of the fixed-size array of sound buffers that is part of a SoundFilterFrame.
			static const Size FIXED_BUFFER_ARRAY_SIZE = 2;
			
			
			
			
			/// Define the size of the fixed-size array of MIDI buffers that is part of a SoundFilterFrame.
			static const Size FIXED_MIDI_BUFFER_ARRAY_SIZE = 1;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to an array of SoundBuffer pointers which represent the buffers for this frame.
			SoundBuffer** buffers;
			
			
			
			
			/// A pointer to an array of MIDIBuffer pointers which represent the MIDI buffers for this frame.
			MIDIBuffer** midiBuffers;
			
			
			
			
			/// The number of buffers that this filter frame has.
			UInt16 numBuffers;
			
			
			
			
			/// The maximum number of buffers that this filter frame can hold.
			UInt16 bufferCapacity;
			
			
			
			
			/// The number of MIDI buffers that this filter frame has.
			UInt16 numMIDIBuffers;
			
			
			
			
			/// The maximum number of MIDI buffers that this filter frame can hold.
			UInt16 midiBufferCapacity;
			
			
			
			
			/// The absolute time of the start of this filter frame.
			/**
			  * This is measured relative to the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
			  */
			Time time;
			
			
			
			
			/// A fixed-size array of buffers that are part of the frame object to avoid excessive allocations.
			SoundBuffer* bufferArray[FIXED_BUFFER_ARRAY_SIZE];
			
			
			
			
			/// A fixed-size array of MIDI buffers that are part of the frame object to avoid excessive allocations.
			MIDIBuffer* midiBufferArray[FIXED_MIDI_BUFFER_ARRAY_SIZE];
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_FILTER_FRAME_H
