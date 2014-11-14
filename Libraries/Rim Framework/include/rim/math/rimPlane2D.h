/*
 *  rimPlane2D.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 10/15/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PLANE_2D_H
#define INCLUDE_RIM_PLANE_2D_H


#include "rimMathConfig.h"


#include "rimVector2D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a plane in 2D space.
/**
  * It uses the normal and offset plane representation as it is the most universally
  * useful in computational mathematics, especially relating to graphics and geometry.
  */
template < typename T >
class Plane2D
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a plane in 2D space with the normal pointing along the positive Y axis with offset = 0.
			RIM_FORCE_INLINE Plane2D()
				:	normal( 0, 1 ),
					offset( 0 )
			{
			}
			
			
			
			
			/// Create a plane in 2D space with the specified normal and offset from the origin.
			RIM_FORCE_INLINE Plane2D( const Vector2D<T>& planeNormal, T planeOffset )
				:	normal( planeNormal ),
					offset( planeOffset )
			{
			}
			
			
			
			
			/// Create a plane in 2D space from two points in that plane.
			RIM_FORCE_INLINE Plane2D( const Vector2D<T>& p1, const Vector2D<T>& p2 )
				:	normal( math::perp( p2 - p1 ).normalize() )
			{
				offset = -math::dot( p1, normal );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point Distance Methods
			
			
			
			
			/// Get the perpendicular distance from the specified point to the plane.
			RIM_FORCE_INLINE T getDistanceTo( const Vector2D<T>& point ) const
			{
				return math::abs( math::dot( normal, point ) + offset );
			}
			
			
			
			
			/// Get the perpendicular distance from the specified point to the plane.
			RIM_FORCE_INLINE T getSignedDistanceTo( const Vector2D<T>& point ) const
			{
				return math::dot( normal, point ) + offset;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point Projection Methods
			
			
			
			
			/// Return the projection of the given point onto the plane.
			RIM_FORCE_INLINE Vector2D<T> getProjection( const Vector2D<T>& point ) const
			{
				T t = getSignedDistanceTo(point) / math::dot( normal, normal );
				return point - t*normal;
			}
			
			
			
			
			/// Return the projection of the given point onto the plane.
			/**
			  * The plane is assumed to have a normal vector of unit length. This
			  * results in a significantly faster function, however the results are
			  * meaningless if the precondition is not met.
			  */
			RIM_FORCE_INLINE Vector2D<T> getProjectionNormalized( const Vector2D<T>& point ) const
			{
				return point - getSignedDistanceTo(point)*normal;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point Reflection Methods
			
			
			
			
			/// Get the reflection of a point over the plane.
			RIM_FORCE_INLINE Vector2D<T> getReflection( const Vector2D<T>& point ) const
			{
				T t = getSignedDistanceTo(point) / math::dot( normal, normal );
				return point - T(2)*t*normal;
			}
			
			
			
			
			/// Get the reflection of a point over the plane.
			RIM_FORCE_INLINE Vector2D<T> getReflectionNormalized( const Vector2D<T>& point ) const
			{
				return point - T(2)*getSignedDistanceTo(point)*normal;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Plane Normalization Method
			
			
			
			
			/// Normalize the plane's normal vector and correct the offset to match.
			RIM_FORCE_INLINE Plane2D normalize() const
			{
				T inverseMagnitude = T(1)/normal.getMagnitude();
				
				return Plane2D( normal*inverseMagnitude, offset*inverseMagnitude );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Plane Inversion Operator
			
			
			
			
			/// Return the plane with the opposite normal vector and offset.
			/** 
			  * This plane is mathematically the same as the original plane.
			  */
			RIM_FORCE_INLINE Plane2D operator - () const
			{
				return Plane2D( -normal, -offset );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// A vector perpendicular to the plane.
			Vector2D<T> normal;
			
			
			
			
			/// The distance that the plane is offset from the origin.
			T offset;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		2D Plane Type Definitions
//############		
//##########################################################################################
//##########################################################################################




typedef Plane2D<int> Plane2i;
typedef Plane2D<float> Plane2f;
typedef Plane2D<double> Plane2d;




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PLANE_2D_H
