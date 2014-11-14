/*
 *  rimGraphicsGUIButtonDelegate.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/5/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_BUTTON_DELEGATE_H
#define INCLUDE_RIM_GRAPHICS_GUI_BUTTON_DELEGATE_H


#include "rimGraphicsGUIConfig.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Button;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve button events.
/**
  * Any button-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the button
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, a button simply ignores it.
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
			
			
			
			
			/// A function object which is called whenever an attached button is unselected by the user.
			/**
			  * This means that the user has put the button into its 'off' state.
			  */
			Function<void ( Button& )> unselect;
			
			
			
			
			/// A function object which is called whenever an attached button is pressed by the user.
			Function<void ( Button& )> press;
			
			
			
			
			/// A function object which is called whenever an attached button is released by the user.
			Function<void ( Button& )> release;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_BUTTON_DELEGATE_H
