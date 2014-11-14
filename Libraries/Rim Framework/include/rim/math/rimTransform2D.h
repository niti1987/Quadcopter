/*
 *  rimTransform2D.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 1/24/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_TRANSFORM_2D_H
#define INCLUDE_RIM_TRANSFORM_2D_H


#include "rimMathConfig.h"


#include "rimVector2D.h"
#include "rimMatrix2D.h"
#include "rimMatrix3D.h"
#include "rimRay2D.h"
#include "rimPlane2D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a 2-dimensional transformation.
/**
  * The transformation is composed of translation, rotation, and scaling.
  * The components are assumed to be in the following order: translation, rotation,
  * and scaling. Thus, when transforming a point from world to object space by the
  * transformation, translation is first applied, followed by scaling, and finally
  * rotation. The reverse holds true for transformations from object to world space.
  */
template < typename T >
class Transform2D
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an identity transformation that doesn't modify transformed points.
			RIM_FORCE_INLINE Transform2D()
				:	position( Vector2D<T>::ZERO ),
					orientation( Matrix2D<T>::IDENTITY ),
					scale( 1 )
			{
			}
			
			
			
			
			/// Create a transformation with the specified translation and no rotation or scaling.
			RIM_FORCE_INLINE Transform2D( const Vector2D<T>& newPosition )
				:	position( newPosition ),
					orientation( Matrix2D<T>::IDENTITY ),
					scale( 1 )
			{
			}
			
			
			
			
			/// Create a transformation with the specified translation, rotation, and no scaling.
			RIM_FORCE_INLINE Transform2D( const Vector2D<T>& newPosition, 
												const Matrix2D<T>& newOrientation )
				:	position( newPosition ),
					orientation( newOrientation ),
					scale( 1 )
			{
			}
			
			
			
			
			/// Create a transformation with the specified translation, rotation, and uniform scaling.
			RIM_FORCE_INLINE Transform2D( const Vector2D<T>& newPosition, 
												const Matrix2D<T>& newOrientation, 
												T newScale )
				:	position( newPosition ),
					orientation( newOrientation ),
					scale( newScale )
			{
			}
			
			
			
			
			/// Create a transformation with the specified translation, rotation, and uniform scaling.
			RIM_FORCE_INLINE Transform2D( const Vector2D<T>& newPosition, 
												const Matrix2D<T>& newOrientation, 
												const Vector2D<T>& newScale )
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
			RIM_FORCE_INLINE Vector2D<T> transformToObjectSpace( T original ) const
			{
				return original/scale;
			}
			
			
			
			
			/// Transform the specified position vector to object space.
			RIM_FORCE_INLINE Vector2D<T> transformToObjectSpace( const Vector2D<T>& original ) const
			{
				return ((original - position)*orientation)/scale;
			}
			
			
			
			
			/// Transform the specified matrix to object space.
			/**
			  * This returns what the specified matrix would be in this transformation's
			  * coordinate frame. This method does not perform any scaling on the input
			  * matrix. The input matrix is assumed to be an orthonormal rotation matrix.
			  */
			RIM_FORCE_INLINE Matrix2D<T> transformToObjectSpace( const Matrix2D<T>& original ) const
			{
				return original*orientation;
			}
			
			
			
			
			/// Rotate the specified vector to object space.
			/**
			  * This method does not perform any translation or scaling on the
			  * input point. This function is ideal for transforming directional
			  * quantities like surface normal vectors.
			  */
			RIM_FORCE_INLINE Vector2D<T> rotateToObjectSpace( const Vector2D<T>& original ) const
			{
				return original*orientation;
			}
			
			
			
			
			/// Scale a vector to object space.
			RIM_FORCE_INLINE Vector2D<T> scaleToObjectSpace( const Vector2D<T>& original ) const
			{
				return original*orientation;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	World Space Transforms
			
			
			
			
			/// Transform the specified scalar value to world space.
			/**
			  * This will perform any scaling necessary to satisfy the transformation.
			  */
			RIM_FORCE_INLINE Vector2D<T> transformToWorldSpace( T original ) const
			{
				return original*scale;
			}
			
			
			
			
			/// Transform the specified position vector to world space.
			RIM_FORCE_INLINE Vector2D<T> transformToWorldSpace( const Vector2D<T>& original ) const
			{
				return position + (orientation*original)*scale;
			}
			
			
			
			
			/// Transform the specified matrix to world space.
			/**
			  * This returns what the specified matrix would be in this transformation's
			  * coordinate frame. This method does not perform any scaling on the input
			  * matrix. The input matrix is assumed to be an orthonormal rotation matrix.
			  */
			RIM_FORCE_INLINE Matrix2D<T> transformToWorldSpace( const Matrix2D<T>& original ) const
			{
				return orientation*original;
			}
			
			
			
			
			/// Rotate the specified vector to world space.
			/**
			  * This method does not perform any translation or scaling on the
			  * input point. This function is ideal for transforming directional
			  * quantities like surface normal vectors.
			  */
			RIM_FORCE_INLINE Vector2D<T> rotateToWorldSpace( const Vector2D<T>& original ) const
			{
				return orientation*original;
			}
			
			
			
			
			/// Scale a vector to world space.
			RIM_FORCE_INLINE Vector2D<T> scaleToWorldSpace( const Vector2D<T>& original ) const
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
			RIM_FORCE_INLINE Vector2D<T> operator * ( const Vector2D<T>& vector ) const
			{
				return this->transformToWorldSpace( vector );
			}
			
			
			
			
			/// Transform the specified matrix to world space with this transformation.
			RIM_FORCE_INLINE Matrix2D<T> operator * ( const Matrix2D<T>& matrix ) const
			{
				return this->transformToWorldSpace( matrix );
			}
			
			
			
			
			/// Transform the specified ray to world space with this transformation.
			RIM_FORCE_INLINE Ray2D<T> operator * ( const Ray2D<T>& ray ) const
			{
				return this->transformToWorldSpace( ray );
			}
			
			
			
			
			/// Transform the specified plane to world space with this transformation.
			RIM_FORCE_INLINE Plane2D<T> operator * ( const Plane2D<T>& plane ) const
			{
				return this->transformToWorldSpace( plane );
			}
			
			
			
			
			/// Concatenate this transformation with another and return the combined transformation.
			/**
			  * This transformation represents the total transformation from object space of the
			  * other, into this transformation's object space, and then to world space.
			  */
			RIM_FORCE_INLINE Transform2D<T> operator * ( const Transform2D<T>& other ) const
			{
				return Transform2D<T>( this->transformToWorldSpace( other.position ),
											this->transformToWorldSpace( other.orientation ),
											scale*this->rotateToWorldSpace( other.scale ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transform Inversion Method
			
			
			
			
			/// Return the inverse of this transformations that applys the opposite transformation.
			RIM_FORCE_INLINE Transform2D<T> invert() const
			{
				Vector2D<T> inverseScale = T(1)/scale;
				
				return Transform2D<T>( (position*(-inverseScale))*orientation, orientation.transpose(), inverseScale );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Matrix Conversion Methods
			
			
			
			
			/// Convert this transformation into a 3x3 homogeneous-coordinate matrix.
			RIM_FORCE_INLINE Matrix3D<T> toMatrix() const
			{
				return Matrix3D<T>(	scale.x*orientation.x.x, scale.y*orientation.y.x, position.x,
									scale.x*orientation.x.y, scale.y*orientation.y.y, position.y,
									T(0), T(0), T(1) );
			}
			
			
			
			
			/// Convert the inverse of this transformation into a 3x3 homogeneous-coordinate matrix.
			RIM_FORCE_INLINE Matrix3D<T> toMatrixInverse() const
			{
				Vector2D<T> inverseScale = T(1)/scale;
				T zx = -(position.x*orientation.x.x + position.y*orientation.x.y);
				T zy = -(position.x*orientation.y.x + position.y*orientation.y.y);
				
				return Matrix3D<T>( inverseScale.x*orientation.x.x, inverseScale.x*orientation.x.y, zx,
									inverseScale.y*orientation.y.x, inverseScale.y*orientation.y.y, zy,
									T(0), T(0), T(1) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The translation component of the rigid transformation.
			Vector2D<T> position;
			
			
			
			
			/// The rotation component of the rigid transformation.
			Matrix2D<T> orientation;
			
			
			
			
			/// The scaling component of the rigid transformation.
			Vector2D<T> scale;
			
			
			
			
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
RIM_FORCE_INLINE T operator * ( T value, const Transform2D<T>& transform )
{
	return transform.transformToWorldSpace( value );
}




/// Transform the specified vector to object space with the inverse of the specified transformation.
template < typename T >
RIM_FORCE_INLINE Vector2D<T> operator * ( const Vector2D<T>& vector, const Transform2D<T>& transform )
{
	return transform.transformToObjectSpace( vector );
}




/// Transform the specified matrix to object space with the inverse of the specified transformation.
template < typename T >
RIM_FORCE_INLINE Matrix2D<T> operator * ( const Matrix2D<T>& matrix, const Transform2D<T>& transform )
{
	return transform.transformToObjectSpace( matrix );
}




/// Transform the specified ray to object space with the inverse of the specified transformation.
template < typename T >
RIM_FORCE_INLINE Ray2D<T> operator * ( const Ray2D<T>& ray, const Transform2D<T>& transform )
{
	return transform.transformToObjectSpace( ray );
}




/// Transform the specified plane to object space with the inverse of the specified transformation.
template < typename T >
RIM_FORCE_INLINE Plane2D<T> operator * ( const Plane2D<T>& plane, const Transform2D<T>& transform )
{
	return transform.transformToObjectSpace( plane );
}




//##########################################################################################
//##########################################################################################
//############		
//############		2D Transform Type Definitions
//############		
//##########################################################################################
//##########################################################################################




typedef Transform2D<int>		Transform2i;
typedef Transform2D<float>		Transform2f;
typedef Transform2D<double>	Transform2d;




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_TRANSFORM_2D_H
