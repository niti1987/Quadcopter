/*
 *  Quadcopter.h
 *  Quadcopter
 *
 *  Created by Carl Schissler on 10/23/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_QUADCOPTER_H
#define INCLUDE_QUADCOPTER_H


#include "rim/rimEngine.h"
#include "rim/rimGraphicsGUI.h"


using namespace rim;
using namespace rim::graphics;
using namespace rim::graphics::gui;
using namespace rim::engine;



class Quadcopter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			Quadcopter();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Functions
			
			
			
			/// Update the graphical representation + camera with the new simulated position.
			void updateGraphics();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Data Members
			
			
			
			Vector3f position;
			Vector3f velocity;
			Vector3f force;
			
			Matrix3f orientation;
			Vector3f angularVelocity;
			Vector3f torque;
			
			Float mass;
			Float inverseMass;
			
			Matrix3f inertia;
			
			
			Pointer<PerspectiveCamera> camera;
			Pointer<GraphicsObject> graphics;
			
			
			
};





#endif // INCLUDE_QUADCOPTER_H
