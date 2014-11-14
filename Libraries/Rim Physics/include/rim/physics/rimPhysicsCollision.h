/*
 *  rimPhysicsCollision.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 5/8/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_H
#define INCLUDE_RIM_PHYSICS_COLLISION_H


#include "rimPhysicsConfig.h"


#include "collision/rimPhysicsCollisionConfig.h"


#include "collision/rimPhysicsCollisionAlgorithm.h"
#include "collision/rimPhysicsCollisionAlgorithmBase.h"
#include "collision/rimPhysicsCollisionAlgorithmDispatcher.h"


#include "collision/rimPhysicsCollisionPair.h"


#include "collision/rimPhysicsCollisionManifold.h"
#include "collision/rimPhysicsCollisionResultSet.h"


#include "collision/rimPhysicsCollisionDetector.h"
#include "collision/rimPhysicsCollisionDetectorSimple.h"
#include "collision/rimPhysicsCollisionDetectorOctree.h"


#include "collision/rimPhysicsCollisionAlgorithmSphereVsSphere.h"
#include "collision/rimPhysicsCollisionAlgorithmGJK.h"
#include "collision/rimPhysicsCollisionAlgorithmsGJK.h"
#include "collision/rimPhysicsCollisionAlgorithmFunction.h"
#include "collision/rimPhysicsCollisionAlgorithmFunctions.h"
#include "collision/rimPhysicsCollisionAlgorithmSphereVsMesh.h"



//##########################################################################################
//**********************  Start Rim Physics Collision Namespace  ***************************
RIM_PHYSICS_COLLISION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################






//##########################################################################################
//**********************  End Rim Physics Collision Namespace  *****************************
RIM_PHYSICS_COLLISION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_H
