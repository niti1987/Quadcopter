#pragma once

#include "VehicleState.h"
#include "AngularVelocity.h"
#include "Orientation.h"
#include "VehicleAttitudeHelpers.h"
//#include "vmath.h"


#include "rim/rimEngine.h"


using namespace rim;
using namespace rim::math;


/**
 * This is supposed to be a "simple" rotorcraft but still have the ability to
 * test. As such a move method which adjusts attitude
 * during translation is needed. For the case of "simplicity", this craft does
 * not yaw. To move, in a given time step, the craft moves in the direction of
 * the position correction vector at its maximum velocity. To do this, it moves
 * first in the z direction with a level attitude. Next, it tilts by
 * <code>VEHICLE_MAX_TILT_ANGLE_RADIANS</code> and moves in the global xy plane.
 * <p>
 * The attitude of a spacecraft is its rotational orientation in space relative
 * to a defined reference coordinate system. Yaw, pitch, and roll angles are
 * alpha, beta, and gamma, respectively.
 * </p>
 * 
 * Author: Niti Madhugiri
 * 
 */

static float VEHICLE_MAX_SPEED_MPS = 10.0f;
static float VEHICLE_MAX_TILT_ANGLE_RADIANS = 0.26f;
static float VEHICLE_MAX_THRUST = 20;
static float VEHICLE_MIN_THRUST = 5;

static Vector3f VEHICLE_DELTA_THRUST = Vector3f(20, 20, 25);

static float VEHICLE_CLOSE_RANGE = 7;
static float VEHICLE_CLOSE_RANGE_SCALE_FACTOR = 0.2f;

static Vector3f GRAVITY_VECTOR = Vector3f(0, 0, -9.8f);

class Vehicle{

private:
	Vector3f linearAccelerations;
	AngularVelocity angularVelocities;
	Vector3f positionCorrection;
	VehicleState vehicleState;


	VehicleState lastStateGlobalFrame;
    Vector3f lastThrustVector;

    Vector3f currentVelocityBodyFrame;


public:
	/**
     * This constructor builds a new <code>SimpleMultiRotoCopter</code>. It
     * takes a <code>VehicleState</code> which places it in its proper location
     * and orientation in space as well as a starting velocity.
     * 
     * @param startingState
     *            A <code>VehicleState</code> representing the craft's starting
     *            state.
     */
    Vehicle(VehicleState startingState) {
       
		linearAccelerations = Vector3f();
        angularVelocities = AngularVelocity();
        positionCorrection = Vector3f();
        vehicleState = VehicleState();
        setVehicleState(vehicleState.deepCopy(startingState));


        lastStateGlobalFrame.deepCopy(startingState);
        lastThrustVector = Vector3f(GRAVITY_VECTOR*(-1));

		float yaw = (float) getVehicleState().orientation.getYawRadians();
        float pitch = (float) getVehicleState().orientation.getPitchRadians();
        float roll = (float) getVehicleState().orientation.getRollRadians();

		VehicleAttitudeHelpers vehiclehelpers;

		currentVelocityBodyFrame = vehiclehelpers
                .translateVectorToBodyFrame(vehiclehelpers
                        .getAttitudeMatrix(yaw, pitch, roll),
                        getVehicleState().velocity);


	}


	Vector3f getLinearAccelerations() {
		Vector3f returnAccelerations = Vector3f();
		
			returnAccelerations.x = linearAccelerations.x;
			returnAccelerations.y = linearAccelerations.y;
			returnAccelerations.z = linearAccelerations.z;
			return returnAccelerations;
	}


	Vector3f getGravityVector() {
		Vector3f gravityBodyFrame = Vector3f();
		
			float yaw = (float) getVehicleState().orientation.getYawRadians();
			float pitch = (float) getVehicleState().orientation.getPitchRadians();
			float roll = (float) getVehicleState().orientation.getRollRadians();

			VehicleAttitudeHelpers vehiclehelpers;

			gravityBodyFrame = vehiclehelpers
					.translateVectorToBodyFrame(vehiclehelpers
							.getAttitudeMatrix(yaw, pitch, roll),
							GRAVITY_VECTOR);
		
		return gravityBodyFrame;
	}


