/*
 *  rimPhysicsAssetsConfig.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/22/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef INCLUDE_RIM_PHYSICS_ASSETS_CONFIG_H
#define INCLUDE_RIM_PHYSICS_ASSETS_CONFIG_H


#include "../rimPhysicsConfig.h"


#include "../rimPhysicsUtilities.h"
#include "../rimPhysicsShapes.h"
#include "../rimPhysicsObjects.h"
#include "../rimPhysicsForces.h"
#include "../rimPhysicsConstraints.h"
#include "../rimPhysicsScenes.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_PHYSICS_ASSETS_NAMESPACE_START
	#define RIM_PHYSICS_ASSETS_NAMESPACE_START		RIM_PHYSICS_NAMESPACE_START namespace assets {
#endif




#ifndef RIM_PHYSICS_ASSETS_NAMESPACE_END
	#define RIM_PHYSICS_ASSETS_NAMESPACE_END		}; RIM_PHYSICS_NAMESPACE_END
#endif




//##########################################################################################
//************************  Start Rim Physics Assets Namespace  ****************************
RIM_PHYSICS_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################






//##########################################################################################
//************************  End Rim Physics Assets Namespace  ******************************
RIM_PHYSICS_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_ASSETS_CONFIG_H
