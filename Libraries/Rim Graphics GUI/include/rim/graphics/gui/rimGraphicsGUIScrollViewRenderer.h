/*
 *  rimGraphicsGUIScrollViewRenderer.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/11/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_SCROLL_VIEW_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_GUI_SCROLL_VIEW_RENDERER_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObjectRenderer.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class ScrollView;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles drawing ScrollView objects to a graphics rendering context.
template <>
class GUIObjectRenderer<ScrollView>
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
		//******	Object Rendering Methods
			
			
			
			
			/// Draw an object using the specified renderer within the given parent coordinate bounds.
			/**
			  * The method returns whether or not the object was able to be successfully drawn.
			  */
			virtual Bool render( GUIRenderer& renderer, const AABB2f& parentBounds, const ScrollView& scrollView ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Background Color Accessor Methods
			
			
			
			
			/// Return the background color for this scroll view's main area.
			virtual Color4f getBackgroundColor() const = 0;
			
			
			
			
			
			/// Set the background color for this scroll view's main area.
			/**
			  * The method returns whether or not the scroll view's background color was successfully changed.
			  */
			virtual Bool setBackgroundColor( const Color4f& newBackgroundColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a scroll view.
			virtual Color4f getBorderColor() const = 0;
			
			
			
			
			
			/// Set the border color used when rendering a scroll view.
			/**
			  * The method returns whether or not the scroll view border color was successfully changed.
			  */
			virtual Bool setBorderColor( const Color4f& newBorderColor ) = 0;
			
			
			
};




/// A short name for the interface of a class that draws a ScrollView.
typedef GUIObjectRenderer<ScrollView> ScrollViewRenderer;




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_SCROLL_VIEW_RENDERER_H
