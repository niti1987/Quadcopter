/*
 *  rimPhysicsCollisionAlgorithmSphereVsSphere.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_SPHERE_VS_SPHERE_H
#define INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_SPHERE_VS_SPHERE_H


#include "rimPhysicsCollisionConfig.h"


#include "rimPhysicsCollisionAlgorithmBase.h"


//##########################################################################################
//**********************  Start Rim Physics Collision Namespace  ***************************
RIM_PHYSICS_COLLISION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which detects collisions between two Rigid Objects with spherical shapes.
class CollisionAlgorithmSphereVsSphere : public CollisionAlgorithmBase<RigidObject,RigidObject,CollisionShapeSphere,CollisionShapeSphere>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Collision Detection Method
			
			
			
			
			/// Test the specified object pair for collisions and add the results to the result set.
			/**
			  * If a collision occurred, TRUE is returned and the resulting CollisionPoint(s)
			  * are added to the CollisionManifold for the object pair in the specified
			  * CollisionResultSet. If there was no collision detected, FALSE is returned
			  * and the result set is unmodified.
			  */
			virtual Bool testForCollisions( const ObjectCollider<RigidObject>& collider1,
											const ObjectCollider<RigidObject>& collider2,
											CollisionResultSet<RigidObject,RigidObject>& resultSet )
			{
				const RigidObject* object1 = collider1.getObject();
				const CollisionShapeSphere::Instance* sphere1 = (const CollisionShapeSphere::Instance*)collider1.getShape();
				const RigidObject* object2 = collider2.getObject();
				const CollisionShapeSphere::Instance* sphere2 = (const CollisionShapeSphere::Instance*)collider2.getShape();
				
				Vector3 positionVector = sphere2->getPosition() - sphere1->getPosition();
				Real distanceSquared = positionVector.getMagnitudeSquared();
				Real radii = sphere1->getRadius() + sphere2->getRadius();
				
				if ( distanceSquared >= radii*radii )
					return false;
				
				CollisionManifold& manifold = resultSet.addManifold( object1, object2 );
				
				// Compute the distance between the spheres' centers.
				Real distance = math::sqrt(distanceSquared);
				
				// Compute the negative penetration distance.
				Real penetrationDistance = distance - radii;
				
				// Compute the normal vector from object 1 to object 2.
				Vector3 normal = positionVector / distance;
				
				// Compute the world space collision points for each object.
				Vector3 worldPoint1 = sphere1->getPosition() + normal*(sphere1->getRadius() + penetrationDistance);
				Vector3 worldPoint2 = sphere2->getPosition() - normal*(sphere2->getRadius() + penetrationDistance);
				
				// Create a collision point and add it to these objects' manifold.
				manifold.addPoint( CollisionPoint(
						object1->getTransform().transformToObjectSpace( worldPoint1 ),
						object2->getTransform().transformToObjectSpace( worldPoint2 ),
						worldPoint1, worldPoint2,
						normal,
						penetrationDistance,
						CollisionShapeMaterial( sphere1->getMaterial(), sphere2->getMaterial() ) ) );
				
				return true;
			}
			
			
			
};




//##########################################################################################
//**********************  End Rim Physics Collision Namespace  *****************************
RIM_PHYSICS_COLLISION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_SPHERE_VS_SPHERE_H
