/*
 *  rimGraphicsGUIGraphViewRenderer.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 7/9/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_GRAPH_VIEW_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_GUI_GRAPH_VIEW_RENDERER_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObjectRenderer.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class GraphView;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles drawing GraphView objects to a graphics rendering context.
template <>
class GUIObjectRenderer<GraphView>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Virtual Destructor Declaration
			
			
			
			
			/// Destroy this GUI object renderer, releasing all of its internal state.
			virtual ~GUIObjectRenderer()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content View Rendering Methods
			
			
			
			
			/// Draw a graph view using the specified renderer within the given object coordinate bounds.
			virtual Bool render( GUIRenderer& renderer, const AABB2f& selfBounds, const GraphView& graphView ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Background Color Accessor Methods
			
			
			
			
			/// Return the background color for this graph view's main area.
			virtual Color4f getBackgroundColor() const = 0;
			
			
			
			
			
			/// Set the background color for this graph view's main area.
			/**
			  * The method returns whether or not the graph view's background color was successfully changed.
			  */
			virtual Bool setBackgroundColor( const Color4f& newBackgroundColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a graph view.
			virtual Color4f getBorderColor() const = 0;
			
			
			
			
			
			/// Set the border color used when rendering a graph view.
			/**
			  * The method returns whether or not the graph view border color was successfully changed.
			  */
			virtual Bool setBorderColor( const Color4f& newBorderColor ) = 0;
			
			
			
};




/// A short name for the interface of a class that draws a GraphView.
typedef GUIObjectRenderer<GraphView> GraphViewRenderer;




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_GRAPH_VIEW_RENDERER_H
