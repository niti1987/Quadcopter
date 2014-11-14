/*
 *  rimGraphicsTextureUsage.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/27/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_TEXTURE_USAGE_H
#define INCLUDE_RIM_GRAPHICS_TEXTURE_USAGE_H


#include "rimGraphicsTexturesConfig.h"


#include "rimGraphicsTexture.h"
#include "rimGraphicsTextureType.h"


//##########################################################################################
//**********************  Start Rim Graphics Textures Namespace  ***************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies how a texture is semantically used for rendering.
/**
  * Each instance allows the user to specify an enum value indicating the
  * type of usage and also an integral index for that usage. This allows the user
  * to specify multiple color map usages, for instance.
  */
class TextureUsage
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Texture Usage Enum Definition
			
			
			
			
			typedef enum Enum
			{
				/// An unfefined texture usage.
				UNDEFINED = 0,
				
				/// A usage which specifies that the texture is used as an ambient color texture map.
				AMBIENT_COLOR_MAP,
				
				/// A usage which specifies that the texture is used as a diffuse color texture map.
				DIFFUSE_COLOR_MAP,
				
				/// A usage which specifies that the texture is used as a specular color texture map.
				SPECULAR_COLOR_MAP,
				
				/// A usage which specifies that the texture is used as an object's normal map.
				NORMAL_MAP,
				
				/// A usage which specifies that the texture is used as an object's height/displacement map.
				DISPLACEMENT_MAP,
				
				/// A usage which specifies that the texture is used as an object's height/displacement map.
				HEIGHT_MAP = DISPLACEMENT_MAP,
				
				/// A usage which specifies that the texture is used as an object's environment map.
				ENVIRONMENT_MAP,
				
				/// A usage which specifies that the texture is used as a scene's light map.
				LIGHT_MAP,
				
				/// A usage which specifies that the texture is used as a directional light shadow map.
				DIRECTIONAL_LIGHT_SHADOW_MAP,
				
				/// A usage for the closest shadow map cascade to the camera.
				DIRECTIONAL_LIGHT_CSM_0,
				DIRECTIONAL_LIGHT_CSM_1 = DIRECTIONAL_LIGHT_CSM_0 + 1,
				DIRECTIONAL_LIGHT_CSM_2 = DIRECTIONAL_LIGHT_CSM_0 + 2,
				DIRECTIONAL_LIGHT_CSM_3 = DIRECTIONAL_LIGHT_CSM_0 + 3,
				DIRECTIONAL_LIGHT_CSM_4 = DIRECTIONAL_LIGHT_CSM_0 + 4,
				DIRECTIONAL_LIGHT_CSM_5 = DIRECTIONAL_LIGHT_CSM_0 + 5,
				DIRECTIONAL_LIGHT_CSM_6 = DIRECTIONAL_LIGHT_CSM_0 + 6,
				DIRECTIONAL_LIGHT_CSM_7 = DIRECTIONAL_LIGHT_CSM_0 + 7,
				
				/// A usage for a texture array of directional light shadow map cascades.
				DIRECTIONAL_LIGHT_CSM_ARRAY,
				
				/// A usage which specifies that the texture is used as a point light shadow cube map.
				POINT_LIGHT_SHADOW_CUBE_MAP,
				
				/// A usage which specifies that the texture is used as a spot light shadow map.
				SPOT_LIGHT_SHADOW_MAP
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new texture usage with the specified texture usage enum value.
			RIM_INLINE TextureUsage( Enum newUsage )
				:	usage( newUsage ),
					index( 0 )
			{
			}
			
			
			
			
			/// Create a new texture usage with the specified texture usage enum value and index.
			RIM_INLINE TextureUsage( Enum newUsage, Index newIndex )
				:	usage( newUsage ),
					index( (UInt16)newIndex )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this texture usage to an enum value.
			RIM_INLINE operator Enum () const
			{
				return (Enum)usage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Equality Comparison Operators
			
			
			
			
			/// Return whether or not this texture usage is the same as another.
			/**
			  * This operator does not compare any usage index, just the usage type.
			  */
			RIM_INLINE Bool operator == ( const TextureUsage::Enum otherEnum ) const
			{
				return usage == otherEnum;
			}
			
			
			
			
			/// Return whether or not this texture usage is the same as another.
			RIM_INLINE Bool operator == ( const TextureUsage& other ) const
			{
				return *((UInt32*)this) == *((UInt32*)&other);
			}
			
			
			
			
			/// Return whether or not this texture usage is different than another.
			/**
			  * This operator does not compare any usage index, just the usage type.
			  */
			RIM_INLINE Bool operator != ( const TextureUsage::Enum otherEnum ) const
			{
				return usage != otherEnum;
			}
			
			
			
			
			/// Return whether or not this texture usage is different than another.
			RIM_INLINE Bool operator != ( const TextureUsage& other ) const
			{
				return *((UInt32*)this) != *((UInt32*)&other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Attribute Type Accessor Method
			
			
			
			
			/// Return whether or not the specified texture type is a valid type for this usage.
			Bool isValidType( const TextureType& type ) const;
			
			
			
			
			/// Return whether or not the specified texture is a valid type for this usage.
			Bool isValidType( const Texture& texture ) const;
			
			
			
			
			/// Return whether or not this texture usage represents a shadow map (depth texture) format.
			Bool isAShadowMap() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Index Accessor Methods
			
			
			
			
			/// Return an index for the shader attribute usage.
			/**
			  * This value allows the user to keep track of multiple distinct
			  * usages separately (i.e. for multiple color maps) that have the
			  * same usage type.
			  */
			RIM_FORCE_INLINE Index getIndex() const
			{
				return index;
			}
			
			
			
			
			/// Return an index for the shader attribute usage.
			/**
			  * This value allows the user to keep track of multiple distinct
			  * usages separately (i.e. for multiple color maps) that have the
			  * same usage type.
			  */
			RIM_FORCE_INLINE void setIndex( Index newIndex )
			{
				index = (UInt16)newIndex;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a texture usage which corresponds to the given enum string.
			static TextureUsage fromEnumString( const String& enumString );
			
			
			
			
			/// Return a unique string for this texture usage that matches its enum value name.
			String toEnumString() const;
			
			
			
			
			/// Return a string representation of the texture usage.
			String toString() const;
			
			
			
			
			/// Convert this texture usage into a string representation.
			RIM_FORCE_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Hash Code Accessor Method
			
			
			
			
			/// Return a hash code for this texture usage.
			RIM_FORCE_INLINE Hash getHashCode() const
			{
				return Hash(usage)*14111677 + Hash(index);
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum for the texture usage.
			UInt16 usage;
			
			
			
			
			/// The index of the usage specified by the enum value.
			/**
			  * This value allows the user to keep track of multiple distinct
			  * usages separately (i.e. for multiple color maps) that have the
			  * same usage type.
			  */
			UInt16 index;
			
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Textures Namespace  *****************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_TEXTURE_USAGE_H
