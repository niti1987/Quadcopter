/*
 *  rimTransform3D.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 6/4/07.
 *  Copyright 2007 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_TRANSFORM_3D_H
#define INCLUDE_RIM_TRANSFORM_3D_H


#include "rimMathConfig.h"


#include "rimVector3D.h"
#include "rimMatrix3D.h"
#include "rimMatrix4D.h"
#include "rimRay3D.h"
#include "rimPlane3D.h"
#include "rimAABB3D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a 3-dimensional transformation.
/**
  * The transformation is composed of translation, rotation, and scaling.
  * The components are assumed to be in the following order: translation, rotation,
  * and scaling. Thus, when transforming a point from world to object space by the
  * transformation, translation is first applied, followed by scaling, and finally
  * rotation. The reverse holds true for transformations from object to world space.
  */
template < typename T >
class Transform3D
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an identity transformation that doesn't modify transformed points.
			RIM_FORCE_INLINE Transform3D()
				:	position( Vector3D<T>() ),
					orientation( Matrix3D<T>::IDENTITY ),
					scale( 1 )
			{
			}
			
			
			
			
			/// Create a transformation with the specified translation and no rotation or scaling.
			RIM_FORCE_INLINE Transform3D( const Vector3D<T>& newPosition )
				:	position( newPosition ),
					orientation( Matrix3D<T>::IDENTITY ),
					scale( 1 )
			{
			}
			
			
			
			
			/// Create a transformation with the specified translation, rotation, and no scaling.
			RIM_FORCE_INLINE Transform3D( const Vector3D<T>& newPosition, 
									const Matrix3D<T>& newOrientation )
				:	position( newPosition ),
					orientation( newOrientation ),
					scale( 1 )
			{
			}
			
			
			
			
			/// Create a transformation with the specified translation, rotation, and uniform scaling.
			RIM_FORCE_INLINE Transform3D(	const Vector3D<T>& newPosition, 
											const Matrix3D<T>& newOrientation, 
											T newScale )
				:	position( newPosition ),
					orientation( newOrientation ),
					scale( newScale )
			{
			}
			
			
			
			
			/// Create a transformation with the specified translation, rotation, and uniform scaling.
			RIM_FORCE_INLINE Transform3D(	const Vector3D<T>& newPosition, 
											const Matrix3D<T>& newOrientation, 
											const Vector3D<T>& newScale )
				:	position( newPosition ),
					orientation( newOrientation ),
					scale( newScale )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Space Transforms
			
			
			
			
			/// Transform the specified scalar value to object space.
			/**
			  * This will perform any scaling necessary to satisfy the transformation.
			  */
			RIM_FORCE_INLINE Vector3D<T> transformToObjectSpace( T original ) const
			{
				return original/scale;
			}
			
			
			
			
			/// Transform the specified position vector to object space.
			RIM_FORCE_INLINE Vector3D<T> transformToObjectSpace( const Vector3D<T>& original ) const
			{
				return ((original - position)*orientation)/scale;
			}
			
			
			
			
			/// Transform the specified matrix to object space.
			/**
			  * This returns what the specified matrix would be in this transformation's
			  * coordinate frame. This method does not perform any scaling on the input
			  * matrix. The input matrix is assumed to be an orthonormal rotation matrix.
			  */
			RIM_FORCE_INLINE Matrix3D<T> transformToObjectSpace( const Matrix3D<T>& original ) const
			{
				return original*orientation;
			}
			
			
			
			
			/// Transform the specified ray into object space.
			/**
			  * This method performs a standard vector transformation for the ray origin
			  * and only rotates the ray direction, preserving the length of the ray's direction
			  * vector.
			  */
			RIM_FORCE_INLINE Ray3D<T> transformToObjectSpace( const Ray3D<T>& ray ) const
			{
				return Ray3D<T>( ((ray.origin - position)*orientation)/scale, ray.direction*orientation );
			}
			
			
			
			
			/// Transform the specified plane into object space.
			/**
			  * This method rotates the normal of the plane into the new coordinate frame
			  * and calculates a new offset for the plane based on the projection of the origin
			  * onto the plane in world space transformed to object space.
			  */
			RIM_FORCE_INLINE Plane3D<T> transformToObjectSpace( const Plane3D<T>& plane ) const
			{
				return Plane3D<T>( plane.normal*orientation, this->transformToObjectSpace(-plane.offset*plane.normal) );
			}
			
			
			
			
			/// Transform the specified axis-aligned box into object space, producing another axis-aligned box that encloses the original.
			RIM_FORCE_INLINE AABB3D<T> transformToObjectSpace( const AABB3D<T>& box ) const
			{
				AABB3D<T> result( this->transformToObjectSpace( Vector3D<T>( box.min.x, box.min.y, box.min.z ) ) );
				result.enlargeFor( this->transformToObjectSpace( Vector3D<T>( box.min.x, box.min.y, box.max.z ) ) );
				result.enlargeFor( this->transformToObjectSpace( Vector3D<T>( box.min.x, box.max.y, box.min.z ) ) );
				result.enlargeFor( this->transformToObjectSpace( Vector3D<T>( box.max.x, box.min.y, box.min.z ) ) );
				result.enlargeFor( this->transformToObjectSpace( Vector3D<T>( box.max.x, box.min.y, box.max.z ) ) );
				result.enlargeFor( this->transformToObjectSpace( Vector3D<T>( box.max.x, box.max.y, box.min.z ) ) );
				result.enlargeFor( this->transformToObjectSpace( Vector3D<T>( box.max.x, box.max.y, box.max.z ) ) );
				result.enlargeFor( this->transformToObjectSpace( Vector3D<T>( box.min.x, box.max.y, box.max.z ) ) );
				
				return result;
				/*
				AABB3D<T> translatedBox( box.min - position, box.max - position );
				Vector3D<T> center = translatedBox.getCenter();
				translatedBox.min -= center;
				translatedBox.max -= center;
				
				AABB3D<T> result( center*orientation );
				
				for ( Index i = 0; i < 3; i++ )
				{
					for ( Index j = 0; j < 3; j++ )
					{
						T a = orientation[j][i]*translatedBox.min[j];
						T b = orientation[j][i]*translatedBox.max[j];
						
						if ( a < b )
						{
							result.min[j] += a;
							result.max[j] += b;
						}
						else
						{
							result.min[j] += b;
							result.max[j] += a;
						}
					}
				}
				
				result.min /= scale;
				result.max /= scale;
				
				return result;*/
			}
			
			
			
			
			/// Rotate the specified vector to object space.
			/**
			  * This method does not perform any translation or scaling on the
			  * input point. This function is ideal for transforming directional
			  * quantities like surface normal vectors.
			  */
			RIM_FORCE_INLINE Vector3D<T> rotateToObjectSpace( const Vector3D<T>& original ) const
			{
				return original*orientation;
			}
			
			
			
			
			/// Scale a vector to object space.
			RIM_FORCE_INLINE Vector3D<T> scaleToObjectSpace( const Vector3D<T>& original ) const
			{
				return original/scale;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	World Space Transforms
			
			
			
			
			/// Transform the specified scalar value to world space.
			/**
			  * This will perform any scaling necessary to satisfy the transformation.
			  */
			RIM_FORCE_INLINE Vector3D<T> transformToWorldSpace( T original ) const
			{
				return original*scale;
			}
			
			
			
			
			/// Transform the specified position vector from object to world space.
			RIM_FORCE_INLINE Vector3D<T> transformToWorldSpace( const Vector3D<T>& original ) const
			{
				return position + orientation*(original*scale);
			}
			
			
			
			
			/// Transform the specified matrix from object to world space.
			/**
			  * This returns what the specified matrix would be in this transformation's
			  * coordinate frame. This method does not perform any scaling on the input
			  * matrix. The input matrix is assumed to be an orthonormal rotation matrix.
			  */
			RIM_FORCE_INLINE Matrix3D<T> transformToWorldSpace( const Matrix3D<T>& original ) const
			{
				return orientation*original;
			}
			
			
			
			
			/// Transform the specified ray into world space.
			/**
			  * This method performs a standard vector transformation for the ray origin
			  * and only rotates the ray direction, preserving the length of the ray's direction
			  * vector.
			  */
			RIM_FORCE_INLINE Ray3D<T> transformToWorldSpace( const Ray3D<T>& ray ) const
			{
				return Ray3D<T>( position + orientation*(ray.origin*scale), orientation*ray.direction );
			}
			
			
			
			
			/// Transform the specified plane into world space.
			/**
			  * This method rotates the normal of the plane into the new coordinate frame
			  * and calculates a new offset for the plane based on the projection of the origin
			  * onto the plane in object space transformed to world space.
			  */
			RIM_FORCE_INLINE Plane3D<T> transformToWorldSpace( const Plane3D<T>& plane ) const
			{
				return Plane3D<T>( orientation*plane.normal, this->transformToWorldSpace(-plane.offset*plane.normal) );
			}
			
			
			
			
			/// Transform the specified axis-aligned box into world space, producing another axis-aligned box that encloses the original.
			RIM_FORCE_INLINE AABB3D<T> transformToWorldSpace( const AABB3D<T>& box ) const
			{
				AABB3D<T> result( this->transformToWorldSpace( Vector3D<T>( box.min.x, box.min.y, box.min.z ) ) );
				result.enlargeFor( this->transformToWorldSpace( Vector3D<T>( box.min.x, box.min.y, box.max.z ) ) );
				result.enlargeFor( this->transformToWorldSpace( Vector3D<T>( box.min.x, box.max.y, box.min.z ) ) );
				result.enlargeFor( this->transformToWorldSpace( Vector3D<T>( box.max.x, box.min.y, box.min.z ) ) );
				result.enlargeFor( this->transformToWorldSpace( Vector3D<T>( box.max.x, box.min.y, box.max.z ) ) );
				result.enlargeFor( this->transformToWorldSpace( Vector3D<T>( box.max.x, box.max.y, box.min.z ) ) );
				result.enlargeFor( this->transformToWorldSpace( Vector3D<T>( box.max.x, box.max.y, box.max.z ) ) );
				result.enlargeFor( this->transformToWorldSpace( Vector3D<T>( box.min.x, box.max.y, box.max.z ) ) );
				
				return result;
				/*
				// Move the box to the origin.
				Vector3D<T> center = box.getCenter();
				AABB3D<T> scaledBox( box.min - center, box.max - center );
				
				// Scale the box.
				scaledBox.min *= scale;
				scaledBox.max *= scale;
				
				// Rotate the box.
				AABB3D<T> result;
				
				for ( Index i = 0; i < 3; i++ )
				{
					Vector3D<T> a = orientation[i]*scaledBox.min;
					Vector3D<T> b = orientation[i]*scaledBox.max;
					
					for ( Index j = 0; j < 3; j++ )
					{
						if ( a[j] < b[j] )
						{
							result.min[j] += a[j];
							result.max[j] += b[j];
						}
						else
						{
							result.min[j] += b[j];
							result.max[j] += a[j];
						}
					}
				}
				
				// Position the box.
				result.min += position + orientation*center*scale;
				result.max += position + orientation*center*scale;
				
				return result;*/
			}
			
			
			
			
			/// Rotate the specified vector to world space.
			/**
			  * This method does not perform any translation or scaling on the
			  * input point. This function is ideal for transforming directional
			  * quantities like surface normal vectors.
			  */
			RIM_FORCE_INLINE Vector3D<T> rotateToWorldSpace( const Vector3D<T>& original ) const
			{
				return orientation*original;
			}
			
			
			
			
			/// Scale a vector to world space.
			RIM_FORCE_INLINE Vector3D<T> scaleToWorldSpace( const Vector3D<T>& original ) const
			{
				return original*scale;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transform Multiplication Operators
			
			
			
			
			/// Scale the specified value to world space with this transformation.
			RIM_FORCE_INLINE T operator * ( T value ) const
			{
				return this->transformToWorldSpace( value );
			}
			
			
			
			
			/// Transform the specified vector to world space with this transformation.
			RIM_FORCE_INLINE Vector3D<T> operator * ( const Vector3D<T>& vector ) const
			{
				return this->transformToWorldSpace( vector );
			}
			
			
			
			
			/// Transform the specified matrix to world space with this transformation.
			RIM_FORCE_INLINE Matrix3D<T> operator * ( const Matrix3D<T>& matrix ) const
			{
				return this->transformToWorldSpace( matrix );
			}
			
			
			
			
			/// Transform the specified ray to world space with this transformation.
			RIM_FORCE_INLINE Ray3D<T> operator * ( const Ray3D<T>& ray ) const
			{
				return this->transformToWorldSpace( ray );
			}
			
			
			
			
			/// Transform the specified plane to world space with this transformation.
			RIM_FORCE_INLINE Plane3D<T> operator * ( const Plane3D<T>& plane ) const
			{
				return this->transformToWorldSpace( plane );
			}
			
			
			
			
			/// Concatenate this transformation with another and return the combined transformation.
			/**
			  * This transformation represents the total transformation from object space of the
			  * other, into this transformation's object space, and then to world space.
			  */
			RIM_FORCE_INLINE Transform3D<T> operator * ( const Transform3D<T>& other ) const
			{
				return Transform3D<T>( this->transformToWorldSpace( other.position ),
										this->transformToWorldSpace( other.orientation ),
										scale*other.scale );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transform Inversion Method
			
			
			
			
			/// Return the inverse of this transformations that applys the opposite transformation.
			RIM_FORCE_INLINE Transform3D<T> invert() const
			{
				Vector3D<T> inverseScale = T(1)/scale;
				
				return Transform3D<T>( (position*(-inverseScale))*orientation, orientation.transpose(), inverseScale );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Matrix Conversion Methods
			
			
			
			
			/// Convert this transformation into a 4x4 homogeneous-coordinate matrix.
			RIM_FORCE_INLINE Matrix4D<T> toMatrix() const
			{
				return Matrix4D<T>(	scale.x*orientation.x.x, scale.y*orientation.y.x, scale.z*orientation.z.x, position.x,
									scale.x*orientation.x.y, scale.y*orientation.y.y, scale.z*orientation.z.y, position.y,
									scale.x*orientation.x.z, scale.y*orientation.y.z, scale.z*orientation.z.z, position.z,
									T(0), T(0), T(0), T(1) );
			}
			
			
			
			
			/// Convert the inverse of this transformation into a 4x4 homogeneous-coordinate matrix.
			RIM_FORCE_INLINE Matrix4D<T> toMatrixInverse() const
			{
				Vector3D<T> inverseScale = T(1)/scale;
				T wx = -( position.x*orientation.x.x + position.y*orientation.x.y + position.z*orientation.x.z );
				T wy = -( position.x*orientation.y.x + position.y*orientation.y.y + position.z*orientation.y.z );
				T wz = -( position.x*orientation.z.x + position.y*orientation.z.y + position.z*orientation.z.z );
				
				return Matrix4D<T>( inverseScale.x*orientation.x.x, inverseScale.x*orientation.x.y, inverseScale.x*orientation.x.z, wx,
									inverseScale.y*orientation.y.x, inverseScale.y*orientation.y.y, inverseScale.y*orientation.y.z, wy,
									inverseScale.z*orientation.z.x, inverseScale.z*orientation.z.y, inverseScale.z*orientation.z.z, wz,
									T(0), T(0), T(0), T(1) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The translation component of the rigid transformation.
			Vector3D<T> position;
			
			
			
			
			/// The rotation component of the rigid transformation.
			Matrix3D<T> orientation;
			
			
			
			
			/// The scaling component of the rigid transformation.
			Vector3D<T> scale;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Inverse Transform Multiplication Operators
//############		
//##########################################################################################
//##########################################################################################




/// Scale the specified scalar value to object space with the inverse of the specified transformation.
template < typename T >
RIM_FORCE_INLINE T operator * ( T value, const Transform3D<T>& transform )
{
	return transform.transformToWorldSpace( value );
}




/// Transform the specified vector to object space with the inverse of the specified transformation.
template < typename T >
RIM_FORCE_INLINE Vector3D<T> operator * ( const Vector2D<T>& vector, const Transform3D<T>& transform )
{
	return transform.transformToObjectSpace( vector );
}




/// Transform the specified matrix to object space with the inverse of the specified transformation.
template < typename T >
RIM_FORCE_INLINE Matrix3D<T> operator * ( const Matrix2D<T>& matrix, const Transform3D<T>& transform )
{
	return transform.transformToObjectSpace( matrix );
}




/// Transform the specified ray to object space with the inverse of the specified transformation.
template < typename T >
RIM_FORCE_INLINE Ray3D<T> operator * ( const Ray3D<T>& ray, const Transform3D<T>& transform )
{
	return transform.transformToObjectSpace( ray );
}




/// Transform the specified plane to object space with the inverse of the specified transformation.
template < typename T >
RIM_FORCE_INLINE Plane3D<T> operator * ( const Plane3D<T>& plane, const Transform3D<T>& transform )
{
	return transform.transformToObjectSpace( plane );
}




//##########################################################################################
//##########################################################################################
//############		
//############		3D Transform Type Definitions
//############		
//##########################################################################################
//##########################################################################################




typedef Transform3D<int>		Transform3i;
typedef Transform3D<float>		Transform3f;
typedef Transform3D<double>	Transform3d;




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_TRANSFORM_3D_H
