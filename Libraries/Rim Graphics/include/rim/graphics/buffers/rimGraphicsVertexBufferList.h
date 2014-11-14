/*
 *  rimGraphicsVertexBufferList.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/12/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_VERTEX_BUFFER_LIST_H
#define INCLUDE_RIM_GRAPHICS_VERTEX_BUFFER_LIST_H


#include "rimGraphicsBuffersConfig.h"


#include "rimGraphicsVertexUsage.h"
#include "rimGraphicsVertexBuffer.h"


//##########################################################################################
//***********************  Start Rim Graphics Buffers Namespace  ***************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates a set of vertex buffers associated with VertexUsage types.
/**
  * This class allows the user to provide external vertex data to a ShaderPass
  * without having to modify the buffer bindings of the shader pass. This is useful when
  * a shader pass is shared among many objects that may each have different vertex
  * buffers.
  *
  * At render time, an object's vertex buffer list is used to provide vertex data
  * to the shader pass with which it is being rendered by connecting the VertexUsage
  * of each buffer with shader inputs of the same usage types.
  */
class VertexBufferList
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new empty vertex buffer list.
			VertexBufferList();
			
			
			
			
			/// Create an exact copy of the another vertex buffer list.
			VertexBufferList( const VertexBufferList& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a vertex buffer list and release all internal state.
			~VertexBufferList();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of another vertex buffer list to this one.
			VertexBufferList& operator = ( const VertexBufferList& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Buffer Accessor Methods
			
			
			
			
			/// Return the number of vertex buffers in this vertex buffer list.
			RIM_INLINE Size getBufferCount() const
			{
				return buffers.getSize();
			}
			
			
			
			
			/// Return a pointer to the buffer with the specified index in this buffer list.
			/**
			  * If an invalid index is specified, a NULL pointer is returned.
			  */
			RIM_INLINE Pointer<VertexBuffer> getBuffer( Index bufferIndex ) const
			{
				if ( bufferIndex < buffers.getSize() )
					return buffers[bufferIndex].buffer;
				else
					return Pointer<VertexBuffer>();
			}
			
			
			
			
			/// Return an object indicating the usage of the buffer with the specified index in this buffer list.
			/**
			  * If an invalid index is specified, a VertexUsage::UNDEFINED is returned.
			  */
			RIM_INLINE VertexUsage getBufferUsage( Index bufferIndex ) const
			{
				if ( bufferIndex < buffers.getSize() )
					return buffers[bufferIndex].usage;
				else
					return VertexUsage::UNDEFINED;
			}
			
			
			
			
			/// Return a pointer to the vertex buffer with the specified usage in this vertex buffer list.
			Pointer<VertexBuffer> getBufferWithUsage( const VertexUsage& usage ) const;
			
			
			
			
			/// Return whether or not there is a vertex buffer with the specified usage in this vertex buffer list.
			Bool hasBufferWithUsage( const VertexUsage& usage ) const;
			
			
			
			
			/// Add a vertex buffer with the specified usage to this vertex buffer list.
			Bool addBuffer( const Pointer<VertexBuffer>& newBuffer,
							const VertexUsage& newUsage = VertexUsage::UNDEFINED );
			
			
			
			
			/// Remove the first buffer with the specified address from this vertex buffer list.
			/**
			  * The method returns whether or not the buffer was successfully removed.
			  */
			Bool removeBuffer( const VertexBuffer* buffer );
			
			
			
			
			/// Remove the first buffer with the specified usage from this vertex buffer list.
			/**
			  * The method returns whether or not the buffer was successfully removed.
			  */
			Bool removeBuffer( const VertexUsage& usage );
			
			
			
			
			/// Clear all vertex buffers from this vertex buffer list.
			void clearBuffers();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return the smallest capacity of the buffers within this vertex buffer list.
			/**
			  * This value is computed by taking the minimum capacity of all buffers
			  * that the buffer list has which have data. If there are no buffers
			  * in the list, the method returns 0.
			  */
			Size getMinimumCapacity() const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Vertex Buffer Enry Class Definition
			
			
			
			
			/// A class which stores information about a single vertex buffer and its usage.
			class Entry
			{
				public:
					
					/// Create a new vertex buffer entry with the specified buffer and usage.
					RIM_INLINE Entry( const Pointer<VertexBuffer>& newBuffer, const VertexUsage& newUsage )
						:	usage( newUsage ),
							buffer( newBuffer )
					{
					}
					
					
					/// A pointer to the vertex buffer which this entry represents.
					Pointer<VertexBuffer> buffer;
					
					
					/// An object representing the usage of this vertex buffer.
					VertexUsage usage;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the attribute buffers that are part of this vertex buffer.
			ArrayList<Entry> buffers;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Buffers Namespace  *****************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_VERTEX_BUFFER_LIST_H
