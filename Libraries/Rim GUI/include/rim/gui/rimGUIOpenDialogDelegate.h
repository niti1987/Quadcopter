/*
 *  rimGUIOpenDialogDelegate.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/29/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_OPEN_DIALOG_DELEGATE_H
#define INCLUDE_RIM_GUI_OPEN_DIALOG_DELEGATE_H


#include "rimGUIConfig.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class OpenDialog;



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve window events.
/**
  * Any window-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the GUI event thread 
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, a window simply ignores it.
  * 
  * It must be noted that the callback functions are asynchronous and
  * not thread-safe. Thus, it is necessary to perform any additional synchronization
  * externally.
  */
class OpenDialogDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Visibility Callback Functions
			
			
			
			
			/// A function object which is called when the user picks a path to open a file.
			/**
			  * The function should return whether or not the file was able to be opend.
			  */
			Function<Bool ( OpenDialog&, const UTF8String& )> open;
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_OPEN_DIALOG_DELEGATE_H
