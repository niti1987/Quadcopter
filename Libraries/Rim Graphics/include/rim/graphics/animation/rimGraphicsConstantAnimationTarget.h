/*
 *  rimGraphicsConstantAnimationTarget.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/28/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_CONSTANT_ANIMATION_TARGET_H
#define INCLUDE_RIM_GRAPHICS_CONSTANT_ANIMATION_TARGET_H


#include "rimGraphicsAnimationConfig.h"


#include "rimGraphicsAnimationTarget.h"


//##########################################################################################
//**********************  Start Rim Graphics Animation Namespace  **************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that controls a shader pass constant value via animation input data.
class ConstantAnimationTarget : public AnimationTarget
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new constant animation target for the specified shader pass and constant index.
			ConstantAnimationTarget( const Pointer<ShaderPass>& newShaderPass, Index constantIndex );
			
			
			
			
			/// Create a new constant animation target for the specified shader pass and constant usage.
			/**
			  * This constructor finds the index of the constant binding in the shader pass with the
			  * specified usage and uses that as the animation target.
			  */
			ConstantAnimationTarget( const Pointer<ShaderPass>& newShaderPass, const ConstantUsage& usage );
			
			
			
			
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
		//******	Private Data Members
			
			
			
			
			/// A pointer to the shader pass that is being animated.
			Pointer<ShaderPass> shaderPass;
			
			
			
			
			/// The index of the constant that should be controlled by this target.
			Index constantIndex;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Animation Namespace  ****************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_CONSTANT_ANIMATION_TARGET_H
