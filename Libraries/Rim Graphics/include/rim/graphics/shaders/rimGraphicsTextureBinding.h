/*
 *  rimGraphicsTextureBinding.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 1/19/11.
 *  Copyright 2011 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_TEXTURE_BINDING_H
#define INCLUDE_RIM_GRAPHICS_TEXTURE_BINDING_H


#include "rimGraphicsShadersConfig.h"


#include "rimGraphicsTextureVariable.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class used to represent the binding between a texture shader variable and its texture and usage.
class TextureBinding
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Variable Accessor Methods
			
			
			
			
			/// Get a reference to the texture variable which this texture binding binds to.
			RIM_FORCE_INLINE const TextureVariable& getVariable() const
			{
				return *variable;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Attribute Usage Accessor Methods
			
			
			
			
			/// Return the semantic usage for this texture binding.
			RIM_FORCE_INLINE const TextureUsage& getUsage() const
			{
				return usage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Offset Accessor Methods
			
			
			
			
			/// Return the starting index for the first texture of this binding in its shader pass's texture storage buffer.
			RIM_FORCE_INLINE UInt getTextureOffset() const
			{
				return textureOffset;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Input Status Accessor Methods
			
			
			
			
			/// Return whether or not this texture binding is a dynamic input to a shader pass.
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
			
			
			
			
			/// Create a texture binding for the specified shader variable, texture offset, and usage.
			RIM_INLINE TextureBinding( const TextureVariable* newVariable, const TextureUsage& newUsage,
										UInt newTextureOffset, Bool newIsInput )
				:	variable( newVariable ),
					usage( newUsage ),
					textureOffset( newTextureOffset ),
					isInput( newIsInput )
			{
				RIM_DEBUG_ASSERT_MESSAGE( newVariable != NULL,
					"Cannot create TextureBinding with NULL shader texture variable." );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the texture variable which this texture binding binds to.
			const TextureVariable* variable;
			
			
			
			
			/// The semantic usage for this texture binding.
			/**
			  * This object allows the creator to specify the semantic usage for the texture
			  * variable. For instance, the usage could be to specify a shadowmap. This
			  * allows the rendering system to automatically update certain shader parameters
			  * that are environmental.
			  */
			TextureUsage usage;
			
			
			
			
			/// The starting index for the first texture of this binding in its shader pass's texture storage buffer.
			UInt textureOffset;
			
			
			
			
			/// A boolean value indicating whether or not this binding represents a dynamic input.
			Bool isInput;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_TEXTURE_BINDING_H
