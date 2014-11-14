/*
 *  rimGraphicsOpenGLConfig.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/1/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_OPENGL_CONFIG_H
#define INCLUDE_RIM_GRAPHICS_OPENGL_CONFIG_H


#include "../rimGraphicsDevicesConfig.h"


#include "../rimGraphicsDevice.h"
#include "../rimGraphicsContext.h"
#include "../rimGraphicsContextFlags.h"
#include "../rimGraphicsPixelFormat.h"


#ifdef RIM_PLATFORM_APPLE
	
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <OpenGL/glext.h>
	
#else
#ifdef RIM_PLATFORM_WINDOWS
	
	#ifndef UNICODE
		#define UNICODE
	#endif
	
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif
	
	#include <Windows.h>
	
	#define GLEW_STATIC
	#include <GL/glew.h>
	#include <GL/wglew.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
    #define glXGetProcAddress(x) (*glXGetProcAddressARB)((const GLubyte*)x)
	
#endif
#endif




//##########################################################################################
//##########################################################################################
//############		
//############		Extension Handling
//############		
//##########################################################################################
//##########################################################################################




#if GL_VERSION_3_0 | GL_VERSION_2_0
	
	//********************************************************************************
	//********************************************************************************
	//********************************************************************************
	//******	Framebuffer Object Preprocessor Redefinitions
	
	
	// Map EXT FBO function names to version 3.0 names if necessary
	#ifndef glGenFramebuffers
	#define glGenFramebuffers			glGenFramebuffersEXT
	#endif
	
	#ifndef glDeleteFramebuffers
	#define glDeleteFramebuffers		glDeleteFramebuffersEXT
	#endif
	
	#ifndef glBindFramebuffer
	#define glBindFramebuffer			glBindFramebufferEXT
	#endif
	
	#ifndef glFramebufferTexture1D
	#define glFramebufferTexture1D		glFramebufferTexture1DEXT
	#endif
	
	#ifndef glFramebufferTexture2D
	#define glFramebufferTexture2D		glFramebufferTexture2DEXT
	#endif
	
	#ifndef glFramebufferTexture3D
	#define glFramebufferTexture3D		glFramebufferTexture3DEXT
	#endif
	
	#ifndef glCheckFramebufferStatus
	#define glCheckFramebufferStatus	glCheckFramebufferStatusEXT
	#endif
	
	#ifndef glGenerateMipmap
	#define glGenerateMipmap			glGenerateMipmapEXT
	#endif
	
	
	// Map EXT FBO constants to version 3.0 constants
	#ifndef GL_FRAMEBUFFER
	#define GL_FRAMEBUFFER				GL_FRAMEBUFFER_EXT
	#endif
	
	#ifndef GL_COLOR_ATTACHMENT0
	#define GL_COLOR_ATTACHMENT0		GL_COLOR_ATTACHMENT0_EXT
	#endif
	
	#ifndef GL_COLOR_ATTACHMENT1
	#define GL_COLOR_ATTACHMENT1		GL_COLOR_ATTACHMENT1_EXT
	#endif
	
	#ifndef GL_COLOR_ATTACHMENT2
	#define GL_COLOR_ATTACHMENT2		GL_COLOR_ATTACHMENT2_EXT
	#endif
	
	#ifndef GL_COLOR_ATTACHMENT3
	#define GL_COLOR_ATTACHMENT3		GL_COLOR_ATTACHMENT3_EXT
	#endif
	
	#ifndef GL_COLOR_ATTACHMENT4
	#define GL_COLOR_ATTACHMENT4		GL_COLOR_ATTACHMENT4_EXT
	#endif
	
	#ifndef GL_COLOR_ATTACHMENT5
	#define GL_COLOR_ATTACHMENT5		GL_COLOR_ATTACHMENT5_EXT
	#endif
	
	#ifndef GL_COLOR_ATTACHMENT6
	#define GL_COLOR_ATTACHMENT6		GL_COLOR_ATTACHMENT6_EXT
	#endif
	
	#ifndef GL_COLOR_ATTACHMENT7
	#define GL_COLOR_ATTACHMENT7		GL_COLOR_ATTACHMENT7_EXT
	#endif
	
	#ifndef GL_COLOR_ATTACHMENT8
	#define GL_COLOR_ATTACHMENT8		GL_COLOR_ATTACHMENT8_EXT
	#endif
	
	#ifndef GL_COLOR_ATTACHMENT9
	#define GL_COLOR_ATTACHMENT9		GL_COLOR_ATTACHMENT9_EXT
	#endif
	
	#ifndef GL_MAX_COLOR_ATTACHMENTS
	#define GL_MAX_COLOR_ATTACHMENTS		GL_MAX_COLOR_ATTACHMENTS_EXT
	#endif
	
	#ifndef GL_DEPTH_ATTACHMENT
	#define GL_DEPTH_ATTACHMENT			GL_DEPTH_ATTACHMENT_EXT
	#endif
	
	#ifndef GL_STENCIL_ATTACHMENT
	#define GL_STENCIL_ATTACHMENT		GL_STENCIL_ATTACHMENT_EXT
	#endif
	
	#ifndef GL_FRAMEBUFFER_COMPLETE
	#define GL_FRAMEBUFFER_COMPLETE		GL_FRAMEBUFFER_COMPLETE_EXT
	#endif
	
	#ifndef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
	#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT	GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT
	#endif
	
	#ifndef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
	#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT	GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT
	#endif
	
	#ifndef GL_FRAMEBUFFER_UNSUPPORTED
	#define GL_FRAMEBUFFER_UNSUPPORTED	GL_FRAMEBUFFER_UNSUPPORTED_EXT
	#endif
	
	#ifndef GL_FRAMEBUFFER_BINDING
	#define GL_FRAMEBUFFER_BINDING	GL_FRAMEBUFFER_BINDING_EXT
	#endif
	
	
	//********************************************************************************
	//********************************************************************************
	//********************************************************************************
	//******	Floating Point Texture Preprocessor Redefinitions
	
	
	#if GL_ARB_texture_float
		
		// 16-Bit Half Float Texture Formats
		#ifndef GL_ALPHA16F
		#define GL_ALPHA16F	GL_ALPHA16F_ARB
		#endif
		
		#ifndef GL_LUMINANCE16F
		#define GL_LUMINANCE16F	GL_LUMINANCE16F_ARB
		#endif
		
		#ifndef GL_LUMINANCE_ALPHA16F
		#define GL_LUMINANCE_ALPHA16F	GL_LUMINANCE_ALPHA16F_ARB
		#endif
		
		#ifndef GL_INTENSITY16F
		#define GL_INTENSITY16F	GL_INTENSITY16F_ARB
		#endif
		
		#ifndef GL_RGB16F
		#define GL_RGB16F	GL_RGB16F_ARB
		#endif
		
		#ifndef GL_RGBA16F
		#define GL_RGBA16F	GL_RGBA16F_ARB
		#endif
		
		
		// 32-Bit Single Precision Float Texture Formats
		#ifndef GL_ALPHA32F
		#define GL_ALPHA32F	GL_ALPHA32F_ARB
		#endif
		
		#ifndef GL_LUMINANCE32F
		#define GL_LUMINANCE32F	GL_LUMINANCE32F_ARB
		#endif
		
		#ifndef GL_LUMINANCE_ALPHA32F
		#define GL_LUMINANCE_ALPHA32F	GL_LUMINANCE_ALPHA32F_ARB
		#endif
		
		#ifndef GL_INTENSITY32F
		#define GL_INTENSITY32F	GL_INTENSITY32F_ARB
		#endif
		
		#ifndef GL_RGB32F
		#define GL_RGB32F	GL_RGB32F_ARB
		#endif
		
		#ifndef GL_RGBA32F
		#define GL_RGBA32F	GL_RGBA32F_ARB
		#endif
		
	#endif
	
	
	#if GL_ARB_half_float_pixel
		
		#ifndef GL_HALF_FLOAT
		#define GL_HALF_FLOAT	GL_HALF_FLOAT_ARB
		#endif
		
	#endif
	
	
	#if GL_EXT_framebuffer_sRGB
		
		#ifndef GL_FRAMEBUFFER_SRGB
		#define GL_FRAMEBUFFER_SRGB	GL_FRAMEBUFFER_SRGB_EXT
		#endif
		
	#endif
	
	
	//********************************************************************************
	//********************************************************************************
	//********************************************************************************
	//******	Unsigned Integer Shader Uniform Type Preprocessor Redefinitions
	
	
	#if GL_EXT_gpu_shader4
		
		#ifndef GL_UNSIGNED_INT_VEC2
		#define GL_UNSIGNED_INT_VEC2	GL_UNSIGNED_INT_VEC2_EXT
		#endif
		
		#ifndef GL_UNSIGNED_INT_VEC3
		#define GL_UNSIGNED_INT_VEC3	GL_UNSIGNED_INT_VEC3_EXT
		#endif
		
		#ifndef GL_UNSIGNED_INT_VEC4
		#define GL_UNSIGNED_INT_VEC4	GL_UNSIGNED_INT_VEC4_EXT
		#endif
		
		#ifndef GL_SAMPLER_CUBE_SHADOW
		#define GL_SAMPLER_CUBE_SHADOW	GL_SAMPLER_CUBE_SHADOW_EXT
		#endif
		
	#endif
	
#else
	
	//********************************************************************************
	//********************************************************************************
	//********************************************************************************
	//******	OpenGL Version < 2.0 Not Supported!
	
	#error "OpenGL Version 2.0 or later is required"
	
#endif




//********************************************************************************
//********************************************************************************
//********************************************************************************
//******	Anisotropic Filtering Preprocessor Redefinitions



#if GL_EXT_texture_filter_anisotropic
	
	#ifndef GL_TEXTURE_MAX_ANISOTROPY
	#define GL_TEXTURE_MAX_ANISOTROPY	GL_TEXTURE_MAX_ANISOTROPY_EXT
	#endif
	
	#ifndef GL_MAX_TEXTURE_MAX_ANISOTROPY
	#define GL_MAX_TEXTURE_MAX_ANISOTROPY	GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT
	#endif
	
#endif




//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_START
	#define RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_START		RIM_GRAPHICS_DEVICES_NAMESPACE_START namespace opengl {
#endif




#ifndef RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_END
	#define RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_END		}; RIM_GRAPHICS_DEVICES_NAMESPACE_END
#endif




//##########################################################################################
//********************  Start Rim Graphics Devices OpenGL Namespace  ***********************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




/// Define the type which is used to represent an object ID for the OpenGL API.
typedef UInt OpenGLID;




/// Define the type which is used to represent an enum value in the OpenGL API.
typedef UInt OpenGLEnum;




//##########################################################################################
//********************  End Rim Graphics Devices OpenGL Namespace  *************************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_OPENGL_CONFIG_H
