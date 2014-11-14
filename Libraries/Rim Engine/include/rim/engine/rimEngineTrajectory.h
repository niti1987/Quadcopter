/*
 *  rimEngineTrajectory.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 7/1/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ENGINE_TRAJECTORY_H
#define INCLUDE_RIM_ENGINE_TRAJECTORY_H


#include "rimEngineConfig.h"


//##########################################################################################
//***************************  Start Rim Engine Namespace  *********************************
RIM_ENGINE_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that stores a 3D transformation and motion information for a generic object.
/**
  * This class allows unrelated systems to communicate the positions of common objects.
  * For example, a physics object can set the trajectory, which is then read by a graphics
  * object.
  */
class Trajectory
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default identity trajectory transformation with no motion.
			RIM_INLINE Trajectory()
			{
			}
			
			
			
			
			/// Create a trajectory with the specified static transformation.
			RIM_INLINE Trajectory( const Transform3f& newTransform )
				:	transform( newTransform )
			{
			}
			
			
			
			
			/// Create a trajectory with the specified transformation and velocities.
			RIM_INLINE Trajectory( const Transform3f& newTransform, const Vector3f& newVelocity,
									const Vector3f& newAngularVelocity = Vector3f() )
				:	transform( newTransform ),
					velocity( newVelocity ),
					angularVelocity( newAngularVelocity )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Position Accessor Methods
			
			
			
			
			/// Return the position of this trajectory in world space.
			RIM_INLINE const Vector3f& getPosition() const
			{
				return transform.position;
			}
			
			
			
			
			/// Set the position of this trajectory in world space.
			RIM_INLINE void setPosition( const Vector3f& newPosition )
			{
				transform.position = newPosition;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Orientation Accessor Methods
			
			
			
			
			/// Return a reference to this trajectory's 3x3 orthonormal rotation matrix.
			/**
			  * This is the orthonormal matrix which defines the rotational transformation
			  * from object to world space.
			  */
			RIM_INLINE const Matrix3f& getOrientation() const
			{
				return transform.orientation;
			}
			
			
			
			
			/// Set this trajectory's 3x3 orthonormal rotation matrix.
			/**
			  * This is the orthonormal matrix which defines the rotational transformation
			  * from object to world space.
			  */
			RIM_INLINE void setOrientation( const Matrix3f& newOrientation )
			{
				transform.orientation = newOrientation;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transform Accessor Methods
			
			
			
			
			/// Return a const reference to this trajectory's transformation.
			RIM_INLINE const Transform3f& getTransform() const
			{
				return transform;
			}
			
			
			
			
			/// Set this trajectory's transformation.
			RIM_INLINE void setTransform( const Transform3f& newTransform )
			{
				transform = newTransform;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Velocity Accessor Methods
			
			
			
			
			/// Return the linear velocity of this trajectory in world units per second.
			RIM_INLINE const Vector3f& getVelocity() const
			{
				return velocity;
			}
			
			
			
			
			/// Set the linear velocity of this trajectory in world units per second.
			RIM_INLINE void setVelocity( const Vector3f& newVelocity )
			{
				velocity = newVelocity;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Angular Velocity Accessor Methods
			
			
			
			
			/// Return the angular velocity of this trajectory in radians per second.
			RIM_INLINE const Vector3f& getAngularVelocity() const
			{
				return angularVelocity;
			}
			
			
			
			
			/// Set the angular velocity of this trajectory in radians per second.
			RIM_INLINE void setAngularVelocity( const Vector3f& newAngularVelocity )
			{
				angularVelocity = newAngularVelocity;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A 3D transformation from object to world space for the trajectory.
			Transform3f transform;
			
			
			
			
			/// The linear velocity of this trajectory in world space.
			Vector3f velocity;
			
			
			
			
			/// The angular velocity of this trajectory along the 3 principle axes.
			Vector3f angularVelocity;
			
			
			
};




//##########################################################################################
//***************************  End Rim Engine Namespace  ***********************************
RIM_ENGINE_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ENGINE_TRAJECTORY_H
