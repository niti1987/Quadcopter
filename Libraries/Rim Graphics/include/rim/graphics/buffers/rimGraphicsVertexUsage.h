/*
 *  rimGraphicsVertexUsage.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/27/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_VERTEX_USAGE_H
#define INCLUDE_RIM_GRAPHICS_VERTEX_USAGE_H


#include "rimGraphicsBuffersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Buffers Namespace  ***************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies how a vertex attribute is semantically used for rendering.
/**
  * Each instance allows the user to specify an enum value indicating the
  * type of usage and also an integral index for that usage. For example,
  * this allows the user to specify multiple texture coordinate usages.
  */
class VertexUsage
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Usage Enum Definition
			
			
			
			
			/// An enum type which represents a type of vertex attribute usage.
			typedef enum Enum
			{
				/// An undefined vertex attribute usage.
				UNDEFINED = 0,
				
				/// A usage where the attribute is used to specify a vertex's position.
				POSITION = 1,
				
				/// A usage where the attribute is used to specify a vertex's normal vector.
				NORMAL = 2,
				
				/// A usage where the attribute is used to specify a vertex's binormal vector.
				BINORMAL = 3,
				
				/// A usage where the attribute is used to specify a vertex's tangent vector.
				TANGENT = 4,
				
				/// A usage where the attribute is used to specify a vertex's color.
				COLOR = 5,
				
				/// A usage where the attribute is used to specify a vertex's texture coordinate.
				TEXTURE_COORDINATE = 6,
				
				/// A usage where the attribute is used to represent one or more per-vertex bone indices.
				BONE_INDEX = 7,
				
				/// A usage where the attribute is used to represent one or more per-vertex bone weights.
				BONE_WEIGHT = 8
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new vertex usage with the specified vertex attribute usage enum value.
			RIM_INLINE VertexUsage( Enum newUsage )
				:	usage( newUsage ),
					index( 0 )
			{
			}
			
			
			
			
			/// Create a new vertex usage with the specified usage enum value and index.
			RIM_INLINE VertexUsage( Enum newUsage, Index newIndex )
				:	usage( newUsage ),
					index( (UInt16)newIndex )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this vertex usage to an enum value.
			RIM_INLINE operator Enum () const
			{
				return (Enum)usage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Equality Comparison Operators
			
			
			
			
			/// Return whether or not this vertex usage is the same as another.
			/**
			  * This operator does not compare any usage index, just the usage type.
			  */
			RIM_INLINE Bool operator == ( const VertexUsage::Enum otherEnum ) const
			{
				return usage == otherEnum;
			}
			
			
			
			
			/// Return whether or not this vertex usage is the same as another.
			RIM_INLINE Bool operator == ( const VertexUsage& other ) const
			{
				return *((UInt32*)this) == *((UInt32*)&other);
			}
			
			
			
			
			/// Return whether or not this vertex usage is different than another.
			/**
			  * This operator does not compare any usage index, just the usage type.
			  */
			RIM_INLINE Bool operator != ( const VertexUsage::Enum otherEnum ) const
			{
				return usage != otherEnum;
			}
			
			
			
			
			/// Return whether or not this vertex usage is different than another.
			RIM_INLINE Bool operator != ( const VertexUsage& other ) const
			{
				return *((UInt32*)this) != *((UInt32*)&other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertex Attribute Type Accessor Method
			
			
			
			
			/// Return whether or not the specified vertex attribute type is a valid type for this usage.
			Bool isValidType( const AttributeType& type ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Index Accessor Methods
			
			
			
			
			/// Return an index for the vertex usage.
			/**
			  * This value allows the user to keep track of multiple distinct
			  * usages separately (i.e. for multiple lights) that have the
			  * same usage type.
			  */
			RIM_FORCE_INLINE Index getIndex() const
			{
				return index;
			}
			
			
			
			
			/// Return an index for the vertex usage.
			/**
			  * This value allows the user to keep track of multiple distinct
			  * usages separately (i.e. for multiple lights) that have the
			  * same usage type.
			  */
			RIM_FORCE_INLINE void setIndex( Index newIndex )
			{
				index = (UInt16)newIndex;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a unique string for this vertex usage that matches its enum value name.
			String toEnumString() const;
			
			
			
			
			/// Return a vertex usage which corresponds to the given enum string.
			static VertexUsage fromEnumString( const String& enumString );
			
			
			
			
			/// Return a string representation of the vertex usage.
			String toString() const;
			
			
			
			
			/// Convert this vertex usage into a string representation.
			RIM_FORCE_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum for the vertex usage.
			UInt16 usage;
			
			
			
			
			/// The index of the usage specified by the enum value.
			/**
			  * This value allows the user to keep track of multiple distinct
			  * usages separately (i.e. for multiple texture coordinates) that have the
			  * same usage type.
			  */
			UInt16 index;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Buffers Namespace  *****************************
RIM_GRAPHICS_BUFFERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_VERTEX_USAGE_H
