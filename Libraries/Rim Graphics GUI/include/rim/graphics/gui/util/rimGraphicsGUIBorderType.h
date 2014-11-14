/*
 *  rimGraphicsGUIBorderType.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/10/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_BORDER_TYPE_H
#define INCLUDE_RIM_GRAPHICS_GUI_BORDER_TYPE_H


#include "rimGraphicsGUIUtilitiesConfig.h"


//##########################################################################################
//*******************  Start Rim Graphics GUI Utilities Namespace  *************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the type of visual appearance of a rectangular border.
class BorderType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Enum Declaration
			
			
			
			
			/// An enum which specifies the different kinds of borders.
			typedef enum Enum
			{
				/// A border type where the border is a solid line.
				SOLID,
				
				/// A border type where the border is a dotted line.
				DOTTED,
				
				/// A border type where the border uses a color fade on all sides.
				/**
				  * The content area's background color is smoothly faded to the border
				  * color.
				  */
				FADE,
				
				/// A border type where border has a raised appearance.
				/**
				  * This is usually accomplished by using two-sided border lighting to
				  * give the impression of a raised border.
				  */
				RAISED,
				
				/// A border type where border has a sunken appearance.
				/**
				  * This is usually accomplished by using two-sided lighting to
				  * give the impression of a sunken border.
				  */
				SUNKEN,
				
				/// A border type which indicates that there should be no border.
				NONE
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new border type using the specified border type enum value.
			RIM_INLINE BorderType( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this border type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the border type.
			String toString() const;
			
			
			
			
			/// Convert this border type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value indicating the type of border this object represents.
			Enum type;
			
			
			
};




//##########################################################################################
//*******************  End Rim Graphics GUI Utilities Namespace  ***************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_BORDER_TYPE_H
