/*
 *  rimTraversalStack.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 11/27/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_TRAVERSAL_STACK_H
#define INCLUDE_RIM_TRAVERSAL_STACK_H


#include "rimBVHConfig.h"


//##########################################################################################
//*****************************  Start Rim BVH Namespace  **********************************
RIM_BVH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which stores a stack of node pointers used by an iterative traversal.
/**
  * When traversing a BVH, the user passes in a stack object to use for node pointer
  * storage during tree traversal. This allows for easier multithreaded traversal,
  * since each thread can use a different stack object.
  */
class TraversalStack
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new traversal stack with the default stack size of 32.
			RIM_INLINE TraversalStack()
				:	stack( util::allocate<const void*>( DEFAULT_STACK_SIZE ) ),
					size( DEFAULT_STACK_SIZE )
			{
			}
			
			
			
			
			/// Create a new traversal stack with the specified size.
			/**
			  * The stack size is clamped so that it is at least 1.
			  */
			RIM_INLINE TraversalStack( Size newSize )
				:	size( math::max( newSize, Size(1) ) )
			{
				stack = util::allocate<const void*>( newSize );
			}
			
			
			
			
			/// Create a new traversal stack with the same size as another stack.
			/**
			  * The entries of the stack are not copied.
			  */
			RIM_INLINE TraversalStack( const TraversalStack& other )
				:	stack( util::allocate<const void*>( other.size ) ),
					size( other.size )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this traversal stack.
			RIM_INLINE ~TraversalStack()
			{
				util::deallocate( stack );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Make sure that this stack has size greater than or equal to another stack's size.
			/**
			  * The entries of the stack are not copied.
			  */
			RIM_INLINE TraversalStack& operator = ( const TraversalStack& other )
			{
				if ( size < other.size )
				{
					// Reallocate the stack if it needs to be bigger.
					util::deallocate( stack );
					stack = util::allocate<const void*>( other.size );
					size = other.size;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stack Accessor Methods
			
			
			
			
			
			/// Return a pointer to the root of the stack.
			/**
			  * The stack is an array of pointers that are stored contiguously after the root.
			  */
			RIM_INLINE const void** getRoot() const
			{
				return stack;
			}
			
			
			
			
			
			/// Return the total size of this traversal stack, the number of entries it has.
			RIM_INLINE Size getSize() const
			{
				return size;
			}
			
			
			
			
			/// Ensure that the stack has size greater than or equal to the specified size.
			RIM_INLINE void resize( Size newSize )
			{
				if ( size < newSize )
				{
					// Reallocate the stack if it needs to be bigger.
					util::deallocate( stack );
					stack = util::allocate<const void*>( newSize );
					size = newSize;
				}
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// A constant indicating the default stack size used when no size is specified.
			static const Size DEFAULT_STACK_SIZE = 32;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An array of pointers, indicating the stack entries.
			const void** stack;
			
			
			
			
			/// The total size of this traversal stack, the number of entries it has.
			Size size;
			
			
			
};




//##########################################################################################
//*****************************  End Rim BVH Namespace  ************************************
RIM_BVH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_TRAVERSAL_STACK_H
