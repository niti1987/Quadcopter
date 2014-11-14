/*
 *  rimAABBTree4.h
 *  Rim BVH
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_BVH_AABB_TREE_4_H
#define INCLUDE_RIM_BVH_AABB_TREE_4_H


#include "rimBVHConfig.h"


#include "./rimBVH.h"


//##########################################################################################
//*****************************  Start Rim BVH Namespace  **********************************
RIM_BVH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that implements a SIMD-accelerated 4-ary bounding volume hierarchy.
class AABBTree4 : public BVH
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new quad AABB tree with no primitives.
			AABBTree4();
			
			
			
			
			/// Create a new quad AABB tree with the specified primitive set.
			AABBTree4( const Pointer<const PrimitiveInterface>& newPrimitives );
			
			
			
			
			/// Create a copy of the specified quad AABB tree, using the same primitives.
			AABBTree4( const AABBTree4& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this quad AABB tree.
			virtual ~AABBTree4();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign a copy of another quad AABB tree to this one, using the same primitives.
			AABBTree4& operator = ( const AABBTree4& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	BVH Primitive Accessor Methods
			
			
			
			
			/// Set the primitive interface that this BVH should use.
			/**
			  * Calling this method invalidates the current BVH, requiring it
			  * to be rebuilt before it can be used.
			  */
			virtual void setPrimitives( const Pointer<const PrimitiveInterface>& newPrimitives );
			
			
			
			
			/// Return a pointer to the primitive interface used by this BVH.
			virtual const Pointer<const PrimitiveInterface>& getPrimitives() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	BVH Attribute Accessor Methods
			
			
			
			
			/// Return the maximum depth of this BVH's hierarchy.
			/**
			  * This value can be used to pre-allocate traversal stacks to prevent overflow.
			  */
			virtual Size getMaxDepth() const;
			
			
			
			
			/// Return whether or not this BVH is built, valid, and ready for use.
			virtual Bool isValid() const;
			
			
			
			
			/// Return the approximate total amount of memory in bytes allocated for this BVH.
			virtual Size getSizeInBytes() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	BVH Building Methods
			
			
			
			
			/// Rebuild the BVH using the current set of primitives.
			virtual void rebuild();
			
			
			
			
			/// Do a quick update of the BVH by refitting the bounding volumes without changing the hierarchy.
			virtual void refit();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Ray Tracing Methods
			
			
			
			
			/// Trace the specified ray through this BVH up to a maximum distance.
			/**
			  * The method returns whether or not an intersection was found. If so, the distance
			  * along the ray and the intersected primitive index are placed in the output parameters.
			  */
			virtual Bool traceRay( const Ray3f& ray, Float maxDistance, const void** stack,
									Float& closestIntersection, Index& closestPrimitiveID ) const;
			
			
			
			
			/// Trace the specified ray through this BVH up to a maximum distance.
			/**
			  * The method returns whether or not an intersection was found.
			  */
			virtual Bool traceRay( const Ray3f& ray, Float maxDistance, const void** stack ) const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations
			
			
			
			
			/// A class which represents a single node in the quad AABB tree.
			class Node;
			
			
			
			
			/// A class which stores the AABB of a single primitive used during tree construction.
			class PrimitiveAABB;
			
			
			
			
			/// A class used to keep track of surface-area-heuristic paritioning data.
			class SplitBin;
			
			
			
			
			/// A class which represents an internally cached triangle that has an efficient storage layout.
			class CachedTriangle;
			
			
			
			
			/// A SIMD ray class with extra data used to speed up intersection tests.
			class FatSIMDRay;
			
			
			
			
			/// Define the type to use for offsets in the BVH.
			typedef Index IndexType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Ray Tracing Methods
			
			
			
			
			/// Trace a ray through the BVH for generic-typed primitives.
			RIM_FORCE_INLINE Bool traceRayVsGeneric( const Ray3f& ray, Float maxDistance, const void** stack,
													Float& closestIntersection, Index& closestPrimitiveID ) const;
			
			
			
			
			/// Trace a ray through the BVH for cached triangle primitives.
			RIM_FORCE_INLINE Bool traceRayVsTriangles( const Ray3f& ray, Float maxDistance, const void** stack,
														Float& closestIntersection, Index& closestPrimitiveID ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Intersection Methods
			
			
			
			
			/// Trace a ray through the BVH for cached triangle primitives.
			RIM_FORCE_INLINE static SIMDInt4 rayIntersectsTriangles( const SIMDRay3f& ray,
													const CachedTriangle& triangle, SIMDFloat4& distance );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Tree Bulding Methods
			
			
			
			
			/// Build a tree starting at the specified node using the specified objects.
			/**
			  * This method returns the number of nodes in the tree created.
			  */
			static Size buildTreeRecursive( Node* node,
											PrimitiveAABB* primitiveAABBs, Index start, Size numPrimitives,
											SplitBin* splitBins, Size numSplitCandidates,
											Size maxNumObjectsPerLeaf, Size depth, Size& maxDepth );
			
			
			
			
			/// Partition the specified list of objects into two sets based on the given split plane.
			/**
			  * The objects are sorted so that the first N objects in the list are deemed "less" than
			  * the split plane along the split axis, and the next M objects are the remainder.
			  * The number of "lesser" objects is placed in the output variable.
			  */
			static void partitionPrimitivesSAH( PrimitiveAABB* primitiveAABBs, Size numPrimitives,
												SplitBin* splitBins, Size numSplitCandidates,
												Index& axis, Size& numLesserObjects,
												AABB3f& lesserVolume, AABB3f& greaterVolume );
			
			
			
			
			/// Partition the specified list of objects into two sets based on their median along the given axis.
			static void partitionPrimitivesMedian( PrimitiveAABB* objectAABBs, Size numObjects,
												Index splitAxis, Size& numLesserTriangles,
												AABB3f& lesserVolume, AABB3f& greaterVolume );
			
			
			
			
			/// Compute the axis-aligned bounding box for the specified list of objects.
			static AABB3f computeAABBForPrimitives( const PrimitiveAABB* primitiveAABBs, Size numPrimitives );
			
			
			
			
			/// Compute the axis-aligned bounding box for the specified list of objects' centroids.
			static AABB3f computeAABBForPrimitiveCentroids( const PrimitiveAABB* primitiveAABBs, Size numPrimitives );
			
			
			
			
			/// Get the surface area of a 3D axis-aligned bounding box specified by 2 SIMD min-max vectors.
			RIM_FORCE_INLINE static float getAABBSurfaceArea( const math::SIMDFloat4& min,
															const math::SIMDFloat4& max );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Tree Refitting Methods
			
			
			
			
			/// Refit the bounding volume for the specified node and return the final bounding box.
			AABB3f refitTreeGeneric( Node* node );
			
			
			
			
			/// Refit the bounding volume for the specified node and return the final bounding box.
			AABB3f refitTreeTriangles( Node* node );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Primitive List Building Methods
			
			
			
			
			/// Fill the list of objects indices with the final indices.
			static void fillPrimitiveIndices( Index* primitiveIndices, const PrimitiveAABB* primitiveAABBs, Size numPrimitives );
			
			
			
			
			Size getTriangleArraySize( const Node* node ) const;
			
			
			
			
			Size fillTriangleArray( CachedTriangle* triangles, const PrimitiveInterface* primitiveInterface,
									const PrimitiveAABB* aabbs, Node* node, Size numFilled );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Other Helper Methods
			
			
			
			
			/// Return a deep copy of this tree's cached primitive data.
			UByte* copyPrimitiveData( Size& newCapacity ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The default intial number of splitting plane candidates that are considered when building the tree.
			static const Size DEFAULT_NUM_SPLIT_CANDIDATES = 32;
			
			
			
			
			/// The default maximum number of primitives that can be in a leaf node.
			static const Size DEFAULT_MAX_PRIMITIVES_PER_LEAF = 4;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to a flat array of nodes that make up this tree.
			Node* nodes;
			
			
			
			
			/// A packed list of primitive data that are organized by node.
			UByte* primitiveData;
			
			
			
			
			/// The capacity in bytes of the primitive data allocation.
			Size primitiveDataCapacity;
			
			
			
			
			/// An opaque set of the primitives used by this tree.
			Pointer<const PrimitiveInterface> primitiveSet;
			
			
			
			
			/// An enum value which indicates the type of the cached primitives, or UNDEFINED if not cached.
			PrimitiveInterfaceType cachedPrimitiveType;
			
			
			
			
			/// The number of primitives that are part of this qaud AABB tree.
			Size numPrimitives;
			
			
			
			
			/// The number of nodes that are in this quad AABB tree.
			Size numNodes;
			
			
			
			
			/// The maximum depth of the hierarchy of this quad AABB tree.
			Size maxDepth;
			
			
			
			
			/// The maximum number of primitives that this quad AABB tree can have per leaf node.
			Size maxNumPrimitivesPerLeaf;
			
			
			
			
			/// The number of Surface Area Heuristic split plane candidates to consider when building the tree.
			Size numSplitCandidates;
			
			
			
			
};





//##########################################################################################
//*****************************  End Rim BVH Namespace  ************************************
RIM_BVH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_BVH_AABB_TREE_4_H
