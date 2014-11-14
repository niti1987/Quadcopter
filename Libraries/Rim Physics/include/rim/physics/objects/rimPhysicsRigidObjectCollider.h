/*
 *  rimPhysicsRigidObjectCollider.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_RIGID_OBJECT_COLLIDER_H
#define INCLUDE_RIM_PHYSICS_RIGID_OBJECT_COLLIDER_H


#include "rimPhysicsObjectsConfig.h"


#include "rimPhysicsObjectCollider.h"
#include "rimPhysicsRigidObject.h"


//##########################################################################################
//***********************  Start Rim Physics Objects Namespace  ****************************
RIM_PHYSICS_OBJECTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains collision data for a RigidObject.
/**
  * This class contains a pointer to a RigidObject and a pointer to a
  * CollisionShapeInstance which is being tested for collision. This is
  * necessary because an object could potentailly have more than one shape
  * (such as via shape hierarchies).
  */
template <>
class ObjectCollider<RigidObject>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a ObjectCollider object which encapsulates the specified object and shape instance.
			RIM_FORCE_INLINE ObjectCollider( const RigidObject* newObject, const CollisionShapeInstance* newShape )
				:	object( newObject ),
					shape( newShape )
			{
				RIM_DEBUG_ASSERT_MESSAGE( newObject != NULL, "Cannot use NULL RigidObject in ObjectCollider" );
				RIM_DEBUG_ASSERT_MESSAGE( newShape != NULL, "Cannot use NULL shape instance in ObjectCollider" );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Accessor Methods
			
			
			
			
			/// Return a pointer to the object that constitutes this ObjectCollider.
			RIM_FORCE_INLINE const RigidObject* getObject() const
			{
				return object;
			}
			
			
			
			
			/// Set a pointer to the object that constitutes this ObjectCollider.
			RIM_FORCE_INLINE void setObject( const RigidObject* newObject )
			{
				object = newObject;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shape Accessor Methods
			
			
			
			
			/// Return a pointer to the collision shape instance that constitutes this ObjectCollider.
			RIM_FORCE_INLINE const CollisionShapeInstance* getShape() const
			{
				return shape;
			}
			
			
			
			
			/// Set a pointer to the collision shape instance that constitutes this ObjectCollider.
			RIM_FORCE_INLINE void setShape( const CollisionShapeInstance* newShape )
			{
				shape = newShape;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Collider Type Accessor Methods
			
			
			
			
			/// Return a const reference the collision shape type for this ObjectCollider.
			RIM_FORCE_INLINE const CollisionShapeType& getType() const
			{
				return shape->getType();
			}
			
			
			
			
			/// Return an integral identifier for this collider's collision shape type.
			RIM_FORCE_INLINE CollisionShapeTypeID getTypeID() const
			{
				return shape->getTypeID();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the object that constitutes this ObjectCollider.
			const RigidObject* object;
			
			
			
			
			/// The specific shape instance of this collider's object that is being tested for collisions.
			const CollisionShapeInstance* shape;
			
			
			
};




//##########################################################################################
//***********************  End Rim Physics Objects Namespace  ******************************
RIM_PHYSICS_OBJECTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_RIGID_OBJECT_COLLIDER_H
