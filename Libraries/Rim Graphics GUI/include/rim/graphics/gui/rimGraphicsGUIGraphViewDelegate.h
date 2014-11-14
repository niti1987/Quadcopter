/*
 *  rimGraphicsGUIGraphViewDelegate.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 7/9/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_GRAPH_VIEW_DELEGATE_H
#define INCLUDE_RIM_GRAPHICS_GUI_GRAPH_VIEW_DELEGATE_H


#include "rimGraphicsGUIConfig.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class GraphView;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve GraphView events.
/**
  * Any render-view-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the button
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, a render view simply ignores it.
  */
class GraphViewDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Data Access Functions
			
			
			
			
			/// A callback function called when an attached graph view needs to update the visible data points for a series.
			/**
			  * The implementor should modify the specified list of points so that they reflect the currently
			  * visible set of points for the graph view's current visible range.
			  */
			Function<void ( GraphView& graphView, Index seriesIndex, ArrayList<Vector2f>& points )> updateSeries;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	User Input Callback Functions
			
			
			
			
			/// A function object called whenever an attached graph view receives a keyboard event.
			Function<void ( GraphView& graphView, const KeyboardEvent& keyEvent )> keyEvent;
			
			
			
			
			/// A function object called whenever an attached graph view receives a mouse-motion event.
			Function<void ( GraphView& graphView, const MouseMotionEvent& mouseMotionEvent )> mouseMotionEvent;
			
			
			
			
			/// A function object called whenever an attached graph view receives a mouse-button event.
			Function<void ( GraphView& graphView, const MouseButtonEvent& mouseButtonEvent )> mouseButtonEvent;
			
			
			
			
			/// A function object called whenever an attached graph view receives a mouse-wheel event.
			Function<void ( GraphView& graphView, const MouseWheelEvent& mouseWheelEvent )> mouseWheelEvent;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_GRAPH_VIEW_DELEGATE_H
