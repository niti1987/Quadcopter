/*
 *  Roadmap.cpp
 *  Quadcopter
 *
 *  Created by Carl Schissler on 12/5/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "Roadmap.h"


class Foo
{
	public:
		
		inline Foo( const Pointer<GenericBufferList>& b, Index i )
			:	bufferList( b ),
				indexOffset(i)
		{
		}
		
		inline Bool operator == ( const Foo& other ) const
		{
			return bufferList == other.bufferList;
		}
		
		Pointer<GenericBufferList> bufferList;
		Index indexOffset;
};




ArrayList<Triangle<Vector3f> > convertGenericMeshToMesh( const GenericMeshShape& genericMesh )
{
	ArrayList<Vector3f> vertices;
	ArrayList< Triangle<Index> > triangles;
	Index vertexOffset = 0;
	
	ArrayList<Foo> pastBuffers;
	
	for ( Index g = 0; g < genericMesh.getGroupCount(); g++ )
	{
		const Pointer<GenericMeshGroup>& group = genericMesh.getGroup(g);
		const BufferRange& bufferRange = group->getBufferRange();
		
		if ( bufferRange.getPrimitiveType() != IndexedPrimitiveType::TRIANGLES )
			continue;
		
		//***********************************************************************
		
		const Pointer<GenericBufferList>& vertexBuffers = group->getVertexBuffers();
		Index pastBufferIndex;
		Index currentVertexOffset = 0;
		
		if ( !pastBuffers.getIndex( Foo( vertexBuffers, 0 ), pastBufferIndex ) )
		{
			Pointer<GenericBuffer> positionBuffer = vertexBuffers->getBufferWithUsage( VertexUsage::POSITION );
			
			if ( positionBuffer.isNull() )
				continue;
			
			for ( Index i = 0; i < positionBuffer->getSize(); i++ )
				vertices.add( positionBuffer->get<Vector3f>(i) );
			
			currentVertexOffset = vertexOffset;
			pastBuffers.add( Foo( vertexBuffers, vertexOffset ) );
			vertexOffset += positionBuffer->getSize();
		}
		else
		{
			currentVertexOffset = pastBuffers[pastBufferIndex].indexOffset;
		}
		
		//***********************************************************************
		
		const Pointer<GenericBuffer>& indexBuffer = group->getIndexBuffer();
		
		if ( indexBuffer.isNull() )
			continue;
		
		if ( indexBuffer->getAttributeType() == AttributeType::get<UInt32>() )
		{
			for ( Index i = 0; i < indexBuffer->getSize(); i += 3 )
			{
				Index v0 = currentVertexOffset + indexBuffer->get<UInt32>(i);
				Index v1 = currentVertexOffset + indexBuffer->get<UInt32>(i + 1);
				Index v2 = currentVertexOffset + indexBuffer->get<UInt32>(i + 2);
				triangles.add( Triangle<Index>( v0, v1, v2 ) );
			}
		}
	}
	
	//***********************************************************************
	
	ArrayList<Triangle<Vector3f> > outputTriangles;
	
	for ( Index t = 0; t < triangles.getSize(); t++ )
	{
		outputTriangles.add( Triangle<Vector3f>( vertices[triangles[t].v1], vertices[triangles[t].v2], vertices[triangles[t].v3] ) );
	}
	
	return outputTriangles;
}




class Roadmap:: TriangleSet : public bvh::PrimitiveInterface
{
	public:
		
		TriangleSet( const Pointer<GenericMeshShape>& mesh )
			:	triangles( convertGenericMeshToMesh( *mesh ) )
		{
		}
		
		
		virtual Size getSize() const
		{
			return triangles.getSize();
		}
		
		virtual PrimitiveInterfaceType getType() const
		{
			return PrimitiveInterfaceType::TRIANGLES;
		}
		
		
		
		virtual AABB3f getAABB( Index primitiveIndex ) const
		{
			const Triangle<Vector3f>& t = triangles[primitiveIndex];
			AABB3f result( t.v1 );
			result.enlargeFor( t.v2 );
			result.enlargeFor( t.v3 );
			
			return result;
		}
		
		
		virtual bvh::BoundingSphere<Float> getBoundingSphere( Index primitiveIndex ) const
		{
			const Triangle<Vector3f>& t = triangles[primitiveIndex];
			return bvh::BoundingSphere<Float>( t.v1, t.v2, t.v3 );
		}
		
		
		virtual Bool intersectRay( Index primitiveIndex, const Ray3f& ray, Float& distance ) const
		{
			return true;
		}
		
		
		
		virtual Bool intersectRay( const Index* primitiveIndices, Size numPrimitives,
									const Ray3f& ray, Float& distance, Index& closestPrimitive ) const
		{
			return true;
		}
		
		
		
		virtual Bool getTriangle( Index primitiveIndex, Vector3f& v0, Vector3f& v1, Vector3f& v2 ) const
		{
			if ( primitiveIndex < triangles.getSize() )
			{
				const Triangle<Vector3f>& t = triangles[primitiveIndex];
				
				v0 = t.v1;
				v1 = t.v2;
				v2 = t.v3;
				
				return true;
			}
			
			return false;
		}
		
		
	private:
		
		ArrayList< Triangle<Vector3f> > triangles;
		
};





Roadmap:: Roadmap( const Pointer<GenericMeshShape>& mesh )
{
	bvh = Pointer<AABBTree4>::construct( Pointer<TriangleSet>::construct( mesh ) );
	bvh->rebuild();
}




Bool Roadmap:: link( const Vector3f& start, const Vector3f& end ) const
{
	Float distance;
	Ray3f ray( start, (end - start).normalize( distance ) );
	
	return !bvh->traceRay( ray, distance, stack.getRoot() );
}




void Roadmap:: rebuild( const AABB3f& bounds, Size numSamples, const Vector3f& start, const Vector3f& goal )
{
	nodes.clear();
	nodes.add( Node( start ) );
	nodes.add( Node( goal ) );
	
	for ( Index i = 0; i < numSamples; i++ )
	{
		Vector3f p( math::random( bounds.min.x, bounds.max.x ),
					math::random( bounds.min.y, bounds.max.y ),
					math::random( bounds.min.z, bounds.max.z ) );
		
		nodes.add( Node( p ) );
	}
	
	const Float distanceThreshold = 100.0;
	const Float distanceThreshold2 = distanceThreshold*distanceThreshold;
	
	for ( Index i = 0; i < nodes.getSize(); i++ )
	{
		const Vector3f& p1 = nodes[i].position;
		
		for ( Index j = 0; j < nodes.getSize(); j++ )
		{
			const Vector3f& p2 = nodes[j].position;
			
			if ( p1.getDistanceToSquared(p2) < distanceThreshold2 && link( p1, p2 ) )
			{
				nodes[i].neighbors.add( j );
				nodes[j].neighbors.add( i );
			}
		}
	}
}




Index Roadmap:: getClosestNode( const Vector3f& position ) const
{
	const Size numNodes = nodes.getSize();
	Float minDistance = math::max<Float>();
	Index minIndex = 0;
	
	for ( Index i = 0; i < numNodes; i++ )
	{
		Float distance = nodes[i].position.getDistanceTo( position );
		
		if ( distance < minDistance )
		{
			minDistance = distance;
			minIndex = i;
		}
	}
	
	return minIndex;
}



