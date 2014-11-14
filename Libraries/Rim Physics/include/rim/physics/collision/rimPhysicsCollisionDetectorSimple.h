/*
 *  rimPhysicsCollisionDetectorSimple.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_DETECTOR_SIMPLE_H
#define INCLUDE_RIM_PHYSICS_COLLISION_DETECTOR_SIMPLE_H


#include "rimPhysicsCollisionConfig.h"


#include "rimPhysicsCollisionDetector.h"


//##########################################################################################
//**********************  Start Rim Physics Collision Namespace  ***************************
RIM_PHYSICS_COLLISION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An implementation of the CollisionDetector interface that uses simple O(n^2) collision detection.
class CollisionDetectorSimple : public CollisionDetector
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a simple collision detector which contains no objects.
			CollisionDetectorSimple();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Collision Detection Methods
			
			
			
			
			/// Detect rigid-vs-rigid collisions that occurr over a timestep and add them to the result set.
			/**
			  * This implementation of this method uses a simple O(n^2) algorithm
			  * to determine which objects are colliding. It examines all possible object-object
			  * pairs and tests all pairs whose bounding spheres intersect.
			  */
			virtual void testForCollisions( Real dt, CollisionResultSet<RigidObject,RigidObject>& resultSet );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Rigid Object Accessor Methods
			
			
			
			
			/// Add the specified rigid object to this simple collision detector.
			/**
			  * If the specified rigid object pointer is NULL, the
			  * collision detector is unchanged.
			  */
			virtual void addRigidObject( const RigidObject* rigidObject );
			
			
			
			
			/// Remove the specified rigid object from this simple collision detector.
			/**
			  * If this detector contains the specified rigid object, the
			  * object is removed from the collision detector and TRUE is returned.
			  * Otherwise, if the rigid object is not found, FALSE is returned
			  * and the collision detector is unchanged.
			  */
			virtual Bool removeRigidObject( const RigidObject* rigidObject );
			
			
			
			
			/// Remove all rigid objects from this simple collision detector.
			virtual void removeRigidObjects();
			
			
			
			
			/// Return whether or not the specified rigid object is contained in this simple collision detector.
			/**
			  * If this simple collision detector contains the specified rigid object, TRUE is returned.
			  * Otherwise, if the rigid object is not found, FALSE is returned.
			  */
			virtual Bool containsRigidObject( const RigidObject* rigidObject ) const;
			
			
			
			
			/// Return the number of rigid objects that are contained in this simple collision detector.
			virtual Size getRigidObjectCount() const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of pointers to rigid objects that are being tested for collisions.
			ArrayList<const RigidObject*> rigidObjects;
			
			
			
};




//##########################################################################################
//**********************  End Rim Physics Collision Namespace  *****************************
RIM_PHYSICS_COLLISION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_DETECTOR_SIMPLE_H
