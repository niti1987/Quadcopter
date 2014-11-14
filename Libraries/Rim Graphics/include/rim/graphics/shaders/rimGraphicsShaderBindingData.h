/*
 *  rimGraphicsShaderBindingData.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/7/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_BINDING_DATA_H
#define INCLUDE_RIM_GRAPHICS_SHADER_BINDING_DATA_H


#include "rimGraphicsShadersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that stores the input data for a shader pass.
class ShaderBindingData
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new shader binding data object with no allocated data.
			ShaderBindingData();
			
			
			
			
			/// Create a new shader binding data object with the specified initial capacity for each data type.
			ShaderBindingData( Size constantDataCapacity, Size textureCapacity, Size vertexBufferCapacity );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constant Accessor Methods
			
			
			
			
			/// Return an pointer to the internal array of shader constant data.
			RIM_FORCE_INLINE Size getConstantDataSize() const
			{
				return numConstantBytes;
			}
			
			
			
			
			/// Return a pointer to the internal array of shader constant data.
			RIM_FORCE_INLINE UByte* getConstantData()
			{
				return constants.getPointer();
			}
			
			
			
			
			/// Return a const pointer to the internal array of shader constant data.
			RIM_FORCE_INLINE const UByte* getConstantData() const
			{
				return constants.getPointer();
			}
			
			
			
			
			/// Allocate a new constant for this shader binding data and return a pointer to the constant storage.
			RIM_INLINE UByte* allocateConstant( Size sizeInBytes )
			{
				// Compute the new size of the constant buffer.
				Index byteOffset = alignConstantAddress( numConstantBytes );
				Size newNumConstantBytes = byteOffset + sizeInBytes;
				
				// Reallocate the constant buffer if necessary.
				if ( newNumConstantBytes > constants.getSize() )
					constants.setSize( newNumConstantBytes*2 );
				
				// Compute the pointer to the constant's storage buffer.
				UByte* storage = constants.getPointer() + byteOffset;
				numConstantBytes = newNumConstantBytes;
				
				return storage;
			}
			
			
			
			
			/// Remove all stored constants from this shader binding data object.
			RIM_INLINE void clearConstants()
			{
				numConstantBytes = 0;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Accessor Methods
			
			
			
			
			/// Return an pointer to the internal array of shader textures.
			RIM_FORCE_INLINE Size getTextureCount() const
			{
				return numTextures;
			}
			
			
			
			
			/// Return a pointer to the internal array of shader textures.
			RIM_FORCE_INLINE Resource<Texture>* getTextures()
			{
				return textures.getPointer();
			}
			
			
			
			
			/// Return a const pointer to the internal array of shader textures.
			RIM_FORCE_INLINE const Resource<Texture>* getTextures() const
			{
				return textures.getPointer();
			}
			
			
			
			
			/// Allocate the specified number of textures for this shader binding data and return a pointer to the texture storage.
			RIM_INLINE Resource<Texture>* allocateTextures( Size texturesToAdd )
			{
				// Compute the new size of the texture buffer.
				Size newNumTextures = numTextures + texturesToAdd;
				
				// Reallocate the constant buffer if necessary.
				if ( newNumTextures > textures.getSize() )
					textures.setSize( newNumTextures*2 );
				
				// Compute the pointer to the constant's storage buffer.
				Resource<Texture>* storage = textures.getPointer() + numTextures;
				numTextures = newNumTextures;
				
				return storage;
			}
			
			
			
			
			/// Remove all stored textures from this shader binding data object.
			RIM_INLINE void clearTextures()
			{
				numTextures = 0;
				textures.setAll( Resource<Texture>() );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Buffer Accessor Methods
			
			
			
			
			/// Return an pointer to the internal array of shader vertex buffers.
			RIM_FORCE_INLINE Size getVertexBufferCount() const
			{
				return numBuffers;
			}
			
			
			
			
			/// Return a pointer to the internal array of shader vertex buffers.
			RIM_FORCE_INLINE Pointer<VertexBuffer>* getVertexBuffers()
			{
				return buffers.getPointer();
			}
			
			
			
			
			/// Return a const pointer to the internal array of shader vertex buffers.
			RIM_FORCE_INLINE const Pointer<VertexBuffer>* getVertexBuffers() const
			{
				return buffers.getPointer();
			}
			
			
			
			
			/// Allocate the specified number of vertex buffers for this shader binding data and return a pointer to the buffer storage.
			RIM_INLINE Pointer<VertexBuffer>* allocateVertexBuffers( Size buffersToAdd )
			{
				// Compute the new size of the texture buffer.
				Size newNumBuffers = numBuffers + buffersToAdd;
				
				// Reallocate the constant buffer if necessary.
				if ( newNumBuffers > buffers.getSize() )
					buffers.setSize( newNumBuffers*2 );
				
				// Compute the pointer to the constant's storage buffer.
				Pointer<VertexBuffer>* storage = buffers.getPointer() + numBuffers;
				numBuffers = newNumBuffers;
				
				return storage;
			}
			
			
			
			
			/// Remove all stored vertex buffers from this shader binding data object.
			RIM_INLINE void clearVertexBuffers()
			{
				numBuffers = 0;
				buffers.setAll( Pointer<VertexBuffer>() );
			}
			
			
			
			
			
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
			RIM_INLINE Size getMinimumVertexBufferCapacity() const
			{
				Size result = math::max<Size>();
				
				for ( Index i = 0; i < numBuffers; i++ )
				{
					const Pointer<VertexBuffer>& buffer = buffers[i];
					
					if ( buffer.isSet() )
						result = math::min( result, buffer->getCapacity() );
				}
				
				if ( result == math::max<Size>() )
					return 0;
				else
					return result;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Data Set Method
			
			
			
			
			/// Copy all data from the other shader binding data object into this one.
			void setData( const ShaderBindingData& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Constant Data Members
			
			
			
			
			/// The default size of a shader pass's constant buffer in bytes.
			static const Size DEFAULT_CONSTANT_BUFFER_SIZE = 64;
			
			
			
			
			/// The default size of a shader pass's texture array.
			static const Size DEFAULT_TEXTURE_ARRAY_SIZE = 4;
			
			
			
			
			/// The default size of a shader pass's buffer array.
			static const Size DEFAULT_BUFFER_ARRAY_SIZE = 2;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Align the specified address to a 4-byte boundary.
			RIM_FORCE_INLINE static Index alignConstantAddress( Index address )
			{
				return (address + (DEFAULT_CONSTANT_ALIGNMENT - 1)) & -(SignedIndex)DEFAULT_CONSTANT_ALIGNMENT;
			}
			
			
			
			
			/// The default alignment requirement in bytes for allocated constants.
			static const Index DEFAULT_CONSTANT_ALIGNMENT = 4;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An array of bytes that stores the values for all constants that are part of this shader pass.
			Array<UByte> constants;
			
			
			
			
			/// A list of the textures that are bound as part of this shader pass.
			Array< Resource<Texture> > textures;
			
			
			
			
			/// A list of the vertex buffers that are bound as part of this shader pass.
			Array< Pointer<VertexBuffer> > buffers;
			
			
			
			
			/// The total number of bytes used for current bindings in the constant data buffer.
			Size numConstantBytes;
			
			
			
			
			/// The number of valid textures allcated in the texture array.
			Size numTextures;
			
			
			
			
			/// The number of valid textures allcated in the texture array.
			Size numBuffers;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_BINDING_DATA_H
