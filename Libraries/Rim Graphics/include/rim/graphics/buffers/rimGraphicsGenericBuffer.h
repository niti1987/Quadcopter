/*
 *  rimGraphicsGenericBuffer.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 2/10/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GENERIC_BUFFER_H
#define INCLUDE_RIM_GRAPHICS_GENERIC_BUFFER_H


#include "rimGraphicsBuffersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Buffers Namespace  ***************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a buffer of shader attributes stored in CPU memory.
class GenericBuffer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an empty generic buffer with the specified data type and zero capacity.
			RIM_FORCE_INLINE GenericBuffer()
				:	buffer( NULL ),
					capacityInBytes( 0 ),
					size( 0 ),
					type()
			{
			}
			
			
			
			
			/// Create an empty generic buffer with the specified data type and zero capacity.
			RIM_FORCE_INLINE GenericBuffer( AttributeType newType )
				:	buffer( NULL ),
					capacityInBytes( 0 ),
					size( 0 ),
					type( newType )
			{
			}
			
			
			
			
			/// Create an empty generic buffer containing the specified data type and with the specified capacity.
			GenericBuffer( AttributeType newType, Size capacity );
			
			
			
			
			/// Create a copy of another generic buffer.
			GenericBuffer( const GenericBuffer& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy an generic buffer.
			RIM_INLINE ~GenericBuffer()
			{
				if ( buffer != NULL )
					util::deallocate( buffer );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Copy the contents of one generic buffer to this one.
			GenericBuffer& operator = ( const GenericBuffer& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Size Accessor Methods
			
			
			
			
			/// Get the number of attributes stored in the buffer.
			RIM_FORCE_INLINE Size getSize() const
			{
				return size;
			}
			
			
			
			
			/// Change the size of the buffer to hold the specified number of attributes.
			/**
			  * If the new size is greater than the previous size, the new attribute
			  * values at the end of the buffer are undefined. This method avoids
			  * reallocating the internal buffer array if possible.
			  */
			RIM_INLINE void setSize( Size newSize )
			{
				if ( newSize > capacityInBytes )
					reallocateBuffer( newSize*type.getSizeInBytes() );
				
				size = newSize;
			}
			
			
			
			
			/// Get the total size of all data in the buffer in bytes.
			RIM_FORCE_INLINE Size getSizeInBytes() const
			{
				return size*type.getSizeInBytes();
			}
			
			
			
			
			/// Get the number of elements that this generic buffer can hold.
			RIM_INLINE Size getCapacity() const
			{
				return capacityInBytes / type.getSizeInBytes();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Attribute Type Accessor Methods
			
			
			
			
			/// Get the type of element this buffer holds.
			RIM_FORCE_INLINE const AttributeType& getAttributeType() const
			{
				return type;
			}
			
			
			
			
			/// Set the type of element this buffer holds.
			/**
			  * This method has the effect of invalidating the contents of the buffer,
			  * setting its size (but not capacity) to 0.
			  */
			RIM_INLINE void setAttributeType( const AttributeType& newAttributeType )
			{
				type = newAttributeType;
				size = 0;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Information Accessor Methods
			
			
			
			
			/// Get a pointer to the start of the internal buffer of attributes.
			RIM_FORCE_INLINE void* getPointer()
			{
				return buffer;
			}
			
			
			
			
			/// Get a const pointer to the start of the internal buffer of attributes.
			RIM_FORCE_INLINE const void* getPointer() const
			{
				return buffer;
			}
			
			
			
			
			/// Get the number of bytes between successive elements in the buffer.
			RIM_FORCE_INLINE Size getStride() const
			{
				return 0;
			}
			
			
			
			
			/// Return whether or not this generic buffer has data.
			RIM_FORCE_INLINE Bool hasData() const
			{
				return buffer != NULL && size != 0;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Element Accessor Methods
			
			
			
			
			/// Return the attribute stored at the specified index in this generic buffer.
			/**
			  * The method will not compile if an invalid output type is specified. A
			  * debug assertion is raised if the output type is incompatible with the buffer
			  * attribute type or if the specified index is invalid.
			  */
			template < typename T >
			RIM_INLINE T get( Index index ) const
			{
				// Statically check to make sure the attribute has a valid attribute type.
				AttributeType::check<T>();
				
				// Do dynamic debug checks on the type and index.
				RIM_DEBUG_ASSERT_MESSAGE( typeIsValid<T>(), "Invalid output type for generic buffer attribute get method" );
				RIM_DEBUG_ASSERT_MESSAGE( index < size, "Invalid index for generic buffer attribute get method" );
				
				return ((T*)buffer)[index];
			}
			
			
			
			
			/// Get the attribute stored at the specified index in this generic buffer.
			/**
			  * The value is stored in the output value parameter. The method returns
			  * whether or not the value was able to be accessed.
			  */
			Bool getAttribute( Index index, AttributeValue& value ) const;
			
			
			
			
			/// Set the attribute stored at the specified index in this generic buffer.
			/**
			  * The method will not compile if an invalid output type is specified. A
			  * debug assertion is raised if the input type is incompatible with the buffer
			  * attribute type or if the specified index is invalid.
			  */
			template < typename T >
			RIM_INLINE void set( Index index, const T& element )
			{
				// Statically check to make sure the attribute has a valid attribute type.
				AttributeType::check<T>();
				
				// Do dynamic debug checks on the type and index.
				RIM_DEBUG_ASSERT_MESSAGE( typeIsValid<T>(), "Invalid input type for generic buffer attribute set method" );
				RIM_DEBUG_ASSERT_MESSAGE( index < size, "Invalid index for generic buffer attribute set method" );
				
				((T*)buffer)[index] = element;
			}
			
			
			
			
			/// Set the attribute stored at the specified index in this generic buffer.
			/**
			  * The value is copied from the value parameter.
			  * The method returns whether or not the value was able to be set.
			  * The method can fail if the index is invalid or the value's type
			  * does not match the buffer's type.
			  */
			Bool setAttribute( Index index, const AttributeValue& value ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Add Methods
			
			
			
			
			/// Add the specified attribute to the end of the buffer.
			/**
			  * If the type of the argument is incompatable with the current type of the buffer
			  * then FALSE is returned. Otherwise TRUE is returned.
			  */
			Bool addAttribute( const AttributeValue& newAttribute );
			
			
			
			
			/// Add the specified attribute to the end of the buffer.
			/**
			  * If the type of the argument is incompatable with the current type of the buffer
			  * then FALSE is returned. Otherwise TRUE is returned.
			  */
			template < typename T >
			RIM_INLINE Bool add( const T& newAttribute )
			{
				// Statically check to make sure the attribute has a valid attribute type.
				AttributeType::check<T>();
				
				// If the type of the buffer was previously undefined, replace the type of the buffer.
				if ( type == AttributeType::UNDEFINED )
					type = AttributeType::get<T>();
				else if ( !typeIsValid<T>() )
					return false;
				
				// If the type of the new attribute is the same as the current type of the buffer, add it.
				addToBuffer( newAttribute );
				
				return true;
			}
			
			
			
			
			/// Add the specified array list of attributes to the buffer's end.
			/**
			  * If the type of the argument elements is incompatable with the current type of the buffer
			  * then FALSE is returned. Otherwise TRUE is returned.
			  */
			template < typename T >
			RIM_INLINE Bool add( const ArrayList<T>& newAttributes )
			{
				return add( newAttributes.getArrayPointer(), newAttributes.getSize() );
			}
			
			
			
			
			/// Add the specified array of attributes to the buffer's end.
			/**
			  * If the type of the argument elements is incompatable with the current type of the buffer
			  * then FALSE is returned. Otherwise TRUE is returned.
			  */
			template < typename T >
			RIM_INLINE Bool add( const Array<T>& newAttributes )
			{
				return add( newAttributes.getPointer(), newAttributes.getSize() );
			}
			
			
			
			
			/// Add the specified number of attributes from the given array to the buffer's end.
			/**
			  * If the type of the argument elements is incompatable with the current type of the buffer
			  * then FALSE is returned. Otherwise TRUE is returned.
			  */
			template < typename T >
			RIM_INLINE Bool add( const T* newAttributes, Size number )
			{
				// Statically check to make sure the attribute has a valid attribute type.
				AttributeType::check<T>();
				
				// If the type of the buffer was previously undefined, replace the type of the buffer.
				if ( type == AttributeType::UNDEFINED )
					type = AttributeType::get<T>();
				else if ( !typeIsValid<T>() )
					return false;
				
				// If the type of the new attributes is the same as the current type of the buffer, add it.
				addToBuffer( newAttributes, number );
				
				return true;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Fill Methods
			
			
			
			
			/// Replace the current buffer contents with those in the given array list.
			/**
			  * If the type of the argument is incompatable with the current type of the buffer
			  * then FALSE is returned and the buffer is unchanged. Otherwise TRUE is returned
			  * and the data from the specified attribute array list is written to the buffer at the
			  * given attribute start index.
			  */
			template < typename T >
			RIM_FORCE_INLINE Bool fill( const ArrayList<T>& newAttributes, Index startIndex = 0 )
			{
				return fill( newAttributes.getPointer(), newAttributes.getSize(), startIndex );
			}
			
			
			
			
			/// Replace the current buffer contents with those in the given array.
			/**
			  * If the type of the argument is incompatable with the current type of the buffer
			  * then FALSE is returned and the buffer is unchanged. Otherwise TRUE is returned
			  * and the data from the specified attribute array is written to the buffer at the
			  * given attribute start index.
			  */
			template < typename T >
			RIM_FORCE_INLINE Bool fill( const Array<T>& newAttributes, Index startIndex = 0 )
			{
				return fill( newAttributes.getPointer(), newAttributes.getSize(), startIndex );
			}
			
			
			
			
			/// Replace the current buffer contents with the specified number from the given array.
			/**
			  * If the type of the argument is incompatable with the current type of the buffer
			  * then FALSE is returned and the buffer is unchanged. Otherwise TRUE is returned
			  * and the data from the specified attribute pointer is written to the buffer at the
			  * given attribute start index.
			  */
			template < typename T >
			RIM_INLINE Bool fill( const T* newAttributes, Size number, Index startIndex = 0 )
			{
				// Statically check to make sure the attribute has a valid attribute type.
				AttributeType::check<T>();
				
				// If the type of the buffer was previously undefined, replace the type of the buffer.
				if ( type == AttributeType::UNDEFINED )
					type = AttributeType::get<T>();
				else if ( !typeIsValid<T>() )
					return false;
				
				fillBuffer( newAttributes, number, startIndex );
				
				return true;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Remove Methods
			
			
			
			
			/// Remove the element at the specified index in this buffer.
			/**
			  * This method maintains the order of the buffer elements and copies them
			  * to fill the space left by the removed element.
			  */
			Bool remove( Index index );
			
			
			
			
			/// Remove the element at the specified index in this buffer.
			/**
			  * This method moves the last element in the buffer to fill the space
			  * left by the removed element.
			  */
			Bool removeUnordered( Index index );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Clear Methods
			
			
			
			
			/// Clear all entries and the associated attribute type type from the buffer.
			/**
			  * This method doesn't release any of the buffer's data, allowing the buffer's
			  * data to be reused again.
			  */
			RIM_INLINE void clear()
			{
				size = 0;
				type = AttributeType::UNDEFINED;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Functions
			
			
			
			
			void addAttributeToBuffer( const UByte* attribute );
			
			
			
			
			template < typename T >
			RIM_INLINE void addToBuffer( const T& attribute )
			{
				// If the buffer is too small, double its capacity
				if ( sizeof(T)*(size + 1) >= capacityInBytes )
					reallocateBuffer( 2*sizeof(T)*(size + 1) );
				
				((T*)buffer)[size] = attribute;
				size++;
			}
			
			
			
			
			template < typename T >
			RIM_INLINE void addToBuffer( const T* attributes, Size number )
			{
				Size newSizeInBytes = sizeof(T)*(number + size);
				
				// If the buffer is too small, increase its capacity to the smallest that will
				// hold the given attributes.
				if ( newSizeInBytes > capacityInBytes )
					reallocateBuffer( newSizeInBytes );
				
				util::copy( (T*)buffer + size, attributes, number );
				size += number;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Buffer Fill Functions
			
			
			
			
			template < typename T >
			RIM_INLINE void fillBuffer( const T* attributes, Size number, Index startIndex )
			{
				// Compute the required size in bytes of the buffer.
				Size newSize = math::max( size, number + startIndex );
				Size newSizeInBytes = sizeof(T)*newSize;
				
				// If the buffer is too small, increase its capacity to the smallest that will
				// hold the given attributes.
				if ( newSizeInBytes > capacityInBytes )
					reallocateBuffer( newSizeInBytes );
				
				// Copy the attributes.
				util::copy( (T*)buffer + startIndex, attributes, number );
				size = newSize;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Buffer Reallocation Method
			
			
			
			
			/// Reallocate the internal data for the generic buffer to have the specified capacity in bytes.
			void reallocateBuffer( Size requestedCapacityInBytes );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Type Validity Checking Functions
			
			
			
			
			/// Return whether or not the specified template attribute type is compatible with this buffer.
			template < typename T >
			RIM_FORCE_INLINE Bool typeIsValid() const
			{
				return AttributeType::get<T>() == type;
			}
			
			
			
			
			/// Return whether or not the specified attribute type is compatible with this buffer.
			RIM_FORCE_INLINE Bool typeIsValid( const AttributeType& aType ) const
			{
				return type == aType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An generic buffer of attributes.
			UByte* buffer;
			
			
			
			
			/// The number of attributes stored in the buffer.
			Size size;
			
			
			
			
			/// The number of bytes consumed by the attribute buffer.
			Size capacityInBytes;
			
			
			
			
			/// The type of the attributes that are stored in the generic buffer.
			AttributeType type;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Buffers Namespace  *****************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GENERIC_BUFFER_H
