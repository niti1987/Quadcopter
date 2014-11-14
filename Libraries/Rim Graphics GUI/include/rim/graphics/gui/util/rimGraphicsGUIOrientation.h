/*
 *  rimGraphicsGUIOrientation.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/7/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_ORIENTATION_H
#define INCLUDE_RIM_GRAPHICS_GUI_ORIENTATION_H


#include "rimGraphicsGUIUtilitiesConfig.h"


//##########################################################################################
//*******************  Start Rim Graphics GUI Utilities Namespace  *************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a 2D axis direction.
/**
  * This class can be used to specify how certain GUI elements are rotated,
  * allowing them to specify either a horizontal or vertical orientation.
  */
class Orientation
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Enum Declaration
			
			
			
			
			/// An enum which specifies the different kinds of orientations.
			typedef enum Enum
			{
				/// A horizontal orientation, where the major axis is the X axis.
				HORIZONTAL,
				
				/// A vertical orientation, where the major axis is the Y axis.
				VERTICAL
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new orientation using the specified orientation type enum value.
			RIM_INLINE Orientation( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this orientation type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the orientation type.
			String toString() const;
			
			
			
			
			/// Convert this orientation type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value indicating the type of orientation this object represents.
			Enum type;
			
			
			
};




//##########################################################################################
//*******************  End Rim Graphics GUI Utilities Namespace  ***************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_ORIENTATION_H
