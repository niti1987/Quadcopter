/*
 *  rimGraphicsGUISliderRenderer.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/8/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_SLIDER_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_GUI_SLIDER_RENDERER_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObjectRenderer.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Slider;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles drawing Slider objects to a graphics rendering context.
template <>
class GUIObjectRenderer<Slider>
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
			virtual Bool render( GUIRenderer& renderer, const AABB2f& parentBounds, const Slider& slider ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Accessor Methods
			
			
			
			
			/// Return the background color for this slider's area.
			virtual Color4f getBackgroundColor() const = 0;
			
			
			
			
			
			/// Set the background color for this slider's area.
			/**
			  * The method returns whether or not the slider's background color was successfully changed.
			  */
			virtual Bool setBackgroundColor( const Color4f& newBackgroundColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a slider.
			virtual Color4f getBorderColor() const = 0;
			
			
			
			
			
			/// Set the border color used when rendering a slider.
			/**
			  * The method returns whether or not the slider border color was successfully changed.
			  */
			virtual Bool setBorderColor( const Color4f& newBorderColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Slider Color Accessor Methods
			
			
			
			
			/// Return the color used when rendering a slider's moving area.
			virtual Color4f getSliderColor() const = 0;
			
			
			
			
			
			/// Set the color used when rendering a slider's moving area.
			/**
			  * The method returns whether or not the slider color was successfully changed.
			  */
			virtual Bool setSliderColor( const Color4f& newSliderColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Slider Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a slider's moving area.
			virtual Color4f getSliderBorderColor() const = 0;
			
			
			
			
			
			/// Set the border color used when rendering a slider's moving area.
			/**
			  * The method returns whether or not the slider color was successfully changed.
			  */
			virtual Bool setSliderBorderColor( const Color4f& newSliderBorderColor ) = 0;
			
			
			
};




/// A short name for the interface of a class that draws a Slider.
typedef GUIObjectRenderer<Slider> SliderRenderer;




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_SLIDER_RENDERER_H
