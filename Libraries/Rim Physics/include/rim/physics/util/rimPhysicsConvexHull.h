/*
 *  rimPhysicsConvexHull.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 9/3/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_CONVEX_HULL_H
#define INCLUDE_RIM_PHYSICS_CONVEX_HULL_H


#include "rimPhysicsUtilitiesConfig.h"


#include "rimPhysicsVertex.h"


//##########################################################################################
//**********************  Start Rim Physics Utilities Namespace  ***************************
RIM_PHYSICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a convex polyhedron with triangular faces.
class ConvexHull
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Class Declarations
			
			
			
			
			/// A class which represents a vertex on a convex hull.
			class Vertex;
			
			
			
			
			/// A class which represents a triangle on the surface of a polyhedral convex hull.
			class Triangle;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an empty convex hull with no triangles or vertices.
			ConvexHull();
			
			
			
			
			/// Create a convex hull from the specified array of input vertices.
			ConvexHull( const PhysicsVertex3* inputVertices, Size numVertices );
			
			
			
			
			/// Create a convex hull from the specified list of input vertices.
			ConvexHull( const ArrayList<PhysicsVertex3>& inputVertices );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Triangle Accessor Methods
			
			
			
			
			/// Return the number of triangles that define the surface of this convex hull.
			RIM_FORCE_INLINE Size getTriangleCount() const
			{
				return triangles.getSize();
			}
			
			
			
			
			/// Return a const reference to the convex hull triangle at the specified index.
			RIM_FORCE_INLINE const Triangle& getTriangle( Index index ) const
			{
				return triangles[index];
			}
			
			
			
			
			/// Return an array of the three triangle neighbor indices for the triangle at the specified index.
			StaticArray<Index,3> getTriangleNeighbors( Index index ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Accessor Methods
			
			
			
			
			/// Return the number of vertices that are on the surface of this convex hull.
			RIM_FORCE_INLINE Size getVertexCount() const
			{
				return vertices.getSize();
			}
			
			
			
			
			/// Return a reference to the vertex on this convex hull at the specified index.
			RIM_FORCE_INLINE const Vertex& getVertex( Index index ) const
			{
				return vertices[index];
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Triangle Accessor Methods
			
			
			
			
			/// Return the number of triangles which share the specified vertex.
			RIM_FORCE_INLINE Size getVertexTriangleCount( Index vertexIndex ) const;
			
			
			
			
			/// Return a const reference to the triange sharing the specified vertex at the given index.
			RIM_FORCE_INLINE const Triangle& getVertexTriangle( Index vertexIndex, Index triangleIndex ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Supporting Vertex Accessor Method
			
			
			
			
			/// Determine which vertex on this convex hull is farthest in the specified direction.
			/**
			  * This method uses the optional starting vertex as a best-guess for the
			  * supporting vertex. The hull then uses a 'hill-climbing' algorithm to find the
			  * actual supporting vertex in the specified direction. The direction does not
			  * need to be normalized. The index of the support vertex is returned.
			  *
			  * If the convex hull has no vertices, math::max<Index>() is returned.
			  */
			Index getSupportVertexIndex( const Vector3& direction, Index startingVertex = 0 ) const;
			
			
			
			
			/// Determine which vertex on this convex hull is farthest in the specified direction.
			/**
			  * This method uses the optional starting vertex as a best-guess for the
			  * supporting vertex. The hull then uses a 'hill-climbing' algorithm to find the
			  * actual supporting vertex in the specified direction. The direction does not
			  * need to be normalized. The position of the support vertex is returned.
			  *
			  * If the convex hull has no vertices, the origin is returned.
			  */
			RIM_INLINE const PhysicsVertex3& getSupportVertex( const Vector3& direction, Index startingVertex = 0 ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Sphere Accessor Methods
			
			
			
			
			/// Compute and return a bounding sphere for this convex hull.
			BoundingSphere computeBoundingSphere() const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which holds extra data about vertices, used during hull construction.
			class VertexData;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Convex Hull Computation Method
			
			
			
			
			/// Compute the convex hull of the specified list of input vertices.
			/**
			  * The method places the resulting convex hull vertices and triangles
			  * into the two output lists.
			  *
			  * This method can fail if less than 4 vertices are used as input, or
			  * if all of the vertices are coplanar. In these cases, FALSE is returned.
			  * Otherwise, TRUE is returned indicating that convex hull computation was
			  * successful.
			  */
			static Bool computeConvexHull( const Vector3* vertices, Size numVertices,
											ArrayList<Vertex>& hullVertices, 
											ArrayList<Triangle>& triangles, 
											ArrayList<Index>& vertexTriangles );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of all of the vertices that are on the boundary of this convex hull.
			ArrayList<Vertex> vertices;
			
			
			
			
			/// A list of all of the triangles that are on the boundary of this convex hull.
			ArrayList<Triangle> triangles;
			
			
			
			
			/// A list of triangle indices that are shared by various vertices in the convex hull.
			ArrayList<Index> vertexTriangles;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Convex Hull Vertex Class Declaration
//############		
//##########################################################################################
//##########################################################################################




class ConvexHull:: Vertex
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// Create a new convex hull vertex with the specified position and no connecting triangles.
			RIM_INLINE Vertex( const PhysicsVertex3& newPosition )
				:	position( newPosition ),
					triangleListStartIndex( 0 ),
					numTriangles( 0 )
			{
			}
			
			
			
			
			/// Create a new convex hull vertex with the specified position and index into the triangle neighbor list.
			RIM_INLINE Vertex( const PhysicsVertex3& newPosition, Index trianglesStart, Size newNumTriangles )
				:	position( newPosition ),
					triangleListStartIndex( trianglesStart ),
					numTriangles( newNumTriangles )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Accessor Methods
			
			
			
			
			/// Return a const reference to the 3D position of this convex hull vertex.
			RIM_FORCE_INLINE const PhysicsVertex3& getPosition() const
			{
				return position;
			}
			
			
			
			
			/// Return the number of triangles that share this convex hull vertex.
			RIM_FORCE_INLINE Size getTriangleCount() const
			{
				return numTriangles;
			}
			
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The position of this convex hull vertex.
			PhysicsVertex3 position;
			
			
			
			
			/// The starting index of this vertex's list of neighboring triangles in the convex hull's neighbor list.
			Index triangleListStartIndex;
			
			
			
			
			/// The number of triangles that share this convex hull vertex.
			Size numTriangles;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Friend Class Declaration
			
			
			
			
			/// Declare the convex hull class as a friend so that it can access necessary data without exposing it in the interface.
			friend class ConvexHull;
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Convex Hull Triangle Class Declaration
//############		
//##########################################################################################
//##########################################################################################




class ConvexHull:: Triangle
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// Create a new convex hull triangle with the specified vertex indices and plane.
			RIM_INLINE Triangle( Index newV1, Index newV2, Index newV3, const Plane3& newPlane )
				:	v1( newV1 ),
					v2( newV2 ),
					v3( newV3 ),
					plane( newPlane )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Accessor Methods
			
			
			
			
			/// Return the index of the vertex at the specified index in this triangle.
			/**
			  * Valid vertex indices are 0, 1, or 2.
			  */
			RIM_FORCE_INLINE Index getVertexIndex( Index index ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( index < 3, "Cannot access invalid vertex index for convex hull triangle." );
				
				return (&v1)[index];
			}
			
			
			
			
			/// Return a const reference to the 3D plane of this convex hull triangles.
			RIM_FORCE_INLINE const Plane3& getPlane() const
			{
				return plane;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Attribute Accessor Methods
			
			
			
			
			/// Set the index of the vertex at the specified index in this triangle.
			/**
			  * Valid vertex indices are 0, 1, or 2.
			  */
			RIM_FORCE_INLINE void setVertexIndex( Index v, Index newIndex )
			{
				RIM_DEBUG_ASSERT_MESSAGE( v < 3, "Cannot access invalid vertex index for convex hull triangle." );
				
				(&v1)[v] = newIndex;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The index of the first vertex that defines a corner of this triangle.
			Index v1;
			
			
			
			
			/// The index of the second vertex that defines a corner of this triangle.
			Index v2;
			
			
			
			
			/// The index of the third vertex that defines a corner of this triangle.
			Index v3;
			
			
			
			
			/// An object representing the 3D plane that this triangle lies in.
			Plane3 plane;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Friend Class Declaration
			
			
			
			
			/// Declare the convex hull class as a friend so that it can access necessary data without exposing it in the interface.
			friend class ConvexHull;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Vertex Triangle Accessor Methods
//############		
//##########################################################################################
//##########################################################################################




Size ConvexHull:: getVertexTriangleCount( Index vertexIndex ) const
{
	return vertices[vertexIndex].getTriangleCount();
}




const ConvexHull::Triangle& ConvexHull:: getVertexTriangle( Index vertexIndex, Index triangleIndex ) const
{
	return triangles[vertexTriangles[vertices[vertexIndex].triangleListStartIndex + triangleIndex]];
}




//##########################################################################################
//##########################################################################################
//############		
//############		Support Vertex Accessor Method
//############		
//##########################################################################################
//##########################################################################################




const PhysicsVertex3& ConvexHull:: getSupportVertex( const Vector3& direction, Index startingVertex ) const
{
	Index supportIndex = this->getSupportVertexIndex( direction, startingVertex );
	
	if ( supportIndex < vertices.getSize() )
		return vertices[supportIndex].getPosition();
	else
		return PhysicsVertex3::ZERO;
}




//##########################################################################################
//**********************  End Rim Physics Utilities Namespace  *****************************
RIM_PHYSICS_UTILITES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_CONVEX_HULL_H
