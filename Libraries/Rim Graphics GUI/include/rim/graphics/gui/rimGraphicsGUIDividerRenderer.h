/*
 *  rimGraphicsGUIDividerRenderer.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/7/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_DIVIDER_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_GUI_DIVIDER_RENDERER_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObjectRenderer.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Divider;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles drawing Divider objects to a graphics rendering context.
template <>
class GUIObjectRenderer<Divider>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Virtual Destructor Declaration
			
			
			
			
			/// Destroy this GUI object renderer, releasing all of its internal state.
			virtual ~GUIObjectRenderer()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Rendering Methods
			
			
			
			
			/// Draw an object using the specified renderer within the given parent coordinate bounds.
			/**
			  * The method returns whether or not the object was able to be successfully drawn.
			  */
			virtual Bool render( GUIRenderer& renderer, const AABB2f& parentBounds, const Divider& object ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Accessor Methods
			
			
			
			
			/// Return the color for this divider's dividing line.
			virtual Color4f getColor() const = 0;
			
			
			
			
			
			/// Set the color for this divider's dividing line.
			/**
			  * The method returns whether or not the divider's color was successfully changed.
			  */
			virtual Bool setColor( const Color4f& newColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Width Accessor Methods
			
			
			
			
			/// Return the width of this divider's dividing line.
			virtual Float getWidth() const = 0;
			
			
			
			
			/// Set the width of this divider's dividing line.
			/**
			  * The method returns whether or not the divider's width was able to be changed.
			  */
			virtual Bool setWidth( Float newWidth ) = 0;
			
			
			
};




/// A short name for the interface of a class that draws a Divider.
typedef GUIObjectRenderer<Divider> DividerRenderer;




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_DIVIDER_RENDERER_H
