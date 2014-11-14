/*
 *  rimGraphicsLightType.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 10/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_LIGHT_TYPE_H
#define INCLUDE_RIM_GRAPHICS_LIGHT_TYPE_H


#include "rimGraphicsLightsConfig.h"


//##########################################################################################
//************************  Start Rim Graphics Lights Namespace  ***************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the type of a light.
class LightType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Enum Declaration
			
			
			
			
			/// An enum which specifies the different allowed texture faces.
			typedef enum Enum
			{
				/// A light which radiates light evenly in all directions from single point.
				/**
				  * All Light objects that have this type value can be assumed to be instances
				  * of the class PointLight.
				  */
				POINT = 1,
				
				/// A light which radiates light from a single point to a cone-shaped area.
				/**
				  * All Light objects that have this type value can be assumed to be instances
				  * of the class SpotLight.
				  */
				SPOT = 2,
				
				/// A light which has no position and only direction.
				/**
				  * This light type is equivalent to an infinitely far away point light and
				  * is often used to approximate these cases.
				  *
				  * All Light objects that have this type value can be assumed to be instances
				  * of the class DirectionalLight.
				  */
				DIRECTIONAL = 3,
				
				/// The base value for user-defined light types.
				/**
				  * Users can define new types of lights using this value as a base value,
				  * plus some positive integer offset. All types greater than or equal to
				  * this value are valid user light types.
				  */
				USER = 0x1000,
				
				/// An undefined light type.
				UNDEFINED = 0
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new light type with the specified light type enum value.
			RIM_INLINE LightType( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
			/// Create a new light type with the specified user-defined light type value.
			/**
			  * This value should be greater than or equal to the value of LightType::USER
			  * in order to avoid collisions with predefined light types.
			  */
			RIM_INLINE LightType( UInt newUserType )
				:	userType( newUserType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this light type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the light type.
			String toString() const;
			
			
			
			
			/// Convert this light type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			union
			{
				/// An enum value which represents the light type.
				Enum type;
				
				
				/// An integer value that represents a user-defined light type.
				UInt userType;
			};
			
			
};




//##########################################################################################
//************************  End Rim Graphics Lights Namespace  *****************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_LIGHT_TYPE_H
