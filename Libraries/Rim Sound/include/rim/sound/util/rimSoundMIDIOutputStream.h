/*
 *  rimSoundMIDIOutputStream.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 5/30/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_MIDI_OUTPUT_STREAM_H
#define INCLUDE_RIM_SOUND_MIDI_OUTPUT_STREAM_H


#include "rimSoundUtilitiesConfig.h"


#include "rimSoundMIDIMessage.h"
#include "rimSoundMIDIEvent.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a stream-writable destination for MIDI data.
class MIDIOutputStream
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this MIDI output stream and release any resourcees associated with it.
			virtual ~MIDIOutputStream()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Writing Methods
			
			
			
			
			/// Write the specified number of MIDI events from the buffer to the output stream.
			/**
			  * This method attempts to write the specified number of MIDI events to the stream
			  * from the buffer. It then returns the total number of valid events which
			  * were written to the stream. The current write position in the stream
			  * is advanced by the number of events that are written.
			  */
			RIM_INLINE Size write( const MIDIBuffer& buffer, Size numEvents )
			{
				numEvents = math::min( buffer.getEventCount(), numEvents );
				
				return this->writeEvents( buffer, numEvents );
			}
			
			
			
			
			/// Flush the MIDI output stream, sending all internally buffered events to the destination.
			/** 
			  * This method causes all currently pending output MIDI data to be sent to it's
			  * final destination. This method blocks the current thread until it ensures that
			  * this is done and that all internal data buffers are emptied if they have any contents.
			  */
			virtual void flush() = 0;
			
			
			
			
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
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Stream Methods
			
			
			
			
			/// Write the specified number of MIDI events from the buffer to the output stream.
			/**
			  * This method attempts to write the specified number of MIDI events to the stream
			  * from the buffer. It then returns the total number of valid events which
			  * were written to the stream. The current write position in the stream
			  * is advanced by the number of events that are written.
			  */
			virtual Size writeEvents( const MIDIBuffer& buffer, Size numEvents ) = 0;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_MIDI_OUTPUT_STREAM_H
