/*
 *  rimGraphicsTextureFilterType.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 12/21/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_TEXTURE_FILTER_TYPE_H
#define INCLUDE_RIM_GRAPHICS_TEXTURE_FILTER_TYPE_H


#include "rimGraphicsTexturesConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Textures Namespace  ***************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies how texture should be magnified or reduced in size.
/**
  * This class allows the user to specify the basic filter type used to decrease
  * or increase the size of a texture, as well as a floating-point anisotropy
  * level. This anisotropy level indicates how much anisotropic filtering can be done.
  */
class TextureFilterType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Enum Declaration
			
			
			
			
			/// An enum type which represents the different texture filtering types.
			typedef enum Enum
			{
				/// A nearest-neighbor filter type. The closest texel is chosen without any interpolation.
				/**
				  * This filter type is generally undesireable because it will produce blocky artifacts
				  * when used to enlarge a texture and will produce texture 'sparkling' when used
				  * to reduce a texture's size.
				  */
				NEAREST,
				
				/// A linear filter type. The final texel is computed from a linear interpolation of the nearest texels.
				/**
				  * This filter type produces smooth texel interpolation when used for texture magnification.
				  * This filter type is undesirable for texture minification because it produces
				  * 'sparkling' artifacts because no mip-maps are used.
				  */
				LINEAR,
				
				/// A linear filter type. The final texel is computed from a linear interpolation of the nearest texels in the nearest mipmap level.
				/**
				  * This filter type should not be used for texture magnification (it is needless overkill, use LINEAR instead).
				  * This filter type produces better results for texture minification than LINEAR, but
				  * still produces artifacts where mip-map levels change.
				  */
				BILINEAR,
				
				/// A linear filter type. The final texel is computed from a linear interpolation of the nearest texels in the nearest two mipmap levels.
				/**
				  * This filter type should not be used for texture magnification (it is needless overkill, use LINEAR instead).
				  * This filter type produces better results for texture minification than LINEAR or BILINEAR.
				  * Texture mip-map levels are smoothly interpolated between, resulting in the smoothest kind
				  * of texture filtering.
				  */
				TRILINEAR,
				
				/// An undefined type of textuer filtering.
				UNDEFINED
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new UNDEFINED texture filter type.
			RIM_INLINE TextureFilterType()
				:	type( UNDEFINED ),
					anisotropy( 1.0f )
			{
			}
			
			
			
			
			/// Create a new texture filter type with the specified filter type and default anisotropy of 1.0
			RIM_INLINE TextureFilterType( Enum newType )
				:	type( newType ),
					anisotropy( 1.0f )
			{
			}
			
			
			
			
			/// Create a new texture filter type with the specified filter type and anisotropy.
			RIM_INLINE TextureFilterType( Enum newType, Float newAnisotropy )
				:	type( newType ),
					anisotropy( newAnisotropy )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this texture filter type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Anisotropy Accessor Methods
			
			
			
			
			/// Get the maximum level of anisotropy which this texture filter type should use.
			RIM_INLINE Float getAnisotropy() const
			{
				return anisotropy;
			}
			
			
			
			
			/// Set the maximum level of anisotropy which this texture filter type should use.
			RIM_INLINE void setAnisotropy( Float newAnisotropy )
			{
				anisotropy = newAnisotropy;
			}
			
			
			
			
			/// Return the maximum texture filter anisotropy allowed by the graphics implementation.
			static Float getMaxAnisotropy();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a unique string for this texture filter type that matches its enum value name.
			String toEnumString() const;
			
			
			
			
			/// Return a texture filter type which corresponds to the given enum string.
			static TextureFilterType fromEnumString( const String& enumString );
			
			
			
			
			/// Return a string representation of the texture filter type.
			String toString() const;
			
			
			
			
			/// Convert this texture filter type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum for the texture filter type.
			Enum type;
			
			
			
			
			/// The maximum level of anisotropy which this texture filter type should use.
			Float anisotropy;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Textures Namespace  *****************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_TEXTURE_FILTER_TYPE_H
