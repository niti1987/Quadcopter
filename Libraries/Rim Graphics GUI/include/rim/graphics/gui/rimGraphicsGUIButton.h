/*
 *  rimGraphicsGUIButton.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/29/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_BUTTON_H
#define INCLUDE_RIM_GRAPHICS_GUI_BUTTON_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObject.h"
#include "rimGraphicsGUIFonts.h"
#include "rimGraphicsGUIButtonDelegate.h"
#include "rimGraphicsGUIButtonType.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a rectangular region that can be clicked on to perform an action.
class Button : public GUIObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new sizeless button with no text label and positioned at the origin of its coordinate system.
			Button();
			
			
			
			
			/// Create a new button which occupies the specified rectangle with no text label.
			Button( const Rectangle& newRectangle );
			
			
			
			
			/// Create a new button which occupies the specifieid rectangle with the given label text.
			Button( const Rectangle& newRectangle, const UTF8String& newText );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Accessor Methods
			
			
			
			
			/// Return a reference to a string representing the text label of this button.
			RIM_INLINE const UTF8String& getText() const
			{
				return text;
			}
			
			
			
			
			/// Set a string representing the text label of this button.
			RIM_INLINE void setText( const UTF8String& newText )
			{
				text = newText;
			}
			
			
			
			
			/// Return a reference to a string representing the text label of this button when it is selected.
			RIM_INLINE const UTF8String& getAlternateText() const
			{
				return alternateText;
			}
			
			
			
			
			/// Set a string representing the text label of this button when it is selected.
			RIM_INLINE void setAlternateText( const UTF8String& newAlternateText )
			{
				alternateText = newAlternateText;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Alignment Accessor Methods
			
			
			
			
			/// Return an object which describes how this button's text is aligned within the button's bounds.
			RIM_INLINE const Origin& getTextAlignment() const
			{
				return textAlignment;
			}
			
			
			
			
			/// Set an object which describes how this button's text is aligned within the button's bounds.
			RIM_INLINE void setTextAlignment( const Origin& newTextAlignment )
			{
				textAlignment = newTextAlignment;
			}
			
			
			
			
			/// Set an object which describes how this button's text is aligned within the button's bounds.
			RIM_INLINE void setTextAlignment( Origin::XOrigin newXOrigin,
												Origin::YOrigin newYOrigin )
			{
				textAlignment = Origin( newXOrigin, newYOrigin );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Visibility Accessor Methods
			
			
			
			
			/// Return a boolean value indicating whether or not this button's text label is displayed.
			RIM_INLINE Bool getTextIsVisible() const
			{
				return textIsVisible;
			}
			
			
			
			
			/// Set a boolean value indicating whether or not this button's text label is displayed.
			RIM_INLINE void setTextIsVisible( Bool newTextIsVisible )
			{
				textIsVisible = newTextIsVisible;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Accessor Methods
			
			
			
			
			/// Return a reference to the image which is displayed in the button's content area when in its normal state.
			RIM_INLINE const Pointer<GUIImage>& getImage() const
			{
				return image;
			}
			
			
			
			
			/// Set the image which is displayed in the button's content area when in its normal state.
			RIM_INLINE void setImage( const Pointer<GUIImage>& newImage )
			{
				image = newImage;
			}
			
			
			
			
			/// Return a reference to the image which is displayed in the button's content area when in its alternate state.
			RIM_INLINE const Pointer<GUIImage>& getAlternateImage() const
			{
				return alternateImage;
			}
			
			
			
			
			/// Set the image which is displayed in the button's content area when in its alternate state.
			RIM_INLINE void setAlternateImage( const Pointer<GUIImage>& newAlternateImage )
			{
				alternateImage = newAlternateImage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Alignment Accessor Methods
			
			
			
			
			/// Return an object which describes how this button's image is aligned within the button's bounds.
			RIM_INLINE const Origin& getImageAlignment() const
			{
				return imageAlignment;
			}
			
			
			
			
			/// Set an object which describes how this button's image is aligned within the button's bounds.
			RIM_INLINE void setImageAlignment( const Origin& newImageAlignment )
			{
				imageAlignment = newImageAlignment;
			}
			
			
			
			
			/// Set an object which describes how this button's image is aligned within the button's bounds.
			RIM_INLINE void setImageAlignment( Origin::XOrigin newXOrigin,
												Origin::YOrigin newYOrigin )
			{
				imageAlignment = Origin( newXOrigin, newYOrigin );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Visibility Accessor Methods
			
			
			
			
			/// Return a boolean value indicating whether or not this button's image is displayed.
			RIM_INLINE Bool getImageIsVisible() const
			{
				return imageIsVisible;
			}
			
			
			
			
			/// Set a boolean value indicating whether or not this button's image is displayed.
			RIM_INLINE void setImageIsVisible( Bool newImageIsVisible )
			{
				imageIsVisible = newImageIsVisible;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Button State Accessor Methods
			
			
			
			
			/// Return whether or not this button is currently active.
			/**
			  * An enabled button (the default) can be interacted with by the user
			  * and is displayed normally. A disabled button can't be pressed by the
			  * user and displays more transparently, indicating its state.
			  */
			RIM_INLINE Bool getIsEnabled() const
			{
				return isEnabled;
			}
			
			
			
			
			/// Set whether or not this button is currently active.
			/**
			  * An enabled button (the default) can be interacted with by the user
			  * and is displayed normally. A disabled button can't be pressed by the
			  * user and displays more transparently, indicating its state.
			  */
			RIM_INLINE void setIsEnabled( Bool newIsEnabled )
			{
				isEnabled = newIsEnabled;
			}
			
			
			
			
			/// Return whether or not this button is currently selected (in its alternate state).
			/**
			  * When a button is selected, its alternate text and image will be displayed
			  * instead of the normal text or image.
			  */
			RIM_INLINE Bool getIsSelected() const
			{
				return isSelected;
			}
			
			
			
			
			/// Set whether or not this button is currently selected (in its alternate state).
			/**
			  * When a button is selected, its alternate text and image will be displayed
			  * instead of the normal text or image.
			  */
			RIM_INLINE void setIsSelected( Bool newIsSelected )
			{
				isSelected = newIsSelected;
			}
			
			
			
			
			/// Return whether or not this button is currently pressed by the user.
			/**
			  * If this method returns TRUE, the user is currently pressing the button
			  * but has not yet released the button. Depending on the type of button
			  * different actions will be taken after the button is released.
			  */
			RIM_INLINE Bool getIsPressed() const
			{
				return isPressed;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Button Type Accessor Methods
			
			
			
			
			/// Return an object which represents the type of this button.
			RIM_INLINE ButtonType getType() const
			{
				return type;
			}
			
			
			
			
			/// Return an object which represents the type of this button.
			RIM_INLINE void setType( ButtonType newType )
			{
				type = newType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Accessor Methods
			
			
			
			
			/// Return a mutable object which describes this button's border.
			RIM_INLINE Border& getBorder()
			{
				return border;
			}
			
			
			
			
			/// Return an object which describes this button's border.
			RIM_INLINE const Border& getBorder() const
			{
				return border;
			}
			
			
			
			
			/// Set an object which describes this button's border.
			RIM_INLINE void setBorder( const Border& newBorder )
			{
				border = newBorder;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content Bounding Box Accessor Methods
			
			
			
			
			/// Return the 3D bounding box for the button's content display area in its local coordinate frame.
			RIM_INLINE AABB3f getLocalContentBounds() const
			{
				return AABB3f( this->getLocalContentBoundsXY(), AABB1f( Float(0), this->getSize().z ) );
			}
			
			
			
			
			/// Return the 2D bounding box for the button's content display area in its local coordinate frame.
			RIM_INLINE AABB2f getLocalContentBoundsXY() const
			{
				return border.getContentBounds( AABB2f( Vector2f(), this->getSizeXY() ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Background Color Accessor Methods
			
			
			
			
			/// Return the background color for this button's main area.
			RIM_INLINE const Color4f& getBackgroundColor() const
			{
				return backgroundColor;
			}
			
			
			
			
			
			/// Set the background color for this button's main area.
			RIM_INLINE void setBackgroundColor( const Color4f& newBackgroundColor )
			{
				backgroundColor = newBackgroundColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a button.
			RIM_INLINE const Color4f& getBorderColor() const
			{
				return borderColor;
			}
			
			
			
			
			
			/// Set the border color used when rendering a button.
			RIM_INLINE void setBorderColor( const Color4f& newBorderColor )
			{
				borderColor = newBorderColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Alternate Color Accessor Methods
			
			
			
			
			/// Return the alternate color for this button's main area.
			/**
			  * This is the color of the button when it is pressed.
			  */
			RIM_INLINE const Color4f& getAlternateColor() const
			{
				return alternateColor;
			}
			
			
			
			
			/// Set the alternate color for this button's main area.
			/**
			  * This is the color of the button when it is pressed.
			  */
			RIM_INLINE void setAlternateColor( const Color4f& newAlternateColor )
			{
				alternateColor = newAlternateColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Style Accessor Methods
			
			
			
			
			/// Return a reference to the font style which is used to render the text for a button.
			RIM_INLINE const FontStyle& getTextStyle() const
			{
				return textStyle;
			}
			
			
			
			
			/// Set the font style which is used to render the text for a button.
			RIM_INLINE void setTextStyle( const FontStyle& newTextStyle )
			{
				textStyle = newTextStyle;
			}
			
			
			
			
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
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return a reference to the delegate which responds to events for this button.
			RIM_INLINE ButtonDelegate& getDelegate()
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this button.
			RIM_INLINE const ButtonDelegate& getDelegate() const
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this button.
			RIM_INLINE void setDelegate( const ButtonDelegate& newDelegate )
			{
				delegate = newDelegate;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Construction Methods
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<Button> construct()
			{
				return Pointer<Button>::construct();
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<Button> construct( const Rectangle& newRectangle )
			{
				return Pointer<Button>::construct( newRectangle );
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<Button> construct( const Rectangle& newRectangle, const UTF8String& newText )
			{
				return Pointer<Button>::construct( newRectangle, newText );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// The default border that is used for a button.
			static const Border DEFAULT_BORDER;

			
			/// The default alignment that is used for a button's text label.
			static const Origin DEFAULT_TEXT_ALIGNMENT;
			
			
			/// The default background color that is used for a button's area.
			static const Color4f DEFAULT_BACKGROUND_COLOR;
			
			
			/// The default border color that is used for a button.
			static const Color4f DEFAULT_BORDER_COLOR;
			
			
			/// The default color that is used for a button's background when it is pressed.
			static const Color4f DEFAULT_ALTERNATE_COLOR;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A string representing the text label of this button.
			UTF8String text;
			
			
			
			
			/// A string representing the text label of this button when it is selected.
			UTF8String alternateText;
			
			
			
			
			/// An image which is displayed within the content rectangle of this button.
			Pointer<GUIImage> image;
			
			
			
			
			/// An image which is displayed within the content rectangle of this button when it is selected.
			Pointer<GUIImage> alternateImage;
			
			
			
			
			/// An object which describes how this button's text is aligned within the button.
			Origin textAlignment;
			
			
			
			
			/// An object which describes how this button's image is aligned within the button.
			Origin imageAlignment;
			
			
			
			
			/// An object which describes the border of this button.
			Border border;
			
			
			
			
			/// An object which contains function pointers that respond to button events.
			ButtonDelegate delegate;
			
			
			
			
			/// An object which represents the type of this button.
			ButtonType type;
			
			
			
			
			/// The background color for the button's main area.
			Color4f backgroundColor;
			
			
			
			
			/// The border color for the button.
			Color4f borderColor;
			
			
			
			
			/// The alternate color for the button when it is pressed.
			Color4f alternateColor;
			
			
			
			
			/// An object which determines the style of the text contained by this button.
			FontStyle textStyle;
			
			
			
			
			/// A boolean value indicating whether or not this button's text label is visible.
			Bool textIsVisible;
			
			
			
			
			/// A boolean value indicating whether or not this button's image is visible.
			Bool imageIsVisible;
			
			
			
			
			/// A boolean value which indicates whether or not this button is currently pressed.
			Bool isPressed;
			
			
			
			
			/// A boolean value which indicates whether or not this button is currently selected.
			Bool isSelected;
			
			
			
			
			/// A boolean value indicating whether or not this button is enabled and able to be pressed by the user.
			Bool isEnabled;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_BUTTON_H
