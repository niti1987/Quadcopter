/*
 *  rimGraphicsProjectionType.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 4/19/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_PROJECTION_TYPE_H
#define INCLUDE_RIM_GRAPHICS_PROJECTION_TYPE_H


#include "rimGraphicsCamerasConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Cameras Namespace  ***************************
RIM_GRAPHICS_CAMERAS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that enumerates the different types of 3D->2D viewing projections.
class ProjectionType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Enum Declaration
			
			
			
			
			/// An enum type which represents the different projection types.
			typedef enum Enum
			{
				/// A projection where objects are the same size, no matter their distance.
				ORTHOGRAPHIC = 1,
				
				/// A projection where closer objects appear larger than farther away ones.
				PERSPECTIVE = 2,
				
				/// An orthographic projection with shearing applied.
				OBLIQUE = 3,
				
				/// An undefined or unknown projection type.
				UNDEFINED = 0
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new projection type with the specified projection type enum value.
			RIM_INLINE ProjectionType( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this projection type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the projection type.
			String toString() const;
			
			
			
			
			/// Convert this projection type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum representing the projection type.
			Enum type;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Cameras Namespace  *****************************
RIM_GRAPHICS_CAMERAS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_PROJECTION_TYPE_H
