/*
 *  rimGraphicsGUIFontStyle.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/22/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_FONT_STYLE_H
#define INCLUDE_RIM_GRAPHICS_GUI_FONT_STYLE_H


#include "rimGraphicsGUIFontsConfig.h"


#include "rimGraphicsGUIFont.h"
#include "rimGraphicsGUIFontLayout.h"


//##########################################################################################
//*********************  Start Rim Graphics GUI Fonts Namespace  ***************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which describes information about appearance of a particular font style.
/**
  * This information includes the font itself, the size of the font and the font's color.
  */
class FontStyle
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a default font style object which doesn't represent a valid font style.
			RIM_INLINE FontStyle()
				:	font(),
					fontSize( 0 ),
					color(),
					layout( FontLayout::HORIZONTAL )
			{
			}
			
			
			
			
			/// Create a new font style object which has the specified attributes.
			RIM_INLINE FontStyle( const Pointer<Font>& newFont, Float newFontSize, const Color4f& newColor )
				:	font( newFont ),
					fontSize( newFontSize ),
					color( newColor ),
					layout( FontLayout::HORIZONTAL )
			{
			}
			
			
			
			
			/// Create a new font style object which has the specified attributes.
			RIM_INLINE FontStyle( const Pointer<Font>& newFont, Float newFontSize,
									const Color4f& newColor, const FontLayout& newLayout )
				:	font( newFont ),
					fontSize( newFontSize ),
					color( newColor ),
					layout( newLayout )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Accessor Methods
			
			
			
			
			/// Return a pointer to a Font object which determines the appearance of the style.
			RIM_INLINE const Pointer<Font>& getFont() const
			{
				return font;
			}
			
			
			
			
			/// Set a pointer to a Font object which determines the appearance of the style.
			RIM_INLINE void setFont( const Pointer<Font>& newFont )
			{
				font = newFont;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Size Accessor Methods
			
			
			
			
			/// Return a number which indicates the nominal size of the font for the style.
			RIM_INLINE Float getFontSize() const
			{
				return fontSize;
			}
			
			
			
			
			/// Set a number which indicates the nominal size of the font for the style.
			RIM_INLINE void setFontSize( Float newFontSize )
			{
				fontSize = newFontSize;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Style Name Accessor Methods
			
			
			
			
			/// Return a reference to an object that describes the RGBA color of the font style.
			RIM_INLINE const Color4f& getColor() const
			{
				return color;
			}
			
			
			
			
			/// Set an object that describes the RGBA color of the font style.
			RIM_INLINE void setColor( const Color4f& newColor )
			{
				color = newColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Style Name Accessor Methods
			
			
			
			
			/// Return a reference to an object that describes the direction that the font style is layed out.
			RIM_INLINE const FontLayout& getLayout() const
			{
				return layout;
			}
			
			
			
			
			/// Set an object that describes the direction that the font style is layed out.
			RIM_INLINE void setLayout( const FontLayout& newLayout )
			{
				layout = newLayout;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Font Style Accessor Methods
			
			
			
			
			/// Return the default font style.
			RIM_INLINE static FontStyle getDefault()
			{
				return FontStyle( Font::getDefault(), 12, Color4f::BLACK );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An RGBA color which indicates the desired color of the font style, including transparency.
			Color4f color;
			
			
			
			
			/// A number which indicates the nominal size of the font for the style.
			Float fontSize;
			
			
			
			
			/// An object which specifies the direction in which this font style should be layed out.
			FontLayout layout;
			
			
			
			
			/// A pointer to an object which determines the appearance of the font style.
			Pointer<Font> font;
			
			
			
};




//##########################################################################################
//*********************  End Rim Graphics GUI Fonts Namespace  *****************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_FONT_STYLE_H
