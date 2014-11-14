/*
 *  rimSoundChannelInfo.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/15/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_CHANNEL_INFO_H
#define INCLUDE_RIM_SOUND_CHANNEL_INFO_H


#include "rimSoundUtilitiesConfig.h"


#include "rimSoundChannelType.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which provides info about the placement and type of a channel's speaker.
class ChannelInfo
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new channel information object with undefined type and position (0,0,0).
			RIM_INLINE ChannelInfo()
				:	type( ChannelType::UNDEFINED ),
					position( 0, 0, 0 ),
					positional( false )
			{
			}
			
			
			
			
			/// Create a new channel information object with the specified type which is not positional.
			RIM_INLINE ChannelInfo( ChannelType newType )
				:	type( newType ),
					position( 0, 0, 0 ),
					positional( false )
			{
			}
			
			
			
			
			/// Create a new channel information object with the specified type and speaker position.
			RIM_INLINE ChannelInfo( ChannelType newType, const Vector2f& newPosition )
				:	type( newType ),
					position( newPosition.x, 0, newPosition.y ),
					positional( newPosition.getMagnitudeSquared() > math::epsilon<Float>() )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Type Accessor Methods
			
			
			
			
			/// Return an object representing the semantic type of this channel's speaker.
			RIM_INLINE ChannelType getType() const
			{
				return type;
			}
			
			
			
			
			/// Set the semantic type of this channel's speaker.
			RIM_INLINE void setType( ChannelType newType )
			{
				type = newType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Speaker Position Accessor Methods
			
			
			
			
			/// Return a reference to the 3D position of the channel's speaker relative to the listener.
			/**
			  * The position is specified in the right-handed coordinate system where -z
			  * is forward, +x is right, and +y is up. The distance to the speaker may
			  * optionally be encoded as the magnitude of the position vector.
			  */
			RIM_INLINE const Vector3f& getPosition() const
			{
				return position;
			}
			
			
			
			
			/// Set the 2D XZ plane position of the channel's speaker relative to the listener.
			/**
			  * The position is specified in the right-handed coordinate system where -z
			  * is forward, +x is right, and +y is up. This method is designed for dealing
			  * with 2D arrays of speakers in the horizontal plane. The value 0 is inserted
			  * for the Y component of the 3D position vector. The distance to the speaker may
			  * optionally be encoded as the magnitude of the position vector.
			  */
			RIM_INLINE void setPosition( const Vector2f& newPosition )
			{
				position = Vector3f( newPosition.x, 0, newPosition.y );
				
				positional = newPosition.getMagnitudeSquared() > math::epsilon<Float>();
			}
			
			
			
			
			
			/// Return whether or not this channel has a valid position.
			RIM_INLINE Bool getIsPositional() const
			{
				return positional;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value indicating the type of the channel.
			ChannelType type;
			
			
			
			
			/// A 3D vector indicating the position of the channel's speaker relative to the listener.
			/**
			  * The position is specified in the right-handed coordinate system where -z
			  * is forward, +x is right, and +y is up. The distance to the speaker may
			  * optionally be encoded as the magnitude of the position vector.
			  */
			Vector3f position;
			
			
			
			
			/// A boolean value indicating whether or not this channel has a valid position.
			Bool positional;
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_CHANNEL_INFO_H
