/*
 *  rimPhysicsCollisionAlgorithmFunctions.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 7/6/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_FUNCTIONS_H
#define INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_FUNCTIONS_H


#include "rimPhysicsCollisionConfig.h"


#include "rimPhysicsCollisionAlgorithmFunction.h"
#include "rimPhysicsCollisionAlgorithmsGJK.h"


//##########################################################################################
//**********************  Start Rim Physics Collision Namespace  ***************************
RIM_PHYSICS_COLLISION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


//##########################################################################################
//##########################################################################################
//############		
//############		Plane vs Sphere Intersection Detection Functions
//############		
//##########################################################################################
//##########################################################################################




RIM_INLINE Bool getPlaneVsSphereIntersection( const CollisionShapePlane::Instance* plane, 
											const CollisionShapeSphere::Instance* sphere,
											IntersectionPoint& point )
{
	// Get the projection of the sphere's position onto the plane.
	Vector3 projection = plane->getPlane().getProjectionNormalized( sphere->getPosition() );
	
	// The vector from the plane projection to the sphere's center.
	Vector3 d = sphere->getPosition() - projection;
	
	// The squared distance from the sphere's center to the plane projection.
	Real distanceSquared = d.getMagnitudeSquared();
	
	if ( distanceSquared < sphere->getRadius()*sphere->getRadius() )
	{
		Real distance = math::sqrt( distanceSquared );
		
		point.point1 = projection;
		point.point2 = sphere->getPosition() - plane->getNormal()*sphere->getRadius();
		point.normal = plane->getNormal();
		point.penetrationDistance = sphere->getRadius() - distance;
		
		return true;
	}
	
	return false;
}




RIM_INLINE Bool getSphereVsPlaneIntersection( const CollisionShapeSphere::Instance* sphere, 
											const CollisionShapePlane::Instance* plane,
											IntersectionPoint& point )
{
	Bool result = getPlaneVsSphereIntersection( plane, sphere, point );
	
	if ( result )
		point.reverse();
	
	return result;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Plane vs Capsule Intersection Detection Functions
//############		
//##########################################################################################
//##########################################################################################




RIM_INLINE Bool getPlaneVsCapsuleIntersection( const CollisionShapePlane::Instance* plane, 
											const CollisionShapeCapsule::Instance* capsule,
											IntersectionPoint& point )
{
	// Compute the closest point on the capsule to the plane.
	Vector3 closestPoint = getCapsuleSupportPoint( -plane->getNormal(), capsule );
	
	// Compute the distance to the closest capsule point.
	Real distance = plane->getPlane().getSignedDistanceTo( closestPoint );
	
	if ( distance < Real(0) )
	{
		point.point1 = plane->getPlane().getProjectionNormalized( closestPoint );
		point.point2 = closestPoint;
		point.normal = plane->getNormal();
		point.penetrationDistance = -distance;
		
		return true;
	}
	
	return false;
}




RIM_INLINE Bool getCapsuleVsPlaneIntersection( const CollisionShapeCapsule::Instance* capsule, 
											const CollisionShapePlane::Instance* plane,
											IntersectionPoint& point )
{
	Bool result = getPlaneVsCapsuleIntersection( plane, capsule, point );
	
	if ( result )
		point.reverse();
	
	return result;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Plane vs Cylinder Intersection Detection Functions
//############		
//##########################################################################################
//##########################################################################################




RIM_INLINE Bool getPlaneVsCylinderIntersection( const CollisionShapePlane::Instance* plane, 
											const CollisionShapeCylinder::Instance* cylinder,
											IntersectionPoint& point )
{
	// Compute the closest point on the cylinder to the plane.
	Vector3 closestPoint = getCylinderSupportPoint( -plane->getNormal(), cylinder );
	
	// Compute the distance to the closest cylinder point.
	Real distance = plane->getPlane().getSignedDistanceTo( closestPoint );
	
	if ( distance < Real(0) )
	{
		point.point1 = plane->getPlane().getProjectionNormalized( closestPoint );
		point.point2 = closestPoint;
		point.normal = plane->getNormal();
		point.penetrationDistance = -distance;
		
		return true;
	}
	
	return false;
}




RIM_INLINE Bool getCylinderVsPlaneIntersection( const CollisionShapeCylinder::Instance* cylinder, 
											const CollisionShapePlane::Instance* plane,
											IntersectionPoint& point )
{
	Bool result = getPlaneVsCylinderIntersection( plane, cylinder, point );
	
	if ( result )
		point.reverse();
	
	return result;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Plane vs Box Intersection Detection Functions
//############		
//##########################################################################################
//##########################################################################################




RIM_INLINE Bool getPlaneVsBoxIntersection( const CollisionShapePlane::Instance* plane, 
											const CollisionShapeBox::Instance* box,
											IntersectionPoint& point )
{
	// Compute the closest point on the box to the plane.
	Vector3 closestPoint = getBoxSupportPoint( -plane->getNormal(), box );
	
	// Compute the distance to the closest box point.
	Real distance = plane->getPlane().getSignedDistanceTo( closestPoint );
	
	if ( distance < Real(0) )
	{
		point.point1 = plane->getPlane().getProjectionNormalized( closestPoint );
		point.point2 = closestPoint;
		point.normal = plane->getNormal();
		point.penetrationDistance = -distance;
		
		return true;
	}
	
	return false;
}




RIM_INLINE Bool getBoxVsPlaneIntersection( const CollisionShapeBox::Instance* box, 
											const CollisionShapePlane::Instance* plane,
											IntersectionPoint& point )
{
	Bool result = getPlaneVsBoxIntersection( plane, box, point );
	
	if ( result )
		point.reverse();
	
	return result;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Plane vs Convex Intersection Detection Functions
//############		
//##########################################################################################
//##########################################################################################




RIM_INLINE Bool getPlaneVsConvexIntersection( const CollisionShapePlane::Instance* plane, 
											const CollisionShapeConvex::Instance* convex,
											IntersectionPoint& point )
{
	// Compute the closest point on the convex shape to the plane.
	Vector3 closestPoint = getConvexSupportPoint( -plane->getNormal(), convex );
	
	// Compute the distance to the closest convex shape point.
	Real distance = plane->getPlane().getSignedDistanceTo( closestPoint );
	
	if ( distance < Real(0) )
	{
		point.point1 = plane->getPlane().getProjectionNormalized( closestPoint );
		point.point2 = closestPoint;
		point.normal = plane->getNormal();
		point.penetrationDistance = -distance;
		
		return true;
	}
	
	return false;
}




RIM_INLINE Bool getConvexVsPlaneIntersection( const CollisionShapeConvex::Instance* convex, 
											const CollisionShapePlane::Instance* plane,
											IntersectionPoint& point )
{
	Bool result = getPlaneVsConvexIntersection( plane, convex, point );
	
	if ( result )
		point.reverse();
	
	return result;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Sphere vs Box Intersection Detection Functions
//############		
//##########################################################################################
//##########################################################################################




RIM_INLINE Bool getSphereVsBoxIntersection( const CollisionShapeSphere::Instance* sphere, 
											const CollisionShapeBox::Instance* box,
											IntersectionPoint& point )
{
	return util::sphereIntersectsBox( sphere->getPosition(), sphere->getRadius(),
									box->getPosition(), box->getOrientation(), box->getSize(),
									point );
}




RIM_INLINE Bool getBoxVsSphereIntersection( const CollisionShapeBox::Instance* box, 
											const CollisionShapeSphere::Instance* sphere,
											IntersectionPoint& point )
{
	Bool result = util::sphereIntersectsBox( sphere->getPosition(), sphere->getRadius(),
											box->getPosition(), box->getOrientation(), box->getSize(),
											point );
	
	if ( result )
		point.reverse();
	
	return result;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Sphere vs Cylinder Intersection Detection Functions
//############		
//##########################################################################################
//##########################################################################################




RIM_INLINE Bool getSphereVsCylinderIntersection( const CollisionShapeSphere::Instance* sphere, 
											const CollisionShapeCylinder::Instance* cylinder,
											IntersectionPoint& point )
{
	return util::sphereIntersectsCylinder( sphere->getPosition(), sphere->getRadius(),
											cylinder->getEndpoint1(), cylinder->getAxis(),
											cylinder->getHeight(), cylinder->getRadius1(), cylinder->getRadius2(),
											point );
}




RIM_INLINE Bool getCylinderVsSphereIntersection( const CollisionShapeCylinder::Instance* cylinder, 
											const CollisionShapeSphere::Instance* sphere,
											IntersectionPoint& point )
{
	Bool result = util::sphereIntersectsCylinder( sphere->getPosition(), sphere->getRadius(),
												cylinder->getEndpoint1(), cylinder->getAxis(),
												cylinder->getHeight(), cylinder->getRadius1(), cylinder->getRadius2(),
												point );
	
	if ( result )
		point.reverse();
	
	return result;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Plane Vs. Shape Algorithm Declarations
//############		
//##########################################################################################
//##########################################################################################




/// A class which detects collisions between two Rigid Objects with plane and sphere shapes.
typedef CollisionAlgorithmFunction<CollisionShapePlane,CollisionShapeSphere,
									CollisionShapePlane::Instance,CollisionShapeSphere::Instance,
									getPlaneVsSphereIntersection> CollisionAlgorithmPlaneVsSphere;




/// A class which detects collisions between two Rigid Objects with plane and capsule shapes.
typedef CollisionAlgorithmFunction<CollisionShapePlane,CollisionShapeCapsule,
									CollisionShapePlane::Instance,CollisionShapeCapsule::Instance,
									getPlaneVsCapsuleIntersection> CollisionAlgorithmPlaneVsCapsule;




/// A class which detects collisions between two Rigid Objects with plane and cylinder shapes.
typedef CollisionAlgorithmFunction<CollisionShapePlane,CollisionShapeCylinder,
									CollisionShapePlane::Instance,CollisionShapeCylinder::Instance,
									getPlaneVsCylinderIntersection> CollisionAlgorithmPlaneVsCylinder;




/// A class which detects collisions between two Rigid Objects with plane and box shapes.
typedef CollisionAlgorithmFunction<CollisionShapePlane,CollisionShapeBox,
									CollisionShapePlane::Instance,CollisionShapeBox::Instance,
									getPlaneVsBoxIntersection> CollisionAlgorithmPlaneVsBox;




/// A class which detects collisions between two Rigid Objects with plane and convex shapes.
typedef CollisionAlgorithmFunction<CollisionShapePlane,CollisionShapeConvex,
									CollisionShapePlane::Instance,CollisionShapeConvex::Instance,
									getPlaneVsConvexIntersection> CollisionAlgorithmPlaneVsConvex;



//##########################################################################################
//##########################################################################################
//############		
//############		Sphere Vs. Shape Algorithm Declarations
//############		
//##########################################################################################
//##########################################################################################




/// A class which detects collisions between two Rigid Objects with sphere and plane shapes.
typedef CollisionAlgorithmFunction<CollisionShapeSphere,CollisionShapePlane,
									CollisionShapeSphere::Instance,CollisionShapePlane::Instance,
									getSphereVsPlaneIntersection> CollisionAlgorithmSphereVsPlane;




/// A class which detects collisions between two Rigid Objects with sphere and cylinder shapes.
typedef CollisionAlgorithmFunction<CollisionShapeSphere,CollisionShapeCylinder,
									CollisionShapeSphere::Instance,CollisionShapeCylinder::Instance,
									getSphereVsCylinderIntersection> CollisionAlgorithmSphereVsCylinder;




/// A class which detects collisions between two Rigid Objects with sphere and box shapes.
typedef CollisionAlgorithmFunction<CollisionShapeSphere,CollisionShapeBox,
									CollisionShapeSphere::Instance,CollisionShapeBox::Instance,
									getSphereVsBoxIntersection> CollisionAlgorithmSphereVsBox;




//##########################################################################################
//##########################################################################################
//############		
//############		Capsule Vs. Shape Algorithm Declarations
//############		
//##########################################################################################
//##########################################################################################




/// A class which detects collisions between two Rigid Objects with plane and capsule shapes.
typedef CollisionAlgorithmFunction<CollisionShapeCapsule,CollisionShapePlane,
									CollisionShapeCapsule::Instance,CollisionShapePlane::Instance,
									getCapsuleVsPlaneIntersection> CollisionAlgorithmCapsuleVsPlane;



//##########################################################################################
//##########################################################################################
//############		
//############		Cylinder Vs. Shape Algorithm Declarations
//############		
//##########################################################################################
//##########################################################################################




/// A class which detects collisions between two Rigid Objects with cylinder and plane shapes.
typedef CollisionAlgorithmFunction<CollisionShapeCylinder,CollisionShapePlane,
									CollisionShapeCylinder::Instance,CollisionShapePlane::Instance,
									getCylinderVsPlaneIntersection> CollisionAlgorithmCylinderVsPlane;




/// A class which detects collisions between two Rigid Objects with sphere and cylinder shapes.
typedef CollisionAlgorithmFunction<CollisionShapeCylinder,CollisionShapeSphere,
									CollisionShapeCylinder::Instance,CollisionShapeSphere::Instance,
									getCylinderVsSphereIntersection> CollisionAlgorithmCylinderVsSphere;




//##########################################################################################
//##########################################################################################
//############		
//############		Box Vs. Shape Algorithm Declarations
//############		
//##########################################################################################
//##########################################################################################




/// A class which detects collisions between two Rigid Objects with box and sphere shapes.
typedef CollisionAlgorithmFunction<CollisionShapeBox,CollisionShapeSphere,
									CollisionShapeBox::Instance,CollisionShapeSphere::Instance,
									getBoxVsSphereIntersection> CollisionAlgorithmBoxVsSphere;




/// A class which detects collisions between two Rigid Objects with box and plane shapes.
typedef CollisionAlgorithmFunction<CollisionShapeBox,CollisionShapePlane,
									CollisionShapeBox::Instance,CollisionShapePlane::Instance,
									getBoxVsPlaneIntersection> CollisionAlgorithmBoxVsPlane;




//##########################################################################################
//##########################################################################################
//############		
//############		Convex Vs. Shape Algorithm Declarations
//############		
//##########################################################################################
//##########################################################################################




/// A class which detects collisions between two Rigid Objects with plane and convex shapes.
typedef CollisionAlgorithmFunction<CollisionShapeConvex,CollisionShapePlane,
									CollisionShapeConvex::Instance,CollisionShapePlane::Instance,
									getConvexVsPlaneIntersection> CollisionAlgorithmConvexVsPlane;
									



//##########################################################################################
//**********************  End Rim Physics Collision Namespace  *****************************
RIM_PHYSICS_COLLISION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_FUNCTIONS_H
