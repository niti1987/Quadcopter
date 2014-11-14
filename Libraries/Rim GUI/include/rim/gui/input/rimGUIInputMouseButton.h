/*
 *  rimGUIInputMouseButton.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 1/30/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_INPUT_MOUSE_BUTTON_H
#define INCLUDE_RIM_GUI_INPUT_MOUSE_BUTTON_H


#include "rimGUIInputConfig.h"


//##########################################################################################
//************************     Start Rim GUI Input Namespace     ***************************
RIM_GUI_INPUT_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class representing a mouse button.
/**
  * There are several possible types of mouse buttons and they are accessed 
  * as public static members of the mouse button class. Each button is uniquely
  * idenfitifed by an integer button code and has a name. User-defined mouse button
  * types can also be created.
  *
  * This class also provides statically-defined MouseButton objects that encompass
  * most types of mouse buttons. These objects can be queried directly as public
  * static members or by hash table key code lookup.
  */
class MouseButton
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			/// The type to use for a mouse button code.
			typedef UInt Code;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new mouse button with the specified code and name as a string.
			RIM_INLINE MouseButton( Code buttonCode, const String& buttonName )
				:	code( buttonCode ),
					name( buttonName )
			{
			}
			
			
			
			
			/// Create a new mouse button with the specified code and name as a character array.
			RIM_INLINE MouseButton( Code buttonCode, const Char* buttonName )
				:	code( buttonCode ),
					name( buttonName )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mouse Button Code and Name Accessors
			
			
			
			
			/// Get a string representing the button's name.
			RIM_INLINE const String& toString() const
			{
				return name;
			}
			
			
			
			/// Get a string representing the button's name.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Get an integer code representing the mouse button.
			RIM_INLINE Code getCode() const
			{
				return code;
			}
			
			
			
			
			/// Get a hash code for the mouse button.
			RIM_INLINE Hash getHashCode() const
			{
				return (Hash)code;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Equality Comparison Operators
			
			
			
			
			/// Test whether or not this button is equal to another. (compares button code)
			RIM_INLINE Bool operator == ( const MouseButton& button ) const
			{
				return code == button.code ;
			}
			
			
			
			
			/// Test whether or not this button is not equal to another. (compares button code)
			RIM_INLINE Bool operator != ( const MouseButton& button ) const
			{
				return code  != button.code ;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Mouse Button Accessors
			
			
			
			
			/// Get a reference to a mouse button, based on it's button code (an integer).
			RIM_INLINE static const MouseButton& getButtonWithCode( Code buttonCode )
			{
				if ( !buttonDataStructuresAreInitialized )
					initializeButtonDataStructures();
				
				const MouseButton** button;
				
				if ( buttonMap.find( (Hash)buttonCode, buttonCode, button ) )
					return **button;
				else
					return UNKNOWN;
			}
			
			
			
			
			/// Get a reference of an array list of all predefined mouse buttons
			RIM_INLINE static const ArrayList<const MouseButton*>& getButtons()
			{
				if ( !buttonDataStructuresAreInitialized )
					initializeButtonDataStructures();
				
				return buttons;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Statically Defined Mouse Buttons
			
			
			
			
			/// Unknown mouse button (used as a catch-all)
			static const MouseButton UNKNOWN;
			
			
			/// Left mouse button.
			static const MouseButton LEFT;
			
			
			/// Middle mouse button.
			static const MouseButton MIDDLE;
			
			
			/// Right mouse button.
			static const MouseButton RIGHT;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Key Data Structure Initializer Methods
			
			
			
			
			/// Add the specified mouse button to the static mouse button data structures.
			RIM_NO_INLINE static void addButtonToDataStructures( const MouseButton& button )
			{
				buttons.add( &button );
				buttonMap.add( (Hash)button.getCode(), button.getCode(), &button );
			}
			
			
			
			
			/// Initialize the data structures used for mouse button lookup.
			static void initializeButtonDataStructures();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An integer button code serving as a uniqued identifier for the button.
			Code code;
			
			
			
			
			/// A string representing the name of the button
			String name;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// A static hash map mapping integer button codes to mouse button pointer.
			static HashMap<Code,const MouseButton*> buttonMap;
			
			
			
			
			/// A static array list which contains all possible mouse buttons.
			static ArrayList<const MouseButton*> buttons;
			
			
			
			
			/// Whether or not the static mouse button data structures have been initialized.
			static Bool buttonDataStructuresAreInitialized;
			
			
			
			
};




//##########################################################################################
//************************     End Rim GUI Input Namespace     *****************************
RIM_GUI_INPUT_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_INPUT_MOUSE_BUTTON_H
