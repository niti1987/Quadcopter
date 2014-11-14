/*
 *  rimGraphicsShaderParameterFlags.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 1/30/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_PARAMETER_FLAGS_H
#define INCLUDE_RIM_GRAPHICS_SHADER_PARAMETER_FLAGS_H


#include "rimGraphicsShadersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates the different flags that a shader paramter can have.
/**
  * These flags provide boolean information about a shader parameter. Flags
  * are indicated by setting a single bit of a 32-bit unsigned integer to 1.
  *
  * Enum values for the different flags are defined as members of the class. Typically,
  * the user would bitwise-OR the flag enum values together to produce a final set
  * of set flags.
  */
class ShaderParameterFlags
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Parameter Flags Enum Declaration
			
			
			
			
			/// An enum which specifies the different shader parameter flags.
			typedef enum Flag
			{
				/// A flag indicating whether or not the parameter allows reading its value.
				READ_ACCESS = 1,
				
				/// A flag indicating whether or not the parameter allows setting its value.
				WRITE_ACCESS = 1 << 1,
				
				/// The flag value when all flags are not set.
				UNDEFINED = 0
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new shader parameter flags object with no flags set.
			RIM_INLINE ShaderParameterFlags()
				:	flags( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new shader parameter flags object with the specified flag value initially set.
			RIM_INLINE ShaderParameterFlags( Flag flag )
				:	flags( flag )
			{
			}
			
			
			
			
			/// Create a new shader parameter flags object with the specified initial combined flags value.
			RIM_INLINE ShaderParameterFlags( UInt32 newFlags )
				:	flags( newFlags )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Integer Cast Operator
			
			
			
			
			/// Convert this shader parameter flags object to an integer value.
			/**
			  * This operator is provided so that the ShaderParameterFlags object
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
			
			
			
			
			/// A value indicating the flags that are set for a shader parameter.
			UInt32 flags;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_PARAMETER_FLAGS_H
