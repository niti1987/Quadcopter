/*
 *  rimGraphicsOpenGLShaderProgram.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/2/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_OPENGL_SHADER_PROGRAM_H
#define INCLUDE_RIM_GRAPHICS_OPENGL_SHADER_PROGRAM_H


#include "rimGraphicsOpenGLConfig.h"


//##########################################################################################
//********************  Start Rim Graphics Devices OpenGL Namespace  ***********************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents an OpenGL hardware-executed shading program.
class OpenGLShaderProgram : public ShaderProgram
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this shader program and release all resources associated with it.
			~OpenGLShaderProgram();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Accessor Methods
			
			
			
			
			/// Return the total number of shaders that are attached to this shader program.
			virtual Size getShaderCount() const;
			
			
			
			
			/// Return a pointer to the shader object attached at the specified index to the shader program.
			/**
			  * Shader indices range from 0 for the first attached shader to N for the
			  * Nth attached shader.
			  */
			virtual Pointer<Shader> getShader( Index shaderIndex ) const;
			
			
			
			
			/// Attach the specified shader to this shader program.
			/**
			  * The method returns whether or not the new shader was able to be attached.
			  * The method can fail if the shader pointer is NULL, the shader was not able
			  * to be compiled, or if there was an internal error.
			  *
			  * If the method succeeds, the shader program will need to be re-linked
			  * before it can be used.
			  */
			virtual Bool addShader( const Pointer<Shader>& newShader );
			
			
			
			
			/// Detach the shader at the specified index from this shader program.
			/**
			  * The method returns whether or not the shader was able to be removed.
			  *
			  * If the method succeeds, the shader program will need to be re-linked
			  * before it can be used.
			  */
			virtual Bool removeShader( Index shaderIndex );
			
			
			
			
			/// Detach the shader with the specified address from this shader program.
			/**
			  * The method returns whether or not the shader was able to be removed.
			  *
			  * If the method succeeds, the shader program will need to be re-linked
			  * before it can be used.
			  */
			virtual Bool removeShader( const Shader* shader );
			
			
			
			
			/// Remove all shaders that are attached to this shader program.
			/**
			  * Shaders will need to be attatched to an empty program before
			  * it can be used again.
			  */
			virtual void clearShaders();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Program Link Method
			
			
			
			
			/// Link the vertex and fragment shaders into a useable shader program.
			/**
			  * The return value indicates wether or not the link operation was successful.
			  */
			Bool link();
			
			
			
			
			/// Link the vertex and fragment shaders into a useable shader program.
			/**
			  * The return value indicates wether or not the link operation was successful.
			  * If an error was encountered during the link process, the linker's output
			  * is written to the link log parameter.
			  */
			Bool link( String& linkLog );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Program Status Accessor Method
			
			
			
			
			/// Return whether or not a link operation has been attempted on this shader program.
			virtual Bool isLinked() const;
			
			
			
			
			/// Return whether or not the shader program was linked successfully and is ready for use.
			virtual Bool isValid() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constant Variable Accessor Methods
			
			
			
			
			/// Return the total number of constant variables that are part of this shader program.
			virtual Size getConstantVariableCount() const;
			
			
			
			
			/// Return a pointer to the constant variable for this shader program at the given index.
			/**
			  * Variable indices range from 0 up to the number of constant variables minus one.
			  * If an invalid variable index is specified, NULL is returned.
			  */
			virtual const ConstantVariable* getConstantVariable( Index variableIndex ) const;
			
			
			
			
			/// Get the constant variable that is part of this shader program with the specified name.
			/**
			  * The constant variable, if found, is placed in the output reference parameter.
			  * The method returns whether or not this shader program has a variable with
			  * the given variable name.
			  */
			virtual Bool getConstantVariable( const String& variableName, const ConstantVariable*& variable ) const;
			
			
			
			
			/// Get the constant variable index for this shader program with the specified name.
			/**
			  * The constant variable's index, if found, is placed in the output reference parameter.
			  * The method returns whether or not this shader program has a variable with
			  * the given variable name.
			  */
			virtual Bool getConstantVariableIndex( const String& variableName, Index& variableIndex ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Variable Accessor Methods
			
			
			
			
			/// Return the total number of texture variables that are part of this shader program.
			virtual Size getTextureVariableCount() const;
			
			
			
			
			/// Return a pointer to the texture variable for this shader program at the given index.
			/**
			  * Variable indices range from 0 up to the number of texture variables minus one.
			  * If an invalid variable index is specified, NULL is returned.
			  */
			virtual const TextureVariable* getTextureVariable( Index variableIndex ) const;
			
			
			
			
			/// Get the texture variable that is part of this shader program with the specified name.
			/**
			  * The texture variable, if found, is placed in the output reference parameter.
			  * The method returns whether or not this shader program has a variable with
			  * the given variable name.
			  */
			virtual Bool getTextureVariable( const String& variableName, const TextureVariable*& variable ) const;
			
			
			
			
			/// Get the texture variable index for this shader program with the specified name.
			/**
			  * The texture variable's index, if found, is placed in the output reference parameter.
			  * The method returns whether or not this shader program has a variable with
			  * the given variable name.
			  */
			virtual Bool getTextureVariableIndex( const String& variableName, Index& variableIndex ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Variable Accessor Methods
			
			
			
			
			/// Return the total number of vertex variables that are part of this shader program.
			virtual Size getVertexVariableCount() const;
			
			
			
			
			/// Return a pointer to the vertex variable for this shader program at the given index.
			/**
			  * Variable indices range from 0 up to the number of vertex variables minus one.
			  * If an invalid variable index is specified, NULL is returned.
			  */
			virtual const VertexVariable* getVertexVariable( Index variableIndex ) const;
			
			
			
			
			/// Get the vertex variable that is part of this shader program with the specified name.
			/**
			  * The vertex variable, if found, is placed in the output reference parameter.
			  * The method returns whether or not this shader program has a variable with
			  * the given variable name.
			  */
			virtual Bool getVertexVariable( const String& variableName, const VertexVariable*& variable ) const;
			
			
			
			
			/// Get the vertex variable index for this shader program with the specified name.
			/**
			  * The vertex variable's index, if found, is placed in the output reference parameter.
			  * The method returns whether or not this shader program has a variable with
			  * the given variable name.
			  */
			virtual Bool getVertexVariableIndex( const String& variableName, Index& variableIndex ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Program ID Accessor Method
			
			
			
			
			/// Get a unique integral identifier for this shader program.
			RIM_INLINE OpenGLID getID() const
			{
				return programID;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Declaration
			
			
			
			
			/// Make the shader program class a friend so that it can create instances of this class.
			friend class OpenGLContext;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// An enum which describes the kind of a particular variable.
			typedef enum VariableType
			{
				CONSTANT_VARIABLE,
				TEXTURE_VARIABLE,
				VERTEX_VARIABLE
			};
			
			
			
			
			/// A class which encapsulates an index and variable type.
			class VariableIndex
			{
				public:
					
					/// Create a new variable index with the specified variable type and index.
					RIM_INLINE VariableIndex( VariableType newType, Index newIndex )
						:	type( newType ),
							index( newIndex )
					{
					}
					
					
					/// An enum value which describes the kind of variable this index is for.
					VariableType type;
					
					
					/// The index of the variable within the list of this index's variable type.
					Index index;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructors
			
			
			
			
			/// Create a shader program for the given context with no shaders attached to it.
			OpenGLShaderProgram( const GraphicsContext* context );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Query the shader for information about its attribute variables and store it in the shader program.
			void cacheShaderVariables();
			
			
			
			
			/// Clear all previously cached shader variables from this shader program.
			RIM_INLINE void clearCachedVariables();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An integer ID from OpenGL uniquely representing this shader program.
			OpenGLID programID;
			
			
			
			
			/// A list of the shader objects that are attached to this shader program.
			ArrayList< Pointer<Shader> > shaders;
			
			
			
			
			/// A list of the constant variables that are part of this shader program.
			ArrayList<ConstantVariable> constantVariables;
			
			
			
			
			/// A list of the texture variables that are part of this shader program.
			ArrayList<TextureVariable> textureVariables;
			
			
			
			
			/// A list of the per-vertex attribute variables that are part of this shader program.
			ArrayList<VertexVariable> vertexVariables;
			
			
			
			
			/// A hash map from variable names to 
			HashMap<String,VariableIndex> variableNames;
			
			
			
			
			/// A boolean value which indicates whether or not the shader program has been linked successfully.
			Bool linked;
			
			
			
			
			/// A boolean value which indicates whether or not this shader program was created successfully.
			Bool valid;
			
			
			
};




//##########################################################################################
//********************  End Rim Graphics Devices OpenGL Namespace  *************************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_OPENGL_SHADER_PROGRAM_H
