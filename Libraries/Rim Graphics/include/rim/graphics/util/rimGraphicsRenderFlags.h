/*
 *  rimGraphicsRenderFlags.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/14/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_RENDER_FLAGS_H
#define INCLUDE_RIM_GRAPHICS_RENDER_FLAGS_H


#include "rimGraphicsUtilitiesConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates different boolean parameters that a RenderState has.
/**
  * These flags provide boolean information about a rendering state. Flags
  * are indicated by setting a single bit of a 32-bit unsigned integer to 1.
  *
  * Enum values for the different flags are defined as members of the class. Typically,
  * the user would bitwise-OR the flag enum values together to produce a final set
  * of set flags.
  */
class RenderFlags
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Graphics Context Flags Enum Declaration
			
			
			
			
			/// An enum which specifies the different render flags.
			typedef enum Flag
			{
				/// The flag value when all flags are not set.
				UNDEFINED = 0,
				
				/// A flag indicating that color writing to red channel is enabled.
				RED_WRITE = 1,
				
				/// A flag indicating that color writing to green channel is enabled.
				GREEN_WRITE = 1 << 1,
				
				/// A flag indicating that color writing to blue channel is enabled.
				BLUE_WRITE = 1 << 2,
				
				/// A flag indicating that color writing to alpha channel is enabled.
				ALPHA_WRITE = 1 << 3,
				
				/// A flag indicating that color writing to all channels is enabled.
				COLOR_WRITE = RED_WRITE | GREEN_WRITE | BLUE_WRITE | ALPHA_WRITE,
				
				/// A flag indicating that depth buffer writing is enabled.
				DEPTH_WRITE = 1 << 4,
				
				/// A flag indicating that the depth test should be performed and depth buffer updated.
				DEPTH_TEST = 1 << 5,
				
				/// A flag indicating that the stencil test should be performed and stencil buffer updated.
				STENCIL_TEST = 1 << 6,
				
				/// A flag indicating that the alpha test should be performed.
				ALPHA_TEST = 1 << 7,
				
				/// A flag indicating that blending should be performed.
				BLENDING = 1 << 8,
				
				/// A flag indicating that the shader needs to be drawn in back-to-front order.
				TRANSPARENCY_DEPTH_SORT = 1 << 9,
				
				/// A flag indicating that back-face culling should be performed.
				/**
				  * If a face's normal points away from the camera, it is not drawn
				  * if this flag is set.
				  */
				BACK_FACE_CULLING = 1 << 10,
				
				/// A flag indicating that front-face culling should be performed.
				/**
				  * If a face's normal points toward the camera, it is not drawn
				  * if this flag is set.
				  */
				FRONT_FACE_CULLING = 1 << 11,
				
				/// A flag that indicates that slope-scaled depth biasing should be applied.
				SLOPE_SCALED_DEPTH_BIAS = 1 << 12,
				
				/// A flag that indicates that the color values written to the framebuffer are in linear space and should have gamma applied.
				/**
				  * This means that color values are raised to the power of (1/2.2) in order to convert
				  * them from a linear to sRGB color space for correct monitor output. In order for
				  * this rendering to look correct, textures must be supplied in the correct
				  * color space for the shader (usually linear).
				  */
				GAMMA_CORRECTION = 1 << 13
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new render flags object with no flags set.
			RIM_INLINE RenderFlags()
				:	flags( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new render flags object with the specified flag value initially set.
			RIM_INLINE RenderFlags( Flag flag )
				:	flags( flag )
			{
			}
			
			
			
			
			/// Create a new render flags object with the specified initial combined flags value.
			RIM_INLINE RenderFlags( UInt32 newFlags )
				:	flags( newFlags )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Integer Cast Operator
			
			
			
			
			/// Convert this render flags object to an integer value.
			/**
			  * This operator is provided so that the RenderFlags object
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
			RIM_INLINE void set( Flag flag, Bool newIsSet = true )
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
			
			
			
			
			/// A value indicating the flags that are set for a the rendering state.
			UInt32 flags;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_RENDER_FLAGS_H
