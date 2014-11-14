/*
 *  rimGraphicsObjectFlags.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/16/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_OBJECT_FLAGS_H
#define INCLUDE_RIM_GRAPHICS_OBJECT_FLAGS_H


#include "rimGraphicsObjectsConfig.h"


//##########################################################################################
//************************  Start Rim Graphics Objects Namespace  **************************
RIM_GRAPHICS_OBJECTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates the different boolean flags that a graphics object can have.
/**
  * These flags provide boolean information about a certain graphics object. Flags
  * are indicated by setting a single bit of a 32-bit unsigned integer to 1.
  *
  * Enum values for the different flags are defined as members of the class. Typically,
  * the user would bitwise-OR the flag enum values together to produce a final set
  * of set flags.
  */
class GraphicsObjectFlags
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Graphics Object Flags Enum Declaration
			
			
			
			
			/// An enum which specifies the different graphics object flags.
			typedef enum Flag
			{
				/// A flag indicating that an object should be drawn.
				VISIBLE = (1 << 0),
				
				/// A flag indicating whether or not the object can cast shadows.
				SHADOWS_ENABLED = (1 << 1),
				
				/// The flag value when all flags are not set.
				UNDEFINED = 0
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new graphics object flags object with no flags set.
			RIM_INLINE GraphicsObjectFlags()
				:	flags( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new graphics object flags object with the specified flag value initially set.
			RIM_INLINE GraphicsObjectFlags( Flag flag )
				:	flags( flag )
			{
			}
			
			
			
			
			/// Create a new graphics object flags object with the specified initial combined flags value.
			RIM_INLINE GraphicsObjectFlags( UInt32 newFlags )
				:	flags( newFlags )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Integer Cast Operator
			
			
			
			
			/// Convert this graphics object flags object to an integer value.
			/**
			  * This operator is provided so that the GraphicsObjectFlags object
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
			
			
			
			
			/// A value indicating the flags that are set for a graphics object.
			UInt32 flags;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics Objects Namespace  ****************************
RIM_GRAPHICS_OBJECTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_OBJECT_FLAGS_H
