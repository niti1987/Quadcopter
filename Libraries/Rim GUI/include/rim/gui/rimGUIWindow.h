/*
 *  rimGUIWindow.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 5/24/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_WINDOW_H
#define INCLUDE_RIM_GUI_WINDOW_H


#include "rimGUIConfig.h"


#include "rimGUIElement.h"
#include "rimGUIWindowElement.h"
#include "rimGUIMenuBar.h"
#include "rimGUIWindowDelegate.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a generic operating system GUI window.
/**
  * A window is a rectangular region of the screen that floats over the GUI desktop.
  * It is generally the top-level object that contains the interface for an application.
  */
class Window : public GUIElement
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a centered window with the specified width and height.
			Window( const UTF8String& title, const Size2D& size );
			
			
			
			
			/// Create a window with the specified width, height, position.
			Window( const UTF8String& title, const Size2D& size, const Vector2i& position );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a window, closing it if is visible and releasing all resources used.
			~Window();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content View Accessor Methods
			
			
			
			
			/// Return the number of window element children that this window has.
			Size getChildCount() const;
			
			
			
			
			/// Return a shared pointer to the child window element at the specified index in this window.
			/**
			  * If the specified index is out of bounds or an error occurs, a NULL pointer
			  * is returned.
			  */
			Pointer<WindowElement> getChild( Index childIndex ) const;
			
			
			
			
			/// Add a child window element to this window.
			/**
			  * The method returns whether or not the add operation was successful.
			  * The method can fail if the specified window element pointer is NULL
			  * or if the window element already has a parent window.
			  */
			Bool addChild( const Pointer<WindowElement>& element );
			
			
			
			
			/// Remove the child window element from this window that matches the specified element.
			/**
			  * The method returns whether or not the specified window element was found
			  * to be a part of this window and then successfully removed.
			  */
			Bool removeChild( const WindowElement* element );
			
			
			
			
			/// Remove all child window elements from this window.
			void removeChildren();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Menu Accessor Methods
			
			
			
			
			/// Get a non-const shared pointer to the window's menu.
			Pointer<MenuBar> getMenu() const;
			
			
			
			
			/// Set the menu of the window.
			Bool setMenu( const Pointer<MenuBar>& newMenu );
			
			
			
			
			/// Return whether or not this window has a menu associated with it.
			Bool hasMenu() const;
			
			
			
			
			/// Release any references to the window's menu.
			void removeMenu();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Positioning Methods
			
			
			
			
			/// Get the position of the window relative to the top left corner of the screen (in pixels).
			Vector2i getPosition() const;
			
			
			
			
			/// Set the position of the window relative to the top left corner of the screen (in pixels).
			Bool setPosition( const Vector2i& newPosition );
			
			
			
			
			/// Set the position of the window relative to the top left corner of the screen (in pixels).
			Bool setPosition( Int xPosition, Int yPosition );
			
			
			
			
			/// Center the window within the screen where it currently resides.
			Bool center();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content Sizing Methods
			
			
			
			
			/// Get the width of the window's content area in pixels.
			RIM_INLINE Size getContentWidth() const
			{
				return this->getContentSize().x;
			}
			
			
			
			
			/// Get the height of the window's content area in pixels.
			RIM_INLINE Size getContentHeight() const
			{
				return this->getContentSize().y;
			}
			
			
			
			
			/// Return a 2D vector indicating the horizontal and vertical size of the window's content area in pixels.
			Size2D getContentSize() const;
			
			
			
			
			/// Set the width of the window's content view, changing the window's size and resizing the content view.
			RIM_INLINE Bool setContentWidth( Size newWidth )
			{
				return this->setContentSize( newWidth, this->getContentHeight() );
			}
			
			
			
			
			/// Set the height of the window's content view, changing the window's size and resizing the content view.
			RIM_INLINE Bool setContentHeight( Size newHeight )
			{
				return this->setContentSize( this->getContentWidth(), newHeight );
			}
			
			
			
			
			/// Set the size of the window's content view, changing the window's size and resizing the content view.
			RIM_INLINE Bool setContentSize( Size newWidth, Size newHeight )
			{
				return this->setContentSize( Size2D( newWidth, newHeight ) );
			}
			
			
			
			
			/// Set the size of the window's content view, changing the window's size and resizing the content view.
			Bool setContentSize( const Size2D& newSize );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Window Sizing Methods
			
			
			
			
			/// Return the size of the entire window frame, including any title or menu bars or borders.
			Size2D getFrameSize() const;
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Title Accessor Methods
			
			
			
			
			/// Return the title string for this window.
			/**
			  * On most platforms, this string will be placed at the top of the window in
			  * a title bar.
			  */
			UTF8String getTitle() const;
			
			
			
			
			/// Set the title string for this window.
			/**
			  * The method returns whether or not the title change operation was successful.
			  */
			Bool setTitle( const UTF8String& newTitle );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Window Minimization Methods
			
			
			
			
			/// Return a boolean value indicating whether or not a window is currently minimized.
			Bool getIsMinimized() const;
			
			
			
			
			/// Set a boolean value determining whether or not a window should be minimized.
			Bool setIsMinimized( Bool newIsMinimized );
			
			
			
			
			/// Minimize the window, moving it from the main screen to somewhere inconspicuous (OS-dependent).
			/**
			  * The method returns whether or not the minimization operation was successful.
			  */
			Bool minimize();
			
			
			
			
			/// Restore the window, moving it from it's minimized location to it's previous location on the screen.
			/**
			  * The method returns whether or not the un-minimization operation was successful.
			  */
			Bool unminimize();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Window Ordering Methods
			
			
			
			
			/// Move the window to the front of the window order (in it's level) within an application.
			Bool moveToFront();
			
			
			
			
			/// Move the window to the back of the window order, beneath all windows but the desktop.
			Bool moveToBack();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Visibility Status Accessor Methods
			
			
			
			
			/// Return whether or not the window is currently visible.
			Bool getIsVisible() const;
			
			
			
			
			/// Set whether or not the window should be visible.
			Bool setIsVisible( Bool newIsVisible );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Window Status Accessor Methods
			
			
			
			
			/// Get whether or not the window is fullscreen (takes entire screen area, including any OS menu bars).
			Bool getIsFullscreen() const;
			
			
			
			
			/// Set whether or not the window is fullscreen (takes entire screen area, including any OS menu bars).
			Bool setIsFullscreen( Bool newIsFullscreen );
			
			
			
			
			/// Get whether or not the window is floating (always in front of normal windows).
			Bool getIsFloating() const;
			
			
			
			
			/// Get whether or not the window is floating (always in front of normal windows).
			Bool setIsFloating( Bool newIsFloating );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Window Capability Accessor Methods
			
			
			
			
			/// Get whether or not the window is able to be resized by the GUI user.
			/**
			  * If a window is not able to be resized, it is still possible to resize the
			  * window programatically. The only resizing operations that are prevented
			  * are those that are caused by the user interacting with the GUI.
			  */
			Bool getIsResizable() const;
			
			
			
			
			/// Set whether or not the window is able to be resized by the GUI user.
			/**
			  * If a window is not able to be resized, it is still possible to resize the
			  * window programatically. The only resizing operations that are prevented
			  * are those that are caused by the user interacting with the GUI.
			  */
			void setIsResizable( Bool newIsResizable );
			
			
			
			
			/// Get whether or not the window is able to be moved by the GUI user.
			/**
			  * If a window is not able to be moved, it is still possible to move the
			  * window programatically. The only moving operations that are prevented
			  * are those that are caused by the user interacting with the GUI.
			  */
			Bool getIsMovable() const;
			
			
			
			
			/// Set whether or not the window is able to be resized by the GUI user.
			/**
			  * If a window is not able to be moved, it is still possible to move the
			  * window programatically. The only moving operations that are prevented
			  * are those that are caused by the user interacting with the GUI.
			  */
			void setIsMovable( Bool newIsMovable );
			
			
			
			
			/// Get whether or not the window is able to be closed by the GUI user.
			/**
			  * If a window is not able to be closed, it is still possible to close the
			  * window programatically. The only closing operations that are prevented
			  * are those that are caused by the user interacting with the GUI.
			  */
			Bool getIsClosable() const;
			
			
			
			
			/// Set whether or not the window is able to be closed by the GUI user.
			/**
			  * If a window is not able to be closed, it is still possible to close the
			  * window programatically. The only closing operations that are prevented
			  * are those that are caused by the user interacting with the GUI.
			  */
			void setIsClosable( Bool newIsClosable );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate (Event Handler) Accessor Methods
			
			
			
			
			/// Get a reference to the delegate object associated with this window.
			const WindowDelegate& getDelegate() const;
			
			
			
			
			/// Set the delegate object to which this window sends events.
			void setDelegate( const WindowDelegate& delegate );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Platform-Specific Pointer Accessor Method
			
			
			
			
			/// Get a pointer to this window's platform-specific internal representation.
			/**
			  * On Mac OS X, this method returns a pointer to a subclass of NSWindow
			  * which represents the window.
			  *
			  * On Windows, this method returns an HWND indicating a handle to the window which
			  * represents the window.
			  */
			virtual void* getInternalPointer() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Shared Construction Methods
			
			
			
			
			/// Create a shared-pointer window object, calling the constructor with the same arguments.
			RIM_INLINE static Pointer<Window> construct( const UTF8String& newText,
															const Size2D& newSize )
			{
				return Pointer<Window>( util::construct<Window>( newText, newSize ) );
			}
			
			
			
			
			/// Create a shared-pointer window object, calling the constructor with the same arguments.
			RIM_INLINE static Pointer<Window> construct( const UTF8String& newText, const Size2D& newSize,
															const Vector2i& newPosition )
			{
				return Pointer<Window>( util::construct<Window>( newText, newSize, newPosition ) );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Window Wrapper Class Declaration
			
			
			
			
			/// A class which encapsulates internal platform-specific state.
			class Wrapper;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to internal implementation-specific data.
			Wrapper* wrapper;
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_WINDOW_H
