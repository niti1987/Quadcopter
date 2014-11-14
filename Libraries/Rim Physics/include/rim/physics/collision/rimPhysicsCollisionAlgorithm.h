/*
 *  rimPhysicsCollisionAlgorithm.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_H
#define INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_H


#include "rimPhysicsCollisionConfig.h"


#include "rimPhysicsCollisionResultSet.h"


//##########################################################################################
//**********************  Start Rim Physics Collision Namespace  ***************************
RIM_PHYSICS_COLLISION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// The base class for an object which detects collisions between two types of CollisionShape.
template < typename ObjectType1, typename ObjectType2 >
class CollisionAlgorithm
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this collision algorithm and all associated resources.
			virtual ~CollisionAlgorithm()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Collision Detection Methods
			
			
			
			
			/// Test the specified object pair for collisions and add the results to the result set.
			/**
			  * If a collision occurred, TRUE is returned and the resulting CollisionPoint(s)
			  * are added to the CollisionManifold for the object pair in the specified
			  * CollisionResultSet. If there was no collision detected, FALSE is returned
			  * and the result set is unmodified.
			  */
			virtual Bool testForCollisions( const ObjectCollider<ObjectType1>& collider1,
											const ObjectCollider<ObjectType2>& collider2,
											CollisionResultSet<ObjectType1,ObjectType2>& resultSet ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shape Type Accessor Methods
			
			
			
			
			/// Get a type ID for the first collision shape type that this algorithm operates on.
			RIM_FORCE_INLINE CollisionShapeTypeID getShapeTypeID1() const
			{
				return shapeType1->getID();
			}
			
			
			
			
			/// Return an object representing the first shape type that this algorithm operates on.
			RIM_FORCE_INLINE const CollisionShapeType& getShapeType1() const
			{
				return *shapeType1;
			}
			
			
			
			
			/// Get a type ID for the second collision shape type that this algorithm operates on.
			RIM_FORCE_INLINE CollisionShapeTypeID getShapeTypeID2() const
			{
				return shapeType2->getID();
			}
			
			
			
			
			/// Return an object representing the second shape type that this algorithm operates on.
			RIM_FORCE_INLINE const CollisionShapeType& getShapeType2() const
			{
				return *shapeType2;
			}
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Constructor
			
			
			
			
			/// Create a new collision algorithm which operates on the specified collision shape types.
			RIM_FORCE_INLINE CollisionAlgorithm( const CollisionShapeType* newShapeType1, const CollisionShapeType* newShapeType2 )
				:	shapeType1( newShapeType1 ),
					shapeType2( newShapeType2 )
			{
				RIM_DEBUG_ASSERT_MESSAGE( shapeType1 != NULL, "Cannot create collision algorithm with NULL shape type." );
				RIM_DEBUG_ASSERT_MESSAGE( shapeType2 != NULL, "Cannot create collision algorithm with NULL shape type." );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to an object representing the first shape type that this algorithm operates on.
			const CollisionShapeType* shapeType1;
			
			
			
			
			/// A pointer to an object representing the second shape type that this algorithm operates on.
			const CollisionShapeType* shapeType2;
			
			
			
};




//##########################################################################################
//**********************  End Rim Physics Collision Namespace  *****************************
RIM_PHYSICS_COLLISION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_H
