/*
 *  rimPhysicsObjectPair.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_OBJECT_PAIR_H
#define INCLUDE_RIM_PHYSICS_OBJECT_PAIR_H


#include "rimPhysicsObjectsConfig.h"


//##########################################################################################
//***********************  Start Rim Physics Objects Namespace  ****************************
RIM_PHYSICS_OBJECTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates a pair of physics objects of different types.
template < typename ObjectType1, typename ObjectType2 >
class ObjectPair
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an object pair from the two specified objects.
			RIM_INLINE ObjectPair( const ObjectType1* newObject1,
									const ObjectType2* newObject2 )
				:	object1( newObject1 ),
					object2( newObject2 )
			{
				RIM_DEBUG_ASSERT_MESSAGE( newObject1 != NULL, "Cannot use NULL object in collision pair." );
				RIM_DEBUG_ASSERT_MESSAGE( newObject2 != NULL, "Cannot use NULL object in collision pair." );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Collider Accessor Methods
			
			
			
			
			/// Return a const pointer to the first object in this object pair.
			RIM_FORCE_INLINE const ObjectType1* getObject1() const
			{
				return object1;
			}
			
			
			
			
			/// Set the first object in this object pair.
			RIM_INLINE void setObject1( const ObjectType1* newObject1 )
			{
				RIM_DEBUG_ASSERT_MESSAGE( newObject1 != NULL, "Cannot use NULL object in collision pair." );
				object1 = newObject1;
			}
			
			
			
			
			/// Return a const pointer to the first object in this object pair.
			RIM_FORCE_INLINE const ObjectType2* getObject2() const
			{
				return object2;
			}
			
			
			
			
			/// Set the second object in this object pair.
			RIM_INLINE void setObject2( const ObjectType2* newObject2 )
			{
				RIM_DEBUG_ASSERT_MESSAGE( newObject2 != NULL, "Cannot use NULL object in collision pair." );
				object2 = newObject2;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Pair Comparison Operators
			
			
			
			
			/// Return whether or not this object pair is equal to another.
			RIM_FORCE_INLINE Bool operator == ( const ObjectPair& other ) const
			{
				return object1 == other.object1 && object2 == other.object2;
			}
			
			
			
			
			/// Return whether or not this object pair is not equal to another.
			RIM_FORCE_INLINE Bool operator != ( const ObjectPair& other ) const
			{
				return object1 != other.object1 || object2 != other.object2;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Hash Code Accessor Methods
			
			
			
			
			/// Return a hash code for this object pair.
			RIM_INLINE Hash getHashCode() const
			{
				return object1->getHashCode() ^ object2->getHashCode();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The first object in this object pair.
			const ObjectType1* object1;
			
			
			
			
			/// The second object in this object pair.
			const ObjectType2* object2;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Same-Type Object Pair Template Specialization
//############		
//##########################################################################################
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates a pair of physics objects of the same type.
/**
  * This ObjectPair specialization exists to account for the fact that
  * objects of the same type may be reversed and thus it is necessary to 
  * test pairs for equality with both combinations of objects.
  */
template < typename ObjectType >
class ObjectPair<ObjectType,ObjectType>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an object pair from the two specified objects.
			RIM_INLINE ObjectPair( const ObjectType* newObject1,
									const ObjectType* newObject2 )
				:	object1( newObject1 ),
					object2( newObject2 )
			{
				RIM_DEBUG_ASSERT_MESSAGE( newObject1 != NULL, "Cannot use NULL object in collision pair." );
				RIM_DEBUG_ASSERT_MESSAGE( newObject2 != NULL, "Cannot use NULL object in collision pair." );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Collider Accessor Methods
			
			
			
			
			/// Return a const pointer to the first object in this object pair.
			RIM_FORCE_INLINE const ObjectType* getObject1() const
			{
				return object1;
			}
			
			
			
			
			/// Set the first object in this object pair.
			RIM_INLINE void setObject1( const ObjectType* newObject1 )
			{
				RIM_DEBUG_ASSERT_MESSAGE( newObject1 != NULL, "Cannot use NULL object in collision pair." );
				object1 = newObject1;
			}
			
			
			
			
			/// Return a const pointer to the first object in this object pair.
			RIM_FORCE_INLINE const ObjectType* getObject2() const
			{
				return object2;
			}
			
			
			
			
			/// Set the second object in this object pair.
			RIM_INLINE void setObject2( const ObjectType* newObject2 )
			{
				RIM_DEBUG_ASSERT_MESSAGE( newObject2 != NULL, "Cannot use NULL object in collision pair." );
				object2 = newObject2;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Pair Comparison Operators
			
			
			
			
			/// Return whether or not this object pair is equal to another.
			RIM_FORCE_INLINE Bool operator == ( const ObjectPair& other ) const
			{
				return (object1 == other.object1 && object2 == other.object2) ||
						(object1 == other.object2 && object2 == other.object1);
			}
			
			
			
			
			/// Return whether or not this object pair is not equal to another.
			RIM_FORCE_INLINE Bool operator != ( const ObjectPair& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Hash Code Accessor Methods
			
			
			
			
			/// Return a hash code for this object pair.
			RIM_INLINE Hash getHashCode() const
			{
				return object1->getHashCode() ^ object2->getHashCode();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The first object in this object pair.
			const ObjectType* object1;
			
			
			
			
			/// The second object in this object pair.
			const ObjectType* object2;
			
			
			
};




//##########################################################################################
//***********************  End Rim Physics Objects Namespace  ******************************
RIM_PHYSICS_OBJECTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_OBJECT_PAIR_H
