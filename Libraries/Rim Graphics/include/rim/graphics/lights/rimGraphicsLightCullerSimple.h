/*
 *  rimGraphicsLightCullerSimple.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 5/16/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_LIGHT_CULLER_SIMPLE_H
#define INCLUDE_RIM_GRAPHICS_LIGHT_CULLER_SIMPLE_H


#include "rimGraphicsLightsConfig.h"


#include "rimGraphicsLightCuller.h"


//##########################################################################################
//************************  Start Rim Graphics Lights Namespace  ***************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A simple implementation of the LightCuller interface that provides O(n) performance.
class LightCullerSimple : public LightCuller
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new simple light culler with no lights.
			LightCullerSimple();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Visible Light Accessor Methods
			
			
			
			
			/// Add a pointer for each light that intersects the specified view volume to the output list.
			virtual void getIntersectingLights( const ViewVolume& viewVolume, LightBuffer& outputBuffer ) const;
			
			
			
			
			/// Add a pointer for each light that intersects the specified bounding sphere to the output list.
			virtual void getIntersectingLights( const BoundingSphere& sphere, LightBuffer& outputBuffer ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Method
			
			
			
			
			/// Update the bounding volumes of all lights that are part of this light culler and any spatial data structures.
			virtual void update();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Light Accessor Methods
			
			
			
			
			/// Return the number of lights that are in this light culler.
			virtual Size getLightCount() const;
			
			
			
			
			/// Return whether or not this light culler contains the specified light.
			virtual Bool containsLight( const Pointer<Light>& light ) const;
			
			
			
			
			/// Add the specified light to this light culler.
			virtual Bool addLight( const Pointer<Light>& light );
			
			
			
			
			/// Remove the specified light from this light culler and return whether or not it was removed.
			virtual Bool removeLight( const Pointer<Light>& light );
			
			
			
			
			/// Remove all lights from this light culler.
			virtual void clearLights();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of all of the lights in this simple light culler.
			ArrayList< Pointer<Light> > lights;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics Lights Namespace  *****************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_LIGHT_MANAGER_H
