/*
 *  rimGraphicsGUIImage.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 3/31/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_IMAGE_H
#define INCLUDE_RIM_GRAPHICS_GUI_IMAGE_H


#include "rimGraphicsGUIUtilitiesConfig.h"


//##########################################################################################
//*******************  Start Rim Graphics GUI Utilities Namespace  *************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Direction;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a rectangular region containing an image drawn by an arbitrary process.
/**
  * This abstraction allows GUIs to use pixel-based or vector-based images
  * in a uniform manner.
  */
class GUIImage
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new GUI image with a width and height of 0.
			RIM_INLINE GUIImage()
				:	size()
			{
			}
			
			
			
			
			/// Create a new GUI image with the specified displayed size in pixels.
			RIM_INLINE GUIImage( const Vector2f& newSize )
				:	size( newSize )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this GUI image, releasing all internal state.
			virtual ~GUIImage()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return a 2D vector representing the displayed size of this image in pixels.
			/**
			  * This is the final size that the image is scaled to (neglecting any
			  * global scaling) when it is displayed. This size also determines the aspect
			  * ratio of the image.
			  */
			RIM_INLINE const Vector2f& getSize() const
			{
				return size;
			}
			
			
			
			
			/// Set a 2D vector representing the displayed size of this image in pixels.
			/**
			  * This is the final size that the image is scaled to (neglecting any
			  * global scaling) when it is displayed. This size also determines the aspect
			  * ratio of the image.
			  */
			RIM_INLINE void setSize( const Vector2f& newSize )
			{
				size = newSize;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Validity Accessor Methods
			
			
			
			
			/// Return whether or not this image is valid and can be used for rendering.
			virtual Bool isValid() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Image Drawing Method
			
			
			
			
			/// Draw this image using the specified renderer to the given bounding box on the screen.
			/**
			  * The image's appearance should be tinted (multiplied) by the specified color value.
			  */
			virtual Bool drawSelf( GUIRenderer& renderer, const AABB2f& pixelBounds,
									const Color4f& color = Color4f::WHITE ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Standard Image Construction Methods
			
			
			
			
			/// Return a pointer to an image object that represents a small triangular arrow pointing in the given direction.
			static Pointer<GUIImage> getTriangleArrow( const Vector2f& newSize, const Direction& direction,
														const Color4f& color = Color4f::BLACK );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations
			
			
			
			
			/// A class which draws a triangular arrow image.
			class TriangleArrowImage;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// A 2D vector indicating the scaled width and height of this image.
			Vector2f size;
			
			
			
};




//##########################################################################################
//*******************  End Rim Graphics GUI Utilities Namespace  ***************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_IMAGE_H
