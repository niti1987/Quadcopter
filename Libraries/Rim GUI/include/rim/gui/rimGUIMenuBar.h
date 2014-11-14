/*
 *  rimGUIMenuBar.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 9/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_MENU_BAR_H
#define INCLUDE_RIM_GUI_MENU_BAR_H


#include "rimGUIConfig.h"


#include "rimGUIElement.h"
#include "rimGUIMenuItem.h"
#include "rimGUIMenuDelegate.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Window;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a set of drop-down menus that are displayed in a horizontal row.
class MenuBar : public GUIElement
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new menu bar with no name and no menu items.
			MenuBar();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a menu bar object and all state associated with it.
			/**
			  * The destructor for a menu bar should not be called until it is not being
			  * used as part of any active GUI.
			  */
			~MenuBar();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Menu Item Accessor Methods
			
			
			
			
			/// Return the number of menus that this menu bar has.
			Size getMenuCount() const;
			
			
			
			
			/// Get the menu at the specified index in this menu bar.
			/**
			  * If the specified index is invalid, a NULL pointer is returned.
			  * 
			  * @param index - the index of the menu to be retrieved.
			  * @return a pointer to the menu at the specified index.
			  */
			Pointer<Menu> getMenu( Index index ) const;
			
			
			
			
			/// Place the index of the specified menu in the output parameter and return if it was found.
			/**
			  * If the menu bar contains the specified menu, it places the index of that menu in
			  * the output index parameter and returns TRUE. Otherwise, if the menu is not found,
			  * the method returns FALSE and no index is retrieved.
			  */
			Bool getMenuIndex( const Menu* item, Index& index ) const;
			
			
			
			
			/// Add the specified menu to the end of the list of menus, placing it at the right side of the menu bar.
			/**
			  * If the new menu pointer is NULL, the add operation is ignored and FALSE is returned.
			  * Otherwise, the menu is added and TRUE is returned, indicating success.
			  * 
			  * @param newMenu - the menu to add to the end of the menu list.
			  */
			Bool addMenu( const Pointer<Menu>& newMenu );
			
			
			
			
			/// Insert the specified menu at the specified index in this menu bar.
			/**
			  * If the new menu pointer is NULL or if the specified insertion index is
			  * greater than the number of menus in the menu bar, FALSE is returned indicating that
			  * the insertion operation failed. Otherwise, TRUE is returned and the menu is inserted
			  * at the specified index.
			  * 
			  * @param newMenu - the menu to insert in the menu list.
			  * @param index - the index in the menu list at which to insert the new menu.
			  */
			Bool insertMenu( const Pointer<Menu>& newMenu, Index index );
			
			
			
			
			/// Set the specified menu at the specified index in the list of menus.
			/**
			  * This method replaces the menu at the specified index with a new menu.
			  * If the new menu pointer is NULL, the set operation is ignored.
			  * 
			  * @param newMenu - the menu to set in the menu item list.
			  * @param index - the index at which to set the new item.
			  */
			Bool setMenu( const Pointer<Menu>& newMenu, Index index );
			
			
			
			
			/// Remove the specified menu from this menu bar.
			/**
			  * If the menu pointer is NULL or if the specified menu is not contained
			  * in this menu bar, FALSE is returned indicating failure. Otherwise, that
			  * menu is removed and TRUE is returned.
			  * 
			  * @param menu - the menu to remove from the menu list.
			  * @return whether or not the remove operation was successful.
			  */
			Bool removeMenu( const Menu* menu );
			
			
			
			
			/// Remove the menu at the specified index in the menu list.
			/**
			  * If the specified index is invalid, FALSE is returned and the menu bar
			  * is unaltered. Otherwise, the menu at that index is removed and
			  * TRUE is returned.
			  * 
			  * @param index - the index at which to remove a menu from the menu bar.
			  * @return whether or not the remove operation was successful.
			  */
			Bool removeMenuAtIndex( Index index );
			
			
			
			
			/// Remove all menus from this menu bar.
			void clearMenus();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parent Window Accessor Methods
			
			
			
			
			/// Return a pointer to the window that this menu bar belongs to.
			/**
			  * This method returns a NULL pointer if the menu bar doesn't have a parent
			  * window. Use the hasParentWindow() function to detect if the menu bar
			  * has a parent window.
			  */
			Window* getParentWindow() const;
			
			
			
			
			/// Return whether or not this menu bar has a parent window.
			Bool hasParentWindow() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Platform-Specific Element Pointer Accessor Method
			
			
			
			
			/// Get a pointer to this menu bar's platform-specific internal representation.
			/**
			  * On Mac OS X, this method returns a pointer to a subclass of NSMenu which
			  * represents the menu bar.
			  *
			  * On Windows, this method returns
			  */
			virtual void* getInternalPointer() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Shared Construction Methods
			
			
			
			
			/// Create a shared-pointer menu bar object, calling the default constructor.
			RIM_INLINE static Pointer<MenuBar> construct()
			{
				return Pointer<MenuBar>( util::construct<MenuBar>() );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Menu Wrapper Class Declaration.
			
			
			
			
			/// A class which hides internal platform-specific state for a menu bar.
			class Wrapper;
			
			
			
			
			/// Declare the Window class as a friend so that it can make itself a parent privately.
			friend class Window;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Set a pointer to this menu bar's parent window.
			void setParentWindow( Window* window );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to an object which wraps internal platform-specific state for this menu bar.
			Wrapper* wrapper;
			
			
			
			
};



//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_MENU_BAR_H
