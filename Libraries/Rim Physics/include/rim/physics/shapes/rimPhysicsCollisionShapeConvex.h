/*
 *  rimPhysicsCollisionShapeConvex.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 6/6/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_CONVEX_H
#define INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_CONVEX_H


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
/// A class which represents a convex polyhedral collision shape.
class CollisionShapeConvex : public CollisionShapeBase<CollisionShapeConvex>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Class Declarations
			
			
			
			
			class Instance;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an empty convex hull shape with no vertices.
			CollisionShapeConvex();
			
			
			
			
			/// Create a convex hull shape from the specified array of vertices.
			CollisionShapeConvex( const PhysicsVertex3* vertices, Size numVertices );
			
			
			
			
			/// Create a convex hull shape from the specified array of vertices.
			CollisionShapeConvex( const ArrayList<PhysicsVertex3>& vertices );
			
			
			
			
			/// Create a convex shape from the specified convex hull representation.
			CollisionShapeConvex( const ConvexHull& convexHull );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Convex Hull Accessor Methods
			
			
			
			
			/// Return a const reference to the convex hull which defines this convex shape.
			RIM_INLINE const ConvexHull& getConvexHull() const
			{
				return convexHull;
			}
			
			
			
			
			/// Return a const reference to the convex hull which defines this convex shape.
			void setConvexHull( const ConvexHull& newConvexHull );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Accessor Methods
			
			
			
			
			/// Return the number of vertices that define the convex hull of this convex shape.
			RIM_INLINE Size getVertexCount() const
			{
				return convexHull.getVertexCount();
			}
			
			
			
			
			/// Return the vertex at the specified index in this convex shape.
			RIM_INLINE const ConvexHull::Vertex& getVertex( Index index ) const
			{
				return convexHull.getVertex( index );
			}
			
			
			
			
			/// Replace this convex shape's convex hull with one built from the specified vertices.
			void setVertices( const ArrayList<Vector3>& newVertices );
			
			
			
			
			/// Replace this convex shape's convex hull with one built from the specified vertices.
			void setVertices( const Vector3* newVertices, Size numVertices );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Triangle Accessor Methods
			
			
			
			
			/// Return the number of triangles that define the surface of the convex hull of this convex shape.
			RIM_INLINE Size getTriangleCount() const
			{
				return convexHull.getTriangleCount();
			}
			
			
			
			
			/// Return the triangle at the specified index in this convex shape.
			RIM_INLINE const ConvexHull::Triangle& getTriangle( Index index ) const
			{
				return convexHull.getTriangle( index );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Supporting Vertex Accessor Method
			
			
			
			
			/// Determine which vertex on this convex shape's hull is farthest in the specified direction.
			/**
			  * If the convex hull of this convex shape has no points, the origin is returned.
			  */
			RIM_INLINE const PhysicsVertex3& getSupportVertex( const Vector3& direction ) const
			{
				lastSupportVertex = convexHull.getSupportVertexIndex( direction, lastSupportVertex );
				
				if ( lastSupportVertex < convexHull.getVertexCount() )
					return convexHull.getVertex(lastSupportVertex).getPosition();
				else
					return PhysicsVertex3::ZERO;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mass Distribution Accessor Methods
			
			
			
			
			/// Return a 3x3 matrix for the inertia tensor of this shape relative to its center of mass.
			virtual Matrix3 getInertiaTensor() const;
			
			
			
			
			/// Return a 3D vector representing the center-of-mass of this shape in its coordinate frame.
			virtual Vector3 getCenterOfMass() const;
			
			
			
			
			/// Return the volume of this shape in length units cubed (m^3).
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
		//******	Private Helper Methods
			
			
			
			
			/// Recompute the bounding sphere, center of mass, volume, and inertia tensor for this convex shape.
			void updateDependentQuantities();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The convex hull of this convex shape.
			ConvexHull convexHull;
			
			
			
			
			/// The center of mass of this convex shape.
			Vector3 centerOfMass;
			
			
			
			
			/// The volume of this convex shape in length units cubed (m^3).
			Real volume;
			
			
			
			
			/// The inertia tensor of this convex shape where volume is treated as mass.
			/**
			  * This tensor is then multiplied by the density of the shape in order to produce
			  * the final inertia tensor for the shape.
			  */
			Matrix3 volumeInertiaTensor;
			
			
			
			
			/// The index of the last returned support vertex.
			/**
			  * This value is cached with each call to getSupportVertex() and is used to
			  * speed up future queries to that method.
			  */
			mutable Index lastSupportVertex;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Convex Shape Instance Class Definition
//############		
//##########################################################################################
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which is used to instance a CollisionShapeConvex object with an arbitrary rigid transformation.
class CollisionShapeConvex:: Instance : public CollisionShapeInstance
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transform Update Method
			
			
			
			
			/// Update this convex shape instance with the specified 3D rigid transformation from shape to world space.
			virtual void setTransform( const Transform3& newTransform );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Support Vertex Accessor Method
			
			
			
			
			/// Determine which vertex on this convex shape instance's hull is farthest in the specified direction.
			RIM_INLINE PhysicsVertex3 getSupportVertex( const Vector3& direction ) const
			{
				// Transform the support vertex direction into the shape's coordinate frame.
				Vector3 objectSpaceDirection = transformation.rotateToObjectSpace( direction );
				
				// Get the base shape for this convex shape instance.
				const ConvexHull& convexHull = ((const CollisionShapeConvex*)this->getShape())->getConvexHull();
				
				// Get the object-space support point in the given object-space direction.
				lastSupportVertex = convexHull.getSupportVertexIndex( objectSpaceDirection, lastSupportVertex );
				
				// Transform the resulting support point back to world space.
				if ( lastSupportVertex < convexHull.getVertexCount() )
					return transformation.transformToWorldSpace( 
								convexHull.getVertex(lastSupportVertex).getPosition() );
				else
					return Vector3::ZERO;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Triangle Accessor Methods
			
			
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Accessor Methods
			
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructors
			
			
			
			
			/// Create a new convex shape instance which uses the specified base convex shape.
			RIM_INLINE Instance( const CollisionShapeConvex* newConvex )
				:	CollisionShapeInstance( newConvex ),
					lastSupportVertex( 0 )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The transformation from shape-space to world space for this convex shape instance.
			Transform3 transformation;
			
			
			
			
			/// The index of the last returned support vertex.
			/**
			  * This value is cached with each call to getSupportVertex() and is used to
			  * speed up future queries to that method.
			  */
			mutable Index lastSupportVertex;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Declarations
			
			
			
			
			/// Declare the convex collision shape as a friend so that it can construct instances.
			friend class CollisionShapeConvex;
			
			
};




//##########################################################################################
//************************  End Rim Physics Shapes Namespace  ******************************
RIM_PHYSICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_CONVEX_H
