/*
 *  rimGraphicsGenericTextureBinding.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 9/26/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GENERIC_TEXTURE_BINDING_H
#define INCLUDE_RIM_GRAPHICS_GENERIC_TEXTURE_BINDING_H


#include "rimGraphicsShadersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An object that encapsulates information about the binding of a texture to a name and usage.
class GenericTextureBinding
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new generic texture binding object with no name, UNDEFINED usage, and NULL image.
			RIM_INLINE GenericTextureBinding()
				:	name(),
					usage( TextureUsage::UNDEFINED ),
					texture(),
					isInput( true )
			{
			}
			
			
			
			
			/// Create a new generic texture binding object with the specified name, usage, and texture image.
			RIM_INLINE GenericTextureBinding( const String& newName, const TextureUsage& newUsage )
				:	name( newName ),
					usage( newUsage ),
					texture(),
					isInput( true )
			{
			}
			
			
			
			
			/// Create a new generic texture binding object with the specified name, usage, and texture image.
			RIM_INLINE GenericTextureBinding( const String& newName, const Resource<GenericTexture>& newTexture,
											const TextureUsage& newUsage, Bool newIsInput = true )
				:	name( newName ),
					usage( newUsage ),
					texture( newTexture ),
					isInput( true )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Binding Name Accessor Methods
			
			
			
			
			/// Return a string representing the name of the texture binding.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set a string representing the name of the texture binding.
			RIM_INLINE void setName( const String& newName )
			{
				name = newName;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Binding Usage Accessor Methods
			
			
			
			
			/// Return an enum value indicating the semantic usage of this texture binding.
			RIM_INLINE const TextureUsage& getUsage() const
			{
				return usage;
			}
			
			
			
			
			/// Set an enum value indicating the semantic usage of this texture binding.
			RIM_INLINE void setUsage( const TextureUsage& newUsage )
			{
				usage = newUsage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Binding Image Accessor Methods
			
			
			
			
			/// Return a pointer to the texture used for this texture binding.
			RIM_INLINE const Resource<GenericTexture>& getTexture() const
			{
				return texture;
			}
			
			
			
			
			/// Set a pointer to the texture used for this texture binding.
			RIM_INLINE void setTexture( const Resource<GenericTexture>& newTexture )
			{
				texture = newTexture;
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
			
			
			
			
			/// Set whether or not this texture binding is a dynamic input to a shader pass.
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
			
			
			
			
			/// A string representing the name of the texture binding.
			String name;
			
			
			
			
			/// An enum value indicating the semantic usage of this texture binding.
			TextureUsage usage;
			
			
			
			
			/// A pointer to the texture used for this texture binding.
			Resource<GenericTexture> texture;
			
			
			
			
			/// A boolean value indicating whether or not this binding represents a dynamic input.
			Bool isInput;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GENERIC_TEXTURE_BINDING_H
