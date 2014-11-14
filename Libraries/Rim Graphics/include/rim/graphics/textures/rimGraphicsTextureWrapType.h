/*
 *  rimGraphicsTextureWrapType.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 12/22/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_TEXTURE_WRAP_TYPE_H
#define INCLUDE_RIM_GRAPHICS_TEXTURE_WRAP_TYPE_H


#include "rimGraphicsTexturesConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Textures Namespace  ***************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies how a texture should repeat for texture coordinates outside the range (0,1).
/**
  * Textures can repeat, be clamped, or repeat in a mirrored fashion. Different
  * wrap types are suitable for tiling textures or for textures that should not
  * tile.
  */
class TextureWrapType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Enum Declaration
			
			
			
			
			/// An enum type which represents the different texture wrap types.
			typedef enum Enum
			{
				/// The texture uses the outer pixel edge for all texels outside the range (0,1).
				CLAMP,
				
				/// The texture repeats normally. Coordinates outside (0,1) are mod-ed to be in that range.
				REPEAT,
				
				/// The texture repeats in a mirrored fashion, producing seamless tiling for all images.
				MIRRORED_REPEAT,
				
				/// An undefined texture wrap type.
				UNDEFINED
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new texture wrap type with the specified wrap type enum value.
			RIM_INLINE TextureWrapType( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this texture wrap type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a unique string for this texture wrap type that matches its enum value name.
			String toEnumString() const;
			
			
			
			
			/// Return a texture wrap type which corresponds to the given enum string.
			static TextureWrapType fromEnumString( const String& enumString );
			
			
			
			
			/// Return a string representation of the texture wrap type.
			String toString() const;
			
			
			
			
			/// Convert this texture wrap type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum for the texture wrap type.
			Enum type;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Textures Namespace  *****************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_TEXTURE_WRAP_TYPE_H
