/*
 *  rimGraphicsGUIScreenDelegate.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/15/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_SCREEN_DELEGATE_H
#define INCLUDE_RIM_GRAPHICS_GUI_SCREEN_DELEGATE_H


#include "rimGraphicsGUIConfig.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Screen;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve Screen events.
/**
  * Any screen-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the screen
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, the screen simply ignores it.
  */
class ScreenDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Screen Delegate Callback Functions
			
			
			
			
			/// A function object which is called whenever a screen's internal state is updated.
			/**
			  * A screen calls this method when its update() method is called, allowing
			  * the user to perform any logic updates for the specified time interval which
			  * are needed for the screen.
			  */
			Function<void ( Screen& screen, Float dt )> update;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	User Input Callback Functions
			
			
			
			
			/// A function object called whenever an attached screen receives a keyboard event.
			Function<void ( Screen& screen, const KeyboardEvent& keyEvent )> keyEvent;
			
			
			
			
			/// A function object called whenever an attached screen receives a mouse-motion event.
			Function<void ( Screen& screen, const MouseMotionEvent& mouseMotionEvent )> mouseMotionEvent;
			
			
			
			
			/// A function object called whenever an attached screen receives a mouse-button event.
			Function<void ( Screen& screen, const MouseButtonEvent& mouseButtonEvent )> mouseButtonEvent;
			
			
			
			
			/// A function object called whenever an attached screen receives a mouse-wheel event.
			Function<void ( Screen& screen, const MouseWheelEvent& mouseWheelEvent )> mouseWheelEvent;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_SCREEN_DELEGATE_H
