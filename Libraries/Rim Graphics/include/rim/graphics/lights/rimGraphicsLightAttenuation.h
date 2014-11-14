/*
 *  rimGraphicsLightAttenuation.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 5/16/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_LIGHT_ATTENUATION_H
#define INCLUDE_RIM_GRAPHICS_LIGHT_ATTENUATION_H


#include "rimGraphicsLightsConfig.h"


//##########################################################################################
//************************  Start Rim Graphics Lights Namespace  ***************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An object which describes how the intensity of a light decreases with the distance away from the light.
class LightAttenuation
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default light attenuation object.
			/**
			  * This object is created to have a constant attenuation factor of 1, 
			  * a linear attenuation factor of 0, and a quadratic attenuation factor of 0.
			  */
			RIM_INLINE LightAttenuation()
				:	constantAttenuation( 1 ),
					linearAttenuation( 0 ),
					quadraticAttenuation( 0 )
			{
			}
			
			
			
			
			/// Create a light attenuation object with the specified constant, linear, and quadratic attenuation factors.
			RIM_INLINE LightAttenuation( Real newConstantAttenuation, Real newLinearAttenuation,
										Real newQuadraticAttenuation )
				:	constantAttenuation( newConstantAttenuation ),
					linearAttenuation( newLinearAttenuation ),
					quadraticAttenuation( newQuadraticAttenuation )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constant Attenuation Accessor Methods
			
			
			
			
			/// Get the constant attenuation factor for this light attenuation object.
			RIM_FORCE_INLINE Real getConstant() const
			{
				return constantAttenuation;
			}
			
			
			
			
			/// Set the constant attenuation factor for this light attenuation object.
			RIM_INLINE void setConstant( Real newConstantAttenuation )
			{
				constantAttenuation = math::max( newConstantAttenuation, Real(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Linear Attenuation Accessor Methods
			
			
			
			
			/// Get the linear attenuation factor for this light attenuation object.
			RIM_FORCE_INLINE Real getLinear() const
			{
				return linearAttenuation;
			}
			
			
			
			
			/// Set the linear attenuation factor for this light attenuation object.
			RIM_INLINE void setLinear( Real newLinearAttenuation )
			{
				linearAttenuation = math::max( newLinearAttenuation, Real(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Quadratic Attenuation Accessor Methods
			
			
			
			
			/// Get the quadratic attenuation factor for this light attenuation object.
			RIM_FORCE_INLINE Real getQuadratic() const
			{
				return quadraticAttenuation;
			}
			
			
			
			
			/// Set the quadratic attenuation factor for this light attenuation object.
			RIM_INLINE void setQuadratic( Real newQuadraticAttenuation )
			{
				quadraticAttenuation = math::max( newQuadraticAttenuation, Real(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distance Attenuation Calculation Methods
			
			
			
			
			/// Calculate and return the attenuation amount at the specified distance.
			RIM_INLINE Real getAttenuation( Real distance ) const
			{
				return Real(1) / (constantAttenuation + distance*linearAttenuation + 
									distance*distance*quadraticAttenuation);
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Light Attenuation Data Members
			
			
			
			
			/// The amount that constant attenuation is applied to the light's brightness.
			/**
			  * This value will generally range between 0 and 1 (and cannot be negative). It
			  * indicates the 'c' coefficient of the R^1 term in the denominator of the attenuation
			  * equation: attenuation = 1/(c + a*R^1 + q*R^2).
			  */
			Real constantAttenuation;
			
			
			
			
			/// The amount that linear attenuation is applied to the light's brightness.
			/**
			  * This value will generally range between 0 and 1 (and cannot be negative). It
			  * indicates the 'a' coefficient of the R^1 term in the denominator of the attenuation
			  * equation: attenuation = 1/(c + a*R^1 + q*R^2).
			  */
			Real linearAttenuation;
			
			
			
			
			/// The amount that quadratic attenuation is applied to the light's brightness.
			/**
			  * This value will generally range between 0 and 1 (and cannot be negative). It
			  * indicates the 'q' coefficient of the R^2 term in the denominator of the attenuation
			  * equation: attenuation = 1/(c + a*R^1 + q*R^2).
			  */
			Real quadraticAttenuation;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics Lights Namespace  *****************************
RIM_GRAPHICS_LIGHTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_LIGHT_ATTENUATION_H
