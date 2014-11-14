/*
 *  rimGraphicsGUISliderDelegate.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/8/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_SLIDER_DELEGATE_H
#define INCLUDE_RIM_GRAPHICS_GUI_SLIDER_DELEGATE_H


#include "rimGraphicsGUIConfig.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Slider;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve Slider events.
/**
  * Any slider-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the slider
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, a slider simply ignores it.
  */
class SliderDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Slider Delegate Callback Functions
			
			
			
			
			/// A function object which is called whenever an attached slider has started to be changed by the user.
			Function<void ( Slider& slider )> startEdit;
			
			
			
			
			/// A function object which is called whenever an attached slider has finished being changed by the user.
			Function<void ( Slider& slider )> endEdit;
			
			
			
			
			/// A function object which is called whenever an attached slider is changed by the user.
			/**
			  * The delegate function has the option to allow or disallow the change to the
			  * slider's value by returning TRUE to allow or FALSE to not allow the change.
			  */
			Function<Bool ( Slider& slider, Float newValue )> edit;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_SLIDER_DELEGATE_H
