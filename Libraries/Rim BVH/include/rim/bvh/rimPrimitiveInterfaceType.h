/*
 *  rimPrimitiveInterfaceType.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 5/4/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_BVH_PRIMITIVE_INTERFACE_TYPE_H
#define INCLUDE_RIM_BVH_PRIMITIVE_INTERFACE_TYPE_H


#include "rimBVHConfig.h"


//##########################################################################################
//*****************************  Start Rim BVH Namespace  **********************************
RIM_BVH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the type of a primitive.
class PrimitiveInterfaceType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Enum Declaration
			
			
			
			
			/// An enum which specifies the different allowed texture faces.
			typedef enum Enum
			{
				/// An enum corresponding to a primitive interface for points.
				POINTS = 1,
				
				/// An enum corresponding to a primitive interface for line segments.
				LINES = 2,
				
				/// An enum corresponding to a primitive interface for triangles.
				TRIANGLES = 3,
				
				/// An enum corresponding to a primitive interface for quads.
				QUADS = 4,
				
				/// An enum corresponding to a primitive interface for axis-aligned bounding boxes.
				AABBS = 5,
				
				/// An enum corresponding to a primitive interface for spheres.
				SPHERES = 6,
				
				/// An enum corresponding to a primitive interface for cylinders.
				CYLINDERS = 7,
				
				/// An enum corresponding to a primitive interface for capsules.
				CAPSULES = 8,
				
				/// An enum corresponding to a primitive interface for oriented boxes.
				BOXES = 9,
				
				/// An undefined primitive type, the default.
				UNDEFINED = 0
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new primitive type with an UNDEFINED type value.
			RIM_INLINE PrimitiveInterfaceType()
				:	type( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new primitive type with the specified primitive type enum value.
			RIM_INLINE PrimitiveInterfaceType( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this primitive type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the primitive type.
			String toString() const;
			
			
			
			
			/// Convert this primitive type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value which represents the primitive type.
			Enum type;
			
			
			
};




//##########################################################################################
//*****************************  End Rim BVH Namespace  ************************************
RIM_BVH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_BVH_PRIMITIVE_INTERFACE_TYPE_H
