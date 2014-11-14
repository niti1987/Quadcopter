/*
 *  rimGraphicsGUIOptionMenu.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/18/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_OPTION_MENU_H
#define INCLUDE_RIM_GRAPHICS_GUI_OPTION_MENU_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObject.h"
#include "rimGraphicsGUIOptionMenuDelegate.h"
#include "rimGraphicsGUIMenu.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which allows the user to select from a list of options using a menu.
/**
  * Each item is represented by a MenuItem.
  */
class OptionMenu : public GUIObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new option menu with no width or height positioned at the origin.
			OptionMenu();
			
			
			
			
			/// Create a new empty option menu which occupies the specified rectangular region.
			OptionMenu( const Rectangle& newRectangle );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Item Accessor Methods
			
			
			
			
			/// Return the total number of items that are part of this option menu.
			RIM_INLINE Size getItemCount() const
			{
				return menu.getItemCount();
			}
			
			
			
			
			/// Return a pointer to the item at the specified index in this option menu.
			RIM_INLINE const Pointer<MenuItem>& getItem( Index itemIndex ) const
			{
				return menu.getItem( itemIndex );
			}
			
			
			
			
			/// Add the specified item to this option menu.
			/**
			  * If the specified item pointer is NULL, the method fails and FALSE
			  * is returned. Otherwise, the item is appended to the end of the menu
			  * and TRUE is returned.
			  */
			RIM_INLINE Bool addItem( const Pointer<MenuItem>& newItem )
			{
				if ( newItem.isNull() || newItem->getType() == MenuItem::MENU )
					return false;
				
				return menu.addItem( newItem );
			}
			
			
			
			
			/// Insert the specified item at the given index in this option menu.
			/**
			  * If the specified item pointer is NULL, the method fails and FALSE
			  * is returned. Otherwise, the item is inserted at the given index in the menu
			  * and TRUE is returned.
			  */
			RIM_INLINE Bool insertItem( Index itemIndex, const Pointer<MenuItem>& newItem )
			{
				if ( newItem.isNull() || newItem->getType() == MenuItem::MENU )
					return false;
				
				return menu.insertItem( itemIndex, newItem );
			}
			
			
			
			
			/// Replace the specified item at the given index in this option menu.
			/**
			  * If the specified item pointer is NULL or if the item has an invalid type,
			  * the method fails and FALSE is returned. Otherwise, the item is inserted
			  * at the given index in the menu and TRUE is returned.
			  */
			RIM_INLINE Bool setItem( Index itemIndex, const Pointer<MenuItem>& newItem )
			{
				if ( newItem.isNull() || newItem->getType() == MenuItem::MENU )
					return false;
				
				return menu.setItem( itemIndex, newItem );
			}
			
			
			
			
			/// Remove the specified item from this option menu.
			/**
			  * If the given item is part of this menu, the method removes it
			  * and returns TRUE. Otherwise, if the specified item is not found,
			  * the method doesn't modify the menu and FALSE is returned.
			  */
			Bool removeItem( const MenuItem* oldItem )
			{
				return menu.removeItem( oldItem );
			}
			
			
			
			
			/// Remove the item at the specified index from this option menu.
			/**
			  * If the specified index is invalid, FALSE is returned and the Menu
			  * is unaltered. Otherwise, the item at that index is removed and
			  * TRUE is returned.
			  */
			RIM_INLINE Bool removeItemAtIndex( Index itemIndex )
			{
				return menu.removeItemAtIndex( itemIndex );
			}
			
			
			
			
			/// Remove all items from this option menu.
			RIM_INLINE void clearItems()
			{
				menu.clearItems();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Selected Menu Index Accesor Methods
			
			
			
			
			/// Return the index of the currently highlighted item in this option menu.
			/**
			  * If there is no currently highlighted item, -1 is returned.
			  */
			RIM_INLINE Int getHighlightedItemIndex() const
			{
				return menu.getHighlightedItemIndex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Item Padding Accessor Methods
			
			
			
			
			/// Return the padding amount between each item in this option menu.
			RIM_INLINE Float getItemPadding() const
			{
				return menu.getItemPadding();
			}
			
			
			
			
			/// Set the padding amount between each item in this option menu.
			RIM_INLINE void setItemPadding( Float newPadding )
			{
				menu.setItemPadding( newPadding );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Selected Item Index Accesor Methods
			
			
			
			
			/// Return the index of the currently selected item in this menu.
			/**
			  * If there is no currently selected item, -1 is returned.
			  */
			RIM_INLINE Int getSelectedItemIndex() const
			{
				return selectedItemIndex;
			}
			
			
			
			
			/// Set the index of the currently selected item in this menu.
			/**
			  * If an invalid index is specified, such as -1, the selected item is cleared.
			  */
			RIM_INLINE void setSelectedItemIndex( Int newSelectedItemIndex )
			{
				if ( newSelectedItemIndex < -1 || newSelectedItemIndex >= (Int)menu.getItemCount() )
					selectedItemIndex = -1;
				else
					selectedItemIndex = newSelectedItemIndex;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Menu Status Accessor Methods
			
			
			
			
			/// Return whether or not this option menu is currently open, with the popup menu showing.
			RIM_INLINE Bool getIsOpen() const
			{
				return isOpen;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Menu Accessor Methods
			
			
			
			
			/// Return a const reference to the menu object for this option menu.
			/**
			  * This method is provided primarily so that renderers can access the menu
			  * to draw it. The returned object should not be modified directly.
			  */
			RIM_INLINE const Menu& getMenu() const
			{
				return menu;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Accessor Methods
			
			
			
			
			/// Return a mutable object which describes this option menu's border.
			RIM_INLINE Border& getBorder()
			{
				return border;
			}
			
			
			
			
			/// Return an object which describes this option menu's border.
			RIM_INLINE const Border& getBorder() const
			{
				return border;
			}
			
			
			
			
			/// Set an object which describes this option menu's border.
			RIM_INLINE void setBorder( const Border& newBorder )
			{
				border = newBorder;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return a reference to the delegate which responds to events for this option menu.
			RIM_INLINE OptionMenuDelegate& getDelegate()
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this option menu.
			RIM_INLINE const OptionMenuDelegate& getDelegate() const
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this option menu.
			RIM_INLINE void setDelegate( const OptionMenuDelegate& newDelegate )
			{
				delegate = newDelegate;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Accessor Methods
			
			
			
			
			/// Return the background color for this option menu's main area.
			RIM_INLINE const Color4f& getBackgroundColor() const
			{
				return backgroundColor;
			}
			
			
			
			
			
			/// Set the background color for this option menu's main area.
			RIM_INLINE void setBackgroundColor( const Color4f& newBackgroundColor )
			{
				backgroundColor = newBackgroundColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a option menu.
			RIM_INLINE const Color4f& getBorderColor() const
			{
				return borderColor;
			}
			
			
			
			
			/// Set the border color used when rendering a option menu.
			RIM_INLINE void setBorderColor( const Color4f& newBorderColor )
			{
				borderColor = newBorderColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Style Accessor Methods
			
			
			
			
			/// Return a reference to the font style which is used to render the text for a option menu.
			RIM_INLINE const FontStyle& getTextStyle() const
			{
				return textStyle;
			}
			
			
			
			
			/// Set the font style which is used to render the text for a option menu.
			RIM_INLINE void setTextStyle( const FontStyle& newTextStyle )
			{
				textStyle = newTextStyle;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Drawing Method
			
			
			
			
			/// Draw this option menu using the specified GUI renderer to the given parent coordinate system bounds.
			/**
			  * The method returns whether or not the option menu was successfully drawn.
			  */
			virtual Bool drawSelf( GUIRenderer& renderer, const AABB3f& parentBounds ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Input Handling Methods
			
			
			
			
			/// Handle the specified keyboard event for the entire option menu.
			virtual void keyEvent( const KeyboardEvent& event );
			
			
			
			
			/// Handle the specified mouse motion event for the entire option menu.
			virtual void mouseMotionEvent( const MouseMotionEvent& event );
			
			
			
			
			/// Handle the specified mouse button event for the entire option menu.
			virtual void mouseButtonEvent( const MouseButtonEvent& event );
			
			
			
			
			/// Handle the specified mouse wheel event for the entire option menu.
			virtual void mouseWheelEvent( const MouseWheelEvent& event );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Construction Methods
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<OptionMenu> construct()
			{
				return Pointer<OptionMenu>::construct();
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<OptionMenu> construct( const Rectangle& newRectangle )
			{
				return Pointer<OptionMenu>::construct( newRectangle );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// The default border that is used for an option menu.
			static const Border DEFAULT_BORDER;
			
			
			/// The default background color that is used for an option menu's area.
			static const Color4f DEFAULT_BACKGROUND_COLOR;
			
			
			/// The default border color that is used for an option menu.
			static const Color4f DEFAULT_BORDER_COLOR;
			
			
			/// The default color for the down arrow for an option menu.
			static const Color4f DEFAULT_ARROW_COLOR;
			
			
			/// The default color for the down arrow divider line for an option menu.
			static const Color4f DEFAULT_DIVIDER_COLOR;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Return the bounding box of the child menu of this option menu in its local coordinate frame.
			RIM_INLINE AABB2f getLocalMenuBounds() const
			{
				const Vector3f& menuSize = menu.getSize();
				
				return AABB2f( Float(0), menuSize.x, -menuSize.y, Float(0) );
			}
			
			
			
			
			/// Change whether or not the option menu's popup menu is open, sending any necessary delegate events.
			void setIsOpen( Bool newIsOpen );
			
			
			
			
			/// A callback method called when a menu item is selected.
			void selectMenuItem( Menu& menu, Index itemIndex );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The menu object which is used to implement most of the option menu functionality.
			Menu menu;
			
			
			
			
			/// An object which describes the border for this option menu.
			Border border;
			
			
			
			
			/// An object which contains function pointers that respond to option menu events.
			OptionMenuDelegate delegate;
			
			
			
			
			/// The index of the currently selected menu item, or -1 if there is no selected item.
			Int selectedItemIndex;
			
			
			
			
			/// The background color for the option menu's area.
			Color4f backgroundColor;
			
			
			
			
			/// The border color for the option menu's background area.
			Color4f borderColor;
			
			
			
			
			/// The color for the down arrow image for this option menu.
			Color4f arrowColor;
			
			
			
			
			/// The color for the down arrow divider line for this option menu.
			Color4f dividerColor;
			
			
			
			
			/// An object which determines the style of the text for this option menu's items.
			FontStyle textStyle;
			
			
			
			
			/// The image of a downward arrow which is used when rendering an option menu.
			Pointer<GUIImage> downArrowImage;
			
			
			
			
			/// A boolean value indicating whether or not this option menu is currently open.
			Bool isOpen;
			
			
			
			
			/// A boolean value indicating whether or not the user has clicked the option menu with the mouse.
			Bool mousePressed;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_OPTION_MENU_H
