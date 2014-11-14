/*
 *  rimGraphicsMeshShape.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/30/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_MESH_SHAPE_H
#define INCLUDE_RIM_GRAPHICS_MESH_SHAPE_H


#include "rimGraphicsShapesConfig.h"


#include "rimGraphicsShapeBase.h"
#include "rimGraphicsMeshGroup.h"
#include "rimGraphicsSkeleton.h"


//##########################################################################################
//***********************  Start Rim Graphics Shapes Namespace  ****************************
RIM_GRAPHICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that represents a renderable mesh.
class MeshShape : public GraphicsShapeBase<MeshShape>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new mesh shape with no mesh groups or geometry.
			MeshShape();
			
			
			
			
			/// Create a new mesh shape with the specified vertices, indices, and material.
			MeshShape( const MeshGroup& newGroup );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mesh Group Accessor Methods
			
			
			
			
			/// Return the total number of mesh groups that are a part of this mesh shape.
			RIM_INLINE Size getGroupCount() const
			{
				return groups.getSize();
			}
			
			
			
			
			/// Return a reference to the mesh group for this mesh shape at the specified index.
			/**
			  * If an out-of-bounds index is given, an assertion is raised.
			  */
			RIM_INLINE MeshGroup& getGroup( Index groupIndex )
			{
				RIM_DEBUG_ASSERT_MESSAGE( groupIndex < groups.getSize(), "Cannot get mesh mesh group at invalid index." );
				
				return groups[groupIndex];
			}
			
			
			
			
			/// Return a reference to the mesh group for this mesh shape at the specified index.
			/**
			  * If an out-of-bounds index is given, an assertion is raised.
			  */
			RIM_INLINE const MeshGroup& getGroup( Index groupIndex ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( groupIndex < groups.getSize(), "Cannot get mesh mesh group at invalid index." );
				
				return groups[groupIndex];
			}
			
			
			
			
			/// Add a new mesh group to this mesh shape.
			/**
			  * Calling this method causes the shape's bounding sphere to be updated.
			  */
			void addGroup( const MeshGroup& newGroup );
			
			
			
			
			/// Remove the mesh group from this mesh at the specified index.
			/**
			  * If an out-of-bounds index is given, the method call is ignored.
			  *
			  * Calling this method causes the shape's bounding sphere to be updated.
			  */
			void removeGroup( Index groupIndex );
			
			
			
			
			/// Remove all mesh groups and geometry from this mesh shape.
			/**
			  * Calling this method causes the shape's bounding sphere to be updated.
			  */
			void clearGroups();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Skeleton Accessor Methods
			
			
			
			
			/// Return a pointer to the skeleton for this mesh, or NULL if it doesn't have one.
			RIM_INLINE const Pointer<Skeleton>& getSkeleton() const
			{
				return skeleton;
			}
			
			
			
			
			/// Set the skeleton for this mesh.
			RIM_INLINE void setSkeleton( const Pointer<Skeleton>& newSkeleton )
			{
				skeleton = newSkeleton;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Volume Accessor Methods
			
			
			
			
			/// Update the local-space bounding sphere for this mesh shape.
			/**
			  * This method is automatically called whenever a mesh shape is
			  * first created and anytime the mesh groups of the shape are changed.
			  * It is declared publicly so that a user can make sure that the bounding
			  * box matches the geometry (which might be shared and could changed without notice).
			  */
			virtual void updateBoundingBox();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shape Chunk Accessor Method
			
			
			
			
			/// Process the shape into a flat list of mesh chunk objects.
			/**
			  * This method flattens the shape hierarchy and produces mesh chunks
			  * for rendering from the specified camera's perspective. The method
			  * converts its internal representation into one or more MeshChunk
			  * objects which it appends to the specified output list of mesh chunks.
			  *
			  * The method returns whether or not the shape was successfully flattened
			  * into chunks.
			  */
			virtual Bool getChunks( const Transform3& worldTransform, const Camera& camera,
									const ViewVolume* viewVolume, const Vector2D<Size>& viewportSize,
									ArrayList<MeshChunk>& chunks ) const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of objects which each store a group of geometry associated with a particular material.
			ArrayList<MeshGroup> groups;
			
			
			
			
			/// A pointer to the skeleton for this mesh, or NULL if it doesn't have one.
			Pointer<Skeleton> skeleton;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_MESH_SHAPE_H
