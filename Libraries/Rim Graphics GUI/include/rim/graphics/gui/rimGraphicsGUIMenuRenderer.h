/*
 *  rimGraphicsGUIMenuRenderer.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/18/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_MENU_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_GUI_MENU_RENDERER_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIFonts.h"
#include "rimGraphicsGUIObjectRenderer.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Menu;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles drawing Menu objects to a graphics rendering context.
template <>
class GUIObjectRenderer<Menu>
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
			
			
			
			
			/// Draw a menu using the specified renderer within the given object coordinate bounds.
			virtual Bool render( GUIRenderer& renderer, const AABB2f& selfBounds, const Menu& menu ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Background Color Accessor Methods
			
			
			
			
			/// Return the background color for this menu's main area.
			virtual Color4f getBackgroundColor() const = 0;
			
			
			
			
			/// Set the background color for this menu's main area.
			/**
			  * The method returns whether or not the menu's background color was successfully changed.
			  */
			virtual Bool setBackgroundColor( const Color4f& newBackgroundColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a menu.
			virtual Color4f getBorderColor() const = 0;
			
			
			
			
			/// Set the border color used when rendering a menu.
			/**
			  * The method returns whether or not the menu border color was successfully changed.
			  */
			virtual Bool setBorderColor( const Color4f& newBorderColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Separator Color Accessor Methods
			
			
			
			
			/// Return the color used when rendering a menu item separator.
			virtual Color4f getSeparatorColor() const = 0;
			
			
			
			
			/// Set the color used when rendering a menu item separator.
			/**
			  * The method returns whether or not the menu separator color was successfully changed.
			  */
			virtual Bool setSeparatorColor( const Color4f& newSeparatorColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Separator Color Accessor Methods
			
			
			
			
			/// Return the color overlayed when a menu item is highlighted.
			virtual Color4f getHighlightColor() const = 0;
			
			
			
			
			/// Set the color overlayed when a menu item is highlighted.
			/**
			  * The method returns whether or not the menu highlight color was successfully changed.
			  */
			virtual Bool setHighlightColor( const Color4f& newHighlightColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Style Accessor Methods
			
			
			
			
			/// Return a reference to the font style which is used to render the text for a menu.
			virtual const fonts::FontStyle& getTextStyle() const = 0;
			
			
			
			
			/// Set the font style which is used to render the text for a menu.
			/**
			  * The method returns whether or not the text's style was successfully changed.
			  */
			virtual Bool setTextStyle( const fonts::FontStyle& newTextStyle ) = 0;
			
			
			
};




/// A short name for the interface of a class that draws a Menu.
typedef GUIObjectRenderer<Menu> MenuRenderer;




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_MENU_RENDERER_H
