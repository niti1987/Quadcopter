/*
 *  rimGraphicsHardwareBuffer.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/29/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_HARDWARE_BUFFER_H
#define INCLUDE_RIM_GRAPHICS_HARDWARE_BUFFER_H


#include "rimGraphicsBuffersConfig.h"


#include "rimGraphicsGenericBuffer.h"
#include "rimGraphicsHardwareBufferAccessType.h"
#include "rimGraphicsHardwareBufferUsage.h"
#include "rimGraphicsHardwareBufferType.h"


//##########################################################################################
//***********************  Start Rim Graphics Buffers Namespace  ***************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a buffer of shader attributes stored in GPU memory.
/**
  * This class allows attribute data to be stored in the graphics card's RAM for
  * faster access. It is analogous to the Texture class which performs the same
  * function but for pixel data.
  */
class HardwareBuffer : public ContextObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	 Buffer Capacity Accessor Methods
			
			
			
			
			/// Return the total number of elements of this buffer's current attribute type that it can hold.
			RIM_INLINE Size getCapacity() const
			{
				Size attributeSizeInBytes = attributeType.getSizeInBytes();
				
				if ( attributeSizeInBytes != 0 )
					return capacityInBytes / attributeSizeInBytes;
				else
					return capacityInBytes;
			}
			
			
			
			
			/// Set the number of elements of this buffer's current attribute type that this buffer is able to hold.
			/**
			  * This method invalidates any contents of the buffer and reallocates the buffer's
			  * data store to have the specified capacity.
			  *
			  * If the method fails (i.e. capacity too big), the method returns FALSE. Otherwise,
			  * the method returns TRUE indicating that the buffer was successfully resized.
			  */
			Bool setCapacity( Size newCapacity );
			
			
			
			
			/// Return the capacity of the hardware attribute buffer in bytes.
			RIM_INLINE Size getCapacityInBytes() const
			{
				return capacityInBytes;
			}
			
			
			
			
			/// Set the number of bytes that this buffer is able to hold.
			/**
			  * This method invalidates any contents of the buffer and reallocates the buffer's
			  * data store to have the specified capacity.
			  *
			  * If the method fails (i.e. capacity too big), the method returns FALSE. Otherwise,
			  * the method returns TRUE indicating that the buffer was successfully resized.
			  */
			virtual Bool setCapacityInBytes( Size newCapacityInBytes );
			
			
			
			
			/// Return whether or not this buffer has been initialized with any attribute data or a capacity.
			RIM_INLINE Bool hasData() const
			{
				return capacityInBytes > 0;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	 Buffer Nominal Size Accessor Methods
			
			
			
			
			/// Return the number of valid attributes that this buffer has.
			/**
			  * The number returned is independent of the buffer's capacity but must
			  * be less than or equal to the return value of getCapacity(). It indicates
			  * a user-defined 'size' of the buffer that may be different than the
			  * buffer's actual capacity. This allows the user to encode the number of
			  * valid attributes into the buffer itself.
			  */
			RIM_INLINE Size getNominalSize() const
			{
				return nominalSize;
			}
			
			
			
			
			/// Set the nominal size of this hardware buffer
			/**
			  * This number is clamped to be less than the buffer's capacity.
			  * It indicates a user-defined 'size' of the buffer that may be different than the
			  * buffer's actual capacity. This allows the user to encode the number of
			  * valid attributes into the buffer itself.
			  */
			RIM_INLINE void setNominalSize( Size newNominalSize )
			{
				nominalSize = math::min( newNominalSize, this->getCapacity() );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Type Accessor Methods
			
			
			
			
			/// Return the type of elements that this hardware attribute buffer can hold.
			RIM_INLINE const AttributeType& getAttributeType() const
			{
				return attributeType;
			}
			
			
			
			
			/// Set the type of elements that this hardware attribute buffer can hold.
			/**
			  * This method will not alter the contents of the buffer but it changes
			  * how they will be interpreted. The old attribute type is replaced
			  * but the capacity and contents are unchanged.
			  *
			  * The method returns whether or not the attribute type was able to be changed.
			  * A return value of FALSE means that the specified attribute type was
			  * incompatible with this buffer.
			  */
			virtual Bool setAttributeType( const AttributeType& newAttributeType );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Accessor Methods
			
			
			
			
			/// Read the specified number of attributes from the hardware buffer into the specified output pointer.
			/**
			  * If the method succeeds, it reads the specified number of attributes from the buffer
			  * and writes them to the specified attribute pointer and returns TRUE. The number of
			  * attributes read from the buffer is written to the output numAttributes reference.
			  * If the method fails, FALSE is returned.
			  *
			  * The attribute pointer should be allocated with enough room to hold that many attributes
			  * of the buffer's type.
			  */
			virtual Bool getAttributes( void* attributes, Size& numAttributes ) const = 0;
			
			
			
			
			/// Read all of the attributes from the hardware buffer into the specified output buffer.
			/**
			  * If the method succeeds, it reads all of the attributes from the buffer
			  * and writes them to the specified attribute buffer and returns TRUE. The method replaces
			  * any data that was previously in the opaque buffer.
			  *
			  * The attribute pointer should be allocated with enough room to hold that many attributes
			  * of the buffer's type.
			  */
			Bool getAttributes( GenericBuffer& attributes ) const;
			
			
			
			
			/// Read the specified number of attributes from the hardware buffer into the specified output buffer.
			/**
			  * If the method succeeds, it reads the specified number of attributes from the buffer
			  * and writes them to the specified attribute buffer and returns TRUE. The method replaces
			  * any data that was previously in the opaque buffer. The number of
			  * attributes read from the buffer is written to the output numAttributes reference.
			  *
			  * The attribute pointer should be allocated with enough room to hold that many attributes
			  * of the buffer's type.
			  */
			Bool getAttributes( GenericBuffer& attributes, Size& numAttributes ) const;
			
			
			
			
			/// Replace the contents of this hardware attribute buffer with the specified attributes.
			/**
			  * This method replaces the current contents of the buffer (reallocating the buffer
			  * if necessary), and sets this buffer to have the same attribute type as the given buffer.
			  *
			  * This variant allows the user to modify the usage type of the buffer's data store.
			  *
			  * If the method fails (i.e. if the buffer's attribute type is incompatible with this
			  * buffer), FALSE is returned the buffer is unchanged. If the method succeeds, TRUE
			  * is returned.
			  */
			virtual Bool setAttributes( const void* attributes, const AttributeType& attributeType,
										Size numAttributes, HardwareBufferUsage newUsage = HardwareBufferUsage::STATIC ) = 0;
			
			
			
			
			/// Replace the contents of this hardware attribute buffer with the specified attributes.
			/**
			  * This method replaces the current contents of the buffer (reallocating the buffer
			  * if necessary), and sets this buffer to have the same attribute type as the given buffer.
			  *
			  * If the method fails (i.e. if the buffer's attribute type is incompatible with this
			  * buffer), FALSE is returned the buffer is unchanged. If the method succeeds, TRUE
			  * is returned.
			  */
			RIM_INLINE Bool setAttributes( const GenericBuffer& attributes,
											HardwareBufferUsage newUsage = HardwareBufferUsage::STATIC )
			{
				return this->setAttributes( attributes.getPointer(), attributes.getAttributeType(),
											attributes.getSize(), newUsage );
			}
			
			
			
			
			/// Update a region of this hardware attribute buffer with the specified attributes.
			/**
			  * This method updates the current contents of the buffer, starting at the specified
			  * attribute start index within the buffer.
			  *
			  * If the method fails (i.e. if the buffer's attribute type is incompatible with this
			  * buffer), FALSE is returned the buffer is unchanged. If the method succeeds, TRUE
			  * is returned.
			  */
			virtual Bool updateAttributes( const void* attributes, const AttributeType& attributeType,
											Size numAttributes, Index startIndex = 0 ) = 0;
			
			
			
			
			/// Update a region of this hardware attribute buffer with the specified attributes.
			/**
			  * This method updates the current contents of the buffer, starting at the specified
			  * attribute start index within the buffer.
			  *
			  * If the method fails (i.e. if the buffer's attribute type is incompatible with this
			  * buffer), FALSE is returned the buffer is unchanged. If the method succeeds, TRUE
			  * is returned.
			  */
			RIM_INLINE Bool updateAttributes( const GenericBuffer& attributes, Index startIndex )
			{
				return this->updateAttributes( attributes.getPointer(), attributes.getAttributeType(),
												attributes.getSize(), startIndex );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Reallocation Method
			
			
			
			
			/// Reallocate this buffer's data store using its current capacity.
			/**
			  * This method allows the user to get a new data store for the buffer,
			  * releasing the previous data store. This is useful if you are using
			  * a memory-mapped buffer to transfer vertices to the GPU. By releasing
			  * the buffer before mapping it, you signal that you don't need the old
			  * buffer anymore, avoiding synchronization stalls.
			  *
			  * The resulting contents of the buffer are undefined.
			  */
			virtual Bool reallocate() = 0;
			
			
			
			
			/// Reallocate this buffer's data store using its current capacity, changing its usage type.
			/**
			  * This method allows the user to get a new data store for the buffer,
			  * releasing the previous data store. This is useful if you are using
			  * a memory-mapped buffer to transfer vertices to the GPU. By releasing
			  * the buffer before mapping it, you signal that you don't need the old
			  * buffer anymore, avoiding synchronization stalls.
			  *
			  * The resulting contents of the buffer are undefined.
			  *
			  * This variant allows the user to change the usage of the buffer when it is
			  * reallocated.
			  */
			virtual Bool reallocate( HardwareBufferUsage newUsage ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Mapping Methods
			
			
			
			
			/// Map this buffer's data store to the main memory address space and return a pointer to it.
			/**
			  * The method returns NULL if the buffer is unable to be mapped with the
			  * given access type. The method allows the user to specify an offset within
			  * the buffer which is applied to the returned pointer, in units of the attribute type width.
			  *
			  * This method is called by HardwareBufferIterator when an object
			  * of that class is constructed.
			  */
			virtual void* mapBuffer( HardwareBufferAccessType accessType, Index startIndex = 0 ) = 0;
			
			
			
			
			/// Unmap this buffer's data store to the main memory address space.
			/**
			  * This method is called by HardwareBufferIterator when an object
			  * of that class is destroyed.
			  */
			virtual void unmapBuffer() const = 0;
			
			
			
			
			/// Return whether or not this attribute buffer is currently mapped to main memory.
			/**
			  * If this method returns TRUE, it means that a HardwareBufferIterator is
			  * probably iterating over the buffer. The buffer cannot be used for any drawing
			  * until the iterator object is destroyed, causing the buffer's data to be unmapped
			  * from main memory.
			  */
			virtual Bool isMapped() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Hardware Attribute Buffer Type Accessor Methods
			
			
			
			
			/// Get the current expected usage pattern for this hardware attribute buffer.
			/**
			  * The usage type can be changed any time the buffer's contents are reallocated.
			  */
			virtual HardwareBufferUsage getUsage() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Hardware Attribute Buffer Type Accessor Methods
			
			
			
			
			/// Return an object representing the semantic type of this hardware buffer.
			RIM_INLINE const HardwareBufferType& getType() const
			{
				return bufferType;
			}
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Constructor
			
			
			
			
			/// Create a hardware attribute buffer for the specified context with the given buffer type.
			RIM_INLINE HardwareBuffer( const devices::GraphicsContext* context, HardwareBufferType newBufferType )
				:	ContextObject( context ),
					bufferType( newBufferType ),
					attributeType( AttributeType::UNDEFINED ),
					capacityInBytes( 0 ),
					nominalSize( 0 )
			{
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value which is set by subclasses that determines the kind of hardware attribute buffer this is.
			/**
			  * This can be used to specify that a buffer is a vertex attribute buffer
			  * or an index buffer or some other kind of buffer. These buffers types allow
			  * different kinds of attributes to be stored in them.
			  */
			HardwareBufferType bufferType;
			
			
			
			
			/// An object which indicates the kind of attribute data stored in this buffer.
			AttributeType attributeType;
			
			
			
			
			/// The total capacity of this buffer's data store in bytes.
			Size capacityInBytes;
			
			
			
			
			/// The nominal size of the hardware buffer which can be used to indicate how many buffer elements are valid.
			Size nominalSize;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Buffers Namespace  *****************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_HARDWARE_BUFFER_H
