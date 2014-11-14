/*
 *  rimSoundMIDIMessage.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 7/15/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_MIDI_MESSAGE_H
#define INCLUDE_RIM_SOUND_MIDI_MESSAGE_H


#include "rimSoundUtilitiesConfig.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a single MIDI message.
/**
  * This particular implementation does not support SysEx MIDI messages.
  */
class MIDIMessage
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Type Enum Declaration
			
			
			
			
			/// An enum which indicates the type of a MIDI message.
			typedef enum Type
			{
				/// A message type indicating that a note was turned on.
				NOTE_ON,
				
				/// A message type indicating that a note was turned off.
				NOTE_OFF,
				
				/// A message type indicating that a control parameter was changed.
				CONTROL_CHANGE,
				
				/// A message type indicating a change in a key's current pressure.
				AFTERTOUCH,
				
				/// A message type indicating a change in a MIDI channel's global pressure.
				CHANNEL_PRESSURE,
				
				/// A message type indicating a change in the pitch wheel's position.
				PITCH_WHEEL,
				
				/// A message type indicating that the current patch should be changed.
				PROGRAM_CHANGE,
				
				/// A message type indicating that a slave device should start playback from the start of a song.
				START,
				
				/// A message type indicating that a slave device should stop playback.
				STOP,
				
				/// A message type indicating that a slave device should continue playback from its current position.
				CONTINUE,
				
				/// An undefined message type.
				UNDEFINED
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default MIDI message with undefined type.
			RIM_INLINE MIDIMessage()
				:	type( UNDEFINED ),
					channel( 0 ),
					data1( 0 ),
					data2( 0 )
			{
			}
			
			
			
			
			/// Create a MIDI message with the specified type with all other data members set to 0.
			RIM_INLINE MIDIMessage( Type newType )
				:	type( newType ),
					channel( 0 ),
					data1( 0 ),
					data2( 0 )
			{
			}
			
			
			
			
			/// Create a MIDI message with the specified type, channel, and integral data member.
			RIM_INLINE MIDIMessage( Type newType, Index newChannel, UByte newData1 )
				:	type( newType ),
					channel( (UByte)newChannel ),
					data1( newData1 ),
					data2( 0 )
			{
			}
			
			
			
			
			/// Create a MIDI message with the specified type, channel, and floating point data member.
			RIM_INLINE MIDIMessage( Type newType, Index newChannel, Float newData2 )
				:	type( newType ),
					channel( (UByte)newChannel ),
					data1( 0 ),
					data2( newData2 )
			{
			}
			
			
			
			
			/// Create a MIDI message with the specified type, channel, integral data member, and floating point data member.
			RIM_INLINE MIDIMessage( Type newType, Index newChannel, UByte newData1, Float newData2 )
				:	type( newType ),
					channel( (UByte)newChannel ),
					data1( newData1 ),
					data2( newData2 )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Message Attribute Accessor Methods
			
			
			
			
			/// Return the type of this MIDI message.
			RIM_INLINE Type getType() const
			{
				return (Type)type;
			}
			
			
			
			
			/// Return the number of the channel associated with this MIDI message (if applicable).
			/**
			  * This value has no meaning if the message type is one with global effect,
			  * such as START, STOP, or CONTINUE.
			  */
			RIM_INLINE Index getChannel() const
			{
				return (Index)channel;
			}
			
			
			
			
			/// Return the integer data element for this midi message.
			/**
			  * The information carried in this first data member is dependent on the message type:
			  * - NOTE_ON: The note number which is to be turned on, ranging from 0 to 127.
			  * - NOTE_OFF: The note number which is to be turned off, ranging from 0 to 127.
			  * - CONTROL_CHANGE: The index of the control, ranging from 0 to 127.
			  * - AFTERTOUCH: The note number which should have its pressure value updated, ranging from 0 to 127.
			  * - CHANNEL_PRESSURE: Unused.
			  * - PITCH_WHEEL: Unused.
			  * - PROGRAM_CHANGE: The index of the program to select, ranging from 0 to 127.
			  * - Otherwise: The data stored in this value has no meaning and should be ignored.
			  */
			RIM_INLINE UByte getData1() const
			{
				return data1;
			}
			
			
			
			
			/// Return the floating-point data element for this midi message.
			/**
			  * The information carried in this second data member is dependent on the message type:
			  * - NOTE_ON: The velocity of the note-on message, ranging from 0 to 1, 1 being the highest velocity.
			  * - NOTE_OFF: The release velocity of the note-on message, ranging from 0 to 1, 1 being the highest velocity.
			  * - CONTROL_CHANGE: The value that the control should be set to, ranging from 0 to 1.
			  * - AFTERTOUCH: The new pressure value that the aftertouch key should have, ranging from 0 to 1.
			  * - CHANNEL_PRESSURE: The new pressure value that the midi channel should have, ranging from 0 to 1.
			  * - PITCH_WHEEL: The pitch shift amount the midi channel should have, given a value from -1 to 1.
			  * - Otherwise: The data stored in this value has no meaning and should be ignored.
			  */
			RIM_INLINE Float getData2() const
			{
				return data2;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Message-Specific Data Accessor Methods
			
			
			
			
			/// Return the note number associated with this MIDI message.
			/**
			  * The returned note number is valid only if the message type is NOTE_ON,
			  * NOTE_OFF, or AFTERTOUCH.
			  */
			RIM_INLINE UByte getNote() const
			{
				return data1;
			}
			
			
			
			
			/// Return the note velocity associated with this MIDI message.
			/**
			  * The returned note velocity is valid only if the message type is NOTE_ON or
			  * NOTE_OFF. The velocity is in the range [0,1], where 1 is the highest
			  * note velocity.
			  */
			RIM_INLINE Float getVelocity() const
			{
				return data2;
			}
			
			
			
			
			/// Return the control index associated with this MIDI message.
			/**
			  * The returned control index is valid only if the message type is CONTROL_CHANGE.
			  */
			RIM_INLINE UByte getControl() const
			{
				return data1;
			}
			
			
			
			
			/// Return the control value associated with this MIDI message.
			/**
			  * The returned value is valid only if the message type is CONTROL_CHANGE.
			  * The value is unitless and in the range [0,1].
			  */
			RIM_INLINE Float getControlValue() const
			{
				return data2;
			}
			
			
			
			
			/// Return the pressure value associated with this MIDI message.
			/**
			  * The returned pressure is valid only if the message type is AFTERTOUCH or
			  * CHANNEL_PRESSURE. The pressure is in the range [0,1].
			  */
			RIM_INLINE Float getPressure() const
			{
				return data2;
			}
			
			
			
			
			/// Return the pitch shift amount associated with this MIDI message.
			/**
			  * The returned value is valid only if the message type is PITCH_WHEEL.
			  * The pitch shift amount is unitless and in the range [-1,1]. Users
			  * should define a mapping from this range to semitones, etc.
			  */
			RIM_INLINE Float getPitch() const
			{
				return data2;
			}
			
			
			
			
			/// Return the program index associated with this MIDI message.
			/**
			  * The returned program index is valid only if the message type is PROGRAM_CHANGE.
			  */
			RIM_INLINE UByte getProgram() const
			{
				return data1;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Message Conversion Methods
			
			
			
			
			/// Parse a MIDI message object from a pointer to an array of bytes for the MIDI message.
			/**
			  * If the method succeeds, TRUE is returned and the output message parameter is
			  * set to be the parsed MIDI message. The length of the message in bytes is placed
			  * in the message length parameter.
			  *
			  * If the method fails, indicating a parse error, FALSE is returned.
			  */
			static Bool fromBytes( const UByte* bytes, MIDIMessage& message, Size& messageLengthInBytes );
			
			
			
			
			/// Convert the specified MIDIMessage object to a sequence of MIDI data stream bytes.
			/**
			  * If the method succeeds, TRUE is returned and the message data is written to the
			  * byte array pointer. The length of the message in bytes is placed in the message
			  * length parameter.
			  *
			  * The specified byte array must be at least 3 bytes long, the length of a standard
			  * (non-sysex) MIDI message.
			  *
			  * If the method fails, indicating a conversion error, FALSE is returned.
			  */
			static Bool toBytes( const MIDIMessage& message, UByte* bytes, Size& messageLengthInBytes );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum representinng the type of this midi message.
			UByte type;
			
			
			
			
			/// A byte indicating the midi channel on which the event occurred (if applicable).
			UByte channel;
			
			
			
			
			/// A byte indicating an integer data element for this midi message.
			/**
			  * The information carried in this first data member is dependent on the message type:
			  * - NOTE_ON: The note number which is to be turned on, ranging from 0 to 127.
			  * - NOTE_OFF: The note number which is to be turned off, ranging from 0 to 127.
			  * - CONTROL: The index of the control, ranging from 0 to 127.
			  * - AFTERTOUCH: The note number which should have its pressure value updated, ranging from 0 to 127.
			  * - CHANNEL_PRESSURE: Unused.
			  * - PITCH_WHEEL: Unused.
			  * - PROGRAM_CHANGE: The index of the program to select, ranging from 0 to 127.
			  * - Otherwise: The data stored in this value has no meaning and should be ignored.
			  */
			UByte data1;
			
			
			
			
			/// A floating-point data member representing secondary data for this midi message.
			/**
			  * The information carried in this second data member is dependent on the message type:
			  * - NOTE_ON: The velocity of the note-on message, ranging from 0 to 1, 1 being the highest velocity.
			  * - NOTE_OFF: The release velocity of the note-on message, ranging from 0 to 1, 1 being the highest velocity.
			  * - CONTROL: The value that the control should be set to, ranging from 0 to 1.
			  * - AFTERTOUCH: The new pressure value that the aftertouch key should have, ranging from 0 to 1.
			  * - CHANNEL_PRESSURE: The new pressure value that the midi channel should have, ranging from 0 to 1.
			  * - PITCH_WHEEL: The pitch shift amount the midi channel should have, given a value from -1 to 1.
			  * - Otherwise: The data stored in this value has no meaning and should be ignored.
			  */
			Float data2;
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_MIDI_MESSAGE_H