	Vector3f getCurrentPosition() {
		Vector3f returnCurrentPosition = Vector3f();
		
			returnCurrentPosition.x = vehicleState.position.x;
			returnCurrentPosition.y = vehicleState.position.y;
			returnCurrentPosition.z = vehicleState.position.z;
		
		return returnCurrentPosition;
	}

	
	AngularVelocity getAngularVelocities() {
		AngularVelocity returnAngularVelocities = AngularVelocity();
		
			returnAngularVelocities = AngularVelocity(angularVelocities);
		
		return returnAngularVelocities;
	}


	Vector3f getNegativeZAxis() {
		Vector3f returnNegativeZAxis = Vector3f();
		
			float yaw = (float) vehicleState.orientation.getYawRadians();
			float pitch = (float) vehicleState.orientation.getPitchRadians();
			float roll = (float) vehicleState.orientation.getRollRadians();

			VehicleAttitudeHelpers vehiclehelpers;

			returnNegativeZAxis = vehiclehelpers
					.getAttitudeMatrix(yaw, pitch, roll)
					.getColumn(vehiclehelpers.INDEX_Z)*(-1);
		
		return returnNegativeZAxis;
	}


	VehicleState getVehicleState() {
		VehicleState returnVehicleState = VehicleState();
		
			returnVehicleState = returnVehicleState.deepCopy(vehicleState);
		
		return returnVehicleState;
	}


	protected:
		Vector3f getPositionCorrection() {
		Vector3f returnPositionCorrection = Vector3f();
		
			returnPositionCorrection.x = positionCorrection.x;
			returnPositionCorrection.y = positionCorrection.y;
			returnPositionCorrection.z = positionCorrection.z;
		
		return returnPositionCorrection;
	}


	public:
		void setPositionCorrection(Vector3f newPositionCorrection) {
		
			positionCorrection.x = newPositionCorrection.x;
			positionCorrection.y = newPositionCorrection.y;
			positionCorrection.z = newPositionCorrection.z;
		
	}


	protected:
		void setLinearAccelerations(Vector3f newLinearAccelerations) {
		
			linearAccelerations.x = newLinearAccelerations.x;
			linearAccelerations.y = newLinearAccelerations.y;
			linearAccelerations.z = newLinearAccelerations.z;
		
	}


	void setAngularVelocities(AngularVelocity newAngularVelocity) {
		
			angularVelocities = AngularVelocity(newAngularVelocity);
		
	}

	void setVehicleState(VehicleState newVehicleState) {
		
			vehicleState.deepCopy(newVehicleState);
		
	}



	public:
		void move(double timeStep) {
        // Save current state as last state
        lastStateGlobalFrame.deepCopy(getVehicleState());
        Vector3f accelerationVector = getAccelerationVector(timeStep);
        Vector3f thrustVector = setZComponentOfThrustVector(accelerationVector);
        thrustVector = calculateXAndYComponentsOfThrust(timeStep, thrustVector,
                accelerationVector);
        lastThrustVector = thrustVector;
        setNewVelocity(timeStep, thrustVector);
        setNewPosition(timeStep);
        setNewOrientation(thrustVector);
        Matrix3f currentAttitudeMatrix = getNewAttitudeMatrix();
        calculateNewLinearAccelerations(timeStep, currentAttitudeMatrix);
        calculateAngularVelocities(timeStep, currentAttitudeMatrix);
		}


