/*
 *  rimGUITextFieldDelegate.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 9/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_TEXT_FIELD_DELEGATE_H
#define INCLUDE_RIM_GUI_TEXT_FIELD_DELEGATE_H


#include "rimGUIConfig.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class TextField;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve text field events.
/**
  * Any text field-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the GUI event thread 
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, a text field simply ignores it.
  * 
  * It must be noted that the callback functions are asynchronous and
  * not thread-safe. Thus, it is necessary to perform any additional synchronization
  * externally.
  */
class TextFieldDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Editing Callback Functions
			
			
			
			
			/// A function object which is called whenever the user changes the text in the text field.
			/**
			  * Every time that the user presses a key or does anything to change the contents
			  * of the text field, this method is called.
			  */
			Function<void ( TextField& )> edit;
			
			
			
			
			/// A function object which is called whenever the user is finished editing the text in a text field.
			/**
			  * This method will be called whenever the user presses the return key or 
			  * removes focus from the text field, indicating that they are finished editing the field
			  */
			Function<void ( TextField& )> finishEdit;
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_TEXT_FIELD_DELEGATE_H
