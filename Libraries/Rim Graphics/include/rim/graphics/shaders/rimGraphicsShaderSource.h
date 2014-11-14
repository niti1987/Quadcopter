/*
 *  rimGraphicsShaderSource.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 1/30/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_SOURCE_H
#define INCLUDE_RIM_GRAPHICS_SHADER_SOURCE_H


#include "rimGraphicsShadersConfig.h"


#include "rimGraphicsShaderType.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




/// The type of string to use to represent shader source code.
typedef String ShaderSourceString;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains the source code for a shader.
/**
  * In addition to a string specifying the source code for the shader, a ShaderSource
  * object also contains a ShaderType object specifying the type of shader the source
  * code describes.
  */
class ShaderSource
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new shader source object with an empty source code string and ShaderType::UNDEFINED type.
			RIM_INLINE ShaderSource()
				:	type( ShaderType::UNDEFINED ),
					source()
			{
			}
			
			
			
			
			/// Create a new shader source object with the specified type and source code.
			RIM_INLINE ShaderSource( const ShaderSourceString& newSource, const ShaderType& newType )
				:	type( newType ),
					source( newSource )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Type Accessor Methods
			
			
			
			
			/// Return an object describing the type of shader this source code describes.
			RIM_INLINE const ShaderType& getType() const
			{
				return type;
			}
			
			
			
			
			/// Set an object describing the type of shader this source code describes.
			RIM_INLINE void setType( const ShaderType& newType )
			{
				type = newType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Source Accessor Methods
			
			
			
			
			/// Return a string containing the source code for this shader.
			RIM_INLINE const ShaderSourceString& getSource() const
			{
				return source;
			}
			
			
			
			
			/// Set a string containing the source code for this shader.
			RIM_INLINE void setSource( const ShaderSourceString& newSource )
			{
				source = newSource;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object describing the type of this shader.
			ShaderType type;
			
			
			
			
			/// A string containing the source code for this shader.
			ShaderSourceString source;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_SOURCE_H
