/*
 *  rimPhysicsEPAResult.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 6/22/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_EPA_RESULT_H
#define INCLUDE_RIM_PHYSICS_EPA_RESULT_H


#include "rimPhysicsUtilitiesConfig.h"


#include "rimPhysicsMinkowskiVertex.h"
#include "rimPhysicsIntersectionPoint.h"


//##########################################################################################
//**********************  Start Rim Physics Utilities Namespace  ***************************
RIM_PHYSICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which holds the results of the EPA algorithm.
/**
  * The EPA algorithm returns the triangle that is closest to the surface of the
  * minkowski difference between the two convex shapes being tested.
  */
class EPAResult
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new EPA result object with the specified triangle vertices and distance.
			RIM_INLINE EPAResult( const MinkowskiVertex3& newV1, const MinkowskiVertex3& newV2,
									const MinkowskiVertex3& newV3, Real newDistance )
				:	v1( newV1 ),
					v2( newV2 ),
					v3( newV3 ),
					distance( newDistance )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Penetration Distance Accessor Method
			
			
			
			
			/// Return the positive penetration distance between the two shapes.
			RIM_INLINE Real getPenetrationDistance() const
			{
				return distance;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Collision Point Computation Method
			
			
			
			
			/// Return an intersection point, indicating the collision configuration of the two convex shapes in world space.
			/**
			  * This method computes the points, normal, and distance of the intersection between
			  * two convex shapes.
			  * 
			  * These points are computed by projecting the origin in minkowski space
			  * onto the closest EPA triangle and determining that point's barycentric
			  * coordinates for the triangle. These barycentric coordinates are then
			  * used to compute the resulting collision point on each object.
			  */
			IntersectionPoint getIntersectionPoint() const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Return the barycentric coordinates of the specified point for the given vertices.
			RIM_INLINE static Vector3 computeBarycentricCoordinates( const Vector3& v1, const Vector3& v2, 
																	const Vector3& v3, const Vector3& point );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The first vertex in the EPA result triangle.
			MinkowskiVertex3 v1;
			
			
			
			
			/// The first vertex in the EPA result triangle.
			MinkowskiVertex3 v2;
			
			
			
			
			/// The first vertex in the EPA result triangle.
			MinkowskiVertex3 v3;
			
			
			
			
			/// The distance of the resulting triangle from the origin in minkowski space.
			/**
			  * This is also the positive penetration distance between the two convex shapes.
			  */
			Real distance;
			
			
			
};




//##########################################################################################
//**********************  End Rim Physics Utilities Namespace  *****************************
RIM_PHYSICS_UTILITES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_EPA_RESULT_H
