/*
 *  rimAssetType.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/11/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ASSET_TYPE_H
#define INCLUDE_RIM_ASSET_TYPE_H


#include "rimAssetsConfig.h"


//##########################################################################################
//****************************  Start Rim Assets Namespace  ********************************
RIM_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the type of a generic asset.
/**
  * An asset type is defined by a unique string.
  */
class AssetType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new asset type with an empty type string.
			RIM_INLINE AssetType()
				:	typeString()
			{
			}
			
			
			
			
			/// Create a new asset type with the specified constant NULL-terminated type string.
			RIM_INLINE AssetType( const Char* newTypeString )
				:	typeString( newTypeString )
			{
			}
			
			
			
			
			/// Create a new asset type with the specified type string.
			RIM_INLINE AssetType( const String& newTypeString )
				:	typeString( newTypeString )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return a string representing the name of this asset type.
			RIM_INLINE const String& getName() const
			{
				return typeString;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this asset type is equal to another.
			RIM_INLINE Bool operator == ( const AssetType& other ) const
			{
				return typeString == other.typeString;
			}
			
			
			
			
			/// Return whether or not this asset type is equal to another.
			RIM_INLINE Bool operator != ( const AssetType& other ) const
			{
				return typeString != other.typeString;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Hash Code Accessor Methods
			
			
			
			
			/// Return an integer hash code for this asset type.
			RIM_INLINE Hash getHashCode() const
			{
				return typeString.getHashCode();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Asset Type Determination Method
			
			
			
			
			template < typename DataType >
			RIM_INLINE static const AssetType& of()
			{
				return UNDEFINED;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Asset Type Declarations
			
			
			
			
			/// The asset type to use for an undefined object type.
			static const AssetType UNDEFINED;
			
			/// The asset type to use for a 8-bit signed integer.
			static const AssetType INT8;
			
			/// The asset type to use for a 8-bit unsigned integer.
			static const AssetType UINT8;
			
			/// The asset type to use for a 16-bit signed integer.
			static const AssetType INT16;
			
			/// The asset type to use for a 16-bit unsigned integer.
			static const AssetType UINT16;
			
			/// The asset type to use for a 32-bit signed integer.
			static const AssetType INT32;
			
			/// The asset type to use for a 32-bit unsigned integer.
			static const AssetType UINT32;
			
			/// The asset type to use for a 64-bit signed integer.
			static const AssetType INT64;
			
			/// The asset type to use for a 64-bit unsigned integer.
			static const AssetType UINT64;
			
			/// The asset type to use for a floating point number.
			static const AssetType FLOAT32;
			
			/// The asset type to use for a double floating point number.
			static const AssetType FLOAT64;
			
			/// The asset type to use for a 2-component 32-bit float vector.
			static const AssetType VECTOR2_F32;
			
			/// The asset type to use for a 2-component 64-bit float vector.
			static const AssetType VECTOR2_F64;
			
			/// The asset type to use for a 3-component 32-bit float vector.
			static const AssetType VECTOR3_F32;
			
			/// The asset type to use for a 3-component 64-bit float vector.
			static const AssetType VECTOR3_F64;
			
			/// The asset type to use for a 4-component 32-bit float vector.
			static const AssetType VECTOR4_F32;
			
			/// The asset type to use for a 4-component 64-bit float vector.
			static const AssetType VECTOR4_F64;
			
			/// The asset type to use for a 2x2 32-bit float matrix.
			static const AssetType MATRIX2_F32;
			
			/// The asset type to use for a 2x2 64-bit float matrix.
			static const AssetType MATRIX2_F64;
			
			/// The asset type to use for a 3x3 32-bit float matrix.
			static const AssetType MATRIX3_F32;
			
			/// The asset type to use for a 3x3 64-bit float matrix.
			static const AssetType MATRIX3_F64;
			
			/// The asset type to use for a 4x4 32-bit float matrix.
			static const AssetType MATRIX4_F32;
			
			/// The asset type to use for a 4x4 64-bit float matrix.
			static const AssetType MATRIX4_F64;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A string which represents this asset type.
			String typeString;
			
			
			
};




template <>
RIM_INLINE const AssetType& AssetType::of<Int8>()
{
	return AssetType::INT8;
}




template <>
RIM_INLINE const AssetType& AssetType::of<UInt8>()
{
	return AssetType::UINT8;
}




template <>
RIM_INLINE const AssetType& AssetType::of<Int16>()
{
	return AssetType::INT16;
}




template <>
RIM_INLINE const AssetType& AssetType::of<UInt16>()
{
	return AssetType::UINT16;
}




template <>
RIM_INLINE const AssetType& AssetType::of<Int32>()
{
	return AssetType::INT32;
}




template <>
RIM_INLINE const AssetType& AssetType::of<UInt32>()
{
	return AssetType::UINT32;
}




template <>
RIM_INLINE const AssetType& AssetType::of<Int64>()
{
	return AssetType::INT64;
}




template <>
RIM_INLINE const AssetType& AssetType::of<UInt64>()
{
	return AssetType::UINT64;
}




template <>
RIM_INLINE const AssetType& AssetType::of<Float32>()
{
	return AssetType::FLOAT32;
}




template <>
RIM_INLINE const AssetType& AssetType::of<Float64>()
{
	return AssetType::FLOAT64;
}




template <>
RIM_INLINE const AssetType& AssetType::of< math::Vector2D<Float32> >()
{
	return AssetType::VECTOR2_F32;
}




template <>
RIM_INLINE const AssetType& AssetType::of< math::Vector2D<Float64> >()
{
	return AssetType::VECTOR2_F64;
}




template <>
RIM_INLINE const AssetType& AssetType::of< math::Vector3D<Float32> >()
{
	return AssetType::VECTOR3_F32;
}




template <>
RIM_INLINE const AssetType& AssetType::of< math::Vector3D<Float64> >()
{
	return AssetType::VECTOR3_F64;
}




template <>
RIM_INLINE const AssetType& AssetType::of< math::Vector4D<Float32> >()
{
	return AssetType::VECTOR4_F32;
}




template <>
RIM_INLINE const AssetType& AssetType::of< math::Vector4D<Float64> >()
{
	return AssetType::VECTOR4_F64;
}




template <>
RIM_INLINE const AssetType& AssetType::of< math::Matrix2D<Float32> >()
{
	return AssetType::MATRIX2_F32;
}




template <>
RIM_INLINE const AssetType& AssetType::of< math::Matrix2D<Float64> >()
{
	return AssetType::MATRIX2_F64;
}




template <>
RIM_INLINE const AssetType& AssetType::of< math::Matrix3D<Float32> >()
{
	return AssetType::MATRIX3_F32;
}




template <>
RIM_INLINE const AssetType& AssetType::of< math::Matrix3D<Float64> >()
{
	return AssetType::MATRIX3_F64;
}




template <>
RIM_INLINE const AssetType& AssetType::of< math::Matrix4D<Float32> >()
{
	return AssetType::MATRIX4_F32;
}




template <>
RIM_INLINE const AssetType& AssetType::of< math::Matrix4D<Float64> >()
{
	return AssetType::MATRIX4_F64;
}




//##########################################################################################
//****************************  End Rim Assets Namespace  **********************************
RIM_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ASSET_TYPE_H
