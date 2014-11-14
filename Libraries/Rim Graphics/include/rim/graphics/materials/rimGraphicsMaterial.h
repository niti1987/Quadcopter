/*
 *  rimGraphicsMaterial.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 8/10/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_MATERIAL_H
#define INCLUDE_RIM_GRAPHICS_MATERIAL_H


#include "rimGraphicsMaterialsConfig.h"


#include "rimGraphicsMaterialTechnique.h"
#include "rimGraphicsMaterialTechniqueUsage.h"


//##########################################################################################
//**********************  Start Rim Graphics Materials Namespace  **************************
RIM_GRAPHICS_MATERIALS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains a set of techniques for drawing the visual appearance of an object.
/**
  * Each technique represents a particular way of drawing an object. A material is
  * a set of techniques, where each technique is associated with a usage type.
  * The usage allows the renderer to pick the correct technique to render
  * an object.
  */
class Material
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an empty default material with no material techniques.
			Material();
			
			
			
			
			/// Create a material which uses the specified technique.
			Material( const Pointer<MaterialTechnique>& newTechnique );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this material, releasing all resources.
			virtual ~Material();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Technique Accessor Methods
			
			
			
			
			/// Return the total number of material techniques that are part of this material.
			RIM_INLINE Size getTechniqueCount() const
			{
				return techniques.getSize();
			}
			
			
			
			
			/// Return a pointer to the material technique at the specified index in this material.
			RIM_INLINE const Pointer<MaterialTechnique>& getTechnique( Index index ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( index < techniques.getSize(),
										"Cannot access invalid technique index in material" );
				
				return techniques[index];
			}
			
			
			
			
			/// Return a pointer to the technique with the specified usage in this material.
			/**
			  * If this material does not contain a technique with that usage,
			  * a NULL pointer is returned.
			  */
			Pointer<MaterialTechnique> getTechniqueWithUsage( const MaterialTechniqueUsage& usage ) const;
			
			
			
			
			/// Return a pointer to the technique with the specified usage in this material.
			/**
			  * If this material does not contain a technique with that usage,
			  * a NULL pointer is returned.
			  */
			Bool hasTechniqueWithUsage( const MaterialTechniqueUsage& usage ) const;
			
			
			
			
			/// Add a new material technique to this material with the specified usage.
			/**
			  * If the technique pointer is NULL, the method fails and FALSE is returned.
			  * Otherwise, the technique is added and TRUE is returned.
			  */
			Bool addTechnique( const Pointer<MaterialTechnique>& newTechnique );
			
			
			
			
			/// Remove the technique with the specified index from this material.
			/**
			  * This causes all techniques stored after the given index to be moved one
			  * index back in this internal list of techniques. The method returns
			  * whether or not the remove operation was successful.
			  */
			Bool removeTechnique( Index index );
			
			
			
			
			/// Remove the technique with the specified usage from this material.
			/**
			  * The method returns whether or not the remove operation was successful.
			  */
			Bool removeTechniqueWithUsage( const MaterialTechniqueUsage& name );
			
			
			
			
			/// Remove all material techniques from this material.
			void clearTechniques();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the different material techniques that make up this material.
			ShortArrayList<Pointer<MaterialTechnique>,1> techniques;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Materials Namespace  ****************************
RIM_GRAPHICS_MATERIALS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_MATERIAL_H
