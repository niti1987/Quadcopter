/*
 *  rimGraphicsHardwareBufferIterator.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 1/9/11.
 *  Copyright 2011 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_HARDWARE_BUFFER_ITERATOR_H
#define INCLUDE_RIM_GRAPHICS_HARDWARE_BUFFER_ITERATOR_H


#include "rimGraphicsBuffersConfig.h"


#include "rimGraphicsHardwareBuffer.h"
#include "rimGraphicsHardwareBufferAccessType.h"


//##########################################################################################
//***********************  Start Rim Graphics Buffers Namespace  ***************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which allows the user to iterate over a hardware attribute buffer.
/**
  * It does this by mapping the buffer's data to the main memory's address space
  * which allows the buffer's contents to be iterated over normally. Iterators
  * can be created to be either read-only, write-only, or read-write.
  *
  * Important: The iterated buffer object must not be destroyed until the
  * iterator is also destroyed or the behavior is undefined. In addition,
  * a buffer cannot be used again by the GPU until the iterator object is destroyed,
  * unmapping the buffer data.
  */
template < typename T >
class HardwareBufferIterator
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new buffer iterator which doesn't iterator over any buffer.
			RIM_INLINE HardwareBufferIterator()
				:	buffer(),
					accessType( HardwareBufferAccessType::READ ),
					bufferStart( NULL ),
					bufferEnd( NULL ),
					bufferElement( NULL )
			{
				// Statically check the attribute type of the template type.
				AttributeType::check<T>();
			}
			
			
			
			
			/// Create a new buffer iterator for the specified buffer and access type.
			/**
			  * The constructor maps the buffer's data store to main memory and allows the
			  * iterator to iterate over the data using the specified access type. The
			  * buffer object must not be destroyed until the iterator is also destroyed
			  * or the behavior is undefined. In addition, the buffer cannot be used again
			  * by the GPU until the iterator object is destroyed, unmapping the buffer data.
			  */
			HardwareBufferIterator( const Pointer<HardwareBuffer>& newBuffer,
									HardwareBufferAccessType newAccessType = HardwareBufferAccessType::READ )
				:	buffer( newBuffer ),
					accessType( newAccessType )
			{
				// Statically check the attribute type of the template type.
				AttributeType::check<T>();
				
				// Try mapping the buffer
				if ( newBuffer.isSet() && newBuffer->getAttributeType() == AttributeType::get<T>() &&
					(bufferStart = (T*)newBuffer->mapBuffer( newAccessType )) != NULL )
				{
					bufferElement = bufferStart;
					bufferEnd = bufferStart + buffer->getCapacityInBytes();
				}
				else
				{
					buffer = Pointer<HardwareBuffer>();
					bufferElement = NULL;
					bufferEnd = NULL;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a hardware attribute buffer iterator, releasing the buffer back to the GPU.
			/**
			  * Once an iterator for an attribute buffer is created, the buffer is unable to be used
			  * until the iterator is destroyed, unmapping the buffer's data. Therefore, it is
			  * important to destroy an iterator when one is done with it.
			  */
			RIM_INLINE ~HardwareBufferIterator()
			{
				if ( buffer.isSet() )
					buffer->unmapBuffer();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Position Increment Methods
			
			
			
			
			/// Increment the buffer iterator by one element.
			RIM_INLINE void next()
			{
				RIM_DEBUG_ASSERT_MESSAGE( bufferElement != NULL,
										"Cannot iterate with invalid hardware attribute buffer iterator" );
				RIM_DEBUG_ASSERT_MESSAGE( bufferElement < bufferEnd,
										"Cannot iterate past end of hardware attribute buffer" );
				
				bufferElement++;
			}
			
			
			
			
			/// Increment the buffer iterator by one element.
			RIM_INLINE void operator ++ ()
			{
				RIM_DEBUG_ASSERT_MESSAGE( bufferElement != NULL,
										"Cannot iterate with invalid hardware attribute buffer iterator" );
				RIM_DEBUG_ASSERT_MESSAGE( bufferElement < bufferEnd,
										"Cannot iterate past end of hardware attribute buffer" );
				
				bufferElement++;
			}
			
			
			
			
			/// Increment the buffer iterator by one element.
			RIM_INLINE void operator ++ ( int )
			{
				RIM_DEBUG_ASSERT_MESSAGE( bufferElement != NULL,
										"Cannot iterate with invalid hardware attribute buffer iterator" );
				RIM_DEBUG_ASSERT_MESSAGE( bufferElement < bufferEnd,
										"Cannot iterate past end of hardware attribute buffer" );
				
				bufferElement++;
			}
			
			
			
			
			/// Increment the buffer iterator by the specified number of elements.
			RIM_INLINE void operator += ( Size numElements )
			{
				RIM_DEBUG_ASSERT_MESSAGE( bufferElement != NULL,
										"Cannot iterate with invalid hardware attribute buffer iterator" );
				RIM_DEBUG_ASSERT_MESSAGE( numElements < bufferEnd - bufferElement,
										"Cannot iterate past end of hardware attribute buffer" );
				
				bufferElement += numElements;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Iteration Status Methods
			
			
			
			
			/// Return whether or not this iterator has any more elements to iterate over.
			RIM_INLINE operator Bool () const
			{
				return bufferElement != NULL && bufferElement < bufferEnd;
			}
			
			
			
			
			/// Return whether or not this iterator has any more elements to iterate over.
			RIM_INLINE Bool hasNext() const
			{
				return bufferElement != NULL && bufferElement < bufferEnd;
			}
			
			
			
			
			/// Return the current attribute index which is being iterated over.
			RIM_INLINE Index getIndex() const
			{
				RIM_DEBUG_ASSERT_MESSAGE( bufferElement != NULL,
										"Cannot get element index of invalid hardware attribute buffer iterator" );
				
				return bufferElement - bufferStart;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Element Accessor Operators
			
			
			
			
			/// Return a reference to the value of the attribute at the current iterator position.
			/**
			  * This method returns the attribute at the current iterator position in the
			  * class's templated type.
			  */
			RIM_INLINE T& operator * () const
			{
				RIM_DEBUG_ASSERT_MESSAGE( bufferElement != NULL,
										"Cannot get element of invalid hardware attribute buffer iterator" );
				return *bufferElement;
			}
			
			
			
			
			/// Return a reference to the value of the attribute at the current iterator position.
			/**
			  * This method returns the attribute at the current iterator position in the
			  * class's templated type.
			  */
			RIM_INLINE T& operator [] ( Index index ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( bufferElement != NULL,
										"Cannot get element of invalid hardware attribute buffer iterator" );
				RIM_DEBUG_ASSERT_MESSAGE( index < bufferEnd - bufferElement,
										"Cannot get out-of-bounds element of hardware attribute buffer iterator" );
				return bufferElement[index];
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Element Accessor Methods
			
			
			
			
			/// Return a reference to the value of the attribute at the current iterator position.
			/**
			  * This method returns the attribute at the current iterator position in the
			  * class's templated type.
			  */
			RIM_FORCE_INLINE const T& get() const
			{
				RIM_DEBUG_ASSERT_MESSAGE( bufferElement != NULL,
										"Cannot get element of invalid hardware attribute buffer iterator" );
				return *bufferElement;
			}
			
			
			
			
			/// Set the value of the attribute at the current iterator position.
			/**
			  * This method set the attribute at the current iterator position in the
			  * specified templated type. If the templated attribute type is not a valid
			  * attribute type, a compile-time error is generated. A debug assertion is
			  * raised if the attribute type doesn't match the underlying buffer's attribute type
			  * or if writing to the buffer is not supported.
			  */
			RIM_FORCE_INLINE void set( const T& newAttribute )
			{
				RIM_DEBUG_ASSERT_MESSAGE( bufferElement != NULL,
										"Cannot set element of invalid hardware attribute buffer iterator" );
				*bufferElement = newAttribute;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Release Method
			
			
			
			
			/// Unmap the buffer's memory and invalidate the iterator.
			RIM_INLINE void releaseBuffer()
			{
				if ( buffer.isSet() )
					buffer->unmapBuffer();
				
				buffer = Pointer<HardwareBuffer>();
				bufferEnd = bufferElement = bufferStart = NULL;
			}
			
			
			
			
			/// Reset the iterator and map the specified buffer's contents using the given access type.
			/**
			  * If the method succeeds, the iterator can iterate over the buffer's contents and
			  * TRUE is returned. Otherwise, the method fails and FALSE is returned.
			  */
			Bool setBuffer( const Pointer<HardwareBuffer>& newBuffer,
							HardwareBufferAccessType newAccessType )
			{
				// Release the previous buffer.
				if ( buffer.isSet() )
					buffer->unmapBuffer();
				
				// Try mapping the buffer
				if ( newBuffer.isSet() && newBuffer->getAttributeType() == AttributeType::get<T>() &&
					(bufferStart = (T*)newBuffer->mapBuffer( newAccessType )) != NULL )
				{
					buffer = newBuffer;
					accessType = newAccessType;
					bufferElement = bufferStart;
					bufferEnd = bufferStart + buffer->getCapacityInBytes();
					return true;
				}
				else
				{
					buffer = Pointer<HardwareBuffer>();
					bufferElement = NULL;
					bufferEnd = NULL;
					return false;
				}
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Friend Class Declaration
			
			
			
			
			/// Declare the hardware attribute class a friend so that it can create instance of this class.
			friend class HardwareBuffer;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Copy Operations
			
			
			
			
			/// Create a copy of the specified iterator's state.
			/**
			  * This copy constructor is declared private so that copies of this object
			  * cannot be made (only created and destroyed).
			  */
			HardwareBufferIterator( const HardwareBufferIterator& other );
			
			
			
			
			/// Assign the state of the specified iterator to this one.
			/**
			  * This operator is declared private so that copies of this object
			  * cannot be made (only created and destroyed).
			  */
			HardwareBufferIterator& operator = ( const HardwareBufferIterator& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the current iterated element of the memory-mapped data store for the buffer.
			T* bufferElement;
			
			
			
			
			/// A pointer to the memory-mapped data store for the buffer.
			T* bufferStart;
			
			
			
			
			/// A pointer to just past the last byte of the buffer's mapped data store.
			const T* bufferEnd;
			
			
			
			
			/// A pointer to the hardware attribute buffer object which is being iterated over.
			Pointer<HardwareBuffer> buffer;
			
			
			
			
			/// An object which describes the allowed access type for the buffer iterator.
			HardwareBufferAccessType accessType;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Buffers Namespace  *****************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_HARDWARE_BUFFER_ITERATOR_H
