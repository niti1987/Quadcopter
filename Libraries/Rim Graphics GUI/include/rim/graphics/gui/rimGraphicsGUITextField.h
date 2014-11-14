/*
 *  rimGraphicsGUITextField.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/29/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_TEXT_FIELD_H
#define INCLUDE_RIM_GRAPHICS_GUI_TEXT_FIELD_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObject.h"
#include "rimGraphicsGUIFonts.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a simple multi-line text area with a single text style.
class TextField : public GUIObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new text field with no text content and positioned at the origin of its coordinate system.
			TextField();
			
			
			
			
			/// Create a new text field which occupies the specified rectangular region with no text contents.
			TextField( const Rectangle& newRectangle );
			
			
			
			
			/// Create a new text field which places the specified text content within the given rectangle.
			TextField( const Rectangle& newRectangle, const UTF8String& newText );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Accessor Methods
			
			
			
			
			/// Return a reference to a string representing the text contents of this text view.
			RIM_INLINE const UTF8String& getText() const
			{
				return text;
			}
			
			
			
			
			/// Set a string representing the text contents of this text view.
			RIM_INLINE void setText( const UTF8String& newText )
			{
				text = newText;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Alignment Accessor Methods
			
			
			
			
			/// Return an object which describes how this text field's text is aligned.
			RIM_INLINE const Origin& getTextAlignment() const
			{
				return textAlignment;
			}
			
			
			
			
			/// Set an object which describes how this text field's text is aligned.
			RIM_INLINE void setTextAlignment( const Origin& newTextAlignment )
			{
				textAlignment = newTextAlignment;
			}
			
			
			
			
			/// Set an object which describes how this text field's text is aligned.
			RIM_INLINE void setTextAlignment( Origin::XOrigin newXOrigin,
												Origin::YOrigin newYOrigin )
			{
				textAlignment = Origin( newXOrigin, newYOrigin );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Wrap Accessor Methods
			
			
			
			
			/// Return whether or not this text field's text wraps within its display area.
			RIM_INLINE Bool getTextIsWrapped() const
			{
				return textIsWrapped;
			}
			
			
			
			
			/// Set whether or not this text field's text wraps within its display area.
			RIM_INLINE void setTextIsWrapped( Bool newTextIsWrapped )
			{
				textIsWrapped = newTextIsWrapped;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Margin Accessor Methods
			
			
			
			
			/// Return an object which describes the size of this text field's margins.
			/**
			  * The margin describes the padding distance between the text field's frame and the
			  * box where text is drawn.
			  */
			RIM_INLINE const Margin& getMargin() const
			{
				return margin;
			}
			
			
			
			
			/// Set an object which describes the size of this text field's margins.
			/**
			  * The margin describes the padding distance between the text field's frame and the
			  * box where text is drawn.
			  */
			RIM_INLINE void setMargin( const Margin& newMargin )
			{
				margin = newMargin;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Accessor Methods
			
			
			
			
			/// Return a mutable object which describes this text field's border.
			RIM_INLINE Border& getBorder()
			{
				return border;
			}
			
			
			
			
			/// Return an object which describes this text field's border.
			RIM_INLINE const Border& getBorder() const
			{
				return border;
			}
			
			
			
			
			/// Set an object which describes this text field's border.
			RIM_INLINE void setBorder( const Border& newBorder )
			{
				border = newBorder;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content Bounding Box Accessor Methods
			
			
			
			
			/// Return the 3D bounding box for the text field's text display area in its local coordinate frame.
			RIM_INLINE AABB3f getLocalContentBounds() const
			{
				return AABB3f( this->getLocalContentBoundsXY(), AABB1f( Float(0), this->getSize().z ) );
			}
			
			
			
			
			/// Return the 2D bounding box for the text field's text display area in its local coordinate frame.
			RIM_INLINE AABB2f getLocalContentBoundsXY() const
			{
				return border.getContentBounds( AABB2f( Vector2f(), this->getSizeXY() ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Background Color Accessor Methods
			
			
			
			
			/// Return the background color for this text field's text area.
			RIM_INLINE const Color4f& getBackgroundColor() const
			{
				return backgroundColor;
			}
			
			
			
			
			
			/// Set the background color for this text field's text area.
			RIM_INLINE void setBackgroundColor( const Color4f& newBackgroundColor )
			{
				backgroundColor = newBackgroundColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color for a text field.
			RIM_INLINE const Color4f& getBorderColor() const
			{
				return borderColor;
			}
			
			
			
			
			
			/// Set the border color for a text field.
			RIM_INLINE void setBorderColor( const Color4f& newBorderColor )
			{
				borderColor = newBorderColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Style Accessor Methods
			
			
			
			
			/// Return a reference to the font style which is used to render the text for a text field.
			RIM_INLINE const fonts::FontStyle& getTextStyle() const
			{
				return textStyle;
			}
			
			
			
			
			/// Set the font style which is used to render the text for a text field.
			RIM_INLINE void setTextStyle( const fonts::FontStyle& newTextStyle )
			{
				textStyle = newTextStyle;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Input Handling Methods
			
			
			
			
			/// Handle the specified keyboard event that occured when this object had focus.
			virtual void keyEvent( const KeyboardEvent& event );
			
			
			
			
			/// Handle the specified mouse motion event that occurred.
			virtual void mouseMotionEvent( const MouseMotionEvent& event );
			
			
			
			
			/// Handle the specified mouse button event that occurred.
			virtual void mouseButtonEvent( const MouseButtonEvent& event );
			
			
			
			
			/// Handle the specified mouse wheel event that occurred.
			virtual void mouseWheelEvent( const MouseWheelEvent& event );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Drawing Method
			
			
			
			
			/// Draw this object using the specified GUI renderer to the given parent coordinate system bounds.
			/**
			  * The method returns whether or not the object was successfully drawn.
			  *
			  * The default implementation draws nothing and returns TRUE.
			  */
			virtual Bool drawSelf( GUIRenderer& renderer, const AABB3f& parentBounds ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Construction Methods
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<TextField> construct()
			{
				return Pointer<TextField>( rim::util::construct<TextField>() );
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<TextField> construct( const Rectangle& newRectangle )
			{
				return Pointer<TextField>( rim::util::construct<TextField>( newRectangle ) );
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<TextField> construct( const Rectangle& newRectangle, const UTF8String& newText )
			{
				return Pointer<TextField>( rim::util::construct<TextField>( newRectangle, newText ) );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A string representing the text contents of this text field.
			UTF8String text;
			
			
			
			
			/// An object which describes how this text field's text is aligned.
			Origin textAlignment;
			
			
			
			
			/// An object which describes the width of the 4-sided margins of this text field.
			Margin margin;
			
			
			
			
			/// An object which describes the border of this text field.
			Border border;
			
			
			
			
			/// The code point index within the text field's text where the current cursor is located.
			Index currentCursorIndex;
			
			
			
			
			/// The background color for the text field's text area.
			Color4f backgroundColor;
			
			
			
			
			/// The border color for the text field's text area.
			Color4f borderColor;
			
			
			
			
			/// An object which determines the style of the text contained by this text field.
			fonts::FontStyle textStyle;
			
			
			
			
			/// A boolean value indicating whether or not this text field's text wraps within its display area.
			Bool textIsWrapped;
			
			
			
			
			/// A boolean value which indicates whether or not this text field's text is able to be edited.
			Bool isEditable;
			
			
			
			
			/// A boolean value which indicates whether or not this text field's text is able to be selected.
			Bool isSelectable;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_TEXT_FIELD_H
