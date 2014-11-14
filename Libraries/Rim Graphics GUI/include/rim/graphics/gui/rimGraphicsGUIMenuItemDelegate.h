/*
 *  rimGraphicsGUIMenuItemDelegate.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/18/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_MENU_ITEM_DELEGATE_H
#define INCLUDE_RIM_GRAPHICS_GUI_MENU_ITEM_DELEGATE_H


#include "rimGraphicsGUIConfig.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class MenuItem;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve menu item events.
/**
  * Any menu-item-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the menu item
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, a menu item simply ignores it.
  */
class MenuItemDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	MenuItem Delegate Callback Functions
			
			
			
			
			/// A function object which is called whenever an attached menu item is selected by the user.
			Function<void ( MenuItem& item )> select;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_MENU_ITEM_DELEGATE_H
