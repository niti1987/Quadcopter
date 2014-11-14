/*
 *  rimGUIElementMenu.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 6/3/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_ELEMENT_MENU_H
#define INCLUDE_RIM_GUI_ELEMENT_MENU_H


#include "rimGUIConfig.h"


#include "rimGUIElement.h"
#include "rimGUIMenuItem.h"
#include "rimGUIMenuDelegate.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class MenuBar;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a dropdown menu that contains a series of menu items.
class Menu : public GUIElement
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new menu with no name and no menu items.
			Menu();
			
			
			
			
			/// Create a new menu with the specified name (title), and no menu items.
			Menu( const UTF8String& name );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a Menu object and all state associated with it.
			/**
			  * The destructor for a menu should not be called until it is not being
			  * used as part of any active GUI.
			  */
			~Menu();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Menu Item Accessor Methods
			
			
			
			
			/// Return the number of menu items that this Menu has.
			Size getItemCount() const;
			
			
			
			
			/// Get the menu item at the specified index in the Menu.
			/**
			  * If the specified index is invalid, a NULL pointer is returned.
			  * 
			  * @param index - the index of the menu item to be retrieved.
			  * @return a pointer to the menu item at the specified index.
			  */
			Pointer<MenuItem> getItem( Index index ) const;
			
			
			
			
			/// Place the index of the specified menu item in the output parameter and return if it was found.
			/**
			  * If the menu contains the specified menu item, it places the index of that item in
			  * the output index parameter and returns TRUE. Otherwise, if the menu item is not found,
			  * the method returns FALSE and no index is retrieved.
			  */
			Bool getItemIndex( const MenuItem* item, Index& index ) const;
			
			
			
			
			/// Add the specified MenuItem to the end of the list of items, placing it at the bottom of the Menu.
			/**
			  * If the new menu item pointer is NULL, the add operation is ignored and FALSE is returned.
			  * Otherwise, the menu item is added and TRUE is returned, indicating success.
			  * 
			  * @param newItem - the menu item to add to the end of the menu item list.
			  */
			Bool addItem( const Pointer<MenuItem>& newItem );
			
			
			
			
			/// Insert the specified MenuItem at the specified item index in this menu.
			/**
			  * If the new menu item pointer is NULL or if the specified insertion index is
			  * greater than the number of items in the menu, FALSE is returned indicating that
			  * the insertion operation failed. Otherwise, TRUE is returned and the item is inserted
			  * at the specified index.
			  * 
			  * @param newItem - the menu item to insert in the menu item list.
			  * @param index - the index in the menu item list at which to insert the new item.
			  */
			Bool insertItem( const Pointer<MenuItem>& newItem, Index index );
			
			
			
			
			/// Set the specified MenuItem at the specified index in the list of menu items.
			/**
			  * This method replaces the menu item at the specified index with a new menu
			  * item. If the new menu item pointer is NULL, the set operation is ignored.
			  * 
			  * @param newItem - the menu item to set in the menu item list.
			  * @param index - the index at which to set the new item.
			  */
			Bool setItem( const Pointer<MenuItem>& newItem, Index index );
			
			
			
			
			/// Remove the specified MenuItem from this Menu.
			/**
			  * If the menu item pointer is NULL or if the specified item is not contained
			  * in this menu, FALSE is returned indicating failure. Otherwise, that
			  * menu item is removed and TRUE is returned.
			  * 
			  * @param item - the menu item to remove from the menu item list.
			  * @return whether or not the remove operation was successful.
			  */
			Bool removeItem( const MenuItem* item );
			
			
			
			
			/// Remove the menu item at the specified index in the menu item list.
			/**
			  * If the specified index is invalid, FALSE is returned and the Menu
			  * is unaltered. Otherwise, the item at that index is removed and
			  * TRUE is returned.
			  * 
			  * @param index - the index at which to remove a menu item from the menu.
			  * @return whether or not the remove operation was successful.
			  */
			Bool removeItemAtIndex( Index index );
			
			
			
			
			/// Remove all menu items from this menu.
			void clearItems();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Menu Name Accessor Methods
			
			
			
			
			/// Return the name (title) of this Menu.
			UTF8String getName() const;
			
			
			
			
			/// Set the name (title) of this Menu.
			void setName( const UTF8String& newName );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Menu State Accessor Methods
			
			
			
			
			/// Return whether or not the menu is currently open, with the user in the process of selecting an item.
			Bool isOpen() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Get a reference to the delegate object associated with this menu item.
			const MenuDelegate& getDelegate() const;
			
			
			
			
			/// Set the delegate object to which this menu item sends events.
			void setDelegate( const MenuDelegate& delegate );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parent Object Accessor Methods
			
			
			
			
			/// Return a pointer to the menu bar that this menu belongs to.
			/**
			  * This method returns a NULL pointer if the menu doesn't have a parent
			  * menu bar. Use the hasParentMenuBar() function to detect if the menu
			  * has a parent menu bar.
			  */
			MenuBar* getParentMenuBar() const;
			
			
			
			
			/// Return whether or not this menu is part of a menu bar.
			Bool hasParentMenuBar() const;
			
			
			
			
			/// Return a pointer to the menu item that this menu belongs to.
			/**
			  * This method returns a NULL pointer if the menu doesn't have a parent
			  * menu item. Use the hasParentMenuItem() function to detect if the menu
			  * has a parent menu item.
			  */
			MenuItem* getParentMenuItem() const;
			
			
			
			
			/// Return whether or not this menu is a submenu of a menu item.
			Bool hasParentMenuItem() const;
			
			
			
			
			/// Return whether or not this menu has either a parent menu bar or parent menu item.
			Bool hasParent() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Platform-Specific Element Pointer Accessor Method
			
			
			
			
			/// Get a pointer to this menu's platform-specific internal representation.
			/**
			  * On Mac OS X, this method returns a pointer to a subclass of NSMenu which
			  * represents the menu.
			  *
			  * On Windows, this method returns
			  */
			virtual void* getInternalPointer() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Shared Construction Methods
			
			
			
			
			/// Create a shared-pointer menu object, calling the default constructor.
			RIM_INLINE static Pointer<Menu> construct()
			{
				return Pointer<Menu>( util::construct<Menu>() );
			}
			
			
			
			
			/// Create a shared-pointer menu object, calling the constructor with the same arguments.
			RIM_INLINE static Pointer<Menu> construct( const UTF8String& name )
			{
				return Pointer<Menu>( util::construct<Menu>( name ) );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations.
			
			
			
			
			/// A class which hides internal platform-specific state for a menu.
			class Wrapper;
			
			
			
			
			/// Declare the MenuBar class as a friend so that it can make itself a parent privately.
			friend class MenuBar;
			
			
			
			
			/// Declare the MenuItem class as a friend so that it can make itself a parent privately.
			friend class MenuItem;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Set a pointer to this menu's parent menu bar.
			void setParentMenuBar( MenuBar* menuBar );
			
			
			
			
			/// Set a pointer to this menu's parent menu item.
			void setParentMenuItem( MenuItem* menuItem );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to an object which wraps internal platform-specific state for this Menu.
			Wrapper* wrapper;
			
			
			
			
};



//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_MENU_H
