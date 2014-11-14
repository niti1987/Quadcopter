/*
 *  rimPhysicsCollisionConstraintRigidVsRigid.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_CONSTRAINT_RIGID_VS_RIGID_H
#define INCLUDE_RIM_PHYSICS_COLLISION_CONSTRAINT_RIGID_VS_RIGID_H


#include "rimPhysicsConstraintsConfig.h"


#include "rimPhysicsConstraint.h"
#include "rimPhysicsCollisionConstraint.h"


//##########################################################################################
//*********************  Start Rim Physics Constraints Namespace  **************************
RIM_PHYSICS_CONSTRAINTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which solves collision constraints between arbitrary template object types.
template <>
class CollisionConstraint<RigidObject,RigidObject> : public Constraint
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Constraint Instance Declaration
			
			
			
			
			/// A class which represents an instance of a collision constraint.
			class Instance;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constraint Instance Accessor Methods
			
			
			
			
			/// Return a pointer to the constraint instance between the specified rigid objects.
			/**
			  * If there is no constraint instance between those objects, NULL is returned.
			  */
			RIM_INLINE const Instance* getInstance( const RigidObject* object1, const RigidObject* object2 ) const
			{
				ObjectPair<RigidObject,RigidObject> pair( object1, object2 );
				const Instance* instance;
				
				if ( instances.find( pair.getHashCode(), pair, instance ) )
					return instance;
				else
					return NULL;
			}
			
			
			
			
			/// Return the total number of object-object collision constraint instances in this constraint.
			RIM_INLINE Size getInstanceCount() const
			{
				return instances.getSize();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constraint Solving Methods
			
			
			
			
			/// Solve all instances of this constraint for the specified time step and number of solver iterations.
			/**
			  * In this method, the collision result set for this constraint is examined
			  * and collision constraint instances are created for each pair of colliding
			  * objects in the collision manifold.
			  */
			virtual void solve( Real dt, Size numIterations );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Collision Result Set Accessor Methods
			
			
			
			
			/// Return a const reference to the collision result set for this collision constraint.
			RIM_INLINE const CollisionResultSet<RigidObject,RigidObject>& getCollisionResultSet() const
			{
				return collisionResultSet;
			}
			
			
			
			
			/// Return a reference to the collision result set for this collision constraint.
			RIM_INLINE CollisionResultSet<RigidObject,RigidObject>& getCollisionResultSet()
			{
				return collisionResultSet;
			}
			
			
			
			
			/// Set the collision result set for this collision constraint.
			RIM_INLINE void setCollisionResultSet( const CollisionResultSet<RigidObject,RigidObject>& newResultSet )
			{
				collisionResultSet = newResultSet;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Solver Point Class Declaration
			
			
			
			
			/// A class which represents a single collision point constraint solver state.
			class SolverPoint;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A set of collision results that this constraint uses to create constraint instances.
			CollisionResultSet<RigidObject,RigidObject> collisionResultSet;
			
			
			
			
			/// A map from object pairs to collision constraint instances.
			HashMap<ObjectPair<RigidObject,RigidObject>,Instance> instances;
			
			
			
			
			/// The current frame index for this constraint.
			/**
			  * This value is used to keep track of which constraint instances have
			  * not been updated recently and need to be removed from this constraint.
			  */
			Index timestamp;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Collision Constraint Solver Point Class Definition
//############		
//##########################################################################################
//##########################################################################################




class CollisionConstraint<RigidObject,RigidObject>:: SolverPoint
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new collision constraint solver point for the specified objects and collision point.
			RIM_INLINE SolverPoint( const RigidObject& object1, const RigidObject& object2,
									const CollisionPoint& point, Index newTimestamp = 0 )
				:	frame( Matrix3::planeBasis( point.getNormal() ) ),
					r1( point.getWorldSpacePoint1() - object1.getCenterOfMass() ),
					r2( point.getWorldSpacePoint2() - object2.getCenterOfMass() ),
					separationDistance( point.getSeparationDistance() ),
					material( point.getMaterial() ),
					biasAmount( 0 ),
					accumulatedBiasImpulse( 0 ),
					timestamp( newTimestamp )
			{
				objectSpaceR1 = object1.getTransform().transformToObjectSpace( r1 );
				objectSpaceR2 = object2.getTransform().transformToObjectSpace( r2 );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Collision Configuration Update Method
			
			
			
			
			/// Update the specified collision configuration data members.
			RIM_INLINE void update( const Vector3& newNormal, const Vector3& newR1, const Vector3& newR2, 
									const Vector3& newObjectSpaceR1, const Vector3& newObjectSpaceR2,
									Real newSeparationDistance, const CollisionShapeMaterial& newMaterial,
									Index newTimestamp )
			{
				frame = Matrix3::planeBasis( newNormal );
				r1 = newR1;
				r2 = newR2;
				objectSpaceR1 = newObjectSpaceR1;
				objectSpaceR2 = newObjectSpaceR2;
				separationDistance = newSeparationDistance;
				material = newMaterial;
				timestamp = newTimestamp;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Collision Configuration Data Members
			
			
			
			
			/// A 3x3 matrix representing the coordinate frame axes of this solver point.
			/**
			  * The collision normal is the Z-vector of this matrix, the other vectors
			  * are tangent vectors to the normal.
			  */
			Matrix3 frame;
			
			
			
			
			/// The vector from the first object's center of mass to the collision point in world space.
			Vector3 r1;
			
			
			
			
			/// The vector from the second object's center of mass to the collision point in world space.
			Vector3 r2;
			
			
			
			
			/// The vector from the first object's center of mass to the collision point in object space.
			Vector3 objectSpaceR1;
			
			
			
			
			/// The vector from the second object's center of mass to the collision point in object space.
			Vector3 objectSpaceR2;
			
			
			
			
			/// The current negative penetration distance of the two objects.
			Real separationDistance;
			
			
			
			
			/// The combined material of the two objects at this collision solver point.
			CollisionShapeMaterial material;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Constraint Solving Data Members
			
			
			
			
			/// The inertial mass for each of the point's coordinate frame directions.
			/**
			  * This mass is stored in (tangent1, tangent2, normal) diretion format.
			  */
			Vector3 massVector;
			
			
			
			
			/// The accumulated impulse for this constraint, stored in (tangent1, tangent2, normal) format.
			Vector3 accumulatedImpulse;
			
			
			
			
			/// The desired bias amount (in units of velocity).
			Real biasAmount;
			
			
			
			
			/// The accumulate bias impulse along the collision normal direction.
			Real accumulatedBiasImpulse;
			
			
			
			
			/// The velocity at which the objects should separate (if they collide elastically).
			Real bounceVelocity;
			
			
			
			
			/// An integral timestamp for this solver point indicating when it was last updated.
			Index timestamp;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Collision Constraint Instance Class Definition
//############		
//##########################################################################################
//##########################################################################################




class CollisionConstraint<RigidObject,RigidObject>:: Instance
{
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Accessor Methods
			
			
			
			
			/// Return a pointer to the first object that is a part of this collision constraint instance.
			RIM_INLINE RigidObject* getObject1() const
			{
				return object1;
			}
			
			
			
			
			/// Return a pointer to the second object that is a part of this collision constraint instance.
			RIM_INLINE RigidObject* getObject2() const
			{
				return object2;
			}
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructors
			
			
			
			
			/// Create a new collision constraint instance bewteen the specified rigid objects.
			/**
			  * This constructor adds a constraint solver point for each collision point
			  * in the specified manifold between these objects.
			  */
			RIM_INLINE Instance( RigidObject* newObject1, RigidObject* newObject2,
								const CollisionManifold& manifold, Index newTimestamp )
				:	object1( newObject1 ),
					object2( newObject2 )
			{
				updateSolverPoints( manifold, newTimestamp );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constraint Instance Update Method
			
			
			
			
			/// Update this constraint instance with the collision points from the specified manifold.
			/**
			  * When updating solver points, this method attempts to match old solver points
			  * with new collision points if these points are within the specified update
			  * threshold distance from each other.
			  */
			void updateSolverPoints( const CollisionManifold& newManifold, Index newTimestamp,
									Real updateThreshold = Real(0.01) )
			{
				timestamp = newTimestamp;
				Real updateThresholdSquared = updateThreshold*updateThreshold;
				
				//*************************************************************************
				// Look through the set of manifold collision points and see if any
				// of them match old solver points. If not, add them to the list of points.
				
				Size numManifoldPoints = newManifold.getPointCount();
				Size oldNumSolverPoints = solverPoints.getSize();
				
				for ( Index i = 0; i < numManifoldPoints; i++ )
				{
					const CollisionPoint& point = newManifold.getPoint(i);
					Index j = 0;
					
					for ( ; j < oldNumSolverPoints; j++ )
					{
						SolverPoint& solverPoint = solverPoints[j];
						
						// If this point has already been updated, skip it.
						if ( solverPoint.timestamp == timestamp )
							continue;
						
						// Test to see if the new point is close to the old point in object space.
						Vector3 r1 = point.getObjectSpacePoint1() - object1->getCenterOfMass();
						Vector3 r2 = point.getObjectSpacePoint2() - object2->getCenterOfMass();
						Vector3 objectSpaceR1 = object1->getTransform().transformToObjectSpace( r1 );
						Vector3 objectSpaceR2 = object2->getTransform().transformToObjectSpace( r2 );
						
						if ( objectSpaceR1.getDistanceToSquared( solverPoint.objectSpaceR1 ) < updateThresholdSquared &&
							objectSpaceR2.getDistanceToSquared( solverPoint.objectSpaceR2 ) < updateThresholdSquared )
						{
							// This is a matching solver point, update it.
							solverPoint.update( point.getNormal(), r1, r2, objectSpaceR1, objectSpaceR2,
												point.getSeparationDistance(), point.getMaterial(), timestamp );
							break;
						}
					}
					
					// If we didn't find a matching point, add a new solver point.
					if ( j == oldNumSolverPoints )
						solverPoints.add( SolverPoint( *object1, *object2, point, timestamp ) );
				}
				
				// Find all of the old solver points in this constraint instance and remove them.
				for ( Index i = 0; i < oldNumSolverPoints; i++ )
				{
					if ( solverPoints[i].timestamp < timestamp )
						solverPoints.removeAtIndexUnordered( i );
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The first object that is being affected by this collision constraint instance.
			RigidObject* object1;
			
			
			
			
			/// The second object that is being affected by this collision constraint instance.
			RigidObject* object2;
			
			
			
			
			/// An array of the solver points associated with this constraint instance.
			ArrayList<SolverPoint> solverPoints;
			
			
			
			
			/// The last integral frame timestamp when this constraint instance was updated.
			/**
			  * This value is used to keep track of whether or not a collision constraint
			  * is still valid. If there are no collision points between an object pair,
			  * the constraint is not updated and it should be removed from simulation.
			  */
			Index timestamp;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Class Declaration
			
			
			
			
			/// Declare the collision constraint class as a friend.
			friend class CollisionConstraint<RigidObject,RigidObject>;
			
			
			
};




//##########################################################################################
//*********************  End Rim Physics Constraints Namespace  ****************************
RIM_PHYSICS_CONSTRAINTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_CONSTRAINT_RIGID_VS_RIGID_H
