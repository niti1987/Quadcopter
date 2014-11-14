/*
 *  rimGraphicsStencilTest.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/13/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_STENCIL_TEST_H
#define INCLUDE_RIM_GRAPHICS_STENCIL_TEST_H


#include "rimGraphicsUtilitiesConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies the operation performed when testing a new stencil fragment.
/**
  * If the stencil test succeeds, the fragment is rendered. Otherwise, the fragment
  * is discarded and rendering for the fragment stops.
  */
class StencilTest
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stencil Test Enum Definition
			
			
			
			
			/// An enum type which represents the type of stencil test.
			typedef enum Enum
			{
				/// A test where the test never succeeds (no fragments ever pass or update the stencil buffer).
				NEVER = 0,
				
				
				/// A test where the test always succeeds (all fragments pass and update the stencil buffer).
				ALWAYS = 1,
				
				
				/// A test where the test succeeds if the source and destination stencils are equal.
				EQUAL = 2,
				
				
				/// A test where the test succeeds if the source and destination stencils are not equal.
				NOT_EQUAL = 3,
				
				
				/// A test where the test succeeds if the new stencil value is less than the existing stencil value.
				LESS_THAN = 4,
				
				
				/// A test where it succeeds if the new stencil value is less than or equal to the existing stencil value.
				LESS_THAN_OR_EQUAL = 5,
				
				
				/// A test where the test succeeds if the new stencil value is greater than the existing stencil value.
				GREATER_THAN = 6,
				
				
				/// A test where it succeeds if the new stencil value is greater than or equal to the existing stencil value.
				GREATER_THAN_OR_EQUAL = 7
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new stencil test with the specified stencil test enum value.
			RIM_INLINE StencilTest( Enum newTest )
				:	test( newTest )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this stencil test type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return (Enum)test;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a stencil test enum which corresponds to the given enum string.
			static StencilTest fromEnumString( const String& enumString );
			
			
			
			
			/// Return a unique string for this stencil test that matches its enum value name.
			String toEnumString() const;
			
			
			
			
			/// Return a string representation of the stencil test.
			String toString() const;
			
			
			
			
			/// Convert this stencil test into a string representation.
			RIM_FORCE_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value which indicates the type of stencil test.
			UByte test;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_STENCIL_TEST_H
