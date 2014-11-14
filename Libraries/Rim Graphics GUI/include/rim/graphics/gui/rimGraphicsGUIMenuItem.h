/*
 *  rimGraphicsGUIMenuItem.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/18/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_MENU_ITEM_H
#define INCLUDE_RIM_GRAPHICS_GUI_MENU_ITEM_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObject.h"
#include "rimGraphicsGUIMenuItemDelegate.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Menu;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a selectable item which is part of a Menu.
/**
  * A menu item consists of an optional image, a text label, and a keyboard
  * shortcut.
  */
class MenuItem
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Menu Item Type Enum Declaration
			
			
			
			
			/// An enum type which specifies the different kinds of menu items.
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
			
			
			
			
			/// Create a new normal menu item with the specified text and keyboard shortcut.
			MenuItem( const UTF8String& newText, const KeyboardShortcut& shortcut = KeyboardShortcut() );
			
			
			
			
			/// Create a new normal menu item with the specified image, text and keyboard shortcut.
			MenuItem( const Pointer<GUIImage>& newImage, const UTF8String& newText,
					const KeyboardShortcut& shortcut = KeyboardShortcut() );
			
			
			
			
			/// Create a new menu item which uses the specified menu as a child menu.
			/**
			  * If the specified menu is NULL or if it already has a parent item or menu bar,
			  * the menu is not used and the submenu is unitialized.
			  */
			MenuItem( const Pointer<Menu>& menu );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Accessor Methods
			
			
			
			
			/// Return a reference to a string representing the text label of this menu item.
			RIM_INLINE const UTF8String& getText() const
			{
				return text;
			}
			
			
			
			
			/// Set a string representing the text label of this menu item.
			RIM_INLINE void setText( const UTF8String& newText )
			{
				text = newText;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Alignment Accessor Methods
			
			
			
			
			/// Return an object which describes how this menu item's text is aligned within the menu item's bounds.
			RIM_INLINE const Origin& getTextAlignment() const
			{
				return textAlignment;
			}
			
			
			
			
			/// Set an object which describes how this menu item's text is aligned within the menu item's bounds.
			RIM_INLINE void setTextAlignment( const Origin& newTextAlignment )
			{
				textAlignment = newTextAlignment;
			}
			
			
			
			
			/// Set an object which describes how this menu item's text is aligned within the menu item's bounds.
			RIM_INLINE void setTextAlignment( Origin::XOrigin newXOrigin,
												Origin::YOrigin newYOrigin )
			{
				textAlignment = Origin( newXOrigin, newYOrigin );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Visibility Accessor Methods
			
			
			
			
			/// Return a boolean value indicating whether or not this menu item's text label is displayed.
			RIM_INLINE Bool getTextIsVisible() const
			{
				return textIsVisible;
			}
			
			
			
			
			/// Set a boolean value indicating whether or not this menu item's text label is displayed.
			RIM_INLINE void setTextIsVisible( Bool newTextIsVisible )
			{
				textIsVisible = newTextIsVisible;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Accessor Methods
			
			
			
			
			/// Return a reference to the image which is displayed in the menu item's content area when in its normal state.
			RIM_INLINE const Pointer<GUIImage>& getImage() const
			{
				return image;
			}
			
			
			
			
			/// Set the image which is displayed in the menu item's content area when in its normal state.
			RIM_INLINE void setImage( const Pointer<GUIImage>& newImage )
			{
				image = newImage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Alignment Accessor Methods
			
			
			
			
			/// Return an object which describes how this menu item's image is aligned within the menu item's bounds.
			RIM_INLINE const Origin& getImageAlignment() const
			{
				return imageAlignment;
			}
			
			
			
			
			/// Set an object which describes how this menu item's image is aligned within the menu item's bounds.
			RIM_INLINE void setImageAlignment( const Origin& newImageAlignment )
			{
				imageAlignment = newImageAlignment;
			}
			
			
			
			
			/// Set an object which describes how this menu item's image is aligned within the menu item's bounds.
			RIM_INLINE void setImageAlignment( Origin::XOrigin newXOrigin,
												Origin::YOrigin newYOrigin )
			{
				imageAlignment = Origin( newXOrigin, newYOrigin );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Visibility Accessor Methods
			
			
			
			
			/// Return a boolean value indicating whether or not this menu item's image is displayed.
			RIM_INLINE Bool getImageIsVisible() const
			{
				return imageIsVisible;
			}
			
			
			
			
			/// Set a boolean value indicating whether or not this menu item's image is displayed.
			RIM_INLINE void setImageIsVisible( Bool newImageIsVisible )
			{
				imageIsVisible = newImageIsVisible;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Menu Accessor Methods
			
			
			
			
			/// Return whether or not this menu item has a child menu associated with it.
			/**
			  * This method always returns FALSE is this menu item is a separator or a
			  * normal menu item.
			  */
			RIM_INLINE Bool hasMenu() const
			{
				return menu.isSet();
			}
			
			
			
			
			/// Return a pointer to the child menu associated with this menu item.
			/**
			  * If there is no such menu, a NULL pointer is returned.
			  */
			RIM_INLINE const Pointer<Menu>& getMenu() const
			{
				return menu;
			}
			
			
			
			
			/// Set the child menu which should be associated with this menu item.
			/**
			  * If the specified menu pointer is NULL, this has the effect of clearing
			  * any existing child menu from this menu item.
			  */
			void setMenu( const Pointer<Menu>& newMenu );
			
			
			
			
			/// Remove any child menu that was associated with this menu item.
			void removeMenu();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Keyboard Shortcut Accessor Methods
			
			
			
			
			/// Return an object which describes the keyboard shortcut to use for this menu item.
			const KeyboardShortcut& getKeyboardShortcut() const
			{
				return shortcut;
			}
			
			
			
			
			/// Set an object which describes the keyboard shortcut to use for this menu item.
			void setKeyboardShortcut( const KeyboardShortcut& newShortcut )
			{
				shortcut = newShortcut;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Type Accessor Methods
			
			
			
			
			/// Return an enum value indicating the type of menu item that this is.
			/**
			  * The type of a menu item determines how it will be displayed and how
			  * it may be interacted with by the user. Any item attributes that are
			  * irrelevant for a given item type are simply ignored.
			  */
			RIM_INLINE Type getType() const
			{
				return type;
			}
			
			
			
			
			/// Set an enum value indicating the type of menu item that this is.
			/**
			  * The type of a menu item determines how it will be displayed and how
			  * it may be interacted with by the user. Any item attributes that are
			  * irrelevant for a given item type are simply ignored.
			  */
			RIM_INLINE void setType( Type newType )
			{
				type = newType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	MenuItem State Accessor Methods
			
			
			
			
			/// Return whether or not this menu item is currently active.
			/**
			  * An enabled menu item (the default) can be interacted with by the user
			  * and is displayed normally. A disabled menu item can't be selected by the
			  * user and displays more transparently, indicating its state.
			  */
			RIM_INLINE Bool getIsEnabled() const
			{
				return isEnabled && type != SEPARATOR;
			}
			
			
			
			
			/// Set whether or not this menu item is currently active.
			/**
			  * An enabled menu item (the default) can be interacted with by the user
			  * and is displayed normally. A disabled menu item can't be selected by the
			  * user and displays more transparently, indicating its state.
			  */
			RIM_INLINE void setIsEnabled( Bool newIsEnabled )
			{
				isEnabled = newIsEnabled;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return a reference to the delegate which responds to events for this menu item.
			RIM_INLINE MenuItemDelegate& getDelegate()
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this menu item.
			RIM_INLINE const MenuItemDelegate& getDelegate() const
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this menu item.
			RIM_INLINE void setDelegate( const MenuItemDelegate& newDelegate )
			{
				delegate = newDelegate;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Construction Methods
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<MenuItem> construct( Type newType = NORMAL )
			{
				return Pointer<MenuItem>( rim::util::construct<MenuItem>( newType ) );
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<MenuItem> construct( const UTF8String& newText,
															const KeyboardShortcut& newShortcut = KeyboardShortcut() )
			{
				return Pointer<MenuItem>( rim::util::construct<MenuItem>( newText, newShortcut ) );
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<MenuItem> construct( const Pointer<GUIImage>& newImage, const UTF8String& newText,
														const KeyboardShortcut& newShortcut = KeyboardShortcut() )
			{
				return Pointer<MenuItem>( rim::util::construct<MenuItem>( newImage, newText, newShortcut ) );
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<MenuItem> construct( const Pointer<Menu>& newMenu )
			{
				return Pointer<MenuItem>( rim::util::construct<MenuItem>( newMenu ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members

			
			
			
			/// The default alignment that is used for a menu item's text label.
			static const Origin DEFAULT_TEXT_ALIGNMENT;
			
			
			/// The default alignment that is used for a menu item's image label.
			static const Origin DEFAULT_IMAGE_ALIGNMENT;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value which indicates the type of this menu item.
			Type type;
			
			
			
			
			/// A string representing the text label of this menu item.
			UTF8String text;
			
			
			
			
			/// An image which is displayed within the content rectangle of this menu item.
			Pointer<GUIImage> image;
			
			
			
			
			/// An object which describes how this menu item's text is aligned within the menu item.
			Origin textAlignment;
			
			
			
			
			/// An object which describes how this menu item's image is aligned within the menu item.
			Origin imageAlignment;
			
			
			
			
			/// A pointer to the menu which is a child menu of this menu item.
			Pointer<Menu> menu;
			
			
			
			
			/// An object which contains function pointers that respond to menu item events.
			MenuItemDelegate delegate;
			
			
			
			
			/// An object representing the keyboard shortcut to use for this menu item.
			KeyboardShortcut shortcut;
			
			
			
			
			/// A boolean value indicating whether or not this menu item's text label is visible.
			Bool textIsVisible;
			
			
			
			
			/// A boolean value indicating whether or not this menu item's image is visible.
			Bool imageIsVisible;
			
			
			
			
			/// A boolean value indicating whether or not this menu item is enabled and able to be selected.
			Bool isEnabled;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_MENU_ITEM_H
