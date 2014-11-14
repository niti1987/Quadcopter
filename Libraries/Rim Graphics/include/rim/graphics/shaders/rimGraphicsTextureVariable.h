/*
 *  rimGraphicsTextureVariable.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 9/12/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_TEXTURE_VARIABLE_H
#define INCLUDE_RIM_GRAPHICS_TEXTURE_VARIABLE_H


#include "rimGraphicsShadersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a shader texture input variable.
/**
  * A TextureVariable object contains a description of a texture input
  * variable in a shader's source code. The description consists of the variable's
  * name, the type of the texture variable, and an integral identifier for the texture
  * variable within the shader.
  */
class TextureVariable
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a texture variable with the specified name, type, and identifier.
			RIM_INLINE TextureVariable( const String& newName, const TextureType& newType,
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
		//******	Attribute Accessor Methods
			
			
			
			
			/// Get the name of the texture variable in the shader source code.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Get the type of this texture variable within the shader.
			RIM_INLINE const TextureType& getType() const
			{
				return type;
			}
			
			
			
			
			/// Return the implementation-defined location for the texture variable within the shader.
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
			
			
			
			
			/// The name of the texture attribute variable in the shader's source code.
			String name;
			
			
			
			
			/// The type of the texture variable within the shader source code.
			TextureType type;
			
			
			
			
			/// The size of the array starting at this constant variable.
			/**
			  * This valid is equal to 1 for variables that are not arrays and will be
			  * the size of the array for array variables.
			  */
			UByte arraySize;
			
			
			
			
			/// The implementation-defined location for the texture variable within the shader.
			ShaderVariableLocation location;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_TEXTURE_VARIABLE_H
