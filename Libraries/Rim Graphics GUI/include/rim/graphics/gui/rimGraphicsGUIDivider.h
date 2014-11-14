/*
 *  rimGraphicsGUIDivider.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/7/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_DIVIDER_H
#define INCLUDE_RIM_GRAPHICS_GUI_DIVIDER_H


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
/// A class which represents a rectangular region that divides a view.
/**
  * The divider is a horizontal or vertical line aligned within the divider's
  * area.
  */
class Divider : public GUIObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new sizeless divider positioned at the origin of its coordinate system.
			Divider();
			
			
			
			
			/// Create a new divider which occupies the specified rectangle.
			Divider( const Rectangle& newRectangle, const Orientation& newOrientation = Orientation::HORIZONTAL );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Orientation Accessor Methods
			
			
			
			
			/// Return an object which describes how this divider's dividing line is rotated.
			RIM_INLINE const Orientation& getOrientation() const
			{
				return orientation;
			}
			
			
			
			
			/// Set an object which describes how this divider's dividing line is rotated.
			RIM_INLINE void setOrientation( const Orientation& newOrientation )
			{
				orientation = newOrientation;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Alignment Accessor Methods
			
			
			
			
			/// Return an object which describes how this divider's dividing line is aligned within its area.
			RIM_INLINE const Origin& getAlignment() const
			{
				return alignment;
			}
			
			
			
			
			/// Set an object which describes how this divider's dividing line is aligned within its area.
			RIM_INLINE void setAlignment( const Origin& newAlignment )
			{
				alignment = newAlignment;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Accessor Methods
			
			
			
			
			/// Return a mutable object which describes this divider's border.
			RIM_INLINE Border& getBorder()
			{
				return border;
			}
			
			
			
			
			/// Return an object which describes this divider's border.
			RIM_INLINE const Border& getBorder() const
			{
				return border;
			}
			
			
			
			
			/// Set an object which describes this divider's border.
			RIM_INLINE void setBorder( const Border& newBorder )
			{
				border = newBorder;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Divider Line Width Accessor Methods
			
			
			
			
			/// Return the width of this divider's dividing line.
			RIM_INLINE Float getDividerWidth() const
			{
				return dividerWidth;
			}
			
			
			
			
			/// Set the width of this divider's dividing line.
			RIM_INLINE void setDividerWidth( Float newDividerWidth )
			{
				dividerWidth = math::max( newDividerWidth, Float(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content Bounding Box Accessor Methods
			
			
			
			
			/// Return the 3D bounding box for the divider's dividing line in its local coordinate frame.
			RIM_INLINE AABB3f getLocalDividerBounds() const
			{
				return AABB3f( this->getLocalDividerBoundsXY(), AABB1f( Float(0), this->getSize().z ) );
			}
			
			
			
			
			/// Return the 2D bounding box for the divider's dividing line in its local coordinate frame.
			AABB2f getLocalDividerBoundsXY() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Background Color Accessor Methods
			
			
			
			
			/// Return the background color for this divider's dividing line.
			RIM_INLINE const Color4f& getBackgroundColor() const
			{
				return backgroundColor;
			}
			
			
			
			
			
			/// Set the background color for this divider's dividing line.
			RIM_INLINE void setBackgroundColor( const Color4f& newBackgroundColor )
			{
				backgroundColor = newBackgroundColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a divider's dividing line.
			RIM_INLINE const Color4f& getBorderColor() const
			{
				return borderColor;
			}
			
			
			
			
			
			/// Set the border color used when rendering a divider's dividing line.
			RIM_INLINE void setBorderColor( const Color4f& newBorderColor )
			{
				borderColor = newBorderColor;
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
			RIM_INLINE static Pointer<Divider> construct()
			{
				return Pointer<Divider>::construct();
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<Divider> construct( const Rectangle& newRectangle )
			{
				return Pointer<Divider>::construct( newRectangle );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// The default border that is used for a divider.
			static const Border DEFAULT_BORDER;
			
			
			/// The default line width that is used for a divider.
			static const Float DEFAULT_DIVIDER_WIDTH;
			
			
			/// The default color used for the main part of the divider's area.
			static const Color4f DEFAULT_BACKGROUND_COLOR;
			
			
			/// The default color used for the border of the divider's area.
			static const Color4f DEFAULT_BORDER_COLOR;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object which describes how this divider is rotated within its area.
			Orientation orientation;
			
			
			
			
			/// An object which describes how this divider is aligned within its area.
			Origin alignment;
			
			
			
			
			/// An object which describes the appearance of this divider's border.
			Border border;
			
			
			
			
			/// The width of the dividing line in vertical screen coordinates.
			Float dividerWidth;
			
			
			
			
			/// The color used for the main part of the divider's area.
			Color4f backgroundColor;
			
			
			
			
			/// The color used for the border of the divider's area.
			Color4f borderColor;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_DIVIDER_H
