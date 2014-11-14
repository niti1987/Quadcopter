/*
 *  rimGraphicsMeshChunk.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/23/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_MESH_CHUNK_H
#define INCLUDE_RIM_GRAPHICS_MESH_CHUNK_H


#include "rimGraphicsShapesConfig.h"


#include "rimGraphicsSkeleton.h"


//##########################################################################################
//***********************  Start Rim Graphics Shapes Namespace  ****************************
RIM_GRAPHICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains all information needed to draw a chunk of geometry.
/**
  * A MeshChunk is used as a intermediate universal data format which should work
  * for almost any rendering technique. It contains a pointer to a vertex buffer,
  * an optional index buffer pointer, a range of elements to draw, an object-to-world-
  * space transformation matrix, and a material for the specified geometry.
  *
  * If an index buffer is specified, the range of elements to draw refers to the index
  * range which should be drawn. If no index buffer is provided, the range refers to the
  * range of vertices which should be drawn from the vertex buffer.
  */
class MeshChunk
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a mesh chunk with no data.
			RIM_FORCE_INLINE MeshChunk()
				:	transformation(),
					boundingBox(),
					vertexBuffers( NULL ),
					indexBuffer( NULL ),
					material( NULL ),
					skeleton( NULL ),
					bufferRange()
			{
			}
			
			
			
			
			/// Create an indexed mesh chunk which uses the specified range of indices.
			RIM_FORCE_INLINE MeshChunk( const Matrix4& newTransform, const AABB3& newBoundingBox,
										const Material* newMaterial, const Skeleton* newSkeleton,
										const VertexBufferList* newVertexBuffers, const IndexBuffer* newIndices,
										const BufferRange& newBufferRange )
				:	transformation( newTransform ),
					boundingBox( newBoundingBox ),
					vertexBuffers( newVertexBuffers ),
					indexBuffer( newIndices ),
					material( newMaterial ),
					skeleton( newSkeleton ),
					bufferRange( newBufferRange )
			{
			}
			
			
			
			
			/// Create a non-indexed mesh chunk which uses the specified range of vertices.
			RIM_FORCE_INLINE MeshChunk( const Matrix4& newTransform, const AABB3& newBoundingBox,
										const Material* newMaterial, const Skeleton* newSkeleton,
										const VertexBufferList* newVertexBuffers,
										const BufferRange& newBufferRange )
				:	transformation( newTransform ),
					boundingBox( newBoundingBox ),
					vertexBuffers( newVertexBuffers ),
					indexBuffer( NULL ),
					material( newMaterial ),
					skeleton( newSkeleton ),
					bufferRange( newBufferRange )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Buffer Accessor Methods
			
			
			
			
			/// Return whether or not there is a vertex buffer list associated with this mesh chunk.
			RIM_FORCE_INLINE Bool hasVertexBuffers() const
			{
				return vertexBuffers != NULL;
			}
			
			
			
			
			/// Return a pointer to the vertex buffer list for this mesh chunk.
			RIM_FORCE_INLINE const VertexBufferList* getVertexBuffers() const
			{
				return vertexBuffers;
			}
			
			
			
			
			/// Set a pointer to the vertex buffers for this mesh chunk.
			RIM_FORCE_INLINE void setVertexBuffers( const VertexBufferList* newVertexBuffers )
			{
				vertexBuffers = newVertexBuffers;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Index Buffer Accessor Methods
			
			
			
			
			/// Return whether or not there is an index buffer associated with this mesh chunk.
			/**
			  * If this method returns FALSE, it means that the mesh chunk should
			  * use the in-order vertices in the vertex buffer when it is drawn.
			  * Otherwise, the index buffer is used to index into the vertex buffer
			  * for the chunk's range of elements.
			  */
			RIM_FORCE_INLINE Bool hasIndexBuffer() const
			{
				return indexBuffer != NULL;
			}
			
			
			
			
			/// Return a pointer to the index buffer for this mesh chunk.
			/**
			  * If this method returns NULL, it means that the mesh chunk should
			  * use the in-order vertices in the vertex buffer when it is drawn.
			  * Otherwise, the index buffer is used to index into the vertex buffer
			  * for the chunk's range of elements.
			  */
			RIM_FORCE_INLINE const IndexBuffer* getIndexBuffer() const
			{
				return indexBuffer;
			}
			
			
			
			
			/// Set a pointer to the index buffer for this mesh chunk.
			RIM_FORCE_INLINE void setIndexBuffer( const IndexBuffer* newIndexBuffer )
			{
				indexBuffer = newIndexBuffer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Range Accessor Methods
			
			
			
			
			/// Return a reference to the buffer range for this mesh chunk.
			/**
			  * If the mesh chunk has an index buffer, the valid range refers to the indices
			  * which should be used when drawing the chunk. Otherwise, the range refers
			  * to the valid contiguous range of vertices to use.
			  */
			RIM_FORCE_INLINE const BufferRange& getBufferRange() const
			{
				return bufferRange;
			}
			
			
			
			
			/// Set the buffer range for this mesh chunk.
			/**
			  * If the mesh chunk has an index buffer, the valid range refers to the indices
			  * which should be used when drawing the chunk. Otherwise, the range refers
			  * to the valid contiguous range of vertices to use.
			  */
			RIM_FORCE_INLINE void setBufferRange( const BufferRange& newBufferRange )
			{
				bufferRange = newBufferRange;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Material Accessor Methods
			
			
			
			
			/// Return whether or not this mesh chunk has a material associated with it.
			RIM_FORCE_INLINE Bool hasMaterial() const
			{
				return material != NULL;
			}
			
			
			
			
			/// Return a pointer to the material which should be used to render this mesh chunk.
			/**
			  * If the method returns NULL, the renderer can either choose to use a default
			  * material when rendering the chunk or can skip the chunk entirely.
			  */
			RIM_FORCE_INLINE const Material* getMaterial() const
			{
				return material;
			}
			
			
			
			
			/// Set a pointer to the material which should be used to render this mesh chunk.
			RIM_FORCE_INLINE void setMaterial( const Material* newMaterial )
			{
				material = newMaterial;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Skeleton Accessor Methods
			
			
			
			
			/// Return whether or not this mesh chunk has a skeleton associated with it.
			RIM_FORCE_INLINE Bool hasSkeleton() const
			{
				return skeleton != NULL;
			}
			
			
			
			
			/// Return a pointer to the skeleton which should be used to render this mesh chunk, or NULL if there is none.
			RIM_FORCE_INLINE const Skeleton* getSkeleton() const
			{
				return skeleton;
			}
			
			
			
			
			/// Set a pointer to the skeleton which should be used to render this mesh chunk.
			RIM_FORCE_INLINE void setSkeleton( const Skeleton* newSkeleton )
			{
				skeleton = newSkeleton;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Sphere Accessor Methods
			
			
			
			
			/// Return a 4x4 matrix representing the homogeneous coordinate transform from the mesh's object to world space.
			RIM_FORCE_INLINE const Matrix4& getTransformMatrix() const
			{
				return transformation;
			}
			
			
			
			
			/// Set a 4x4 matrix representing the homogeneous coordinate transform from the mesh's object to world space.
			RIM_FORCE_INLINE void setTransformMatrix( const Matrix4& newTransform )
			{
				transformation = newTransform;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Volume Accessor Methods
			
			
			
			
			/// Return a reference to a bounding box for this mesh chunk in world space.
			RIM_FORCE_INLINE const AABB3& getBoundingBox() const
			{
				return boundingBox;
			}
			
			
			
			
			/// Return a reference to a bounding box for this mesh chunk in world space.
			RIM_FORCE_INLINE void setBoundingBox( const AABB3& newBoundingBox )
			{
				boundingBox = newBoundingBox;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A 4x4 transformation matrix which transforms from mesh to world space.
			Matrix4 transformation;
			
			
			
			
			/// The bounding box of this mesh chunk in world space.
			AABB3 boundingBox;
			
			
			
			
			/// A pointer to the vertex buffer list which this mesh chunk uses to describe its vertices.
			const VertexBufferList* vertexBuffers;
			
			
			
			
			/// A pointer to the index buffer which this mesh chunk uses to describe primitives.
			const IndexBuffer* indexBuffer;
			
			
			
			
			/// The material which should be used to render this mesh chunk.
			const Material* material;
			
			
			
			
			/// The skeleton which should be used to render this mesh chunk.
			const Skeleton* skeleton;
			
			
			
			
			/// An object describing the range of indices or vertices to use from the mesh chunk's buffers.
			BufferRange bufferRange;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_MESH_CHUNK_H
