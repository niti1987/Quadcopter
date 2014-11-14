/*
 *  rimGraphicsConstantBuffer.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 11/9/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_CONSTANT_BUFFER_H
#define INCLUDE_RIM_GRAPHICS_CONSTANT_BUFFER_H


#include "rimGraphicsShadersConfig.h"


#include "rimGraphicsConstantUsage.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that stores a collection of shader constants with their associated usages.
/**
  * This allows objects like meshes and shapes to store constants (such as color)
  * independently of the shader pass that is used to render the object. At render time,
  * the constant buffer is used as source of constant data for shader constant variables
  * that require input for certain constant usages.
  */
class ConstantBuffer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new constant buffer object with no constants stored.
			ConstantBuffer();
			
			
			
			
			/// Create a new constant buffer object with the specified initial capacity in bytes.
			ConstantBuffer( Size constantDataCapacity );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a constant buffer, releasing all internal resources.
			~ConstantBuffer();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constant Accessor Methods
			
			
			
			
			/// Return the number of constants that are stored in this constant buffer.
			RIM_FORCE_INLINE Size getConstantCount() const
			{
				return numConstantBytes;
			}
			
			
			
			
			/// Return a pointer to the storage for the specified constant usage if it is part of this buffer.
			/**
			  * If the method succeeds in finds a constant with that usage that is compatible
			  * with the templated return type, a pointer to the stored value is returned.
			  * Otherwise, the method fails and returns NULL.
			  */
			template < typename T >
			RIM_INLINE const T* getConstant( const ConstantUsage& usage ) const
			{
				return this->getConstantValue( usage, AttributeType::get<T>() );
			}
			
			
			
			
			/// Get the value for the specified constant usage if it is part of this buffer.
			/**
			  * If the method succeeds in finds a constant with that usage that is compatible
			  * with the templated value output type, the constant's value is stored in the
			  * output parameter and the method returns TRUE.
			  * Otherwise the method has no effect and returns FALSE.
			  */
			template < typename T >
			RIM_INLINE Bool getConstant( const ConstantUsage& usage, T& value ) const
			{
				return this->getConstantValue( usage, AttributeType::get<T>(), &value );
			}
			
			
			
			
			/// Get the value for the specified constant usage if it is part of this buffer.
			/**
			  * If the method succeeds in finds a constant with that usage, the constant's value
			  * is stored in the output parameter and the method returns TRUE.
			  * Otherwise the method has no effect and returns FALSE.
			  */
			RIM_INLINE Bool getConstant( const ConstantUsage& usage, AttributeValue& value ) const
			{
				return this->getConstantValue( usage, value );
			}
			
			
			
			
			/// Get the value for the specified constant usage if it is part of this buffer.
			/**
			  * If the method succeeds in finds a constant with that usage that is compatible
			  * with the specified value output type, the constant's value is stored in the
			  * output value parameter and the method returns TRUE.
			  * Otherwise the method has no effect and returns FALSE.
			  */
			RIM_INLINE Bool getConstant( const ConstantUsage& usage, const AttributeType& outputType, void* value ) const
			{
				return this->getConstantValue( usage, outputType, value );
			}
			
			
			
			
			/// Add a new constant with the specified usage and value to this constant buffer.
			/**
			  * The method returns whether or not a new constant was successfully added
			  * to this buffer. The method can fail if the specified value does not
			  * have a type that is compatible with the given usage.
			  */
			template < typename T >
			RIM_INLINE Bool addConstant( const ConstantUsage& usage, const T& value )
			{
				return this->addConstantValue( usage, AttributeType::get<T>(), &value );
			}
			
			
			
			
			/// Add a new constant with the specified usage and value to this constant buffer.
			/**
			  * The method returns whether or not a new constant was successfully added
			  * to this buffer. The method can fail if the specified value does not
			  * have a type that is compatible with the given usage.
			  */
			template < typename T >
			RIM_INLINE Bool addConstant( const ConstantUsage& usage, const AttributeValue& value )
			{
				return this->addConstantValue( usage, value.getType(), value.getPointer() );
			}
			
			
			
			
			/// Set the value of the stored constant with the given usgae.
			/**
			  * If the method finds a stored constant with the specified usage
			  * and the given templated value type is compatible with the stored value,
			  * the constants value is set to the new value and TRUE is returned.
			  * If not found, the method adds the given constant value to the buffer
			  * as if calling addConstant(). If the value is incompatible with the
			  * usage, the method fails and FALSE is returned.
			  */
			template < typename T >
			RIM_INLINE Bool setConstant( const ConstantUsage& usage, const T& value )
			{
				return this->setConstantValue( usage, AttributeType::get<T>(), &value );
			}
			
			
			
			
			/// Set the value of the stored constant with the given usgae.
			/**
			  * If the method finds a stored constant with the specified usage
			  * and the given value type is compatible with the stored value,
			  * the constants value is set to the new value and TRUE is returned.
			  * If not found, the method adds the given constant value to the buffer
			  * as if calling addConstant(). If the value is incompatible with the
			  * usage, the method fails and FALSE is returned.
			  */
			RIM_INLINE Bool setConstant( const ConstantUsage& usage, const AttributeValue& value )
			{
				return this->setConstantValue( usage, value.getType(), value.getPointer() );
			}
			
			
			
			
			/// Remove all stored constants from this constant buffer object.
			RIM_INLINE void clearConstants()
			{
				constants.clear();
				numConstantBytes = 0;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constant Data Accessor Methods
			
			
			
			
			/// Return an pointer to the internal array of shader constant data.
			RIM_FORCE_INLINE Size getConstantDataSize() const
			{
				return numConstantBytes;
			}
			
			
			
			
			/// Return a pointer to the internal array of shader constant data.
			RIM_FORCE_INLINE UByte* getConstantData()
			{
				return constantData.getPointer();
			}
			
			
			
			
			/// Return a const pointer to the internal array of shader constant data.
			RIM_FORCE_INLINE const UByte* getConstantData() const
			{
				return constantData.getPointer();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Constant Data Members
			
			
			
			
			/// The default size of a constant buffer's constant buffer in bytes.
			static const Size DEFAULT_CONSTANT_BUFFER_SIZE = 64;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Entry Class Declaration
			
			
			
			
			/// A class that stores the usage and offset of a constant within this constant buffer.
			class Entry
			{
				public:
					
					/// Create a new entry with the specified usage, type, and storage offset in bytes.
					RIM_INLINE Entry( const ConstantUsage& newUsage, const AttributeType& newType, Index newByteOffset )
						:	usage( newUsage ),
							type( newType ),
							byteOffset( newByteOffset )
					{
					}
					
					
					/// The usage associated with this constant buffer entry.
					ConstantUsage usage;
					
					/// The type of the value that is stored for this constant.
					AttributeType type;
					
					/// The offset in bytes of the constant value for this entry.
					Index byteOffset;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Find the index of the constant with the specified usage in this buffer.
			RIM_FORCE_INLINE Bool findUsage( const ConstantUsage& usage, Index& constantIndex ) const;
			
			
			
			
			/// Return a pointer to the storage for the constant with the specified usage.
			const void* getConstantValue( const ConstantUsage& usage, const AttributeType& valueType ) const;
			
			
			
			
			/// Get the value of a constant with the specified usage in the output parameter.
			Bool getConstantValue( const ConstantUsage& usage, const AttributeType& valueType, void* value ) const;
			
			
			
			
			/// Get the value of a constant with the specified usage in the output parameter.
			Bool getConstantValue( const ConstantUsage& usage, AttributeValue& value ) const;
			
			
			
			
			/// Set the value of a constant with the specified usage.
			Bool setConstantValue( const ConstantUsage& usage, const AttributeType& valueType, const void* value );
			
			
			
			
			/// Add a new constant with the specified usage, type, and value.
			Bool addConstantValue( const ConstantUsage& usage, const AttributeType& valueType, const void* value );
			
			
			
			
			/// Allocate a new constant for this constant buffer and return the byte offset for the constant storage.
			RIM_FORCE_INLINE Index allocateConstant( Size sizeInBytes );
			
			
			
			
			/// Align the specified address to a 4-byte boundary.
			RIM_FORCE_INLINE static Index alignConstantAddress( Index address )
			{
				return (address + (DEFAULT_CONSTANT_ALIGNMENT - 1)) & -(SignedIndex)DEFAULT_CONSTANT_ALIGNMENT;
			}
			
			
			
			
			/// The default alignment requirement in bytes for allocated constants.
			static const Index DEFAULT_CONSTANT_ALIGNMENT = 4;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the constants and their usages that are stored in this buffer.
			ArrayList<Entry> constants;
			
			
			
			
			/// An array of bytes that stores the values for all constants that are part of this constant buffer.
			Array<UByte> constantData;
			
			
			
			
			/// The total number of bytes used for current bindings in the constant data buffer.
			Size numConstantBytes;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_CONSTANT_BUFFER_H
