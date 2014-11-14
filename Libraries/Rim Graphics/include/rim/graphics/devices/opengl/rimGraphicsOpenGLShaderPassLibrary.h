/*
 *  rimGraphicsOpenGLShaderPassLibrary.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/1/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_OPENGL_SHADER_PASS_LIBRARY_H
#define INCLUDE_RIM_GRAPHICS_OPENGL_SHADER_PASS_LIBRARY_H


#include "rimGraphicsOpenGLConfig.h"


//##########################################################################################
//********************  Start Rim Graphics Devices OpenGL Namespace  ***********************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains a set of default shader passes for OpenGL.
class OpenGLShaderPassLibrary : public ShaderPassLibrary
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new OpenGL shader pass library with the default set of shader passes.
			OpenGLShaderPassLibrary();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Initialize this shader pass library with the default set of OpenGL shader passes.
			void initializeLibrary();
			
			
			
			
			/// Create an initialize a new generic shader pass with the ShaderPassUsage::FLAT usage type.
			static Pointer<GenericShaderPass> newFlatPass();
			
			/// Create an initialize a new generic shader pass with the ShaderPassUsage::FLAT_VERTEX_COLOR usage type.
			static Pointer<GenericShaderPass> newFlatVertexColorPass();
			
			/// Create an initialize a new generic shader pass with the ShaderPassUsage::LAMBERTIAN usage type.
			static Pointer<GenericShaderPass> newLambertianPass();
			
			/// Create an initialize a new generic shader pass with the ShaderPassUsage::LAMBERTIAN_VERTEX_COLOR usage type.
			static Pointer<GenericShaderPass> newLambertianVertexColorPass();
			
			/// Create an initialize a new generic shader pass with the ShaderPassUsage::PHONG usage type.
			static Pointer<GenericShaderPass> newPhongPass();
			
			/// Create an initialize a new generic shader pass with the ShaderPassUsage::PHONG_VERTEX_COLOR usage type.
			static Pointer<GenericShaderPass> newPhongVertexColorPass();
			
			/// Create an initialize a new generic shader pass with the ShaderPassUsage::DEPTH usage type.
			static Pointer<GenericShaderPass> newDepthPass();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			static String phongVertexSource;
			static String phongFragmentSource;
			
			
			static String depthVertexSource;
			static String depthFragmentSource;
			
			
			
};




//##########################################################################################
//********************  End Rim Graphics Devices OpenGL Namespace  *************************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_OPENGL_SHADER_PASS_LIBRARY_H
