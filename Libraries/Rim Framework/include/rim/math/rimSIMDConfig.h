/*
 *  rimSIMDConfig.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 7/22/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SIMD_CONFIG_H
#define INCLUDE_RIM_SIMD_CONFIG_H


#include "rimMathConfig.h"


#include "rimScalarMath.h"


//##########################################################################################
//##########################################################################################
//############		
//############		SIMD Configuration Macros
//############		
//##########################################################################################
//##########################################################################################




/// Determine whether or not SIMD code should be used.
/**
  * If set to 1, many operations will be parallelized using SIMD vector operations.
  * This will generally increase performance but may not work on all hardware. If set to
  * 0, no SIMD operations will be used. If enabled but the hardware doesn't support SIMD
  * instructions, a serial fallback implementation will be used.
  */
#ifndef RIM_USE_SIMD
	#define RIM_USE_SIMD 1
#endif




/// Define the newest major version of SSE that can be used by GSound.
/**
  * This value can be used to limit the complexity of the SSE operations
  * performed when compiling for hardware that doesn't support newer SSE versions.
  * Only SSE versions up to this version (specified as an integer number)
  * can be used.
  */
#ifndef RIM_SSE_MAX_MAJOR_VERSION
	#define RIM_SSE_MAX_MAJOR_VERSION 4
#endif




/// Define the newest minor version of SSE that can be used by GSound.
/**
  * This value can be used to limit the complexity of the SSE operations
  * performed when compiling for hardware that doesn't support newer SSE versions.
  * Only SSE versions up to this version (specified as an integer number)
  * can be used.
  */
#ifndef RIM_SSE_MAX_MINOR_VERSION
	#define RIM_SSE_MAX_MINOR_VERSION 2
#endif




#if RIM_USE_SIMD
#if defined(RIM_CPU_POWER_PC) && defined(__ALTIVEC__)
	/// Define that Altivec instructions are available.
	#define RIM_SIMD_ALTIVEC 1
	
	/// Redfine the keyword associated with an Altivec vector to avoid name collisions.
	#ifdef RIM_COMPILER_GCC
		#undef vector
		#define RIM_ALTIVEC_VECTOR __vector
	#endif
	
	/// A macro which produces a boolean value indicating whether the specified (major,minor) version of SSE is supported.
	#define RIM_SSE_VERSION_IS_SUPPORTED( majorVersion, minorVersion ) 0

#elif defined(RIM_CPU_INTEL)
	/// Define that SSE instructions are available.
	#define RIM_SIMD_SSE 1
	
	/// Define a macro which determines whether a specified (major,minor) version of SSE is allowed by the user.
	#define RIM_SSE_VERSION_IS_ALLOWED( majorVersion, minorVersion ) \
				(RIM_SSE_MAX_MAJOR_VERSION > majorVersion || \
				(RIM_SSE_MAX_MAJOR_VERSION == majorVersion && RIM_SSE_MAX_MINOR_VERSION >= minorVersion))
	
	// Determine the newest available version of SSE and include its header.
	#if defined(RIM_COMPILER_GCC)
		#if defined(__SSE4_2__)
			#define RIM_SSE_MAJOR_VERSION 4
			#define RIM_SSE_MINOR_VERSION 2
			
		#elif defined(__SSE4_1__)
			#define RIM_SSE_MAJOR_VERSION 4
			#define RIM_SSE_MINOR_VERSION 1
			
		#elif defined(__SSSE3__)
			#define RIM_SSE_MAJOR_VERSION 3
			#define RIM_SSE_MINOR_VERSION 1
			
		#elif defined(__SSE3__)
			#define RIM_SSE_MAJOR_VERSION 3
			#define RIM_SSE_MINOR_VERSION 0
			
		#elif defined(__SSE2__)
			#define RIM_SSE_MAJOR_VERSION 2
			#define RIM_SSE_MINOR_VERSION 0
		
		#elif defined(__SSE__)
			#define RIM_SSE_MAJOR_VERSION 1
			#define RIM_SSE_MINOR_VERSION 0
		#endif
	#elif defined(RIM_COMPILER_MSVC)
		// Assume the newest version because MSVC has no way to determine this.
		#define RIM_SSE_MAJOR_VERSION 4
		#define RIM_SSE_MINOR_VERSION 2
	#endif
	
	
	/// A macro which produces a boolean value indicating whether the specified (major,minor) version of SSE is supported.
	#define RIM_SSE_VERSION_IS_SUPPORTED( majorVersion, minorVersion ) \
				(RIM_SSE_VERSION_IS_ALLOWED( majorVersion, minorVersion ) && \
				((majorVersion < RIM_SSE_MAJOR_VERSION) || \
				(majorVersion == RIM_SSE_MAJOR_VERSION && minorVersion <= RIM_SSE_MINOR_VERSION)))

#endif
#else // !RIM_USE_SIMD
	
	/// A macro which produces a boolean value indicating whether the specified (major,minor) version of SSE is supported.
	#define RIM_SSE_VERSION_IS_SUPPORTED( majorVersion, minorVersion ) 0
	
#endif




//##########################################################################################
//##########################################################################################
//############		
//############		SIMD Header Includes
//############		
//##########################################################################################
//##########################################################################################




#if RIM_SSE_VERSION_IS_SUPPORTED(1,0)
#if defined(RIM_COMPILER_MSVC)
	#include <intrin.h> // Include for extra intrinsics
#endif
	#include <mmintrin.h> // Include for MMX intrinsics
	#include <xmmintrin.h> // Include for SSE intrinsics
#endif

#if RIM_SSE_VERSION_IS_SUPPORTED(2,0)
	#include <emmintrin.h> // Include for SSE2 intrinsics
#endif

#if RIM_SSE_VERSION_IS_SUPPORTED(3,0)
	#include <pmmintrin.h> // Include for SSE3 intrinsics
#endif

#if RIM_SSE_VERSION_IS_SUPPORTED(3,1)
	#include <tmmintrin.h> // Include for SSSE3 intrinsics
#endif

#if RIM_SSE_VERSION_IS_SUPPORTED(4,1)
	#include <smmintrin.h> // Include for SSE4.1 intrinsics
#endif

#if RIM_SSE_VERSION_IS_SUPPORTED(4,2)
	#include <nmmintrin.h> // Include for SSE4.2 intrinsics
#endif




//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SIMD_CONFIG_H
