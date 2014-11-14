/*
 *  rimGraphicsGUIImageViewRenderer.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/13/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_IMAGE_VIEW_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_GUI_IMAGE_VIEW_RENDERER_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObjectRenderer.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class ImageView;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles drawing ImageView objects to a graphics rendering context.
template <>
class GUIObjectRenderer<ImageView>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Virtual Destructor Declaration
			
			
			
			
			/// Destroy this GUI object renderer, releasing all of its internal state.
			virtual ~GUIObjectRenderer()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Rendering Methods
			
			
			
			
			/// Draw an image view using the specified renderer within the given parent coordinate bounds.
			/**
			  * The method returns whether or not the image view was able to be successfully drawn.
			  */
			virtual Bool render( GUIRenderer& renderer, const AABB2f& parentBounds, const ImageView& imageView ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Background Color Accessor Methods
			
			
			
			
			/// Return the background color for this image view's main area.
			virtual Color4f getBackgroundColor() const = 0;
			
			
			
			
			
			/// Set the background color for this image view's main area.
			/**
			  * The method returns whether or not the image view's background color was successfully changed.
			  */
			virtual Bool setBackgroundColor( const Color4f& newBackgroundColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering an image view.
			virtual Color4f getBorderColor() const = 0;
			
			
			
			
			
			/// Set the border color used when rendering an image view.
			/**
			  * The method returns whether or not the image view border color was successfully changed.
			  */
			virtual Bool setBorderColor( const Color4f& newBorderColor ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Background Color Accessor Methods
			
			
			
			
			/// Return the tint color for this image view's image.
			/**
			  * This color is multiplied with the image when it is displayed to
			  * produce an optional tinting of the image. The default color, white,
			  * produces no tinting.
			  */
			virtual Color4f getImageColor() const = 0;
			
			
			
			
			
			/// Set the tint color for this image view's image.
			/**
			  * This color is multiplied with the image when it is displayed to
			  * produce an optional tinting of the image. The default color, white,
			  * produces no tinting.
			  *
			  * The method returns whether or not the image's tint color was successfully changed.
			  */
			virtual Bool setImageColor( const Color4f& newImageColor ) = 0;
			
			
			
};




/// A short name for the interface of a class that draws a ImageView.
typedef GUIObjectRenderer<ImageView> ImageViewRenderer;




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_IMAGE_VIEW_RENDERER_H
