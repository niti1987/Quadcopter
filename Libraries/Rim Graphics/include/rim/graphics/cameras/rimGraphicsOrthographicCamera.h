/*
 *  rimGraphicsOrthographicCamera.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 9/7/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_ORTHOGRAPHIC_CAMERA_H
#define INCLUDE_RIM_GRAPHICS_ORTHOGRAPHIC_CAMERA_H


#include "rimGraphicsCamerasConfig.h"


#include "rimGraphicsCamera.h"


//##########################################################################################
//***********************  Start Rim Graphics Cameras Namespace  ***************************
RIM_GRAPHICS_CAMERAS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a camera which uses an orthographic projection transformation.
class OrthographicCamera : public Camera
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a camera which uses orthographic projection with the specified viewport.
			OrthographicCamera();
			
			
			
			
			/// Create an othographic camera with the specified viewport, position, and orientation.
			OrthographicCamera( const Vector3& newPosition, const Matrix3& newOrientation,
								const Viewport& newViewport = Viewport() );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	View Width Accessor Methods
			
			
			
			
			/// Return the camera-space bounding box of the camera's viewport.
			RIM_INLINE const AABB2& getViewportBounds() const
			{
				return viewportBounds;
			}
			
			
			
			
			/// Set the camera-space bounding box of the camera's viewport.
			RIM_INLINE void setViewportBounds( const AABB2& newViewportBounds )
			{
				viewportBounds = newViewportBounds;
			}
			
			
			
			
			/// Set the camera-space bounding box of the camera's view volume.
			RIM_INLINE void setViewBounds( const AABB3& newViewBounds )
			{
				viewportBounds = AABB2( newViewBounds.min.x, newViewBounds.max.x, newViewBounds.min.y, newViewBounds.max.y );
				nearPlaneDistance = newViewBounds.min.z;
				farPlaneDistance = newViewBounds.max.z;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transform Matrix Accessor Methods
			
			
			
			
			/// Get a matrix which projects points in camera space onto the near plane of the camera.
			virtual Matrix4 getProjectionMatrix() const;
			
			
			
			
			/// Return a depth-biased projection matrix for this camera for the given depth and bias distance.
			virtual Matrix4 getDepthBiasProjectionMatrix( Real depth, Real bias ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	View Volume Accessor Method
			
			
			
			
			/// Return an object specifying the volume of this camera's view.
			virtual ViewVolume getViewVolume() const;
			
			
			
			
			/// Compute the 8 corners of this camera's view volume and place them in the output array.
			virtual void getViewVolumeCorners( StaticArray<Vector3,8>& corners ) const;
			
			
			
			
			/// Return whether or not the specified direction is within the camera's field of view.
			virtual Bool canViewDirection( const Vector3f& direction ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Screen-Space Size Accessor Methods
			
			
			
			
			/// Return the screen-space radius in pixels of the specified world-space bounding sphere.
			virtual Real getScreenSpaceRadius( const BoundingSphere& sphere ) const;
			
			
			
			
			/// Return the distance to the center of the specified bounding sphere along the view direction.
			virtual Real getDepth( const Vector3f& position ) const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The horizontal and vertical bounds of the viewport in camera-space coordinates.
			AABB2 viewportBounds;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Cameras Namespace  *****************************
RIM_GRAPHICS_CAMERAS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_ORTHOGRAPHIC_CAMERA_H
