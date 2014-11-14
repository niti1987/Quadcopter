/*
 *  rimSoundMIDITime.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 6/5/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_MIDI_TIME_H
#define INCLUDE_RIM_SOUND_MIDI_TIME_H


#include "rimSoundUtilitiesConfig.h"


#include "rimSoundTimeSignature.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a musical position within a MIDI sequence.
/**
  * This position is used for MIDI playback and sequencing, as well as synchronizing
  * audio effects with MIDI data.
  *
  * The MIDI time is represented by a tempo, measure index, time signature, and
  * fractional number of beats since the beginning of the measure.
  */
class MIDITime
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default MIDI time object with the default tempo of 120 quarter notes per minute.
			RIM_INLINE MIDITime()
				:	tempo( 120.0f ),
					beat( 0.0f ),
					measure( 0 ),
					timeSignature()
			{
			}
			
			
			
			
			/// Create a new MIDI Time object with the specified tempo, measure index, beat number, and time signature.
			RIM_INLINE MIDITime( Float newTempo, Index newMeasure, Float newBeat, TimeSignature newTimeSignature )
				:	tempo( newTempo ),
					beat( newBeat ),
					measure( (UByte)newMeasure ),
					timeSignature( newTimeSignature )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Tempo Accessor Methods
			
			
			
			
			/// Return the number of quarter notes per minutes for the current position in the MIDI sequence.
			/**
			  * This value can be used to convert the beat value into a time in seconds.
			  */
			RIM_INLINE Float getTempo() const
			{
				return tempo;
			}
			
			
			
			
			
			/// Return the number of quarter notes per minutes for the current position in the MIDI sequence.
			/**
			  * This value can be used to convert the beat value into a time in seconds.
			  *
			  * The new tempo is clamped to be greater than or equal to 0.
			  */
			RIM_INLINE void setTempo( Float newTempo )
			{
				tempo = math::max( newTempo, Float(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Measure Accessor Methods
			
			
			
			
			/// The index of the current measure within the MIDI sequence.
			/**
			  * This value should not be used to compute the current time position
			  * within the MIDI sequence (along with the time signature and tempo), because
			  * the time signature and tempo may change throughout a given sequence, making
			  * a simple computation of the current time impossible given only the measure
			  * index.
			  */
			RIM_INLINE Index getMeasure() const
			{
				return (Index)measure;
			}
			
			
			
			
			/// Set the index of the current measure within the MIDI sequence.
			/**
			  * This value should not be used to compute the current time position
			  * within the MIDI sequence (along with the time signature and tempo), because
			  * the time signature and tempo may change throughout a given sequence, making
			  * a simple computation of the current time impossible given only the measure
			  * index.
			  */
			RIM_INLINE void setMeasure( Index newMeasure )
			{
				measure = (UByte)newMeasure;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Beat Accessor Methods
			
			
			
			
			/// Return the fractional number of time signature beats since the beginning of the measure.
			/**
			  * This value is represented in units of the time signature,
			  * so if the time signature is 6/8, the beat value can be in the
			  * range from 0 to 5.99999 and indicates the number of eigth notes
			  * since the start of the measure.
			  */
			RIM_INLINE Float getBeat() const
			{
				return beat;
			}
			
			
			
			
			/// Set the fractional number of time signature beats since the beginning of the measure.
			/**
			  * This value is represented in units of the time signature,
			  * so if the time signature is 6/8, the beat value can be in the
			  * range from 0 to 5.99999 and indicates the number of eigth notes
			  * since the start of the measure.
			  *
			  * The new beat value is clamped to be greater than 0.
			  */
			RIM_INLINE void setBeat( Float newBeat )
			{
				beat = math::max( newBeat, Float(0) );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The number of quarter notes per minute for the current position in the MIDI sequence.
			Float tempo;
			
			
			
			
			/// The fractional number of time signature beats since the beginning of the measure.
			/**
			  * This value is represented in units of the time signature,
			  * so if the time signature is 6/8, the beat value can be in the
			  * range from 0 to 5.99999 and indicates the number of eigth notes
			  * since the start of the measure.
			  */
			Float beat;
			
			
			
			
			/// The index of the current measure within the MIDI sequence.
			UInt32 measure;
			
			
			
			
			/// The time signature for the current measure.
			TimeSignature timeSignature;
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_MIDI_TIME_H
