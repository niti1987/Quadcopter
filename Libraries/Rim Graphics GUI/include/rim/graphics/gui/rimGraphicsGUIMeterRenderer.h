/*
 *  rimGraphicsGUIMeterRenderer.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/13/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_METER_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_GUI_METER_RENDERER_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObjectRenderer.h"
#include "rimGraphicsGUIFonts.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Meter;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles drawing Meter objects to a graphics rendering context.
template <>
class GUIObjectRenderer<Meter>
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
			virtual Bool render( GUIRenderer& renderer, const AABB2f& parentBounds, const Meter& meter ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Accessor Methods
			
			
			
			
			/// Return the background color for this meter's area.
			virtual Color4f getBackgroundColor() const = 0;
			
			
			
			
			
			/// Set the background color for this meter's area.
			/**
			  * The method returns whether or not the meter's background color was successfully changed.
			  */
			virtual Bool setBackgroundColor( const Color4f& newBackgroundColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a meter.
			virtual Color4f getBorderColor() const = 0;
			
			
			
			
			
			/// Set the border color used when rendering a meter.
			/**
			  * The method returns whether or not the meter border color was successfully changed.
			  */
			virtual Bool setBorderColor( const Color4f& newBorderColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Meter Color Accessor Methods
			
			
			
			
			/// Return the color used when rendering a meter's moving area.
			virtual Color4f getMeterColor() const = 0;
			
			
			
			
			
			/// Set the color used when rendering a meter's moving area.
			/**
			  * The method returns whether or not the meter color was successfully changed.
			  */
			virtual Bool setMeterColor( const Color4f& newMeterColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Meter Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a meter's moving area.
			virtual Color4f getMeterBorderColor() const = 0;
			
			
			
			
			
			/// Set the border color used when rendering a meter's moving area.
			/**
			  * The method returns whether or not the meter color was successfully changed.
			  */
			virtual Bool setMeterBorderColor( const Color4f& newMeterBorderColor ) = 0;
			
			
			
};




/// A short name for the interface of a class that draws a Meter.
typedef GUIObjectRenderer<Meter> MeterRenderer;




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_METER_RENDERER_H
