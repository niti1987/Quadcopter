/*
 *  rimGUIInputMouseWheelEvent.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 1/30/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_INPUT_MOUSE_WHEEL_EVENT_H
#define INCLUDE_RIM_GUI_INPUT_MOUSE_WHEEL_EVENT_H


#include "rimGUIInputConfig.h"


//##########################################################################################
//************************     Start Rim GUI Input Namespace     ***************************
RIM_GUI_INPUT_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An event class representing the motion of a mouse's scroll wheel input device.
/**
  * It contains the relative motion in internal units of the the mouse's
  * scroll wheel since the last mouse wheel event. Both horizontal and vertical
  * scrolling is handled by the event.
  */
class MouseWheelEvent
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new mouse wheel event with the mouse scroll wheel's relative motion.
			RIM_INLINE MouseWheelEvent( const Vector2f& newRelativeMotion )
				:	relativeMotion( newRelativeMotion )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Event Data Accessors
			
			
			
			
			/// Get the relative motion of the mouse wheel on both axes.
			RIM_INLINE const Vector2f& getRelativeMotion() const
			{
				return relativeMotion;
			}
			
			
			
			
			/// Set the relative motion of the mouse wheel on both axes.
			RIM_INLINE void setRelativeMotion( const Vector2f& newRelativeMotion )
			{
				relativeMotion = newRelativeMotion;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The relative motion of the mouse wheel since the last time it was moved.
			Vector2f relativeMotion;
			
			
			
};




//##########################################################################################
//************************     End Rim GUI Input Namespace     *****************************
RIM_GUI_INPUT_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_INPUT_MOUSE_WHEEL_EVENT_H
