/*
 *  rimGraphicsGUIMenuDelegate.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/18/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_MENU_DELEGATE_H
#define INCLUDE_RIM_GRAPHICS_GUI_MENU_DELEGATE_H


#include "rimGraphicsGUIConfig.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Menu;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve menu events.
/**
  * Any menu-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the menu
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, a menu simply ignores it.
  */
class MenuDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Menu Delegate Callback Functions
			
			
			
			
			/// A function object which is called whenever an attached menu is opened by the user.
			Function<void ( Menu& menu )> open;
			
			
			
			
			/// A function object which is called whenever an attached menu is closed by the user.
			Function<void ( Menu& menu )> close;
			
			
			
			
			/// A function object which is called whenever an item with the given index is selected by the user.
			Function<void ( Menu& menu, Index itemIndex )> selectItem;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_MENU_DELEGATE_H
