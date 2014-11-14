/*
 *  rimGraphicsShadowMap.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 12/5/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADOW_MAP_H
#define INCLUDE_RIM_GRAPHICS_SHADOW_MAP_H


#include "rimGraphicsTexturesConfig.h"


#include "rimGraphicsTexture.h"


//##########################################################################################
//**********************  Start Rim Graphics Textures Namespace  ***************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which stores a shadow map texture and shadow map texture matrix for that texture.
/**
  * The texture matrix transforms points from world space into the normalized texture coordinate
  * space for the light's shadow map.
  */
class ShadowMap
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a shadow map object with no associated texture.
			RIM_INLINE ShadowMap()
				:	texture()
			{
			}
			
			
			
			
			/// Create a shadow map object for the given shadow map texture and shadow texture matrix.
			RIM_INLINE ShadowMap( const Resource<Texture>& newTexture, const Matrix4& newShadowTextureMatrix )
				:	texture( newTexture ),
					shadowTextureMatrix( newShadowTextureMatrix )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Accessor Methods
			
			
			
			
			/// Return a pointer to the texture which is used to store this shadow map.
			RIM_INLINE const Resource<Texture>& getTexture() const
			{
				return texture;
			}
			
			
			
			
			/// Set a pointer to the texture which is used to store this shadow map.
			RIM_INLINE void setTexture( const Resource<Texture>& newTexture )
			{
				texture = newTexture;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shadow Texture Matrix Accessor Methods
			
			
			
			
			/// Return a reference to the shadow texture matrix for this shadow map.
			/**
			  * The texture matrix transforms points from world space into the normalized texture coordinate
			  * space for the light's shadow map.
			  */
			RIM_INLINE const Matrix4& getMatrix() const
			{
				return shadowTextureMatrix;
			}
			
			
			
			
			/// Set a pointer to the texture which is used to store this shadow map.
			/**
			  * The texture matrix transforms points from world space into the normalized texture coordinate
			  * space for the light's shadow map.
			  */
			RIM_INLINE void setMatrix( const Matrix4& newShadowTextureMatrix )
			{
				shadowTextureMatrix = newShadowTextureMatrix;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			Resource<Texture> texture;
			
			
			
			
			Matrix4 shadowTextureMatrix;
			
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Textures Namespace  *****************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADOW_MAP_H
