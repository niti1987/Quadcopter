/*
 *  rimGraphicsLight.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 9/17/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_LIGHT_H
#define INCLUDE_RIM_GRAPHICS_LIGHT_H


#include "rimGraphicsLightsConfig.h"


#include "rimGraphicsLightType.h"
#include "rimGraphicsLightFlags.h"


//##########################################################################################
//************************  Start Rim Graphics Lights Namespace  ***************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a source of light in a scene.
class Light
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a light object.
			RIM_INLINE virtual ~Light()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Light Type Accessor Method
			
			
			
			
			/// Return an object representing the type of this light.
			/**
			  * This value can be used to efficiently determine the derived class of this
			  * light object.
			  */
			RIM_INLINE LightType getType() const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Intensity Accessor Methods
			
			
			
			
			/// Get the intensity of the light source.
			RIM_INLINE Real getIntensity() const
			{
				return intensity;
			}
			
			
			
			
			/// Set the intensity of the light source.
			RIM_INLINE void setIntensity( Real newIntensity )
			{
				intensity = math::max( newIntensity, Real(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Ambient Contribution Accessor Methods
			
			
			
			
			/// Get the ambient contribution of the light source.
			RIM_INLINE Real getAmbientContribution() const
			{
				return ambient;
			}
			
			
			
			
			/// Set the ambient contribution of the light source.
			RIM_INLINE void setAmbientContribution( Real newAmbient )
			{
				ambient = math::max( newAmbient, Real(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Accessor Methods
			
			
			
			
			/// Get the color of the light source.
			RIM_INLINE const Color3f& getColor() const
			{
				return color;
			}
			
			
			
			
			/// Set the color of the light source.
			RIM_INLINE void setColor( const Color3f& newColor )
			{
				color = newColor;
			}
			
			
			
			
			/// Get the color of the light source scaled by the light source's intensity.
			RIM_INLINE Color3f getScaledColor() const
			{
				return color*intensity;
			}
			
			
			
			
			/// Get the ambient color of the light source scaled by the source's intensity and ambient contribution.
			RIM_INLINE Color3f getAmbientColor() const
			{
				return color*ambient*intensity;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shadow Casting Accessor Methods
			
			
			
			
			/// Return whether or not this light can produce shadows.
			RIM_INLINE Bool getShadowsEnabled() const
			{
				return flags.isSet( LightFlags::SHADOWS_ENABLED );
			}
			
			
			
			
			/// Set whether or not this light can produce shadows.
			RIM_INLINE void setShadowsEnabled( Bool newCanCastShadows )
			{
				flags.set( LightFlags::SHADOWS_ENABLED, newCanCastShadows );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flags Accessor Methods
			
			
			
			
			/// Return a reference to an object which contains boolean parameters of the light.
			RIM_INLINE LightFlags& getFlags()
			{
				return flags;
			}
			
			
			
			
			/// Return an object which contains boolean parameters of the light.
			RIM_INLINE const LightFlags& getFlags() const
			{
				return flags;
			}
			
			
			
			
			/// Set an object which contains boolean parameters of the light.
			RIM_INLINE void setFlags( const LightFlags& newFlags )
			{
				flags = newFlags;
			}
			
			
			
			
			/// Return whether or not the specified boolan flag is set for this light.
			RIM_INLINE Bool flagIsSet( LightFlags::Flag flag ) const
			{
				return flags.isSet( flag );
			}
			
			
			
			
			/// Set whether or not the specified boolan flag is set for this light.
			RIM_INLINE void setFlag( LightFlags::Flag flag, Bool newIsSet = true )
			{
				flags.set( flag, newIsSet );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return the name of the light.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set the name of the light.
			RIM_INLINE void setName( const String& newName )
			{
				name = newName;
			}
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default white light with intensity of 1 and no ambient component.
			RIM_INLINE Light( LightType newType )
				:	type( newType ),
					color( Color3f::WHITE ),
					intensity( 1 ),
					ambient( 0 ),
					flags( DEFAULT_LIGHT_FLAGS )
			{
			}
			
			
			
			
			/// Create a light with the specified color and an intensity of 1 and no ambient component.
			RIM_INLINE Light( LightType newType, const Color3f& newColor )
				:	type( newType ),
					color( newColor ),
					intensity( 1 ),
					ambient( 0 ),
					flags( DEFAULT_LIGHT_FLAGS )
			{
			}
			
			
			
			
			/// Create a light with the specified color, intensity, and ambient component.
			RIM_INLINE Light( LightType newType, const Color3f& newColor, Real newIntensity, Real newAmbient )
				:	type( newType ),
					color( newColor ),
					intensity( math::max( newIntensity, Real(0) ) ),
					ambient( math::max( newAmbient, Real(0) ) ),
					flags( DEFAULT_LIGHT_FLAGS )
			{
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The bitwise-or of the default LightFlags for a light.
			static const UInt32 DEFAULT_LIGHT_FLAGS = LightFlags::SHADOWS_ENABLED;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object representing the type of this light.
			LightType type;
			
			
			
			
			/// The 3-component (RGB) color of the light.
			Color3f color;
			
			
			
			
			/// The brightness of the light. This is used to compensate for attenuation.
			/**
			  * Valid values are in the range of [0,infinity].
			  */
			Real intensity;
			
			
			
			
			/// The ambient intensity of the light.
			/**
			  * This is multiplied with the light's intensity to get the final ambient brightness.
			  * Values will typically range from 0 to 1, depending on the ambient illumination of the scene.
			  */
			Real ambient;
			
			
			
			
			/// An object that contains boolean flags for this light.
			LightFlags flags;
			
			
			
			
			/// A name string for this light.
			String name;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics Lights Namespace  *****************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_LIGHT_H
