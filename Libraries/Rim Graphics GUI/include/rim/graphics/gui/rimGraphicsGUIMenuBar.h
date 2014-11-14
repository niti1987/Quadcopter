/*
 *  rimGraphicsGUIMenuBar.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/18/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_MENU_BAR_H
#define INCLUDE_RIM_GRAPHICS_GUI_MENU_BAR_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObject.h"
#include "rimGraphicsGUIMenuBarDelegate.h"
#include "rimGraphicsGUIMenu.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which arranges a set of closed Menu objects within a rectangular area.
/**
  * A menu bar uses user input to show or hide menus that it contains, similar to
  * a standard GUI menu bar.
  */
class MenuBar : public GUIObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new menu bar with no width or height positioned at the origin.
			MenuBar();
			
			
			
			
			/// Create a new empty menu bar which occupies the specified rectangular region.
			MenuBar( const Rectangle& newRectangle );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Menu Accessor Methods
			
			
			
			
			/// Return the total number of menus that are part of this menu bar.
			RIM_INLINE Size getMenuCount() const
			{
				return menus.getSize();
			}
			
			
			
			
			/// Return a pointer to the menu at the specified index in this menu bar.
			RIM_INLINE const Pointer<Menu>& getMenu( Index menuIndex ) const
			{
				return menus[menuIndex].menu;
			}
			
			
			
			
			/// Add the specified menu to this menu bar.
			/**
			  * If the specified menu pointer is NULL, the method fails and FALSE
			  * is returned. Otherwise, the menu is appended to the end of the menu bar
			  * and TRUE is returned.
			  */
			Bool addMenu( const Pointer<Menu>& newMenu );
			
			
			
			
			/// Insert the specified menu at the given index in this menu bar.
			/**
			  * If the specified menu pointer is NULL, the method fails and FALSE
			  * is returned. Otherwise, the menu is inserted at the given index in the menu bar
			  * and TRUE is returned.
			  */
			Bool insertMenu( Index menuIndex, const Pointer<Menu>& newMenu );
			
			
			
			
			/// Replace the specified menu at the given index in this menu bar.
			/**
			  * If the specified menu pointer is NULL, the method fails and FALSE
			  * is returned. Otherwise, the menu is inserted at the given index in the menu bar
			  * and TRUE is returned.
			  */
			Bool setMenu( Index menuIndex, const Pointer<Menu>& newMenu );
			
			
			
			
			/// Remove the specified menu from this menu bar.
			/**
			  * If the given menu is part of this menu bar, the method removes it
			  * and returns TRUE. Otherwise, if the specified menu is not found,
			  * the method doesn't modify the menu bar and FALSE is returned.
			  */
			Bool removeMenu( const Menu* oldMenu );
			
			
			
			
			/// Remove the menu at the specified index from this menu bar.
			/**
			  * If the specified index is invalid, FALSE is returned and the Menu
			  * is unaltered. Otherwise, the menu at that index is removed and
			  * TRUE is returned.
			  */
			Bool removeMenuAtIndex( Index menuIndex );
			
			
			
			
			/// Remove all menus from this menu bar.
			void clearMenus();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Selected Menu Index Accesor Methods
			
			
			
			
			/// Return the index of the currently highlighted menu in this menu bar.
			/**
			  * If there is no currently highlighted menu, -1 is returned.
			  */
			RIM_INLINE Int getHighlightedMenuIndex() const
			{
				return highlightedMenuIndex;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Menu Padding Accessor Methods
			
			
			
			
			/// Return the padding amount between each menu in this menu bar.
			RIM_INLINE Float getMenuPadding() const
			{
				return menuPadding;
			}
			
			
			
			
			/// Set the padding amount between each menu in this menu bar.
			RIM_INLINE void setMenuPadding( Float newPadding )
			{
				menuPadding = newPadding;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Menu Bounding Box Accessor Methods
			
			
			
			
			/// Return the bounding box of the menu title with the specified index in this menu bar.
			RIM_INLINE const AABB2f& getMenuBounds( Index menuIndex ) const
			{
				return menus[menuIndex].bounds;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Accessor Methods
			
			
			
			
			/// Return a mutable object which describes this menu bar's border.
			RIM_INLINE Border& getBorder()
			{
				return border;
			}
			
			
			
			
			/// Return an object which describes this menu bar's border.
			RIM_INLINE const Border& getBorder() const
			{
				return border;
			}
			
			
			
			
			/// Set an object which describes this menu bar's border.
			RIM_INLINE void setBorder( const Border& newBorder )
			{
				border = newBorder;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Accessor Methods
			
			
			
			
			/// Return the background color for this menu bar's main area.
			RIM_INLINE const Color4f& getBackgroundColor() const
			{
				return backgroundColor;
			}
			
			
			
			
			
			/// Set the background color for this menu bar's main area.
			RIM_INLINE void setBackgroundColor( const Color4f& newBackgroundColor )
			{
				backgroundColor = newBackgroundColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a menu bar.
			RIM_INLINE const Color4f& getBorderColor() const
			{
				return borderColor;
			}
			
			
			
			
			/// Set the border color used when rendering a menu bar.
			RIM_INLINE void setBorderColor( const Color4f& newBorderColor )
			{
				borderColor = newBorderColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Separator Color Accessor Methods
			
			
			
			
			/// Return the color overlayed when a menu bar item is highlighted.
			RIM_INLINE const Color4f& getHighlightColor() const
			{
				return highlightColor;
			}
			
			
			
			
			/// Set the color overlayed when a menu bar item is highlighted.
			RIM_INLINE void setHighlightColor( const Color4f& newHighlightColor )
			{
				highlightColor = newHighlightColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Style Accessor Methods
			
			
			
			
			/// Return a reference to the font style which is used to render the text for a menu bar.
			RIM_INLINE const FontStyle& getTextStyle() const
			{
				return textStyle;
			}
			
			
			
			
			/// Set the font style which is used to render the text for a menu bar.
			RIM_INLINE void setTextStyle( const FontStyle& newTextStyle )
			{
				textStyle = newTextStyle;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Drawing Method
			
			
			
			
			/// Draw this menu bar using the specified GUI renderer to the given parent coordinate system bounds.
			/**
			  * The method returns whether or not the menu bar was successfully drawn.
			  */
			virtual Bool drawSelf( GUIRenderer& renderer, const AABB3f& parentBounds ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Input Handling Methods
			
			
			
			
			/// Handle the specified keyboard event for the entire menu bar.
			virtual void keyEvent( const KeyboardEvent& event );
			
			
			
			
			/// Handle the specified mouse motion event for the entire menu bar.
			virtual void mouseMotionEvent( const MouseMotionEvent& event );
			
			
			
			
			/// Handle the specified mouse button event for the entire menu bar.
			virtual void mouseButtonEvent( const MouseButtonEvent& event );
			
			
			
			
			/// Handle the specified mouse wheel event for the entire menu bar.
			virtual void mouseWheelEvent( const MouseWheelEvent& event );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return a reference to the delegate which responds to events for this menu bar.
			RIM_INLINE MenuBarDelegate& getDelegate()
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this menu bar.
			RIM_INLINE const MenuBarDelegate& getDelegate() const
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this menu bar.
			RIM_INLINE void setDelegate( const MenuBarDelegate& newDelegate )
			{
				delegate = newDelegate;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Construction Methods
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<MenuBar> construct()
			{
				return Pointer<MenuBar>::construct();
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<MenuBar> construct( const Rectangle& newRectangle )
			{
				return Pointer<MenuBar>::construct( newRectangle );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// The default padding to use between menus of a menu bar.
			static const Float DEFAULT_MENU_PADDING;
			
			
			/// The default border that is used for a menu bar.
			static const Border DEFAULT_BORDER;
			
			
			/// The default background color that is used for a menu bar's area.
			static const Color4f DEFAULT_BACKGROUND_COLOR;
			
			
			/// The default border color that is used for a menu bar.
			static const Color4f DEFAULT_BORDER_COLOR;
			
			
			/// The default highlight color that is used for a menu bar.
			static const Color4f DEFAULT_HIGHLIGHT_COLOR;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which contains information about a single menu that is part of a menu bar.
			class MenuInfo
			{
				public:
					
					/// Create a new menu information object associated with the specified menu.
					RIM_INLINE MenuInfo( const Pointer<Menu>& newMenu )
						:	menu( newMenu )
					{
					}
					
					/// A pointer to the menu associated with this menu information object.
					Pointer<Menu> menu;
					
					/// The bounding box of the menu within the menu bar's coordinate system.
					AABB2f bounds;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Change which menu is highlighted as part of this menu bar, sending any events to delegates.
			RIM_INLINE void setHighlightedMenu( Int newHighlightedIndex )
			{
				// Don't send any events if the highlighted menu didn't change.
				if ( newHighlightedIndex == highlightedMenuIndex )
					return;
				
				// Notify the previous menu that it was closed.
				if ( highlightedMenuIndex != -1 )
				{
					const Pointer<Menu>& menu = menus[highlightedMenuIndex].menu;
					const MenuDelegate& menuDelegate = menu->getDelegate();
					
					if ( menuDelegate.close.isSet() )
						menuDelegate.close( *menu );
					
					// Notify the menu bar delegate.
					if ( delegate.closeMenu.isSet() )
						delegate.closeMenu( *this, highlightedMenuIndex );
				}
				
				highlightedMenuIndex = newHighlightedIndex;
				
				// Notify the new menu that it was opened.
				if ( highlightedMenuIndex != -1 )
				{
					const Pointer<Menu>& menu = menus[highlightedMenuIndex].menu;
					const MenuDelegate& menuDelegate = menus[highlightedMenuIndex].menu->getDelegate();
					
					if ( menuDelegate.open.isSet() )
						menuDelegate.open( *menu );
					
					// Notify the menu bar delegate.
					if ( delegate.openMenu.isSet() )
						delegate.openMenu( *this, highlightedMenuIndex );
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of all of the menus that are part of this menu bar.
			ArrayList<MenuInfo> menus;
			
			
			
			
			/// An object which describes the border for this menu bar.
			Border border;
			
			
			
			
			/// The padding space between menus.
			Float menuPadding;
			
			
			
			
			/// The background color for the menu bar's area.
			Color4f backgroundColor;
			
			
			
			
			/// The border color for the menu bar's background area.
			Color4f borderColor;
			
			
			
			
			/// The color which is used to highlight selected menu bar items.
			Color4f highlightColor;
			
			
			
			
			/// An object which determines the style of the text for this menu bar's items.
			FontStyle textStyle;
			
			
			
			
			/// An object which contains function pointers that respond to menu bar events.
			MenuBarDelegate delegate;
			
			
			
			
			/// The index of the currently highlighted menu, or -1 if no menu is highlighted.
			Int highlightedMenuIndex;
			
			
			
			
			/// A boolean value indicating whether or not the user has clicked the menu bar with the mouse.
			Bool mousePressed;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_MENU_BAR_H
