/*
 *  rimGUIInputMouseMotionEvent.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 1/30/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_INPUT_MOUSE_MOTION_EVENT_H
#define INCLUDE_RIM_GUI_INPUT_MOUSE_MOTION_EVENT_H


#include "rimGUIInputConfig.h"


//##########################################################################################
//************************     Start Rim GUI Input Namespace     ***************************
RIM_GUI_INPUT_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An event class representing the motion of a mouse input device.
/**
  * It contains the position in pixels of the the mouse at the time
  * of the event, as well as the relative motion in pixels since the last
  * mouse motion event.
  */
class MouseMotionEvent
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new mouse motion event with the mouse's position and relative motion.
			RIM_INLINE MouseMotionEvent( const Vector2f& newPosition, const Vector2f& newRelativeMotion )
				:	position( newPosition ),
					relativeMotion( newRelativeMotion )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mouse Position Accessor Methods
			
			
			
			
			/// Get the current position of the mouse in screen coordinates
			RIM_INLINE const Vector2f& getPosition() const
			{
				return position;
			}
			
			
			
			
			/// Set the current position of the mouse in screen coordinates
			RIM_INLINE void setPosition( const Vector2f& newPosition )
			{
				position = newPosition;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mouse Motion Accessor Methods
			
			
			
			
			/// Return the relative motion in pixels of the mouse.
			RIM_INLINE const Vector2f& getRelativeMotion() const
			{
				return relativeMotion;
			}
			
			
			
			
			/// Set the relative motion in pixels of the mouse.
			RIM_INLINE void setRelativeMotion( const Vector2f& newRelativeMotion )
			{
				relativeMotion = newRelativeMotion;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The current position of the mouse in screen coordinates.
			Vector2f position;
			
			
			
			
			/// The relative motion of the mouse since the last time it was moved.
			Vector2f relativeMotion;
			
			
			
};




//##########################################################################################
//************************     End Rim GUI Input Namespace     *****************************
RIM_GUI_INPUT_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_INPUT_MOUSE_MOTION_EVENT_H
