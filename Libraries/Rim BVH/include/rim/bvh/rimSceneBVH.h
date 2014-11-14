/*
 *  rimSceneBVH.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 10/28/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_BVH_SCENE_BVH_H
#define INCLUDE_RIM_BVH_SCENE_BVH_H


#include "rimBVHConfig.h"


#include "./rimBVH.h"
#include "rimObjectInterface.h"


//##########################################################################################
//*****************************  Start Rim BVH Namespace  **********************************
RIM_BVH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that handles hierarchies of transformed BVHs in a scene.
class SceneBVH
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new scene BVH with no objects.
			SceneBVH();
			
			
			
			
			/// Create a new scene BVH with the specified object set.
			SceneBVH( const Pointer<const ObjectInterface>& newObjectSet );
			
			
			
			
			/// Create a copy of the specified scene BVH, using the same objects.
			SceneBVH( const SceneBVH& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this scene BVH.
			virtual ~SceneBVH();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign a copy of another scene BVH to this one, using the same objects.
			SceneBVH& operator = ( const SceneBVH& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	BVH Object Accessor Methods
			
			
			
			
			/// Set the object interface that this scene BVH should use.
			/**
			  * Calling this method invalidates the current BVH, requiring it
			  * to be rebuilt before it can be used.
			  */
			virtual void setObjects( const Pointer<const ObjectInterface>& newObjects );
			
			
			
			
			/// Return a pointer to the object interface used by this BVH.
			virtual const Pointer<const ObjectInterface>& getObjects() const;
			
			
			
			
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
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	BVH Building Methods
			
			
			
			
			/// Rebuild the BVH using the current set of objects.
			virtual void rebuild();
			
			
			
			
			/// Do a quick update of the BVH by refitting the bounding volumes without changing the hierarchy.
			virtual void refit();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Ray Tracing Methods
			
			
			
			
			/// Trace the specified ray through this scene BVH up to a maximum distance.
			/**
			  * The method returns whether or not an intersection was found. If so, the distance
			  * along the ray and the intersected object and object index are placed in the output parameters.
			  */
			virtual Bool traceRay( const Ray3f& ray, Float maxDistance, TraversalStack& stack,
									Float& closestIntersection, Index& primitiveIndex, Index& objectIndex ) const;
			
			
			
			
			/// Trace the specified ray through this scene BVH up to a maximum distance.
			/**
			  * The method returns whether or not an intersection was found.
			  */
			virtual Bool traceRay( const Ray3f& ray, Float maxDistance, TraversalStack& stack ) const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations
			
			
			
			
			/// A class which represents a single node in the scene BVH.
			class Node;
			
			
			
			
			/// A class which stores the AABB of a single object used during tree construction.
			class ObjectAABB;
			
			
			
			
			/// A class used to keep track of surface-area-heuristic paritioning data.
			class SplitBin;
			
			
			
			
			/// A class which stores an object in the scene an its associated object-to-world transformation.
			class ObjectData;
			
			
			
			
			/// A SIMD ray class with extra data used to speed up intersection tests.
			class FatSIMDRay;
			
			
			
			
			/// Define the type to use for offsets in the BVH.
			typedef Index IndexType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Tree Bulding Methods
			
			
			
			
			/// Build a tree starting at the specified node using the specified objects.
			/**
			  * This method returns the number of nodes in the tree created.
			  */
			static Size buildTreeRecursive( Node* node,
											ObjectAABB* objectAABBs, Index start, Size numObjects,
											SplitBin* splitBins, Size numSplitCandidates,
											Size depth, Size& maxDepth );
			
			
			
			
			/// Partition the specified list of objects into two sets based on the given split plane.
			/**
			  * The objects are sorted so that the first N objects in the list are deemed "less" than
			  * the split plane along the split axis, and the next M objects are the remainder.
			  * The number of "lesser" objects is placed in the output variable.
			  */
			static void partitionObjectsSAH( ObjectAABB* objectAABBs, Size numObjects,
												SplitBin* splitBins, Size numSplitCandidates,
												Index& axis, Size& numLesserObjects,
												AABB3f& lesserVolume, AABB3f& greaterVolume );
			
			
			
			
			/// Partition the specified list of objects into two sets based on their median along the given axis.
			static void partitionObjectsMedian( ObjectAABB* objectAABBs, Size numObjects,
												Index splitAxis, Size& numLesserTriangles,
												AABB3f& lesserVolume, AABB3f& greaterVolume );
			
			
			
			
			/// Compute the axis-aligned bounding box for the specified list of objects.
			static AABB3f computeAABBForObjects( const ObjectAABB* objectAABBs, Size numObjects );
			
			
			
			
			/// Compute the axis-aligned bounding box for the specified list of objects' centroids.
			static AABB3f computeAABBForObjectCentroids( const ObjectAABB* objectAABBs, Size numObjects );
			
			
			
			
			/// Get the surface area of a 3D axis-aligned bounding box specified by 2 SIMD min-max vectors.
			RIM_FORCE_INLINE static float getAABBSurfaceArea( const math::SIMDFloat4& min,
															const math::SIMDFloat4& max );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Tree Refitting Methods
			
			
			
			
			/// Refit the bounding volume for the specified node and return the final bounding box.
			AABB3f refitTree( Node* node );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object List Building Methods
			
			
			
			
			/// Fill the list of objects data with the final data.
			void fillObjectData( const ObjectAABB* objectAABBs, Size numObjects );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The default intial number of splitting plane candidates that are considered when building the tree.
			static const Size DEFAULT_NUM_SPLIT_CANDIDATES = 32;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to a flat array of nodes that make up this tree.
			Node* nodes;
			
			
			
			
			/// The number of nodes that are in this scene BVH.
			Size numNodes;
			
			
			
			
			/// A list of data objects for each object in the tree.
			ArrayList<ObjectData> objectData;
			
			
			
			
			/// An opaque set of the objects used by this tree.
			Pointer<const ObjectInterface> objectSet;
			
			
			
			
			/// The maximum depth of the hierarchy of this scene BVH.
			Size maxDepth;
			
			
			
			
			/// The number of Surface Area Heuristic split plane candidates to consider when building the tree.
			Size numSplitCandidates;
			
			
			
			
};





//##########################################################################################
//*****************************  End Rim BVH Namespace  ************************************
RIM_BVH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_BVH_SCENE_BVH_H
