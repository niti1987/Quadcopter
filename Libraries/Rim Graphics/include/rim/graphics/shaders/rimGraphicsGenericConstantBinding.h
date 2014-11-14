/*
 *  rimGraphicsGenericConstantBinding.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 9/26/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GENERIC_CONSTANT_BINDING_H
#define INCLUDE_RIM_GRAPHICS_GENERIC_CONSTANT_BINDING_H


#include "rimGraphicsShadersConfig.h"


#include "rimGraphicsConstantUsage.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An object that encapsulates information about the binding of a constant to a name and usage.
class GenericConstantBinding
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new generic constant binding object with no name, UNDEFINED usage, and no value.
			RIM_INLINE GenericConstantBinding()
				:	name(),
					usage( ConstantUsage::UNDEFINED ),
					value(),
					isInput( true )
			{
			}
			
			
			
			
			/// Create a new generic constant binding object with the specified name, usage, and value.
			RIM_INLINE GenericConstantBinding( const String& newName, const ConstantUsage& newUsage )
				:	name( newName ),
					usage( newUsage ),
					value(),
					isInput( true )
			{
			}
			
			
			
			
			/// Create a new generic constant binding object with the specified name, usage, and value.
			RIM_INLINE GenericConstantBinding( const String& newName, const AttributeValue& newValue,
												const ConstantUsage& newUsage, Bool newIsInput = true )
				:	name( newName ),
					usage( newUsage ),
					value( newValue ),
					isInput( newIsInput )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Binding Name Accessor Methods
			
			
			
			
			/// Return a string representing the name of the constant binding.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set a string representing the name of the constant binding.
			RIM_INLINE void setName( const String& newName )
			{
				name = newName;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Binding Usage Accessor Methods
			
			
			
			
			/// Return an enum value indicating the semantic usage of this constant binding.
			RIM_INLINE const ConstantUsage& getUsage() const
			{
				return usage;
			}
			
			
			
			
			/// Set an enum value indicating the semantic usage of this constant binding.
			RIM_INLINE void setUsage( const ConstantUsage& newUsage )
			{
				usage = newUsage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constant Binding Value Accessor Methods
			
			
			
			
			/// Return an object which contains the constant value for this constant binding.
			RIM_INLINE AttributeValue& getValue()
			{
				return value;
			}
			
			
			
			
			/// Return an object which contains the constant value for this constant binding.
			RIM_INLINE const AttributeValue& getValue() const
			{
				return value;
			}
			
			
			
			
			/// Set an object which contains the constant value for this constant binding.
			RIM_INLINE void setValue( const AttributeValue& newValue )
			{
				value = newValue;
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
			
			
			
			
			/// Set whether or not this constant binding is a dynamic input to a shader pass.
			/**
			  * If so, the renderer can provide dynamic scene information for this binding
			  * (such as nearby lights, textures, etc) that aren't explicitly part of this
			  * binding.
			  */
			RIM_INLINE void setIsInput( Bool newInput )
			{
				isInput = newInput;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A string representing the name of the constant binding.
			String name;
			
			
			
			
			/// An enum value indicating the semantic usage of this constant binding.
			ConstantUsage usage;
			
			
			
			
			/// An object which contains the constant value for this constant binding.
			AttributeValue value;
			
			
			
			
			/// A boolean value indicating whether or not this binding represents a dynamic input.
			Bool isInput;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GENERIC_CONSTANT_BINDING_H
