/*
 *  rimGraphicsShaderPassLibrary.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 1/30/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_PASS_LIBRARY_H
#define INCLUDE_RIM_GRAPHICS_SHADER_PASS_LIBRARY_H


#include "rimGraphicsShadersConfig.h"


#include "rimGraphicsGenericShaderPass.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A library which contains GenericShaderPass objects for different ShaderUsage types.
class ShaderPassLibrary
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new shader pass library that contains no shader passes.
			ShaderPassLibrary();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this shader pass library, releasing all associated resources.
			virtual ~ShaderPassLibrary();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Pass Accessor Methods
			
			
			
			
			/// Return the number of generic shader passes that this shader pass library has.
			RIM_INLINE Size getPassCount() const
			{
				return passes.getSize();
			}
			
			
			
			
			/// Return a pointer to the generic shader pass at the specified index in this shader pass library.
			RIM_INLINE const Pointer<GenericShaderPass>& getPass( Index passIndex ) const
			{
				return passes[passIndex];
			}
			
			
			
			
			/// Return a pointer to a generic shader pass in this shader pass library with the specified usage.
			/**
			  * If there is no generic shader pass with that usage, a NULL pointer is returned.
			  */
			Pointer<GenericShaderPass> getPassWithUsage( const ShaderPassUsage& usage ) const;
			
			
			
			
			/// Return a pointer to a generic shader pass in this shader pass library with the specified usage and shader language.
			/**
			  * If there is no generic shader pass with that usage and shader language, a NULL pointer is returned.
			  */
			Pointer<ShaderPassSource> getPassWithUsageAndLanguage( const ShaderPassUsage& usage,
																	const ShaderLanguage& language ) const;
			
			
			
			
			/// Add a new generic shader pass to the end of this shader pass library's list of passes.
			/**
			  * If the specified generic shader pass is NULL, the method fails and returns FALSE.
			  * Otherwise, the new pass is added and TRUE is returned.
			  */
			RIM_INLINE Bool addPass( const Pointer<GenericShaderPass>& newPass )
			{
				if ( newPass.isNull() )
					return false;
				
				passes.add( newPass );
				
				return true;
			}
			
			
			
			
			/// Remove the generic shader pass at the specified index in this shader pass library.
			/**
			  * This method maintains the order of the remaining shader passes.
			  */
			RIM_INLINE void removePass( Index passIndex )
			{
				passes.removeAtIndex( passIndex );
			}
			
			
			
			
			/// Clear all generic shader passes from this shader pass library.
			RIM_INLINE void clearPasses()
			{
				passes.clear();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the different shader classes for this shader library.
			ArrayList< Pointer<GenericShaderPass> > passes;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_PASS_LIBRARY_H
