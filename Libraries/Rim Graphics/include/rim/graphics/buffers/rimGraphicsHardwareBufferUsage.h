/*
 *  rimGraphicsHardwareBufferUsage.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 1/8/11.
 *  Copyright 2011 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_HARDWARE_BUFFER_USAGE_H
#define INCLUDE_RIM_GRAPHICS_HARDWARE_BUFFER_USAGE_H


#include "rimGraphicsBuffersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Buffers Namespace  ***************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies how a GPU-side attribute buffer should be used.
/**
  * The usage specified here is used as a hint to the GPU to how the
  * hardware attribute buffer is handled. The usage hints at how often
  * a buffer will be updated and used to draw.
  */
class HardwareBufferUsage
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Attribute Buffer Usage Enum Definition
			
			
			
			
			/// An enum type which represents the usage for a hardware attribute buffer.
			typedef enum Enum
			{
				/// A usage where the buffer contents are set once and used to draw many times.
				STATIC = 1,
				
				/// A usage where the buffer contents are set and used to draw many times.
				DYNAMIC = 2,
				
				/// A usage where the buffer contents are set once and used to draw only a few times.
				STREAM = 3
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new hardware attribute buffer usage with the specified usage enum value.
			RIM_INLINE HardwareBufferUsage( Enum newUsage )
				:	usage( newUsage )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this hardware attribute buffer usage to an enum value.
			RIM_INLINE operator Enum () const
			{
				return (Enum)usage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the hardware attribute buffer usage.
			String toString() const;
			
			
			
			
			/// Convert this hardware attribute buffer usage into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum for the hardware attribute buffer usage.
			UByte usage;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Buffers Namespace  *****************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_HARDWARE_BUFFER_USAGE_H
