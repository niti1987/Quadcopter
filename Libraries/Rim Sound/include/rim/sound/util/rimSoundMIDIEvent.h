/*
 *  rimSoundMIDIEvent.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 5/25/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_MIDI_EVENT_H
#define INCLUDE_RIM_SOUND_MIDI_EVENT_H


#include "rimSoundUtilitiesConfig.h"


#include "rimSoundMIDIMessage.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a single MIDI message that fires at an absolute moment in time.
/**
  * This class consists of a MIDIMessage object and a relative time at which that
  * event occurs.
  */
class MIDIEvent
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default MIDI event with an undefined message and time.
			RIM_INLINE MIDIEvent()
				:	message(),
					time()
			{
			}
			
			
			
			
			/// Create a MIDI event for the specified message.
			/**
			  * The time for the event is default-initialized to be 0, indicating
			  * it coincided with the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
			  */
			RIM_INLINE MIDIEvent( const MIDIMessage& newMessage )
				:	message( newMessage ),
					time()
			{
			}
			
			
			
			
			/// Create a MIDI event for the specified message at the specified time.
			/**
			  * This time is measured relative to the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
			  */
			RIM_INLINE MIDIEvent( const MIDIMessage& newMessage, const Time& newTime )
				:	message( newMessage ),
					time( newTime )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Message Accessor Methods
			
			
			
			
			/// Return a reference to the MIDI message associated with this event.
			RIM_INLINE const MIDIMessage& getMessage() const
			{
				return message;
			}
			
			
			
			
			/// Set the MIDI message which is associated with this event.
			RIM_INLINE void setMessage( const MIDIMessage& newMessage )
			{
				message = newMessage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Time Accessor Methods
			
			
			
			
			/// Return the relative time at which this MIDI event occurred.
			/**
			  * This time is measured relative to some reference time. For absolute-time
			  * MIDI events (real-time), the reference time is the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
			  * For other events, such as those that are part of a SoundFilterFrame, the
			  * time is specified relative to the frame's time.
			  */
			RIM_INLINE const Time& getTime() const
			{
				return time;
			}
			
			
			
			
			/// Set the absolute time at which this MIDI event occurred.
			/**
			  * This time is measured relative to some reference time. For absolute-time
			  * MIDI events (real-time), the reference time is the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
			  * For other events, such as those that are part of a SoundFilterFrame, the
			  * time is specified relative to the frame's time.
			  */
			RIM_INLINE void setTime( const Time& newTime )
			{
				time = newTime;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The MIDI message associated with this MIDI event.
			MIDIMessage message;
			
			
			
			
			/// The relative offset in time when the associated MIDI message occurred from some reference point.
			/**
			  * This time is measured relative to some reference time. For absolute-time
			  * MIDI events (real-time), the reference time is the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
			  * For other events, such as those that are part of a SoundFilterFrame, the
			  * time is specified relative to the frame's time.
			  */
			Time time;
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_MIDI_EVENT_H
