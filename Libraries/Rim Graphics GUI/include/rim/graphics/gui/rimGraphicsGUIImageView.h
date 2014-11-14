/*
 *  rimGraphicsGUIImageView.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/13/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_IMAGE_VIEW_H
#define INCLUDE_RIM_GRAPHICS_GUI_IMAGE_VIEW_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObject.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a rectangular region that can be clicked on to perform an action.
class ImageView : public GUIObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new sizeless image view positioned at the origin of its coordinate system.
			ImageView();
			
			
			
			
			/// Create a new image view which occupies the specified rectangle with no image.
			ImageView( const Rectangle& newRectangle );
			
			
			
			
			/// Create a new image view which occupies the specified rectangle with the specified image.
			ImageView( const Rectangle& newRectangle, const Pointer<GUIImage>& newImage );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Accessor Methods
			
			
			
			
			/// Return a reference to the image which is displayed with this image view.
			RIM_INLINE const Pointer<GUIImage>& getImage() const
			{
				return image;
			}
			
			
			
			
			/// Set the image which is displayed with this image view.
			RIM_INLINE void setImage( const Pointer<GUIImage>& newImage )
			{
				image = newImage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Alignment Accessor Methods
			
			
			
			
			/// Return an object which describes how this image view's image is aligned within the view's area.
			RIM_INLINE const Origin& getAlignment() const
			{
				return alignment;
			}
			
			
			
			
			/// Set an object which describes how this image view's image is aligned within the view's area.
			RIM_INLINE void setAlignment( const Origin& newAlignment )
			{
				alignment = newAlignment;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Accessor Methods
			
			
			
			
			/// Return a mutable object which describes this image view's border.
			RIM_INLINE Border& getBorder()
			{
				return border;
			}
			
			
			
			
			/// Return an object which describes this image view's border.
			RIM_INLINE const Border& getBorder() const
			{
				return border;
			}
			
			
			
			
			/// Set an object which describes this image view's border.
			RIM_INLINE void setBorder( const Border& newBorder )
			{
				border = newBorder;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content Bounding Box Accessor Methods
			
			
			
			
			/// Return the 3D bounding box for the image view's content display area in its local coordinate frame.
			RIM_INLINE AABB3f getLocalContentBounds() const
			{
				return AABB3f( this->getLocalContentBoundsXY(), AABB1f( Float(0), this->getSize().z ) );
			}
			
			
			
			
			/// Return the 2D bounding box for the image view's content display area in its local coordinate frame.
			RIM_INLINE AABB2f getLocalContentBoundsXY() const
			{
				return border.getContentBounds( AABB2f( Vector2f(), this->getSizeXY() ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Background Color Accessor Methods
			
			
			
			
			/// Return the background color for this image view's main area.
			RIM_INLINE const Color4f& getBackgroundColor() const
			{
				return backgroundColor;
			}
			
			
			
			
			
			/// Set the background color for this image view's main area.
			RIM_INLINE void setBackgroundColor( const Color4f& newBackgroundColor )
			{
				backgroundColor = newBackgroundColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering an image view.
			RIM_INLINE const Color4f& getBorderColor() const
			{
				return borderColor;
			}
			
			
			
			
			
			/// Set the border color used when rendering an image view.
			RIM_INLINE void setBorderColor( const Color4f& newBorderColor )
			{
				borderColor = newBorderColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Color Accessor Methods
			
			
			
			
			/// Return the tint color for this image view's image.
			RIM_INLINE const Color4f& getImageColor() const
			{
				return imageColor;
			}
			
			
			
			
			
			/// Set the tint color for this image view's image.
			RIM_INLINE void setImageColor( const Color4f& newImageColor )
			{
				imageColor = newImageColor;
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
		//******	Static Construction Methods
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<ImageView> construct()
			{
				return Pointer<ImageView>::construct();
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<ImageView> construct( const Rectangle& newRectangle )
			{
				return Pointer<ImageView>::construct( newRectangle );
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<ImageView> construct( const Rectangle& newRectangle, const Pointer<GUIImage>& newImage )
			{
				return Pointer<ImageView>::construct( newRectangle, newImage );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// The default border that is used for a button.
			static const Border DEFAULT_BORDER;

			
			/// The default alignment that is used for an image view's image within its content area.
			static const Origin DEFAULT_ALIGNMENT;
			
			
			/// The default background color that is used for an image view's area.
			static const Color4f DEFAULT_BACKGROUND_COLOR;
			
			
			/// The default border color that is used for a image view.
			static const Color4f DEFAULT_BORDER_COLOR;
			
			
			/// The default color to use to shade the image (multiply).
			static const Color4f DEFAULT_IMAGE_COLOR;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An image which is displayed within the content rectangle of this image view.
			Pointer<GUIImage> image;
			
			
			
			
			/// An object which describes how the image is aligned within the view's area.
			Origin alignment;
			
			
			
			
			/// An object which describes the appearance of this image view's border.
			Border border;
			
			
			
			
			/// The background color for the image view's area.
			Color4f backgroundColor;
			
			
			
			
			/// The border color for the image view's area.
			Color4f borderColor;
			
			
			
			
			/// A color which is used to multiplicatively tint an image.
			Color4f imageColor;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_IMAGE_VIEW_H
