/*
 *  rimPhysicsCollisionConstraint.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_CONSTRAINT_H
#define INCLUDE_RIM_PHYSICS_COLLISION_CONSTRAINT_H


#include "rimPhysicsConstraintsConfig.h"


#include "rimPhysicsConstraint.h"


//##########################################################################################
//*********************  Start Rim Physics Constraints Namespace  **************************
RIM_PHYSICS_CONSTRAINTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which solves collision constraints between arbitrary template object types.
template < typename ObjectType1, typename ObjectType2 >
class CollisionConstraint;




//##########################################################################################
//*********************  End Rim Physics Constraints Namespace  ****************************
RIM_PHYSICS_CONSTRAINTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_CONSTRAINT_H
