/*
 *  rimResourceType.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/24/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_RESOURCE_TYPE_H
#define INCLUDE_RIM_RESOURCE_TYPE_H


#include "rimResourcesConfig.h"


//##########################################################################################
//**************************  Start Rim Resources Namespace  *******************************
RIM_RESOURCES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An enum class which specifies a kind of resource.
class ResourceType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resource Type Enum Definition
			
			
			
			
			/// An enum type which represents the type of resource type.
			typedef enum Enum
			{
				/// An undefined resource type.
				UNDEFINED = 0,
				
				//********************************************************************************
				// High-Level Types
				
				/// A resource type that corresponds to a multi-media scene with graphics, physics, and sound data, etc.
				ASSET_SCENE,
				
				//********************************************************************************
				// Graphics Types
				
				/// A resource type that corresponds to a graphics scene: a collection of objects, cameras, lights, etc.
				GRAPHICS_SCENE,
				
				/// A resource type that correponds to an object or object hierarchy.
				GRAPHICS_OBJECT,
				
				/// A resource type that corresponds to a camera/viewport.
				GRAPHICS_CAMERA,
				
				/// A resource type that corresponds to a light.
				GRAPHICS_LIGHT,
				
				/// A resource type that corresponds to a renderable shape.
				GRAPHICS_SHAPE,
				
				/// A resource type that corresponds to a visual material.
				GRAPHICS_MATERIAL,
				
				/// A resource type that corresponds to a material rendering technique.
				GRAPHICS_TECHNIQUE,
				
				/// A resource type that corresponds to a shader pass.
				SHADER_PASS,
				
				/// A resource type that corresponds to a specific shader pass implementation.
				SHADER_PASS_VERSION,
				
				/// A resource type that corresponds to a shader source code.
				SHADER_SOURCE,
				
				/// A resource type that corresponds to a configuration for a shader pass.
				SHADER_CONFIGURATION,
				
				/// A resource type that corresponds to a shader constant binding.
				SHADER_CONSTANT_BINDING,
				
				/// A resource type that corresponds to a shader texture binding.
				SHADER_TEXTURE_BINDING,
				
				/// A resource type that corresponds to a shader vertex binding.
				SHADER_VERTEX_BINDING,
				
				/// A resource type that corresponds to a texture: an image plus sampling characteristics.
				TEXTURE,
				
				/// A resource type that corresponds to the type of a texture.
				TEXTURE_TYPE,
				
				/// A resource type that corresponds to an image.
				IMAGE,
				
				/// A resource type that corresponds to a buffer of shader attributes.
				ATTRIBUTE_BUFFER,
				
				/// A resource type that corresponds to the rendering state configuration for a shader pass.
				RENDER_MODE,
				
				/// A resource type that describes how alpha testing should be performed.
				ALPHA_TEST,
				
				/// A resource type that describes how blending should be performed.
				BLEND_MODE,
				
				/// A resource type that describes how depth testing should be performed.
				DEPTH_MODE,
				
				/// A resource type that describes how stencil testing should be performed.
				STENCIL_MODE,
				
				//********************************************************************************
				// Sound Types
				
				/// A resource type that corresponds to a buffer of sound sample data.
				SOUND,
				
				/// A resource type that corresponds to a sequence of musical notes and control information.
				MIDI
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new resource type with the UNDEFINED resource type.
			RIM_INLINE ResourceType()
				:	type( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new resource type with the specified resource type enum value.
			RIM_INLINE ResourceType( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this resource type type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a unique string for this resource format that matches its enum value name.
			data::String toEnumString() const;
			
			
			
			
			/// Return a resource type which corresponds to the given enum string.
			static ResourceType fromEnumString( const data::String& enumString );
			
			
			
			
			/// Return a string representation of the resource type.
			data::String toString() const;
			
			
			
			
			/// Convert this resource type into a string representation.
			RIM_FORCE_INLINE operator data::String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value which indicates the type of resource type.
			Enum type;
			
			
			
};




//##########################################################################################
//**************************  End Rim Resources Namespace  *********************************
RIM_RESOURCES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_RESOURCE_TYPE_H
