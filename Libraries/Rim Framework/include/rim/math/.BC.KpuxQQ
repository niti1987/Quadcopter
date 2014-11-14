/*
 *  rimRay3D.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 5/14/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_RAY_3D_H
#define INCLUDE_RIM_RAY_3D_H


#include "rimMathConfig.h"


#include "rimVector3D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a ray in 3D space.
/**
  * This class contains two data members: origin and direction. Origin represents
  * the starting position of the ray and direction represents the positively
  * parameterized direction along the ray.
  */
template < typename T >
class Ray3D
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a ray starting at the origin pointing in the positive Z direction.
			RIM_FORCE_INLINE Ray3D()
				:	origin( 0, 0, 0 ),
					direction( 0, 0, 1 )
			{
			}
			
			
			
			
			/// Create a ray with the specified origin and direction.
			RIM_FORCE_INLINE Ray3D( const Vector3D<T>& newOrigin, const Vector3D<T>& newDirection )
				:	origin( newOrigin ),
					direction( newDirection )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Ray Methods
			
			
			
			
			/// Get the position along the ray at the specified parameter value.
			/**
			  * This position is calculated using the equation:
			  * position = origin + parameter*direction.
			  */
			RIM_FORCE_INLINE Vector3D<T> getPositionAt( T parameter ) const
			{
				return origin + parameter*direction;
			}
			
			
			
			
			/// Return a new ray with a unit-length direction vector.
			RIM_FORCE_INLINE Ray3D<T> normalize() const
			{
				return Ray3D<T>( origin, direction.normalize() );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The origin of the ray in 3D space;
			Vector3D<T> origin;
			
			
			
			
			/// The direction of the ray in 3D space.
			Vector3D<T> direction;
			
			
			
			
};




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_RAY_3D_H
