/*
 *  rimGraphicsShaderPassUsage.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 10/5/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_PASS_USAGE_H
#define INCLUDE_RIM_GRAPHICS_SHADER_PASS_USAGE_H


#include "rimGraphicsShadersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the semantic usage for a ShaderPass.
/**
  * This enum class contains various values which describe different common
  * types of shading.
  */
class ShaderPassUsage
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Pass Usage Enum Definition
			
			
			
			
			/// An enum value which indicates the type of shader pass usage.
			typedef enum Enum
			{
				/// This usage specifies an undefined shader pass usage.
				UNDEFINED = 0,
				
				/// The shader pass renders geometry using a flat-shading model (no lighting).
				/**
				  * This shading model should use a uniform surface color.
				  */
				FLAT,
				
				/// The shader pass renders geometry using a flat vertex-color-shading model (no lighting).
				/**
				  * This shading model should use a per-vertex surface color.
				  */
				FLAT_VERTEX_COLOR,
				
				/// The shader pass renders geometry using a lambertian illumination model.
				LAMBERTIAN,
				
				/// The shader pass renders using a lambertian vertex-color-shading model.
				/**
				  * This shading model should use a per-vertex surface color.
				  */
				LAMBERTIAN_VERTEX_COLOR,
				
				/// The shader pass renders geometry using a phong illumination model.
				PHONG,
				
				/// The shader pass renders using a phong vertex-color-shading model.
				/**
				  * This shading model should use a per-vertex surface color.
				  */
				PHONG_VERTEX_COLOR,
				
				/// The shader pass is used to render depth information only, i.e. for shadow maps.
				DEPTH
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new shader pass usage with an undefined usage enum value..
			RIM_INLINE ShaderPassUsage()
				:	usage( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new shader pass usage with the specified shader pass usage enum value.
			RIM_INLINE ShaderPassUsage( Enum newUsage )
				:	usage( newUsage )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this shader pass usage to an enum value.
			RIM_INLINE operator Enum () const
			{
				return usage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a unique string for this shader pass usage that matches its enum value name.
			data::String toEnumString() const;
			
			
			
			
			/// Return a shader pass usage which corresponds to the given enum string.
			static ShaderPassUsage fromEnumString( const data::String& enumString );
			
			
			
			
			/// Return a string representation of the shader pass usage.
			String toString() const;
			
			
			
			
			/// Convert this shader pass usage into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum for the shader pass usage.
			Enum usage;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_PASS_USAGE_H
