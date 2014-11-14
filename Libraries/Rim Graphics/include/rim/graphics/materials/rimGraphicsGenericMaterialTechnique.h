/*
 *  rimGraphicsGenericMaterialTechnique.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 9/25/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GENERIC_MATERIAL_TECHNIQUE_H
#define INCLUDE_RIM_GRAPHICS_GENERIC_MATERIAL_TECHNIQUE_H


#include "rimGraphicsMaterialsConfig.h"


#include "rimGraphicsMaterialTechniqueUsage.h"


//##########################################################################################
//**********************  Start Rim Graphics Materials Namespace  **************************
RIM_GRAPHICS_MATERIALS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a kind of visual effect that uses an ordered series of shader passes.
/**
  * A material technique contains an ordered list of shader passes which indicate
  * the different passes that are part of rendering a particular visual effect.
  * These passes are performed in series during rendering in the order stored in the
  * technique.
  *
  * A material technique may be simply a different visual style (shiny or not shiny)
  * or a totally different rendering technique (standard versus shadow map rendering).
  */
class GenericMaterialTechnique
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new generic material technique with no shader passes.
			GenericMaterialTechnique();
			
			
			
			
			/// Create a new generic material technique with no shader passes and the specified usage.
			GenericMaterialTechnique( const MaterialTechniqueUsage& newUsgae );
			
			
			
			
			/// Create a new generic material technique with no shader passes and the specified usage and name.
			GenericMaterialTechnique( const MaterialTechniqueUsage& newUsgae, const String& newName );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return the name of the material technique.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set the name of the material technique.
			RIM_INLINE void setName( const String& newName )
			{
				name = newName;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Usage Accessor Methods
			
			
			
			
			/// Return an enum value indicating the semantic usage of this material technique.
			RIM_INLINE const MaterialTechniqueUsage& getUsage() const
			{
				return usage;
			}
			
			
			
			
			/// Set an enum value indicating the semantic usage of this material technique.
			RIM_INLINE void setUsage( const MaterialTechniqueUsage& newUsage )
			{
				usage = newUsage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shader Pass Accessor Methods
			
			
			
			
			/// Return the number of shader passes that are part of this generic material technique.
			RIM_INLINE Size getPassCount() const
			{
				return passes.getSize();
			}
			
			
			
			
			/// Return a pointer to the shader pass at the specified index in this generic material technique.
			RIM_INLINE const Pointer<GenericShaderPass>& getPass( Index index ) const
			{
				return passes.get( index );
			}
			
			
			
			
			/// Add the specified shader pass to the end of this generic material technique's list of passes.
			/**
			  * If the pointer to the pass is NULL, the method fails and FALSE is returned.
			  * Otherise, the shader pass is added and TRUE is returned.
			  */
			Bool addPass( const Pointer<GenericShaderPass>& newPass );
			
			
			
			
			/// Insert the specified shader pass at the given position in this generic material technique's list of passes.
			/**
			  * If the pointer to the pass is NULL, the method fails and FALSE is returned.
			  * Otherise, the shader pass is inserted and TRUE is returned.
			  */
			Bool insertPass( Index index, const Pointer<GenericShaderPass>& newPass );
			
			
			
			
			/// Replace the shader pass at the specified index in this generic material technique.
			/**
			  * If the pointer to the pass is NULL, the method fails and FALSE is returned.
			  * Otherise, the shader pass is replaced and TRUE is returned.
			  */
			Bool setPass( Index index, const Pointer<GenericShaderPass>& newPass );
			
			
			
			
			/// Remove the shader pass at the specified index in this generic material technique.
			/**
			  * This method shifts all shader passes after the removed one back one index
			  * in the shader pass list.
			  */
			void removePass( Index index );
			
			
			
			
			/// Remove all shader passes from this generic material technique.
			void clearPasses();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the different shader passes that are used when rendering this technique.
			ArrayList< Pointer<GenericShaderPass> > passes;
			
			
			
			
			/// An enum value indicating the semantic usage of this material technique.
			MaterialTechniqueUsage usage;
			
			
			
			
			/// A pointer to a string representing the name of this material technique.
			String name;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Materials Namespace  ****************************
RIM_GRAPHICS_MATERIALS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GENERIC_MATERIAL_TECHNIQUE_H
