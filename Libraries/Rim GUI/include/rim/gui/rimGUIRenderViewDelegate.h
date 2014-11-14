/*
 *  rimGUIRenderViewDelegate.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 3/1/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_RENDER_VIEW_DELEGATE_H
#define INCLUDE_RIM_GUI_RENDER_VIEW_DELEGATE_H


#include "rimGUIConfig.h"


#include "rimGUIInput.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class RenderView;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve RenderView events.
/**
  * Any RenderView-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the GUI event thread 
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, the RenderView simply ignores it and doesn't call the function.
  * 
  * It must be noted that the callback functions are asynchronous and
  * not thread-safe. Thus, it is necessary to perform any additional synchronization
  * externally.
  */
class RenderViewDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sizing Callback Functions
			
			
			
			/// A function object which is called whenever an attached RenderView is resized.
			/**
			  * The delegate function may choose to return either a value of TRUE, indicating
			  * that the change in size is allowed, or a value of FALSE, indicating that the
			  * change in size should be ignored.
			  * 
			  * The RenderView provides the desired new size of the view as a (width, height) pair.
			  */
			Function<Bool ( RenderView&, const Size2D& )> resize;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Positioning Callback Functions
			
			
			
			
			/// A function object which is called whenever an attached RenderView is moved.
			/**
			  * The delegate function may choose to return either a value of TRUE, indicating
			  * that the change in position is allowed, or a value of FALSE, indicating that the
			  * change in position should be ignored.
			  * 
			  * The RenderView provides the desired new position of the view as a 2D vector.
			  */
			Function<Bool ( RenderView&, const Vector2i& )> move;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	User Input Callback Functions
			
			
			
			
			/// A function object called whenever an attached render view receives a keyboard event.
			Function<void ( RenderView&, const input::KeyboardEvent& )> keyEvent;
			
			
			
			
			/// A function object called whenever an attached render view receives a mouse-motion event.
			Function<void ( RenderView&, const input::MouseMotionEvent& )> mouseMotionEvent;
			
			
			
			
			/// A function object called whenever an attached render view receives a mouse-button event.
			Function<void ( RenderView&, const input::MouseButtonEvent& )> mouseButtonEvent;
			
			
			
			
			/// A function object called whenever an attached render view receives a mouse-wheel event.
			Function<void ( RenderView&, const input::MouseWheelEvent& )> mouseWheelEvent;
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_RENDER_VIEW_DELEGATE_H
