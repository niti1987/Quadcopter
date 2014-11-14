/*
 *  rimGraphicsContextCapabilities.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 3/8/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_CONTEXT_CAPABILITIES_H
#define INCLUDE_RIM_GRAPHICS_CONTEXT_CAPABILITIES_H


#include "rimGraphicsDevicesConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Devices Namespace  ***************************
RIM_GRAPHICS_DEVICES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates the different capabilities that a graphics context can have.
/**
  * These capabilities provide boolean information about a certain graphics context. Capabilities
  * are indicated by setting a single bit of a 64-bit unsigned integer to 1.
  *
  * Enum values for the different capabilities are defined as members of the class. Typically,
  * the user would bitwise-OR the capability enum values together to produce a final set
  * of set capabilities.
  */
class GraphicsContextCapabilities
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Graphics Context Capabilities Enum Declaration
			
			
			
			
			/// An enum which specifies the different graphics context capabilities.
			typedef enum Capability
			{
				//********************************************************************************
				// Texturing Capabilities
				
				/// A capability flag indicating that anisotropic texture filtering is supported.
				ANISOTROPIC_FILTERING = (UInt64(1) << 0),
				
				/// A capability flag indicating that non power-of-two sized textures are supported.
				NON_POWER_OF_2_TEXTURES = (UInt64(1) << 1),
				
				/// A capability flag indicating that floating-point textures are supported.
				FLOAT_TEXTURES = (UInt64(1) << 2),
				
				/// A capability flag indicating that texture arrays are supported.
				TEXTURE_ARRAYS = (UInt64(1) << 3),
				
				/// A capability flag indicating that texture rectangles are supported.
				TEXTURE_RECTANGLES = (UInt64(1) << 4),
				
				/// A capability flag indicating that render-to-texture is supported (e.g. framebuffers).
				RENDER_TO_TEXTURE = (UInt64(1) << 5),
				
				/// A capability flag indicating that multiple render targets are supported.
				MULTIPLE_RENDER_TARGETS = (UInt64(1) << 6),
				
				//********************************************************************************
				// Buffer Capabilities
				
				/// A capability flag indicating that hardware vertex buffer arrays are supported.
				VERTEX_BUFFER_ARRAYS = (UInt64(1) << 7),
				
				/// A capability flag indicating that hardware constant buffers are supported.
				CONSTANT_BUFFERS = (UInt64(1) << 8),
				
				//********************************************************************************
				// Shader Capabilities
				
				/// A capability flag indicating that vertex shaders are supported.
				VERTEX_SHADERS = (UInt64(1) << 9),
				
				/// A capability flag indicating that fragment shaders are supported.
				FRAGMENT_SHADERS = (UInt64(1) << 10),
				
				/// A capability flag indicating that geometry shaders are supported.
				GEOMETRY_SHADERS = (UInt64(1) << 11),
				
				/// A capability flag indicating that tesselation shaders are supported.
				TESSELATION_SHADERS = (UInt64(1) << 12),
				
				/// A capability flag indicating that compiled program binaries are supported.
				PROGRAM_BINARIES = (UInt64(1) << 13),
				
				//********************************************************************************
				// Rendering Capabilities
				
				/// A capability flag indicating that vertex transform feedback is supported.
				TRANSFORM_FEEDBACK = (UInt64(1) << 14),
				
				/// A capability flag indicating that instanced rendering is supported.
				INSTANCED_RENDERING = (UInt64(1) << 15),
				
				/// The capability value when all capabilities are not set.
				UNDEFINED = 0
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new graphics context capabilities object with no capabilities set.
			RIM_INLINE GraphicsContextCapabilities()
				:	capabilities( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new graphics context capabilities object with the specified capability value initially set.
			RIM_INLINE GraphicsContextCapabilities( Capability capability )
				:	capabilities( capability )
			{
			}
			
			
			
			
			/// Create a new graphics context capabilities object with the specified initial combined capabilities value.
			RIM_INLINE GraphicsContextCapabilities( UInt64 newCapabilities )
				:	capabilities( newCapabilities )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Integer Cast Operator
			
			
			
			
			/// Convert this graphics context capabilities object to an integer value.
			/**
			  * This operator is provided so that the GraphicsContextCapabilities object
			  * can be used as an integer value for bitwise logical operations.
			  */
			RIM_INLINE operator UInt64 () const
			{
				return capabilities;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flag Status Accessor Methods
			
			
			
			
			/// Return whether or not the specified capability is set for this capabilities object.
			RIM_INLINE Bool isSet( Capability capability ) const
			{
				return (capabilities & capability) != UNDEFINED;
			}
			
			
			
			
			/// Set whether or not the specified capability is set for this capabilities object.
			RIM_INLINE void set( Capability capability, Bool newIsSet )
			{
				if ( newIsSet )
					capabilities |= capability;
				else
					capabilities &= ~capability;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flag OR Methods
			
			
			
			
			/// Set the specified capability to TRUE in this capabilities object.
			RIM_INLINE GraphicsContextCapabilities& operator |= ( Capability capability )
			{
				capabilities |= capability;
				return *this;
			}
			
			
			
			
			/// Set all of the specified capabilities to TRUE in this capabilities object.
			RIM_INLINE GraphicsContextCapabilities& operator |= ( const GraphicsContextCapabilities& newCapabilities )
			{
				capabilities |= newCapabilities;
				return *this;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A value indicating the capabilities that are available for a graphics context.
			UInt64 capabilities;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Devices Namespace  *****************************
RIM_GRAPHICS_DEVICES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_CONTEXT_CAPABILITIES_H
