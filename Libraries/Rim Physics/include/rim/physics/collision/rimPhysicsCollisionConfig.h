/*
 *  rimPhysicsConfig.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_CONFIG_H
#define INCLUDE_RIM_PHYSICS_COLLISION_CONFIG_H


#include "../rimPhysicsConfig.h"


#include "../rimPhysicsShapes.h"
#include "../rimPhysicsObjects.h"
#include "../rimPhysicsUtilities.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_PHYSICS_COLLISION_NAMESPACE_START
	#define RIM_PHYSICS_COLLISION_NAMESPACE_START		RIM_PHYSICS_NAMESPACE_START namespace collision {
#endif




#ifndef RIM_PHYSICS_COLLISION_NAMESPACE_END
	#define RIM_PHYSICS_COLLISION_NAMESPACE_END		}; RIM_PHYSICS_NAMESPACE_END
#endif




//##########################################################################################
//**********************  Start Rim Physics Collision Namespace  ***************************
RIM_PHYSICS_COLLISION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




using namespace rim::physics::shapes;


using rim::physics::objects::RigidObject;
using rim::physics::objects::ObjectPair;
using rim::physics::objects::ObjectCollider;


using rim::physics::util::MinkowskiVertex3;
using rim::physics::util::GJKSolver;
using rim::physics::util::EPASolver;
using rim::physics::util::EPAResult;
using rim::physics::util::IntersectionPoint;



//##########################################################################################
//**********************  End Rim Physics Collision Namespace  *****************************
RIM_PHYSICS_COLLISION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_CONFIG_H
