/*
 *  rimGraphicsTextureFace.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 1/2/11.
 *  Copyright 2011 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_TEXTURE_FACE_H
#define INCLUDE_RIM_GRAPHICS_TEXTURE_FACE_H


#include "rimGraphicsTexturesConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Textures Namespace  ***************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a particular face of a texture.
/**
  * While most common textures have only a single face (FRONT),
  * cube map textures may have six faces for the six axial directions
  * of a cube. This class allows the user to specify a particular face
  * of that cube map.
  */
class TextureFace
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Enum Declaration
			
			
			
			
			/// An enum which specifies the different allowed texture faces.
			typedef enum Enum
			{
				/// The face of the cube map in the positive X direction (front face).
				POSITIVE_X = 0,
				
				/// The front face of a texture (face in the positive X direction).
				FRONT = 0,
				
				/// The face of the cube map in the negative X direction.
				NEGATIVE_X = 1,
				
				/// The face of the cube map in the positive Y direction.
				POSITIVE_Y = 2,
				
				/// The face of the cube map in the negative Y direction.
				NEGATIVE_Y = 3,
				
				/// The face of the cube map in the positive Z direction.
				POSITIVE_Z = 4,
				
				/// The face of the cube map in the negative Z direction.
				NEGATIVE_Z = 5,
				
				/// An undefined face of a texture.
				UNDEFINED
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new texture face type with the specified face type enum value.
			RIM_INLINE TextureFace( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
			/// Create a new texture face type with the specified face index.
			RIM_INLINE TextureFace( Index faceIndex )
				:	type( faceIndex < TextureFace::getMaxFaceCount() ? (Enum)faceIndex : UNDEFINED )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Max Number Of Faces Accessor Method
			
			
			
			
			/// Return the maximum number of faces that a texture can have.
			RIM_INLINE static Size getMaxFaceCount()
			{
				return 6;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Direction Accessor Method
			
			
			
			
			/// Return a 3D vector indicating the cannonical direction for this texture face.
			Vector3 getDirection() const;
			
			
			
			
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
			
			
			
			
			/// Return a unique string for this texture face that matches its enum value name.
			String toEnumString() const;
			
			
			
			
			/// Return a texture face which corresponds to the given enum string.
			static TextureFace fromEnumString( const String& enumString );
			
			
			
			
			/// Return a string representation of the texture face type.
			String toString() const;
			
			
			
			
			/// Convert this texture face type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value which represents the texture face type.
			Enum type;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Textures Namespace  *****************************
RIM_GRAPHICS_TEXTURES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_TEXTURE_FACE_H
