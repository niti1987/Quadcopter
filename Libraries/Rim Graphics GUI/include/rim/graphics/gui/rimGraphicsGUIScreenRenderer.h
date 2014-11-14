/*
 *  rimGraphicsGUIScreenRenderer.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/15/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_SCREEN_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_GUI_SCREEN_RENDERER_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObjectRenderer.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Screen;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles drawing Screen objects to a graphics rendering context.
template <>
class GUIObjectRenderer<Screen>
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
		//******	Screen Rendering Methods
			
			
			
			
			/// Draw a screen using the specified renderer within the given object coordinate bounds.
			/**
			  * This method should be implemented by a subclass so that it draws the given
			  * screen to the specified rectangle on the screen. The size of the bounding
			  * box may not match the size of the screen being rendered, in which case the
			  * renderer should automatically scale its output to fit within the bounding box.
			  *
			  * This effect is used to produce resolution independent rendering - a higher-level
			  * system can scale the rendering of an entire GUI based on the required output resolution.
			  *
			  * The method should return whether or not the screen was able to be successfully drawn.
			  */
			virtual Bool render( GUIRenderer& renderer, const AABB2f& selfBounds, const Screen& screen ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Background Color Accessor Methods
			
			
			
			
			/// Return the background color for this screen's main area.
			virtual Color4f getBackgroundColor() const = 0;
			
			
			
			
			
			/// Set the background color for this screen's main area.
			/**
			  * The method returns whether or not the screen's background color was successfully changed.
			  */
			virtual Bool setBackgroundColor( const Color4f& newBackgroundColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a screen.
			virtual Color4f getBorderColor() const = 0;
			
			
			
			
			
			/// Set the border color used when rendering a screen.
			/**
			  * The method returns whether or not the screen border color was successfully changed.
			  */
			virtual Bool setBorderColor( const Color4f& newBorderColor ) = 0;
			
			
			
};




/// A short name for the interface of a class that draws a Screen.
typedef GUIObjectRenderer<Screen> ScreenRenderer;




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_SCREEN_RENDERER_H
