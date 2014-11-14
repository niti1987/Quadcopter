/*
 *  rimResourceTranscoder.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/24/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_RESOURCE_TRANSCODER_H
#define INCLUDE_RIM_RESOURCE_TRANSCODER_H


#include "rimResourcesConfig.h"

#include "rimResource.h"
#include "rimResourceID.h"


//##########################################################################################
//**************************  Start Rim Resources Namespace  *******************************
RIM_RESOURCES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




class ResourceManager;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which defines the interface for other classes that load and save resource data.
template < typename DataType >
class ResourceTranscoder
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a resource transcoder and release all of its resources.
			virtual ~ResourceTranscoder()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resource Format Accessor Methods
			
			
			
			
			/// Return an object which represents the resource type that this transcoder can read and write.
			virtual ResourceType getResourceType() const = 0;
			
			
			
			
			/// Return an object which represents the resource format that this transcoder can read and write.
			virtual ResourceFormat getResourceFormat() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Encoding Methods
			
			
			
			
			/// Return whether or not this transcoder is able to encode the specified resource.
			virtual Bool canEncode( const DataType& resource ) const = 0;
			
			
			
			
			/// Save the specified resource object at the specified ID location.
			/**
			  * The method returns whether or not the resource was successfully written.
			  */
			virtual Bool encode( const ResourceID& identifier, const DataType& resource ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Decoding Methods
			
			
			
			
			/// Return whether or not the specified identifier refers to a valid resource for this transcoder.
			/**
			  * If the identifier represents a valid resource, TRUE is returned. Otherwise,
			  * if the resource is not valid, FALSE is returned.
			  */
			virtual Bool canDecode( const ResourceID& identifier ) const = 0;
			
			
			
			
			/// Load the resource pointed to by the specified identifier.
			/**
			  * The caller can supply a pointer to a resource manager which can be used
			  * to manage the creation of child resources.
			  *
			  * If the method fails, the return value will be NULL.
			  */
			virtual lang::Pointer<DataType> decode( const ResourceID& identifier, ResourceManager* manager = NULL ) = 0;
			
			
			
			
};




//##########################################################################################
//**************************  End Rim Resources Namespace  *********************************
RIM_RESOURCES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_RESOURCE_TRANSCODER_H
