/*
 *  rimGUIDisplayMode.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 9/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_DISPLAY_MODE_H
#define INCLUDE_RIM_GUI_DISPLAY_MODE_H


#include "rimGUISystemConfig.h"


//##########################################################################################
//************************     Start Rim GUI System Namespace     **************************
RIM_GUI_SYSTEM_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates a single possible configuration for a system video display.
/**
  * A display mode configuration contains information related to a particular
  * mode of operation for a physical video display. This information includes the 
  * size of the display in pixels (width and height), the refresh rate, and the
  * pixel type (color depth) for the display.
  */
class DisplayMode
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default display mode with (0,0) size and 0 refresh rate.
			RIM_INLINE DisplayMode()
				:	size( 0, 0 ),
					refreshRate( 0 ),
					bitsPerPixel( 0 )
			{
			}
			
			
			
			
			/// Create a new display mode object with the specified size, refresh rate, and bits per pixel.
			RIM_INLINE DisplayMode( const Size2D& newSize, Double newRefreshRate, Size newBitsPerPixel )
				:	size( newSize ),
					refreshRate( newRefreshRate ),
					bitsPerPixel( newBitsPerPixel )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return the horizontal size of this display mode in pixels.
			RIM_INLINE Size getWidth() const
			{
				return size.x;
			}
			
			
			
			
			/// Return the vertical size of this display mode in pixels.
			RIM_INLINE Size getHeight() const
			{
				return size.y;
			}
			
			
			
			
			/// Return a 2D vector representing the horizontal and vertical size of this display mode in pixels.
			RIM_INLINE Size2D getSize() const
			{
				return size;
			}
			
			
			
			
			/// Set the horizontal size of this display mode in pixels.
			RIM_INLINE void setWidth( Size width )
			{
				size.x = width;
			}
			
			
			
			
			/// Set the vertical size of this display mode in pixels.
			RIM_INLINE void setHeight( Size height )
			{
				size.y = height;
			}
			
			
			
			
			/// Set the horizontal and vertical size of this display mode in pixels.
			RIM_INLINE void setSize( Size width, Size height )
			{
				size.x = width;
				size.y = height;
			}
			
			
			
			
			/// Set the horizontal and vertical size of this display mode in pixels.
			RIM_INLINE void setSize( const Size2D& newSize )
			{
				size = newSize;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Refresh Rate Accessor Methods
			
			
			
			
			/// Return the refresh rate of this display mode in cycles per second (hertz).
			RIM_INLINE Double getRefreshRate() const
			{
				return refreshRate;
			}
			
			
			
			
			/// Set the refresh rate of this display mode in cycles per second (hertz).
			/**
			  * The new refresh rate is clamped to the range of [0,+infinity].
			  */
			RIM_INLINE void setRefreshRate( Double newRefreshRate )
			{
				refreshRate = math::max( newRefreshRate, Double(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bits Per Pixel Accessor Methods
			
			
			
			
			/// Return the number of bits used to represent each pixel of this display mode.
			RIM_INLINE Size getBitsPerPixel() const
			{
				return bitsPerPixel;
			}
			
			
			
			
			/// Set the number of bits used to represent each pixel of this display mode.
			RIM_INLINE void setBitsPerPixel( Size newBitsPerPixel )
			{
				bitsPerPixel = newBitsPerPixel;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this display mode is equivalent to another.
			RIM_INLINE Bool operator == ( const DisplayMode& other ) const
			{
				return size == other.size && refreshRate == other.refreshRate &&
						bitsPerPixel == other.bitsPerPixel;
			}
			
			
			
			
			/// Return whether or not this display mode is not equivalent to another.
			RIM_INLINE Bool operator != ( const DisplayMode& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The horizontal and vertical size of this display mode in pixels.
			Size2D size;
			
			
			
			
			/// The vertical refresh rate of this display mode in hertz.
			Double refreshRate;
			
			
			
			
			/// The number of bits per pixel of this display mode.
			Size bitsPerPixel;
			
			
			
};




//##########################################################################################
//************************     End Rim GUI System Namespace     ****************************
RIM_GUI_SYSTEM_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_DISPLAY_MODE_H
