/*
 *  rimPhysicsCollisionDetector.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_DETECTOR_H
#define INCLUDE_RIM_PHYSICS_COLLISION_DETECTOR_H


#include "rimPhysicsCollisionConfig.h"


#include "rimPhysicsCollisionAlgorithmDispatcher.h"
#include "rimPhysicsCollisionResultSet.h"


//##########################################################################################
//**********************  Start Rim Physics Collision Namespace  ***************************
RIM_PHYSICS_COLLISION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which describes the interface for an object that detects colisions between different object types.
class CollisionDetector
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this collision detector object.
			virtual ~CollisionDetector()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Collision Detection Methods
			
			
			
			
			/// Detect rigid-vs-rigid collisions that occurr over a timestep and add them to the result set.
			virtual void testForCollisions( Real dt, CollisionResultSet<RigidObject,RigidObject>& resultSet ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Rigid Object Accessor Methods
			
			
			
			
			/// Add the specified rigid object to this CollisionDetector.
			/**
			  * If the specified rigid object pointer is NULL, the
			  * collision detector is unchanged.
			  */
			virtual void addRigidObject( const RigidObject* rigidObject ) = 0;
			
			
			
			
			/// Remove the specified rigid object from this CollisionDetector.
			/**
			  * If this detector contains the specified rigid object, the
			  * object is removed from the collision detector and TRUE is returned.
			  * Otherwise, if the rigid object is not found, FALSE is returned
			  * and the collision detector is unchanged.
			  */
			virtual Bool removeRigidObject( const RigidObject* rigidObject ) = 0;
			
			
			
			
			/// Remove all rigid objects from this CollisionDetector.
			virtual void removeRigidObjects() = 0;
			
			
			
			
			/// Return whether or not the specified rigid object is contained in this CollisionDetector.
			/**
			  * If this CollisionDetector contains the specified rigid object, TRUE is returned.
			  * Otherwise, if the rigid object is not found, FALSE is returned.
			  */
			virtual Bool containsRigidObject( const RigidObject* rigidObject ) const = 0;
			
			
			
			
			/// Return the number of rigid objects that are contained in this CollisionDetector.
			virtual Size getRigidObjectCount() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Dispatcher Accessor Methods
			
			
			
			
			/// Return a reference to the collision algorithm dispatcher for the specified template object types.
			template < typename ObjectType1, typename ObjectType2 >
			RIM_INLINE CollisionAlgorithmDispatcher<ObjectType1,ObjectType2>& getDispatcher()
			{
			}
			
			
			
			
			/// Return a const reference to the collision algorithm dispatcher for the specified template object types.
			template < typename ObjectType1, typename ObjectType2 >
			RIM_INLINE const CollisionAlgorithmDispatcher<ObjectType1,ObjectType2>& getDispatcher() const
			{
			}
			
			
			
			
			/// Replace the dispatcher in this collision detector for the specified template object types.
			/**
			  * This method completely replaces the dispatcher used in this collision
			  * detector with a copy of the specified dispatcher object.
			  */
			template < typename ObjectType1, typename ObjectType2 >
			RIM_INLINE void setDispatcher( const CollisionAlgorithmDispatcher<ObjectType1,ObjectType2>& newDispatcher )
			{
			}
			
			
			
			
	protected:
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Collider Dispatch Functions
			
			
			
			
			/// Test the specified pair of objects for collisions and add any collisions to the result set.
			/**
			  * This method may be specialized to support different object types and
			  * combinations. It should not do any additional bounding volume intersection tests
			  * other than the test to determine if the objects' shapes intersect.
			  * Typically, one would test the objects' bounding spheres for intersection
			  * before calling this method.
			  */
			template < typename ObjectType1, typename ObjectType2 >
			RIM_INLINE void testPair( const ObjectType1* object1, const ObjectType2* object2,
										CollisionResultSet<ObjectType1,ObjectType2>& resultSet )
			{	
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The collision algorithm dispatcher that dispatches collidind pairs of rigid objects.
			CollisionAlgorithmDispatcher<RigidObject,RigidObject> rigidVsRigidDispatcher;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Algorithm Dispatcher Template Specializations
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_INLINE CollisionAlgorithmDispatcher<RigidObject,RigidObject>& CollisionDetector:: getDispatcher<RigidObject,RigidObject>()
{
	return rigidVsRigidDispatcher;
}




template <>
RIM_INLINE const CollisionAlgorithmDispatcher<RigidObject,RigidObject>& CollisionDetector:: getDispatcher<RigidObject,RigidObject>() const
{
	return rigidVsRigidDispatcher;
}




template <>
RIM_INLINE void CollisionDetector:: setDispatcher( const CollisionAlgorithmDispatcher<RigidObject,RigidObject>& newDispatcher )
{
	rigidVsRigidDispatcher = newDispatcher;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Collision Pair Dispatch Template Specializations
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_INLINE void CollisionDetector:: testPair( const RigidObject* object1, const RigidObject* object2,
									CollisionResultSet<RigidObject,RigidObject>& resultSet )
{
	const Size numShapes1 = object1->getShapeCount();
	const Size numShapes2 = object2->getShapeCount();
	
	for ( Index i = 0; i < numShapes1; i++ )
	{
		ObjectCollider<RigidObject> collider1( object1, object1->getShapeInstance(i) );
		
		for ( Index j = 0; j < numShapes2; j++ )
		{
			ObjectCollider<RigidObject> collider2( object2, object2->getShapeInstance(j) );
			
			rigidVsRigidDispatcher.testForCollisions( collider1, collider2, resultSet );
		}
	}
}




//##########################################################################################
//**********************  End Rim Physics Collision Namespace  *****************************
RIM_PHYSICS_COLLISION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_DETECTOR_H
