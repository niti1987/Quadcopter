/*
 *  rimGraphicsBufferRange.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 7/3/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_BUFFER_RANGE_H
#define INCLUDE_RIM_GRAPHICS_BUFFER_RANGE_H


#include "rimGraphicsBuffersConfig.h"


#include "rimGraphicsIndexedPrimitiveType.h"


//##########################################################################################
//***********************  Start Rim Graphics Buffers Namespace  ***************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies a range of primitives to render from either a vertex or index buffer.
class BufferRange
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new buffer range with the UNDEFINED primitive type and zero length.
			RIM_INLINE BufferRange()
				:	primitiveType( IndexedPrimitiveType::UNDEFINED ),
					vertexCount( 0 ),
					startIndex( 0 )
			{
			}
			
			
			
			
			/// Create a new buffer range with the specified primitive type, vertex count, and start index.
			RIM_INLINE BufferRange( const IndexedPrimitiveType& newPrimitiveType, Size newVertexCount,
									Index newStartIndex = 0 )
				:	primitiveType( newPrimitiveType ),
					vertexCount( newVertexCount ),
					startIndex( newStartIndex )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Indexed Primitive Type Accessor Methods
			
			
			
			
			/// Return an object describing the type of primitive this buffer range corresponds to.
			RIM_INLINE const IndexedPrimitiveType& getPrimitiveType() const
			{
				return primitiveType;
			}
			
			
			
			
			/// Set the type of primitive this buffer range corresponds to.
			RIM_INLINE void setPrimitiveType( const IndexedPrimitiveType& newPrimitiveType )
			{
				primitiveType = newPrimitiveType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Start Index Accessor Methods
			
			
			
			
			/// Return the start index offset within the buffer.
			RIM_INLINE Index getStartIndex() const
			{
				return startIndex;
			}
			
			
			
			
			/// Set the start index offset within the buffer.
			RIM_INLINE void setStartIndex( Index newStartIndex )
			{
				startIndex = newStartIndex;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Count Accessor Methods
			
			
			
			
			/// Return the number of vertices to draw from the buffer.
			RIM_INLINE Size getVertexCount() const
			{
				return vertexCount;
			}
			
			
			
			
			/// Set the number of vertices to draw from the buffer.
			RIM_INLINE void setVertexCount( Size newVertexCount )
			{
				vertexCount = newVertexCount;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A the type of indexed primitive this buffer range corresponds to.
			IndexedPrimitiveType primitiveType;
			
			
			
			
			/// The start index offset within the buffer.
			Index startIndex;
			
			
			
			
			/// The number of vertices to draw from the buffer.
			Size vertexCount;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Buffers Namespace  *****************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_BUFFER_RANGE_H
