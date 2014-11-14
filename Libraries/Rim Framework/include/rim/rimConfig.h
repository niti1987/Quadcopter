/*
 *  RimConfig.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 2/6/11.
 *  Copyright 2011 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_CONFIG_H
#define INCLUDE_RIM_CONFIG_H


#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <cstring>


//##########################################################################################
//##########################################################################################
//############		
//############		Library Debugging Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_DEBUG
	#if defined(_DEBUG)
		/// Define whether or not internal debugging checks should be force-enabled.
		#define RIM_DEBUG
	#endif
#endif




//##########################################################################################
//##########################################################################################
//############		
//############		Library Configuration
//############		
//##########################################################################################
//##########################################################################################




/// Define whether or not to turn off all assertion (including assertions active during release-mode builds).
#ifndef RIM_DISABLE_ASSERTIONS
	#define RIM_DISABLE_ASSERTIONS 0
#endif




/// Define the function to use for all library memory allocations.
#ifndef RIM_MALLOC
	#define RIM_MALLOC(X) (std::malloc(X))
#endif




/// Define the function to use for all library memory deallocations.
#ifndef RIM_FREE
	#define RIM_FREE(X) (std::free(X))
#endif



/// Define a macro that converts its argument to its literal string representation.
#ifndef RIM_STRINGIFY
	#ifndef RIM_STRINGIFIY_WRAPPER
		#define RIM_STRINGIFIY_WRAPPER( x ) #x
	#endif
	
	#define RIM_STRINGIFY( x ) (RIM_STRINGIFIY_WRAPPER(x))
#endif




//##########################################################################################
//##########################################################################################
//############		
//############		Library Platform Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifdef __APPLE__
	#define RIM_PLATFORM_APPLE
#endif




#if defined(_WIN32) || defined(__WIN32__)
	#define RIM_PLATFORM_WIN32
#endif




#if defined(_WIN64)
	#define RIM_PLATFORM_WIN64
#endif




#if defined(RIM_PLATFORM_WIN32) || defined(RIM_PLATFORM_WIN64) || defined(__WINDOWS__)
	#define RIM_PLATFORM_WINDOWS
#endif




#if defined( __GNUC__ )
	#define RIM_COMPILER_GCC __GNUC__
	#define RIM_COMPILER RIM_COMPILER_GCC
	#define RIM_GCC_VERSION( Major, Minor ) (Major*10000 + Minor*100 )
	#define RIM_COMPILER_VERSION RIM_GCC_VERSION( __GNUC__, __GNUC_MINOR__ )
	
#elif defined( _MSC_VER )
	#define RIM_COMPILER_MSVC _MSC_VER
	#define RIM_COMPILER RIM_COMPILER_MSVC
	#define RIM_COMPILER_VERSION _MSC_VER
	
#else
	#error Unsupported compiler.
#endif



#if defined( RIM_COMPILER_GCC )
	
	#ifdef RIM_DEBUG
		#define RIM_INLINE inline
		#define RIM_FORCE_INLINE inline
	#else
		#define RIM_INLINE inline
		#define RIM_FORCE_INLINE __attribute__((__always_inline__)) inline
	#endif
	
	#define RIM_NO_INLINE __attribute__((noinline))
	
	#define RIM_EXPORT __attribute__((visibility("default")))
	
	#define RIM_ALIGN(alignment) __attribute__((aligned(alignment)))
	
	#if defined(RIM_PLATFORM_APPLE)
        #if !defined(__MAC_10_6)
			#define RIM_ALIGNED_MALLOC( size, alignment ) (RIM_MALLOC( size ))
        #else
			namespace rim { namespace util {

			RIM_FORCE_INLINE void* posix_memalign_wrapper( size_t size, size_t alignment )
			{
				void* pointer;
				posix_memalign( &pointer, alignment, size );
				return pointer;
			}

			}; };

			#include <malloc/malloc.h>
			#define RIM_ALIGNED_MALLOC( size, alignment ) (posix_memalign_wrapper( size, alignment ))

        #endif
	#else
		#define RIM_ALIGNED_MALLOC( size, alignment ) (RIM_MALLOC( size ))
	#endif
	
	#define RIM_ALIGNED_FREE(X) (std::free(X))
	
	#define RIM_DEPRECATED __attribute__((deprecated))
	
	#if __LP64__
		#define RIM_PLATFORM_64_BIT
	#else
		#define RIM_PLATFORM_32_BIT
	#endif

#elif defined( RIM_COMPILER_MSVC )
	
	#include <malloc.h>
	
	#ifdef RIM_DEBUG
		#define RIM_INLINE inline
		#define RIM_FORCE_INLINE inline
	#else
		#if RIM_COMPILER_VERSION >= 1200
			#define RIM_INLINE inline
			#define RIM_FORCE_INLINE __forceinline
		#else
			#define RIM_INLINE inline
			#define RIM_FORCE_INLINE inline
		#endif
	#endif
	
	#define RIM_NO_INLINE __declspec(noinline)
	
	#define RIM_EXPORT __declspec(dllexport)
	
	#define RIM_ALIGN(alignment) __declspec(align(alignment))
	
	#define RIM_ALIGNED_MALLOC( size, alignment ) (_aligned_malloc( size, alignment ))
	
	#define RIM_ALIGNED_FREE(X) (_aligned_free(X))
	
	#define RIM_DEPRECATED __declspec(deprecated)
	
	#if defined(_WIN64)
		#define RIM_PLATFORM_64_BIT
	#else
		#define RIM_PLATFORM_32_BIT
	#endif
	
#else
	
	/// Define the inlining procedure to use for methods that should be inlined.
	#define RIM_INLINE inline
	#define RIM_FORCE_INLINE inline
	#define RIM_NO_INLINE 
	
	/// Define the alignment declaration to be use when aligning structure/class members.
	#define RIM_ALIGN(alignment) 
	
	#define RIM_EXPORT 
	
	/// Define the function to use when allocating aligned blocks of memory.
	#define RIM_ALIGNED_MALLOC( size, alignment ) (RIM_MALLOC(size))
	
	/// Define the function to use when freeing an aligned block of memory.
	#define RIM_ALIGNED_FREE(X) (RIM_FREE(X))
	
	/// Define the marker which is used when defining methods, types, and variables as deprecated.
	#define RIM_DEPRECATED 
	
#endif




#if defined(_M_PPC) || defined(__ppc__) || defined(__POWERPC__)
	#define RIM_CPU_POWER_PC
	
#elif defined(_M_X64) || defined(_M_IX86) || defined(__x86_64__) || defined(__i386__)
	#define RIM_CPU_INTEL
#else
	#error Unsupported CPU type.
#endif




//##########################################################################################
//##########################################################################################
//############		
//############		Library Assertion Configuration
//############		
//##########################################################################################
//##########################################################################################



#if !RIM_DISABLE_ASSERTIONS

	// Define the assertion to use in only debug builds.
	#ifdef RIM_DEBUG
		// Make sure that debugging is enabled.
		#ifdef NDEBUG
			#undef NDEBUG

			#include <assert.h>
			#define RIM_DEBUG_ASSERT(X) assert(X)
			#define RIM_DEBUG_ASSERT_MESSAGE(X, MESSAGE) { ( X ? 0 : std::printf("%s\n",MESSAGE)); assert(X); }
			#define RIM_DEBUG_ASSERT_MESSAGE_CODE(X, MESSAGE, CODE) { ( X ? 0 : \
					std::printf("%s\nError Code: %X\n",MESSAGE,(int)CODE)); assert(X); }

			#define NDEBUG
		#else
			#include <assert.h>
			#define RIM_DEBUG_ASSERT(X) assert(X)
			#define RIM_DEBUG_ASSERT_MESSAGE(X, MESSAGE) { ( X ? 0 : std::printf("%s\n",MESSAGE)); assert(X); }
			#define RIM_DEBUG_ASSERT_MESSAGE_CODE(X, MESSAGE, CODE) { ( X ? 0 : \
					std::printf("%s\nError Code: %X\n",MESSAGE,(int)CODE)); assert(X); }
		#endif
	#else
		#define RIM_DEBUG_ASSERT(X) ((void)0)
		#define RIM_DEBUG_ASSERT_MESSAGE(X, MESSAGE) ((void)0)
	#endif


	// Define the assertion to use for release builds.
	#ifdef NDEBUG
		#undef NDEBUG
		#include <assert.h>
		#define RIM_ASSERT(X) assert(X)
		#define RIM_ASSERT_MESSAGE(X, MESSAGE) { ( X ? 0 : std::printf("%s\n",MESSAGE)); assert(X); }
		#define RIM_ASSERT_MESSAGE_CODE(X, MESSAGE, CODE) { ( X ? 0 : \
					std::printf("%s\nError Code: %X\n",MESSAGE,(int)CODE)); assert(X); }
		#define NDEBUG
	#else
		#include <assert.h>
		#define RIM_ASSERT(X) assert(X)
		#define RIM_ASSERT_MESSAGE(X, MESSAGE) { ( X ? 0 : std::printf("%s\n",MESSAGE)); assert(X); }
		#define RIM_ASSERT_MESSAGE_CODE(X, MESSAGE, CODE) { ( X ? 0 : \
					std::printf("%s\nError Code: %X\n",MESSAGE,(int)CODE)); assert(X); }
	#endif
	
#else

	// Define dummy assertion macros if assertions are disabled.
	#define RIM_ASSERT(X) ((void)0)
	#define RIM_ASSERT_MESSAGE(X, MESSAGE) ((void)0)
	#define RIM_ASSERT_MESSAGE_CODE(X, MESSAGE, CODE) ((void)0)
	#define RIM_DEBUG_ASSERT(X) ((void)0)
	#define RIM_DEBUG_ASSERT_MESSAGE(X, MESSAGE) ((void)0)

#endif




//##########################################################################################
//##########################################################################################
//############		
//############		Library Endian-ness Configuration
//############		
//##########################################################################################
//##########################################################################################




#if	defined(__hppa__) || \
    defined(__m68k__) || defined(mc68000) || defined(_M_M68K) || \
    (defined(__MIPS__) && defined(__MISPEB__)) || \
    defined(__ppc__) || defined(__POWERPC__) || defined(_M_PPC) || \
    defined(__sparc__)
	#define RIM_BIG_ENDIAN
#else
	#define RIM_LITTLE_ENDIAN
#endif




//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




/// Define the name of the main rim library namespace.
#ifndef RIM_NAMESPACE
	#define RIM_NAMESPACE rim
#endif




/// Define a macro used to start the rim namespace.
#ifndef RIM_NAMESPACE_START
	#define RIM_NAMESPACE_START		namespace RIM_NAMESPACE {
#endif




/// Define a macro used to end the rim namespace.
#ifndef RIM_NAMESPACE_END
	#define RIM_NAMESPACE_END		};
#endif




/// The enclosing namespace for the entire Rim library.
RIM_NAMESPACE_START
RIM_NAMESPACE_END




//##########################################################################################
//******************************  Start Rim Namespace  **********************************
RIM_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//##########################################################################################
//##########################################################################################
//############		
//############		Define NULL (if not already avalible)
//############		
//##########################################################################################
//##########################################################################################




#ifndef NULL
	#ifndef __cplusplus
		#define NULL ((void *)0)
	#else
		#define NULL 0
	#endif
#endif




//##########################################################################################
//##########################################################################################
//############		
//############		Sized Floating-Point Primitive Type Definitions
//############		
//##########################################################################################
//##########################################################################################




/// Define the type used to represent a 32-bit floating point number.
typedef float				Float32;




/// Define the type used to represent a 64-bit floating point number.
typedef double				Float64;




//##########################################################################################
//##########################################################################################
//############		
//############		Sized Integer Primitive Type Definitions
//############		
//##########################################################################################
//##########################################################################################




/// Define the type used to represent an 8-bit signed integral number.
typedef signed char			Int8;


/// Define the type used to represent an 8-bit unsigned integral number.
typedef unsigned char		UInt8;




/// Define the type used to represent a 16-bit signed integral number.
typedef signed short		Int16;


/// Define the type used to represent a 16-bit unsigned integral number.
typedef unsigned short		UInt16;




/// Define the type used to represent a 32-bit signed integral number.
typedef signed int			Int32;


/// Define the type used to represent a 32-bit unsigned integral number.
typedef unsigned int		UInt32;




/// Define the type used to represent a 64-bit signed integral number.
typedef signed long long	Int64;


/// Define the type used to represent a 64-bit unsigned integral number.
typedef unsigned long long	UInt64;




//##########################################################################################
//##########################################################################################
//############		
//############		Standard Primitive Type Redefinitions
//############		
//##########################################################################################
//##########################################################################################




/// Redefine the standard 'bool' primitive type to use the library's type naming conventions.
typedef bool Bool;




/// Redefine the standard 'short' primitive type to use the library's type naming conventions.
typedef short				Short;


/// Redefine the standard 'unsigned short' primitive type to use the library's type naming conventions.
typedef unsigned short		UShort;




/// Redefine the standard 'int' primitive type to use the library's type naming conventions.
typedef int					Int;


/// Redefine the standard 'unsigned int' primitive type to use the library's type naming conventions.
typedef unsigned int		UInt;




/// Redefine the standard 'long' primitive type to use the library's type naming conventions.
typedef long				Long;


/// Redefine the standard 'unsigned long' primitive type to use the library's type naming conventions.
typedef unsigned long		ULong;




/// Redefine the standard 'long long' primitive type to use the library's type naming conventions.
typedef long long			LongLong;


/// Redefine the standard 'unsigned long long' primitive type to use the library's type naming conventions.
typedef unsigned long long	ULongLong;




/// Redefine the standard 'float' primitive type to use the library's type naming conventions.
typedef float				Float;




/// Redefine the standard 'double' primitive type to use the library's type naming conventions.
typedef double				Double;




//##########################################################################################
//##########################################################################################
//############		
//############		Application-Specific Primitive Type Definitions
//############		
//##########################################################################################
//##########################################################################################




/// Define the type to use when holding signed data, should be 8 bits wide.
typedef Int8				Byte;




/// Define the type to use when holding generic data, should be 8 bits wide.
typedef UInt8				UByte;




/// Define the type to use when working with ASCII character data.
typedef char				Char;




/// Define the type to use for hash codes in hash tables, should be an unsigned integer.
typedef std::size_t			Hash;




/// Define the type to use to represent a quanitity of something, should be an unsigned integer.
typedef std::size_t			Size;




/// Define the type to use for a large-scale size. This is the largest supported unsigned integer type.
typedef UInt64				LargeSize;




/// Define the type to use to represent an offset (index) in an array or sequence of things.
typedef std::size_t			Index;




/// Define the type to use for a large-scale index. This is the largest supported unsigned integer type.
typedef UInt64				LargeIndex;




#if defined(RIM_PLATFORM_32_BIT)
/// Define the type on 32-bit systems that is the same size as a pointer.
typedef UInt32				PointerInt;
typedef Int32				SignedIndex;
#elif defined(RIM_PLATFORM_64_BIT)
/// Define the type on 64-bit systems that is the same size as a pointer.
typedef UInt64				PointerInt;
typedef Int64				SignedIndex;
#endif



/// Define the type for a UTF-8 unicode character.
typedef UInt8				UTF8Char;




/// Define the type for a UTF-16 unicode character.
typedef UInt16				UTF16Char;




/// Define the type for a UTF-32 unicode character.
typedef UInt32				UTF32Char;




/// Define the type for a unicode character that can hold the data for any other unicode character type.
typedef UTF32Char			UniChar;




//##########################################################################################
//******************************  End Rim Namespace  ************************************
RIM_NAMESPACE_END
//******************************************************************************************
//##########################################################################################




#endif // INCLUDE_RIM_CONFIG_H
