/*
 *  rimGraphicsGenericBoxShape.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/22/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GENERIC_BOX_SHAPE_H
#define INCLUDE_RIM_GRAPHICS_GENERIC_BOX_SHAPE_H


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
/// A class which represents a generic box shape.
/**
  * A box is specified by its width, height, and depth, as well as the position
  * of its center and the 3 orthonormal axis that define its orientation.
  * It has an associated generic material for use in drawing.
  */
class GenericBoxShape : public GraphicsShapeBase<GenericBoxShape>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a box shape centered at the origin with a size of 1 along each axis.
			RIM_INLINE GenericBoxShape()
				:	size( 1, 1, 1 )
			{
			}
			
			
			
			
			/// Create a box shape centered at the origin with the specified width, height, and depth.
			RIM_INLINE GenericBoxShape( Real width, Real height, Real depth )
			{
				this->setSize( Vector3( width, height, depth ) );
			}
			
			
			
			
			/// Create a box shape centered at the given position with the specified width, height, and depth.
			RIM_INLINE GenericBoxShape( Real width, Real height, Real depth, const Vector3& newPosition )
			{
				this->setSize( Vector3( width, height, depth ) );
				this->setPosition( newPosition );
			}
			
			
			
			
			/// Create a box shape centered at the given position with the specified width, height, and depth, and orientation.
			RIM_INLINE GenericBoxShape( Real width, Real height, Real depth,
										const Vector3& newPosition, const Matrix3& newOrientation )
			{
				this->setSize( Vector3( width, height, depth ) );
				this->setPosition( newPosition );
				this->setOrientation( newOrientation );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Set the 3D dimensions of this box in its local coordinate frame.
			RIM_FORCE_INLINE const Vector3& getSize() const
			{
				return size;
			}
			
			
			
			
			/// Set the 3D dimensions of this box in its local coordinate frame.
			RIM_INLINE void setSize( const Vector3& newSize )
			{
				size.x = math::max( newSize.x, Real(0) );
				size.y = math::max( newSize.y, Real(0) );
				size.z = math::max( newSize.z, Real(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Width Accessor Methods
			
			
			
			
			/// Return the width (X size) of this box in its local coordinate frame.
			RIM_FORCE_INLINE Real getWidth() const
			{
				return size.x;
			}
			
			
			
			
			/// Set the width (X size) of this box in its local coordinate frame.
			/**
			  * This width value is clamped to the range of [0,+infinity].
			  */
			RIM_INLINE void setWidth( Real newWidth )
			{
				size.x = math::max( newWidth, Real(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Height Accessor Methods
			
			
			
			
			/// Return the height (Y size) of this box in its local coordinate frame.
			RIM_FORCE_INLINE Real getHeight() const
			{
				return size.y;
			}
			
			
			
			
			/// Set the height (Y size) of this box in its local coordinate frame.
			/**
			  * This height value is clamped to the range of [0,+infinity].
			  */
			RIM_INLINE void setHeight( Real newHeight )
			{
				size.y = math::max( newHeight, Real(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Depth Accessor Methods
			
			
			
			
			/// Return the depth (Z size) of this box in its local coordinate frame.
			RIM_FORCE_INLINE Real getDepth() const
			{
				return size.z;
			}
			
			
			
			
			/// Set the depth (Z size) of this box in its local coordinate frame.
			/**
			  * This depth value is clamped to the range of [0,+infinity].
			  */
			RIM_INLINE void setDepth( Real newDepth )
			{
				size.z = math::max( newDepth, Real(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Material Accessor Methods
			
			
			
			
			/// Get the material of this generic box shape.
			RIM_INLINE Pointer<GenericMaterial>& getMaterial()
			{
				return material;
			}
			
			
			
			
			/// Get the material of this generic box shape.
			RIM_INLINE const Pointer<GenericMaterial>& getMaterial() const
			{
				return material;
			}
			
			
			
			
			/// Set the material of this generic box shape.
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
				Vector3 halfSize = size*Real(0.5);
				
				setLocalBoundingBox( AABB3( -halfSize, halfSize ) );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The size of this box along each local coordinate axis.
			Vector3 size;
			
			
			
			
			/// A pointer to the material to use when rendering this generic box shape.
			Pointer<GenericMaterial> material;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GENERIC_BOX_SHAPE_H
