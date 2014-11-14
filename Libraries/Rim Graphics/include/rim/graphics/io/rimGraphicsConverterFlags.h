/*
 *  rimGraphicsConverterFlags.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/28/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_CONVERTER_FLAGS_H
#define INCLUDE_RIM_GRAPHICS_CONVERTER_FLAGS_H


#include "rimGraphicsIOConfig.h"


//##########################################################################################
//**************************  Start Rim Graphics IO Namespace  *****************************
RIM_GRAPHICS_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates the different flags that a graphics converter can have.
/**
  * These flags provide boolean information about a certain graphics converter. Flags
  * are indicated by setting a single bit of a 32-bit unsigned integer to 1.
  *
  * Enum values for the different flags are defined as members of the class. Typically,
  * the user would bitwise-OR the flag enum values together to produce a final set
  * of set flags.
  */
class GraphicsConverterFlags
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Graphics Converter Flags Enum Declaration
			
			
			
			
			/// An enum which specifies the different graphics converter flags.
			typedef enum Flag
			{
				/// A flag which determines whether or not conversion caching is enabled.
				CACHE_ENABLED = (1 << 0),
				
				/// A flag which determines whether or not converted scene caching is enabled.
				SCENE_CACHE_ENABLED = (1 << 1),
				
				/// A flag which determines whether or not converted object caching is enabled.
				OBJECT_CACHE_ENABLED = (1 << 2),
				
				/// A flag which determines whether or not converted shape caching is enabled.
				SHAPE_CACHE_ENABLED = (1 << 3),
				
				/// A flag which determines whether or not converted material caching is enabled.
				MATERIAL_CACHE_ENABLED = (1 << 4),
				
				/// A flag which determines whether or not converted material technique caching is enabled.
				MATERIAL_TECHNIQUE_CACHE_ENABLED = (1 << 5),
				
				/// A flag which determines whether or not converted shader pass caching is enabled.
				SHADER_PASS_CACHE_ENABLED = (1 << 6),
				
				/// A flag which determines whether or not converted shader program caching is enabled.
				SHADER_PROGRAM_CACHE_ENABLED = (1 << 7),
				
				/// A flag which determines whether or not converted shader caching is enabled.
				SHADER_CACHE_ENABLED = (1 << 8),
				
				/// A flag which determines whether or not converted vertex buffer caching is enabled.
				VERTEX_BUFFER_CACHE_ENABLED = (1 << 9),
				
				/// A flag which determines whether or not converted vertex buffer caching is enabled.
				VERTEX_BUFFER_LIST_CACHE_ENABLED = (1 << 10),
				
				/// A flag which determines whether or not converted texture caching is enabled.
				TEXTURE_CACHE_ENABLED = (1 << 11),
				
				/// A flag which determines whether or not the graphics converter can load external resources.
				RESOURCE_LOADING_ENABLED = (1 << 12),
				
				/// A flag which determines whether or not the graphics converter uses deferred resource loading.
				/**
				  * If this flag is set, the converter sets loading function callbacks for each resource,
				  * deferring the loading of the resource until it is accessed. This allows resources
				  * to be in use but not in memory, and allows the user to release resource data if it is
				  * no longer needed while keeping the resource object.
				  */
				DEFERRED_LOADING_ENABLED = (1 << 13),
				
				/// The flag value when all flags are not set.
				UNDEFINED = 0
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new graphics converter flags object with no flags set.
			RIM_INLINE GraphicsConverterFlags()
				:	flags( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new graphics converter flags object with the specified flag value initially set.
			RIM_INLINE GraphicsConverterFlags( Flag flag )
				:	flags( flag )
			{
			}
			
			
			
			
			/// Create a new graphics converter flags object with the specified initial combined flags value.
			RIM_INLINE GraphicsConverterFlags( UInt32 newFlags )
				:	flags( newFlags )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Integer Cast Operator
			
			
			
			
			/// Convert this graphics converter flags object to an integer value.
			/**
			  * This operator is provided so that the GraphicsConverterFlags object
			  * can be used as an integer value for bitwise logical operations.
			  */
			RIM_INLINE operator UInt32 () const
			{
				return flags;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flag Status Accessor Methods
			
			
			
			
			/// Return whether or not the specified flag value is set for this flags object.
			RIM_INLINE Bool isSet( Flag flag ) const
			{
				return (flags & flag) != UNDEFINED;
			}
			
			
			
			
			/// Set whether or not the specified flag value is set for this flags object.
			RIM_INLINE void set( Flag flag, Bool newIsSet )
			{
				if ( newIsSet )
					flags |= flag;
				else
					flags &= ~flag;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A value indicating the flags that are set for a graphics converter.
			UInt32 flags;
			
			
			
};




//##########################################################################################
//**************************  End Rim Graphics IO Namespace  *******************************
RIM_GRAPHICS_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_CONVERTER_FLAGS_H
