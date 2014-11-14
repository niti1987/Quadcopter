/*
 *  rimGraphicsGUIKnobDelegate.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/17/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_KNOB_DELEGATE_H
#define INCLUDE_RIM_GRAPHICS_GUI_KNOB_DELEGATE_H


#include "rimGraphicsGUIConfig.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Knob;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve Knob events.
/**
  * Any knob-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the knob
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, a knob simply ignores it.
  */
class KnobDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Knob Delegate Callback Functions
			
			
			
			
			/// A function object which is called whenever an attached knob has started to be changed by the user.
			Function<void ( Knob& knob )> startEdit;
			
			
			
			
			/// A function object which is called whenever an attached knob has finished being changed by the user.
			Function<void ( Knob& knob )> endEdit;
			
			
			
			
			/// A function object which is called whenever an attached knob is changed by the user.
			/**
			  * The delegate function has the option to allow or disallow the change to the
			  * slider's value by returning TRUE to allow or FALSE to not allow the change.
			  */
			Function<Bool ( Knob& knob, Float newValue )> edit;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_KNOB_DELEGATE_H
