/*
 *  rimGraphicsOpenGLShader.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/2/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_OPENGL_SHADER_H
#define INCLUDE_RIM_GRAPHICS_OPENGL_SHADER_H


#include "rimGraphicsOpenGLConfig.h"


//##########################################################################################
//********************  Start Rim Graphics Devices OpenGL Namespace  ***********************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents an OpenGL hardware-executed shader program.
class OpenGLShader : public Shader
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this shader and release all resources associated with it.
			virtual ~OpenGLShader();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Source Code Accessor Methods
			
			
			
			
			/// Get the source code used by this shader.
			virtual const ShaderSourceString& getSourceCode() const;
			
			
			
			
			/// Set the source code used by the shader.
			virtual Bool setSourceCode( const ShaderSourceString& newSource,
										const ShaderLanguage& language = ShaderLanguage::DEFAULT );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	OpenGLShader Compile Method
			
			
			
			
			/// Compile the shader's source code and return whether or not the operation was successful.
			virtual Bool compile();
			
			
			
			
			/// Compile the shader's source code and return whether or not the operation was successful.
			virtual Bool compile( String& compilationLog );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Compilation Status Accessor Method
			
			
			
			
			/// Return whether or not this shader has been compiled.
			virtual Bool isCompiled() const;
			
			
			
			
			/// Return whether or not the shader was successfully compiled.
			virtual Bool isValid() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	OpenGL ID Accessor Method
			
			
			
			
			/// Get a unique integral identifier of this shader for OpenGL.
			RIM_INLINE OpenGLID getID() const
			{
				return shaderID;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Declaration
			
			
			
			
			/// Make the shader program class a friend so that it can create instances of this class.
			friend class OpenGLContext;
			
			
			
			
			/// Make the shader program class a friend so that it can access the shader ID of this shader.
			friend class OpenGLShaderProgram;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Constructors
			
			
			
			
			/// Create a new shader for the specified context with no preprocessor symbols defined.
			OpenGLShader( const GraphicsContext* context, ShaderType shaderType,
						const ShaderSourceString& newSource, const ShaderLanguage& newLanguage );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Submit the current shader source code to OpenGL.
			void submitSourceCode();
			
			
			
			
			/// Convert the specified shader type enum to an OpenGL shader type enum value.
			RIM_INLINE static Bool getGLShaderType( ShaderType shaderType, OpenGLEnum& glOpenGLShaderType );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An integer which uniquely identifies this shader within OpenGL.
			OpenGLID shaderID;
			
			
			
			
			/// A string representing the complete source code of the shader.
			ShaderSourceString sourceCode;
			
			
			
			
			/// A boolean value indicating whether or not this shader has been compiled.
			Bool compiled;
			
			
			
			
			/// A boolean value which indicates whether or not this shader was created successfully.
			Bool valid;
			
			
			
};




//##########################################################################################
//********************  End Rim Graphics Devices OpenGL Namespace  *************************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_OPENGL_SHADER_H
