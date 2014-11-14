/*
 *  rimGraphicsBoundingCone.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 12/23/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_BOUNDING_CONE_H
#define INCLUDE_RIM_GRAPHICS_BOUNDING_CONE_H


#include "rimGraphicsUtilitiesConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a bounding cone for a spot light's area of effect.
class BoundingCone
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a BoundingCone object with the specified vertex, axis direction, half angle, and height.
			RIM_INLINE BoundingCone( const Vector3& newVertex, const Vector3& newAxis,
									Real newTheta, Real newHeight )
				:	vertex( newVertex ),
					axis( newAxis ),
					height( newHeight ),
					sinTheta( math::sin( newTheta ) ),
					cosTheta( math::cos( newTheta ) ),
					theta( newTheta )
			{
			}
			
			
			
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Accessor Methods
			
			
			
			
			/// Get the position of the vertex (tip) of the cone.
			RIM_INLINE const Vector3& getVertex() const
			{
				return vertex;
			}
			
			
			
			
			/// Set the position of the vertex (tip) of the cone.
			RIM_INLINE void setVertex( const Vector3& newVertex )
			{
				vertex = newVertex;
			}
			
			
			
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Axis Accessor Methods
			
			
			
			
			/// Get the normalized direction of the cone's axis from the vertex to the base's center.
			RIM_INLINE const Vector3& getAxis() const
			{
				return axis;
			}
			
			
			
			
			/// Set the normalized direction of the cone's axis from the vertex to the base's center.
			RIM_INLINE void setAxis( const Vector3& newAxis )
			{
				axis = newAxis;
			}
			
			
			
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Height Accessor Methods
			
			
			
			
			/// Get the extent of the cone from the base's center along the cone's axis.
			RIM_INLINE Real getHeight() const
			{
				return height;
			}
			
			
			
			
			/// Set the extent of the cone from the base's center along the cone's axis.
			RIM_INLINE void setHeight( Real newHeight )
			{
				height = newHeight;
			}
			
			
			
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Half Angle Accessor Methods
			
			
			
			
			/// Get the angle in radians between the the cone's axis and the side of the cone.
			RIM_INLINE Real getHalfAngle() const
			{
				return theta;
			}
			
			
			
			
			/// Set the angle in radians between the the cone's axis and the side of the cone.
			RIM_INLINE void setHalfAngle( Real newHalfAngle )
			{
				theta = newHalfAngle;
				sinTheta = math::sin(theta);
				cosTheta = math::cos(theta);
			}
			
			
			
			
			/// Get the sine of the angle in radians between the the cone's axis and the side of the cone.
			RIM_INLINE Real getSineHalfAngle() const
			{
				return sinTheta;
			}
			
			
			
			
			/// Get the cosine of the angle in radians between the the cone's axis and the side of the cone.
			RIM_INLINE Real getCosineHalfAngle() const
			{
				return cosTheta;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Intersection Test Methods
			
			
			
			
			/// Return whether or not this BoundingCone intersects the specified BoundingSphere.
			RIM_NO_INLINE Bool intersects( const BoundingSphere& sphere ) const
			{
				Real inverseSinTheta = Real(1)/sinTheta;
				Real cosThetaSquared = cosTheta*cosTheta;
				Vector3 vertexToSphereCenter = sphere.position - vertex;
				Vector3 d = vertexToSphereCenter + (sphere.radius*inverseSinTheta)*axis;
				Real dMagnitudeSquared = d.getMagnitudeSquared();
				Real e = math::dot( d, axis );
				
				if ( e > Real(0) && e*e >= dMagnitudeSquared*cosThetaSquared )
				{
					Real sinThetaSquared = sinTheta*sinTheta;
					Real vertexToSpereCenterDistanceSquared = vertexToSphereCenter.getMagnitudeSquared();
					Real f = -math::dot( vertexToSphereCenter, axis );
					
					if ( f < -(height + sphere.radius) )
						return false;
					
					if ( f > Real(0) && f*f >= vertexToSpereCenterDistanceSquared*sinThetaSquared )
					{
						return vertexToSpereCenterDistanceSquared <= sphere.radius*sphere.radius;
					}
					else
						return true;
				}
				else
					return false;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The extent of the cone from the base's center along the cone's axis.
			Real height;
			
			
			
			
			/// The vertex of the cone
			Vector3 vertex;
			
			
			
			
			/// The normalized direction from the cone's vertex to the center of the cone's base.
			Vector3 axis;
			
			
			
			
			/// The sine of the half angle of the cone.
			Real sinTheta;
			
			
			
			
			/// The cosine of the half angle of the cone.
			Real cosTheta;
			
			
			
			
			/// The half angle of the cone.
			Real theta;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_BOUNDING_CONE_H
