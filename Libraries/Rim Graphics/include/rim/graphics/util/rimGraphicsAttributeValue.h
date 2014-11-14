/*
 *  rimGraphicsAttributeValue.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/29/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_ATTRIBUTE_VALUE_H
#define INCLUDE_RIM_GRAPHICS_ATTRIBUTE_VALUE_H


#include "rimGraphicsUtilitiesConfig.h"


#include "rimGraphicsAttributeType.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which is used to store the value of a shader attribute of any common type.
class AttributeValue
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a AttributeValue with undefined type and no value set.
			RIM_INLINE AttributeValue()
				:	value( localBuffer ),
					type(),
					arraySize( 0 ),
					capacityInBytes( LOCAL_BUFFER_SIZE )
			{
			}
			
			
			
			
			/// Create a AttributeValue with the specified type and an undefined value.
			/**
			  * If the new attribute value's type is undefined, the shader attribute is
			  * constructed with no value stored.
			  */
			RIM_INLINE AttributeValue( const AttributeType& newType, Size newArraySize = Size(1) )
				:	type( newType ),
					arraySize( (UShort)newArraySize )
			{
				Size typeSize = arraySize*type.getSizeInBytes();
				
				// Check to see if we should allocate a buffer for the value or use the local buffer.
				if ( typeSize > LOCAL_BUFFER_SIZE )
				{
					value = util::allocate<UByte>( typeSize );
					capacityInBytes = typeSize;
				}
				else
				{
					value = localBuffer;
					capacityInBytes = LOCAL_BUFFER_SIZE;
				}
			}
			
			
			
			
			/// Create a AttributeValue with the specified value and type from a packed array.
			/**
			  * If the new attribute value's type is undefined, the shader attribute is
			  * constructed with no value stored.
			  */
			template < typename PrimType >
			RIM_INLINE AttributeValue( const PrimType* newAttribute, const AttributeType& newType, Size newArraySize = Size(1) )
				:	type( newType ),
					arraySize( (UShort)newArraySize )
			{
				// Statically verify the primitive type.
				PrimitiveType::check<PrimType>();
				
				Size typeSize = arraySize*type.getSizeInBytes();
				
				// Check to see if we should allocate a buffer for the value or use the local buffer.
				if ( typeSize > LOCAL_BUFFER_SIZE )
				{
					value = util::allocate<UByte>( typeSize );
					capacityInBytes = typeSize;
				}
				else
				{
					value = localBuffer;
					capacityInBytes = LOCAL_BUFFER_SIZE;
				}
				
				// Copy the new attribute components.
				if ( newAttribute )
					util::copy( (UByte*)value, (const UByte*)newAttribute, typeSize );
			}
			
			
			
			
			/// Create a AttributeValue with the type and value of the specified parameter and given array size.
			/**
			  * If the new attribute value's type is undefined, the shader attribute is
			  * constructed with no value stored. The specified attribute value is
			  * copied for each element in the attribute array size.
			  */
			template < typename T >
			RIM_INLINE AttributeValue( const T& newAttribute, Size newArraySize = Size(1) )
				:	type( AttributeType::get<T>() ),
					arraySize( (UShort)newArraySize )
			{
				// Statically verify the attribute type.
				AttributeType::check<T>();
				
				Size typeSize = arraySize*type.getSizeInBytes();
				
				// Check to see if we should allocate a buffer for the value or use the local buffer.
				if ( typeSize > LOCAL_BUFFER_SIZE )
				{
					value = util::allocate<UByte>( typeSize );
					capacityInBytes = typeSize;
				}
				else
				{
					value = localBuffer;
					capacityInBytes = LOCAL_BUFFER_SIZE;
				}
				
				assignArrayValues( newAttribute );
			}
			
			
			
			
			/// Create a copy of the specified shader attribute.
			RIM_INLINE AttributeValue( const AttributeValue& other )
				:	type( other.type ),
					arraySize( other.arraySize )
			{
				if ( other.isSet() )
				{
					Size typeSize = arraySize*type.getSizeInBytes();
					
					if ( typeSize > LOCAL_BUFFER_SIZE )
					{
						value = util::allocate<UByte>( typeSize );
						capacityInBytes = typeSize;
					}
					else
					{
						value = localBuffer;
						capacityInBytes = LOCAL_BUFFER_SIZE;
					}
					
					util::copy( (UByte*)value, (UByte*)other.value, typeSize );
				}
				else
				{
					value = localBuffer;
					capacityInBytes = LOCAL_BUFFER_SIZE;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a AttributeValue object and its associated value.
			RIM_INLINE ~AttributeValue()
			{
				if ( value != localBuffer )
					util::deallocate( value );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the value and type of another shader attribute to this attribute.
			RIM_INLINE AttributeValue& operator = ( const AttributeValue& other )
			{
				if ( this != &other )
				{
					type = other.type;
					arraySize = other.arraySize;
					
					if ( other.isSet() )
					{
						Size typeSize = arraySize*type.getSizeInBytes();
						
						if ( typeSize > capacityInBytes )
						{
							if ( value != localBuffer )
								util::deallocate( value );
							
							value = util::allocate<UByte>( typeSize );
							capacityInBytes = typeSize;
						}
						
						util::copy( (UByte*)value, (UByte*)other.value, typeSize );
					}
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Type Accessor Method
			
			
			
			
			/// Return the type of value that this AttributeValue represents.
			RIM_INLINE const AttributeType& getType() const
			{
				return type;
			}
			
			
			
			
			/// Set the type of value that this AttributeValue represents.
			/**
			  * The internal memory for this value is enlarged if necessary to
			  * contain the specified type and array size. The contents of the
			  * value are undefined after this method is called.
			  */
			void setType( const AttributeType& newType, Size newArraySize = Size(1) );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Value Get Methods
			
			
			
			
			/// Store the value of the AttributeValue in the specified reference.
			/**
			  * If the templated type of the output object matches the type of the 
			  * shader attribute, TRUE is returned and the value is placed in the location
			  * specified by the output reference. Otherwise FALSE is returned and no value
			  * is retrieved.
			  */
			template < typename T >
			RIM_INLINE Bool getValue( T& output, Index arrayIndex = 0 ) const
			{
				// Statically verify the output attribute type.
				AttributeType::check<T>();
				
				if ( value == NULL || AttributeType::get<T>() != type )
					return false;
				
				output = ((T*)value)[arrayIndex];
				
				return true;
			}
			
			
			
			
			/// Store the components of the AttributeValue in the specified pointer.
			/**
			  * If the templated type of the output pointer matches the type of the 
			  * shader attribute's component type, TRUE is returned and the attribute is
			  * placed in the location specified by the output pointer. Otherwise FALSE is
			  * returned and no value is retrieved.
			  */
			template < typename T >
			RIM_INLINE Bool getComponents( T* output ) const
			{
				// Statically check the output component type.
				PrimitiveType::check<T>();
				
				if ( value == NULL || PrimitiveType::get<T>() != type.getPrimitiveType() )
					return false;
				
				util::copy( output, (T*)value, type.getComponentCount() );
				
				return true;
			}
			
			
			
			
			/// Return a pointer to the components of this Shader attribute, stored in column major order.
			/**
			  * If the templated type of the function matches the type of the 
			  * shader attribute's component type, the function is successful and
			  * the component pointer is returned. Otherwise, NULL is
			  * returned indicating failure.
			  */
			template < typename T >
			RIM_INLINE T* getComponents()
			{
				// Statically check the output component type.
				PrimitiveType::check<T>();
				
				if ( PrimitiveType::get<T>() != type.getPrimitiveType() )
					return NULL;
				
				return (T*)value;
			}
			
			
			
			
			/// Return a pointer to the components of this Shader attribute, stored in column major order.
			/**
			  * If the templated type of the function matches the type of the 
			  * shader attribute's component type, the function is successful and
			  * the component pointer is returned. Otherwise, NULL is
			  * returned indicating failure.
			  */
			template < typename T >
			RIM_INLINE const T* getComponents() const
			{
				// Statically check the output component type.
				PrimitiveType::check<T>();
				
				if ( PrimitiveType::get<T>() != type.getPrimitiveType() )
					return NULL;
				
				return (T*)value;
			}
			
			
			
			
			/// Return a raw pointer to the underlying data storage for this attribute value.
			RIM_INLINE UByte* getPointer()
			{
				return value;
			}
			
			
			
			
			/// Return a raw pointer to the underlying data storage for this attribute value.
			RIM_INLINE const UByte* getPointer() const
			{
				return value;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Value Set Method
			
			
			
			
			/// Set the value stored in this AttributeValue object.
			/**
			  * If the type of the new attribute value is undefined, the AttributeValue
			  * is unmodified and FALSE is returned. Otherwise, the value and type
			  * of the AttributeValue object are replaced by the new attribute value
			  * and type.
			  */
			template < typename T >
			RIM_INLINE Bool setValue( const T& newAttribute, Index arrayIndex = 0 )
			{
				// Statically verify the input attribute type.
				AttributeType::check<T>();
				
				// Don't reallocate the attribute value data array if not necessary.
				if ( sizeof(T) > capacityInBytes )
				{
					if ( value != localBuffer )
						util::deallocate( value );
					
					value = util::allocate<UByte>( sizeof(T) );
					capacityInBytes = sizeof(T);
				}
				
				assignValue( newAttribute, arrayIndex );
				type = AttributeType::get<T>();
				
				return true;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Array Size Accessor Methods
			
			
			
			
			/// Return the size of the stored attribute array.
			RIM_INLINE Size getArraySize() const
			{
				return arraySize;
			}
			
			
			
			
			/// Set the size of the stored attribute array.
			/**
			  * New attributes are filled in with the previous last
			  * value in the array.
			  */
			void setArraySize( Size newArraySize );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Status Accessor Method
			
			
			
			
			/// Return whether or not the AttributeValue is not set.
			RIM_INLINE Bool isNull() const
			{
				return type.getPrimitiveType() == PrimitiveType::UNDEFINED;
			}
			
			
			
			
			/// Return whether or not the AttributeValue has a value set.
			RIM_INLINE Bool isSet() const
			{
				return type.getPrimitiveType() != PrimitiveType::UNDEFINED;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the attribute value.
			String toString() const;
			
			
			
			/// Convert this attribute value into a string representation.
			RIM_FORCE_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < typename T >
			RIM_FORCE_INLINE static void* allocateSpaceFor()
			{
				return util::allocate<UByte>( sizeof(T) );
			}
			
			
			
			
			template < typename T >
			RIM_FORCE_INLINE void assignValue( const T& newValue, Index arrayIndex = 0 )
			{
				((T*)value)[arrayIndex] = newValue;
			}
			
			
			
			
			template < typename T >
			RIM_FORCE_INLINE void assignArrayValues( const T& newValue )
			{
				for ( Index i = 0; i < arraySize; i++ )
					((T*)value)[i] = newValue;
			}
			
			
			
			
			template < typename T >
			static String convertComponentsToString( const T* components, Size numRows, Size numColumns );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// Define the size in bytes of the fixed-size local buffer for this shader attribute.
			/**
			  * Make the buffer 16 bytes - enough to hold a 4-component floating point vector.
			  */
			static const Size LOCAL_BUFFER_SIZE = 16;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An opaque pointer to the data type stored by this shader attribute.
			UByte* value;
			
			
			
			
			/// An object representing the type of the data stored by this shader attribute.
			AttributeType type;
			
			
			
			
			/// The size of the array of attributes stored in this attribute value.
			UShort arraySize;
			
			
			
			
			/// The capacity in bytes of this shader attribute's internal data array.
			Size capacityInBytes;
			
			
			
			
			/// A local buffer of bytes that can store small shader attributes without a memory allocation.
			UByte localBuffer[LOCAL_BUFFER_SIZE];
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_ATTRIBUTE_VALUE_H
