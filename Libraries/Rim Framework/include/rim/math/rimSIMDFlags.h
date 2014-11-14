/*
 *  rimSIMDFlags.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 9/25/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SIMD_FLAGS_H
#define INCLUDE_RIM_SIMD_FLAGS_H


#include "rimSIMDConfig.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that contains flags that specify the type of SIMD operations supported.
/**
  * These flags allow the user to determine at runtime the capabilities of the CPU,
  * and to then choose one code path or another based on the result.
  */
class SIMDFlags
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	SIMD Flags Enum Declaration
			
			
			
			
			/// An enum which specifies the different SIMD flags.
			typedef enum Flag
			{
				/// A flag indicating that SSE is supported by the CPU.
				SSE = (1 << 0),
				
				/// A flag indicating that SSE2 is supported by the CPU.
				SSE_2 = (1 << 1),
				
				/// A flag indicating that SSE3 is supported by the CPU.
				SSE_3 = (1 << 2),
				
				/// A flag indicating that SSSE3 is supported by the CPU.
				SSSE_3 = (1 << 3),
				
				/// A flag indicating that SSE 4.1 is supported by the CPU.
				SSE_4_1 = (1 << 4),
				
				/// A flag indicating that SSE 4.2 is supported by the CPU.
				SSE_4_2 = (1 << 5),
				
				/// A flag indicating that SSE 4.1 and SSE 4.2 is supported by the CPU.
				SSE_4 = SSE_4_1 | SSE_4_2,
				
				/// A flag indicating that AVX is supported by the CPU.
				AVX = (1 << 6),
				
				/// A flag indicating that AVX2 is supported by the CPU.
				AVX_2 = (1 << 7),
				
				/// A flag indicating that AVX-512F is supported by the CPU.
				AVX_512F = (1 << 8),
				
				/// A flag indicating that AVX-512PF is supported by the CPU.
				AVX_512PF = (1 << 9),
				
				/// A flag indicating that AVX-512ER is supported by the CPU.
				AVX_512ER = (1 << 10),
				
				/// A flag indicating that AVX-512CD is supported by the CPU.
				AVX_512CD = (1 << 11),
				
				/// A flag indicating that the ARM NEON SIMD is supported by the CPU.
				NEON = (1 << 30),
				
				/// A flag indicating that Altivec is supported by the CPU.
				ALTIVEC = (1 << 31),
				
				/// The flag value when no flags are set.
				UNDEFINED = 0
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new SIMD flags object with no flags set.
			RIM_INLINE SIMDFlags()
				:	flags( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new SIMD flags object with the specified flag value initially set.
			RIM_INLINE SIMDFlags( Flag flag )
				:	flags( flag )
			{
			}
			
			
			
			
			/// Create a new SIMD flags object with the specified initial combined flags value.
			RIM_INLINE SIMDFlags( UInt32 newFlags )
				:	flags( newFlags )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Integer Cast Operator
			
			
			
			
			/// Convert this flags object to an integer value.
			/**
			  * This operator is provided so that the object
			  * can be used as an integer value for bitwise logical operations.
			  */
			RIM_INLINE operator UInt32 () const
			{
				return flags;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flag Is Set Accessor Methods
			
			
			
			
			/// Return whether or not the specified flag value is set for this flags object.
			RIM_INLINE Bool isSet( Flag flag ) const
			{
				return (flags & flag) != UNDEFINED;
			}
			
			
			
			
			/// Set whether or not the specified flag value is set for this flags object.
			RIM_INLINE void set( Flag flag, Bool newIsSet )
			{
				if ( newIsSet )
					flags |= flag;
				else
					flags &= ~flag;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Current CPU Flags Accessor
			
			
			
			
			/// Return an object containing the SIMD flags for the current CPU.
			static SIMDFlags get();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A value indicating the flags that are set.
			UInt32 flags;
			
			
			
};




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SIMD_FLAGS_H
