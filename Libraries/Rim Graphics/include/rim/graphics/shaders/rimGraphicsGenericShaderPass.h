/*
 *  rimGraphicsGenericShaderPass.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 1/30/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GENERIC_SHADER_PASS_H
#define INCLUDE_RIM_GRAPHICS_GENERIC_SHADER_PASS_H


#include "rimGraphicsShadersConfig.h"


#include "rimGraphicsShaderPassSource.h"
#include "rimGraphicsShaderPassUsage.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains a set of ShaderPassSource code implementations for different platforms.
class GenericShaderPass
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new generic shader pass that has no implementation sources.
			/**
			  * The shader pass has an empty name string and ShaderPassUsage::UNDEFINED usage.
			  */
			RIM_INLINE GenericShaderPass()
				:	name(),
					usage( ShaderPassUsage::UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new generic shader pass with the specified usage and no name.
			RIM_INLINE GenericShaderPass( const ShaderPassUsage& newUsage )
				:	name(),
					usage( newUsage )
			{
			}
			
			
			
			
			/// Create a new generic shader pass with the specified name and usage.
			RIM_INLINE GenericShaderPass( const ShaderPassUsage& newUsage, const String& newName )
				:	name( newName ),
					usage( newUsage )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return the name of this shader pass.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set the name of this generic shader pass.
			RIM_INLINE void setName( const String& newName )
			{
				name = newName;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Usage Accessor Methods
			
			
			
			
			/// Return an object which describes the semantic usage of this generic shader pass.
			RIM_INLINE const ShaderPassUsage& getUsage() const
			{
				return usage;
			}
			
			
			
			
			/// Set an object which describes the semantic usage of this generic shader pass.
			RIM_INLINE void setUsage( const ShaderPassUsage& newUsage )
			{
				usage = newUsage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Source Accessor Methods
			
			
			
			
			/// Return the number of sources that this generic shader pass has.
			RIM_INLINE Size getSourceCount() const
			{
				return sources.getSize();
			}
			
			
			
			
			/// Return a pointer to the source at the specified index in this generic shader pass.
			RIM_INLINE const Pointer<ShaderPassSource>& getSource( Index sourceIndex ) const
			{
				return sources[sourceIndex];
			}
			
			
			
			
			/// Return a pointer to the source of this generic shader pass that uses the specified shader language.
			/**
			  * If there is no shader pass source that uses the specified shader language,
			  * a NULL pointer is returned.
			  */
			Pointer<ShaderPassSource> getSourceWithLanguage( const ShaderLanguage& language ) const;
			
			
			
			
			/// Replace the source at the specified index in this generic shader pass.
			/**
			  * If the specified source is NULL, the method fails and returns FALSE.
			  * Otherwise, the source at that index is replaced and TRUE is returned.
			  */
			Bool setSource( Index sourceIndex, const Pointer<ShaderPassSource>& newSource );
			
			
			
			
			/// Add a new shader source to the end of this generic shader pass's list of sources.
			/**
			  * If the specified source is NULL, the method fails and returns FALSE.
			  * Otherwise, the new source is added and TRUE is returned.
			  */
			Bool addSource( const Pointer<ShaderPassSource>& newSource );
			
			
			
			
			/// Remove the source at the specified index in this generic shader pass.
			/**
			  * This method maintains the order of the remaining sources.
			  */
			void removeSource( Index sourceIndex );
			
			
			
			
			/// Clear all sources from this generic shader pass.
			void clearSources();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to a string representing the name of this generic shader pass.
			String name;
			
			
			
			
			/// An enum value representing the semantic usage of this generic shader pass.
			ShaderPassUsage usage;
			
			
			
			
			/// A list of the different sources for this generic shader pass.
			ArrayList< Pointer<ShaderPassSource> > sources;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GENERIC_SHADER_PASS_H
