/*
 *  rimPhysicsObjectsConfig.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_OBJECTS_CONFIG_H
#define INCLUDE_RIM_PHYSICS_OBJECTS_CONFIG_H


#include "../rimPhysicsConfig.h"


#include "../rimPhysicsUtilities.h"
#include "../rimPhysicsShapes.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_PHYSICS_OBJECTS_NAMESPACE_START
	#define RIM_PHYSICS_OBJECTS_NAMESPACE_START		RIM_PHYSICS_NAMESPACE_START namespace objects {
#endif




#ifndef RIM_PHYSICS_OBJECTS_NAMESPACE_END
	#define RIM_PHYSICS_OBJECTS_NAMESPACE_END		}; RIM_PHYSICS_NAMESPACE_END
#endif




//##########################################################################################
//***********************  Start Rim Physics Objects Namespace  ****************************
RIM_PHYSICS_OBJECTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



using rim::physics::shapes::CollisionShape;
using rim::physics::shapes::CollisionShapeInstance;
using rim::physics::shapes::CollisionShapeType;
using rim::physics::shapes::CollisionShapeTypeID;



//##########################################################################################
//***********************  End Rim Physics Objects Namespace  ******************************
RIM_PHYSICS_OBJECTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_OBJECTS_CONFIG_H
