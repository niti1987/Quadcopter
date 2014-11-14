/*
 *  rimGraphicsGUIObjectFlags.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 11/2/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_OBJECT_FLAGS_H
#define INCLUDE_RIM_GRAPHICS_GUI_OBJECT_FLAGS_H


#include "rimGraphicsGUIConfig.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates the different boolean flags that a GUI object can have.
/**
  * These flags provide boolean information about a certain GUI object. Flags
  * are indicated by setting a single bit of a 32-bit unsigned integer to 1.
  *
  * Enum values for the different flags are defined as members of the class. Typically,
  * the user would bitwise-OR the flag enum values together to produce a final set
  * of set flags.
  */
class GUIObjectFlags
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Graphics Object Flags Enum Declaration
			
			
			
			
			/// An enum which specifies the different GUI object flags.
			typedef enum Flag
			{
				/// A flag indicating that an object should be drawn.
				VISIBLE = (1 << 0),
				
				/// A flag indicating whether or not the object should clip child rendering to its bounds.
				CLIPPING = (1 << 1),
				
				/// A flag indicating that an object should be drawn with a shadow.
				SHADOW = (1 << 2),
				
				/// The default flags to use for a GUI object.
				DEFAULT = VISIBLE | CLIPPING,
				
				/// The flag value when all flags are not set.
				UNDEFINED = 0
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new GUI object flags object with no flags set.
			RIM_INLINE GUIObjectFlags()
				:	flags( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new GUI object flags object with the specified flag value initially set.
			RIM_INLINE GUIObjectFlags( Flag flag )
				:	flags( flag )
			{
			}
			
			
			
			
			/// Create a new GUI object flags object with the specified initial combined flags value.
			RIM_INLINE GUIObjectFlags( UInt32 newFlags )
				:	flags( newFlags )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Integer Cast Operator
			
			
			
			
			/// Convert this GUI object flags object to an integer value.
			/**
			  * This operator is provided so that the GUIObjectFlags object
			  * can be used as an integer value for bitwise logical operations.
			  */
			RIM_INLINE operator UInt32 () const
			{
				return flags;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flag Status Accessor Methods
			
			
			
			
			/// Return whether or not the specified flag value is set for this flags object.
			RIM_INLINE Bool isSet( Flag flag ) const
			{
				return (flags & flag) != UNDEFINED;
			}
			
			
			
			
			/// Set whether or not the specified flag value is set for this flags object.
			RIM_INLINE void set( Flag flag, Bool newIsSet )
			{
				if ( newIsSet )
					flags |= flag;
				else
					flags &= ~flag;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flag String Accessor Methods
			
			
			
			
			/// Return the flag for the specified literal string representation.
			static Flag fromEnumString( const String& enumString );
			
			
			
			
			/// Convert the specified flag to its literal string representation.
			static String toEnumString( Flag flag );
			
			
			
			
			/// Convert the specified flag to human-readable string representation.
			static String toString( Flag flag );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A value indicating the flags that are set for a GUI object.
			UInt32 flags;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_OBJECT_FLAGS_H
