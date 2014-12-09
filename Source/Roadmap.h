/*
 *  Roadmap.h
 *  Quadcopter
 *
 *  Created by Carl Schissler on 12/5/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_ROADMAP_H
#define INCLUDE_ROADMAP_H


#include "rim/rimEngine.h"
using namespace rim;
using namespace rim::bvh;
using namespace rim::graphics;



class Roadmap
{
	public:
		
		/// A node in a roadmap.
		class Node
		{
			public:
				
				Node( const Vector3f& newPosition )
					:	position( newPosition ),
						previous( 0 )
				{
				}
				
				/// The 3D position of this node in space.
				Vector3f position;
				
				/// A list of the node indices of the neighbors to this node.
				ArrayList<Index> neighbors;
				
				/// In the A* algorithm, this value stores the index of the previous node in the path so it can be reconstructed.
				Index previous;
				
				
		};
		
		
		
		Roadmap( const Pointer<GenericMeshShape>& mesh );
		
		
		
		
		/// Return whether or not the specified start and end positions are visible to each other.
		Bool link( const Vector3f& start, const Vector3f& end ) const;
		
		
		/// Return whether or not the specified start and end positions are visible to each other.
		Bool link( const Vector3f& start, const Vector3f& end, Float radius, Size numSamples = 50 ) const;
		
		
		
		Bool traceRay( const Vector3f& start, const Vector3f& direction, Float maxDistance, Float& t );
		
		
		
		void rebuild( const AABB3f& bounds, Size numSamples, const Vector3f& start, const Vector3f& goal );
		
		
		
		
		/// Return the index of the node in the roadmap that is closest (and visible to) the specified point.
		Index getClosestNode( const Vector3f& position ) const;
		
		
		
		
		/// Return the number of nodes that are in this roadmap.
		inline Size getNodeCount() const
		{
			return nodes.getSize();
		}
		
		
		/// Return a reference to the node at the given index in this roadmap.
		inline const Node& getNode( Index nodeIndex ) const
		{
			return nodes[nodeIndex];
		}
		
		
		
	private:
		
		/// An object used as the interface to the BVH.
		class TriangleSet;
		
		
		ArrayList<Node> nodes;
		
			
		/// A pointer to a BVH used for ray tracing in the scene.
		Pointer<BVH> bvh;
		
		TraversalStack stack;
		
		mutable RandomVariable<Float> randomVariable;
		
};



#endif // INCLUDE_ROADMAP_H
