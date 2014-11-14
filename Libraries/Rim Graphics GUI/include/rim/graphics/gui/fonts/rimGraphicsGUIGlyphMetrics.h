/*
 *  rimGraphicsGUIGlyphMetrics.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/16/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_GLYPH_METRICS_H
#define INCLUDE_RIM_GRAPHICS_GUI_GLYPH_METRICS_H


#include "rimGraphicsGUIFontsConfig.h"


//##########################################################################################
//*********************  Start Rim Graphics GUI Fonts Namespace  ***************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which describes sizing information about a particular font glyph.
class GlyphMetrics
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a default glyph metrics object.
			RIM_INLINE GlyphMetrics()
				:	size( 0 ),
					height( 0 )
			{
			}
			
			
			
			
			/// Create a glyph metrics object with the specified attributes.
			RIM_INLINE GlyphMetrics( Float newSize, Float newHeight,
									const AABB2f& newBounds, const Vector2f& newAdvance )
				:	size( newSize ),
					height( newHeight ),
					bounds( newBounds ),
					advance( newAdvance )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Size Accessor Methods
			
			
			
			
			/// Return the nominal size of the glyph's font in pixels.
			RIM_INLINE Float getSize() const
			{
				return size;
			}
			
			
			
			
			/// Set the nominal size of the glyph's font in pixels.
			RIM_INLINE void setSize( Float newSize )
			{
				size = newSize;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Height Accessor Methods
			
			
			
			
			/// Return the distance in pixels between consecutive horizontal lines of text of the glyph's font.
			RIM_INLINE Float getHeight() const
			{
				return height;
			}
			
			
			
			
			/// Set the distance in pixels between consecutive horizontal lines of text of the glyph's font.
			RIM_INLINE void setHeight( Float newHeight )
			{
				height = newHeight;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Box Accessor Methods
			
			
			
			
			/// Return a 2D bounding box which completely encloses the glyphs.
			/**
			  * This bounding box is specified where (0,0) is the origin of a glyph.
			  * The bounding box is expressed in units of pixels.
			  */
			RIM_INLINE const AABB2f& getBounds() const
			{
				return bounds;
			}
			
			
			
			
			/// Set a 2D bounding box which completely encloses the glyphs.
			/**
			  * This bounding box is specified where (0,0) is the origin of a glyph.
			  * The bounding box is expressed in units of pixels.
			  */
			RIM_INLINE void setBounds( const AABB2f& newBounds )
			{
				bounds = newBounds;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Maximum Advance Accessor Methods
			
			
			
			
			/// Return the vector in pixels from the origin of the glyph to the next glyph for the font.
			/**
			  * This value is returned for both the horizontal and vertical directions.
			  * It does not include any kerning between the glyphs. Use the font's kerning
			  * accessor method to get the proper kerning for pairs of glyphs.
			  */
			RIM_INLINE const Vector2f& getAdvance() const
			{
				return advance;
			}
			
			
			
			
			/// Set the vector in pixels from the origin of the glyph to the next glyph for the font.
			/**
			  * This value is returned for both the horizontal and vertical directions.
			  * It does not include any kerning between the glyphs. Use the font's kerning
			  * accessor method to get the proper kerning for pairs of glyphs.
			  */
			RIM_INLINE void setAdvance( const Vector2f& newAdvance )
			{
				advance = newAdvance;
			}
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The nominal size of the glyph's font.
			Float size;
			
			
			
			
			/// The distance in pixels between successive horizontal lines of the glyph.
			/**
			  * This value will likely be the same for all glyphs that are part of a font.
			  */
			Float height;
			
			
			
			
			/// A 2D axis-aligned bounding box which completely encloses the glyph.
			/**
			  * This bounding box is specified where (0,0) is the origin of the glyph.
			  * The bounding box is expressed in units of pixels.
			  */
			AABB2f bounds;
			
			
			
			
			/// The advance vector between this glyph and the next (not kerned).
			Vector2f advance;
			
			
			
};




//##########################################################################################
//*********************  End Rim Graphics GUI Fonts Namespace  *****************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_GLYPH_METRICS_H
