#pragma once


#include "vmath.h"

#include <math.h>

#include "AngularVelocity.h"
#include "Orientation.h"
#include "VehicleState.h"

#define PI 3.1416

/**
     * The i index for the components of a coordinate system represented as a
     * matrix.
     * <p>
     * \(\begin{bmatrix} xi&yi&zi\\ xj&yj&zj\\ xk&yk&zk \end{bmatrix}\)
     * </p>
     */

	static int INDEX_i = 0;

    /**
     * The j index for the components of a coordinate system represented as a
     * matrix.
     * <p>
     * \(\begin{bmatrix} xi&yi&zi\\ xj&yj&zj\\ xk&yk&zk \end{bmatrix}\)
     * </p>
     */
    static int INDEX_j = 1;

    /**
     * The k index for the components of a coordinate system represented as a
     * matrix.
     * <p>
     * \(\begin{bmatrix} xi&yi&zi\\ xj&yj&zj\\ xk&yk&zk \end{bmatrix}\)
     * </p>
     */
    static int INDEX_k = 2;

    /**
     * The x index for the components of a coordinate system represented as a
     * matrix.
     * <p>
     * \(\begin{bmatrix} xi&yi&zi\\ xj&yj&zj\\ xk&yk&zk \end{bmatrix}\)
     * </p>
     */
    static int INDEX_X = 0;

    /**
     * The y index for the components of a coordinate system represented as a
     * matrix.
     * <p>
     * \(\begin{bmatrix} xi&yi&zi\\ xj&yj&zj\\ xk&yk&zk \end{bmatrix}\)
     * </p>
     */
    static int INDEX_Y = 1;

    /**
     * The z index for the components of a coordinate system represented as a
     * matrix.
     * <p>
     * \(\begin{bmatrix} xi&yi&zi\\ xj&yj&zj\\ xk&yk&zk \end{bmatrix}\)
     * </p>
     */
    static int INDEX_Z = 2;



class VehicleAttitudeHelpers
{
public:

	/**
     * This function translates yaw, pitch, and roll angles to a
     * <code>Matrix3f</code> representing the X, Y, and Z-axis attitude of a
     * vehicle. Rotations are performed, roll, then pitch, and finally yaw.
     * 
     * <p>
     * \(\begin{bmatrix} xi&yi&zi\\ xj&yj&zj\\ xk&yk&zk \end{bmatrix}\)
     * </p>
     * 
     * @param yawRadians
     *            The angle in radians of rotation about the Z-axis.
     * @param pitchRadians
     *            The angle in radians of rotation about the Y-axis.
     * @param rollRadians
     *            The angle in radians of rotation about the X-axis.
     * @return A <code>Matrix3f</code> representation of the body frame
     *         coordinate system that coincides with the passed yaw, pitch, and
     *         roll.
     */

	static Matrix3f getAttitudeMatrix(float,float, float);

	/**
     * This function returns a <code>Vector3f</code> of the Z-axis of the
     * coordinate system defined by the yaw, pitch, and roll angles passed.
     * 
     * @param yawRadians
     *            The angle in radians of rotation about the Z-axis.
     * @param pitchRadians
     *            The angle in radians of rotation about the Y-axis.
     * @param rollRadians
     *            The angle in radians of rotation about the X-axis.
     * @return <code>Vector3f</code> representation of the Z-axis of the
     *         coordinates system defined by the angles passed
     */
    static Vector3f getZAxisFromRadians(float, float, float); 

	/**
     * This function translates a coordinate system defined in the global
     * reference frame to the coordinate system passed in's frame.
     * <p>
     * The <code>Matrix3f</code> objects represent the X, Y, and Z-axis of a
     * coordinate system.
     * </p>
     * <p>
     * \(\begin{bmatrix} xi&yi&zi\\ xj&yj&zj\\ xk&yk&zk \end{bmatrix}\)
     * </p>
     * 
     * @param bodyAttitudeG
     *            A <code>Matrix3f</code> of the current body attitude in the
     *            Global reference frame.
     * @param newBodyAttitudeG
     *            A <code>Matrix3f</code> of the target body attitude in the
     *            Global reference frame.
     * @return A <code>Matrix3f</code> of the newBodyAttitude in the Body frame.
     */
    static Matrix3f translateCoordinateSystemToBodyFrame(Matrix3f, Matrix3f);

