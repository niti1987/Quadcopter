/*
 *  rimQueue.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 2/27/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_QUEUE_H
#define INCLUDE_RIM_QUEUE_H


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
/// A linked queue data structure, with first-in-first-out semantics.
template < typename T >
class Queue
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new empty queue with no elements.
			RIM_INLINE Queue()
					:	head( NULL ),
						tail( NULL ),
						numElements( 0 )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Copy Constructor
			
			
			
			
			/// Perform a deep copy of a queue, copying all of its elements.
			RIM_INLINE Queue( const Queue<T>& other )
				:	head( NULL ),
					tail( NULL ),
					numElements( 0 )
			{
				if ( other.head )
				{
					numElements = other.numElements;
					Node* current = other.head;
					
					tail = head = util::construct<Node>( current->data, (Node*)NULL, (Node*)NULL );
					current = current->next;
					
					while ( current )
					{
						// copy and add each node to this queue
						tail = tail->next = util::construct<Node>( current->data, tail, (Node*)NULL );
						current = current->next;
					}
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of one queue to another, performing a deep copy.
			RIM_INLINE Queue& operator = ( const Queue<T>& other )
			{
				if ( this != &other )
				{
					// deallocate the previous contents
					clear();
					
					// Copy the queue only if it has elements.
					if ( other.head )
					{
						numElements = other.numElements;
						Node* current = other.head;
						
						tail = head = util::construct<Node>( current->data, (Node*)NULL, (Node*)NULL );
						current = current->next;
						
						while ( current )
						{
							// copy and add each node to this queue
							tail = tail->next = util::construct<Node>( current->data, tail, (Node*)NULL );
							current = current->next;
						}
					}
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a queue, deallocating all memory used by internal structures.
			RIM_INLINE ~Queue()
			{
				this->clear();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Queue Methods
			
			
			
			
			/// Add an element to the end of the queue.
			/**
			  * This increases the size of the queue by one and 
			  * allocates another node in the queue's internal linked
			  * data structure.
			  * 
			  * @param newElement - the new element to add to the end of the queue
			  */
			RIM_INLINE void add( const T& newElement )
			{
				if ( head == NULL )
					tail = head = util::construct<Node>( newElement, (Node*)NULL, (Node*)NULL );
				else
					tail = tail->next = util::construct<Node>( newElement, tail, (Node*)NULL );
				
				numElements++;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Remove Methods
			
			
			
			
			/// Remove the first element in the queue if one exists.
			/** 
			  * If the queue is not empty, then the first element in the
			  * queue is remove (the first element put in that has not yet
			  * been dequeued). Otherwise, if the queue is empty, an assertion is raised.
			  */
			RIM_INLINE void remove()
			{
				RIM_DEBUG_ASSERT_MESSAGE( head != NULL, "Cannot remove an element from an empty queue." );
				
				// If the queue is one element, set the tail to NULL. (no elements after dequeue).
				if ( head == tail )
					tail = NULL;
				
				Node* oldHead = head;
				
				// remove the first element in the queue
				head = oldHead->next;
				
				if ( head != NULL )
					head->previous = NULL;
				
				util::destruct( oldHead );
				numElements--;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Contains Method
			
			
			
			
			/// Return whether or not the specified element is in the queue.
			RIM_INLINE Bool contains( const T& element ) const
			{
				Node* current = head;
				
				while ( current )
				{
					if ( current->data == element )
						return true;
					
					current = current->next;
				}
				
				return false;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Element Accessor Methods
			
			
			
			
			/// Return a reference to the first element in the queue.
			/**
			  * If there are no elements in the queue, then an assertion is raised.
			  * The first element in the queue is the first element that was enqueued 
			  * which has not yet been dequeued.
			  * 
			  * @return the first element in the queue.
			  */
			RIM_INLINE T& getFirst()
			{
				RIM_DEBUG_ASSERT_MESSAGE( head != NULL, "Cannot peek at an empty queue." );
				
				return head->data;
			}
			
			
			
			
			/// Return a const reference to the first element in the queue.
			/**
			  * If there are no elements in the queue, then an assertion is raised.
			  * The first element in the queue is the first element that was enqueued 
			  * which has not yet been dequeued.
			  * 
			  * @return the first element in the queue.
			  */
			RIM_INLINE const T& getFirst() const
			{
				RIM_DEBUG_ASSERT_MESSAGE( head != NULL, "Cannot peek at an empty queue." );
				
				return head->data;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Clear Method
			
			
			
			
			/// Remove all elements from the queue.
			/**
			  * This method deallocates all memory used by the queue,
			  * reseting it to the state of when it was first constructed.
			  */
			RIM_INLINE void clear()
			{
				Node* current = head;
				
				while ( current )
				{
					Node* previous = current;
					current = previous->next;
					
					util::destruct( previous );
				}
				
				head = tail = NULL;
				numElements = Size(0);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return whether or not the queue has any elements.
			/** 
			  * This method returns TRUE if the size of the queue
			  * is greater than zero, and FALSE otherwise.
			  * 
			  * @return whether or not the priority queue has any elements.
			  */
			RIM_INLINE Bool isEmpty() const
			{
				return numElements == Size(0);
			}
			
			
			
			
			/// Return the number of elements in the queue.
			/** 
			  * @return the number of elements in the queue
			  */
			RIM_INLINE Size getSize() const
			{
				return numElements;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Queue Node Class
			
			
			
			
			/// A class which defines the type of a doubly-linked node in a queue.
			class Node
			{
				public:
					
					//****************************************************
					//	Constructors
						
						
						
						/// Create a new node with the specified data element and previous and next node pointers.
						RIM_INLINE Node( const T& newData, Node* newPrevious, Node* newNext )
							:	data( newData ),
								previous( newPrevious ),
								next( newNext )
						{
						}
						
						
					//****************************************************
					//	Data Members
						
						
						/// The data contained by the queue node.
						T data;
						
						
						/// A pointer to the previous node in the queue.
						Node* previous;
						
						
						/// A pointer to the next node in the queue.
						Node* next;
						
						
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The head of the queue (pointing to the first element).
			Node* head;
			
			
			
			
			/// The tail of the queue (pointing to the last element).
			Node* tail;
			
			
			
			
			/// The number of elements in the queue.
			Size numElements;
			
			
			
			
};




//##########################################################################################
//***************************  End Rim Framework Namespace  ********************************
RIM_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_QUEUE_H
