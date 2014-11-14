/*
 *  rimGUIButtonDelegate.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 9/25/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_BUTTON_DELEGATE_H
#define INCLUDE_RIM_GUI_BUTTON_DELEGATE_H


#include "rimGUIConfig.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Button;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve button events.
/**
  * Any button-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the GUI event thread 
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, a button simply ignores it.
  * 
  * It must be noted that the callback functions are asynchronous and
  * not thread-safe. Thus, it is necessary to perform any additional synchronization
  * externally.
  */
class ButtonDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Button Delegate Callback Functions
			
			
			
			
			/// A function object which is called whenever an attached button is selected by the user.
			/**
			  * This means that the user has put the button into its 'on' state.
			  */
			Function<void ( Button& )> select;
			
			
			
			
			/// A function object which is called whenever an attached button is pressed by the user.
			Function<void ( Button& )> press;
			
			
			
			
			/// A function object which is called whenever an attached button is released by the user.
			Function<void ( Button& )> release;
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_BUTTON_DELEGATE_H
