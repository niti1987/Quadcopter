#pragma once
class Orientation
{
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
	Orientation(const Orientation&);

	/*
     * Internal use only. This should only be called by the
     * buildOrientationFromRadians function so users have a more verbosely named
     * function to describe what to pass and how it should be used.
     */
private:
	Orientation(double, double, double);

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
	static Orientation buildOrientationFromRadians(double,double, double);

	 /**
     * Returns the yaw in radians.
     * 
     * @return The rotation about the Z-axis in radians.
     */
    double getYawRadians (void);

	 /**
     * Returns the pitch in radians.
     * 
     * @return The rotation about the Y-axis in radians.
     */
    double getPitchRadians(void);

	/**
     * Returns the roll in radians.
     * 
     * @return The rotation about the X axis-in radians.
     */
    double getRollRadians(void);

//default
	Orientation(void);
	//~Orientation(void);
};

