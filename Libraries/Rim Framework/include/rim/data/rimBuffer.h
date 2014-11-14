/*
 *  rimBuffer.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 5/22/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_BUFFER_H
#define INCLUDE_RIM_BUFFER_H


#include "rimDataConfig.h"


#include "../util/rimArray.h"


//##########################################################################################
//*******************************   Start Data Namespace   *********************************
RIM_DATA_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An array-based buffer class
/** 
  * This class allows the user to accumulate elements in a resizing buffer,
  * then use the buffer's array as a contiguous block of memory at some later point.
  */
template < typename T >
class Buffer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an empty buffer with the default initial capacity.
			RIM_INLINE Buffer()
				:	buffer( util::allocate<T>( DEFAULT_CAPACITY ) ),
					capacity( DEFAULT_CAPACITY ),
					resizeFactor( DEFAULT_RESIZE_FACTOR )
			{
				nextElement = buffer;
				bufferEnd = buffer + capacity;
			}
			
			
			
			
			/// Create an empty buffer with the specified initial capacity.
			RIM_INLINE Buffer( Size initialCapacity )
				:	buffer( util::allocate<T>( initialCapacity ) ),
					capacity( initialCapacity ),
					resizeFactor( DEFAULT_RESIZE_FACTOR )
			{
				nextElement = buffer;
				bufferEnd = buffer + capacity;
			}
			
			
			
			
			/// Create an empty buffer with the specified initial capacity and resize factor.
			RIM_INLINE Buffer( Size initialCapacity, Float newResizeFactor )
				:	buffer( util::allocate<T>( initialCapacity ) ),
					capacity( initialCapacity ),
					resizeFactor( math::clamp( resizeFactor, 1.1f, 10.0f ) )
			{
				nextElement = buffer;
				bufferEnd = buffer + capacity;
			}
			
			
			
			
			/// Create an identical copy of the specified buffer.
			RIM_INLINE Buffer( const Buffer& other )
				:	buffer( util::allocate<T>( other.capacity ) ),
					capacity( other.capacity ),
					resizeFactor( other.resizeFactor )
			{
				Size otherSize = other.getSize();
				
				Buffer::copyObjects( buffer, other.buffer, otherSize );
				
				nextElement = buffer + otherSize;
				bufferEnd = buffer + capacity;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a buffer, deallocating all resources used.
			RIM_INLINE ~Buffer()
			{
				util::destructArray( buffer, getSize() );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of one array list to another, performing a deep copy.
			RIM_NO_INLINE Buffer& operator = ( const Buffer& other )
			{
				if ( this != &other )
				{
					// Call the destructors of all objects that are already in the buffer.
					util::destructArray( buffer, getSize() );
					
					capacity = other.capacity;
					resizeFactor = other.resizeFactor;
					Size otherSize = other.getSize();
					
					// Reallocate the buffer array.
					buffer = util::allocate<T>( other.capacity );
					
					// Copy objects from the other buffer to this one.
					Buffer::copyObjects( buffer, other.buffer, otherSize );
					
					nextElement = buffer + otherSize;
					bufferEnd = buffer + capacity;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Append Methods
			
			
			
			
			/// Append an element to the end of this buffer.
			RIM_INLINE Buffer& append( const T& element )
			{
				if ( nextElement == bufferEnd )
					increaseCapacity( nextElement - buffer + 1 );
				
				new ( nextElement ) T( element );
				nextElement++;
				
				return *this;
			}
			
			
			
			
			/// Append the specified number of elements from the given array.
			RIM_INLINE Buffer& append( const T* source, Size numElements )
			{
				if ( nextElement + numElements > bufferEnd )
					increaseCapacity( nextElement - buffer + numElements );
				
				Buffer::copyObjects( nextElement, source, numElements );
				
				nextElement += numElements;
				
				return *this;
			}
			
			
			
			
			/// Append all elements from the specified array to the end of the buffer.
			RIM_INLINE Buffer& append( const util::Array<T>& array )
			{
				return append( array.getPointer(), array.getSize() );
			}
			
			
			
			
			/// Append a certain number of elements from the specified array to the end of the buffer.
			RIM_INLINE Buffer& append( const util::Array<T>& array, Size number )
			{
				return append( array.getPointer(), math::min( number, array.getSize() ) );
			}
			
			
			
			
			/// Append all data from the specified buffer.
			RIM_INLINE Buffer& append( const Buffer& aBuffer )
			{
				return append( aBuffer.buffer, aBuffer.getSize() );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Append Operators
			
			
			
			
			/// Append an element to the end of this buffer.
			RIM_INLINE Buffer& operator << ( const T& element )
			{
				return append( element );
			}
			
			
			
			
			/// Append all elements from the specified array to the end of the buffer.
			RIM_INLINE Buffer& operator << ( const util::Array<T>& array )
			{
				return append( array );
			}
			
			
			
			
			/// Append all data from the specified buffer.
			RIM_INLINE Buffer& operator << ( const Buffer& aBuffer )
			{
				return append( aBuffer );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Clear Method
			
			
			
			
			/// Clear the contents of the buffer, keeping its capacity intact.
			RIM_INLINE void clear()
			{
				Buffer::callDestructors( buffer, getSize() );
				nextElement = buffer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content Accessor Methods
			
			
			
			
			/// Convert the contents of this buffer to an array object.
			RIM_INLINE util::Array<T> toArray() const
			{
				return util::Array<T>( (const T*)buffer, getSize() );
			}
			
			
			
			
			/// Convert the contents of this buffer to an array object.
			RIM_INLINE operator util::Array<T> ()
			{
				return util::Array<T>( (const T*)buffer, getSize() );
			}
			
			
			
			
			/// Get a pointer pointing to the buffer's internal array.
			RIM_INLINE const T* getPointer() const
			{
				return buffer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Get the number of elements in the buffer.
			RIM_INLINE Size getSize() const
			{
				return nextElement - buffer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Capacity Accessor Methods
			
			
			
			
			
			/// Get the number of elements the buffer can hold without resizing.
			RIM_INLINE Size getCapacity() const
			{
				return capacity;
			}
			
			
			
			
			/// Set the number of elements the buffer can hold.
			RIM_INLINE Bool setCapacity( Size newCapacity )
			{
				if ( newCapacity < getSize() )
					return false;
				else
					resize( newCapacity );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resize Factor Accessor Methods
			
			
			
			
			/// Get the resize factor for this buffer.
			RIM_INLINE Float getResizeFactor() const
			{
				return resizeFactor;
			}
			
			
			
			
			/// Set the resize factor for this buffer, clamped to [1.1, 10.0]
			RIM_INLINE void setResizeFactor( Float newResizeFactor )
			{
				resizeFactor = math::clamp( newResizeFactor, 1.1f, 10.0f );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Methods
			
			
			
			
			/// Call the constructors of the specified number of elements of the given array.
			static void callDestructors( T* array, Size number )
			{
				const T* const arrayEnd = array + number;
				
				while ( array != arrayEnd )
				{
					array->~T();
					array++;
				}
			}
			
			
			
			
			/// Copy the specified number of objects from the source to the destination location.
			static void copyObjects( T* destination, const T* source, Size number )
			{
				const T* const sourceEnd = source + number;
				
				while ( source != sourceEnd )
				{
					new (destination) T(*source);
					destination++;
					source++;
				}
			}
			
			
			
			
			/// Move the specified number of objects from the source to the destination location.
			static void moveObjects( T* destination, const T* source, Size number )
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
			
			
			
			
			/// Increase the capacity to the specified amount multiplied by the resize factor.
			RIM_INLINE void increaseCapacity( Size minimumCapacity )
			{
				resize( math::max( minimumCapacity, Size(Float(capacity)*resizeFactor) ) );
			}
			
			
			
			
			/// Resize the internal buffer to be the specified length.
			RIM_NO_INLINE void resize( Size newCapacity )
			{
				Size numElements = getSize();
				
				// Update the capacity and allocate a new array.
				capacity = newCapacity;
				T* oldBuffer = buffer;
				buffer = util::allocate<T>( capacity );
				
				// copy the elements from the old array to the new array.
				Buffer::moveObjects( buffer, oldBuffer, numElements );
				
				// Update pointers needed for quick adding to the buffer.
				nextElement = buffer + numElements;
				bufferEnd = buffer + capacity;
				
				// deallocate the old array.
				util::destructArray( oldBuffer, numElements );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An array of elements which is the buffer.
			T* buffer;
			
			
			
			
			/// A pointer to the location in the buffer where the next element should be inserted.
			T* nextElement;
			
			
			
			
			/// A pointer to the first element past the end of the buffer.
			const T* bufferEnd;
			
			
			
			
			/// The number of elements that the buffer can hold.
			Size capacity;
			
			
			
			
			/// How much the buffer's capacity increases when it needs to.
			Float resizeFactor;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The default capacity for a buffer if it is not specified.
			static const Size DEFAULT_CAPACITY = 32;
			
			
			
			
			/// The default factor by which the buffer resizes.
			static const Float DEFAULT_RESIZE_FACTOR;
			
			
			
};




template < typename T >
const Float		Buffer<T>::	DEFAULT_RESIZE_FACTOR = 2.0f;




//##########################################################################################
//*******************************   End Data Namespace   ***********************************
RIM_DATA_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_BUFFER_H
