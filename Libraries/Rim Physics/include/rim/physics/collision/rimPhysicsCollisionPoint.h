/*
 *  rimPhysicsCollisionPoint.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_POINT_H
#define INCLUDE_RIM_PHYSICS_COLLISION_POINT_H


#include "rimPhysicsCollisionConfig.h"


//##########################################################################################
//**********************  Start Rim Physics Collision Namespace  ***************************
RIM_PHYSICS_COLLISION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which holds information about a single point of collision between two objects.
/**
  * This information consists of the point of collision on each object,
  * the collision normal, and the distance between the objects' surfaces.
  */
class CollisionPoint
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a collision point object from the specified collision data.
			RIM_INLINE CollisionPoint( const Vector3& newObjectSpacePoint1, const Vector3& newObjectSpacePoint2,
										const Vector3& newWorldSpacePoint1, const Vector3& newWorldSpacePoint2,
										const Vector3& newNormal, Real newSeparationDistance,
										const CollisionShapeMaterial& newMaterial )
				:	objectSpacePoint1( newObjectSpacePoint1 ),
					objectSpacePoint2( newObjectSpacePoint2 ),
					worldSpacePoint1( newWorldSpacePoint1 ),
					worldSpacePoint2( newWorldSpacePoint2 ),
					normal( newNormal ),
					separationDistance( newSeparationDistance ),
					material( newMaterial )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Collision Point Position Accessor Methods
			
			
			
			
			/// Return a const reference to the position of the collision point on object 1 in its local coordinate frame.
			RIM_FORCE_INLINE const Vector3& getObjectSpacePoint1() const
			{
				return objectSpacePoint1;
			}
			
			
			
			
			/// Return a const reference to the position of the collision point on object 2 in its local coordinate frame.
			RIM_FORCE_INLINE const Vector3& getObjectSpacePoint2() const
			{
				return objectSpacePoint2;
			}
			
			
			
			
			/// Return a const reference to the position of the collision point on object 1 in world coordinates.
			RIM_FORCE_INLINE const Vector3& getWorldSpacePoint1() const
			{
				return worldSpacePoint1;
			}
			
			
			
			
			/// Set the position of the collision point on object 1 in world coordinates.
			RIM_FORCE_INLINE void setWorldSpacePoint1( const Vector3& newWorldSpacePoint1 )
			{
				worldSpacePoint1 = newWorldSpacePoint1;
			}
			
			
			
			
			/// Return a const reference to the position of the collision point on object 2 in world coordinates.
			RIM_FORCE_INLINE const Vector3& getWorldSpacePoint2() const
			{
				return worldSpacePoint2;
			}
			
			
			
			
			/// Set the position of the collision point on object 2 in world coordinates.
			RIM_FORCE_INLINE void setWorldSpacePoint2( const Vector3& newWorldSpacePoint2 )
			{
				worldSpacePoint2 = newWorldSpacePoint2;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Normal Accessor Methods
			
			
			
			
			/// Return a const reference to the world-space collision normal for this collision point.
			/**
			  * This vector always points in the direction from object 1 to object 2.
			  */
			RIM_FORCE_INLINE const Vector3& getNormal() const
			{
				return normal;
			}
			
			
			
			
			/// Return the distance between the two colliding objects in world space.
			/**
			  * This value will always be negative for colliding objects.
			  */
			RIM_FORCE_INLINE Real getSeparationDistance() const
			{
				return separationDistance;
			}
			
			
			
			
			/// Set the distance between the two colliding objects in world space.
			/**
			  * This value should always be negative for colliding objects.
			  */
			RIM_FORCE_INLINE void setSeparationDistance( Real newSeparationDistance )
			{
				separationDistance = newSeparationDistance;
			}
			
			
			
			
			/// Return a const reference to the combined material for the two objects at this collision point.
			/**
			  * This material should be generated to represent how the two colliding objects
			  * should interact at this collision point.
			  */
			RIM_FORCE_INLINE const CollisionShapeMaterial& getMaterial() const
			{
				return material;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The position of the collision point on object 1 in its local coordinate frame.
			Vector3 objectSpacePoint1;
			
			
			
			
			/// The position of the collision point on object 2 in its local coordinate frame.
			Vector3 objectSpacePoint2;
			
			
			
			
			/// The position of the collision point on object 1 in world coordinates.
			Vector3 worldSpacePoint1;
			
			
			
			
			/// The position of the collision point on object 2 in world coordinates.
			Vector3 worldSpacePoint2;
			
			
			
			
			/// A 3D vector in world space indicating the collision normal.
			/**
			  * This vector always points from object 1 to object 2.
			  */
			Vector3 normal;
			
			
			
			
			/// The distance between the two colliding objects (always negative for colliding objects).
			Real separationDistance;
			
			
			
			
			/// The material object which defines the combind materials of the objects at this point.
			CollisionShapeMaterial material;
			
			
			
};




//##########################################################################################
//**********************  End Rim Physics Collision Namespace  *****************************
RIM_PHYSICS_COLLISION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_POINT_H
