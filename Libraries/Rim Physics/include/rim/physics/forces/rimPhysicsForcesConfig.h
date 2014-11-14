/*
 *  rimPhysicsForcesConfig.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_FORCES_CONFIG_H
#define INCLUDE_RIM_PHYSICS_FORCES_CONFIG_H


#include "../rimPhysicsConfig.h"


#include "../rimPhysicsObjects.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_PHYSICS_FORCES_NAMESPACE_START
	#define RIM_PHYSICS_FORCES_NAMESPACE_START		RIM_PHYSICS_NAMESPACE_START namespace forces {
#endif




#ifndef RIM_PHYSICS_FORCES_NAMESPACE_END
	#define RIM_PHYSICS_FORCES_NAMESPACE_END		}; RIM_PHYSICS_NAMESPACE_END
#endif




//##########################################################################################
//************************  Start Rim Physics Forces Namespace  ****************************
RIM_PHYSICS_FORCES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




using rim::physics::objects::RigidObject;




//##########################################################################################
//************************  End Rim Physics Forces Namespace  ******************************
RIM_PHYSICS_FORCES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_FORCES_CONFIG_H
