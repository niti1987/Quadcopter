/*
 *  rimPhysicsForceFieldGravitySimple.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_FORCE_FIELD_GRAVITY_SIMPLE_H
#define INCLUDE_RIM_PHYSICS_FORCE_FIELD_GRAVITY_SIMPLE_H


#include "rimPhysicsForcesConfig.h"


#include "rimPhysicsForceField.h"


//##########################################################################################
//************************  Start Rim Physics Forces Namespace  ****************************
RIM_PHYSICS_FORCES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An implementation of the ForceField interface that provides a simple model for gravity.
/**
  * This class assumes that gravity can be modeled as a uniform force field
  * that is specified by a single gravitational acceleration vector. This kind of 
  * gravity models how gravity appears to work on the earth's surface,
  * but would be unsuitable for n-body planetary-scale gravitation.
  */
class ForceFieldGravitySimple : public ForceField
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default simple gravitational field with earth-like gravity.
			/**
			  * This gravitational acceleration is equal to 9.81 m/s and is pointed
			  * in the negative Y direction, resulting in a gravity vector of (0,-9.81,0).
			  */
			RIM_INLINE ForceFieldGravitySimple()
				:	gravityVector( Real(0), Real(-9.81), Real(0) )
			{
			}
			
			
			
			
			/// Create a gravitational field with the specified gravitational acceleration.
			RIM_INLINE ForceFieldGravitySimple( const Vector3& newGravityVector )
				:	gravityVector( newGravityVector )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Force Application Method
			
			
			
			
			/// Apply force vectors to all objects that this simple gravity field effects.
			/**
			  * These force vectors should be based on the internal configuration
			  * of the force system. If this force field contains an object,
			  * the force field calculates the force on that object and applies it.
			  * These forces may be caused by or affected by the objects in the 
			  * ForceField system.
			  */
			virtual void applyForces( Real dt );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Rigid Object Accessor Methods
			
			
			
			
			/// Add the specified rigid object to this ForceField.
			/**
			  * If the specified rigid object pointer is NULL, the
			  * force field is unchanged.
			  */
			virtual void addRigidObject( RigidObject* newRigidObject );
			
			
			
			
			/// Remove the specified rigid object from this ForceField.
			/**
			  * If this ForceField contains the specified rigid object, the
			  * object is removed from the force system and TRUE is returned.
			  * Otherwise, if the rigid object is not found, FALSE is returned
			  * and the force field is unchanged.
			  */
			virtual Bool removeRigidObject( RigidObject* newRigidObject );
			
			
			
			
			/// Remove all rigid objects from this ForceField.
			virtual void removeRigidObjects();
			
			
			
			
			/// Return whether or not the specified rigid object is contained in this ForceField.
			/**
			  * If this ForceField contains the specified rigid object, TRUE is returned.
			  * Otherwise, if the rigid object is not found, FALSE is returned.
			  */
			virtual Bool containsRigidObject( RigidObject* newRigidObject ) const;
			
			
			
			
			/// Return the number of rigid objects that are contained in this ForceField.
			virtual Size getRigidObjectCount() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Gravity Vector Accessor Methods
			
			
			
			
			/// Return the gravitational acceleration vector that is being applied to all objects.
			RIM_INLINE const Vector3& getGravityVector() const
			{
				return gravityVector;
			}
			
			
			
			
			/// Set the gravitational acceleration vector that should be applied to all objects.
			RIM_INLINE void setGravityVector( const Vector3& newGravityVector )
			{
				gravityVector = newGravityVector;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of all of the objects in this simple gravitational field.
			ArrayList<RigidObject*> rigidObjects;
			
			
			
			
			/// The gravitational acceleration vector that is being applied to all objects.
			Vector3 gravityVector;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Physics Forces Namespace  ******************************
RIM_PHYSICS_FORCES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_FORCE_FIELD_GRAVITY_SIMPLE_H
