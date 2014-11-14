/*
 *  rimPhysicsCollisionAlgorithmFunction.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 7/6/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_FUNCTION_H
#define INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_FUNCTION_H


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
/// A class which detects collisions between two Rigid Objects using a function-based test.
template < typename ShapeType1, typename ShapeType2, typename ShapeInstanceType1, typename ShapeInstanceType2,
			Bool (*getIntersectionPoint)( const ShapeInstanceType1*, const ShapeInstanceType2*, IntersectionPoint& points ) >
class CollisionAlgorithmFunction : public CollisionAlgorithmBase<RigidObject,RigidObject,ShapeType1,ShapeType2>
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
				const ShapeInstanceType1* shape1 = (const ShapeInstanceType1*)collider1.getShape();
				const RigidObject* object2 = collider2.getObject();
				const ShapeInstanceType2* shape2 = (const ShapeInstanceType2*)collider2.getShape();
				
				if ( getIntersectionPoint( shape1, shape2, point ) )
				{
					// Get the collision manifold for these objects.
					CollisionManifold& manifold = resultSet.addManifold( object1, object2 );
					
					manifold.addPoint( CollisionPoint(
						object1->getTransform().transformToObjectSpace( point.point1 ),
						object2->getTransform().transformToObjectSpace( point.point2 ),
						point.point1, point.point2,
						point.normal, -point.penetrationDistance,
						CollisionShapeMaterial( shape1->getMaterial(), shape2->getMaterial() ) ) );
					
					return true;
				}
				
				return false;
			}
			
			
			
			
	private:
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A point used to hold temporary contact points between shapes.
			IntersectionPoint point;
			
			
			
};




//##########################################################################################
//**********************  End Rim Physics Collision Namespace  *****************************
RIM_PHYSICS_COLLISION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_FUNCTION_H
