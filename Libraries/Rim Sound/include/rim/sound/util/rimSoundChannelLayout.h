/*
 *  rimSoundChannelLayout.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/13/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_CHANNEL_LAYOUT_H
#define INCLUDE_RIM_SOUND_CHANNEL_LAYOUT_H


#include "rimSoundUtilitiesConfig.h"


#include "rimSoundChannelInfo.h"
#include "rimSoundGain.h"
#include "rimSoundPanDirection.h"
#include "rimSoundChannelMixMatrix.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies the configuration and usage of a set of channels of audio.
/**
  * A ChannelLayout object contains a enum value indicating the type of the layout.
  * This value either indicates a predefined layout type for standard channel
  * layout formats, or a custom or undefined layout. A custom layout indicates that
  * a custom SpeakerLayout has been defined and is stored by the ChannelLayout object.
  *
  * For standard layout types, no SpeakerLayout is allocated, the ChannelLayout uses
  * a predefined static layout object instead and only copies the predefined layout
  * if the user attempts to modify the speaker layout.
  */
class ChannelLayout
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Layout Type Enum Declaration
			
			
			
			
			/// An enum which is used to specify various pre-defined types of channel layouts.
			typedef enum Type
			{
				/// An enum value describing a ChannelLayout with only one speaker.
				MONO,
				
				/// An enum value describing a ChannelLayout for a basic stereo speaker system.
				/**
				  * The left and right speakers are placed 90 degrees left and right of front center.
				  * This doesn't correspond to the actual placement of stereo speakers but it is used
				  * to provide proper panning - stereo speakers at the normal placement  of 30 degrees off
				  * center axis wouldn't produce as wide of a stereo image.
				  * Another benefit is that this corresponds to headphone positioning, where it will produce
				  * realistic panning.
				  */
				STEREO,
				
				/// An enum value describing a ChannelLayout for a 4 channel quadraphonic speaker system.
				/**
				  * Front left and right speakers are placed 30 degrees off of front center. Back left
				  * and right speakers are placed 95 degrees off of front center.
				  */
				QUAD,
				
				/// An alias for the QUAD speaker configuration.
				SURROUND_4 = QUAD,
				
				/// An enum value describing a ChannelLayout for a 5.1 surround speaker system.
				/**
				  * Front left and right speakers are placed 30 degrees off of front center. Back left
				  * and right speakers are placed 110 degrees off of front center. The low frequency
				  * channel's positioning is undefined.
				  */
				SURROUND_5_1,
				
				/// An enum value describing a ChannelLayout for a 7.1 surround speaker system.
				/**
				  * Front left and right speakers are placed 30 degrees off of front center. Back left
				  * and right speakers are placed 135 degrees off of front center. Side left and right
				  * speakers are placed 90 degrees off of front center. The low frequency channel's
				  * positioning is undefined.
				  */
				SURROUND_7_1,
				
				/// An enum value indicating a custom channel layout.
				CUSTOM,
				
				/// An enum value indicating a binaural HRTF-based output format.
				HRTF,
				
				/// An enum value indicating an undefined type of channel layout.
				UNDEFINED
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default channel layout with no channels.
			RIM_INLINE ChannelLayout()
				:	channels( NULL ),
					numChannels( 0 ),
					channelCapacity( 0 ),
					speakerAngles( NULL ),
					numSpeakerAngles( 0 ),
					speakerAngleCapacity( 0 ),
					speakerAnglesNeedUpdate( false )
			{
			}
			
			
			
			
			/// Create a new channel layout with the specified number of channels.
			/**
			  * All channels in the layout are initialized to have the ChannelType::UNDEFINED
			  * type and are non-positional.
			  */
			ChannelLayout( Size newNumChannels );
			
			
			
			
			/// Create a ChannelLayout object which has the specified predefined layout type.
			/**
			  * The predefined layout type is used to determine the type and number of
			  * channels that should be in the layout.
			  */
			ChannelLayout( Type newType );
			
			
			
			
			/// Create a copy of the specified ChannelLayout object.
			ChannelLayout( const ChannelLayout& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy all state used by a ChannelLayout object.
			~ChannelLayout();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of one ChannelLayout to this object.
			ChannelLayout& operator = ( const ChannelLayout& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Count Accessor Methods
			
			
			
			
			/// Return the total number of channels that are part of this channel layout.
			RIM_INLINE Size getChannelCount() const
			{
				return numChannels;
			}
			
			
			
			
			/// Set the total number of channels that are part of this channel layout.
			/**
			  * If increasing the size of the layout, the new channels are initialized to
			  * have the ChannelType::UNDEFINED type and to be non-positional. If decreasing
			  * the size, the extra channels are just removed.
			  */
			void setChannelCount( Size newNumChannels );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Information Accessor Methods
			
			
			
			
			/// Return a reference to the channel information object describing the channel at the given index.
			/**
			  * If the given channel index is invalid, a reference to a placeholder undefined
			  * channel is returned.
			  */
			RIM_INLINE const ChannelInfo& getChannelInfo( Index channelIndex ) const
			{
				if ( channelIndex < numChannels )
					return channels[channelIndex];
				else
					return UNDEFINED_CHANNEL;
			}
			
			
			
			
			/// Set the information about the channel at the specified index in this layout.
			/**
			  * This method completely replaces the previous state of the channel at
			  * the given index. If the channel index is invalid, the method has no effect.
			  */
			void setChannelInfo( Index channelIndex, const ChannelInfo& newInfo );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Type Accessor Methods
			
			
			
			
			/// Return an object representing the semantic type of the channel at the specified index.
			/**
			  * If the given channel index is invalid, the ChannelType::UNDEFINED type is
			  * returned.
			  */
			RIM_INLINE ChannelType getChannelType( Index channelIndex ) const
			{
				if ( channelIndex < numChannels )
					return channels[channelIndex].getType();
				else
					return ChannelType::UNDEFINED;
			}
			
			
			
			
			/// Set the semantic type of the channel at the specified index.
			/**
			  * If the given channel index is invalid, the method has no effect.
			  */
			RIM_INLINE void setChannelType( Index channelIndex, ChannelType newType )
			{
				if ( channelIndex < numChannels )
					return channels[channelIndex].setType( newType );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Position Accessor Methods
			
			
			
			
			/// Return a reference to the channel position at the specified index.
			/**
			  * If the channel index is invalid or if the speaker is not positional,
			  * the vector (0,0,0) is returned.
			  */
			RIM_INLINE const Vector3f& getChannelPosition( Index channelIndex ) const
			{
				if ( channelIndex < numChannels )
					return channels[channelIndex].getPosition();
				else
					return UNDEFINED_CHANNEL.getPosition();
			}
			
			
			
			
			/// Set the position of the channel's speaker at the specified index.
			void setChannelPosition( Index channelIndex, const Vector2f& newPosition );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Spatialization Methods
			
			
			
			
			/// Get the channel gain coefficients for a sound source in the specified direction.
			/**
			  * This method uses a vector-based amplitude panning implementation to determine
			  * the speakers that are located nearest to the specified 3D direction. It then computes
			  * the gain coefficients for each of those speakers that will localize a sound
			  * source in the given direction. Those linear gain coefficients are placed in
			  * the output array of channel gains. The output array may be enlarged if necessary
			  * to hold all of this speaker layout's channels.
			  *
			  * The method returns TRUE if it succeeds and FALSE if there was an error.
			  * This can happen if the layout has no speakers.
			  */
			Bool panDirection( const Vector3f& direction, Array<Gain>& channelGains ) const;
			
			
			
			
			/// Get a channel mix matrix which maps the specified speaker layout to this one.
			/**
			  * This method determines the best mapping from the specified arbitrary speaker
			  * layout to this speaker layout. The method returns TRUE if a mapping was found and FALSE if
			  * no mapping was found between the layouts. This can happen if either layout
			  * has no speakers.
			  */
			Bool mapLayout( const ChannelLayout& layout, ChannelMixMatrix& mixMatrix ) const;
			
			
			
			
			/// Get a channel mix matrix which maps the specified speaker layout to this one using the specified panning.
			/**
			  * This method determines the best mapping from the specified arbitrary speaker
			  * layout to this speaker layout when the original layout is panned in the specified
			  * direction. The method returns TRUE if a mapping was found and FALSE if
			  * no mapping was found between the layouts. This can happen if either layout
			  * has no speakers.
			  */
			Bool panLayout( const ChannelLayout& layout, const PanDirection& pan,
							ChannelMixMatrix& mixMatrix ) const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Speaker Class Definition
			
			
			
			
			/// A class which stores the angle of a single speaker within a speaker layout.
			class SpeakerAngle
			{
				public:
					
					/// Create a new speaker angle object with the specified channel index and angle.
					RIM_INLINE SpeakerAngle( Index newChannelIndex, Float newAngle )
						:	channelIndex( newChannelIndex ),
							angle( newAngle )
					{
					}
					
					
					/// The index of this speaker's channel within the channel layout.
					Index channelIndex;
					
					
					/// The angle within the XZ plane relative to the origin where this speaker is located.
					Float angle;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Panning Helper Methods
			
			
			
			
			/// Compute the angle within the XZ plane of the specified position, relative to the origin.
			RIM_INLINE static Float getAngle( const Vector3f& position )
			{
				Float angle = math::atan2( -position.z, position.x ) - Float(0.5)*math::pi<Float>();
				
				// Make sure the angle is between 0 and 2*pi.
				if ( angle < Float(0) )
					angle += Float(2)*math::pi<Float>();
				
				return angle;
			}
			
			
			
			
			/// Find the speaker pair that the specified angle lies between and compute the panning gains.
			RIM_FORCE_INLINE Bool panAngle( Float angle, Index& channelIndex1, Index& channelIndex2,
											Float& gain1, Float& gain2 ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Speaker Angle Update Helper Methods
			
			
			
			
			/// Return an integer which indicates the value of a comparison of two SpeakerAngle objects.
			RIM_INLINE static int compareSpeakerAngles( const void* a, const void* b )
			{
				SpeakerAngle* speaker1 = (SpeakerAngle*)a;
				SpeakerAngle* speaker2 = (SpeakerAngle*)b;
				
				if ( speaker1->angle == speaker2->angle )
					return 0;
				else if ( speaker1->angle < speaker2->angle )
					return -1;
				else
					return 1;
			}
			
			
			
			
			/// Update and sort the speaker angles so that the speaker angles are in order from 0 to 2*pi.
			RIM_INLINE void updateSpeakerAngles() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// A static ChannelInfo object which is used to refer to an undefined channel.
			/**
			  * Declaring this here allows the channel layout to always return a reference
			  * to channel positions, etc even when invalid arguments are provided.
			  */
			static const ChannelInfo UNDEFINED_CHANNEL;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An array of information about the channels in this channel layout.
			ChannelInfo* channels;
			
			
			
			
			/// The total number of valid channels in this channel layout.
			Size numChannels;
			
			
			
			
			/// The capacity of the channel info array.
			Size channelCapacity;
			
			
			
			
			/// A pointer to an array of speaker angles which correspond to the positioned channels of this layout.
			mutable SpeakerAngle* speakerAngles;
			
			
			
			
			/// The total number of valid entries in the speaker angle array.
			mutable Size numSpeakerAngles;
			
			
			
			
			/// The capacity of the speaker angle array.
			mutable Size speakerAngleCapacity;
			
			
			
			
			/// A boolean value which acts as a dirty bit to determine when the speaker angle data needs to be updated.
			mutable Bool speakerAnglesNeedUpdate;
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_CHANNEL_LAYOUT_H
