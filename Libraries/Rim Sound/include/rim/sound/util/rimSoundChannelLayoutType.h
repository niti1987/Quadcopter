/*
 *  rimSoundChannelLayoutType.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/18/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_CHANNEL_LAYOUT_TYPE_H
#define INCLUDE_RIM_SOUND_CHANNEL_LAYOUT_TYPE_H


#include "rimSoundUtilitiesConfig.h"


#include "rimSoundChannelLayout.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An enum wrapper class which specifies various predefined types of channel layouts.
/**
  * See the ChannelLayout::Type declaration for more information on the predefined layout types.
  */
class ChannelLayoutType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new channel layout type object with the undefined channel layout type enum value.
			RIM_INLINE ChannelLayoutType()
				:	type( ChannelLayout::UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new channel layout type object with the specified channel layout type enum value.
			RIM_INLINE ChannelLayoutType( ChannelLayout::Type newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this channel layout type to an enum value.
			/**
			  * This operator is provided so that the ChannelLayoutType object can be used
			  * directly in a switch statement without the need to explicitly access
			  * the underlying enum value.
			  * 
			  * @return the enum representation of this channel layout type.
			  */
			RIM_INLINE operator ChannelLayout::Type () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the channel layout type.
			data::String toString() const;
			
			
			
			
			/// Return a string representing the name of this channel layout type.
			RIM_INLINE data::String getName() const
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
			
			
			
			
			/// The underlying enum representing the type of layout for this ChannelLayoutType object.
			ChannelLayout::Type type;
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_CHANNEL_LAYOUT_TYPE_H
