/*
 *  rimGraphicsSceneRendererFlags.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 7/8/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SCENE_RENDERER_FLAGS_H
#define INCLUDE_RIM_GRAPHICS_SCENE_RENDERER_FLAGS_H


#include "rimGraphicsRenderersConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Renderers Namespace  **************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates the different boolean flags that a scene renderer can have.
/**
  * These flags provide boolean information about a certain scene renderer. Flags
  * are indicated by setting a single bit of a 32-bit unsigned integer to 1.
  *
  * Enum values for the different flags are defined as members of the class. Typically,
  * the user would bitwise-OR the flag enum values together to produce a final set
  * of set flags.
  */
class SceneRendererFlags
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Scene Renderer Flags Enum Declaration
			
			
			
			
			/// An enum which specifies the different scene renderer flags.
			typedef enum Flag
			{
				/// A flag indicating whether or not objects should be drawn.
				OBJECTS_ENABLED = (1 << 0),
				
				/// A flag indicating whether or not lighting is enabled.
				LIGHTS_ENABLED = (1 << 1),
				
				/// A flag indicating whether or not shadowing is enabled.
				SHADOWS_ENABLED = (1 << 2),
				
				/// A flag indicating whether or not debug info should be drawn for lights.
				DEBUG_LIGHTS = (1 << 3),
				
				/// A flag indicating whether or not debug info should be drawn for cameras.
				DEBUG_CAMERAS = (1 << 4),
				
				/// A flag indicating whether or not debug info should be drawn for objects.
				DEBUG_OBJECTS = (1 << 5),
				
				/// A flag indicating whether or not debug info should be drawn for shapes.
				DEBUG_SHAPES = (1 << 6),
				
				/// A flag indicating whether or not bounding boxes should be drawn.
				DEBUG_BOUNDING_BOXES = (1 << 7),
				
				/// The flag value when all flags are not set.
				UNDEFINED = 0
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new scene renderer flags object with no flags set.
			RIM_INLINE SceneRendererFlags()
				:	flags( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new scene renderer flags object with the specified flag value initially set.
			RIM_INLINE SceneRendererFlags( Flag flag )
				:	flags( flag )
			{
			}
			
			
			
			
			/// Create a new scene renderer flags object with the specified initial combined flags value.
			RIM_INLINE SceneRendererFlags( UInt32 newFlags )
				:	flags( newFlags )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Integer Cast Operator
			
			
			
			
			/// Convert this scene renderer flags object to an integer value.
			/**
			  * This operator is provided so that the SceneRendererFlags object
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
			
			
			
			
			/// A value indicating the flags that are set for a scene renderer.
			UInt32 flags;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Renderers Namespace  ****************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SCENE_RENDERER_FLAGS_H
