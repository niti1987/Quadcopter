/*
 *  rimGraphicsGUIDirection.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 3/31/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_DIRECTION_H
#define INCLUDE_RIM_GRAPHICS_GUI_DIRECTION_H


#include "rimGraphicsGUIUtilitiesConfig.h"


//##########################################################################################
//*******************  Start Rim Graphics GUI Utilities Namespace  *************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a 2D cardinal direction.
/**
  * This class can be used to specify the direction in which a GUI element
  * is pointing, or the direction in which text is renderered, for example.
  */
class Direction
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Enum Declaration
			
			
			
			
			/// An enum which specifies the different kinds of directions.
			typedef enum Enum
			{
				/// The negative X axis direction.
				LEFT,
				
				/// The positive X axis direction.
				RIGHT,
				
				/// The positive Y axis direction.
				UP,
				
				/// The negative Y axis direction.
				DOWN
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new direction using the specified direction type enum value.
			RIM_INLINE Direction( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this direction type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vector Accessor Method
			
			
			
			
			/// Return a 2D unit vector indicating the vector for this direction.
			RIM_INLINE Vector2f getVector() const
			{
				switch ( type )
				{
					case LEFT:	return Vector2f(-1,0);
					case RIGHT:	return Vector2f(1,0);
					case UP:	return Vector2f(0,1);
					case DOWN:	return Vector2f(0,-1);
					default:	return Vector2f(0,0);
				}
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


#endif // INCLUDE_RIM_GRAPHICS_GUI_DIRECTION_H
