/*
 *  rimPhysicsCollisionPair.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_PAIR_H
#define INCLUDE_RIM_PHYSICS_COLLISION_PAIR_H


#include "rimPhysicsCollisionConfig.h"


//##########################################################################################
//**********************  Start Rim Physics Collision Namespace  ***************************
RIM_PHYSICS_COLLISION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates a potentially colliding pair of objects.
/**
  * Each object is specified using an ObjectCollider object which may contain additional
  * information about the object used during collision detection.
  */
template < typename ObjectType1, typename ObjectType2 >
class CollisionPair
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a collision pair object from the two specified ObjectCollider objects.
			RIM_INLINE CollisionPair( const ObjectCollider<ObjectType1>& newCollider1,
									const ObjectCollider<ObjectType2>& newCollider2 )
				:	collider1( newCollider1 ),
					collider2( newCollider2 )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Collider Accessor Methods
			
			
			
			
			/// Return a const reference to the first collider in this collision pair.
			RIM_FORCE_INLINE const ObjectCollider<ObjectType1>& getCollider1() const
			{
				return collider1;
			}
			
			
			
			
			/// Set the first collider in this collision pair.
			RIM_INLINE void setCollider1( const ObjectCollider<ObjectType1>& newCollider1 )
			{
				collider1 = newCollider1;
			}
			
			
			
			
			/// Return a const reference to the first collider in this collision pair.
			RIM_FORCE_INLINE const ObjectCollider<ObjectType2>& getCollider2() const
			{
				return collider2;
			}
			
			
			
			
			/// Set the second collider in this collision pair.
			RIM_INLINE void setCollider2( const ObjectCollider<ObjectType2>& newCollider2 )
			{
				collider2 = newCollider2;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The first collider in this collision pair.
			ObjectCollider<ObjectType1> collider1;
			
			
			
			
			/// The second collider in this collision pair.
			ObjectCollider<ObjectType2> collider2;
			
			
			
};




//##########################################################################################
//**********************  End Rim Physics Collision Namespace  *****************************
RIM_PHYSICS_COLLISION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_PAIR_H
