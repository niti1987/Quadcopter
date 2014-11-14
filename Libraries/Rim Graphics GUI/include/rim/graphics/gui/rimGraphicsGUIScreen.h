/*
 *  rimGraphicsScreen.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/22/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_SCREEN_H
#define INCLUDE_RIM_GRAPHICS_GUI_SCREEN_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObject.h"
#include "rimGraphicsGUIScreenDelegate.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains a collection of scaled GUI objects positioned within a 2D rectangle.
/**
  * The primary purpose of this class is to provide an adapter which allows resolution-
  * independent GUI rendering. It accomplishes this by applying a scaling factor to
  * its child coordinate system such that child objects are rendered and updated as
  * if they were at the scaled size. The default scaling factor is 1, indicating that all
  * child objects will be drawn at the same resolution as the screen. By varying the
  * scaling factor and the screen's size, a user can resize a GUI to be any on-screen size
  * in pixels.
  *
  * A screen delegates UI actions to the objects that it contains, as well
  * as maintains a sorted order for drawing objects based on their depth.
  */
class Screen : public GUIObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new empty screen with no width or height positioned at the origin.
			Screen();
			
			
			
			
			/// Create a new empty screen which occupies the specified rectangular region.
			Screen( const Rectangle& newRectangle );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Accessor Methods
			
			
			
			
			/// Return the total number of GUIObjects that are part of this screen.
			RIM_INLINE Size getObjectCount() const
			{
				return objects.getSize();
			}
			
			
			
			
			/// Return a pointer to the object at the specified index in this screen.
			/**
			  * Objects are stored in back-to-front sorted order, such that the object
			  * with index 0 is the furthest toward the back of the object ordering.
			  */
			RIM_INLINE const Pointer<GUIObject>& getObject( Index objectIndex ) const
			{
				return objects[objectIndex];
			}
			
			
			
			
			/// Add the specified object to this screen.
			/**
			  * If the specified object pointer is NULL, the method fails and FALSE
			  * is returned. Otherwise, the object is inserted in the front-to-back order
			  * of the screen's objects and TRUE is returned.
			  */
			Bool addObject( const Pointer<GUIObject>& newObject );
			
			
			
			
			/// Remove the specified object from this screen.
			/**
			  * If the given object is part of this screen, the method removes it
			  * and returns TRUE. Otherwise, if the specified object is not found,
			  * the method doesn't modify the screen and FALSE is returned.
			  */
			Bool removeObject( const GUIObject* oldObject );
			
			
			
			
			/// Remove all objects from this screen.
			void clearObjects();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Accessor Methods
			
			
			
			
			/// Return a mutable object which describes this screen's border.
			RIM_INLINE Border& getBorder()
			{
				return border;
			}
			
			
			
			
			/// Return an object which describes this screen's border.
			RIM_INLINE const Border& getBorder() const
			{
				return border;
			}
			
			
			
			
			/// Set an object which describes this screen's border.
			RIM_INLINE void setBorder( const Border& newBorder )
			{
				border = newBorder;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content Bounding Box Accessor Methods
			
			
			
			
			/// Return the 3D bounding box for the screens's main area in its local coordinate frame.
			RIM_INLINE AABB3f getLocalContentBounds() const
			{
				return AABB3f( border.getContentBounds( AABB2f( Vector2f(), this->getSizeXY() ) ),
								AABB1f( Float(0), this->getSize().z ) );
			}
			
			
			
			
			/// Return the 2D bounding box for the screens's main area in its local coordinate frame.
			RIM_INLINE AABB2f getLocalContentBoundsXY() const
			{
				return border.getContentBounds( AABB2f( Vector2f(), this->getSizeXY() ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Accessor Methods
			
			
			
			
			/// Return the background color for this screen's main area.
			RIM_INLINE const Color4f& getBackgroundColor() const
			{
				return backgroundColor;
			}
			
			
			
			
			
			/// Set the background color for this screen's main area.
			RIM_INLINE void setBackgroundColor( const Color4f& newBackgroundColor )
			{
				backgroundColor = newBackgroundColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a screen.
			RIM_INLINE const Color4f& getBorderColor() const
			{
				return borderColor;
			}
			
			
			
			
			/// Set the border color used when rendering a screen.
			RIM_INLINE void setBorderColor( const Color4f& newBorderColor )
			{
				borderColor = newBorderColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Method
			
			
			
			
			/// Update the current internal state of this screen for the specified time interval in seconds.
			/**
			  * This method recursively calls the update() methods for all child GUI objects
			  * so that they are updated.
			  */
			virtual void update( Float dt );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Drawing Method
			
			
			
			
			/// Draw this screen using the specified GUI renderer to the given parent coordinate system bounds.
			/**
			  * The method returns whether or not the screen was successfully drawn.
			  *
			  * The default implementation calls the renderer's drawScreen() method to
			  * draw the screen.
			  */
			virtual Bool drawSelf( GUIRenderer& renderer, const AABB3f& parentBounds ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Input Handling Methods
			
			
			
			
			/// Handle the specified keyboard event for the entire screen.
			virtual void keyEvent( const KeyboardEvent& event );
			
			
			
			
			/// Handle the specified mouse motion event for the entire screen.
			virtual void mouseMotionEvent( const MouseMotionEvent& event );
			
			
			
			
			/// Handle the specified mouse button event for the entire screen.
			virtual void mouseButtonEvent( const MouseButtonEvent& event );
			
			
			
			
			/// Handle the specified mouse wheel event for the entire screen.
			virtual void mouseWheelEvent( const MouseWheelEvent& event );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return a reference to the delegate which responds to events for this screen.
			RIM_INLINE ScreenDelegate& getDelegate()
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this screen.
			RIM_INLINE const ScreenDelegate& getDelegate() const
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this screen.
			RIM_INLINE void setDelegate( const ScreenDelegate& newDelegate )
			{
				delegate = newDelegate;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Construction Methods
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<Screen> construct()
			{
				return Pointer<Screen>::construct();
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<Screen> construct( const Rectangle& newRectangle )
			{
				return Pointer<Screen>::construct( newRectangle );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// The default border that is used for a screen.
			static const Border DEFAULT_BORDER;
			
			
			/// The default background color that is used for a screen's area.
			static const Color4f DEFAULT_BACKGROUND_COLOR;
			
			
			/// The default border color that is used for a screen.
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
			
			
			
			
			/// A list of all of the objects that are part of this screen.
			ArrayList< Pointer<GUIObject> > objects;
			
			
			
			
			/// An object which describes the border for this screen.
			Border border;
			
			
			
			
			/// An object which contains function pointers that respond to screen events.
			ScreenDelegate delegate;
			
			
			
			
			/// The background color for the screen's area.
			Color4f backgroundColor;
			
			
			
			
			/// The border color for the screen's background area.
			Color4f borderColor;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_SCREEN_H
