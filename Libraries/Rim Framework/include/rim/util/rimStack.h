/*
 *  rimStack.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 11/26/07.
 *  Copyright 2007 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_STACK_H
#define INCLUDE_RIM_STACK_H


#include "rimUtilitiesConfig.h"


//##########################################################################################
//***************************  Start Rim Framework Namespace  ******************************
RIM_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A simple stack class which implements the standard push, pop, and peek methods.
/** 
  * This class is an array-based stack class. It is a first-in-first-out data
  * structure. One places an element on the stack by calling add(), and
  * removes an element by calling remove(). One can return the top value on the
  * stack without changing the stack by calling get(). Other attributes such
  * as the size of the stack can be queried. This data structure is not thread safe.
  */
template < typename T >
class Stack
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new empty stack with the default capacity of 8 elements.
			/**
			  * This is a lightweight operation and the stack doesn't allocate any
			  * memory until an element is pushed onto the stack.
			  */
			RIM_INLINE Stack()
				:	numElements( 0 ),
					capacity( 0 ),
					stack( NULL )
			{
			}
			
			
			
			
			/// Create a new empty stack with the specified initial capacity.
			/** 
			  * The initial capacity of the stack array can be set by the
			  * parameter, which can be used to pad the stack to avoid having
			  * to resize the stack often.
			  * 
			  * @param newCapacity - the initial capacity of the stack array
			  */
			RIM_INLINE Stack( Size newCapacity )
				:	numElements( 0 ),
					capacity( newCapacity ),
					stack( util::allocate<T>(newCapacity) )
			{
			}
			
			
			
			
			/// Create a copy of an existing stack. This is a deep copy.
			RIM_INLINE Stack( const Stack& otherStack )
				:	numElements( otherStack.numElements ),
					capacity( otherStack.capacity ),
					stack( util::allocate<T>(otherStack.capacity) )
			{
				// copy the elements from the old array to the new array.
				Stack<T>::copyObjects( stack, otherStack.array, numElements );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			RIM_INLINE ~Stack()
			{
				if ( stack != NULL )
				{
					// Call the destructors of all objects that were constructed and deallocate the internal array.
					util::destructArray( stack, numElements );
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of one stack to another, performing a deep copy.
			RIM_INLINE Stack<T>& operator = ( const Stack<T>& other )
			{
				if ( this != &other )
				{
					if ( stack != NULL )
					{
						// Call the destructors of all objects that were constructed.
						Stack<T>::callDestructors( stack, numElements );
					}
					
					numElements = other.numElements;
					
					if ( numElements == Size(0) )
						return *this;
					else
					{
						if ( numElements > capacity || stack == NULL )
						{
							// Deallocate the internal array.
							if ( stack != NULL )
								util::deallocate( stack );
							
							// Allocate a new array.
							capacity = other.capacity;
							stack = util::allocate<T>( capacity );
						}
						
						// copy the elements from the other Stack.
						Stack<T>::copyObjects( stack, other.stack, numElements );
					}
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Push Method
			
			
			
			
			/// Push a new element onto the stack.
			/**
			  * If the current size of the stack is equal to its capacity,
			  * then the stack is resized by calling the private resize() method
			  * which reallocates the internal stack array to double the original
			  * size.
			  * 
			  * @param newElement - the new element to be pushed onto the stack.
			  */
			void add( const T& newElement )
			{
				if ( numElements == capacity )
					doubleCapacity();
				
				new (stack + numElements) T( newElement );
				numElements++;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Get Methods
			
			
			
			
			/// Return the top element of the stack without removing it.
			/** 
			  * If there are no elements in the stack, then an exception is
			  * thrown indicating the error. This is the const version which
			  * returns a const reference to the element, disallowing its
			  * modification.
			  * 
			  * @return a const reference to the top element of the stack.
			  */
			RIM_INLINE const T& get() const
			{
				RIM_DEBUG_ASSERT_MESSAGE( numElements > 0, "Attempted to get the top of an empty stack." );
				
				return *(stack + numElements - 1);
			}
			
			
			
			
			/// Return the top element of the stack without removing it.
			/** 
			  * If there are no elements in the stack, then an exception is
			  * thrown indicating the error. This is the non-const version which
			  * returns a non-const reference to the element, allowing its
			  * modification.
			  * 
			  * @return a reference to the top element of the stack.
			  */
			RIM_INLINE T& get()
			{
				RIM_DEBUG_ASSERT_MESSAGE( numElements > 0, "Attempted to get the top of an empty stack." );
				
				return *(stack + numElements - 1);
			}
			
			
			
			
			/// Return the element of the stack at the specified depth without removing it.
			/** 
			  * The depth at which one is peeking is an integer ranging from 0 to 
			  * the size of the stack minus 1. Depth zero specifies the element at the top
			  * of the stack. If the depth index is outside of the valid range, then
			  * an exception is thrown indicating the error. This is the const version which
			  * returns a const reference to the element, disallowing its
			  * modification.
			  * 
			  * @return a const reference to the element of the stack at the specified depth.
			  */
			RIM_INLINE const T& get( Index depth ) const
			{
				Index index = numElements - depth - 1;
				
				RIM_DEBUG_ASSERT_MESSAGE( index < numElements, "Attempted to get stack element at an invalid index." );
				
				return *(stack + index);
			}
			
			
			
			
			/// Return the element of the stack at the specified depth without removing it.
			/** 
			  * The depth at which one is peeking is an integer ranging from 0 to 
			  * the size of the stack minus 1. Depth zero specifies the element at the top
			  * of the stack. If the depth index is outside of the valid range, then
			  * an exception is thrown indicating the error. This is the non-const version which
			  * returns a non-const reference to the element, disallowing its
			  * modification.
			  * 
			  * @return a reference to the element of the stack at the specified depth.
			  */
			RIM_INLINE T& get( Index depth )
			{
				Index index = numElements - depth - 1;
				
				RIM_DEBUG_ASSERT_MESSAGE( index < numElements, "Attempted to get stack element at an invalid index." );
				
				return *(stack + index);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Remove Method
			
			
			
			
			/// Return the top element of the stack and remove it in the process.
			/** 
			  * If there are no elements in the stack, then an exception is
			  * thrown indicating the error.
			  * 
			  * @return the top element of the stack.
			  */
			RIM_INLINE T remove()
			{
				RIM_DEBUG_ASSERT_MESSAGE( numElements > 0, "Attempted to remove element from an empty stack." );
				
				// Extract the element to be removed.
				numElements--;
				T temp = *(stack + numElements);
				
				// Destroy the element that was stored.
				(stack + numElements)->~T();
				
				return temp;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Clear Methods
			
			
			
			
			//// Clear the contents of this stack.
			/**
			  * This method calls the destructors of all elements in the stack
			  * and sets the number of elements to zero while maintaining the
			  * stack's capacity.
			  */
			RIM_INLINE void clear()
			{
				if ( stack != NULL )
					Stack<T>::callDestructors( stack, numElements );
				
				numElements = Size(0);
			}
			
			
			
			
			/// Clear the contents of this stack and reclaim the allocated memory.
			/**
			  * This method performs the same function as the clear() method, but
			  * also deallocates the previously allocated internal array and reallocates
			  * it to a small initial starting size. Calling this method is equivalent
			  * to assigning a brand new stack instance to this one.
			  */
			RIM_INLINE void reset()
			{
				if ( stack != NULL )
					util::destructArray( stack, numElements );
				
				capacity = Size(0);
				stack = NULL;
				numElements = Size(0);
			}
			
			
			
			
			/// Clear the contents of this stack and reclaim the allocated memory.
			/**
			  * This method performs the same function as the clear() method, but
			  * also deallocates the previously allocated internal array and reallocates
			  * it to an initial starting size. Calling this method is equivalent
			  * to assigning a brand new stack instance to this one. This version of
			  * the reset() method allows the caller to specify the new starting
			  * capacity of the array list.
			  */
			RIM_INLINE void reset( Size newCapacity )
			{
				if ( stack != NULL )
					util::destructArray( stack, numElements );
				
				capacity = newCapacity;
				stack = util::allocate<T>( capacity );
				numElements = Size(0);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return whether or not the stack has any elements.
			/** 
			  * This method returns TRUE if the size of the stack
			  * is greater than zero, and FALSE otherwise.
			  * This method is here for convenience.
			  * 
			  * @return whether or not the stack has any elements.
			  */
			RIM_INLINE Bool isEmpty() const
			{
				return numElements == Size(0);
			}
			
			
			
			
			/// Return the number of elements in the stack.
			/** 
			  * @return the number of elements in the stack.
			  */
			RIM_INLINE Size getSize() const
			{
				return numElements;
			}
			
			
			
			
			/// Get the current capacity of the stack.
			/**
			  * The capacity is the maximum number of elements that the
			  * stack can hold before it will have to resize its
			  * internal array.
			  * 
			  * @return the current capacity of the stack.
			  */
			RIM_INLINE Size getCapacity() const
			{
				return capacity;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Stack Methods
			
			
			
			
			RIM_INLINE void doubleCapacity()
			{
				// check to see if the array has not yet been allocated.
				if ( capacity == 0 )
				{
					// allocate the array to hold elements.
					capacity = DEFAULT_INITIAL_CAPACITY;
					stack = util::allocate<T>( capacity );
				}
				else
					resize( capacity << 1 );
			}
			
			
			
			
			/// Double the size of the element array to increase the capacity of the stack.
			/**
			  * This method deallocates the previously used array, and then allocates
			  * a new block of memory with a size equal to double the previous size.
			  * It then copies over all of the previous elements into the new array.
			  */
			void resize( Size newCapacity )
			{
				// Update the capacity and allocate a new array.
				capacity = newCapacity;
				T* oldStack = stack;
				stack = util::allocate<T>( capacity );
				
				// copy the elements from the old array to the new array.
				Stack<T>::moveObjects( stack, oldStack, numElements );
				
				// deallocate the old array.
				util::deallocate( oldStack );
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
			
			
			
			
			/// A pointer to the array containing all elements in the stack.
			T* stack;
			
			
			
			/// The number of elements in the stack.
			Size numElements;
			
			
			
			/// The number of possible elements that the current stack array could hold.
			Size capacity;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The default initial capacity of a stack.
			/**
			  * This value is used whenever the creator of the stack does
			  * not specify the initial capacity of the stack.
			  */
			static const Size DEFAULT_INITIAL_CAPACITY = 8;
			
			
			
};




//##########################################################################################
//***************************  End Rim Framework Namespace  ********************************
RIM_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_STACK_H