		/*
     * This helper method calculates and returns the desired acceleration vector
     * which would correct the vehicle's velocity vector.
     * 
     * @param timeStep The time step in seconds of this move step.
     * 
     * @return A Vector3f of the desired acceleration vector.
     */
	private:
		Vector3f getAccelerationVector(double timeStep) {
        /*
         * Divide positionCorrection by its magnitude to get a unit vector
         * \hat{\rho} and Multiply \hat{\rho} by max velocity to get
         * newVelocityVector. This limits speed.
         */
        Vector3f positionCorrectionVector = getPositionCorrection();

        float vehicleCalculatedMaxSpeed = VEHICLE_MAX_SPEED_MPS;
        if (positionCorrectionVector.getMagnitude() < VEHICLE_CLOSE_RANGE) {
            vehicleCalculatedMaxSpeed = VEHICLE_MAX_SPEED_MPS
                    * VEHICLE_CLOSE_RANGE_SCALE_FACTOR;
        }

        Vector3f newVelocityVector = positionCorrectionVector.normalize()*(
                vehicleCalculatedMaxSpeed);

        // Calculate thrust needed to correct velocity.
        Vector3f deltaVelocityVector = newVelocityVector
                - (lastStateGlobalFrame.velocity);

        return deltaVelocityVector/((float) timeStep);
    }


/*
     * This helper method calculates sets the Z component of the thrust vector
     * as not crashing to the Earth is of most importance.
     * 
     * @param accelerationVector The desired acceleration vector.
     * 
     * @return A Vector3f object containing only the Z component of the vehicles
     * new thrust vector.
     */
    Vector3f setZComponentOfThrustVector(Vector3f accelerationVector) {
        Vector3f thrustVector = Vector3f();
        if (accelerationVector.z < GRAVITY_VECTOR.z) {
            // If we need to accelerate downward faster than gravity, the best
            // we can do is VEHICLE_MIN_THRUST.
            thrustVector.z = VEHICLE_MIN_THRUST;
        } else if (accelerationVector.z >= VEHICLE_MAX_THRUST) {
            // If we need to accelerate upward harder than we are capable of,
            // the best we can do is most of MAX_THRUST.
            thrustVector.z = VEHICLE_MAX_THRUST - VEHICLE_MIN_THRUST;
        } else {
            // Otherwise we have to calculate our z thrust as what we want
            // vector plus gravity vector.
            thrustVector.z = accelerationVector.z + GRAVITY_VECTOR.z;
        }
        return thrustVector;
    }


	/*
     * This helper method calculates sets the X and Y component of the thrust
     * vector but does not allow the craft to tilt by more than the crafts
     * VEHICLE_MAX_TILT_ANGLE_RADIANS. If there is not enough thrust available
     * to achieve the desired acceleration, the X and Y components are scaled
     * such that the acceleration is in the correct direction but not the
     * correct amount.
     * 
     * @param thrustVector The current thrustVector which should only have a the
     * Z component set at this time.
     * 
     * @param accelerationVector The desired acceleration vector.
     * 
     * @return A Vector3f object containing only the final new thrust vector of
     * the vehicle.
     */
    Vector3f calculateXAndYComponentsOfThrust(double timeStep,
            Vector3f thrustVector, Vector3f accelerationVector) {

        // Now we know what z must be.
        // Get the R component of the desired acceleration vector.
        Vector3f rOfAcceleration = Vector3f(accelerationVector.x,
                accelerationVector.y, 0);

        // Get the amount of MAX_THRUST we have left to utilize
        float value = (VEHICLE_MAX_THRUST * VEHICLE_MAX_THRUST)
                - (thrustVector.z * thrustVector.z);
        if (value < 0) {
            value = 0;
        }
        float magnitudeOfThrustLeftForR = (float) sqrt(value);

        // Calculate components of available thrust in x and y to thrust in the
        // direction of acceleration R.
        float xComponentOfThrustRInAccelerationR = magnitudeOfThrustLeftForR
                * rOfAcceleration.normalize().x;
        float yComponentOfThrustRInAccelerationR = magnitudeOfThrustLeftForR
                * rOfAcceleration.normalize().y;

        // Make a thrustVectorR
        Vector3f thrustR = Vector3f(xComponentOfThrustRInAccelerationR,
                yComponentOfThrustRInAccelerationR, 0);

        // thrustR.length() and thrustVector.z will be zero or positive from
        // above.

        if (abs(thrustVector.z) < 0.5
                || abs(atan(thrustR.getMagnitude() / thrustVector.z)) > VEHICLE_MAX_TILT_ANGLE_RADIANS) {
            // If the angle phi is greater than our
            // VEHICLE_MAX_TILT_ANGLE_RADIANS, reduce the angle and deal with
            // reduced R thrust.
            float newThrustRMagnitude = (float) (abs(thrustVector.z) *tan(VEHICLE_MAX_TILT_ANGLE_RADIANS));
            thrustVector.x = thrustR.normalize().x * newThrustRMagnitude;
            thrustVector.y = thrustR.normalize().y * newThrustRMagnitude;
        } else {
            // If phi is not greater than VEHICLE_MAX_TILT_ANGLE_RADIANS, let it
            // roll.
            thrustVector.x = thrustR.x;
            thrustVector.y = thrustR.y;
        }

        thrustVector = adjustLimitDeltaThrustVector(timeStep, thrustVector);

        return thrustVector;
    }


