/*
 *  rimGraphicsGenericVertexBinding.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 9/26/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GENERIC_VERTEX_BINDING_H
#define INCLUDE_RIM_GRAPHICS_GENERIC_VERTEX_BINDING_H


#include "rimGraphicsShadersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An object that encapsulates information about the binding of a vertex buffer to a name and usage.
class GenericVertexBinding
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new generic vertex binding object with no name, UNDEFINED usage, and no value.
			RIM_INLINE GenericVertexBinding()
				:	name(),
					usage( VertexUsage::UNDEFINED ),
					buffer(),
					isInput( true )
			{
			}
			
			
			
			
			/// Create a new generic vertex binding object with the specified name, usage, and value.
			RIM_INLINE GenericVertexBinding( const String& newName, const VertexUsage& newUsage )
				:	name( newName ),
					usage( newUsage ),
					buffer(),
					isInput( true )
			{
			}
			
			
			
			
			/// Create a new generic vertex binding object with the specified name, usage, and value.
			RIM_INLINE GenericVertexBinding( const String& newName, const Pointer<GenericBuffer>& newBuffer,
											const VertexUsage& newUsage, Bool newIsInput = true )
				:	name( newName ),
					usage( newUsage ),
					buffer( newBuffer ),
					isInput( newIsInput )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Binding Name Accessor Methods
			
			
			
			
			/// Return a string representing the name of the vertex binding.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set a string representing the name of the vertex binding.
			RIM_INLINE void setName( const String& newName )
			{
				name = newName;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Binding Usage Accessor Methods
			
			
			
			
			/// Return an enum value indicating the semantic usage of this vertex binding.
			RIM_INLINE const VertexUsage& getUsage() const
			{
				return usage;
			}
			
			
			
			
			/// Set an enum value indicating the semantic usage of this vertex binding.
			RIM_INLINE void setUsage( const VertexUsage& newUsage )
			{
				usage = newUsage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Binding Buffer Accessor Methods
			
			
			
			
			/// Return a pointer to the vertex buffer which is bound to this binding.
			RIM_INLINE const Pointer<GenericBuffer>& getBuffer() const
			{
				return buffer;
			}
			
			
			
			
			/// Set a pointer to the vertex buffer which is bound to this binding.
			RIM_INLINE void setBuffer( const Pointer<GenericBuffer>& newBuffer )
			{
				buffer = newBuffer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Input Status Accessor Methods
			
			
			
			
			/// Return whether or not this vertex binding is a dynamic input to a shader pass.
			/**
			  * If so, the renderer can provide dynamic scene information for this binding
			  * (such as nearby lights, textures, etc) that aren't explicitly part of this
			  * binding. By default, all bindings are inputs.
			  */
			RIM_INLINE Bool getIsInput() const
			{
				return isInput;
			}
			
			
			
			
			/// Set whether or not this vertex binding is a dynamic input to a shader pass.
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
			
			
			
			
			/// A string representing the name of the vertex binding.
			String name;
			
			
			
			
			/// An enum representing the semantic usage for this vertex attribute binding.
			VertexUsage usage;
			
			
			
			
			/// A pointer to the vertex buffer which is bound to this binding.
			Pointer<GenericBuffer> buffer;
			
			
			
			
			/// A boolean value indicating whether or not this binding represents a dynamic input.
			Bool isInput;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GENERIC_VERTEX_BINDING_H
