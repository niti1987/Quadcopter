/*
 *  rimPhysicsForceField.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_FORCE_FIELD_H
#define INCLUDE_RIM_PHYSICS_FORCE_FIELD_H


#include "rimPhysicsForcesConfig.h"


#include "rimPhysicsForce.h"


//##########################################################################################
//************************  Start Rim Physics Forces Namespace  ****************************
RIM_PHYSICS_FORCES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An extension of the Force interface which can apply forces to a collection of objects.
/**
  * By deriving from this class, one can simulate various global or n-body force fields
  * such as gravity, magnetism, etc.
  */
class ForceField : public Force
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Force Application Method
			
			
			
			
			/// Apply force vectors to all objects that this ForceField effects.
			/**
			  * These force vectors should be based on the internal configuration
			  * of the force system. If this force field contains an object,
			  * the force field calculates the force on that object and applies it.
			  * These forces may be caused by or affected by the objects in the 
			  * ForceField system.
			  */
			virtual void applyForces( Real dt ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Rigid Object Accessor Methods
			
			
			
			
			/// Add the specified rigid object to this ForceField.
			/**
			  * If the specified rigid object pointer is NULL, the
			  * force field is unchanged.
			  */
			virtual void addRigidObject( RigidObject* newRigidObject ) = 0;
			
			
			
			
			/// Remove the specified rigid object from this ForceField.
			/**
			  * If this ForceField contains the specified rigid object, the
			  * object is removed from the force system and TRUE is returned.
			  * Otherwise, if the rigid object is not found, FALSE is returned
			  * and the force field is unchanged.
			  */
			virtual Bool removeRigidObject( RigidObject* newRigidObject ) = 0;
			
			
			
			
			/// Remove all rigid objects from this ForceField.
			virtual void removeRigidObjects() = 0;
			
			
			
			
			/// Return whether or not the specified rigid object is contained in this ForceField.
			/**
			  * If this ForceField contains the specified rigid object, TRUE is returned.
			  * Otherwise, if the rigid object is not found, FALSE is returned.
			  */
			virtual Bool containsRigidObject( RigidObject* newRigidObject ) const = 0;
			
			
			
			
			/// Return the number of rigid objects that are contained in this ForceField.
			virtual Size getRigidObjectCount() const = 0;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Physics Forces Namespace  ******************************
RIM_PHYSICS_FORCES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_FORCE_FIELD_H
