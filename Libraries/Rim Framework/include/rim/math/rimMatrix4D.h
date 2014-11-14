/*
 *  rimMatrix4D.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 1/23/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */


#ifndef INCLUDE_RIM_MATRIX_4D_H
#define INCLUDE_RIM_MATRIX_4D_H


#include "rimMathConfig.h"


#include "../data/rimBasicString.h"
#include "../data/rimBasicStringBuffer.h"
#include "rimVector4D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a 4x4 matrix.
/**
  * Elements in the matrix are stored in column-major order.
  */
template < typename T>
class Matrix4D
{
	public:
	
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a 4x4 matrix with all elements equal to zero.
			RIM_FORCE_INLINE Matrix4D<T>()
				:	x( 0, 0, 0, 0 ),
					y( 0, 0, 0, 0 ),
					z( 0, 0, 0, 0 ),
					w( 0, 0, 0, 0 )
			{
			}
			
			
			
			
			/// Create a 4x4 matrix from four column vectors.
			RIM_FORCE_INLINE Matrix4D<T>(	const Vector4D<T>& col1, 
											const Vector4D<T>& col2, 
											const Vector4D<T>& col3, 
											const Vector4D<T>& col4 )
				:	x( col1 ),
					y( col2 ),
					z( col3 ),
					w( col4 )
			{
			}
			
			
			
			
			/// Create a 4x4 matrix with elements specified in row-major order.
			RIM_FORCE_INLINE Matrix4D<T>(	T a, T b, T c, T d,
											T e, T f, T g, T h,
											T i, T j, T k, T l,
											T m, T n, T o, T p )
				:	x( a, e, i, m ),
					y( b, f, j, n ),
					z( c, g, k, o ),
					w( d, h, l, p )
			{
			}
			
			
			
