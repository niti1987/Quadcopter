/*
 *  rimPhysicsConstraintsConfig.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_CONSTRAINTS_CONFIG_H
#define INCLUDE_RIM_PHYSICS_CONSTRAINTS_CONFIG_H


#include "../rimPhysicsConfig.h"


#include "../rimPhysicsObjects.h"
#include "../rimPhysicsShapes.h"
#include "../rimPhysicsCollision.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_PHYSICS_CONSTRAINTS_NAMESPACE_START
	#define RIM_PHYSICS_CONSTRAINTS_NAMESPACE_START		RIM_PHYSICS_NAMESPACE_START namespace constraints {
#endif




#ifndef RIM_PHYSICS_CONSTRAINTS_NAMESPACE_END
	#define RIM_PHYSICS_CONSTRAINTS_NAMESPACE_END		}; RIM_PHYSICS_NAMESPACE_END
#endif




//##########################################################################################
//*********************  Start Rim Physics Constraints Namespace  **************************
RIM_PHYSICS_CONSTRAINTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




using rim::physics::objects::RigidObject;
using rim::physics::objects::ObjectPair;
using rim::physics::collision::CollisionResultSet;
using rim::physics::collision::CollisionManifold;
using rim::physics::collision::CollisionPoint;
using rim::physics::shapes::CollisionShapeMaterial;




//##########################################################################################
//*********************  End Rim Physics Constraints Namespace  ****************************
RIM_PHYSICS_CONSTRAINTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_CONSTRAINTS_CONFIG_H
