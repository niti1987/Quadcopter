/*
 *  rimMatrix3D.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 10/5/06.
 *  Copyright 2006 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_MATRIX_3D_H
#define INCLUDE_RIM_MATRIX_3D_H


#include "rimMathConfig.h"


#include "../data/rimBasicString.h"
#include "../data/rimBasicStringBuffer.h"
#include "rimVector3D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a 3x3 matrix.
/**
  * Elements in the matrix are stored in column-major order.
  */
template < typename T>
class Matrix3D
{
	public:
	
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a 3x3 matrix with all elements equal to zero.
			RIM_FORCE_INLINE Matrix3D<T>()
				:	x( 0, 0, 0 ),
					y( 0, 0, 0 ),
					z( 0, 0, 0 )
			{
			}
			
			
			
			
			/// Create a 3x3 matrix from three column vectors.
			RIM_FORCE_INLINE Matrix3D<T>(	const Vector3D<T>& column1, 
											const Vector3D<T>& column2, 
											const Vector3D<T>& column3 )
				:	x( column1 ),
					y( column2 ),
					z( column3 )
			{
			}
			
			
			
			
			/// Create a 3x3 matrix with elements specified in row-major order.
			RIM_FORCE_INLINE Matrix3D<T>(	T a, T b, T c, 
											T d, T e, T f, 
											T g, T h, T i )
				:	x( a, d, g ),
					y( b, e, h ),
					z( c, f, i )
			{
			}
			
			
			
			
			/// Create a 3x3 matrix from a pointer to an array of elements in column-major order.
			RIM_FORCE_INLINE explicit Matrix3D<T>( const T* array )
				:	x( array[0], array[3], array[6] ),
					y( array[1], array[4], array[7] ),
					z( array[2], array[5], array[8] )
			{
			}
			
			
			
			
			/// Create an identity matrx with the specified 2x2 matrix in the upper-left corner.
			template < typename U >
			RIM_FORCE_INLINE explicit Matrix3D( const Matrix2D<U>& other )
				:	x( other.x, T(0) ),
					y( other.y, T(0) ),
					z( T(0), T(0), T(1) )
			{
			}
			
			
			
			
			/// Create a copy of the specified 3x3 matrix with different template parameter type.
			template < typename U >
			RIM_FORCE_INLINE Matrix3D( const Matrix3D<U>& other )
				:	x( other.x ),
					y( other.y ),
					z( other.z )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Matrix Constructors
			
			
			
			
			/// Return a skew-symmetric matrix using the elements of the specified vector.
			RIM_FORCE_INLINE static Matrix3D<T> skewSymmetric( const Vector3D<T>& vector )
			{
				return Matrix3D<T>( 0, -vector.z, vector.y, vector.z, 0, -vector.x, -vector.y, vector.x, 0 );
			}
			
			
			
			
			/// Return an orthogonal matrix defining a basis for the coordinate frame of a plane with the specified normal.
			/**
			  * TODO: Fix this so that it handles zero vectors gracefully.
			  */
			RIM_FORCE_INLINE static Matrix3D<T> planeBasis( const Vector3D<T>& normal )
			{
				Vector3D<T> binormal;
				Vector3D<T> n = math::abs(normal);
				
				if ( n.x <= n.y && n.x <= n.z )
					binormal = Vector3D<T>( T(0), -normal.z, normal.y ).normalize();
				
				if ( n.y <= n.x && n.y <= n.z )
					binormal = Vector3D<T>( -normal.z, T(0), normal.x ).normalize();
				
				if ( n.z <= n.x && n.z <= n.y )
					binormal = Vector3D<T>( -normal.y, normal.x, T(0) ).normalize();
				
				return Matrix3D<T>( math::cross( binormal, normal ), binormal, normal );
			}
			
			
			
			
			/// Create a 3x3 rotation matrix about the X-axis with the angle in radians.
			RIM_FORCE_INLINE static Matrix3D<T> rotationX( T xRotation )
			{
				return Matrix3D<T>(	1,	0,				0,
									0,	math::cos(xRotation),	math::sin(xRotation),
									0, -math::sin(xRotation),	math::cos(xRotation) );
			}
			
			
			
			
			/// Create a 3x3 rotation matrix about the Y-axis with the angle in radians.
			RIM_FORCE_INLINE static Matrix3D<T> rotationY( T yRotation )
			{
				return Matrix3D<T>(	math::cos(yRotation),	0, -math::sin(yRotation),
									0,				1,	0,
									math::sin(yRotation),	0,	math::cos(yRotation) );
			}
			
			
			
			
			/// Create a 3x3 rotation matrix about the Z-axis with the angle in radians.
			RIM_FORCE_INLINE static Matrix3D<T> rotationZ( T zRotation )
			{
				return Matrix3D<T>(	math::cos(zRotation),	math::sin(zRotation),	0,
									-math::sin(zRotation),	math::cos(zRotation),	0, 
									0,				0,				1 );
			}
			
			
			
			
			/// Create a 3x3 rotation matrix about the X-axis with the angle in degrees.
			RIM_FORCE_INLINE static Matrix3D<T> rotationXDegrees( T xRotation )
			{
				return rotationX( math::degreesToRadians(xRotation) );
			}
			
			
			
			
			/// Create a 3x3 rotation matrix about the Y-axis with the angle in degrees.
			RIM_FORCE_INLINE static Matrix3D<T> rotationYDegrees( T yRotation )
			{
				return rotationY( math::degreesToRadians(yRotation) );
			}
			
			
			
			
			/// Create a 3x3 rotation matrix about the Z-axis with the angle in degrees.
			RIM_FORCE_INLINE static Matrix3D<T> rotationZDegrees( T zRotation )
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
				outputArray[0] = x.x;	outputArray[1] = y.x;	outputArray[2] = z.x;
				outputArray[3] = x.y;	outputArray[4] = y.y;	outputArray[5] = z.y;
				outputArray[6] = x.z;	outputArray[7] = y.z;	outputArray[8] = z.z;
			}
			
			
			
			
			/// Get the column at the specified index in the matrix.
			RIM_FORCE_INLINE Vector3D<T>& getColumn( Index columnIndex )
			{
				RIM_DEBUG_ASSERT( columnIndex < 3 );
				
				return (&x)[columnIndex];
			}
			
			
			
			
			/// Get the column at the specified index in the matrix.
			RIM_FORCE_INLINE const Vector3D<T>& getColumn( Index columnIndex ) const
			{
				RIM_DEBUG_ASSERT( columnIndex < 3 );
				
				return (&x)[columnIndex];
			}
			
			
			
			
			/// Get the column at the specified index in the matrix.
			RIM_FORCE_INLINE Vector3D<T>& operator () ( Index columnIndex )
			{
				RIM_DEBUG_ASSERT( columnIndex < 3 );
				
				return (&x)[columnIndex];
			}
			
			
			
			
			/// Get the column at the specified index in the matrix.
			RIM_FORCE_INLINE const Vector3D<T>& operator () ( Index columnIndex ) const
			{
				RIM_DEBUG_ASSERT( columnIndex < 3 );
				
				return (&x)[columnIndex];
			}
			
			
			
			
			/// Get the column at the specified index in the matrix.
			RIM_FORCE_INLINE Vector3D<T>& operator [] ( Index columnIndex )
			{
				RIM_DEBUG_ASSERT( columnIndex < 3 );
				
				return (&x)[columnIndex];
			}
			
			
			
			
			/// Get the column at the specified index in the matrix.
			RIM_FORCE_INLINE const Vector3D<T>& operator [] ( Index columnIndex ) const
			{
				RIM_DEBUG_ASSERT( columnIndex < 3 );
				
				return (&x)[columnIndex];
			}
			
			
			
			
			/// Get the row at the specified index in the matrix.
			RIM_FORCE_INLINE Vector3D<T> getRow( Index rowIndex ) const
			{
				RIM_DEBUG_ASSERT( rowIndex < 3 );
				
				switch ( rowIndex )
				{
					case 0: return Vector3D<T>( x.x, y.x, z.x );
					case 1: return Vector3D<T>( x.y, y.y, z.y );
					case 2: return Vector3D<T>( x.z, y.z, z.z );
					default: return Vector3D<T>::ZERO;
				}
			}
			
			
			
			
			/// Get the element at the specified (column, row) index in the matrix.
			RIM_FORCE_INLINE T& get( Index columnIndex, Index rowIndex )
			{
				RIM_DEBUG_ASSERT( columnIndex < 3 && rowIndex < 3 );
				
				return (&x)[columnIndex][rowIndex];
			}
			
			
			
			
			/// Get the element at the specified (column, row) index in the matrix.
			RIM_FORCE_INLINE const T& get( Index columnIndex, Index rowIndex ) const
			{
				RIM_DEBUG_ASSERT( columnIndex < 3 && rowIndex < 3 );
				
				return (&x)[columnIndex][rowIndex];
			}
			
			
			
			
			/// Get the element at the specified (column, row) index in the matrix.
			RIM_FORCE_INLINE T& operator () ( Index columnIndex, Index rowIndex )
			{
				RIM_DEBUG_ASSERT( columnIndex < 3 && rowIndex < 3 );
				
				return (&x)[columnIndex][rowIndex];
			}
			
			
			
			
			/// Get the element at the specified (column, row) index in the matrix.
			RIM_FORCE_INLINE const T& operator () ( Index columnIndex, Index rowIndex ) const
			{
				RIM_DEBUG_ASSERT( columnIndex < 3 && rowIndex < 3 );
				
				return (&x)[columnIndex][rowIndex];
			}
			
			
			
			
			/// Set the element in the matrix at the specified (row, column) index.
			RIM_FORCE_INLINE void set( Index rowIndex, Index columnIndex, T value )
			{
				RIM_DEBUG_ASSERT( rowIndex < 3 && columnIndex < 3 );
				
				return (&x)[columnIndex][rowIndex] = value;
			}
			
			
			
			
			/// Set the column in the matrix at the specified index.
			RIM_FORCE_INLINE void setColumn( Index columnIndex, const Vector3D<T>& newColumn )
			{
				RIM_DEBUG_ASSERT( columnIndex < 3 );
				
				(&x)[columnIndex] = newColumn;
			}
			
			
			
			
			/// Set the row in the matrix at the specified index.
			RIM_FORCE_INLINE void setRow( Index rowIndex, const Vector3D<T>& newRow )
			{
				RIM_DEBUG_ASSERT( rowIndex < 3 );
				
				switch ( rowIndex )
				{
					case 0: x.x = newRow.x;	y.x = newRow.y;	z.x = newRow.z; return;
					case 1: x.y = newRow.x;	y.y = newRow.y;	z.y = newRow.z; return;
					case 2: x.z = newRow.x;	y.z = newRow.y;	z.z = newRow.z; return;
				}
			}
			
			
			
			
			/// Return the diagonal vector of this matrix.
			RIM_FORCE_INLINE Vector3D<T> getDiagonal() const
			{
				return Vector3D<T>( x.x, y.y, z.z );
			}
			
			
			
			
			/// Return the upper-left 2x2 submatrix of this matrix.
			RIM_FORCE_INLINE Matrix2D<T> getXY() const
			{
				return Matrix2D<T>( x.getXY(), y.getXY() );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Matrix Operation Methods
			
			
			
			
			/// Return the determinant of this matrix.
			RIM_FORCE_INLINE T getDeterminant() const
			{
				return x.x*( y.y*z.z - z.y*y.z ) - 
					   y.x*( x.y*z.z - z.y*x.z ) + 
					   z.x*( x.y*y.z - y.y*x.z );
			}
			
			
			
			
			/// Return the inverse of this matrix, or the zero matrix if the matrix has no inverse.
			/**
			  * Whether or not the matrix is invertable is determined by comparing the determinant
			  * to a threshold - if the absolute value of the determinant is less than the threshold,
			  * the matrix is not invertable.
			  */
			RIM_FORCE_INLINE Matrix3D<T> invert( T threshold = 0 ) const
			{
				T det = getDeterminant();
				
				if ( math::abs(det) <= threshold )
					return Matrix3D<T>::ZERO;
				
				T detInv = T(1)/det;
				
				return Matrix3D<T>(	(y.y*z.z - z.y*y.z)*detInv, 
									(z.x*y.z - y.x*z.z)*detInv,
									(y.x*z.y - z.x*y.y)*detInv,
									(z.y*x.z - x.y*z.z)*detInv,
									(x.x*z.z - z.x*x.z)*detInv,
									(z.x*x.y - x.x*z.y)*detInv,
									(x.y*y.z - y.y*x.z)*detInv,
									(y.x*x.z - x.x*y.z)*detInv,
									(x.x*y.y - y.x*x.y)*detInv );
			}
			
			
			
			
			/// Compute the inverse of this matrix, returning the result in the output parameter.
			/**
			  * The method returns whether or not the matrix was able to be inverted. This propery
			  * is determined by comparing the determinant to a threshold - if the absolute value of 
			  * the determinant is less than the threshold, the matrix is not invertable.
			  */
			RIM_FORCE_INLINE Bool invert( Matrix3D<T>& inverse, T threshold = 0 ) const
			{
				T det = getDeterminant();
				
				if ( math::abs(det) <= threshold )
					return false;
				
				T detInv = T(1)/det;
				
				inverse = Matrix3D<T>(	(y.y*z.z - z.y*y.z)*detInv, 
									(z.x*y.z - y.x*z.z)*detInv,
									(y.x*z.y - z.x*y.y)*detInv,
									(z.y*x.z - x.y*z.z)*detInv,
									(x.x*z.z - z.x*x.z)*detInv,
									(z.x*x.y - x.x*z.y)*detInv,
									(x.y*y.z - y.y*x.z)*detInv,
									(y.x*x.z - x.x*y.z)*detInv,
									(x.x*y.y - y.x*x.y)*detInv );
				
				return true;
			}
			
			
			
			
			/// Return the orthonormalization of this matrix.
			/**
			  * This matrix that is returned has all column vectors of unit
			  * length and perpendicular to each other.
			  */
			RIM_FORCE_INLINE Matrix3D<T> orthonormalize() const
			{
				Vector3D<T> newX = x.normalize();
				Vector3D<T> newZ = cross( newX, y ).normalize();
				
				return Matrix3D( newX, cross( newZ, newX ).normalize(), newZ );
			}
			
			
			
			
			/// Return the transposition of this matrix.
			RIM_FORCE_INLINE Matrix3D<T> transpose() const
			{
				return Matrix3D( x.x, x.y, x.z,
								y.x, y.y, y.z,
								z.x, z.y, z.z );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Compare two matrices component-wise for equality.
			RIM_FORCE_INLINE Bool operator == ( const Matrix3D<T>& m ) const
			{
				return x == m.x && y == m.y && z == m.z;
			}
			
			
			
			
			
			/// Compare two matrices component-wise for inequality.
			RIM_FORCE_INLINE Bool operator != ( const Matrix3D<T>& m ) const
			{
				return x != m.x || y != m.y || z != m.z;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Matrix Negation/Positivation Operators
			
			
			
			
			/// Negate every element of this matrix and return the resulting matrix.
			RIM_FORCE_INLINE Matrix3D<T> operator - () const
			{
				return Matrix3D<T>( -x, -y, -z );
			}
			
			
			
			
			/// 'Positivate' every element of this matrix, returning a copy of the original matrix.
			RIM_FORCE_INLINE Matrix3D<T> operator + () const
			{
				return Matrix3D<T>( x, y, z );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Operators
			
			
			
			
			/// Add this matrix to another and return the resulting matrix.
			RIM_FORCE_INLINE Matrix3D<T> operator + ( const Matrix3D<T>& matrix ) const
			{
				return Matrix3D<T>( x + matrix.x, y + matrix.y, z + matrix.z );
			}
			
			
			
			
			/// Add a scalar to the elements of this matrix and return the resulting matrix.
			RIM_FORCE_INLINE Matrix3D<T> operator + ( const T& value ) const
			{
				return Matrix3D<T>( x + value, y + value, z + value );
			}
			
			
			
			
			/// Subtract a matrix from this matrix and return the resulting matrix.
			RIM_FORCE_INLINE Matrix3D<T> operator - ( const Matrix3D<T>& matrix ) const
			{
				return Matrix3D<T>( x - matrix.x, y - matrix.y, z - matrix.z );
			}
			
			
			
			
			/// Subtract a scalar from the elements of this matrix and return the resulting matrix.
			RIM_FORCE_INLINE Matrix3D<T> operator - ( const T& value ) const
			{
				return Matrix3D<T>( x - value, y - value, z - value );
			}
			
			
			
			
			/// Multiply a matrix by this matrix and return the result.
			RIM_FORCE_INLINE Matrix3D<T> operator * ( const Matrix3D<T>& matrix ) const
			{
				return Matrix3D<T>(	x.x*matrix.x.x + y.x*matrix.x.y + z.x*matrix.x.z,
									x.x*matrix.y.x + y.x*matrix.y.y + z.x*matrix.y.z,
									x.x*matrix.z.x + y.x*matrix.z.y + z.x*matrix.z.z,
									x.y*matrix.x.x + y.y*matrix.x.y + z.y*matrix.x.z,
									x.y*matrix.y.x + y.y*matrix.y.y + z.y*matrix.y.z,
									x.y*matrix.z.x + y.y*matrix.z.y + z.y*matrix.z.z,
									x.z*matrix.x.x + y.z*matrix.x.y + z.z*matrix.x.z,
									x.z*matrix.y.x + y.z*matrix.y.y + z.z*matrix.y.z,
									x.z*matrix.z.x + y.z*matrix.z.y + z.z*matrix.z.z );
			}

			
			
			
			/// Multiply a vector/point by this matrix and return the result.
			RIM_FORCE_INLINE Vector3D<T> operator * ( const Vector3D<T>& vector ) const
			{
				return Vector3D<T>(	x.x*vector.x + y.x*vector.y + z.x*vector.z,
									x.y*vector.x + y.y*vector.y + z.y*vector.z,
									x.z*vector.x + y.z*vector.y + z.z*vector.z );
			}
			
			
			
			
			/// Multiply the elements of this matrix by a scalar and return the resulting matrix.
			RIM_FORCE_INLINE Matrix3D<T> operator * ( const T& value ) const
			{
				return Matrix3D<T>( x*value, y*value, z*value );
			}
			
			
			
			
			/// Divide the elements of this matrix by a scalar and return the resulting matrix.
			RIM_FORCE_INLINE Matrix3D<T> operator / ( const T& value ) const
			{
				return Matrix3D<T>( x/value, y/value, z/value );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Assignment Operators
			
			
			
			
			/// Add the elements of another matrix to this matrix.
			RIM_FORCE_INLINE Matrix3D<T>& operator += ( const Matrix3D<T>& matrix )
			{
				x += matrix.x;
				y += matrix.y;
				z += matrix.z;
				
				return *this;
			}
			
			
			
			
			/// Add a scalar value to the elements of this matrix.
			RIM_FORCE_INLINE Matrix3D<T>& operator += ( const T& value )
			{
				x += value;
				y += value;
				z += value;
				
				return *this;
			}
			
			
			
			
			/// Subtract the elements of another matrix from this matrix.
			RIM_FORCE_INLINE Matrix3D<T>& operator -= ( const Matrix3D<T>& matrix )
			{
				x -= matrix.x;
				y -= matrix.y;
				z -= matrix.z;
				
				return *this;
			}
			
			
			
			
			/// Subtract a scalar value from the elements of this matrix.
			RIM_FORCE_INLINE Matrix3D<T>& operator -= ( const T& value )
			{
				x -= value;
				y -= value;
				z -= value;
				
				return *this;
			}
			
			
			
			
			/// Multiply the elements of this matrix by a scalar value.
			RIM_FORCE_INLINE Matrix3D<T>& operator *= ( const T& value )
			{
				x *= value;
				y *= value;
				z *= value;
				
				return *this;
			}
			
			
			
			
			/// Divide the elements of this matrix by a scalar value.
			RIM_FORCE_INLINE Matrix3D<T>& operator /= ( const T& value )
			{
				x /= value;
				y /= value;
				z /= value;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Conversion Methods
			
			
			
			
			/// Convert this 3x3 matrix into a human-readable string representation.
			RIM_NO_INLINE data::String toString() const
			{
				data::StringBuffer buffer;
				
				buffer << "[ " << x.x << ", " << y.x << ", " << z.x << " ]\n";
				buffer << "[ " << x.y << ", " << y.y << ", " << z.y << " ]\n";
				buffer << "[ " << x.z << ", " << y.z << ", " << z.z << " ]";
				
				return buffer.toString();
			}
			
			
			
			
			/// Convert this 3x3 matrix into a human-readable string representation.
			RIM_FORCE_INLINE operator data::String () const
			{
				return this->toString();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The first column vector of the matrix.
			Vector3D<T> x;
			
			
			
			
			/// The second column vector of the matrix.
			Vector3D<T> y;
			
			
			
			
			/// The third column vector of the matrix.
			Vector3D<T> z;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// Constant matrix with all elements equal to zero.
			static const Matrix3D<T> ZERO;
			
			
			
			
			/// Constant matrix with diagonal elements equal to one and all others equal to zero.
			static const Matrix3D<T> IDENTITY;
			
			
			
			
};




template < typename T >
const Matrix3D<T> Matrix3D<T>:: ZERO( T(0), T(0), T(0), T(0), T(0), T(0), T(0), T(0), T(0) );




template < typename T >
const Matrix3D<T> Matrix3D<T>:: IDENTITY( T(1), T(0), T(0), T(0), T(1), T(0), T(0), T(0), T(1) );




//##########################################################################################
//##########################################################################################
//############		
//############		Reverse Matrix Arithmetic Operators
//############		
//##########################################################################################
//##########################################################################################




/// Add a sclar value to a matrix's elements and return the resulting matrix
template < typename T >
RIM_FORCE_INLINE Matrix3D<T> operator + ( const T& value, const Matrix3D<T>& matrix )
{
	return Matrix3D<T>( matrix.x + value, matrix.y + value, matrix.z + value );
}





/// 'Reverse' multiply a vector/point by matrix: multiply it by the matrix's transpose.
template < typename T >
RIM_FORCE_INLINE Vector3D<T> operator * ( const Vector3D<T>& vector, const Matrix3D<T>& matrix )
{	
	return Vector3D<T>(  matrix.x.x * vector.x + matrix.x.y * vector.y + matrix.x.z * vector.z,
						matrix.y.x * vector.x + matrix.y.y * vector.y + matrix.y.z * vector.z,
						matrix.z.x * vector.x + matrix.z.y * vector.y + matrix.z.z * vector.z );
}




/// Multiply a matrix's elements by a scalar and return the resulting matrix
template < typename T >
RIM_FORCE_INLINE Matrix3D<T> operator * ( const T& value, const Matrix3D<T>& matrix )
{
	return Matrix3D<T>( matrix.x*value, matrix.y*value, matrix.z*value );
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
RIM_FORCE_INLINE Matrix3D<T> abs( const Matrix3D<T>& matrix )
{
	return Matrix3D<T>(	math::abs(matrix.x.x), math::abs(matrix.y.x), math::abs(matrix.z.x),
						math::abs(matrix.x.y), math::abs(matrix.y.y), math::abs(matrix.z.y),
						math::abs(matrix.x.z), math::abs(matrix.y.z), math::abs(matrix.z.z) );
}




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_MATRIX_3D_H
