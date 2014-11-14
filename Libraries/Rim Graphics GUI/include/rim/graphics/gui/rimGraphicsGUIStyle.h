/*
 *  rimGraphicsGUIStyle.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 11/4/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_STYLE_H
#define INCLUDE_RIM_GRAPHICS_GUI_STYLE_H


#include "rimGraphicsGUIBase.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the style to use when drawing a GUI object.
/**
  * A style object contains a set of shader passes that are used to draw
  * different parts of GUI elements.
  */
class GUIStyle
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new GUI style without any shaders set.
			RIM_INLINE GUIStyle()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The default shader to use to draw a border area of a rectangle.
			Pointer<ShaderPass> border;
			
			
			/// The shader to use to draw a solid border area of a rectangle.
			Pointer<ShaderPass> borderSolid;
			
			
			/// The shader to use to draw a raised border area of a rectangle.
			Pointer<ShaderPass> borderRaised;
			
			
			/// The shader to use to draw a sunken border area of a rectangle.
			Pointer<ShaderPass> borderSunken;
			
			
			/// The shader to use to draw the background of a rectangular content area.
			Pointer<ShaderPass> content;
			
			
			/// The shader to use to draw raster images.
			Pointer<ShaderPass> image;
			
			
			/// The shader to use to draw text glyphs.
			Pointer<ShaderPass> text;
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_STYLE_H
