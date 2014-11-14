/*
 *  rimGUIElementWindowDelegate.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 6/2/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_ELEMENT_WINDOW_DELEGATE_H
#define INCLUDE_RIM_GUI_ELEMENT_WINDOW_DELEGATE_H


#include "rimGUIConfig.h"


#include "rimGUIInput.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Window;



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve window events.
/**
  * Any window-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the GUI event thread 
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, a window simply ignores it.
  * 
  * It must be noted that the callback functions are asynchronous and
  * not thread-safe. Thus, it is necessary to perform any additional synchronization
  * externally.
  */
class WindowDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Visibility Callback Functions
			
			
			
			
			/// A function object which is called whenever an attached window is made visible programmatically.
			/**
			  * The delegate function may choose to return either a value of TRUE, indicating
			  * that the open operation is allowed, or a value of FALSE, indicating that the
			  * open operation should be ignored.
			  */
			Function<Bool ( Window& )> open;
			
			
			
			
			/// A function object which is called whenever an attached window attempts to be closed.
			/**
			  * The delegate function may choose to return either a value of TRUE, indicating
			  * that the close operation is allowed, or a value of FALSE, indicating that the
			  * close operation should be ignored.
			  */
			Function<Bool ( Window& )> close;
			
			
			
			
			/// A function object which is called whenever an attached window gains or loses focus.
			/**
			  * The boolean parameter indicates whether or not the window now has focus. A value
			  * of TRUE indicates that the window just gained focus. A value of FALSE indicates
			  * that the window just lost focus.
			  */
			Function<void ( Window&, Bool )> setFocus;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sizing Callback Functions
			
			
			
			/// A function object which is called whenever an attached window is resized programmatically.
			/**
			  * The delegate function may choose to return either a value of TRUE, indicating
			  * that the change in size is allowed, or a value of FALSE, indicating that the
			  * change in size should be ignored.
			  * 
			  * The window provides the desired new size of the window as a (width, height) pair.
			  */
			Function<Bool ( Window&, const Size2D& )> resize;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Positioning Callback Functions
			
			
			
			
			/// A function object which is called whenever an attached window is moved programmatically.
			/**
			  * The delegate function may choose to return either a value of TRUE, indicating
			  * that the change in position is allowed, or a value of FALSE, indicating that the
			  * change in position should be ignored.
			  * 
			  * The window provides the desired new position of the window as a 2D vector.
			  */
			Function<Bool ( Window&, const Vector2i& )> move;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	User Input Callback Functions
			
			
			
			
			/// A function object called whenever an attached window receives a keyboard event.
			Function<void ( Window&, const input::KeyboardEvent& )> keyEvent;
			
			
			
			
			/// A function object called whenever an attached window receives a mouse-motion event.
			Function<void ( Window&, const input::MouseMotionEvent& )> mouseMotionEvent;
			
			
			
			
			/// A function object called whenever an attached window receives a mouse-button event.
			Function<void ( Window&, const input::MouseButtonEvent& )> mouseButtonEvent;
			
			
			
			
			/// A function object called whenever an attached window receives a mouse-wheel event.
			Function<void ( Window&, const input::MouseWheelEvent& )> mouseWheelEvent;
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_ELEMENT_WINDOW_DELEGATE_H
