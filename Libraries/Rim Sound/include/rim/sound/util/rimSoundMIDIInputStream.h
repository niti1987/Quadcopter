/*
 *  rimSoundMIDIInputStream.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 5/30/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_MIDI_INPUT_STREAM_H
#define INCLUDE_RIM_SOUND_MIDI_INPUT_STREAM_H


#include "rimSoundUtilitiesConfig.h"


#include "rimSoundMIDIMessage.h"
#include "rimSoundMIDIEvent.h"
#include "rimSoundMIDIBuffer.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a stream-readable source for MIDI data.
class MIDIInputStream
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this MIDI input stream and release any resourcees associated with it.
			virtual ~MIDIInputStream()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	MIDI Reading Methods
			
			
			
			
			/// Read the specified number of MIDI events from the input stream into the output buffer.
			/**
			  * This method attempts to read the specified number of MIDI events from the
			  * stream into the buffer and then returns the total number of events that
			  * were successfully read. The stream's current position is incremented by the
			  * return value.
			  *
			  * The timestamps of the returned MIDI events are specified relative to the start
			  * of the stream.
			  */
			RIM_INLINE Size read( MIDIBuffer& buffer, Size numEvents )
			{
				return this->readEvents( buffer, numEvents );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Seek Status Accessor Methods
			
			
			
			
			/// Return whether or not seeking is allowed in this input stream.
			virtual Bool canSeek() const = 0;
			
			
			
			
			/// Return whether or not this input stream's current position can be moved by the specified signed event offset.
			/**
			  * This event offset is specified as the signed number of MIDI events to move
			  * in the stream.
			  */
			virtual Bool canSeek( Int64 relativeEventOffset ) const = 0;
			
			
			
			
			/// Move the current event position in the stream by the specified signed amount of events.
			/**
			  * This method attempts to seek the position in the stream by the specified amount of MIDI events.
			  * The method returns the signed amount that the position in the stream was changed
			  * by. Thus, if seeking is not allowed, 0 is returned. Otherwise, the stream should
			  * seek as far as possible in the specified direction and return the actual change
			  * in position.
			  */
			virtual Int64 seek( Int64 relativeEventOffset ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Size Accessor Methods
			
			
			
			
			/// Return the number of MIDI events remaining in the MIDI input stream.
			/**
			  * The value returned must only be a lower bound on the total number of MIDI
			  * events in the stream. For instance, if there are events remaining, the method
			  * should return at least 1. If there are no events remaining, the method should
			  * return 0. This behavior is allowed in order to support never-ending streams
			  * which might not have a defined endpoint.
			  */
			virtual Size getEventsRemaining() const = 0;
			
			
			
			
			/// Return whether or not this MIDI input stream has any events remaining in the stream.
			RIM_INLINE Bool hasEventsRemaining() const
			{
				return this->getEventsRemaining() > Size(0);
			}
			
			
			
			
			/// Return the current position of the stream in events relative to the start of the stream.
			/**
			  * The returned value indicates the event index of the current read
			  * position within the MIDI stream. For unbounded streams, this indicates
			  * the number of samples that have been read by the stream since it was opened.
			  */
			virtual Index getPosition() const = 0;
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected MIDI Stream Methods
			
			
			
			
			/// Read the specified number of MIDI events from the input stream into the output buffer.
			/**
			  * This method attempts to read the specified number of MIDI events from the
			  * stream into the buffer and then returns the total number of events that
			  * were successfully read. The stream's current position is incremented by the
			  * return value.
			  *
			  * The timestamps of the returned MIDI events are specified relative to the start
			  * of the stream.
			  */
			virtual Size readEvents( MIDIBuffer& buffer, Size numEvents ) = 0;
			
			
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_MIDI_INPUT_STREAM_H
