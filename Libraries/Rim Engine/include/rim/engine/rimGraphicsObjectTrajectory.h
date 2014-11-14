/*
 *  rimGraphicsObjectTrajectory.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 7/1/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ENGINE_GRAPHICS_OBJECT_TRAJECTORY_H
#define INCLUDE_RIM_ENGINE_GRAPHICS_OBJECT_TRAJECTORY_H


#include "rimEngineConfig.h"


#include "rimEngineTrajectory.h"


//##########################################################################################
//***************************  Start Rim Engine Namespace  *********************************
RIM_ENGINE_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that handles the automatic control of a graphics object's transformation from an external source.
class GraphicsObjectTrajectory
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// An enumeration of the ways that a graphics object can interact with a trajectory.
			typedef enum Usage
			{
				/// With this usage, the graphics object and trajectory do not interact.
				NONE = 0,
				
				/// With this usage, the graphics object uses the trajectory to set its transformation.
				READ,
				
				/// With this usage, the graphics object writes its transformation to the trajectory.
				WRITE
				
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default graphics objects trajectory that doesn't have an object or trajectory.
			GraphicsObjectTrajectory();
			
			
			
			
			/// Create a trajectory with the specified object, trajectory, and usage enum.
			GraphicsObjectTrajectory( const Pointer<Transformable>& newObject,
									const Pointer<Trajectory>& newTrajectory,
									Usage newUsage = READ );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Method
			
			
			
			
			/// Update the state of the graphics object and trajectory based on the trajectory usage.
			/**
			  * The method returns whether or not the update succeeded.
			  */
			Bool update();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Accessor Methods
			
			
			
			
			/// Return a pointer to the graphics object that is being influenced by this trajectory.
			RIM_INLINE const Pointer<Transformable>& getObject() const
			{
				return object;
			}
			
			
			
			
			/// Set a pointer to the graphics object that should be influenced by this trajectory.
			RIM_INLINE void setObject( const Pointer<Transformable>& newObject )
			{
				object = newObject;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Trajectory Accessor Methods
			
			
			
			
			/// Return a pointer to the trajectory that is being used to influence the graphics object.
			RIM_INLINE const Pointer<Trajectory>& getTrajectory() const
			{
				return trajectory;
			}
			
			
			
			
			/// Set a pointer to the trajectory that should be used to influence the graphics object.
			RIM_INLINE void setTrajectory( const Pointer<Trajectory>& newTrajectory )
			{
				trajectory = newTrajectory;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Usage Accessor Methods
			
			
			
			
			/// Return an enum value that indicates the current usage pattern for this object trajectory.
			RIM_INLINE Usage getUsage() const
			{
				return usage;
			}
			
			
			
			
			/// Set an enum value that determines the usage pattern for this object trajectory.
			RIM_INLINE void setUsage( Usage newUsage )
			{
				usage = newUsage;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the object that is using the trajectory.
			Pointer<Transformable> object;
			
			
			
			
			/// A pointer to the trajectory which the graphics object is using.
			Pointer<Trajectory> trajectory;
			
			
			
			
			/// An enum value that determines how the trajectory and graphics object interact.
			Usage usage;
			
			
			
};




//##########################################################################################
//***************************  End Rim Engine Namespace  ***********************************
RIM_ENGINE_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ENGINE_GRAPHICS_OBJECT_TRAJECTORY_H
