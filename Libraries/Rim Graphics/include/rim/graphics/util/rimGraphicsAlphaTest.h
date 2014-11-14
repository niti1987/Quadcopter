/*
 *  rimGraphicsAlphaTest.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/16/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_ALPHA_TEST_H
#define INCLUDE_RIM_GRAPHICS_ALPHA_TEST_H


#include "rimGraphicsUtilitiesConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies the operation performed when testing the alpha of a fragment.
/**
  * If the alpha test succeeds, the fragment is rendered. Otherwise, the fragment
  * is discarded and rendering for the fragment stops.
  */
class AlphaTest
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Depth Test Enum Definition
			
			
			
			
			/// An enum type which represents the type of alpha test.
			typedef enum Enum
			{
				/// An alpha test where the test never succeeds (no fragments ever pass or update the framebuffer).
				NEVER = 0,
				
				
				/// An alpha test where the test always succeeds (all fragments pass and update the framebuffer).
				ALWAYS = 1,
				
				
				/// An alpha test where the test succeeds if the fragment alpha and test alpha value are equal.
				EQUAL = 2,
				
				
				/// An alpha test where the test succeeds if the fragment alpha and test alpha value are not equal.
				NOT_EQUAL = 3,
				
				
				/// An alpha test where the test succeeds if the fragment alpha is less than the test alpha.
				LESS_THAN = 4,
				
				
				/// An alpha test where the test succeeds if the fragment alpha is less than or equal to the test alpha.
				LESS_THAN_OR_EQUAL = 5,
				
				
				/// An alpha test where the test succeeds if the fragment alpha is greater than the test alpha.
				GREATER_THAN = 6,
				
				
				/// An alpha test where the test succeeds if the fragment alpha is greater than or equal to the test alpha.
				GREATER_THAN_OR_EQUAL = 7
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new alpha test with the specified alpha test enum value and test alpha value.
			RIM_INLINE AlphaTest( Enum newTest, Float newTestAlpha = Float(0) )
				:	testAlpha( newTestAlpha ),
					test( newTest )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this alpha test type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return (Enum)test;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Test Alpha Accessor Methods
			
			
			
			
			/// Return the reference alpha value with which incoming fragment alphas are compared.
			RIM_INLINE Float getTestAlpha() const
			{
				return testAlpha;
			}
			
			
			
			
			/// Set the reference alpha value with which incoming fragment alphas are compared.
			RIM_INLINE void setTestAlpha( Float newTestAlpha )
			{
				testAlpha = newTestAlpha;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a alpha test enum which corresponds to the given enum string.
			static Enum fromEnumString( const String& enumString );
			
			
			
			
			/// Return a unique string for this alpha test that matches its enum value name.
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
			
			
			
			
			/// The reference alpha value with which incoming fragment alphas are compared.
			Float testAlpha;
			
			
			
			
			/// An enum value which indicates the type of depth test.
			UByte test;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_ALPHA_TEST_H
