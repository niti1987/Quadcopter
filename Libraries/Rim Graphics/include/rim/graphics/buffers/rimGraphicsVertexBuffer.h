/*
 *  rimGraphicsVertexBuffer.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/10/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_VERTEX_BUFFER_H
#define INCLUDE_RIM_GRAPHICS_VERTEX_BUFFER_H


#include "rimGraphicsBuffersConfig.h"


#include "rimGraphicsHardwareBuffer.h"


//##########################################################################################
//***********************  Start Rim Graphics Buffers Namespace  ***************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A type of HardwareBuffer which is used for specifying vertex attributes.
class VertexBuffer : public HardwareBuffer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an empty vertex buffer for the specified context.
			RIM_INLINE VertexBuffer( const devices::GraphicsContext* context )
				:	HardwareBuffer( context, HardwareBufferType::VERTEX_BUFFER )
			{
			}
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Buffers Namespace  *****************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_VERTEX_BUFFER_H
