/*
 *  rimGraphicsGUIButtonType.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/5/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_BUTTON_TYPE_H
#define INCLUDE_RIM_GRAPHICS_GUI_BUTTON_TYPE_H


#include "rimGraphicsGUIBase.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the type of a button.
class ButtonType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Enum Declaration
			
			
			
			
			/// An enum which specifies the different kinds of buttons.
			typedef enum Enum
			{
				/// A button type where the button selection event is sent when the button is released after being pressed.
				/**
				  * The button sends a 'select' message when the button is pressed
				  * and then released. The button is then immediatedly set to be unselected.
				  *
				  * This button type should be used to perform an action when it is selected.
				  * Since the button is not selected until released over the button's area,
				  * it gives the user the ability to confirm their choice.
				  */
				ACTION,
				
				/// A button type where the button is only selected while it is pressed.
				/**
				  * The button sends a 'select' message when the button is first pressed
				  * and an 'unselect' message when the button is released.
				  */
				MOMENTARY,
				
				/// A button type where the button is either in an 'on' or 'off' state.
				/**
				  * The button sends a 'select' message when the button is pressed
				  * and then released, turning the button to the 'on' state. An 'unselect'
				  * message is sent when the button is pressed again and released,
				  * turning it to the 'off' state.
				  */
				SWITCH
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new button type using the specified button type enum value.
			RIM_INLINE ButtonType( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this button type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the button type.
			String toString() const;
			
			
			
			
			/// Convert this button type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value indicating the type of button this object represents.
			Enum type;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_BUTTON_TYPE_H
