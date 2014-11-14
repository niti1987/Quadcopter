/*
 *  rimResourcePool.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 11/27/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_RESOURCE_POOL_H
#define INCLUDE_RIM_RESOURCE_POOL_H


#include "rimResourcesConfig.h"


#include "rimResource.h"
#include "rimResourceID.h"


//##########################################################################################
//**************************  Start Rim Resources Namespace  *******************************
RIM_RESOURCES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which stores a persistent pool of resources to avoid resource duplication.
template < typename DataType >
class ResourcePool
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new empty resource pool.
			RIM_INLINE ResourcePool()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resource Accessor Methods
			
			
			
			
			/// Return the total number of resources that are part of this resource pool.
			RIM_INLINE Size getResourceCount() const
			{
				return pool.getSize();
			}
			
			
			
			
			/// Return a pointer to the resource with the specified ID.
			/**
			  * If there is no resource corresponding to that ID, the method returns NULL.
			  */
			RIM_NO_INLINE Resource<DataType>* getResource( const ResourceID& identifier )
			{
				Resource<DataType>* resource;
				
				if ( pool.find( identifier.getHashCode(), identifier, resource ) )
					return resource;
				else
					return NULL;
			}
			
			
			
			
			/// Add a new resource with the specified ID to this pool.
			/**
			  * If the resource is not NULL, it is added to the pool and TRUE is
			  * returned. Otherwise, the pool is unmodified and FALSE is returned.
			  */
			RIM_NO_INLINE Bool addResource( const ResourceID& identifier, const Resource<DataType>& resource )
			{
				if ( resource.isNull() )
					return false;
				
				pool.add( identifier.getHashCode(), identifier, resource );
				
				return true;
			}
			
			
			
			
			/// Remove all resources from the pool that aren't referenced anywhere else.
			/**
			  * This has the effect of deallocating any data stored by any of the unreferenced
			  * resources.
			  */
			RIM_NO_INLINE void removeUnusedResources()
			{
				typename util::HashMap<ResourceID,Resource<DataType> >::Iterator iterator = pool.getIterator();
				
				while ( iterator )
				{
					if ( iterator->getReferenceCount() <= 1 )
					{
						iterator->release();
						iterator.remove();
						continue;
					}
					
					iterator++;
				}
			}
			
			
			
			
			/// Remove all references of the resources contained in this pool.
			/**
			  * This won't cause the resources to be deallocated from memory
			  * unless the aren't being used elsewhere. The resources will stay
			  * resident in memory until they are not used, at which point they will
			  * be deallocated automatically.
			  */
			void clearResources()
			{
				pool.clear();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A map from resource ID to resource
			util::HashMap< ResourceID, Resource<DataType> > pool;
			
			
			
};




//##########################################################################################
//**************************  End Rim Resources Namespace  *********************************
RIM_RESOURCES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_RESOURCE_POOL_H
