/*
 *  rimGraphicsLightBuffer.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 5/17/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_LIGHT_BUFFER_H
#define INCLUDE_RIM_GRAPHICS_LIGHT_BUFFER_H


#include "rimGraphicsLightsConfig.h"


#include "rimGraphicsLight.h"
#include "rimGraphicsDirectionalLight.h"
#include "rimGraphicsPointLight.h"
#include "rimGraphicsSpotLight.h"


//##########################################################################################
//************************  Start Rim Graphics Lights Namespace  ***************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




class LightBuffer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			RIM_INLINE LightBuffer()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Directional Light Accessor Methods
			
			
			
			
			/// Return a pointer to the directional light contained in this light buffer at the specified index.
			RIM_INLINE Size getDirectionalLightCount() const
			{
				return directionalLights.getSize();
			}
			
			
			
			
			/// Return a pointer to the directional light contained in this light buffer at the specified index.
			RIM_INLINE const Pointer<DirectionalLight>& getDirectionalLight( Index index ) const
			{
				return directionalLights[index].light;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point Light Accessor Methods
			
			
			
			
			/// Return a pointer to the point light contained in this light buffer at the specified index.
			RIM_INLINE Size getPointLightCount() const
			{
				return pointLights.getSize();
			}
			
			
			
			
			/// Return a pointer to the directional light contained in this light buffer at the specified index.
			RIM_INLINE const Pointer<PointLight>& getPointLight( Index index ) const
			{
				return pointLights[index].light;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Spot Light Accessor Methods
			
			
			
			
			/// Return a pointer to the spot light contained in this light buffer at the specified index.
			RIM_INLINE Size getSpotLightCount() const
			{
				return spotLights.getSize();
			}
			
			
			
			
			/// Return a pointer to the spot light contained in this light buffer at the specified index.
			RIM_INLINE const Pointer<SpotLight>& getSpotLight( Index index ) const
			{
				return spotLights[index].light;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Light Add Methods
			
			
			
			
			/// Add the specified directional light to this light buffer.
			RIM_INLINE void addLight( const Pointer<DirectionalLight>& newDirectionalLight )
			{
				directionalLights.add( LightIntensity<DirectionalLight>( newDirectionalLight ) );
			}
			
			
			
			
			/// Add the specified point light to this light buffer.
			RIM_INLINE void addLight( const Pointer<PointLight>& newPointLight )
			{
				pointLights.add( LightIntensity<PointLight>( newPointLight ) );
			}
			
			
			
			
			/// Add the specified spot light to this light buffer.
			RIM_INLINE void addLight( const Pointer<SpotLight>& newSpotLight )
			{
				spotLights.add( LightIntensity<SpotLight>( newSpotLight ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Clear Methods
			
			
			
			
			/// Remove all of the lights from this light buffer.
			RIM_INLINE void removeAllLights()
			{
				directionalLights.clear();
				pointLights.clear();
				spotLights.clear();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Light Sorting Method
			
			
			
			
			/// Sort each type of light independently in order of decreasing intensity for the specified detector.
			void sortLightsByDecreasingIntensity( const BoundingSphere& detector );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			template < typename LightType >
			class LightIntensity
			{
				public:
					
					
					RIM_INLINE LightIntensity( const Pointer<LightType>& newLight )
						:	light( newLight ),
							intensity( 0 )
					{
					}
					
					
					Real intensity;
					const Pointer<LightType> light;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < typename LightType >
			static void sortLightsByDecreasingIntensity( ArrayList<LightIntensity<LightType> >& list );
			
			
			
			
			template < typename LightType >
			static int compareLightIntensities( const void* a, const void* b );
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of all of the directional lights in this light buffer.
			ArrayList<LightIntensity<DirectionalLight> > directionalLights;
			
			
			
			
			/// A list of all of the point lights in this light buffer.
			ArrayList<LightIntensity<PointLight> > pointLights;
			
			
			
			
			/// A list of all of the spot lights in this light buffer.
			ArrayList<LightIntensity<SpotLight> > spotLights;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics Lights Namespace  *****************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_LIGHT_BUFFER_H
