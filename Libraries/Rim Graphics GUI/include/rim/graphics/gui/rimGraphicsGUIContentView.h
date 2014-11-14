/*
 *  rimGraphicsGUIContentView.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/13/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_CONTENT_VIEW_H
#define INCLUDE_RIM_GRAPHICS_GUI_CONTENT_VIEW_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObject.h"
#include "rimGraphicsGUIContentViewDelegate.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains a collection of GUI objects positioned within a 2D rectangle.
/**
  * A content view delegates UI actions to the objects that it contains, as well
  * as maintains a sorted order for drawing objects based on their depth.
  */
class ContentView : public GUIObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new content view with no width or height positioned at the origin.
			ContentView();
			
			
			
			
			/// Create a new empty content view which occupies the specified rectangular region.
			ContentView( const Rectangle& newRectangle );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Accessor Methods
			
			
			
			
			/// Return the total number of GUIObjects that are part of this content view.
			RIM_INLINE Size getObjectCount() const
			{
				return objects.getSize();
			}
			
			
			
			
			/// Return a pointer to the object at the specified index in this content view.
			/**
			  * Objects are stored in back-to-front sorted order, such that the object
			  * with index 0 is the furthest toward the back of the object ordering.
			  */
			RIM_INLINE const Pointer<GUIObject>& getObject( Index objectIndex ) const
			{
				return objects[objectIndex];
			}
			
			
			
			
			/// Add the specified object to this content view.
			/**
			  * If the specified object pointer is NULL, the method fails and FALSE
			  * is returned. Otherwise, the object is inserted in the front-to-back order
			  * of the content view's objects and TRUE is returned.
			  */
			Bool addObject( const Pointer<GUIObject>& newObject );
			
			
			
			
			/// Remove the specified object from this content view.
			/**
			  * If the given object is part of this content view, the method removes it
			  * and returns TRUE. Otherwise, if the specified object is not found,
			  * the method doesn't modify the content view and FALSE is returned.
			  */
			Bool removeObject( const GUIObject* oldObject );
			
			
			
			
			/// Remove all objects from this content view.
			void clearObjects();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Accessor Methods
			
			
			
			
			/// Return a mutable object which describes this content view's border.
			RIM_INLINE Border& getBorder()
			{
				return border;
			}
			
			
			
			
			/// Return an object which describes this content view's border.
			RIM_INLINE const Border& getBorder() const
			{
				return border;
			}
			
			
			
			
			/// Set an object which describes this content view's border.
			RIM_INLINE void setBorder( const Border& newBorder )
			{
				border = newBorder;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content Bounding Box Accessor Methods
			
			
			
			
			/// Return the 3D bounding box for the content view's content display area in its local coordinate frame.
			RIM_INLINE AABB3f getLocalContentBounds() const
			{
				return AABB3f( this->getLocalContentBoundsXY(), AABB1f( Float(0), this->getSize().z ) );
			}
			
			
			
			
			/// Return the 2D bounding box for the content view's content display area in its local coordinate frame.
			RIM_INLINE AABB2f getLocalContentBoundsXY() const
			{
				return border.getContentBounds( AABB2f( Vector2f(), this->getSizeXY() ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Accessor Methods
			
			
			
			
			/// Return the background color for this content view's main area.
			RIM_INLINE const Color4f& getBackgroundColor() const
			{
				return backgroundColor;
			}
			
			
			
			
			
			/// Set the background color for this content view's main area.
			RIM_INLINE void setBackgroundColor( const Color4f& newBackgroundColor )
			{
				backgroundColor = newBackgroundColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a content view.
			RIM_INLINE const Color4f& getBorderColor() const
			{
				return borderColor;
			}
			
			
			
			
			/// Set the border color used when rendering a content view.
			RIM_INLINE void setBorderColor( const Color4f& newBorderColor )
			{
				borderColor = newBorderColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Method
			
			
			
			
			/// Update the current internal state of this content view for the specified time interval in seconds.
			/**
			  * This method recursively calls the update() methods for all child objects
			  * so that they are updated.
			  */
			virtual void update( Float dt );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Drawing Method
			
			
			
			
			/// Draw this content view using the specified GUI renderer to the given parent coordinate system bounds.
			/**
			  * The method returns whether or not the content view was successfully drawn.
			  */
			virtual Bool drawSelf( GUIRenderer& renderer, const AABB3f& parentBounds ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Input Handling Methods
			
			
			
			
			/// Handle the specified keyboard event for the entire content view.
			virtual void keyEvent( const KeyboardEvent& event );
			
			
			
			
			/// Handle the specified mouse motion event for the entire content view.
			virtual void mouseMotionEvent( const MouseMotionEvent& event );
			
			
			
			
			/// Handle the specified mouse button event for the entire content view.
			virtual void mouseButtonEvent( const MouseButtonEvent& event );
			
			
			
			
			/// Handle the specified mouse wheel event for the entire content view.
			virtual void mouseWheelEvent( const MouseWheelEvent& event );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return a reference to the delegate which responds to events for this content view.
			RIM_INLINE ContentViewDelegate& getDelegate()
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this content view.
			RIM_INLINE const ContentViewDelegate& getDelegate() const
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this content view.
			RIM_INLINE void setDelegate( const ContentViewDelegate& newDelegate )
			{
				delegate = newDelegate;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Construction Methods
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<ContentView> construct()
			{
				return Pointer<ContentView>::construct();
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<ContentView> construct( const Rectangle& newRectangle )
			{
				return Pointer<ContentView>::construct( newRectangle );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// The default border that is used for a content view.
			static const Border DEFAULT_BORDER;
			
			
			/// The default background color that is used for a content view's area.
			static const Color4f DEFAULT_BACKGROUND_COLOR;
			
			
			/// The default border color that is used for a content view.
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
			
			
			
			
			/// A list of all of the objects that are part of this content view.
			ArrayList< Pointer<GUIObject> > objects;
			
			
			
			
			/// An object which describes the border for this content view.
			Border border;
			
			
			
			
			/// The background color for the content view's area.
			Color4f backgroundColor;
			
			
			
			
			/// The border color for the content view's background area.
			Color4f borderColor;
			
			
			
			
			/// An object which contains function pointers that respond to content view events.
			ContentViewDelegate delegate;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_CONTENT_VIEW_H
