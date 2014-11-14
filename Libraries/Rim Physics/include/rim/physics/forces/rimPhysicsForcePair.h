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
/// An extension of the Force interface which can apply forces to a pair of objects.
/**
  * By deriving from this class, one can simulate various pair-wise force interactions
  * such as gravity, springs, etc.
  */
template < typename ObjectType1, typename ObjectType2 >
class ForcePair : public Force
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default force pair which affects no objects.
			RIM_INLINE ForcePair()
				:	object1( NULL ),
					object2( NULL )
			{
			}
			
			
			
			
			/// Create a force pair which affects the specified pair of objects.
			RIM_INLINE ForcePair( ObjectType1* newObject1, ObjectType2* newObject2 )
				:	object1( newObject1 ),
					object2( newObject2 )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Force Application Method
			
			
			
			
			/// Apply force vectors to the pair of objects that this ForceField effects.
			/**
			  * These force vectors should be based on the internal configuration
			  * of the force system.
			  */
			virtual void applyForces( Real dt ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Accessor Methods
			
			
			
			
			/// Return the first object in this force pair.
			/**
			  * If this pair does not have a first object, NULL is returned.
			  */
			RIM_FORCE_INLINE ObjectType1* getObject1() const
			{
				return object1;
			}
			
			
			
			
			/// Set the first object in this pair.
			/**
			  * Setting the first object pointer to a NULL value will remove
			  * that object from this pair's force system.
			  */
			RIM_FORCE_INLINE void setObject1( ObjectType1* newObject1 )
			{
				object1 = newObject1;
			}
			
			
			
			
			/// Return the second object in this force pair.
			/**
			  * If this pair does not have a second object, NULL is returned.
			  */
			RIM_FORCE_INLINE ObjectType2* getObject2() const
			{
				return object2;
			}
			
			
			
			
			/// Set the second object in this pair.
			/**
			  * Setting the second object pointer to a NULL value will remove
			  * that object from this pair's force system.
			  */
			RIM_FORCE_INLINE void setObject2( ObjectType2* newObject2 )
			{
				object2 = newObject2;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The first object of this force pair.
			ObjectType1* object1;
			
			
			
			
			/// The second object of this force pair.
			ObjectType2* object2;
			
			
			
};




//##########################################################################################
//************************  End Rim Physics Forces Namespace  ******************************
RIM_PHYSICS_FORCES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_FORCE_FIELD_H
