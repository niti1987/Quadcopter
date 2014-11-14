/*
 *  rimGraphicsShaderPass.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 1/6/11.
 *  Copyright 2011 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_PASS_H
#define INCLUDE_RIM_GRAPHICS_SHADER_PASS_H


#include "rimGraphicsShadersConfig.h"


#include "rimGraphicsConstantBinding.h"
#include "rimGraphicsConstantUsage.h"
#include "rimGraphicsTextureBinding.h"
#include "rimGraphicsVertexBinding.h"

#include "rimGraphicsShaderBindingData.h"

#include "rimGraphicsShaderProgram.h"
#include "rimGraphicsShaderPassSource.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains all information necessary to do a single rendering pass.
class ShaderPass : public ContextObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this shader pass, releasing all resources.
			~ShaderPass();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Program Accessor Methods
			
			
			
			
			/// Get the shader program used to render this shader pass.
			RIM_INLINE const Pointer<ShaderProgram>& getProgram() const
			{
				return program;
			}
			
			
			
			
			/// Set the shader program used to render this shader pass.
			/**
			  * When this method is called, all attribute and texture bindings
			  * are rebound for the new shader if there exist variables with the
			  * same names in the new shader. All bindings that are no longer valid
			  * are discarded. If the specified shader program is not valid, the
			  * method returns FALSE and has no effect. Otherwise, the method succeeds
			  * and TRUE is returned.
			  */
			Bool setProgram( const Pointer<ShaderProgram>& newProgram );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Source Code Accessor Method
			
			
			
			
			/// Return a pointer to an object which contains the source code and original bindings for this shader pass.
			/**
			  * This pointer may be NULL if the shader pass does not support dynamic recompilation.
			  */
			RIM_INLINE const Pointer<ShaderPassSource>& getSource() const
			{
				return source;
			}
			
			
			
			
			/// Set a pointer to an object which contains the source code and original bindings for this shader pass.
			/**
			  * This pointer may be NULL if the shader pass does not support dynamic recompilation.
			  */
			RIM_INLINE void setSource( const Pointer<ShaderPassSource>& newSource )
			{
				source = newSource;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Binding Data Accessor Methods
			
			
			
			
			/// Return a reference to the internal shader binding data for this shader pass.
			RIM_FORCE_INLINE const ShaderBindingData& getBindingData() const
			{
				return bindingData;
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
			
			
			
			
			/// Return a reference to the ConstantBinding at the specified index in this shader pass.
			/**
			  * Binding indices range from 0 to the number of constant bindings minus one.
			  */
			RIM_FORCE_INLINE const ConstantBinding& getConstantBinding( Index bindingIndex ) const
			{
				return constantBindings[bindingIndex];
			}
			
			
			
			
			/// Return a pointer to the first constant binding in this shader pass associated with the specified usage.
			/**
			  * If there is no binding for that usage, NULL is returned.
			  */
			const ConstantBinding* getConstantBindingWithUsage( const ConstantUsage& usage ) const;
			
			
			
			
			/// Get the index of the binding for the constant variable with the specified name.
			/**
			  * This method does an expensive linear search through the array of bindings
			  * until it finds the variable with the specified name and places its index
			  * in the output reference parameter.
			  *
			  * The method returns whether or not there was a binding for a variable with that name.
			  */
			Bool getConstantBindingIndex( const String& variableName, Index& bindingIndex ) const;
			
			
			
			
			/// Get the index of the binding for the constant variable with the specified usage.
			/**
			  * This method does a linear search through the array of bindings
			  * until it finds the variable with the specified usage and places its index
			  * in the output reference parameter.
			  *
			  * The method returns whether or not there was a binding for a variable with that usage.
			  */
			Bool getConstantBindingIndexWithUsage( const ConstantUsage& usage, Index& bindingIndex ) const;
			
			
			
			
			/// Add a constant binding for the variable with the given name to this shader pass.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * variable with the specified name, or the specified usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, a new binding is added to the shader pass with the given attributes
			  * and TRUE is returned. The binding's value is zero-initialized.
			  */
			Bool addConstantBinding( const String& variableName, const ConstantUsage& usage );
			
			
			
			
			/// Add a constant binding for the variable with the given name to this shader pass.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * variable with the specified name, or the specified constant or usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, a new binding is added to the shader pass with the given attributes
			  * and TRUE is returned.
			  */
			template < typename T >
			RIM_INLINE Bool addConstantBinding( const String& variableName, const T& value,
												const ConstantUsage& usage = ConstantUsage::UNDEFINED, Bool isInput = true )
			{
				const ConstantVariable* variable;
				
				if ( program.isSet() && program->getConstantVariable( variableName, variable ) &&
					(usage == ConstantUsage::UNDEFINED || usage.isValidType( variable->getType() )) )
				{
					ConstantBinding* binding = allocateConstantBinding( variable, usage, isInput );
					
					if ( binding != NULL )
					{
						setConstantValues( *binding, AttributeType::get<T>(), 1, &value );
						return true;
					}
				}
				
				return false;
			}
			
			
			
			
			/// Add a constant binding for the variable with the given name to this shader pass.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * variable with the specified name, or the specified constant or usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, a new binding is added to the shader pass with the given attributes
			  * and TRUE is returned.
			  */
			Bool addConstantBinding( const String& variableName, const AttributeValue& value,
										const ConstantUsage& usage = ConstantUsage::UNDEFINED, Bool isInput = true );
			
			
			
			
			/// Set the constant binding for this shader pass at the specified index, replacing any previous binding.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * binding with the specified index, or the specified constant or usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, the previously existing binding is updated with the given attributes
			  * and TRUE is returned.
			  */
			template < typename T >
			Bool setConstantBinding( Index bindingIndex, const T& value,
									const ConstantUsage& usage = ConstantUsage::UNDEFINED, Bool isInput = true )
			{
				if ( bindingIndex >= constantBindings.getSize() )
					return false;
				
				ConstantBinding& binding = constantBindings[bindingIndex];
				const ConstantVariable& variable = binding.getVariable();
				
				// Check to see if the described usage is compatible with the variable's type.
				if ( usage == ConstantUsage::UNDEFINED || usage.isValidType( variable.getType() ) )
				{
					binding.usage = usage;
					
					setConstantValues( binding, AttributeType::get<T>(), 1, &value );
					
					return true;
				}
				
				return false;
			}
			
			
			
			
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
			
			
			
			
			/// Get the value of the constant with the specified binding and array indices in this shader pass.
			/**
			  * If a binding exists with that index, TRUE is returned and the value of
			  * the constant's specified array element is written to the output value parameter.
			  * Otherwise, FALSE is returned and the value parameter is unmodified.
			  */
			Bool getConstantValue( Index bindingIndex, Index arrayIndex, AttributeValue& value ) const;
			
			
			
			
			/// Get the value of the constant with the specified binding index in this shader pass.
			/**
			  * If a binding exists with that index, TRUE is returned and the value of
			  * the constant's first array element is written to the output value parameter.
			  * Otherwise, FALSE is returned and the value parameter is unmodified.
			  */
			template < typename T >
			RIM_INLINE Bool getConstantValue( Index bindingIndex, T& value ) const
			{
				return this->getConstantValue( bindingIndex, 0, value );
			}
			
			
			
			
			/// Get the value of the constant with the specified binding and array indices in this shader pass.
			/**
			  * If a binding exists with that index, TRUE is returned and the value of
			  * the constant's specified array element is written to the output value parameter.
			  * Otherwise, FALSE is returned and the value parameter is unmodified.
			  */
			template < typename T >
			RIM_NO_INLINE Bool getConstantValue( Index bindingIndex, Index arrayIndex, T& value ) const
			{
				if ( bindingIndex < constantBindings.getSize() )
				{
					const ConstantBinding& binding = constantBindings[bindingIndex];
					const ConstantVariable& variable = binding.getVariable();
					const AttributeType& variableType = variable.getType();
					
					if ( arrayIndex < variable.getArraySize() && AttributeType::get<T>() == variableType )
						return getConstantValue( binding, arrayIndex, &value );
				}
				
				return false;
			}
			
			
			
			
			/// Set the value of the constant with the specified binding index in this shader pass.
			/**
			  * The method returns whether or not the value was able to be set.
			  */
			Bool setConstantValue( Index bindingIndex, const AttributeValue& value );
			
			
			
			
			/// Set the value of the constant with the specified binding index in this shader pass.
			/**
			  * The method returns whether or not the value was able to be set.
			  */
			Bool setConstantValue( Index bindingIndex, Index arrayIndex, const AttributeValue& value );
			
			
			
			
			/// Set the value of the constant with the specified binding index in this shader pass.
			/**
			  * The method returns whether or not the value was able to be set.
			  */
			template < typename T >
			RIM_NO_INLINE Bool setConstantValue( Index bindingIndex, const T& value )
			{
				if ( bindingIndex < constantBindings.getSize() )
				{
					ConstantBinding& binding = constantBindings[bindingIndex];
					
					return setConstantValues( binding, AttributeType::get<T>(), 1, &value );
				}
				
				return false;
			}
			
			
			
			
			/// Set the value of the constant with the specified binding and array indices in this shader pass.
			/**
			  * The method returns whether or not the value was able to be set.
			  */
			template < typename T >
			RIM_NO_INLINE Bool setConstantValue( Index bindingIndex, Index arrayIndex, const T& value )
			{
				if ( bindingIndex < constantBindings.getSize() )
				{
					ConstantBinding& binding = constantBindings[bindingIndex];
					
					return setConstantValue( binding, arrayIndex, AttributeType::get<T>(), 1, &value );
				}
				
				return false;
			}
			
			
			
			
			template < typename T >
			RIM_NO_INLINE Bool getConstantValueForUsage( const ConstantUsage& usage, T& value )
			{
				return this->getConstantValueForUsage( usage, 0, value );
			}
			
			
			
			
			template < typename T >
			RIM_INLINE Bool getConstantValueForUsage( const ConstantUsage& usage, Index arrayIndex, T& value )
			{
				const Size numConstants = constantBindings.getSize();
				
				for ( Index i = 0; i < numConstants; i++ )
				{
					ConstantBinding& binding = constantBindings[i];
					
					if ( binding.getUsage() == usage )
						return getConstantValue( binding, arrayIndex, &value );
				}
				
				return false;
			}
			
			
			
			
			template < typename T >
			RIM_NO_INLINE Bool setConstantValueForUsage( const ConstantUsage& usage, const T& value )
			{
				const Size numConstants = constantBindings.getSize();
				
				for ( Index i = 0; i < numConstants; i++ )
				{
					ConstantBinding& binding = constantBindings[i];
					
					if ( binding.getUsage() == usage )
						return setConstantValues( binding, AttributeType::get<T>(), 1, &value );
				}
				
				return false;
			}
			
			
			
			
			template < typename T >
			RIM_NO_INLINE Bool setConstantValueForUsage( const ConstantUsage& usage, Index arrayIndex, const T& value )
			{
				const Size numConstants = constantBindings.getSize();
				
				for ( Index i = 0; i < numConstants; i++ )
				{
					ConstantBinding& binding = constantBindings[i];
					
					if ( binding.getUsage() == usage )
						return setConstantValue( binding, arrayIndex, AttributeType::get<T>(), 1, &value );
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
			
			
			
			
			/// Return a reference to the TextureBinding at the specified index in this shader pass.
			/**
			  * Binding indices range from 0 to the number of texture bindings minus one.
			  */
			RIM_FORCE_INLINE const TextureBinding& getTextureBinding( Index bindingIndex ) const
			{
				return textureBindings[bindingIndex];
			}
			
			
			
			
			/// Return a pointer to the first texture binding in this shader pass associated with the specified usage.
			/**
			  * If there is no binding for that usage, NULL is returned.
			  */
			const TextureBinding* getTextureBindingForUsage( const TextureUsage& usage ) const;
			
			
			
			
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
			Bool addTextureBinding( const String& variableName, const Resource<Texture>& texture,
									const TextureUsage& usage = TextureUsage::UNDEFINED, Bool isInput = true );
			
			
			
			
			/// Set the texture binding for this shader pass at the specified index, replacing any previous binding.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * binding with the specified index, or the specified texture or usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, the previously existing binding is updated with the given attributes
			  * and TRUE is returned.
			  */
			Bool setTextureBinding( Index bindingIndex, const Resource<Texture>& texture,
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
			
			
			
			
			/// Get the first texture for this shader pass at the specified binding index.
			Bool getTexture( Index bindingIndex, Resource<Texture>& texture ) const;
			
			
			
			
			/// Get the texture for this shader pass at the specified binding and array index.
			Bool getTexture( Index bindingIndex, Index arrayIndex, Resource<Texture>& texture ) const;
			
			
			
			
			/// Set the texture for this shader pass at the specified binding index, replacing any previous texture.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * binding with the specified index, or the specified texture has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, the previously existing binding is updated with the given texture
			  * and TRUE is returned..
			  */
			Bool setTexture( Index bindingIndex, const Resource<Texture>& texture );
			
			
			
			
			/// Set the texture for this shader pass at the specified binding index, replacing any previous texture.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * binding with the specified index, or the specified texture has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, the previously existing binding is updated with the given texture
			  * and TRUE is returned..
			  */
			Bool setTexture( Index bindingIndex, Index arrayIndex, const Resource<Texture>& texture );
			
			
			
			
			/// Get the texture to use for the specified usage in this shader pass.
			Bool getTextureForUsage( const TextureUsage& usage, Resource<Texture>& texture );
			
			
			
			
			/// Set the texture to use for the specified usage in this shader pass.
			Bool setTextureForUsage( const TextureUsage& usage, const Resource<Texture>& texture );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Binding Accessor Methods
			
			
			
			
			/// Get the number of vertex bindings associated with this shader pass.
			RIM_FORCE_INLINE Size getVertexBindingCount() const
			{
				return vertexBindings.getSize();
			}
			
			
			
			
			/// Return a reference to the VertexBinding at the specified index in this shader pass.
			/**
			  * Binding indices range from 0 to the number of vertex bindings minus one.
			  */
			RIM_FORCE_INLINE const VertexBinding& getVertexBinding( Index bindingIndex ) const
			{
				return vertexBindings[bindingIndex];
			}
			
			
			
			
			/// Return a pointer to the first vertex binding in this shader pass associated with the specified usage.
			/**
			  * If there is no binding for that usage, NULL is returned.
			  */
			const VertexBinding* getVertexBindingForUsage( const VertexUsage& usage ) const;
			
			
			
			
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
			Bool addVertexBinding( const String& variableName, const Pointer<VertexBuffer>& buffer,
									const VertexUsage& usage = VertexUsage::UNDEFINED, Bool isInput = true );
			
			
			
			
			/// Set the vertex binding for this shader pass at the specified index, replacing any previous binding.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * binding with the specified index, or the specified vertex or usage has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, the previously existing binding is updated with the given attributes
			  * and TRUE is returned.
			  */
			Bool setVertexBinding( Index bindingIndex, const Pointer<VertexBuffer>& buffer,
									const VertexUsage& usage = VertexUsage::UNDEFINED, Bool isInput = true );
			
			
			
			
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
		//******	Vertex Buffer Accessor Methods
			
			
			
			
			/// Set the vertex buffer for this shader pass at the specified binding index, replacing any previous buffer.
			/**
			  * If there is no shader for this shader pass, or the shader doesn't have a 
			  * binding with the specified index, or the specified vertex buffer has an incompatible
			  * type with the shader variable, the method call fails and FALSE is returned.
			  * Otherwise, the previously existing binding is updated with the given vertex buffer
			  * and TRUE is returned..
			  */
			Bool setVertexBuffer( Index bindingIndex, const Pointer<VertexBuffer>& buffer );
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Minimum Vertex Buffer Size Accessor Method
			
			
			
			
			/// Return the smallest number of elements that are in any vertex buffer that is part of this shader pass.
			/**
			  * If there are no vertex buffers attached, 0 is returned. This method
			  * can be used to make sure that a shader pass has enough vertex data
			  * for a particular draw call or index buffer.
			  */
			Size getMinimumVertexBufferCapacity() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transparency Accessor Methods
			
			
			
			
			/// Get whether or not this shader pass produces pixels which are transparent.
			/**
			  * A shader pass is deemed to be transparent if blending and transparency depth sorting
			  * is enabled by the  shader pass's render mode.
			  */
			RIM_INLINE Bool getIsTransparent() const
			{
				return renderMode.flagIsSet( RenderFlags::BLENDING ) && renderMode.flagIsSet( RenderFlags::TRANSPARENCY_DEPTH_SORT );
			}
			
			
			
			
			/// Set whether or not this shader pass produces pixels which are transparent.
			/**
			  * A shader pass is deemed to be transparent if blending and transparency depth sorting
			  * is enabled by the  shader pass's render mode. Calling this method causes blending 
			  * and transparency sorting to be enabled or disabled.
			  */
			RIM_INLINE void setIsTransparent( Bool newIsTransparent )
			{
				renderMode.setFlag( RenderFlags::BLENDING, newIsTransparent );
				renderMode.setFlag( RenderFlags::TRANSPARENCY_DEPTH_SORT, newIsTransparent );
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
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new shader pass which doesn't have an associated shader program.
			ShaderPass( const devices::GraphicsContext* context );
			
			
			
			
			/// Create a new shader pass which uses the specified shader program and the default render mode.
			ShaderPass( const devices::GraphicsContext* context, const Pointer<ShaderProgram>& newProgram );
			
			
			
			
			/// Create a new shader pass which uses the specified shader program and render mode.
			ShaderPass( const devices::GraphicsContext* context, const Pointer<ShaderProgram>& newProgram,
						const RenderMode& newRenderMode );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constant Variable Binding Helper Methods
			
			
			
			
			/// Add a new constant binding to this shader pass for the variable.
			/**
			  * If there is no variable with that name or if the specified usage is incompatible
			  * with the variable, the method fails and NULL is returned. Otherwise, the method
			  * returns a pointer to the new constant binding and allocates storage for
			  * its value.
			  */
			ConstantBinding* allocateConstantBinding( const ConstantVariable* variable,
													const ConstantUsage& usage, Bool isInput );
			
			
			
			
			/// Zero the memory for the specified constant binding.
			void zeroConstantValues( const ConstantBinding& binding );
			
			
			
			
			/// Write the value for the specified binding and array index to the output parameter.
			Bool getConstantValue( const ConstantBinding& binding, Index arrayIndex, void* value ) const;
			
			
			
			
			/// Initialize the memory for the specified constant binding with the given value.
			Bool setConstantValues( const ConstantBinding& binding,
									const AttributeType& valueType, Size valueArraySize, const void* value );
			
			
			
			
			/// Initialize the memory for the specified constant binding with the given value.
			Bool setConstantValue( const ConstantBinding& binding, Index arrayIndex,
									const AttributeType& valueType, Size valueArraySize, const void* value );
			
			
			
			
			/// Return whether or not the specified shader variable supports the given attribute type.
			RIM_INLINE static Bool constantVariableSupportsType( const ConstantVariable& variable,
																const AttributeType& type )
			{
				const AttributeType& variableType = variable.getType();
				
				return variableType.getRowCount() == type.getRowCount() && 
						variableType.getColumnCount() == type.getColumnCount();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Texture Variable Binding Helper Methods
			
			
			
			
			/// Add a new texture binding to this shader pass for the variable with the given name.
			/**
			  * If there is no variable with that name or if the specified usage is incompatible
			  * with the variable, the method fails and NULL is returned. Otherwise, the method
			  * returns a pointer to the new texture binding and allocates storage for
			  * its textures.
			  */
			TextureBinding* allocateTextureBinding( const TextureVariable* variable, const TextureUsage& usage, Bool isInput );
			
			
			
			
			/// Zero the memory for the specified texture binding.
			void zeroTextures( const TextureBinding& binding );
			
			
			
			
			/// Set all textures that the specified texture binding uses to the specified texture.
			Bool setTextures( const TextureBinding& binding, const Resource<Texture>& texture );
			
			
			
			
			/// Set the texture with the specified array index for the given texture binding.
			Bool setTexture( const TextureBinding& binding, Index arrayIndex, const Resource<Texture>& texture );
			
			
			
			
			/// Return whether or not the specified shader variable supports the given attribute type.
			RIM_INLINE static Bool textureVariableSupportsTexture( const TextureVariable& variable,
																	const Resource<Texture>& texture )
			{
				if ( texture.isNull() )
					return false;
				
				const TextureType& textureType = variable.getType();
				
				// Make sure that the texture variable's type is compatable with the texture.
				if ( textureType.getDimensionCount() != texture->getDimensionCount() )
					return false;
				else if ( textureType.isAShadowMap() && texture->getFormat() != TextureFormat::DEPTH )
					return false;
				else
					return textureType.isACubeMap() == texture->isACubeMap();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Vertex Binding Helper Methods
			
			
			
			
			/// Add a new vertex binding to this shader pass for the variable with the given name.
			/**
			  * If there is no variable with that name or if the specified usage is incompatible
			  * with the variable, the method fails and NULL is returned. Otherwise, the method
			  * returns a pointer to the new vertex binding and allocates storage for
			  * its buffers.
			  */
			VertexBinding* allocateVertexBinding( const VertexVariable* variable, const VertexUsage& usage, Bool isInput );
			
			
			
			
			/// Zero the memory for the specified vertex binding.
			void zeroVertexBuffers( const VertexBinding& binding );
			
			
			
			
			/// Set all buffers that the specified vertex binding uses to the specified buffer.
			Bool setVertexBuffers( const VertexBinding& binding, const Pointer<VertexBuffer>& buffer );
			
			
			
			
			/// Set the buffer with the specified array index for the given vertex binding.
			Bool setVertexBuffer( const VertexBinding& binding, const Pointer<VertexBuffer>& buffer, Index arrayIndex );
			
			
			
			
			/// Return whether or not the specified shader variable supports the given attribute type.
			RIM_INLINE static Bool vertexVariableSupportsBuffer( const VertexVariable& variable,
																const Pointer<VertexBuffer>& buffer )
			{
				if ( buffer.isNull() )
					return false;
				
				const AttributeType& variableType = variable.getType();
				const AttributeType& bufferType = buffer->getAttributeType();
				
				return variableType.getRowCount() == bufferType.getRowCount() && 
						variableType.getColumnCount() == bufferType.getColumnCount();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Shader Data Members
			
			
			
			
			/// A pointer to the shader program which is used to render this shader pass.
			Pointer<ShaderProgram> program;
			
			
			
			
			/// A pointer to an object which contains the source code and original bindings for this shader pass.
			/**
			  * This pointer may be NULL if the shader pass does not support dynamic recompilation.
			  */
			Pointer<ShaderPassSource> source;
			
			
			
			
			/// A pointer to an object that specifies the compile-time configuration of this shader pass's shader program.
			Pointer<ShaderConfiguration> configuration;
			
			
			
			
			/// An object which encapsulates the configuration of this shader pass's rendering pipeline.
			RenderMode renderMode;
			
			
			
			
			/// A list of the constant variable bindings for this shader pass.
			ArrayList<ConstantBinding> constantBindings;
			
			
			
			
			/// A list of the texture variable bindings for this shader pass.
			ArrayList<TextureBinding> textureBindings;
			
			
			
			
			/// A list of the vertex variable bindings for this shader pass.
			ArrayList<VertexBinding> vertexBindings;
			
			
			
			
			/// A set of binding data for this shader pass.
			ShaderBindingData bindingData;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_PASS_H
