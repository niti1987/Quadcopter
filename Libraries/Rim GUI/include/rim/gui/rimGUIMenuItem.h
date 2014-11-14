/*
 *  rimGUIElementMenuItem.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 6/3/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_MENU_ITEM_H
#define INCLUDE_RIM_GUI_MENU_ITEM_H


#include "rimGUIConfig.h"


#include "rimGUIInput.h"
#include "rimGUIElement.h"
#include "rimGUIMenuItemDelegate.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Menu;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a single item of a drop-down GUI menu.
class MenuItem : public GUIElement
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Menu Item Type Enum Declaration
			
			
			
			
			/// An enum type which specifies special kinds of menu items.
			typedef enum Type
			{
				/// A menu item type that represents a normal menu item.
				NORMAL = 0,
				
				/// A menu item type that represents an item that has a submenu.
				MENU,
				
				/// A menu item type that represents a menu separator.
				/**
				  * A menu item separator is a type of item that is usually drawn as a 
				  * horizontal line which is used to break up groups of menu items
				  * in long menus.
				  */
				SEPARATOR
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new menu item with the specified specialized type.
			/**
			  * This constructor allows one to create menu items that represent
			  * special kinds of items - separators, etc - that aren't able to be
			  * represented easily another way.
			  */
			MenuItem( Type newType = NORMAL );
			
			
			
			
			/// Create a new normal menu item with the specified name string and no keyboard shortcut.
			/**
			  * This menu item is enabled by default.
			  */
			MenuItem( const UTF8String& name );
			
			
			
			
			/// Create a new normal menu item with the specified name string and keyboard shortcut.
			/**
			  * This constructor allows one to specify if the menu item should be enabled or not.
			  * The default behavior if the parameter is ommitted is for the item to be enabled.
			  */
			MenuItem( const UTF8String& name, const input::KeyboardShortcut& shortcut, Bool isEnabled = true );
			
			
			
			
			/// Create a new submenu menu item which uses the specified menu as a submenu.
			/**
			  * If the specified menu is NULL or if it already has a parent item or menu bar,
			  * the menu is not used and the submenu is unitialized.
			  */
			MenuItem( const Pointer<Menu>& menu );
			
			
			
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a menu item and release all internal state.
			/**
			  * The destructor for a menu item should not be called until it is not being
			  * used as part of any active GUI.
			  */
			~MenuItem();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Submenu Accessor Methods
			
			
			
			
			/// Return whether or not this menu item has a child menu associated with it.
			/**
			  * This method always returns FALSE is this menu item is a separator or a
			  * normal menu item.
			  */
			Bool hasMenu() const;
			
			
			
			
			/// Return a pointer to the child menu associated with this menu item.
			/**
			  * If there is no such menu, or if this menu item's type doesn't allow it
			  * to have a child menu, a NULL pointer is returned.
			  */
			Pointer<Menu> getMenu() const;
			
			
			
			
			/// Set the child menu which should be associated with this menu item.
			/**
			  * If the specified menu pointer is NULL, this has the effect of clearing
			  * any existing child menu from this menu item. The method returns whether
			  * or not the menu set operation was successful - it can fail if this menu
			  * item is a separator or normal menu item, since they can't have child menus.
			  */
			Bool setMenu( const Pointer<Menu>& newSubmenu );
			
			
			
			
			/// Remove any child menu that was associated with this menu item.
			void removeMenu();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Keyboard Shortcut Accessor Methods
			
			
			
			
			/// Return an object which describes the keyboard shortcut to use for this menu item.
			const input::KeyboardShortcut& getKeyboardShortcut() const;
			
			
			
			
			/// Set an object which describes the keyboard shortcut to use for this menu item.
			/**
			  * The method returns whether or not the keyboard shortcut was accepted as being
			  * valid. A shortcut can fail validation if it uses a modifier key combination that
			  * is not valid or if the menu item has a type that does not support a keyboard
			  * shortcut.
			  */
			Bool setKeyboardShortcut( const input::KeyboardShortcut& shortcut );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return a string representing the name of this menu item.
			/**
			  * If this item is a separator menu item, this method always returns
			  * an empty string.
			  */
			UTF8String getName() const;
			
			
			
			
			/// Set a string which specifies a new name for this menu item.
			/**
			  * If this item is a type of menu item that can't have a name (such as a separator),
			  * or if the name change operation is not successful, FALSE is returned.
			  * Otherwise, the name of the menu item is changed and TRUE is returned.
			  */
			Bool setName( const UTF8String& newName );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return a reference to the delegate object associated with this menu item.
			const MenuItemDelegate& getDelegate() const;
			
			
			
			
			/// Set the delegate object to which this menu item sends events.
			void setDelegate( const MenuItemDelegate& delegate );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	State Accessor Methods
			
			
			
			
			/// Return whether or not this menu item is currently able to be selected by the user.
			Bool getIsEnabled() const;
			
			
			
			
			/// Set whether or not this menu item should be able to be selected by the user.
			/**
			  * The method returns whether or not the state of the menu item was able to
			  * be changed.
			  */
			Bool setIsEnabled( Bool newIsEnabled );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Type Accessor Methods
			
			
			
			
			/// Return an enum value indicating the type of this menu item.
			/**
			  * The type of a menu item is determined at construction and cannot be changed.
			  */
			Type getType() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parent Menu Accessor Methods
			
			
			
			
			/// Return a pointer to the menu that this menu item belongs to.
			/**
			  * This method returns a NULL pointer if the menu item doesn't have a parent
			  * menu. Use the hasParentMenu() function to detect if the menu item
			  * has a parent menu.
			  */
			Menu* getParentMenu() const;
			
			
			
			
			/// Return whether or not this menu item is part of a menu.
			Bool hasParentMenu() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Platform-Specific Element Pointer Accessor Method
			
			
			
			
			/// Get a pointer to this menu item's platform-specific internal representation.
			/**
			  * On Mac OS X, this method returns a pointer to a subclass of NSMenuItem which
			  * represents the menu item.
			  *
			  * On Windows, this method returns
			  */
			virtual void* getInternalPointer() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Shared Construction Methods
			
			
			
			
			/// Create a shared-pointer menu item object, calling the constructor with the same arguments.
			RIM_INLINE static Pointer<MenuItem> construct( Type type )
			{
				return Pointer<MenuItem>( util::construct<MenuItem>( type ) );
			}
			
			
			
			
			/// Create a shared-pointer menu item object, calling the constructor with the same arguments.
			RIM_INLINE static Pointer<MenuItem> construct( const UTF8String& name )
			{
				return Pointer<MenuItem>( util::construct<MenuItem>( name ) );
			}
			
			
			
			
			/// Create a shared-pointer menu item object, calling the constructor with the same arguments.
			RIM_INLINE static Pointer<MenuItem> construct( const UTF8String& name,
															const input::KeyboardShortcut& shortcut,
															Bool enabled = true )
			{
				return Pointer<MenuItem>( util::construct<MenuItem>( name, shortcut, enabled ) );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Wrapper Class Declaration
			
			
			
			
			/// A class which wraps platform-specific state for a menu item.
			class Wrapper;
			
			
			
			
			/// Allow the Menu class to set itself as the parent of this menu item privately.
			friend class Menu;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Set a pointer to this menu item's parent menu.
			void setParentMenu( Menu* menu );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to an object which wraps platform-specific state for this menu item.
			Wrapper* wrapper;
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_MENU_ITEM_H
