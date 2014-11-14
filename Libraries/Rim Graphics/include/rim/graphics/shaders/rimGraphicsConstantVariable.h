/*
 *  rimGraphicsConstantVariable.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 9/12/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_CONSTANT_VARIABLE_H
#define INCLUDE_RIM_GRAPHICS_CONSTANT_VARIABLE_H


#include "rimGraphicsShadersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which provides a desciption of a constant shader input variable.
/**
  * A ConstantVariable object contains a description of a constant input
  * variable from a shader's source code. These are variables that are constant across
  * an entire draw call. The description consists of the variable's
  * name, the type of the variable, and an integral location for the
  * variable within the shader.
  */
class ConstantVariable
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a shader attribute variable with the specified name, type, and identifier, and array size.
			/**
			  * This attribute variable represents a variable which is the start of an array of attributes
			  * under the same array name.
			  */
			RIM_INLINE ConstantVariable( const String& newName, const AttributeType& newType,
										ShaderVariableLocation newLocation, Size newArraySize = Size(1) )
				:	name( newName ),
					type( newType ),
					location( newLocation ),
					arraySize( (UByte)newArraySize )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Variable Information Accessor Methods
			
			
			
			
			/// Return the name of the constant variable in the shader source code.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Return an object which describes the type of the constant variable.
			RIM_INLINE const AttributeType& getType() const
			{
				return type;
			}
			
			
			
			
			/// Return the implementation-defined location for the constant variable within the shader.
			RIM_INLINE ShaderVariableLocation getLocation() const
			{
				return location;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Array Accessor Methods
			
			
			
			
			/// Return the number of elements that are in the array starting at this variable.
			/**
			  * For shader variables that are declared as arrays, this function will return the
			  * size of the static variable array. For shader variables that are not arrays, this
			  * function returns 1.
			  */
			RIM_INLINE Size getArraySize() const
			{
				return arraySize;
			}
			
			
			
			
			/// Return whether or not this shader variable denotes the start of its array.
			RIM_INLINE Bool isArray() const
			{
				return arraySize > 1;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The name of the constant variable in a shader's source code.
			String name;
			
			
			
			
			/// The type of the constant variable.
			AttributeType type;
			
			
			
			
			/// The size of the array starting at this constant variable.
			/**
			  * This valid is equal to 1 for variables that are not arrays and will be
			  * the size of the array for array variables.
			  */
			UByte arraySize;
			
			
			
			
			/// The implementation-defined location for the constant variable within the shader.
			ShaderVariableLocation location;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_CONSTANT_VARIABLE_H
