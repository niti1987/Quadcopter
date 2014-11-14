/*
 *  rimGraphicsMaterialTechniqueUsage.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 1/11/11.
 *  Copyright 2011 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_MATERIAL_TECHNIQUE_USAGE_H
#define INCLUDE_RIM_GRAPHICS_MATERIAL_TECHNIQUE_USAGE_H


#include "rimGraphicsMaterialsConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Materials Namespace  **************************
RIM_GRAPHICS_MATERIALS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the semantic usage for a MaterialTechnique.
/**
  * This enum class contains various values which describe different common
  * types of rendering techniques. These can include standard forward rendering,
  * deferred rendering, or shadow map rendering. This allows a MaterialTechnique
  * to be labeled with a particular semantic usage so that the renderer can decide
  * at render-time which is the correct technique for rendering an object.
  */
class MaterialTechniqueUsage
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Material Technique Usage Enum Definition
			
			
			
			
			/// An enum value which indicates the type of technique usage.
			typedef enum Enum
			{
				/// This usage specifies the technique to use when no other is available.
				DEFAULT = 1,
				
				/// This usage specifies a technique used for traditional forward rendering.
				FORWARD_RENDERING = 1 << 1,
				
				/// This usage specifies a technique used to fill the GBuffer during deferred rendering.
				DEFERRED_GBUFFER_RENDERING = 1 << 2,
				
				/// This usage specifies a technique used for shadow map rendering.
				SHADOW_MAP_RENDERING = 1 << 3,
				
				/// This usage specifies a technique for an undefined usage.
				UNDEFINED = 0
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new undefined material technique usage.
			RIM_INLINE MaterialTechniqueUsage()
				:	usage( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new material technique usage with the specified material technique usage enum value.
			RIM_INLINE MaterialTechniqueUsage( Enum newUsage )
				:	usage( newUsage )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this material technique usage to an enum value.
			RIM_INLINE operator Enum () const
			{
				return usage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a unique string for this technique usage that matches its enum value name.
			String toEnumString() const;
			
			
			
			
			/// Return a technique usage which corresponds to the given enum string.
			static MaterialTechniqueUsage fromEnumString( const String& enumString );
			
			
			
			
			/// Return a string representation of the material technique usage.
			String toString() const;
			
			
			
			
			/// Convert this material technique usage into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum for the material technique usage.
			Enum usage;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Materials Namespace  ****************************
RIM_GRAPHICS_MATERIALS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_MATERIAL_TECHNIQUE_USAGE_H
