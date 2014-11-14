/*
 *  rimSoundChannelType.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 8/11/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_CHANNEL_TYPE_H
#define INCLUDE_RIM_SOUND_CHANNEL_TYPE_H


#include "rimSoundUtilitiesConfig.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An enum wrapper class which specifies the semantic usage of a channel of audio.
/**
  * This class allows channels of audio to be tagged with their semantic usage.
  * Classes that process that audio can then alter their processing depending on the
  * semantic usage of the channel.
  */
class ChannelType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Type Enum Definition
			
			
			
			
			/// The underlying enum type which specifies the type of a sample of audio data.
			typedef enum Enum
			{
				//********************************************************************************
				// Standard Stereo Channel Types.
				
				
				/// The main front left channel in headphone, 2-channel, quad, and surround setups.
				LEFT = 0,
				
				/// The main front left channel in headphone, 2-channel, quad, and surround setups.
				FRONT_LEFT = LEFT,
				
				/// The main front right channel in headphone, 2-channel, quad, and surround setups.
				RIGHT = 1,
				
				/// The main front right channel in headphone, 2-channel, quad, and surround setups.
				FRONT_RIGHT = RIGHT,
				
				
				//********************************************************************************
				// Quadrophonic, 5.1, 7.1 Surround Channel Types.
				
				
				/// The front center channel in surround setups.
				CENTER = 2,
				
				/// The front center channel in surround setups.
				FRONT_CENTER = CENTER,
				
				/// A channel which carries low-frequency audio information only.
				LOW_FREQUENCY = 3,
				
				/// The left surround channel in quad and surround setups.
				SURROUND_LEFT = 4,
				
				/// The right surround channel in quad and surround setups.
				SURROUND_RIGHT = 5,
				
				/// The back left channel in 7.1 and higher surround setups.
				BACK_LEFT = 6,
				
				/// The back right channel in 7.1 and higher surround setups.
				BACK_RIGHT = 7,
				
				
				//********************************************************************************
				// Other Surround Channel Types.
				
				
				/// The channel for a speaker positioned between the center speaker and the front left speaker.
				FRONT_LEFT_OF_CENTER = 8,
				
				/// The channel for a speaker positioned between the center speaker and the front right speaker.
				FRONT_RIGHT_OF_CENTER = 9,
				
				/// The channel for a speaker positioned directly behind the listener.
				BACK_CENTER = 10,
				
				
				//********************************************************************************
				// Other Channel Types.
				
				
				/// The channel type indicating a single channel speaker.
				MONO,
				
				/// An undefined channel type - the channel is used for an unknown purpose.
				UNDEFINED
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new channel type object with the undefined channel type enum value.
			RIM_INLINE ChannelType()
				:	type( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new channel type object with the specified channel type enum value.
			RIM_INLINE ChannelType( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this channel type to an enum value.
			/**
			  * This operator is provided so that the ChannelType object can be used
			  * directly in a switch statement without the need to explicitly access
			  * the underlying enum value.
			  * 
			  * @return the enum representation of this channel type.
			  */
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Type Attribute Accessor Methods
			
			
			
			
			/// Return the cannonical channel index associated with this channel type.
			Index getChannelIndex() const;
			
			
			
			
			/// Return a 3D vector representing the cannonical direction for this channel type's speaker.
			/**
			  * The directions returned here are in the right-handed 3D coordinate system
			  * where -z is forward, +x is to the right, and +y is up. The directions returned here
			  * may not be accurate for all kinds of speaker layouts, but they at least point in the
			  * general direction where the speaker should be located.
			  */
			Vector3f getSpeakerDirection() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Get a short abbreviation for this channel type's string representation.
			String getAbbreviation() const;
			
			
			
			
			/// Return a string representation of the channel type.
			String toString() const;
			
			
			
			
			/// Return a string representing the name of this channel type.
			RIM_INLINE String getName() const
			{
				return this->toString();
			}
			
			
			
			
			/// Convert this channel type into a string representation.
			RIM_INLINE operator data::String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The underlying enum representing the type of channel for this ChannelType object.
			Enum type;
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_CHANNEL_TYPE_H
