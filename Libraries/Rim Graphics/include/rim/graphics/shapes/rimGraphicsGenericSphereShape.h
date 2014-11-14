/*
 *  rimGraphicsGenericSphereShape.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/2/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GENERIC_SPHERE_SHAPE_H
#define INCLUDE_RIM_GRAPHICS_GENERIC_SPHERE_SHAPE_H


#include "rimGraphicsShapesConfig.h"


#include "rimGraphicsShapeBase.h"


//##########################################################################################
//***********************  Start Rim Graphics Shapes Namespace  ****************************
RIM_GRAPHICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a generic sphere shape.
/**
  * A sphere is specified by a position and radius, and has an associated
  * material for use in drawing.
  */
class GenericSphereShape : public GraphicsShapeBase<GenericSphereShape>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a sphere shape for the given graphics context centered at the origin with a radius of 1.
			RIM_INLINE GenericSphereShape()
				:	radius( 1 )
			{
			}
			
			
			
			
			/// Create a sphere shape for the given graphics context centered at the origin with the specified radius.
			RIM_INLINE GenericSphereShape( Real newRadius )
				:	radius( math::max( newRadius, Real(0) ) )
			{
			}
			
			
			
			
			/// Create a sphere shape for the given graphics context with the specified position and radius.
			RIM_INLINE GenericSphereShape( const Vector3& newPosition, Real newRadius )
				:	radius( math::max( newRadius, Real(0) ) )
			{
				this->setPosition( newPosition );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Radius Accessor Methods
			
			
			
			
			/// Get the radius of this sphere shape in local coordinates.
			RIM_INLINE Real getRadius() const
			{
				return radius;
			}
			
			
			
			
			/// Set the radius of this sphere shape in local coordinates.
			/**
			  * The radius is clamed to the range of [0,+infinity).
			  */
			RIM_INLINE void setRadius( Real newRadius )
			{
				radius = math::max( newRadius, Real(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Material Accessor Methods
			
			
			
			
			/// Get the material of this generic sphere shape.
			RIM_INLINE Pointer<GenericMaterial>& getMaterial()
			{
				return material;
			}
			
			
			
			
			/// Get the material of this generic sphere shape.
			RIM_INLINE const Pointer<GenericMaterial>& getMaterial() const
			{
				return material;
			}
			
			
			
			
			/// Set the material of this generic sphere shape.
			RIM_INLINE void setMaterial( const Pointer<GenericMaterial>& newMaterial )
			{
				material = newMaterial;
			}
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Box Update Method
			
			
			
			
			/// Update the shape's bounding box based on its current geometric representation.
			virtual void updateBoundingBox()
			{
				setLocalBoundingBox( AABB3( Vector3(-radius), Vector3(radius) ) );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The radius of this sphere in shape-coordinates.
			Real radius;
			
			
			
			
			/// A pointer to the material to use when rendering this generic sphere shape.
			Pointer<GenericMaterial> material;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GENERIC_SPHERE_SHAPE_H
