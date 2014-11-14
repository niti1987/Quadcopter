/*
 *  rimPhysicsCollisionShapeBase.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_BASE_H
#define INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_BASE_H


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
/// A class from which all collision shape subclasses should derive that simplifies shape typing.
/**
  * This class simplifies CollisionShape subclassing by automatically providing
  * CollisionShapeType information to the CollisionShape based on the
  * SubType template parameter.
  */
template < typename SubType >
class CollisionShapeBase : public CollisionShape
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a base collision shape.
			RIM_FORCE_INLINE CollisionShapeBase()
				:	CollisionShape( &type )
			{
			}
			
			
			
			
			/// Create a base collision shape with the specified material.
			RIM_FORCE_INLINE CollisionShapeBase( const CollisionShapeMaterial& newMaterial )
				:	CollisionShape( &type, newMaterial )
			{
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A CollisionShapeType object representing the type of this base collision shape.
			/**
			  * The type object is created directly from the SubType template parameter.
			  */
			static const CollisionShapeType type;
			
			
			
};




template < typename SubType >
const CollisionShapeType CollisionShapeBase<SubType>:: type = CollisionShapeType::of<SubType>();




//##########################################################################################
//************************  End Rim Physics Shapes Namespace  ******************************
RIM_PHYSICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_BASE_H
