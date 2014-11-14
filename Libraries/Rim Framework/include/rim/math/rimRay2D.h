/*
 *  rimRay2D.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 10/15/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_RAY_2D_H
#define INCLUDE_RIM_RAY_2D_H


#include "rimMathConfig.h"


#include "rimVector2D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a ray in 2D space.
/**
  * This class contains two data members: origin and direction. Origin represents
  * the starting position of the ray and direction represents the positively
  * parameterized direction along the ray.
  */
template < typename T >
class Ray2D
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a ray starting at the origin pointing in the positive Y direction.
			RIM_FORCE_INLINE Ray2D()
				:	origin( 0, 0 ),
					direction( 0, 1 )
			{
			}
			
			
			
			
			/// Create a ray with the specified origin and direction.
			RIM_FORCE_INLINE Ray2D( const Vector2D<T>& newOrigin, const Vector2D<T>& newDirection )
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
			RIM_FORCE_INLINE Vector2D<T> getPositionAt( T parameter ) const
			{
				return origin + parameter*direction;
			}
			
			
			
			
			/// Return a new ray with a unit-length direction vector.
			RIM_FORCE_INLINE Vector2D<T> normalize() const
			{
				return Vector2D<T>( origin, direction.normalize() );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The origin of the ray in 2D space;
			Vector2D<T> origin;
			
			
			
			
			/// The direction of the ray in 2D space.
			Vector2D<T> direction;
			
			
			
			
};




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_RAY_3D_H
