/*
 *  rimPhysicsCollisionShapeMesh.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 7/6/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_MESH_H
#define INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_MESH_H


#include "rimPhysicsShapesConfig.h"


#include "rimPhysicsCollisionShape.h"
#include "rimPhysicsCollisionShapeBase.h"
#include "rimPhysicsCollisionShapeInstance.h"


//##########################################################################################
//************************  Start Rim Physics Shapes Namespace  ****************************
RIM_PHYSICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents an triangle-soup mesh collision shape.
class CollisionShapeMesh : public CollisionShapeBase<CollisionShapeMesh>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Declarations
			
			
			
			
			class Instance;
			
			
			
			
			/// Define the type of BVH acceleration structure to use for this mesh collision shape.
			typedef AABBTree4 BVHType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default empty mesh shape with no vertices or triangles.
			CollisionShapeMesh();
			
			
			
			
			/// Create a mesh shape with the specified vertices, triangles, and materials.
			CollisionShapeMesh( const PhysicsVertex3* vertices, Size numVertices,
								const PhysicsTriangle* triangles, Size numTriangles,
								const CollisionShapeMaterial* materials, Size numMaterials );
			
			
			
			
			/// Create a mesh shape with the specified vertices, triangles, and materials.
			CollisionShapeMesh( const ArrayList<PhysicsVertex3>& vertices,
								const ArrayList<PhysicsTriangle>& triangles,
								const ArrayList<CollisionShapeMaterial>& materials );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Accessor Methods
			
			
			
			
			/// Return the vertex at the specified index in this mesh shape.
			RIM_INLINE const PhysicsVertex3& getVertex( Index vertexIndex ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( vertexIndex < vertices.getSize(),
							"Cannot access vertex at invalid index in a mesh collision shape." );
				
				return vertices[vertexIndex];
			}
			
			
			
			
			/// Return the number of vertices that this mesh shape contains.
			RIM_INLINE Size getVertexCount() const
			{
				return vertices.getSize();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Triangle Accessor Methods
			
			
			
			
			/// Return the triangle at the specified index in this mesh shape.
			RIM_INLINE const PhysicsTriangle& getTriangle( Index triangleIndex ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( triangleIndex < triangles.getSize(),
							"Cannot access triangle at invalid index in a mesh collision shape." );
				
				return triangles[triangleIndex];
			}
			
			
			
			
			/// Return the number of triangles that this mesh shape contains.
			RIM_INLINE Size getTriangleCount() const
			{
				return triangles.getSize();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Material Accessor Methods
			
			
			
			
			/// Return the material at the specified index in this mesh shape.
			RIM_INLINE const CollisionShapeMaterial& getMaterial( Index materialIndex ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( materialIndex < materials.getSize(),
							"Cannot access material at invalid index in a mesh collision shape." );
				
				return materials[materialIndex];
			}
			
			
			
			
			/// Return the number of materials that this mesh shape contains.
			RIM_INLINE Size getMaterialCount() const
			{
				return materials.getSize();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	BVH Accessor Methods
			
			
			
			
			/// Return a pointer to this mesh collision shape's bounding volume hierarchy.
			/**
			  * If this mesh has no geometry or invalid geometry, NULL is returned indicating
			  * that the mesh has no BVH.
			  */
			RIM_FORCE_INLINE const BVHType* getBVH() const
			{
				return bvh;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mass Distribution Accessor Methods
			
			
			
			
			/// Return a 3x3 matrix for the inertia tensor of this mesh shape relative to its center of mass.
			/**
			  * The returned inertia tensor for this mesh shape will always be a matrix
			  * with infinite inertial values because the mesh has no mass.
			  */
			virtual Matrix3 getInertiaTensor() const;
			
			
			
			
			/// Return a 3D vector representing the center-of-mass of this mesh shape in its coordinate frame.
			/**
			  * Since a mesh shape has no mass or center, the returned center of mass is the projection of
			  * the origin onto the mesh.
			  */
			virtual Vector3 getCenterOfMass() const;
			
			
			
			
			/// Return the volume of this mesh shape in length units cubed (m^3).
			/**
			  * This method always returns 0 because a mesh has no volume.
			  */
			virtual Real getVolume() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Instance Creation Methods
			
			
			
			
			/// Create and return an instance of this shape.
			virtual Pointer<CollisionShapeInstance> getInstance() const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which creates axis-aligned bounding boxes for PhysicsTriangle objects.
			class PhysicsTriangleAABBGenerator;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Update the bounding sphere and mass quantities of this mesh collision shape.
			void updateDependentQuantities();
			
			
			
			
			/// Rebuild the BVH for this mesh shape.
			void rebuildBVH();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of all of the triangles in this mesh collision shape.
			ArrayList<PhysicsTriangle> triangles;
			
			
			
			
			/// A list of all of the vertices in this mesh collision shape.
			ArrayList<PhysicsVertex3> vertices;
			
			
			
			
			/// A list of all of the collision materials in this mesh collision shape.
			ArrayList<CollisionShapeMaterial> materials;
			
			
			
			
			/// A bounding volume hierarchy for this mesh shape's trianges to accelerate collision detection.
			BVHType* bvh;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Mesh Shape Instance Class Definition
//############		
//##########################################################################################
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which is used to instance a CollisionShapeMesh object with an arbitrary rigid transformation.
class CollisionShapeMesh:: Instance : public CollisionShapeInstance
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transform Update Method
			
			
			
			
			/// Update this mesh instance with the specified 3D rigid transformation from shape to world space.
			/**
			  * This method transforms this instance's mesh equation from shape space to world space.
			  */
			virtual void setTransform( const Transform3& newTransform );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Accessor Methods
			
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructors
			
			
			
			
			/// Create a new mesh shape instance which uses the specified base mesh shape.
			RIM_INLINE Instance( const CollisionShapeMesh* newMesh )
				:	CollisionShapeInstance( newMesh )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The transformation from shape-space to world space for this mesh shape instance.
			Transform3 transformation;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Declarations
			
			
			
			
			/// Declare the mesh collision shape as a friend so that it can construct instances.
			friend class CollisionShapeMesh;
			
			
};




//##########################################################################################
//************************  End Rim Physics Shapes Namespace  ******************************
RIM_PHYSICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_MESH_H
