/*
 *  rimGraphicsGUIGraphicsFontDrawer.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/16/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_GRAPHICS_FONT_DRAWER_H
#define INCLUDE_RIM_GRAPHICS_GUI_GRAPHICS_FONT_DRAWER_H


#include "rimGraphicsGUIFontsConfig.h"


#include "rimGraphicsGUIFont.h"
#include "rimGraphicsGUIFontDrawer.h"


//##########################################################################################
//*********************  Start Rim Graphics GUI Fonts Namespace  ***************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the interface for classes that draw strings for Font objects using OpenGL.
class GraphicsFontDrawer : public FontDrawer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a graphics font drawer which has no valid rendering context.
			/**
			  * This font drawer will not be able to draw anything until a valid context
			  * is supplied via setContext().
			  */
			GraphicsFontDrawer();
			
			
			
			
			/// Create a graphics font drawer which uses the specified graphics context to draw with.
			GraphicsFontDrawer( const Pointer<GraphicsContext>& newContext );
			
			
			
			
			/// Create a copy of the state of another OpenGL font drawer.
			GraphicsFontDrawer( const GraphicsFontDrawer& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy an OpenGL font drawer and release all of its internal state.
			~GraphicsFontDrawer();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of another font drawer to this one.
			GraphicsFontDrawer& operator = ( const GraphicsFontDrawer& other );
			
			
			
			
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
			virtual Bool drawString( const UTF8String& string, const FontStyle& style, Vector2f& position );
			
			
			
			
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
										const FontStyle& style, Vector2f& position );
			
			
			
			
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
			virtual Bool getStringBounds( const UTF8String& string, const FontStyle& style, AABB2f& bounds );
			
			
			
			
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
										const Vector2f& maxSize, AABB2f& bounds );
			
			
			
			
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
			virtual Bool cacheString( const UTF8String& string, const FontStyle& style );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Context Accessor Methods
			
			
			
			
			/// Return a pointer to the graphics context which this font drawer is using to draw.
			RIM_INLINE const Pointer<GraphicsContext>& getContext() const
			{
				return context;
			}
			
			
			
			
			/// Set a pointer to the graphics context which this font drawer is using to draw.
			/**
			  * This causes the renderer to use the specified context to do all of its rendering.
			  * The renderer reinitializes all internal state using the new context. If the
			  * new context is NULL or not valid, the renderer will not be able to render anything.
			  */
			void setContext( const Pointer<GraphicsContext>& newContext );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Appearance Attribute Accessor Methods
			
			
			
			
			/// Return the number of space characters that each tab '\t' character will be translated into.
			RIM_INLINE Float getTabWidth() const
			{
				return tabWidth;
			}
			
			
			
			
			/// Set the number of space characters that each tab '\t' character will be translated into.
			RIM_INLINE void setTabWidth( Float newTabWidth )
			{
				tabWidth = newTabWidth;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations
			
			
			
			
			/// A class which contains information for rendering a particular size of a font glyph.
			class GlyphSize;
			
			
			
			
			/// A class which contains information about a particular texture atlas.
			class TextureAtlas;
			
			
			
			
			/// A class which contains glyphs for characters for a particular font.
			class FontAtlas;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Retrieve detailed information about the specified font style.
			/**
			  * If the method fails, FALSE is returned.
			  */
			Bool getFontInfo( const FontStyle& style, const Font*& font,
								FontAtlas*& fontAtlas, FontMetrics& fontMetrics );
			
			
			
			
			/// Return a pointer to a glyph size object for the specified font sizes and character.
			/**
			  * If there is no cached glyph for that size/font, a new one is created.
			  * If the method fails, NULL is returned.
			  */
			GlyphSize* getGlyphSize( Float nominalFontSize, Float maxFontSize, UTF32Char character,
									const Font& font, FontAtlas& fontAtlas );
			
			
			
			
			/// Create a new glyph size for the specified minimum font size and character.
			/**
			  * If the method fails, NULL is returned.
			  */
			GlyphSize* createNewGlyphSize( Float minimumFontSize, UTF32Char character,
											const Font& font, ArrayList<TextureAtlas>& atlases,
											ArrayList<GlyphSize>& glyphs );
			
			
			
			
			/// Create and initialize this drawer's vertex buffers and shaders to their default state.
			void initializeGraphicsState();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to graphics context which is used by this font drawer to draw.
			Pointer<GraphicsContext> context;
			
			
			
			ImmediateRenderer imm;
			
			
			
			
			/// A map from internal font IDs to sets of glyphs for those fonts.
			HashMap<UTF8String,FontAtlas> fonts;
			
			
			
			
			/// A pointer to the default font to use when rendering strings of characters.
			Pointer<fonts::Font> defaultFont;
			
			
			
			
			/// An object representing the default shader pass to use for fonts rendererd without a user-defined shader.
			Pointer<ShaderPass> defaultShaderPass;
			
			
			
			
			/// A pointer to a buffer for which is used by this font drawer to accumulate glyph vertex positions.
			Pointer<VertexBuffer> positionBuffer;
			
			
			
			
			/// A pointer to a buffer for which is used by this font drawer to accumulate glyph vertex texture coordinates.
			Pointer<VertexBuffer> uvBuffer;
			
			
			
			
			/// The number of space characters that each tab '\t' character will be translated into.
			Float tabWidth;
			
			
			
			
			/// The index of the model view matrix constant binding for the font drawer's shader pass.
			Index modelViewBindingIndex;
			
			
			
			
			/// The index of the color constant binding for the renderer's shader passes.
			Index colorBindingIndex;
			
			
			
			
			/// The index of the glyph texture binding for the font drawer's shader pass.
			Index glyphBindingIndex;
			
			
			
			
};




//##########################################################################################
//*********************  End Rim Graphics GUI Fonts Namespace  *****************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_GRAPHICS_FONT_DRAWER_H
