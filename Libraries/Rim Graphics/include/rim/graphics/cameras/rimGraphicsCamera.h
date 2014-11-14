/*
 *  rimGraphicsCamera.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_CAMERA_H
#define INCLUDE_RIM_GRAPHICS_CAMERA_H


#include "rimGraphicsCamerasConfig.h"


#include "rimGraphicsCameraFlags.h"


//##########################################################################################
//***********************  Start Rim Graphics Cameras Namespace  ***************************
RIM_GRAPHICS_CAMERAS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a camera in 3D space with an implementation-defined projection transformation.
class Camera : public Transformable
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a camera at the origin looking along the z axis.
			Camera();
			
			
			
			
			/// Create a camera with the specified position, orientation, and viewport.
			Camera( const Vector3& newPosition, const Matrix3& newOrientation );
			
			
			
			
			/// Create a camera with the specified transformation and viewport.
			Camera( const Transform3& newTransform );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Position Accessor Methods
			
			
			
			
			/// Get the position of the camera.
			RIM_INLINE const Vector3& getPosition() const
			{
				return transform.position;
			}
			
			
			
			
			/// Set the position of the camera.
			RIM_INLINE void setPosition( const Vector3& newPosition )
			{
				transform.position = newPosition;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Orientation Accessor Methods
			
			
			
			
			/// Get the orientation of the camera.
			RIM_INLINE const Matrix3& getOrientation() const
			{
				return transform.orientation;
			}
			
			
			
			
			/// Set the orientation of the camera.
			/**
			  * This method ensures that the new camera orientation matrix is orthonormal.
			  */
			RIM_NO_INLINE void setOrientation( const Matrix3& newOrientation )
			{
				transform.orientation = newOrientation.orthonormalize();
			}
			
			
			
			
			/// Get a unit vector along the camera's view direction.
			RIM_INLINE Vector3 getViewDirection() const
			{
				return -this->getOrientation().z;
			}
			
			
			
			
			/// Get a unit vector pointing to the camera's up direction.
			RIM_INLINE const Vector3& getUpDirection() const
			{
				return this->getOrientation().y;
			}
			
			
			
			
			/// Get a unit vector pointing to the camera's left.
			RIM_INLINE Vector3 getLeftDirection() const
			{
				return -this->getOrientation().x;
			}
			
			
			
			
			/// Get a unit vector pointing to the camera's left.
			RIM_INLINE const Vector3& getRightDirection() const
			{
				return this->getOrientation().x;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Clipping Plane Accessor Methods
			
			
			
			
			/// Get the distance to the near clipping plane.
			RIM_INLINE Real getNearPlaneDistance() const
			{
				return nearPlaneDistance;
			}
			
			
			
			
			/// Set the distance to the near clipping plane.
			RIM_INLINE void setNearPlaneDistance( Real newNearPlaneDistance )
			{
				nearPlaneDistance = newNearPlaneDistance;
			}
			
			
			
			/// Get the distance to the far clipping plane.
			RIM_INLINE Real getFarPlaneDistance() const
			{
				return farPlaneDistance;
			}
			
			
			
			
			/// Set the distance to the far clipping plane.
			RIM_INLINE void setFarPlaneDistance( Real newFarPlaneDistance )
			{
				farPlaneDistance = newFarPlaneDistance;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Look At Methods
			
			
			
			
			/// Rotate the camera at its current position so that the specified point is in the center of its view.
			/**
			  * This method uses the camera's current up vector in determining the camera's
			  * new orientation.
			  */
			void lookAt( const Vector3& point );
			
			
			
			
			/// Rotate the camera at its current position so that the specified point is in the center of its view.
			/**
			  * This method uses the specified up vector in determining the camera's
			  * new orientation.
			  */
			void lookAt( const Vector3& point, const Vector3& up );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transform Matrix Accessor Methods
			
			
			
			
			/// Get a matrix which projects points in camera space onto the near plane of the camera.
			virtual Matrix4 getProjectionMatrix() const = 0;
			
			
			
			
			/// Return a depth-biased projection matrix for this camera for the given depth and bias distance.
			virtual Matrix4 getDepthBiasProjectionMatrix( Real depth, Real bias ) const = 0;
			
			
			
			
			/// Return a 4x4 matrix which transforms points from camera space to world space.
			Matrix4 getTransformMatrix() const;
			
			
			
			
			/// Return a 4x4 matrix which transforms points from world space to camera space.
			Matrix4 getInverseTransformMatrix() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	View Volume Accessor Method
			
			
			
			
			/// Return an object specifying the volume of this camera's view.
			virtual ViewVolume getViewVolume() const = 0;
			
			
			
			
			/// Compute the 8 corners of this camera's view volume and place them in the output array.
			/**
			  * The corners are stored in the following order: near bottom left, near bottom right,
			  * near top left, near top right, far bottom left, far bottom right, far top left,
			  * far top right.
			  */
			virtual void getViewVolumeCorners( StaticArray<Vector3,8>& corners ) const = 0;
			
			
			
			
			/// Return whether or not the specified direction is within the camera's field of view.
			virtual Bool canViewDirection( const Vector3f& direction ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Screen-Space Size Accessor Methods
			
			
			
			
			/// Return the screen-space radius in pixels of the specified world-space bounding sphere.
			virtual Real getScreenSpaceRadius( const BoundingSphere& sphere ) const = 0;
			
			
			
			
			/// Return the distance to the specified position along the view direction.
			virtual Real getDepth( const Vector3f& position ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flags Accessor Methods
			
			
			
			
			/// Return a reference to an object which contains boolean parameters of the camera.
			RIM_INLINE CameraFlags& getFlags()
			{
				return flags;
			}
			
			
			
			
			/// Return an object which contains boolean parameters of the camera.
			RIM_INLINE const CameraFlags& getFlags() const
			{
				return flags;
			}
			
			
			
			
			/// Set an object which contains boolean parameters of the camera.
			RIM_INLINE void setFlags( const CameraFlags& newFlags )
			{
				flags = newFlags;
			}
			
			
			
			
			/// Return whether or not the specified boolan flag is set for this camera.
			RIM_INLINE Bool flagIsSet( CameraFlags::Flag flag ) const
			{
				return flags.isSet( flag );
			}
			
			
			
			
			/// Set whether or not the specified boolan flag is set for this camera.
			RIM_INLINE void setFlag( CameraFlags::Flag flag, Bool newIsSet = true )
			{
				flags.set( flag, newIsSet );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return the name of the camera.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set the name of the camera.
			RIM_INLINE void setName( const String& newName )
			{
				name = newName;
			}
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// An integer which contains the default boolean flags for a camera.
			static const UInt32 DEFAULT_FLAGS = CameraFlags::ENABLED;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The distance from the camera to the near plane along the view direction.
			Real nearPlaneDistance;
			
			
			
			
			/// The distance from the camera to the far plane along the view direction.
			Real farPlaneDistance;
			
			
			
			
			/// A name string for this camera.
			String name;
			
			
			
			
			/// An object containing boolean configuration data for this camera.
			CameraFlags flags;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Cameras Namespace  *****************************
RIM_GRAPHICS_CAMERAS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_CAMERA_H
