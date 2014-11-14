/*
 *  rimGraphicsConstantUsage.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 1/13/11.
 *  Copyright 2011 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_CONSTANT_USAGE_H
#define INCLUDE_RIM_GRAPHICS_CONSTANT_USAGE_H


#include "rimGraphicsShadersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies how a constant is semantically used for rendering.
/**
  * Each instance allows the user to specify an enum value indicating the
  * type of usage and also an integral index for that usage. This allows the user
  * to specify multiple light-position usages, for instance.
  */
class ConstantUsage
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	ConstantUsage Usage Enum Definition
			
			
			
			
			typedef enum Enum
			{
				/// An undefined constant usage.
				UNDEFINED,
				
				
				//******************************************************************
				// Material attributes.
				
				/// The 3 or 4 component diffuse color of a material surface.
				DIFFUSE_COLOR,
				
				/// The 3 or 4 component specular color of a material surface.
				SPECULAR_COLOR,
				
				/// The 3 or 4 component ambient color of a material surface.
				AMBIENT_COLOR,
				
				/// A scalar value between 0 and 1 that indicates how bright the material's specular highlight should be.
				REFLECTIVITY,
				
				/// The scalar floating-point phong exponent for a material.
				PHONG_EXPONENT,
				
				/// The index of refraction of a material.
				INDEX_OF_REFRACTION,
				
				
				//******************************************************************
				// Matrix attributes.
				
				/// The 4x4 transformation matrix from object space to world space.
				MODEL_MATRIX,
				
				/// The 4x4 transformation matrix from object space to world space.
				INVERSE_MODEL_MATRIX,
				
				/// The 4x4 transformation matrix from view to world space.
				VIEW_MATRIX,
				
				/// The 4x4 transformation matrix from world to view space.
				INVERSE_VIEW_MATRIX,
				
				/// The 4x4 transformation matrix from object to world to view space.
				MODEL_VIEW_MATRIX,
				
				/// The 4x4 projection matrix for the current view.
				PROJECTION_MATRIX,
				
				/// The modelview matrix multiplied by the projection matrix (P*Mv).
				MODEL_VIEW_PROJECTION_MATRIX,
				
				/// The upper-left 3x3 section of the inverse of the transpose of the model matrix.
				MODEL_NORMAL_MATRIX,
				
				/// The upper-left 3x3 section of the inverse of the transpose of the model view matrix.
				MODEL_VIEW_NORMAL_MATRIX,
				
				/// The 4x4 transformation matrix from bone to model-space.
				BONE_MATRIX,
				
				
				//******************************************************************
				// Lighting attributes for directional lights
				
				/// The 3d vector specifying the direction to a directional light in world space.
				DIRECTIONAL_LIGHT_DIRECTION,
				
				/// The 3d vector specifying the direction to a directional light in view space.
				DIRECTIONAL_LIGHT_VIEW_SPACE_DIRECTION,
				
				/// The 3d vector specifying the direction of maximum highlights for a directional light in view space.
				DIRECTIONAL_LIGHT_VIEW_SPACE_HALF_VECTOR,
				
				/// The 3 or 4 component diffuse color of a directional light source.
				DIRECTIONAL_LIGHT_DIFFUSE_COLOR,
				
				/// The 3 or 4 component specular color of a directional light source.
				DIRECTIONAL_LIGHT_SPECULAR_COLOR,
				
				/// The 3 or 4 component ambient color of a directional light source.
				DIRECTIONAL_LIGHT_AMBIENT_COLOR,
				
				/// The 4x4 matrix transforming view-space positions into shadow map texture coordinate space for a directional light.
				DIRECTIONAL_LIGHT_SHADOW_TEXTURE_MATRIX,
				
				/// The 4x4 matrix transforming view-space positions into texture coordinates for a directional light shadow map cascade.
				DIRECTIONAL_LIGHT_CSM_MATRIX_0,
				DIRECTIONAL_LIGHT_CSM_MATRIX_1 = DIRECTIONAL_LIGHT_CSM_MATRIX_0 + 1,
				DIRECTIONAL_LIGHT_CSM_MATRIX_2 = DIRECTIONAL_LIGHT_CSM_MATRIX_0 + 2,
				DIRECTIONAL_LIGHT_CSM_MATRIX_3 = DIRECTIONAL_LIGHT_CSM_MATRIX_0 + 3,
				DIRECTIONAL_LIGHT_CSM_MATRIX_4 = DIRECTIONAL_LIGHT_CSM_MATRIX_0 + 4,
				DIRECTIONAL_LIGHT_CSM_MATRIX_5 = DIRECTIONAL_LIGHT_CSM_MATRIX_0 + 5,
				DIRECTIONAL_LIGHT_CSM_MATRIX_6 = DIRECTIONAL_LIGHT_CSM_MATRIX_0 + 6,
				DIRECTIONAL_LIGHT_CSM_MATRIX_7 = DIRECTIONAL_LIGHT_CSM_MATRIX_0 + 7,
				
				/// A 2d vector specifying the horizontal and vertical resolution for a directional light shadow map.
				DIRECTIONAL_LIGHT_SHADOW_MAP_SIZE,
				
				
				//******************************************************************
				// Lighting attributes for point lights
				
				/// The 3d or 4d vector specifying the position of a point light in world space.
				POINT_LIGHT_POSITION,
				
				/// The 3d or 4d vector specifying the position of a point light in view space.
				POINT_LIGHT_VIEW_SPACE_POSITION,
				
				/// The 3 or 4 component diffuse color of a point light source.
				POINT_LIGHT_DIFFUSE_COLOR,
				
				/// The 3 or 4 component specular color of a point light source.
				POINT_LIGHT_SPECULAR_COLOR,
				
				/// The 3 or 4 component ambient color of a point light source.
				POINT_LIGHT_AMBIENT_COLOR,
				
				/// The scalar constant attenuation of a spot light source.
				POINT_LIGHT_CONSTANT_ATTENUATION,
				
				/// The scalar linear attenuation of a spot light source.
				POINT_LIGHT_LINEAR_ATTENUATION,
				
				/// The scalar quadratic attenuation of a spot light source.
				POINT_LIGHT_QUADRATIC_ATTENUATION,
				
				/// The 4x4 projection matrix for each of the faces of a point light cube shadow map.
				POINT_LIGHT_SHADOW_CUBE_PROJECTION_MATRIX,
				
				
				//******************************************************************
				// Lighting attributes for spot lights
				
				/// The 3d or 4d vector specifying the position of a spot light in world space.
				SPOT_LIGHT_POSITION,
				
				/// The 3d or 4d vector specifying the position of a spot light in view space.
				SPOT_LIGHT_VIEW_SPACE_POSITION,
				
				/// The 3d vector specifying the direction of a spot light in world space.
				SPOT_LIGHT_DIRECTION,
				
				/// The 3d vector specifying the direction of a light in view space.
				SPOT_LIGHT_VIEW_SPACE_DIRECTION,
				
				/// The scalar spot cutoff angle in radians of a spot light.
				SPOT_LIGHT_CUTOFF,
				
				/// The cosine of the scalar spot cutoff angle of a spot light.
				SPOT_LIGHT_COSINE_CUTOFF,
				
				/// The the scalar spot falloff angle of a spot light.
				SPOT_LIGHT_FALLOFF,
				
				/// The cosine of the scalar spot falloff angle of a spot light.
				SPOT_LIGHT_COSINE_FALLOFF,
				
				/// The scalar falloff of the spot light from the light's direction.
				SPOT_LIGHT_EXPONENT,
				
				/// The 3 or 4 component diffuse color of a spot light source.
				SPOT_LIGHT_DIFFUSE_COLOR,
				
				/// The 3 or 4 component specular color of a spot light source.
				SPOT_LIGHT_SPECULAR_COLOR,
				
				/// The 3 or 4 component ambient color of a spot light source.
				SPOT_LIGHT_AMBIENT_COLOR,
				
				/// The scalar constant attenuation of a spot light source.
				SPOT_LIGHT_CONSTANT_ATTENUATION,
				
				/// The scalar linear attenuation of a spot light source.
				SPOT_LIGHT_LINEAR_ATTENUATION,
				
				/// The scalar quadratic attenuation of a spot light source.
				SPOT_LIGHT_QUADRATIC_ATTENUATION,
				
				/// The 4x4 matrix transforming view-space positions into shadow map texture coordinate space for a spot light
				SPOT_LIGHT_SHADOW_TEXTURE_MATRIX,
				
				/// A 2d vector specifying the horizontal and vertical resolution for a spot light shadow map.
				SPOT_LIGHT_SHADOW_MAP_SIZE,
				
				
				//******************************************************************
				// Shadow Attributes
				
				/// A factor by which the depth should be scaled when rendering a shadow map.
				SHADOW_DEPTH_BIAS,
				
				
				//******************************************************************
				// GUI Attributes
				
				/// The 3 or 4 component background color for a GUI object.
				GUI_BACKGROUND_COLOR,
				
				/// The 3 or 4 component border color for a GUI object.
				GUI_BORDER_COLOR,
				
				/// The scalar radius of the border bevels for a GUI object.
				GUI_BORDER_RADIUS,
				
				/// The scalar width of the border line for a GUI object.
				GUI_BORDER_WIDTH,
				
				/// The 3 or 4 component color that is used to shade (multiply) images displayed in a GUI.
				GUI_IMAGE_COLOR,
				
				/// The 3 or 4 component color to use for rendering text in a GUI.
				GUI_TEXT_COLOR,
				
				/// The size of a rendered pixel in the local coordinate space of a GUI object.
				GUI_PIXEL_SIZE,
				
				
				//******************************************************************
				// Sound Attributes
				
				/// The fraction of sound that hits a surface that is reflected, per frequency.
				SOUND_REFLECTIVITY,
				
				/// The fraction of reflected sound that hits a surface that is scattered, per frequency.
				SOUND_SCATTERING,
				
				/// The fraction of sound that is not reflected that is transmitted through the material, per frequency.
				SOUND_TRANSMISSION
				
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new constant usage with the specified constant usage enum value.
			RIM_INLINE ConstantUsage( Enum newUsage )
				:	usage( newUsage ),
					index( 0 )
			{
			}
			
			
			
			
			/// Create a new constant usage with the specified usage enum value and index.
			RIM_INLINE ConstantUsage( Enum newUsage, Index newIndex )
				:	usage( newUsage ),
					index( (UInt16)newIndex )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this constant usage to an enum value.
			RIM_INLINE operator Enum () const
			{
				return (Enum)usage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Equality Comparison Operators
			
			
			
			
			/// Return whether or not this constant usage is the same as another.
			RIM_INLINE Bool operator == ( const ConstantUsage& other ) const
			{
				return *((UInt32*)this) == *((UInt32*)&other);
			}
			
			
			
			
			/// Return whether or not this constant usage is the same as another.
			/**
			  * This operator does not compare any usage index, just the usage type.
			  */
			RIM_INLINE Bool operator == ( ConstantUsage::Enum other ) const
			{
				return usage == other;
			}
			
			
			
			
			/// Return whether or not this constant usage is different than another.
			RIM_INLINE Bool operator != ( const ConstantUsage& other ) const
			{
				return *((UInt32*)this) != *((UInt32*)&other);
			}
			
			
			
			
			/// Return whether or not this constant usage is different than another.
			/**
			  * This operator does not compare any usage index, just the usage type.
			  */
			RIM_INLINE Bool operator != ( ConstantUsage::Enum other ) const
			{
				return usage != other;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Attribute Type Accessor Method
			
			
			
			
			/// Return whether or not the specified attribute type is a valid type for this usage.
			Bool isValidType( const AttributeType& type ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Index Accessor Methods
			
			
			
			
			/// Return an index for the constant usage.
			/**
			  * This value allows the user to keep track of multiple distinct
			  * usages separately (i.e. for multiple lights) that have the
			  * same usage type.
			  */
			RIM_FORCE_INLINE Index getIndex() const
			{
				return index;
			}
			
			
			
			
			/// Return an index for the constant usage.
			/**
			  * This value allows the user to keep track of multiple distinct
			  * usages separately (i.e. for multiple lights) that have the
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
			
			
			
			
			/// Return a unique string for this constant usage that matches its enum value name.
			String toEnumString() const;
			
			
			
			
			/// Return a constant usage which corresponds to the given enum string.
			static ConstantUsage fromEnumString( const String& enumString );
			
			
			
			
			/// Return a string representation of the constant usage.
			String toString() const;
			
			
			
			
			/// Convert this constant usage into a string representation.
			RIM_FORCE_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Hash Code Accessor Method
			
			
			
			
			/// Return a hash code for this constant usage.
			RIM_FORCE_INLINE Hash getHashCode() const
			{
				return Hash(usage)*14111677 + Hash(index);
			}
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum for the constant usage.
			UInt16 usage;
			
			
			
			
			/// The index of the usage specified by the enum value.
			/**
			  * This value allows the user to keep track of multiple distinct
			  * usages separately (i.e. for multiple lights) that have the
			  * same usage type.
			  */
			UInt16 index;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_CONSTANT_USAGE_H
