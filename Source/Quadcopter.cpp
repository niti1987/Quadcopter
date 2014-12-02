/*
 *  Quadcopter.cpp
 *  Quadcopter
 *
 *  Created by Carl Schissler on 10/23/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "Quadcopter.h"


#include "VehicleAttitudeHelpers.h"


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
	// Compute the delta vector for position between the target position and the new state position.
	Vector3f deltaPosition = nextWaypoint - newState.position;
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
	preferredThrust -= linearAcceleration;
	
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
	
	//****************************************************************************
	// Once we have the preferred acceleration, compute the target orientation that
	// the quadcopter should rotate to acheive that acceleration.
	
	Matrix3f preferredRotation = computePreferredRotation( newState, deltaPosition.normalize(), preferredThrust );
	prefRot = preferredRotation;
	
	// Compute the rotational difference between the new rotation and the target rotation.
	Quaternion<Float> qNew( newState.rotation );
	Quaternion<Float> qPref( preferredRotation );
	Quaternion<Float> deltaQ = qPref*qNew.invert();
	
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
	
	Vector3f deltaAngularVelocity = preferredAngularVelocity - newState.angularVelocity;
	Vector3f preferredAngularAcceleration = deltaAngularVelocity / planningTimestep;
	
	//****************************************************************************
	// Determine the final acceleration due to the motors.
	
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
	linearAcceleration += preferredThrust;
	angularAcceleration += preferredAngularAcceleration;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Thrust Computation Methods
//############		
//##########################################################################################
//##########################################################################################




Matrix3f rotationFromUpLook( const Vector3f& up, const Vector3f& look, const Matrix3f& oldRotation )
{
	const Float epsilon = math::degreesToRadians( 0.01f );
	const Float cosEpsilon = math::cos( epsilon );
	const Float cosTheta = math::abs(math::dot( up, look ));
	
	// Generate an orthonormal rotation matrix based on that up vector and the desired look direction.
	/*Vector3f right = cosTheta < cosEpsilon ?
						math::cross( up, oldRotation.z ).normalize() :
						math::cross( up, -look ).normalize();*/
	Vector3f right = math::cross( up, -look ).normalize();
	Vector3f back = math::cross( right, up ).normalize();
	
	return Matrix3f( right, up, back ).orthonormalize();
}




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
		if ( math::abs(math::dot( up, look )) < math::cos( 0.001f ) )
			horizontal = rotationFromUpLook( up, look, newState.rotation );
		else
			horizontal = rotationFromUpLook( up, -newState.rotation.z, newState.rotation );
		
		// Apply the quaternion to the horizontal frame to get the target rotation.
		return q.toMatrix().transpose()*horizontal;
	}
	else
	{
		// The preferred thrust vector is suitable for use as the up vector.
		up = thrustDirection;
		
		if ( math::abs(math::dot( up, look )) < math::cos( 0.001f ) )
			return rotationFromUpLook( up, look, newState.rotation );
		else
			return rotationFromUpLook( up, -newState.rotation.z, newState.rotation );
	}
}













# if 0

Vector3f Quadcopter:: getPreferredAccelerationVector( Float timeStep )
{
	/*
	 * Divide positionCorrection by its magnitude to get a unit vector
	 * \hat{\rho} and Multiply \hat{\rho} by max velocity to get
	 * newVelocityVector. This limits speed.
	 */
	Vector3f positionCorrectionVector = nextWaypoint - currentState.position;

	float vehicleCalculatedMaxSpeed = VEHICLE_MAX_SPEED_MPS;
	
	if ( positionCorrectionVector.getMagnitude() < VEHICLE_CLOSE_RANGE )
		vehicleCalculatedMaxSpeed = VEHICLE_MAX_SPEED_MPS * VEHICLE_CLOSE_RANGE_SCALE_FACTOR;
	
	Vector3f newVelocityVector = positionCorrectionVector.normalize()*vehicleCalculatedMaxSpeed;
	
	// Calculate thrust needed to correct velocity.
	Vector3f deltaVelocityVector = newVelocityVector - lastState.velocity;
	
	return deltaVelocityVector / timeStep;
}




Vector3f Quadcopter:: getZComponentOfThrustVector( const Vector3f& accelerationVector, const Vector3f& globalGravity )
{
	Vector3f thrustVector = Vector3f();
	if ( accelerationVector.z < globalGravity.z )
	{
		// If we need to accelerate downward faster than gravity, the best
		// we can do is VEHICLE_MIN_THRUST.
		thrustVector.z = VEHICLE_MIN_THRUST;
	}
	else if ( accelerationVector.z >= VEHICLE_MAX_THRUST )
	{
		// If we need to accelerate upward harder than we are capable of,
		// the best we can do is most of MAX_THRUST.
		thrustVector.z = VEHICLE_MAX_THRUST - VEHICLE_MIN_THRUST;
	}
	else
	{
		// Otherwise we have to calculate our z thrust as what we want
		// vector plus gravity vector.
		thrustVector.z = accelerationVector.z + globalGravity.z;
	}
	
	return thrustVector;
}




