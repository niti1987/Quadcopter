/*
 *  rimSoundMIDIBuffer.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 4/25/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_MIDI_BUFFER_H
#define INCLUDE_RIM_SOUND_MIDI_BUFFER_H


#include "rimSoundUtilitiesConfig.h"


#include "rimSoundMIDIEvent.h"
#include "rimSoundMIDITime.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a sequence of MIDI events.
/**
  * A MIDI buffer keeps a small local storage space for events which avoids
  * allocating any extra memory when the total number of events in a buffer
  * small (less than a few).
  */
class MIDIBuffer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an empty MIDI buffer with the default initial capacity.
			RIM_INLINE MIDIBuffer()
				:	events( (MIDIEvent*)eventArray ),
					numEvents( 0 ),
					eventCapacity( FIXED_EVENT_ARRAY_SIZE )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a MIDI buffer, deallocating its internal array of events.
			RIM_INLINE ~MIDIBuffer()
			{
				if ( events != (MIDIEvent*)eventArray )
					rim::util::deallocate( events );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of the specified MIDI buffer to this one.
			MIDIBuffer& operator = ( const MIDIBuffer& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Event Accessor Methods
			
			
			
			
			/// Return the total number of valid events that are part of this MIDI buffer.
			RIM_INLINE Size getEventCount() const
			{
				return numEvents;
			}
			
			
			
			
			/// Return a reference to the MIDI event at the specified index in this MIDI buffer.
			RIM_INLINE MIDIEvent& getEvent( Index eventIndex )
			{
				RIM_DEBUG_ASSERT_MESSAGE( eventIndex < numEvents, "Invalid MIDI event buffer index" );
				
				return events[eventIndex];
			}
			
			
			
			
			/// Return a const reference to the MIDI event at the specified index in this MIDI buffer.
			RIM_INLINE const MIDIEvent& getEvent( Index eventIndex ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( eventIndex < numEvents, "Invalid MIDI event buffer index" );
				
				return events[eventIndex];
			}
			
			
			
			
			/// Add a new MIDI event to the end of this MIDI buffer.
			RIM_INLINE void addEvent( const MIDIEvent& newEvent )
			{
				if ( numEvents == eventCapacity )
					reallocateEvents( eventCapacity*2 );
				
				events[numEvents] = newEvent;
				numEvents++;
			}
			
			
			
			
			/// Remove all events from this MIDI buffer.
			RIM_INLINE void clearEvents()
			{
				numEvents = 0;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Capacity Accessor Methods
			
			
			
			
			/// Return the maximum number of events that can be stored in this buffer without any buffer reallocations.
			RIM_INLINE Size getCapacity() const
			{
				return eventCapacity;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer MIDI Time Accessor Methods
			
			
			
			
			/// Return the musical time within the MIDI sequence for the start of this frame.
			RIM_INLINE const MIDITime& getTime() const
			{
				return time;
			}
			
			
			
			
			/// Set the musical time within the MIDI sequence for the start of this frame.
			RIM_INLINE void setTime( const MIDITime& newTime )
			{
				time = newTime;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Copy Method
			
			
			
			
			/// Copy the entire contents of this buffer to another MIDI buffer, including the MIDI time.
			void copyTo( MIDIBuffer& other ) const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Double the capacity of the internal event array, copying the old events.
			void reallocateEvents( Size newCapacity );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// Define the size of the fixed-size array of MIDI events that is part of a MIDIBuffer.
			static const Size FIXED_EVENT_ARRAY_SIZE = 2;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the internal buffer of events.
			MIDIEvent* events;
			
			
			
			
			/// The number of events that are currently valid in this MIDI buffer.
			Size numEvents;
			
			
			
			
			/// The total number of events that can be stored in the current data buffer used by this MIDI buffer.
			Size eventCapacity;
			
			
			
			
			/// An object representing the musical time within the MIDI sequence for the start of this buffer.
			MIDITime time;
			
			
			
			
			/// A fixed-size array of bytes that localy store a few MIDI events to avoid allocations.
			UByte eventArray[FIXED_EVENT_ARRAY_SIZE*sizeof(MIDIEvent)];
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_MIDI_BUFFER_H
