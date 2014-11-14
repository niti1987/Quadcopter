/*
 *  rimBoundingSphere.h
 *  Rim BVH
 *
 *  Created by Carl Schissler on 5/19/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_BOUNDING_SPHERE_H
#define INCLUDE_RIM_BOUNDING_SPHERE_H


#include "rimBVHConfig.h"


//##########################################################################################
//*****************************  Start Rim BVH Namespace  **********************************
RIM_BVH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a sphere that bounds a more complex geometric structure.
/**
  * Typically, this class will be used as part of a bounding volume hierarchy to
  * bound complex point or triangle data.
  */
template < typename T >
class BoundingSphere
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a BoundingSphere object that has a radius of 0 and a position centered at the origin.
			RIM_INLINE BoundingSphere()
				:	position(),
					radius( 0 )
			{
			}
			
			
			
			
			/// Create a BoundingSphere object with the specified center position and radius.
			/**
			  * @param newPosition - the position of the center of the BoundingSphere in 3D space.
			  * @param newRadius - the radius of the BoundingSphere.
			  */
			RIM_INLINE BoundingSphere( const Vector3D<T>& newPosition, T newRadius )
				:	position( newPosition ),
					radius( newRadius )
			{
			}
			
			
			
			
			/// Create a BoundingSphere object which tightly bounds the specified 3 points in space.
			/**
			  * Typically, this constructor is used to easily create a bounding sphere for a triangle
			  * when constructing a bounding volume hierarchy.
			  * 
			  * @param a - a point that should be enclosed by the BoundingSphere.
			  * @param b - a point that should be enclosed by the BoundingSphere.
			  * @param c - a point that should be enclosed by the BoundingSphere.
			  */
			BoundingSphere( const Vector3D<T>& a, const Vector3D<T>& b, const Vector3D<T>& c );
			
			
			
			
			/// Create a BoundingSphere object which encloses all of the points in the specified list.
			/**
			  * This constructor uses an implementation-defined method of generating a bounding sphere
			  * for an arbitrary set of points in 3D space. The resulting sphere is not guaranteed to 
			  * be a minimal bounding sphere but should offer a reasonably-tight fit of the input
			  * point set. If the number of input points is 0, the resulting BoundingSphere will
			  * be a sphere of 0 radius centered at the origin.
			  * 
			  * @param points - the points which this bounding sphere should enclose.
			  */
			BoundingSphere( const ArrayList< Vector3D<T> >& points );
			
			
			
			
			/// Create a BoundingSphere object which encloses all of the points in the specified array.
			/**
			  * This constructor uses an implementation-defined method of generating a bounding sphere
			  * for an arbitrary set of points in 3D space. The resulting sphere is not guaranteed to 
			  * be a minimal bounding sphere but should offer a reasonably-tight fit of the input
			  * point set. The constructor uses numPoints sequential points from the array of input points
			  * to construct the bounding sphere. If the number of input points is 0 or the point array
			  * is NULL, the resulting BoundingSphere will be a sphere of 0 radius centered at the origin.
			  * 
			  * @param points - a pointer to an array of input point data.
			  * @param numPoints - the number of sequential points to use from the point array.
			  */
			BoundingSphere( const Vector3D<T>* points, Size numPoints );
			
			
			
			
			/// Create a BoundingSphere object which encloses the two given bounding spheres.
			/**
			  * This constructor uses an implementation-defined method of generating a bounding sphere
			  * for an arbitrary set of points in 3D space. The resulting sphere is not guaranteed to 
			  * be a minimal bounding sphere but should offer a reasonably-tight fit of the input
			  * point set. The constructor uses numPoints sequential points from the array of input points
			  * to construct the bounding sphere. If the number of input points is 0 or the point array
			  * is NULL, the resulting BoundingSphere will be a sphere of 0 radius centered at the origin.
			  * 
			  * @param points - a pointer to an array of input point data.
			  * @param numPoints - the number of sequential points to use from the point array.
			  */
			RIM_INLINE BoundingSphere( const BoundingSphere& sphere1, const BoundingSphere& sphere2 )
			{
				BoundingSphere both = sphere1 + sphere2;
				position = both.position;
				radius = both.radius;
			}
			
			
			
			
			/// Create a copy of a BoundingSphere object with another templated type.
			/**
			  * @param other - the bounding sphere object which should be copied.
			  */
			template < typename U >
			RIM_INLINE BoundingSphere( const BoundingSphere<U>& other )
				:	radius( other.radius ),
					position( other.position )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign a BoundingSphere object with another templated type to this bounding sphere.
			/**
			  * @param other - the bounding sphere object which should be copied.
			  */
			template < typename U >
			RIM_INLINE BoundingSphere& operator = ( const BoundingSphere<U>& other )
			{
				position = other.position;
				radius = (T)other.radius;
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Intersection Test Method
			
			
			
			
			/// Return whether or not this BoundingSphere intersects another.
			/**
			  * If the spheres intersect, TRUE is returned. Otherwise, FALSE is 
			  * returned.
			  * 
			  * @param sphere - the sphere to test for intersection with this BoundingSphere.
			  * @return whether or not this BoundingSphere intersects another.
			  */
			RIM_FORCE_INLINE Bool intersects( const BoundingSphere& sphere ) const
			{
				register T distanceSquared = position.getDistanceToSquared( sphere.position );
				register T radii = radius + sphere.radius;
				
				return distanceSquared < radii*radii;
			}
			
			
			
			
			/// Return whether or not this bounding sphere is intersected by the specified ray.
			RIM_FORCE_INLINE Bool intersects( const Ray3D<T>& ray ) const
			{
				Vector3D<T> d = position - ray.origin;
				T dSquared = d.getMagnitudeSquared();
				T rSquared = radius*radius;
				
				if ( dSquared < rSquared )
				{
					// The ray starts inside the sphere and therefore we have an intersection.
					return true;
				}
				else
				{
					// Find the closest point on the ray to the sphere's center.
					T t1 = math::dot( d, ray.direction );
					
					if ( t1 < T(0) )
					{
						// The ray points away from the sphere so there is no intersection.
						return false;
					}
					
					// Find the distance from the closest point to the sphere's surface.
					T t2Squared = rSquared - dSquared + t1*t1;
					
					if ( t2Squared < T(0) )
						return false;
					
					return true;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Sphere Enlargement Methods
			
			
			
			
			/// Enlarge this bounding sphere so that it encloses both its original volume and the new sphere.
			RIM_INLINE void enlargeFor( const BoundingSphere& other )
			{
				// Compute the vector from the child's bounding sphere to current bounding sphere.
				Vector3D<T> v = other.position - position;
				T distanceSquared = v.getMagnitudeSquared();
				T radiusDiff = other.radius - radius;
				
				if ( distanceSquared < radiusDiff*radiusDiff )
				{
					// The other bounding sphere completely contains the previous bounding sphere.
					if ( other.radius > radius )
					{
						position = other.position;
						radius = other.radius;
					}
				}
				else
				{
					// the other sphere is outside the previous bounding sphere. Resize the bounding
					// sphere to fit the other sphere.
					T distance = math::sqrt( distanceSquared );
					T newRadius = (distance + other.radius + radius)*T(0.5);
					
					if ( distance > math::epsilon<T>() )
						position += v*((newRadius - radius) / distance);
					
					radius = newRadius;
				}
			}
			
			
			
			
			/// Enlarge this bounding sphere so that it encloses both its original volume and the given point.
			RIM_INLINE void enlargeFor( const Vector3D<T>& point )
			{
				// Compute the vector from the child's bounding sphere to current bounding sphere.
				Vector3D<T> v = point - position;
				T distanceSquared = v.getMagnitudeSquared();
				
				if ( distanceSquared > radius*radius )
				{
					// the point is outside the previous bounding sphere. Resize the bounding
					// sphere to enclose the point.
					T distance = math::sqrt( distanceSquared );
					T newRadius = (distance + radius)*T(0.5);
					
					position += v*((newRadius - radius) / distance);
					radius = newRadius;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Sphere Union Operator
			
			
			
			
			/// Compute the union of this bounding sphere with another.
			/**
			  * The resulting BoundingSphere object is guaranteed to tightly
			  * bound both the L-value BoundingSphere object as well as the R-value
			  * BoundingSphere.
			  * 
			  * @param sphere - the sphere to union with this BoundingSphere.
			  * @return a BoundingSphere which encloses both spheres.
			  */
			BoundingSphere operator + ( const BoundingSphere& sphere ) const
			{
				// Compute the squared distance between the sphere centers.
				Vector3D<T> d = sphere.position - position;
				T distanceSquared = d.getMagnitudeSquared();
				T radiusDiff = sphere.radius - radius;
				
				if ( radiusDiff*radiusDiff > distanceSquared )
				{
					// The sphere with the larger radius encloses the other.
					// Return the larger of these two spheres.
					if ( sphere.radius > radius )
						return sphere;
					else
						return *this;
				}
				else
				{
					// The spheres are partially overlapping or disjoint.
					T distance = math::sqrt(distanceSquared);
					T newRadius = (distance + radius + sphere.radius) * T(0.5);
					
					return BoundingSphere( distance > math::epsilon<T>() ? 
												position + ((newRadius - radius) / distance)*d
												: position,
											newRadius );
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The position of the center of this BoundingSphere.
			Vector3D<T> position;
			
			
			
			
			/// The radius of this BoundingSphere.
			T radius;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Compute the approximate bounding sphere for the specified array of points.
			RIM_FORCE_INLINE static void computeApproximateBoundingSphere( const Vector3D<T>* points, Size numPoints,
																		Vector3D<T>& position, T& radius );
			
			
			
			
			/// Compute the exact bounding sphere for three points.
			RIM_FORCE_INLINE static void computeTriangleBoundingSphere( const Vector3D<T>& a, const Vector3D<T>& b, const Vector3D<T>& c,
																		Vector3D<T>& position, T& radius );
			
			
			
			
};




//##########################################################################################
//*****************************  End Rim BVH Namespace  ************************************
RIM_BVH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_BOUNDING_SPHERE_H
