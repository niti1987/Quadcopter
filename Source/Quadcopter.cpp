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
		frontCamera( Pointer<PerspectiveCamera>::construct() ),
		downCamera( Pointer<PerspectiveCamera>::construct() )
{
}





void Quadcopter:: updateGraphics()
{
	if ( graphics.isSet() )
	{
		graphics->setPosition( position );
		graphics->setOrientation( orientation );
	}
	
	if ( frontCamera.isSet() )
	{
		frontCamera->setPosition( position );
		frontCamera->setOrientation( orientation );
	}
	
	if ( downCamera.isSet() )
	{
		downCamera->setPosition( position );
		downCamera->setOrientation( orientation * Matrix3f::rotationXDegrees(90) );
	}
}