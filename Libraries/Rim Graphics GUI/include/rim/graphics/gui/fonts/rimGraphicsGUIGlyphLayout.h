/*
 *  rimGraphicsGUIGlyphLayout.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 11/11/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_GLYPH_LAYOUT_H
#define INCLUDE_RIM_GRAPHICS_GUI_GLYPH_LAYOUT_H


#include "rimGraphicsGUIFontsConfig.h"


#include "rimGraphicsGUIFontStyle.h"


//##########################################################################################
//*********************  Start Rim Graphics GUI Fonts Namespace  ***************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which stores the bounding boxes of glyphs that have the same font style.
class GlyphLayout
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a default glyph layout with no glyphs and an invalid font style.
			GlyphLayout();
			
			
			
			
			/// Create a glyph layout with the specified font style.
			GlyphLayout( const FontStyle& newStyle );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this glyph layout, releasing all internal resources.
			~GlyphLayout();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Glyph Accessor Methods
			
			
			
			
			/// Return the number of glyphs in this layout.
			RIM_INLINE Size getGlyphCount() const
			{
				return glyphs.getSize();
			}
			
			
			
			
			/// Return the UTF-32 character code for the glyph at the specified index in this layout.
			RIM_INLINE UTF32Char getGlyphCharacter( Index glyphIndex ) const
			{
				return glyphs[glyphIndex].character;
			}
			
			
			
			
			/// Return the bounding box for the glyph at the specified index in this layout.
			RIM_INLINE const AABB2f& getGlyphBounds( Index glyphIndex ) const
			{
				return glyphs[glyphIndex].bounds;
			}
			
			
			
			
			/// Add a new glyph to this glyph layout with the specified character code and bounding box.
			void addGlyph( UTF32Char newCharacter, const AABB2f& newBounds );
			
			
			
			
			/// Remove all glyphs from this layout.
			void clearGlyphs();
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Style Accessor Methods
			
			
			
			
			/// Return an object which stores the font style parameters for this glyph layout.
			RIM_INLINE const FontStyle& getStyle() const
			{
				return style;
			}
			
			
			
			
			/// Set an object which stores the font style parameters for this glyph layout.
			/**
			  * After changing the style, the glyph layout must be regenerated if the font or font
			  * size changed in order to remain valid.
			  */
			RIM_INLINE void setStyle( const FontStyle& newStyle )
			{
				style = newStyle;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Box Accessor Methods
			
			
			
			
			/// Return A 2D axis-aligned bounding box which completely encloses all glyphs in this layout.
			RIM_INLINE const AABB2f& getBounds() const
			{
				return bounds;
			}
			
			
			
			
			/// Set a 2D axis-aligned bounding box which completely encloses all glyphs in this layout.
			RIM_INLINE void setBounds( const AABB2f& newBounds )
			{
				bounds = newBounds;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Glyph Picking Method
			
			
			
			
			/// Determine the index of the glyph that contains the specified point.
			/**
			  * The method finds the first glyph whose bounds contain the point,
			  * puts the index of that glyph in the output parameter and returns TRUE.
			  * If there is no glyph containing that point, FALSE is returned.
			  */
			Bool pickGlyph( const Vector2f& point, Index glyphIndex ) const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A class that stores the bounding box and character code for a glyph.
			class Glyph
			{
				public:
					
					/// Create a new glyph with the specified character and bounding box.
					RIM_INLINE Glyph( UTF32Char newCharacter, const AABB2f& newBounds )
						:	bounds( newBounds ),
							character( newCharacter )
					{
					}
					
					
					/// A 2D axis-aligned bounding box for this glyph.
					AABB2f bounds;
					
					/// The character code associated with this glyph, or 0 if there is no character code.
					UTF32Char character;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object which stores the font style parameters for this glyph layout.
			FontStyle style;
			
			
			
			
			/// A 2D axis-aligned bounding box which completely encloses all glyphs in this layout.
			AABB2f bounds;
			
			
			
			
			/// A list of the glyphs that are contained in this glyph layout.
			ArrayList<Glyph> glyphs;
			
			
			
};




//##########################################################################################
//*********************  End Rim Graphics GUI Fonts Namespace  *****************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_GLYPH_LAYOUT_H
