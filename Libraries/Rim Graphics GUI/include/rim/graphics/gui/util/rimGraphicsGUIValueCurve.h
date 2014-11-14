/*
 *  rimGraphicsGUIValueCurve.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 7/9/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_VALUE_CURVE_H
#define INCLUDE_RIM_GRAPHICS_GUI_VALUE_CURVE_H


#include "rimGraphicsGUIUtilitiesConfig.h"


//##########################################################################################
//*******************  Start Rim Graphics GUI Utilities Namespace  *************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the scaling curve to use when displaying a value.
/**
  * This class allows the user to specify how to display slider values, graphs, etc.
  * Certain types of data are better visualized with a log scale, for instance.
  */
class ValueCurve
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Enum Declaration
			
			
			
			
			/// An enum which specifies the different kinds of curves.
			typedef enum Enum
			{
				/// The values are spaced evenly in a linear fashion.
				LINEAR = 0,
				
				/// The value are spaced logarithmically along the number line from the minimum to maximum value.
				LOGARITHMIC = 1,
				
				/// The values are spaced using the function x^2.
				SQUARE = 2,
				
				/// The values are spaced using the function sqrt(x). 
				SQUARE_ROOT = 3,
				
				/// The values are spaced using the function x^3.
				CUBE = 4,
				
				/// The values are spaced using the function x^(1/3).
				CUBE_ROOT = 5
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new value curve with the default curve - linear.
			RIM_INLINE ValueCurve()
				:	type( LINEAR )
			{
			}
			
			
			
			
			/// Create a new value curve using the specified value curve type enum value.
			RIM_INLINE ValueCurve( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this value curve type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Curve Evalutation Method
			
			
			
			
			/// Apply this curve to a value with the specified linear parameter from 0 to 1 and output range.
			/**
			  * This method takes a parameter which ranges from 0 to 1, indicating the linear
			  * range of the value. It applies the transfer function of this curve to that
			  * parameter and returns the result, adjusted to lie within the specified value output
			  * range. The result indicates the actual parameter value that should be displayed
			  * at the original linear position.
			  *
			  * Use this method to convert from a display location to the actual value at the
			  * display location.
			  */
			Float evaluate( Float a, const AABB1f& range = AABB1f(0,1) ) const;
			
			
			
			
			/// Apply this curve to a value in reverse with the specified value and input range.
			/**
			  * This method takes a parameter which ranges from its minimum to maximum value
			  * and undoes the value curve, producing a linear parameter value which ranges from
			  * 0 to 1.
			  *
			  * Use this method to convert from actual values to where they should be
			  * displayed.
			  */
			Float evaluateInverse( Float value, const AABB1f& range = AABB1f(0,1) ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the value curve type.
			String toString() const;
			
			
			
			
			/// Convert this value curve type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Data Transformation Method
			
			
			
			
			/// Transform a 1D value in the given range by the specified value curve.
			static Float transform( Float value, const AABB1f& range,
									ValueCurve curve );
			
			
			
			
			/// Transform a 2D value in the given range by the specified value curve.
			static Vector2f transform( const Vector2f& value, const AABB2f& range,
										ValueCurve xCurve, ValueCurve yCurve );
			
			
			
			
			/// Transform a 3D value in the given range by the specified value curve.
			static Vector3f transform( const Vector3f& value, const AABB3f& range,
										ValueCurve xCurve, ValueCurve yCurve, ValueCurve zCurve );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value indicating the type of value curve this object represents.
			Enum type;
			
			
			
};




//##########################################################################################
//*******************  End Rim Graphics GUI Utilities Namespace  ***************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_VALUE_CURVE_H
