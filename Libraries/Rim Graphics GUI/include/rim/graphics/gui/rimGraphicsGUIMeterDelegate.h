/*
 *  rimGraphicsGUIMeterDelegate.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/13/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_METER_DELEGATE_H
#define INCLUDE_RIM_GRAPHICS_GUI_METER_DELEGATE_H


#include "rimGraphicsGUIConfig.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Meter;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve Meter events.
/**
  * Any meter-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the button
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, a meter simply ignores it.
  */
class MeterDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Meter Delegate Callback Functions
			
			
			
			
			/// A function object which is called whenever a meter's displayed value should update.
			/**
			  * The delegate function can provide a new value to the meter by writing
			  * the new value to the output parameter and returning TRUE, indicating that
			  * the new value should be used.
			  */
			Function<Bool ( Meter& meter, Float& newValue )> update;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_METER_DELEGATE_H
