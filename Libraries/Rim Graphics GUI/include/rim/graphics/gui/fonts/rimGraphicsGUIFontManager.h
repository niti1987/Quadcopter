/*
 *  rimGraphicsGUIFontManager.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/15/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_FONT_MANAGER_H
#define INCLUDE_RIM_GRAPHICS_GUI_FONT_MANAGER_H


#include "rimGraphicsGUIFontsConfig.h"


#include "rimGraphicsGUIFontInfo.h"


//##########################################################################################
//*********************  Start Rim Graphics GUI Fonts Namespace  ***************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which allows the user to enumerate and search through the installed system fonts.
/**
  * When the information is first needed, the font manager automatically caches
  * the system's available fonts by searching system directories for font files,
  * then saving each valid file's path and information so that it can be later used.
  * Keep in mind that this this caching can take a few seconds to occur.
  *
  * The font manager then allows the user to search for fonts with a certain font family
  * and style name within the cached fonts.
  */
class FontManager
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a default font manager which hasn't yet cached the system's available fonts.
			RIM_INLINE FontManager()
				:	hasCachedFonts( false )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Accessor Methods
			
			
			
			
			/// Return the total number of system fonts that are available for use.
			RIM_INLINE Size getFontCount() const
			{
				if ( !hasCachedFonts )
					const_cast<FontManager*>(this)->cacheFonts();
				
				return cachedFonts.getSize();
			}
			
			
			
			
			/// Find a system font which has the specified font family name.
			/**
			  * The method attempts to match the family name when determining the font to retrieve.
			  * The font information is placed in the output font information object.
			  * If the method finds a suitable font, TRUE is returned.
			  * Otherwise, if the method fails, FALSE is returned indicating that no
			  * font with those names was found.
			  */
			RIM_INLINE Bool findFont( const UTF8String& familyName, const FontInfo*& fontInfo ) const
			{
				return this->findFont( familyName, NULL, fontInfo );
			}
			
			
			
			
			/// Find a system font which has the specified font family name and specified style name.
			/**
			  * The method attempts to match both the family name
			  * and style name when determining the font to retrieve. The font information is placed
			  * in the output font information object. If the method finds a suitable font, TRUE
			  * is returned. Otherwise, if the method fails, FALSE is returned indicating that no
			  * font with those names was found.
			  */
			RIM_INLINE Bool findFont( const UTF8String& familyName, const UTF8String& styleName,
									const FontInfo*& fontInfo ) const
			{
				return this->findFont( familyName, &styleName, fontInfo );
			}
			
			
			
			
			/// Find a system font which has the specified font family name and optionally specified style name.
			/**
			  * If the style name pointer is not NULL, the method attempts to match both the family name
			  * and style name when determining the font to retrieve. The font information is placed
			  * in the output font information object. If the method finds a suitable font, TRUE
			  * is returned. Otherwise, if the method fails, FALSE is returned indicating that no
			  * font with those names was found.
			  */
			Bool findFont( const UTF8String& familyName, const UTF8String* styleName, const FontInfo*& fontInfo ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Caching Method
			
			
			
			
			/// Search the system for valid font files and cache their locations and names.
			/**
			  * Calling this method replaces all previously cached fonts with the current
			  * set of available system fonts. Beware, calling this method may take a significant
			  * time to execute (on the order of a few seconds) if there are a large number
			  * of fonts installed because the font manager has to examine every font file
			  * to determine the font's name and style name.
			  */
			void cacheFonts();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Default Font Accessor Method
			
			
			
			
			/// Return a reference to information about the default font.
			/**
			  * This font will be a valid font file, chosen to match the system's
			  * default font.
			  */
			static const FontInfo* getDefaultFont();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which wraps a string so that it can be compare case-insensitively using operator ==.
			class CaselessString
			{
				public:
					
					/// Create a new caseless string which wraps the specified string.
					RIM_INLINE CaselessString( const UTF8String& newString )
						:	string( newString.toLowerCase() )
					{
					}
					
					
					/// Return whether or not this caseless string equals another (case insensitively).
					RIM_INLINE Bool operator == ( const CaselessString& other ) const
					{
						return string.equalsIgnoreCase( other.string );
					}
					
					
					/// Return a hash code for this caseless string.
					RIM_INLINE Hash getHashCode() const
					{
						return string.getHashCode();
					}
					
					
					/// A pointer to a string which is being wrapped by this case-insensitive string.
					UTF8String string;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Cache any fonts contained in the specified directory. This may be called recursively.
			void cacheFontDirectory( const Directory& directory );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The total number of font search paths where the font manager looks for fonts.
#if defined(RIM_PLATFORM_APPLE)
			static const Size NUM_SEARCH_PATHS = 2;
#elif defined(RIM_PLATFORM_WINDOWS)
			static const Size NUM_SEARCH_PATHS = 1;
#endif
			
			
			
			
			/// An array of the paths that the font manager is searching on this system
			static const UTF8String DEFAULT_SEARCH_PATHS[NUM_SEARCH_PATHS];
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A cached map from font family name to a list of font styles for that family.
			HashMap< CaselessString, ArrayList<FontInfo> > cachedFonts;
			
			
			
			
			/// A boolean value indicating whether or not this font manager has cached the available fonts.
			Bool hasCachedFonts;
			
			
			
};




//##########################################################################################
//*********************  End Rim Graphics GUI Fonts Namespace  *****************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_FONT_MANAGER_H
