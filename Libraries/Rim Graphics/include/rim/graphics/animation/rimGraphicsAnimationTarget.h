/*
 *  rimGraphicsAnimationTarget.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/24/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_ANIMATION_TARGET_H
#define INCLUDE_RIM_GRAPHICS_ANIMATION_TARGET_H


#include "rimGraphicsAnimationConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Animation Namespace  **************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that serves as an interface for targets of interpolated animation data.
class AnimationTarget
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this animation target.
			virtual ~AnimationTarget()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Target Methods
			
			
			
			
			/// Return whether or not this target is the same as another.
			virtual Bool operator == ( const AnimationTarget& other ) const = 0;
			
			
			
			
			/// Return whether or not the specified attribute type is compatible with this animation target.
			virtual Bool isValidType( const AttributeType& type ) const = 0;
			
			
			
			
			// Set the target to have the given value.
			virtual Bool setValue( const AttributeValue& value ) = 0;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Animation Namespace  ****************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_ANIMATION_TARGET_H
