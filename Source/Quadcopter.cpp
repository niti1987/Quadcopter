/*
 *  Quadcopter.cpp
 *  Quadcopter
 *
 *  Created by Carl Schissler on 10/23/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "Quadcopter.h"


const float Quadcopter:: MAX_SPEED = 7.0f;
const float Quadcopter:: MAX_TILT_ANGLE = math::degreesToRadians( 15.0f );
const float Quadcopter:: MAX_ROLL_RATE = math::degreesToRadians( 50.0f );
const float Quadcopter:: MAX_ANGLE_ERROR = math::degreesToRadians( 1.0f );
const float Quadcopter:: MAX_THRUST = 20;
const float Quadcopter:: MIN_THRUST = 1;
const float Quadcopter:: MAX_DELTA_THRUST = 20.0f;

const Vector3f Quadcopter:: VEHICLE_DELTA_THRUST = Vector3f(20, 20, 25);

const float Quadcopter:: VEHICLE_CLOSE_RANGE = 7;
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
		inertia( Matrix3f::IDENTITY ),
		planningTimestep( 0.5f ),
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
	// Determine the final acceleration due to the motors.
	/*
	Vector3f localThrust = currentState.rotateVectorToWorld( preferredThrust );
	
	Vector3f force, torque;
	
	for ( Index m = 0; m < motors.getSize(); m++ )
	{
		const Motor& motor = motors[m];
		
		// Transform the center-of mass offset into world space.
		Vector3f motorPoint = currentState.transformToWorld( motor.comOffset );
		Vector3f motorForce = currentState.rotateVectorToWorld( motor.thrustDirection*math::dot( motor.thrustDirection, localThrust ) / motors.getSize() );
		
		applyForce( motorPoint, motorForce, force, torque );
	}
	
	// Compute the inverse world-space inertia tensor (similarity transform).
	Matrix3f worldInverseInertia = newState.rotation * inertia.invert() * newState.rotation.transpose();
	
	/// Apply the motor acceleration.
	//linearAcceleration += mass > math::epsilon<Float>() ? force / mass : Vector3f();
	//linearAcceleration = Vector3f();
	//angularAcceleration += worldInverseInertia*torque;
	*/
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
	
	// Compensate in the preferred thrust for the effects of environmental forces (i.e. gravity, drag).
	preferredThrust -= externalAcceleration;
	
	// Make sure the preferred velocity is within the limits of thrust produced by the motors.
	Float preferredThrustMag = preferredThrust.getMagnitude();
	
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
	
	Matrix3f preferredRotation = computePreferredRotation( state, deltaPosition.normalize(), preferredThrust );
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


