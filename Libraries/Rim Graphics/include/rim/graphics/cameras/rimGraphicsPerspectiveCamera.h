/*
 *  rimGraphicsPerspectiveCamera.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 9/7/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_PERSPECTIVE_CAMERA_H
#define INCLUDE_RIM_GRAPHICS_PERSPECTIVE_CAMERA_H


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
/// A class which represents a camera which uses a perspective projection transformation.
class PerspectiveCamera : public Camera
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a perspective camera with the specified aspect ratio. 
			PerspectiveCamera( Real aspectRatio = Real(1) );
			
			
			
			
			/// Create a perspective camera with the specified aspect ratio, position and orientation.
			PerspectiveCamera( Real aspectRatio, const Vector3& newPosition, const Matrix3& newOrientation );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Field of View Accessor Methods
			
			
			
			
			/// Get the horizontal field of view of the camera's view frustum.
			/**
			  * This value is specified in degrees.
			  */
			RIM_INLINE Real getHorizontalFieldOfView() const
			{
				return horizontalFieldOfView;
			}
			
			
			
			
			/// Set the horizontal field of view of the camera's view frustum.
			/**
			  * This value, specified in degrees, is clamped between 0 and 180.
			  */
			RIM_INLINE void setHorizontalFieldOfView( Real newHorizontalFieldOfView )
			{
				horizontalFieldOfView = math::clamp( newHorizontalFieldOfView, Real(0), Real(180) );
				horizontalSlope = math::tan( Real(0.5)*math::degreesToRadians( horizontalFieldOfView ) );
			}
			
			
			
			
			/// Get the vertical field of view of the camera's view frustum.
			/**
			  * This value is specified in degrees.
			  */
			RIM_INLINE Real getVerticalFieldOfView() const
			{
				Real nearWidth = nearPlaneDistance*math::tan( math::degreesToRadians( horizontalFieldOfView*Real(0.5) ) );
				Real nearHeight = nearWidth / aspectRatio;
				
				return math::radiansToDegrees( math::atan( nearHeight/nearPlaneDistance ) );
			}
			
			
			
			
			/// Get the vertical field of view of the camera's view frustum.
			/**
			  * This value, specified in degrees, is clamped between 0 and 180.
			  */
			RIM_INLINE void setVerticalFieldOfView( Real newVerticalFieldOfView )
			{
				newVerticalFieldOfView = math::clamp( newVerticalFieldOfView, Real(0), Real(180) );
				Real nearHeight = nearPlaneDistance*math::tan( math::degreesToRadians( newVerticalFieldOfView*Real(0.5) ) );
				Real nearWidth = nearHeight * aspectRatio;
				
				horizontalFieldOfView = math::radiansToDegrees( math::atan( nearWidth/nearPlaneDistance ) );
				horizontalSlope = math::tan( Real(0.5)*math::degreesToRadians( horizontalFieldOfView ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Aspect Ratio Accessor Methods
			
			
			
			
			/// Return the aspect ratio of this perspective camera (the ratio of the frustum's width to its height).
			/**
			  * The default aspect ratio is 1.
			  */
			RIM_INLINE Real getAspectRatio() const
			{
				return aspectRatio;
			}
			
			
			
			
			/// Set the aspect ratio of this perspective camera (the ratio of the frustum's width to its height).
			/**
			  * The default aspect ratio is 1.
			  */
			RIM_INLINE void setAspectRatio( Real newAspectRatio )
			{
				aspectRatio = math::abs( newAspectRatio );
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
		//******	Private Helper Methods
			
			
			
			
			/// Return a projection matrix for the specified viewing plane distances.
			RIM_FORCE_INLINE static Matrix4 perspectiveProjection( Real left, Real right, Real bottom,
																	Real top, Real near, Real far );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The horizontal field of view of the camera's viewing frustum.
			Real horizontalFieldOfView;
			
			
			
			
			/// The ratio of a change in the width of the view frustum to a change in depth, i.e. tan( 0.5*horizFOV ).
			/**
			  * Mulitplying this value by a screen-space depth value gives the width of the frustum at that depth.
			  */
			Real horizontalSlope;
			
			
			
			
			/// The aspect ratio of this perspective camera (the ratio of the frustum's width to its height).
			/**
			  * The default aspect ratio is 1.
			  */
			Real aspectRatio;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Cameras Namespace  *****************************
RIM_GRAPHICS_CAMERAS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_PERSPECTIVE_CAMERA_H
