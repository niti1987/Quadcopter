/*
 *  rimGraphicsViewVolume.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 12/5/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_VIEW_VOLUME_H
#define INCLUDE_RIM_GRAPHICS_VIEW_VOLUME_H


#include "rimGraphicsUtilitiesConfig.h"


#include "rimGraphicsBoundingCone.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a visible region of space.
/**
  * A ViewVolume is specified as the intersection of the half-spaces defined by
  * six viewing planes. Typically, these planes will represent the six sides of a
  * canonical viewing frustum.
  *
  * This class provides methods to determine whether or not a view volume contains
  * any part of several types of geometric primitives: points, spheres, cones, and
  * axis-aligned bounding boxes.
  */
class ViewVolume
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// The return value for an intersection routine when an object is completely inside the view volume.
			static const UInt INSIDE = 2;
			
			
			
			
			/// The return value for an intersection routine when an object intersects the boundary of the view volume.
			static const UInt INTERSECTS = 1;
			
			
			
			
			/// The return value for an intersection routine when an object is outside of the view volume.
			static const UInt OUTSIDE = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a view volume with the specified bounding planes.
			/**
			  * By convention, the normals of all planes should point towards the
			  * interior of the view volume.
			  */
			ViewVolume( const Plane3& newNear, const Plane3& newFar,
						const Plane3& newLeft, const Plane3& newRight,
						const Plane3& newTop, const Plane3& newBottom );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Intersection Query Methods
			
			
			
			
			/// Return whether or not the specified point is contained by this view volume.
			RIM_INLINE Bool intersects( const Vector3& point ) const
			{
				if ( left.getSignedDistanceTo( point ) < Real(0) ||
					right.getSignedDistanceTo( point ) < Real(0) ||
					top.getSignedDistanceTo( point ) < Real(0) ||
					bottom.getSignedDistanceTo( point ) < Real(0) ||
					near.getSignedDistanceTo( point ) < Real(0) ||
					far.getSignedDistanceTo( point ) < Real(0) )
				{
					return false;
				}
				else
					return true;
			}
			
			
			
			
			/// Return whether or not the specified bounding sphere intersects this view volume.
			RIM_INLINE Bool intersects( const BoundingSphere& sphere ) const
			{
				if ( left.getSignedDistanceTo( sphere.position ) < -sphere.radius ||
					right.getSignedDistanceTo( sphere.position ) < -sphere.radius ||
					top.getSignedDistanceTo( sphere.position ) < -sphere.radius ||
					bottom.getSignedDistanceTo( sphere.position ) < -sphere.radius ||
					near.getSignedDistanceTo( sphere.position ) < -sphere.radius ||
					far.getSignedDistanceTo( sphere.position ) < -sphere.radius )
				{
					return false;
				}
				else
					return true;
			}
			
			
			
			
			/// Return whether or not the specified bounding cone intersects this view volume.
			Bool intersects( const BoundingCone& cone ) const;
			
			
			
			
			/// Return whether or not the specified point is contained by this view volume.
			UInt intersects( const AABB3& box ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Near Plane Accessor Methods
			
			
			
			
			/// Get the near clipping plane of this view volume.
			RIM_INLINE const Plane3& getNearPlane() const
			{
				return near;
			}
			
			
			
			
			/// Set the near clipping plane of this view volume.
			RIM_INLINE void setNearPlane( const Plane3& newNear )
			{
				near = newNear;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Far Plane Accessor Methods
			
			
			
			
			/// Get the far clipping plane of this view volume.
			RIM_INLINE const Plane3& getFarPlane() const
			{
				return far;
			}
			
			
			
			
			/// Set the far clipping plane of this view volume.
			RIM_INLINE void setFarPlane( const Plane3& newFar )
			{
				far = newFar;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Left Plane Accessor Methods
			
			
			
			
			/// Get the left clipping plane of this view volume.
			RIM_INLINE const Plane3& getLeftPlane() const
			{
				return left;
			}
			
			
			
			
			/// Set the left clipping plane of this view volume.
			RIM_INLINE void setLeftPlane( const Plane3& newLeft )
			{
				left = newLeft;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Right Plane Accessor Methods
			
			
			
			
			/// Get the right clipping plane of this view volume.
			RIM_INLINE const Plane3& getRightPlane() const
			{
				return right;
			}
			
			
			
			
			/// Set the right clipping plane of this view volume.
			RIM_INLINE void setRightPlane( const Plane3& newRight )
			{
				right = newRight;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Top Plane Accessor Methods
			
			
			
			
			/// Get the top clipping plane of this view volume.
			RIM_INLINE const Plane3& getTopPlane() const
			{
				return top;
			}
			
			
			
			
			/// Set the top clipping plane of this view volume.
			RIM_INLINE void setTopPlane( const Plane3& newTop )
			{
				top = newTop;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bottom Plane Accessor Methods
			
			
			
			
			/// Get the bottom clipping plane of this view volume.
			RIM_INLINE const Plane3& getBottomPlane() const
			{
				return bottom;
			}
			
			
			
			
			/// Set the bottom clipping plane of this view volume.
			RIM_INLINE void setBottomPlane( const Plane3& newBottom )
			{
				bottom = newBottom;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Methodds
			
			
			
			
			/// Return whether or not all of the specified vertices are behind a plane.
			RIM_FORCE_INLINE static Bool verticesAreBehindPlane( const Plane3& plane,
																const Vector3* vertices );
			
			
			
			
			/// Return whether or not a cone is entirely behind a plane.
			RIM_FORCE_INLINE static Bool coneIsBehindPlane( const Plane3& plane, const BoundingCone& cone );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The near clipping plane of the view volume.
			Plane3 near;
			
			
			
			
			/// The far clipping plane of the view volume.
			Plane3 far;
			
			
			
			
			/// The left clipping plane of the view volume.
			Plane3 left;
			
			
			
			
			/// The right clipping plane of the view volume.
			Plane3 right;
			
			
			
			
			/// The top clipping plane of the view volume.
			Plane3 top;
			
			
			
			
			/// The bottom clipping plane of the view volume.
			Plane3 bottom;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_VIEW_VOLUME_H
