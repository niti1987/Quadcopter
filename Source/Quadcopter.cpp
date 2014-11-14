/*
 *  Quadcopter.cpp
 *  Quadcopter
 *
 *  Created by Carl Schissler on 10/23/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "Quadcopter.h"





Quadcopter:: Quadcopter()
	:	position(),
		velocity(),
		force(),
		orientation( Matrix3f::IDENTITY ),
		angularVelocity(),
		torque(),
		mass( 0 ),
		inverseMass( 0 ),
		inertia( Matrix3f::IDENTITY ),
		camera( Pointer<PerspectiveCamera>::construct() )
{
}





void Quadcopter:: updateGraphics()
{
	graphics->setPosition( position );
	graphics->setOrientation( orientation );
	camera->setPosition( position );
	camera->setOrientation( orientation );
}