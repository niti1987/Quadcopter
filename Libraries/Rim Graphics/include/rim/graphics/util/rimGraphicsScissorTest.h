/*
 *  rimGraphicsScissorTest.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/17/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SCISSOR_TEST_H
#define INCLUDE_RIM_GRAPHICS_SCISSOR_TEST_H


#include "rimGraphicsUtilitiesConfig.h"


#include "rimGraphicsViewport.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies the configuration of the scissor test clipping pipeline.
/**
  * A scissor test is defined by a rectangular region of the screen where rendering
  * should occur, excluding all other areas. Incoming primitives are clipped to the
  * region.
  */
class ScissorTest
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default stencil test with an empty viewport and disabled status.
			RIM_INLINE ScissorTest()
				:	viewport(),
					enabled( false )
			{
			}
			
			
			
			
			/// Create a new scissor test with the specified viewport and enable status.
			RIM_INLINE ScissorTest( const Viewport& newViewport, Bool newIsEnabled = true )
				:	viewport( newViewport ),
					enabled( newIsEnabled )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Viewport Accessor Methods
			
			
			
			
			/// Return a reference to the viewport which this scissor test is clipping geometry to.
			RIM_INLINE const Viewport& getViewport() const
			{
				return viewport;
			}
			
			
			
			
			/// Set the viewport which this scissor test is clipping geometry to.
			RIM_INLINE void setViewport( const Viewport& newViewport )
			{
				viewport = newViewport;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Scissor Test Enable Status
			
			
			
			
			/// Return whether or not the scissor test is enabled.
			RIM_INLINE Bool getIsEnabled() const
			{
				return enabled;
			}
			
			
			
			
			/// SEt whether or not the scissor test is enabled.
			RIM_INLINE void setIsEnabled( Bool newIsEnabled )
			{
				enabled = newIsEnabled;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The viewport which is being clipped to by the scissor test.
			Viewport viewport;
			
			
			
			
			/// A boolean value indicating whether or not the scissor test is enabled.
			Bool enabled;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SCISSOR_TEST_H
