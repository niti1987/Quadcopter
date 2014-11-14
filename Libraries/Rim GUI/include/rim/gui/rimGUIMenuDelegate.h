/*
 *  rimGUIMenuDelegate.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 6/3/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_MENU_DELEGATE_H
#define INCLUDE_RIM_GUI_MENU_DELEGATE_H


#include "rimGUIConfig.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Menu;
class MenuItem;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve menu events.
/**
  * Any menu-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the GUI event thread 
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, a menu simply ignores it.
  * 
  * It must be noted that the callback functions are asynchronous and
  * not thread-safe. Thus, it is necessary to perform any additional synchronization
  * externally.
  */
class MenuDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Open/Close Callback Functions
			
			
			
			
			/// A function object which is called whenever an attached menu is opened by the user.
			Function<void ( Menu& )> open;
			
			
			
			
			/// A function object which is called whenever an attached menu is closed by the user.
			Function<void ( Menu& )> close;
			
			
			
			
			/// A function object which is called whenever an item in an attached menu is highlighted.
			Function<void ( Menu&, MenuItem& )> itemHighlight;
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_MENU_DELEGATE_H
