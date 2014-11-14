/*
 *  rimGraphicsGUIFont.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/15/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_FONT_H
#define INCLUDE_RIM_GRAPHICS_GUI_FONT_H


#include "rimGraphicsGUIFontsConfig.h"


#include "rimGraphicsGUIFontInfo.h"
#include "rimGraphicsGUIFontMetrics.h"
#include "rimGraphicsGUIGlyphMetrics.h"


//##########################################################################################
//*********************  Start Rim Graphics GUI Fonts Namespace  ***************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which acts as an interface to a single font style.
/**
  * The class provides ways to access sizing metrics globally and for each glyph,
  * glyph pair kerning, and can render bitmap images for each glyph that can be
  * used to do various kinds of font rendering.
  */
class Font
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new font object for the font file located at the specified path string.
			Font( const UTF8String& fontPath );
			
			
			
			
			/// Create a new font object for the font described by the specified font information.
			/**
			  * This constructor uses the font info's path string to load the font from
			  * mass storage.
			  */
			Font( const FontInfo& fontInfo );
			
			
			
			
			/// Create a new font object for a font file with the specified data.
			/**
			  * This constructor creates a font which uses a memory-resident block of font
			  * data (previously read from a font file) to realize the font.
			  */
			Font( const Data& fontData );
			
			
			
			
			/// Create a copy of another font object, obtaining a reference to its font.
			Font( const Font& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this font object and release all of its resources.
			~Font();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Copy the state of another Font object to this one.
			Font& operator = ( const Font& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Info Accessor Methods
			
			
			
			
			/// Return a reference to an object which contains information about this font.
			RIM_INLINE const FontInfo& getInfo() const
			{
				return info;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Metrics Accessor Methods
			
			
			
			
			/// Get font metric information for the specified size of this font.
			/**
			  * If the method succeeds, the metrics object is updated to reflect
			  * the metrics for this font with the given size and TRUE is returned.
			  * Otherwise, FALSE is returned indicating failure. The method can fail if
			  * an invalid size (i.e. negative) is specified.
			  */
			Bool getMetrics( Float fontSize, FontMetrics& metrics ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Glyph Accessor Methods
			
			
			
			
			/// Get sizing metrics for the glyph with the specified character code and font size.
			/**
			  * If the metrics are successfully retrieved, they are placed in the output
			  * metrics parameter and TRUE is returned. Otherwise, FALSE is returned and
			  * no metrics are set.
			  */
			Bool getGlyphMetrics( Float fontSize, UTF32Char character, GlyphMetrics& metrics ) const;
			
			
			
			
			/// Render a bitmap for the glyph with the specified character code and font size.
			/**
			  * If the glyph's image is successfully rendered, it is placed in the output glyph
			  * image parameter and TRUE is returned. A glyph metrics object is initialized for
			  * the glyph too. If the method fails, FALSE is returned and no image or metrics are
			  * retrieved.
			  */
			Bool getGlyphImage( Float fontSize, UTF32Char character, Image& glyphImage, GlyphMetrics& metrics ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Kerning Accessor Methods
			
			
			
			
			/// Get the kerning advance vector in pixels between the origins for the specified two characters.
			/**
			  * This method uses the font's internal kerning information, scaled to the
			  * specified font point size, to determine how far to advance
			  * in pixels between the origins of the two specified characters. If the method
			  * succeeds, it places the kerning vector in the output parameter and returns
			  * TRUE. Otherwise, if the method fails, it returns FALSE.
			  */
			Bool getKerning( Float fontSize, UTF32Char character1, UTF32Char character2, Vector2f& kerning ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Validity Accessor Method
			
			
			
			
			/// Return whether or not this font object represents a valid font.
			Bool isValid() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Default Font Accessor Method
			
			
			
			
			/// Return a shared pointer to an object representing the default system font.
			static const Pointer<Font>& getDefault();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which represents a pair of UTF-32 encoded characters used for kerning information access.
			class CharacterPair;
			
			
			
			
			/// A class which stores kerning information for a particular pair of characters.
			class KerningInfo;
			
			
			
			
			/// A class which encapsulates platform-specific information about this font.
			class FontWrapper;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// A helper method which sets the size that should be used for the font.
			Bool setFontSize( Float newFontSize ) const;
			
			
			
			
			/// Update the font info structure with more detailed information from the font.
			void updateFontInfo();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to an object which holds platform-specific information for this font.
			FontWrapper* wrapper;
			
			
			
			
			/// An object which stores information about this font.
			FontInfo info;
			
			
			
			
			/// The current nominal size of the font which allows the font to only be resized when needed.
			mutable Float currentFontSize;
			
			
			
};




//##########################################################################################
//*********************  End Rim Graphics GUI Fonts Namespace  *****************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_FONT_H
