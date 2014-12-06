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
					:	position( newPosition )
				{
				}
				
				/// The 3D position of this node in space.
				Vector3f position;
				
				/// A list of the node indices of the neighbors to this node.
				ArrayList<Index> neighbors;
		};
		
		
		
		Roadmap( const Pointer<GenericMeshShape>& mesh );
		
		
		
		
		/// Return whether or not the specified start and end positions are visible to each other.
		Bool link( const Vector3f& start, const Vector3f& end ) const;
		
		
		
		void rebuild( const AABB3f& bounds, Size numSamples );
		
		
		
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
		
		
};



#endif // INCLUDE_ROADMAP_H