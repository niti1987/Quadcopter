/*
 *  rimGraphicsSpotLight.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 5/16/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SPOT_LIGHT_H
#define INCLUDE_RIM_GRAPHICS_SPOT_LIGHT_H


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
/// A class which represents a conical spot light source.
class SpotLight : public Light
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default 90 degree spot light positioned at the origin, pointing the positive X direction.
			SpotLight();
			
			
			
			
			/// Create a new spot light with the specified position, direction, and spot cutoff.
			SpotLight( const Vector3& newPosition, const Vector3& newDirection, Real newSpotCutoff );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Position Accessor Methods
			
			
			
			
			/// Get the position of this spot light in world space.
			RIM_INLINE const Vector3& getPosition() const
			{
				return position;
			}
			
			
			
			
			/// Set the position of this spot light in world space.
			RIM_INLINE void setPosition( const Vector3& newPosition )
			{
				position = newPosition;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Direction Accessor Methods
			
			
			
			
			/// Get the direction that this spot light is facing.
			RIM_INLINE const Vector3& getDirection() const
			{
				return direction;
			}
			
			
			
			
			/// Set the direction that this spot light is facing.
			RIM_INLINE void setDirection( const Vector3& newDirection )
			{
				direction = newDirection;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Spot Cutoff Angle Accessor Methods
			
			
			
			
			/// Get the spot cutoff angle of this spot light in degrees.
			/**
			  * This is the maximum angle from the spot light's direction that
			  * light will be produced.
			  */
			RIM_INLINE Real getCutoff() const
			{
				return cutoff;
			}
			
			
			
			
			/// Set the spot cutoff angle of this spot light in degrees.
			/**
			  * This is the maximum angle from the spot light's direction that
			  * light will be produced. The input value is clamped to the valid range of
			  * [0,90].
			  */
			RIM_INLINE void setCutoff( Real newCutoffAngle )
			{
				cutoff = math::clamp( newCutoffAngle, Real(0), Real(90) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Spot Exponent Accessor Methods
			
			
			
			
			/// Return the spot exponent for this spot light.
			/**
			  * If this value is 0, it will result in a spot light with uniform
			  * light distribution across the spot area. A value greater than 0 will
			  * cause the light to be more focused toward the center of the light spot.
			  */
			RIM_INLINE Real getExponent() const
			{
				return exponent;
			}
			
			
			
			
			/// Set the spot exponent for this spot light.
			/**
			  * If this value is 0, it will result in a spot light with uniform
			  * light distribution across the spot area. A value greater than 0 will
			  * cause the light to be more focused toward the center of the light spot.
			  */
			RIM_INLINE void setExponent( Real newSpotExponent )
			{
				exponent = newSpotExponent;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Falloff Accessor Methods
			
			
			
			
			/// Return the falloff size of this spot light.
			/**
			  * This value is used to create a smooth transition from 100% illuination to
			  * 0% illumination outside of the spot light's cutoff angle. This value is
			  * multiplied by the cutoff angle to determine how many degrees that falloff
			  * spans.
			  */
			RIM_INLINE Real getFalloff() const
			{
				return falloff;
			}
			
			
			
			
			/// Set the falloff size of this spot light.
			/**
			  * This value is used to create a smooth transition from 100% illuination to
			  * 0% illumination outside of the spot light's cutoff angle. This value is
			  * multiplied by the cutoff angle to determine how many degrees that falloff
			  * spans.
			  *
			  * The new falloff value is clamped to the range [0,1].
			  */
			RIM_INLINE void setFalloff( Real newFallOff )
			{
				falloff = math::clamp( newFallOff, Real(0), Real(1) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attenuation Accessor Methods
			
			
			
			
			/// Get an object representing how this spot light is attenuated with distance.
			RIM_INLINE LightAttenuation& getAttenuation()
			{
				return attenuation;
			}
			
			
			
			
			/// Get an object representing how this spot light is attenuated with distance.
			RIM_INLINE const LightAttenuation& getAttenuation() const
			{
				return attenuation;
			}
			
			
			
			
			/// Set the object representing how this spot light is attenuated with distance.
			RIM_INLINE void setAttenuation( const LightAttenuation& newAttenuation )
			{
				attenuation = newAttenuation;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Cone Accessor Method
			
			
			
			
			/// Get a bounding cone for this light's area of effect with the specified cutoff intensity.
			BoundingCone getBoundingCone( Real cutoffIntensity ) const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The position of this spot light in world space.
			Vector3 position;
			
			
			
			
			/// The direction that this spot light is facing.
			Vector3 direction;
			
			
			
			
			/// An object which models the distance attenuation from this light source.
			LightAttenuation attenuation;
			
			
			
			
			/// This value determines the fraction of the spot light's angular width where the spot intensity falls off.
			/**
			  * This value is used to create a smooth transition from 100% illuination to
			  * 0% illumination outside of the spot light's cutoff angle. This value is
			  * multiplied by the cutoff angle to determine how many degrees that falloff
			  * spans.
			  */
			Real falloff;
			
			
			
			
			/// The exponent of the spot light.
			/**
			  * This value determines how focused the light is towards the center of the spot.
			  */
			Real exponent;
			
			
			
			
			/// The cutoff angle of the spot light in degrees.
			/**
			  * This is the maximum angle from the spot light's direction that
			  * light will be produced.
			  */
			Real cutoff;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics Lights Namespace  *****************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SPOT_LIGHT_H
