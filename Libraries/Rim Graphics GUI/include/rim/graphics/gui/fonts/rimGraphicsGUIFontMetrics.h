/*
 *  rimGraphicsGUIFontMetrics.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/16/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_FONT_METRICS_H
#define INCLUDE_RIM_GRAPHICS_GUI_FONT_METRICS_H


#include "rimGraphicsGUIFontsConfig.h"


//##########################################################################################
//*********************  Start Rim Graphics GUI Fonts Namespace  ***************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which describes sizing information for a particular Font.
class FontMetrics
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a default font metrics object.
			RIM_INLINE FontMetrics()
				:	size( 0 )
			{
			}
			
			
			
			
			/// Create a font metrics object with the specified attributes.
			RIM_INLINE FontMetrics( Float newSize, const Vector2f& newLineAdvance,
									const AABB2f& newGlyphBounds, const Vector2f& newMaxAdvance )
				:	size( newSize ),
					lineAdvance( newLineAdvance ),
					glyphBounds( newGlyphBounds ),
					maxAdvance( newMaxAdvance )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Size Accessor Methods
			
			
			
			
			/// Return the nominal size of the font in pixels.
			RIM_INLINE Float getSize() const
			{
				return size;
			}
			
			
			
			
			/// Set the nominal size of the font in pixels.
			RIM_INLINE void setSize( Float newSize )
			{
				size = newSize;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Font Height Accessor Methods
			
			
			
			
			/// Return the vector in pixels between consecutive lines of text of the font.
			RIM_INLINE const Vector2f& getLineAdvance() const
			{
				return lineAdvance;
			}
			
			
			
			
			/// Set the vector in pixels between consecutive lines of text of the font.
			RIM_INLINE void setLineAdvance( const Vector2f& newLineAdvance )
			{
				lineAdvance = newLineAdvance;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Box Accessor Methods
			
			
			
			
			/// Return a 2D bounding box which encloses all glyphs that are part of the font.
			/**
			  * This bounding box is specified where (0,0) is the origin of a glyph.
			  * The bounding box is expressed in units of pixels.
			  */
			RIM_INLINE const AABB2f& getBounds() const
			{
				return glyphBounds;
			}
			
			
			
			
			/// Set a 2D bounding box which encloses all glyphs that are part of the font.
			/**
			  * This bounding box is specified where (0,0) is the origin of a glyph.
			  * The bounding box is expressed in units of pixels.
			  */
			RIM_INLINE void setBounds( const AABB2f& newGlyphBounds )
			{
				glyphBounds = newGlyphBounds;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Maximum Advance Accessor Methods
			
			
			
			
			/// Return the maximum distance in pixels from the origin of a first glyph to that of a second glyph for the font.
			/**
			  * This value is returned for both the horizontal and vertical directions.
			  */
			RIM_INLINE const Vector2f& getMaxAdvance() const
			{
				return maxAdvance;
			}
			
			
			
			
			/// Set the maximum distance in pixels from the origin of a first glyph to that of a second glyph for the font.
			/**
			  * This value is specified for both the horizontal and vertical directions.
			  */
			RIM_INLINE void setMaxAdvance( const Vector2f& newMaxAdvance )
			{
				maxAdvance = newMaxAdvance;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The nominal size of the font.
			Float size;
			
			
			
			
			/// The vector in pixels between successive lines of the font.
			Vector2f lineAdvance;
			
			
			
			
			/// A 2D axis-aligned bounding box which encloses all glyphs that are part of the font.
			/**
			  * This bounding box is specified where (0,0) is the origin of the glyph.
			  * The bounding box is expressed in units of pixels.
			  */
			AABB2f glyphBounds;
			
			
			
			
			/// The largest advance vector between two successive characters in both directions.
			Vector2f maxAdvance;
			
			
			
};




//##########################################################################################
//*********************  End Rim Graphics GUI Fonts Namespace  *****************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_FONT_METRICS_H
