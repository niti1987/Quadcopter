/*
 *  rimGraphicsGUIFontInfo.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/15/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_FONT_INFO_H
#define INCLUDE_RIM_GRAPHICS_GUI_FONT_INFO_H


#include "rimGraphicsGUIFontsConfig.h"


//##########################################################################################
//*********************  Start Rim Graphics GUI Fonts Namespace  ***************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which describes information about an installed font file.
class FontInfo
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a default font information object which doesn't represent a valid font.
			RIM_INLINE FontInfo()
			{
			}
			
			
			
			
			/// Create a new font information object with the specified path to a font file.
			RIM_INLINE FontInfo( const UTF8String& newFontPath )
				:	fontPath( newFontPath )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Path Accessor Methods
			
			
			
			
			/// Return a string representing the path to the font that is being described.
			RIM_INLINE const UTF8String& getPathString() const
			{
				return fontPath;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Family Name Accessor Methods
			
			
			
			
			/// Return a string which represents a human-readable name for the font family that is being described.
			RIM_INLINE const UTF8String& getFamilyName() const
			{
				return fontFamilyName;
			}
			
			
			
			
			/// Set a string which represents a human-readable name for the font family that is being described.
			RIM_INLINE void setFamilyName( const UTF8String& newFamilyName )
			{
				fontFamilyName = newFamilyName;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Style Name Accessor Methods
			
			
			
			
			/// Return a string which represents a human-readable name for the font style that is being described.
			RIM_INLINE const UTF8String& getStyleName() const
			{
				return fontStyleName;
			}
			
			
			
			
			/// Set a string which represents a human-readable name for the font style that is being described.
			RIM_INLINE void setStyleName( const UTF8String& newStyleName )
			{
				fontStyleName = newStyleName;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A string representing the path to the font file that is being described by this font info.
			UTF8String fontPath;
			
			
			
			
			/// A string representing the name of the font family described by this font info.
			UTF8String fontFamilyName;
			
			
			
			
			/// A string representing the name of the font style described by this font info.
			UTF8String fontStyleName;
			
			
			
};




//##########################################################################################
//*********************  End Rim Graphics GUI Fonts Namespace  *****************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_FONT_INFO_H
