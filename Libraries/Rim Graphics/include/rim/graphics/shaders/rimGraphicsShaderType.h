/*
 *  rimGraphicsShaderType.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/7/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_TYPE_H
#define INCLUDE_RIM_GRAPHICS_SHADER_TYPE_H


#include "rimGraphicsShadersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies a kind of Shader.
/**
  * The type specified here is used to determine the kinds of operations that a
  * shader can perform, as well as how it may be structured (inputs/outputs).
  */
class ShaderType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Attribute Buffer Usage Enum Definition
			
			
			
			
			/// An enum type which represents the type for a shader.
			typedef enum Enum
			{
				/// An undefined shader type.
				UNDEFINED = 0,
				
				/// A shader that handles processing of individual vertices.
				/**
				  * This allows transformations and other operations to be
				  * performed on a per-vertex basis.
				  */
				VERTEX,
				
				/// A shader that is executed for each output fragment (pixel) for a primitive.
				/**
				  * This allows shading and other operations to be performed on
				  * a per-pixel basis. The output of the fragment shader is the
				  * final color value sent to the render target.
				  */
				FRAGMENT,
				
				/// A shader that takes an input primitive (i.e. triangles) and outputs 0 or more output primitives.
				/**
				  * This allows things like geometry instancing.
				  */
				GEOMETRY,
				
				/// A shader that tessellates primitives into smaller primitives.
				/**
				  * This allows additional geometric complexity to be generated
				  * in the shader.
				  */
				TESSELLATION
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new shader type with the ShaderType::UNDEFINED type.
			RIM_INLINE ShaderType()
				:	type( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new shader type with the specified type enum value.
			RIM_INLINE ShaderType( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this shader type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a shader type which corresponds to the given enum string.
			static ShaderType fromEnumString( const String& enumString );
			
			
			
			
			/// Return a unique string for this shader type that matches its enum value name.
			String toEnumString() const;
			
			
			
			
			/// Return a string representation of the shader type.
			String toString() const;
			
			
			
			
			/// Convert this shader type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value for the shader type.
			Enum type;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_TYPE_H
