/*
 *  rimGUIInputKeyboardEvent.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 1/30/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_INPUT_KEYBOARD_EVENT_H
#define INCLUDE_RIM_GUI_INPUT_KEYBOARD_EVENT_H


#include "rimGUIInputConfig.h"


//##########################################################################################
//************************     Start Rim GUI Input Namespace     ***************************
RIM_GUI_INPUT_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Key;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates an event that occurrs whenever a key's state is changed.
class KeyboardEvent
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new keyboard event for the specified key and pressed-state.
			RIM_INLINE KeyboardEvent( const Key& newKey, Bool newIsAPress )
				:	key( newKey ),
					pressed( newIsAPress )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Event Key Accessor Methods
			
			
			
			
			/// Return a const reference to the key which this keyboard event is associated with.
			RIM_INLINE const Key& getKey() const
			{
				return key;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Event Status Accessor Methods
			
			
			
			
			/// Get whether or not the key was pressed.
			RIM_INLINE Bool isAPress() const
			{
				return pressed;
			}
			
			
			
			
			/// Get whether or not the key was released.
			RIM_INLINE Bool isARelease() const
			{
				return !pressed;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A const reference to a Key object that represents the key whose state was changed.
			const Key& key;
			
			
			
			
			/// A boolean flag indicating whether or not the keyboard event was a press or a release event.
			Bool pressed;
			
			
			
};




//##########################################################################################
//************************     End Rim GUI Input Namespace     *****************************
RIM_GUI_INPUT_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_INPUT_KEYBOARD_EVENT_H
