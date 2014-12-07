#pragma once

/**
 * This class represents the transformation state of the vehicle and includes fields for
 * position, <code>Orientation</code>, and velocity.
 * <p>
 * The <code>TransformState</code> is only a data holder and values within it are
 * public and may be accessed and changed by anyone with a reference. If a safe
 * copy needs to be shared be sure to provide a deep copy instead of simply
 * passing the reference.
 * </p>
 * 
 * Author: Niti Madhugiri
 * 
 */

#include "Orientation.h"
#include "AngularVelocity.h"

#include "rim/rimEngine.h"

using namespace rim;
using namespace rim::math;


class TransformState
{
    
public:
	/**
     * A <code>Vector3f</code> object containing the position of the object.
     * <ul>
     * <li>The global x coordinate is stored in <code>x</code>.</li>
     * <li>The global y coordinate is stored in <code>y</code>.</li>
     * <li>The global z coordinate is stored in <code>z</code>.</li>
     * </ul>
     */
	Vector3f position;

    /**
     * An <code>Orientation</code> object containing the roll, pitch, and yaw of
     * the object.
     * 
     * <p>
     * The roll, pitch, and yaw are accessed with their respective getters and
     * are in radians.
     * </p>
     */
    //Orientation orientation;
	
	/// A 3x3 orthonormal rotation matrix indicating the rotation from body to world space.
	Matrix3f rotation;
	
    /**
     * A <code>Vector3f</code> object containing the velocity of the object.
     * <ul>
     * <li>The global x velocity is stored in <code>x</code>.</li>
     * <li>The global y velocity is stored in <code>y</code>.</li>
     * <li>The global z velocity is stored in <code>z</code>.</li>
     * </ul>
     */
    Vector3f velocity;
	
	
	/// The angular velocity of the object in world space.
	Vector3f angularVelocity;
	
	
	
    /**
     * Blank constructor which constructs a new <code>TransformState</code> object
     * having position (0,0,0), orientation (0,0,0), and velocity, (0,0,0).
     */
    TransformState()
		:	position(),
			rotation( Matrix3f::IDENTITY ),
			velocity(),
			angularVelocity()
	{
    }
	
	
    /**
     * Constructor for building a new <code>TransformState</code> object with the
     * passed position, orientation, and velocity.
     * 
     * @param position
     *            A <code>Vector3f</code> object containing the position of the
     *            object.
     * @param orientation
     *            An <code>Orientation</code> object containing the roll, pitch,
     *            and yaw of the object.
     * @param velocity
     *            A <code>Vector3f</code> object containing the velocity of the
     *            object.
     */
    TransformState( const Vector3f& pos, const Matrix3f& rot, const Vector3f& vel, const Vector3f& angularVel )
		:	position( pos ),
			rotation( rot ),
			velocity( vel ),
			angularVelocity( angularVel )
	{
    }
	
	
	
	/// Transform a point in body space into world space.
	Vector3f transformToWorld( const Vector3f& point ) const
	{
		return position + rotation*point;
	}
	
	
	
	/// Transform a point in world space into body space.
	Vector3f transformToBody( const Vector3f& point ) const
	{
		// Reverse multiply is the same as multiply by the transpose.
		return (point - position)*rotation;
	}
	
	
	/// Rotate a vector in body space into world space.
	Vector3f rotateVectorToWorld( const Vector3f& point ) const
	{
		return rotation*point;
	}
	
	
	/// Rotate a vector in world space into body space.
	Vector3f rotateVectorToBody( const Vector3f& point ) const
	{
		// Reverse multiply is the same as multiply by the transpose.
		return point*rotation;
	}
};


