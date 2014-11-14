/*
 *  rimPhysicsCollisionShapeSphere.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_SPHERE_H
#define INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_SPHERE_H


#include "rimPhysicsShapesConfig.h"


#include "rimPhysicsCollisionShape.h"
#include "rimPhysicsCollisionShapeBase.h"
#include "rimPhysicsCollisionShapeInstance.h"


//##########################################################################################
//************************  Start Rim Physics Shapes Namespace  ****************************
RIM_PHYSICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a spherical collision shape.
class CollisionShapeSphere : public CollisionShapeBase<CollisionShapeSphere>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Class Declarations
			
			
			
			
			class Instance;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default sphere shape with radius 1 centered at the origin.
			RIM_INLINE CollisionShapeSphere()
			{
				this->setBoundingSphere( BoundingSphere( Vector3::ZERO, Real(1) ) );
			}
			
			
			
			
			/// Create a sphere shape with the specified position and radius and default material.
			/**
			  * The radius parameter is automatically clamped to the range [0,+infinity].
			  */
			RIM_INLINE CollisionShapeSphere( const Vector3& newPosition, Real newRadius )
			{
				this->setBoundingSphere( BoundingSphere( newPosition, newRadius ) );
			}
			
			
			
			
			/// Create a sphere shape with the specified position and radius and material.
			/**
			  * The radius parameter is automatically clamped to the range [0,+infinity].
			  */
			RIM_INLINE CollisionShapeSphere( const Vector3& newPosition, Real newRadius,
											const CollisionShapeMaterial& newMaterial )
				:	CollisionShapeBase<CollisionShapeSphere>( newMaterial )
			{
				this->setBoundingSphere( BoundingSphere( newPosition, newRadius ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Position Accessor Methods
			
			
			
			
			/// Return the position of this sphere in shape-space.
			RIM_INLINE const Vector3& getPosition() const
			{
				return this->getBoundingSphere().position;
			}
			
			
			
			
			/// Set the position of this sphere in shape-space.
			RIM_INLINE void setPosition( const Vector3& newPosition )
			{
				this->setBoundingSphere( BoundingSphere( newPosition, this->getRadius() ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Radius Accessor Methods
			
			
			
			
			/// Return the radius of this sphere in shape-space.
			RIM_INLINE Real getRadius() const
			{
				return this->getBoundingSphere().radius;
			}
			
			
			
			
			/// Set the radius of this sphere in shape-space.
			RIM_INLINE void setRadius( Real newRadius )
			{
				this->setBoundingSphere( BoundingSphere( this->getPosition(), newRadius ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mass Distribution Accessor Methods
			
			
			
			
			/// Return a 3x3 matrix for the inertia tensor of this shape relative to its center of mass.
			virtual Matrix3 getInertiaTensor() const;
			
			
			
			
			/// Return a 3D vector representing the center-of-mass of this shape in its coordinate frame.
			virtual Vector3 getCenterOfMass() const;
			
			
			
			
			/// Return the volume of this shape in length units cubed (m^3).
			virtual Real getVolume() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Instance Creation Methods
			
			
			
			
			/// Create and return an instance of this shape.
			virtual Pointer<CollisionShapeInstance> getInstance() const;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Sphere Shape Instance Class Definition
//############		
//##########################################################################################
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which is used to instance a CollisionShapeSphere object with an arbitrary rigid transformation.
class CollisionShapeSphere:: Instance : public CollisionShapeInstance
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transform Update Method
			
			
			
			
			/// Update this sphere instance with the specified 3D rigid transformation from shape to world space.
			/**
			  * This method transforms this instance's position and radius from
			  * shape space to world space.
			  */
			virtual void setTransform( const Transform3& newTransform );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Accessor Methods
			
			
			
			
			/// Return a const reference to this sphere shape instance's position in world space.
			RIM_FORCE_INLINE const Vector3& getPosition() const
			{
				return this->getBoundingSphere().position;
			}
			
			
			
			
			/// Return this sphere shape instance's radius in world space.
			RIM_FORCE_INLINE Real getRadius() const
			{
				return this->getBoundingSphere().radius;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructors
			
			
			
			
			/// Create a new sphere shape instance which uses the specified base sphere shape.
			RIM_INLINE Instance( const CollisionShapeSphere* newSphere )
				:	CollisionShapeInstance( newSphere )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Declarations
			
			
			
			
			/// Declare the sphere collision shape as a friend so that it can construct instances.
			friend class CollisionShapeSphere;
			
			
};




//##########################################################################################
//************************  End Rim Physics Shapes Namespace  ******************************
RIM_PHYSICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_SPHERE_H
