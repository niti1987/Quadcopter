/*
 *  rimGUIInputKey.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 1/30/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_INPUT_KEY_H
#define INCLUDE_RIM_GUI_INPUT_KEY_H


#include "rimGUIInputConfig.h"


//##########################################################################################
//************************     Start Rim GUI Input Namespace     ***************************
RIM_GUI_INPUT_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a single key on a keyboard.
/**
  * Each Key object has an integeral key code for that key, plus a
  * human-readable name string for that key.
  *
  * This class also provides statically-defined Key objects that encompass
  * most types of keyboards. These objects can be queried directly as public
  * static members or by hash table key code lookup.
  */
class Key
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			/// The type to use for a key code.
			typedef UInt Code;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a key with an undefind code and name.
			RIM_INLINE Key()
				:	code( UNKNOWN.getCode() ),
					name( UNKNOWN.getName() )
			{
			}
			
			
			
			
			/// Create a key with the specified code and name string.
			RIM_INLINE Key( Code keyCode, const String& keyName )
				:	code( keyCode ),
					name( keyName )
			{
			}
			
			
			
			
			/// Create a key with the specified code and name string.
			RIM_INLINE Key( Code keyCode, const Char* keyName )
				:	code( keyCode ),
					name( keyName )
			{
			}
			
			
			
			
			/// Return a const reference to this key's name string.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			RIM_INLINE Code getCode() const
			{
				return code;
			}
			
			
			
			
			RIM_INLINE Hash getHashCode() const
			{
				return (Hash)code;
			}
		
		
		
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Key String Conversion Methods
			
			
			
			
			/// Return a const reference to this key's string representation (its name).
			RIM_INLINE const String& toString() const
			{
				return name;
			}
			
			
			
			
			/// Convert this key to a string representation (its name).
			RIM_INLINE operator String () const
			{
				return name;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Equality Comparison Operators
			
			
			
			
			/// Return whether or not this key is equal to another key.
			RIM_INLINE Bool operator == ( const Key& key ) const
			{
				return code == key.code;
			}
			
			
			
			
			/// Return whether or not this key is not equal to another key.
			RIM_INLINE Bool operator != ( const Key& key ) const
			{
				return code != key.code;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Key Accessor Methods
			
			
			
			
			/// Return a const reference to the statically-defined key with the specified code.
			static const Key& getKeyWithCode( Code keyCode );			
			
			
			
			/// Return a const reference to a list of all statically-defined keys.
			RIM_INLINE static const ArrayList<const Key*>& getKeys()
			{
				if ( !keyDataStructuresAreInitialized )
					initializeKeyDataStructures();
				
				return keys;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Statically Defined Unknown Key
			
			
			
			
			static const Key UNKNOWN;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Statically Defined Letter Keys
			
			
			
			
			static const Key A;
			static const Key B;
			static const Key C;
			static const Key D;
			static const Key E;
			static const Key F;
			static const Key G;
			static const Key H;
			static const Key I;
			static const Key J;
			static const Key K;
			static const Key L;
			static const Key M;
			static const Key N;
			static const Key O;
			static const Key P;
			static const Key Q;
			static const Key R;
			static const Key S;
			static const Key T;
			static const Key U;
			static const Key V;
			static const Key W;
			static const Key X;
			static const Key Y;
			static const Key Z;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Statically Defined Number Keys
			
			
			
			
			static const Key NUMBER_0;
			static const Key NUMBER_1;
			static const Key NUMBER_2;
			static const Key NUMBER_3;
			static const Key NUMBER_4;
			static const Key NUMBER_5;
			static const Key NUMBER_6;
			static const Key NUMBER_7;
			static const Key NUMBER_8;
			static const Key NUMBER_9;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Statically Defined Punctuation Keys
			
			
			
			
			static const Key QUOTE;
			static const Key COMMA;
			static const Key HYPHEN;
			static const Key PERIOD;
			static const Key SLASH;
			static const Key SEMICOLON;
			static const Key EQUALS;
			static const Key OPEN_BRACKET;
			static const Key CLOSE_BRACKET;
			static const Key BACKSLASH;
			static const Key TILDE;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Statically Defined Keypad Keys
			
			
			
			
			static const Key KEYPAD_0;
			static const Key KEYPAD_1;
			static const Key KEYPAD_2;
			static const Key KEYPAD_3;
			static const Key KEYPAD_4;
			static const Key KEYPAD_5;
			static const Key KEYPAD_6;
			static const Key KEYPAD_7;
			static const Key KEYPAD_8;
			static const Key KEYPAD_9;
			
			
			static const Key KEYPAD_PERIOD;
			static const Key KEYPAD_SLASH;
			static const Key KEYPAD_ASTERISK;
			static const Key KEYPAD_HYPHEN;
			static const Key KEYPAD_PLUS;
			static const Key KEYPAD_ENTER;
			static const Key KEYPAD_EQUALS;
			static const Key KEYPAD_COMMA;
			static const Key KEYPAD_EQUALS_AS400;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Statically Defined Keystate Modifier Keys
			
			
			
			
			static const Key NUM_LOCK;
			static const Key CAPS_LOCK;
			static const Key SCROLL_LOCK;
			static const Key LEFT_SHIFT;
			static const Key RIGHT_SHIFT;
			static const Key LEFT_CONTROL;
			static const Key RIGHT_CONTROL;
			static const Key LEFT_ALT;
			static const Key RIGHT_ALT;
			static const Key LEFT_GUI;
			static const Key RIGHT_GUI;
			static const Key LOCKING_CAPS_LOCK;
			static const Key LOCKING_NUM_LOCK;
			static const Key LOCKING_SCROLL_LOCK;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Statically Defined Arrow Keys
			
			
			
			
			static const Key UP_ARROW;
			static const Key DOWN_ARROW;
			static const Key LEFT_ARROW;
			static const Key RIGHT_ARROW;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Statically Defined Basic Function Keys
			
			
			
			
			static const Key BACKSPACE;
			static const Key DELETE;
			static const Key TAB;
			static const Key CLEAR;
			static const Key RETURN;
			static const Key PAUSE;
			static const Key ESCAPE;
			static const Key SPACE;
			static const Key ALTERNATE_ERASE;
			static const Key ALTERNATE_RETURN;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Statically Defined Miscellaneous Function Keys
			
			
			
			
			static const Key HELP;
			static const Key PRINT;
			static const Key SYS_REQ;
			static const Key MENU;
			static const Key POWER;
			static const Key UNDO;
			static const Key INSERT;
			static const Key HOME;
			static const Key END;
			static const Key PAGE_UP;
			static const Key PAGE_DOWN;
			static const Key APPLICATION;
			static const Key EXECUTE;
			static const Key SELECT;
			static const Key STOP;
			static const Key AGAIN;
			static const Key VOLUME_UP;
			static const Key VOLUME_DOWN;
			static const Key VOLUME_MUTE;
			static const Key CANCEL;
			static const Key PRIOR;
			static const Key SEPARATOR;
			static const Key OUT;
			static const Key OPERATE;
			static const Key CLEAR_OR_AGAIN;
			static const Key CR_SEL_OR_PROPS;
			static const Key EX_SEL;
			static const Key CUT;
			static const Key COPY;
			static const Key PASTE;
			static const Key FIND;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Statically Defined Programmable Function Keys
			
			
			
			
			static const Key F1;
			static const Key F2;
			static const Key F3;
			static const Key F4;
			static const Key F5;
			static const Key F6;
			static const Key F7;
			static const Key F8;
			static const Key F9;
			static const Key F10;
			static const Key F11;
			static const Key F12;
			static const Key F13;
			static const Key F14;
			static const Key F15;
			static const Key F16;
			static const Key F17;
			static const Key F18;
			static const Key F19;
			static const Key F20;
			static const Key F21;
			static const Key F22;
			static const Key F23;
			static const Key F24;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Statically Defined International Keys
			
			
			
			
			static const Key INTERNATIONAL_1;
			static const Key INTERNATIONAL_2;
			static const Key INTERNATIONAL_3;
			static const Key INTERNATIONAL_4;
			static const Key INTERNATIONAL_5;
			static const Key INTERNATIONAL_6;
			static const Key INTERNATIONAL_7;
			static const Key INTERNATIONAL_8;
			static const Key INTERNATIONAL_9;
			
			
			static const Key LANGUAGE_1;
			static const Key LANGUAGE_2;
			static const Key LANGUAGE_3;
			static const Key LANGUAGE_4;
			static const Key LANGUAGE_5;
			static const Key LANGUAGE_6;
			static const Key LANGUAGE_7;
			static const Key LANGUAGE_8;
			static const Key LANGUAGE_9;
			
			
			static const Key NON_US_POUND;
			static const Key NON_US_BACKSLASH;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Key Data Structure Initializer Methods
			
			
			
			
			/// Add the specified key to the statically-defined key data structures.
			RIM_NO_INLINE static void addKeyToDataStructures( const Key& key )
			{
				keys.add( &key );
				keyMap.add( (Hash)key.getCode(), key.getCode(), &key );
			}
			
			
			
			
			/// Initialize the statically-defined key data structures.
			static void initializeKeyDataStructures();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An integer value which represents this key.
			Code code;
			
			
			
			
			/// A human-readable string representation for this key.
			String name;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// A map from statically defined key codes to key objects.
			static HashMap<Code,const Key*> keyMap;
			
			
			
			
			/// A list of all statically defined keys.
			static ArrayList<const Key*> keys;
			
			
			
			
			/// A boolean indicating whether or not the static key data structures have been initialized.
			static Bool keyDataStructuresAreInitialized;
			
			
			
			
};




//##########################################################################################
//************************     End Rim GUI Input Namespace     *****************************
RIM_GUI_INPUT_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_INPUT_KEY_H
