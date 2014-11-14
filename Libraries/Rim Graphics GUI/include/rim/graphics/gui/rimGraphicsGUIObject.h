/*
 *  rimGraphicsGUIObject.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/22/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_OBJECT_H
#define INCLUDE_RIM_GRAPHICS_GUI_OBJECT_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObjectFlags.h"
#include "rimGraphicsGUIStyle.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class GUIRenderer;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the base class for an interactive rectangular region within a GUI.
class GUIObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a default visible GUI object positioned at the origin (0,0) with 0 width and 0 height.
			RIM_INLINE GUIObject()
				:	rectangle(),
					flags( GUIObjectFlags::DEFAULT )
			{
			}
			
			
			
			
			/// Create a visible GUI object which occupies the specified rectangle.
			RIM_INLINE GUIObject( const Rectangle& newRectangle )
				:	rectangle( newRectangle ),
					flags( GUIObjectFlags::DEFAULT )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destory the GUI object, releasing all internal resources.
			virtual ~GUIObject();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Rectangle Accessor Methods
			
			
			
			
			/// Return a reference to this GUI object's rectangle.
			/**
			  * This object represents the object's positioning and rotation relative to its
			  * parent coordinate system.
			  */
			RIM_INLINE const Rectangle& getRectangle() const
			{
				return rectangle;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return a reference to the 3D size of this object along each of its local axes.
			RIM_INLINE const Vector3f& getSize() const
			{
				return rectangle.size;
			}
			
			
			
			
			/// Return a reference to the 2D scaling factor of this object along each of its local axes.
			RIM_INLINE const Vector2f& getSizeXY() const
			{
				return *reinterpret_cast<const Vector2f*>( &rectangle.size );
			}
			
			
			
			
			/// Set the 3D size of this object along each of its local axes.
			/**
			  * The method returns whether or not the size of the object was able to be changed.
			  */
			virtual Bool setSize( const Vector3f& newSize );
			
			
			
			
			/// Set the 2D size of this object along the X and Y local axes.
			RIM_INLINE Bool setSize( const Vector2f& newSizeXY )
			{
				return this->setSize( Vector3f( newSizeXY, rectangle.size.z ) );
			}
			
			
			
			
			/// Set the 2D size of this object along the X and Y local axes.
			RIM_INLINE Bool setSize( Float newWidth, Float newHeight )
			{
				return this->setSize( Vector3f( newWidth, newHeight, rectangle.size.z ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return a reference to the 3D scaling factor of this object along each of its local axes.
			RIM_INLINE const Vector3f& getScale() const
			{
				return rectangle.transform.scale;
			}
			
			
			
			
			/// Return a reference to the 2D scaling factor of this object along each of its local axes.
			RIM_INLINE const Vector2f& getScaleXY() const
			{
				return *reinterpret_cast<const Vector2f*>( &rectangle.transform.scale );
			}
			
			
			
			
			/// Set the 3D scaling factor of this object along each of its local axes.
			/**
			  * The method returns whether or not the scale of the object was able to be changed.
			  */
			virtual Bool setScale( const Vector3f& newScale );
			
			
			
			
			/// Set the 2D scaling factor of this object along the X and Y local axes.
			RIM_INLINE Bool setScale( const Vector2f& newSizeXY )
			{
				return this->setScale( Vector3f( newSizeXY, rectangle.size.z ) );
			}
			
			
			
			
			/// Set the 2D scaling factor of this object along the X and Y local axes.
			RIM_INLINE Bool setScale( Float newWidth, Float newHeight )
			{
				return this->setScale( Vector3f( newWidth, newHeight, rectangle.size.z ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Position Accessor Methods
			
			
			
			
			/// Return the position of this GUI object's origin relative to its parent's coordinate origin.
			RIM_INLINE const Vector3f& getPosition() const
			{
				return rectangle.transform.position;
			}
			
			
			
			
			/// Return the 2D position of this GUI object's origin relative to its parent's coordinate origin.
			RIM_INLINE const Vector2f& getPositionXY() const
			{
				return *reinterpret_cast<const Vector2f*>( &rectangle.transform.position );
			}
			
			
			
			
			/// Set the position of this GUI object's origin relative to its parent's coordinate origin.
			RIM_INLINE Bool setPosition( const Vector2f& newPosition )
			{
				return this->setPosition( Vector3f( newPosition, this->getPosition().x ) );
			}
			
			
			
			
			/// Set the position of this GUI object's origin relative to its parent's coordinate origin.
			/**
			  * The method returns whether or not the position and origin of the object was able to be changed.
			  */
			virtual Bool setPosition( const Vector3f& newPosition );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Rotation Accessor Methods
			
			
			
			
			/// Return a 3x3 orthonormal matrix indicating the basis of this object's coordinate frame.
			RIM_INLINE const Matrix3f& getRotation() const
			{
				return rectangle.transform.orientation;
			}
			
			
			
			
			/// Set a 3x3 orthonormal matrix indicating the basis of this object's coordinate frame.
			/**
			  * The method returns whether or not the rotation of the object was able to be changed.
			  */
			virtual Bool setRotation( const Matrix3f& newRotation );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Origin Accessor Methods
			
			
			
			
			/// Return the alignment of the coordinate origin for this object.
			RIM_INLINE Origin& getOrigin()
			{
				return rectangle.origin;
			}
			
			
			
			
			/// Return the alignment of the coordinate origin for this object.
			RIM_INLINE const Origin& getOrigin() const
			{
				return rectangle.origin;
			}
			
			
			
			
			/// Set the alignment of the coordinate origin for this object.
			/**
			  * The method returns whether or not the origin of the object was able to be changed.
			  */
			virtual Bool setOrigin( const Origin& newPositionOrigin );
			
			
			
			
			/// Set the alignment of the coordinate origin for this object.
			RIM_INLINE void setOrigin( Origin::XOrigin newXOrigin, Origin::YOrigin newYOrigin )
			{
				rectangle.origin.setX( newXOrigin );
				rectangle.origin.setY( newYOrigin );
			}
			
			
			
			
			/// Set the alignment of the coordinate origin for this object.
			RIM_INLINE void setOrigin( Origin::XOrigin newXOrigin, Origin::YOrigin newYOrigin, Origin::ZOrigin newZOrigin )
			{
				rectangle.origin = Origin( newXOrigin, newYOrigin, newZOrigin );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Box Accessor Methods
			
			
			
			
			/// Return the 2D bounding box of this object in the coordinate frame of the specified parent bounding box.
			RIM_INLINE AABB2f getBoundsInParent( const AABB2f& parentBounds ) const
			{
				return rectangle.getBoundsInParent( parentBounds );
			}
			
			
			
			
			/// Return the 3D bounding box of this object in the coordinate frame of the specified parent bounding box.
			RIM_INLINE AABB3f getBoundsInParent( const AABB3f& parentBounds ) const
			{
				return rectangle.getBoundsInParent( parentBounds );
			}
			
			
			
			
			/// Return the 2D bounding box of this object in its local coordinate frame.
			RIM_INLINE AABB2f getLocalBoundsXY() const
			{
				return AABB2f( Vector2f(), rectangle.size.getXY() );
			}
			
			
			
			
			/// Return the 3D bounding box of this object in its local coordinate frame.
			RIM_INLINE AABB3f getLocalBounds() const
			{
				return AABB3f( Vector3f(), rectangle.size );
			}
			
			
			
			
			/// Return the 2D center of this object's rectangle in its local coordinate frame.
			RIM_INLINE Vector2f getLocalCenterXY() const
			{
				return Float(0.5)*rectangle.size.getXY();
			}
			
			
			
			
			/// Return the 3D center of this object's rectangle in its local coordinate frame.
			RIM_INLINE Vector3f getLocalCenter() const
			{
				return Float(0.5)*rectangle.size;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transformation Matrix Accessor Methods
			
			
			
			
			/// Return the object-space-to-parent-space homogeneous transformation matrix for the given parent bounding box.
			RIM_INLINE Matrix4f getTransformMatrix( const AABB3f& parentBounds ) const
			{
				return rectangle.getTransformMatrix( parentBounds );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point Transformation Methods
			
			
			
			
			/// Transform a 3D point in the parent coordinate system into this object's coordinate system.
			RIM_INLINE Vector2f transformToLocal( const Vector2f& pointInParent, const AABB2f& parentBounds ) const
			{
				return rectangle.transformToLocal( pointInParent, parentBounds );
			}
			
			
			
			
			/// Transform a 3D point in the parent coordinate system into this object's coordinate system.
			RIM_INLINE Vector3f transformToLocal( const Vector3f& pointInParent, const AABB3f& parentBounds ) const
			{
				return rectangle.transformToLocal( pointInParent, parentBounds );
			}
			
			
			
			
			/// Transform a 2D point in this object's local coordinate system into its parent's coordinate system.
			RIM_INLINE Vector2f transformFromLocal( const Vector2f& localPoint, const AABB2f& parentBounds ) const
			{
				return rectangle.transformFromLocal( localPoint, parentBounds );
			}
			
			
			
			
			/// Transform a 3D point in this object's local coordinate system into its parent's coordinate system.
			RIM_INLINE Vector3f transformFromLocal( const Vector3f& localPoint, const AABB3f& parentBounds ) const
			{
				return rectangle.transformFromLocal( localPoint, parentBounds );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vector Transformation Methods
			
			
			
			
			/// Transform a 3D vector in the parent coordinate system into this object's coordinate system.
			RIM_INLINE Vector2f transformVectorToLocal( const Vector2f& vectorInParent ) const
			{
				return rectangle.transformVectorToLocal( vectorInParent );
			}
			
			
			
			
			/// Transform a 3D vector in the parent coordinate system into this object's coordinate system.
			RIM_INLINE Vector3f transformVectorToLocal( const Vector3f& vectorInParent ) const
			{
				return rectangle.transformVectorToLocal( vectorInParent );
			}
			
			
			
			
			/// Transform a 2D vector in this object's local coordinate system into its parent's coordinate system.
			RIM_INLINE Vector2f transformVectorFromLocal( const Vector2f& localVector ) const
			{
				return rectangle.transformVectorFromLocal( localVector );
			}
			
			
			
			
			/// Transform a 3D vector in this object's local coordinate system into its parent's coordinate system.
			RIM_INLINE Vector3f transformVectorFromLocal( const Vector3f& localVector ) const
			{
				return rectangle.transformVectorFromLocal( localVector );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point Containment Methods
			
			
			
			
			/// Return whether or not this GUI object contains the specified local point within its local bounds.
			RIM_INLINE Bool containsLocalPoint( const Vector2f& localPoint ) const
			{
				return rectangle.containsLocalPoint( localPoint );
			}
			
			
			
			
			/// Return whether or not this GUI object contains the specified local point within its local bounds.
			RIM_INLINE Bool containsLocalPoint( const Vector3f& localPoint ) const
			{
				return rectangle.containsLocalPoint( localPoint );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Style Accessor Methods
			
			
			
			
			/// Return a pointer to the style object to use when drawing this GUI object.
			RIM_INLINE const Pointer<GUIStyle>& getStyle() const
			{
				return style;
			}
			
			
			
			
			/// Set a pointer to the style object to use when drawing this GUI object.
			RIM_INLINE void setStyle( const Pointer<GUIStyle>& newStyle )
			{
				style = newStyle;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flags Accessor Methods
			
			
			
			
			/// Return a reference to the flags for this GUI object.
			RIM_INLINE GUIObjectFlags& getFlags()
			{
				return flags;
			}
			
			
			
			
			/// Return a const reference to the flags for this GUI object.
			RIM_INLINE const GUIObjectFlags& getFlags() const
			{
				return flags;
			}
			
			
			
			
			/// Set the flags for this GUI object.
			RIM_INLINE void setFlags( const GUIObjectFlags& newFlags )
			{
				flags = newFlags;
			}
			
			
			
			
			/// Return whether or not the specified boolan flag is set for this GUI object.
			RIM_INLINE Bool flagIsSet( GUIObjectFlags::Flag flag ) const
			{
				return flags.isSet( flag );
			}
			
			
			
			
			/// Set whether or not the specified boolan flag is set for this GUI object.
			RIM_INLINE void setFlag( GUIObjectFlags::Flag flag, Bool newIsSet = true )
			{
				flags.set( flag, newIsSet );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Visibility Accessor Methods
			
			
			
			
			/// Return whether or not this GUI object should be drawn to the screen.
			RIM_INLINE Bool getIsVisible() const
			{
				return flags.isSet( GUIObjectFlags::VISIBLE );
			}
			
			
			
			
			/// Set whether or not this GUI object should be drawn to the screen.
			RIM_INLINE void setIsVisible( Bool newIsVisible )
			{
				flags.set( GUIObjectFlags::VISIBLE, newIsVisible );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Method
			
			
			
			
			/// Update the current internal state of this object for the specified time interval in seconds.
			/**
			  * This method can be used to update animations or other time-based effects that
			  * require a regular update interval. This method is usually called once for each frame
			  * that is rendered, but could be called at a different rate if desired.
			  *
			  * Objects are responsible for calling update() with the same time parameter for all
			  * child GUI objects that need to be updated.
			  */
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
			/**
			  * The default implementation does nothing.
			  */
			virtual void keyEvent( const KeyboardEvent& event );
			
			
			
			
			/// Handle the specified mouse motion event that occurred.
			/**
			  * The default implementation does nothing.
			  */
			virtual void mouseMotionEvent( const MouseMotionEvent& event );
			
			
			
			
			/// Handle the specified mouse button event that occurred.
			/**
			  * The default implementation does nothing.
			  */
			virtual void mouseButtonEvent( const MouseButtonEvent& event );
			
			
			
			
			/// Handle the specified mouse wheel event that occurred.
			/**
			  * The default implementation does nothing.
			  */
			virtual void mouseWheelEvent( const MouseWheelEvent& event );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A rectangle indicating the position, orientation, scaling, and size of this object.
			Rectangle rectangle;
			
			
			
			
			/// An object containing boolean configuration flags for this GUI object.
			GUIObjectFlags flags;
			
			
			
			
			/// A pointer to a style object for this GUI obejct.
			Pointer<GUIStyle> style;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_OBJECT_H
