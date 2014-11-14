/*
 *  rimGraphicsPointLight.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 5/16/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_POINT_LIGHT_H
#define INCLUDE_RIM_GRAPHICS_POINT_LIGHT_H


#include "rimGraphicsLightsConfig.h"


#include "rimGraphicsLight.h"
#include "rimGraphicsLightAttenuation.h"


//##########################################################################################
//************************  Start Rim Graphics Lights Namespace  ***************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a point light source.
/**
  * A point light has all of the standard light attributes (color, intensity, etc),
  * but also has position and distance attenuation attributes.
  */
class PointLight : public Light
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default point light centered at the origin.
			PointLight();
			
			
			
			
			/// Create a default point light at the specified position.
			PointLight( const Vector3& newPosition );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Position Accessor Methods
			
			
			
			
			/// Get the position of this point light in world space.
			RIM_INLINE const Vector3& getPosition() const
			{
				return position;
			}
			
			
			
			
			/// Set the position of this point light in world space.
			RIM_INLINE void setPosition( const Vector3& newPosition )
			{
				position = newPosition;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attenuation Accessor Methods
			
			
			
			
			/// Get an object representing how this point light is attenuated with distance.
			RIM_INLINE LightAttenuation& getAttenuation()
			{
				return attenuation;
			}
			
			
			
			
			/// Get an object representing how this point light is attenuated with distance.
			RIM_INLINE const LightAttenuation& getAttenuation() const
			{
				return attenuation;
			}
			
			
			
			
			/// Set the object representing how this point light is attenuated with distance.
			RIM_INLINE void setAttenuation( const LightAttenuation& newAttenuation )
			{
				attenuation = newAttenuation;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Sphere Accessor Method
			
			
			
			
			/// Get a bounding sphere for this light's area of effect with the specified cutoff intensity.
			BoundingSphere getBoundingSphere( Real cutoffIntensity ) const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The position of this point light in world space.
			Vector3 position;
			
			
			
			
			/// An object which models the distance attenuation of this light source.
			LightAttenuation attenuation;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics Lights Namespace  *****************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_POINT_LIGHT_H
