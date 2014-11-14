/*
 *  rimTransformableAnimationTarget.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 7/1/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_TRANSFORMABLE_ANIMATION_TARGET_H
#define INCLUDE_RIM_GRAPHICS_TRANSFORMABLE_ANIMATION_TARGET_H


#include "rimGraphicsAnimationConfig.h"


#include "rimGraphicsAnimationTarget.h"
#include "rimGraphicsAnimationTrackUsage.h"


//##########################################################################################
//**********************  Start Rim Graphics Animation Namespace  **************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that controls a transformable object via animation input data.
class TransformableAnimationTarget : public AnimationTarget
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new object animation target for the specified graphics object and usage.
			/**
			  * The animation target will only function properly if the object and usage are
			  * compatible.
			  */
			TransformableAnimationTarget( const Pointer<Transformable>& newObject,
											const AnimationTrackUsage& newUsage );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Target Methods
			
			
			
			
			/// Return whether or not this target is the same as another.
			virtual Bool operator == ( const AnimationTarget& other ) const;
			
			
			
			
			/// Return whether or not the specified attribute type is compatible with this animation target.
			virtual Bool isValidType( const AttributeType& type ) const;
			
			
			
			
			// Set the target to have the given value.
			virtual Bool setValue( const AttributeValue& value );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < typename T >
			RIM_FORCE_INLINE static T convertValue( const AttributeValue& value );
			
			
			
			
			static Bool convertComponents( const UByte* componentData, const AttributeType& type, Real* output );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the graphics object that is being animated.
			Pointer<Transformable> object;
			
			
			
			
			/// An object that determines the object attribute that is animated.
			AnimationTrackUsage usage;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Animation Namespace  ****************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_TRANSFORMABLE_ANIMATION_TARGET_H
