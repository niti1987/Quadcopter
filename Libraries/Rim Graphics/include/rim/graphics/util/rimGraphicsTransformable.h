/*
 *  rimGraphicsTransformable.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 7/3/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_TRANSFORMABLE_H
#define INCLUDE_RIM_GRAPHICS_TRANSFORMABLE_H


#include "rimGraphicsUtilitiesConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents an object that has a 3D transformation from object to world space.
/**
  * This is the base class for other types that have a transformation, such as
  * objects, shapes, and cameras. It gives them a common interface for graphics
  * systems like animation.
  */
class Transformable
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new transformable with the identity transformation.
			Transformable();
			
			
			
			
			/// Create a new transformable with the specified transformation.
			Transformable( const Transform3& newTransform );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this transformable, releasing all associated resources.
			virtual ~Transformable();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Position Accessor Methods
			
			
			
			
			/// Return the position of this transformable.
			/**
			  * This position is specifid relative to the origin of the
			  * enclosing coordinate space.
			  */
			RIM_INLINE const Vector3& getPosition() const
			{
				return transform.position;
			}
			
			
			
			
			/// Set the position of this transformable.
			/**
			  * This position is specifid relative to the origin of the
			  * enclosing coordinate space.
			  */
			RIM_INLINE void setPosition( const Vector3& newPosition )
			{
				transform.position = newPosition;
				boundingBoxNeedsUpdate = true;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Orientation Accessor Methods
			
			
			
			
			/// Return the orientation of this transformable.
			RIM_INLINE const Matrix3& getOrientation() const
			{
				return transform.orientation;
			}
			
			
			
			
			/// Set the orientation of this transformable.
			void setOrientation( const Matrix3& newOrientation );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Scale Accessor Methods
			
			
			
			
			/// Get the scale of the transformable.
			RIM_INLINE const Vector3& getScale() const
			{
				return transform.scale;
			}
			
			
			
			
			/// Set the scale of the transformable uniformly for all dimensions.
			RIM_INLINE void setScale( Real newScale )
			{
				transform.scale = Vector3(newScale);
				boundingBoxNeedsUpdate = true;
			}
			
			
			
			
			/// Set the scale of the transformable.
			RIM_INLINE void setScale( const Vector3& newScale )
			{
				transform.scale = newScale;
				boundingBoxNeedsUpdate = true;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transform Accessor Methods
			
			
			
			
			/// Return the transformation for this transformable between its local and parent coordinate frame.
			RIM_INLINE const Transform3& getTransform() const
			{
				return transform;
			}
			
			
			
			
			/// Set the transformation for this transformable between its local and parent coordinate frame.
			/**
			  * This method ensures that the transformable's new orientation matrix is orthonormal.
			  */
			void setTransform( const Transform3& newTransform );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transform Matrix Accessor Methods
			
			
			
			
			/// Return a 4x4 matrix representing the transformation from object to world space.
			Matrix4 getTransformMatrix() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Volume Accessor Method
			
			
			
			
			/// Return an axis-aligned bounding box that encompases this entire transformable in its parent coordinate space.
			RIM_FORCE_INLINE const AABB3& getBoundingBox() const
			{
				if ( boundingBoxNeedsUpdate )
					updateBoundingBoxFromLocal();
				
				return boundingBox;
			}
			
			
			
			
			/// Return an axis-aligned bounding box that encompases this entire transformable in its local coordinate space.
			RIM_FORCE_INLINE const AABB3& getLocalBoundingBox() const
			{
				return localBoundingBox;
			}
			
			
			
			
			/// Update the transformable's bounding box based on its current geometric representation.
			virtual void updateBoundingBox();
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Box Accessor Method
			
			
			
			
			/// Set the local axis-aligned bounding box for this shape.
			/**
			  * Shape subclasses should call this method to set the bounding box of their
			  * geometry in their local coordinate frames (before applying the shape's own transformation).
			  */
			RIM_INLINE void setLocalBoundingBox( const AABB3& newLocalBoundingBox )
			{
				localBoundingBox = newLocalBoundingBox;
				boundingBoxNeedsUpdate = true;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Data Members
			
			
			
			
			/// The transformation for this transformable between its local and parent coordinate frame.
			Transform3 transform;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Update the shape's parent-space bounding box from its local-space bounding box.
			void updateBoundingBoxFromLocal() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An axis-aligned bounding box for this transformable in its local coordinate frame.
			AABB3 localBoundingBox;
			
			
			
			
			/// An axis-aligned bounding box for this transformable in its parent coordinate frame.
			mutable AABB3 boundingBox;
			
			
			
			
			/// A boolean value indicating whether or not this shape's parent-space bounding box needs updating.
			mutable Bool boundingBoxNeedsUpdate;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_TRANSFORMABLE_H
