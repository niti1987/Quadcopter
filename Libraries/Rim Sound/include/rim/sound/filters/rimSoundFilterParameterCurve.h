/*
 *  rimSoundFilterParameterCurve.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 8/4/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_FILTER_PARAMETER_CURVE_H
#define INCLUDE_RIM_SOUND_FILTER_PARAMETER_CURVE_H


#include "rimSoundFiltersConfig.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the scaling curve to use when displaying a SoundFilter parameter.
/**
  * This class allows the user to specify how to display slider values, graphs, etc.
  * Certain types of data are better visualized with a log scale, for instance.
  */
class FilterParameterCurve
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parameter Type Enum Declaration
			
			
			
			
			/// An enum which specifies the different kinds of scaling curves.
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
			
			
			
			
			/// Create a new filter parameter curve object with the LINEAR parameter curve.
			RIM_INLINE FilterParameterCurve()
				:	curve( (UByte)LINEAR )
			{
			}
			
			
			
			
			/// Create a new filter parameter curve object with the specified units enum value.
			RIM_INLINE FilterParameterCurve( Enum newCurve )
				:	curve( (UByte)newCurve )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this filter parameter curve type to an enum value.
			/**
			  * This operator is provided so that the FilterParameterCurve object can be used
			  * directly in a switch statement without the need to explicitly access
			  * the underlying enum value.
			  * 
			  * @return the enum representation of this parameter curve type.
			  */
			RIM_INLINE operator Enum () const
			{
				return (Enum)curve;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the parameter curve type.
			UTF8String toString() const;
			
			
			
			
			/// Convert this parameter curve type into a string representation.
			RIM_INLINE operator UTF8String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value indicating the scaling curve type of a SoundFilter parameter.
			UByte curve;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_FILTER_PARAMETER_CURVE_H
