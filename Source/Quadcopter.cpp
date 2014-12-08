/*
 *  Quadcopter.cpp
 *  Quadcopter
 *
 *  Created by Carl Schissler on 10/23/14.
 *  Co-author: Niti Madhugiri
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "Quadcopter.h"


const float Quadcopter:: MAX_SPEED = 4.0f;
const float Quadcopter:: MAX_ACCELERATION = 10.0f;
const float Quadcopter:: MAX_TILT_ANGLE = math::degreesToRadians( 15.0f );
const float Quadcopter:: MAX_ROLL_RATE = math::degreesToRadians( 20.0f );
const float Quadcopter:: MAX_ANGLE_ERROR = math::degreesToRadians( 1.0f );
const float Quadcopter:: MAX_THRUST = 20;
const float Quadcopter:: MIN_THRUST = 1;
const float Quadcopter:: MAX_MOTOR_THRUST = MAX_THRUST / 4;
const float Quadcopter:: MAX_ANGULAR_ACCELERATION = 1;
const float Quadcopter:: MAX_DELTA_THRUST = 1.0f;

const Vector3f Quadcopter:: VEHICLE_DELTA_THRUST = Vector3f(20, 20, 25);

const float Quadcopter:: VEHICLE_CLOSE_RANGE = 1;
const float Quadcopter:: VEHICLE_CLOSE_RANGE_SCALE_FACTOR = 0.2f;




//##########################################################################################
//##########################################################################################
//############		
//############		Constructor
//############		
//##########################################################################################
//##########################################################################################




Quadcopter:: Quadcopter()
	:	currentState(),
		mass( 1 ),
		inertia( 1, 0, 0,
				0, 1, 0,
				0, 0, 1 ),
		planningTimestep( 0.016f / 2 ),
		frontCamera( Pointer<PerspectiveCamera>::construct() ),
		downCamera( Pointer<PerspectiveCamera>::construct() )
{
}




//##########################################################################################
//##########################################################################################
//############		
//############		Graphics Update Method
//############		
//##########################################################################################
//##########################################################################################




void Quadcopter:: updateGraphics()
{
	const Vector3f& position = currentState.position;
	const Matrix3f& rotation = currentState.rotation;

	
	if ( graphics.isSet() )
	{
		graphics->setPosition( position );
		graphics->setOrientation( rotation );
	}
	
	if ( frontCamera.isSet() )
	{
		frontCamera->setPosition( position );
		frontCamera->setOrientation( rotation );
	}
	
	if ( downCamera.isSet() )
	{
		downCamera->setPosition( position );
		downCamera->setOrientation( rotation * Matrix3f::rotationXDegrees(90) );
	}
}


//############
// Path to the goal
//###############

vertices Quadcopter::getpath(const TransformState& state, const Vector3f& goalPosition, Pointer<Roadmap> rmap) const
{
	Global_planner g_plan = Global_planner(); 
	return (g_plan.prm(state.position,goalPosition,rmap));
}



//##########################################################################################
//##########################################################################################
//############		
//############		Acceleration Computation Method
//############		
//##########################################################################################
//##########################################################################################




void Quadcopter:: computeAcceleration( const TransformState& newState, Float timeStep,
										Vector3f& linearAcceleration, Vector3f& angularAcceleration ) const
{
	
	if((float)((nextWaypoint - goalpoint).getMagnitude()) != 0)
	{
		if((float)((nextWaypoint-newState.position).getMagnitude()) < (VEHICLE_CLOSE_RANGE/1.5))
		{
			nextid = nextid + 1;
			
			if ( nextid < path.size() )
				nextWaypoint = path[nextid];
		}
	}
	

	//****************************************************************************
	// Determine the preferred thrust vector based on the next waypoint.
	
	Vector3f preferredThrust = computePreferredThrust( newState, nextWaypoint, linearAcceleration );
	
	//****************************************************************************
	// Once we have the preferred acceleration, compute the target orientation that
	// the quadcopter should rotate to acheive that acceleration, then determine
	// the angular acceleration required.
	
	Vector3f preferredAngularAcceleration = computePreferredAngularAcceleration( newState, nextWaypoint, preferredThrust );
	
	// Add the preferred accelerations to the output parameters.
	linearAcceleration += preferredThrust;
	angularAcceleration += preferredAngularAcceleration;
	
	//****************************************************************************
	// Solve for the thrust (scalar value) at each motor given the current state.
	
	Array<Float> thrusts( motors.getSize(), 0 );
	Vector3f localPreferredForce = mass*newState.rotateVectorToBody( preferredThrust );
	Vector3f localPreferredTorque = inertia*newState.rotateVectorToBody( preferredAngularAcceleration );
	
	solveForMotorThrusts( newState, motors, localPreferredForce, localPreferredTorque, thrusts );
	
	//****************************************************************************
	// Apply the force and torque due to each motor.
	
	Vector3f force, torque;
	
	for ( Index m = 0; m < motors.getSize(); m++ )
	{
		const Motor& motor = motors[m];
		const Float motorThrust = thrusts[m];
		
		// Transform the center-of mass offset into world space.
		Vector3f motorPoint = currentState.transformToWorld( motor.comOffset );
		Vector3f motorForce = currentState.rotateVectorToWorld( motor.thrustDirection*motorThrust );
		
		applyForce( motorPoint, motorForce, force, torque );
	}
	
	// Compute the inverse world-space inertia tensor (similarity transform).
	Matrix3f worldInverseInertia = newState.rotation * inertia.invert() * newState.rotation.transpose();
	
	/// Apply the motor acceleration.
	//linearAcceleration += mass > math::epsilon<Float>() ? force / mass : Vector3f();
	//angularAcceleration += worldInverseInertia*torque;
	//linearAcceleration = Vector3f();
	//angularAcceleration = Vector3f();
}




//##########################################################################################
//##########################################################################################
//############		
//############		Preferred Thrust Computation Method
//############		
//##########################################################################################
//##########################################################################################




Vector3f Quadcopter:: computePreferredThrust( const TransformState& newState, const Vector3f& goalPosition,
											const Vector3f& externalAcceleration ) const
{
	// Compute the delta vector for position between the target position and the new state position.
	Vector3f deltaPosition = goalPosition - newState.position;
	Float distance = deltaPosition.getMagnitude();
	
	//****************************************************************************
	// Determine the preferred linear velocity of the quadcopter.
	// This is the desired linear velocity that the center of mass of the quadcopter should have.
	
	Vector3f preferredVelocity;
	
	if ( distance < VEHICLE_CLOSE_RANGE )
		preferredVelocity = (deltaPosition/VEHICLE_CLOSE_RANGE)*MAX_SPEED;
	else
		preferredVelocity = deltaPosition / planningTimestep;
	
	Float preferredSpeed = preferredVelocity.getMagnitude();
	
	// Make sure the preferred velocity is within the limit of the max speed.
	if  ( preferredSpeed > MAX_SPEED )
	{
		preferredVelocity *= (MAX_SPEED / preferredSpeed);
		preferredSpeed = MAX_SPEED;
	}
	
	//****************************************************************************
	// Determine the preferred linear acceleration of the quadcopter.
	// This is the desired net acceleration produced by the motors, not yet respecting
	// the physical limits of the motors.
	
	// Compute the desired change in velocity.
	Vector3f deltaVelocity = preferredVelocity - newState.velocity;
	
	// Determine the additional thrust necessary to acheive the desired change in velocity
	// within the planning time step.
	Vector3f preferredThrust = deltaVelocity / planningTimestep;
	Float preferredThrustMag = preferredThrust.getMagnitude();
	/*
	if ( preferredThrustMag > MAX_ACCELERATION )
	{
		preferredThrust *= (MAX_ACCELERATION / preferredThrustMag);
		preferredThrustMag = MAX_ACCELERATION;
	}
	*/
	// Compensate in the preferred thrust for the effects of environmental forces (i.e. gravity, drag).
	preferredThrust -= externalAcceleration;
	
	// Make sure the preferred velocity is within the limits of thrust produced by the motors.
	preferredThrustMag = preferredThrust.getMagnitude();
	
	if  ( preferredThrustMag > MAX_THRUST )
	{
		preferredThrust *= (MAX_THRUST / preferredThrustMag);
		preferredThrustMag = MAX_THRUST;
	}
	else if ( preferredThrustMag < MIN_THRUST )
	{
		preferredThrust *= (MIN_THRUST / preferredThrustMag);
		preferredThrustMag = MIN_THRUST;
	}
	
	return preferredThrust;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Preferred Angular Acceleration Computation Method
