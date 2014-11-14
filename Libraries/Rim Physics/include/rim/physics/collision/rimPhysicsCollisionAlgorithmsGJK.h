/*
 *  rimPhysicsCollisionAlgorithmsGJK.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 7/1/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHMS_GJK_H
#define INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHMS_GJK_H


#include "rimPhysicsCollisionConfig.h"


#include "rimPhysicsCollisionAlgorithmGJK.h"


//##########################################################################################
//**********************  Start Rim Physics Collision Namespace  ***************************
RIM_PHYSICS_COLLISION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




/// Return the point on the specified sphere that is farthest in the given normalized direction.
RIM_INLINE Vector3 getSphereSupportPoint( const Vector3& direction, const CollisionShapeSphere::Instance* sphere )
{
	return sphere->getPosition() + direction*sphere->getRadius();
}




/// Return the point on the specified cylinder that is farthest in the given normalized direction.
RIM_INLINE Vector3 getCylinderSupportPoint( const Vector3& direction, const CollisionShapeCylinder::Instance* cylinder )
{
	// Assume the direction is normalized.
	const Vector3& axis = cylinder->getAxis();
	
	Real aDotS = math::dot( axis, direction );
	
	// Make sure that the support direction isn't parallel to the axis.
	if ( Real(1.0) - math::abs(aDotS) < math::epsilon<Real>() )
	{
		// If so, return one of the endpoints.
		if ( aDotS > Real(0) )
			return cylinder->getEndpoint2();
		else
			return cylinder->getEndpoint1();
	}
	
	Vector3 point1 = cylinder->getEndpoint1() + cylinder->getRadius1()*(direction - axis*aDotS).normalize();
	Vector3 point2 = cylinder->getEndpoint2() + cylinder->getRadius2()*(direction - axis*aDotS).normalize();
	
	Vector3 edge = point2 - point1;
	
	Real edgeDotS = math::dot( edge, direction );
	
	if ( edgeDotS > Real(0) )
		return point2;
	else
		return point1;
}




/// Return the point on the specified capsule that is farthest in the given normalized direction.
RIM_INLINE Vector3 getCapsuleSupportPoint( const Vector3& direction, const CollisionShapeCapsule::Instance* capsule )
{
	// Assume the direction is normalized.
	const Vector3& axis = capsule->getAxis();
	Real height = capsule->getHeight();
	Real radius1 = capsule->getRadius1();
	Real radius2 = capsule->getRadius2();
	
	Real aDotS = math::dot( axis, direction );
	Real threshold = radius1 != radius2 ? (radius1 / (height + radius2*height/(radius1 - radius2))) : Real(0);
	
	if ( aDotS > threshold )
		return capsule->getEndpoint2() + direction*radius2;
	else
		return capsule->getEndpoint1() + direction*radius1;
}




/// Return the point on the box that is farthest in the given normalized direction.
RIM_INLINE Vector3 getBoxSupportPoint( const Vector3& direction, const CollisionShapeBox::Instance* box )
{
	const Matrix3& o = box->getOrientation();
	const Vector3 halfSize = box->getSize()*Real(0.5);
	
	Vector3 supportPoint = box->getPosition();
	
	if ( math::dot( o.x, direction ) >= Real(0) )
		supportPoint += o.x*halfSize.x;
	else
		supportPoint -= o.x*halfSize.x;
	
	if ( math::dot( o.y, direction ) >= Real(0) )
		supportPoint += o.y*halfSize.y;
	else
		supportPoint -= o.y*halfSize.y;
	
	if ( math::dot( o.z, direction ) >= Real(0) )
		supportPoint += o.z*halfSize.z;
	else
		supportPoint -= o.z*halfSize.z;
	
	return supportPoint;
}




/// Return the point on the convex shape that is farthest in the given normalized direction.
RIM_INLINE Vector3 getConvexSupportPoint( const Vector3& direction, const CollisionShapeConvex::Instance* convex )
{
	return convex->getSupportVertex( direction );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Sphere Vs. Shape Algorithm Declarations
//############		
//##########################################################################################
//##########################################################################################




/// A class which detects collisions between two Rigid Objects with sphere and capsule shapes.
typedef CollisionAlgorithmGJK<CollisionShapeSphere,CollisionShapeCapsule,
							CollisionShapeSphere::Instance,CollisionShapeCapsule::Instance,
							getSphereSupportPoint,getCapsuleSupportPoint> CollisionAlgorithmSphereVsCapsule;




/// A class which detects collisions between two Rigid Objects with sphere and convex shapes.
typedef CollisionAlgorithmGJK<CollisionShapeSphere,CollisionShapeConvex,
							CollisionShapeSphere::Instance,CollisionShapeConvex::Instance,
							getSphereSupportPoint,getConvexSupportPoint> CollisionAlgorithmSphereVsConvex;




//##########################################################################################
//##########################################################################################
//############		
//############		Capsule Vs. Shape Algorithm Declarations
//############		
//##########################################################################################
//##########################################################################################




/// A class which detects collisions between two Rigid Objects with capsule and sphere shapes.
typedef CollisionAlgorithmGJK<CollisionShapeCapsule,CollisionShapeSphere,
							CollisionShapeCapsule::Instance,CollisionShapeSphere::Instance,
							getCapsuleSupportPoint,getSphereSupportPoint> CollisionAlgorithmCapsuleVsSphere;




/// A class which detects collisions between two Rigid Objects with capsule shapes.
typedef CollisionAlgorithmGJK<CollisionShapeCapsule,CollisionShapeCapsule,
							CollisionShapeCapsule::Instance,CollisionShapeCapsule::Instance,
							getCapsuleSupportPoint,getCapsuleSupportPoint> CollisionAlgorithmCapsuleVsCapsule;




/// A class which detects collisions between two Rigid Objects with capsule and cylinder shapes.
typedef CollisionAlgorithmGJK<CollisionShapeCapsule,CollisionShapeCylinder,
							CollisionShapeCapsule::Instance,CollisionShapeCylinder::Instance,
							getCapsuleSupportPoint,getCylinderSupportPoint> CollisionAlgorithmCapsuleVsCylinder;




/// A class which detects collisions between two Rigid Objects with capsule and box shapes.
typedef CollisionAlgorithmGJK<CollisionShapeCapsule,CollisionShapeBox,
							CollisionShapeCapsule::Instance,CollisionShapeBox::Instance,
							getCapsuleSupportPoint,getBoxSupportPoint> CollisionAlgorithmCapsuleVsBox;




/// A class which detects collisions between two Rigid Objects with capsule and convex shapes.
typedef CollisionAlgorithmGJK<CollisionShapeCapsule,CollisionShapeConvex,
							CollisionShapeCapsule::Instance,CollisionShapeConvex::Instance,
							getCapsuleSupportPoint,getConvexSupportPoint> CollisionAlgorithmCapsuleVsConvex;




//##########################################################################################
//##########################################################################################
//############		
//############		Cylinder Vs. Shape Algorithm Declarations
//############		
//##########################################################################################
//##########################################################################################




/// A class which detects collisions between two Rigid Objects with cylinder and capsule shapes.
typedef CollisionAlgorithmGJK<CollisionShapeCylinder,CollisionShapeCapsule,
							CollisionShapeCylinder::Instance,CollisionShapeCapsule::Instance,
							getCylinderSupportPoint,getCapsuleSupportPoint> CollisionAlgorithmCylinderVsCapsule;




/// A class which detects collisions between two Rigid Objects with cylinder shapes.
typedef CollisionAlgorithmGJK<CollisionShapeCylinder,CollisionShapeCylinder,
							CollisionShapeCylinder::Instance,CollisionShapeCylinder::Instance,
							getCylinderSupportPoint,getCylinderSupportPoint> CollisionAlgorithmCylinderVsCylinder;




/// A class which detects collisions between two Rigid Objects with cylinder and box shapes.
typedef CollisionAlgorithmGJK<CollisionShapeCylinder,CollisionShapeBox,
							CollisionShapeCylinder::Instance,CollisionShapeBox::Instance,
							getCylinderSupportPoint,getBoxSupportPoint> CollisionAlgorithmCylinderVsBox;




/// A class which detects collisions between two Rigid Objects with cylinder and convex shapes.
typedef CollisionAlgorithmGJK<CollisionShapeCylinder,CollisionShapeConvex,
							CollisionShapeCylinder::Instance,CollisionShapeConvex::Instance,
							getCylinderSupportPoint,getConvexSupportPoint> CollisionAlgorithmCylinderVsConvex;




//##########################################################################################
//##########################################################################################
//############		
//############		Box Vs. Shape Algorithm Declarations
//############		
//##########################################################################################
//##########################################################################################




/// A class which detects collisions between two Rigid Objects with box and capsule shapes.
typedef CollisionAlgorithmGJK<CollisionShapeBox,CollisionShapeCapsule,
							CollisionShapeBox::Instance,CollisionShapeCapsule::Instance,
							getBoxSupportPoint,getCapsuleSupportPoint> CollisionAlgorithmBoxVsCapsule;




/// A class which detects collisions between two Rigid Objects with box and cylinder shapes.
typedef CollisionAlgorithmGJK<CollisionShapeBox,CollisionShapeCylinder,
							CollisionShapeBox::Instance,CollisionShapeCylinder::Instance,
							getBoxSupportPoint,getCylinderSupportPoint> CollisionAlgorithmBoxVsCylinder;




/// A class which detects collisions between two Rigid Objects with box shapes.
typedef CollisionAlgorithmGJK<CollisionShapeBox,CollisionShapeBox,
							CollisionShapeBox::Instance,CollisionShapeBox::Instance,
							getBoxSupportPoint,getBoxSupportPoint> CollisionAlgorithmBoxVsBox;




/// A class which detects collisions between two Rigid Objects with box and convex shapes.
typedef CollisionAlgorithmGJK<CollisionShapeBox,CollisionShapeConvex,
							CollisionShapeBox::Instance,CollisionShapeConvex::Instance,
							getBoxSupportPoint,getConvexSupportPoint> CollisionAlgorithmBoxVsConvex;




/// A class which detects collisions between two Rigid Objects with convex and sphere shapes.
typedef CollisionAlgorithmGJK<CollisionShapeConvex,CollisionShapeSphere,
							CollisionShapeConvex::Instance,CollisionShapeSphere::Instance,
							getConvexSupportPoint,getSphereSupportPoint> CollisionAlgorithmConvexVsSphere;




/// A class which detects collisions between two Rigid Objects with convex and capsule shapes.
typedef CollisionAlgorithmGJK<CollisionShapeConvex,CollisionShapeCapsule,
							CollisionShapeConvex::Instance,CollisionShapeCapsule::Instance,
							getConvexSupportPoint,getCapsuleSupportPoint> CollisionAlgorithmConvexVsCapsule;




/// A class which detects collisions between two Rigid Objects with convex and cylinder shapes.
typedef CollisionAlgorithmGJK<CollisionShapeConvex,CollisionShapeCylinder,
							CollisionShapeConvex::Instance,CollisionShapeCylinder::Instance,
							getConvexSupportPoint,getCylinderSupportPoint> CollisionAlgorithmConvexVsCylinder;




/// A class which detects collisions between two Rigid Objects with convex and box shapes.
typedef CollisionAlgorithmGJK<CollisionShapeConvex,CollisionShapeBox,
							CollisionShapeConvex::Instance,CollisionShapeBox::Instance,
							getConvexSupportPoint,getBoxSupportPoint> CollisionAlgorithmConvexVsBox;




/// A class which detects collisions between two Rigid Objects with convex shapes.
typedef CollisionAlgorithmGJK<CollisionShapeConvex,CollisionShapeConvex,
							CollisionShapeConvex::Instance,CollisionShapeConvex::Instance,
							getConvexSupportPoint,getConvexSupportPoint> CollisionAlgorithmConvexVsConvex;




//##########################################################################################
//**********************  End Rim Physics Collision Namespace  *****************************
RIM_PHYSICS_COLLISION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHMS_GJK_H
