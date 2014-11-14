/*
 *  rimPhysicsObjectCollider.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_OBJECT_COLLIDER_H
#define INCLUDE_RIM_PHYSICS_OBJECT_COLLIDER_H


#include "rimPhysicsObjectsConfig.h"


//##########################################################################################
//***********************  Start Rim Physics Objects Namespace  ****************************
RIM_PHYSICS_OBJECTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates concrete collision data for a templated type of object.
/**
  * In practice, one would specialize this class template for each type of object
  * used in the simulation (rigid, particle, etc.) to encapsulate specific collision
  * information about each object. For instance, particles are simple and don't need
  * to specify additional collision information. However, rigid objects can have multiple
  * shapes and needs to specify which shape instance is being used.
  *
  * This default template instantiation contains a pointer to a templated object type
  * and nothing else.
  */
template < typename ObjectType >
class ObjectCollider
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a ObjectCollider object which encapsulates the specified object.
			RIM_FORCE_INLINE ObjectCollider( const ObjectType* newObject )
				:	object( newObject )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Accessor Methods
			
			
			
			
			/// Return a pointer to the object that constitutes this ObjectCollider.
			RIM_FORCE_INLINE const ObjectType* getObject() const
			{
				return object;
			}
			
			
			
			
			/// Set a pointer to the object that constitutes this ObjectCollider.
			RIM_FORCE_INLINE void setObject( const ObjectType* newObject )
			{
				object = newObject;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Collider Type Accessor Methods
			
			
			
			
			/// Return a const reference the collision shape type for this ObjectCollider.
			RIM_FORCE_INLINE const CollisionShapeType& getType() const
			{
				return type;
			}
			
			
			
			
			/// Return an integral identifier for this collider's collision shape type.
			RIM_FORCE_INLINE CollisionShapeTypeID getTypeID() const
			{
				return type.getID();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the object that constitutes this ObjectCollider.
			const ObjectType* object;
			
			
			
			
			/// An object representing the type of this collider, created from the collider's object type.
			static const CollisionShapeType type;
			
			
			
};




template < typename ObjectType >
const CollisionShapeType ObjectCollider<ObjectType>:: type = CollisionShapeType::of<ObjectType>();




//##########################################################################################
//***********************  End Rim Physics Objects Namespace  ******************************
RIM_PHYSICS_OBJECTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_OBJECT_COLLIDER_H
