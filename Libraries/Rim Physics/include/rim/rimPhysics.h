/*
 *  rimPhysics.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 5/8/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_H
#define INCLUDE_RIM_PHYSICS_H


#include "physics/rimPhysicsConfig.h"


#include "physics/rimPhysicsUtilities.h"
#include "physics/rimPhysicsCollision.h"
#include "physics/rimPhysicsForces.h"
#include "physics/rimPhysicsObjects.h"
#include "physics/rimPhysicsShapes.h"
#include "physics/rimPhysicsConstraints.h"
#include "physics/rimPhysicsScenes.h"
#include "physics/rimPhysicsAssets.h"


//##########################################################################################
//***************************  Start Rim Physics Namespace  ********************************
RIM_PHYSICS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


using namespace rim::physics::util;
using namespace rim::physics::collision;
using namespace rim::physics::forces;
using namespace rim::physics::objects;
using namespace rim::physics::shapes;
using namespace rim::physics::scenes;
using namespace rim::physics::constraints;
using namespace rim::physics::assets;


//##########################################################################################
//***************************  End Rim Physics Namespace  **********************************
RIM_PHYSICS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_H
