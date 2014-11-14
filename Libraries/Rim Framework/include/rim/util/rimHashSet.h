/*
 *  rimHashSet.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 3/3/11.
 *  Copyright 2011 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_HASH_SET_H
#define INCLUDE_RIM_HASH_SET_H


#include "rimUtilitiesConfig.h"


#include "../math/rimPrimes.h"
#include "rimAllocator.h"


//##########################################################################################
//***************************  Start Rim Utilities Namespace  ******************************
RIM_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A container class which uses a hash table to keep track of a set of values.
template < typename T, typename HashType = Hash >
class HashSet
{
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Entry Class
			
			
			
			
			class Entry
			{
				public:
					
					
					RIM_INLINE Entry( HashType newHash, const T& newValue )
						:	next( NULL ),
							hash( newHash ),
							value( newValue )
					{
					}
					
					
					RIM_INLINE Entry( const Entry& other )
						:	hash( other.hash ),
							value( other.value )
					{
						if ( other.next )
							next = HashSet::newEntry(*other.next);
						else
							next = NULL;
					}
					
					
					~Entry()
					{
						if ( next )
							delete next;
					}
					
					
					Entry* next;
					
					HashType hash;
					T value;
					
			};
			
			
			
			
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a hash set with the default load factor and number of buckets.
			RIM_INLINE HashSet()
				:	loadFactor( DEFAULT_LOAD_FACTOR ),
					loadThreshold( Size(DEFAULT_LOAD_FACTOR*DEFAULT_NUMBER_OF_BUCKETS) ),
					numElements( 0 ),
					numBuckets( DEFAULT_NUMBER_OF_BUCKETS ),
					buckets( util::allocate<Entry*>(DEFAULT_NUMBER_OF_BUCKETS) )
			{
				nullBuckets();
			}
			
			
			
			
			/// Create a hash set with the specified load factor and default number of buckets.
			RIM_INLINE HashSet( Float newLoadFactor )
				:	loadFactor( math::clamp( newLoadFactor, 0.1f, 2.0f ) ),
					numElements( 0 ),
					numBuckets( DEFAULT_NUMBER_OF_BUCKETS ),
					buckets( util::allocate<Entry*>(DEFAULT_NUMBER_OF_BUCKETS) )
			{
				loadThreshold = Size(loadFactor*DEFAULT_NUMBER_OF_BUCKETS);
				nullBuckets();
			}
			
			
			
			
			/// Create a hash set with the default load factor and specified number of buckets.
			RIM_INLINE HashSet( HashType newNumBuckets )
				:	loadFactor( DEFAULT_LOAD_FACTOR ),
					numElements( 0 ),
					numBuckets( math::nextPowerOf2Prime(newNumBuckets) )
			{
				buckets = util::allocate<Entry*>(numBuckets);
				loadThreshold = Size(DEFAULT_LOAD_FACTOR*numBuckets);
				nullBuckets();
			}
			
			
			
			
			/// Create a hash set with the specified load factor and number of buckets.
			RIM_INLINE HashSet( HashType newNumBuckets, Float newLoadFactor )
				:	loadFactor( math::clamp( newLoadFactor, 0.1f, 2.0f ) ),
					numElements( 0 ),
					numBuckets( math::nextPowerOf2Prime(newNumBuckets) )
			{
				buckets = util::allocate<Entry*>(numBuckets);
				loadThreshold = Size(loadFactor*numBuckets);
				nullBuckets();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Copy Constructor
			
			
			
			
			/// Create a hash set with the specified load factor and number of buckets.
			RIM_INLINE HashSet( const HashSet& other )
				:	loadFactor( other.loadFactor ),
					numElements( other.numElements ),
					numBuckets( other.numBuckets ),
					buckets( util::allocate<Entry*>(other.numBuckets) )
			{
				// Copy the hash table buckets
				const Entry* const * otherBucket = other.buckets;
				const Entry* const * const otherBucketsEnd = otherBucket + numBuckets;
				Entry** bucket = buckets;
				
				while ( otherBucket != otherBucketsEnd )
				{
					if ( *otherBucket )
						*bucket = HashSet::newEntry(**otherBucket);
					else
						*bucket = NULL;
					
					otherBucket++;
					bucket++;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Copy the contents of one hash set into another.
			RIM_INLINE HashSet& operator = ( const HashSet& other )
			{
				if ( this != &other )
				{
					deleteBuckets( buckets, numBuckets );
					
					// Copy the parameters from the other hash set.
					numBuckets = other.numBuckets;
					loadFactor = other.loadFactor;
					numElements = other.numElements;
					buckets = util::allocate<Entry*>(numBuckets);
					
					{
						// Copy the hash table buckets
						const Entry* const * otherBucket = other.buckets;
						const Entry* const * const otherBucketsEnd = otherBucket + numBuckets;
						Entry** bucket = buckets;
						
						while ( otherBucket != otherBucketsEnd )
						{
							if ( *otherBucket )
								*bucket = HashSet::newEntry(**otherBucket);
							else
								*bucket = NULL;
							
							otherBucket++;
							bucket++;
						}
					}
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a hash set and it's contents, deallocating all memory used.
			RIM_INLINE ~HashSet()
			{
				deleteBuckets( buckets, numBuckets );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Add Method
			
			
			
			
			/// Add a new element to the hash set if it does not already exist.
			/**
			  * If the element did not previously exist in the set, return TRUE.
			  * Otherwise return FALSE.
			  */
			RIM_INLINE Bool add( HashType hash, const T& value )
			{
				// Compute the bucket for the new element.
				Entry** bucket = buckets + hash % numBuckets;
				
				if ( *bucket == NULL )
					*bucket = HashSet::newEntry( hash, value );
				else
				{
					Entry* entry = *bucket;
					
					if ( entry->value == value )
						return false;
					
					while ( entry->next )
					{
						entry = entry->next;
						
						if ( entry->value == value )
							return false;
					}
					
					entry->next = HashSet::newEntry( hash, value );
				}
				
				numElements++;
				return true;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Remove Methods
			
			
			
			
			/// Remove the specified value from the hash set if it exists.
			/**
			  * If the value does not exist in the hash set, then FALSE is returned,
			  * otherwise TRUE is returned.
			  */
			RIM_INLINE Bool remove( HashType hash, const T& value )
			{
				// Compute the bucket for the new element.
				Entry** bucket = buckets + hash % numBuckets;
				Entry* entry = *bucket;
				
				if ( !entry )
					return false;
				
				if ( entry->value == value )
				{
					*bucket = entry->next;
					entry->next = NULL;
					delete entry;
					numElements--;
					return true;
				}
				
				Entry* lastEntry = *bucket;
				entry = entry->next;
				
				while ( entry )
				{
					if ( entry->value == value )
					{
						lastEntry->next = entry->next;
						entry->next = NULL;
						delete entry;
						numElements--;
						return true;
					}
					
					lastEntry = entry;
					entry = entry->next;
				}
				
				return false;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Clear Method
			
			
			
			
			/// Clear all elements from the hash set.
			RIM_INLINE void clear()
			{
				// Delete all entries
				Entry** bucket = buckets;
				const Entry* const * const bucketsEnd = bucket + numBuckets;
				
				while ( bucket != bucketsEnd )
				{
					if ( *bucket )
					{
						delete (*bucket);
						*bucket = NULL;
					}
					
					bucket++;
				}
				
				numElements = 0;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Contains Methods
			
			
			
		
			/// Query whether or not the specified value is contained in a hash set.
			RIM_INLINE Bool contains( HashType hash, const T& value ) const
			{
				// Compute the bucket for the query.
				Entry* entry = *(buckets + hash % numBuckets);
				
				// Look for the value in the bucket.
				while ( entry )
				{
					if ( entry->value == value )
						return true;
					
					entry = entry->next;
				}
				
				return false;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return the number of setpings in a hash set.
			RIM_INLINE Size getSize() const
			{
				return numElements;
			}
			
			
			
			
			/// Return whether or not a hash set is empty.
			RIM_INLINE Bool isEmpty() const
			{
				return numElements == Size(0);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Iterator Class
			
			
			
			
			/// A class which iterates over hash set elements.
			class Iterator
			{
				public:
					
					//********************************************
					//	Constructor
						
						
						
						/// Create a new hash set iterator for the specified hash set.
						RIM_INLINE Iterator( HashSet& newHashSet )
							:	hashSet( newHashSet ),
								currentBucket( newHashSet.buckets ),
								bucketsEnd( newHashSet.buckets + newHashSet.numBuckets )
						{
							// advance until the first element
							advanceToNextFullBucket();
						}
						
						
						
						
					//********************************************
					//	Destructor
						
						
						
						
						/// Destroy a hash set iterator.
						RIM_INLINE ~Iterator()
						{
						}
						
						
						
						
					//********************************************
					//	Public Methods
						
						
						
						/// Increment the location of a hash set iterator by one element.
						RIM_INLINE void operator ++ ()
						{
							currentEntry = currentEntry->next;
							
							if ( currentEntry == NULL )
							{
								currentBucket++;
								advanceToNextFullBucket();
							}
						}
						
						
						
						
						/// Increment the location of a hash set iterator by one element.
						RIM_INLINE void operator ++ ( int )
						{
							this->operator++();
						}
						
						
						
						
						/// Test whether or not the current element is valid.
						/**
						  * This will return FALSE when the last element of the hash set
						  * has been iterated over.
						  */
						RIM_INLINE operator Bool () const
						{
							return currentEntry != NULL;
						}
						
						
						
						/// Return the value of the value-value pair pointed to by the iterator.
						RIM_INLINE T& operator * () const
						{
							return currentEntry->value;
						}
						
						
						
						
						/// Access the current iterator element value
						RIM_INLINE T* operator -> () const
						{
							return &currentEntry->value;
						}
						
						
						
						/// Get the value hash of the value-value pair pointed to by the iterator.
						RIM_INLINE HashType getHash() const
						{
							return currentEntry->hash;
						}
						
						
						
						
						/// Remove the current element from the hash table and advance to the next element.
						void remove()
						{
							// Backup in the bucket so that we can remove the current element.
							// This is potentially inefficient, it would be best if the buckets
							// would use a doublely linked list, but this might add extra overhead
							// elsewhere.
							
							// Handle removing from the start of a bucket separately.
							if ( currentEntry == *currentBucket )
							{
								*currentBucket = currentEntry->next;
								
								if ( *currentBucket != NULL )
								{
									currentEntry->next = NULL;
									delete currentEntry;
									currentEntry = *currentBucket;
								}
								else
								{
									delete currentEntry;
									currentBucket++;
									
									advanceToNextFullBucket();
								}
							}
							else
							{
								// Otherwise, iterate through the bucket until we find the element
								// before this one.
								Entry* previousEntry = *currentBucket;
								
								while ( previousEntry && previousEntry->next != currentEntry )
									previousEntry = previousEntry->next;
								
								previousEntry->next = currentEntry->next;
								Entry* temp = currentEntry;
								operator++();
								temp->next = NULL;
								delete temp;
							}
							
							hashSet.numElements--;
						}
						
						
						
						/// Reset the iterator to the beginning of the hash set.
						RIM_INLINE void reset()
						{
							currentBucket = hashSet.buckets;
							
							// advance until the first element
							advanceToNextFullBucket();
						}
						
						
						
						
				private:
					
					//********************************************
					//	Private Methods
						
						
						
						
						/// Advance the iterator to the next non-empty bucket.
						RIM_INLINE void advanceToNextFullBucket()
						{
							while ( *currentBucket == NULL && currentBucket != bucketsEnd )
								currentBucket++;
							
							if ( currentBucket == bucketsEnd )
								currentEntry = NULL;
							else
								currentEntry = *currentBucket;
						}
						
						
						
						
					//********************************************
					//	Private Data Members
						
						
						
						
						/// The HashSet that is being iterated over.
						HashSet& hashSet;
						
						
						
						
						/// The current bucket in the HashSet.
						Entry** currentBucket;
						
						
						
						
						/// The last bucket in the HashSet.
						const Entry* const * const bucketsEnd;
						
						
						
						
						/// The current entry in the hash set that the iterator is pointing to.
						Entry* currentEntry;
						
						
						
						
						/// Make the const iterator class a friend.
						friend class HashSet::ConstIterator;
						
						
						
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	ConstIterator Class
			
			
			
			
			/// A class which iterates over hash set elements without the ability to modify them.
			class ConstIterator
			{
				public:
					
					//********************************************
					//	Constructor
						
						
						
						/// Create a new hash set iterator for the specified hash set.
						RIM_INLINE ConstIterator( const HashSet<T>& newHashSet )
							:	hashSet( newHashSet ),
								currentBucket( newHashSet.buckets ),
								bucketsEnd( newHashSet.buckets + newHashSet.numBuckets )
						{
							// advance until the first element
							advanceToNextFullBucket();
						}
						
						
						
						/// Create a new const hash set iterator from a non-const iterator.
						RIM_INLINE ConstIterator( const Iterator& iterator )
							:	hashSet( iterator.hashSet ),
								currentBucket( iterator.currentBucket ),
								bucketsEnd( iterator.bucketsEnd ),
								currentEntry( iterator.currentEntry )
						{
						}
						
						
						
						
					//********************************************
					//	Destructor
						
						
						
						
						/// Destroy a hash set iterator.
						RIM_INLINE ~ConstIterator()
						{
						}
						
						
						
						
					//********************************************
					//	Public Methods
						
						
						
						/// Increment the location of a hash set iterator by one element.
						RIM_INLINE void operator ++ ()
						{
							currentEntry = currentEntry->next;
							
							if ( currentEntry == NULL )
							{
								currentBucket++;
								advanceToNextFullBucket();
							}
						}
						
						
						
						
						/// Increment the location of a hash set iterator by one element.
						RIM_INLINE void operator ++ ( int )
						{
							this->operator++();
						}
						
						
						
						
						/// Test whether or not the current element is valid.
						/**
						  * This will return FALSE when the last element of the hash set
						  * has been iterated over.
						  */
						RIM_INLINE operator Bool () const
						{
							return currentEntry != NULL;
						}
						
						
						
						/// Return the value of the value-value pair pointed to by the iterator.
						RIM_INLINE const T& operator * () const
						{
							return currentEntry->value;
						}
						
						
						
						
						/// Access the current iterator element
						RIM_INLINE const T* operator -> () const
						{
							return &currentEntry->value;
						}
						
						
						
						/// Get the hash of the element pointed to by the iterator.
						RIM_INLINE HashType getHash() const
						{
							return currentEntry->valueHash;
						}
						
						
						
						/// Reset the iterator to the beginning of the hash set.
						RIM_INLINE void reset()
						{
							currentBucket = hashSet.buckets;
							
							// advance until the first element.
							advanceToNextFullBucket();
						}
						
						
						
						
				private:
					
					//********************************************
					//	Private Methods
						
						
						
						
						/// Advance the iterator to the next non-empty bucket.
						RIM_INLINE void advanceToNextFullBucket()
						{
							while ( *currentBucket == NULL && currentBucket != bucketsEnd )
								currentBucket++;
							
							if ( currentBucket == bucketsEnd )
								currentEntry = NULL;
							else
								currentEntry = *currentBucket;
						}
						
						
						
						
					//********************************************
					//	Private Data Members
						
						
						
						
						/// The HashSet that is being iterated over.
						const HashSet<T>& hashSet;
						
						
						
						
						/// The current bucket in the HashSet.
						const Entry* const * currentBucket;
						
						
						
						
						/// The last bucket in the HashSet.
						const Entry* const * bucketsEnd;
						
						
						
						
						/// The current entry in the hash set that the iterator is pointing to.
						const Entry* currentEntry;
						
						
						
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Iterator Method
			
			
			
			
			/// Get a const-iterator for the hash set.
			RIM_INLINE ConstIterator getIterator() const
			{
				return ConstIterator(*this);
			}
			
			
			
			
			/// Get an iterator for the hash set that can modify the hash set.
			RIM_INLINE Iterator getIterator()
			{
				return Iterator(*this);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Load Factor Accessor Methods
			
			
			
			
			RIM_INLINE void setLoadFactor( Float newLoadFactor )
			{
				loadFactor = math::clamp( newLoadFactor, 0.1f, 5.0f );
				loadThreshold = Size(loadFactor*numBuckets);
				
				// Check the load constraint, if necessary, increase the size of the table.
				if ( numElements > loadThreshold )
					resize( math::nextPowerOf2Prime( numBuckets + 1 ) );
			}
			
			
			
			
			RIM_INLINE Float getLoadFactor() const
			{
				return loadFactor;
			}
			
			
			
			
	private:
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Methods
			
			
			
			
			void resize( HashType newNumBuckets )
			{
				Entry** oldBuckets = buckets;
				HashType oldNumBuckets = numBuckets;
				
				// initialize all buckets and resize the array
				numBuckets = newNumBuckets;
				loadThreshold = Size(loadFactor*numBuckets);
				buckets = util::allocate<Entry*>(numBuckets);
				nullBuckets();
				
				// add old elements to the hash set.
				Entry** oldBucket = oldBuckets;
				const Entry* const * const oldBucketsEnd = oldBucket + oldNumBuckets;
				
				while ( oldBucket != oldBucketsEnd )
				{
					Entry* oldEntry = *oldBucket;
					
					while ( oldEntry )
					{
						Entry** bucket = buckets + oldEntry->hash % numBuckets;
						
						// Add the new element.
						if ( *bucket == NULL )
							*bucket = HashSet::newEntry( oldEntry->hash, oldEntry->value );
						else
						{
							Entry* entry = *bucket;
							
							while ( entry->next )
								entry = entry->next;
							
							entry->next = HashSet::newEntry( oldEntry->hash, oldEntry->value );
						}
						
						oldEntry = oldEntry->next;
					}
					
					oldBucket++;
				}
								
				// deallocate all memory currently used by the old buckets
				deleteBuckets( oldBuckets, oldNumBuckets );
			}
			
			
			
			
			RIM_INLINE void nullBuckets()
			{
				Entry** bucket = buckets;
				const Entry* const * const bucketsEnd = bucket + numBuckets;
				
				while ( bucket != bucketsEnd )
				{
					*bucket = NULL;
					bucket++;
				}
			}
			
			
			
			
			RIM_INLINE static void deleteBuckets( Entry** buckets, HashType numBuckets )
			{
				// Delete all entries
				Entry** entry = buckets;
				const Entry* const * const entryEnd = entry + numBuckets;
				
				while ( entry != entryEnd )
				{
					if ( *entry )
						delete (*entry);
					
					entry++;
				}
				
				// Delete the bucket array.
				util::deallocate( buckets );
			}
			
			
			
			
			RIM_INLINE static Entry* newEntry( const Entry& other )
			{
				Entry* result = util::allocate<Entry>();
				
				new (result) Entry( other );
				
				return result;
			}
			
			
			
			
			RIM_INLINE static Entry* newEntry( HashType hash, const T& value )
			{
				Entry* result = util::allocate<Entry>();
				
				new (result) Entry( hash, value );
				
				return result;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			Entry** buckets;
			HashType numBuckets;
			
			
			Size numElements;
			Float loadFactor;
			Size loadThreshold;
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			static const HashType DEFAULT_NUMBER_OF_BUCKETS = 19;
			
			static const Float DEFAULT_LOAD_FACTOR;
			
			
			
};




template < typename T, typename HashType >
const Float		HashSet<T,HashType>:: DEFAULT_LOAD_FACTOR = 0.5f;




//##########################################################################################
//***************************  End Rim Utilities Namespace  ********************************
RIM_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################

#endif // INCLUDE_RIM_HASH_SET_H
