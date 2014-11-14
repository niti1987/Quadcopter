/*
 *  rimPhysicsCollisionManifold.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 5/8/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_MANIFOLD_H
#define INCLUDE_RIM_PHYSICS_COLLISION_MANIFOLD_H


#include "rimPhysicsCollisionConfig.h"


#include "rimPhysicsCollisionPoint.h"


//##########################################################################################
//**********************  Start Rim Physics Collision Namespace  ***************************
RIM_PHYSICS_COLLISION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains a collection of collision points.
/**
  * These collision points represent the contact surface between to objects.
  */
class CollisionManifold
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default empty collision manifold.
			RIM_INLINE CollisionManifold()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Collision Point Accessor Methods
			
			
			
			
			/// Add the specified CollisionPoint to this manifold.
			RIM_INLINE void addPoint( const CollisionPoint& newPoint )
			{
				// Add the new point and immediately return when the manifold is empty.
				if ( points.getSize() == Real(0) )
				{
					points.add( Point( newPoint, timestamp ) );
					return;
				}
				else
					addPointToNonEmptyManifold( newPoint );
			}
			
			
			
			
			/// Return a const reference to the collision point at the specified index.
			/**
			  * If the point index is greater than or equal to the number of points
			  * in the manifold, the result of this method is undefined.
			  */
			RIM_FORCE_INLINE const CollisionPoint& getPoint( Index pointIndex ) const
			{
				return points[pointIndex].point;
			}
			
			
			
			
			/// Remove the collision point at the specified index in the collision manifold.
			/**
			  * If the point index is less than the number of points in this manifold,
			  * the point at that index is removed and TRUE is returned. Otherwie, FALSE
			  * is returned and the manifold is unchanged.
			  */
			RIM_FORCE_INLINE Bool removePoint( Index pointIndex )
			{
				return points.removeAtIndex( pointIndex );
			}
			
			
			
			
			/// Return the number of collision points that are contained in this collision manifold.
			RIM_FORCE_INLINE Size getPointCount() const
			{
				return points.getSize();
			}
			
			
			
			
			/// Remove all collision points from this collision manifold.
			RIM_INLINE void clearPoints()
			{
				points.clear();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Manifold Update Method
			
			
			
			
			/// Update the local-to-world transformations for the two colliding objects.
			/**
			  * This method recomputes the world space positions and separation distance
			  * for every collision point in this manifold from the object-space positions.
			  * If there are any collision points that are no longer physically valid based
			  * on the current object configuration (if their separation distance becomes
			  * positive), they are removed from the manifold.
			  */
			void updateTransforms( const Transform3& t1, const Transform3& t2 );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which holds information about a collision point, plus its current timestamp.
			class Point
			{
				public:
					
					/// Create a new collision manifold point with the specified collision point and timetamp.
					RIM_INLINE Point( const CollisionPoint& newPoint, Index newTimestamp )
						:	point( newPoint ),
							timestamp( newTimestamp )
					{
					}
					
					
					CollisionPoint point;
					
					
					/// The current timestamp
					Index timestamp;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Add a new collision point to this manifold, looking to see if there are any existing duplicate points.
			void addPointToNonEmptyManifold( const CollisionPoint& newPoint );
			
			
			
			
			/// Remove the point from this collision manifold that is least important.
			/**
			  * This method is called when a collision manifold has the maximum number of
			  * points and needs to add a new point.
			  */
			void removeWorstPoint();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// Define the maximum number of collision points that a collision manifold can contain.
			static const Size MAX_NUM_COLLISION_POINTS = 4;
			
			
			
			
			/// A fixed-size array list of collision points in this collision manifold.
			StaticArrayList<Point,MAX_NUM_COLLISION_POINTS> points;
			
			
			
			
			/// The current timestamp within this collision manifold.
			/**
			  * This is the frame index indicating how many times that the manifold
			  * has been updated
			  */
			Index timestamp;
			
			
};




//##########################################################################################
//**********************  End Rim Physics Collision Namespace  *****************************
RIM_PHYSICS_COLLISION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_MANIFOLD_H
