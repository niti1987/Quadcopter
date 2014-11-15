#pragma once

//#include "vmath.h"
#include <math.h>

#include "AngularVelocity.h"
#include "Orientation.h"
#include "VehicleState.h"


#include "rim/rimEngine.h"


using namespace rim;
using namespace rim::math;


/**
 * 
 * This class has been roughly tested but due to the importance of the
 * operations in the class to the rest of the simulation system, extensive
 * testing should be performed on all of the contained functions.
 * 
 * This class contains static helper functions for calculating coordinate
 * matrices and various transformations and rotations upon them.
 * 
 * 
 * Author: Niti Madhugiri
 * 
 */

#define PI 3.1416

    /**
     * The i index for the components of a coordinate system represented as a
     * matrix.
     * 
     * \(\begin{bmatrix} xi&yi&zi\\ xj&yj&zj\\ xk&yk&zk \end{bmatrix}\)
     * 
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

	class VehicleAttitudeHelpers {


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
	public:
		static Matrix3f getAttitudeMatrix(float yawRadians,
            float pitchRadians, float rollRadians) {
        float alpha = yawRadians;
        float beta = pitchRadians;
        float gamma = rollRadians;

        float cosAlpha = cos(alpha);
        float sinAlpha = sin(alpha);
        float cosBeta = cos(beta);
        float sinBeta = sin(beta);
        float cosGamma = cos(gamma);
        float sinGamma = sin(gamma);

        float bxi = cosAlpha * cosBeta;
        float bxj = sinAlpha * cosBeta;
        float bxk = -sinBeta;

        float byi = (cosAlpha * sinBeta * sinGamma) - (sinAlpha * cosGamma);
        float byj = (sinAlpha * sinBeta * sinGamma) + (cosAlpha * cosGamma);
        float byk = cosBeta * sinGamma;

        float bzi = (cosAlpha * sinBeta * cosGamma) + (sinAlpha * sinGamma);
        float bzj = (sinAlpha * sinBeta * cosGamma) - (cosAlpha * sinGamma);
        float bzk = cosBeta * cosGamma;

		float barray[9] = {bxi, byi, bzi, bxj, byj, bzj, bxk, byk, bzk};

		//return Matrix3f(barray);

		return Matrix3f(bxi, bxj, bxk, byi, byj, byk, bzi, bzj, bzk);
    }

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
    static Vector3f getZAxisFromRadians(float yawRadians,
            float pitchRadians, float rollRadians) {
        float beta = pitchRadians;
        float gamma = rollRadians;

        float cosBeta = cos(beta);
        float sinBeta = sin(beta);
        float cosGamma = cos(gamma);
        float sinGamma = sin(gamma);

        float m20 = sinBeta;
        float m21 = cosBeta * sinGamma;
        float m22 = cosBeta * cosGamma;

        return Vector3f(m20, m21, m22);
    }

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
    static Matrix3f translateCoordinateSystemToBodyFrame(
            Matrix3f bodyAttitudeG, Matrix3f newBodyAttitudeG) {
        Matrix3f bodyAttitudeGTranspose = bodyAttitudeG.transpose();
        // Multiplies newBodyAttitudeG by bodyAttitudeGTranspose
        return bodyAttitudeGTranspose*(newBodyAttitudeG);
    }

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
    static Vector3f translateVectorToBodyFrame(Matrix3f bodyAttitudeG,
            Vector3f vectorG) {
        Matrix3f bodyAttitudeGTranspose = bodyAttitudeG.transpose();
        // Multiplies newBodyAttitudeG by bodyAttitudeGTranspose
        return bodyAttitudeGTranspose*(vectorG);
    }

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
    static Matrix3f getRotationMatrix(Matrix3f currentAttitude,
            float yawRadians, float pitchRadians, float rollRadians) {

        float alpha = yawRadians;
        float beta = pitchRadians;
        float gamma = rollRadians;

        float cosAlpha = cos(alpha);
        float sinAlpha = sin(alpha);
        float cosBeta = cos(beta);
        float sinBeta = sin(beta);
        float cosGamma = cos(gamma);
        float sinGamma = sin(gamma);

        float bxi = cosAlpha * cosBeta;
        float bxj = sinAlpha * cosBeta;
        float bxk = -sinBeta;

        float byi = (cosAlpha * sinBeta * sinGamma) - (sinAlpha * cosGamma);
        float byj = (sinAlpha * sinBeta * sinGamma) + (cosAlpha * cosGamma);
        float byk = cosBeta * sinGamma;

        float bzi = (cosAlpha * sinBeta * cosGamma) + (sinAlpha * sinGamma);
        float bzj = (sinAlpha * sinBeta * cosGamma) - (cosAlpha * sinGamma);
        float bzk = cosBeta * cosGamma;

		float barray[9] = {bxi, byi, bzi, bxj, byj, bzj,
                bxk, byk, bzk};

        Matrix3f rotationMatrix = Matrix3f(bxi, bxj, bxk, byi, byj, byk, bzi, bzj, bzk); //Matrix3f(barray);
        return rotationMatrix*(currentAttitude).transpose();

    }

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
    static Matrix3f getNewAttitudeMatrix(Matrix3f currentAttitude,
            float yawRadians, float pitchRadians, float rollRadians) {

        float alpha = yawRadians;
        float beta = pitchRadians;
        float gamma = rollRadians;

        float cosAlpha = cos(alpha);
        float sinAlpha = sin(alpha);
        float cosBeta = cos(beta);
        float sinBeta = sin(beta);
        float cosGamma = cos(gamma);
        float sinGamma = sin(gamma);

        float bxi = cosAlpha * cosBeta;
        float bxj = sinAlpha * cosBeta;
        float bxk = -sinBeta;

        float byi = (cosAlpha * sinBeta * sinGamma) - (sinAlpha * cosGamma);
        float byj = (sinAlpha * sinBeta * sinGamma) + (cosAlpha * cosGamma);
        float byk = cosBeta * sinGamma;

        float bzi = (cosAlpha * sinBeta * cosGamma) + (sinAlpha * sinGamma);
        float bzj = (sinAlpha * sinBeta * cosGamma) - (cosAlpha * sinGamma);
        float bzk = cosBeta * cosGamma;

		float barray[9] = {bxi, byi, bzi, bxj, byj, bzj,
                bxk, byk, bzk};

        Matrix3f rotationMatrix = Matrix3f(bxi, bxj, bxk, byi, byj, byk, bzi, bzj, bzk); //Matrix3f(barray);

        return rotationMatrix*(currentAttitude);
    }

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
    static Vector3f getYawPitchRollFromCoordinateSystemInRadians(
            Matrix3f newAttitude) {

        Matrix3f normalAttitude = Matrix3f();
        normalAttitude.setColumn(0, newAttitude.getColumn(0).normalize());
        normalAttitude.setColumn(1, newAttitude.getColumn(1).normalize());
        normalAttitude.setColumn(2, newAttitude.getColumn(2).normalize());

        float xi = newAttitude.get(INDEX_i, INDEX_X);
        float xj = newAttitude.get(INDEX_j, INDEX_X);
        float xk = newAttitude.get(INDEX_k, INDEX_X);
        float zk = newAttitude.get(INDEX_k, INDEX_Z);
        float yk = newAttitude.get(INDEX_k, INDEX_Y);

        float yaw = 0;
        float pitch = 0;
        float roll = 0;
        if (xi == 0 && xj > 0) {
            // can not divide by zero and if xj is positive, angle is Pi/2
            yaw = PI/2;
        } else if (xi == 0 && xj < 0) {
            // can not divide by zero and if xj is negative, angle is 3Pi/2
            yaw = 3 * PI/4;
        } else if (xj >= 0 && xi > 0) {
            // if xj and xi are positive then atan returns the correct value
            yaw = atan(xj / xi);
        } else if (xj < 0 && xi > 0) {
            // if xj is negative and xi is positive, atan returns a negative
            // angle and we want positive ones
            yaw = atan(xj / xi);
        } else {
            // if xj is negative or positive and xi is negative, atan returns an
            // angle reflected about the origin
            yaw = atan(xj / xi) + PI;
        }

        if (xk >= 0 && xi >= 0) {
            // if xk and xi are positive then asin returns the correct value
            pitch = asin(-xk);
        } else if (xk >= 0 && xi < 0) {
            // if xk is positive and xi is negative, asin returns an angle
            // reflected about the y axis
            pitch = -asin(-xk);
        } else if (xk < 0 && xi < 0) {
            // if xk is negative and xi is negative, asin returns an angle
            // reflected about the y axis
            pitch = 2*PI + asin(-xk);
        } else if (xk < 0 && xi >= 0) {
            // if xk is negative and xi is positive, asin returns a negative
            // angle and we want positive ones
            pitch = asin(-xk);
        }

        if (zk == 0 && yk > 0) {
            // can not divide by zero and if yk is positive, angle is Pi/2
            roll = PI/2;
        } else if (zk == 0 && yk < 0) {
            // can not divide by zero and if yk is negative, angle is 3Pi/2
            roll = 3 * PI/4;
        } else if (yk >= 0 && zk > 0) {
            // if yk and zk are positive then atan returns the correct value
            roll = atan(yk / zk);
        } else if (yk < 0 && zk > 0) {
            // if yk is negative and zk is positive, atan returns a negative
            // angle and we want positive ones
            roll = atan(yk / zk);
        } else {
            // if yk is negative or positive and zk is negative, atan returns an
            // angle reflected about the origin
            roll = atan(yk / zk) + PI;
        }
        return Vector3f(yaw, pitch, roll);
    }

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
    static Vector3f getPitchAndRollFromZWhenYawIsZero(Vector3f zAxis) {

        Vector3f normalizedZAxis = zAxis;
		normalizedZAxis.normalize();
        float beta = 0;
        float gamma = 0;
        if (normalizedZAxis.z == 0 && normalizedZAxis.x >= 0) {
            beta = PI/2;
        } else if (normalizedZAxis.z == 0 && normalizedZAxis.x < 0) {
            beta = -PI/2;
        } else if (normalizedZAxis.z > 0 && normalizedZAxis.x >= 0) {
            beta = (float) atan(normalizedZAxis.x / normalizedZAxis.z);
        } else if (normalizedZAxis.z > 0 && normalizedZAxis.x < 0) {
            beta = (float) atan(normalizedZAxis.x / normalizedZAxis.z);
        } else if (normalizedZAxis.z < 0 && normalizedZAxis.x >= 0) {
            beta = (float) (PI - atan(normalizedZAxis.x
                    / normalizedZAxis.z));
        } else {
            beta = (float) (-PI + atan(normalizedZAxis.x
                    / normalizedZAxis.z));
        }

        if (normalizedZAxis.y >= 0 && normalizedZAxis.z >= 0) {
            // if xk and xi are positive then asin returns the correct value
            gamma = (float) -asin(normalizedZAxis.y);
        } else if (normalizedZAxis.y >= 0 && normalizedZAxis.z < 0) {
            // if xk is positive and xi is negative, asin returns an angle
            // reflected about the y axis
            gamma = (float) (-PI + asin(normalizedZAxis.y));
        } else if (normalizedZAxis.y < 0 && normalizedZAxis.z < 0) {
            // if xk is negative and xi is negative, asin returns an angle
            // reflected about the y axis
            gamma = (float) (PI + asin(normalizedZAxis.y));
        } else {            // if xk is negative and xi is positive, asin returns a negative
            // angle and we want positive ones
            gamma = (float) (-asin(normalizedZAxis.y));
        }
        return Vector3f(0, beta, gamma);
    }



	};

