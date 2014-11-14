/*
 *  rimGraphicsShaderTechnique.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 1/6/11.
 *  Copyright 2011 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_MATERIAL_TECHNIQUE_H
#define INCLUDE_RIM_GRAPHICS_MATERIAL_TECHNIQUE_H


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
class MaterialTechnique
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new empty material technique with no shader passes.
			MaterialTechnique();
			
			
			
			
			/// Create a new empty material technique with the specified usage type.
			MaterialTechnique( const MaterialTechniqueUsage& newUsage );
			
			
			
			
			/// Create a new material technique with the specified usage type and first shader pass.
			MaterialTechnique( const MaterialTechniqueUsage& newUsage, const Pointer<ShaderPass>& newPass );
			
			
			
			
			/// Create a new material technique with undefined usage and the specified shader pass pass.
			MaterialTechnique( const Pointer<ShaderPass>& newPass );
			
			
			
			
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
			
			
			
			
			/// Return the number of shader passes that are part of this material technique.
			RIM_INLINE Size getPassCount() const
			{
				return passes.getSize();
			}
			
			
			
			
			/// Return a pointer to the shader pass at the specified index in this material technique.
			RIM_INLINE const Pointer<ShaderPass>& getPass( Index index ) const
			{
				return passes.get( index );
			}
			
			
			
			
			/// Add the specified shader pass to the end of this material technique's list of passes.
			/**
			  * If the pointer to the pass is NULL, the method fails and FALSE is returned.
			  * Otherise, the shader pass is added and TRUE is returned.
			  */
			Bool addPass( const Pointer<ShaderPass>& newPass );
			
			
			
			
			/// Insert the specified shader pass at the given position in this material technique's list of passes.
			/**
			  * If the pointer to the pass is NULL, the method fails and FALSE is returned.
			  * Otherise, the shader pass is inserted and TRUE is returned.
			  */
			Bool insertPass( Index index, const Pointer<ShaderPass>& newPass );
			
			
			
			
			/// Replace the shader pass at the specified index in this material technique.
			/**
			  * If the pointer to the pass is NULL, the method fails and FALSE is returned.
			  * Otherise, the shader pass is replaced and TRUE is returned.
			  */
			Bool setPass( Index index, const Pointer<ShaderPass>& newPass );
			
			
			
			
			/// Remove the shader pass at the specified index in this material technique.
			/**
			  * This method shifts all shader passes after the removed one back one index
			  * in the shader pass list.
			  */
			void removePass( Index index );
			
			
			
			
			/// Remove all shader passes from this material technique.
			void clearPasses();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transparency Accessor Methods
			
			
			
			
			/// Return whether or not this material technique produces transparent pixels.
			Bool getIsTransparent() const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the shader passes that make up this material technique, in order of their execution.
			ShortArrayList<Pointer<ShaderPass>,2> passes;
			
			
			
			
			/// An enum value indicating the semantic usage of this material technique.
			MaterialTechniqueUsage usage;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Materials Namespace  ****************************
RIM_GRAPHICS_MATERIALS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_MATERIAL_TECHNIQUE_H
