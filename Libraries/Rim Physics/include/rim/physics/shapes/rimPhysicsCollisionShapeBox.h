/*
 *  rimPhysicsCollisionShapeBox.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 6/6/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_BOX_H
#define INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_BOX_H


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
/// A class which represents a rectangular collision shape.
class CollisionShapeBox : public CollisionShapeBase<CollisionShapeBox>
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
			
			
			
			
			/// Create a default box centered at the origin with width, height, and depth = 1.
			CollisionShapeBox();
			
			
			
			
			/// Create a default box centered at the origin with the specified width, height, and depth.
			CollisionShapeBox( Real newWidth, Real newHeight, Real newDepth );
			
			
			
			
			/// Create a box at the specified position and orientation with the specified sizes.
			CollisionShapeBox( const Vector3& newPosition, const Matrix3& newOrientation,
								Real newWidth, Real newHeight, Real newDepth );
			
			
			
			
			/// Create a box at the specified position and orientation with the specified sizes and material,
			CollisionShapeBox( const Vector3& newPosition, const Matrix3& newOrientation,
								Real newWidth, Real newHeight, Real newDepth,
								const CollisionShapeMaterial& newMaterial );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Position Accessor Methods
			
			
			
			
			/// Return a const reference to the position of this box's center.
			RIM_FORCE_INLINE const Vector3& getPosition() const
			{
				return position;
			}
			
			
			
			
			/// Set the position of this box's center.
			RIM_INLINE void setPosition( const Vector3& newPosition )
			{
				position = newPosition;
				
				updateBoundingSphere();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Orientation Accessor Methods
			
			
			
			
			/// Return a const reference to the orientation of this box in its enclosing coordinate frame.
			/**
			  * This orientation is specified by a 3x3 rotation matrix where each
			  * column vector indicates the positive direction of the box's local
			  * coordinate frame. Thus, each column vector is the normal or antinormal
			  * for the faces in that direction.
			  */
			RIM_FORCE_INLINE const Matrix3& getOrientation() const
			{
				return orientation;
			}
			
			
			
			
			/// Set the orientation of this box in its enclosing coordinate frame.
			/**
			  * This orientation is specified by a 3x3 rotation matrix where each
			  * column vector indicates the positive direction of the box's local
			  * coordinate frame. Thus, each column vector is the normal or antinormal
			  * for the faces in that direction.
			  */
			RIM_INLINE void setOrientation( const Matrix3& newOrientation )
			{
				orientation = newOrientation.orthonormalize();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return a const reference to a 3D vector indicating the size of this box's dimensions.
			/**
			  * The x coordinate indicates the box's local width, y is the local height,
			  * and z is the local depth of the box.
			  */
			RIM_FORCE_INLINE const Vector3& getSize() const
			{
				return size;
			}
			
			
			
			
			/// Set a 3D vector indicating the size of this box's dimensions.
			/**
			  * The x coordinate indicates the box's local width, y is the local height,
			  * and z is the local depth of the box.
			  */
			RIM_INLINE void setSize( const Vector3& newSize )
			{
				size.x = math::max( newSize.x, Real(0) );
				size.y = math::max( newSize.y, Real(0) );
				size.z = math::max( newSize.z, Real(0) );
				
				updateBoundingSphere();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Width Accessor Methods
			
			
			
			
			/// Return the width of this box (x dimension) in its local coordinate frame.
			RIM_FORCE_INLINE Real getWidth() const
			{
				return size.x;
			}
			
			
			
			
			/// Set the width of this box (x dimension) in its local coordinate frame.
			RIM_INLINE void setWidth( Real newWidth )
			{
				size.x = math::max( newWidth, Real(0) );
				updateBoundingSphere();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Height Accessor Methods
			
			
			
			
			/// Return the height of this box (x dimension) in its local coordinate frame.
			RIM_FORCE_INLINE Real getHeight() const
			{
				return size.y;
			}
			
			
			
			
			/// Set the height of this box (x dimension) in its local coordinate frame.
			RIM_INLINE void setHeight( Real newHeight )
			{
				size.y = math::max( newHeight, Real(0) );
				updateBoundingSphere();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Depth Accessor Methods
			
			
			
			
			/// Return the depth of this box (x dimension) in its local coordinate frame.
			RIM_FORCE_INLINE Real getDepth() const
			{
				return size.z;
			}
			
			
			
			
			/// Set the depth of this box (x dimension) in its local coordinate frame.
			RIM_INLINE void setDepth( Real newDepth )
			{
				size.z = math::max( newDepth, Real(0) );
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
				this->setBoundingSphere( BoundingSphere( position, Real(0.5)*size.getMagnitude() ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The position of the center of this box.
			Vector3 position;
			
			
			
			
			/// A 3x3 rotation matrix representing the orientation of this box.
			Matrix3 orientation;
			
			
			
			
			/// A 3-component vector containing the sizes for this box along each dimension.
			Vector3 size;
			
			
			
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
/// A class which is used to instance a CollisionShapeBox object with an arbitrary rigid transformation.
class CollisionShapeBox:: Instance : public CollisionShapeInstance
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transform Update Method
			
			
			
			
			/// Update this box instance with the specified 3D rigid transformation from shape to world space.
			virtual void setTransform( const Transform3& newTransform );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Accessor Methods
			
			
			
			
			/// Return a const reference to the position of this box's center in world space.
			RIM_FORCE_INLINE const Vector3& getPosition() const
			{
				return position;
			}

			
			
			
			/// Return a const reference to the orientation of this box in world space.
			/**
			  * This orientation is specified by a 3x3 rotation matrix where each
			  * column vector indicates the positive direction of the box's local
			  * coordinate frame. Thus, each column vector is the normal or antinormal
			  * for the faces in that direction.
			  */
			RIM_FORCE_INLINE const Matrix3& getOrientation() const
			{
				return orientation;
			}

			
			
			
			/// Return a const reference to a 3D vector indicating the size of this box's dimensions.
			/**
			  * The x coordinate indicates the box's local width, y is the local height,
			  * and z is the local depth of the box.
			  */
			RIM_FORCE_INLINE const Vector3& getSize() const
			{
				return size;
			}

			
			
			
			/// Return the width of this box (x dimension) in its local coordinate frame.
			RIM_FORCE_INLINE Real getWidth() const
			{
				return size.x;
			}

			
			
			
			/// Return the height of this box (x dimension) in its local coordinate frame.
			RIM_FORCE_INLINE Real getHeight() const
			{
				return size.y;
			}

			
			
			
			/// Return the depth of this box (x dimension) in its local coordinate frame.
			RIM_FORCE_INLINE Real getDepth() const
			{
				return size.z;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructors
			
			
			
			
			/// Create a new box shape instance which uses the specified base box shape.
			RIM_INLINE Instance( const CollisionShapeBox* newBox )
				:	CollisionShapeInstance( newBox )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The position of the center of this box.
			Vector3 position;
			
			
			
			
			/// A 3x3 rotation matrix representing the orientation of this box.
			Matrix3 orientation;
			
			
			
			
			/// A 3-component vector containing the sizes for this box along each dimension.
			Vector3 size;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Declarations
			
			
			
			
			/// Declare the box collision shape as a friend so that it can construct instances.
			friend class CollisionShapeBox;
			
			
};




//##########################################################################################
//************************  End Rim Physics Shapes Namespace  ******************************
RIM_PHYSICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_BOX_H
