#pragma once

/**
 * This class represents the state of the vehicle and includes fields for
 * position, <code>Orientation</code>, and velocity.
 * <p>
 * The <code>VehicleState</code> is only a data holder and values within it are
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


class VehicleState {
    /**
     * A <code>Vector3f</code> object containing the position of the object.
     * <ul>
     * <li>The global x coordinate is stored in <code>x</code>.</li>
     * <li>The global y coordinate is stored in <code>y</code>.</li>
     * <li>The global z coordinate is stored in <code>z</code>.</li>
     * </ul>
     */
public:
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
	Vector3f orientation;

    /**
     * A <code>Vector3f</code> object containing the velocity of the object.
     * <ul>
     * <li>The global x velocity is stored in <code>x</code>.</li>
     * <li>The global y velocity is stored in <code>y</code>.</li>
     * <li>The global z velocity is stored in <code>z</code>.</li>
     * </ul>
     */
    Vector3f velocity;

    /**
     * Blank constructor which constructs a new <code>VehicleState</code> object
     * having position (0,0,0), orientation (0,0,0), and velocity, (0,0,0).
     */
    VehicleState() {
        position = Vector3f();
        orientation = Vector3f();//Orientation();
        velocity = Vector3f();
		
    }

    /**
     * Constructor for building a new <code>VehicleState</code> object with the
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
    VehicleState(Vector3f pos, Vector3f ori,
            Vector3f vel) {
        position = pos;
        orientation = ori;
        velocity = vel;
    }

    /**
     * This function produces a safe deep copy of the <code>VehicleState</code>
     * object passed.
     * 
     * @param state
     *            The <code>VehicleState</code> object to be copied.
     * @return A new <code>VehicleState</code> object identical to the passed
     *         object.
     */
    static VehicleState deepCopy(VehicleState state) {
        Vector3f pos = Vector3f(state.position.x,
                state.position.y, state.position.z);
		Vector3f ori = Vector3f(state.orientation.x,
                state.orientation.y, state.orientation.z);
        //Orientation ori = Orientation(state.orientation);
        Vector3f vel = Vector3f(state.velocity.x,
                state.velocity.y, state.velocity.z);
        return VehicleState(pos, ori, vel);
    }
};


