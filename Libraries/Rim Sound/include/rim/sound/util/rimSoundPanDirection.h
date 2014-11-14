/*
 *  rimSoundPanDirection.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/11/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_PAN_DIRECTION_H
#define INCLUDE_RIM_SOUND_PAN_DIRECTION_H


#include "rimSoundUtilitiesConfig.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a generic panning direction.
/**
  * This class contains a 3D vector representing the panning direction, a
  * 'directionality' value which indicates how localized the panning direction
  * is, and a 'spread' value which indicates how spread out the panned sound field is.
  *
  * The panning direction uses coordinates where the -z axis is the forward direction,
  * the x axis points the right, and the y axis points up. Since 3D panning is not yet
  * supported, the direction is specified as a 2D vector defined as (X,Z) and contains
  * the X and Z components of a 3D direction.
  *
  * The panning directionality ranges from 0 to 1. A value of 0 indicates that the original
  * channel layout for the source audio is kept intact and the channels are merely rotated
  * around the listener by the pannning direction. A value of 1 indicates that all source
  * audio channels are to be clustered in the panning direction. Values inbetween 0 and 1
  * cause the source channels to cluster closer towards the panning direction the closer
  * the directionality gets to 1.
  *
  * The panning spread ranges from 0 to 1 and indicates how far each source audio channel
  * spreads out around the panning sphere. A value of 0 indicates that the sound
  * from each source channel should be as localized as possible, while a value of 1
  * indicates that the source channels should be spread up to +-180 degrees from the actual
  * source channel position.
  */
class PanDirection
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a panning which has a directionality and spread of 0 and direction (0,0,-1), straight ahead.
			RIM_INLINE PanDirection()
				:	direction( 0, 0, -1 ),
					directionality( 0 ),
					spread( 0 )
			{
			}
			
			
			
			
			/// Create a new panning direction with the specified direction vector, directionality, and spread factor.
			RIM_INLINE PanDirection( const Vector2f& newDirection, Float newDirectionality, Float newSpread )
				:	direction( newDirection.x, 0, newDirection.y ),
					directionality( math::clamp( newDirectionality, Float(0), Float(1) ) ),
					spread( math::clamp( newSpread, Float(0), Float(1) ) )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Direction Accessor Methods
			
			
			
			
			/// Return a reference to the 3D direction vector for this panning direction object.
			RIM_INLINE const Vector3f& getDirection() const
			{
				return direction;
			}
			
			
			
			
			/// Set the 3D direction vector for this panning direction object.
			RIM_INLINE void setDirection( const Vector3f& newDirection )
			{
				direction = newDirection;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Directionality Accessor Methods
			
			
			
			
			/// Return the directionality for this panning direction object.
			RIM_INLINE Float getDirectionality() const
			{
				return directionality;
			}
			
			
			
			
			/// Set the directionality for this panning direction object.
			/**
			  * The new directionality value is clamped to the range [0,1].
			  */
			RIM_INLINE void setDirectionality( Float newDirectionality )
			{
				directionality = math::clamp( newDirectionality, Float(0), Float(1) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Spread Accessor Methods
			
			
			
			
			/// Return the spread for this panning direction object.
			RIM_INLINE Float getSpread() const
			{
				return spread;
			}
			
			
			
			
			/// Set the spread for this panning direction object.
			/**
			  * The new spread value is clamped to the range [0,1].
			  */
			RIM_INLINE void setSpread( Float newSpread )
			{
				spread = math::clamp( newSpread, Float(0), Float(1) );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A 3D vector indicating the direction in which the sound is panned.
			Vector3f direction;
			
			
			
			
			/// A value ranging from 0 to 1 indicating how directional the panned sound should be.
			Float directionality;
			
			
			
			
			/// A value ranging from 0 to 1 indicating how spread out the panned sound should be.
			Float spread;
			
			
			
};





//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_PAN_DIRECTION_H
