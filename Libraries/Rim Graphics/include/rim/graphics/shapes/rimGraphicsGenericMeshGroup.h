/*
 *  rimGraphicsGenericMeshGroup.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/2/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GENERIC_GROUP_H
#define INCLUDE_RIM_GENERIC_GROUP_H


#include "rimGraphicsShapesConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Shapes Namespace  ****************************
RIM_GRAPHICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains information about a group of geometric primitives that have the same attributes.
/**
  * Each group defines a set of vertex indices (into the vertex buffers)
  * a primitive type for the group, and a material to use when rendering
  * the group.
  */
class GenericMeshGroup
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a defalut generic mesh group with no vertex or index buffers, material.
			RIM_INLINE GenericMeshGroup()
				:	vertexBuffers(),
					indexBuffer(),
					primitiveType(),
					material()
			{
			}
			
			
			
			
			/// Create a new generic group with the specified material and index buffer pointers.
			RIM_INLINE GenericMeshGroup( const Pointer<GenericBufferList>& newVertexBuffers,
									const Pointer<GenericBuffer>& newIndexBuffer, const BufferRange& newBufferRange,
									const Pointer<GenericMaterial>& newMaterial )
				:	vertexBuffers( newVertexBuffers ),
					indexBuffer( newIndexBuffer ),
					bufferRange( newBufferRange ),
					material( newMaterial )
			{
				updateBoundingBox();
			}
			
			
			
			
			/// Create a new generic group with the specified material and index buffer pointers.
			RIM_INLINE GenericMeshGroup( const Pointer<GenericBufferList>& newVertexBuffers,
									const Pointer<GenericBuffer>& newIndexBuffer, const BufferRange& newBufferRange,
									const Pointer<GenericMaterial>& newMaterial,
									const String& newName )
				:	vertexBuffers( newVertexBuffers ),
					indexBuffer( newIndexBuffer ),
					bufferRange( newBufferRange ),
					material( newMaterial ),
					name( newName )
			{
				updateBoundingBox();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return a the name of this mesh group.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set the name of this mesh group.
			RIM_INLINE void setName( const String& newName )
			{
				name = newName;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Buffer List Accessor Methods
			
			
			
			
			/// Get the index buffer associated with this generic group.
			RIM_INLINE const Pointer<GenericBufferList>& getVertexBuffers() const
			{
				return vertexBuffers;
			}
			
			
			
			
			/// Set the index buffer associated with this generic group.
			RIM_INLINE void setVertexBuffers( const Pointer<GenericBufferList>& newVertexBuffers )
			{
				vertexBuffers = newVertexBuffers;
				updateBoundingBox();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Index Buffer Accessor Methods
			
			
			
			
			/// Get the index buffer associated with this generic group.
			RIM_INLINE const Pointer<GenericBuffer>& getIndexBuffer() const
			{
				return indexBuffer;
			}
			
			
			
			
			/// Set the index buffer associated with this generic group.
			RIM_INLINE void setIndexBuffer( const Pointer<GenericBuffer>& newIndexBuffer )
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
			
			
			
			
			/// Return a pointer to the material of this generic group.
			RIM_INLINE const Pointer<GenericMaterial>& getMaterial() const
			{
				return material;
			}
			
			
			
			
			/// Set the material of this generic group.
			RIM_INLINE void setMaterial( const Pointer<GenericMaterial>& newMaterial )
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
			
			
			
			
			/// An object representing the axis-aligned bounding box for this generic mesh group.
			AABB3 boundingBox;
			
			
			
			
			/// A pointer to a list of vertex buffer which contains the vertex data for this generic group's geometry.
			Pointer<GenericBufferList> vertexBuffers;
			
			
			
			
			/// A pointer to an index buffer which contains the indices for this generic group's geometry.
			Pointer<GenericBuffer> indexBuffer;
			
			
			
			
			/// An object representing the type of geometric primitives this group's index buffer describes.
			IndexedPrimitiveType primitiveType;
			
			
			
			
			/// A pointer to the material associated with this generic group.
			Pointer<GenericMaterial> material;
			
			
			
			
			/// A pointer to string containing a name for this generic group.
			String name;
			
			
			
			
			/// An object which describes the range of vertices or indices to use from the group's buffers.
			BufferRange bufferRange;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GENERIC_GROUP_H
