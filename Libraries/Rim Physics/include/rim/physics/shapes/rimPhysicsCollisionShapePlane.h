/*
 *  rimPhysicsCollisionShapePlane.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 7/6/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_PLANE_H
#define INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_PLANE_H


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
/// A class which represents an infinite plane collision shape.
class CollisionShapePlane : public CollisionShapeBase<CollisionShapePlane>
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
			
			
			
			
			/// Create a default plane shape which is the XZ plane with normal pointing along the positive Y direction.
			RIM_INLINE CollisionShapePlane()
				:	plane( Vector3( 0, 1, 0 ), 0 )
			{
				updateBoundingSphere();
			}
			
			
			
			
			/// Create a plane shape with the specified plane equation.
			/**
			  * The plane's normal is normalized and its offset recalculated
			  * to reflect the new normal.
			  */
			RIM_INLINE CollisionShapePlane( const Plane3& newPlane )
				:	plane( newPlane.normal.normalize(), newPlane.offset*newPlane.normal.getMagnitude() )
			{
				updateBoundingSphere();
			}
			
			
			
			
			/// Create a plane shape with the specified point on the plane and plane normal.
			/**
			  * The plane's normal is normalized and used to calculate the plane's offset
			  * with the point on the plane.
			  */
			RIM_INLINE CollisionShapePlane( const Vector3& normal, const Vector3& pointOnPlane )
				:	plane( normal.normalize(), pointOnPlane )
			{
				updateBoundingSphere();
			}
			
			
			
			
			/// Create a plane shape with the specified plane equation and material.
			/**
			  * The plane's normal is normalized and its offset recalculated
			  * to reflect the new normal.
			  */
			RIM_INLINE CollisionShapePlane( const Plane3& newPlane,
											const CollisionShapeMaterial& newMaterial )
				:	CollisionShapeBase<CollisionShapePlane>( newMaterial ),
					plane( newPlane )
			{
				updateBoundingSphere();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Plane Accessor Methods
			
			
			
			
			/// Return the plane equation of this plane shape.
			RIM_INLINE const Plane3& getPlane() const
			{
				return plane;
			}
			
			
			
			
			/// Set the plane equation of this plane shape.
			/**
			  * The plane's normal is normalized and its offset recalculated
			  * to reflect the new normal.
			  */
			RIM_INLINE void setPlane( const Plane3& newPlane )
			{
				Real normalMagnitude = newPlane.normal.getMagnitude();
				plane.normal = newPlane.normal / normalMagnitude;
				plane.offset = newPlane.offset * normalMagnitude;
				updateBoundingSphere();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Normal Accessor Methods
			
			
			
			
			/// Return the normal of this plane shape in shape space.
			RIM_INLINE const Vector3& getNormal() const
			{
				return plane.normal;
			}
			
			
			
			
			/// Set the normal of this plane shape in shape space.
			/**
			  * The new normal is automatically normalzed upon input.
			  * This method does not change the plane's offset.
			  */
			RIM_INLINE void setNormal( const Vector3& newNormal )
			{
				plane.normal = newNormal.normalize();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Offset Accessor Methods
			
			
			
			
			/// Return the offset of this plane shape in shape space.
			RIM_INLINE Real getOffset() const
			{
				return plane.offset;
			}
			
			
			
			
			/// Set the offset of this plane shape in shape space.
			RIM_INLINE void setOffset( Real newOffset )
			{
				plane.offset = newOffset;
				updateBoundingSphere();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mass Distribution Accessor Methods
			
			
			
			
			/// Return a 3x3 matrix for the inertia tensor of this plane shape relative to its center of mass.
			/**
			  * The returned inertia tensor for this plane shape will always be a matrix
			  * with infinite inertial values because the plane has no mass.
			  */
			virtual Matrix3 getInertiaTensor() const
			{
				return Matrix3( math::infinity<Real>(), Real(0), Real(0),
								Real(0), math::infinity<Real>(), Real(0),
								Real(0), Real(0), math::infinity<Real>() );
			}
			
			
			
			
			/// Return a 3D vector representing the center-of-mass of this plane shape in its coordinate frame.
			/**
			  * Since a plane shape has no mass or center, the returned center of mass is the projection of
			  * the origin onto the plane.
			  */
			virtual Vector3 getCenterOfMass() const
			{
				return this->getCenter();
			}
			
			
			
			
			/// Return the volume of this plane shape in length units cubed (m^3).
			/**
			  * This method always returns 0 because a plane has no volume.
			  */
			virtual Real getVolume() const
			{
				return Real(0);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Instance Creation Methods
			
			
			
			
			/// Create and return an instance of this shape.
			virtual Pointer<CollisionShapeInstance> getInstance() const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Return the 'center' of the plane, the projection of the origin onto it.
			RIM_INLINE Vector3 getCenter() const
			{
				return -plane.offset*plane.normal;
			}
			
			
			
			
			/// Update the bounding sphere for this plane shape.
			RIM_INLINE void updateBoundingSphere()
			{
				this->setBoundingSphere( BoundingSphere( this->getCenter(), math::infinity<Real>() ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The plane equation for this plane shape.
			Plane3 plane;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Plane Shape Instance Class Definition
//############		
//##########################################################################################
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which is used to instance a CollisionShapePlane object with an arbitrary rigid transformation.
class CollisionShapePlane:: Instance : public CollisionShapeInstance
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transform Update Method
			
			
			
			
			/// Update this plane instance with the specified 3D rigid transformation from shape to world space.
			/**
			  * This method transforms this instance's plane equation from shape space to world space.
			  */
			virtual void setTransform( const Transform3& newTransform );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Accessor Methods
			
			
			
			
			/// Return the plane equation of this plane shape.
			RIM_INLINE const Plane3& getPlane() const
			{
				return plane;
			}
			
			
			
			
			/// Return the normal of this plane shape in shape space.
			RIM_INLINE const Vector3& getNormal() const
			{
				return plane.normal;
			}
			
			
			
			
			/// Return the offset of this plane shape in shape space.
			RIM_INLINE const Vector3& getOffset() const
			{
				return plane.normal;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructors
			
			
			
			
			/// Create a new plane shape instance which uses the specified base plane shape.
			RIM_INLINE Instance( const CollisionShapePlane* newPlane )
				:	CollisionShapeInstance( newPlane )
			{
				this->updateBoundingSphere();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Update the bounding sphere for this plane shape.
			RIM_INLINE void updateBoundingSphere()
			{
				this->setBoundingSphere( BoundingSphere( -plane.offset*plane.normal, math::infinity<Real>() ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The plane equation of this plane shape.
			Plane3 plane;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Declarations
			
			
			
			
			/// Declare the plane collision shape as a friend so that it can construct instances.
			friend class CollisionShapePlane;
			
			
};




//##########################################################################################
//************************  End Rim Physics Shapes Namespace  ******************************
RIM_PHYSICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_PLANE_H
