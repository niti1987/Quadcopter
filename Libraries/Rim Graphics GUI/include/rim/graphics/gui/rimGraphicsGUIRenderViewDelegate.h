/*
 *  rimGraphicsGUIRenderViewDelegate.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/13/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_RENDER_VIEW_DELEGATE_H
#define INCLUDE_RIM_GRAPHICS_GUI_RENDER_VIEW_DELEGATE_H


#include "rimGraphicsGUIConfig.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class RenderView;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve RenderView events.
/**
  * Any render-view-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the button
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, a render view simply ignores it.
  */
class RenderViewDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Render View Delegate Callback Functions
			
			
			
			
			/// A function object which is called whenever a render view's internal state is updated.
			/**
			  * A render view calls this method when its update() method is called, allowing
			  * the user to perform any logic updates for the specified time interval which
			  * are needed for the RenderView.
			  */
			Function<void ( RenderView& renderView, Float dt )> update;
			
			
			
			
			/// A function object which is called whenever a render view's display should update.
			/**
			  * A render view calls this method when it needs to display itself. This method
			  * is called after the render view has already drawn its border and background.
			  * The specified viewport indicates the area of the screen which should be drawn
			  * to.
			  *
			  * The delegate function should return whether or not it successfully rendered
			  * anything to the specified viewport.
			  */
			Function<Bool ( const RenderView& renderView, GUIRenderer& renderer, const Viewport& newViewport )> render;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	User Input Callback Functions
			
			
			
			
			/// A function object called whenever an attached render view receives a keyboard event.
			Function<void ( RenderView& renderView, const KeyboardEvent& keyEvent )> keyEvent;
			
			
			
			
			/// A function object called whenever an attached render view receives a mouse-motion event.
			Function<void ( RenderView& renderView, const MouseMotionEvent& mouseMotionEvent )> mouseMotionEvent;
			
			
			
			
			/// A function object called whenever an attached render view receives a mouse-button event.
			Function<void ( RenderView& renderView, const MouseButtonEvent& mouseButtonEvent )> mouseButtonEvent;
			
			
			
			
			/// A function object called whenever an attached render view receives a mouse-wheel event.
			Function<void ( RenderView& renderView, const MouseWheelEvent& mouseWheelEvent )> mouseWheelEvent;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_RENDER_VIEW_DELEGATE_H
