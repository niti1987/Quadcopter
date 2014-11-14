/*
 *  rimGraphicsShaderProgram.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 2/11/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_PROGRAM_H
#define INCLUDE_RIM_GRAPHICS_SHADER_PROGRAM_H


#include "rimGraphicsShadersConfig.h"


#include "rimGraphicsShader.h"
#include "rimGraphicsConstantVariable.h"
#include "rimGraphicsVertexVariable.h"
#include "rimGraphicsTextureVariable.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the interface for a hardware-executed shading program.
/**
  * A shader program is made up of one or more Shader objects that describe
  * the different stages of a shading pipeline. A ShaderProgram presents an
  * interface of shader variables that can be used to control the output of the
  * shader. Shader variables can correspond to constants, per-vertex attributes,
  * or textures. A shader program must be successfully linked before it can be used.
  */
class ShaderProgram : public ContextObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Accessor Methods
			
			
			
			
			/// Return the total number of shaders that are attached to this shader program.
			virtual Size getShaderCount() const = 0;
			
			
			
			
			/// Return a pointer to the shader object attached at the specified index to the shader program.
			/**
			  * Shader indices range from 0 for the first attached shader to N for the
			  * Nth attached shader.
			  */
			virtual Pointer<Shader> getShader( Index shaderIndex ) const = 0;
			
			
			
			
			/// Attach the specified shader to this shader program.
			/**
			  * The method returns whether or not the new shader was able to be attached.
			  * The method can fail if the shader pointer is NULL, the shader was not able
			  * to be compiled, or if there was an internal error.
			  *
			  * If the method succeeds, the shader program will need to be re-linked
			  * before it can be used.
			  */
			virtual Bool addShader( const Pointer<Shader>& newShader ) = 0;
			
			
			
			
			/// Detach the shader at the specified index from this shader program.
			/**
			  * The method returns whether or not the shader was able to be removed.
			  *
			  * If the method succeeds, the shader program will need to be re-linked
			  * before it can be used.
			  */
			virtual Bool removeShader( Index shaderIndex ) = 0;
			
			
			
			
			/// Detach the shader with the specified address from this shader program.
			/**
			  * The method returns whether or not the shader was able to be removed.
			  *
			  * If the method succeeds, the shader program will need to be re-linked
			  * before it can be used.
			  */
			virtual Bool removeShader( const Shader* shader ) = 0;
			
			
			
			
			/// Remove all shaders that are attached to this shader program.
			/**
			  * Shaders will need to be attatched to an empty program before
			  * it can be used again.
			  */
			virtual void clearShaders() = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Program Link Method
			
			
			
			
			/// Link the vertex and fragment shaders into a useable shader program.
			/**
			  * The return value indicates wether or not the link operation was successful.
			  */
			virtual Bool link() = 0;
			
			
			
			
			/// Link the vertex and fragment shaders into a useable shader program.
			/**
			  * The return value indicates wether or not the link operation was successful.
			  * If an error was encountered during the link process, the linker's output
			  * is written to the link log parameter.
			  */
			virtual Bool link( String& linkLog ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Program Status Accessor Method
			
			
			
			
			/// Return whether or not a link operation has been attempted on this shader program.
			/**
			  * The method does not return whether or not the link operation was successful,
			  * use the isValid() method instead to determine that.
			  */
			virtual Bool isLinked() const = 0;
			
			
			
			
			/// Return whether or not the shader program was linked successfully and is ready for use.
			/**
			  * If the shader program has not yet been linked, FALSE is returned.
			  */
			virtual Bool isValid() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constant Variable Accessor Methods
			
			
			
			
			/// Return the total number of constant variables that are part of this shader program.
			virtual Size getConstantVariableCount() const = 0;
			
			
			
			
			/// Return a pointer to the constant variable for this shader program at the given index.
			/**
			  * Variable indices range from 0 up to the number of constant variables minus one.
			  * If an invalid variable index is specified, NULL is returned.
			  */
			virtual const ConstantVariable* getConstantVariable( Index variableIndex ) const = 0;
			
			
			
			
			/// Get the constant variable that is part of this shader program with the specified name.
			/**
			  * The constant variable, if found, is placed in the output reference parameter.
			  * The method returns whether or not this shader program has a variable with
			  * the given variable name.
			  */
			virtual Bool getConstantVariable( const String& variableName, const ConstantVariable*& variable ) const = 0;
			
			
			
			
			/// Get the constant variable index for this shader program with the specified name.
			/**
			  * The constant variable's index, if found, is placed in the output reference parameter.
			  * The method returns whether or not this shader program has a variable with
			  * the given variable name.
			  */
			virtual Bool getConstantVariableIndex( const String& variableName, Index& variableIndex ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Variable Accessor Methods
			
			
			
			
			/// Return the total number of texture variables that are part of this shader program.
			virtual Size getTextureVariableCount() const = 0;
			
			
			
			
			/// Return a pointer to the texture variable for this shader program at the given index.
			/**
			  * Variable indices range from 0 up to the number of texture variables minus one.
			  * If an invalid variable index is specified, NULL is returned.
			  */
			virtual const TextureVariable* getTextureVariable( Index variableIndex ) const = 0;
			
			
			
			
			/// Get the texture variable that is part of this shader program with the specified name.
			/**
			  * The texture variable, if found, is placed in the output reference parameter.
			  * The method returns whether or not this shader program has a variable with
			  * the given variable name.
			  */
			virtual Bool getTextureVariable( const String& variableName, const TextureVariable*& variable ) const = 0;
			
			
			
			
			/// Get the texture variable index for this shader program with the specified name.
			/**
			  * The texture variable's index, if found, is placed in the output reference parameter.
			  * The method returns whether or not this shader program has a variable with
			  * the given variable name.
			  */
			virtual Bool getTextureVariableIndex( const String& variableName, Index& variableIndex ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Variable Accessor Methods
			
			
			
			
			/// Return the total number of vertex variables that are part of this shader program.
			virtual Size getVertexVariableCount() const = 0;
			
			
			
			
			/// Return a pointer to the vertex variable for this shader program at the given index.
			/**
			  * Variable indices range from 0 up to the number of vertex variables minus one.
			  * If an invalid variable index is specified, NULL is returned.
			  */
			virtual const VertexVariable* getVertexVariable( Index variableIndex ) const = 0;
			
			
			
			
			/// Get the vertex variable that is part of this shader program with the specified name.
			/**
			  * The vertex variable, if found, is placed in the output reference parameter.
			  * The method returns whether or not this shader program has a variable with
			  * the given variable name.
			  */
			virtual Bool getVertexVariable( const String& variableName, const VertexVariable*& variable ) const = 0;
			
			
			
			
			/// Get the vertex variable index for this shader program with the specified name.
			/**
			  * The vertex variable's index, if found, is placed in the output reference parameter.
			  * The method returns whether or not this shader program has a variable with
			  * the given variable name.
			  */
			virtual Bool getVertexVariableIndex( const String& variableName, Index& variableIndex ) const = 0;
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Constructors
			
			
			
			
			/// Create a new shader program for the specified graphics context.
			RIM_INLINE ShaderProgram( const devices::GraphicsContext* context )
				:	ContextObject( context )
			{
			}
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_PROGRAM_H
