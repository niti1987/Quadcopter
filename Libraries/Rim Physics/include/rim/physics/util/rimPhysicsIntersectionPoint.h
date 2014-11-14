/*
 *  rimPhysicsIntersectionPoint.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 6/23/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_INTERSECTION_POINT_H
#define INCLUDE_RIM_PHYSICS_INTERSECTION_POINT_H


#include "rimPhysicsUtilitiesConfig.h"


//##########################################################################################
//**********************  Start Rim Physics Utilities Namespace  ***************************
RIM_PHYSICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class used to encapsulate basic information about a point of intersection between two shapes.
class IntersectionPoint
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			RIM_INLINE IntersectionPoint()
			{
			}
			
			
			
			
			RIM_INLINE IntersectionPoint( const Vector3& newPoint1, const Vector3& newPoint2, 
										const Vector3& newNormal, Real newDistance )
				:	point1( newPoint1 ),
					point2( newPoint2 ),
					normal( newNormal ),
					penetrationDistance( newDistance )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Reverse Method
			
			
			
			
			/// Reverse this intersection point by swapping the shape intersection points and negating the normal vector.
			RIM_INLINE void reverse()
			{
				Vector3 temp = point1;
				point1 = point2;
				point2 = temp;
				normal = -normal;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The intersection point on the surface of the first intersecting shape.
			Vector3 point1;
			
			
			
			
			/// The intersection point on the surface of the second intersecting shape.
			Vector3 point2;
			
			
			
			
			/// The normal pointing from the intersection on shape 1 to the intersection on shape 2.
			Vector3 normal;
			
			
			
			
			/// The positive penetration distance of the two shapes.
			Real penetrationDistance;
			
			
			
			
};




//##########################################################################################
//**********************  End Rim Physics Utilities Namespace  *****************************
RIM_PHYSICS_UTILITES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_INTERSECTION_POINT_H
