/*
 *  rimGraphicsOpenGLShaderPass.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/2/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_OPENGL_SHADER_PASS_H
#define INCLUDE_RIM_GRAPHICS_OPENGL_SHADER_PASS_H


#include "rimGraphicsOpenGLConfig.h"


//##########################################################################################
//********************  Start Rim Graphics Devices OpenGL Namespace  ***********************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents an OpenGL hardware-executed shader pass.
class OpenGLShaderPass : public ShaderPass
{
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
		//******	Constructors
			
			
			
			
			/// Create a new shader pass which doesn't have an associated shader program.
			RIM_INLINE OpenGLShaderPass( const devices::GraphicsContext* context )
				:	ShaderPass( context )
			{
			}
			
			
			
			
			/// Create a new shader pass which uses the specified shader program and the default render mode.
			RIM_INLINE OpenGLShaderPass( const devices::GraphicsContext* context, const Pointer<ShaderProgram>& newProgram )
				:	ShaderPass( context, newProgram )
			{
			}
			
			
			
			
			/// Create a new shader pass which uses the specified shader program and render mode.
			RIM_INLINE OpenGLShaderPass( const devices::GraphicsContext* context, const Pointer<ShaderProgram>& newProgram,
										const RenderMode& newRenderMode )
				:	ShaderPass( context, newProgram, newRenderMode )
			{
			}
			
			
			
};




//##########################################################################################
//********************  End Rim Graphics Devices OpenGL Namespace  *************************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_OPENGL_SHADER_PASS_H
