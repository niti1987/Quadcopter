/*
 *  rimPhysicsCollisionShapeInstance.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_INSTANCE_H
#define INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_INSTANCE_H


#include "rimPhysicsShapesConfig.h"


#include "rimPhysicsCollisionShape.h"


//##########################################################################################
//************************  Start Rim Physics Shapes Namespace  ****************************
RIM_PHYSICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// The base class for classes which instance a CollisionShape with a particular transformation in world space.
class CollisionShapeInstance
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this collision shape instance and release all associated resources.
			virtual ~CollisionShapeInstance()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transform Update Method
			
			
			
			
			/// Update this collision shape instance using the specified transformation.
			/**
			  * This method should transform any necessary collision quantities stored in the
			  * instance's base shape into world space using the specified transformation
			  * object. In addition, it transforms the bounding sphere from shape to
			  * world space.
			  */
			virtual void setTransform( const Transform3& newTransform ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Material Accessor Methods
			
			
			
			
			/// Return a const reference to the material for this shape instance's base shape.
			RIM_INLINE const CollisionShapeMaterial& getMaterial() const
			{
				return shape->getMaterial();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Sphere Accessor Methods
			
			
			
			
			/// Return a const reference to this collision shape instance's bounding sphere.
			RIM_FORCE_INLINE const BoundingSphere& getBoundingSphere() const
			{
				return boundingSphere;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shape Accessor Methods
			
			
			
			
			/// Return a const pointer to the shape that this instance is derrived from.
			RIM_INLINE const CollisionShape* getShape() const
			{
				return shape;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shape Type Accessor Methods
			
			
			
			
			/// Return an integer identifying the sub type of this collision shape.
			/**
			  * This ID is a 32-bit integer that is generated by hashing the string
			  * generated for the SubType template parameter. While the posibility of
			  * ID collisions is very low, duplicates are nonetheless a possibility.
			  */
			RIM_FORCE_INLINE CollisionShapeTypeID getTypeID() const
			{
				return shape->getTypeID();
			}
			
			
			
			
			/// Return an object representing the type of this CollisionShape.
			RIM_FORCE_INLINE const CollisionShapeType& getType() const
			{
				return shape->getType();
			}
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Constructor
			
			
			
			
			/// Create a collision shape instance with the specified template shape.
			RIM_FORCE_INLINE CollisionShapeInstance( const CollisionShape* newShape )
				:	shape( newShape )
			{
				RIM_DEBUG_ASSERT_MESSAGE( newShape != NULL, "Cannot have NULL shape for collision shape instance." );
				
				boundingSphere = shape->getBoundingSphere();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Shape Accessor Methods
			
			
			
			
			/// Set a const pointer to the shape that this instance is derrived from.
			RIM_INLINE void setShape( const CollisionShape* newShape )
			{
				RIM_DEBUG_ASSERT_MESSAGE( newShape != NULL, "Cannot have NULL shape for collision shape instance." );
				
				shape = newShape;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Bounding Sphere Accessor Methods
			
			
			
			
			/// Set the bounding sphere for this shape instance in world coordinates.
			RIM_INLINE void setBoundingSphere( const BoundingSphere& newBoundingSphere )
			{
				boundingSphere = newBoundingSphere;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A CollisionShape object representing the shape template from which this instance is derrived.
			const CollisionShape* shape;
			
			
			
			
			/// A bounding sphere for this collision shape instance in world coordinates.
			BoundingSphere boundingSphere;
			
			
			
};




//##########################################################################################
//************************  End Rim Physics Shapes Namespace  ******************************
RIM_PHYSICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_INSTANCE_H