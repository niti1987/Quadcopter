/*
 *  rimGUIInputKeyCodeConverter.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 5/28/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_INPUT_KEY_CODE_CONVERTER_H
#define INCLUDE_RIM_GUI_INPUT_KEY_CODE_CONVERTER_H


#include "rimGUIInputConfig.h"


#include "rimGUIInputKey.h"


//##########################################################################################
//************************     Start Rim GUI Input Namespace     ***************************
RIM_GUI_INPUT_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which is used to convert key codes from platform-specific codes to a generic code set.
class KeyCodeConverter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Key Conversion Methods
			
			
			
			
			/// Convert the specified Mac OS X key code to a generic code set.
			static Key::Code convertMacCode( Key::Code macKeyCode )
			{
				if ( !keyCodesAreInitialized )
					KeyCodeConverter::initializeKeyCodes();
				
				Index index = macKeyCode & 0x7f;
				
				return MAC_KEY_CODE_MAPPING[index];
			}
			
			
			
			
			/// Convert the specified Windows key code to a generic code set.
			static Key::Code convertWindowsCode( Key::Code windowsKeyCode )
			{
				if ( !keyCodesAreInitialized )
					KeyCodeConverter::initializeKeyCodes();
				
				Index index = windowsKeyCode & 0xff;
				
				return WINDOWS_KEY_CODE_MAPPING[index];
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Key Accessor Methods
			
			
			
			
			/// Return a reference to the Key object for the specified Mac OS X key code.
			RIM_INLINE static const Key& getKeyForMacCode( Key::Code macKeyCode )
			{
				return Key::getKeyWithCode( KeyCodeConverter::convertMacCode( macKeyCode ) );
			}
			
			
			
			
			/// Return a reference to the Key object for the specified Windows key code.
			RIM_INLINE static const Key& getKeyForWindowsCode( Key::Code windowsKeyCode )
			{
				return Key::getKeyWithCode( KeyCodeConverter::convertWindowsCode( windowsKeyCode ) );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructor
			
			
			
			
			/// Declared private to avoid instantiation.
			KeyCodeConverter()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Methods
			
			
			
			
			/// Initialized the key code mappings for all platforms.
			static void initializeKeyCodes();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// An array of key codes that map from Mac OS X key code indices to generic key codes.
			static Key::Code MAC_KEY_CODE_MAPPING[128];
			
			
			
			
			/// An array of key codes that map from Windows key code indices to generic key codes.
			static Key::Code WINDOWS_KEY_CODE_MAPPING[256];
			
			
			
			
			/// Whether or not the key code conversion tables are initialized.
			static Bool keyCodesAreInitialized;
			
			
			
};




//##########################################################################################
//************************     End Rim GUI Input Namespace     *****************************
RIM_GUI_INPUT_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_INPUT_KEY_CODE_CONVERTER_H
