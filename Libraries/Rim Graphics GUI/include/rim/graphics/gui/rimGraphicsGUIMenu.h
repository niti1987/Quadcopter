/*
 *  rimGraphicsGUIMenu.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/18/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_MENU_H
#define INCLUDE_RIM_GRAPHICS_GUI_MENU_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObject.h"
#include "rimGraphicsGUIMenuDelegate.h"
#include "rimGraphicsGUIMenuItem.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains a list of MenuItem objects that the user can select.
/**
  * Typically, a menu will be used to present a list of actions to the user
  * which the user can then select. This class can be used as popup-style menu
  * or as part of a MenuBar (such as at the top of a window).
  */
class Menu : public GUIObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default menu with no items.
			Menu();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return a string representing the title of this menu.
			/**
			  * This is the displayed name of the menu when it is part of a MenuBar
			  * or is a submenu of a MenuItem.
			  */
			RIM_INLINE const UTF8String& getTitle() const
			{
				return title;
			}
			
			
			
			
			/// Set a string representing the title of this menu.
			/**
			  * This is the displayed name of the menu when it is part of a MenuBar
			  * or is a submenu of a MenuItem.
			  */
			RIM_INLINE void setTitle( const UTF8String& newTitle )
			{
				title = newTitle;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Item Accessor Methods
			
			
			
			
			/// Return the total number of items that are part of this menu.
			RIM_INLINE Size getItemCount() const
			{
				return items.getSize();
			}
			
			
			
			
			/// Return a pointer to the item at the specified index in this menu.
			RIM_INLINE const Pointer<MenuItem>& getItem( Index itemIndex ) const
			{
				return items[itemIndex].item;
			}
			
			
			
			
			/// Add the specified item to this menu.
			/**
			  * If the specified item pointer is NULL, the method fails and FALSE
			  * is returned. Otherwise, the item is appended to the end of the menu
			  * and TRUE is returned.
			  */
			Bool addItem( const Pointer<MenuItem>& newItem );
			
			
			
			
			/// Insert the specified item at the given index in this menu.
			/**
			  * If the specified item pointer is NULL, the method fails and FALSE
			  * is returned. Otherwise, the item is inserted at the given index in the menu
			  * and TRUE is returned.
			  */
			Bool insertItem( Index itemIndex, const Pointer<MenuItem>& newItem );
			
			
			
			
			/// Replace the specified item at the given index in this menu.
			/**
			  * If the specified item pointer is NULL, the method fails and FALSE
			  * is returned. Otherwise, the item is inserted at the given index in the menu
			  * and TRUE is returned.
			  */
			Bool setItem( Index itemIndex, const Pointer<MenuItem>& newItem );
			
			
			
			
			/// Remove the specified item from this menu.
			/**
			  * If the given item is part of this menu, the method removes it
			  * and returns TRUE. Otherwise, if the specified item is not found,
			  * the method doesn't modify the menu and FALSE is returned.
			  */
			Bool removeItem( const MenuItem* oldItem );
			
			
			
			
			/// Remove the item at the specified index from this menu.
			/**
			  * If the specified index is invalid, FALSE is returned and the Menu
			  * is unaltered. Otherwise, the item at that index is removed and
			  * TRUE is returned.
			  */
			Bool removeItemAtIndex( Index itemIndex );
			
			
			
			
			/// Remove all items from this menu.
			void clearItems();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Selected Item Index Accesor Methods
			
			
			
			
			/// Return the index of the currently highlighted item in this menu.
			/**
			  * If there is no currently highlighted item, -1 is returned.
			  */
			RIM_INLINE Int getHighlightedItemIndex() const
			{
				return highlightedItemIndex;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Item Padding Accessor Methods
			
			
			
			
			/// Return the padding amount between each menu item in this menu.
			RIM_INLINE Float getItemPadding() const
			{
				return itemPadding;
			}
			
			
			
			
			/// Set the padding amount between each menu item in this menu.
			RIM_INLINE void setItemPadding( Float newPadding )
			{
				itemPadding = newPadding;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Item Bounding Box Accessor Methods
			
			
			
			
			/// Return the maximum width of any item's image within this menu.
			RIM_INLINE Float getMaxItemImageWidth() const
			{
				return maxItemImageWidth;
			}
			
			
			
			
			/// Return the maximum width of any item's text within this menu.
			RIM_INLINE Float getMaxItemTextWidth() const
			{
				return maxItemTextWidth;
			}
			
			
			
			
			/// Return the maximum width of any item's keyboard shortcut within this menu.
			RIM_INLINE Float getMaxItemShortcutWidth() const
			{
				return maxItemShortcutWidth;
			}
			
			
			
			
			/// Return the bounding box of the menu item with the specified index.
			RIM_INLINE const AABB2f& getItemBounds( Index itemIndex ) const
			{
				return items[itemIndex].bounds;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Accessor Methods
			
			
			
			
			/// Return a mutable object which describes the border for this menu's popup area.
			RIM_INLINE Border& getBorder()
			{
				return border;
			}
			
			
			
			
			/// Return an object which describes the border for this menu's popup area.
			RIM_INLINE const Border& getBorder() const
			{
				return border;
			}
			
			
			
			
			/// Set an object which describes the border for this menu's popup area.
			RIM_INLINE void setBorder( const Border& newBorder )
			{
				border = newBorder;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Accessor Methods
			
			
			
			
			/// Return the background color for this menu's main area.
			RIM_INLINE const Color4f& getBackgroundColor() const
			{
				return backgroundColor;
			}
			
			
			
			
			
			/// Set the background color for this menu's main area.
			RIM_INLINE void setBackgroundColor( const Color4f& newBackgroundColor )
			{
				backgroundColor = newBackgroundColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a menu.
			RIM_INLINE const Color4f& getBorderColor() const
			{
				return borderColor;
			}
			
			
			
			
			/// Set the border color used when rendering a menu.
			RIM_INLINE void setBorderColor( const Color4f& newBorderColor )
			{
				borderColor = newBorderColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Separator Color Accessor Methods
			
			
			
			
			/// Return the color used when rendering a menu item separator.
			RIM_INLINE const Color4f& getSeparatorColor() const
			{
				return separatorColor;
			}
			
			
			
			
			/// Set the color used when rendering a menu item separator.
			RIM_INLINE void setSeparatorColor( const Color4f& newSeparatorColor )
			{
				separatorColor = newSeparatorColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Separator Color Accessor Methods
			
			
			
			
			/// Return the color overlayed when a menu item is highlighted.
			RIM_INLINE const Color4f& getHighlightColor() const
			{
				return highlightColor;
			}
			
			
			
			
			/// Set the color overlayed when a menu item is highlighted.
			RIM_INLINE void setHighlightColor( const Color4f& newHighlightColor )
			{
				highlightColor = newHighlightColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Style Accessor Methods
			
			
			
			
			/// Return a reference to the font style which is used to render the text for a menu.
			RIM_INLINE const FontStyle& getTextStyle() const
			{
				return textStyle;
			}
			
			
			
			
			/// Set the font style which is used to render the text for a menu.
			RIM_INLINE void setTextStyle( const FontStyle& newTextStyle )
			{
				textStyle = newTextStyle;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Drawing Method
			
			
			
			
			/// Draw this menu using the specified GUI renderer to the given parent coordinate system bounds.
			/**
			  * The method returns whether or not the menu was successfully drawn.
			  */
			virtual Bool drawSelf( GUIRenderer& renderer, const AABB3f& parentBounds ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Input Handling Methods
			
			
			
			
			/// Handle the specified keyboard event for the entire menu.
			virtual void keyEvent( const KeyboardEvent& event );
			
			
			
			
			/// Handle the specified mouse motion event for the entire menu.
			virtual void mouseMotionEvent( const MouseMotionEvent& event );
			
			
			
			
			/// Handle the specified mouse button event for the entire menu.
			virtual void mouseButtonEvent( const MouseButtonEvent& event );
			
			
			
			
			/// Handle the specified mouse wheel event for the entire menu.
			virtual void mouseWheelEvent( const MouseWheelEvent& event );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return a reference to the delegate which responds to events for this menu.
			RIM_INLINE MenuDelegate& getDelegate()
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this menu.
			RIM_INLINE const MenuDelegate& getDelegate() const
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this menu.
			RIM_INLINE void setDelegate( const MenuDelegate& newDelegate )
			{
				delegate = newDelegate;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Construction Methods
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<Menu> construct()
			{
				return Pointer<Menu>::construct();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// The default padding to use between menu items of a menu.
			static const Float DEFAULT_ITEM_PADDING;
			
			
			/// The default border that is used for a menu.
			static const Border DEFAULT_BORDER;
			
			
			/// The default background color that is used for a menu's area.
			static const Color4f DEFAULT_BACKGROUND_COLOR;
			
			
			/// The default border color that is used for a menu.
			static const Color4f DEFAULT_BORDER_COLOR;
			
			
			/// The default separator color that is used for a menu.
			static const Color4f DEFAULT_SEPARATOR_COLOR;
			
			
			/// The default highlight color that is used for a menu.
			static const Color4f DEFAULT_HIGHLIGHT_COLOR;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which contains information about a single menu item that is part of a menu.
			class ItemInfo
			{
				public:
					
					/// Create a new item information object associated with the specified item.
					RIM_INLINE ItemInfo( const Pointer<MenuItem>& newItem )
						:	item( newItem )
					{
					}
					
					/// A pointer to the item associated with this item information object.
					Pointer<MenuItem> item;
					
					/// The bounding box of the item within the menu's coordinate system.
					AABB2f bounds;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A string representing the title of this menu.
			/**
			  * This is the displayed name of the menu when it is part of a MenuBar
			  * or is a submenu of a MenuItem.
			  */
			UTF8String title;
			
			
			
			
			/// A list of all of the items that are part of this menu.
			ArrayList<ItemInfo> items;
			
			
			
			
			/// The padding space between menu items.
			Float itemPadding;
			
			
			
			
			/// An object which describes the border for this menu's popup area.
			Border border;
			
			
			
			
			/// The background color for the menu's area.
			Color4f backgroundColor;
			
			
			
			
			/// The border color for the menu's background area.
			Color4f borderColor;
			
			
			
			
			/// The color to use when rendering menu separators.
			Color4f separatorColor;
			
			
			
			
			/// The color which is used to highlight selected menu items.
			Color4f highlightColor;
			
			
			
			
			/// An object which determines the style of the text for this menu's items.
			FontStyle textStyle;
			
			
			
			
			/// An object which contains function pointers that respond to menu events.
			MenuDelegate delegate;
			
			
			
			
			/// The index of the currently highlighted item, or -1 if no item is highlighted.
			Int highlightedItemIndex;
			
			
			
			
			/// A value which caches the maximum image width of this menu's items.
			mutable Float maxItemImageWidth;
			
			
			
			
			/// A value which caches the maximum text width of this menu's items.
			mutable Float maxItemTextWidth;
			
			
			
			
			/// A value which caches the maximum keyboard shortcut width of this menu's items.
			mutable Float maxItemShortcutWidth;
			
			
			
			
			/// A boolean value indicating whether or not the user has clicked the menu with the mouse.
			Bool mousePressed;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_MENU_H