Vector3f Quadcopter:: calculateXAndYComponentsOfThrust( Float timeStep, const Vector3f& inputThrust, const Vector3f& accelerationVector )
{
	Vector3f thrustVector = inputThrust;
	
	// Now we know what z must be.
	// Get the R component of the desired acceleration vector.
	Vector3f rOfAcceleration = Vector3f(accelerationVector.x,
			accelerationVector.y, 0);

	// Get the amount of MAX_THRUST we have left to utilize
	float remainingThrust = math::square( VEHICLE_MAX_THRUST ) - math::square( thrustVector.z );
	float magnitudeOfThrustLeftForR = remainingThrust < 0 ? 0 : math::sqrt( remainingThrust );
	
	// Calculate components of available thrust in x and y to thrust in the
	// direction of acceleration R.
	float xComponentOfThrustRInAccelerationR = magnitudeOfThrustLeftForR * rOfAcceleration.normalize().x;
	float yComponentOfThrustRInAccelerationR = magnitudeOfThrustLeftForR * rOfAcceleration.normalize().y;
	
	// Make a thrustVectorR
	Vector3f thrustR = Vector3f( xComponentOfThrustRInAccelerationR, yComponentOfThrustRInAccelerationR, 0 );
	
	// thrustR.length() and thrustVector.z will be zero or positive from above.
	if ( math::abs( thrustVector.z ) < 0.5f ||
		 math::abs( math::atan(thrustR.getMagnitude() / thrustVector.z) ) > VEHICLE_MAX_TILT_ANGLE_RADIANS )
	{
		// If the angle phi is greater than our
		// VEHICLE_MAX_TILT_ANGLE_RADIANS, reduce the angle and deal with
		// reduced R thrust.
		float newThrustRMagnitude = math::abs(thrustVector.z) * math::tan(VEHICLE_MAX_TILT_ANGLE_RADIANS);
		thrustVector.x = thrustR.normalize().x * newThrustRMagnitude;
		thrustVector.y = thrustR.normalize().y * newThrustRMagnitude;
	}
	else
	{
		// If phi is not greater than VEHICLE_MAX_TILT_ANGLE_RADIANS, let it roll.
		thrustVector.x = thrustR.x;
		thrustVector.y = thrustR.y;
	}

	thrustVector = adjustLimitDeltaThrustVector(timeStep, thrustVector);

	return thrustVector;
}




Vector3f Quadcopter:: adjustLimitDeltaThrustVector( Float timeStep, const Vector3f& inputThurst )
{
	Vector3f thrustVector = inputThurst;
	Vector3f deltaThrust = thrustVector - (lastThrust);
	
	if ( deltaThrust.getMagnitude() / timeStep > VEHICLE_DELTA_THRUST.getMagnitude() )
	{
		deltaThrust = deltaThrust.normalize()*( VEHICLE_DELTA_THRUST*((float) timeStep) );
		thrustVector = Vector3f(lastThrust + (deltaThrust));
		
		Vector3f thrustR = Vector3f(thrustVector.x, thrustVector.y, 0);
		float maxR = thrustVector.z / sin(VEHICLE_MAX_TILT_ANGLE_RADIANS);
		
		if (thrustR.getMagnitude() > maxR)
		{
			thrustVector.x = thrustR.normalize().x * maxR;
			thrustVector.y = thrustR.normalize().y * maxR;
		}
	}
	
	return thrustVector;
}



/*
Matrix3f Quadcopter:: getNewAttitudeMatrix()
{
	float yaw = (float) currentState.orientation.getYawRadians();
	float pitch = (float) currentState.orientation.getPitchRadians();
	float roll = (float) currentState.orientation.getRollRadians();
	
	return VehicleAttitudeHelpers::getAttitudeMatrix(yaw, pitch, roll);
}
*/

/*

Vector3f Quadcopter:: calculatePreferredLinearAcceleration( Float timeStep )
{
	Vector3f lastVelocityBodyFrame = Vector3f(currentVelocityBodyFrame);
	currentVelocityBodyFrame = VehicleAttitudeHelpers::translateVectorToBodyFrame( currentAttitudeMatrix, currentState.velocity );
	
	return (currentVelocityBodyFrame - lastVelocityBodyFrame) / timeStep;
}




Vector3f Quadcopter:: calculatePreferredAngularVelocity( Float timeStep )
{
	float oldYaw = (float) lastState.orientation.getYawRadians();
	float oldPitch = (float) lastState.orientation.getPitchRadians();
	float oldRoll = (float) lastState.orientation.getRollRadians();

	VehicleAttitudeHelpers vehiclehelpers;

	Matrix3f oldAttitudeMatrix = VehicleAttitudeHelpers::getAttitudeMatrix(
			oldYaw, oldPitch, oldRoll);

	Matrix3f newAttitudeMatrixBodyFrame = VehicleAttitudeHelpers::
			translateCoordinateSystemToBodyFrame( oldAttitudeMatrix, currentAttitudeMatrix );

	// Get yaw, pitch, and roll from newAttitudeMatrixBodyFrame
	Vector3f yawPitchRollBodyFrame = vehiclehelpers
			.getYawPitchRollFromCoordinateSystemInRadians(newAttitudeMatrixBodyFrame);

	float angularVelocityX = (float) (yawPitchRollBodyFrame.z / timeStep);
	float angularVelocityY = (float) (yawPitchRollBodyFrame.y / timeStep);
	float angularVelocityZ = (float) (yawPitchRollBodyFrame.x / timeStep);
	
	
	setAngularVelocities(AngularVelocity(angularVelocityZ,
			angularVelocityY, angularVelocityX));
}

*/


#endif