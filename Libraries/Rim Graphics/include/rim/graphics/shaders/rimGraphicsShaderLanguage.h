/*
 *  rimGraphicsShaderLanguage.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/9/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_LANGUAGE_H
#define INCLUDE_RIM_GRAPHICS_SHADER_LANGUAGE_H


#include "rimGraphicsShadersConfig.h"


#include "rimGraphicsShaderLanguageVersion.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies a particular type and version of a shading language.
/**
  * The type specified here is used to determine how a shader's source
  * code is compiled.
  */
class ShaderLanguage
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Attribute Buffer Usage Enum Definition
			
			
			
			
			/// An enum type which represents the type for a shading language.
			/**
			  * Some of these shading language types may be unimplemented for
			  * the current platform.
			  */
			typedef enum Type
			{
				/// The OpenGL Shading Language.
				GLSL,
				
				/// The High-Level Shading Language for DirectX.
				HLSL,
				
				/// The NVIDIA Cg shading language.
				CG,
				
				/// ARB assembly language.
				ARB_ASSEMBLY,
				
				/// The PlayStation Shading Language.
				PSSL,
				
				/// The RenderMan offline shading language.
				RENDERMAN,
				
				/// The Houdini VEX offline shading language.
				VEX,
				
				/// The Gelato offline shading language.
				GELATO,
				
				/// The default shading language for a particular implementation.
				/**
				  * The version number is ignored for this shader language type.
				  */
				DEFAULT,
				
				/// An undefined shading language.
				UNDEFINED
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new shader language type with the specified type enum value.
			RIM_INLINE ShaderLanguage( Type newType )
				:	type( newType )
			{
			}
			
			
			
			
			/// Create a new shader language type with the specified type enum value.
			RIM_INLINE ShaderLanguage( Type newType, const ShaderLanguageVersion& newVersion )
				:	type( newType ),
					version( newVersion )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this shader language to an enum value.
			RIM_INLINE operator Type () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Type Accessor Methods
			
			
			
			
			/// Return an enum indicating the type of this shader language.
			RIM_INLINE Type getType() const
			{
				return type;
			}
			
			
			
			
			/// Set an enum indicating the type of this shader language.
			RIM_INLINE void setType( Type newType )
			{
				type = newType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Version Accessor Methods
			
			
			
			
			/// Return a reference to an object representing the version of this shader langauge.
			RIM_INLINE const ShaderLanguageVersion& getVersion() const
			{
				return version;
			}
			
			
			
			
			/// Set an object representing the version of this shader langauge.
			RIM_INLINE void setVersion( const ShaderLanguageVersion& newVersion )
			{
				version = newVersion;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a shader language type which corresponds to the given type enum string.
			static ShaderLanguage::Type fromEnumString( const String& enumString );
			
			
			
			
			/// Return a unique string for this shader language's type that matches its type enum value name.
			String toEnumString() const;
			
			
			
			
			/// Return a human-readable string representation of the shader language.
			String toString() const;
			
			
			
			
			/// Convert this shader language into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Predefined Shader Language Types
			
			
			
			
			/// The GLSL version 1.10 predefined shader language object.
			static const ShaderLanguage GLSL_110;
			
			/// The GLSL version 1.20 predefined shader language object.
			static const ShaderLanguage GLSL_120;
			
			/// The GLSL version 1.30 predefined shader language object.
			static const ShaderLanguage GLSL_130;
			
			/// The GLSL version 1.40 predefined shader language object.
			static const ShaderLanguage GLSL_140;
			
			/// The GLSL version 1.50 predefined shader language object.
			static const ShaderLanguage GLSL_150;
			
			/// The GLSL version 3.30 predefined shader language object.
			static const ShaderLanguage GLSL_330;
			
			/// The GLSL version 4.00 predefined shader language object.
			static const ShaderLanguage GLSL_400;
			
			/// The GLSL version 4.10 predefined shader language object.
			static const ShaderLanguage GLSL_410;
			
			/// The GLSL version 4.20 predefined shader language object.
			static const ShaderLanguage GLSL_420;
			
			/// The GLSL version 4.30 predefined shader language object.
			static const ShaderLanguage GLSL_430;
			
			/// The GLSL version 4.40 predefined shader language object.
			static const ShaderLanguage GLSL_440;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum for the shader language.
			Type type;
			
			
			
			
			/// An object which represents the version number for this shader language.
			ShaderLanguageVersion version;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_LANGUAGE_H
