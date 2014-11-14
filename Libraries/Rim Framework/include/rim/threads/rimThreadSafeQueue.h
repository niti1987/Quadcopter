/*
 *  rimThreadSafeQueue.h
 *  Rim Threads
 *
 *  Created by Carl Schissler on 2/26/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_THREAD_SAFE_QUEUE_H
#define INCLUDE_RIM_THREAD_SAFE_QUEUE_H


#include "rimThreadsConfig.h"


#include "rimMutex.h"


//##########################################################################################
//***************************  Start Rim Threads Namespace  ********************************
RIM_THREADS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A linked queue data structure, with first-in-first-out semantics.
/**
  * This class allows the user to manipulate its elements in a 
  * first-in-first-out manner. This can be used to implement a task
  * queue or a buffer. One adds elements to the queue by calling
  * the enqueue() method and removes elements by calling
  * the dequeue() method. One can also query the queue's size and get
  * the first element in the queue without removing it.
  * 
  * This queue implementation uses bmutexing synchronization to
  * make it thread-safe. Thus, this class can be accessed from multiple
  * threads simultaneously while avoiding the problems associated with
  * shared data. It is particularly useful in passing data from one thread
  * to another. One thread enqueues data and the other dequeues it, all
  * with no chance of concurrent modification. However, this class should
  * not be used in a single threaded environment due to the slight overhead
  * of synchronization, although it can without serious consequence.
  */
template < typename T >
class ThreadSafeQueue
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new empty queue with no elements.
			RIM_INLINE ThreadSafeQueue()
					:	head( NULL ),
						tail( NULL ),
						numElements( 0 )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Copy Constructor
			
			
			
			
			/// Perform a deep copy of a queue.
			RIM_NO_INLINE ThreadSafeQueue( const ThreadSafeQueue<T>& queue )
				:	head( NULL ),
					tail( NULL ),
					numElements( 0 )
			{
				queue.acquireMutex();
				
				Node* current = queue.head;
				
				while ( current )
				{
					// copy and add each node to this queue
					if ( head == NULL )
						tail = head = util::construct<Node>( current->data, NULL, NULL );
					else
						tail = tail->next = util::construct<Node>( current->data, tail, NULL );
					
					numElements++;
					
					
					current = current->next;
				}
				
				queue.releaseMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of one queue to another, performing a deep copy.
			RIM_NO_INLINE ThreadSafeQueue& operator = ( const ThreadSafeQueue<T>& queue )
			{
				// deallocate the previous contents
				clear();
				
				acquireMutex();
				queue.acquireMutex();
				
				Node* current = queue.head;
				
				while ( current )
				{
					// copy and add each node to this queue
					if ( head == NULL )
						tail = head = util::construct<Node>( current->data, NULL, NULL );
					else
						tail = tail->next = util::construct<Node>( current->data, tail, NULL );
					
					numElements++;
					
					
					current = current->next;
				}
				
				queue.releaseMutex();
				releaseMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a queue, deallocating all memory used by internal structures.
			RIM_INLINE ~ThreadSafeQueue()
			{
				clear();
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
				acquireMutex();
				
				if ( head == NULL )
					tail = head = util::construct<Node>( newElement, (Node*)NULL, (Node*)NULL );
				else
					tail = tail->next = util::construct<Node>( newElement, tail, (Node*)NULL );
				
				numElements++;
				
				releaseMutex();
			}
			
			
			
			
			/// Remove and return the first element in the queue if one exists.
			/** 
			  * If the queue is not empty, then the first element in the
			  * queue is returned (the first element put in that has not yet
			  * been dequeued). Otherwise, a NoSuchElementException is thrown.
			  * 
			  * @return the removed element of the queue.
			  */
			RIM_NO_INLINE T remove()
			{
				acquireMutex();
				
				// test if the queue is empty
				RIM_DEBUG_ASSERT_MESSAGE( head != NULL, "Cannot dequeue from an empty queue." );
				
				T temp = head->data;
				
				// if the queue is one element, set the tail to NULL. (no elements after dequeue).
				if ( head == tail )
					tail = NULL;
				
				Node* oldHead = head;
				
				// remove the first element in the queue
				head = oldHead->next;
				
				if ( head != NULL )
					head->previous = NULL;
				
				
				util::destruct( oldHead );
				numElements--;
				
				releaseMutex();
				
				return temp;
			}
			
			
			
			
			/// Return the first element in the queue without removing it.
			/**
			  * If there are no elements in the queue, then a
			  * NoSuchElementException is thrown. The first element 
			  * in the queue is the first element that was enqueued 
			  * which has not yet been dequeued.
			  * 
			  * @return the first element in the queue
			  */
			RIM_INLINE T peek()
			{
				acquireMutex();
				
				RIM_DEBUG_ASSERT_MESSAGE( head != NULL, "Cannot peek at an empty queue." );
				
				T temp = head->data;
				
				releaseMutex();
				
				return temp;
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
				acquireMutex();
					
					Node* current = head;
					Node* previous = NULL;
					
					while ( current )
					{
						previous = current;
						current = current->next;
						util::destruct( previous );
					}
					
					head = tail = NULL;
					numElements = Size(0);
					
				releaseMutex();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return whether or not the queue has any elements
			/** 
			  * @return whether or not the queue has any elements
			  */
			RIM_INLINE Bool isEmpty() const
			{
				acquireMutex();
				
					Bool result = numElements == Size(0);
					
				releaseMutex();
				
				return result;
			}
			
			
			
			
			/// Get the number of elements in the queue.
			/** 
			  * @return the number of elements in the queue
			  */
			RIM_INLINE Size getSize() const
			{
				acquireMutex();
				
					Size tempSize = numElements;
					
				releaseMutex();
				
				return tempSize;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Queue Node Class
			
			
			
			
			/// The class defining a queue node.
			/** 
			  * The class is used to implement a doubly-linked queue,
			  * such that each element has a reference to it's previous node
			  * and it's next node. This makes adding and removing elements more
			  * efficient.
			  */
			class Node
			{
				public:
					
					//****************************************************
					//	Constructors
						
						
						
						/// Create a new node.
						/** 
						  * The user must specifiy the node data, the previous node,
						  * and the next node.
						  * 
						  * @param newData - the data for the node
						  * @param newPrevious - the previous node in the queue
						  * @param newNext - the next node in the queue
						  */
						RIM_INLINE Node( const T& newData, Node* newPrevious, Node* newNext )
							:	data(newData),
								previous(newPrevious),
								next(newNext)
						{
						}
						
						
					//****************************************************
					//	Data Members
						
						
						/// The data contained by the queue node.
						T data;
						
						
						/// The previous node for the queue node
						Node* previous;
						
						
						/// The next node for the queue node
						Node* next;
						
						
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Methods
			
			
			
			
			/// Acquire the read/write mutex for the queue.
			RIM_INLINE void acquireMutex() const
			{
				mutex.lock();
			}
			
			
			
			
			/// Release the read/write mutex for the queue.
			RIM_INLINE void releaseMutex() const
			{
				mutex.unlock();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The head of the queue (containing the first element).
			Node* head;
			
			
			
			
			/// The tail of the queue (containing the last element).
			Node* tail;
			
			
			
			
			/// The number of elements in the queue.
			Size numElements;
			
			
			
			
			/// The mutex used to make the queue thread-safe.
			mutable Mutex mutex;
			
			
			
			
};




//##########################################################################################
//***************************  End Rim Threads Namespace  **********************************
RIM_THREADS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_THREAD_SAFE_QUEUE_H
