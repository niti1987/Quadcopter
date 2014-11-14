/*
 *  rimGraphicsGUITextFieldRenderer.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/29/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_TEXT_FIELD_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_GUI_TEXT_FIELD_RENDERER_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObjectRenderer.h"
#include "rimGraphicsGUIFonts.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class TextField;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles drawing TextField objects to a graphics rendering context.
template <>
class GUIObjectRenderer<TextField>
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
			virtual Bool render( GUIRenderer& renderer, const AABB2f& parentBounds, const TextField& object ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Background Color Accessor Methods
			
			
			
			
			/// Return the background color for this text field's text area.
			virtual Color4f getBackgroundColor() const = 0;
			
			
			
			
			
			/// Set the background color for this text field's text area.
			/**
			  * The method returns whether or not the text field's background color was successfully changed.
			  */
			virtual Bool setBackgroundColor( const Color4f& newBackgroundColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color for a text field.
			virtual Color4f getBorderColor() const = 0;
			
			
			
			
			
			/// Set the border color for a text field.
			/**
			  * The method returns whether or not the text field's border color was successfully changed.
			  */
			virtual Bool setBorderColor( const Color4f& newBorderColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Style Accessor Methods
			
			
			
			
			/// Return a reference to the font style which is used to render the text for a text field.
			virtual const fonts::FontStyle& getTextStyle() const = 0;
			
			
			
			
			/// Set the font style which is used to render the text for a text field.
			/**
			  * The method returns whether or not the text's style was successfully changed.
			  */
			virtual Bool setTextStyle( const fonts::FontStyle& newTextStyle ) = 0;
			
			
			
};




/// A short name for the interface of a class that draws a TextField.
typedef GUIObjectRenderer<TextField> TextFieldRenderer;




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_TEXT_FIELD_RENDERER_H
