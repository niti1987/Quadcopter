/*
 *  rimGraphicsLightCuller.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 12/25/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_LIGHT_CULLER_H
#define INCLUDE_RIM_GRAPHICS_LIGHT_CULLER_H


#include "rimGraphicsLightsConfig.h"


#include "rimGraphicsLight.h"
#include "rimGraphicsLightBuffer.h"


//##########################################################################################
//************************  Start Rim Graphics Lights Namespace  ***************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class interface which determines which lights in a scene are visible to cameras and objects.
/**
  * This class keeps an internal set of lights that it queries for visibility.
  *
  * Typically, a class implementing this interface will have data structures
  * that speed up the O(n) problem of determining which lights intersect any given
  * bounding sphere or view volume.
  */
class LightCuller
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new light culler with the default light intensity cutoff value of 0.01.
			RIM_INLINE LightCuller()
				:	cutoff( 0.01f )
			{
			}
			
			
			
			
			/// Create a new light culler with specified light intensity cutoff value.
			/**
			  * The input cutoff value is clamped to the valid range of [0,+infinity].
			  */
			RIM_INLINE LightCuller( Real newCutoff )
				:	cutoff( math::max( newCutoff, Real(0) ) )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this light culler.
			virtual ~LightCuller()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Visible Light Accessor Methods
			
			
			
			
			/// Add a pointer to each light that intersects the specified view volume to the output list.
			virtual void getIntersectingLights( const ViewVolume& viewVolume, LightBuffer& outputBuffer ) const = 0;
			
			
			
			
			/// Add a pointer to each light that intersects the specified bounding sphere to the output list.
			virtual void getIntersectingLights( const BoundingSphere& sphere, LightBuffer& outputBuffer ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Method
			
			
			
			
			/// Update the bounding volumes of all lights that are part of this light culler and any spatial data structures.
			virtual void update() = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Light Cutoff Accessor Methods
			
			
			
			
			/// Return the light intensity cutoff value at which lights are no longer considered visible.
			RIM_INLINE Real getCutoff() const
			{
				return cutoff;
			}
			
			
			
			
			/// Set the light intensity cutoff value at which lights are no longer considered visible.
			/**
			  * The input cutoff value is clamped to the valid range of [0,+infinity].
			  */
			RIM_INLINE void setCutoff( Real newCutoff )
			{
				cutoff = math::max( newCutoff, Real(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Light Accessor Methods
			
			
			
			
			/// Return the number of lights that are in this light culler.
			virtual Size getLightCount() const = 0;
			
			
			
			
			/// Return whether or not this light culler contains the specified light.
			virtual Bool containsLight( const Pointer<Light>& light ) const = 0;
			
			
			
			
			/// Add the specified light to this light culler.
			virtual Bool addLight( const Pointer<Light>& light ) = 0;
			
			
			
			
			/// Remove the specified light from this light culler and return whether or not it was removed.
			virtual Bool removeLight( const Pointer<Light>& light ) = 0;
			
			
			
			
			/// Clear all lights from this light culler.
			virtual void clearLights() = 0;
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Data Members
			
			
			
			
			/// The light intensity cutoff value at which lights are no longer considered visible.
			Real cutoff;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics Lights Namespace  *****************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_LIGHT_MANAGER_H
