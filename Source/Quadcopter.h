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
//#include "rim/rimGraphicsGUI.h"

#include "TransformState.h"


using namespace rim;
using namespace rim::graphics;
//using namespace rim::graphics::gui;
//using namespace rim::engine;



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
			
			
			
			
			/// Compute the linear and angular accelerations of this quadcopter given the specified state and timestep.
			/**
			  * The accelerations due to environmental forces (i.e. gravity, drag) are passed in the
			  * acceleration parameters. The function writes the final accelerations of the quadcopter's
			  * center of mass to those parameters.
			  */
			void computeAcceleration( const TransformState& state, Float timeStep, Vector3f& linearAcceleration, Vector3f& angularAcceleration ) const;
			
			
			
			Matrix3f getNewAttitudeMatrix();
			Vector3f getPreferredAccelerationVector( Float timeStep );
			Vector3f getZComponentOfThrustVector( const Vector3f& accelerationVector, const Vector3f& globalGravity );
			Vector3f calculateXAndYComponentsOfThrust( Float timeStep, const Vector3f& thrustVector, const Vector3f& accelerationVector );
			Vector3f adjustLimitDeltaThrustVector( Float timeStep, const Vector3f& thrustVector );
			Vector3f calculatePreferredLinearAcceleration( Float timeStep );
			Vector3f calculateAngularVelocity( Float timeStep );
			
			
			
			
			/// Apply a force vector at the given radial arm in world space, adding to the linear and angular acceleration.
			static void applyForce( const Vector3f& r, const Vector3f& forceVector,
									Vector3f& force, Vector3f& torque )
			{
				force += forceVector;
				torque += math::cross( r, forceVector );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Motor Class Declaration
			
			
			
			
			/// A class that stores information related to a single motor on a quadcopter.
			class Motor
			{
				public:
					
					/// Create a new motor with the specified center-of-mass offset vector and unit-length thrust direction.
					RIM_INLINE Motor( const Vector3f& newCOMOffset, const Vector3f& newThrustDirection )
						:	comOffset( newCOMOffset ),
							thrustDirection( newThrustDirection.normalize() ),
							thrust( 0 )
					{
					}
					
					/// Return the force vector for this motor.
					RIM_INLINE Vector3f getForce() const
					{
						return thrustDirection*thrust;
					}
					
					
					/// The vector from this quadcopter's center of mass to the motor position in body space.
					Vector3f comOffset;
					
					/// The unit-length direction of this motor's thrust.
					Vector3f thrustDirection;
					
					/// The current thrust of the motor in newtons.
					Float thrust;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Data Members
			
			
			
			
			static const float MAX_SPEED;
			static const float MAX_TILT_ANGLE;
			
			/// The maximum thrust that the quadcopter can produce from all motors combined.
			static const float MAX_THRUST;
			
			/// The minimum thrust that the quadcopter can produce from all motors combined.
			static const float MIN_THRUST;
			
			/// The maximum change in thrust per second for a quadcopter motor.
			static const float MAX_DELTA_THRUST;
			
			static const Vector3f VEHICLE_DELTA_THRUST;
			
			static const float VEHICLE_CLOSE_RANGE;
			static const float VEHICLE_CLOSE_RANGE_SCALE_FACTOR;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Data Members
			
			
			
			/// The current state of the quadcopter.
			TransformState currentState;
			
			
			/// A list of the motors that are part of the quadcopter.
			ShortArrayList<Motor,4> motors;
			
			
			
			/// The previous thrust vector in the world coordinate frame.
			Vector3f lastThrust;
			
			/// The current target waypoint for the quadcopter in world space.
			Vector3f nextWaypoint;
			
			
			/// The mass of the quadcopter in kg.
			Float mass;
			
			/// The body-space inertia tensor of the quadcopter.
			Matrix3f inertia;
			
			/// The current inverse world-space interia tensor.
			Matrix3f inverseWorldInertia;
			
			
			/// The time step used to determine the next acceleration.
			Float planningTimestep;
			
			
			/// A camera that looks in the forward direction.
			Pointer<PerspectiveCamera> frontCamera;
			
			/// A camera that looks downwards.
			Pointer<PerspectiveCamera> downCamera;
			
			/// The graphical representation of the quadcopter.
			Pointer<GraphicsObject> graphics;
			
			
			
};





#endif // INCLUDE_QUADCOPTER_H
