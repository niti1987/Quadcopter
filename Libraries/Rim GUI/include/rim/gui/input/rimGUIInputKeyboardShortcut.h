/*
 *  rimGUIInputKeyboardShortcut.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 6/7/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_INPUT_KEYBOARD_SHORTCUT_H
#define INCLUDE_RIM_GUI_INPUT_KEYBOARD_SHORTCUT_H


#include "rimGUIInputConfig.h"


//##########################################################################################
//************************     Start Rim GUI Input Namespace     ***************************
RIM_GUI_INPUT_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a keyboard shortcut, usually for a menu item.
/**
  * This class describes the keys that the user must press together in order to 
  * execute a keyboard shortcut. Typically, keyboard shortcuts will be associated with
  * specific menu items, allowing the user to quickly perform basic operations such as
  * copy and paste without having to use the mouse.
  */
class KeyboardShortcut
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Key Modifier Type Enum
			
			
			
			
			/// An enum of keyboard shortcut modifier flags.
			/**
			  * These flags are combined into a bitfield which represents the different
			  * modifiers that affect a given key character.
			  */
			typedef enum Modifier
			{
				/// The default modifier key to use on Mac OS X that represents the command/apple key.
				COMMAND = 1,
				
				/// A modifier key to use on windows that represents the windows key.
				/**
				  * This key modifier shouldn't be used because the default behavior in windows
				  * is for this key to open the start menu.
				  */
				WINDOWS = 1,
				
				/// The generic name for the GUI-specific modifier key (either the command or windows key).
				GUI_KEY = 1,
				
				/// The modifier key code that represents the control key.
				CONTROL = 2,
				
				/// The modifier key code that represents the shift key.
				SHIFT = 4,
				
				/// The modifier key code that represents the option key on Mac OS X (same as ALT).
				OPTION = 8,
				
				/// The modifier key code that represents the alt key on Windows (same as OPTION).
				ALT = 8
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default keyboard shortcut which doesn't correspond to any keyboard key.
			RIM_INLINE KeyboardShortcut()
				:	character( '\0' )
			{
			}
			
			
			
			
			/// Create a keyboard shortcut for the specified character and the system default modifier(s).
			RIM_INLINE KeyboardShortcut( Char newCharacter )
				:	character( newCharacter )
			{
#if defined(RIM_PLATFORM_APPLE)
				modifiers = COMMAND;
#elif defined(RIM_PLATFORM_WINDOWS)
				modifiers = CONTROL;
#else
				modifiers = CONTROL;
#endif
			}
			
			
			
			
			/// Create a keyboard shortcut using the specified character and modifier.
			RIM_INLINE KeyboardShortcut( Char newCharacter, Modifier modifier )
				:	modifiers( modifier ),
					character( newCharacter )
			{
			}
			
			
			
			
			/// Create a keyboard shortcut using the specified character and 2 modifiers.
			RIM_INLINE KeyboardShortcut( Char newCharacter, Modifier modifier1, Modifier modifier2 )
				:	modifiers( modifier1 | modifier2 ),
					character( newCharacter )
			{
			}
			
			
			
			
			/// Create a keyboard shortcut using the specified character and 3 modifiers.
			RIM_INLINE KeyboardShortcut( Char newCharacter, Modifier modifier1,
										Modifier modifier2, Modifier modifier3 )
				:	modifiers( modifier1 | modifier2 | modifier3 ),
					character( newCharacter )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Character Accessor Methods
			
			
			
			
			/// Return the character which this keyboard shortcut applies to.
			RIM_INLINE Char getCharacter() const
			{
				return character;
			}
			
			
			
			
			/// Set the character which this keyboard shortcut applies to.
			RIM_INLINE void setCharacter( Char newCharacter )
			{
				character = newCharacter;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Modifier Accessor Methods
			
			
			
			
			/// Return a bitfield representing the different modifier keys associated with this keyboard shortcut.
			RIM_INLINE UInt32 getModifiers() const
			{
				return modifiers;
			}
			
			
			
			
			/// Return whether or not this keyboard shortcut has any modifier keys set.
			RIM_INLINE Bool hasModifiers() const
			{
				return modifiers != UInt32(0);
			}
			
			
			
			
			/// Return whether or not this keyboard shortcut has the specified modifier key set.
			RIM_INLINE Bool hasModifier( Modifier newModifier ) const
			{
				return (modifiers & newModifier) != UInt32(0);
			}
			
			
			
			
			/// Ensure that the specified key modifier is set for this keyboard shortcut.
			RIM_INLINE void setModifier( Modifier newModifier )
			{
				modifiers |= newModifier;
			}
			
			
			
			
			/// Ensure that the specified key modifier is not set for this keyboard shortcut.
			RIM_INLINE void removeModifier( Modifier oldModifier )
			{
				modifiers = modifiers & (~oldModifier);
			}
			
			
			
			
			/// Clear all set modifiers and reinitialize the keyboard shortcut to use only the specified modifier.
			/**
			  * Since a keyboard shortcut must always have an associated modifier key, an
			  * initial modifier is required when clearing the other modifiers.
			  */
			RIM_INLINE void clearModifiers( Modifier initialModifier )
			{
				modifiers = initialModifier;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Keyboard Shortcut Comparison Operators
			
			
			
			
			/// Return whether or not this keyboard shortcut is exactly equal to another.
			RIM_INLINE Bool operator == ( const KeyboardShortcut& other ) const
			{
				return character == other.character && modifiers == other.modifiers;
			}
			
			
			
			
			/// Return whether or not this keyboard shortcut is not equal to another.
			RIM_INLINE Bool operator != ( const KeyboardShortcut& other ) const
			{
				return character != other.character || modifiers != other.modifiers;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Validity Accessor Methods
			
			
			
			
			/// Return whether or not this keyboard shortcut is valid and properly formed.
			RIM_INLINE Bool isValid() const
			{
				return character != '\0';
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Conversion Methods
			
			
			
			
			/// Convert this keyboard shortcut to a human-readable string representation.
			/**
			  * The representation returned may differ, depending on the system platform.
			  */
			UTF8String toString() const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A bitfield representing all of the modifiers that are active for this keyboard shortcut.
			UInt32 modifiers;
			
			
			
			
			/// A character indicating the desired key that this shortcut applies to.
			Char character;
			
			
			
};




//##########################################################################################
//************************     End Rim GUI Input Namespace     *****************************
RIM_GUI_INPUT_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_INPUT_KEYBOARD_SHORTCUT_H
