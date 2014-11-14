/*
 *  rimGUIButton.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 9/25/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_BUTTON_H
#define INCLUDE_RIM_GUI_BUTTON_H


#include "rimGUIConfig.h"


#include "rimGUIWindowElement.h"
#include "rimGUIButtonDelegate.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a rectangular region that responds to mouse click events.
class Button : public WindowElement
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new text field which uses the specified text label, size, and position.
			Button( const UTF8String& buttonText, const Size2D& newSize, const Vector2i& newPosition );
			
			
			
			
			/// Create a new text field which uses the specified image label, size, and position.
			//Button( const Image& buttonImage, const Size2D& newSize, const Vector2i& newPosition );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a button, releasing all resources associated with it.
			~Button();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Accessor Methods
			
			
			
			
			/// Return a string that represents the text label for this button.
			UTF8String getText() const;
			
			
			
			
			/// Set a string that represents the text label for this button.
			/**
			  * The method returns whether or not the text change operation was successful.
			  */
			Bool setText( const UTF8String& newText );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return a 2D vector indicating the size on the screen of this button in pixels.
			virtual Size2D getSize() const;
			
			
			
			
			/// Set the size on the screen of this text field in pixels.
			/**
			  * The method returns whether or not the size change operation was
			  * successful.
			  */
			virtual Bool setSize( const Size2D& size );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Position Accessor Methods
			
			
			
			
			/// Return the 2D position of this text field in pixels, relative to the bottom left corner.
			/**
			  * The coordinate position is defined relative to its enclosing coordinate frame
			  * where the origin will be the bottom left corner of the enclosing view or window.
			  */
			virtual Vector2i getPosition() const;
			
			
			
			
			/// Set the 2D position of this text field in pixels, relative to the bottom left corner.
			/**
			  * The coordinate position is defined relative to its enclosing coordinate frame
			  * where the origin will be the bottom left corner of the enclosing view or window.
			  *
			  * If the position change operation is successful, TRUE is returned and the text field is
			  * moved. Otherwise, FALSE is returned and the text field is not moved.
			  */
			virtual Bool setPosition( const Vector2i& position );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	State Accessor Methods
			
			
			
			
			/// Return whether or not this button is currently pressed.
			Bool getIsPressed() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return a const reference to the object which responds to events for this button.
			const ButtonDelegate& getDelegate() const;
			
			
			
			
			/// Set the object to which button events should be delegated.
			void setDelegate( const ButtonDelegate& newDelegate );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parent Window Accessor Methods
			
			
			
			
			/// Return the window which is a parent of this button.
			/**
			  * If NULL is returned, it indicates that the button is not part of a window.
			  */
			virtual Window* getParentWindow() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Platform-Specific Element Pointer Accessor Method
			
			
			
			
			/// Return a pointer to platform-specific data for this button.
			/**
			  * On Mac OS X, this method returns a pointer to a subclass of NSButton
			  * which represents the button.
			  *
			  * On Windows, this method returns an HWND indicating the 'window' which
			  * represents the button.
			  */
			virtual void* getInternalPointer() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Shared Construction Methods
			
			
			
			
			/// Create a shared-pointer button object, calling the constructor with the same arguments.
			RIM_INLINE static Pointer<Button> construct( const UTF8String& newText, const Size2D& newSize,
															const Vector2i& newPosition )
			{
				return Pointer<Button>( util::construct<Button>( newText, newSize, newPosition ) );
			}
			
			
			
			
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Wrapper Class Declaration
			
			
			
			
			/// A class which wraps platform-specific data for a button.
			class Wrapper;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Parent Accessor Methods
			
			
			
			
			/// Set the window which is going to be a parent of this button.
			/**
			  * Setting this value to NULL should indicate that the button is no longer
			  * part of a window.
			  */
			virtual void setParentWindow( Window* parentWindow );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to an object which wraps platform-specific data for this button.
			Wrapper* wrapper;
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_BUTTON_H
