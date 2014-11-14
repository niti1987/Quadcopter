/*
 *  rimGraphicsStencilMode.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/13/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_STENCIL_MODE_H
#define INCLUDE_RIM_GRAPHICS_STENCIL_MODE_H


#include "rimGraphicsUtilitiesConfig.h"


#include "rimGraphicsStencilTest.h"
#include "rimGraphicsStencilAction.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




/// A type which represents a value stored in a stencil buffer.
typedef UInt StencilValue;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies how the stencil buffer should be updated.
class StencilMode
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new stencil mode with the default stencil test parameters.
			RIM_INLINE StencilMode()
				:	test( StencilTest::ALWAYS ),
					stencilFailAction( StencilAction::KEEP ),
					stencilPassDepthFailAction( StencilAction::KEEP ),
					stencilPassAction( StencilAction::KEEP ),
					mask( StencilValue(0xFFFFFFFF) ),
					value( 0 )
			{
			}
			
			
			
			
			/// Create a new depth mode with the specified test and action parameters.
			RIM_INLINE StencilMode( StencilTest newTest, StencilAction stencilFail,
									StencilAction stencilPassDepthFail, StencilAction stencilPass )
				:	test( newTest ),
					stencilFailAction( stencilFail ),
					stencilPassDepthFailAction( stencilPassDepthFail ),
					stencilPassAction( stencilPass ),
					mask( StencilValue(0xFFFFFFFF) ),
					value( 0 )
			{
			}
			
			
			
			
			/// Create a new depth mode with the specified test and action parameters.
			RIM_INLINE StencilMode( StencilTest newTest, StencilAction stencilFail,
									StencilAction stencilPassDepthFail, StencilAction stencilPass,
									StencilValue newMask = StencilValue(0xFFFFFFFF), StencilValue newValue = 0 )
				:	test( newTest ),
					stencilFailAction( stencilFail ),
					stencilPassDepthFailAction( stencilPassDepthFail ),
					stencilPassAction( stencilPass ),
					mask( newMask ),
					value( newValue )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stencil Test Accessor Methods
			
			
			
			
			/// Return an object which describes the stencil test used by this stencil mode.
			RIM_INLINE const StencilTest& getTest() const
			{
				return test;
			}
			
			
			
			
			/// Set the stencil test used by this stencil mode.
			RIM_INLINE void setTest( const StencilTest& newTest )
			{
				test = newTest;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stencil Test Pass Action Accessor Methods
			
			
			
			
			/// Return an object which describes the stencil action taken when the stencil test passes.
			RIM_INLINE const StencilAction& getPassAction() const
			{
				return stencilPassAction;
			}
			
			
			
			
			/// Set an object which describes the stencil action taken when the stencil test passes.
			RIM_INLINE void setPassAction( const StencilAction& newPassAction )
			{
				stencilPassAction = newPassAction;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stencil Test Pass Depth Fail Action Accessor Methods
			
			
			
			
			/// Return an object which describes the stencil action taken when the stencil test passes but depth fails.
			RIM_INLINE const StencilAction& getPassDepthFailAction() const
			{
				return stencilPassDepthFailAction;
			}
			
			
			
			
			/// Set an object which describes the stencil action taken when the stencil test passes but depth fails.
			RIM_INLINE void setPassDepthFailAction( const StencilAction& newPassDepthFailAction )
			{
				stencilPassDepthFailAction = newPassDepthFailAction;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stencil Test Fail Action Accessor Methods
			
			
			
			
			/// Return an object which describes the stencil action taken when the stencil test fails.
			RIM_INLINE const StencilAction& getFailAction() const
			{
				return stencilFailAction;
			}
			
			
			
			
			/// Set an object which describes the stencil action taken when the stencil test fails.
			RIM_INLINE void setFailAction( const StencilAction& newFailAction )
			{
				stencilFailAction = newFailAction;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stencil Mask Accessor Methods
			
			
			
			
			/// Return a bitwise stencil value mask which is used to determine which bits of the stencil buffer to update.
			/**
			  * If a bit in the mask is set to 1, that bit of the stencil
			  * buffer will be updated. Otherwise, the buffer is not updated for
			  * that bit.
			  */
			RIM_INLINE StencilValue getMask() const
			{
				return mask;
			}
			
			
			
			
			/// Set a bitwise stencil value mask which is used to determine which bits of the stencil buffer to update.
			/**
			  * If a bit in the mask is set to 1, that bit of the stencil
			  * buffer will be updated. Otherwise, the buffer is not updated for
			  * that bit.
			  */
			RIM_INLINE void setMask( StencilValue newMask )
			{
				mask = newMask;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stencil Constant Value Accessor Methods
			
			
			
			
			/// Return a constant stencil value which may be used by some stencil actions.
			RIM_INLINE StencilValue getValue() const
			{
				return value;
			}
			
			
			
			
			/// Set a constant stencil value which may be used by some stencil actions.
			RIM_INLINE void setValue( StencilValue newValue )
			{
				value = newValue;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this stencil mode is equal to another stencil mode.
			RIM_INLINE Bool operator == ( const StencilMode& other ) const
			{
				return test == other.test &&
						stencilFailAction == other.stencilFailAction &&
						stencilPassDepthFailAction == other.stencilPassDepthFailAction &&
						stencilPassAction == other.stencilPassAction &&
						mask == other.mask &&
						value == other.value;
			}
			
			
			
			
			/// Return whether or not this stencil mode is not equal to another stencil mode.
			RIM_INLINE Bool operator != ( const StencilMode& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object which describes the stencil test which should be performed by this mode.
			StencilTest test;
			
			
			
			
			/// An object which describes the stencil action to take when the stencil test fails.
			StencilAction stencilFailAction;
			
			
			
			
			/// An object which describes the stencil action to take when the stencil test pass but depth test fails.
			StencilAction stencilPassDepthFailAction;
			
			
			
			
			/// An object which describes the stencil action to take when the stencil test passes.
			StencilAction stencilPassAction;
			
			
			
			
			/// A bitwise stencil value mask which is used to determine which bits of the stencil buffer to update.
			/**
			  * If a bit in the mask is set to 1, that bit of the stencil
			  * buffer will be updated. Otherwise, the buffer is not updated for
			  * that bit.
			  */
			StencilValue mask;
			
			
			
			
			/// A constant stencil value which may be used by some stencil actions.
			StencilValue value;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_STENCIL_MODE_H
