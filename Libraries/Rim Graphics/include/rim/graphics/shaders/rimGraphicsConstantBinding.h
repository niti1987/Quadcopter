/*
 *  rimGraphicsConstantBinding.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 1/17/11.
 *  Copyright 2011 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_CONSTANT_BINDING_H
#define INCLUDE_RIM_GRAPHICS_CONSTANT_BINDING_H


#include "rimGraphicsShadersConfig.h"


#include "rimGraphicsConstantUsage.h"
#include "rimGraphicsConstantVariable.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class used to represent the binding between a constant shader variable and its value and usage.
class ConstantBinding
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Attribute Variable Accessor Methods
			
			
			
			
			/// Get the shader attribute variable to which a value is bound.
			RIM_FORCE_INLINE const ConstantVariable& getVariable() const
			{
				return *variable;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Attribute Usage Accessor Methods
			
			
			
			
			/// Return the semantic usage for this shader attribute binding.
			RIM_FORCE_INLINE const ConstantUsage& getUsage() const
			{
				return usage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Byte Offset Accessor Methods
			
			
			
			
			/// Return the offset in bytes for this binding's value in its shader pass's constant storage buffer.
			RIM_FORCE_INLINE UInt getByteOffset() const
			{
				return byteOffset;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Input Status Accessor Methods
			
			
			
			
			/// Return whether or not this constant binding is a dynamic input to a shader pass.
			/**
			  * If so, the renderer can provide dynamic scene information for this binding
			  * (such as nearby lights, textures, etc) that aren't explicitly part of this
			  * binding. By default, all bindings are inputs.
			  */
			RIM_INLINE Bool getIsInput() const
			{
				return isInput;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Friend Class Declarations
			
			
			
			
			/// Declare the ShaderPass class a friend so that it can manipulate internal data easily.
			friend class ShaderPass;
			
			
			
			
			/// Declare the ShaderBindingSet class a friend so that it can manipulate internal data easily.
			friend class ShaderBindingSet;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructors
			
			
			
			
			/// Create a constant binding for the specified variable and usage with the given byte offset and input status.
			RIM_INLINE ConstantBinding( const ConstantVariable* newVariable, const ConstantUsage& newUsage,
										UInt newByteOffset, Bool newIsInput )
				:	variable( newVariable ),
					usage( newUsage ),
					byteOffset( newByteOffset ),
					isInput( newIsInput )
			{
				RIM_DEBUG_ASSERT_MESSAGE( newVariable != NULL,
					"Cannot create ConstantBinding with NULL constant variable." );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The constant variable which is bound.
			const ConstantVariable* variable;
			
			
			
			
			/// The semantic usage for this shader attribute binding.
			/**
			  * This object allows the creator to specify the semantic usage for the shader attribute
			  * variable. For instance, the usage could be to specify a light's position. This
			  * allows the rendering system to automatically update certain shader parameters
			  * that are environmental.
			  */
			ConstantUsage usage;
			
			
			
			
			/// An offset in bytes for this binding's value in its shader pass's constant storage buffer.
			UInt byteOffset;
			
			
			
			
			/// A boolean value indicating whether or not this binding represents a dynamic input.
			Bool isInput;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_CONSTANT_BINDING_H
