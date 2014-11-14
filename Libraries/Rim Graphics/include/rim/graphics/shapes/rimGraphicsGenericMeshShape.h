/*
 *  rimGraphicsGenericMeshShape.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/2/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GENERIC_MESH_SHAPE_H
#define INCLUDE_RIM_GRAPHICS_GENERIC_MESH_SHAPE_H


#include "rimGraphicsShapesConfig.h"


#include "rimGraphicsShapeBase.h"
#include "rimGraphicsGenericMeshGroup.h"
#include "rimGraphicsSkeleton.h"


//##########################################################################################
//***********************  Start Rim Graphics Shapes Namespace  ****************************
RIM_GRAPHICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a generic chunk of mesh data and its associated materials.
class GenericMeshShape : public GraphicsShapeBase<GenericMeshShape>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new generic mesh with no vertex buffers or material groups.
			GenericMeshShape();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this generic mesh and release all resources that it references.
			virtual ~GenericMeshShape();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Group Accessor Methods
			
			
			
			
			/// Return the total number of groups that this mesh has.
			RIM_INLINE Size getGroupCount() const
			{
				return groups.getSize();
			}
			
			
			
			
			/// Return a reference to the mesh group at the specified index.
			/**
			  * If an out-of-bounds index is given, an assertion is raised.
			  */
			RIM_INLINE const Pointer<GenericMeshGroup>& getGroup( Index groupIndex ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( groupIndex < groups.getSize(), "Cannot get mesh material group at invalid index." );
				
				return groups[groupIndex];
			}
			
			
			
			
			/// Add a new group to this mesh.
			/**
			  * The method returns whether or not the operation was successful.
			  * The method can fail if the group's index buffer is NULL. The material is allowed to be NULL.
			  */
			Bool addGroup( const Pointer<GenericMeshGroup>& newGroup );
			
			
			
			
			/// Remove the group at the specified index from this mesh.
			/**
			  * The method returns whether or not the operation was successful.
			  * The method can fail if the specified group index is not valid.
			  */
			Bool removeGroup( Index groupIndex );
			
			
			
			
			/// Remove all groups from this mesh.
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
			
			
			
			
			/// Update the local-space bounding sphere for this generic mesh shape.
			/**
			  * This method is automatically called whenever a generic mesh shape is
			  * first created and anytime the mesh groups of the shape are changed.
			  * It is declared publicly so that a user can make sure that the bounding
			  * box matches the geometry (which might be shared and could changed without notice).
			  */
			virtual void updateBoundingBox();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the groups that this mesh uses.
			ArrayList< Pointer<GenericMeshGroup> > groups;
			
			
			
			
			/// A pointer to the skeleton for this mesh, or NULL if it doesn't have one.
			Pointer<Skeleton> skeleton;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GENERIC_MESH_SHAPE_H
