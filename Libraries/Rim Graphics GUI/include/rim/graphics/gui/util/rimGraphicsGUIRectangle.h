/*
 *  rimGraphicsGUIRectangle.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/8/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_RECTANGLE_H
#define INCLUDE_RIM_GRAPHICS_GUI_RECTANGLE_H


#include "rimGraphicsGUIUtilitiesConfig.h"


#include "rimGraphicsGUIOrigin.h"


//##########################################################################################
//*******************  Start Rim Graphics GUI Utilities Namespace  *************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a rectangle positioned relative to a parent bounding box origin.
class Rectangle
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new rectangle which is position at the bottom left origin with 0 width and height.
			RIM_INLINE Rectangle()
				:	size(),
					transform(),
					origin()
			{
			}
			
			
			
			
			/// Create a new rectangle which has the specified size, position, and origin.
			RIM_INLINE Rectangle( const Vector2f& newSize, const Vector2f& newPosition = Vector2f(),
								const Origin& newPositionOrigin = Origin() )
				:	size( newSize, Float(0) ),
					transform( Vector3f( newPosition, Float(0) ) ),
					origin( newPositionOrigin )
			{
			}
			
			
			
			
			/// Create a new rectangle which has the specified size, position, and origin.
			RIM_INLINE Rectangle( const Vector3f& newSize, const Vector3f& newPosition = Vector3f(),
								const Origin& newPositionOrigin = Origin() )
				:	size( newSize ),
					transform( newPosition ),
					origin( newPositionOrigin )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point Transformation Methods
			
			
			
			
			/// Transform a 2D point in the parent coordinate system into this rectangles's coordinate system.
			Vector2f transformToLocal( const Vector2f& point, const AABB2f& parentBounds ) const;
			
			
			
			
			/// Transform a 3D point in the parent coordinate system into this rectangles's coordinate system.
			Vector3f transformToLocal( const Vector3f& point, const AABB3f& parentBounds ) const;
			
			
			
			
			/// Transform a 2D point in this rectangle's local coordinate system into its parent's coordinate system.
			Vector2f transformFromLocal( const Vector2f& point, const AABB2f& parentBounds ) const;
			
			
			
			
			/// Transform a 3D point in this rectangle's local coordinate system into its parent's coordinate system.
			Vector3f transformFromLocal( const Vector3f& point, const AABB3f& parentBounds ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vector Transformation Methods
			
			
			
			
			/// Transform a 2D vector in the parent coordinate system into this rectangles's coordinate system.
			Vector2f transformVectorToLocal( const Vector2f& vector ) const;
			
			
			
			
			/// Transform a 3D vector in the parent coordinate system into this rectangles's coordinate system.
			Vector3f transformVectorToLocal( const Vector3f& vector ) const;
			
			
			
			
			/// Transform a 2D vector in this rectangle's local coordinate system into its parent's coordinate system.
			Vector2f transformVectorFromLocal( const Vector2f& vector ) const;
			
			
			
			
			/// Transform a 3D vector in this rectangle's local coordinate system into its parent's coordinate system.
			Vector3f transformVectorFromLocal( const Vector3f& vector ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size in Parent Frame Accessor Methods
			
			
			
			
			/// Return the 3D size of this rectangle's bounding box in its parent coordinate frame.
			/**
			  * The method computes the projected size of this rectangle along its parent's coordinate
			  * axes.
			  */
			RIM_INLINE Vector3f getSizeInParent() const
			{
				return math::abs( transform.orientation*(transform.scale*size) );
			}
			
			
			
			
			/// Return the 2D bounding box of this rectangle in the coordinate frame of the specified parent bounding box.
			RIM_INLINE AABB2f getBoundsInParent( const AABB2f& parentBounds ) const
			{
				// Get the size of this rectangle in its parent coordinate frame.
				const Vector2f sizeInParent = this->getSizeInParent().getXY();
				
				// Compute the location of the origin for this rectangles's position within the parent bounding box.
				Vector2f originOffset = parentBounds.min + origin.getOffset( parentBounds.getSize(), sizeInParent );
				
				return AABB2f( originOffset, originOffset + sizeInParent );
			}
			
			
			
			
			/// Return the 3D bounding box of this rectangle in the coordinate frame of the specified parent bounding box.
			RIM_INLINE AABB3f getBoundsInParent( const AABB3f& parentBounds ) const
			{
				// Get the size of this rectangle in its parent coordinate frame.
				const Vector3f sizeInParent = this->getSizeInParent();
				
				// Compute the location of the origin for this rectangles's position within the parent bounding box.
				Vector3f originOffset = parentBounds.min + origin.getOffset( parentBounds.getSize(), sizeInParent );
				
				return AABB3f( originOffset, originOffset + sizeInParent );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Contains Point Methods
			
			
			
			
			/// Return whether or not the specified local point is contained within this rectangle.
			RIM_INLINE Bool containsLocalPoint( const Vector2f& point ) const
			{
				return point.x >= Float(0) && point.x <= size.x &&
						point.y >= Float(0) && point.y <= size.y;
			}
			
			
			
			
			/// Return whether or not the specified local point is contained within this rectangle.
			RIM_INLINE Bool containsLocalPoint( const Vector3f& point ) const
			{
				return point.x >= Float(0) && point.x <= size.x &&
						point.y >= Float(0) && point.y <= size.y &&
						point.z >= Float(0) && point.z <= size.z;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transformation Matrix Accessor Methods
			
			
			
			
			/// Return the rectangle-to-parent homogeneous transformation matrix.
			Matrix4f getTransformMatrix( const AABB3f& parentBounds ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// A 3D vector indicating the width, height, and depth of this rectangle before scaling.
			Vector3f size;
			
			
			
			
			/// A 3D transformation from rectangle-space to the rectangle's parent coordinate frame.
			Transform3f transform;
			
			
			
			
			/// An object representing the alignment of the coordinate origin for this rectangle.
			/**
			  * This includes the position of the parent coordinate system's origin, but also
			  * the location of the reference point on the rectangle. For instance, the default
			  * coordinate system (bottom left) places the origin for the parent system at the
			  * bottom left of the parent's bounds, and calculates all translation relative to
			  * the bottom left corner of this rectangle's bounding box.
			  */
			Origin origin;
			
			
			
};




//##########################################################################################
//*******************  End Rim Graphics GUI Utilities Namespace  ***************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_RECTANGLE_H
