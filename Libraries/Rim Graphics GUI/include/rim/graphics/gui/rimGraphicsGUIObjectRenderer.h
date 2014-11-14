/*
 *  rimGraphicsGUIObjectRenderer.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/22/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_OBJECT_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_GUI_OBJECT_RENDERER_H


#include "rimGraphicsGUIBase.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class GUIRenderer;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles drawing GUI objects to a graphics rendering context.
template < typename ObjectType >
class GUIObjectRenderer
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
			
			
			
			
			/// Draw an object using the specified renderer within the given pixel coordinate bounds.
			/**
			  * This method should be implemented by a subclass so that it draws the given
			  * object to the specified rectangle on the screen. The size of the bounding
			  * box may not match the size of the object being rendered, in which case the
			  * renderer should automatically scale its output to fit within the bounding box.
			  * The bounding box is specified in viewport pixel coordinates, where (0,0) is the
			  * lower left corner of the screen.
			  *
			  * This effect is used to produce resolution independent rendering - a higher-level
			  * system can scale the rendering of an entire GUI based on the required output resolution.
			  *
			  * The method should return whether or not the object was able to be successfully drawn.
			  */
			virtual Bool render( GUIRenderer& renderer, const AABB2f& pixelBounds, const ObjectType& object ) const = 0;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_OBJECT_RENDERER_H
