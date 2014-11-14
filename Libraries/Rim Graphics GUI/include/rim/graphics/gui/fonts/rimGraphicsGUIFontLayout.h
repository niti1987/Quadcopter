/*
 *  rimGraphicsGUIFontLayout.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/7/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_FONT_LAYOUT_H
#define INCLUDE_RIM_GRAPHICS_GUI_FONT_LAYOUT_H


#include "rimGraphicsGUIFontsConfig.h"


//##########################################################################################
//*********************  Start Rim Graphics GUI Fonts Namespace  ***************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which describes the orientation of a particular font.
/**
  * A font can be layed out either horizontally, in which case lines are
  * horizontal and each successive line is vertically offset, or vertically,
  * where lines are vertical and each successive line is horizontally offset.
  */
class FontLayout
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Enum Declaration
			
			
			
			
			/// An enum which specifies the different kinds of font layouts.
			typedef enum Enum
			{
				/// A font layout where lines are horizontal.
				/**
				  * Each successive line of text is vertically offset from the last.
				  */
				HORIZONTAL,
				
				/// A font layout where lines are vertical.
				/**
				  * Each successive line of text is horizontally offset from the last.
				  */
				VERTICAL
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new font layout  using the specified font layout enum value.
			RIM_INLINE FontLayout( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this font layout to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the font layout.
			String toString() const;
			
			
			
			
			/// Convert this font layout into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value indicating the type of font layout this object represents.
			Enum type;
			
			
			
			
};




//##########################################################################################
//*********************  End Rim Graphics GUI Fonts Namespace  *****************************
RIM_GRAPHICS_GUI_FONTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_FONT_LAYOUT_H
