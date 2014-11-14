/*
 *  rimGraphicsAnimationTrackUsage.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/24/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_ANIMATION_TRACK_USAGE_H
#define INCLUDE_RIM_GRAPHICS_ANIMATION_TRACK_USAGE_H


#include "rimGraphicsAnimationConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Animation Namespace  **************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that enumerates the different standard usages for an animation track.
class AnimationTrackUsage
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Enum Declaration
			
			
			
			
			/// An enum type which represents the different animation track usages.
			typedef enum Enum
			{
				/// An animation track with undefined usage.
				UNDEFINED = 0,
				
				/// An animation track that is used to determine the position of its target.
				/**
				  * The position is usually a 3 or 2-component vector.
				  */
				POSITION,
				
				/// An animation track that is used to determine the scalar X-coordinate position of its target.
				POSITION_X,
				
				/// An animation track that is used to determine the scalar Y-coordinate position of its target.
				POSITION_Y,
				
				/// An animation track that is used to determine the scalar Z-coordinate position of its target.
				POSITION_Z,
				
				/// An animation track that is used to determine the orientation of its target.
				/**
				  * The orientation can be represented by either a 3x3 matrix or a 4-component quaternion.
				  */
				ORIENTATION,
				
				/// An animation track that is used to determine the rotation around the X-axis of the target.
				ROTATION_X,
				
				/// An animation track that is used to determine the rotation around the Y-axis of the target.
				ROTATION_Y,
				
				/// An animation track that is used to determine the rotation around the Z-axis of the target.
				ROTATION_Z,
				
				/// An animation track that is used to determine the global scale factor of its target.
				/**
				  * The scale can be represented by either a vector (indicating the scale along each axis),
				  * or as a scalar, indicating the scaling for all axes.
				  */
				SCALE,
				
				/// An animation track that is used to determine the X-coordinate scale of its target.
				SCALE_X,
				
				/// An animation track that is used to determine the Y-coordinate scale of its target.
				SCALE_Y,
				
				/// An animation track that is used to determine the Z-coordinate scale of its target.
				SCALE_Z,
				
				/// An animation track that is used to determine the color of its target.
				COLOR,
				
				/// An animation track that is used to determine the diffuse color of its target.
				DIFFUSE_COLOR,
				
				/// An animation track that is used to determine the ambient color of its target.
				AMBIENT_COLOR,
				
				/// An animation track that is used to determine the specular color of its target.
				SPECULAR_COLOR
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new animation usage with the UNDEFINED usage enum value.
			RIM_INLINE AnimationTrackUsage()
				:	usage( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new animation usage with the specified animation usage enum value.
			RIM_INLINE AnimationTrackUsage( Enum newUsage )
				:	usage( newUsage )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this animation usage type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return usage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a unique string for this track usage that matches its enum value name.
			String toEnumString() const;
			
			
			
			
			/// Return a track usage which corresponds to the given enum string.
			static AnimationTrackUsage fromEnumString( const String& enumString );
			
			
			
			
			/// Return a string representation of the animation usage.
			String toString() const;
			
			
			
			
			/// Convert this animation usage into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum representing the animation usage.
			Enum usage;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Animation Namespace  ****************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_ANIMATION_TRACK_USAGE_H
