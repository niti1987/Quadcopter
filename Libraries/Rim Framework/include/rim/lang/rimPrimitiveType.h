/*
 *  rimPrimitiveType.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 9/13/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PRIMITIVE_TYPE_H
#define INCLUDE_RIM_PRIMITIVE_TYPE_H


#include "rimLanguageConfig.h"


#include "../data/rimBasicString.h"
#include "rimHalfFloat.h"


//##########################################################################################
//***************************  Start Rim Language Namespace  *******************************
RIM_LANGUAGE_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a kind of primitive built-in type.
class PrimitiveType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Primitive Type Enum Definition
			
			
			
			
			typedef enum Enum
			{
				/// An undefined primitive type.
				UNDEFINED = 0,
				
				/// A primitive type representing the 'bool' type.
				BOOLEAN = 1,
				
				/// A primitive type representing an 8-bit signed integer type.
				BYTE = 2,
				
				/// A primitive type representing an 8-bit unsigned integer type.
				UNSIGNED_BYTE = 3,
				
				/// A primitive type representing an 16-bit signed signed integer type.
				SHORT = 4,
				
				/// A primitive type representing an 16-bit unsigned integer type.
				UNSIGNED_SHORT = 5,
				
				/// A primitive type representing a 32-bit signed integer type.
				INT = 6,
				
				/// A primitive type representing a 32-bit unsigned integer type.
				UNSIGNED_INT = 7,
				
				/// A primitive type representing an 16-bit floating-point type.
				HALF_FLOAT = 8,
				
				/// A primitive type representing a 32-bit floating-point type.
				FLOAT = 9,
				
				/// A primitive type representing a 64-bit floating-point type.
				DOUBLE = 10
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new primitive type with the specified primitive type enum value.
			RIM_INLINE PrimitiveType( Enum newType )
				:	type( (UByte)newType )
			{
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Primitive Type Static Templated Accessor Method
			
			
			
			
			/// Get the primitive type of a templated type.
			/**
			  * If the templated type is not a primitive type, an UNDEFINED
			  * primitive type is returned.
			  */
			template < typename T >
			RIM_INLINE static PrimitiveType get()
			{
				return UNDEFINED;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Primitive Type Checking Method
			
			
			
			
			/// Check to see if the templated type is a supported primitive type.
			/**
			  * Calling this empty method will produce a compiler error if the
			  * templated type is not a supported primitive type.
			  */
			template < typename T >
			RIM_FORCE_INLINE static void check();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this primitive type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return (Enum)type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Byte Size Accessor Method
			
			
			
			
			/// Return the size of this primitive type in bits.
			RIM_INLINE Size getSizeInBits() const
			{
				return this->getSizeInBytes() << 3;
			}
			
			
			
			
			/// Return the size of this primitive type in bytes.
			RIM_INLINE Size getSizeInBytes() const
			{
				switch ( type )
				{
					case PrimitiveType::BOOLEAN:
						return sizeof(Bool);
					case PrimitiveType::BYTE:
						return sizeof(Byte);
					case PrimitiveType::UNSIGNED_BYTE:
						return sizeof(UByte);
					case PrimitiveType::SHORT:
						return sizeof(Short);
					case PrimitiveType::UNSIGNED_SHORT:
						return sizeof(UShort);
					case PrimitiveType::INT:
						return sizeof(Int);
					case PrimitiveType::UNSIGNED_INT:
						return sizeof(UInt);
					case PrimitiveType::HALF_FLOAT:
						return sizeof(HalfFloat);
					case PrimitiveType::FLOAT:
						return sizeof(Float);
					case PrimitiveType::DOUBLE:
						return sizeof(Double);
					default:
						return 0;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the primitive type.
			data::String toString() const;
			
			
			
			
			/// Convert this primitive type into a string representation.
			RIM_INLINE operator data::String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum for the primitive type.
			UByte type;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Primitive Type Accessor Method Specializations
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_INLINE PrimitiveType PrimitiveType:: get<Bool>()
{
	return BOOLEAN;
}




template <>
RIM_INLINE PrimitiveType PrimitiveType:: get<Byte>()
{
	return BYTE;
}




template <>
RIM_INLINE PrimitiveType PrimitiveType:: get<UByte>()
{
	return UNSIGNED_BYTE;
}




template <>
RIM_INLINE PrimitiveType PrimitiveType:: get<Short>()
{
	return SHORT;
}




template <>
RIM_INLINE PrimitiveType PrimitiveType:: get<UShort>()
{
	return UNSIGNED_SHORT;
}




template <>
RIM_INLINE PrimitiveType PrimitiveType:: get<Int>()
{
	return INT;
}




template <>
RIM_INLINE PrimitiveType PrimitiveType:: get<UInt>()
{
	return UNSIGNED_INT;
}




template <>
RIM_INLINE PrimitiveType PrimitiveType:: get<HalfFloat>()
{
	return HALF_FLOAT;
}




template <>
RIM_INLINE PrimitiveType PrimitiveType:: get<Float>()
{
	return FLOAT;
}




template <>
RIM_INLINE PrimitiveType PrimitiveType:: get<Double>()
{
	return DOUBLE;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Primitive Type Checking Method Specializations
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_INLINE void PrimitiveType:: check<Bool>()
{
}




template <>
RIM_INLINE void PrimitiveType:: check<Byte>()
{
}




template <>
RIM_INLINE void PrimitiveType:: check<UByte>()
{
}




template <>
RIM_INLINE void PrimitiveType:: check<Short>()
{
}




template <>
RIM_INLINE void PrimitiveType:: check<UShort>()
{
}




template <>
RIM_INLINE void PrimitiveType:: check<Int>()
{
}




template <>
RIM_INLINE void PrimitiveType:: check<UInt>()
{
}




template <>
RIM_INLINE void PrimitiveType:: check<HalfFloat>()
{
}




template <>
RIM_INLINE void PrimitiveType:: check<Float>()
{
}




template <>
RIM_INLINE void PrimitiveType:: check<Double>()
{
}




//##########################################################################################
//***************************  End Rim Language Namespace  *********************************
RIM_LANGUAGE_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PRIMITIVE_TYPE_H
