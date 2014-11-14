/*
 *  rimGraphicsOpenGLVertexBuffer.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/2/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_OPENGL_VERTEX_BUFFER_H
#define INCLUDE_RIM_GRAPHICS_OPENGL_VERTEX_BUFFER_H


#include "rimGraphicsOpenGLConfig.h"


//##########################################################################################
//********************  Start Rim Graphics Devices OpenGL Namespace  ***********************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a buffer of vertex attributes stored in GPU memory.
/**
  * This class allows attribute data to be stored in the graphics card's RAM for
  * faster access. It is analogous to the Texture class which performs the same
  * function but for pixel data.
  */
class OpenGLVertexBuffer : public VertexBuffer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructors
			
			
			
			
			/// Destroy this vertex buffer and all state associated with it.
			~OpenGLVertexBuffer();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	 Buffer Capacity Accessor Methods
			
			
			
			
			/// Set the number of bytes that this buffer is able to hold.
			virtual Bool setCapacityInBytes( Size newCapacityInBytes );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Accessor Methods
			
			
			
			
			/// Read the specified number of attributes from the vertex buffer into the specified output pointer.
			virtual Bool getAttributes( void* attributes, Size& numAttributes ) const;
			
			
			
			
			/// Replace the contents of this vertex buffer with the specified attributes.
			virtual Bool setAttributes( const void* attributes, const AttributeType& attributeType,
									Size numAttributes, HardwareBufferUsage newUsage = HardwareBufferUsage::STATIC );
			
			
			
			
			/// Update a region of this hardware attribute buffer with the specified attributes.
			virtual Bool updateAttributes( const void* attributes, const AttributeType& attributeType,
											Size numAttributes, Index startIndex = 0 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Reallocation Method
			
			
			
			
			/// Reallocate this buffer's data store using its current capacity.
			virtual Bool reallocate();
			
			
			
			
			/// Reallocate this buffer's data store using its current capacity, changing its usage type.
			virtual Bool reallocate( HardwareBufferUsage newUsage );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Mapping Methods
			
			
			
			
			/// Map this buffer's data store to the main memory address space and return a pointer to it.
			virtual void* mapBuffer( HardwareBufferAccessType accessType, Index startIndex );
			
			
			
			
			/// Unmap this buffer's data store to the main memory address space.
			virtual void unmapBuffer() const;
			
			
			
			
			/// Return whether or not this attribute buffer is currently mapped to main memory.
			virtual Bool isMapped() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Usage Accessor Method
			
			
			
			
			/// Get the current expected usage pattern for this hardware attribute buffer.
			virtual HardwareBufferUsage getUsage() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Integral Identifier Accessor Method
			
			
			
			
			/// Get a unique integral identifier for this vertex buffer.
			RIM_INLINE OpenGLID getID() const
			{
				return bufferID;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Friend Class Declaration
			
			
			
			
			/// Declare the OpenGLContext class as a friend so that it can create instances of this class.
			friend class OpenGLContext;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructors
			
			
			
			
			/// Create an empty vertex buffer with the given usage type.
			OpenGLVertexBuffer( const GraphicsContext* context, HardwareBufferUsage usageType );
			
			
			
			
			/// Create an empty vertex buffer with the given usage type, attribute type, and capacity.
			OpenGLVertexBuffer( const GraphicsContext* context, const AttributeType& attributeType,
								Size capacity, HardwareBufferUsage usageType );
			
			
			
			
			/// Create an empty vertex buffer with the type, attributes, and usage type.
			OpenGLVertexBuffer( const GraphicsContext* context, const void* attributes,
								const AttributeType& attributeType, Size capacity,
								HardwareBufferUsage usageType );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Convert the specified buffer usage to an OpenGL VBO usage enum.
			RIM_INLINE static Bool getGLUsage( HardwareBufferUsage usage, OpenGLEnum& glUsage );
			
			
			
			
			/// Convert the specified access type to an OpenGL access type enum value.
			RIM_INLINE static Bool getGLAccessType( const HardwareBufferAccessType& accessType,
													OpenGLEnum& glAccessType );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The ID used by OpenGL to uniquely identify this vertex buffer.
			OpenGLID bufferID;
			
			
			
			
			/// An object which indicates the expected usage pattern for this buffer.
			HardwareBufferUsage usage;
			
			
			
			
			/// A boolean value which indicates whether or not this buffer's data is currently mapped to main memory.
			/**
			  * If this value is TRUE, it means that the buffer's data is being iterated over
			  * and potentially read/updated and so cannot be used to draw anything.
			  */
			mutable Bool mapped;
			
			
			
};




//##########################################################################################
//********************  End Rim Graphics Devices OpenGL Namespace  *************************
RIM_GRAPHICS_DEVICES_OPENGL_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_OPENGL_VERTEX_BUFFER_H
