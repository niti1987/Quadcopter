/*
 *  rimGUIInputMouseButtonEvent.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 1/30/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_INPUT_MOUSE_BUTTON_EVENT_H
#define INCLUDE_RIM_GUI_INPUT_MOUSE_BUTTON_EVENT_H


#include "rimGUIInputConfig.h"


#include "rimGUIInputMouseButton.h"


//##########################################################################################
//************************     Start Rim GUI Input Namespace     ***************************
RIM_GUI_INPUT_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class representing a button press or release event.
/**
  * A mouse button event contains information regarding a particular mouse button
  * press or release event, such as the mouse button for the event, the new state of the
  * mouse button, and the position of the mouse when the event occurred.
  */
class MouseButtonEvent
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			/// Construct a new mouse button event with button, it's state, and position.
			RIM_INLINE MouseButtonEvent( const MouseButton& newButton, Bool newButtonIsPressed, const Vector2f& newPosition )
				:	button( newButton ),
					position( newPosition ),
					buttonIsPressed( newButtonIsPressed )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Event Button Accessor Methods
			
			
			
			
			/// Return a const reference to the MouseButton that this event relates to.
			RIM_INLINE const MouseButton& getButton() const
			{
				return button;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Event Type Accessor Methods
			
			
			
			
			/// Return whether or not the button was pressed.
			RIM_INLINE Bool isAPress() const
			{
				return buttonIsPressed;
			}
			
			
			
			
			/// Return whether or not the button was released.
			RIM_INLINE Bool isARelease() const
			{
				return !buttonIsPressed;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mouse Position Accessor Methods
			
			
			
			
			/// Return the position of the mouse when the mouse button event occurred.
			RIM_INLINE const Vector2f& getPosition() const
			{
				return position;
			}
			
			
			
			
			/// Set the position of the mouse when the mouse button event occurred.
			RIM_INLINE void setPosition( const Vector2f& newPosition )
			{
				position = newPosition;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A reference to the button this event relates to.
			const MouseButton& button;
			
			
			
			
			/// The position of the mouse when the mouse button event occurred.
			Vector2f position;
			
			
			
			
			/// Whether or not the button is in a pressed or released state.
			Bool buttonIsPressed;
			
			
			
};




//##########################################################################################
//************************     End Rim GUI Input Namespace     *****************************
RIM_GUI_INPUT_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_INPUT_MOUSE_BUTTON_EVENT_H
