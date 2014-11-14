/*
 *  rimGraphicsShaderParameter.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 1/30/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_PARAMETER_H
#define INCLUDE_RIM_GRAPHICS_SHADER_PARAMETER_H


#include "rimGraphicsShadersConfig.h"


#include "rimGraphicsShaderParameterInfo.h"
#include "rimGraphicsShaderParameterValue.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains the entire state for a shader parameter.
/**
  * This state includes information about the shader parameter as well as its
  * value.
  */
class ShaderParameter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new UNDEFINED shader parameter object with the value 0.
			RIM_INLINE ShaderParameter()
				:	info(),
					value()
			{
			}
			
			
			
			
			/// Create a new shader parameter object with the specified info and value.
			RIM_INLINE ShaderParameter( const ShaderParameterInfo& newInfo, const ShaderParameterValue& newValue )
				:	info( newInfo ),
					value( newValue )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Info Accessor Methods
			
			
			
			
			/// Return an object describing information about this shader parameter.
			RIM_INLINE const ShaderParameterInfo& getInfo() const
			{
				return info;
			}
			
			
			
			
			/// Set an object describing information about this shader parameter.
			RIM_INLINE void setInfo( const ShaderParameterInfo& newInfo )
			{
				info = newInfo;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return a string representing the name for this shader parameter.
			RIM_INLINE const String& getName() const
			{
				return info.getName();
			}
			
			
			
			
			/// Set a string representing the name for this shader parameter.
			RIM_INLINE void setName( const String& newName )
			{
				info.setName( newName );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Usage Accessor Methods
			
			
			
			
			/// Return an object describing the semantic usage of this shader parameter.
			RIM_INLINE const ShaderParameterUsage& getUsage() const
			{
				return info.getUsage();
			}
			
			
			
			
			/// Set an object describing the semantic usage of this shader parameter.
			RIM_INLINE void setUsage( const ShaderParameterUsage& newInfo )
			{
				info.setUsage( newInfo );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value Accessor Methods
			
			
			
			
			/// Return an object which contains the value for this shader parameter.
			RIM_INLINE const ShaderParameterValue& getValue() const
			{
				return value;
			}
			
			
			
			
			/// Set an object containing a new value for this shader parameter.
			RIM_INLINE void setValue( const ShaderParameterValue& newValue )
			{
				value = newValue;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object describing information about this shader parameter.
			ShaderParameterInfo info;
			
			
			
			
			/// The value for this shader parameter.
			ShaderParameterValue value;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_PARAMETER_H
