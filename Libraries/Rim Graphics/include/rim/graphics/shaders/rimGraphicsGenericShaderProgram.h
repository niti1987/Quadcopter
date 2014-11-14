/*
 *  rimGraphicsGenericShaderProgram.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 3/1/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GENERIC_SHADER_PROGRAM_H
#define INCLUDE_RIM_GRAPHICS_GENERIC_SHADER_PROGRAM_H


#include "rimGraphicsShadersConfig.h"


#include "rimGraphicsShader.h"
#include "rimGraphicsShaderConfiguration.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a collection of shader source code objects.
class GenericShaderProgram
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new generic shader program with no shaders and undefined shader language.
			RIM_INLINE GenericShaderProgram()
				:	language( ShaderLanguage::UNDEFINED ),
					configuration()
			{
			}
			
			
			
			
			/// Create a new generic shader program with no shaders for the specified shader language.
			RIM_INLINE GenericShaderProgram( const ShaderLanguage& newLanguage )
				:	language( newLanguage ),
					configuration()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Language Accessor Methods
			
			
			
			
			/// Return an object describing the language in which this shader program source is written.
			RIM_INLINE const ShaderLanguage& getLanguage() const
			{
				return language;
			}
			
			
			
			
			/// Set an object describing the language in which this shader program source is written.
			RIM_INLINE void setLanguage( const ShaderLanguage& newLanguage )
			{
				language = newLanguage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Configuration Accessor Methods
			
			
			
			
			/// Return an object describing the configuration of this shader program source.
			/**
			  * If there are not configuration options for this shader program source,
			  * the method may return a NULL pointer.
			  */
			RIM_INLINE const Pointer<ShaderConfiguration>& getConfiguration() const
			{
				return configuration;
			}
			
			
			
			
			/// Set an object describing the configuration of this shader program source.
			RIM_INLINE void setConfiguration( const Pointer<ShaderConfiguration>& newConfiguration )
			{
				configuration = newConfiguration;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Accessor Methods
			
			
			
			
			/// Return the number of shaders that this generic shader program has.
			RIM_INLINE Size getShaderCount() const
			{
				return shaders.getSize();
			}
			
			
			
			
			/// Return a const reference to the shader source at the specified index in this generic shader program.
			RIM_INLINE const ShaderSource& getShader( Index sourceIndex ) const
			{
				return shaders[sourceIndex];
			}
			
			
			
			
			/// Replace the shader source at the specified index in this generic shader program.
			RIM_INLINE void setShader( Index sourceIndex, const ShaderSource& newShader )
			{
				shaders[sourceIndex] = newShader;
			}
			
			
			
			
			/// Add a new shader source to the end of this generic shader program's list of shaders.
			RIM_INLINE void addShader( const ShaderSource& newShader )
			{
				shaders.add( newShader );
			}
			
			
			
			
			/// Remove the shader source at the specified index in this generic shader program.
			/**
			  * This method maintains the order of the remaining shaders.
			  */
			RIM_INLINE void removeShader( Index sourceIndex )
			{
				shaders.removeAtIndex( sourceIndex );
			}
			
			
			
			
			/// Clear all shader sources from this generic shader program.
			RIM_INLINE void clearShaders()
			{
				shaders.clear();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object describing the language used for this shader program source.
			ShaderLanguage language;
			
			
			
			
			/// A list of source code objects for each shader that makes up this shader program.
			ArrayList<ShaderSource> shaders;
			
			
			
			
			/// An optionally-NULL pointer to the configuration parameters for this shader program source.
			Pointer<ShaderConfiguration> configuration;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GENERIC_SHADER_PROGRAM_H
