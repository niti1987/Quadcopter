/*
 *  rimSoundBufferQueue.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/8/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_BUFFER_QUEUE_H
#define INCLUDE_RIM_SOUND_BUFFER_QUEUE_H


#include "rimSoundUtilitiesConfig.h"


#include "rimSoundBuffer.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which efficiently queues SoundBuffer objects in a first-in-first-out manner.
/**
  * This class can be used to buffer sound data between a sound producer and sound
  * consumer, such as between threads. However, this queue is NOT threadsafe, so
  * thread synchronization should be performed externally.
  */
class SoundBufferQueue
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new empty sound buffer queue.
			SoundBufferQueue();
			
			
			
			
			/// Create an exact copy of the specified sound buffer queue.
			SoundBufferQueue( const SoundBufferQueue& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this sound buffer queue and release all associated resources.
			~SoundBufferQueue();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of another sound buffer queue to this queue.
			SoundBufferQueue& operator = ( const SoundBufferQueue& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Queue Accessor Methods
			
			
			
			
			/// Return the total number of buffers that are queued in this buffer queue, waiting to be read.
			RIM_INLINE Size getBufferCount() const
			{
				return numBuffersQueued;
			}
			
			
			
			
			/// Return whether or not this buffer queue has a next buffer to read from.
			RIM_INLINE Bool hasNextBuffer() const
			{
				return numBuffersQueued > 0;
			}
			
			
			
			
			/// Return a reference to the next buffer to be read in the queue.
			/**
			  * The buffer's size corresponds to the number of valid samples in the buffer.
			  */
			SoundBuffer& getNextBuffer()
			{
				return *buffers[nextOutputBufferIndex];
			}
			
			
			
			
			/// Return a reference to the next buffer to be read in the queue.
			/**
			  * The buffer's size corresponds to the number of valid samples in the buffer.
			  */
			const SoundBuffer& getNextBuffer() const
			{
				return *buffers[nextOutputBufferIndex];
			}
			
			
			
			
			/// Write the specified number of samples from the given buffer to the queue.
			void addBuffer( const SoundBuffer& buffer, Size numSamples );
			
			
			
			
			
			/// Remove the next buffer from the buffer queue, indicating that it has been processed.
			RIM_INLINE void removeBuffer()
			{
				// If possible, increment the next buffer index.
				if ( this->hasNextBuffer() )
				{
					nextOutputBufferIndex = (nextOutputBufferIndex + 1) % buffers.getSize();
					numBuffersQueued--;
				}
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An array of sound buffers which serves as the queue.
			ArrayList<SoundBuffer*> buffers;
			
			
			
			
			/// The index of the buffer in the array which corresponds to the next place to put input audio.
			Index nextInputBufferIndex;
			
			
			
			
			/// The index of the buffer in the array which corresponds to the next place to get output audio.
			Index nextOutputBufferIndex;
			
			
			
			
			/// The total number of valid buffers in the queue waiting to be read.
			Size numBuffersQueued;
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_BUFFER_QUEUE_H
