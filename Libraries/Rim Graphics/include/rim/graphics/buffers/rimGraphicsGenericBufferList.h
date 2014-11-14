/*
 *  rimGraphicsGenericBufferList.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 11/28/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GENERIC_BUFFER_LIST_H
#define INCLUDE_RIM_GRAPHICS_GENERIC_BUFFER_LIST_H


#include "rimGraphicsBuffersConfig.h"


#include "rimGraphicsGenericBuffer.h"
#include "rimGraphicsVertexUsage.h"


//##########################################################################################
//***********************  Start Rim Graphics Buffers Namespace  ***************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates a set of generic buffers associated with VertexUsage types.
/**
  * This class allows the user to provide external vertex data to a ShaderPass
  * without having to modify the buffer bindings of the shader pass. This is useful when
  * a shader pass is shared among many objects that may each have different vertex
  * buffers.
  *
  * At render time, an object's generic buffer list is used to provide vertex data
  * to the shader pass with which it is being rendered by connecting the VertexUsage
  * of each buffer with shader inputs of the same usage types.
  */
class GenericBufferList
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new empty generic buffer list.
			GenericBufferList();
			
			
			
			
			/// Create an exact copy of the another generic buffer list.
			GenericBufferList( const GenericBufferList& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a generic buffer list and release all internal state.
			~GenericBufferList();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of another generic buffer list to this one.
			GenericBufferList& operator = ( const GenericBufferList& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Buffer Accessor Methods
			
			
			
			
			/// Return the number of generic buffers in this generic buffer list.
			RIM_INLINE Size getBufferCount() const
			{
				return buffers.getSize();
			}
			
			
			
			
			/// Return a pointer to the buffer with the specified index in this buffer list.
			/**
			  * If an invalid index is specified, a NULL pointer is returned.
			  */
			RIM_INLINE Pointer<GenericBuffer> getBuffer( Index bufferIndex ) const
			{
				if ( bufferIndex < buffers.getSize() )
					return buffers[bufferIndex].buffer;
				else
					return Pointer<GenericBuffer>();
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
			
			
			
			
			/// Return a pointer to the generic buffer with the specified usage in this generic buffer list.
			Pointer<GenericBuffer> getBufferWithUsage( const VertexUsage& usage ) const;
			
			
			
			
			/// Return whether or not there is a generic buffer with the specified usage in this generic buffer list.
			Bool hasBufferWithUsage( const VertexUsage& usage ) const;
			
			
			
			
			/// Add a generic buffer with the specified usage to this generic buffer list.
			Bool addBuffer( const Pointer<GenericBuffer>& newBuffer,
							const VertexUsage& newUsage = VertexUsage::UNDEFINED );
			
			
			
			
			/// Add a generic buffer with the specified name and usage to this generic buffer list.
			Bool addBuffer( const Pointer<GenericBuffer>& newBuffer, const String& newName,
							const VertexUsage& newUsage );
			
			
			
			
			/// Remove the first buffer with the specified address from this generic buffer list.
			/**
			  * The method returns whether or not the buffer was successfully removed.
			  */
			Bool removeBuffer( const GenericBuffer* buffer );
			
			
			
			
			/// Remove the first buffer with the specified usage from this generic buffer list.
			/**
			  * The method returns whether or not the buffer was successfully removed.
			  */
			Bool removeBuffer( const VertexUsage& usage );
			
			
			
			
			/// Clear all generic buffers from this generic buffer list.
			void clearBuffers();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return the smallest capacity of the buffers within this generic buffer list.
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
			
			
			
			
			/// A class which stores information about a single generic buffer and its usage.
			class Entry
			{
				public:
					
					/// Create a new generic buffer entry with the specified buffer and usage.
					RIM_INLINE Entry( const Pointer<GenericBuffer>& newBuffer, const VertexUsage& newUsage )
						:	usage( newUsage ),
							buffer( newBuffer ),
							name()
					{
					}
					
					/// Create a new generic buffer entry with the specified buffer and usage.
					RIM_INLINE Entry( const Pointer<GenericBuffer>& newBuffer, const String& newName,
									const VertexUsage& newUsage )
						:	usage( newUsage ),
							buffer( newBuffer ),
							name( Pointer<String>::construct( newName ) )
					{
					}
					
					
					/// An object representing the usage of this buffer.
					VertexUsage usage;
					
					
					/// A pointer to the buffer which this entry represents.
					Pointer<GenericBuffer> buffer;
					
					
					/// A pointer to a string representing the name of this buffer list entry.
					Pointer<String> name;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the buffers that are part of this generic buffer.
			ArrayList<Entry> buffers;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Buffers Namespace  *****************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GENERIC_BUFFER_LIST_H
