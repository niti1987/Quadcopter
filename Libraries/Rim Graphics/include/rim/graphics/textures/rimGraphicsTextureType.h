/*
 *  rimGraphicsTextureType.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 9/12/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_TEXTURE_TYPE_H
#define INCLUDE_RIM_GRAPHICS_TEXTURE_TYPE_H


#include "rimGraphicsTexturesConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Textures Namespace  ***************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies the high-level type of a texture.
/**
  * A texture type consists of the dimensionality of the texture, whether
  * or not it is a depth map (i.e. shadow map), and whether or not it is a cube
  * map.
  */
class TextureType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a texture type with the specified dimensionality and attributes.
			RIM_INLINE TextureType( Size newNumDimensions, Bool newIsAShadowMap, Bool newIsACubeMap )
				:	numDimensions( (UByte)newNumDimensions ),
					isShadowMap( newIsAShadowMap ),
					isCubeMap( newIsACubeMap )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Accessor Methods
			
			
			
			
			/// Get the number of dimensions in this texture type (usually 1, 2, or 3).
			RIM_INLINE Size getDimensionCount() const
			{
				return numDimensions;
			}
			
			
			
			
			/// Return whether or not this texture type represents a shadow map.
			RIM_INLINE Bool isAShadowMap() const
			{
				return isShadowMap != 0;
			}
			
			
			
			
			/// Return whether or not this texture type represents a cube map.
			RIM_INLINE Bool isACubeMap() const
			{
				return isCubeMap != 0;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Equality Comparison Operators
			
			
			
			
			/// Return whether or not this texture type is exactly equal to another.
			RIM_INLINE Bool operator == ( const TextureType& other ) const
			{
				return numDimensions == other.numDimensions && isShadowMap == other.isShadowMap && isCubeMap == other.isCubeMap;
			}
			
			
			
			
			/// Return whether or not this texture type is not equal to another.
			RIM_INLINE Bool operator != ( const TextureType& other ) const
			{
				return numDimensions != other.numDimensions || isShadowMap != other.isShadowMap || isCubeMap != other.isCubeMap;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The number of dimensions of the texture map.
			UByte numDimensions;
			
			
			
			
			/// Whether or not this texture type is a shadow (depth) map.
			UByte isShadowMap;
			
			
			
			
			/// Whether or not this texture type is a cube map.
			UByte isCubeMap;
			
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Textures Namespace  *****************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_TEXTURE_TYPE_H
