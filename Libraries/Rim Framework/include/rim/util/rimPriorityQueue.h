/*
 *  rimPriorityQueue.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 3/5/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PRIORITY_QUEUE_H
#define INCLUDE_RIM_PRIORITY_QUEUE_H


#include "rimUtilitiesConfig.h"


#include "rimAllocator.h"


//##########################################################################################
//***************************  Start Rim Framework Namespace  ******************************
RIM_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which implements a max-heap-based priority queue.
/**
  * The class uses an array-based heap where larger elements are
  * stored towards the front. When elements are added or removed
  * from the heap, internal state is kept consistent so that the 
  * first item in the queue is the largest.
  *		Element comparisons are done using the greater-than operator (>).
  * Therefore, any class which the user wishes to use with this implementation
  * must provide an overloaded greater-than operator.
  */
template < typename T >
class PriorityQueue
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new empty priority queue with the default capacity.
			RIM_INLINE PriorityQueue()
				:	numElements( 0 ),
					capacity( 0 ),
					array( NULL )
			{
			}
			
			
			
			
			/// Create a new empty priority queue with the specified initial capacity.
			RIM_INLINE PriorityQueue( Size newCapacity )
				:	numElements( 0 ),
					capacity( newCapacity ),
					array( util::allocate<T>(newCapacity) )
			{
			}
			
			
			
			
			/// Create a copy of an existing priority queue, performing a deep copy.
			RIM_INLINE PriorityQueue( const PriorityQueue<T>& other )
				:	numElements( other.numElements ),
					capacity( other.capacity ),
					array( util::allocate<T>(other.capacity) )
			{
				PriorityQueue<T>::copyObjects( array, other.array, numElements );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a priority queue.
			/**
			  * This destructor reclaims all memory previously used
			  * by this priority queue.
			  */
			RIM_INLINE ~PriorityQueue()
			{
				if ( array != NULL )
				{
					// Call the destructors of all objects that were constructed and deallocate the internal array.
					util::destructArray( array, numElements );
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign this priority queue with the contents of another, performing a deep copy.
			RIM_INLINE PriorityQueue<T>& operator = ( const PriorityQueue<T>& other )
			{
				if ( this != &other )
				{
					if ( array != NULL )
					{
						// Call the destructors of all objects that were constructed.
						PriorityQueue<T>::callDestructors( array, numElements );
					}
					
					numElements = other.numElements;
					
					if ( numElements == Size(0) )
						return *this;
					else
					{
						if ( numElements > capacity || array == NULL )
						{
							// Deallocate the internal array.
							if ( array != NULL )
								util::deallocate( array );
							
							// Allocate a new array.
							capacity = other.capacity;
							array = util::allocate<T>( capacity );
						}
						
						// copy the elements from the other queue.
						PriorityQueue<T>::copyObjects( array, other.array, numElements );
					}
				}
				
				return *this;
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Equality Operators
			
			
			
			
			/// Return whether or not whether every entry in this queue is equal to another queue's entries.
			RIM_INLINE Bool operator == ( const PriorityQueue<T>& other ) const
			{
				// If the queues point to the same data, they are equal.
				if ( array == other.array )
					return true;
				else if ( numElements != other.numElements )
					return false;
				
				// Do an element-wise comparison otherwise.
				const T* a = array;
				const T* b = other.array;
				const T* const aEnd = a + numElements;
				
				while ( a != aEnd )
				{
					if ( !(*a == *b) )
						return false;
					
					a++;
					b++;
				}
				
				return true;
			}
			
			
			
			
			RIM_INLINE Bool operator != ( const PriorityQueue<T>& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Add Methods
			
			
			
			
			/// Add a new element to this priority queue.
			RIM_INLINE void add( const T& newElement )
			{
				if ( numElements == capacity )
					doubleCapacity();
				
				Index i = numElements;
				Index parent = getParentIndex(i);
				
				new (array + numElements) T( newElement );
				numElements++;
				
				// reorder the queue's heap so that the new element is in the correct place.
				while ( array[parent] < array[i] )
				{
					T temp = array[parent];
					array[parent] = array[i];
					array[i] = temp;
					
					i = parent;
					parent = getParentIndex(i);
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Remove Methods
			
			
			
			
			/// Remove the largest element from the priority queue.
			RIM_INLINE void remove()
			{
				RIM_DEBUG_ASSERT_MESSAGE( numElements != Size(0), "Cannot remove element from an empty priority queue." );
				
				// Decrement the number of elements in the queue.
				numElements--;
				
				// Copy the last element in the queue's array into the largest element's location.
				array[0] = array[numElements];
				
				// Call the destructor for the old last element.
				array[numElements].~T();
				
				// Convert the new array into a heap, starting at the first element.
				this->heapify( 0 );
			}
			
			
			
			
			/// Remove the element with the specified value from the priority queue.
			/**
			  * The method returns whether or not the value was able to be removed.
			  */
			RIM_INLINE Bool remove( const T& element )
			{
				Index i;
				
				if ( !getIndexRecursive( element, 0, i ) )
					return false;
				
				// Decrement the number of elements in the queue.
				numElements--;
				
				// Copy the last element in the queue's array into the largest element's location.
				array[i] = array[numElements];
				
				// Call the destructor for the old last element.
				array[numElements].~T();
				
				// Convert the new array into a heap, starting at the removed element.
				this->heapify( i );
				
				return true;
			}
			
			
			
			
			/// Remove the element at the specified index from the priority queue.
			/**
			  * Indices start at 0 for the largest element in the queue and must be
			  * less than the number of elements in the queue.
			  */
			RIM_INLINE void removeAtIndex( Index i )
			{
				RIM_DEBUG_ASSERT_MESSAGE( i < numElements, "Cannot remove element at invalid index in priority queue." );
				
				// Decrement the number of elements in the queue.
				numElements--;
				
				// Copy the last element in the queue's array into the largest element's location.
				array[i] = array[numElements];
				
				// Call the destructor for the old last element.
				array[numElements].~T();
				
				// Convert the new array into a heap, starting at the first element.
				this->heapify( i );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Methods
			
			
			
			
			/// Ensure that the heap is propery ordered after the specified element was changed.
			RIM_INLINE void update( Index i )
			{
				if ( i > 0 )
				{
					Index parent = getParentIndex(i);
					
					// Did the entry increase its value?
					if ( array[parent] < array[i] )
					{
						do
						{
							T temp = array[parent];
							array[parent] = array[i];
							array[i] = temp;
							
							i = parent;
							parent = getParentIndex(i);
						}
						while ( i > 0 && array[parent] < array[i] );
						
						return;
					}
				}
				
				this->heapify( i );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Index Accessor Methods
			
			
			
			
			/// Get the index of the specified value in this priority queue.
			/**
			  * The method returns whether or not the given value was contained
			  * in the queue.
			  */
			RIM_INLINE Bool getIndex( const T& value, Index& index ) const
			{
				return getIndexRecursive( value, 0, index );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Contains Method
			
			
			
			
			/// Return whether or not the specified element is in the priority queue.
			RIM_INLINE Bool contains( const T& element ) const
			{
				return containsRecursive( element, 0 );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Element Accessor Methods
			
			
			
			
			/// Return a reference to the largest element in the priority queue.
			RIM_INLINE T& getFirst()
			{
				RIM_DEBUG_ASSERT_MESSAGE( numElements != Size(0), "Cannot get first element from empty priority queue" );
				
				return *array;
			}
			
			
			
			
			/// Return a const reference to the largest element in the priority queue.
			RIM_INLINE const T& getFirst() const
			{
				RIM_DEBUG_ASSERT_MESSAGE( numElements != Size(0), "Cannot get first element from empty priority queue" );
				
				return *array;
			}
			
			
			
			
			/// Return a reference to the element in this priority queue at the specified index.
			RIM_INLINE T& operator [] ( Index i )
			{
				RIM_DEBUG_ASSERT_MESSAGE( i < numElements, "Cannot get invalid element from priority queue" );
				
				return array[i];
			}
			
			
			
			
			/// Return a const reference to the element in this priority queue at the specified index.
			RIM_INLINE const T& operator [] ( Index i ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( i < numElements, "Cannot get invalid element from priority queue" );
				
				return array[i];
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Clear Methods
			
			
			
			
			/// Clear the contents of this priority queue.
			/**
			  * This method calls the destructors of all elements in the priority queue
			  * and sets the number of elements to zero while maintaining the
			  * queue's capacity.
			  */
			RIM_INLINE void clear()
			{
				if ( array != NULL )
					PriorityQueue<T>::callDestructors( array, numElements );
				
				numElements = Size(0);
			}
			
			
			
			
			/// Clear the contents of this priority queue and reclaim the allocated memory.
			/**
			  * This method performs the same function as the clear() method, but
			  * also deallocates the previously allocated internal array. Calling this
			  * method is equivalent to assigning a new queue instance to this one.
			  */
			RIM_INLINE void reset()
			{
				if ( array != NULL )
				{
					PriorityQueue<T>::callDestructors( array, numElements );
					util::deallocate( array );
				}
				
				capacity = Size(0);
				array = NULL;
				numElements = Size(0);
			}
			
			
			
			
			/// Clear the contents of this priority queue and reclaim the allocated memory.
			/**
			  * This method performs the same function as the clear() method, but
			  * also deallocates the previously allocated internal array and reallocates
			  * it to a small initial starting size. Calling this method is equivalent
			  * to assigning a new priority queue instance to this one. This version of
			  * the reset() method allows the caller to specify the new starting
			  * capacity of the queue.
			  */
			RIM_INLINE void reset( Size newCapacity )
			{
				if ( array != NULL )
				{
					PriorityQueue<T>::callDestructors( array, numElements );
					util::deallocate( array );
				}
				
				capacity = newCapacity;
				array = util::allocate<T>( capacity );
				numElements = Size(0);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return whether or not the priority queue has any elements.
			/** 
			  * This method returns TRUE if the size of the priority queue
			  * is greater than zero, and FALSE otherwise.
			  * 
			  * @return whether or not the priority queue has any elements.
			  */
			RIM_INLINE Bool isEmpty() const
			{
				return numElements == Size(0);
			}
			
			
			
			
			/// Get the number of elements in the priority queue.
			/** 
			  * @return the number of elements in the priority queue.
			  */
			RIM_INLINE Size getSize() const
			{
				return numElements;
			}
			
			
			
			
			/// Get the current capacity of the priority queue.
			/**
			  * The capacity is the maximum number of elements that the
			  * priority queue can hold before it will have to resize its
			  * internal array.
			  * 
			  * @return the current capacity of the priority queue.
			  */
			RIM_INLINE Size getCapacity() const
			{
				return capacity;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Heap Methods
			
			
			
			
			/// Recursively query the priority queue to find the index of a value.
			/**
			  * This method has O(log n) complexity due to the priority queue's
			  * internal heap data structure.
			  */
			RIM_INLINE Bool getIndexRecursive( const T& value, Index i, Index& index ) const
			{
				if ( i >= numElements || array[i] < value )
					return false;
				else if ( array[i] == value )
				{
					index = i;
					return true;
				}
				
				if ( getIndexRecursive( value, getChildIndex1(i), index ) ||
					getIndexRecursive( value, getChildIndex2(i), index ) )
					return true;
				
				return false;
			}
			
			
			
			
			/// Recursively query the priorit queue to see if a value is contained.
			/**
			  * This method has O(log n) complexity due to the priority queue's
			  * internal heap data structure.
			  */
			RIM_INLINE Bool containsRecursive( const T& value, Index i ) const
			{
				if ( i >= numElements || array[i] < value )
					return false;
				else if ( array[i] == value )
					return true;
				
				if ( containsRecursive( value, getChildIndex1(i) ) ||
					containsRecursive( value, getChildIndex2(i) ) )
					return true;
				
				return false;
			}
			
			
			
			
			/// Get the index of a child elements's parent element given the child element's index.
			/**
			  * If the child index is zero, the method returns 0 because this child element is
			  * at the top of the heap and has no parent by definition.
			  */
			RIM_INLINE static Index getParentIndex( Index child )
			{
				if ( child == Index(0) )
					return Index(0);
				
				return (child - Index(1))/Index(2);
			}
			
			
			
			
			/// Get the index of the left child element given the parent element's index.
			RIM_INLINE static Index getChildIndex1( Index parent )
			{
				return (parent << 1) + Index(1);
			}
			
			
			
			
			/// Get the index of the right child element given the parent element's index.
			RIM_INLINE static Index getChildIndex2( Index parent )
			{
				return (parent << 1) + Index(2);
			}
			
			
			
			
			/// Convert the specified sub-heap, with root at index i, into a heap.
			RIM_INLINE void heapify( Index i )
			{
				while ( i < numElements )
				{
					Index childIndex1 = getChildIndex1(i);
					Index childIndex2 = getChildIndex2(i);
					Index max;
					
					if ( childIndex1 < numElements && array[i] < array[childIndex1] )
						max = childIndex1;
					else
						max = i;
					
					if ( childIndex2 < numElements && array[max] < array[childIndex2] )
						max = childIndex2;
					
					if ( max == i )
						break;
					
					T temp = array[max];
					array[max] = array[i];
					array[i] = temp;
					i = max;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Array-Management Methods
			
			
			
			
			RIM_INLINE void doubleCapacity()
			{
				// check to see if the array has not yet been allocated.
				if ( capacity == 0 )
				{
					// allocate the array to hold elements.
					capacity = DEFAULT_INITIAL_CAPACITY;
					array = util::allocate<T>( capacity );
				}
				else
					resize( capacity << 1 );
			}
			
			
			
			
			/// Double the size of the element array to increase the capacity of the priority queue.
			/**
			  * This method deallocates the previously used array, and then allocates
			  * a new block of memory with a size equal to double the previous size.
			  * It then copies over all of the previous elements into the new array.
			  */
			void resize( Size newCapacity )
			{
				// Update the capacity and allocate a new array.
				capacity = newCapacity;
				T* oldArray = array;
				array = util::allocate<T>( capacity );
				
				// copy the elements from the old array to the new array.
				PriorityQueue<T>::moveObjects( array, oldArray, numElements );
				
				// deallocate the old array.
				util::deallocate( oldArray );
			}
			
			
			
			
			RIM_INLINE static void callDestructors( T* array, Size number )
			{
				const T* const arrayEnd = array + number;
				
				while ( array != arrayEnd )
				{
					array->~T();
					array++;
				}
			}
			
			
			
			
			RIM_INLINE static void copyObjects( T* destination, const T* source, Size number )
			{
				const T* const sourceEnd = source + number;
				
				while ( source != sourceEnd )
				{
					new (destination) T(*source);
					destination++;
					source++;
				}
			}
			
			
			
			
			RIM_INLINE static void moveObjects( T* destination, const T* source, Size number )
			{
				const T* const sourceEnd = source + number;
				
				while ( source != sourceEnd )
				{
					// copy the object from the source to destination
					new (destination) T(*source);
					
					// call the destructors on the source
					source->~T();
					
					destination++;
					source++;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the array containing all elements in the queue.
			/**
			  * Data is stored in this array using an array-based max-heap representation.
			  */
			T* array;
			
			
			
			
			/// The number of elements in the priority queue.
			Size numElements;
			
			
			
			
			/// The number of possible elements that the current queue could hold without resizing.
			Size capacity;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The default initial capacity of a priority queue.
			/**
			  * This value is used whenever the creator of the queue does
			  * not specify the initial capacity of the priority queue.
			  */
			static const Size DEFAULT_INITIAL_CAPACITY;
			
			
			
			
};




template < typename T >
const Size PriorityQueue<T>:: DEFAULT_INITIAL_CAPACITY = 8;




//##########################################################################################
//***************************  End Rim Framework Namespace  ********************************
RIM_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PRIORITY_QUEUE_H
