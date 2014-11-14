/*
 *  rimGraphicsShader.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 2/11/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_H
#define INCLUDE_RIM_GRAPHICS_SHADER_H


#include "rimGraphicsShadersConfig.h"


#include "rimGraphicsShaderType.h"
#include "rimGraphicsShaderLanguage.h"
#include "rimGraphicsShaderSource.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a hardware-executed programmable rendering stage.
/**
  * A shader is defined by its source code, a string of characters which uses
  * an implementation-defined language to perform graphics operations such as
  * lighting and shading.
  */
class Shader : public ContextObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Source Code Accessor Methods
			
			
			
			
			/// Return the source code used by this shader.
			virtual const ShaderSourceString& getSourceCode() const = 0;
			
			
			
			
			/// Set the source code used by the shader.
			/**
			  * This method replaces the current source code for this shader.
			  * The shader must be compiled before the new source code takes effect.
			  *
			  * The method allows the user to specify the language of the shader's source
			  * code. This allows the implementation to choose the correct compiler for
			  * the shader.
			  *
			  * If there is an error or the specified language is not supported, FALSE
			  * is returned and the source code for the shader is unchanged. Otherwise,
			  * the method succeeds and TRUE is returned.
			  */
			virtual Bool setSourceCode( const ShaderSourceString& newSource,
										const ShaderLanguage& language = ShaderLanguage::DEFAULT ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Compile Method
			
			
			
			
			/// Compile the shader's source code and return whether or not the operation was successful.
			virtual Bool compile() = 0;
			
			
			
			
			/// Compile the shader's source code and return whether or not the operation was successful.
			/**
			  * If the result of compilation was not successful, the output of the 
			  * compiler be stored in the compilation log parameter.
			  */
			virtual Bool compile( String& compilationLog ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Compilation Status Accessor Method
			
			
			
			
			/// Return whether or not this shader has been compiled.
			/**
			  * The return value indicates whether or not a compilation operation has been
			  * attempted since the last source code change, not whether or not the compilation
			  * was without error.
			  */
			virtual Bool isCompiled() const = 0;
			
			
			
			
			/// Return whether or not the shader was successfully compiled.
			/**
			  * If the shader was not successfully compiled or hasn't been compiled yet,
			  * it cannot be used as part of a shader program.
			  */
			virtual Bool isValid() const = 0;
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Constructors
			
			
			
			
			/// Create a new shader with the specified shader type.
			RIM_INLINE Shader( const devices::GraphicsContext* newContext, ShaderType newShaderType )
				:	ContextObject( newContext ),
					shaderType( newShaderType )
			{
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value which determines what kind of shader this shader is.
			ShaderType shaderType;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_H
