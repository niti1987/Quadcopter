/*
 *  rimPhysicsCollisionShapeCylinder.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 6/6/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_CYLINDER_H
#define INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_CYLINDER_H


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
/// A class which represents a cylindrical collision shape.
class CollisionShapeCylinder : public CollisionShapeBase<CollisionShapeCylinder>
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
			
			
			
			
			/// Create a default cylinder shape with radius 1, height 1, and centered at the origin.
			CollisionShapeCylinder();
			
			
			
			
			/// Create a cylinder shape with the specified endpoints and radius.
			/**
			  * This creates a cylinder with both circular end cap radii equal
			  * to the specified radius value.
			  */
			CollisionShapeCylinder( const Vector3& newEndpoint1, const Vector3& newEndpoint2,
									Real newRadius );
			
			
			
			
			/// Create a cylinder shape with the specified endpoints and radii.
			CollisionShapeCylinder( const Vector3& newEndpoint1, const Vector3& newEndpoint2,
									Real newRadius1, Real newRadius2 );
			
			
			
			
			/// Create a cylinder shape with the specified endpoints, radii, and material
			CollisionShapeCylinder( const Vector3& newEndpoint1, const Vector3& newEndpoint2,
									Real newRadius1, Real newRadius2, const CollisionShapeMaterial& newMaterial );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point 1 Accessor Methods
			
			
			
			
			/// Return a const reference to the center of this cylinder's bottom circular cap.
			RIM_FORCE_INLINE const Vector3& getEndpoint1() const
			{
				return endpoint1;
			}
			
			
			
			
			/// Set the position of the center of the cylinder's bottom circular cap.
			/**
			  * This keeps the cylinder's 2nd endpoint in the same location and
			  * updates all other cylinder properties to be consistent with the new
			  * first endpoint.
			  */
			RIM_INLINE void setEndpoint1( const Vector3& newEndpoint1 )
			{
				endpoint1 = newEndpoint1;
				axis = endpoint2 - endpoint1;
				height = axis.getMagnitude();
				axis /= height;
				updateBoundingSphere();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point 2 Accessor Methods
			
			
			
			
			/// Return a const reference to the center of this cylinder's top circular cap.
			RIM_FORCE_INLINE const Vector3& getEndpoint2() const
			{
				return endpoint2;
			}
			
			
			
			
			/// Set the position of the center of the cylinder's top circular cap.
			/**
			  * This keeps the cylinder's 1st endpoint in the same location and
			  * updates all other cylinder properties to be consistent with the new
			  * 2nd endpoint.
			  */
			RIM_INLINE void setEndpoint2( const Vector3& newEndpoint2 )
			{
				endpoint2 = newEndpoint2;
				axis = endpoint2 - endpoint1;
				height = axis.getMagnitude();
				axis /= height;
				updateBoundingSphere();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Radius 1 Accessor Methods
			
			
			
			
			/// Return the radius of this cylinder's bottom circular cap in shape space.
			RIM_FORCE_INLINE Real getRadius1() const
			{
				return radius1;
			}
			
			
			
			
			/// Set the radius of this cylinder's bottom circular cap in shape space.
			/**
			  * This radius value is clamped to the range of [0,+infinity].
			  */
			RIM_INLINE void setRadius1( Real newRadius1 )
			{
				radius1 = math::max( newRadius1, Real(0) );
				updateBoundingSphere();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Radius 2 Accessor Methods
			
			
			
			
			/// Return the radius of this cylinder's top circular cap in shape space.
			RIM_FORCE_INLINE Real getRadius2() const
			{
				return radius2;
			}
			
			
			
			
			/// Set the radius of this cylinder's bottom circular cap in shape space.
			/**
			  * This radius value is clamped to the range of [0,+infinity].
			  */
			RIM_INLINE void setRadius2( Real newRadius2 )
			{
				radius2 = math::max( newRadius2, Real(0) );
				updateBoundingSphere();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Axis Accessor Methods
			
			
			
			
			/// Return a const reference to the normalized axis of this cylinder.
			RIM_FORCE_INLINE const Vector3& getAxis() const
			{
				return axis;
			}
			
			
			
			
			/// Set the axis this cylinder's shaft.
			/**
			  * This new axis vector is normalized and then the cylinder's
			  * 2nd endpoint is recomputed using the new axis vector and
			  * the cylinder's height and 1st endpoint.
			  */
			RIM_INLINE void setAxis( const Vector3& newAxis )
			{
				axis = newAxis.normalize();
				endpoint2 = endpoint1 + axis*height;
				updateBoundingSphere();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Height Accessor Methods
			
			
			
			
			/// Return the distance from this cylinder's top to bottom end caps.
			RIM_FORCE_INLINE Real getHeight() const
			{
				return height;
			}
			
			
			
			
			/// Set the distance from this cylinder's top to bottom end caps.
			/**
			  * This method keeps the cylinder's first endpoint at the same location
			  * and recomputes the cylinder's 2nd endpoint based on the cylinder's
			  * axis and the new height value.
			  *
			  * This height value is clamped to the range of [0,+infinity].
			  */
			RIM_INLINE void setHeight( Real newHeight )
			{
				height = math::max( newHeight, Real(0) );
				endpoint2 = endpoint1 + axis*height;
				updateBoundingSphere();
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
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Recalculate this cylinder's bounding sphere from the current cylinder description.
			RIM_INLINE void updateBoundingSphere()
			{
				// Find a point along the cylinder's axis from its 1st endpoint
				// where the optimal bounding sphere is positioned.
				Real h = Real(0.5)*(height*height - radius1*radius1 + radius2*radius2) / height;
				
				this->setBoundingSphere( BoundingSphere( endpoint1 + axis*h, math::sqrt(h*h + radius1*radius1) ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The center of the bottom circular cap of this cylinder shape.
			Vector3 endpoint1;
			
			
			
			
			/// The radius of this cylinder's bottom circular face.
			Real radius1;
			
			
			
			
			/// The center of the top circular cap of this cylinder shape.
			Vector3 endpoint2;
			
			
			
			
			/// The radius of this cylinder's top circular face.
			Real radius2;
			
			
			
			
			/// The normalized vector along this cylinder's axis from its bottom face to top face.
			Vector3 axis;
			
			
			
			
			/// The height of this cylinder, the distance between the top and bottom faces.
			Real height;
			
			
			
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
/// A class which is used to instance a CollisionShapeCylinder object with an arbitrary rigid transformation.
class CollisionShapeCylinder:: Instance : public CollisionShapeInstance
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
			
			
			
			
			/// Return a const reference to the center of this cylinder's bottom circular cap.
			RIM_FORCE_INLINE const Vector3& getEndpoint1() const
			{
				return endpoint1;
			}
			
			
			
			
			/// Return a const reference to the center of this cylinder's top circular cap.
			RIM_FORCE_INLINE const Vector3& getEndpoint2() const
			{
				return endpoint2;
			}
			
			
			
			
			/// Return the radius of this cylinder's bottom circular cap in world space.
			RIM_FORCE_INLINE Real getRadius1() const
			{
				return radius1;
			}
			
			
			
			
			/// Return the radius of this cylinder's top circular cap in world space.
			RIM_FORCE_INLINE Real getRadius2() const
			{
				return radius2;
			}
			
			
			
			
			/// Return a const reference to the normalized axis of this cylinder.
			RIM_FORCE_INLINE const Vector3& getAxis() const
			{
				return axis;
			}
			
			
			
			
			/// Return the distance from this cylinder's top to bottom end caps.
			RIM_FORCE_INLINE Real getHeight() const
			{
				return height;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructors
			
			
			
			
			/// Create a new cylinder shape instance which uses the specified base cylinder shape.
			RIM_INLINE Instance( const CollisionShapeCylinder* newCylinder )
				:	CollisionShapeInstance( newCylinder )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The center of the bottom circular cap of this cylinder shape instance.
			Vector3 endpoint1;
			
			
			
			
			/// The radius of this cylinder's bottom circular face.
			Real radius1;
			
			
			
			
			/// The center of the top circular cap of this cylinder shape instance.
			Vector3 endpoint2;
			
			
			
			
			/// The radius of this cylinder's top circular face.
			Real radius2;
			
			
			
			
			/// The normalized vector along this cylinder's axis from its bottom face to top face.
			Vector3 axis;
			
			
			
			
			/// The height of this cylinder, the distance between the top and bottom faces.
			Real height;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Declarations
			
			
			
			
			/// Declare the cylinder collision shape as a friend so that it can construct instances.
			friend class CollisionShapeCylinder;
			
			
};




//##########################################################################################
//************************  End Rim Physics Shapes Namespace  ******************************
RIM_PHYSICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_CYLINDER_H
