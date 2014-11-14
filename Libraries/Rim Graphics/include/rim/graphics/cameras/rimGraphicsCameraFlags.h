/*
 *  rimGraphicsCameraFlags.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 7/3/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_CAMERA_FLAGS_H
#define INCLUDE_RIM_GRAPHICS_CAMERA_FLAGS_H


#include "rimGraphicsCamerasConfig.h"


//##########################################################################################
//************************  Start Rim Graphics Cameras Namespace  **************************
RIM_GRAPHICS_CAMERAS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates the different boolean flags that a camera can have.
/**
  * These flags provide boolean information about a certain camera. Flags
  * are indicated by setting a single bit of a 32-bit unsigned integer to 1.
  *
  * Enum values for the different flags are defined as members of the class. Typically,
  * the user would bitwise-OR the flag enum values together to produce a final set
  * of set flags.
  */
class CameraFlags
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Graphics Camera Flags Enum Declaration
			
			
			
			
			/// An enum which specifies the different camera flags.
			typedef enum Flag
			{
				/// A flag indicating that an camera is enabled to be drawn to the screen.
				ENABLED = (1 << 0),
				
				/// The flag value when all flags are not set.
				UNDEFINED = 0
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new camera flags camera with no flags set.
			RIM_INLINE CameraFlags()
				:	flags( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new camera flags camera with the specified flag value initially set.
			RIM_INLINE CameraFlags( Flag flag )
				:	flags( flag )
			{
			}
			
			
			
			
			/// Create a new camera flags camera with the specified initial combined flags value.
			RIM_INLINE CameraFlags( UInt32 newFlags )
				:	flags( newFlags )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Integer Cast Operator
			
			
			
			
			/// Convert this camera flags camera to an integer value.
			/**
			  * This operator is provided so that the CameraFlags camera
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
			
			
			
			
			/// Return whether or not the specified flag value is set for this flags camera.
			RIM_INLINE Bool isSet( Flag flag ) const
			{
				return (flags & flag) != UNDEFINED;
			}
			
			
			
			
			/// Set whether or not the specified flag value is set for this flags camera.
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
			
			
			
			
			/// A value indicating the flags that are set for a camera.
			UInt32 flags;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics Cameras Namespace  ****************************
RIM_GRAPHICS_CAMERAS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_CAMERA_FLAGS_H
