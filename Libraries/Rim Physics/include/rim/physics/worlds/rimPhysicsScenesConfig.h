/*
 *  rimPhysicsScenesConfig.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 6/1/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_SCENES_CONFIG_H
#define INCLUDE_RIM_PHYSICS_SCENES_CONFIG_H


#include "../rimPhysicsConfig.h"


#include "../rimPhysicsObjects.h"
#include "../rimPhysicsShapes.h"
#include "../rimPhysicsCollision.h"
#include "../rimPhysicsForces.h"
#include "../rimPhysicsConstraints.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_PHYSICS_SCENES_NAMESPACE_START
	#define RIM_PHYSICS_SCENES_NAMESPACE_START		RIM_PHYSICS_NAMESPACE_START namespace scenes {
#endif




#ifndef RIM_PHYSICS_SCENES_NAMESPACE_END
	#define RIM_PHYSICS_SCENES_NAMESPACE_END		}; RIM_PHYSICS_NAMESPACE_END
#endif




//##########################################################################################
//***********************  Start Rim Physics Scenes Namespace  *****************************
RIM_PHYSICS_SCENES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




using namespace rim::physics::shapes;
using namespace rim::physics::objects;
using namespace rim::physics::collision;
using namespace rim::physics::forces;
using namespace rim::physics::constraints;




//##########################################################################################
//***********************  End Rim Physics Scenes Namespace  *******************************
RIM_PHYSICS_SCENES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_SCENES_CONFIG_H
