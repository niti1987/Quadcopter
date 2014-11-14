/*
 *  rimGraphicsDirectionalLight.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 5/16/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_DIRECTIONAL_LIGHT_H
#define INCLUDE_RIM_GRAPHICS_DIRECTIONAL_LIGHT_H


#include "rimGraphicsLightsConfig.h"


#include "rimGraphicsLight.h"


//##########################################################################################
//************************  Start Rim Graphics Lights Namespace  ***************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a simple directional light source.
/**
  * A directional light source has all of the standard light attributes (color, intensity),
  * and also has a direction in which it is pointing. A directional light affects the
  * entire scene and can be used to approximate a very distant point light source
  * such as the sun.
  */
class DirectionalLight : public Light
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default directional light source with the default direction (1,0,0).
			DirectionalLight();
			
			
			
			
			/// Create a directional light source with the specified direction.
			DirectionalLight( const Vector3& newDirection );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Direction Accessor Methods
			
			
			
			
			/// Get the direction where this directional light is pointing.
			RIM_INLINE const Vector3& getDirection() const
			{
				return direction;
			}
			
			
			
			
			/// Set the direction where this directional light should point.
			RIM_INLINE void setDirection( const Vector3& newDirection )
			{
				direction = newDirection;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The direction that this directional light is pointing in.
			Vector3 direction;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics Lights Namespace  *****************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_POINT_LIGHT_H