			/// Create a 4x4 matrix from a pointer to an array of elements in column-major order.
			RIM_FORCE_INLINE explicit Matrix4D<T>( const T* array )
				:	x( array[0], array[4], array[8], array[12] ),
					y( array[1], array[5], array[9], array[13] ),
					z( array[2], array[6], array[10], array[14] ),
					w( array[3], array[7], array[11], array[15] )
			{
			}
			
			
			
			
			/// Create an identity matrx with the specified 2x2 matrix in the upper-left corner.
			template < typename U >
			RIM_FORCE_INLINE explicit Matrix4D( const Matrix2D<U>& other )
				:	x( other.x, T(0), T(0) ),
					y( other.y, T(0), T(0) ),
					z( T(0), T(0), T(1), T(0) ),
					w( T(0), T(0), T(0), T(1) )
			{
			}
			
			
			
			
			/// Create an identity matrx with the specified 3x3 matrix in the upper-left corner.
			template < typename U >
			RIM_FORCE_INLINE explicit Matrix4D( const Matrix3D<U>& other )
				:	x( other.x, T(0) ),
					y( other.y, T(0) ),
					z( other.z, T(0) ),
					w( T(0), T(0), T(0), T(1) )
			{
			}
			
			
			
			
			/// Create a copy of the specified 4x4 matrix with different template parameter type.
			template < typename U >
			RIM_FORCE_INLINE Matrix4D( const Matrix4D<U>& other )
				:	x( other.x ),
					y( other.y ),
					z( other.z ),
					w( other.w )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Matrix Constructors
			
			
			
			
			/// Create a 4x4 rotation matrix about the X-axis with the angle in radians.
			RIM_FORCE_INLINE static Matrix4D<T> rotationX( T xRotation )
			{
				return Matrix4D<T>(	1,	0,						0,						0,
									0,	math::cos(xRotation),	math::sin(xRotation),	0,
									0, -math::sin(xRotation),	math::cos(xRotation),	0,
									0,	0,						0,						1 );
			}
			
			
			
			
			/// Create a 4x4 rotation matrix about the Y-axis with the angle in radians.
			RIM_FORCE_INLINE static Matrix4D<T> rotationY( T yRotation )
			{
				return Matrix4D<T>(	math::cos(yRotation),	0, -math::sin(yRotation),	0,
									0,						1,	0,						0,
									math::sin(yRotation),	0,	math::cos(yRotation),	0,
									0,						0,	0,						1 );
			}
			
			
			
			
			/// Create a 4x4 rotation matrix about the Z-axis with the angle in radians.
			RIM_FORCE_INLINE static Matrix4D<T> rotationZ( T zRotation )
			{
				return Matrix4D<T>(	math::cos(zRotation),	math::sin(zRotation),	0,	0,
									-math::sin(zRotation),	math::cos(zRotation),	0,	0,
									0,						0,						1,	0,
									0,						0,						0,	1 );
			}
			
			
			
			
			/// Create a 4x4 rotation matrix about the X-axis with the angle in degrees.
			RIM_FORCE_INLINE static Matrix4D<T> rotationXDegrees( T xRotation )
			{
				return rotationX( math::degreesToRadians(xRotation) );
			}
			
			
			
			
			/// Create a 4x4 rotation matrix about the Y-axis with the angle in degrees.
			RIM_FORCE_INLINE static Matrix4D<T> rotationYDegrees( T yRotation )
			{
				return rotationY( math::degreesToRadians(yRotation) );
			}
			
			
			
			
			/// Create a 4x4 rotation matrix about the Z-axis with the angle in degrees.
			RIM_FORCE_INLINE static Matrix4D<T> rotationZDegrees( T zRotation )
			{
				return rotationZ( math::degreesToRadians(zRotation) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Accessor Methods
			
			
			
			
			/// Return a pointer to the matrix's elements in colunn-major order.
			/**
			  * Since matrix elements are stored in column-major order,
			  * no allocation is performed and the elements are accessed directly.
			  */
			RIM_FORCE_INLINE T* toArrayColumnMajor()
			{
				return (T*)&x;
			}
			
			
			
			
			/// Return a pointer to the matrix's elements in colunn-major order.
			/**
			  * Since matrix elements are stored in column-major order,
			  * no allocation is performed and the elements are accessed directly.
			  */
			RIM_FORCE_INLINE const T* toArrayColumnMajor() const
			{
				return (T*)&x;
			}
			
			
			
			
			/// Place the elements of the matrix at the location specified in row-major order.
			/**
			  * The output array must be at least 9 elements long.
			  */
			RIM_FORCE_INLINE void toArrayRowMajor( T* outputArray ) const
			{
				outputArray[0] = x.x;	outputArray[1] = y.x;	outputArray[2] = z.x;	outputArray[3] = w.x;
				outputArray[4] = x.y;	outputArray[5] = y.y;	outputArray[6] = z.y;	outputArray[7] = w.y;
				outputArray[8] = x.z;	outputArray[9] = y.z;	outputArray[10] = z.z;	outputArray[11] = w.z;
				outputArray[12] = x.w;	outputArray[13] = y.w;	outputArray[14] = z.w;	outputArray[15] = w.w;
			}
			
			
			
			
			/// Get the column at the specified index in the matrix.
			RIM_FORCE_INLINE Vector4D<T>& getColumn( Index columnIndex )
			{
				RIM_DEBUG_ASSERT( columnIndex < 4 );
				
				return (&x)[columnIndex];
			}
			
			
			
			
			/// Get the column at the specified index in the matrix.
			RIM_FORCE_INLINE const Vector4D<T>& getColumn( Index columnIndex ) const
			{
				RIM_DEBUG_ASSERT( columnIndex < 4 );
				
				return (&x)[columnIndex];
			}
			
			
			
			
			/// Get the column at the specified index in the matrix.
			RIM_FORCE_INLINE Vector4D<T>& operator () ( Index columnIndex )
			{
				RIM_DEBUG_ASSERT( columnIndex < 4 );
				
				return (&x)[columnIndex];
			}
			
			
			
			
			/// Get the column at the specified index in the matrix.
			RIM_FORCE_INLINE const Vector4D<T>& operator () ( Index columnIndex ) const
			{
				RIM_DEBUG_ASSERT( columnIndex < 4 );
				
				return (&x)[columnIndex];
			}
			
			
			
			
			/// Get the column at the specified index in the matrix.
			RIM_FORCE_INLINE Vector4D<T>& operator [] ( Index columnIndex )
			{
				RIM_DEBUG_ASSERT( columnIndex < 4 );
				
				return (&x)[columnIndex];
			}
			
			
			
			
			/// Get the column at the specified index in the matrix.
			RIM_FORCE_INLINE const Vector4D<T>& operator [] ( Index columnIndex ) const
			{
				RIM_DEBUG_ASSERT( columnIndex < 4 );
				
				return (&x)[columnIndex];
			}
			
			
			
			
			/// Get the row at the specified index in the matrix.
			RIM_FORCE_INLINE Vector4D<T> getRow( Index rowIndex ) const
			{
				RIM_DEBUG_ASSERT( rowIndex < 4 );
				
				switch ( rowIndex )
				{
					case 0: return Vector4D<T>( x.x, y.x, z.x );
					case 1: return Vector4D<T>( x.y, y.y, z.y );
					case 2: return Vector4D<T>( x.z, y.z, z.z );
					case 3: return Vector4D<T>( x.z, y.z, z.z );
					default: return Vector4D<T>::ZERO;
				}
			}
			
			
			
			
			/// Get the element at the specified (column, row) index in the matrix.
			RIM_FORCE_INLINE T& get( Index columnIndex, Index rowIndex )
			{
				RIM_DEBUG_ASSERT( columnIndex < 4 && rowIndex < 4 );
				
				return (&x)[columnIndex][rowIndex];
			}
			
			
			
			
			/// Get the element at the specified (column, row) index in the matrix.
			RIM_FORCE_INLINE const T& get( Index columnIndex, Index rowIndex ) const
			{
				RIM_DEBUG_ASSERT( columnIndex < 4 && rowIndex < 4 );
				
				return (&x)[columnIndex][rowIndex];
			}
			
			
			
			
			/// Get the element at the specified (column, row) index in the matrix.
			RIM_FORCE_INLINE T& operator () ( Index columnIndex, Index rowIndex )
			{
				RIM_DEBUG_ASSERT( columnIndex < 4 && rowIndex < 4 );
				
				return (&x)[columnIndex][rowIndex];
			}
			
			
			
			
			/// Get the element at the specified (column, row) index in the matrix.
			RIM_FORCE_INLINE const T& operator () ( Index columnIndex, Index rowIndex ) const
			{
				RIM_DEBUG_ASSERT( columnIndex < 4 && rowIndex < 4 );
				
				return (&x)[columnIndex][rowIndex];
			}
			
			
			
			
			/// Set the element in the matrix at the specified (column, row) index.
			RIM_FORCE_INLINE void set( Index columnIndex, Index rowIndex, T value )
			{
				RIM_DEBUG_ASSERT( columnIndex < 4 && rowIndex < 4 );
				
				return (&x)[columnIndex][rowIndex] = value;
			}
			
			
			
			
			/// Set the column in the matrix at the specified index.
			RIM_FORCE_INLINE void setColumn( Index columnIndex, const Vector4D<T>& newColumn )
			{
				RIM_DEBUG_ASSERT( columnIndex < 4 );
				
				(&x)[columnIndex] = newColumn;
			}
			
			
			
			
			/// Set the row in the matrix at the specified index.
			RIM_FORCE_INLINE void setRow( Index rowIndex, const Vector4D<T>& newRow )
			{
				RIM_DEBUG_ASSERT( rowIndex < 4 );
				
				switch ( rowIndex )
				{
					case 0: x.x = newRow.x;	y.x = newRow.y;	z.x = newRow.z;	w.x = newRow.w; return;
					case 1: x.y = newRow.x;	y.y = newRow.y;	z.y = newRow.z;	w.y = newRow.w; return;
					case 2: x.z = newRow.x;	y.z = newRow.y;	z.z = newRow.z;	w.z = newRow.w; return;
					case 3: x.w = newRow.x;	y.w = newRow.y;	z.w = newRow.z;	w.w = newRow.w; return;
				}
			}
			
			
			
			
			/// Return the diagonal vector of this matrix.
			RIM_FORCE_INLINE Vector4D<T> getDiagonal() const
			{
				return Vector4D<T>( x.x, y.y, z.z, w.w );
			}
			
			
			
			
			/// Return the upper-left 2x2 submatrix of this matrix.
			RIM_FORCE_INLINE Matrix2D<T> getXY() const
			{
				return Matrix2D<T>( x.getXY(), y.getXY() );
			}
			
			
			
			
			/// Return the upper-left 3x3 submatrix of this matrix.
			RIM_FORCE_INLINE Matrix3D<T> getXYZ() const
			{
				return Matrix3D<T>( x.getXYZ(), y.getXYZ(), z.getXYZ() );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Matrix Operation Methods
			
			
			
			
			/// Return the determinant of this matrix.
			RIM_FORCE_INLINE T getDeterminant() const
			{
				T s0 = (x.x*y.y - y.x*x.y);
				T s1 = (x.x*z.y - z.x*x.y);
				T s2 = (x.x*w.y - w.x*x.y);
				T s3 = (y.x*z.y - z.x*y.y);
				T s4 = (y.x*w.y - w.x*y.y);
				T s5 = (z.x*w.y - w.x*z.y);
				T c0 = (z.z*w.w - w.z*z.w);
				T c1 = (y.z*w.w - w.z*y.w);
				T c2 = (y.z*z.w - z.z*y.w);
				T c3 = (x.z*w.w - w.z*x.w);
				T c4 = (x.z*z.w - z.z*x.w);
				T c5 = (x.z*y.w - y.z*x.w);
				
				return s0*c0 - s1*c1 + s2*c2 + s3*c3 - s4*c4 + s5*c5;
			}
			
			
			
			
			/// Return the inverse of this matrix, or the zero matrix if the matrix has no inverse.
			/**
			  * Whether or not the matrix is invertable is determined by comparing the determinant
			  * to a threshold - if the absolute value of the determinant is less than the threshold,
			  * the matrix is not invertable.
			  */
			RIM_FORCE_INLINE Matrix4D<T> invert( T threshold = 0 ) const
			{
				T det = getDeterminant();
				
				if ( math::abs(det) <= threshold )
					return Matrix4D<T>::ZERO;
				
				T detInv = T(1)/det;
				
				return Matrix4D<T>(
					((z.y*w.z - w.y*z.z)*y.w + (w.y*y.z - y.y*w.z)*z.w - (z.y*y.z - y.y*z.z)*w.w) * detInv,
					((w.x*z.z - z.x*w.z)*y.w - (w.x*y.z - y.x*w.z)*z.w + (z.x*y.z - y.x*z.z)*w.w) * detInv,
					((z.x*w.y - w.x*z.y)*y.w + (w.x*y.y - y.x*w.y)*z.w - (z.x*y.y - y.x*z.y)*w.w) * detInv,
					((w.x*z.y - z.x*w.y)*y.z - (w.x*y.y - y.x*w.y)*z.z + (z.x*y.y - y.x*z.y)*w.z) * detInv,
					((w.y*z.z - z.y*w.z)*x.w - (w.y*x.z - x.y*w.z)*z.w + (z.y*x.z - x.y*z.z)*w.w) * detInv,
					((z.x*w.z - w.x*z.z)*x.w + (w.x*x.z - x.x*w.z)*z.w - (z.x*x.z - x.x*z.z)*w.w) * detInv,
					((w.x*z.y - z.x*w.y)*x.w - (w.x*x.y - x.x*w.y)*z.w + (z.x*x.y - x.x*z.y)*w.w) * detInv,
					((z.x*w.y - w.x*z.y)*x.z + (w.x*x.y - x.x*w.y)*z.z - (z.x*x.y - x.x*z.y)*w.z) * detInv,
					((y.y*w.z - w.y*y.z)*x.w + (w.y*x.z - x.y*w.z)*y.w - (y.y*x.z - x.y*y.z)*w.w) * detInv,
					((w.x*y.z - y.x*w.z)*x.w - (w.x*x.z - x.x*w.z)*y.w + (y.x*x.z - x.x*y.z)*w.w) * detInv,
					((y.x*w.y - w.x*y.y)*x.w + (w.x*x.y - x.x*w.y)*y.w - (y.x*x.y - x.x*y.y)*w.w) * detInv,
					((w.x*y.y - y.x*w.y)*x.z - (w.x*x.y - x.x*w.y)*y.z + (y.x*x.y - x.x*y.y)*w.z) * detInv,
					((z.y*y.z - y.y*z.z)*x.w - (z.y*x.z - x.y*z.z)*y.w + (y.y*x.z - x.y*y.z)*z.w) * detInv,
					((y.x*z.z - z.x*y.z)*x.w + (z.x*x.z - x.x*z.z)*y.w - (y.x*x.z - x.x*y.z)*z.w) * detInv,
					((z.x*y.y - y.x*z.y)*x.w - (z.x*x.y - x.x*z.y)*y.w + (y.x*x.y - x.x*y.y)*z.w) * detInv,
					((y.x*z.y - z.x*y.y)*x.z + (z.x*x.y - x.x*z.y)*y.z - (y.x*x.y - x.x*y.y)*z.z) * detInv );
			}
			
			
			
			
			/// Compute the inverse of this matrix, returning the result in the output parameter.
			/**
			  * The method returns whether or not the matrix was able to be inverted. This propery
			  * is determined by comparing the determinant to a threshold - if the absolute value of 
			  * the determinant is less than the threshold, the matrix is not invertable.
			  */
			RIM_FORCE_INLINE Bool invert( Matrix4D<T>& inverse, T threshold = 0 ) const
			{
				T det = getDeterminant();
				
				if ( math::abs(det) <= threshold )
					return false;
				
				T detInv = T(1)/det;
				
				inverse = Matrix4D<T>(
					((z.y*w.z - w.y*z.z)*y.w + (w.y*y.z - y.y*w.z)*z.w - (z.y*y.z - y.y*z.z)*w.w) * detInv,
					((w.x*z.z - z.x*w.z)*y.w - (w.x*y.z - y.x*w.z)*z.w + (z.x*y.z - y.x*z.z)*w.w) * detInv,
					((z.x*w.y - w.x*z.y)*y.w + (w.x*y.y - y.x*w.y)*z.w - (z.x*y.y - y.x*z.y)*w.w) * detInv,
					((w.x*z.y - z.x*w.y)*y.z - (w.x*y.y - y.x*w.y)*z.z + (z.x*y.y - y.x*z.y)*w.z) * detInv,
					((w.y*z.z - z.y*w.z)*x.w - (w.y*x.z - x.y*w.z)*z.w + (z.y*x.z - x.y*z.z)*w.w) * detInv,
					((z.x*w.z - w.x*z.z)*x.w + (w.x*x.z - x.x*w.z)*z.w - (z.x*x.z - x.x*z.z)*w.w) * detInv,
					((w.x*z.y - z.x*w.y)*x.w - (w.x*x.y - x.x*w.y)*z.w + (z.x*x.y - x.x*z.y)*w.w) * detInv,
					((z.x*w.y - w.x*z.y)*x.z + (w.x*x.y - x.x*w.y)*z.z - (z.x*x.y - x.x*z.y)*w.z) * detInv,
					((y.y*w.z - w.y*y.z)*x.w + (w.y*x.z - x.y*w.z)*y.w - (y.y*x.z - x.y*y.z)*w.w) * detInv,
					((w.x*y.z - y.x*w.z)*x.w - (w.x*x.z - x.x*w.z)*y.w + (y.x*x.z - x.x*y.z)*w.w) * detInv,
					((y.x*w.y - w.x*y.y)*x.w + (w.x*x.y - x.x*w.y)*y.w - (y.x*x.y - x.x*y.y)*w.w) * detInv,
					((w.x*y.y - y.x*w.y)*x.z - (w.x*x.y - x.x*w.y)*y.z + (y.x*x.y - x.x*y.y)*w.z) * detInv,
					((z.y*y.z - y.y*z.z)*x.w - (z.y*x.z - x.y*z.z)*y.w + (y.y*x.z - x.y*y.z)*z.w) * detInv,
					((y.x*z.z - z.x*y.z)*x.w + (z.x*x.z - x.x*z.z)*y.w - (y.x*x.z - x.x*y.z)*z.w) * detInv,
					((z.x*y.y - y.x*z.y)*x.w - (z.x*x.y - x.x*z.y)*y.w + (y.x*x.y - x.x*y.y)*z.w) * detInv,
					((y.x*z.y - z.x*y.y)*x.z + (z.x*x.y - x.x*z.y)*y.z - (y.x*x.y - x.x*y.y)*z.z) * detInv );
				
				return true;
			}
			
			
			
			
			/// Return the orthonormalization of this matrix.
			/**
			  * This matrix that is returned has all column vectors of unit
			  * length and perpendicular to each other.
			  */
			RIM_FORCE_INLINE Matrix4D<T> orthonormalize() const
			{
				Vector4D<T> newX = x.normalize();
				Vector4D<T> newY = (y - y.projectOnNormalized( newX )).normalize();
				Vector4D<T> newZ = (z - z.projectOnNormalized( newX ) - z.projectOnNormalized( newY )).normalize();
				Vector4D<T> newW = (w - w.projectOnNormalized( newX ) - w.projectOnNormalized( newY ) 
									- w.projectOnNormalized( newZ )).normalize();
				
				return Matrix4D( newX, newY, newZ, newW );
			}
			
			
			
			
			/// Return the transposition of this matrix.
			RIM_FORCE_INLINE Matrix4D<T> transpose() const
			{
				return Matrix4D<T>(	x.x, x.y, x.z, x.w,
									y.x, y.y, y.z, y.w,
									z.x, z.y, z.z, z.w,
									w.x, w.y, w.z, w.w );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Compare two matrices component-wise for equality
			RIM_FORCE_INLINE Bool operator == ( const Matrix4D<T>& m ) const
			{
				return x == m.x && y == m.y && z == m.z && w == m.w;
			}
			
			
			
			
			
			/// Compare two matrices component-wise for inequality
			RIM_FORCE_INLINE Bool operator != ( const Matrix4D<T>& m ) const
			{
				return x != m.x || y != m.y || z != m.z || w != m.w;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Matrix Negation/Positivation Operators
			
			
			
			
			/// Negate every element of this matrix and return the resulting matrix.
			RIM_FORCE_INLINE Matrix4D<T> operator - () const
			{
				return Matrix4D<T>( -x, -y, -z, -w );
			}
			
			
			
			
			/// 'Positivate' every element of this matrix, returning a copy of the original matrix.
			RIM_FORCE_INLINE Matrix4D<T> operator + () const
			{
				return Matrix4D<T>( x, y, z, w );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Operators
			
			
			
			
			/// Add this matrix to another and return the resulting matrix.
			RIM_FORCE_INLINE Matrix4D<T> operator + ( const Matrix4D<T>& matrix ) const
			{
				return Matrix4D<T>(	x + matrix.x, y + matrix.y, z + matrix.z, w + matrix.w );
			}
			
			
			
			
			/// Add a scalar to the elements of this matrix and return the resulting matrix.
			RIM_FORCE_INLINE Matrix4D<T> operator + ( const T& value ) const
			{
				return Matrix4D<T>( x + value, y + value, z + value, 2 + value );
			}
			
			
			
			
			/// Subtract a matrix from this matrix and return the resulting matrix.
			RIM_FORCE_INLINE Matrix4D<T> operator - ( const Matrix4D<T>& matrix ) const
			{
				return Matrix4D<T>(	x - matrix.x, y - matrix.y, z - matrix.z, w - matrix.w );
			}
			
			
			
			
			/// Subtract a scalar from the elements of this matrix and return the resulting matrix.
			RIM_FORCE_INLINE Matrix4D<T> operator - ( const T& value ) const
			{
				return Matrix4D<T>( x - value, y - value, z - value, w - value );
			}
			
			
			
			
			/// Multiply a matrix by this matrix and return the result.
			RIM_FORCE_INLINE Matrix4D<T> operator * ( const Matrix4D<T>& matrix ) const
			{
				return Matrix4D<T>(	x.x*matrix.x.x + y.x*matrix.x.y + z.x*matrix.x.z + w.x*matrix.x.w,
									x.x*matrix.y.x + y.x*matrix.y.y + z.x*matrix.y.z + w.x*matrix.y.w,
									x.x*matrix.z.x + y.x*matrix.z.y + z.x*matrix.z.z + w.x*matrix.z.w,
									x.x*matrix.w.x + y.x*matrix.w.y + z.x*matrix.w.z + w.x*matrix.w.w,
									x.y*matrix.x.x + y.y*matrix.x.y + z.y*matrix.x.z + w.y*matrix.x.w,
									x.y*matrix.y.x + y.y*matrix.y.y + z.y*matrix.y.z + w.y*matrix.y.w,
									x.y*matrix.z.x + y.y*matrix.z.y + z.y*matrix.z.z + w.y*matrix.z.w,
									x.y*matrix.w.x + y.y*matrix.w.y + z.y*matrix.w.z + w.y*matrix.w.w,
									x.z*matrix.x.x + y.z*matrix.x.y + z.z*matrix.x.z + w.z*matrix.x.w,
									x.z*matrix.y.x + y.z*matrix.y.y + z.z*matrix.y.z + w.z*matrix.y.w,
									x.z*matrix.z.x + y.z*matrix.z.y + z.z*matrix.z.z + w.z*matrix.z.w,
									x.z*matrix.w.x + y.z*matrix.w.y + z.z*matrix.w.z + w.z*matrix.w.w,
									x.w*matrix.x.x + y.w*matrix.x.y + z.w*matrix.x.z + w.w*matrix.x.w,
									x.w*matrix.y.x + y.w*matrix.y.y + z.w*matrix.y.z + w.w*matrix.y.w,
									x.w*matrix.z.x + y.w*matrix.z.y + z.w*matrix.z.z + w.w*matrix.z.w,
									x.w*matrix.w.x + y.w*matrix.w.y + z.w*matrix.w.z + w.w*matrix.w.w );
			}
			
			
			
			RIM_FORCE_INLINE Vector4D<T> operator * ( const Vector4D<T>& vector ) const
			{
				return Vector4D<T>( x.x*vector.x + y.x*vector.y + z.x*vector.z + w.x * vector.w,
									x.y*vector.x + y.y*vector.y + z.y*vector.z + w.y * vector.w,
									x.z*vector.x + y.z*vector.y + z.z*vector.z + w.z * vector.w,
									x.w*vector.x + y.w*vector.y + z.w*vector.z + w.w * vector.w );
			}
			
			
			
			
			/// Multiply the elements of this matrix by a scalar and return the resulting matrix.
			RIM_FORCE_INLINE Matrix4D<T> operator * ( const T& value ) const
			{
				return Matrix4D<T>( x*value, y*value, z*value, w*value );
			}
			
			
			
			
			/// Multiply the elements of this matrix by a scalar and return the resulting matrix.
			RIM_FORCE_INLINE Matrix4D<T> operator / ( const T& value ) const
			{
				return Matrix4D<T>( x/value, y/value, z/value, w/value );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Assignment Operators
			
			
			
			
			/// Add the elements of another matrix to this matrix.
			RIM_FORCE_INLINE Matrix4D<T>& operator += ( const Matrix4D<T>& matrix2 )
			{
				x += matrix2.x;
				y += matrix2.y;
				z += matrix2.z;
				w += matrix2.w;
				
				return *this;
			}
			
			
			
			
			/// Add a scalar value to the elements of this matrix.
			RIM_FORCE_INLINE Matrix4D<T>& operator += ( const T& value )
			{
				x += value;
				y += value;
				z += value;
				w += value;
				
				return *this;
			}
			
			
			
			
			/// Subtract the elements of another matrix from this matrix.
			RIM_FORCE_INLINE Matrix4D<T>& operator -= ( const Matrix4D<T>& matrix2 )
			{
				x -= matrix2.x;
				y -= matrix2.y;
				z -= matrix2.z;
				w -= matrix2.w;
				
				return *this;
			}
			
			
			
			
			/// Subtract a scalar value from the elements of this matrix.
			RIM_FORCE_INLINE Matrix4D<T>& operator -= ( const T& value )
			{
				x -= value;
				y -= value;
				z -= value;
				w -= value;
				
				return *this;
			}
			
			
			
			
			/// Multiply the elements of this matrix by a scalar value.
			RIM_FORCE_INLINE Matrix4D<T>& operator *= ( const T& value )
			{
				x *= value;
				y *= value;
				z *= value;
				w *= value;
				
				return *this;
			}
			
			
			
			
			/// Divide the elements of this matrix by a scalar value.
			RIM_FORCE_INLINE Matrix4D<T>& operator /= ( const T& value )
			{
				x /= value;
				y /= value;
				z /= value;
				w /= value;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Conversion Methods
			
			
			
			
			/// Convert this 4x4 matrix into a human-readable string representation.
			RIM_NO_INLINE data::String toString() const
			{
				data::StringBuffer buffer;
				
				buffer << "[ " << x.x << ", " << y.x << ", " << z.x << ", " << w.x << " ]\n";
				buffer << "[ " << x.y << ", " << y.y << ", " << z.y << ", " << w.y << " ]\n";
				buffer << "[ " << x.z << ", " << y.z << ", " << z.z << ", " << w.z << " ]\n";
				buffer << "[ " << x.w << ", " << y.w << ", " << z.w << ", " << w.w << " ]";
				
				return buffer.toString();
			}
			
			
			
			
			/// Convert this 4x4 matrix into a human-readable string representation.
			RIM_FORCE_INLINE operator data::String () const
			{
				return this->toString();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The first column vector of the matrix.
			Vector4D<T> x;
			
			
			
			
			/// The second column vector of the matrix.
			Vector4D<T> y;
			
			
			
			
			/// The third column vector of the matrix.
			Vector4D<T> z;
			
			
			
			
			/// The fourth column vector of the matrix.
			Vector4D<T> w;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// Constant matrix with all elements equal to zero.
			static const Matrix4D<T> ZERO;
			
			
			
			
			/// Constant matrix with diagonal elements equal to one and all others equal to zero.
			static const Matrix4D<T> IDENTITY;
			
			
			
			
};



 

template <typename T>
const Matrix4D<T> Matrix4D<T>:: ZERO(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);




template <typename T>
const Matrix4D<T> Matrix4D<T>:: IDENTITY(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);




//##########################################################################################
//##########################################################################################
//############		
//############		Reverse Matrix Arithmetic Operators
//############		
//##########################################################################################
//##########################################################################################




/// Add a sclar value to a matrix's elements and return the resulting matrix
template <class T>
RIM_FORCE_INLINE Matrix4D<T> operator + ( const T& value, const Matrix4D<T>& matrix )
{
	return Matrix4D<T>( value + matrix.x.x, value + matrix.y.x, value + matrix.z.x, value + matrix.w.x,
						   value + matrix.x.y, value + matrix.y.y, value + matrix.z.y, value + matrix.w.y,
						   value + matrix.x.z, value + matrix.y.z, value + matrix.z.z, value + matrix.w.z,
						   value + matrix.x.w, value + matrix.y.w, value + matrix.z.w, value + matrix.w.w );
}





/// 'Reverse' multiply a vector/point by matrix: multiply it by the matrix's transpose.
template < typename T >
RIM_FORCE_INLINE Vector4D<T> operator * ( const Vector4D<T>& vector, const Matrix4D<T>& matrix )
{	
	return Vector4D<T>(  matrix.x.x * vector.x + matrix.x.y * vector.y + matrix.x.z * vector.z + matrix.x.w * vector.w,
							matrix.y.x * vector.x + matrix.y.y * vector.y + matrix.y.z * vector.z + matrix.y.w * vector.w,
							matrix.z.x * vector.x + matrix.z.y * vector.y + matrix.z.z * vector.z + matrix.z.w * vector.w,
							matrix.w.x * vector.x + matrix.w.y * vector.y + matrix.w.z * vector.z + matrix.w.w * vector.w );
}




/// Multiply a matrix's elements by a scalar and return the resulting matrix
template <class T>
RIM_FORCE_INLINE Matrix4D<T> operator * ( const T& value, const Matrix4D<T>& matrix )
{
	return Matrix4D<T>( value * matrix.x.x, value * matrix.y.x, value * matrix.z.x, value * matrix.w.x,
						   value * matrix.x.y, value * matrix.y.y, value * matrix.z.y, value * matrix.w.y,
						   value * matrix.x.z, value * matrix.y.z, value * matrix.z.z, value * matrix.w.z,
						   value * matrix.x.w, value * matrix.y.w, value * matrix.z.w, value * matrix.w.w );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Other Matrix Functions
//############		
//##########################################################################################
//##########################################################################################




/// Return the absolute value of the specified matrix, such that the every component is positive.
template < typename T >
RIM_FORCE_INLINE Matrix4D<T> abs( const Matrix4D<T>& matrix )
{
	return Matrix4D<T>(	math::abs(matrix.x.x), math::abs(matrix.y.x), math::abs(matrix.z.x), math::abs(matrix.w.x),
						math::abs(matrix.x.y), math::abs(matrix.y.y), math::abs(matrix.z.y), math::abs(matrix.w.y),
						math::abs(matrix.x.z), math::abs(matrix.y.z), math::abs(matrix.z.z), math::abs(matrix.w.z), 
						math::abs(matrix.x.w), math::abs(matrix.y.w), math::abs(matrix.z.w), math::abs(matrix.w.w) );
}




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_MATRIX_4D_H
