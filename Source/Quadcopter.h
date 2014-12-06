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

#include "Global_planner.h"


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
							thrust( 0 ),
							thrustRange( 0, MAX_MOTOR_THRUST )
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
					
					/// The range of valid thrust of the motor in newtons.
					AABB1f thrustRange;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Data Members
			
			
			
			
			static const float MAX_SPEED;
			static const float MAX_ACCELERATION;
			static const float MAX_TILT_ANGLE;
			
			/// The maximum allowed angular velocity, in radians per second.
			static const float MAX_ROLL_RATE;
			
			/// The maximum allowed tolerance in radians in the rotation from the preferred rotation.
			static const float MAX_ANGLE_ERROR;
			
			/// The maximum thrust that the quadcopter can produce from all motors combined.
			static const float MAX_THRUST;
			
			/// The minimum thrust that the quadcopter can produce from all motors combined.
			static const float MIN_THRUST;
			
			/// The maximum change in thrust per second for a quadcopter motor.
			static const float MAX_DELTA_THRUST;
			
			/// The maximum thrust that the quadcopter can produce from a single motor.
			static const float MAX_MOTOR_THRUST;
			
			/// The maximum torque magnitude that the quadcopter should have, to limit spin.
			static const float MAX_ANGULAR_ACCELERATION;
			
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
			ArrayList<Motor> motors;
			
			
			
			/// The previous thrust vector in the world coordinate frame.
			Vector3f lastThrust;
			
			/// The current target waypoint for the quadcopter in world space.
			Vector3f nextWaypoint;

			/// The goal position for the quadcopter in world space.
			Vector3f goalpoint;
			
			mutable Matrix3f prefRot;
			
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
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Functions
			
			/// Compute the path based on goal position and transform state
			vertices getpath(const TransformState& state, const Vector3f& goalPosition, int numsamples) const;

			
			
			
			/// Compute the ideal thrust vector based on the given goal position, transform stsate, and external acceleration.
			Vector3f computePreferredThrust( const TransformState& state, const Vector3f& goalPosition,
											const Vector3f& externalAcceleration ) const;
			
			
			
			
			/// Compute and return the ideal net angular acceleration that will acheive the target orientation.
			Vector3f computePreferredAngularAcceleration( const TransformState& state, const Vector3f& goalPosition,
														const Vector3f& preferredThrust ) const;
			
			
			
			
			/// Compute and return the preferred rotation matrix.
			Matrix3f computePreferredRotation( const TransformState& state, const Vector3f& look,
												const Vector3f& preferredThrust ) const;
			
			
			
			
			static void solveForMotorThrusts( const TransformState& state, const ArrayList<Motor>& motors,
												const Vector3f& preferredForce, const Vector3f& preferredTorque,
												Array<Float>& thrusts );
			
			
			
			
			
			/// Optimize for the best set of motor thrusts for the specified preferred force and torque.
			static void optimizeThrusts( const ArrayList<Motor>& motors, Array<Float>& thrusts,
										const Vector3f& localForce, const Vector3f& localTorque );
			
			
			
			/// Use a hill-climbing algorithm to find the best thrusts given starting thrusts.
			/**
			  * The final best cost is returned.
			  */
			static Float hillClimbThrusts( const ArrayList<Motor>& motors, Array<Float>& thrusts,
										const Vector3f& localForce, const Vector3f& localTorque );
			
			
			
			/// Constrain the thrust values for the motors to be within the valid range for the motors.
			static void constrainThrusts( const ArrayList<Motor>& motors, Array<Float>& thrusts );
			
			
			
			
			/// Compute the cost for a new set of thrust values for the given quadcopter state and preferred accelerations.
			static Float getCost( const ArrayList<Motor>& motors, const Array<Float>& thrusts,
									const Vector3f& localForce, const Vector3f& localTorque );
			
			
			
			
			/// Compute and return an orthonormal rotation matrix from the given up and look vectors.
			static Matrix3f rotationFromUpLook( const Vector3f& up, const Vector3f& look )
			{
				// Generate an orthonormal rotation matrix based on that up vector and the desired look direction.
				Vector3f right = math::cross( up, -look ).normalize();
				Vector3f back = math::cross( right, up ).normalize();
				
				return Matrix3f( right, up, back ).orthonormalize();
			}
			
			
			
			/// Apply a force vector at the given radial arm in world space, adding to the linear and angular acceleration.
			static void applyForce( const Vector3f& r, const Vector3f& forceVector,
									Vector3f& force, Vector3f& torque )
			{
				force += forceVector;
				torque += math::cross( r, forceVector );
			}
			
			
			
};





#endif // INCLUDE_QUADCOPTER_H
