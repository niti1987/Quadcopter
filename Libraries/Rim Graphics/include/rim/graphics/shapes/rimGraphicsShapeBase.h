/*
 *  rimGraphicsShapeBase.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 2/27/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHAPE_BASE_H
#define INCLUDE_RIM_GRAPHICS_SHAPE_BASE_H


#include "rimGraphicsShapesConfig.h"


#include "rimGraphicsShape.h"


//##########################################################################################
//***********************  Start Rim Graphics Shapes Namespace  ****************************
RIM_GRAPHICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class from which all shape subclasses should derive that simplifies shape typing.
/**
  * This class simplifies Shape subclassing by automatically providing
  * ShapeType information to the parent Shape based on the
  * SubType template parameter.
  */
template < typename SubType >
class GraphicsShapeBase : public GraphicsShape
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a base shape object.
			RIM_FORCE_INLINE GraphicsShapeBase()
				:	GraphicsShape( &type )
			{
			}
			
			
			
			
			/// Create a base shape object with the specified 3D transformation.
			RIM_FORCE_INLINE GraphicsShapeBase( const Transform3& newTransform )
				:	GraphicsShape( &type, newTransform )
			{
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A ShapeType object representing the type of this base collision shape.
			/**
			  * The type object is created directly from the SubType template parameter.
			  */
			static const ShapeType type;
			
			
};




template < typename SubType >
const ShapeType GraphicsShapeBase<SubType>:: type = ShapeType::of<SubType>();




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHAPE_BASE_H
