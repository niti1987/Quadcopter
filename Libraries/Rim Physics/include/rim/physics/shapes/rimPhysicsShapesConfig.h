/*
 *  rimPhysicsShapesConfig.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_SHAPES_CONFIG_H
#define INCLUDE_RIM_PHYSICS_SHAPES_CONFIG_H


#include "../rimPhysicsConfig.h"


#include "../rimPhysicsUtilities.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_PHYSICS_SHAPES_NAMESPACE_START
	#define RIM_PHYSICS_SHAPES_NAMESPACE_START		RIM_PHYSICS_NAMESPACE_START namespace shapes {
#endif




#ifndef RIM_PHYSICS_SHAPES_NAMESPACE_END
	#define RIM_PHYSICS_SHAPES_NAMESPACE_END		}; RIM_PHYSICS_NAMESPACE_END
#endif




//##########################################################################################
//************************  Start Rim Physics Shapes Namespace  ****************************
RIM_PHYSICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




using rim::physics::util::PhysicsVertex3;
using rim::physics::util::PhysicsTriangle;
using rim::physics::util::ConvexHull;
using rim::bvh::AABBTree4;




//##########################################################################################
//************************  End Rim Physics Shapes Namespace  ******************************
RIM_PHYSICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_SHAPES_CONFIG_H
