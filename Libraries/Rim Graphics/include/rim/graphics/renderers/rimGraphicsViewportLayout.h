/*
 *  rimGraphicsViewportLayout.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 7/3/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_VIEWPORT_LAYOUT_H
#define INCLUDE_RIM_GRAPHICS_VIEWPORT_LAYOUT_H


#include "rimGraphicsRenderersConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Renderers Namespace  **************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that defines the viewports on the screen where camera views should be drawn.
/**
  * The cameras are drawn to the screen in the order they are specified in the layout.
  */
class ViewportLayout
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Camera View Class Declaration
			
			
			
			
			/// A class that encapsulates a single camera viewport that should be drawn to the screen.
			class CameraView
			{
				public:
					
					/// Create a new camera view for the specified camera, scene, and viewport.
					RIM_INLINE CameraView( const Pointer<Camera>& newCamera, const Pointer<GraphicsScene>& newScene,
											const Viewport& newViewport )
						:	camera( newCamera ),
							scene( newScene ),
							viewport( newViewport ),
							clearColor( 0.0, 0.0, 0.0, 0.0 ),
							clearDepth( 1 )
					{
					}
					
					
					/// A pointer to the camera whose view is to be drawn.
					Pointer<Camera> camera;
					
					/// A pointer to the scene which should be drawn for this camera's view.
					Pointer<GraphicsScene> scene;
					
					/// The viewport on the screen where the camera's view should be drawn.
					Viewport viewport;
					
					/// The color that the framebuffer is cleared to before the camera view is drawn.
					Color4d clearColor;
					
					/// The depth that the framebuffer is cleared to before the camera view is drawn.
					Double clearDepth;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new viewport layout with no camera views.
			ViewportLayout();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Camera View Accessor Methods
			
			
			
			
			/// Return the number of camera views that this viewport layout has.
			RIM_INLINE Size getCameraViewCount() const
			{
				return cameraViews.getSize();
			}
			
			
			
			
			/// Return a reference to the camera view at the specified index in this viewport layout.
			RIM_INLINE CameraView& getCameraView( Index viewIndex )
			{
				return cameraViews[viewIndex];
			}
			
			
			
			
			/// Return a const reference to the camera view at the specified index in this viewport layout.
			RIM_INLINE const CameraView& getCameraView( Index viewIndex ) const
			{
				return cameraViews[viewIndex];
			}
			
			
			
			
			/// Add a new camera view to this viewport layout that is rendered after the previously added camera views.
			/**
			  * The method returns whether or not the camera view was successfully added.
			  */
			Bool addCameraView( const CameraView& newCameraView );
			
			
			
			
			/// Insert a new camera view to this viewport layout that is rendered at the specified index.
			/**
			  * The method returns whether or not the camera view was successfully added.
			  */
			Bool insertCameraView( Index viewIndex, const CameraView& newCameraView );
			
			
			
			
			/// Remove the camera view at the specified index in this viewport layout.
			/**
			  * The method returns whether or not the camera view was successfully removed.
			  */
			Bool removeCameraView( Index viewIndex );
			
			
			
			
			/// Remove the specified camera's viewport(s) from this viewport layout.
			/**
			  * The method returns whether or not any camera viewport was successfully removed.
			  */
			Bool removeCameraView( const Camera* camera );
			
			
			
			
			/// Remove all camera views from this viewport layout.
			void clearCameraViews();
			
			
			
			
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the camera views that are rendered in order.
			ArrayList<CameraView> cameraViews;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Renderers Namespace  ****************************
RIM_GRAPHICS_RENDERERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_VIEWPORT_LAYOUT_H
