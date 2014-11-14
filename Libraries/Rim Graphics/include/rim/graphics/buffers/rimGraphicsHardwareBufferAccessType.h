/*
 *  rimGraphicsHardwareBufferAccessType.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 1/9/11.
 *  Copyright 2011 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_HARDWARE_BUFFER_ACCESS_TYPE_H
#define INCLUDE_RIM_GRAPHICS_HARDWARE_BUFFER_ACCESS_TYPE_H


#include "rimGraphicsBuffersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Buffers Namespace  ***************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies the allowed type of access to a HardwareBuffer.
/**
  * An instance of this class is used as a hint to the GPU indicating how
  * a HardwareBuffer can be accessed. For instance, READ access allows the
  * GPU to continue to use the buffer for rendering when it is being accessed. It
  * is best to specify the minimum necessary access privilages, only use READ or
  * WRITE access unless you need to read from and write to the buffer simultaneously.
  */
class HardwareBufferAccessType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Hardware Attribute Buffer Access Type Enum Definition
			
			
			
			
			/// An enum type which specifies the type of HardwareBuffer access.
			typedef enum Enum
			{
				/// An access type which allows read-only access to a HardwareBuffer.
				READ = (1 << 0),
				
				
				/// An access type which allows write-only access to a HardwareBuffer.
				WRITE = (1 << 1),
				
				
				/// An access type which allows read and write access to a HardwareBuffer.
				READ_WRITE = READ | WRITE
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new hardware attribute buffer access type with the specified access type enum value.
			RIM_INLINE HardwareBufferAccessType( Enum newAccessType )
				:	type( newAccessType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Read/Write Status Accessor Method
			
			
			
			
			/// Return whether or not this access type object allows read access to a buffer.
			RIM_INLINE Bool canRead() const
			{
				return (type & READ) != 0;
			}
			
			
			
			
			/// Return whether or not this access type object allows write access to a buffer.
			RIM_INLINE Bool canWrite() const
			{
				return (type & WRITE) != 0;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this hardware attribute buffer access type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return (Enum)type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the hardware attribute buffer access type.
			String toString() const;
			
			
			
			
			/// Convert this hardware attribute buffer access type into a string representation.
			RIM_FORCE_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum for the hardware attribute buffer access type.
			UByte type;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Buffers Namespace  *****************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_HARDWARE_BUFFER_ACCESS_TYPE_H
