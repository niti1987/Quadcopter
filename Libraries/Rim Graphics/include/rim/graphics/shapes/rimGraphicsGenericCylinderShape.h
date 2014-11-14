/*
 *  rimGraphicsGenericCylinderShape.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/22/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GENERIC_CYLINDER_SHAPE_H
#define INCLUDE_RIM_GRAPHICS_GENERIC_CYLINDER_SHAPE_H


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
/// A class which represents a generic cylinder shape.
/**
  * A cylinder can have different radii that cause it to instead be a
  * truncated cone.
  * It has an associated generic material for use in drawing.
  */
class GenericCylinderShape : public GraphicsShapeBase<GenericCylinderShape>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a cylinder shape centered at the origin with a radius and height of 1.
			GenericCylinderShape();
			
			
			
			
			/// Create a cylinder shape with the specified endpoints and radius.
			GenericCylinderShape( const Vector3& newEndpoint1, const Vector3& newEndpoint2,
									Real newRadius );
			
			
			
			
			/// Create a cylinder shape with the specified endpoints and radii.
			GenericCylinderShape( const Vector3& newEndpoint1, const Vector3& newEndpoint2,
									Real newRadius1, Real newRadius2 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Endpoint Accessor Methods
			
			
			
			
			/// Return a const reference to the center of this cylinder shape's first endcap in local coordinates.
			RIM_FORCE_INLINE const Vector3& getEndpoint1() const
			{
				return endpoint1;
			}
			
			
			
			
			/// Set the center of this cylinder shape's first endcap in local coordinates.
			void setEndpoint1( const Vector3& newEndpoint1 );
			
			
			
			
			/// Return a const reference to the center of this cylinder shape's second endcap in local coordinates.
			RIM_FORCE_INLINE const Vector3& getEndpoint2() const
			{
				return endpoint2;
			}
			
			
			
			
			/// Set the center of this cylinder shape's second endcap in local coordinates.
			void setEndpoint2( const Vector3& newEndpoint2 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Axis Accessor Methods
			
			
			
			
			/// Return a normalized axis vector for this cylinder, directed from endpoint 1 to endpoint 2.
			RIM_FORCE_INLINE const Vector3& getAxis() const
			{
				return axis;
			}
			
			
			
			
			/// Set a normalized axis vector for this cylinder, directed from endpoint 1 to endpoint 2.
			/**
			  * Setting this cylinder's axis keeps the cylinder's first endpoint stationary in shape
			  * space and moves the second endpoint based on the new axis and cylinder's height.
			  */
			void setAxis( const Vector3& newAxis );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Height Accessor Methods
			
			
			
			
			/// Get the distance between the endpoints of this cylinder shape in local coordinates.
			RIM_FORCE_INLINE Real getHeight() const
			{
				return height;
			}
			
			
			
			
			/// Set the distance between the endpoints of this cylinder shape in local coordinates.
			/**
			  * The value is clamed to the range of [0,+infinity). Setting this height value
			  * causes the cylilnder's second endpoint to be repositioned, keeping the first
			  * endpoint stationary, based on the cylinder's current axis vector.
			  */
			void setHeight( Real newHeight );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Radius Accessor Methods
			
			
			
			
			/// Get the first endcap radius of this cylinder shape in local coordinates.
			RIM_FORCE_INLINE Real getRadius1() const
			{
				return radius1;
			}
			
			
			
			
			/// Set the first endcap radius of this cylinder shape in local coordinates.
			/**
			  * The radius is clamed to the range of [0,+infinity).
			  */
			void setRadius1( Real newRadius1 );
			
			
			
			
			/// Get the second endcap radius of this cylinder shape in local coordinates.
			RIM_FORCE_INLINE Real getRadius2() const
			{
				return radius2;
			}
			
			
			
			
			/// Set the second endcap radius of this cylinder shape in local coordinates.
			/**
			  * The radius is clamed to the range of [0,+infinity).
			  */
			void setRadius2( Real newRadius2 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Material Accessor Methods
			
			
			
			
			/// Get the material of this generic cylinder shape.
			RIM_INLINE Pointer<GenericMaterial>& getMaterial()
			{
				return material;
			}
			
			
			
			
			/// Get the material of this generic cylinder shape.
			RIM_INLINE const Pointer<GenericMaterial>& getMaterial() const
			{
				return material;
			}
			
			
			
			
			/// Set the material of this generic cylinder shape.
			RIM_INLINE void setMaterial( const Pointer<GenericMaterial>& newMaterial )
			{
				material = newMaterial;
			}
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Cylinder Update Method
			
			
			
			
			/// Update the shape's bounding cylinder based on its current geometric representation.
			virtual void updateBoundingBox();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Return the point on this cylinder that is farthest in the specified direction.
			Vector3 getSupportPoint( const Vector3& direction ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The center of the first circular cap of this cylinder in shape coordinates.
			Vector3 endpoint1;
			
			
			
			
			/// The center of the second circular cap of this cylinder in shape coordiantes.
			Vector3 endpoint2;
			
			
			
			
			/// The normalized axis vector for this cylinder in shape coordinates.
			Vector3 axis;
			
			
			
			
			/// The radius of the first endcap of this sphere in shape coordinates.
			Real radius1;
			
			
			
			
			/// The radius of the second endcap of this sphere in shape coordinates.
			Real radius2;
			
			
			
			
			/// The distance from one endpoint to another.
			Real height;
			
			
			
			
			/// A pointer to the material to use when rendering this generic cylinder shape.
			Pointer<GenericMaterial> material;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GENERIC_CYLINDER_SHAPE_H
