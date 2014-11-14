/*
 *  rimGraphicsAttributeType.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 1/30/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_ATTRIBUTE_TYPE_H
#define INCLUDE_RIM_GRAPHICS_ATTRIBUTE_TYPE_H


#include "rimGraphicsUtilitiesConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the type of a shader attribute.
/**
  * A AttributeType can represent either a scalar, vector, or matrix shader
  * attribute. It is specified by a primitive type enumeration indicating the type
  * of the elements of the attribute, plus the number of rows and columns of the
  * attribute type. For instance, a 3-component vector would have 3 rows and 1 column.
  */
class AttributeType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an undefined attribute type with 0 rows and columns.
			RIM_FORCE_INLINE AttributeType()
				:	primitiveType( PrimitiveType::UNDEFINED ),
					numRows( 0 ),
					numColumns( 0 ),
					padding( 0 )
			{
			}
			
			
			
			
			/// Create a scalar attribute type for the specified primitive type.
			RIM_FORCE_INLINE AttributeType( PrimitiveType::Enum newPrimitiveType )
				:	primitiveType( newPrimitiveType ),
					numRows( 1 ),
					numColumns( 1 ),
					padding( 0 )
			{
			}
			
			
			
			
			/// Create a vector attribute type for the specified primitive type and number of components (rows).
			RIM_INLINE AttributeType( PrimitiveType::Enum newPrimitiveType, Size newNumberOfRows )
				:	primitiveType( newPrimitiveType ),
					numRows( (UByte)math::clamp( newNumberOfRows, Size(1), Size(math::max<UByte>()) ) ),
					numColumns( 1 ),
					padding( 0 )
			{
			}
			
			
			
			
			/// Create a matrix attribute type for the specified primitive type and number of rows/columns.
			RIM_INLINE AttributeType( PrimitiveType::Enum newPrimitiveType,
										Size newNumberOfRows, Size newNumberOfColumns )
				:	primitiveType( newPrimitiveType ),
					numRows( (UByte)math::clamp( newNumberOfRows, Size(1), Size(math::max<UByte>()) ) ),
					numColumns( (UByte)math::clamp( newNumberOfColumns, Size(1), Size(math::max<UByte>()) ) ),
					padding( 0 )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Shader Attribute Type Templated Accessor Method
			
			
			
			
			/// Return an AttributeType object for the specified templated type.
			/**
			  * This method returns a valid attribute type for all standard
			  * scalar/vector/matrix/color types. For all other types, an undefined
			  * attribute type is returned.
			  */
			template < typename T >
			RIM_FORCE_INLINE static AttributeType get()
			{
				if ( PrimitiveType::get<T>() == PrimitiveType::UNDEFINED )
					return AttributeType::UNDEFINED;
				else
					return AttributeType( PrimitiveType::get<T>() );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Type Validity Accessor Method
			
			
			
			
			/// Check to see if the templated type is a supported attribute type.
			/**
			  * Calling this empty method will produce a compiler error if the
			  * templated type is not a supported attribute type.
			  */
			template < typename T >
			RIM_FORCE_INLINE static void check();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this attribute type is equal to another.
			RIM_FORCE_INLINE Bool operator == ( const AttributeType& other ) const
			{
				return fullType == other.fullType;
			}
			
			
			
			
			/// Return whether or not this attribute type is not equal to another.
			RIM_FORCE_INLINE Bool operator != ( const AttributeType& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Primitive Type Accessor Methods
			
			
			
			
			/// Return whether or not this attribute's primitive type is a floating-point format (32 or 64-bit).
			RIM_FORCE_INLINE Bool isFloatingPoint() const
			{
				return primitiveType == PrimitiveType::FLOAT || primitiveType == PrimitiveType::DOUBLE;
			}
			
			
			
			
			/// Get the primitive type of this attribute type.
			RIM_FORCE_INLINE PrimitiveType getPrimitiveType() const
			{
				return PrimitiveType( (PrimitiveType::Enum)primitiveType );
			}
			
			
			
			
			/// Set the primitive type of this attribute type.
			RIM_FORCE_INLINE void setPrimitiveType( PrimitiveType newPrimitiveType )
			{
				primitiveType = (UInt8)newPrimitiveType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Row and Column Count Accessor Methods
			
			
			
			
			/// Get the number of rows of this attribute type.
			RIM_FORCE_INLINE Size getRowCount() const
			{
				return (Size)numRows;
			}
			
			
			
			
			/// Set the number of rows of this attribute type.
			RIM_FORCE_INLINE void setRowCount( Size newNumRows )
			{
				numRows = (UInt8)math::clamp( newNumRows, Size(1), Size(4) );
			}
			
			
			
			
			/// Get the number of columns of this attribute type.
			RIM_FORCE_INLINE Size getColumnCount() const
			{
				return (Size)numColumns;
			}
			
			
			
			
			/// Set the number of columns of this attribute type.
			RIM_FORCE_INLINE void setColumnCount( Size newNumColumns )
			{
				numColumns = (UInt8)math::clamp( newNumColumns, Size(1), Size(4) );
			}
			
			
			
			
			/// Return the total number of components that are part of this attribute type (#rows * #columns).
			RIM_FORCE_INLINE Size getComponentCount() const
			{
				return Size(numColumns)*Size(numRows);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Attribute Type Accessor Methods
			
			
			
			
			/// Return whether or not this attribute type represents a scalar type.
			RIM_FORCE_INLINE Bool isAScalar() const
			{
				return numRows == numColumns == Size(1);
			}
			
			
			
			
			/// Return whether or not this attribute type represents a vector type.
			RIM_FORCE_INLINE Bool isAVector() const
			{
				return numRows > 1 && numColumns == Size(1);
			}
			
			
			
			
			/// Return whether or not this attribute type represents a matrix type.
			RIM_FORCE_INLINE Bool isAMatrix() const
			{
				return numRows > 1 && numColumns > 1;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Byte Size Accessor Method
			
			
			
			
			/// Return the size of an attribute with this type in bytes.
			RIM_FORCE_INLINE Size getSizeInBytes() const
			{
				Size numComponents = (Size)numRows*(Size)numColumns;
				
				return getPrimitiveType().getSizeInBytes()*numComponents;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the attribute type.
			String toString() const;
			
			
			
			
			/// Convert this attribute type into a string representation.
			RIM_FORCE_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Predefined Shader Attribute Type Object Constants
			
			
			
			
			static const AttributeType UNDEFINED;
			
			static const AttributeType BOOLEAN;
			static const AttributeType BYTE;
			static const AttributeType UNSIGNED_BYTE;
			static const AttributeType SHORT;
			static const AttributeType UNSIGNED_SHORT;
			static const AttributeType INT;
			static const AttributeType UNSIGNED_INT;
			static const AttributeType HALF_FLOAT;
			static const AttributeType FLOAT;
			static const AttributeType DOUBLE;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			union
			{
				/// A 32-bit integer
				UInt32 fullType;
				
				struct
				{
					/// The primitive type of this attribute type.
					UInt8 primitiveType;
					
					
					
					
					/// The number of rows of this attribute type.
					UInt8 numRows;
					
					
					
					
					/// The number of columns of this attribute type.
					UInt8 numColumns;
					
					
					
					
					/// A reserved padding value.
					UInt8 padding;
				};
			};
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		2D Vector Shader Attribute Type Get Methods
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_INLINE AttributeType AttributeType:: get< Vector2D<Bool> >()
{
	return AttributeType( PrimitiveType::BOOLEAN, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector2D<Byte> >()
{
	return AttributeType( PrimitiveType::BYTE, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector2D<UByte> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_BYTE, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector2D<Short> >()
{
	return AttributeType( PrimitiveType::SHORT, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector2D<UShort> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_SHORT, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector2D<Int> >()
{
	return AttributeType( PrimitiveType::INT, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector2D<UInt> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_INT, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector2D<Float> >()
{
	return AttributeType( PrimitiveType::FLOAT, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector2D<HalfFloat> >()
{
	return AttributeType( PrimitiveType::HALF_FLOAT, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector2D<Double> >()
{
	return AttributeType( PrimitiveType::DOUBLE, 2 );
}





//##########################################################################################
//##########################################################################################
//############		
//############		3D Vector Shader Attribute Type Get Methods
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_INLINE AttributeType AttributeType:: get< Vector3D<Bool> >()
{
	return AttributeType( PrimitiveType::BOOLEAN, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector3D<Byte> >()
{
	return AttributeType( PrimitiveType::BYTE, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector3D<UByte> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_BYTE, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector3D<Short> >()
{
	return AttributeType( PrimitiveType::SHORT, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector3D<UShort> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_SHORT, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector3D<Int> >()
{
	return AttributeType( PrimitiveType::INT, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector3D<UInt> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_INT, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector3D<HalfFloat> >()
{
	return AttributeType( PrimitiveType::HALF_FLOAT, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector3D<Float> >()
{
	return AttributeType( PrimitiveType::FLOAT, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector3D<Double> >()
{
	return AttributeType( PrimitiveType::DOUBLE, 3 );
}




//##########################################################################################
//##########################################################################################
//############		
//############		4D Vector Shader Attribute Type Get Methods
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_INLINE AttributeType AttributeType:: get< Vector4D<Bool> >()
{
	return AttributeType( PrimitiveType::BOOLEAN, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector4D<Byte> >()
{
	return AttributeType( PrimitiveType::BYTE, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector4D<UByte> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_BYTE, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector4D<Short> >()
{
	return AttributeType( PrimitiveType::SHORT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector4D<UShort> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_SHORT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector4D<Int> >()
{
	return AttributeType( PrimitiveType::INT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector4D<UInt> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_INT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector4D<HalfFloat> >()
{
	return AttributeType( PrimitiveType::HALF_FLOAT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector4D<Float> >()
{
	return AttributeType( PrimitiveType::FLOAT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Vector4D<Double> >()
{
	return AttributeType( PrimitiveType::DOUBLE, 4 );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Quaternion Shader Attribute Type Get Methods
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_INLINE AttributeType AttributeType:: get< Quaternion<Bool> >()
{
	return AttributeType( PrimitiveType::BOOLEAN, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Quaternion<Byte> >()
{
	return AttributeType( PrimitiveType::BYTE, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Quaternion<UByte> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_BYTE, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Quaternion<Short> >()
{
	return AttributeType( PrimitiveType::SHORT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Quaternion<UShort> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_SHORT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Quaternion<Int> >()
{
	return AttributeType( PrimitiveType::INT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Quaternion<UInt> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_INT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Quaternion<HalfFloat> >()
{
	return AttributeType( PrimitiveType::HALF_FLOAT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Quaternion<Float> >()
{
	return AttributeType( PrimitiveType::FLOAT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Quaternion<Double> >()
{
	return AttributeType( PrimitiveType::DOUBLE, 4 );
}




//##########################################################################################
//##########################################################################################
//############		
//############		2D Matrix Shader Attribute Type Get Methods
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix2D<Bool> >()
{
	return AttributeType( PrimitiveType::BOOLEAN, 2, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix2D<Byte> >()
{
	return AttributeType( PrimitiveType::BYTE, 2, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix2D<UByte> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_BYTE, 2, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix2D<Short> >()
{
	return AttributeType( PrimitiveType::SHORT, 2, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix2D<UShort> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_SHORT, 2, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix2D<Int> >()
{
	return AttributeType( PrimitiveType::INT, 2, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix2D<UInt> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_INT, 2, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix2D<HalfFloat> >()
{
	return AttributeType( PrimitiveType::HALF_FLOAT, 2, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix2D<Float> >()
{
	return AttributeType( PrimitiveType::FLOAT, 2, 2 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix2D<Double> >()
{
	return AttributeType( PrimitiveType::DOUBLE, 2, 2 );
}





//##########################################################################################
//##########################################################################################
//############		
//############		3D Matrix Shader Attribute Type Get Methods
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix3D<Bool> >()
{
	return AttributeType( PrimitiveType::BOOLEAN, 3, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix3D<Byte> >()
{
	return AttributeType( PrimitiveType::BYTE, 3, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix3D<UByte> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_BYTE, 3, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix3D<Short> >()
{
	return AttributeType( PrimitiveType::SHORT, 3, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix3D<UShort> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_SHORT, 3, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix3D<Int> >()
{
	return AttributeType( PrimitiveType::INT, 3, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix3D<UInt> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_INT, 3, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix3D<HalfFloat> >()
{
	return AttributeType( PrimitiveType::HALF_FLOAT, 3, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix3D<Float> >()
{
	return AttributeType( PrimitiveType::FLOAT, 3, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix3D<Double> >()
{
	return AttributeType( PrimitiveType::DOUBLE, 3, 3 );
}





//##########################################################################################
//##########################################################################################
//############		
//############		4D Matrix Shader Attribute Type Get Methods
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix4D<Bool> >()
{
	return AttributeType( PrimitiveType::BOOLEAN, 4, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix4D<Byte> >()
{
	return AttributeType( PrimitiveType::BYTE, 4, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix4D<UByte> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_BYTE, 4, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix4D<Short> >()
{
	return AttributeType( PrimitiveType::SHORT, 4, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix4D<UShort> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_SHORT, 4, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix4D<Int> >()
{
	return AttributeType( PrimitiveType::INT, 4, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix4D<UInt> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_INT, 4, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix4D<HalfFloat> >()
{
	return AttributeType( PrimitiveType::HALF_FLOAT, 4, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix4D<Float> >()
{
	return AttributeType( PrimitiveType::FLOAT, 4, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Matrix4D<Double> >()
{
	return AttributeType( PrimitiveType::DOUBLE, 4, 4 );
}





//##########################################################################################
//##########################################################################################
//############		
//############		3D Color Shader Attribute Type Get Methods
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_INLINE AttributeType AttributeType:: get< Color3D<Bool> >()
{
	return AttributeType( PrimitiveType::BOOLEAN, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color3D<Byte> >()
{
	return AttributeType( PrimitiveType::BYTE, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color3D<UByte> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_BYTE, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color3D<Short> >()
{
	return AttributeType( PrimitiveType::SHORT, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color3D<UShort> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_SHORT, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color3D<Int> >()
{
	return AttributeType( PrimitiveType::INT, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color3D<UInt> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_INT, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color3D<HalfFloat> >()
{
	return AttributeType( PrimitiveType::HALF_FLOAT, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color3D<Float> >()
{
	return AttributeType( PrimitiveType::FLOAT, 3 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color3D<Double> >()
{
	return AttributeType( PrimitiveType::DOUBLE, 3 );
}





//##########################################################################################
//##########################################################################################
//############		
//############		4D Color Shader Attribute Type Get Methods
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_INLINE AttributeType AttributeType:: get< Color4D<Bool> >()
{
	return AttributeType( PrimitiveType::BOOLEAN, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color4D<Byte> >()
{
	return AttributeType( PrimitiveType::BYTE, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color4D<UByte> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_BYTE, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color4D<Short> >()
{
	return AttributeType( PrimitiveType::SHORT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color4D<UShort> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_SHORT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color4D<Int> >()
{
	return AttributeType( PrimitiveType::INT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color4D<UInt> >()
{
	return AttributeType( PrimitiveType::UNSIGNED_INT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color4D<HalfFloat> >()
{
	return AttributeType( PrimitiveType::HALF_FLOAT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color4D<Float> >()
{
	return AttributeType( PrimitiveType::FLOAT, 4 );
}


template <>
RIM_INLINE AttributeType AttributeType:: get< Color4D<Double> >()
{
	return AttributeType( PrimitiveType::DOUBLE, 4 );
}





//##########################################################################################
//##########################################################################################
//############		
//############		Scalar Shader Attribute Type Check Methods
//############		
//##########################################################################################
//##########################################################################################




template <> RIM_INLINE void AttributeType:: check< Bool >() {}
template <> RIM_INLINE void AttributeType:: check< Byte >() {}
template <> RIM_INLINE void AttributeType:: check< UByte >() {}
template <> RIM_INLINE void AttributeType:: check< Short >() {}
template <> RIM_INLINE void AttributeType:: check< UShort >() {}
template <> RIM_INLINE void AttributeType:: check< Int >() {}
template <> RIM_INLINE void AttributeType:: check< UInt >() {}
template <> RIM_INLINE void AttributeType:: check< HalfFloat >() {}
template <> RIM_INLINE void AttributeType:: check< Float >() {}
template <> RIM_INLINE void AttributeType:: check< Double >() {}




//##########################################################################################
//##########################################################################################
//############		
//############		2D Vector Shader Attribute Type Check Methods
//############		
//##########################################################################################
//##########################################################################################




template <> RIM_INLINE void AttributeType:: check< Vector2D<Bool> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector2D<Byte> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector2D<UByte> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector2D<Short> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector2D<UShort> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector2D<Int> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector2D<UInt> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector2D<HalfFloat> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector2D<Float> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector2D<Double> >() {}




//##########################################################################################
//##########################################################################################
//############		
//############		3D Vector Shader Attribute Type Check Methods
//############		
//##########################################################################################
//##########################################################################################




template <> RIM_INLINE void AttributeType:: check< Vector3D<Bool> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector3D<Byte> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector3D<UByte> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector3D<Short> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector3D<UShort> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector3D<Int> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector3D<UInt> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector3D<HalfFloat> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector3D<Float> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector3D<Double> >() {}




//##########################################################################################
//##########################################################################################
//############		
//############		4D Vector Shader Attribute Type Check Methods
//############		
//##########################################################################################
//##########################################################################################




template <> RIM_INLINE void AttributeType:: check< Vector4D<Bool> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector4D<Byte> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector4D<UByte> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector4D<Short> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector4D<UShort> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector4D<Int> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector4D<UInt> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector4D<HalfFloat> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector4D<Float> >() {}
template <> RIM_INLINE void AttributeType:: check< Vector4D<Double> >() {}




//##########################################################################################
//##########################################################################################
//############		
//############		Quaternion Shader Attribute Type Check Methods
//############		
//##########################################################################################
//##########################################################################################




template <> RIM_INLINE void AttributeType:: check< Quaternion<Bool> >() {}
template <> RIM_INLINE void AttributeType:: check< Quaternion<Byte> >() {}
template <> RIM_INLINE void AttributeType:: check< Quaternion<UByte> >() {}
template <> RIM_INLINE void AttributeType:: check< Quaternion<Short> >() {}
template <> RIM_INLINE void AttributeType:: check< Quaternion<UShort> >() {}
template <> RIM_INLINE void AttributeType:: check< Quaternion<Int> >() {}
template <> RIM_INLINE void AttributeType:: check< Quaternion<UInt> >() {}
template <> RIM_INLINE void AttributeType:: check< Quaternion<HalfFloat> >() {}
template <> RIM_INLINE void AttributeType:: check< Quaternion<Float> >() {}
template <> RIM_INLINE void AttributeType:: check< Quaternion<Double> >() {}




//##########################################################################################
//##########################################################################################
//############		
//############		2D Matrix Shader Attribute Type Check Methods
//############		
//##########################################################################################
//##########################################################################################




template <> RIM_INLINE void AttributeType:: check< Matrix2D<Bool> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix2D<Byte> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix2D<UByte> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix2D<Short> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix2D<UShort> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix2D<Int> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix2D<UInt> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix2D<HalfFloat> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix2D<Float> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix2D<Double> >() {}




//##########################################################################################
//##########################################################################################
//############		
//############		3D Matrix Shader Attribute Type Check Methods
//############		
//##########################################################################################
//##########################################################################################




template <> RIM_INLINE void AttributeType:: check< Matrix3D<Bool> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix3D<Byte> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix3D<UByte> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix3D<Short> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix3D<UShort> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix3D<Int> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix3D<UInt> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix3D<HalfFloat> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix3D<Float> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix3D<Double> >() {}




//##########################################################################################
//##########################################################################################
//############		
//############		4D Matrix Shader Attribute Type Check Methods
//############		
//##########################################################################################
//##########################################################################################




template <> RIM_INLINE void AttributeType:: check< Matrix4D<Bool> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix4D<Byte> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix4D<UByte> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix4D<Short> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix4D<UShort> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix4D<Int> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix4D<UInt> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix4D<HalfFloat> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix4D<Float> >() {}
template <> RIM_INLINE void AttributeType:: check< Matrix4D<Double> >() {}




//##########################################################################################
//##########################################################################################
//############		
//############		3D Color Shader Attribute Type Check Methods
//############		
//##########################################################################################
//##########################################################################################




template <> RIM_INLINE void AttributeType:: check< Color3D<Bool> >() {}
template <> RIM_INLINE void AttributeType:: check< Color3D<Byte> >() {}
template <> RIM_INLINE void AttributeType:: check< Color3D<UByte> >() {}
template <> RIM_INLINE void AttributeType:: check< Color3D<Short> >() {}
template <> RIM_INLINE void AttributeType:: check< Color3D<UShort> >() {}
template <> RIM_INLINE void AttributeType:: check< Color3D<Int> >() {}
template <> RIM_INLINE void AttributeType:: check< Color3D<UInt> >() {}
template <> RIM_INLINE void AttributeType:: check< Color3D<HalfFloat> >() {}
template <> RIM_INLINE void AttributeType:: check< Color3D<Float> >() {}
template <> RIM_INLINE void AttributeType:: check< Color3D<Double> >() {}




//##########################################################################################
//##########################################################################################
//############		
//############		4D Color Shader Attribute Type Check Methods
//############		
//##########################################################################################
//##########################################################################################




template <> RIM_INLINE void AttributeType:: check< Color4D<Bool> >() {}
template <> RIM_INLINE void AttributeType:: check< Color4D<Byte> >() {}
template <> RIM_INLINE void AttributeType:: check< Color4D<UByte> >() {}
template <> RIM_INLINE void AttributeType:: check< Color4D<Short> >() {}
template <> RIM_INLINE void AttributeType:: check< Color4D<UShort> >() {}
template <> RIM_INLINE void AttributeType:: check< Color4D<Int> >() {}
template <> RIM_INLINE void AttributeType:: check< Color4D<UInt> >() {}
template <> RIM_INLINE void AttributeType:: check< Color4D<HalfFloat> >() {}
template <> RIM_INLINE void AttributeType:: check< Color4D<Float> >() {}
template <> RIM_INLINE void AttributeType:: check< Color4D<Double> >() {}




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_ATTRIBUTE_TYPE_H
