/*
 *  rimAssetTranscoder.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/10/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ASSET_TRANSCODER_H
#define INCLUDE_RIM_ASSET_TRANSCODER_H


#include "rimAssetsConfig.h"


#include "rimAssetType.h"
#include "rimAssetScene.h"
#include "rimAssetTypeTranscoder.h"


//##########################################################################################
//****************************  Start Rim Assets Namespace  ********************************
RIM_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which reads and writes asset resources.
class AssetTranscoder : public resources::ResourceTranscoder<AssetScene>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new asset transcoder that has no types it can handle.
			AssetTranscoder();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this asset transcoder and release all associated resources.
			virtual ~AssetTranscoder();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Asset Type Accessor Methods
			
			
			
			
			/// Return the number of asset types that this transcoder can handle.
			RIM_INLINE Size getTypeCount() const
			{
				return assetTypes.getSize();
			}
			
			
			
			
			/// Add a new type to this asset transcoder that is can decode and encode.
			/**
			  * The method returns whether or not the new type was able to be added.
			  * If the asset type already exists in this transcoder, the method
			  * fails and returns FALSE. Otherwise it is added to the transcoder.
			  */
			template < typename DataType >
			RIM_INLINE Bool addType( const AssetType& type, const Pointer<AssetTypeTranscoder<DataType> >& transcoder )
			{
				if ( type == AssetType::UNDEFINED || transcoder.isNull() )
					return false;
				
				/// Check to see if this type is already handled by the transcoder.
				if ( assetTypes.contains( type.getHashCode(), type ) )
					return false;
				
				/// Add the new type delegate.
				assetTypes.add( type.getHashCode(), type,
								Pointer< AssetTypeInfo<DataType> >::construct( type, transcoder ) );
				
				return true;
			}
			
			
			
			
			/// Remove the specified asset type from this asset transcoder.
			/**
			  * The method returns whether or not the type was able to be removed.
			  */
			Bool removeType( const AssetType& type );
			
			
			
			
			/// Remove all asset types from this asset transcoder.
			void clearTypes();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Model Format Accessor Methods
			
			
			
			
			/// Return an object which represents the resource type that this transcoder can read and write.
			virtual resources::ResourceType getResourceType() const;
			
			
			
			
			/// Return an object which represents the resource format that this transcoder can read and write.
			virtual resources::ResourceFormat getResourceFormat() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Encoding Methods
			
			
			
			
			/// Return whether or not this asset transcoder is able to encode the specified resource.
			virtual Bool canEncode( const AssetScene& scene ) const;
			
			
			
			
			/// Encode the specified generic scene to the file at the specified path.
			/**
			  * If the method fails, FALSE is returned.
			  */
			virtual Bool encode( const resources::ResourceID& resourceID, const AssetScene& scene );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Decoding Methods
			
			
			
			
			/// Return whether or not the specified identifier refers to a valid asset file for this transcoder.
			virtual Bool canDecode( const resources::ResourceID& identifier ) const;
			
			
			
			
			/// Decode the asset file at the specified path and return a pointer to the decoded scene.
			/**
			  * If the method fails, a NULL pointer is returned.
			  */
			virtual Pointer<AssetScene> decode( const resources::ResourceID& resourceID, ResourceManager* manager = NULL );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Text Scalar Parsing Helper Methods
			
			
			
			
			/// Attempt to parse a boolean value from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the value was successfully parsed.
			  */
			static Bool parse( const UTF8Char* string, Size numCharacters, Bool& value );
			
			
			
			
			/// Attempt to parse a 32-bit signed integer value from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the value was successfully parsed.
			  */
			static Bool parse( const UTF8Char* string, Size numCharacters, Int32& value );
			
			
			
			
			/// Attempt to parse a 32-bit unsigned integer value from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the value was successfully parsed.
			  */
			static Bool parse( const UTF8Char* string, Size numCharacters, UInt32& value );
			
			
			
			
			/// Attempt to parse a 64-bit signed integer value from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the value was successfully parsed.
			  */
			static Bool parse( const UTF8Char* string, Size numCharacters, Int64& value );
			
			
			
			
			/// Attempt to parse a 64-bit unsigned integer value from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the value was successfully parsed.
			  */
			static Bool parse( const UTF8Char* string, Size numCharacters, UInt64& value );
			
			
			
			
			/// Attempt to parse a 32-bit float value from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the value was successfully parsed.
			  */
			static Bool parse( const UTF8Char* string, Size numCharacters, Float32& value );
			
			
			
			
			/// Attempt to parse a 64-bit float value from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the value was successfully parsed.
			  */
			static Bool parse( const UTF8Char* string, Size numCharacters, Float64& value );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Text Vector Parsing Helper Methods
			
			
			
			
			/// Attempt to parse a 32-bit 2-float vector from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the matrix was successfully parsed.
			  */
			static Bool parse( const UTF8Char* string, Size numCharacters, math::Vector2f& vector );
			
			
			
			
			/// Attempt to parse a 32-bit 3-float vector from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the matrix was successfully parsed.
			  */
			static Bool parse( const UTF8Char* string, Size numCharacters, math::Vector3f& vector );
			
			
			
			
			/// Attempt to parse a 32-bit 4-float vector from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the matrix was successfully parsed.
			  */
			static Bool parse( const UTF8Char* string, Size numCharacters, math::Vector4f& vector );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Text Matrix Parsing Helper Methods
			
			
			
			
			/// Attempt to parse a 32-bit 2x2 float matrix from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the matrix was successfully parsed.
			  */
			static Bool parse( const UTF8Char* string, Size numCharacters, math::Matrix2f& matrix );
			
			
			
			
			/// Attempt to parse a 32-bit 3x3 float matrix from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the matrix was successfully parsed.
			  */
			static Bool parse( const UTF8Char* string, Size numCharacters, math::Matrix3f& matrix );
			
			
			
			
			/// Attempt to parse a 32-bit 4x4 float matrix from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the matrix was successfully parsed.
			  */
			static Bool parse( const UTF8Char* string, Size numCharacters, math::Matrix4f& matrix );
			
			
			
			
			/// Attempt to parse a 32-bit float matrix of arbitrary size from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the matrix was successfully parsed.
			  */
			template < Size numRows, Size numColumns >
			RIM_INLINE static Bool parse( const UTF8Char* string, Size numCharacters,
										math::MatrixND<Float,numRows,numColumns>& matrix )
			{
				return parseMatrix( string, numCharacters, numRows, numColumns, matrix.toArrayColumnMajor() );
			}
			
			
			
			
			/// Attempt to parse a 32-bit float matrix of arbitrary size from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the matrix was successfully parsed.
			  */
			RIM_INLINE static Bool parse( const UTF8Char* string, Size numCharacters, math::Matrix<Float>& matrix )
			{
				if ( matrix.getRowCount() == 0 || matrix.getColumnCount() == 0 )
					return false;
				
				return parseMatrix( string, numCharacters, matrix.getRowCount(), matrix.getColumnCount(), matrix.toArrayColumnMajor() );
			}
			
			
			
			
			/// Attempt to parse a 32-bit float matrix of arbitrary size from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the matrix was successfully parsed.
			  */
			RIM_INLINE static Bool parse( const UTF8Char* string, Size numCharacters,
										Size numRows, Size numColumns, math::Matrix<Float>& matrix )
			{
				if ( matrix.getRowCount() != numRows || matrix.getColumnCount() != numColumns )
					matrix = math::Matrix<Float>( numRows, numColumns );
				
				return parseMatrix( string, numCharacters, numRows, numColumns, matrix.toArrayColumnMajor() );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Text Range Parsing Helper Methods
			
			
			
			
			/// Attempt to parse a 32-bit float 1D range from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the range was successfully parsed.
			  */
			RIM_INLINE static Bool parse( const UTF8Char* string, Size numCharacters, math::AABB1f& range )
			{
				return parseVector( string, numCharacters, 2, &range.min );
			}
			
			
			
			
			/// Attempt to parse a 32-bit float 2D range from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the range was successfully parsed.
			  */
			RIM_INLINE static Bool parse( const UTF8Char* string, Size numCharacters, math::AABB2f& range )
			{
				return parseMatrix( string, numCharacters, 2, 2, &range.min.x );
			}
			
			
			
			
			/// Attempt to parse a 32-bit float 3D range from the given string, placing it in the output parameter value.
			/**
			  * The method returns whether or not the range was successfully parsed.
			  */
			RIM_INLINE static Bool parse( const UTF8Char* string, Size numCharacters, math::AABB3f& range )
			{
				return parseMatrix( string, numCharacters, 3, 2, &range.min.x );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Text String Parsing Helper Methods
			
			
			
			
			/// Attempt to parse a string, populating the output parameter object with the parsed string pointer and length.
			/**
			  * The method returns whether or not the string was successfully parsed.
			  */
			static Bool parseString( const UTF8Char* string, Size numCharacters, const UTF8Char*& result, Size& resultLength );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Text Object Parsing Helper Methods
			
			
			
			
			/// Attempt to parse an object type declaration.
			/**
			  * The method returns whether or not the object type was successfully parsed.
			  * The string pointer is advanced to the next character after the object type,
			  * or until parsing fails.
			  * The method is insensitive to whitespace before, after, and between tokens.
			  */
			static Bool parseObjectType( const UTF8Char*& string, Size numCharacters, AssetType& type );
			
			
			
			
			/// Attempt to parse an object, populating the output parameter object with the parsed fields and object attributes.
			/**
			  * The method returns whether or not the object was successfully parsed.
			  * The string pointer is advanced to the next character after the object,
			  * or until parsing fails.
			  * The method is insensitive to whitespace before, after, and between tokens.
			  */
			static Bool parseObject( const UTF8Char*& string, Size numCharacters, AssetObject& object );
			
			
			
			
			/// Attempt to parse an object, populating the output parameter object with the parsed fields and object attributes.
			/**
			  * The method returns whether or not the object was successfully parsed.
			  * The string pointer is advanced to the next character after the object,
			  * or until parsing fails.
			  * The method is insensitive to whitespace before, after, and between tokens.
			  */
			static Bool parseObject( const UTF8Char*& string, Size numCharacters, AssetObject& object, AssetType& type );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Text Object Parsing Helper Methods
			
			
			
			
			/// Determine the length in character code points of an object, advancing the iterator by that amount.
			static void skipObject( const UTF8Char*& string, const UTF8Char* stringEnd );
			
			
			
			
			/// Determine the length in character code points of an object, advancing the iterator by that amount.
			static void skipObjectType( const UTF8Char*& string, const UTF8Char* stringEnd );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations
			
			
			
			
			/// The base class for objects that contain encoding/decoding information for an asset type.
			class AssetTypeInfoBase
			{
				public:
					
					
					/// Destroy this asset type info object.
					virtual ~AssetTypeInfoBase()
					{
					}
					
					
					/// Create and return a copy of this asset type info object.
					virtual AssetTypeInfoBase* copy() const = 0;
					
					
					virtual Bool encodeText( UTF8StringBuffer& buffer, ResourceManager* manager, const void* asset ) = 0;
					
					
					virtual Bool decodeText( const AssetObject& object, ResourceManager* manager, AssetScene& scene ) = 0;
					
					
			};
			
			
			
			
			template < typename DataType >
			class AssetTypeInfo;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Type Declarations
			
			
			
			
			
			/// An enum type that defines the values that can be stored in a file header.
			typedef enum HeaderField
			{
				UNDEFINED_HEADER_FIELD = 0,
				
				/// An integer indicating the version number of this file format.
				VERSION,
				
				/// A boolean value that indicates the endianness of embedded binary data.
				IS_BIG_ENDIAN,
				
				/// A string value that provides a global name for the file.
				NAME,
				
				/// A string value that provides a global description for the file.
				DESCRIPTION
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Parsing Methods
			
			
			
			
			Bool parseHeader( const UTF8Char*& string, Size stringLength, AssetScene& scene );
			
			
			
			
			Bool parseObjects( const UTF8Char*& string, Size stringLength, ResourceManager* resourceManager, AssetScene& scene );
			
			
			
			
			template < typename T >
			static Bool parseVector( const UTF8Char* string, Size numCharacters, Size numComponents, T* result );
			
			
			template < typename T >
			static Bool parseMatrix( const UTF8Char* string, Size numCharacters, Size numRows, Size numColumns, T* result );
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Parsing Helper Methods
			
			
			
			
			static void skipWhitespace( const UTF8Char*& string, const UTF8Char* stringEnd )
			{
				while ( string != stringEnd && isWhitespace(*string) )
					string++;
			}
			
			
			
			static void skipToAfterNext( const UTF8Char*& string, const UTF8Char* stringEnd, UTF32Char c )
			{
				Size numUnclosedBraces = 0;
				
				while ( string < stringEnd && (*string != c || numUnclosedBraces > 0) )
				{
					if ( *string == '{' )
						numUnclosedBraces++;
					else if ( *string == '}' && numUnclosedBraces > 0 )
						numUnclosedBraces--;
					
					string++;
				}
				
				// We are at the character, so skip to next character.
				if ( string < stringEnd )
					string++;
			}
			
			
			
			
			/// Determine the length in character code points of an object field name, advancing the iterator by that amount.
			static void getWordLength( const UTF8Char*& string, const UTF8Char* stringEnd, Size& length )
			{
				length = 0;
				
				while ( string < stringEnd && isWordCharacter(*string) )
				{
					length++;
					string++;
				}
			}
			
			
			
			
			/// Determine the length in character code points of an object field value, advancing the iterator by that amount.
			static void getFieldValueLength( const UTF8Char*& string, const UTF8Char* stringEnd, Size& length )
			{
				length = 0;
				Size numUnclosedBraces = 0;
				
				while ( string < stringEnd && (*string != ';' || numUnclosedBraces > 0) )
				{
					if ( *string == '{' )
						numUnclosedBraces++;
					else if ( *string == '}' && numUnclosedBraces > 0 )
						numUnclosedBraces--;
					
					length++;
					string++;
				}
			}
			
			
			
			
			/// Return whether or not the specified character is a word character.
			RIM_INLINE static Bool isWordCharacter( UTF8Char c )
			{
				return UTF8String::isALetter(c) || UTF8String::isADigit(c) || c == '_';
			}
			
			
			
			
			/// Return whether or not the specified character is a whitespace character.
			RIM_INLINE static Bool isWhitespace( UTF32Char c )
			{
				return c == ' ' || c == '\t' || c == '\n' || c == '\r';
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			static HeaderField getHeaderFieldType( const AssetObject::String& name );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A map from asset types to objects that decode and encode those types.
			HashMap<AssetType,Pointer<AssetTypeInfoBase> > assetTypes;
			
			
			
			
			/// An asset object used to temporarily hold parsed asset objects.
			AssetObject tempObject;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Asset Type Info Class Declaration
//############		
//##########################################################################################
//##########################################################################################




template < typename DataType >
class AssetTranscoder:: AssetTypeInfo : public AssetTypeInfoBase
{
	public:
		
		RIM_INLINE AssetTypeInfo( const AssetType& newType, const Pointer< AssetTypeTranscoder<DataType> >& newTranscoder )
			:	type( newType ),
				transcoder( newTranscoder )
		{
		}
		
		
		virtual AssetTypeInfo* copy() const
		{
			return util::construct<AssetTypeInfo<DataType> >( *this );
		}
		
		
		virtual Bool encodeText( UTF8StringBuffer& buffer, ResourceManager* manager, const void* asset )
		{
			if ( asset == NULL || transcoder.isNull() )
				return false;
			
			return transcoder->encodeText( buffer, manager, *static_cast<const DataType*>( asset ) );
		}
		
		
		virtual Bool decodeText( const AssetObject& object, ResourceManager* manager, AssetScene& scene )
		{
			if ( transcoder.isNull() )
				return false;
			
			Pointer<DataType> asset = transcoder->decodeText( type, object, manager );
			
			if ( asset.isNull() )
				return false;
			
			scene.addAsset<DataType>( asset, UTF8String(object.getName().string, object.getName().length) );
			
			return true;
		}
		
		
		/// The type of asset that this asset type info handles.
		AssetType type;
		
		
		/// An object that handles encoding and decoding this asset type.
		Pointer< AssetTypeTranscoder<DataType> > transcoder;
		
		
};




//##########################################################################################
//****************************  End Rim Assets Namespace  **********************************
RIM_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ASSET_TRANSCODER_H
