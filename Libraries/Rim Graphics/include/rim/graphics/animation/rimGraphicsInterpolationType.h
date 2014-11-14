/*
 *  rimGraphicsInterpolationType.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 4/20/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_INTERPOLATION_TYPE_H
#define INCLUDE_RIM_GRAPHICS_INTERPOLATION_TYPE_H


#include "rimGraphicsAnimationConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Animation Namespace  **************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that enumerates the different types of sampling interpolation.
class InterpolationType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Enum Declaration
			
			
			
			
			/// An enum type which represents the different interpolation types.
			typedef enum Enum
			{
				/// An undefined or unknown interpolation type.
				UNDEFINED = 0,
				
				/// An interpolation type where no interpolation is performed.
				/**
				  * The nearest sample value is used to determine the final interpolated value.
				  */
				NONE = 1,
				
				/// An interpolation type where basic linear interpolation is used between end points.
				LINEAR = 2,
				
				/// An interpolation type where cubic interpolation is used to interpolate between end points + control points.
				/**
				  * This type of interpolation requires an additional control point for each end point
				  * that determines the shape of the curve.
				  */
				BEZIER = 3,
				
				/// An interpolation type where cubic interpolation is used to interpolate between end points + tangents.
				/**
				  * This type of interpolation requires an additional tangent values for each end point
				  * that determines the shape of the curve.
				  */
				HERMITE = 4,
				
				/// An interpolation type which only guarantees to go through the start and end points, but not necessarily the middle ones.
				B_SPLINE = 5,
				
				/// An interpolation type which uses a sinc low-pass filter to interpolate control points.
				SINC = 6,
				
				/// An interpolation type which uses spherical linear interpolation for correct rotation interpolation.
				/**
				  * This animation type is only valid for quaternion attribute types (4-component vectors).
				  */
				SLERP = 7
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new interpolation type with the UNDEFINED enum value.
			RIM_INLINE InterpolationType()
				:	type( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new interpolation type with the specified interpolation type enum value.
			RIM_INLINE InterpolationType( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this interpolation type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a unique string for this interpolation type that matches its enum value name.
			String toEnumString() const;
			
			
			
			
			/// Return an interpolation type which corresponds to the given enum string.
			static InterpolationType fromEnumString( const String& enumString );
			
			
			
			
			/// Return a string representation of the interpolation type.
			String toString() const;
			
			
			
			
			/// Convert this interpolation type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum representing the interpolation type.
			Enum type;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Animation Namespace  ****************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_INTERPOLATION_TYPE_H
