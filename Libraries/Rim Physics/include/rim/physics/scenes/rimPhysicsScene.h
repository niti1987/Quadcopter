/*
 *  rimPhysicsScene.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 6/1/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_SCENE_H
#define INCLUDE_RIM_PHYSICS_SCENE_H


#include "rimPhysicsScenesConfig.h"


//##########################################################################################
//***********************  Start Rim Physics Scenes Namespace  *****************************
RIM_PHYSICS_SCENES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An interface for classes that handle all aspects of physics simulation.
class PhysicsScene
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this physics scene.
			virtual ~PhysicsScene()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Simulation Update Methods
			
			
			
			
			/// Update the physics simulation for this physics scene for the specified timestep.
			virtual void update( Real dt ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Rigid Object Accessor Methods
			
			
			
			
			/// Add the specified rigid object to this PhysicsScene.
			/**
			  * If the specified rigid object pointer is NULL, the
			  * physics scene is unchanged.
			  */
			virtual void addRigidObject( RigidObject* rigidObject ) = 0;
			
			
			
			
			/// Remove the specified rigid object from this PhysicsScene.
			/**
			  * If this detector contains the specified rigid object, the
			  * object is removed from the physics scene and TRUE is returned.
			  * Otherwise, if the rigid object is not found, FALSE is returned
			  * and the physics scene is unchanged.
			  */
			virtual Bool removeRigidObject( RigidObject* rigidObject ) = 0;
			
			
			
			
			/// Remove all rigid objects from this PhysicsScene.
			virtual void removeRigidObjects() = 0;
			
			
			
			
			/// Return whether or not the specified rigid object is contained in this PhysicsScene.
			/**
			  * If this PhysicsScene contains the specified rigid object, TRUE is returned.
			  * Otherwise, if the rigid object is not found, FALSE is returned.
			  */
			virtual Bool containsRigidObject( RigidObject* rigidObject ) const = 0;
			
			
			
			
			/// Return the number of rigid objects that are contained in this PhysicsScene.
			virtual Size getRigidObjectCount() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Force Field Accessor Methods
			
			
			
			
			/// Add the specified force field to this physics scene.
			/**
			  * If the specified force field pointer is not equal to NULL,
			  * it is added to this physics scene. Otherwise, the physics
			  * scene is unchanged.
			  */
			virtual void addForceField( ForceField* forceField ) = 0;
			
			
			
			
			/// Remove the specified force field from this PhysicsScene.
			/**
			  * If this detector contains the specified force field, the
			  * field is removed from the physics scene and TRUE is returned.
			  * Otherwise, if the force field is not found, FALSE is returned
			  * and the physics scene is unchanged.
			  */
			virtual Bool removeForceField( ForceField* forceField ) = 0;
			
			
			
			
			/// Remove all force fields from this PhysicsScene.
			virtual void removeForceFields() = 0;
			
			
			
			
			/// Return whether or not the specified force field is contained in this PhysicsScene.
			/**
			  * If this PhysicsScene contains the specified force field, TRUE is returned.
			  * Otherwise, if the force field is not found, FALSE is returned.
			  */
			virtual Bool containsForceField( ForceField* forceField ) const = 0;
			
			
			
			
			/// Return the number of force fields that are contained in this PhysicsScene.
			virtual Size getForceFieldCount() const = 0;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Physics Scenes Namespace  *******************************
RIM_PHYSICS_SCENES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_SCENE_H