/*
 *  rimPhysicsCollisionAlgorithmBase.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_BASE_H
#define INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_BASE_H


#include "rimPhysicsCollisionConfig.h"


#include "rimPhysicsCollisionAlgorithm.h"


//##########################################################################################
//**********************  Start Rim Physics Collision Namespace  ***************************
RIM_PHYSICS_COLLISION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class from which all collision algorithms should derive that simplifies algorithm implementation.
/**
  * This class simplifies CollisionAlgorithm implementation by automatically providing
  * CollisionShapeType information to the CollisionAlgorithm based on the
  * ShapeType1 and ShapeType2 template parameters.
  */
template < typename ObjectType1, typename ObjectType2, typename ShapeType1, typename ShapeType2 >
class CollisionAlgorithmBase : public CollisionAlgorithm<ObjectType1,ObjectType2>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default base collision algorithm.
			RIM_FORCE_INLINE CollisionAlgorithmBase()
				:	CollisionAlgorithm<ObjectType1,ObjectType2>( &shapeType1, &shapeType2 )
			{
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The first shape type that this algorithm operates on.
			static const CollisionShapeType shapeType1;
			
			
			
			
			/// The second shape type that this algorithm operates on.
			static const CollisionShapeType shapeType2;
			
			
			
};




template < typename ObjectType1, typename ObjectType2, typename ShapeType1, typename ShapeType2 >
const CollisionShapeType CollisionAlgorithmBase<ObjectType1,ObjectType2,ShapeType1,ShapeType2>:: shapeType1 = CollisionShapeType::of<ShapeType1>();




template < typename ObjectType1, typename ObjectType2, typename ShapeType1, typename ShapeType2 >
const CollisionShapeType CollisionAlgorithmBase<ObjectType1,ObjectType2,ShapeType1,ShapeType2>:: shapeType2 = CollisionShapeType::of<ShapeType2>();




//##########################################################################################
//**********************  End Rim Physics Collision Namespace  *****************************
RIM_PHYSICS_COLLISION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_BASE_H
