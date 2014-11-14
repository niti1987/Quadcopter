/*
 *  rimPhysicsEPASolver.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 9/3/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_EPA_SOLVER_H
#define INCLUDE_RIM_PHYSICS_EPA_SOLVER_H


#include "rimPhysicsUtilitiesConfig.h"


#include "rimPhysicsMinkowskiVertex.h"
#include "rimPhysicsEPAResult.h"


//##########################################################################################
//**********************  Start Rim Physics Utilities Namespace  ***************************
RIM_PHYSICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which iteratively refines a GJK simplex to approximate the shape surface at the collision point.
/**
  * Since the output of the GJKSolver is just a simplex containing the origin,
  * without any contact information, the EPASolver class refines that simplex so that
  * one face of it lies near the surface of the convex shapes that are intersecting.
  * This class can be used to generate better contact information than would be possible
  * with just GJK.
  */
class EPASolver
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default EPASolver object with the default max number of iterations.
			RIM_INLINE EPASolver()
				:	maximumNumberOfIterations( DEFAULT_MAXIMUM_NUMBER_OF_ITERATIONS )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Solve Method
			
			
			
			
			/// Iteratively refine the specified GJK simplex.
			/**
			  * This method iteratively adds triangles to the given simplex
			  * that better approximate the minkowski difference between two convex
			  * shapes. The method returns the triangle that is closest to the surface
			  * of the shapes' minkowski difference. This triangle can then be used to
			  * generate a point of contact on each shape.
			  */
			template < typename UserDataType1, typename UserDataType2, MinkowskiVertex3 (*getSupportPoint)( const Vector3&, const UserDataType1*, const UserDataType2* ) >
			EPAResult solve( const StaticArray<MinkowskiVertex3,4>& simplex, Real terminationThreshold,
							const UserDataType1* userData1 = NULL, const UserDataType2* userDat2 = NULL );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Maximum Number of Iterations Accessor Methods
			
			
			
			
			/// Return the maximum number of iterations that this GJK solver can perform.
			/**
			  * An upper bound to the number of iterations is necessary so that degenerate
			  * cases don't produce an infinite solver loop. Values in the range of 10 to 30
			  * are typical good iteration count limits. Your mileage may vary.
			  */
			RIM_FORCE_INLINE Size getMaximumNumberOfIterations() const
			{
				return maximumNumberOfIterations;
			}
			
			
			
			
			/// Set the maximum number of iterations that this GJK solver can perform.
			/**
			  * An upper bound to the number of iterations is necessary so that degenerate
			  * cases don't produce an infinite solver loop. Values in the range of 10 to 30
			  * are typical good iteration count limits. Your mileage may vary.
			  */
			RIM_FORCE_INLINE void setMaximumNumberOfIterations( Size newMaximumNumberOfIterations )
			{
				maximumNumberOfIterations = newMaximumNumberOfIterations;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	EPA Triangle Class
			
			
			
			
			/// A class which holds data about a triangle in the EPA algorithm.
			class EPATriangle;
			
			
			
			
			/// A class which holds the vertex indices of an edge's endpoints.
			class EPAEdge;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Add a vertex to the expanding polytope, removing and adding triangles necessary to maintain convexity.
			void addNewVertex( const MinkowskiVertex3& newVertex );
			
			
			
			
			/// Create a new triangle with the specified vertex indices and add it to this EPA solver's triangle queue.
			/**
			  * The back vertex index parameter indicates the index of a vertex which should be
			  * behind the created triangle (the normal should point away from this vertex).
			  */
			RIM_FORCE_INLINE void addNewTriangle( Index v1, Index v2, Index v3, Index backVertex );
			
			
			
			
			/// Non-inline version of addNewTriangle() for non performance-critical applications.
			void addNewTriangleNoInline( Index v1, Index v2, Index v3, Index backVertex );
			
			
			
			
			/// Initialize the EPA data structures for the specified GJK termination simplex.
			void initializeDataStructures( const StaticArray<MinkowskiVertex3,4>& simplex );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A queue of EPA triangles, sorted by increasing distance from the origin.
			PriorityQueue<EPATriangle> triangleQueue;
			
			
			
			
			/// A list of all of the current minkowski vertices in this EPA solver.
			ArrayList<MinkowskiVertex3> vertices;
			
			
			
			
			/// A list of edges that need to be connected to a new EPA vertex by triangles.
			ArrayList<EPAEdge> edgesToFill;
			
			
			
			
			/// The maximum allowed number of iterations for this EPA solver.
			Size maximumNumberOfIterations;
			
			
			
			
			/// The default starting maximum number of iterations that this EPA solver performs.
			static const Size DEFAULT_MAXIMUM_NUMBER_OF_ITERATIONS = 64;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		EPA Triangle Class Definition
//############		
//##########################################################################################
//##########################################################################################




class EPASolver:: EPATriangle
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new EPA triangle from the specified vertex indices and plane.
			RIM_INLINE EPATriangle( Index newV1, Index newV2, Index newV3,
									const Plane3& newPlane )
				:	v1( newV1 ),
					v2( newV2 ),
					v3( newV3 ),
					plane( newPlane ),
					distance( math::abs( newPlane.offset ) )
			{
			}
			
			
			
			
			/// Create a new EPA triangle from the specified vertex indices and vertices
			RIM_INLINE EPATriangle( Index newV1, Index newV2, Index newV3,
									const ArrayList<MinkowskiVertex3>& vertices )
				:	v1( newV1 ),
					v2( newV2 ),
					v3( newV3 ),
					plane( vertices[newV1], vertices[newV2], vertices[newV3] )
			{
				if ( plane.offset <= Real(0) )
					distance = -plane.offset;
				else
				{
					distance = plane.offset;
					plane = -plane;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Triangle Comparison Operators
			
			
			
			
			RIM_FORCE_INLINE Bool operator > ( const EPATriangle& triangle ) const
			{
				return distance < triangle.distance;
			}
			
			
			
			
			RIM_FORCE_INLINE Bool operator < ( const EPATriangle& triangle ) const
			{
				return distance > triangle.distance;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The index of the first vertex of this EPA triangle.
			Index v1;
			
			
			
			
			/// The index of the second vertex of this EPA triangle.
			Index v2;
			
			
			
			
			/// The index of the third vertex of this EPA triangle.
			Index v3;
			
			
			
			
			/// The plane of this EPA triangle in minkowski space.
			Plane3 plane;
			
			
			
			
			/// The offset of this triangle from the origin.
			Real distance;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		EPA Triangle Class Definition
//############		
//##########################################################################################
//##########################################################################################




class EPASolver:: EPAEdge
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new EPA edge from the specified vertex indices.
			RIM_INLINE EPAEdge( Index newV1, Index newV2 )
				:	v1( newV1 ),
					v2( newV2 )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Equality Comparison Operators
			
			
			
			
			/// Return whether or not this EPA edge is equal to another.
			RIM_FORCE_INLINE Bool operator == ( const EPAEdge& other ) const
			{
				if ( v1 == other.v1 )
					return v2 == other.v2;
				else if ( v1 == other.v2 )
					return v2 == other.v1;
				else
					return false;
			}
			
			
			
			
			/// Return whether or not this EPA edge is not equal to another.
			RIM_FORCE_INLINE Bool operator != ( const EPAEdge& other ) const
			{
				return !((*this) == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The index of the first vertex of this EPA edge.
			Index v1;
			
			
			
			
			/// The index of the second vertex of this EPA edge.
			Index v2;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		EPA Solve Method
//############		
//##########################################################################################
//##########################################################################################




template < typename UserDataType1, typename UserDataType2, MinkowskiVertex3 (*getSupportPoint)( const Vector3&, const UserDataType1*, const UserDataType2* ) >
EPAResult EPASolver:: solve( const StaticArray<MinkowskiVertex3,4>& simplex,
							Real terminationThreshold, const UserDataType1* userData1, const UserDataType2* userData2 )
{
	// Add the four initial simplex triangles and vertices to start the algorithm.
	initializeDataStructures( simplex );
	
	const EPATriangle* triangle = &triangleQueue[0];
	
	for ( Index i = 0; i < maximumNumberOfIterations; i++ )
	{
		// Get the triangle that is closest to the origin in minkowski space.
		triangle = &triangleQueue[0];
		
		// Detect degenerate triangles before a support vertex is generated.
		// Stop the expansion due to the error and use the closest non-degenerate triangle.
		if ( math::isNAN( triangle->distance ) )
			break;
		
		//************************************************************
		// Find the support point farthest from the triangle and
		// from the origin.
		
		MinkowskiVertex3 supportPoint = getSupportPoint( triangle->plane.normal, userData1, userData2 );
		
		// Terminate the algorithm if the algorithm is within the termination threshold
		// of the surface of the minkowski difference of the two shapes.
		if ( triangle->plane.getSignedDistanceTo( supportPoint ) < terminationThreshold )
			break;
		
		
		// Add the support point to the expanding polytope, adding and removing any triangles
		// necessary to maintain the convex hull of the polytope's vertices.
		addNewVertex( supportPoint );
	}
	
	// A final degeneracy check, sometimes (very rarely) this will happen
	// if a support vertex is generated that already exists numerically in the 
	// set of polytope vertices, just use the closest valid triangle.
	while ( math::isNAN( triangle->distance ) )
	{
		triangleQueue.remove();
		triangle = &triangleQueue[0];
	}
	
	return EPAResult( vertices[triangle->v1], vertices[triangle->v2], vertices[triangle->v3], triangle->distance );
}




//##########################################################################################
//**********************  End Rim Physics Utilities Namespace  *****************************
RIM_PHYSICS_UTILITES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_EPA_SOLVER_H
