/*
 *  rimPhysicsPrimitiveIntersectionTests.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 6/7/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_PRIMITIVE_INTERSECTION_TESTS_H
#define INCLUDE_RIM_PHYSICS_PRIMITIVE_INTERSECTION_TESTS_H


#include "rimPhysicsUtilitiesConfig.h"


#include "rimPhysicsIntersectionPoint.h"


//##########################################################################################
//**********************  Start Rim Physics Utilities Namespace  ***************************
RIM_PHYSICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


//##########################################################################################
//##########################################################################################
//############		
//############		Sphere Vs Sphere Intersection Tests
//############		
//##########################################################################################
//##########################################################################################




/// Return whether or not the two specified spheres intersect.
/**
  * Each sphere is specified by a 3D position and radius.
  */
RIM_FORCE_INLINE Bool sphereIntersectsSphere( const Vector3& position1, Real radius1,
										const Vector3& position2, Real radius2 )
{
	Real distanceSquared = (position2 - position1).getMagnitudeSquared();
	Real radii = radius1 + radius2;
	
	return distanceSquared > radii*radii;
}




/// Return whether or not the two specified spheres intersect and return the point of intersection.
/**
  * Each sphere is specified by a 3D position and radius. If the spheres
  * intersect, the intersection point on each sphere is computed and returned
  * in the specified IntersectionPoint object.
  */
RIM_INLINE Bool sphereIntersectsSphere( const Vector3& position1, Real radius1,
										const Vector3& position2, Real radius2,
										IntersectionPoint& intersectionPoint )
{
	Vector3 normal = position2 - position1;
	Real distanceSquared = normal.getMagnitudeSquared();
	Real radii = radius1 + radius2;
	
	if ( distanceSquared > radii*radii )
	{
		Real distance = math::sqrt( distanceSquared );
		normal /= distance;
		
		intersectionPoint.point1 = position1 + normal*radius1;
		intersectionPoint.point2 = position2 - normal*radius2;
		intersectionPoint.normal = normal;
		intersectionPoint.penetrationDistance = radii - distance;
		
		return true;
	}
	
	return false;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Other Intersection Tests
//############		
//##########################################################################################
//##########################################################################################




/// Return whether or not the specified sphere intersects a box and return the collision point.
Bool sphereIntersectsBox( const Vector3& spherePosition, Real sphereRadius,
						const Vector3& boxPosition, const Matrix3& boxOrientation, const Vector3& boxSize,
						IntersectionPoint& intersectionPoint );




/// Return whether or not the specified sphere intersects a cylinder and return the collision point.
Bool sphereIntersectsCylinder( const Vector3& spherePosition, Real sphereRadius,
							const Vector3& cylinderPoint1, const Vector3& cylinderAxis,
							Real cylinderHeight, Real cylinderRadius1, Real cylinderRadius2,
							IntersectionPoint& intersectionPoint );




//##########################################################################################
//**********************  End Rim Physics Utilities Namespace  *****************************
RIM_PHYSICS_UTILITES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_PRIMITIVE_INTERSECTION_TESTS_H
