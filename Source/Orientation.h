#pragma once


/**
 * Since dealing with angles is difficult and confusing enough with out trying
 * to remember if x equals Yaw or Y equals pitch, as well as wondering if the
 * angles are in degrees or radians, this class encapsulates the orientation
 * data in methods with intelligent names to facilitate ease in programming and
 * increase readability.
 * 
 * Author: Niti Madhugiri
 * 
 */
class Orientation {

    // Yaw about z, pitch, about y, roll about x : alpha, beta, gamma
private:
	double yaw;
    double pitch;
    double roll;

    /**
     * Constructs a deep copy of the passed in <code>Orientation</code>
     * 
     * @param orientationToCopy
     *            The <code>Orientation</code> to be copied.
     */
public:
	Orientation(const Orientation& orientationToCopy) {
        yaw = orientationToCopy.yaw;
        pitch = orientationToCopy.pitch;
        roll = orientationToCopy.roll;
    }

	// default constructor: roll, pitch, yaw set to 0
	Orientation(){
		yaw = 0;
		pitch = 0;
		roll = 0;
	}


    /*
     * Internal use only. This should only be called by the
     * buildOrientationFromRadians function so users have a more verbosely named
     * function to describe what to pass and how it should be used.
     */
private:
	Orientation(double yawRadians, double pitchRadians,
            double rollRadians) {
        yaw = yawRadians;
        pitch = pitchRadians;
        roll = rollRadians;
    }

    /**
     * This static build function is to help point out that the orientation
     * should be in radians instead of just being a constructor named
     * Orientation that takes some numbers but does effectively the same thing as
     * if there were a constructor taking the same parameters available..
     * 
     * @param yawRadians
     *            The rotation about the Z-axis in radians.
     * @param pitchRadians
     *            The rotation about the Y-axis in radians.
     * @param rollRadians
     *            The rotation about the X-axis in radians.
     * @return A properly constructed <code>Orientation</code> object
     */
public:
	static Orientation buildOrientationFromRadians(double yawRadians,
            double pitchRadians, double rollRadians) {
        return Orientation(yawRadians, pitchRadians, rollRadians);
    }

    /**
     * Returns the yaw in radians.
     * 
     * @return The rotation about the Z-axis in radians.
     */
    double getYawRadians() const {
        return yaw;
    }

    /**
     * Returns the pitch in radians.
     * 
     * @return The rotation about the Y-axis in radians.
     */
    double getPitchRadians() const {
        return pitch;
    }

    /**
     * Returns the roll in radians.
     * 
     * @return The rotation about the X axis-in radians.
     */
    double getRollRadians() const {
        return roll;
    }
};


