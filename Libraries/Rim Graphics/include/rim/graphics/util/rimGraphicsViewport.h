/*
 *  rimGraphicsViewport.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_VIEWPORT_H
#define INCLUDE_RIM_GRAPHICS_VIEWPORT_H


#include "rimGraphicsUtilitiesConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a rectangular axis-aligned portion of the screen which should be rendered to.
/**
  * During rendering, all output is rendered to only the area of the framebuffer
  * specified by the current viewport, the rest is clipped to the outer edge of the
  * viewport. This viewport is given in terms of a rectangular axis-aligned region
  * where (0,0) is the lower left corner of the framebuffer, and (1,1) is the upper-right
  * corner of the framebuffer.
  */
class Viewport
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new viewport which covers the entire framebuffer.
			RIM_INLINE Viewport()
				:	bounds( 0, 1, 0, 1 )
			{
			}
			
			
			
			
			/// Create a new viewport with the specified width and height with lower left corner at (0,0).
			RIM_INLINE Viewport( Float width, Float height )
				:	bounds( 0, width, 0, height )
			{
			}
			
			
			
			
			/// Create a new viewport which uses the area defined by the given min and max coordinates for each axis.
			RIM_INLINE Viewport( Float xMin, Float xMax, Float yMin, Float yMax )
				:	bounds( xMin, xMax, yMin, yMax )
			{
			}
			
			
			
			
			/// Create a new viewport which uses the specified minimum and maximum points to define its bounds.
			RIM_INLINE Viewport( const Vector2f& min, const Vector2f& max )
				:	bounds( min, max )
			{
			}
			
			
			
			
			/// Create a new viewport which uses the specified 2D axis-aligned box to define its bounds.
			RIM_INLINE Viewport( const AABB2f& newBounds )
				:	bounds( newBounds )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return the width of this viewport as a fraction of the framebuffer's width.
			RIM_INLINE Real getWidth() const
			{
				return bounds.getWidth();
			}
			
			
			
			
			/// Return the height of this viewport as a fraction of the framebuffer's height.
			RIM_INLINE Real getHeight() const
			{
				return bounds.getHeight();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Position Accessor Methods
			
			
			
			
			/// Return the position of this viewport's lower left corner on the framebuffer.
			RIM_INLINE Vector2f getPosition() const
			{
				return Vector2f( bounds.min.x, bounds.min.y );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Box Accessor Methods
			
			
			
			
			/// Convert this viewport to a 2D axis-aligned bounding box representing the viewport's bounds.
			RIM_INLINE operator const AABB2f& () const
			{
				return bounds;
			}
			
			
			
			
			/// Return a 2D axis-aligned bounding box representing the bounds of this viewport.
			RIM_INLINE const AABB2f& getBounds() const
			{
				return bounds;
			}
			
			
			
			
			/// Set a 2D axis-aligned bounding box representing the bounds of this viewport.
			RIM_INLINE void setBounds( const AABB2f& newBounds )
			{
				bounds = newBounds;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this viewport is exactly the same as another.
			RIM_INLINE Bool operator == ( const Viewport& other ) const
			{
				return bounds == other.bounds;
			}
			
			
			
			
			/// Return whether or not this viewport is diferent than another.
			RIM_INLINE Bool operator != ( const Viewport& other ) const
			{
				return bounds != other.bounds;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A 2D axis-aligned bounding box representing the minimum and maximum coordinates for this viewport.
			/**
			  * Coordinates are specified where (0,0) is the lower left corner of the framebuffer,
			  * and (1,1) is the upper-right corner of the framebuffer.
			  */
			AABB2f bounds;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_VIEWPORT_H
