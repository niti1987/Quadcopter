/*
 *  rimGraphicsMeshGroup.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 9/14/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_MESH_GROUP_H
#define INCLUDE_RIM_GRAPHICS_MESH_GROUP_H


#include "rimGraphicsShapesConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Shapes Namespace  ****************************
RIM_GRAPHICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates geometry and a material with which it should be rendered.
/**
  * A MeshGroup specifies its geometry relative to the origin of its parent
  * shape and does not have its own transformation.
  */
class MeshGroup
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new mesh group with the specified material and vertex buffer pointers.
			MeshGroup( const Pointer<VertexBufferList>& newVertexBuffers,
						const Pointer<IndexBuffer>& newIndexBuffer, const BufferRange& newBufferRange,
						const Pointer<Material>& newMaterial );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Buffer List Accessor Methods
			
			
			
			
			/// Get the index buffer associated with this mesh group.
			RIM_INLINE const Pointer<VertexBufferList>& getVertexBuffers() const
			{
				return vertexBuffers;
			}
			
			
			
			
			/// Set the index buffer associated with this mesh group.
			RIM_INLINE void setVertexBuffers( const Pointer<VertexBufferList>& newVertexBuffers )
			{
				vertexBuffers = newVertexBuffers;
				updateBoundingBox();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Index Buffer Accessor Methods
			
			
			
			
			/// Get the index buffer associated with this mesh group.
			RIM_INLINE const Pointer<IndexBuffer>& getIndexBuffer() const
			{
				return indexBuffer;
			}
			
			
			
			
			/// Set the index buffer associated with this mesh group.
			RIM_INLINE void setIndexBuffer( const Pointer<IndexBuffer>& newIndexBuffer )
			{
				indexBuffer = newIndexBuffer;
				updateBoundingBox();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Range Accessor Methods
			
			
			
			
			/// Return a reference to the buffer range for this mesh group.
			/**
			  * If the mesh group has an index buffer, the valid range refers to the indices
			  * which should be used when drawing the group. Otherwise, the range refers
			  * to the valid contiguous range of vertices to use.
			  */
			RIM_FORCE_INLINE const BufferRange& getBufferRange() const
			{
				return bufferRange;
			}
			
			
			
			
			/// Set the buffer range for this mesh group.
			/**
			  * If the mesh group has an index buffer, the valid range refers to the indices
			  * which should be used when drawing the group. Otherwise, the range refers
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
			
			
			
			
			/// Return a pointer to the material of this mesh group.
			RIM_INLINE const Pointer<Material>& getMaterial() const
			{
				return material;
			}
			
			
			
			
			/// Set the material of this mesh group.
			RIM_INLINE void setMaterial( const Pointer<Material>& newMaterial )
			{
				material = newMaterial;
				updateBoundingBox();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Box Accessor Methods
			
			
			
			
			/// Return a reference to the bounding box for this mesh group.
			/**
			  * The bounding box returned here may not represent an accurate bounding volume for the
			  * mesh group if any of the underlying geometry changes without notice. If this
			  * occurs, call the updateBoundingBox() method directly to force an update
			  * of the bounding box.
			  */
			RIM_FORCE_INLINE const AABB3& getBoundingBox() const
			{
				return boundingBox;
			}
			
			
			
			
			/// Force an update the bounding box for this mesh group.
			/**
			  * This method is automatically called whenever a mesh group is
			  * first created and anytime the vertex or index buffer of a
			  * group is changed. It is declared publicly so that a user can make
			  * sure that the bounding box matches the geometry (which might be
			  * shared and could changed without notice).
			  */
			void updateBoundingBox();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object representing the axis-aligned bounding box for this mesh group.
			AABB3 boundingBox;
			
			
			
			
			/// A pointer to a list of vertex buffer which contains the vertex data for this mesh group's geometry.
			Pointer<VertexBufferList> vertexBuffers;
			
			
			
			
			/// A pointer to an index buffer which contains the indices for this mesh group's geometry.
			Pointer<IndexBuffer> indexBuffer;
			
			
			
			
			/// A pointer to the material associated with this mesh group.
			Pointer<Material> material;
			
			
			
			
			/// An object which describes the range of vertices or indices to use from the group's buffers.
			BufferRange bufferRange;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_MESH_GROUP_H
