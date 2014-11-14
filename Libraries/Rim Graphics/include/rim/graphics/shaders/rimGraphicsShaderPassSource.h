/*
 *  rimGraphicsShaderPassSource.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 1/30/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_PASS_SOURCE_H
#define INCLUDE_RIM_GRAPHICS_SHADER_PASS_SOURCE_H


#include "rimGraphicsShadersConfig.h"


#include "rimGraphicsShaderLanguage.h"
#include "rimGraphicsShaderSource.h"
#include "rimGraphicsShaderConfiguration.h"

#include "rimGraphicsGenericShaderProgram.h"
#include "rimGraphicsGenericConstantBinding.h"
#include "rimGraphicsGenericTextureBinding.h"
#include "rimGraphicsGenericVertexBinding.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which describes a source-code implementation of a shader pass.
class ShaderPassSource
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new shader pass source object with no shader program.
			ShaderPassSource();
			
			
			
			
			/// Create a new shader pass source object that uses the specified shader program.
			ShaderPassSource( const Pointer<GenericShaderProgram>& newProgram );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Language Accessor Methods
			
			
			
			
			/// Return an object describing the language in which this shader pass source is written.
			RIM_INLINE ShaderLanguage getLanguage() const
			{
				if ( program.isSet() )
					return program->getLanguage();
				else
					return ShaderLanguage::UNDEFINED;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Program Accessor Methods
			
			
			
			
			/// Return a pointer to the shader program source code that should be used to render this shader pass.
			RIM_INLINE const Pointer<GenericShaderProgram>& getProgram() const
			{
				return program;
			}
			
			
			
			
			/// Return a pointer to the shader program source code that should be used to render this shader pass.
			RIM_INLINE void setProgram( const Pointer<GenericShaderProgram>& newProgram )
			{
				program = newProgram;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constant Binding Accessor Methods
			
			
			
			
			/// Get the number of constant bindings associated with this shader pass.
			RIM_FORCE_INLINE Size getConstantBindingCount() const
			{
				return constantBindings.getSize();
			}
			
			
			
			
			/// Return a pointer to the ConstantBinding at the specified index in this shader pas.
			/**
			  * Binding indices range from 0 to the number of bindings minus one.
			  * If there is no constant binding that corresponds to that index,
			  * NULL is returned. Otherwise, a pointer to the binding is returned.
			  */
			const GenericConstantBinding* getConstantBinding( Index bindingIndex ) const
			{
				if ( bindingIndex < constantBindings.getSize() )
					return &constantBindings[bindingIndex];
				else
					return NULL;
			}
			
			
			
			
			/// Return a pointer to the first constant binding in this shader pass associated with the specified usage.
			/**
			  * If there is no binding for that usage, NULL is returned.
			  */
			const GenericConstantBinding* getConstantBindingWithUsage( const ConstantUsage& usage ) const;
			
			
			
			
			/// Get the index of the binding for the constant variable with the specified name.
			/**
			  * This method does an expensive linear search through the array of bindings
			  * until it finds the variable with the specified name and places its index
			  * in the output reference parameter.
			  *
			  * The method returns whether or not there was a binding for a variable with that name.
			  */
			Bool getConstantBindingIndex( const String& constantName, Index& bindingIndex ) const;
			
			
			
			
			/// Add a constant binding input for the variable with the given name to this shader pass.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * variable with the specified name, or the specified usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, a new binding is added to the shader pass with the given attributes
			  * and TRUE is returned.
			  */
			Bool addConstantBinding( const String& constantName, const ConstantUsage& usage );
			
			
			
			
			/// Add a constant binding for the variable with the given name to this shader pass.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * variable with the specified name, or the specified constant or usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, a new binding is added to the shader pass with the given attributes
			  * and TRUE is returned.
			  */
			Bool addConstantBinding( const String& constantName, const AttributeValue& value,
									const ConstantUsage& usage, Bool isInput = true );
			
			
			
			
			/// Set the constant binding for this shader pass at the specified index, replacing any previous binding.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * binding with the specified index, or the specified constant or usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, the previously existing binding is updated with the given attributes
			  * and TRUE is returned.
			  */
			Bool setConstantBinding( Index bindingIndex, const AttributeValue& value,
									const ConstantUsage& usage = ConstantUsage::UNDEFINED, Bool isInput = true );
			
			
			
			
			/// Set the constant usage for this shader pass at the specified binding index, replacing any previous usage.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * binding with the specified index, or the specified usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, the previously existing binding is updated with the given constant usage
			  * and TRUE is returned.
			  */
			Bool setConstantUsage( Index bindingIndex, const ConstantUsage& usage );
			
			
			
			
			/// Remove the constant binding with the specified index in this shader pass.
			/**
			  * If the constant binding is successfully removed, TRUE is returned.
			  * Otherwise FALSE is returned and the shader pass is unmodified. This method
			  * removes the constant binding and replaces it with the shader pass's last
			  * constant binding (if there is one) in the list order.
			  */
			Bool removeConstantBinding( Index bindingIndex );
			
			
			
			
			/// Clear all constant bindings from this shader pass.
			void clearConstantBindings();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constant Value Accessor Methods
			
			
			
			
			/// Get the value of the constant with the specified binding index in this shader pass.
			/**
			  * If a binding exists with that index and its value is set, TRUE is returned and the value of
			  * the constant is written to the output value parameter. Otherwise, FALSE is returned
			  * and the value parameter is unmodified.
			  */
			template < typename T >
			Bool getConstantValue( Index bindingIndex, T& value ) const
			{
				if ( bindingIndex < constantBindings.getSize() )
				{
					const AttributeValue& value = constantBindings[bindingIndex].getValue();
					
					return value.isSet() && value.getValue( value );
				}
				
				return false;
			}
			
			
			
			
			/// Set the value of the constant with the specified binding index in this shader pass.
			/**
			  * If there was not an attribute already bound to this ID, a new
			  * attribute is added to the shader pass with the specified name and value.
			  */
			template < typename T >
			Bool setConstantValue( Index bindingIndex, const T& value )
			{
				if ( bindingIndex < constantBindings.getSize() )
				{
					GenericConstantBinding& binding = constantBindings[bindingIndex];
					return binding.getValue().setValue( value );
				}
				
				return false;
			}
			
			
			
			
			/// Set the value of the constant with the specified binding index in this shader pass.
			/**
			  * If there was not an attribute already bound to this ID, a new
			  * attribute is added to the shader pass with the specified name and value.
			  */
			Bool setConstant( Index bindingIndex, const AttributeValue& value )
			{
				if ( bindingIndex < constantBindings.getSize() )
				{
					GenericConstantBinding& binding = constantBindings[bindingIndex];
					binding.getValue() = value;
				}
				
				return false;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Binding Accessor Methods
			
			
			
			
			/// Get the number of texture bindings associated with this shader pass.
			RIM_FORCE_INLINE Size getTextureBindingCount() const
			{
				return textureBindings.getSize();
			}
			
			
			
			
			/// Return a pointer to the TextureBinding at the specified index in this shader pas.
			/**
			  * Binding indices range from 0 to the number of bindings minus one.
			  * If there is no texture binding that corresponds to that index,
			  * NULL is returned. Otherwise, a pointer to the binding is returned.
			  */
			const GenericTextureBinding* getTextureBinding( Index bindingIndex ) const
			{
				if ( bindingIndex < textureBindings.getSize() )
					return &textureBindings[bindingIndex];
				else
					return NULL;
			}
			
			
			
			
			/// Return a pointer to the first texture binding in this shader pass associated with the specified usage.
			/**
			  * If there is no binding for that usage, NULL is returned.
			  */
			const GenericTextureBinding* getTextureBindingWithUsage( const TextureUsage& usage ) const;
			
			
			
			
			/// Get the index of the binding for the texture variable with the specified name.
			/**
			  * This method does an expensive linear search through the array of bindings
			  * until it finds the variable with the specified name and places its index
			  * in the output reference parameter.
			  *
			  * The method returns whether or not there was a binding for a variable with that name.
			  */
			Bool getTextureBindingIndex( const String& variableName, Index& bindingIndex ) const;
			
			
			
			
			/// Add a texture binding for the variable with the given name to this shader pass.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * variable with the specified name, or the specified usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, a new binding is added to the shader pass with the given attributes
			  * and TRUE is returned.
			  */
			Bool addTextureBinding( const String& variableName, const TextureUsage& usage );
			
			
			
			
			/// Add a texture binding for the variable with the given name to this shader pass.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * variable with the specified name, or the specified texture or usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, a new binding is added to the shader pass with the given attributes
			  * and TRUE is returned.
			  */
			Bool addTextureBinding( const String& variableName, const Resource<GenericTexture>& texture,
									const TextureUsage& usage = TextureUsage::UNDEFINED, Bool isInput = true );
			
			
			
			
			/// Set the texture binding for this shader pass at the specified index, replacing any previous binding.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * binding with the specified index, or the specified texture or usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, the previously existing binding is updated with the given attributes
			  * and TRUE is returned.
			  */
			Bool setTextureBinding( Index bindingIndex, const Resource<GenericTexture>& texture,
									const TextureUsage& usage = TextureUsage::UNDEFINED, Bool isInput = true );
			
			
			
			
			/// Set the texture usage for this shader pass at the specified binding index, replacing any previous usage.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * binding with the specified index, or the specified usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, the previously existing binding is updated with the given texture usage
			  * and TRUE is returned.
			  */
			Bool setTextureUsage( Index bindingIndex, const TextureUsage& usage );
			
			
			
			
			/// Remove the texture binding with the specified index in this shader pass.
			/**
			  * If the texture binding is successfully removed, TRUE is returned.
			  * Otherwise FALSE is returned and the shader pass is unmodified.
			  */
			Bool removeTextureBinding( Index bindingIndex );
			
			
			
			
			/// Clear all texture bindings from this shader pass.
			void clearTextureBindings();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Accessor Methods
			
			
			
			
			/// Set the texture for this shader pass at the specified binding index, replacing any previous texture.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * binding with the specified index, or the specified texture has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, the previously existing binding is updated with the given texture
			  * and TRUE is returned..
			  */
			Bool setTexture( Index bindingIndex, const Resource<GenericTexture>& texture );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Binding Accessor Methods
			
			
			
			
			/// Get the number of vertex bindings associated with this shader pass.
			RIM_FORCE_INLINE Size getVertexBindingCount() const
			{
				return vertexBindings.getSize();
			}
			
			
			
			
			/// Return a pointer to the VertexBinding at the specified index in this shader pas.
			/**
			  * Binding indices range from 0 to the number of bindings minus one.
			  * If there is no vertex binding that corresponds to that index,
			  * NULL is returned. Otherwise, a pointer to the binding is returned.
			  */
			const GenericVertexBinding* getVertexBinding( Index bindingIndex ) const
			{
				if ( bindingIndex < vertexBindings.getSize() )
					return &vertexBindings[bindingIndex];
				else
					return NULL;
			}
			
			
			
			
			/// Return a pointer to the first vertex binding in this shader pass associated with the specified usage.
			/**
			  * If there is no binding for that usage, NULL is returned.
			  */
			const GenericVertexBinding* getVertexBindingWithUsage( const VertexUsage& usage ) const;
			
			
			
			
			/// Get the index of the binding for the vertex variable with the specified name.
			/**
			  * This method does an expensive linear search through the array of bindings
			  * until it finds the variable with the specified name and places its index
			  * in the output reference parameter.
			  *
			  * The method returns whether or not there was a binding for a variable with that name.
			  */
			Bool getVertexBindingIndex( const String& variableName, Index& bindingIndex ) const;
			
			
			
			
			/// Add a vertex binding for the variable with the given name to this shader pass.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * variable with the specified name, or the specified vertex or usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, a new binding is added to the shader pass with the given attributes
			  * and TRUE is returned.
			  */
			Bool addVertexBinding( const String& variableName, const VertexUsage& usage );
			
			
			
			
			/// Add a vertex binding for the variable with the given name to this shader pass.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * variable with the specified name, or the specified vertex or usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, a new binding is added to the shader pass with the given attributes
			  * and TRUE is returned.
			  */
			Bool addVertexBinding( const String& variableName, const Pointer<GenericBuffer>& vertexBuffer,
									const VertexUsage& usage = VertexUsage::UNDEFINED, Bool isInput = true );
			
			
			
			
			/// Set the vertex binding for this shader pass at the specified index, replacing any previous binding.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * binding with the specified index, or the specified vertex or usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, the previously existing binding is updated with the given attributes
			  * and TRUE is returned.
			  */
			Bool setVertexBinding( Index bindingIndex, const Pointer<GenericBuffer>& vertexBuffer,
									const VertexUsage& usage = VertexUsage::UNDEFINED, Bool isInput = true );
			
			
			
			
			/// Set the vertex for this shader pass at the specified binding index, replacing any previous vertex.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * binding with the specified index, or the specified vertex has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, the previously existing binding is updated with the given vertex
			  * and TRUE is returned..
			  */
			Bool setVertexBuffer( Index bindingIndex, const Pointer<GenericBuffer>& vertexBuffer );
			
			
			
			
			/// Set the vertex usage for this shader pass at the specified binding index, replacing any previous usage.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * binding with the specified index, or the specified usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, the previously existing binding is updated with the given vertex usage
			  * and TRUE is returned.
			  */
			Bool setVertexUsage( Index bindingIndex, const VertexUsage& usage );
			
			
			
			
			/// Remove the vertex binding with the specified index in this shader pass.
			/**
			  * If the vertex binding is successfully removed, TRUE is returned.
			  * Otherwise FALSE is returned and the shader pass is unmodified.
			  */
			Bool removeVertexBinding( Index bindingIndex );
			
			
			
			
			/// Clear all vertex bindings from this shader pass.
			void clearVertexBindings();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transparency Accessor Methods
			
			
			
			
			/// Get whether or not this shader pass produces pixels which are transparent.
			/**
			  * A shader pass is deemed to be transparent if blending is enabled by the
			  * shader pass's render mode.
			  */
			RIM_INLINE Bool getIsTransparent() const
			{
				return renderMode.flagIsSet( RenderFlags::BLENDING );
			}
			
			
			
			
			/// Set whether or not this shader pass produces pixels which are transparent.
			/**
			  * A shader pass is deemed to be transparent if blending is enabled by the
			  * shader pass's render mode. Calling this method causes blending to be
			  * enabled or disabled.
			  */
			RIM_INLINE void setIsTransparent( Bool newIsTransparent )
			{
				renderMode.setFlag( RenderFlags::BLENDING, newIsTransparent );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Render Mode Accessor Methods
			
			
			
			
			/// Return a reference to the object that determines the fixed-function rendering mode for this shader pass.
			RIM_INLINE RenderMode& getRenderMode()
			{
				return renderMode;
			}
			
			
			
			
			/// Return a const reference to the object that determines the fixed-function rendering mode for this shader pass.
			RIM_INLINE const RenderMode& getRenderMode() const
			{
				return renderMode;
			}
			
			
			
			
			/// Set an object that determines the fixed-function rendering mode for this shader pass.
			RIM_INLINE void setRenderMode( const RenderMode& newRenderMode )
			{
				renderMode = newRenderMode;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to an object containing the source code for this shader pass's shader program.
			Pointer<GenericShaderProgram> program;
			
			
			
			
			/// An object which encapsulates the configuration of this shader pass's rendering pipeline.
			RenderMode renderMode;
			
			
			
			
			/// A list of the constant bindings for this shader pass source.
			ArrayList<GenericConstantBinding> constantBindings;
			
			
			
			
			/// A list of the texture bindings for this shader pass source.
			ArrayList<GenericTextureBinding> textureBindings;
			
			
			
			
			/// A list of the vertex bindings for this shader pass source.
			ArrayList<GenericVertexBinding> vertexBindings;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_PASS_SOURCE_H
