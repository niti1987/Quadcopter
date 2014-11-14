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
			
			
			
			/// The 3D position of the quadcopter's center of mass in world space (meters).
			Vector3f position;
			
			/// The 3D velocity of the quadcopter's center of mass in world space (meters per second).
			Vector3f velocity;
			
			/// The 3D force on the quadcopter's center of mass in world space for the current time step (kg*meters / seconds^2).
			Vector3f force;
			
			/// The 3x3 rotation matrix specifying the rotation from local to world space.
			Matrix3f orientation;
			
			Vector3f angularVelocity;
			Vector3f torque;
			
			/// The mass of the quadcopter in kg.
			Float mass;
			Float inverseMass;
			
			/// The body-space inertia tensor of the quadcopter.
			Matrix3f inertia;
			
			
			/// A camera that looks in the forward direction.
			Pointer<PerspectiveCamera> frontCamera;
			
			/// A camera that looks downwards.
			Pointer<PerspectiveCamera> downCamera;
			
			/// The graphical representation of the quadcopter.
			Pointer<GraphicsObject> graphics;
			
			
			
};





#endif // INCLUDE_QUADCOPTER_H
