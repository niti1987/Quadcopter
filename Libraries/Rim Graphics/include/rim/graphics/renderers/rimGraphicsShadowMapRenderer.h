/*
 *  rimGraphicsShadowMapRenderer.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 12/4/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADOW_MAP_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_SHADOW_MAP_RENDERER_H


#include "rimGraphicsRenderersConfig.h"


#include "rimGraphicsSceneRenderer.h"


//##########################################################################################
//**********************  Start Rim Graphics Renderers Namespace  **************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which manages a set of cached shadow maps that it renders.
class ShadowMapRenderer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new shadow map renderer which uses the specified context to render shadow maps.
			ShadowMapRenderer( const Pointer<GraphicsContext>& newContext );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Context Accessor Methods
			
			
			
			
			/// Return a pointer to the graphics context which is being used to render shadow maps.
			/**
			  * This pointer is NULL if the shadow map renderer renderer does not have a valid context.
			  */
			RIM_INLINE const Pointer<GraphicsContext>& getContext() const
			{
				return context;
			}
			
			
			
			
			/// Change the graphics context that should be used to render shadow maps.
			/**
			  * This method resets any internal context-specific rendering state, including any
			  * cached shadow maps.
			  *
			  * The method returns whether or not the shadow map renderer was reinitialized
			  * successfully. A NULL or invalid context is allowed but will cause the method to return
			  * FALSE, causing the renderer to be unusable.
			  */
			Bool setContext( const Pointer<GraphicsContext>& newContext );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Scene Accessor Methods
			
			
			
			
			/// Return a pointer to the scene that is currently being used to render shadow maps.
			RIM_INLINE const Pointer<GraphicsScene>& getScene() const
			{
				return scene;
			}
			
			
			
			
			/// Set a pointer to the scene that should be used to render shadow maps.
			RIM_INLINE void setScene( const Pointer<GraphicsScene>& newScene )
			{
				scene = newScene;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shadow Map Accessor Methods
			
			
			
			
			/// Render the shadow map for the given light and return the shadow map.
			/**
			  * If the shadow map for this light was not already stored in the cache
			  * for this shadow map renderer, it is added to the cache. Otherwise, the shadow map
			  * that was stored in the cache is returned. A pointer to this shadow map is returned.
			  *
			  * If there was an error in accessing the cache or creating shadow map, a NULL
			  * pointer is returned. If the light pointer is NULL the method fails, returning NULL.
			  *
			  * Since no camera is specified, the camera's view is not taken into account when
			  * rendering the shadow map for the light. This may result in lower quality shadows.
			  * This method is equivalent to calling the overload cacheShadowMap(light,NULL).
			  */
			RIM_INLINE const ShadowMap* cacheShadowMap( const Pointer<Light>& light )
			{
				return this->cacheShadowMap( light, Pointer<Camera>() );
			}
			
			
			
			
			/// Render the shadow map for the given light and camera combination if necessary and return the shadow map.
			/**
			  * If the shadow map for this light/camera pair was not already stored in the cache
			  * for this shadow map renderer, it is added to the cache. Otherwise, the shadow map
			  * that was stored in the cache is returned. A pointer to this shadow map is returned.
			  *
			  * If there was an error in accessing the cache or creating shadow map, a NULL
			  * pointer is returned. If the light pointer is NULL the method fails, returning NULL.
			  *
			  * If the camera pointer is NULL, the camera's view is not taken into account when
			  * rendering the shadow map for the light. This may result in lower quality shadows.
			  */
			const ShadowMap* cacheShadowMap( const Pointer<Light>& light, const Pointer<Camera>& camera );
			
			
			
			
			/// Return the shadow map for the given light stored in the renderer's cache.
			/**
			  * If there is no shadow map for this light, a NULL pointer is returned.
			  */
			RIM_INLINE const ShadowMap* getShadowMap( const Pointer<Light>& light ) const
			{
				return this->getShadowMap( light, Pointer<Camera>() );
			}
			
			
			
			
			/// Return the shadow map for the given light and camera combination stored in the renderer's cache.
			/**
			  * If there is no shadow map for this combination, a NULL pointer is returned.
			  */
			const ShadowMap* getShadowMap( const Pointer<Light>& light, const Pointer<Camera>& camera ) const;
			
			
			
			
			/// Return the total number of cached entries in the shadow map cache.
			/**
			  * This is the number of shadow maps that currently in use (not counting unused shadow
			  * map textures).
			  */
			RIM_INLINE Size getCacheSize() const
			{
				return shadowMapCache.getSize();
			}
			
			
			
			
			/// Return the approximate memory usage in bytes of the entries in the shadow map cache.
			/**
			  * This is computed from the number of shadow maps that currently in use (not counting unused shadow
			  * map textures).
			  */
			RIM_INLINE Size getCacheSizeInBytes() const
			{
				return cacheSizeInBytes;
			}
			
			
			
			
			/// Remove all previously cached shadow maps from this shadow map renderer's internal cache, keeping the texture storage.
			/**
			  * This method should generally be called at the beginning of drawing the shadow maps for
			  * the scene because it removes all cached shadow maps from the previous frame. This
			  * method allows the texture storage from the last frame to be reused, unlike the clearCache()
			  * method.
			  */
			void emptyCache();
			
			
			
			
			/// Remove all previously cached shadow maps from this shadow map renderer's internal cache.
			/**
			  * This method also releases all texture storage that was previously used by the cache.
			  * Calling this method every frame may be expensive, since textures would need to be recreated
			  * after each call.
			  */
			void clearCache();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shadow Parameter Accessor Methods
			
			
			
			
			/// Return a value indicating the approximate pixel-to-unit scale factor for shadow textures.
			/**
			  * This value is used to determine the resolution of a shadow map in order
			  * to meet a minimum texel density per world unit.
			  *
			  * The default shadow quality is 100, corresponding to 100 texels per world unit.
			  * If the units are meters, this means one texel per centimeter.
			  */
			RIM_INLINE Real getShadowQuality() const
			{
				return shadowQuality;
			}
			
			
			
			
			/// Set a value indicating the approximate pixel-to-unit scale factor for shadow textures.
			/**
			  * This value is used to determine the resolution of a shadow map in order
			  * to meet a minimum texel density per world unit.
			  *
			  * The new shadow quality factor is clamped to be greater than 0.001, which would
			  * correspond to a 1-texel-per-kilometer resolution if meters are the units.
			  *
			  * The default shadow quality is 100, corresponding to 100 texels per world unit.
			  * If the units are meters, this means one texel per centimeter.
			  */
			RIM_INLINE void setShadowQuality( Real newShadowQuality )
			{
				shadowQuality = math::max( newShadowQuality, MINIMUM_SHADOW_QUALITY );
			}
			
			
			
			
			/// Return the minimum allowed resolution (width or height) for a shadow map.
			RIM_INLINE Size getMinimumShadowSize() const
			{
				return minimumShadowSize;
			}
			
			
			
			
			/// Set the minimum allowed resolution (width or height) for a shadow map.
			/**
			  * This value is clamped to be greater than 1.
			  */
			RIM_INLINE void setMinimumShadowSize( Size newMinimumShadowSize )
			{
				minimumShadowSize = math::max( newMinimumShadowSize, Size(1) );
			}
			
			
			
			
			/// Return the maximum allowed resolution (width or height) for a shadow map.
			RIM_INLINE Size getMaximumShadowSize() const
			{
				return maximumShadowSize;
			}
			
			
			
			
			/// Set the maximum allowed resolution (width or height) for a shadow map.
			/**
			  * This value is clamped to be greater than 1.
			  */
			RIM_INLINE void setMaximumShadowSize( Size newMaximumShadowSize )
			{
				maximumShadowSize = math::max( newMaximumShadowSize, Size(1) );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which represents a light/camera pair.
			class LightCamera
			{
				public:
					
					/// Create a new light/camera pair with the specified light and camera pointers.
					RIM_INLINE LightCamera( const Light* newLight, const Camera* newCamera )
						:	light( newLight ),
							camera( newCamera )
					{
					}
					
					
					/// Return whether or not this light-camera pair is equal to another.
					RIM_INLINE Bool operator == ( const LightCamera& other ) const
					{
						return light == other.light && camera == other.camera;
					}
					
					
					/// Return a hash code for this light-camera pair.
					RIM_INLINE Hash getHashCode() const
					{
						return Hash((PointerInt(light)*PointerInt(2185031351ul)) ^ (PointerInt(camera)*PointerInt(4232417593ul)));
					}
					
					
					/// A pointer to the light which is part of this light-camera pair.
					const Light* light;
					
					
					/// A pointer to the camera which is part of this light-camera pair.
					const Camera* camera;
					
			};
			
			
			
			
			/// A class storing a single shadow map texture and information about it.
			class ShadowMapInfo
			{
				public:
					
					/// Create a new shadow map information object.
					RIM_INLINE ShadowMapInfo( const Resource<Texture>& newTexture,
											const Pointer<Framebuffer>& newFramebuffer, Bool newInUse )
						:	texture( newTexture ),
							framebuffer( newFramebuffer ),
							inUse( newInUse )
					{
					}
					
					
					/// A pointer to the texture which stores this shadow map.
					Resource<Texture> texture;
					
					
					/// A pointer to a framebuffer object that is used to bind the shadow map for rendering.
					Pointer<Framebuffer> framebuffer;
					
					
					/// A boolean value indicating whether or not this shadow map is currently in use by a light-camera pair.
					Bool inUse;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Render a new shadow map for the given light and camera combination.
			/**
			  * The method returns whether or not the operation was successful.
			  * The resulting shadow map is returned in the output texture parameter,
			  * as is the shadow texture matrix that transforms from world space to light
			  * texture space.
			  */
			RIM_FORCE_INLINE Bool renderShadowMap( const Light* light, const Camera* camera,
													Resource<Texture>& texture, Matrix4& shadowTextureMatrix );
			
			
			
			
			/// Render a new shadow map for the given directional light and camera combination.
			Bool renderDirectionalLightShadowMap( const DirectionalLight* light, const Camera* camera,
											Resource<Texture>& texture, Matrix4& shadowTextureMatrix );
			
			
			
			
			/// Render a new shadow map for the given point light and camera combination.
			Bool renderPointLightShadowMap( const PointLight* light, const Camera* camera,
											Resource<Texture>& texture, Matrix4& shadowProjectionMatrix );
			
			
			
			
			/// Render a new shadow map for the given spot light and camera combination.
			Bool renderSpotLightShadowMap( const SpotLight* light, const Camera* camera,
											Resource<Texture>& texture, Matrix4& shadowTextureMatrix );
			
			
			
			
			/// Render a light view to the given framebuffer.
			/**
			  * The method uses the second camera when determining the level-of-detail
			  * for the geometry to be rendered. The method writes the final shadow
			  * texture matrix to the output parameter.
			  */
			Bool renderLightView( const Camera& lightView, const Camera& camera, const ArrayList<MeshChunk>& meshChunks,
								const Pointer<Framebuffer>& framebuffer );
			
			
			
			
			/// Return a pointer to the material technique to use for rendering the given chunk to a shadow map.
			RIM_FORCE_INLINE const MaterialTechnique* getChunkTechnique( const MeshChunk& chunk ) const;
			
			
			
			
			/// Return a pointer to the default material technique to use for rendering to a shadow map.
			RIM_FORCE_INLINE const MaterialTechnique* getDefaultTechnique() const;
			
			
			
			
			/// Return a new empty shadow map which meets the given specifications.
			/**
			  * This shadow map texture may be either newly created or reused from the
			  * pool of shadow maps. The method returns NULL if no such shadow map was
			  * found or able to be created.
			  */
			ShadowMapInfo* findEmptyShadowMap( Size minimumWidth, Size minimumHeight, Bool cubeMap = false );
			
			
			
			
			/// Return a new empty cube shadow map which meets the given specifications.
			/**
			  * This shadow map texture may be either newly created or reused from the
			  * pool of shadow maps. The method returns NULL if no such shadow map was
			  * found or able to be created.
			  */
			RIM_INLINE ShadowMapInfo* findEmptyCubeShadowMap( Size minimumSize )
			{
				return this->findEmptyShadowMap( minimumSize, minimumSize, true );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the graphics context which is used to render the shadow maps.
			Pointer<GraphicsContext> context;
			
			
			
			
			/// A pointer to the scene for which shadow maps are being rendered.
			Pointer<GraphicsScene> scene;
			
			
			
			
			/// A cache of shadow maps for light-camera pairs.
			HashMap<LightCamera,ShadowMap> shadowMapCache;
			
			
			
			
			/// A list of shadow maps that are part of the cache.
			/**
			  * Each entry is marked as either in use by some light-camera pair or free for use.
			  * Upon needing storage for a shadow map, the renderer looks through this list
			  * for unused shadow maps and uses the first that satisfies its requirements.
			  */
			ArrayList<ShadowMapInfo> shadowMaps;
			
			
			
			
			/// The total size of the cache's texture data in bytes.
			Size cacheSizeInBytes;
			
			
			
			
			/// A temporary list of mesh chunks in the scene.
			ArrayList<MeshChunk> meshChunks;
			
			
			
			
			/// The set of current global shader binding data.
			ShaderBindingData globalBindingData;
			
			
			
			
			/// A pointer to the default material technique to use when an object doesn't specify one for depth rendering.
			mutable Pointer<MaterialTechnique> defaultTechnique;
			
			
			
			
			/// The depth value to which the screen should be cleared before rendering a shadow map.
			Double clearDepth;
			
			
			
			
			/// A value indicating the approximate pixel-to-unit scale factor for shadow textures.
			/**
			  * This value is used to determine the resolution of a shadow map in order
			  * to meet a minimum texel density per world unit. This value is equal
			  * to the number of shadow texels that should cover any surface in the scene.
			  */
			Real shadowQuality;
			
			
			
			
			/// Return the minimum allowed resolution (width or height) for a shadow map.
			Size minimumShadowSize;
			
			
			
			
			/// Return the maximum allowed resolution (width or height) for a shadow map.
			Size maximumShadowSize;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The default depth value to clear the depth buffer to.
			static const Double DEFAULT_CLEAR_DEPTH;
			
			
			
			
			/// The default shadow quality factor to use when creating a shadow map renderer.
			static const Real DEFAULT_SHADOW_QUALITY;
			
			
			
			
			/// The minimum shadow quality factor to use when creating a shadow map renderer.
			static const Real MINIMUM_SHADOW_QUALITY;
			
			
			
			
			/// The default minimum allowed resolution (width or height) for a shadow map.
			static const Size DEFAULT_MINIMUM_SHADOW_SIZE = 128;
			
			
			
			
			/// The default maximum allowed resolution (width or height) for a shadow map.
			static const Size DEFAULT_MAXIMUM_SHADOW_SIZE = 4096;
			
			
			
			
			/// A matrix which transformed from normalized device coordinates [-1,1] to texture coordinates [0,1].
			static const Matrix4 UV_SCALE_MATRIX;
			
			
			
			
			/// A set of 6 orientation matrices that correspond to the view transformations for the 6 cube map faces.
			static const Matrix3 POINT_LIGHT_FACE_VIEWS[6];
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Renderers Namespace  ****************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADOW_MAP_RENDERER_H
