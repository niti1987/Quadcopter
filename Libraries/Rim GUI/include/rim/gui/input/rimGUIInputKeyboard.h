/*
 *  rimGUIInputKeyboard.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 2/1/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_INPUT_KEYBOARD_H
#define INCLUDE_RIM_GUI_INPUT_KEYBOARD_H


#include "rimGUIInputConfig.h"


#include "rimGUIInputKey.h"
#include "rimGUIInputKeyboardEvent.h"


//##########################################################################################
//************************     Start Rim GUI Input Namespace     ***************************
RIM_GUI_INPUT_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// This class represnts a keyboard input device.
/**
  * It keeps track of the current state of all of it's keys
  * (pressed or released). The keyboard object can be manipulated 
  * programmatically or by registering its move() and
  * changeButtonState() callback methods with an input controller which
  * dispatches real world events to connected callback methods.
  * The mouse is created with the predefined mouse buttons as defined
  * in the MouseButton class but can also be used with user-defined mouse buttons,
  * extending its flexibility.
  */
class Keyboard
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new keyboard, with all buttons in the unpressed state.
			RIM_INLINE Keyboard()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Button Accessors
			
			
			
			
			/// Get whether or not the key parameter is pressed on the keyboard.
			RIM_INLINE Bool keyIsPressed( const Key& key ) const
			{
				const Bool* isPressed;
				
				if ( keyState.find( key.getHashCode(), key, isPressed ) )
					return *isPressed;
				else
					return false;
			}
			
			
			/*
			
			/// Get whether or not the key parameter is pressed on the keyboard.
			RIM_INLINE static Bool keyIsPressed( const Key& key )
			{
				return false;
			}
			
			
			*/
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Keyboard Event Callback Methods
			
			
			
			
			/// Callback method called when a key's state is changed.
			RIM_INLINE void changeKeyState( const KeyboardEvent& keyPressEvent )
			{
				const Key& key = keyPressEvent.getKey();
				
				keyState.set( key.getHashCode(), key, keyPressEvent.isAPress() );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A hash map which maps from a key to a bool for the key's state.
			HashMap<Key,Bool> keyState;
			
			
			
			
};




//##########################################################################################
//************************     End Rim GUI Input Namespace     *****************************
RIM_GUI_INPUT_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_INPUT_KEYBOARD_H
