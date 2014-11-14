/*
 *  rimResourceID.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 11/27/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_RESOURCE_ID_H
#define INCLUDE_RIM_RESOURCE_ID_H


#include "rimResourcesConfig.h"


#include "rimResourceType.h"
#include "rimResourceFormat.h"


//##########################################################################################
//**************************  Start Rim Resources Namespace  *******************************
RIM_RESOURCES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




/// The integer type to use for file-local resource ID numbers.
typedef Int64 ResourceLocalID;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a unique identifier for a resource.
/**
  * A resource is specified by a path to a file, an enum determining how that file
  * should be interpreted (its type), the type of resource that this ID corresponds to,
  * and an optional name which is used to identify the resource within the file.
  */
class ResourceID
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new resource ID which doesn't point to a valid resource.
			RIM_INLINE ResourceID()
				:	localID( -1 )
			{
			}
			
			
			
			
			/// Create a new resource ID with the specified resource file path.
			RIM_INLINE ResourceID( const data::UTF8String& newFilePath )
				:	filePath( newFilePath ),
					localID( -1 )
			{
			}
			
			
			
			
			/// Create a new resource ID with the specified attributes.
			RIM_INLINE ResourceID( const ResourceType& newType, const data::UTF8String& newFilePath )
				:	type( newType ),
					filePath( newFilePath ),
					localID( -1 )
			{
			}
			
			
			
			
			/// Create a new resource ID with the specified attributes.
			RIM_INLINE ResourceID( const ResourceType& newType, const ResourceFormat& newFormat,
									const data::UTF8String& newFilePath )
				:	type( newType ),
					format( newFormat ),
					filePath( newFilePath ),
					localID( -1 )
			{
			}
			
			
			
			
			/// Create a new resource ID with the specified attributes.
			RIM_INLINE ResourceID( const ResourceType& newType, const ResourceFormat& newFormat,
									const data::UTF8String& newFilePath, const data::UTF8String& newName,
									ResourceLocalID newLocalID = ResourceLocalID(-1) )
				:	type( newType ),
					format( newFormat ),
					filePath( newFilePath ),
					name( newName ),
					localID( newLocalID )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resource Type Accessor Methods
			
			
			
			
			/// Return an object describing the type of resource this ID refers to.
			RIM_INLINE const ResourceType& getType() const
			{
				return type;
			}
			
			
			
			
			/// Set an object describing the type of resource this ID refers to.
			RIM_INLINE void setType( const ResourceType& newType )
			{
				type = newType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resource File Type Accessor Methods
			
			
			
			
			/// Return an object describing the format of file this ID refers to.
			RIM_INLINE const ResourceFormat& getFormat() const
			{
				return format;
			}
			
			
			
			
			/// Set an object describing the format of file this ID refers to.
			RIM_INLINE void setFormat( const ResourceFormat& newFormat )
			{
				format = newFormat;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	File Path String Accessor Methods
			
			
			
			
			/// Return a reference to the UTF-8 encoded string representing a path to this resource.
			RIM_INLINE const data::UTF8String& getFilePath() const
			{
				return filePath;
			}
			
			
			
			
			/// Set a UTF-8 encoded string representing a path to this resource.
			RIM_INLINE void setFilePath( const data::UTF8String& newFilePath )
			{
				filePath = newFilePath;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resource Name Accessor Methods
			
			
			
			
			/// Return a UTF-8 encoded string representing the name of the resource for this ID.
			RIM_INLINE const data::UTF8String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set a UTF-8 encoded string representing the name of the resource for this ID.
			RIM_INLINE void setName( const data::UTF8String& newName )
			{
				name = newName;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resource Local ID Accessor Methods
			
			
			
			
			/// Return an integer ID for this resource local to the file that can be used to uniquely identify it.
			/**
			  * If the local ID is unused, it should have a value of -1.
			  */
			RIM_INLINE ResourceLocalID getLocalID() const
			{
				return localID;
			}
			
			
			
			
			/// Set an integer ID for this resource local to the file that can be used to uniquely identify it.
			/**
			  * If the local ID is unused, it should have a value of -1.
			  */
			RIM_INLINE void setLocalID( ResourceLocalID newLocalID )
			{
				localID = newLocalID;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this resource ID is equal to another.
			RIM_INLINE Bool operator == ( const ResourceID& other ) const
			{
				Bool result = type == other.type && format == other.format && filePath == other.filePath && name == other.name;
				
				// Check the local ID if it is valid.
				if ( result && localID != INVALID_LOCAL_ID && localID == other.localID )
					return true;
				
				return result;
			}
			
			
			
			
			/// Return whether or not this resource ID is not equal to another.
			RIM_INLINE Bool operator != ( const ResourceID& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Hash Code Accessor Method
			
			
			
			
			/// Return an integral hash code for this resource ID.
			RIM_INLINE Hash getHashCode() const
			{
				return Hash(type)*Hash(format)*filePath.getHashCode() ^ name.getHashCode();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// The invalid local ID that indicates the local ID is unused.
			static const ResourceLocalID INVALID_LOCAL_ID = -1;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object describing the type of this resource.
			ResourceType type;
			
			
			
			
			/// An object describing the format of this resource's file, how it should be interpreted.
			ResourceFormat format;
			
			
			
			
			/// A string representing a path to the resource.
			data::UTF8String filePath;
			
			
			
			
			/// The optional name of the resource within the file.
			data::UTF8String name;
			
			
			
			
			/// An integer ID for this resource local to the file that can be used to uniquely identify it.
			/**
			  * If the local ID is unused, it should have a value of -1.
			  */
			ResourceLocalID localID;
			
			
			
};




//##########################################################################################
//**************************  End Rim Resources Namespace  *********************************
RIM_RESOURCES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_RESOURCE_ID_H
