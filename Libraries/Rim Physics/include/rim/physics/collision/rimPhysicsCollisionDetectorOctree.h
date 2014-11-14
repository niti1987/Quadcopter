/*
 *  rimPhysicsCollisionDetectorOctree.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 10/7/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_DETECTOR_OCTREE_H
#define INCLUDE_RIM_PHYSICS_COLLISION_DETECTOR_OCTREE_H


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
/// An implementation of the CollisionDetector interface that uses a dynamic octree to detect collisions.
class CollisionDetectorOctree : public CollisionDetector
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create an octree-based collision detector which contains no objects.
			CollisionDetectorOctree();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Collision Detection Methods
			
			
			
			
			/// Detect rigid-vs-rigid collisions that occurr over a timestep and add them to the result set.
			/**
			  * This implementation of this method uses an O(n*log(n)) dynamic octree-based 
			  * algorithm to detect potentially colliding pairs of objects.
			  */
			virtual void testForCollisions( Real dt, CollisionResultSet<RigidObject,RigidObject>& resultSet );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Rigid Object Accessor Methods
			
			
			
			
			/// Add the specified rigid object to this octree collision detector.
			/**
			  * If the specified rigid object pointer is NULL, the
			  * collision detector is unchanged.
			  */
			virtual void addRigidObject( const RigidObject* rigidObject );
			
			
			
			
			/// Remove the specified rigid object from this octree collision detector.
			/**
			  * If this detector contains the specified rigid object, the
			  * object is removed from the collision detector and TRUE is returned.
			  * Otherwise, if the rigid object is not found, FALSE is returned
			  * and the collision detector is unchanged.
			  */
			virtual Bool removeRigidObject( const RigidObject* rigidObject );
			
			
			
			
			/// Remove all rigid objects from this octree collision detector.
			virtual void removeRigidObjects();
			
			
			
			
			/// Return whether or not the specified rigid object is contained in this octree collision detector.
			/**
			  * If this octree collision detector contains the specified rigid object, TRUE is returned.
			  * Otherwise, if the rigid object is not found, FALSE is returned.
			  */
			virtual Bool containsRigidObject( const RigidObject* rigidObject ) const;
			
			
			
			
			/// Return the number of rigid objects that are contained in this octree collision detector.
			virtual Size getRigidObjectCount() const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations
			
			
			
			
			/// A class which contains information for a single node of an octree.
			class Node;
			
			
			
			
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


#endif // INCLUDE_RIM_PHYSICS_COLLISION_DETECTOR_OCTREE_H
