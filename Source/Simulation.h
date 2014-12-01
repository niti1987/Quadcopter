/*
 *  Simulation.h
 *  Quadcopter
 *
 *  Created by Carl Schissler on 11/20/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_SIMULATION_H
#define INCLUDE_SIMULATION_H


#include "rim/rimEngine.h"


using namespace rim;
using namespace rim::math;


#include "Quadcopter.h"



/// A class that handles the physical simulation of multiple quadcopters in a virtual environment.
class Simulation
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new simulation with the default paratmers.
			Simulation();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Method
			
			
			
			
			/// Update the current state of the simulation for the given timestep.
			void update( Float dt );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Quadcopter Accessor Methods
			
			
			
			
			/// Return the number of quadcopters in this simulation.
			RIM_INLINE Size getQuadcopterCount() const
			{
				return quadcopters.getSize();
			}
			
			
			
			
			/// Return a pointer to the quadcopter at the given index or NULL if the index is invalid.
			RIM_INLINE Quadcopter* getQuadcopter( Index quadcopterIndex ) const
			{
				if ( quadcopterIndex < quadcopters.getSize() )
					return quadcopters[quadcopterIndex];
				else
					return NULL;
			}
			
			
			
			
			/// Add a new quadcopter to this simulation.
			RIM_INLINE Bool addQuadcopter( Quadcopter* quadcopter )
			{
				if ( quadcopter == NULL )
					return false;
				
				quadcopters.add( quadcopter );
				
				return true;
			}
			
			
			
			
			/// Remove the quadcopter at the specified index in this simulation.
			RIM_INLINE Bool removeQuadcopter( Index quadcopterIndex )
			{
				return quadcopters.removeAtIndex( quadcopterIndex );
			}
			
			
			
			
			/// Remove all quadcopters from the simulation.
			RIM_INLINE void clearQuadcopters()
			{
				quadcopters.clear();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Simulation Helper Methods
			
			
			
			
			/// Update the simulation using the Semi-Implicit Euler integration method for the given timestep.
			void integrateSemiImplicitEuler( Float dt );
			
			
			
			
			/// Update the simulation using the RK4 integration method for the given timestep.
			void integrateRK4( Float dt );
			
			
			
			
			/// Compute the COM acceleration for the given quadcopter with the specified position and velocity parameters.
			/**
			  * The resulting linear and angular acceleration of the quadcopter's center of mass
			  * is returned in the output reference parameters.
			  */
			void computeAcceleration( const Quadcopter& quadcopter, Float timeStep,
									const Vector3f& position, const Vector3f& velocity,
									const Matrix3f& rotation, const Vector3f& angularVelocity,
									Vector3f& linearAcceleration, Vector3f& angularAcceleration );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Data Members
			
			
			
			/// A list of the quadcopters that are part of this simulation.
			ArrayList< Quadcopter* > quadcopters;
			
			
			/// The 3D gravitational acceleration vector of the simulation.
			Vector3f gravity;
			
			
			
};





#endif // INCLUDE_SIMULATION_H
