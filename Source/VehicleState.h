#pragma once

#include "Orientation.h"

#include "AngularVelocity.h"

//#include "vmath.h"


#include "rim/rimEngine.h"
#include "rim/rimGraphicsGUI.h"


using namespace rim;
using namespace rim::graphics;
using namespace rim::graphics::gui;
using namespace rim::engine;

class VehicleState
{
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
    Orientation orientation;

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
    VehicleState(void);

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
    VehicleState(Vector3f, Orientation, Vector3f);

	/**
     * This function produces a safe deep copy of the <code>VehicleState</code>
     * object passed.
     * 
     * @param state
     *            The <code>VehicleState</code> object to be copied.
     * @return A new <code>VehicleState</code> object identical to the passed
     *         object.
     */
    static VehicleState deepCopy(VehicleState);


	//~Vehicle(void);
};

