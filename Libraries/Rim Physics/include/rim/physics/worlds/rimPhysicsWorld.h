/*
 *  rimPhysicsWorld.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 6/1/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_WORLD_H
#define INCLUDE_RIM_PHYSICS_WORLD_H


#include "rimPhysicsWorldsConfig.h"


//##########################################################################################
//***********************  Start Rim Physics Worlds Namespace  *****************************
RIM_PHYSICS_WORLDS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An interface for classes that handle all aspects of physics simulation.
class PhysicsWorld
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this physics world.
			virtual ~PhysicsWorld()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Simulation Update Methods
			
			
			
			
			/// Update the physics simulation for this physics world for the specified timestep.
			virtual void updateSimulation( Real dt ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Rigid Object Accessor Methods
			
			
			
			
			/// Add the specified rigid object to this PhysicsWorld.
			/**
			  * If the specified rigid object pointer is NULL, the
			  * physics world is unchanged.
			  */
			virtual void addRigidObject( RigidObject* rigidObject ) = 0;
			
			
			
			
			/// Remove the specified rigid object from this PhysicsWorld.
			/**
			  * If this detector contains the specified rigid object, the
			  * object is removed from the physics world and TRUE is returned.
			  * Otherwise, if the rigid object is not found, FALSE is returned
			  * and the physics world is unchanged.
			  */
			virtual Bool removeRigidObject( RigidObject* rigidObject ) = 0;
			
			
			
			
			/// Remove all rigid objects from this PhysicsWorld.
			virtual void removeRigidObjects() = 0;
			
			
			
			
			/// Return whether or not the specified rigid object is contained in this PhysicsWorld.
			/**
			  * If this PhysicsWorld contains the specified rigid object, TRUE is returned.
			  * Otherwise, if the rigid object is not found, FALSE is returned.
			  */
			virtual Bool containsRigidObject( RigidObject* rigidObject ) const = 0;
			
			
			
			
			/// Return the number of rigid objects that are contained in this PhysicsWorld.
			virtual Size getRigidObjectCount() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Force Field Accessor Methods
			
			
			
			
			/// Add the specified force field to this physics world.
			/**
			  * If the specified force field pointer is not equal to NULL,
			  * it is added to this physics world. Otherwise, the physics
			  * world is unchanged.
			  */
			virtual void addForceField( ForceField* forceField ) = 0;
			
			
			
			
			/// Remove the specified force field from this PhysicsWorld.
			/**
			  * If this detector contains the specified force field, the
			  * field is removed from the physics world and TRUE is returned.
			  * Otherwise, if the force field is not found, FALSE is returned
			  * and the physics world is unchanged.
			  */
			virtual Bool removeForceField( ForceField* forceField ) = 0;
			
			
			
			
			/// Remove all force fields from this PhysicsWorld.
			virtual void removeForceFields() = 0;
			
			
			
			
			/// Return whether or not the specified force field is contained in this PhysicsWorld.
			/**
			  * If this PhysicsWorld contains the specified force field, TRUE is returned.
			  * Otherwise, if the force field is not found, FALSE is returned.
			  */
			virtual Bool containsForceField( ForceField* forceField ) const = 0;
			
			
			
			
			/// Return the number of force fields that are contained in this PhysicsWorld.
			virtual Size getForceFieldCount() const = 0;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Physics Worlds Namespace  *******************************
RIM_PHYSICS_WORLDS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_WORLD_H