	/*
     * This helper method helps stop the jerky motion of the copter and makes it
     * such that it must slowly change from one direction to another.
     * 
     * @param timeStep
     *            The number of seconds in this time step.
     * @param thrustVector
     *            A <code>Vector3f</code> object representing the currently
     *            calculated thrust.
     * @return The adjusted thrustVector.
     */
    Vector3f adjustLimitDeltaThrustVector(double timeStep,
            Vector3f thrustVector) {

        Vector3f deltaThrust = thrustVector - (lastThrustVector);
        if (deltaThrust.getMagnitude() / timeStep > VEHICLE_DELTA_THRUST.getMagnitude()) {
            deltaThrust = deltaThrust.normalize()*(
                    VEHICLE_DELTA_THRUST*((float) timeStep));
            thrustVector = Vector3f(lastThrustVector + (deltaThrust));
            Vector3f thrustR = Vector3f(thrustVector.x, thrustVector.y, 0);
            float maxR = thrustVector.z
                    / sin(VEHICLE_MAX_TILT_ANGLE_RADIANS);
            if (thrustR.getMagnitude() > maxR) {
                thrustVector.x = thrustR.normalize().x * maxR;
                thrustVector.y = thrustR.normalize().y * maxR;
            }
        }
        return thrustVector;
    }


	 /*
     * This helper method sets the currentStateGlobalFrame's new velocity.
     * 
     * @param timeStep
     *            The time step in seconds of this move step.
     * @param thrustVector
     *            The thrust vector of the vehicle.
     */
    void setNewVelocity(double timeStep, Vector3f thrustVector) {
        VehicleState newState = VehicleState();
		newState.deepCopy(getVehicleState());
        newState.velocity.x += (float) ((thrustVector.x + GRAVITY_VECTOR.x) * timeStep);
        newState.velocity.y += (float) ((thrustVector.y + GRAVITY_VECTOR.y) * timeStep);
        newState.velocity.z += (float) ((thrustVector.z + GRAVITY_VECTOR.z) * timeStep);
        setVehicleState(newState);
    }

	/*
     * This helper method sets the currentStateGlobalFrame's new position.
     * 
     * @param timeStep
     *            The time step in seconds of this move step.
     */
    void setNewPosition(double timeStep) {
        VehicleState newState = VehicleState();
		newState.deepCopy(getVehicleState());

        newState.position.x += (float) ((newState.velocity.x) * timeStep);
        newState.position.y += (float) ((newState.velocity.y) * timeStep);
        newState.position.z += (float) ((newState.velocity.z) * timeStep);

        setVehicleState(newState);
    }


	/*
     * This helper method calculates sets the new orientation in the global
     * frame and stores it in the currentStateGlobalFrame's orientation.
     * 
     * @param thrustVector
     *            The thrust vector of the vehicle.
     */
    void setNewOrientation(Vector3f thrustVector) {
        Vector3f positiveZAxis = Vector3f(thrustVector);
        if (positiveZAxis.z < 0) {
            positiveZAxis = positiveZAxis*(-1);
        }

		VehicleAttitudeHelpers vehiclehelpers;

        Vector3f yawPitchRollGlobalFrame = vehiclehelpers
                .getPitchAndRollFromZWhenYawIsZero(positiveZAxis);

        VehicleState newState = VehicleState();
		newState.deepCopy(getVehicleState());

        newState.orientation.buildOrientationFromRadians(
                yawPitchRollGlobalFrame.x, yawPitchRollGlobalFrame.y,
                yawPitchRollGlobalFrame.z);

        setVehicleState(newState);
    }