	/**
     * This function translates a <code>Vector3f</code> defined in the global
     * reference frame to the coordinate system passed in's frame represented as
     * a <code>Matrix3f</code> object.
     * 
     * <p>
     * The <code>Matrix3f</code> object represents the X, Y, and Z-axis of a
     * coordinate system as follows,
     * </p>
     * <p>
     * \(\begin{bmatrix} xi&yi&zi\\ xj&yj&zj\\ xk&yk&zk \end{bmatrix}\)
     * </p>
     * 
     * @param bodyAttitudeG
     *            A <code>Matrix3f</code> of the current body attitude in the
     *            Global reference frame.
     * @param vectorG
     *            The <code>Vector3f</code> to be translated to the passed body
     *            frame.
     * @return The <code>Vector3f</code> vectorG in the Body frame.
     */
    static Vector3f translateVectorToBodyFrame(Matrix3f,Vector3f);

	/**
     * This function takes a <code>Matrix3f</code> object representing an
     * orientation and returns a rotation matrix that should be applied the
     * identity matrix to achieve the new orientation represented by applying
     * the roll, then pitch, and finally yaw to the original orientation.
     * <p>
     * The currentAttitude <code>Matrix3f</code> represent the X, Y, and Z-axis
     * of a body coordinate system in the global frame.
     * </p>
     * <p>
     * \(\begin{bmatrix} xi&yi&zi\\ xj&yj&zj\\ xk&yk&zk \end{bmatrix}\)
     * </p>
     * 
     * @param currentAttitude
     *            A <code>Matrix3f</code> representing the X, Y, and Z-axis of a
     *            body coordinate system in the global frame.
     * @param yawRadians
     *            The radians of rotation to apply about the Z-axis to the
     *            currentAttitude.
     * @param pitchRadians
     *            The radians of rotation to apply about the Y-axis to the
     *            currentAttitude.
     * @param rollRadians
     *            The radians of rotation to apply about the X-axis to the
     *            currentAttitude.
     * @return A new <code>Matrix3f</code> rotation matrix which if applied to
     *         the identity matrix will result in the new attitude.
     */
    static Matrix3f getRotationMatrix(Matrix3f,float, float, float);

	/**
     * This function takes a <code>Matrix3f</code> object representing an
     * orientation and returns a new matrix that represents the new attitude by
     * applying the roll, then pitch, and finally yaw to the original
     * orientation.
     * <p>
     * The currentAttitude <code>Matrix3f</code> represent the X, Y, and Z-axis
     * of a body coordinate system in the global frame.
     * </p>
     * <p>
     * \(\begin{bmatrix} xi&yi&zi\\ xj&yj&zj\\ xk&yk&zk \end{bmatrix}\)
     * </p>
     * 
     * @param currentAttitude
     *            A <code>Matrix3f</code> representing the X, Y, and Z-axis of a
     *            body coordinate system in the global frame.
     * @param yawRadians
     *            The radians of rotation to apply about the Z-axis to the
     *            currentAttitude.
     * @param pitchRadians
     *            The radians of rotation to apply about the Y-axis to the
     *            currentAttitude.
     * @param rollRadians
     *            The radians of rotation to apply about the X-axis to the
     *            currentAttitude.
     * @return A new <code>Matrix3f</code> that represents the new attitude by
     *         applying the <code>rollRadians</code>, then
     *         <code>pitchRadians</code>, and finally <code>yawRadians</code> to
     *         the original orientation.
     */
    static Matrix3f getNewAttitudeMatrix(Matrix3f,float, float , float );

	/**
     * <FONT COLOR="DC143C">WARNING!</FONT><br>
     * TEST THIS FUNCTION
     * <p>
     * This function returns a <code>Vector3f</code> object containing the yaw,
     * pitch, and roll angles given a new coordinate system from the global
     * system.
     * <ul>
     * <li>The yaw is stored in the <code>x</code> variable.</li>
     * <li>The pitch is stored in the <code>y</code> variable.</li>
     * <li>The roll is stored in the <code>z</code> variable.</li>
     * </ul>
     * </p>
     * 
     * @param newAttitude
     *            A <code>Matrix3f</code> representing the X, Y, and Z-axis of a
     *            body coordinate system in the global frame.
     * @return A <code>Vector3f</code> containing the yaw in radians in the
     *         <code>x</code> value, the pitch in radians in the <code>y</code>
     *         value, and the roll in radians in the<code> z</code> value.
     */
    static Vector3f getYawPitchRollFromCoordinateSystemInRadians(Matrix3f );

	/**
     * <FONT COLOR="DC143C">WARNING!</FONT><br>
     * This function may be wrong. It should be tested throughly.
     * <p>
     * This function returns the pitch and roll angles necessary to achieve the
     * given Z-axis if the yaw angle is fixed at zero.
     * </p>
     * @param zAxis
     *            The Z-axis which defines the new attitude
     * @return A Vector3f that contains zero in the x variable, the pitch angle
     *         in radians in the y variable, and the roll angle in radians in
     *         the z variable.
     */
    static Vector3f getPitchAndRollFromZWhenYawIsZero(Vector3f);

	//VehicleAttitudeHelpers(void);
	//~VehicleAttitudeHelpers(void);
};

