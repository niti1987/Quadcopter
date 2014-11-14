/*
 *  rimGraphicsIndexedPrimitiveType.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 12/27/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_INDEXED_PRIMITIVE_TYPE_H
#define INCLUDE_RIM_GRAPHICS_INDEXED_PRIMITIVE_TYPE_H


#include "rimGraphicsBuffersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Buffers Namespace  ***************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which is used to specify a type of indexed primitive.
/**
  * This class is used to tell the GPU what kind of primitives are represented
  * by an index buffer. For instance, one could specify a list of indexed points,
  * lines, triangles, or quads.
  */
class IndexedPrimitiveType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Indexed Primitive Type Enum Definition
			
			
			
			
			/// An enum representing the type of indexed primitive.
			typedef enum Enum
			{
				/// An undefined indexed primitive type.
				UNDEFINED = 0,
				
				
				/// An indexed primitive type where every index represents a point to draw.
				POINTS = 1,
				
				
				/// An indexed primitive type where every 2 indices represent a line segment to draw.
				LINES = 2,
				
				
				/// An indexed primitive type where all of the indices in a buffer represent a set of connected line segments to draw.
				/**
				  * The first index indicates the starting vertex and each additional index indicates
				  * the next vertex in a connected set of line segments.
				  */
				LINE_STRIP = 3,
				
				
				/// An indexed primitive type where all of the indices in a buffer represent a set of connected line segments to draw.
				/**
				  * The first index indicates the starting vertex and each additional index indicates
				  * the next vertex in a connected set of line segments. At the end of the list,
				  * a line is drawn between the first and last vertex, creating a closed loop.
				  */
				LINE_LOOP = 4,
				
				
				/// An indexed primitive type where every 3 indices represent a triangle to draw.
				TRIANGLES = 5,
				
				
				/// An indexed primitive type where all of the indices in a buffer represent a set of connected triangles to draw.
				/**
				  * The first index indicates the starting vertex, the next vertex indicates the end of the first
				  * side of the first triangle, and the third vertex completes the first triangle.
				  * Each additional index after that creates a triangle with the last two vertices specified.
				  */
				TRIANGLE_STRIP = 6,
				
				
				/// An indexed primitive type where all of the indices in a buffer represent a set of connected triangles to draw.
				/**
				  * The first index indicates the starting vertex, the next vertex indicates the end of the first
				  * side of the first triangle, and the third vertex completes the first triangle.
				  * Each additional index after that creates a triangle with the first vertex and
				  * the last vertex, resulting in a so-called 'fan' of triangles.
				  */
				TRIANGLE_FAN = 7,
				
				
				/// An indexed primitive type where every 3 indices represent a quad to draw.
				QUADS = 8,
				
				
				/// An indexed primitive type where all of the indices in a buffer represent a set of connected quads to draw.
				/**
				  * The first index indicates the starting vertex, the next vertex indicates the end of the first
				  * side of the first quad, and the third and fourth vertices completes the first quad.
				  * Each additional 2 indices after that creates a quad with the last two vertices specified.
				  */
				QUAD_STRIP = 9,
				
				
				/// A polygon with 3 or more vertices.
				/**
				  * For an index buffer with this type, all of the indices in the buffer define the edge
				  * of the polygon.
				  *
				  * This primitive type may not be supported on all hardware but is provided for completeness.
				  */
				POLYGON = 10
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default indexed primitive type with the UNDEFINED primitive type enum value.
			RIM_INLINE IndexedPrimitiveType()
				:	type( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new indexed primitive type with the specified indexed primitive type enum value.
			RIM_INLINE IndexedPrimitiveType( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
			/// Create a new indexed primitive type for the specified vertex count.
			/**
			  * The constructor guesses the primitive type from the given vertex count.
			  */
			RIM_INLINE IndexedPrimitiveType( Size vertexCount )
			{
				switch ( vertexCount )
				{
					case 1:		type = POINTS;		break;
					case 2:		type = LINES;		break;
					case 3:		type = TRIANGLES;	break;
					case 4:		type = QUADS;		break;
					default:	type = UNDEFINED;	break;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this indexed primitive type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return (Enum)type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Type Width Accessor Methods
			
			
			
			
			/// Return the minimum number of vertices needed to define an instance of this primitive type.
			Size getMinimumVertexCount() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a unique string for this indexed primitive type that matches its enum value name.
			String toEnumString() const;
			
			
			
			
			/// Return a indexed primitive type which corresponds to the given enum string.
			static IndexedPrimitiveType fromEnumString( const String& enumString );
			
			
			
			
			/// Return a string representation of the indexed primitive type.
			String toString() const;
			
			
			
			
			/// Convert this indexed primitive type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum for the indexed primitive type.
			UByte type;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Buffers Namespace  *****************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_INDEXED_PRIMITIVE_TYPE_H
