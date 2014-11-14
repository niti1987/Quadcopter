/*
 *  rimResourceManager.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/26/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_RESOURCE_MANAGER_H
#define INCLUDE_RIM_RESOURCE_MANAGER_H


#include "rimResourcesConfig.h"


#include "rimResource.h"
#include "rimResourceID.h"
#include "rimResourceTranscoder.h"
#include "rimResourcePool.h"


//##########################################################################################
//**************************  Start Rim Resources Namespace  *******************************
RIM_RESOURCES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




class ResourceManager
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new empty resource manager with no formats it can manage.
			ResourceManager();
			
			
			
			
			/// Create a new resource manager which is a copy of the other resource manager.
			ResourceManager( const ResourceManager& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this resource manager and release all associated resources.
			virtual ~ResourceManager();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of another resource manager to this one.
			ResourceManager& operator = ( const ResourceManager& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resource Accessor Methods
			
			
			
			
			/// Return a resource object for the specified resource identifier.
			template < typename DataType >
			RIM_INLINE Resource<DataType> getResource( const ResourceID& identifier )
			{
				ResourceFormat format = identifier.getFormat();
				
				// Infer the format type for undefined formats.
				if ( format == ResourceFormat::UNDEFINED )
					format = inferFormat( identifier );
				
				// See if there is a valid loader for this format.
				FormatManagerBase** formatManagerBase;
				
				if ( formats.find( format, format, formatManagerBase ) )
				{
					FormatManager<DataType>* formatManager = *(FormatManager<DataType>**)formatManagerBase;
					
					return formatManager->getResource( ResourceID( identifier.getType(), format,
																	identifier.getFilePath(), identifier.getName() ), this );
				}
				else
					return Resource<DataType>( identifier );
			}
			
			
			
			
			/// Get a resource for the resource identifier.
			template < typename DataType >
			RIM_INLINE Bool getResource( Resource<DataType>& resource )
			{
				ResourceID* identifier = resource.getID();
				
				if ( identifier == NULL )
					return false;
				
				ResourceFormat format = identifier->getFormat();
				
				// Infer the format type for undefined formats.
				if ( format == ResourceFormat::UNDEFINED )
					format = inferFormat( *identifier );
				
				identifier->setFormat( format );
				
				// See if there is a valid loader for this format.
				FormatManagerBase** formatManagerBase;
				
				if ( formats.find( format, format, formatManagerBase ) )
				{
					FormatManager<DataType>* formatManager = *(FormatManager<DataType>**)formatManagerBase;
					
					return formatManager->getResource( resource, this );
				}
				else
					return false;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Format Accessor Methods
			
			
			
			
			/// Return the number of resource formats that this manager can manage.
			RIM_INLINE Size getFormatCount() const
			{
				return formats.getSize();
			}
			
			
			
			
			/// Add a new resource format to this manager.
			/**
			  * The method fails if the format transcoder is NULL or if its format is not valid.
			  * The new transcoder replaces any previously existing transcoder for its format.
			  */
			template < typename DataType >
			RIM_NO_INLINE Bool addFormat( const lang::Pointer<ResourceTranscoder<DataType> >& transcoder,
										Bool cacheEnabled = true )
			{
				// Make sure the new transcoder is not NULL.
				if ( transcoder.isNull() )
					return false;
				
				// Get the format for the new transcoder.
				ResourceFormat format = transcoder->getResourceFormat();
				
				if ( format == ResourceFormat::UNDEFINED )
					return false;
				
				// Check to see if there was already a manager for this format.
				FormatManagerBase** existingManager;
				
				if ( formats.find( format, format, existingManager ) )
				{
					// Replace the existing transcoder for the format.
					FormatManager<DataType>* formatManager = *(FormatManager<DataType>**)existingManager;
					formatManager->transcoder = transcoder;
					formatManager->cacheEnabled = cacheEnabled;
					return true;
				}
				
				// Create a manager for the new format.
				FormatManager<DataType>* formatManager = util::construct<FormatManager<DataType> >( transcoder, cacheEnabled );
				
				// Insert it in the format map.
				formats.add( format, format, formatManager );
				
				return true;
			}
			
			
			
			
			/// Remove the specified format from this resource manager.
			/**
			  * The method returns whether or not the specified format was found and removed.
			  */
			Bool removeFormat( const ResourceFormat& format );
			
			
			
			
			/// Remove all formats from this resource manager.
			void clearFormats();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Cache Accessor Methods
			
			
			
			
			/// Return whether or not the resource cache is enabled for the specified resource format.
			Bool getCacheIsEnabled( const ResourceFormat& format ) const;
			
			
			
			
			/// Set whether or not the resource cache should be enabled for the specified resource format.
			/**
			  * The method returns whether or not the cache status for the specified format was able
			  * to be changed.
			  */
			Bool setCacheIsEnabled( const ResourceFormat& format, Bool newCacheEnabled );
			
			
			
			
			/// Set whether or not the resource cache should be enabled for all resource formats.
			void setCacheIsEnabled( Bool newCacheEnabled );
			
			
			
			
			/// Clear the resource cache for only the specified resource format.
			/**
			  * The method returns whether or not the cache for the specified format was able
			  * to be cleared.
			  */
			Bool clearCache( const ResourceFormat& format );
			
			
			
			
			/// Clear the resource cache for all resource formats.
			void clearCache();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations
			
			
			
			
			/// A class that stores a resource transcoder and pool for a specific ResourceFormat.
			class FormatManagerBase
			{
				public:
					
					RIM_INLINE FormatManagerBase( Bool newCacheEnabled )
						:	cacheEnabled( newCacheEnabled )
					{
					}
					
					virtual ~FormatManagerBase()
					{
					}
					
					
					virtual FormatManagerBase* clone() const = 0;
					
					
					virtual void clearCache() = 0;
					
					
					
					/// A boolean value indicating whether or not this format's resource pool is enabled.
					Bool cacheEnabled;
					
					
			};
			
			
			
			
			/// A class that stores a resource transcoder and pool for a specific ResourceFormat.
			template < typename DataType >
			class FormatManager : public FormatManagerBase
			{
				public:
					
					
					RIM_INLINE FormatManager( const lang::Pointer<ResourceTranscoder<DataType> >& newTranscoder, Bool newCacheEnabled )
						:	FormatManagerBase( newCacheEnabled ),
							transcoder( newTranscoder )
					{
					}
					
					
					virtual FormatManager<DataType>* clone() const
					{
						return util::construct<FormatManager<DataType> >( *this );
					}
					
					
					
					virtual Bool getResource( Resource<DataType>& resource, ResourceManager* manager )
					{
						const ResourceID* identifier = resource.getID();
						
						if ( identifier == NULL )
							return false;
						
						// Check the cache to see if there is anything already loaded in the cache.
						if ( cacheEnabled )
						{
							Resource<DataType>* pooledResource = cache.getResource( *identifier );
							
							if ( pooledResource != NULL )
							{
								resource = *pooledResource;
								return true;
							}
						}
						
						// Try loading the resource using the transcoder.
						if ( transcoder.isNull() )
							return false;
						
						lang::Pointer<DataType> resourceData = transcoder->decode( *identifier, manager );
						
						// If the loading failed, return a NULL resource.
						if ( !resourceData )
							return false;
						
						resource.setData( resourceData );
						
						// Insert the new resource in the cache if necessary.
						if ( cacheEnabled )
							cache.addResource( *identifier, resource );
						
						return true;
					}
					
					
					
					virtual Resource<DataType> getResource( const ResourceID& identifier, ResourceManager* manager )
					{
						// Check the cache to see if there is anything already loaded in the cache.
						if ( cacheEnabled )
						{
							Resource<DataType>* pooledResource = cache.getResource( identifier );
							
							if ( pooledResource != NULL )
								return *pooledResource;
						}
						
						// Try loading the resource using the transcoder.
						if ( transcoder.isNull() )
							return Resource<DataType>( identifier );
						
						lang::Pointer<DataType> resourceData = transcoder->decode( identifier, manager );
						
						// If the loading failed, return a NULL resource.
						if ( !resourceData )
							return Resource<DataType>( identifier );
						
						Resource<DataType> resource( resourceData, identifier );
						
						// Insert the new resource in the cache if necessary.
						if ( cacheEnabled )
							cache.addResource( identifier, resource );
						
						return resource;
					}
					
					
					virtual void clearCache()
					{
						cache.clearResources();
					}
					
					
					
					/// A pointer to the resource transcoder that is used for this format.
					lang::Pointer<ResourceTranscoder<DataType> > transcoder;
					
					
					/// A pool of previously loaded resources for this format.
					ResourcePool<DataType> cache;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Infer the format for the specified resource ID from its attributes.
			static ResourceFormat inferFormat( const ResourceID& identifier );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A map from resource formats to managers for those formats.
			util::HashMap<ResourceFormat,FormatManagerBase*> formats;
			
			
			
};




//##########################################################################################
//**************************  End Rim Resources Namespace  *********************************
RIM_RESOURCES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_RESOURCE_MANAGER_H
