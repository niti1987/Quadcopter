#pragma once
class AngularVelocity
{

	// YawRate about z, pitchRate, about y, rollRate about x : alpha, beta,
	// gamma
private:
	double yawRate;
	double pitchRate;
	double rollRate;

public:

	/**
	 * Constructs a new <code>AngularVelocity</code> object with all rates set to zero.
	 */
	AngularVelocity(void);

	/**
	 * Constructs a copy of the passed <code>AngularVelocity</code>.
	 * 
	 * @param angularVelocityToCopy
	 *            The <code>AngularVelocity</code> to copy.
	 */
	AngularVelocity(AngularVelocity);

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
	AngularVelocity(double, double, double);

	/**
	 * Returns the yaw rate in radians.
	 * 
	 * @return The rotation rate about the Z-axis in radians per second.
	 */
	double getYawRateRadians(void);

	/**
	 * Returns the pitch rate in radians.
	 * 
	 * @return The rotation rate about the Y axis in radians per second.
	 */
	double getPitchRateRadians(void);

	/**
	 * Returns the roll rate in radians.
	 * 
	 * @return The rotation rate about the X axis in radians per second.
	 */
	double getRollRateRadians(void);


	//~AngularVelocity(void);
};

