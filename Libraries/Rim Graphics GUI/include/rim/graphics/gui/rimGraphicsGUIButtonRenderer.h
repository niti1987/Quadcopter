/*
 *  rimGraphicsGUIButtonRenderer.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/29/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_BUTTON_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_GUI_BUTTON_RENDERER_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObjectRenderer.h"
#include "rimGraphicsGUIFonts.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Button;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles drawing Button objects to a graphics rendering context.
template <>
class GUIObjectRenderer<Button>
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
			virtual Bool render( GUIRenderer& renderer, const AABB2f& parentBounds, const Button& object ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Background Color Accessor Methods
			
			
			
			
			/// Return the background color for this button's main area.
			virtual Color4f getBackgroundColor() const = 0;
			
			
			
			
			/// Set the background color for this button's main area.
			/**
			  * The method returns whether or not the buttons's background color was successfully changed.
			  */
			virtual Bool setBackgroundColor( const Color4f& newBackgroundColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a button.
			virtual Color4f getBorderColor() const = 0;
			
			
			
			
			/// Set the border color used when rendering a button.
			/**
			  * The method returns whether or not the button border color was successfully changed.
			  */
			virtual Bool setBorderColor( const Color4f& newBorderColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Alternate Color Accessor Methods
			
			
			
			
			/// Return the alternate color for this button's main area.
			/**
			  * This is the color of the button when it is pressed.
			  */
			virtual Color4f getAlternateColor() const = 0;
			
			
			
			
			/// Set the alternate color for this button's main area.
			/**
			  * This is the color of the button when it is pressed.
			  *
			  * The method returns whether or not the buttons's alternate color was successfully changed.
			  */
			virtual Bool setAlternateColor( const Color4f& newAlternateColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Style Accessor Methods
			
			
			
			
			/// Return a reference to the font style which is used to render the text label for a button.
			virtual const fonts::FontStyle& getTextStyle() const = 0;
			
			
			
			
			/// Set the font style which is used to render the text label for a button.
			/**
			  * The method returns whether or not the text's style was successfully changed.
			  */
			virtual Bool setTextStyle( const fonts::FontStyle& newTextStyle ) = 0;
			
			
			
};




/// A short name for the interface of a class that draws a Button.
typedef GUIObjectRenderer<Button> ButtonRenderer;




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_BUTTON_RENDERER_H
