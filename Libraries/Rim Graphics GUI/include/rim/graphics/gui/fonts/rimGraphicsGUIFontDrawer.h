/*
 *  rimGraphicsGUIFontDrawer.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/16/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_FONT_DRAWER_H
#define INCLUDE_RIM_GRAPHICS_GUI_FONT_DRAWER_H


#include "rimGraphicsGUIFontsConfig.h"


#include "rimGraphicsGUIFont.h"
#include "rimGraphicsGUIFontStyle.h"


//##########################################################################################
//*********************  Start Rim Graphics GUI Fonts Namespace  ***************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the interface for classes that draw strings for Font objects.
class FontDrawer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this font drawer and release any resources.
			virtual ~FontDrawer()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Drawing Methods
			
			
			
			
			/// Draw the specified unicode string using the provided font style.
			/**
			  * The position and font size are assumed to be in viewport pixel coordinates.
			  * For instance, the lower left corner of the current viewport has position (0,0)
			  * and for a viewport with width 1024 and height 768, the upper right corner
			  * has position (1023,767).
			  *
			  * The position is an in/out parameter which indicates the final pen position
			  * of the font renderer after rendering the string. The method returns whether
			  * or not the string was able to be drawn successfully.
			  */
			virtual Bool drawString( const UTF8String& string, const FontStyle& style, Vector2f& position ) = 0;
			
			
			
			
			/// Draw the specified number of characters from a string iterator using the provided font style.
			/**
			  * The position and font size are assumed to be in viewport pixel coordinates.
			  * For instance, the lower left corner of the current viewport has position (0,0)
			  * and for a viewport with width 1024 and height 768, the upper right corner
			  * has position (1023,767).
			  *
			  * The position is an in/out parameter which indicates the final pen position
			  * of the font renderer after rendering the string. The method returns whether
			  * or not the characters were able to be drawn successfully.
			  */
			virtual Bool drawCharacters( UTF8StringIterator& string, Size numCharacters,
										const FontStyle& style, Vector2f& position ) = 0;
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Size Accessor Method
			
			
			
			
			/// Retrieve a bounding box for the specified string using the given font style.
			/**
			  * This method computes a bounding box for the string where the starting
			  * pen position is the origin (0,0). If the method succeeds, the string's
			  * bounding box is placed in the output reference parameter and TRUE is returned.
			  * If the method fails, FALSE is returned and no bounding box is computed.
			  */
			virtual Bool getStringBounds( const UTF8String& string, const FontStyle& style, AABB2f& bounds ) = 0;
			
			
			
			
			/// Retrieve a bounding box for the specified string iterator's next line using the given font style.
			/**
			  * This method computes the bounding box of every character from the specified
			  * string iterator until either a new line character is encountered or the
			  * size of the string's bounding box exceeds the specified maximum size.
			  *
			  * Thie method can be used to perform text wrapping. Use the final position
			  * of the iterator to know how many characters to draw.
			  */
			virtual Bool getLineBounds( UTF8StringIterator& string, const FontStyle& style,
										const Vector2f& maxSize, AABB2f& bounds ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Caching Method
			
			
			
			
			/// Cache all of the glyphs in the specified string with the given font style.
			/**
			  * This method allows the user to cache whatever rendering state is necessary
			  * to draw the glyphs contained in the given string with the specified font
			  * style. Since loading glyphs from a font file can be slow, this allows an
			  * application to pre-cache commonly needed glyphs to avoid rendering stalls
			  * when the drawer loads new glyphs at runtime.
			  *
			  * The method returns whether or not the string's characters were successfully
			  * cached. The default implementation does nothing and returns FALSE.
			  */
			virtual Bool cacheString( const UTF8String& string, const FontStyle& style )
			{
				return false;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
};




//##########################################################################################
//*********************  End Rim Graphics GUI Fonts Namespace  *****************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_FONT_DRAWER_H
