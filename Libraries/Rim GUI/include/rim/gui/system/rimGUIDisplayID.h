/*
 *  rimGUIDisplayID.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 9/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_DISPLAY_ID_H
#define INCLUDE_RIM_GUI_DISPLAY_ID_H


#include "rimGUISystemConfig.h"


//##########################################################################################
//************************     Start Rim GUI System Namespace     **************************
RIM_GUI_SYSTEM_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which is used to encapsulate a unique identifier for a system video display.
/**
  * This opaque type uses a platform-dependent internal representation which uniquely
  * identifies a connected video display on this system.
  */
class DisplayID
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Constants
			
			
			
			
			/// An instance of DisplayID that represents an invalid video display.
			static const DisplayID INVALID;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this display ID represents the same display as another.
			RIM_INLINE Bool operator == ( const DisplayID& other ) const
			{
				return displayID == other.displayID;
			}
			
			
			
			
			/// Return whether or not this display ID represents a different display than another.
			RIM_INLINE Bool operator != ( const DisplayID& other ) const
			{
				return displayID != other.displayID;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Device Status Accessor Method
			
			
			
			
			/// Return whether or not this DisplayID represents a valid display.
			/**
			  * This condition is met whenever the display ID is not equal to INVALID_DISPLAY_ID.
			  */
			RIM_INLINE Bool isValid() const
			{
				return displayID != INVALID_DISPLAY_ID;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Platform-Specific ID Accessor Methods
			
			
			
			
#if defined(RIM_PLATFORM_WINDOWS)
			/// Return a const reference to the wide-character string uniquely representing a video display on this system.
			RIM_INLINE const UTF16String& getIDString() const
			{
				return displayID;
			}
#else
			/// Convert this DisplayID object to an unsigned integer which uniquely represents a dislay on this system.
			RIM_INLINE PointerInt getID() const
			{
				return displayID;
			}
#endif
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructor
			
			
			
			
#if defined(RIM_PLATFORM_WINDOWS)
			/// Create a DisplayID object which represents the display with the specified device ID.
			RIM_INLINE explicit DisplayID( const UTF16String& newDisplayID )
				:	displayID( newDisplayID )
			{
			}
			
#else
			/// Create a DisplayID object which represents the display with the specified display ID.
			RIM_INLINE explicit DisplayID( PointerInt newDisplayID )
				:	displayID( newDisplayID )
			{
			}
#endif
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Conversion Methods
			
			
			
			
#if defined(RIM_PLATFORM_APPLE)
			/// Convert this DisplayID object to an unsigned integer which uniquely represents a dislay on this system.
			RIM_INLINE operator PointerInt () const
			{
				return displayID;
			}
#endif
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
#if defined(RIM_PLATFORM_WINDOWS)
			
			/// The underlying representation of a DisplayID on windows, a UTF-16 encoded ID string.
			UTF16String displayID;
			
			/// The reserved ID used to indicate an invalid display.
			static const UTF16String INVALID_DISPLAY_ID;
			
#else
			
			/// The underlying representation of a DisplayID, an unsigned integer.
			PointerInt displayID;
			
			/// The reserved ID used to indicate an invalid display.
			static const PointerInt INVALID_DISPLAY_ID = -1;
			
#endif
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Declaration
			
			
			
			
			/// Declare the Display class a friend so that it can use opaque DisplayID objects.
			friend class Display;
			
			
			
};




//##########################################################################################
//************************     End Rim GUI System Namespace     ****************************
RIM_GUI_SYSTEM_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_DISPLAY_ID_H
