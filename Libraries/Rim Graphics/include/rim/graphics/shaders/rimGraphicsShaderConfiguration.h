/*
 *  rimGraphicsShaderConfiguration.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 1/30/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_CONFIGURATION_H
#define INCLUDE_RIM_GRAPHICS_SHADER_CONFIGURATION_H


#include "rimGraphicsShadersConfig.h"


#include "rimGraphicsShaderParameter.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains a configuration for a shader.
/**
  * A configuration consists of a list of ShaderParameter objects that determine
  * how a shader should be compiled.
  */
class ShaderConfiguration
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new shader configuration with no parameters.
			RIM_INLINE ShaderConfiguration()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parameter Accessor Methods
			
			
			
			
			/// Return the number of shader parameters that this configuration has.
			RIM_INLINE Size getParameterCount() const
			{
				return parameters.getSize();
			}
			
			
			
			
			/// Return a reference to the shader parameter at the specified index in this configuration.
			RIM_INLINE ShaderParameter& getParameter( Index parameterIndex )
			{
				return parameters[parameterIndex];
			}
			
			
			
			
			/// Return a const reference to the shader parameter at the specified index in this configuration.
			RIM_INLINE const ShaderParameter& getParameter( Index parameterIndex ) const
			{
				return parameters[parameterIndex];
			}
			
			
			
			
			/// Replace the shader parameter at the specified index in this configuration.
			RIM_INLINE void setParameter( Index parameterIndex, const ShaderParameter& newParameter )
			{
				parameters[parameterIndex] = newParameter;
			}
			
			
			
			
			/// Set the value of the parameter in this configuration at the specified index.
			void setParameterValue( Index parameterIndex, const ShaderParameterValue& newValue )
			{
				parameters[parameterIndex].setValue( newValue );
			}
			
			
			
			
			/// Set the value of the parameter in this configuration with the specified usage.
			/**
			  * If there is a parameter with that usage, its value is set to the new value
			  * and TRUE is returned. Otherwise, the method fails and FALSE is returned.
			  */
			Bool setParameterValueForUsage( const ShaderParameterUsage& usage, const ShaderParameterValue& newValue );
			
			
			
			
			/// Add a new shader parameter to the end of this configuration's list of parameters.
			RIM_INLINE void addParameter( const ShaderParameter& newParameter )
			{
				parameters.add( newParameter );
			}
			
			
			
			
			/// Add a new shader parameter with the given attributes to the end of this configuration's list of parameters.
			RIM_INLINE void addParameter( const String& parameterName, const ShaderParameterUsage& usage,
											const ShaderParameterValue& value )
			{
				parameters.add( ShaderParameter( ShaderParameterInfo( parameterName, usage ), value ) );
			}
			
			
			
			
			/// Remove the shader parameter at the specified index in this configuration.
			/**
			  * This method maintains the order of the remaining parameters.
			  */
			RIM_INLINE void removeParameter( Index parameterIndex )
			{
				parameters.removeAtIndex( parameterIndex );
			}
			
			
			
			
			/// Clear all shader parameters from this shader configuration.
			RIM_INLINE void clearParameters()
			{
				parameters.clear();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the shader parameters that are part of this shader configuration.
			ArrayList<ShaderParameter> parameters;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_CONFIGURATION_H
