/*
 *  rimResource.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 11/27/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_RESOURCE_H
#define INCLUDE_RIM_RESOURCE_H


#include "rimResourcesConfig.h"


#include "rimResourceID.h"


//##########################################################################################
//**************************  Start Rim Resources Namespace  *******************************
RIM_RESOURCES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates a handle to resource data.
/**
  * The class allows the user to either load the resource data manually, or
  * to provide a unique identifier and ResourceLoader object to defer loading the
  * resource until it is needed.
  */
template < typename DataType >
class Resource
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Declaration
			
			
			
			
			/// Define the type for a resource loading callback function.
			typedef lang::Function< lang::Pointer<DataType> ( const ResourceID& ) > LoadCallback;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default resource with no data and no resource identifier or loader.
			/**
			  * The created resource is essentially unuseable and can be used to indicate an
			  * invalid resource or a resource that has not yet been set.
			  */
			RIM_INLINE Resource()
				:	info( NULL )
			{
			}
			
			
			
			
			/// Create a new resource for the specified data pointer.
			/**
			  * If the specified data pointer is NULL, the resource is unusable because it has
			  * no way to load any data for the resource.
			  */
			RIM_INLINE Resource( const lang::Pointer<DataType>& newData )
				:	info( util::construct<ResourceInfo>( newData ) )
			{
			}
			
			
			
			
			/// Create a new resource for the specified data which is associated with the specified unique identifier.
			/**
			  * If the specified data pointer is NULL, the resource is unusable because it has
			  * no way to load the resource associated with the given ID.
			  */
			RIM_INLINE Resource( const lang::Pointer<DataType>& newData, const ResourceID& newIdentifier )
				:	info( util::construct<ResourceInfo>( newData, newIdentifier ) )
			{
			}
			
			
			
			
			/// Create a new resource for the specified unique resource identifier.
			RIM_INLINE Resource( const ResourceID& newIdentifier )
				:	info( util::construct<ResourceInfo>( newIdentifier ) )
			{
			}
			
			
			
			
			/// Create a new resource for the specified unique resource identifier using the specified loader object.
			/**
			  * A resource created using this constructor will lazily load the resource when it is first
			  * dereferenced. The specified ID is used to load the resource using the given ResourceLoader
			  * object. If the loader object pointer is NULL, the new resource will be useless because
			  * it has no way to load any data for the resource.
			  */
			RIM_INLINE Resource( const ResourceID& newIdentifier, 
								const LoadCallback& newLoadCallback )
				:	info( util::construct<ResourceInfo>( newIdentifier, newLoadCallback ) )
			{
			}
			
			
			
			
			RIM_INLINE Resource( const Resource& other )
				:	info( other.info )
			{
				if ( info )
					info->referenceCount++;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			RIM_INLINE ~Resource()
			{
				if ( info && (--info->referenceCount) == 0 )
					util::destruct( info );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			RIM_INLINE Resource& operator = ( const Resource& other )
			{
				if ( info != other.info )
				{
					if ( info && (--info->referenceCount) == 0 )
						util::destruct( info );
					
					info = other.info;
					
					if ( info )
						info->referenceCount++;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this resource refers to the same resource as another.
			/**
			  * This operator returns TRUE if the data pointer they refer to is equal, or
			  * if they both have the same resource identifier/loader. Otherwise FALSE is
			  * returned.
			  */
			RIM_INLINE Bool operator == ( const Resource& other ) const
			{
				if ( info == other.info )
					return true;
				else if ( info && other.info && (info->data == other.info->data || info->identifier == other.info->indentifier) )
					return true;
				else
					return false;
			}
			
			
			
			
			/// Return whether or not this resource refers to a different resource than another.
			/**
			  * This operator returns FALSE if the data pointer they refer to is equal, or
			  * if they both have the same resource identifier/loader. Otherwise TRUE is
			  * returned.
			  */
			RIM_INLINE Bool operator != ( const Resource& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Data Accessor Methods
			
			
			
			
			/// Return a pointer to the data associated with this resource.
			/**
			  * The method can return NULL if the resource's data has not yet
			  * been loaded.
			  */
			RIM_INLINE lang::Pointer<DataType> getData() const
			{
				if ( info )
					return info->data;
				else
					return lang::Pointer<DataType>();
			}
			
			
			
			
			/// Set a pointer to the data associated with this resource.
			RIM_INLINE void setData( const lang::Pointer<DataType>& newData )
			{
				if ( info )
					info->data = newData;
				else
					info = util::construct<ResourceInfo>( newData );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Pointer Accesor Method
			
			
			
			
			/// Return a pointer to the data associated with this resource.
			/**
			  * The method can return NULL if the resource's data has not yet
			  * been loaded.
			  */
			RIM_INLINE const DataType* getPointer() const
			{
				if ( info )
					return info->data;
				else
					return NULL;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Cast Operators
			
			
			
			
			/// Cast this Resource object to a reference-counted pointer.
			RIM_INLINE operator lang::Pointer<DataType> () const
			{
				if ( info )
					return info->data;
				else
					return lang::Pointer<DataType>();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Dereferencing Operators
			
			
			
			
			/// Return a reference to the data associated with this resource.
			/**
			  * This operator dereferences the data for the resource. If the data
			  * pointer is currently NULL, the resource attempts to use the associated resource
			  * loader to load the resource data. An assertion is raised if there is no identifier
			  * or loader for the resource if the data is NULL.
			  */
			RIM_INLINE DataType& operator * () const
			{
				RIM_DEBUG_ASSERT_MESSAGE( info != NULL && info->data.isSet(), "Tried to access resource with NULL info or data." );
				
				return *info->data;
			}
			
			
			
			
			/// Return a pointer to the data associated with this resource.
			/**
			  * This operator dereferences the data for the resource. If the data
			  * pointer is currently NULL, the resource attempts to use the associated resource
			  * loader to load the resource data. An assertion is raised if there is no identifier
			  * or loader for the resource if the data is NULL.
			  */
			RIM_INLINE DataType* operator -> () const
			{
				if ( info == NULL )
					return NULL;
				
				if ( info->data.isNull() && info->loadCallback.isSet() )
					info->data = info->loadCallback( info->identifier );
				
				return info->data;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resource Identifier Accessor Methods
			
			
			
			
			/// Return whether or not this resource has a unique identifier associated with it.
			RIM_INLINE Bool hasID() const
			{
				return info != NULL;
			}
			
			
			
			
			/// Return a pointer to the unique identifier associated with this resource.
			/**
			  * If the resource has no identifier associated with it, NULL is returned.
			  */
			RIM_INLINE ResourceID* getID()
			{
				if ( info )
					return &info->identifier;
				else
					return NULL;
			}
			
			
			
			
			/// Return a pointer to the unique identifier associated with this resource.
			/**
			  * If the resource has no identifier associated with it, NULL is returned.
			  */
			RIM_INLINE const ResourceID* getID() const
			{
				if ( info )
					return &info->identifier;
				else
					return NULL;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resource Loader Accessor Methods
			
			
			
			
			/// Return whether or not this resource has a ResourceLoader object associated with it.
			RIM_INLINE Bool hadLoadCallback() const
			{
				return info != NULL && info->loadCallback.isSet();
			}
			
			
			
			
			/// Return a pointer to the resource loading callback function associated with this resource.
			/**
			  * If the resource has no callback function associated with it, NULL is returned.
			  */
			RIM_INLINE const LoadCallback* getLoadCallback() const
			{
				if ( info )
					return &info->loadCallback;
				else
					return NULL;
			}
			
			
			
			
			/// Set the resource loading callback function associated with this resource.
			/**
			  * If the resource has no callback function associated with it, an assertion is raised.
			  */
			RIM_INLINE void setLoadCallback( const LoadCallback& newLoadCallback )
			{
				if ( info == NULL )
					info = util::construct<ResourceInfo>( newLoadCallback );
				else
					info->loadCallback = newLoadCallback;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resource Loading/Releasing Methods
			
			
			
			
			/// Attempt to load the data for this resource if necessary.
			/**
			  * This method tries to ensure that the resource data is loaded and available
			  * for use. If the data is already loaded, the method returns TRUE. Otherwise,
			  * the method loads the data using the resource's ID and loader object and
			  * returns TRUE. If there is no loader or ID for this resource, FALSE is returned,
			  * indicating that the resource was unable to be loaded.
			  */
			RIM_INLINE Bool load() const
			{
				if ( info == NULL )
					return false;
				else if ( info->data.isSet() )
					return true;
				else
				{
					if ( info->loadCallback.isSet() )
						info->data = info->loadCallback( info->identifier );
					
					return info->data.isSet();
				}
			}
			
			
			
			
			/// Release the data assoicated with this resource, but keep the same resource ID and loader.
			/**
			  * This method just releases the reference to the data. If other resource objects reference
			  * the same data, the data is not deallocated until they all release their data.
			  */
			RIM_INLINE void release()
			{
				if ( info )
					info->data.release();
			}
			
			
			
			
			/// Return whether or not the data associated with this resource is currently NULL.
			/**
			  * The data can be NULL if the resource has not yet been loaded, or if the
			  * resource is itself invalid.
			  */
			RIM_INLINE Bool isNull() const
			{
				return info == NULL || info->data.isNull();
			}
			
			
			
			
			/// Return whether or not the data associated with this resource is currently set.
			/**
			  * The data can be NULL if the resource has not yet been loaded, or if the
			  * resource is itself invalid.
			  */
			RIM_INLINE Bool isSet() const
			{
				return info != NULL && info->data.isSet();
			}
			
			
			
			
			/// Return the number of shared references that there are to this resource's data.
			/**
			  * If the returned value is 1, this means that this resource is the only object
			  * which owns the data associated with it.
			  */
			RIM_INLINE Size getReferenceCount() const
			{
				if ( info )
					return info->referenceCount;
				else
					return 0;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which holds shared information about a particular resource.
			class ResourceInfo
			{
				public:
					
					RIM_INLINE ResourceInfo( const lang::Pointer<DataType>& newData )
						:	data( newData ),
							referenceCount( 1 )
					{
					}
					
					
					RIM_INLINE ResourceInfo( const lang::Pointer<DataType>& newData, const ResourceID& newIdentifier )
						:	data( newData ),
							identifier( newIdentifier ),
							referenceCount( 1 )
					{
					}
					
					
					RIM_INLINE ResourceInfo( const ResourceID& newIdentifier )
						:	referenceCount( 1 ),
							identifier( newIdentifier )
					{
					}
					
					
					RIM_INLINE ResourceInfo( const LoadCallback& newLoadCallback )
						:	referenceCount( 1 ),
							loadCallback( newLoadCallback )
					{
					}
					
					
					RIM_INLINE ResourceInfo( const ResourceID& newIdentifier,
											const LoadCallback& newLoadCallback )
						:	referenceCount( 1 ),
							identifier( newIdentifier ),
							loadCallback( newLoadCallback )
					{
					}
					
					
					
					/// A smart pointer to the data associated with this resource.
					lang::Pointer<DataType> data;
					
					
					/// The reference count of this resource info object.
					Size referenceCount;
					
					
					/// An identifier associated with this resource which uniquely locates it.
					ResourceID identifier;
					
					
					/// A function which loads the data associated with this resource.
					LoadCallback loadCallback;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to information about this resource (possibly NULL).
			ResourceInfo* info;
			
			
			
			
};




//##########################################################################################
//**************************  End Rim Resources Namespace  *********************************
RIM_RESOURCES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_RESOURCE_H
