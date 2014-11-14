/*
 *  rimGraphicsGUIKnobRenderer.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/17/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_KNOB_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_GUI_KNOB_RENDERER_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObjectRenderer.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Knob;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles drawing Knob objects to a graphics rendering context.
template <>
class GUIObjectRenderer<Knob>
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
			virtual Bool render( GUIRenderer& renderer, const AABB2f& parentBounds, const Knob& knob ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Accessor Methods
			
			
			
			
			/// Return the background color for this knob's area.
			virtual Color4f getBackgroundColor() const = 0;
			
			
			
			
			
			/// Set the background color for this knob's area.
			/**
			  * The method returns whether or not the knob's background color was successfully changed.
			  */
			virtual Bool setBackgroundColor( const Color4f& newBackgroundColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a knob.
			virtual Color4f getBorderColor() const = 0;
			
			
			
			
			
			/// Set the border color used when rendering a knob.
			/**
			  * The method returns whether or not the knob border color was successfully changed.
			  */
			virtual Bool setBorderColor( const Color4f& newBorderColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Indicator Color Accessor Methods
			
			
			
			
			/// Return the color used when rendering a knob's rotation indicator.
			virtual Color4f getIndicatorColor() const = 0;
			
			
			
			
			
			/// Set the color used when rendering a knob's rotation indicator.
			/**
			  * The method returns whether or not the knob indicator color was successfully changed.
			  */
			virtual Bool setIndicatorColor( const Color4f& newIndicatorColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Indicator Width Accessor Methods
			
			
			
			
			/// Return the width used when rendering a knob's rotation indicator.
			/**
			  * This width is expressed here as a fraction of the knob's radius
			  * and should lie between 0 and 1.
			  */
			virtual Float getIndicatorWidth() const = 0;
			
			
			
			
			
			/// Set the width used when rendering a knob's rotation indicator.
			/**
			  * This width is expressed here as a fraction of the knob's radius
			  * and should lie between 0 and 1.
			  *
			  * The method returns whether or not the knob indicator width was successfully changed.
			  */
			virtual Bool setIndicatorWidth( Float newIndicatorWidth ) = 0;
			
			
			
};




/// A short name for the interface of a class that draws a Knob.
typedef GUIObjectRenderer<Knob> KnobRenderer;




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_KNOB_RENDERER_H