	 /*
     * This helper method gets the new attitude coordinate system from the
     * currentStateGlobalFrame's orientation's yaw, pitch and roll values
     * 
     * @return A Matrix3f representing the vehicles attitude in the global
     *         frame.
     */
    Matrix3f getNewAttitudeMatrix() {

        float yaw = (float) getVehicleState().orientation.getYawRadians();
        float pitch = (float) getVehicleState().orientation.getPitchRadians();
        float roll = (float) getVehicleState().orientation.getRollRadians();

		VehicleAttitudeHelpers vehiclehelpers;

        return vehiclehelpers.getAttitudeMatrix(yaw, pitch, roll);
    }

	/*
     * This helper method calculates the linear accelerations on the body frame
     * of the vehicle and stores them in the linearAccelerationsBodyFrame
     * variable.
     * 
     * @param timeStep
     *            The time step in seconds of this move step.
     * @param currentAttitudeMatrix
     *            The current coordinate system representing the vehicles
     *            attitude.
     */
    void calculateNewLinearAccelerations(double timeStep,
            Matrix3f currentAttitudeMatrix) {
        Vector3f lastVelocityBodyFrame = Vector3f(currentVelocityBodyFrame);

		VehicleAttitudeHelpers vehiclehelpers;

        currentVelocityBodyFrame = vehiclehelpers
                .translateVectorToBodyFrame(currentAttitudeMatrix,
                        getVehicleState().velocity);

        float linearAccelInX = (float) ((currentVelocityBodyFrame.x - lastVelocityBodyFrame.x) / timeStep);
        float linearAccelInY = (float) ((currentVelocityBodyFrame.y - lastVelocityBodyFrame.y) / timeStep);
        float linearAccelInZ = (float) ((currentVelocityBodyFrame.z - lastVelocityBodyFrame.z) / timeStep);

        setLinearAccelerations(Vector3f(linearAccelInX, linearAccelInY,
                linearAccelInZ));
    }


	 /*
     * This helper method calculates the angular velocities on the body frame of
     * the vehicle and stores them in the angularVelocitiesBodyFrame variable.
     * 
     * @param timeStep
     *            The time step in seconds of this move step.
     * @param currentAttitudeMatrix
     *            The current coordinate system representing the vehicles
     *            attitude.
     */
    void calculateAngularVelocities(double timeStep,
            Matrix3f currentAttitudeMatrix) {
        float oldYaw = (float) lastStateGlobalFrame.orientation.getYawRadians();
        float oldPitch = (float) lastStateGlobalFrame.orientation
                .getPitchRadians();
        float oldRoll = (float) lastStateGlobalFrame.orientation
                .getRollRadians();

		VehicleAttitudeHelpers vehiclehelpers;

        Matrix3f oldAttitudeMatrix = vehiclehelpers.getAttitudeMatrix(
                oldYaw, oldPitch, oldRoll);

        Matrix3f newAttitudeMatrixBodyFrame = vehiclehelpers
                .translateCoordinateSystemToBodyFrame(oldAttitudeMatrix,
                        currentAttitudeMatrix);

        // Get yaw, pitch, and roll from newAttitudeMatrixBodyFrame
        Vector3f yawPitchRollBodyFrame = vehiclehelpers
                .getYawPitchRollFromCoordinateSystemInRadians(newAttitudeMatrixBodyFrame);

        float angularVelocityX = (float) (yawPitchRollBodyFrame.z / timeStep);
        float angularVelocityY = (float) (yawPitchRollBodyFrame.y / timeStep);
        float angularVelocityZ = (float) (yawPitchRollBodyFrame.x / timeStep);

        setAngularVelocities(AngularVelocity(angularVelocityZ,
                angularVelocityY, angularVelocityX));

	}



};


