/*
 *  rimGraphicsGUIScrollView.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/11/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_SCROLL_VIEW_H
#define INCLUDE_RIM_GRAPHICS_GUI_SCROLL_VIEW_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObject.h"
#include "rimGraphicsGUISlider.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which provides a scrolling content area that allows viewing of large scale GUI objects.
class ScrollView : public GUIObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new sizeless scroll view positioned at the origin of its coordinate system.
			ScrollView();
			
			
			
			
			/// Create a new scroll view which occupies the specified rectangle.
			ScrollView( const Rectangle& newRectangle );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Slider Width Accessor Methods
			
			
			
			
			/// Return the width in vertical screen coordinates of each scoll bar for this scroll view.
			RIM_INLINE Float getSliderWidth() const
			{
				return sliderWidth;
			}
			
			
			
			
			/// Set the width in vertical screen coordinates of each scoll bar for this scroll view.
			RIM_INLINE void setSliderWidth( Float newSliderWidth )
			{
				sliderWidth = newSliderWidth;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Slider Accessor Methods
			
			
			
			
			/// Return a reference to the horizontal slider for this scroll view.
			RIM_INLINE const Slider& getHorizontalSlider() const
			{
				return horizontalSlider;
			}
			
			
			
			
			/// Return a reference to the vertical slider for this scroll view.
			RIM_INLINE const Slider& getVerticalSlider() const
			{
				return verticalSlider;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Slider Alignment Accessor Methods
			
			
			
			
			/// Return an enum value indicating the vertical alignment of the scroll view's horizontal slider.
			RIM_INLINE Origin::YOrigin getHorizontalSliderAlignment() const
			{
				return horizontalSlider.getOrigin().getY();
			}
			
			
			
			
			/// Set an enum value indicating the vertical alignment of the scroll view's horizontal slider.
			/**
			  * This alignment must be either Origin::TOP or Origin::BOTTOM. Any other alignment
			  * will not be accepted and the method will return FALSE, indicating failure.
			  */
			Bool setHorizontalSliderAlignment( Origin::YOrigin newAlignment );
			
			
			
			
			/// Return an enum value indicating the horizontal alignment of the scroll view's vertical slider.
			RIM_INLINE Origin::XOrigin getVerticalSliderAlignment() const
			{
				return verticalSlider.getOrigin().getX();
			}
			
			
			
			
			/// Set an enum value indicating the horizontal alignment of the scroll view's vertical slider.
			/**
			  * This alignment must be either Origin::LEFT or Origin::RIGHT. Any other alignment
			  * will not be accepted and the method will return FALSE, indicating failure.
			  */
			Bool setVerticalSliderAlignment( Origin::XOrigin newAlignment );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Accessor Methods
			
			
			
			
			/// Return a mutable object which describes this scroll view's border.
			RIM_INLINE Border& getBorder()
			{
				return border;
			}
			
			
			
			
			/// Return an object which describes this scroll view's border.
			RIM_INLINE const Border& getBorder() const
			{
				return border;
			}
			
			
			
			
			/// Set an object which describes this scroll view's border.
			RIM_INLINE void setBorder( const Border& newBorder )
			{
				border = newBorder;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Accessor Methods
			
			
			
			
			/// Return the total number of GUIObjects that are part of this scroll view.
			RIM_INLINE Size getObjectCount() const
			{
				return objects.getSize();
			}
			
			
			
			
			/// Return a pointer to the object at the specified index in this scroll view.
			/**
			  * Objects are stored in back-to-front sorted order, such that the object
			  * with index 0 is the furthest toward the back of the object ordering.
			  */
			RIM_INLINE const Pointer<GUIObject>& getObject( Index objectIndex ) const
			{
				return objects[objectIndex];
			}
			
			
			
			
			/// Add the specified object to this scroll view.
			/**
			  * If the specified object pointer is NULL, the method fails and FALSE
			  * is returned. Otherwise, the object is inserted in the front-to-back order
			  * of the scroll view's objects and TRUE is returned.
			  */
			Bool addObject( const Pointer<GUIObject>& newObject );
			
			
			
			
			/// Remove the specified object from this scroll view.
			/**
			  * If the given object is part of this scroll view, the method removes it
			  * and returns TRUE. Otherwise, if the specified object is not found,
			  * the method doesn't modify the scroll view and FALSE is returned.
			  */
			Bool removeObject( const GUIObject* oldObject );
			
			
			
			
			/// Remove all objects from this scroll view.
			void clearObjects();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content Bounding Box Accessor Methods
			
			
			
			
			/// Return the 3D bounding box for the content view's content display area in its local coordinate frame.
			RIM_INLINE AABB3f getLocalContentBounds() const
			{
				return AABB3f( this->getLocalContentBoundsXY(),
								AABB1f( Float(0), this->getSize().z ) );
			}
			
			
			
			
			/// Return the bounding box for the scroll view's content display area in its local coordinate frame.
			AABB2f getLocalContentBoundsXY() const;
			
			
			
			
			/// Return the total 3D bounding box of this scroll view's content in its local coordinate system.
			RIM_INLINE AABB3f getLocalContentBoundsTotal() const
			{
				return AABB3f( this->getLocalContentBoundsTotalXY(),
								AABB1f( Float(0), this->getSize().z ) );
			}
			
			
			
			
			/// Return the total bounding box of this scroll view's content in its local coordinate system.
			AABB2f getLocalContentBoundsTotalXY() const;
			
			
			
			
			/// Return the visible 3D bounding box of this scroll view's content in its local coordinate system.
			RIM_INLINE AABB3f getLocalContentBoundsVisible() const
			{
				return AABB3f( this->getLocalContentBoundsVisibleXY(),
								AABB1f( Float(0), this->getSize().z ) );
			}
			
			
			
			
			/// Return the visible bounding box of this scroll view's content in its local coordinate system.
			/**
			  * The returned bounding box depends on the positioning of the scroll view's sliders
			  * and the total size of the content.
			  */
			AABB2f getLocalContentBoundsVisibleXY() const;
			
			
			
			
			/// Return the bounding box for the scroll view's dragable corner.
			AABB2f getLocalCornerBoundsXY() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Accessor Methods
			
			
			
			
			/// Return the background color for this scroll view's area.
			RIM_INLINE const Color4f& getBackgroundColor() const
			{
				return backgroundColor;
			}
			
			
			
			
			
			/// Set the background color for this scroll view's area.
			RIM_INLINE void setBackgroundColor( const Color4f& newBackgroundColor )
			{
				backgroundColor = newBackgroundColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a scroll view.
			RIM_INLINE const Color4f& getBorderColor() const
			{
				return borderColor;
			}
			
			
			
			
			/// Set the border color used when rendering a scroll view.
			RIM_INLINE void setBorderColor( const Color4f& newBorderColor )
			{
				borderColor = newBorderColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Method
			
			
			
			
			/// Update the current internal state of this scroll view for the specified time interval in seconds.
			virtual void update( Float dt );
			
			
			
			
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
		//******	Static Construction Methods
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<ScrollView> construct()
			{
				return Pointer<ScrollView>::construct();
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<ScrollView> construct( const Rectangle& newRectangle )
			{
				return Pointer<ScrollView>::construct( newRectangle );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// The default width that is used for a scroll view's sliders.
			static const Float DEFAULT_SLIDER_WIDTH;
			
			
			/// The default border that is used for a scroll view.
			static const Border DEFAULT_BORDER;
			
			
			/// The default background color that is used for a scroll view's area.
			static const Color4f DEFAULT_BACKGROUND_COLOR;
			
			
			/// The default border color that is used for a scroll view.
			static const Color4f DEFAULT_BORDER_COLOR;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Make sure that the list of objects is in sorted order based on their depths.
			void sortObjectsByDepth();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of all of the objects that are children of this scroll view.
			ArrayList< Pointer<GUIObject> > objects;
			
			
			
			
			/// An object which describes the border for this scroll view.
			Border border;
			
			
			
			
			/// An object which represents the horizontal scroll bar for this scroll view.
			Slider horizontalSlider;
			
			
			
			
			/// An object which represents the vertical scroll bar for this scroll view.
			Slider verticalSlider;
			
			
			
			
			/// The width of each scroll bar along its minor axis.
			Float sliderWidth;
			
			
			
			
			/// The background color for the scroll view's area.
			Color4f backgroundColor;
			
			
			
			
			/// The border color for the scroll view's background area.
			Color4f borderColor;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_SCROLL_VIEW_H
