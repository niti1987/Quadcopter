/*
 *  rimGraphicsShaderParameterValue.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 1/30/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_PARAMETER_VALUE_H
#define INCLUDE_RIM_GRAPHICS_SHADER_PARAMETER_VALUE_H


#include "rimGraphicsShadersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which stores a value for a shader parameter.
/**
  * A shader parameter value is a signed integer.
  */
class ShaderParameterValue
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new shader parameter value object with the default value of 0.
			RIM_INLINE ShaderParameterValue()
				:	value( 0 )
			{
			}
			
			
			
			
			/// Create a new shader parameter value object with the specified value.
			RIM_INLINE ShaderParameterValue( Int newValue )
				:	value( newValue )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value Accessor Methods
			
			
			
			
			/// Return the integer value stored by this shader parameter value.
			RIM_INLINE Int getValue() const
			{
				return value;
			}
			
			
			
			
			/// Set the integer value stored by this shader parameter value.
			RIM_INLINE void setValue( Int newValue )
			{
				value = newValue;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An integer value for this shader parameter.
			Int value;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_PARAMETER_VALUE_H
