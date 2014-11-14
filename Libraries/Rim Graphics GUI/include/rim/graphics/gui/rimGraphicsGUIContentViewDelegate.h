/*
 *  rimGraphicsGUIContentViewDelegate.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/15/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_CONTENT_VIEW_DELEGATE_H
#define INCLUDE_RIM_GRAPHICS_GUI_CONTENT_VIEW_DELEGATE_H


#include "rimGraphicsGUIConfig.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class ContentView;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve ContentView events.
/**
  * Any content-view-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the content view
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, a content view simply ignores it.
  */
class ContentViewDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content View Delegate Callback Functions
			
			
			
			
			/// A function object which is called whenever a content view's internal state is updated.
			/**
			  * A content view calls this method when its update() method is called, allowing
			  * the user to perform any logic updates for the specified time interval which
			  * are needed for the content view.
			  */
			Function<void ( ContentView& contentView, Float dt )> update;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	User Input Callback Functions
			
			
			
			
			/// A function object called whenever an attached content view receives a keyboard event.
			Function<void ( ContentView& contentView, const KeyboardEvent& keyEvent )> keyEvent;
			
			
			
			
			/// A function object called whenever an attached content view receives a mouse-motion event.
			Function<void ( ContentView& contentView, const MouseMotionEvent& mouseMotionEvent )> mouseMotionEvent;
			
			
			
			
			/// A function object called whenever an attached content view receives a mouse-button event.
			Function<void ( ContentView& contentView, const MouseButtonEvent& mouseButtonEvent )> mouseButtonEvent;
			
			
			
			
			/// A function object called whenever an attached content view receives a mouse-wheel event.
			Function<void ( ContentView& contentView, const MouseWheelEvent& mouseWheelEvent )> mouseWheelEvent;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_CONTENT_VIEW_DELEGATE_H
