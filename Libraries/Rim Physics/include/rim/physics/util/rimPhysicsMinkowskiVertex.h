/*
 *  rimPhysicsMinkowskiVertex.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 6/7/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_MINKOWSKI_VERTEX_H
#define INCLUDE_RIM_PHYSICS_MINKOWSKI_VERTEX_H


#include "rimPhysicsUtilitiesConfig.h"


//##########################################################################################
//**********************  Start Rim Physics Utilities Namespace  ***************************
RIM_PHYSICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a point on the minkowski difference between two collision shapes.
template < typename T >
class MinkowskiVertex3D
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a vertex in minkowski space representing the origin.
			RIM_INLINE MinkowskiVertex3D()
			{
			}
			
			
			
			
			/// Create a vertex in minkowski space from the two cartesian vertices.
			RIM_INLINE MinkowskiVertex3D( const Vector3D<T>& newPoint1, const Vector3D<T>& newPoint2 )
				:	point( newPoint1 - newPoint2 ),
					pointOnShape2( newPoint2 )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point Accessor Methods
			
			
			
			
			/// Return the position of this minkowski vertex in minkowski difference space.
			RIM_FORCE_INLINE const Vector3D<T>& getPosition() const
			{
				return point;
			}
			
			
			
			
			/// Return the position of this minkowski vertex on the first shape in world space.
			RIM_FORCE_INLINE Vector3D<T> getPositionOnShape1() const
			{
				return point + pointOnShape2;
			}
			
			
			
			
			/// Return the position of this minkowski vertex on the second shape in world space.
			RIM_FORCE_INLINE const Vector3D<T>& getPositionOnShape2() const
			{
				return pointOnShape2;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Cast Operators
			
			
			
			
			/// Cast this minkowski vertex to a 3D vector representing the position of the vertex in minkowski space.
			RIM_FORCE_INLINE operator const Vector3D<T>& () const
			{
				return point;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Negation Operator
			
			
			
			
			/// Return the negation of this minkowski vertex's position in minkowski space.
			RIM_FORCE_INLINE Vector3D<T> operator - () const
			{
				return -point;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Arithmetic Operators
			
			
			
			
			/// Add the minkowski space vertex position of this vertex and another and return the result.
			RIM_FORCE_INLINE Vector3D<T> operator + ( const MinkowskiVertex3D<T>& other ) const
			{
				return point + other.point;
			}
			
			
			
			
			/// Subtract the minkowski space vertex position of this vertex and another and return the result.
			RIM_FORCE_INLINE Vector3D<T> operator - ( const MinkowskiVertex3D<T>& other ) const
			{
				return point - other.point;
			}
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The vertex's position in minkowski space.
			/**
			  * This is equal to the point on shape 1 minus the point on
			  * shape 2.
			  */
			Vector3D<T> point;
			
			
			
			
			/// The world-space position of this minkowski vertex on the second collision shape.
			Vector3D<T> pointOnShape2;
			
			
			
			
};




typedef MinkowskiVertex3D<rim::physics::Real> MinkowskiVertex3;
typedef MinkowskiVertex3D<Float> MinkowskiVertex3f;
typedef MinkowskiVertex3D<Double> MinkowskiVertex3d;




//##########################################################################################
//**********************  End Rim Physics Utilities Namespace  *****************************
RIM_PHYSICS_UTILITES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_MINKOWSKI_VERTEX_H
