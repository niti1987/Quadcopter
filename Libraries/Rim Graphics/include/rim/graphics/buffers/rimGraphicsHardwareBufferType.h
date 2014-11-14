/*
 *  rimGraphicsHardwareBufferType.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 1/27/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_HARDWARE_BUFFER_TYPE_H
#define INCLUDE_RIM_GRAPHICS_HARDWARE_BUFFER_TYPE_H


#include "rimGraphicsBuffersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Buffers Namespace  ***************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies a kind of HardwareBuffer.
/**
  * The type specified here is used to determine the kinds of elements that a hardware
  * attribute buffer can hold and how it can be used.
  */
class HardwareBufferType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Attribute Buffer Usage Enum Definition
			
			
			
			
			/// An enum type which represents the type for a hardware attribute buffer.
			typedef enum Enum
			{
				/// An attribute buffer that can have any vertex attribute type for its elements.
				VERTEX_BUFFER = 1,
				
				/// An attribute buffer that can only have index types for its elements.
				INDEX_BUFFER = 2
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new hardware attribute buffer type with the specified usage enum value.
			RIM_INLINE HardwareBufferType( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this hardware attribute buffer type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return (Enum)type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Valid Attribute Type Method
			
			
			
			
			/// Return whether or not the specified attribute type is a valid type for this buffer type.
			Bool supportsAttributeType( const AttributeType& attributeType ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the hardware attribute buffer type.
			String toString() const;
			
			
			
			
			/// Convert this hardware attribute buffer type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum for the hardware attribute buffer type.
			UByte type;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Buffers Namespace  *****************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_HARDWARE_BUFFER_TYPE_H
