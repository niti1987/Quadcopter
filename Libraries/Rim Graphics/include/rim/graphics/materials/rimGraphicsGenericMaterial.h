/*
 *  rimGraphicsGenericMaterial.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 9/24/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GENERIC_MATERIAL_H
#define INCLUDE_RIM_GRAPHICS_GENERIC_MATERIAL_H


#include "rimGraphicsMaterialsConfig.h"


#include "rimGraphicsGenericMaterialTechnique.h"


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
class GenericMaterial
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an empty default material with no material techniques.
			GenericMaterial();
			
			
			
			
			/// Create an empty default material with no material techniques and the given name.
			GenericMaterial( const String& newName );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return the name of the material.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set the name of the material.
			RIM_INLINE void setName( const String& newName )
			{
				name = newName;
			}
			
			
			
			
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
			/**
			  * If the specified technique index is invalid, a NULL pointer is returned.
			  */
			RIM_INLINE Pointer<GenericMaterialTechnique> getTechnique( Index index ) const
			{
				if ( index < techniques.getSize() )
					return techniques[index];
				else
					return Pointer<GenericMaterialTechnique>();
			}
			
			
			
			
			/// Return a pointer to the technique with the specified name in this material.
			/**
			  * If this material does not contain a technique with that name,
			  * a NULL pointer is returned.
			  */
			Pointer<GenericMaterialTechnique> getTechnique( const String& name ) const;
			
			
			
			
			/// Return a pointer to the technique with the specified usage in this material.
			/**
			  * If this material does not contain a technique with that usage,
			  * a NULL pointer is returned.
			  */
			Pointer<GenericMaterialTechnique> getTechniqueWithUsage( const MaterialTechniqueUsage& usage ) const;
			
			
			
			
			/// Return a pointer to the technique with the specified name in this material.
			/**
			  * If this material does not contain a technique with that name,
			  * a NULL pointer is returned.
			  */
			Bool hasTechnique( const String& name ) const;
			
			
			
			
			/// Return a pointer to the technique with the specified usage in this material.
			/**
			  * If this material does not contain a technique with that usage,
			  * a NULL pointer is returned.
			  */
			Bool hasTechniqueWithUsage( const MaterialTechniqueUsage& usage ) const;
			
			
			
			
			/// Add a new material technique to this material with the specified usage.
			/**
			  * If the technique pointer is NULL, the method fails and FALSE is returned.
			  * Otherwise, the technique is added with the given attributes and TRUE is returned.
			  */
			Bool addTechnique( const Pointer<GenericMaterialTechnique>& newTechnique );
			
			
			
			
			/// Remove the technique with the specified index from this material.
			/**
			  * This causes all techniques stored after the given index to be moved one
			  * index back in this internal list of techniques. The method returns
			  * whether or not the remove operation was successful.
			  */
			Bool removeTechnique( Index index );
			
			
			
			
			/// Remove the technique with the specified name from this material.
			/**
			  * The method returns whether or not the remove operation was successful.
			  */
			Bool removeTechnique( const String& name );
			
			
			
			
			/// Remove the technique with the specified usage from this material.
			/**
			  * The method returns whether or not the remove operation was successful.
			  */
			Bool removeTechniqueWithUsage( const MaterialTechniqueUsage& usage );
			
			
			
			
			/// Remove all material techniques from this material.
			void clearTechniques();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the different techniques that can be used when rendering this material.
			ArrayList< Pointer<GenericMaterialTechnique> > techniques;
			
			
			
			
			/// A pointer to a string representing the name of this material.
			String name;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Materials Namespace  ****************************
RIM_GRAPHICS_MATERIALS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GENERIC_MATERIAL_H
