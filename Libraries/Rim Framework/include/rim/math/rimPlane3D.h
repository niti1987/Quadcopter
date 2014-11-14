/*
 *  rimPlane3D.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 10/12/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PLANE_3D_H
#define INCLUDE_RIM_PLANE_3D_H


#include "rimMathConfig.h"


#include "rimVector3D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a plane in 3D space.
/**
  * It uses the normal and offset plane representation as it is the most universally
  * useful in computational mathematics, especially relating to graphics and geometry.
  */
template < typename T >
class Plane3D
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a plane in 3D space with the normal pointing along the positive Z axis with offset = 0.
			RIM_FORCE_INLINE Plane3D()
				:	normal( 0, 0, 1 ),
					offset( 0 )
			{
			}
			
			
			
			
			/// Create a plane in 3D space with the specified normal and offset from the origin.
			RIM_FORCE_INLINE Plane3D( const Vector3D<T>& planeNormal, T planeOffset )
				:	normal( planeNormal ),
					offset( planeOffset )
			{
			}
			
			
			
			
			/// Create a plane in 3D space from the specified normal and point on the plane.
			RIM_FORCE_INLINE Plane3D( const Vector3D<T>& planeNormal, const Vector3D<T>& pointOnPlane )
				:	normal( planeNormal ),
					offset( -math::dot( pointOnPlane, normal ) )
			{
			}
			
			
			
			
			/// Create a plane in 3D space from three points in that plane.
			RIM_FORCE_INLINE Plane3D( const Vector3D<T>& p1, const Vector3D<T>& p2, const Vector3D<T>& p3 )
				:	normal( math::cross( p2 - p1, p3 - p1 ).normalize() )
			{
				offset = -math::dot( p1, normal );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point Distance Methods
			
			
			
			
			/// Get the perpendicular distance from the specified point to the plane.
			RIM_FORCE_INLINE T getDistanceTo( const Vector3D<T>& point ) const
			{
				return math::abs( math::dot( normal, point ) + offset );
			}
			
			
			
			
			/// Get the perpendicular distance from the specified point to the plane.
			RIM_FORCE_INLINE T getSignedDistanceTo( const Vector3D<T>& point ) const
			{
				return math::dot( normal, point ) + offset;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point Projection Methods
			
			
			
			
			/// Return the projection of the given point onto the plane.
			RIM_FORCE_INLINE Vector3D<T> getProjection( const Vector3D<T>& point ) const
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
			RIM_FORCE_INLINE Vector3D<T> getProjectionNormalized( const Vector3D<T>& point ) const
			{
				return point - getSignedDistanceTo(point)*normal;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vector Projection Methods
			
			
			
			
			/// Return the projection of the given point onto the plane.
			RIM_FORCE_INLINE Vector3D<T> getVectorProjection( const Vector3D<T>& vector ) const
			{
				T t = math::dot(vector,normal) / math::dot( normal, normal );
				return vector - t*normal;
			}
			
			
			
			
			/// Return the projection of the given point onto the plane.
			/**
			  * The plane is assumed to have a normal vector of unit length. This
			  * results in a significantly faster function, however the results are
			  * meaningless if the precondition is not met.
			  */
			RIM_FORCE_INLINE Vector3D<T> getVectorProjectionNormalized( const Vector3D<T>& vector ) const
			{
				return vector - math::dot(vector,normal)*normal;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point Reflection Methods
			
			
			
			
			/// Get the reflection of a point over the plane.
			RIM_FORCE_INLINE Vector3D<T> getReflection( const Vector3D<T>& point ) const
			{
				T t = getSignedDistanceTo(point) / math::dot( normal, normal );
				return point - T(2)*t*normal;
			}
			
			
			
			
			/// Get the reflection of a point over the plane.
			/**
			  * The plane is assumed to have a normal vector of unit length. This
			  * results in a significantly faster function, however the results are
			  * meaningless if the precondition is not met.
			  */
			RIM_FORCE_INLINE Vector3D<T> getReflectionNormalized( const Vector3D<T>& point ) const
			{
				return point - T(2)*getSignedDistanceTo(point)*normal;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vector Reflection Methods
			
			
			
			
			/// Return the specular reflection of a vector off the plane.
			RIM_FORCE_INLINE Vector3D<T> getVectorReflection( const Vector3D<T>& vector ) const
			{
				T t = math::dot(vector,normal) / math::dot( normal, normal );
				return vector - T(2)*t*normal;
			}
			
			
			
			
			/// Return the specular reflection of a vector off the plane, if the plane has a unit normal vector.
			/**
			  * The plane is assumed to have a normal vector of unit length. This
			  * results in a significantly faster function, however the results are
			  * meaningless if the precondition is not met.
			  */
			RIM_FORCE_INLINE Vector3D<T> getVectorReflectionNormalized( const Vector3D<T>& vector ) const
			{
				return vector - T(2)*math::dot(vector,normal)*normal;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Plane Normalization Method
			
			
			
			
			/// Normalize the plane's normal vector and correct the offset to match.
			RIM_FORCE_INLINE Plane3D normalize() const
			{
				T inverseMagnitude = T(1)/normal.getMagnitude();
				
				return Plane3D( normal*inverseMagnitude, offset*inverseMagnitude );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Plane Inversion Operator
			
			
			
			
			/// Return the plane with the opposite normal vector and offset.
			/** 
			  * This plane is mathematically the same as the original plane.
			  */
			RIM_FORCE_INLINE Plane3D operator - () const
			{
				return Plane3D( -normal, -offset );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// A vector perpendicular to the plane.
			Vector3D<T> normal;
			
			
			
			
			/// The distance that the plane is offset from the origin.
			T offset;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		3D Plane Type Definitions
//############		
//##########################################################################################
//##########################################################################################




typedef Plane3D<int> Plane3i;
typedef Plane3D<float> Plane3f;
typedef Plane3D<double> Plane3d;




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PLANE_3D_H
