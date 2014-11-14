/*
 *  rimGraphicsDepthTest.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/13/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_DEPTH_TEST_H
#define INCLUDE_RIM_GRAPHICS_DEPTH_TEST_H


#include "rimGraphicsUtilitiesConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies the operation performed when testing a new depth fragment.
/**
  * If the depth test succeeds, the fragment is rendered. Otherwise, the fragment
  * is discarded and rendering for the fragment stops.
  */
class DepthTest
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Depth Test Enum Definition
			
			
			
			
			/// An enum type which represents the type of depth test.
			typedef enum Enum
			{
				/// A depth test where the test never succeeds (no fragments ever pass or update the depth buffer).
				NEVER = 0,
				
				
				/// A depth test where the test always succeeds (all fragments pass and update the depth buffer).
				ALWAYS = 1,
				
				
				/// A depth test where the test succeeds if the source and destination depths are equal.
				EQUAL = 2,
				
				
				/// A depth test where the test succeeds if the source and destination depths are not equal.
				NOT_EQUAL = 3,
				
				
				/// A depth test where the test succeeds if the new depth is less than the existing depth.
				LESS_THAN = 4,
				
				
				/// A depth test where the test succeeds if the new depth is less than or equal to the existing depth.
				LESS_THAN_OR_EQUAL = 5,
				
				
				/// A depth test where the test succeeds if the new depth is greater than the existing depth.
				GREATER_THAN = 6,
				
				
				/// A depth test where the test succeeds if the new depth is greater than or equal to the existing depth.
				GREATER_THAN_OR_EQUAL = 7
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new depth test with the specified depth test enum value.
			RIM_INLINE DepthTest( Enum newTest )
				:	test( newTest )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this depth test type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return (Enum)test;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a depth test enum which corresponds to the given enum string.
			static DepthTest fromEnumString( const String& enumString );
			
			
			
			
			/// Return a unique string for this depth test that matches its enum value name.
			String toEnumString() const;
			
			
			
			
			/// Return a string representation of the depth test.
			String toString() const;
			
			
			
			
			/// Convert this depth test into a string representation.
			RIM_FORCE_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value which indicates the type of depth test.
			UByte test;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_DEPTH_TEST_H
