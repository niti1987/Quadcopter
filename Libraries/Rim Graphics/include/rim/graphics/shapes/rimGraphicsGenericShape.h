/*
 *  rimGraphicsGenericShape.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/2/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GENERIC_SHAPE_H
#define INCLUDE_RIM_GRAPHICS_GENERIC_SHAPE_H


#include "rimGraphicsShapesConfig.h"


#include "rimGraphicsShapeType.h"


//##########################################################################################
//***********************  Start Rim Graphics Shapes Namespace  ****************************
RIM_GRAPHICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents an abstract type of drawable shape.
class GenericShape
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this shape object.
			virtual ~GenericShape()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return a the name of this shape.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set the name of this shape.
			RIM_INLINE void setName( const String& newName )
			{
				name = newName;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Position Accessor Methods
			
			
			
			
			/// Return a reference to the position for this shape relative to its parent coordinate system.
			RIM_INLINE const Vector3& getPosition() const
			{
				return transformation.position;
			}
			
			
			
			
			/// Set the position for this mesh relative to its parent coordinate system.
			RIM_INLINE void setPosition( const Vector3& newPosition )
			{
				transformation.position = newPosition;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Orientation Accessor Methods
			
			
			
			
			/// Get the orientation of this shape.
			RIM_INLINE const Matrix3& getOrientation() const
			{
				return transformation.orientation;
			}
			
			
			
			
			/// Set the orientation of this shape.
			RIM_NO_INLINE void setOrientation( const Matrix3& newOrientation )
			{
				transformation.orientation = newOrientation.orthonormalize();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Scale Accessor Methods
			
			
			
			
			/// Get the scale of the shape.
			RIM_INLINE Float getScale() const
			{
				return transformation.scale;
			}
			
			
			
			
			/// Set the scale of the shape.
			RIM_INLINE void setScale( Float newScale )
			{
				transformation.scale = newScale;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transformation Accessor Methods
			
			
			
			
			/// Get the transformation of this shape relative to the origin in its coordinate space.
			RIM_INLINE const Transformation3& getTransformation() const
			{
				return transformation;
			}
			
			
			
			
			/// Set the transformation of this shape relative to the origin in its coordinate space.
			RIM_INLINE void setTransformation( const Transformation3& newTransformation )
			{
				transformation.position = newTransformation.position;
				transformation.orientation = newTransformation.orientation.orthonormalize();
				transformation.scale = newTransformation.scale;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Sphere Accessor Method
			
			
			
			
			/// Return a bounding sphere that encompases this entire shape in its coordinate space.
			virtual BoundingSphere getBoundingSphere() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shape Type Accessor Methods
			
			
			
			
			/// Return an integer identifying the sub type of this shape.
			RIM_FORCE_INLINE ShapeTypeID getTypeID() const
			{
				return type->getID();
			}
			
			
			
			
			/// Return a reference to an object representing the type of this Shape.
			RIM_FORCE_INLINE const ShapeType& getType() const
			{
				return *type;
			}
			
			
			
			 
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new shape with the specified type and default identity transformation.
			RIM_INLINE GenericShape( const ShapeType* newType )
				:	transformation(),
					type( newType ),
					name()
			{
				RIM_DEBUG_ASSERT_MESSAGE( type != NULL, "Cannot have NULL type for shape." );
			}
			
			
			
			
			/// Create a new shape with the specified type and transformation.
			RIM_INLINE GenericShape( const ShapeType* newType, const Transformation3f& newTransformation )
				:	transformation( newTransformation ),
					type( newType ),
					name()
			{
				RIM_DEBUG_ASSERT_MESSAGE( type != NULL, "Cannot have NULL type for shape." );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to an object which represents the type of this shape.
			const ShapeType* type;
			
			
			
			
			/// The rigid transformation for this shape relative to its parent coordinate system.
			Transformation3 transformation;
			
			
			
			
			/// A string containing a name for this mesh.
			String name;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GENERIC_SHAPE_H
