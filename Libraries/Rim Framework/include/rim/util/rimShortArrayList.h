/*
 *  rimShortArrayList.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 5/9/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SHORT_ARRAY_LIST_H
#define INCLUDE_RIM_SHORT_ARRAY_LIST_H


#include "rimUtilitiesConfig.h"


#include "rimAllocator.h"


#include <stdio.h>

//##########################################################################################
//***************************  Start Rim Utilities Namespace  ******************************
RIM_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An array-based list class that uses a fixed-size local buffer for its elements.
/** 
  * This fixed-size buffer doesn't require a dynamic allocation and so can improve
  * both runtime cache performance (as well as reducing unnecessary allocations for
  * short lists of elements). When the list grows beyond that initial fixed-size capacity,
  * the elements are reallocated in a dynamic array, allowing the list to be any size.
  *
  * This class can be useful anywhere an application only requires a few elements to be
  * stored on average, and so the elements can be stored locally.
  */
template < typename T, Size localCapacity = Size(4) >
class ShortArrayList
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new empty short short array list with the default capacity of 8 elements.
			/**
			  * This is a lightweight operation and the short array list doesn't initialize or allocate any
			  * memory until an element is added to it.
			  */
			RIM_INLINE ShortArrayList()
				:	array( (T*)localStorage ),
					numElements( 0 ),
					capacity( localCapacity )
			{
			}
			
			
			
			
			/// Create a new short array list with its internal array initialized to the specified capacity.
			RIM_INLINE ShortArrayList( Size newCapacity )
				:	numElements( 0 )
			{
				if ( newCapacity > localCapacity )
				{
					capacity = newCapacity;
					array = util::allocate<T>( newCapacity );
				}
				else
				{
					capacity = localCapacity;
					array = (T*)localStorage;
				}
			}
			
			
			
			
			/// Create a new short array list with its internal array initialized with element from an external array.
			/** 
			  * The initial capacity and size of the short array list is set to the number of
			  * elements that are to be copied from the given array.
			  * 
			  * @param elements - an array of contiguous element objects from which to initialize this short array list.
			  * @param newNumElements - the number of elements to copy from the element array.
			  */
			RIM_INLINE ShortArrayList( const T* elements, Size newNumElements )
				:	numElements( newNumElements )
			{
				if ( newNumElements > localCapacity )
				{
					capacity = newNumElements;
					array = util::allocate<T>( newNumElements );
				}
				else
				{
					capacity = localCapacity;
					array = (T*)localStorage;
				}
				
				copyObjects( array, elements, numElements );
			}
			
			
			
			
			/// Create a copy of an existing short array list. This is a deep copy.
			RIM_INLINE ShortArrayList( const ShortArrayList& other )
				:	numElements( other.numElements )
			{
				if ( numElements > localCapacity )
				{
					capacity = other.capacity;
					array = util::allocate<T>( capacity );
				}
				else
				{
					capacity = localCapacity;
					array = (T*)localStorage;
				}
				
				copyObjects( array, other.array, numElements );
			}
			
			
			
			
			/// Create a copy of an existing short array list. This is a deep copy.
			template < Size otherLocalCapacity >
			RIM_INLINE ShortArrayList( const ShortArrayList<T,otherLocalCapacity>& other )
				:	numElements( other.numElements )
			{
				if ( numElements > localCapacity )
				{
					capacity = other.capacity;
					array = util::allocate<T>( capacity );
				}
				else
				{
					capacity = localCapacity;
					array = (T*)localStorage;
				}
				
				copyObjects( array, other.array, numElements );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this short array list, releasing all internal state.
			RIM_INLINE ~ShortArrayList()
			{
				// Call the destructors of all objects that were constructed.
				callDestructors( array, numElements );
				
				// Deallocate the internal array if necessary.
				if ( array != (T*)localStorage )
					util::deallocate( array );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of one short array list to another, copying all elements.
			RIM_NO_INLINE ShortArrayList& operator = ( const ShortArrayList& other );
			
			
			
			
			/// Assign the contents of one short array list to another, copying all elements.
			template < Size otherLocalCapacity >
			RIM_NO_INLINE ShortArrayList<T,localCapacity>& operator = ( const ShortArrayList<T,otherLocalCapacity>& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Equality Operators
			
			
			
			
			/// Return whether or not whether every entry in this list is equal to another list's entries.
			template < Size otherLocalCapacity >
			RIM_INLINE Bool operator == ( const ShortArrayList<T,otherLocalCapacity>& other ) const
			{
				// If the arraylists point to the same data, they are equal.
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
			
			
			
			
			/// Return whether or not whether any entry in this list is not equal to another list's entries.
			template < Size otherLocalCapacity >
			RIM_INLINE Bool operator != ( const ShortArrayList<T,otherLocalCapacity>& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Add Methods
			
			
			
			
			/// Add an element to the end of the list.
			/** 
			  * If the capacity of the short array list is not great enough to hold
			  * the new element, then the internal array is reallocated to be 
			  * double the size and all elements are copied to the new array.
			  * 
			  * @param newElement - the new element to add to the end of the list
			  */
			RIM_INLINE void add( const T& newElement )
			{
				if ( numElements == capacity )
					doubleCapacity();
				
				new (array + numElements) T( newElement );
				numElements++;
			}
			
			
			
			
			/// Add the contents of one ShortArrayList to another.
			/**
			  * This method has the effect of adding each element of
			  * the given list to the end of this short array list in order.
			  * 
			  * @param list - the list to be added to the end of this list
			  */
			template < Size otherLocalCapacity >
			RIM_INLINE void addAll( const ShortArrayList<T,otherLocalCapacity>& list )
			{
				// resize the internal array if necessary.
				if ( numElements + list.numElements > capacity )
					doubleCapacityUpTo( numElements + list.numElements );
				
				ShortArrayList<T,localCapacity>::copyObjects( array + numElements, list.array, list.numElements );
				
				numElements += list.numElements;
			}
			
			
			
			
			/// Add the contents of the specified array pointer to the end of the list.
			/**
			  * This method has the effect of adding each element of
			  * the given list to the end of this short array list in order.
			  * 
			  * @param list - the list to be added to the end of this list
			  */
			RIM_INLINE void addAll( const T* array, Size number )
			{
				// resize the internal array if necessary.
				if ( numElements + number > capacity )
					doubleCapacityUpTo( numElements + number );
				
				ShortArrayList<T,localCapacity>::copyObjects( array + numElements, number, number );
				
				numElements += number;
			}
			
			
			
			
			/// Insert an element at the specified index of the list.
			/** 
			  * The method returns TRUE if the element was successfully inserted
			  * into the short array list. If the index is outside of the bounds of the
			  * short array list, then FALSE is returned, indicating that the element
			  * was not inserted. If needed, the short array list is resized to double
			  * its current size in order to hold the new element. This method
			  * has time complexity of O(n/2) because all subsequent elements in
			  * the short array list have to be moved towards the end of the list by one
			  * index.
			  * 
			  * @param newElement - the new element to insert into the short array list.
			  * @param index - the index at which to insert the new element.
			  * @return whether or not the element was successfully inserted into the short array list.
			  */
			Bool insert( Index index, const T& newElement );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Set Method
			
			
			
			
			/// Set an element at the specified index of the list to a new value.
			/** 
			  * This method returns TRUE if the specified index is within the bounds
			  * of the short array list, indicating that the element was successfully set
			  * at that position in the short array list. Otherwise, FALSE is returned, 
			  * indicating that the index was out of bounds of the short array list. This
			  * method has worst-case time complexity of O(1).
			  * 
			  * @param newElement - the new element to set in the list.
			  * @param index - the index at which to set the new element.
			  * @return whether or not the element was successfully set to the new value.
			  */
			RIM_INLINE Bool set( Index index, const T& newElement )
			{
				if ( index < numElements )
				{
					// destroy the old element.
					array[index].~T();
					
					// replace it with the new element.
					new (array + index) T(newElement);
					
					return true;
				}
				else
					return false;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Remove Methods
			
			
			
			
			/// Remove the element at the specified index, ordered version.
			/** 
			  * If the index is within the bounds of the list ( >= 0 && < getSize() ),
			  * then the list element at that index is removed and TRUE is returned,
			  * indicating that the remove operation was successful.
			  * Otherwise, FALSE is returned and the list
			  * is unaffected. The order of the list is unaffected, meaning that 
			  * all of the elements after the removed element must be copied one 
			  * index towards the beginning of the list. This gives the method
			  * an average case performance of O(n/2) where n is the number of 
			  * elements in the short array list.
			  * 
			  * @param index - the index of the list element to remove.
			  * @return whether or not the element was successfully removed.
			  */
			RIM_INLINE Bool removeAtIndex( Index index )
			{
				if ( index < numElements )
				{
					// shift all elements forward in the array one index.
					numElements--;
					
					// Destroy the element to be removed.
					array[index].~T();
					
					// Move the objects to fill the hole in the array.
					ShortArrayList<T,localCapacity>::moveObjects( array + index, array + index + 1, numElements - index );
					
					return true;
				}
				else
					return false;
			}
			
			
			
			
			
			/// Remove the element at the specified index, unordered version.
			/** 
			  * If the index is within the bounds of the list ( >= 0 && < getSize() ),
			  * then the list element at that index is removed and TRUE is returned,
			  * indicating that the remove operation was successful.
			  * Otherwise, FALSE is returned and the list is unaffected. 
			  * The order of the list is affected when this method
			  * successfully removes the element. It works by replacing the element
			  * at the index to be removed with the last element in the list. This 
			  * gives the method a worst case time complexity of O(1), which is
			  * much faster than the ordered remove methods.
			  * 
			  * @param index - the index of the list element to remove.
			  * @return whether or not the element was successfully removed.
			  */
			RIM_INLINE Bool removeAtIndexUnordered( Index index )
			{
				if ( index < numElements )
				{
					numElements--;
					
					// Destroy the element to be removed.
					T* destination = array + index;
					destination->~T();
					
					// Replace it with the last element if necessary.
					if ( index != numElements )
					{
						T* source = array + numElements;
						new (destination) T(*source);
						source->~T();
					}
					
					return true;
				}
				else
					return false;
			}
			
			
			
			
			/// Remove the first element equal to the parameter element, ordered version.
			/** 
			  * If this element is found, then it is removed and TRUE 
			  * is returned. Otherwise, FALSE is returned and the list is unaffected.
			  * The order of the list is unaffected, meaning that all of the elements after 
			  * the removed element must be copied one index towards the beginning 
			  * of the list. This gives the method an average case performance
			  * of O(n) where n is the number of elements in the short array list. This
			  * method's complexity is worse than the ordered index remove method
			  * because it must search through the list for the element and then
			  * copy all subsequent elements one position nearer to the start of the
			  * list.
			  *
			  * @param element - the list element to remove the first instance of.
			  * @return whether or not the element was successfully removed.
			  */
			RIM_INLINE Bool remove( const T& object )
			{
				const T* const end = array + numElements;
				
				for ( T* element = array; element != end; element++ )
				{
					if ( *element == object )
					{
						numElements--;
						
						// Destroy the element to be removed.
						element->~T();
						
						// Move the objects to fill the hole in the array.
						ShortArrayList<T,localCapacity>::moveObjects( element, element + 1, end - element - 1 );
						
						return true;
					}
				}
				
				return false;
			}
			
			
			
			
			/// Remove the first element equal to the parameter element, unordered version.
			/** 
			  * If this element is found, then it is removed and TRUE 
			  * is returned. Otherwise, FALSE is returned and the list is unaffected.
			  * The order of the list is affected when this method
			  * successfully removes the element. It works by replacing the element
			  * at the index to be removed with the last element in the list. This 
			  * gives the method a worst case time complexity of O(n), which is
			  * much faster than the ordered remove methods (O(n^2)).
			  *
			  * @param object - the list element to remove the first instance of.
			  * @return whether or not the element was successfully removed.
			  */
			RIM_INLINE Bool removeUnordered( const T& object )
			{
				const T* const end = array + numElements;
				
				for ( T* element = array; element != end; element++ )
				{
					if ( *element == object )
					{
						numElements--;
						
						// Destroy the element to be removed.
						element->~T();
						const T* last = array + numElements;
						
						// Replace it with the last element if possible.
						if ( element != last )
						{
							new (element) T(*last);
							last->~T();
						}
						
						return true;
					}
				}
				
				return false;
			}
			
			
			
			
			/// Remove the last element in the short array list.
			/** 
			  * If the short array list has elements remaining in it, then
			  * the last element in the short array list is removed and TRUE is returned.
			  * If the short array list has no remaining elements, then FALSE is returned,
			  * indicating that the list was unchanged. This method has worst
			  * case O(1) time complexity.
			  * 
			  * @return whether or not the last element was successfully removed.
			  */
			RIM_INLINE Bool removeLast()
			{
				if ( numElements != Size(0) )
				{
					numElements--;
					
					// destroy the last element.
					array[numElements].~T();
					
					return true;
				}
				else
					return false;
			}
			
			
			
			
			/// Remove the last N elements from the short array list.
			/** 
			  * If the short array list has at least N elements remaining in it, then
			  * the last N elements in the short array list are removed and N is returned.
			  * If the short array list has less than N elements, then the list will be
			  * completely cleared, resulting in an empty list. The method returns the
			  * number of elements successfully removed.
			  * 
			  * @return the number of elements removed from the end of the list.
			  */
			RIM_INLINE Size removeLast( Size number )
			{
				number = numElements > number ? number : numElements;
				numElements -= number;
				
				// destroy the elements that were removed.
				ShortArrayList<T,localCapacity>::callDestructors( array + numElements, number );
				
				return number;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Clear Methods
			
			
			
			
			/// Clear the contents of this short array list.
			/**
			  * This method calls the destructors of all elements in the short array list
			  * and sets the number of elements to zero while maintaining the
			  * array's capacity.
			  */
			RIM_INLINE void clear()
			{
				if ( array != NULL )
					ShortArrayList<T,localCapacity>::callDestructors( array, numElements );
				
				numElements = Size(0);
			}
			
			
			
			
			/// Clear the contents of this short array list and reclaim the allocated memory.
			/**
			  * This method performs the same function as the clear() method, but
			  * also deallocates the previously allocated internal array and reallocates
			  * it to an small initial starting size. Calling this method is equivalent
			  * to assigning a brand new short array list instance to this one.
			  */
			RIM_INLINE void reset()
			{
				if ( array != NULL )
					util::destructArray( array, numElements );
				
				capacity = Size(0);
				array = NULL;
				numElements = Size(0);
			}
			
			
			
			
			/// Clear the contents of this short array list and reclaim the allocated memory.
			/**
			  * This method performs the same function as the clear() method, but
			  * also deallocates the previously allocated internal array and reallocates
			  * it to a small initial starting size. Calling this method is equivalent
			  * to assigning a brand new short array list instance to this one. This version of
			  * the reset() method allows the caller to specify the new starting
			  * capacity of the short array list.
			  */
			RIM_INLINE void reset( Size newCapacity )
			{
				if ( array != NULL )
					util::destructArray( array, numElements );
				
				capacity = newCapacity;
				array = util::allocate<T>( capacity );
				numElements = Size(0);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Contains Method
			
			
			
			
			/// Return whether or not the specified element is in this list.
			/**
			  * The method has average case O(n/2) time complexity, where
			  * n is the number of elements in the short array list. This method
			  * is here for convenience. It just calls the short array list's
			  * getIndex() method, and tests to see if the return value is
			  * not equal to -1. It is recommended that if one wants the 
			  * index of the element as well as whether or not it is contained
			  * in the list, they should use the getIndex() method exclusively,
			  * and check the return value to make sure that the element is in the
			  * list. This avoids the double O(n/2) lookup that would be performed
			  * one naively called this method and then that method.
			  * 
			  * @param element - the element to check to see if it is contained in the list.
			  * @return whether or not the specified element is in the list.
			  */
			RIM_INLINE Bool contains( const T& object ) const
			{
				T* element = array;
				const T* const end = array + numElements;
				
				while ( element != end )
				{
					if ( *element == object )
						return true;
					
					element++;
				}
				
				return false;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Element Find Method
			
			
			
			
			/// Get the index of the element equal to the parameter object.
			/** 
			  * If the specified element is not found within the list,
			  * then FALSE is returned. Otherwise, FALSE is returned and the index of
			  * the element in the list is placed in the output index parameter.
			  * 
			  * @param element - the element to find in the short array list.
			  * @param index - a reference to the variable in which to place the index.
			  * @return TRUE if the object was found, FALSE otherwise.
			  */
			RIM_INLINE Bool getIndex( const T& object, Index& index ) const
			{
				T* element = array;
				const T* const end = array + numElements;
				
				while ( element != end )
				{
					if ( *element == object )
					{
						index = element - array;
						return true;
					}
					
					element++;
				}
				
				return false;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Element Accessor Methods
			
			
			
			
			/// Return the element at the specified index.
			/** 
			  * If the specified index is not within the valid bounds
			  * of the short array list, then an exception is thrown indicating
			  * an index out of bounds error occurred. This is the non-const version
			  * of the get() method, allowing modification of the element.
			  * 
			  * @param index - the index of the desired element.
			  * @return a const reference to the element at the index specified by the parameter.
			  */
			RIM_INLINE T& get( Index index )
			{
				RIM_DEBUG_ASSERT_MESSAGE( index < numElements, "Cannot access invalid index in short array list." );
				
				return array[index];
			}
			
			
			
			
			/// Return the element at the specified index.
			/** 
			  * If the specified index is not within the valid bounds
			  * of the short array list, then an exception is thrown indicating
			  * an index out of bounds error occurred. This is the const version
			  * of the get() method, disallowing modification of the element.
			  * 
			  * @param index - the index of the desired element.
			  * @return a const reference to the element at the index specified by the parameter.
			  */
			RIM_INLINE const T& get( Index index ) const
			{
				RIM_DEBUG_ASSERT( index < numElements );
				
				return array[index];
			}
			
			
			
			
			/// Return a reference to the first element in the short array list.
			RIM_INLINE T& getFirst()
			{
				RIM_DEBUG_ASSERT( numElements != Size(0) );
				
				return *array;
			}
			
			
			
			
			/// Return a const reference to the first element in the short array list.
			RIM_INLINE const T& getFirst() const
			{
				RIM_DEBUG_ASSERT( numElements != Size(0) );
				
				return *array;
			}
			
			
			
			
			/// Return a reference to the last element in the short array list.
			RIM_INLINE T& getLast()
			{
				RIM_DEBUG_ASSERT( numElements != Size(0) );
				
				return *(array + numElements - 1);
			}
			
			
			
			
			/// Return a const reference to the last element in the short array list.
			RIM_INLINE const T& getLast() const
			{
				RIM_DEBUG_ASSERT( numElements != Size(0) );
				
				return *(array + numElements - 1);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Element Accessor Operators
			
			
			
			
			/// Return the element at the specified index.
			/** 
			  * If the specified index is not within the valid bounds
			  * of the short array list, then an exception is thrown indicating
			  * an index out of bounds error occurred. This is the const version
			  * of the operator (), disallowing modification of the element.
			  * 
			  * @param index - the index of the desired element.
			  * @return a const reference to the element at the index specified by the parameter.
			  */
			RIM_INLINE T& operator () ( Index index )
			{
				RIM_DEBUG_ASSERT( index < numElements );
				
				return array[index];
			}
			
			
			
			
			/// Return the element at the specified index.
			/** 
			  * If the specified index is not within the valid bounds
			  * of the short array list, then an exception is thrown indicating
			  * an index out of bounds error occurred. This is the const version
			  * of the operator (), disallowing modification of the element.
			  * 
			  * @param index - the index of the desired element.
			  * @return a const reference to the element at the index specified by the parameter.
			  */
			RIM_INLINE const T& operator () ( Index index ) const
			{
				RIM_DEBUG_ASSERT( index < numElements );
				
				return array[index];
			}
			
			
			
			
			/// Return the element at the specified index.
			/** 
			  * If the specified index is not within the valid bounds
			  * of the short array list, then an exception is thrown indicating
			  * an index out of bounds error occurred.
			  * 
			  * @param index - the index of the desired element.
			  * @return a const reference to the element at the index specified by the parameter.
			  */
			RIM_INLINE T& operator [] ( Index index )
			{
				RIM_DEBUG_ASSERT( index < numElements );
				
				return array[index];
			}
			
			
			
			
			/// Return the element at the specified index.
			/** 
			  * If the specified index is not within the valid bounds
			  * of the short array list, then an exception is thrown indicating
			  * an index out of bounds error occurred. This is the const version
			  * of the operator [], disallowing modification of the element.
			  * 
			  * @param index - the index of the desired element.
			  * @return a const reference to the element at the index specified by the parameter.
			  */
			RIM_INLINE const T& operator [] ( Index index ) const
			{
				RIM_DEBUG_ASSERT( index < numElements );
				
				return array[index];
			}
			
			
			
			
			/// Return a const pointer to the beginning of the internal array.
			RIM_INLINE const T* getPointer() const
			{
				return array;
			}
			
			
			
			
			/// Return a pointer to the beginning of the internal array.
			RIM_INLINE T* getPointer()
			{
				return array;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return whether or not the short array list has any elements.
			/** 
			  * This method returns TRUE if the size of the short array list
			  * is greater than zero, and FALSE otherwise.
			  * This method is here for convenience.
			  * 
			  * @return whether or not the short array list has any elements.
			  */
			RIM_INLINE Bool isEmpty() const
			{
				return numElements == Size(0);
			}
			
			
			
			
			/// Get the number of elements in the short array list.
			/** 
			  * @return the number of elements in the short array list.
			  */
			RIM_INLINE Size getSize() const
			{
				return numElements;
			}
			
			
			
			
			/// Get the current capacity of the short array list.
			/**
			  * The capacity is the maximum number of elements that the
			  * short array list can hold before it will have to resize its
			  * internal array.
			  * 
			  * @return the current capacity of the short array list.
			  */
			RIM_INLINE Size getCapacity() const
			{
				return capacity;
			}
			
			
			
			
			/// Set the capacity of the short array list.
			/**
			  * The capacity is the maximum number of elements that the
			  * short array list can hold before it will have to resize its
			  * internal array. The capacity of the short array list is set to
			  * the specified value unless this value is smaller than the
			  * number of elements in the short array list. If so, the capacity
			  * remains unchanged.
			  * 
			  * @param newCapacity the desired capacity of the short array list.
			  */
			RIM_INLINE void setCapacity( Size newCapacity )
			{
				if ( newCapacity < localCapacity || newCapacity < numElements || newCapacity == 0 )
					return;
				else
					resize( newCapacity );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Iterator Class
			
			
			
			
			/// Iterator class for an short array list.
			/** 
			  * The purpose of this class is to iterate through all
			  * or some of the elements in the short array list, making changes as
			  * necessary to the elements.
			  */
			class Iterator
			{
				public:
					
					//********************************************
					//	Constructor
						
						
						
						/// Create a new ShortArrayList iterator from a reference to a list.
						RIM_INLINE Iterator( ShortArrayList<T,localCapacity>& newList )
							:	list( newList ),
								current( newList.array ),
								end( newList.array + newList.numElements )
						{
						}
						
						
						
					//********************************************
					//	Public Methods
						
						
						
						/// Prefix increment operator.
						RIM_INLINE void operator ++ ()
						{
							RIM_DEBUG_ASSERT_MESSAGE( current < end, "Cannot increment short array list iterator past end of list." );
							
							current++;
						}
						
						
						
						
						/// Postfix increment operator.
						RIM_INLINE void operator ++ ( int )
						{
							RIM_DEBUG_ASSERT_MESSAGE( current < end, "Cannot increment short array list iterator past end of list." );
							
							current++;
						}
						
						
						
						
						/// Return whether or not the iterator is at the end of the list.
						/** 
						  * If the iterator is at the end of the list, return FALSE.
						  * Otherwise, return TRUE, indicating that there are more
						  * elements to iterate over.
						  * 
						  * @return FALSE if at the end of list, otherwise TRUE.
						  */
						RIM_INLINE operator Bool () const
						{
							return current < end;
						}
						
						
						
						
						/// Return a reference to the current iterator element.
						RIM_INLINE T& operator * ()
						{
							return *current;
						}
						
						
						
						
						/// Access the current iterator element.
						RIM_INLINE T* operator -> ()
						{
							return current;
						}
						
						
						
						
						/// Remove the current element from the list.
						/**
						  * This method calls the removeAtIndex() method of the 
						  * iterated short array list, and therefore has an average
						  * time complexity of O(n/2) where n is the size of the
						  * short array list.
						  */
						RIM_INLINE void remove()
						{
							list.removeAtIndex( getIndex() );
							current = current == list.array ? current : current - 1;
							end--;
						}
						
						
						
						
						/// Remove the current element from the list.
						/**
						  * This method calls the removeAtIndexUnordered() method of the 
						  * iterated short array list, and therefore has an average
						  * time complexity of O(1).
						  */
						RIM_INLINE void removeUnordered()
						{
							list.removeAtIndexUnordered( getIndex() );
							current = current == list.array ? current : current - 1;
							end--;
						}
						
						
						
						
						/// Reset the iterator to the beginning of the list.
						RIM_INLINE void reset()
						{
							current = list.array;
							end = current + list.numElements;
						}
						
						
						
						
						/// Get the index of the next element to be iterated over.
						RIM_INLINE Index getIndex()
						{
							return current - list.array;
						}
						
						
						
					
				private:
					
					//********************************************
					//	Private Data Members
						
						
						
						/// The current position of the iterator
						T* current;
						
						
						
						
						/// A pointer to one element past the end of the list.
						const T* end;
						
						
						
						
						/// The list that is being iterated over.
						ShortArrayList<T,localCapacity>& list;
						
						
						
						
						/// Make the const iterator class a friend.
						friend class ShortArrayList<T,localCapacity>::ConstIterator;
						
						
						
						
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	ConstIterator Class
			
			
			
			
			/// An iterator class for an short array list which can't modify it.
			/** 
			  * The purpose of this class is to iterate through all
			  * or some of the elements in the short array list.
			  */
			class ConstIterator
			{
				public:
					
					//********************************************
					//	Constructor
						
						
						
						/// Create a new ShortArrayList iterator from a reference to a list.
						RIM_INLINE ConstIterator( const ShortArrayList<T,localCapacity>& newList )
							:	list( newList ),
								current( newList.array ),
								end( newList.array + newList.numElements )
						{
						}
						
						
						
						/// Create a new const short array list iterator from a non-const iterator.
						RIM_INLINE ConstIterator( const Iterator& iterator )
							:	list( iterator.list ),
								current( iterator.current ),
								end( iterator.end )
						{
						}
						
						
						
					//********************************************
					//	Public Methods
						
						
						
						/// Prefix increment operator.
						RIM_INLINE void operator ++ ()
						{
							current++;
						}
						
						
						
						
						/// Postfix increment operator.
						RIM_INLINE void operator ++ ( int )
						{
							current++;
						}
						
						
						
						
						/// Return whether or not the iterator is at the end of the list.
						/** 
						  * If the iterator is at the end of the list, return FALSE.
						  * Otherwise, return TRUE, indicating that there are more
						  * elements to iterate over.
						  * 
						  * @return FALSE if at the end of list, otherwise TRUE.
						  */
						RIM_INLINE operator Bool () const
						{
							return current < end;
						}
						
						
						
						
						/// Return a const-reference to the current iterator element.
						RIM_INLINE const T& operator * () const
						{
							return *current;
						}
						
						
						
						
						/// Access the current iterator element.
						RIM_INLINE const T* operator -> () const
						{
							return current;
						}
						
						
						
						
						/// Reset the iterator to the beginning of the list.
						RIM_INLINE void reset()
						{
							current = list.array;
							end = current + list.numElements;
						}
						
						
						
						
						/// Get the index of the next element to be iterated over.
						RIM_INLINE Index getIndex() const
						{
							return current - list.array;
						}
						
						
						
					
				private:
					
					//********************************************
					//	Private Data Members
						
						
						
						/// The current position of the iterator
						const T* current;
						
						
						
						
						/// A pointer to one element past the end of the list.
						const T* end;
						
						
						
						
						/// The list that is being iterated over.
						const ShortArrayList<T,localCapacity>& list;
						
						
						
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Iterator Creation Methods
			
			
			
			
			/// Return an iterator for the short array list.
			/**
			  * The iterator serves to provide a way to efficiently iterate
			  * over the elements of the short array list. It is more useful for
			  * a linked list type of data structure, but it is provided for
			  * uniformity among data structures.
			  * 
			  * @return an iterator for the short array list.
			  */
			RIM_INLINE Iterator getIterator()
			{ 
				return Iterator(*this);
			}
			
			
			
			
			/// Return a const iterator for the short array list.
			/**
			  * The iterator serves to provide a way to efficiently iterate
			  * over the elements of the short array list. It is more useful for
			  * a linked list type of data structure, but it is provided for
			  * uniformity among data structures.
			  * 
			  * @return an iterator for the short array list.
			  */
			RIM_INLINE ConstIterator getIterator() const
			{ 
				return ConstIterator(*this);
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Methods
			
			
			
			
			/// Double the capacity of this short array list's internal array of objects.
			RIM_INLINE void doubleCapacity()
			{
				resize( capacity << 1 );
			}
			
			
			
			
			/// Double the capacity of this short array list's internal array until it is larger than the specified capacity.
			RIM_INLINE void doubleCapacityUpTo( Size minimumCapacity )
			{
				Size newCapacity = capacity;
				
				while ( newCapacity < minimumCapacity )
					newCapacity <<= 1;
				
				resize( newCapacity );
			}
			
			
			
			
			RIM_NO_INLINE void resize( Size newCapacity );
			
			
			
			
			static void callDestructors( T* array, Size number );
			
			
			
			
			static void copyObjects( T* destination, const T* source, Size number );
			
			
			
			
			static void moveObjects( T* destination, T* source, Size number );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the array containing all elements in the short array list.
			T* array;
			
			
			
			
			/// The number of elements in the short array list.
			Size numElements;
			
			
			
			
			/// The size of the array in this short array list.
			Size capacity;
			
			
			
			
			/// A local array of bytes used to store short lists of elements.
			UByte localStorage[localCapacity*sizeof(T)];
			
			
			
			
};




template < typename T, Size localCapacity >
Bool ShortArrayList<T,localCapacity>:: insert( Index index, const T& newElement )
{
	if ( index <= numElements )
	{
		if ( numElements == capacity )
			doubleCapacity();
		
		T* destination = array + numElements;
		const T* source = array + numElements - 1;
		const T* const sourceEnd = array + index - 1;
		
		while ( source != sourceEnd )
		{
			new (destination) T(*source);
			source->~T();
			
			source--;
			destination--;
		}
		
		new (array + index) T( newElement );
		numElements++;
		
		return true;
	}
	else
		return false;
}




template < typename T, Size localCapacity >
void ShortArrayList<T,localCapacity>:: resize( Size newCapacity )
{
	// Allocate a new array to hold the new array list.
	T* newArray = util::allocate<T>( newCapacity );
	
	// Copy objects from the old array if it has any.
	ShortArrayList<T,localCapacity>::moveObjects( newArray, array, numElements );
	
	// Deallocate the old array if necessary
	if ( array != (T*)localStorage )
		util::deallocate( array );
	
	array = newArray;
	capacity = newCapacity;
}




template < typename T, Size localCapacity >
void ShortArrayList<T,localCapacity>:: callDestructors( T* array, Size number )
{
	const T* const arrayEnd = array + number;
	
	while ( array != arrayEnd )
	{
		array->~T();
		array++;
	}
}




template < typename T, Size localCapacity >
void ShortArrayList<T,localCapacity>:: copyObjects( T* destination, const T* source, Size number )
{
	const T* const sourceEnd = source + number;
	
	while ( source != sourceEnd )
	{
		new (destination) T(*source);
		destination++;
		source++;
	}
}




template < typename T, Size localCapacity >
void ShortArrayList<T,localCapacity>:: moveObjects( T* destination, T* source, Size number )
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




template < typename T, Size localCapacity >
ShortArrayList<T,localCapacity>& ShortArrayList<T,localCapacity>:: operator = ( const ShortArrayList<T,localCapacity>& other )
{
	if ( this != &other )
	{
		// Call the destructors of all objects that were constructed.
		callDestructors( array, numElements );
		
		numElements = other.numElements;
		
		if ( numElements > capacity )
		{
			// Deallocate the internal array if necessary.
			if ( array != (T*)localStorage )
				util::deallocate( array );
			
			// Allocate a new array.
			capacity = other.capacity;
			array = util::allocate<T>( capacity );
		}
		
		// copy the elements from the other ShortArrayList.
		copyObjects( array, other.array, numElements );
	}
	
	return *this;
}




template < typename T, Size localCapacity1 > template < Size localCapacity2 >
ShortArrayList<T,localCapacity1>& ShortArrayList<T,localCapacity1>:: operator = ( const ShortArrayList<T,localCapacity2>& other )
{
	if ( this != &other )
	{
		// Call the destructors of all objects that were constructed.
		callDestructors( array, numElements );
		
		numElements = other.numElements;
		
		if ( numElements > capacity )
		{
			// Deallocate the internal array if necessary.
			if ( array != (T*)localStorage )
				util::deallocate( array );
			
			// Allocate a new array.
			capacity = other.capacity;
			array = util::allocate<T>( capacity );
		}
		
		// copy the elements from the other ShortArrayList.
		copyObjects( array, other.array, numElements );
	}
	
	return *this;
}




//##########################################################################################
//***************************  End Rim Utilities Namespace  ********************************
RIM_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SHORT_ARRAY_LIST_H
