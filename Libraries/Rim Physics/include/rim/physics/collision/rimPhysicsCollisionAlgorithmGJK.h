/*
 *  rimPhysicsCollisionAlgorithmGJK.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 7/1/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_GJK_H
#define INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_GJK_H


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
/// A class which detects collisions between two Rigid Objects with cylinder shapes.
template < typename ShapeType1, typename ShapeType2, typename ShapeInstanceType1, typename ShapeInstanceType2,
			Vector3 (*getSupportPoint1)( const Vector3&, const ShapeInstanceType1* ),
			Vector3 (*getSupportPoint2)( const Vector3&, const ShapeInstanceType2* ) >
class CollisionAlgorithmGJK : public CollisionAlgorithmBase<RigidObject,RigidObject,ShapeType1,ShapeType2>
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
				
				if ( gjkSolver.solve<ShapeInstanceType1,ShapeInstanceType2,
					ThisType::getSupportPoint>( simplex, shape1, shape2 ) )
				{
					// Use the EPA solver to determine the closest triangle on the shapes' minkowski difference.
					EPAResult epaResult = epaSolver.solve<ShapeInstanceType1,ShapeInstanceType2,
														ThisType::getSupportPoint>( simplex, Real(0.0001), shape1, shape2 );
					
					// Compute the point of intersection from the EPA result.
					IntersectionPoint point = epaResult.getIntersectionPoint();
					
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
		//******	Private Type Declaration
			
			
			
			
			/// Define this class's type so that we can easily use it in expressions.
			typedef CollisionAlgorithmGJK<ShapeType1,ShapeType2,ShapeInstanceType1,ShapeInstanceType2,
											getSupportPoint1,getSupportPoint2> ThisType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Return a minkowski vertex for the support point on each of the two specified shapes in the given direction.
			RIM_INLINE static MinkowskiVertex3 getSupportPoint( const Vector3& direction,
																const ShapeInstanceType1* shape1,
																const ShapeInstanceType2* shape2 )
			{
				Vector3 normalizedDirection = direction.normalize();
				
				return MinkowskiVertex3( getSupportPoint1( normalizedDirection, shape1 ),
										 getSupportPoint2( -normalizedDirection, shape2 ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A temporary array of minkowski vertices used to hold the GJK simplex result.
			StaticArray<MinkowskiVertex3,4> simplex;
			
			
			
			
			/// An object which uses the GJK algorithm to determine if the shapes intersect.
			GJKSolver gjkSolver;
			
			
			
			
			/// An object which uses the EPA algorithm to refine a GJK result simplex.
			EPASolver epaSolver;
			
			
			
};




//##########################################################################################
//**********************  End Rim Physics Collision Namespace  *****************************
RIM_PHYSICS_COLLISION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_GJK_H
