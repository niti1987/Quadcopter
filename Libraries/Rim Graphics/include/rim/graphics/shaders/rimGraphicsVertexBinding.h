/*
 *  rimGraphicsVertexBinding.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/10/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_VERTEX_BINDING_H
#define INCLUDE_RIM_GRAPHICS_VERTEX_BINDING_H


#include "rimGraphicsShadersConfig.h"


#include "rimGraphicsVertexVariable.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class used to represent the binding between a per-vertex shader variable and its buffer and usage.
class VertexBinding
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Vertex Variable Accessor Methods
			
			
			
			
			/// Get the shader vertex variable to which a buffer is bound.
			RIM_FORCE_INLINE const VertexVariable& getVariable() const
			{
				return *variable;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Attribute Usage Accessor Methods
			
			
			
			
			/// Return the semantic usage for this vertex attribute binding.
			RIM_FORCE_INLINE const VertexUsage& getUsage() const
			{
				return usage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Offset Accessor Methods
			
			
			
			
			/// Return the starting index for the first buffer of this binding in its shader pass's buffer storage buffer.
			RIM_FORCE_INLINE UInt getBufferOffset() const
			{
				return bufferOffset;
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
			
			
			
			
			/// Create a vertex binding for the specified shader variable, value, and attribute usage.
			RIM_INLINE VertexBinding( const VertexVariable* newVariable, const VertexUsage& newUsage,
									UInt newBufferOffset, Bool newIsInput = true )
				:	variable( newVariable ),
					usage( newUsage ),
					bufferOffset( newBufferOffset ),
					isInput( newIsInput )
			{
				RIM_DEBUG_ASSERT_MESSAGE( newVariable != NULL,
					"Cannot create VertexBinding with NULL vertex variable." );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The vertex variable which is bound.
			const VertexVariable* variable;
			
			
			
			
			/// The semantic usage for this vertex attribute binding.
			/**
			  * This object allows the creator to specify the semantic usage for the vertex attribute
			  * variable. For instance, the usage could be to specify a the vertex's position. This
			  * allows the rendering system to automatically update certain shader parameters
			  * that are environmental.
			  */
			VertexUsage usage;
			
			
			
			
			/// The starting index for the first buffer of this binding in its shader pass's buffer storage buffer.
			UInt bufferOffset;
			
			
			
			
			/// A boolean value indicating whether or not this binding represents a dynamic input.
			Bool isInput;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_VERTEX_BINDING_H
