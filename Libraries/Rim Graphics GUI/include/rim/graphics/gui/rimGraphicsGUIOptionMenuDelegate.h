/*
 *  rimGraphicsGUIOptionMenuDelegate.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/18/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_OPTION_MENU_DELEGATE_H
#define INCLUDE_RIM_GRAPHICS_GUI_OPTION_MENU_DELEGATE_H


#include "rimGraphicsGUIConfig.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class OptionMenu;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve option menu events.
/**
  * Any option-menu-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the option menu
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, an option menu simply ignores it.
  */
class OptionMenuDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Menu Delegate Callback Functions
			
			
			
			
			/// A function object which is called whenever an attached option menu is opened by the user.
			Function<void ( OptionMenu& menu )> open;
			
			
			
			
			/// A function object which is called whenever an attached option menu is closed by the user.
			Function<void ( OptionMenu& menu )> close;
			
			
			
			
			/// A function object which is called whenever an item with the given index is selected by the user.
			Function<void ( OptionMenu& menu, Index itemIndex )> selectItem;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_OPTION_MENU_DELEGATE_H
