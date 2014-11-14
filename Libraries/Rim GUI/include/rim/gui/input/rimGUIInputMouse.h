/*
 *  rimGUIInputMouse.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 2/1/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_INPUT_MOUSE_H
#define INCLUDE_RIM_GUI_INPUT_MOUSE_H


#include "rimGUIInputConfig.h"


#include "rimGUIInputMouseButton.h"
#include "rimGUIInputMouseButtonEvent.h"
#include "rimGUIInputMouseMotionEvent.h"
#include "rimGUIInputMouseWheelEvent.h"


//##########################################################################################
//************************     Start Rim GUI Input Namespace     ***************************
RIM_GUI_INPUT_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




class Mouse
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Position Accessor Methods
			
			
			
			
			/// Return the current position of the global system mouse pointer in screen-space pixels.
			/**
			  * This value is specified relative to the lower left corner of the main system display.
			  */
			static Vector2f getPosition();
			
			
			
			
			/// Move the global system mouse pointer to the specified screen-space position in pixels.
			/**
			  * This value is specified relative to the lower left corner of the main system display.
			  */
			static Bool setPosition( const Vector2f& newPosition );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Visibility State Accessor Methods
			
			
			
			
			/// Return whether or not the current global system mouse pointer is visible.
			static Bool getIsVisible();
			
			
			
			
			/// Set whether or not the current global system mouse pointer is visible.
			/**
			  * This method attempts to set the global system mouse pointer to be
			  * either visible or hidden based on the specified boolean value. If the
			  * visibility change operation is successful, TRUE is returned. Otherwise,
			  * false is returned and no visiblity is changed.
			  */
			static Bool setIsVisible( Bool newIsVisible );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
};




//##########################################################################################
//************************     End Rim GUI Input Namespace     *****************************
RIM_GUI_INPUT_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_INPUT_MOUSE_H
