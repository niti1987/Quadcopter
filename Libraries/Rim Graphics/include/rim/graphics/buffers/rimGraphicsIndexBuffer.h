/*
 *  rimGraphicsIndexBuffer.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/10/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_INDEX_BUFFER_H
#define INCLUDE_RIM_GRAPHICS_INDEX_BUFFER_H


#include "rimGraphicsBuffersConfig.h"


#include "rimGraphicsHardwareBuffer.h"
#include "rimGraphicsIndexedPrimitiveType.h"


//##########################################################################################
//***********************  Start Rim Graphics Buffers Namespace  ***************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A type of HardwareBuffer which is used for specifying indexed geometric primitives.
/**
  * An IndexBuffer allows the user to specify the type of primitive specified (default, triangles),
  * as well as the way in which the buffer will be used (default, static).
  */
class IndexBuffer : public HardwareBuffer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an empty index buffer for the specified context.
			RIM_INLINE IndexBuffer( const devices::GraphicsContext* context )
				:	HardwareBuffer( context, HardwareBufferType::INDEX_BUFFER )
			{
			}
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Buffers Namespace  *****************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_INDEX_BUFFER_H
