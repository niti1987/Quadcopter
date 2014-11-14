/*
 *  rimGraphicsConverter.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/18/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_CONVERTER_H
#define INCLUDE_RIM_GRAPHICS_CONVERTER_H


#include "rimGraphicsIOConfig.h"


#include "rimGraphicsConverterFlags.h"


//##########################################################################################
//**************************  Start Rim Graphics IO Namespace  *****************************
RIM_GRAPHICS_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles conversions from an intermediate format a hardware-based graphics format.
class GraphicsConverter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a generic graphics converter which uses the specified context when converting graphics.
			/**
			  * This converter won't have access to a resource manager which it uses to
			  * load resources that haven't been loaded yet, and so may not be able to convert
			  * all inputs successfully.
			  */
			GraphicsConverter( const Pointer<GraphicsContext>& context );
			
			
			
			
			/// Create a generic graphics converter which uses the specified context and resource manager when converting graphics.
			GraphicsConverter( const Pointer<GraphicsContext>& context,
								const Pointer<ResourceManager>& resourceManager );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this graphics converter, releasing all resources.
			virtual ~GraphicsConverter();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Context Accessor Methods
			
			
			
			
			/// Return a pointer to the graphics context that this converter is using.
			/**
			  * If the context pointer is NULL, the converter cannot be used to convert
			  * generic graphics objects to a hardware representation.
			  */
			RIM_INLINE const Pointer<GraphicsContext>& getContext() const
			{
				return context;
			}
			
			
			
			
			
			/// Set the graphics context that this converter is using.
			/**
			  * If the specified context pointer is NULL, the converter cannot be used to convert
			  * generic graphics objects to a hardware representation.
			  *
			  * Calling this method causes the caches for this converter to be cleared.
			  */
			void setContext( const Pointer<GraphicsContext>& newContext );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resource Manager Accessor Methods
			
			
			
			
			/// Return a pointer to the resource manager that this converter is using to load external resources.
			/**
			  * If the manager pointer is NULL, the converter cannot load external resources
			  * that aren't provided as input.
			  */
			RIM_INLINE const Pointer<ResourceManager>& getResourceManager() const
			{
				return resourceManager;
			}
			
			
			
			
			
			/// Set the resource manager that this converter is using to load external resources.
			/**
			  * If the manager pointer is NULL, the converter cannot load external resources
			  * that aren't provided as input.
			  *
			  * Calling this method causes the caches for this converter to be cleared.
			  */
			void setResourceManager( const Pointer<ResourceManager>& newResourceManager );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flags Accessor Methods
			
			
			
			
			/// Return a reference to an object which contains boolean parameters of the graphics converter.
			RIM_INLINE GraphicsConverterFlags& getFlags()
			{
				return flags;
			}
			
			
			
			
			/// Return an object which contains boolean parameters of the graphics converter.
			RIM_INLINE const GraphicsConverterFlags& getFlags() const
			{
				return flags;
			}
			
			
			
			
			/// Set an object which contains boolean parameters of the graphics converter.
			RIM_INLINE void setFlags( const GraphicsConverterFlags& newFlags )
			{
				flags = newFlags;
			}
			
			
			
			
			/// Return whether or not the specified boolan flag is set for this graphics converter.
			RIM_INLINE Bool flagIsSet( GraphicsConverterFlags::Flag flag ) const
			{
				return flags.isSet( flag );
			}
			
			
			
			
			/// Set whether or not the specified boolan flag is set for this graphics converter.
			RIM_INLINE void setFlag( GraphicsConverterFlags::Flag flag, Bool newIsSet = true )
			{
				flags.set( flag, newIsSet );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Cache Accessor Methods
			
			
			
			
			/// Return whether or not conversion caching is enabled for the templated data type.
			template < typename DataType >
			RIM_INLINE Bool getCacheEnabled() const
			{
				return false;
			}
			
			
			
			
			/// Set whether or not conversion caching is enabled for the templated data type.
			template < typename DataType >
			RIM_INLINE Bool setCacheEnabled( Bool newCacheEnabled )
			{
				return false;
			}
			
			
			
			
			/// Clear the conversion cache for the templated data type.
			template < typename DataType >
			RIM_INLINE Bool clearCache()
			{
				return false;
			}
			
			
			
			
			/// Clear all conversion caches for this graphics converter.
			void clearCaches();
			
			
			
			
			/// Remove all entries in the conversion cache that are not being used (have reference count == 1).
			void trimCaches();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Scene Conversion Methods
			
			
			
			
			/// Convert the specified generic graphics scene into a hardware-based graphics scene.
			/**
			  * If the method fails, a NULL pointer is returned. The method can fail if the
			  * specified scene pointer is NULL or if the converter doesn't have a valid
			  * context.
			  */
			//Pointer<GraphicsScene> convertGenericScene( const Pointer<GenericGraphicsScene>& genericScene );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Conversion Methods
			
			
			
			
			/// Convert the specified generic graphics object into a hardware-based graphics object.
			/**
			  * If the method fails, a NULL pointer is returned. The method can fail if the
			  * specified object pointer is NULL or if the converter doesn't have a valid
			  * context.
			  */
			//Pointer<GraphicsObject> convertGenericObject( const Pointer<GenericGraphicsObject>& genericObject );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shape Conversion Methods
			
			
			
			
			/// Convert the specified generic shape into a hardware-based graphics shape.
			/**
			  * If the method fails, a NULL pointer is returned. The method can fail if the
			  * specified shape pointer is NULL or if the converter doesn't have a valid
			  * context, or if there is no valid conversion for the specified shape's type.
			  */
			Pointer<GraphicsShape> convertShape( const Pointer<GraphicsShape>& shape );
			
			
			
			
			/// Convert the specified generic mesh into a hardware-based graphics shape.
			/**
			  * If the method fails, a NULL pointer is returned. The method can fail if the
			  * specified mesh pointer is NULL or if the converter doesn't have a valid
			  * context.
			  */
			Pointer<MeshShape> convertGenericMesh( const Pointer<GenericMeshShape>& mesh );
			
			
			
			
			/// Convert the specified generic sphere into a hardware-based graphics shape.
			/**
			  * If the method fails, a NULL pointer is returned. The method can fail if the
			  * specified mesh pointer is NULL or if the converter doesn't have a valid
			  * context.
			  */
			Pointer<SphereShape> convertGenericSphere( const Pointer<GenericSphereShape>& sphere );
			
			
			
			
			/// Convert the specified generic cylinder into a hardware-based graphics shape.
			/**
			  * If the method fails, a NULL pointer is returned. The method can fail if the
			  * specified mesh pointer is NULL or if the converter doesn't have a valid
			  * context.
			  */
			Pointer<CylinderShape> convertGenericCylinder( const Pointer<GenericCylinderShape>& cylinder );
			
			
			
			
			/// Convert the specified generic capsule into a hardware-based graphics shape.
			/**
			  * If the method fails, a NULL pointer is returned. The method can fail if the
			  * specified mesh pointer is NULL or if the converter doesn't have a valid
			  * context.
			  */
			Pointer<CapsuleShape> convertGenericCapsule( const Pointer<GenericCapsuleShape>& capsule );
			
			
			
			
			/// Convert the specified generic box into a hardware-based graphics shape.
			/**
			  * If the method fails, a NULL pointer is returned. The method can fail if the
			  * specified mesh pointer is NULL or if the converter doesn't have a valid
			  * context.
			  */
			Pointer<BoxShape> convertGenericBox( const Pointer<GenericBoxShape>& box );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Buffer Conversion Methods
			
			
			
			
			/// Convert the specified generic buffer into a hardware-based graphics vertex buffer.
			/**
			  * If the method fails, a NULL pointer is returned. The method can fail if the
			  * specified generic buffer pointer is NULL or if the converter doesn't have a valid
			  * context.
			  */
			Pointer<VertexBuffer> convertVertexBuffer( const Pointer<GenericBuffer>& buffer );
			
			
			
			
			/// Convert the specified generic buffer and primitive type into a hardware-based graphics index buffer.
			/**
			  * If the method fails, a NULL pointer is returned. The method can fail if the
			  * specified generic buffer pointer is NULL or if the converter doesn't have a valid
			  * context.
			  */
			Pointer<IndexBuffer> convertIndexBuffer( const Pointer<GenericBuffer>& buffer );
			
			
			
			
			/// Convert the specified generic buffer list into a hardware-based graphics vertex buffer list.
			/**
			  * If the method fails, a NULL pointer is returned. The method can fail if the
			  * specified generic buffer list pointer is NULL or if the converter doesn't have a valid
			  * context.
			  */
			Pointer<VertexBufferList> convertGenericBufferList( const Pointer<GenericBufferList>& bufferList );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Material/Shader Conversion Methods
			
			
			
			
			/// Convert the specified generic material into a hardware-based graphics material.
			/**
			  * If the method fails, a NULL pointer is returned. The method can fail if the
			  * specified generic material pointer is NULL or if the converter doesn't have a valid
			  * context.
			  */
			Pointer<Material> convertGenericMaterial( const Pointer<GenericMaterial>& material );
			
			
			
			
			/// Convert the specified generic material technique into a hardware-based graphics material technique.
			/**
			  * If the method fails, a NULL pointer is returned. The method can fail if the
			  * specified generic material technique pointer is NULL or if the converter doesn't have a valid
			  * context.
			  */
			Pointer<MaterialTechnique> convertGenericMaterialTechnique( const Pointer<GenericMaterialTechnique>& materialTechnique );
			
			
			
			
			/// Convert the specified generic shader pass into a hardware-based shader pass.
			/**
			  * If the method fails, a NULL pointer is returned. The method can fail if the
			  * specified generic shader pass pointer is NULL or if the converter doesn't have a valid
			  * context.
			  */
			Pointer<ShaderPass> convertGenericShaderPass( const Pointer<GenericShaderPass>& shaderPass );
			
			
			
			
			/// Convert the specified generic shader program into a hardware-based shader program.
			/**
			  * If the method fails, a NULL pointer is returned. The method can fail if the
			  * specified generic shader program pointer is NULL or if the converter doesn't have a valid
			  * context.
			  */
			Pointer<ShaderProgram> convertGenericShaderProgram( const Pointer<GenericShaderProgram>& shaderProgram );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Conversion Methods
			
			
			
			
			/// Convert the specified generic texture into a hardware-based texture.
			/**
			  * If the method fails, a NULL pointer is returned. The method can fail if the
			  * specified generic texture resource is NULL or if the converter doesn't have a valid
			  * context.
			  */
			Resource<Texture> convertGenericTexture( const Resource<GenericTexture>& texture );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < typename DataType >
			Bool loadGenericResource( const Resource<DataType>& resource )
			{
				// Check to see if the texture is already loaded or can load itself.
				if ( resource.load() )
					return true;
				
				// Return failure if the generic texture has no resource ID.
				const ResourceID* identifier = resource.getID();
				
				if ( identifier == NULL )
					return false;
				
				// Return failure if resource loading is not enabled.
				if ( !flags.isSet( GraphicsConverterFlags::RESOURCE_LOADING_ENABLED ) || resourceManager.isNull() )
					return false;
				
				// Try loading the resource.
				Resource<DataType> temp = resource;
				
				return resourceManager->getResource<DataType>( temp );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The default set of flags for a graphics converter.
			static const UInt32 DEFAULT_FLAGS = GraphicsConverterFlags::CACHE_ENABLED |
												GraphicsConverterFlags::SCENE_CACHE_ENABLED |
												GraphicsConverterFlags::OBJECT_CACHE_ENABLED |
												GraphicsConverterFlags::SHAPE_CACHE_ENABLED |
												GraphicsConverterFlags::MATERIAL_CACHE_ENABLED |
												GraphicsConverterFlags::MATERIAL_TECHNIQUE_CACHE_ENABLED |
												GraphicsConverterFlags::SHADER_PASS_CACHE_ENABLED |
												GraphicsConverterFlags::SHADER_PROGRAM_CACHE_ENABLED |
												GraphicsConverterFlags::SHADER_CACHE_ENABLED |
												GraphicsConverterFlags::VERTEX_BUFFER_CACHE_ENABLED |
												GraphicsConverterFlags::VERTEX_BUFFER_LIST_CACHE_ENABLED |
												GraphicsConverterFlags::TEXTURE_CACHE_ENABLED |
												GraphicsConverterFlags::RESOURCE_LOADING_ENABLED |
												GraphicsConverterFlags::DEFERRED_LOADING_ENABLED;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the graphics context to use when converting intermediate data into a hardware-renderable format.
			Pointer<GraphicsContext> context;
			
			
			
			
			/// A pointer to an object which is managing resources for this converter.
			Pointer<ResourceManager> resourceManager;
			
			
			
			
			/// An object which stores boolean configuration information about this graphics converter.
			GraphicsConverterFlags flags;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Cache Data Members
			
			
			
			
			/// A cache of previously converted materials.
			HashMap< const GenericMaterial*, Pointer<Material> > materialCache;
			
			
			
			
			/// A cache of previously converted materials.
			HashMap< const GenericMaterialTechnique*, Pointer<MaterialTechnique> > materialTechniqueCache;
			
			
			
			
			/// A cache of previously converted shader passes.
			HashMap< const GenericShaderPass*, Pointer<ShaderPass> > shaderPassCache;
			
			
			
			
			/// A cache of previously converted shader programs.
			HashMap< const GenericShaderProgram*, Pointer<ShaderProgram> > shaderProgramCache;
			
			
			
			
			/// A cache of previously converted textures.
			HashMap< const GenericBufferList*, Pointer<VertexBufferList> > bufferListCache;
			
			
			
			
			/// A cache of previously converted textures.
			HashMap< const GenericBuffer*, Pointer<VertexBuffer> > vertexBufferCache;
			
			
			
			
			/// A cache of previously converted textures.
			HashMap< const GenericTexture*, Resource<Texture> > textureCache;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Get Cache Enabled Template Specializations
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_INLINE Bool GraphicsConverter:: getCacheEnabled<Material>() const
{
	return flags.isSet( GraphicsConverterFlags::MATERIAL_CACHE_ENABLED );
}




template <>
RIM_INLINE Bool GraphicsConverter:: getCacheEnabled<MaterialTechnique>() const
{
	return flags.isSet( GraphicsConverterFlags::MATERIAL_TECHNIQUE_CACHE_ENABLED );
}




template <>
RIM_INLINE Bool GraphicsConverter:: getCacheEnabled<ShaderPass>() const
{
	return flags.isSet( GraphicsConverterFlags::SHADER_PASS_CACHE_ENABLED );
}




template <>
RIM_INLINE Bool GraphicsConverter:: getCacheEnabled<ShaderProgram>() const
{
	return flags.isSet( GraphicsConverterFlags::SHADER_PROGRAM_CACHE_ENABLED );
}




template <>
RIM_INLINE Bool GraphicsConverter:: getCacheEnabled<VertexBufferList>() const
{
	return flags.isSet( GraphicsConverterFlags::VERTEX_BUFFER_LIST_CACHE_ENABLED );
}




template <>
RIM_INLINE Bool GraphicsConverter:: getCacheEnabled<VertexBuffer>() const
{
	return flags.isSet( GraphicsConverterFlags::VERTEX_BUFFER_CACHE_ENABLED );
}




template <>
RIM_INLINE Bool GraphicsConverter:: getCacheEnabled<Texture>() const
{
	return flags.isSet( GraphicsConverterFlags::TEXTURE_CACHE_ENABLED );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Set Cache Enabled Template Specializations
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_INLINE Bool GraphicsConverter:: setCacheEnabled<Material>( Bool newCacheEnabled )
{
	flags.set( GraphicsConverterFlags::MATERIAL_CACHE_ENABLED, newCacheEnabled );
	return true;
}




template <>
RIM_INLINE Bool GraphicsConverter:: setCacheEnabled<MaterialTechnique>( Bool newCacheEnabled )
{
	flags.set( GraphicsConverterFlags::MATERIAL_TECHNIQUE_CACHE_ENABLED, newCacheEnabled );
	return true;
}




template <>
RIM_INLINE Bool GraphicsConverter:: setCacheEnabled<ShaderPass>( Bool newCacheEnabled )
{
	flags.set( GraphicsConverterFlags::SHADER_PASS_CACHE_ENABLED, newCacheEnabled );
	return true;
}




template <>
RIM_INLINE Bool GraphicsConverter:: setCacheEnabled<ShaderProgram>( Bool newCacheEnabled )
{
	flags.set( GraphicsConverterFlags::SHADER_PROGRAM_CACHE_ENABLED, newCacheEnabled );
	return true;
}




template <>
RIM_INLINE Bool GraphicsConverter:: setCacheEnabled<VertexBufferList>( Bool newCacheEnabled )
{
	flags.set( GraphicsConverterFlags::VERTEX_BUFFER_LIST_CACHE_ENABLED, newCacheEnabled );
	return true;
}




template <>
RIM_INLINE Bool GraphicsConverter:: setCacheEnabled<VertexBuffer>( Bool newCacheEnabled )
{
	flags.set( GraphicsConverterFlags::VERTEX_BUFFER_CACHE_ENABLED, newCacheEnabled );
	return true;
}




template <>
RIM_INLINE Bool GraphicsConverter:: setCacheEnabled<Texture>( Bool newCacheEnabled )
{
	flags.set( GraphicsConverterFlags::TEXTURE_CACHE_ENABLED, newCacheEnabled );
	return true;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Conversion Cache Clear Method Specializations
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_INLINE Bool GraphicsConverter:: clearCache<Material>()
{
	materialCache.clear();
	return true;
}




template <>
RIM_INLINE Bool GraphicsConverter:: clearCache<MaterialTechnique>()
{
	materialTechniqueCache.clear();
	return true;
}




template <>
RIM_INLINE Bool GraphicsConverter:: clearCache<ShaderPass>()
{
	shaderPassCache.clear();
	return true;
}




template <>
RIM_INLINE Bool GraphicsConverter:: clearCache<ShaderProgram>()
{
	shaderProgramCache.clear();
	return true;
}




template <>
RIM_INLINE Bool GraphicsConverter:: clearCache<VertexBufferList>()
{
	bufferListCache.clear();
	return true;
}




template <>
RIM_INLINE Bool GraphicsConverter:: clearCache<VertexBuffer>()
{
	vertexBufferCache.clear();
	return true;
}




template <>
RIM_INLINE Bool GraphicsConverter:: clearCache<Texture>()
{
	textureCache.clear();
	return true;
}




//##########################################################################################
//**************************  End Rim Graphics IO Namespace  *******************************
RIM_GRAPHICS_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_CONVERTER_H
