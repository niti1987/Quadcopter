/*
 *  rimGraphicsDepthMode.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/13/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_DEPTH_MODE_H
#define INCLUDE_RIM_GRAPHICS_DEPTH_MODE_H


#include "rimGraphicsUtilitiesConfig.h"


#include "rimGraphicsDepthTest.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies how the depth buffer should be updated.
class DepthMode
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new depth mode with the default depth test parameters.
			/**
			  * The default depth test is LESS_THAN_OR_EQUAL and the default depth
			  * range is [0,1].
			  */
			RIM_INLINE DepthMode()
				:	test( DepthTest::LESS_THAN ),
					range( 0, 1 )
			{
			}
			
			
			
			
			/// Create a new depth mode with the given depth test and default range of [0,1].
			RIM_INLINE DepthMode( DepthTest newTest )
				:	test( newTest ),
					range( 0, 1 )
			{
			}
			
			
			
			
			/// Create a new depth mode with the given depth test and range.
			RIM_INLINE DepthMode( DepthTest newTest, const AABB1f& newRange )
				:	test( newTest ),
					range( newRange )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Blend Function Accessor Methods
			
			
			
			
			/// Return an object which describes the depth test used by this depth mode.
			RIM_INLINE const DepthTest& getTest() const
			{
				return test;
			}
			
			
			
			
			/// Set the depth test used by this depth mode.
			RIM_INLINE void setTest( const DepthTest& newTest )
			{
				test = newTest;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constant Color Accessor Methods
			
			
			
			
			/// Return the output range of depth values which should be written to the depth buffer.
			/**
			  * The range of this value should lie within the range [0,1]. This specifies
			  * the range which normalized device coordiantes from [-1,1] should be mapped
			  * to before depth values are written to the depth buffer. For instance, a range of
			  * [0,0.5] means that depth values are in that range and only half of the depth
			  * buffer's precision is used.
			  */
			RIM_INLINE const AABB1f& getRange() const
			{
				return range;
			}
			
			
			
			
			/// Set the output range of depth values which should be written to the depth buffer.
			/**
			  * The range of this value should lie within the range [0,1]. This specifies
			  * the range which normalized device coordiantes from [-1,1] should be mapped
			  * to before depth values are written to the depth buffer. For instance, a range of
			  * [0,0.5] means that depth values are in that range and only half of the depth
			  * buffer's precision is used.
			  */
			RIM_INLINE void setRange( const AABB1f& newDepthRange )
			{
				range = newDepthRange;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this depth mode is equal to another depth mode.
			RIM_INLINE Bool operator == ( const DepthMode& other ) const
			{
				return test == other.test && range == other.range;
			}
			
			
			
			
			/// Return whether or not this depth mode is not equal to another depth mode.
			RIM_INLINE Bool operator != ( const DepthMode& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object which describes the test performed on new fragment when comparing it to the depth buffer.
			DepthTest test;
			
			
			
			
			/// The output range of depth values which should be written to the depth buffer.
			/**
			  * The range of this value should lie within the range [0,1]. This specifies
			  * the range which normalized device coordiantes from [-1,1] should be mapped
			  * to before depth values are written to the depth buffer. For instance, a range of
			  * [0,0.5] means that depth values are in that range and only half of the depth
			  * buffer's precision is used.
			  */
			AABB1f range;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_DEPTH_MODE_H
