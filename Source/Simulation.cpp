/*
 *  Simulation.cpp
 *  Quadcopter
 *
 *  Created by Carl Schissler on 11/20/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "Simulation.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Constructor
//############		
//##########################################################################################
//##########################################################################################



Simulation:: Simulation()
	:	gravity( 0, -9.81, 0 )
{
}




//##########################################################################################
//##########################################################################################
//############		
//############		Update Method
//############		
//##########################################################################################
//##########################################################################################



void Simulation:: update( Float dt )
{
	integrateRK4( dt );
	//integrateSemiImplicitEuler( dt );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Semi-Implicite Euler Integration Method
//############		
//##########################################################################################
//##########################################################################################




void Simulation:: integrateSemiImplicitEuler( Float dt )
{
	// Update the simulation state of each quadcopter.
	const Size numQuadcopters = quadcopters.getSize();
	
	for ( Index i = 0; i < numQuadcopters; i++ )
	{
		Quadcopter& quadcopter = *quadcopters[i];
		TransformState& state = quadcopter.currentState;
		
		const Vector3f& position = state.position;
		const Vector3f& velocity = state.velocity;
		const Matrix3f& rotation = state.rotation;
		const Vector3f& angularVelocity = state.angularVelocity;
		
		//****************************************************************
		
		// Compute the linear and angular acceleration.
		Vector3f acceleration;
		Vector3f angularAcceleration;
		computeAcceleration( quadcopter, dt, position, velocity, rotation, angularVelocity,
							acceleration, angularAcceleration );
		
		// Integrate acceleration to velocity.
		state.velocity += acceleration*dt;
		state.angularVelocity += angularAcceleration*dt;
		
		// Integrate velocity to position.
		state.position += state.velocity*dt;
		state.rotation = (state.rotation + Matrix3f::skewSymmetric( state.angularVelocity )*state.rotation*dt).orthonormalize();
	}
}




//##########################################################################################
//##########################################################################################
//############		
//############		RK4 Integration Method
//############		
//##########################################################################################
//##########################################################################################




void Simulation:: integrateRK4( Float dt )
{
	// Compute various constant factors of the timestep.
	const Float dt2 = (dt / Float(2));
	const Float dt3 = (dt / Float(3));
	const Float dt6 = (dt / Float(6));
	
	// Intermediate linear and angular acceleration values.
	Vector3f ddP1, ddP2, ddP3, ddP4;
	Vector3f ddR1, ddR2, ddR3, ddR4;
	
	// Update the simulation state of each quadcopter.
	const Size numQuadcopters = quadcopters.getSize();
	
	for ( Index i = 0; i < numQuadcopters; i++ )
	{
		Quadcopter& quadcopter = *quadcopters[i];
		TransformState& state = quadcopter.currentState;
		
		const Vector3f& position = state.position;
		const Vector3f& velocity = state.velocity;
		const Matrix3f& rotation = state.rotation;
		const Vector3f& angularVelocity = state.angularVelocity;
		
		//****************************************************************
		// Integrate using RK4.
		
		// xk1 = v_n;
		// vk1 = a( x_n, v_n );
		Vector3f p1 = position;
		Matrix3f r1 = rotation;
		Vector3f dP1 = velocity;
		Vector3f dR1 = angularVelocity;
		computeAcceleration( quadcopter, 0, p1, dP1, r1, dR1, ddP1, ddR1 );
		
		// xk2 = v_n + 0.5*h*vk1;
		// vk2 = a( x_n + 0.5*h*xk1, xk2 );
		Vector3f p2 = position + dP1*dt2;
		Matrix3f r2 = (rotation + Matrix3f::skewSymmetric( dR1 )*rotation*dt).orthonormalize();
		Vector3f dP2 = velocity + ddP1*dt2;
		Vector3f dR2 = angularVelocity + ddR1*dt2;
		computeAcceleration( quadcopter, dt2, p2, dP2, r2, dR2, ddP2, ddR2 );
		
		// xk3 = v_n + 0.5*h*vk2;
		// vk3 = a( x_n + 0.5*h*xk2, xk3 );
		Vector3f p3 = position + dP2*dt2;
		Matrix3f r3 = (rotation + Matrix3f::skewSymmetric( dR2 )*rotation*dt).orthonormalize();
		Vector3f dP3 = velocity + ddP2*dt2;
		Vector3f dR3 = angularVelocity + ddR2*dt2;
		computeAcceleration( quadcopter, dt2, p3, dP3, r3, dR3, ddP3, ddR3 );
		
		// xk4 = v_n + h*vk3;
		// vk4 = a( x_n + h*xk3, xk4 );
		Vector3f p4 = position + dP3*dt;
		Matrix3f r4 = (rotation + Matrix3f::skewSymmetric( dR3 )*rotation*dt).orthonormalize();
		Vector3f dP4 = velocity + ddP3*dt;
		Vector3f dR4 = angularVelocity + ddR3*dt;
		computeAcceleration( quadcopter, dt, p4, dP4, r4, dR4, ddP4, ddR4 );
		
		//****************************************************************
		
		// Accumulate the final weighted position and velocity.
		state.position = position + dP1*dt6 + dP2*dt3 + dP3*dt3 + dP4*dt6;
		state.rotation = (rotation + Matrix3f::skewSymmetric( dR1 )*rotation*dt6 + 
									Matrix3f::skewSymmetric( dR2 )*rotation*dt3 + 
									Matrix3f::skewSymmetric( dR3 )*rotation*dt3 + 
									Matrix3f::skewSymmetric( dR4 )*rotation*dt6).orthonormalize();
		state.velocity = velocity + ddP1*dt6 + ddP2*dt3 + ddP3*dt3 + ddP4*dt6;
		state.angularVelocity = angularVelocity + ddR1*dt6 + ddR2*dt3 + ddR3*dt3 + ddR4*dt6;
	}
}




//##########################################################################################
//##########################################################################################
//############		
//############		Acceleration Computation Method
//############		
//##########################################################################################
//##########################################################################################





void Simulation:: computeAcceleration( const Quadcopter& quadcopter, Float timeStep,
									const Vector3f& position, const Vector3f& velocity,
									const Matrix3f& rotation, const Vector3f& angularVelocity,
									Vector3f& linearAcceleration, Vector3f& angularAcceleration )
{
	// Compute the gravitational acceleration.
	linearAcceleration = gravity;
	
	// Add the effects of drag forces.
	
	
	// Compute the quadcopter acceleration based on the environmental forces.
	quadcopter.computeAcceleration( TransformState( position, rotation, velocity, angularVelocity ),
									timeStep, linearAcceleration, angularAcceleration );
}



