/*
 *  rimPhysicsCollisionAlgorithmDispatcher.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_DISPATCHER_H
#define INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_DISPATCHER_H


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
/// A class which performs collision double dispatch on the type of an object's shape.
template < typename ObjectType1, typename ObjectType2 >
class CollisionAlgorithmDispatcher
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			/// Define the type to use for a collision algorithm in this algorithm dispatcher.
			typedef CollisionAlgorithm<ObjectType1,ObjectType2> AlgorithmType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default algorithm dispatcher with no algorithms.
			RIM_NO_INLINE CollisionAlgorithmDispatcher()
				:	algorithmTable( rim::util::allocate<AlgorithmType*>( DEFAULT_HASH_TABLE_SIZE ) ),
					algorithmTableSize( DEFAULT_HASH_TABLE_SIZE )
			{
				// Zero-out the buckets in the new algorithm table.
				for ( Index i = 0; i < algorithmTableSize; i++ )
					algorithmTable[i] = NULL;
			}
			
			
			
			
			/// Create a copy of an algorithm dispatcher.
			RIM_NO_INLINE CollisionAlgorithmDispatcher( const CollisionAlgorithmDispatcher& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this algorithm dispatcher and all of the algorithms it contains.
			RIM_NO_INLINE ~CollisionAlgorithmDispatcher()
			{
				algorithms.clear();
				
				// Deallocate the algorithm hash table.
				rim::util::deallocate( algorithmTable );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the algorithms of one dispatcher to another.
			RIM_NO_INLINE CollisionAlgorithmDispatcher& operator = ( const CollisionAlgorithmDispatcher& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Collision Detection Methods
			
			
			
			
			/// Test the specified collider pair for collisions and add the results to the result set.
			/**
			  * If a collision occurred, TRUE is returned and the resulting CollisionPoint(s)
			  * are added to the CollisionManifold for the object pair in the specified
			  * CollisionResultSet. If there was no collision detected or there was no
			  * collision algorithm that was compatible with the specified colliders,
			  * FALSE is returned and the result set is unmodified.
			  */
			RIM_INLINE Bool testForCollisions( const ObjectCollider<ObjectType1>& collider1,
												const ObjectCollider<ObjectType2>& collider2,
												CollisionResultSet<ObjectType1,ObjectType2>& resultSet )
			{
				AlgorithmType* algorithm = getAlgorithmForShapeTypes( collider1.getType(), collider2.getType() );
				
				if ( algorithm )
					return algorithm->testForCollisions( collider1, collider2, resultSet );
				else
					return false;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Collision Algorithm Accessor Methods
			
			
			
			
			/// Add the specified CollisionAlgorithm to this dispatcher.
			/**
			  * If there already exists an algorithm for the specified algorithm's shape types,
			  * the old algorithm is replaced.
			  */
			RIM_INLINE Bool addAlgorithm( const Pointer<AlgorithmType>& newAlgorithm )
			{
				return this->addAlgorithmPrivate( newAlgorithm );
			}
			
			
			
			
			/// Return a pointer to the algorithm for the specified template shape types.
			/**
			  * If such an algorithm exists in this dispatcher, a pointer to it is
			  * returned. Otherwise, NULL is returned.
			  */
			RIM_INLINE AlgorithmType* getAlgorithm( const CollisionShapeType& shapeType1,
													const CollisionShapeType& shapeType2 )
			{
				return this->getAlgorithmForShapeTypes( shapeType1, shapeType2 );
			}
			
			
			
			
			/// Return a pointer to the algorithm for the specified template shape types.
			/**
			  * If such an algorithm exists in this dispatcher, a pointer to it is
			  * returned. Otherwise, NULL is returned.
			  */
			RIM_INLINE const AlgorithmType* getAlgorithm( const CollisionShapeType& shapeType1,
															const CollisionShapeType& shapeType2 ) const
			{
				return this->getAlgorithmForShapeTypes( shapeType1, shapeType2 );
			}
			
			
			
			
			/// Return a pointer to the algorithm for the specified template shape types.
			/**
			  * If such an algorithm exists in this dispatcher, a pointer to it is
			  * returned. Otherwise, NULL is returned.
			  */
			template < typename ShapeType1, typename ShapeType2 >
			RIM_INLINE AlgorithmType* getAlgorithm()
			{
				static const CollisionShapeType shapeType1 = CollisionShapeType::of<ShapeType1>();
				static const CollisionShapeType shapeType2 = CollisionShapeType::of<ShapeType2>();
				
				return this->getAlgorithmForShapeTypes( shapeType1, shapeType2 );
			}
			
			
			
			
			/// Return a pointer to the algorithm for the specified template shape types.
			/**
			  * If such an algorithm exists in this dispatcher, a pointer to it is
			  * returned. Otherwise, NULL is returned.
			  */
			template < typename ShapeType1, typename ShapeType2 >
			RIM_INLINE const AlgorithmType* getAlgorithm() const
			{
				static const CollisionShapeType shapeType1 = CollisionShapeType::of<ShapeType1>();
				static const CollisionShapeType shapeType2 = CollisionShapeType::of<ShapeType2>();
				
				return this->getAlgorithmForShapeTypes( shapeType1, shapeType2 );
			}
			
			
			
			
			/// Remove an algorithm with the specified templated shape types from this dispatcher.
			/**
			  * If such an algorithm exists in this dispatcher, it is removed and TRUE is
			  * returned. Otherwise, FALSE is returned and the dispatcher is unchanged.
			  */
			template < typename ShapeType1, typename ShapeType2 >
			RIM_NO_INLINE Bool removeAlgorithm()
			{
				static const CollisionShapeType shapeType1 = CollisionShapeType::of<ShapeType1>();
				static const CollisionShapeType shapeType2 = CollisionShapeType::of<ShapeType2>();
				
				AlgorithmType** algorithmBucket = algorithmTable +
										getBucketIndex( shapeType1.getID(), shapeType2.getID(), algorithmTableSize );
				AlgorithmType* algorithm = *algorithmBucket;
				
				if ( algorithm )
				{
					// Zero-out the hash table entry.
					*algorithmBucket = NULL;
					
					for ( Index i = 0; i < algorithms.getSize(); i++ )
					{
						if ( algorithm == algorithms[i] )
						{
							algorithms.removeAtIndexUnordered( i );
							break;
						}
					}
					
					return true;
				}
				else
					return false;
			}
			
			
			
			
			/// Remove all algorithms from this CollisionAlgorithmDispatcher.
			RIM_NO_INLINE void clearAlgorihtms()
			{
				// Destroy each algorithm in this dispatcher.
				algorithms.clear();
				
				// Zero-out the algorithm hash table.
				for ( Index i = 0; i < algorithmTableSize; i++ )
					algorithmTable[i] = NULL;
			}
			
			
			
			
			/// Return the number of collision algorithms that this dispatcher has.
			RIM_FORCE_INLINE Size getAlgorithmCount() const
			{
				return algorithms.getSize();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Add the specified algorithm pointer to this algorithm dispatcher
			RIM_NO_INLINE Bool addAlgorithmPrivate( const Pointer<AlgorithmType>& newAlgorithm );
			
			
			
			
			/// Resize this dispatcher's algorithm hash table until it hashes perfectly.
			RIM_NO_INLINE void resizeAlgorithmHashTable();
			
			
			
			
			/// Return a pointer to the algorithm for the specified shape types in this dispatcher.
			/**
			  * If no such algorithm exists, NULL is returned.
			  */
			RIM_FORCE_INLINE AlgorithmType* getAlgorithmForShapeTypes( const CollisionShapeType& type1,
																		const CollisionShapeType& type2 ) const
			{
				return algorithmTable[ this->getBucketIndex(type1.getID(), type2.getID(), algorithmTableSize) ];
			}
			
			
			
			
			/// Return a hash code that is created by combining the specified hash code pair.
			RIM_FORCE_INLINE static Hash getBucketIndex( Hash hash1, Hash hash2, Hash tableSize )
			{
				return getPairHashCode( hash1, hash2 ) % tableSize;
			}
			
			
			
			
			/// Return a hash code that is created by combining the specified hash code pair.
			RIM_FORCE_INLINE static Hash getPairHashCode( Hash hash1, Hash hash2 )
			{
				return (hash1*Hash(2185031351ul)) ^ (hash2*Hash(4232417593ul));
			}
			
			
			
			
			RIM_INLINE static Hash getNextPrime( Hash n )
			{
				for ( Index i = 0; i < NUMBER_OF_PRIME_HASH_TABLE_SIZES; i++ )
				{
					if ( PRIME_HASH_TABLE_SIZES[i] > n )
						return PRIME_HASH_TABLE_SIZES[i];
				}
				
				return n;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An array of pointers representing a hash table for the algorithms contained in this dispatcher.
			AlgorithmType** algorithmTable;
			
			
			
			
			/// The size of the collision algorithm hash table.
			Hash algorithmTableSize;
			
			
			
			
			/// A list of pointers to each algorithm in this dispatcher.
			ArrayList<Pointer<AlgorithmType> > algorithms;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The default size of a collision algorithm dispatcher hash table.
			static const Size DEFAULT_HASH_TABLE_SIZE = 11;
			
			
			
			
			/// The number of prime hash table sizes.
			static const Size NUMBER_OF_PRIME_HASH_TABLE_SIZES = 28;
			
			
			
			
			/// An array of prime hash table sizes.
			static const Hash PRIME_HASH_TABLE_SIZES[NUMBER_OF_PRIME_HASH_TABLE_SIZES];
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Copy Constructor Implementation
//############		
//##########################################################################################
//##########################################################################################




template < typename ObjectType1, typename ObjectType2 >
CollisionAlgorithmDispatcher<ObjectType1,ObjectType2>:: CollisionAlgorithmDispatcher(
															const CollisionAlgorithmDispatcher& other )
	:	algorithmTable( rim::util::allocate<AlgorithmType*>( other.algorithmTableSize ) ),
		algorithmTableSize( other.algorithmTableSize ),
		algorithms( other.algorithms.getCapacity() )
{
	// For each algorithm in the other dispatcher, copy the algorithm
	// and hash it into this algorithm dispatcher.
	Size numAlgorithms = other.algorithms.getSize();
	
	for ( Index i = 0; i < numAlgorithms; i++ )
	{
		const Pointer<AlgorithmType>& newAlgorithm = other.algorithms[i];
		
		// Insert it in the hash table and list of algorithms.
		Hash bucketIndex = getBucketIndex( newAlgorithm->getShapeType1().getID(),
											newAlgorithm->getShapeType2().getID(),
											algorithmTableSize );
		algorithmTable[bucketIndex] = newAlgorithm;
		
		// Add the algorithm to the list of algorithms.
		algorithms.add( newAlgorithm );
	}
}




//##########################################################################################
//##########################################################################################
//############		
//############		Assignment Operator Implementation
//############		
//##########################################################################################
//##########################################################################################




template < typename ObjectType1, typename ObjectType2 >
CollisionAlgorithmDispatcher<ObjectType1,ObjectType2>& CollisionAlgorithmDispatcher<ObjectType1,ObjectType2>:: 
									operator = ( const CollisionAlgorithmDispatcher& other )
{
	if ( this != &other )
	{
		// Clear the old list of algorithms.
		algorithms.clear();
		
		// Reallocate the algorithm hash table.
		rim::util::deallocate( algorithmTable );
		algorithmTable = rim::util::allocate<AlgorithmType*>( other.algorithmTableSize );
		algorithmTableSize = other.algorithmTableSize;
		
		// For each algorithm in the other dispatcher, copy the algorithm
		// and hash it into this algorithm dispatcher.
		const Size numAlgorithms = other.algorithms.getSize();
		
		for ( Index i = 0; i < numAlgorithms; i++ )
		{
			const Pointer<AlgorithmType>& newAlgorithm = other.algorithms[i];
			
			// Insert it in the hash table.
			Hash bucketIndex = getBucketIndex( newAlgorithm->getShapeType1().getID(),
												newAlgorithm->getShapeType2().getID(),
												algorithmTableSize );
			algorithmTable[bucketIndex] = newAlgorithm;
			
			// Add the algorithm to the list of algorithms.
			algorithms.add( newAlgorithm );
		}
	}
	
	return *this;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Algorithm Add Method Implementation
//############		
//##########################################################################################
//##########################################################################################




template < typename ObjectType1, typename ObjectType2 >
Bool CollisionAlgorithmDispatcher<ObjectType1,ObjectType2>:: addAlgorithmPrivate( const Pointer<AlgorithmType>& newAlgorithm )
{
	if ( newAlgorithm.isNull() )
		return false;
	
	AlgorithmType** algorithmBucket = algorithmTable + getBucketIndex( newAlgorithm->getShapeTypeID1(),
																		newAlgorithm->getShapeTypeID2(),
																		algorithmTableSize );
	
	if ( *algorithmBucket )
	{
		// An algorithm already exists for this bucket.
		AlgorithmType* const existingAlgorithm = *algorithmBucket;
		
		// Test to see if the shape types for the new and old algorithms match.
		if ( newAlgorithm->getShapeType1() == existingAlgorithm->getShapeType1() &&
			newAlgorithm->getShapeType2() == existingAlgorithm->getShapeType2() )
		{
			// Replace the existing algorithm with the new algorithm.
			for ( Index i = 0; i < algorithms.getSize(); i++ )
			{
				if ( existingAlgorithm == algorithms[i] )
				{
					algorithms.removeAtIndexUnordered( i );
					break;
				}
			}
			
			*algorithmBucket = newAlgorithm;
			algorithms.add( newAlgorithm );
		}
		else
		{
			// The existing algorithm cannot be replaced.
			// Resize the algorithm hash table to accomodate the new algorithm.
			algorithms.add( newAlgorithm );
			resizeAlgorithmHashTable();
		}
	}
	else
	{
		// No algorithm already exists for this bucket. Add the new algorithm.
		*algorithmBucket = newAlgorithm;
		algorithms.add( newAlgorithm );
	}
	
	return true;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Algorithm Hash Table Resize Method Implementation
//############		
//##########################################################################################
//##########################################################################################




template < typename ObjectType1, typename ObjectType2 >
void CollisionAlgorithmDispatcher<ObjectType1,ObjectType2>:: resizeAlgorithmHashTable()
{
	Hash newAlgorithmTableSize = algorithmTableSize;
	AlgorithmType** newAlgorithmTable;
	
	collisionAlgorithmDispatcherHashTableResizeLoop:
	{
		// Create a candidate hash table for the next largest prime number hash table size.
		newAlgorithmTableSize = getNextPrime( newAlgorithmTableSize );
		newAlgorithmTable = rim::util::allocate<AlgorithmType*>( newAlgorithmTableSize );
		
		// Zero-out the buckets in the new algorithm table.
		for ( Index i = 0; i < newAlgorithmTableSize; i++ )
			newAlgorithmTable[i] = NULL;
		
		// For each existing algorithm, determine its algorithm bucket.
		Size numAlgorithms = algorithms.getSize();
		
		for ( Index i = 0; i < numAlgorithms; i++ )
		{
			AlgorithmType* algorithm = algorithms[i];
			AlgorithmType** algorithmBucket = newAlgorithmTable +
					this->getBucketIndex( algorithm->getShapeType1().getID(),
											algorithm->getShapeType2().getID(),
											newAlgorithmTableSize );
			
			if ( *algorithmBucket )
			{
				// There is an algorithm table collision, deallocate this hash table attempt
				// and start the resizing process.
				rim::util::deallocate( newAlgorithmTable );
				goto collisionAlgorithmDispatcherHashTableResizeLoop;
			}
			else
			{
				// Add the algorithm to the new table.
				*algorithmBucket = algorithm;
			}
		}
	}
	
	// Deallocate the old algorithm hash table and replace it with the new one.
	rim::util::deallocate( algorithmTable );
	algorithmTable = newAlgorithmTable;
	algorithmTableSize = newAlgorithmTableSize;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Prime Hash Table Size Array Definition
//############		
//##########################################################################################
//##########################################################################################




template < typename ObjectType1, typename ObjectType2 >
const Hash	CollisionAlgorithmDispatcher<ObjectType1,ObjectType2>:: PRIME_HASH_TABLE_SIZES[] =
{
	11,				//	Between 2^3 and 2^4
	23,				//	Between 2^4 and 2^5
	53,				//	Between 2^5 and 2^6
	97,				//	Between 2^6 and 2^7
	193,			//	Between 2^7 and 2^8
	389,			//	Between 2^8 and 2^9
	769,			//	Between 2^9 and 2^10
	1543,			//	Between 2^10 and 2^11
	3079,			//	Between 2^11 and 2^12
	6151,			//	Between 2^12 and 2^13
	12289,			//	Between 2^13 and 2^14
	24593,			//	Between 2^14 and 2^15
	49157,			//	Between 2^15 and 2^16
	98317,			//	Between 2^16 and 2^17
	196613,			//	Between 2^17 and 2^18
	393241,			//	Between 2^18 and 2^19
	786433,			//	Between 2^19 and 2^20
	1572869,		//	Between 2^20 and 2^21
	3145739,		//	Between 2^21 and 2^22
	6291469,		//	Between 2^22 and 2^23
	12582917,		//	Between 2^23 and 2^24
	25165843,		//	Between 2^24 and 2^25
	50331653,		//	Between 2^25 and 2^26
	100663319,		//	Between 2^26 and 2^27
	201326611,		//	Between 2^27 and 2^28
	402653189,		//	Between 2^28 and 2^29
	805306457,		//	Between 2^29 and 2^30
	1610612741,		//	Between 2^30 and 2^31
};




//##########################################################################################
//**********************  End Rim Physics Collision Namespace  *****************************
RIM_PHYSICS_COLLISION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_ALGORITHM_DISPATCHER_H
