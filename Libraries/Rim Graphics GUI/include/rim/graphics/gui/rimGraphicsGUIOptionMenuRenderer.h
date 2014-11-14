/*
 *  rimGraphicsGUIOptionOptionMenuRenderer.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/18/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_OPTION_MENU_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_GUI_OPTION_MENU_RENDERER_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIFonts.h"
#include "rimGraphicsGUIObjectRenderer.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class OptionMenu;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles drawing OptionMenu objects to a graphics rendering context.
template <>
class GUIObjectRenderer<OptionMenu>
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
			
			
			
			
			/// Draw a option menu using the specified renderer within the given object coordinate bounds.
			virtual Bool render( GUIRenderer& renderer, const AABB2f& selfBounds, const OptionMenu& optionMenu ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Background Color Accessor Methods
			
			
			
			
			/// Return the background color for this option menu's main area.
			virtual Color4f getBackgroundColor() const = 0;
			
			
			
			
			/// Set the background color for this option menu's main area.
			/**
			  * The method returns whether or not the option menu's background color was successfully changed.
			  */
			virtual Bool setBackgroundColor( const Color4f& newBackgroundColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a option menu.
			virtual Color4f getBorderColor() const = 0;
			
			
			
			
			/// Set the border color used when rendering a option menu.
			/**
			  * The method returns whether or not the option menu border color was successfully changed.
			  */
			virtual Bool setBorderColor( const Color4f& newBorderColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Style Accessor Methods
			
			
			
			
			/// Return a reference to the font style which is used to render the text for a option menu.
			virtual const fonts::FontStyle& getTextStyle() const = 0;
			
			
			
			
			/// Set the font style which is used to render the text for a option menu.
			/**
			  * The method returns whether or not the text's style was successfully changed.
			  */
			virtual Bool setTextStyle( const fonts::FontStyle& newTextStyle ) = 0;
			
			
			
};




/// A short name for the interface of a class that draws a OptionMenu.
typedef GUIObjectRenderer<OptionMenu> OptionMenuRenderer;




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_OPTION_MENU_RENDERER_H
