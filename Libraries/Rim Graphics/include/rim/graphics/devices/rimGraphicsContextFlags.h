/*
 *  rimGraphicsContextFlags.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/1/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_CONTEXT_FLAGS_H
#define INCLUDE_RIM_GRAPHICS_CONTEXT_FLAGS_H


#include "rimGraphicsDevicesConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Devices Namespace  ***************************
RIM_GRAPHICS_DEVICES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates the different flags that a graphics context can have.
/**
  * These flags provide boolean information about a certain graphics context. Flags
  * are indicated by setting a single bit of a 32-bit unsigned integer to 1.
  *
  * Enum values for the different flags are defined as members of the class. Typically,
  * the user would bitwise-OR the flag enum values together to produce a final set
  * of set flags.
  */
class GraphicsContextFlags
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Graphics Context Flags Enum Declaration
			
			
			
			
			/// An enum which specifies the different graphics context flags.
			typedef enum Flag
			{
				/// A flag indicating whether or not the context is using double buffering.
				DOUBLE_BUFFERED = 1,
				
				/// A flag indicating whether or not the context's framebuffer has an alpha channel.
				ALPHA = 1 << 1,
				
				/// A flag indicating that the graphics context is hardware accelerated.
				ACCELERATED = 1 << 2,
				
				/// A flag indicating that multisample anti-aliasing is used by the context.
				MULTISAMPLE_AA = 1 << 3,
				
				/// A flag indicating that supersample anti-aliasing is used by the context.
				SUPERSAMPLE_AA = 1 << 4,
				
				/// The flag value when all flags are not set.
				UNDEFINED = 0
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new graphics context flags object with no flags set.
			RIM_INLINE GraphicsContextFlags()
				:	flags( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new graphics context flags object with the specified flag value initially set.
			RIM_INLINE GraphicsContextFlags( Flag flag )
				:	flags( flag )
			{
			}
			
			
			
			
			/// Create a new graphics context flags object with the specified initial combined flags value.
			RIM_INLINE GraphicsContextFlags( UInt32 newFlags )
				:	flags( newFlags )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Integer Cast Operator
			
			
			
			
			/// Convert this graphics context flags object to an integer value.
			/**
			  * This operator is provided so that the GraphicsContextFlags object
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
			
			
			
			
			/// A value indicating the flags that are set for a graphics context.
			UInt32 flags;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Devices Namespace  *****************************
RIM_GRAPHICS_DEVICES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_CONTEXT_FLAGS_H
