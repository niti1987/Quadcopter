#pragma once

/**
 * Since dealing with angles is difficult and confusing enough with out trying
 * to remember if x equals Yaw or Y equals pitch, as well as wondering if the
 * angles are in degrees or radians, this class encapsulates the angular
 * velocity data in methods with intelligent names to facilitate ease in
 * programming and increase readability.
 * 
 * Author: Niti Madhugiri
 * 
 */


class AngularVelocity {

	// YawRate about z, pitchRate, about y, rollRate about x : alpha, beta,
	// gamma
private:
	double yawRate;
	double pitchRate;
	double rollRate;

	/**
	 * Constructs a new <code>AngularVelocity</code> object with all rates set to zero.
	 */
public:
	AngularVelocity() {
		yawRate = 0;
		pitchRate = 0;
		rollRate = 0;
	}

    /**
	 * Constructs a copy of the passed <code>AngularVelocity</code>.
	 * 
	 * @param angularVelocityToCopy
	 *            The <code>AngularVelocity</code> to copy.
	 */
	AngularVelocity(const AngularVelocity& angularVelocityToCopy) {
		yawRate = angularVelocityToCopy.getYawRateRadians();
		pitchRate = angularVelocityToCopy.getPitchRateRadians();
		rollRate = angularVelocityToCopy.getRollRateRadians();
	}

	/**
	 * Constructs a new <code>AngularVelocity</code> with the values passed.
	 * <p>
	 * <FONT COLOR="117711">Attention!</FONT><br>
	 * All angles are in radians.
	 * </p>
	 * 
	 * @param yawRateRadians
	 *            The rotation rate about the Z-axis in radians per second.
	 * @param pitchRateRadians
	 *            The rotation rate about the Y-axis in radians per second.
	 * @param rollRateRadians
	 *            The rotation rate about the X-axis in radians per second.
	 */
	AngularVelocity(double yawRateRadians, double pitchRateRadians,
			double rollRateRadians) {
		yawRate = yawRateRadians;
		pitchRate = pitchRateRadians;
		rollRate = rollRateRadians;
	}


	/**
	 * Returns the yaw rate in radians.
	 * 
	 * @return The rotation rate about the Z-axis in radians per second.
	 */
	double getYawRateRadians() const {
		return yawRate;
	}

	/**
	 * Returns the pitch rate in radians.
	 * 
	 * @return The rotation rate about the Y axis in radians per second.
	 */
	double getPitchRateRadians() const {
		return pitchRate;
	}

	/**
	 * Returns the roll rate in radians.
	 * 
	 * @return The rotation rate about the X axis in radians per second.
	 */
	double getRollRateRadians() const {
		return rollRate;
	}


};


