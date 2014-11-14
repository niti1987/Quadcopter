/*
 *  rimGraphicsShaderParameterUsage.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 1/30/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_PARAMETER_USAGE_H
#define INCLUDE_RIM_GRAPHICS_SHADER_PARAMETER_USAGE_H


#include "rimGraphicsShadersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies the semantic usage for a shader parameter.
class ShaderParameterUsage
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Parameter Usage Enum Definition
			
			
			
			
			/// An enum type which represents the semantic usage for a shader parameter.
			typedef enum Enum
			{
				/// An undefined shader parameter usage.
				UNDEFINED = 0,
				
				/// An integer parameter indicating the full major/minor version of the shader language.
				LANGUAGE_VERSION,
				
				//******************************************************************
				
				VERTEX_COLORS_ENABLED,
				
				
				
				//******************************************************************
				// Lighting shader parameter usages
				
				LIGHTING_ENABLED,
				DIRECTIONAL_LIGHTS_ENABLED,
				POINT_LIGHTS_ENABLED,
				SPOT_LIGHTS_ENABLED,
				
				DIRECTIONAL_LIGHT_COUNT,
				POINT_LIGHT_COUNT,
				SPOT_LIGHT_COUNT,
				
				SPECULAR_ENABLED,
				DIFFUSE_ENABLED,
				AMBIENT_ENABLED,
				
				SHADOWS_ENABLED,
				DIRECTIONAL_LIGHT_SHADOWS_ENABLED,
				DIRECTIONAL_LIGHT_CSM_ENABLED,
				DIRECTIONAL_LIGHT_SHADOW_CASCADE_COUNT,
				POINT_LIGHT_SHADOWS_ENABLED,
				SPOT_LIGHT_SHADOWS_ENABLED,
				SHADOW_FILTERING_ENABLED,
				
				//******************************************************************
				// Texturing shader parameter usages
				
				TEXTURES_ENABLED,
				BUMP_MAPPING_ENABLED
			
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new shader parameter usage with the specified usage enum value.
			RIM_INLINE ShaderParameterUsage( Enum newUsage )
				:	usage( newUsage )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this shader parameter usage to an enum value.
			RIM_INLINE operator Enum () const
			{
				return usage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the shader parameter usage.
			String toString() const;
			
			
			
			
			/// Convert this shader parameter usage into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value for the shader parameter usage.
			Enum usage;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_PARAMETER_USAGE_H
