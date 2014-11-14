/*
 *  rimMathPrimitives.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 9/3/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_MATH_PRIMITIVES_H
#define INCLUDE_RIM_MATH_PRIMITIVES_H


#include "rimMathConfig.h"


#include "rimVector2D.h"
#include "rimVector3D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//##########################################################################################
//##########################################################################################
//############		
//############		Edge Class
//############		
//##########################################################################################
//##########################################################################################




template < typename VertexType >
class Edge
{
	public:
		
		RIM_INLINE Edge()
		{
		}
		
		
		
		RIM_INLINE Edge( const VertexType& newV1, const VertexType& newV2 )
			:	v1( newV1 ),
				v2( newV2 )
		{
		}
		
		
		VertexType v1;
		VertexType v2;
		
};




//##########################################################################################
//##########################################################################################
//############		
//############		Triangle Class
//############		
//##########################################################################################
//##########################################################################################




template < typename VertexType >
class Triangle
{
	public:
		
		RIM_INLINE Triangle()
		{
		}
		
		
		
		RIM_INLINE Triangle( const VertexType& newV1, const VertexType& newV2, const VertexType& newV3 )
			:	v1( newV1 ),
				v2( newV2 ),
				v3( newV3 )
		{
		}
		
		
		VertexType v1;
		VertexType v2;
		VertexType v3;
		
};




//##########################################################################################
//##########################################################################################
//############		
//############		Sphere Class
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
class Sphere3D
{
	public:
		
		RIM_INLINE Sphere3D()
			:	radius( 0 )
		{
		}
		
		
		
		RIM_INLINE Sphere3D( T newRadius )
			:	radius( newRadius )
		{
		}
		
		
		
		RIM_INLINE Sphere3D( const Vector3D<T>& newPosition, T newRadius )
			:	position( newPosition ),
				radius( newRadius )
		{
		}
		
		
		
		Vector3D<T> position;
		T radius;
		
};




//##########################################################################################
//##########################################################################################
//############		
//############		Sphere Class
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
class Circle2D
{
	public:
		
		RIM_INLINE Circle2D()
			:	radius( 0 )
		{
		}
		
		
		
		RIM_INLINE Circle2D( T newRadius )
			:	radius( newRadius )
		{
		}
		
		
		
		RIM_INLINE Circle2D( const Vector2D<T>& newPosition, T newRadius )
			:	position( newPosition ),
				radius( newRadius )
		{
		}
		
		
		
		RIM_INLINE bool intersects( const Circle2D<T>& circle ) const
		{
			register T distanceSquared = position.getDistanceToSquared( circle.position );
			register T radii = radius + circle.radius;
			
			return distanceSquared < radii*radii;
		}
		
		
		
		Vector2D<T> position;
		T radius;
		
};




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################



#endif // INCLUDE_RIM_MATH_PRIMITIVES_H
