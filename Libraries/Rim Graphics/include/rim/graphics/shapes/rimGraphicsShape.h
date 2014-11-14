/*
 *  rimGraphicsShape.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHAPE_H
#define INCLUDE_RIM_GRAPHICS_SHAPE_H


#include "rimGraphicsShapesConfig.h"


#include "rimGraphicsShapeType.h"
#include "rimGraphicsMeshChunk.h"


//##########################################################################################
//***********************  Start Rim Graphics Shapes Namespace  ****************************
RIM_GRAPHICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents an abstract renderable object.
/**
  * A shape object contains whatever information is necessary to render
  * it to the screen. Every shape has a transformation which orients it relative
  * to its parent coordinate frame.
  */
class GraphicsShape : public Transformable
{
	public:
		
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
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return the name of the graphics shape.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set the name of the graphics shape.
			RIM_INLINE void setName( const String& newName )
			{
				name = newName;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mesh Chunk Accessor Method
			
			
			
			
			/// Process the shape into a flat list of mesh chunk objects.
			/**
			  * This method flattens the shape hierarchy and produces mesh chunks
			  * for rendering from the specified camera's perspective. The method
			  * should convert its internal representation into one or more MeshChunk
			  * objects which it should append to the specified output list of mesh chunks.
			  *
			  * The caller provides the concatenated local-to-world transformation for the
			  * shape's parent coordinate frame.
			  *
			  * The method should return whether or not the shape was successfully flattened
			  * into chunks.
			  */
			virtual Bool getChunks( const Transform3& worldTransform, const Camera& camera,
									const ViewVolume* viewVolume, const Vector2D<Size>& viewportSize,
									ArrayList<MeshChunk>& chunks ) const;
			
			
			
			 
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new shape with the specified type and default identity transformation.
			RIM_INLINE GraphicsShape( const ShapeType* newType )
				:	Transformable(),
					type( newType )
			{
				RIM_DEBUG_ASSERT_MESSAGE( type != NULL, "Cannot have NULL type for shape." );
			}
			
			
			
			
			/// Create a new shape with the specified type and transformation.
			RIM_INLINE GraphicsShape( const ShapeType* newType, const Transform3& newTransform )
				:	Transformable( newTransform ),
					type( newType )
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
			
			
			
			
			/// A name for this graphics shape.
			String name;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHAPE_H
