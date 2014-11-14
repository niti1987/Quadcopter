/*
 *  rimGraphicsShaderParameterInfo.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 1/30/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_PARAMETER_INFO_H
#define INCLUDE_RIM_GRAPHICS_SHADER_PARAMETER_INFO_H


#include "rimGraphicsShadersConfig.h"


#include "rimGraphicsShaderParameterUsage.h"
#include "rimGraphicsShaderParameterFlags.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies information about a shader parameter.
/**
  * This information includes a semantic usage for the parameter, as well
  * as flags that specify boolean information about the parameter such as
  * its read/write access status.
  */
class ShaderParameterInfo
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new shader parameter info object with ShaderParameterUsage::UNDEFINED usage and default flags.
			/**
			  * The default shader parameter flags allow no read or write access.
			  */
			RIM_INLINE ShaderParameterInfo()
				:	usage( ShaderParameterUsage::UNDEFINED ),
					flags(),
					name()
			{
			}
			
			
			
			
			/// Create a new shader parameter info object with ShaderParameterUsage::UNDEFINED usage and default flags.
			/**
			  * The default shader parameter flags allow read and write access.
			  */
			RIM_INLINE ShaderParameterInfo( const String& newName )
				:	usage( ShaderParameterUsage::UNDEFINED ),
					flags( ShaderParameterFlags::READ_ACCESS | ShaderParameterFlags::WRITE_ACCESS ),
					name( newName )
			{
			}
			
			
			
			
			/// Create a new shader parameter info object with the specified usage and default flags.
			/**
			  * The default shader parameter flags allow read and write access.
			  */
			RIM_INLINE ShaderParameterInfo( const String& newName, const ShaderParameterUsage& newUsage )
				:	usage( newUsage ),
					flags( ShaderParameterFlags::READ_ACCESS | ShaderParameterFlags::WRITE_ACCESS ),
					name( newName )
			{
			}
			
			
			
			
			/// Create a new shader parameter info object with the specified usage and flags.
			RIM_INLINE ShaderParameterInfo( const String& newName, const ShaderParameterUsage& newUsage,
											const ShaderParameterFlags& newFlags )
				:	usage( newUsage ),
					flags( newFlags ),
					name( newName )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return the name of this shader parameter.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set the name of this shader parameter.
			RIM_INLINE void setName( const String& newName )
			{
				name = newName;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Usage Accessor Methods
			
			
			
			
			/// Return an object describing the semantic usage of this shader parameter.
			RIM_INLINE const ShaderParameterUsage& getUsage() const
			{
				return usage;
			}
			
			
			
			
			/// Set an object describing the semantic usage of this shader parameter.
			RIM_INLINE void setUsage( const ShaderParameterUsage& newUsage )
			{
				usage = newUsage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flags Accessor Methods
			
			
			
			
			/// Return an object describing boolean information about this shader parameter.
			RIM_INLINE const ShaderParameterFlags& getFlags() const
			{
				return flags;
			}
			
			
			
			
			/// Set an object describing boolean information about this shader parameter.
			RIM_INLINE void setFlags( const ShaderParameterFlags& newFlags )
			{
				flags = newFlags;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object describing the semantic usage of this shader parameter.
			ShaderParameterUsage usage;
			
			
			
			
			/// An object describing boolean information about this shader parameter.
			ShaderParameterFlags flags;
			
			
			
			
			/// A string representing the name of the shader parameter.
			String name;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_PARAMETER_INFO_H
