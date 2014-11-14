/*
 *  rimAssetObject.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/13/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ASSET_OBJECT_H
#define INCLUDE_RIM_ASSET_OBJECT_H


#include "rimAssetsConfig.h"


//##########################################################################################
//****************************  Start Rim Assets Namespace  ********************************
RIM_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains a pre-parsed text-based asset object.
class AssetObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Declarations
			
			
			
			
			/// A class representing a lightweight no-allocation string that points to external character data.
			class String
			{
				public:
					
					/// Create a new string with no character data.
					RIM_INLINE String()
						:	string( NULL ),
							length( 0 )
					{
					}
					
					/// Create a new string with the specified starting pointer and length.
					RIM_INLINE String( const UTF8Char* newString, Size newLength )
						:	string( newString ),
							length( newLength )
					{
					}
					
					
					/// Return whether or not this string has any characters.
					RIM_INLINE Bool isSet() const
					{
						return string && length > Size(0);
					}
					
					
					/// Return whether or not this string has any characters.
					RIM_INLINE Bool isNull() const
					{
						return !string || length == Size(0);
					}
					
					
					/// A pointer to the first UTF8 character for this string.
					/**
					  * This string may not be NULL-terminated.
					  */
					const UTF8Char* string;
					
					
					/// The number of characters in this string.
					Size length;
					
					
			};
			
			
			
			
			/// A class representing a single name-value pair for an object field.
			class Field
			{
				public:
					
					/// Create a new field with the specified name and value strings.
					RIM_INLINE Field( const String& newName,
									const String& newValue )
						:	name( newName ),
							value( newValue )
					{
					}
					
					
					/// A string representing the name of this field.
					String name;
					
					
					/// A string representing the value of this field.
					String value;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new asset object with no fields.
			RIM_INLINE AssetObject()
				:	localID( ResourceID::INVALID_LOCAL_ID )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Field Accessor Methods
			
			
			
			
			/// Return the number of fields there are in this asset object.
			RIM_INLINE Size getFieldCount() const
			{
				return fields.getSize();
			}
			
			
			
			
			/// Return a reference to the field at the specified index in this object.
			RIM_INLINE const Field& getField( Index fieldIndex ) const
			{
				return fields[fieldIndex];
			}
			
			
			
			
			/// Add a new field to this asset object, specified as a name/value pair of strings.
			RIM_INLINE void addField( const UTF8Char* nameStart, Size nameLength,
										const UTF8Char* valueStart, Size valueLength )
			{
				fields.add( Field( String( nameStart, nameLength ), String( valueStart, valueLength ) ) );
			}
			
			
			
			
			/// Remove all fields from this asset object.
			RIM_INLINE void clearFields()
			{
				fields.clear();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Asset Object Name Accessor Methods
			
			
			
			
			/// Return a reference to a string representing the name of this asset object.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set a string representing the name of this asset object.
			RIM_INLINE void setName( const String& newName )
			{
				name = newName;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Asset Object Name Accessor Methods
			
			
			
			
			/// Return the file-local ID for this asset object.
			RIM_INLINE ResourceLocalID getLocalID() const
			{
				return localID;
			}
			
			
			
			
			/// Set the file-local ID for this asset object.
			RIM_INLINE void setLocalID( ResourceLocalID newLocalID )
			{
				localID = newLocalID;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Asset Object Reset Method
			
			
			
			
			/// Reset this asset object to the defaut state with no fields and no name or local ID.
			RIM_INLINE void reset()
			{
				localID = ResourceID::INVALID_LOCAL_ID;
				name = String();
				fields.clear();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The file-local ID for this asset object.
			ResourceLocalID localID;
			
			
			
			
			/// The name of this asset object.
			String name;
			
			
			
			
			/// A list of the fields in this asset object.
			ShortArrayList<Field,8> fields;
			
			
			
};




//##########################################################################################
//****************************  End Rim Assets Namespace  **********************************
RIM_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ASSET_OBJECT_H
