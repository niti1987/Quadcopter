/*
 *  rimPhysicsCollisionResultSet.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_RESULT_SET_H
#define INCLUDE_RIM_PHYSICS_COLLISION_RESULT_SET_H


#include "rimPhysicsCollisionConfig.h"


#include "rimPhysicsCollisionManifold.h"


//##########################################################################################
//**********************  Start Rim Physics Collision Namespace  ***************************
RIM_PHYSICS_COLLISION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains a map from object pairs to collision manifolds.
/**
  * This class is used to keep track of all current collisions among a
  * set of objects. Each pair of objects can have a single collision manifold
  * which can contain one or more collision points.
  */
template < typename ObjectType1, typename ObjectType2 >
class CollisionResultSet
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Collision Manifold Accessor Methods
			
			
			
			
			/// Retrieve the collision manifold between the two specified objects if it exists.
			/**
			  * If this result set contains a manifold between the two specified objects,
			  * TRUE is returned and a pointer to the objects' collision manifold is returned
			  * in the output parameter. Otherwise, FALSE is returned and no manifold
			  * is retrieved.
			  */
			RIM_INLINE Bool getManifold( const ObjectType1* object1, const ObjectType2* object2,
										const CollisionManifold*& manifold ) const
			{
				ObjectPair<ObjectType1,ObjectType2> objectPair( object1, object2 );
				
				return results.find( objectPair.getHashCode(), objectPair, manifold );
			}
			
			
			
			
			/// Retrieve the collision manifold between the two specified objects if it exists.
			/**
			  * If this result set contains a manifold between the two specified objects,
			  * TRUE is returned and a pointer to the objects' collision manifold is returned
			  * in the output parameter. Otherwise, FALSE is returned and no manifold
			  * is retrieved.
			  */
			RIM_INLINE Bool getManifold( const ObjectType1* object1, const ObjectType2* object2,
										CollisionManifold*& manifold )
			{
				ObjectPair<ObjectType1,ObjectType2> objectPair( object1, object2 );
				
				return results.find( objectPair.getHashCode(), objectPair, manifold );
			}
			
			
			
			
			/// Return the total number of collision manifolds (colliding object pairs) in this result set.
			RIM_INLINE Size getManifoldCount() const
			{
				return results.getSize();
			}
			
			
			
			
			/// Return whether or not this collision result set contains a manifold for specified object pair.
			RIM_INLINE Bool hasManifold( const ObjectType1* object1, const ObjectType2* object2 ) const
			{
				ObjectPair<ObjectType1,ObjectType2> objectPair( object1, object2 );
				
				return results.contains( objectPair.getHashCode(), objectPair );
			}
			
			
			
			
			/// Add a new collision manifold to this result set between the specified object pair.
			/**
			  * If this result set already contains a manifold for the specified pair of objects,
			  * a reference to that existing (potentially non-empty) manifold is returned.
			  * If there was no previous manifold, a new manifold is added for the object
			  * pair and a reference to it is returned.
			  */
			RIM_INLINE CollisionManifold& addManifold( const ObjectType1* object1, const ObjectType2* object2 )
			{
				ObjectPair<ObjectType1,ObjectType2> objectPair( object1, object2 );
				CollisionManifold* manifold;
				
				if ( results.find( objectPair.getHashCode(), objectPair, manifold ) )
					return *manifold;
				else
					return *results.add( objectPair.getHashCode(), objectPair, CollisionManifold() );
			}
			
			
			
			
			/// Retrieve any manifold associated with the specified object pair from this result set.
			/**
			  * If there was a manifold for that object pair in the result set, TRUE is
			  * returned and the manifold is removed. Otherwise FALSE is returned and the
			  * result set is unchanged.
			  */
			RIM_INLINE Bool removeManifold( const ObjectType1* object1, const ObjectType2* object2 )
			{
				ObjectPair<ObjectType1,ObjectType2> objectPair( object1, object2 );
				
				return results.remove( objectPair.getHashCode(), objectPair );
			}
			
			
			
			
			/// Remove all collision manifolds from this collision result set.
			RIM_NO_INLINE void clearManifolds()
			{
				results.clear();
			}
			
			
			
			
			/// Remove all collision points from all manifolds in this collision result set.
			/**
			  * This method removes all collision points from each manifold in the
			  * result set but does not remove the manifolds themselves. This can be a more
			  * efficient operation than removing all manifolds themselves and can therefore
			  * be useful when performing collision detection from frame-to-frame: objects
			  * that stay colliding across multiple frames will keep the same manifold object,
			  * even if the manifold is recomputed each frame.
			  */
			RIM_NO_INLINE void clearManifoldPoints()
			{
				typename HashMap<ObjectPair<ObjectType1,ObjectType2>,CollisionManifold>::Iterator i = results.getIterator();
				
				for ( ; i; i++ )
					i->clearPoints();
			}
			
			
			
			
			/// Remove all manifolds from this collision result set that have no collision points.
			RIM_NO_INLINE void removeEmptyManifolds()
			{
				typename HashMap<ObjectPair<ObjectType1,ObjectType2>,CollisionManifold>::Iterator i = results.getIterator();
				
				while ( i )
				{
					if ( i->getPointCount() == Size(0) )
					{
						i.remove();
						continue;
					}
					
					i++;
				}
			}
			
			
			
			
			/// Return a const interator for this collision result set.
			RIM_INLINE typename HashMap<ObjectPair<ObjectType1,ObjectType2>,CollisionManifold>::Iterator getIterator()
			{
				return results.getIterator();
			}
			
			
			
			
			/// Return an interator for this collision result set.
			RIM_INLINE typename HashMap<ObjectPair<ObjectType1,ObjectType2>,CollisionManifold>::ConstIterator getIterator() const
			{
				return results.getIterator();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Manifold Object Transform Update Method
			
			
			
			
			/// Update the world-space collision points for all manifolds in this result set.
			RIM_INLINE void updateTransforms()
			{
				// Default implementation doesn't do anything.
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A map from object pairs to collision manifolds for all collision results.
			HashMap<ObjectPair<ObjectType1,ObjectType2>,CollisionManifold> results;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Rigid Object Accessor Methods
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_INLINE void CollisionResultSet<RigidObject,RigidObject>:: updateTransforms()
{
	HashMap<ObjectPair<RigidObject,RigidObject>,CollisionManifold>::Iterator i = results.getIterator();
	
	for ( ; i; i++ )
	{
		const RigidObject* object1 = i.getKey().getObject1();
		const RigidObject* object2 = i.getKey().getObject2();
		
		i->updateTransforms( object1->getTransform(), object2->getTransform() );
	}
}




//##########################################################################################
//**********************  End Rim Physics Collision Namespace  *****************************
RIM_PHYSICS_COLLISION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_RESULT_SET_H
