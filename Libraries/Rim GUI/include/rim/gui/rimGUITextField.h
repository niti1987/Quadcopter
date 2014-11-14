/*
 *  rimGUITextField.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 9/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_TEXT_FIELD_H
#define INCLUDE_RIM_GUI_TEXT_FIELD_H


#include "rimGUIConfig.h"


#include "rimGUIWindowElement.h"
#include "rimGUITextFieldDelegate.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a single-line text label or field that is part of a window.
class TextField : public WindowElement
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new text field with no text content and positioned at the origin of its coordinate system.
			TextField();
			
			
			
			
			/// Create a new text field which uses the specified text content, positioned at the origin of its coordinate system.
			TextField( const UTF8String& newText, const Size2D& newSize );
			
			
			
			
			/// Create a new text field which uses the specified text content and position.
			TextField( const UTF8String& newText, const Size2D& newSize, const Vector2i& newPosition );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a text field, releasing all resources associated with it.
			~TextField();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Accessor Methods
			
			
			
			
			/// Return a string which contains the contents of this text field.
			UTF8String getText() const;
			
			
			
			
			/// Set the text contents of this text field.
			/**
			  * The method returns whether or not the text change operation was successful.
			  */
			Bool setText( const UTF8String& newText );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return a 2D vector indicating the size on the screen of this text field in pixels.
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
		//******	Editing State Accessor Methods
			
			
			
			
			/// Return whether or not the text field is able to be edited by the user.
			/**
			  * A text field that is not editable will appear as a simple text label.
			  */
			Bool getIsEditable() const;
			
			
			
			
			/// Set whether or not the text field is able to be edited by the user.
			/**
			  * A text field that is not editable will appear as a simple text label.
			  */
			void setIsEditable( Bool newIsEditable );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Selecting State Accessor Methods
			
			
			
			
			/// Return whether or not the contents of the text field are able to be selected by the user.
			Bool getIsSelectable() const;
			
			
			
			
			/// Set whether or not the contents of the text field are able to be selected by the user.
			void setIsSelectable( Bool newIsSelectable );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return a const reference to the object which responds to events for this TextField.
			const TextFieldDelegate& getDelegate() const;
			
			
			
			
			/// Set the object to which TextField events should be delegated.
			void setDelegate( const TextFieldDelegate& newDelegate );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parent Window Accessor Methods
			
			
			
			
			/// Return the window which is a parent of this text field.
			/**
			  * If NULL is returned, it indicates that the text field is not part of a window.
			  */
			virtual Window* getParentWindow() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Platform-Specific Element Pointer Accessor Method
			
			
			
			
			/// Return a pointer to platform-specific data for this text field.
			/**
			  * On Mac OS X, this method returns a pointer to a subclass of NSTextField
			  * which represents the text field.
			  *
			  * On Windows, this method returns an HWND indicating the 'window' which
			  * represents the text field.
			  */
			virtual void* getInternalPointer() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Shared Construction Methods
			
			
			
			
			/// Create a shared-pointer text field object, calling the constructor with the same arguments.
			RIM_INLINE static Pointer<TextField> construct()
			{
				return Pointer<TextField>( util::construct<TextField>() );
			}
			
			
			
			
			/// Create a shared-pointer text field object, calling the constructor with the same arguments.
			RIM_INLINE static Pointer<TextField> construct( const UTF8String& newText,
															const Size2D& newSize )
			{
				return Pointer<TextField>( util::construct<TextField>( newText, newSize ) );
			}
			
			
			
			
			/// Create a shared-pointer text field object, calling the constructor with the same arguments.
			RIM_INLINE static Pointer<TextField> construct( const UTF8String& newText, const Size2D& newSize,
															const Vector2i& newPosition )
			{
				return Pointer<TextField>( util::construct<TextField>( newText, newSize, newPosition ) );
			}
			
			
			
			
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Wrapper Class Declaration
			
			
			
			
			/// A class which wraps platform-specific data for a text field.
			class Wrapper;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Parent Accessor Methods
			
			
			
			
			/// Set the window which is going to be a parent of this text field.
			/**
			  * Setting this value to NULL should indicate that the text field is no longer
			  * part of a window.
			  */
			virtual void setParentWindow( Window* parentWindow );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to an object which wraps platform-specific data for this text field.
			Wrapper* wrapper;
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_TEXT_FIELD_H