//############		
//##########################################################################################
//##########################################################################################




Vector3f Quadcopter:: computePreferredAngularAcceleration( const TransformState& state, const Vector3f& goalPosition,
															const Vector3f& preferredThrust ) const
{
	// Compute the delta vector for position between the target position and the new state position.
	Vector3f deltaPosition = goalPosition - state.position;
	Float distance = deltaPosition.getMagnitude();
	
	//****************************************************************************
	
	Matrix3f preferredRotation = computePreferredRotation( state, -state.rotation.z/*deltaPosition.normalize()*/, preferredThrust );
	prefRot = preferredRotation;
	
	// Compute the rotational difference between the new rotation and the target rotation.
	Quaternion<Float> qNew( state.rotation );
	Quaternion<Float> qPref( preferredRotation );
	Quaternion<Float> deltaQ = qPref*qNew.invert();
	
	//****************************************************************************
	
	Vector3f preferredAngularVelocity;
	
	// Make sure there is a substantial difference in the orientations.
	if ( math::abs(deltaQ.a) < math::cos(MAX_ANGLE_ERROR/2) )
	{
		// There is a significant difference in the current and preferred orientation.
		// Determine the preferred rotation rate in radians per second around the rotation axis.
		Float deltaTheta = 2*math::acos( deltaQ.a ) / planningTimestep;
		
		// Compute the rotation axis.
		Vector3f rotationAxis = Vector3f( deltaQ.b, deltaQ.c, deltaQ.d );
		
		if ( rotationAxis.getMagnitude() > math::epsilon<Float>() )
			rotationAxis = rotationAxis.normalize();
		
		// Compute the preferred angular velocity.
		preferredAngularVelocity = deltaTheta * rotationAxis;
		
		// Make sure the preferred angular velocity is within the limits.
		Float preferredAngularVelocityMag = preferredAngularVelocity.getMagnitude();
		
		if  ( preferredAngularVelocityMag > MAX_ROLL_RATE )
		{
			preferredAngularVelocity *= (MAX_ROLL_RATE / preferredAngularVelocityMag);
			preferredAngularVelocityMag = MAX_ROLL_RATE;
		}
		
		// Scale down the angular velocity if we are close to the goal.
		if ( distance < VEHICLE_CLOSE_RANGE )
			preferredAngularVelocity *= (distance / VEHICLE_CLOSE_RANGE);
	}
	
	//****************************************************************************
	// Determine the preferred angular acceleration from the preferred velocity.
	
	Vector3f deltaAngularVelocity = preferredAngularVelocity - state.angularVelocity;
	Vector3f preferredAngularAcceleration = deltaAngularVelocity / planningTimestep;
	
	// Make sure the preferred angular acceleration is within the limits.
	Float preferredAngularAccelerationMag = preferredAngularAcceleration.getMagnitude();
	
	if  ( preferredAngularAccelerationMag > MAX_ANGULAR_ACCELERATION )
		preferredAngularAcceleration *= (MAX_ANGULAR_ACCELERATION / preferredAngularAccelerationMag);
	
	//Vector3f localAcceleration = state.rotateVectorToBody( preferredAngularAcceleration );
	//localAcceleration.y = 0;
	//preferredAngularAcceleration = state.rotateVectorToWorld( localAcceleration );
	
	return preferredAngularAcceleration;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Preferred Rotation Computation Method
//############		
//##########################################################################################
//##########################################################################################




Matrix3f Quadcopter:: computePreferredRotation( const TransformState& newState, const Vector3f& look,
												const Vector3f& preferredThrust ) const
{
	// Determine the up vector based on the preferred thrust vector.
	// The preferred rotation needs to be close to horizontal, within a tolerance angle.
	// The up vector should be as close to the preferred thrust vector as allowed.
	Vector3f up( 0, 1, 0 );
	Vector3f thrustDirection = preferredThrust.normalize();
	Float angle = math::acos( math::dot( thrustDirection, up ) );
	
	if ( angle > MAX_TILT_ANGLE )
	{
		// Clamp the up vector to be no more than the max tilt value.
		
		// Compute the rotation axis and angle relative to the horizontal.
		Vector3f axis = math::cross( thrustDirection, up );
		angle = MAX_TILT_ANGLE;
		
		// Compute the quaternion from the axis-angle representation.
		Float s = math::sin( angle/2 );
		Quaternion<Float> q( math::cos( angle/2 ), axis.x*s, axis.y*s, axis.z*s );
		Matrix3f horizontal;
		
		// Determine the rotation matrix for the horizontal frame.
		if ( math::abs(math::dot( up, look )) < math::cos( MAX_ANGLE_ERROR ) )
			horizontal = rotationFromUpLook( up, look );
		else
			horizontal = rotationFromUpLook( up, -newState.rotation.z );
		
		// Apply the quaternion to the horizontal frame to get the target rotation.
		return q.toMatrix().transpose()*horizontal;
	}
	else
	{
		// The preferred thrust vector is suitable for use as the up vector.
		up = thrustDirection;
		
		if ( math::abs(math::dot( up, look )) < math::cos( MAX_ANGLE_ERROR ) )
			return rotationFromUpLook( up, look );
		else
			return rotationFromUpLook( up, -newState.rotation.z );
	}
}




//##########################################################################################
//##########################################################################################
//############		
//############		Motor Thrust Computation Method
//############		
//##########################################################################################
//##########################################################################################




void Quadcopter:: solveForMotorThrusts( const TransformState& state, const ArrayList<Motor>& motors,
										const Vector3f& localPreferredForce, const Vector3f& localPreferredTorque,
										Array<Float>& thrusts )
{
	Vector3f localForce = localPreferredForce;
	Vector3f localTorque = localPreferredTorque;
	localTorque.y = 0;
	
	// Pick a decent initial guess.
	thrusts.setAll( localForce.getMagnitude() / thrusts.getSize() );
	
	optimizeThrusts( motors, thrusts, localForce, localTorque );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Thrust Optimization Method
//############		
//##########################################################################################
//##########################################################################################




void Quadcopter:: optimizeThrusts( const ArrayList<Motor>& motors, Array<Float>& thrusts,
									const Vector3f& localForce, const Vector3f& localTorque )
{
	const Size numTrys = 100;
	const Size numMotors = motors.getSize();
	Array<Float> currentThrusts = thrusts;
	Float currentCost = getCost( motors, currentThrusts, localForce, localTorque );
	
	for ( Index i = 0; i < numTrys; i++ )
	{
		// Pick a random starting thrust value.
		Array<Float> tempThrusts = currentThrusts;
		
		for ( Index m = 0; m < numMotors; m++ )
		{
			const Motor& motor = motors[m];
			tempThrusts[m] = math::random( motor.thrustRange.min, motor.thrustRange.max );
		}
		
		Float cost = hillClimbThrusts( motors, tempThrusts, localForce, localTorque );
		
		if ( cost < currentCost )
		{
			currentThrusts = tempThrusts;
			currentCost = cost;
		}
	}
	
	thrusts = currentThrusts;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Thrust Optimization Method
//############		
//##########################################################################################
//##########################################################################################




Float Quadcopter:: hillClimbThrusts( const ArrayList<Motor>& motors, Array<Float>& thrusts,
									const Vector3f& localForce, const Vector3f& localTorque )
{
	const Float stepSize = 0.1f; // Newtons.
	const Float acceleration = 1.2f; // unitless
	const Float epsilon = 0.0001f;
	const Size maxIterations = 50;
	const Size numCandidates = 5;
	const Float candidates[numCandidates] = { -acceleration, -1.0f / acceleration, 0, 1.0f / acceleration, acceleration };
	
	const Size numMotors = motors.getSize();
	Array<Float> currentThrusts = thrusts;
	Array<Float> currentStepSize( numMotors, stepSize );
	Float currentCost = getCost( motors, currentThrusts, localForce, localTorque );
	
	for ( Index iteration = 0; iteration < maxIterations; iteration++ )
	{
		// Hill climb for each variable.
		for ( Index m = 0; m < numMotors; m++ )
		{
			Float bestCost = math::max<Float>();
			const Float startPoint = currentThrusts[m];
			Index bestCandidate = numCandidates / 2;
			
			// Try each candidate location to see which has the best cost.
			for ( Index c = 0; c < numCandidates; c++ )
			{
				currentThrusts[m] = startPoint + candidates[c]*currentStepSize[m];
				
				Float candidateCost = getCost( motors, currentThrusts, localForce, localTorque );
				
				if ( candidateCost < bestCost )
				{
					bestCost = candidateCost;
					bestCandidate = c;
				}
			}
			
			if ( bestCost > math::min<Float>() )
			{
				currentThrusts[m] = startPoint + candidates[bestCandidate]*currentStepSize[m];
				currentStepSize[m] *= candidates[bestCandidate]; // accelerate.
			}
		}
		
		constrainThrusts( motors, currentThrusts );
		Float newCost = getCost( motors, currentThrusts, localForce, localTorque );
		
		// Check to see if there is convergence.
		if ( math::abs( newCost - currentCost ) < epsilon )
		{
			thrusts = currentThrusts;
			return newCost;
		}
		
		currentCost = newCost;
	}
	
	thrusts = currentThrusts;
	
	return currentCost;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Motor Constraint Enforcement Method
//############		
//##########################################################################################
//##########################################################################################




void Quadcopter:: constrainThrusts( const ArrayList<Motor>& motors, Array<Float>& thrusts )
{
	const Size numMotors = motors.getSize();
	
	if ( thrusts.getSize() < motors.getSize() )
		thrusts.setSize( motors.getSize() );
	
	for ( Index m = 0; m < numMotors; m++ )
	{
		const Motor& motor = motors[m];
		Float thrust = thrusts[m];
		
		thrust = math::clamp( thrust, motor.thrustRange.min, motor.thrustRange.max );
		
		thrusts[m] = thrust;
	}
}




//##########################################################################################
//##########################################################################################
//############		
//############		Thrust Cost Method
//############		
//##########################################################################################
//##########################################################################################




Float Quadcopter:: getCost( const ArrayList<Motor>& motors, const Array<Float>& thrusts,
							const Vector3f& localForce, const Vector3f& localTorque )
{
	// Weight constants for each of the terms in the cost function.
	const Float deltaWeight = 0;
	const Float linearWeight = 1.0f;
	const Float angleWeight = 0.0f;
	
	const Size numMotors = motors.getSize();
	
	//****************************************************************************
	// Compute the cost due to change in thrust.
	
	Float deltaCost = 0;
	
	for ( Index m = 0; m < numMotors; m++ )
		deltaCost += math::square( thrusts[m] - motors[m].thrust );
	
	//****************************************************************************
	// Compute the cost due to not meeting the target force/torque.
	
	Vector3f newForce;
	Vector3f newTorque;
	
	for ( Index m = 0; m < numMotors; m++ )
	{
		const Motor& motor = motors[m];
		const Float motorThrust = thrusts[m];
		Vector3f motorForce = motor.thrustDirection*motorThrust;
		
		applyForce( motor.comOffset, motorForce, newForce, newTorque );
	}
	
	Float linearCost = localForce.getDistanceToSquared( newForce );
	Float angleCost = localTorque.getDistanceToSquared( newTorque );
	
	//****************************************************************************
	// Accumulate the final weighted costs.
	
	Float cost = 0;
	cost += deltaWeight*deltaCost;
	cost += linearWeight*linearCost;
	cost += angleWeight*angleCost;
	
	return cost;
}




