/*
 *  rimMatrix.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/15/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_MATRIX_H
#define INCLUDE_RIM_MATRIX_H


#include "rimMathConfig.h"


#include "rimArrayMath.h"


#include "../data/rimBasicString.h"
#include "../data/rimBasicStringBuffer.h"
#include "../util/rimCopy.h"
#include "rimMatrix2D.h"
#include "rimMatrix3D.h"
#include "rimMatrix4D.h"
#include "rimMatrixND.h"
#include "rimVector2D.h"
#include "rimVector3D.h"
#include "rimVector4D.h"
#include "rimVectorND.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a matrix of a dynamic arbitrary number of rows and columns.
template < typename T >
class Matrix
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an empty matrix with 0 row and 0 columns.
			RIM_INLINE Matrix()
				:	storage( allocateStorage( 0, 0 ) )
			{
			}
			
			
			
			
			/// Create a matrix with the specified number of rows, columns, and default element value.
			RIM_INLINE explicit Matrix( Size numRows, Size numColumns = Size(1), const T& value = T(0) )
				:	storage( allocateStorage( numRows, numColumns ) )
			{
				util::set( storage->getElements(), value, numRows*numColumns );
			}
			
			
			
			
			/// Create a matrix from a pointer to an array with elements specified in column-major order.
			RIM_INLINE explicit Matrix( const T* array, Size numRows, Size numColumns )
				:	storage( allocateStorage( numRows, numColumns ) )
			{
				util::copy( storage->getElements(), array, numRows*numColumns );
			}
			
			
			
			
			/// Create a matrix copy of the specified 2x2 matrix.
			RIM_INLINE Matrix( const Matrix2D<T>& matrix )
				:	storage( allocateStorage( 2, 2 ) )
			{
				util::copy( storage->getElements(), matrix.toArrayColumnMajor(), 4 );
			}
			
			
			
			
			/// Create a matrix copy of the specified 3x3 matrix.
			RIM_INLINE Matrix( const Matrix3D<T>& matrix )
				:	storage( allocateStorage( 3, 3 ) )
			{
				util::copy( storage->getElements(), matrix.toArrayColumnMajor(), 9 );
			}
			
			
			
			
			/// Create a matrix copy of the specified 4x4 matrix.
			RIM_INLINE Matrix( const Matrix4D<T>& matrix )
				:	storage( allocateStorage( 4, 4 ) )
			{
				util::copy( storage->getElements(), matrix.toArrayColumnMajor(), 16 );
			}
			
			
			
			
			/// Create a matrix copy of the specified MxN matrix.
			template < Size newNumRows, Size newNumColumns >
			RIM_INLINE Matrix( const MatrixND<T,newNumRows,newNumColumns>& matrix )
				:	storage( allocateStorage( newNumRows, newNumColumns ) )
			{
				util::copy( storage->getElements(), matrix.toArrayColumnMajor(), newNumRows*newNumColumns );
			}
			
			
			
			
			/// Create a matrix copy of the specified 2-component column vector.
			RIM_INLINE Matrix( const Vector2D<T>& vector )
				:	storage( allocateStorage( 2, 1 ) )
			{
				util::copy( storage->getElements(), vector.toArray(), 2 );
			}
			
			
			
			
			/// Create a matrix copy of the specified 3-component column vector.
			RIM_INLINE Matrix( const Vector3D<T>& vector )
				:	storage( allocateStorage( 3, 1 ) )
			{
				util::copy( storage->getElements(), vector.toArray(), 3 );
			}
			
			
			
			
			/// Create a matrix copy of the specified 4-component column vector.
			RIM_INLINE Matrix( const Vector4D<T>& vector )
				:	storage( allocateStorage( 4, 1 ) )
			{
				util::copy( storage->getElements(), vector.toArray(), 4 );
			}
			
			
			
			
			/// Create a matrix copy of the specified N-component column vector.
			template < Size newNumRows >
			RIM_INLINE Matrix( const VectorND<T,newNumRows>& vector )
				:	storage( allocateStorage( newNumRows, 1 ) )
			{
				util::copy( storage->getElements(), vector.toArray(), newNumRows );
			}
			
			
			
			
			/// Create a copy of another matrix, taking a reference to its internal storage.
			/**
			  * This operation is very fast because it does not require copying the matrix storage.
			  */
			RIM_INLINE Matrix( const Matrix& other )
				:	storage( other.storage )
			{
				storage->referenceCount++;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this matrix object, release its reference to the internal storage.
			RIM_INLINE ~Matrix()
			{
				deallocateStorage( storage );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of another matrix to this one.
			RIM_INLINE Matrix& operator = ( const Matrix& other )
			{
				if ( storage != other.storage )
				{
					// Destroy the current storage.
					deallocateStorage( storage );
					
					// Copy the other matrix's storage and increment the reference count.
					storage = other.storage;
					storage->referenceCount++;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Element Accessor Methods
			
			
			
			
			/// Return the number of rows that this matrix has.
			RIM_FORCE_INLINE Size getRowCount() const
			{
				return storage->numRows;
			}
			
			
			
			
			/// Return the number of columns that this matrix has.
			RIM_FORCE_INLINE Size getColumnCount() const
			{
				return storage->numColumns;
			}
			
			
			
			
			/// Return a reference to the column at the specified index in the matrix.
			RIM_NO_INLINE Matrix getColumn( Index columnIndex )
			{
				Size numRows = storage->numRows;
				
				RIM_DEBUG_ASSERT_MESSAGE( columnIndex < storage->numColumns, "Invalid matrix column index" );
				
				// Create storage for the result.
				Storage* result = allocateStorage( numRows, 1 );
				T* resultElement = result->getElements();
				const T* const resultElementsEnd = resultElement + numRows;
				const T* matrix1Element = storage->getElements() + columnIndex*numRows;
				
				while ( resultElement != resultElementsEnd )
				{
					*resultElement = *matrix1Element;
					resultElement++;
					matrix1Element++;
				}
				
				return Matrix( result );
			}
			
			
			
			
			/// Set the column vector at the specified index in the matrix.
			RIM_NO_INLINE void setColumn( Index columnIndex, const Matrix& newColumn )
			{
				Size numRows = storage->numRows;
				
				RIM_DEBUG_ASSERT_MESSAGE( numRows != numOtherRows, "Incompatible matrix row dimensions" );
				RIM_DEBUG_ASSERT_MESSAGE( numOtherColumns != Size(1), "Incompatible matrix column dimension" );
				RIM_DEBUG_ASSERT_MESSAGE( columnIndex < numColumns, "Invalid matrix column index" );
				
				T* element = storage->getElements() + columnIndex*numRows;
				const T* const elementsEnd = element + numRows;
				const T* columnElement = newColumn.storage->getElements();
				
				while ( element != elementsEnd )
				{
					*element = *columnElement;
					element++;
					columnElement++;
				}
			}
			
			
			
			
			/// Return the row at the specified index in the matrix.
			RIM_NO_INLINE Matrix getRow( Index rowIndex ) const
			{
				Size numColumns = storage->numColumns;
				
				RIM_DEBUG_ASSERT_MESSAGE( rowIndex < storage->numRows, "Invalid matrix row index" );
				
				// Create storage for the result.
				Storage* result = allocateStorage( 1, numColumns );
				T* resultElement = result->getElements();
				const T* const resultElementsEnd = resultElement + numColumns;
				const T* matrix1Element = storage->getElements() + rowIndex;
				
				while ( resultElement != resultElementsEnd )
				{
					*resultElement = *matrix1Element;
					resultElement++;
					matrix1Element += numColumns;
				}
				
				return Matrix( result );
			}
			
			
			
			
			/// Set the row vector at the specified index in the matrix.
			RIM_NO_INLINE void setRow( Index rowIndex, const Matrix& newRow )
			{
				Size numRows = storage->numRows;
				Size numColumns = storage->numColumns;
				Size numOtherRows = newRow.storage->numRows;
				
				RIM_DEBUG_ASSERT_MESSAGE( numColumns != numOtherColumns, "Incompatible matrix column dimensions" );
				RIM_DEBUG_ASSERT_MESSAGE( numOtherRows != Size(1), "Incompatible matrix row dimension" );
				RIM_DEBUG_ASSERT_MESSAGE( rowIndex < numRows, "Invalid matrix row index" );
				
				T* element = storage->getElements() + rowIndex;
				const T* const elementsEnd = element + numColumns*numRows;
				const T* rowElement = newRow.storage->getElements();
				
				while ( element != elementsEnd )
				{
					*element = *rowElement;
					element += numRows;
					rowElement += numOtherRows;
				}
			}
			
			
			
			
			/// Return the element at the specified (row, column) in the matrix.
			RIM_FORCE_INLINE T& get( Index rowIndex, Index columnIndex )
			{
				RIM_DEBUG_ASSERT_MESSAGE( rowIndex < storage->numRows, "Invalid matrix row index" );
				RIM_DEBUG_ASSERT_MESSAGE( columnIndex < storage->numColumns, "Invalid matrix column index" );
				
				return storage->getElements()[rowIndex + columnIndex*storage->numRows];
			}
			
			
			
			
			/// Return the element at the specified (row, column) in the matrix.
			RIM_FORCE_INLINE const T& get( Index rowIndex, Index columnIndex ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( rowIndex < storage->numRows, "Invalid matrix row index" );
				RIM_DEBUG_ASSERT_MESSAGE( columnIndex < storage->numColumns, "Invalid matrix column index" );
				
				return storage->getElements()[rowIndex + columnIndex*storage->numRows];
			}
			
			
			
			
			/// Get the element at the specified (row, column) in the matrix.
			RIM_FORCE_INLINE void set( Index rowIndex, Index columnIndex, const T& value )
			{
				RIM_DEBUG_ASSERT_MESSAGE( rowIndex < storage->numRows, "Invalid matrix row index" );
				RIM_DEBUG_ASSERT_MESSAGE( columnIndex < storage->numColumns, "Invalid matrix column index" );
				
				storage->getElements()[rowIndex + columnIndex*storage->numRows] = value;
			}
			
			
			
			
			/// Return the element at the specified (row, column) in the matrix.
			RIM_FORCE_INLINE T& operator () ( Index rowIndex, Index columnIndex )
			{
				return this->get( rowIndex, columnIndex );
			}
			
			
			
			
			/// Return the element at the specified (row, column) in the matrix.
			RIM_FORCE_INLINE const T& operator () ( Index rowIndex, Index columnIndex ) const
			{
				return this->get( rowIndex, columnIndex );
			}
			
			
			
			
			/// Return a pointer to raw elements of the matrix in column-major order.
			RIM_FORCE_INLINE T* toArrayColumnMajor()
			{
				return storage->getElements();
			}
			
			
			
			
			/// Return a pointer to raw elements of the matrix in column-major order.
			RIM_FORCE_INLINE const T* toArrayColumnMajor() const
			{
				return storage->getElements();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Matrix Operations
			
			
			
			/*
			/// Get the determinant of the matrix.
			RIM_FORCE_INLINE T getDeterminant() const
			{
				return T(1);
			}
			*/
			
			
			
			/// Return the inverse of the matrix if it has one.
			/**
			  * If there is no inverse, or the matrix is not square, a 0 by 0 matrix
			  * is returned.
			  */
			/*
			RIM_FORCE_INLINE Matrix invert() const
			{
				Size numRows = storage->numRows;
				Size numColumns = storage->numColumns;
				
				if ( numRows != numColumns )
					return Matrix();
				
				Storage* result = allocateStorage( numRows, numColumns );
				
				return Matrix( result );
			}
			*/
			/*
			
			
			/// Return the orthonormalization of this matrix.
			RIM_FORCE_INLINE Matrix orthonormalize() const
			{
				Matrix<T,numRows,numColumns> result;
				
				for ( Index i = 0; i < numColumns; i++ )
				{
					VectorND<T,numRows> newColumn = getColumn(i);
					
					for ( Index j = 0; j < i; j++ )
						newColumn -= getColumn(i).projectOn( result.getColumn(j) );
					
					result.setColumn( i, newColumn.normalize() );
				}
				
				return result;
			}*/
			
			
			
			
			/// Return the transpose of this matrix.
			RIM_FORCE_INLINE Matrix transpose() const
			{
				Size numRows = storage->numRows;
				Size numColumns = storage->numColumns;
				
				// Create storage for the result.
				Storage* result = allocateStorage( numColumns, numRows );
				T* resultElement = result->getElements();
				const T* matrixElements = storage->getElements();
				
				for ( Index i = 0; i < numRows; i++ )
				{
					for ( Index j = 0; j < numColumns; j++ )
					{
						*resultElement = matrixElements[i + j*numRows];
						resultElement++;
					}
				}
				
				return Matrix( result );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not every element in this matrix is equal to that in another matrix.
			RIM_INLINE Bool operator == ( const Matrix& other ) const
			{
				if ( storage->numRows != other.storage->numRows ||
					storage->numColumns != other.storage->numColumns )
					return false;
				
				const T* element1 = storage->getElements();
				const T* element1End = element1 + storage->getSize();
				const T* element2 = other.storage->getElements();
				
				while ( element1 != element1End )
				{
					if ( *element1 != *element2 )
						return false;
					
					element1++;
					element2++;
				}
				
				return true;
			}
			
			
			
			
			/// Return whether or not some element in this matrix is not equal to that in another matrix.
			RIM_FORCE_INLINE Bool operator != ( const Matrix<T>& other ) const
			{
				return !(operator==( other ));
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Matrix Negation/Positivation Operators
			
			
			
			
			/// Negate every element of this matrix and return the resulting matrix.
			RIM_NO_INLINE Matrix operator - () const
			{
				Size numRows = storage->numRows;
				Size numColumns = storage->numColumns;
				
				// Create storage for the result.
				Storage* result = allocateStorage( numRows, numColumns );
				T* resultElement = result->getElements();
				const T* const resultElementsEnd = resultElement + numRows*numColumns;
				const T* matrix1Element = storage->getElements();
				
				while ( resultElement != resultElementsEnd )
				{
					*resultElement = -*matrix1Element;
					resultElement++;
					matrix1Element++;
				}
				
				return Matrix( result );
			}
			
			
			
			
			/// 'Positivate' every element of this matrix, returning a copy of the original matrix.
			RIM_FORCE_INLINE const Matrix& operator + () const
			{
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Operators
			
			
			
			
			/// Add this matrix to another and return the resulting matrix.
			RIM_NO_INLINE Matrix operator + ( const Matrix& matrix ) const
			{
				Size numRows = storage->numRows;
				Size numColumns = storage->numColumns;
				
				RIM_DEBUG_ASSERT_MESSAGE( numRows != matrix.storage->numRows, "Incompatible matrix row dimensions" );
				RIM_DEBUG_ASSERT_MESSAGE( numColumns != matrix.storage->numColumns, "Incompatible matrix column dimensions" );
				
				// Create storage for the result.
				Storage* result = allocateStorage( numRows, numColumns );
				
				// Add the elements and store the result.
				math::add( result->getElements(), storage->getElements(), matrix.storage->getElements(), numRows*numColumns );
				
				return Matrix( result );
			}
			
			
			
			
			/// Add a scalar to the elements of this matrix and return the resulting matrix.
			RIM_NO_INLINE Matrix operator + ( const T& value ) const
			{
				Size numRows = storage->numRows;
				Size numColumns = storage->numColumns;
				
				// Create storage for the result.
				Storage* result = allocateStorage( numRows, numColumns );
				
				// Add the elements and store the result.
				math::add( result->getElements(), storage->getElements(), value, numRows*numColumns );
				
				return Matrix( result );
			}
			
			
			
			
			/// Add this matrix to another and return the resulting matrix.
			RIM_NO_INLINE Matrix operator - ( const Matrix& matrix ) const
			{
				Size numRows = storage->numRows;
				Size numColumns = storage->numColumns;
				
				RIM_DEBUG_ASSERT_MESSAGE( numRows != matrix.storage->numRows, "Incompatible matrix row dimensions" );
				RIM_DEBUG_ASSERT_MESSAGE( numColumns != matrix.storage->numColumns, "Incompatible matrix column dimensions" );
				
				// Create storage for the result.
				Storage* result = allocateStorage( numRows, numColumns );
				
				// Subtract the elements and store the result.
				math::subtract( result->getElements(), storage->getElements(), matrix.storage->getElements(), numRows*numColumns );
				
				return Matrix( result );
			}
			
			
			
			
			/// Subtract a scalar from the elements of this matrix and return the resulting matrix.
			RIM_NO_INLINE Matrix operator - ( const T& value ) const
			{
				Size numRows = storage->numRows;
				Size numColumns = storage->numColumns;
				
				// Create storage for the result.
				Storage* result = allocateStorage( numRows, numColumns );
				
				// Subtract the elements and store the result.
				math::subtract( result->getElements(), storage->getElements(), value, numRows*numColumns );
				
				return Matrix( result );
			}
			
			
			
			
			/// Multiply a matrix by this matrix and return the result.
			RIM_NO_INLINE Matrix operator * ( const Matrix& matrix )
			{
				Size numRows = storage->numRows;
				Size numOtherRows = matrix.storage->numRows;
				Size numOtherColumns = matrix.storage->numColumns;
				
				RIM_DEBUG_ASSERT_MESSAGE( storage->numColumns != numOtherRows, "Incompatible matrix dimensions for multiplication" );
				
				// Create storage for the result.
				Storage* result = allocateStorage( numRows, numOtherColumns );
				T* resultElements = result->getElements();
				const T* matrix1Elements = storage->getElements();
				const T* matrix2Elements = matrix.storage->getElements();
				
				for ( Index i = 0; i < numRows; i++ )
				{
					const T* const m1RowStart = matrix1Elements + i;
					
					for ( Index j = 0; j < numOtherColumns; j++ )
					{
						const T* m2Column = matrix2Elements + j*numOtherRows;
						const T* const m2ColumnEnd = m2Column + numOtherRows;
						const T* m1Row = m1RowStart;
						
						T dot = T(0);
						
						while ( m2Column != m2ColumnEnd )
						{
							dot += (*m1Row)*(*m2Column);
							m1Row += numRows;
							m2Column++;
						}
						
						resultElements[i + j*numRows] = dot;
					}
				}
				
				return Matrix( result );
			}
			
			
			
			
			/// Multiply the elements of this matrix by a scalar and return the resulting matrix.
			RIM_NO_INLINE Matrix operator * ( const T& value ) const
			{
				Size numRows = storage->numRows;
				Size numColumns = storage->numColumns;
				
				// Create storage for the result.
				Storage* result = allocateStorage( numRows, numColumns );
				
				// Multiply the elements and store the result.
				math::multiply( result->getElements(), storage->getElements(), value, numRows*numColumns );
				
				return Matrix( result );
			}
			
			
			
			
			/// Divide the elements of this matrix by a scalar and return the resulting matrix.
			RIM_NO_INLINE Matrix operator / ( const T& value ) const
			{
				Size numRows = storage->numRows;
				Size numColumns = storage->numColumns;
				
				// Create storage for the result.
				Storage* result = allocateStorage( numRows, numColumns );
				
				// Multiply the elements and store the result.
				math::multiply( result->getElements(), storage->getElements(), T(1)/value, numRows*numColumns );
				
				return Matrix( result );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Matrix Operators
			
			
			
			
			/// Add the elements of another matrix to this matrix.
			RIM_NO_INLINE Matrix& operator += ( const Matrix& matrix )
			{
				Size numRows = storage->numRows;
				Size numColumns = storage->numColumns;
				
				RIM_DEBUG_ASSERT_MESSAGE( numRows != matrix.storage->numRows, "Incompatible matrix row dimensions" );
				RIM_DEBUG_ASSERT_MESSAGE( numColumns != matrix.storage->numColumns, "Incompatible matrix column dimensions" );
				
				math::add( storage->getElements(), matrix.storage->getElements(), numRows*numColumns );
				
				return *this;
			}
			
			
			
			
			/// Add a scalar value to the elements of this matrix.
			RIM_NO_INLINE Matrix& operator += ( const T& value )
			{
				if ( storage->referenceCount > Size(1) )
					makeUnique();
				
				Size numRows = storage->numRows;
				Size numColumns = storage->numColumns;
				
				math::add( storage->getElements(), value, numRows*numColumns );
				
				return *this;
			}
			
			
			
			
			/// Subtract the elements of another matrix from this matrix.
			RIM_NO_INLINE Matrix& operator -= ( const Matrix& matrix )
			{
				Size numRows = storage->numRows;
				Size numColumns = storage->numColumns;
				
				RIM_DEBUG_ASSERT_MESSAGE( numRows != matrix.storage->numRows, "Incompatible matrix row dimensions" );
				RIM_DEBUG_ASSERT_MESSAGE( numColumns != matrix.storage->numColumns, "Incompatible matrix column dimensions" );
				
				math::subtract( storage->getElements(), matrix.storage->getElements(), numRows*numColumns );
				
				return *this;
			}
			
			
			
			
			/// Subtract a scalar value from the elements of this matrix.
			RIM_NO_INLINE Matrix& operator -= ( const T& value )
			{
				if ( storage->referenceCount > Size(1) )
					makeUnique();
				
				Size numRows = storage->numRows;
				Size numColumns = storage->numColumns;
				
				math::subtract( storage->getElements(), value, numRows*numColumns );
				
				return *this;
			}
			
			
			
			
			/// Multiply the elements of this matrix by a scalar value.
			RIM_NO_INLINE Matrix& operator *= ( const T& value )
			{
				if ( storage->referenceCount > Size(1) )
					makeUnique();
				
				Size numRows = storage->numRows;
				Size numColumns = storage->numColumns;
				
				math::multiply( storage->getElements(), value, numRows*numColumns );
				
				return *this;
			}
			
			
			
			
			/// Divide the elements of this matrix by a scalar value.
			RIM_NO_INLINE Matrix& operator /= ( const T& value )
			{
				if ( storage->referenceCount > Size(1) )
					makeUnique();
				
				Size numRows = storage->numRows;
				Size numColumns = storage->numColumns;
				
				math::multiply( storage->getElements(), T(1)/value, numRows*numColumns );
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Conversion Methods
			
			
			
			
			/// Convert this matrix into a human-readable string representation.
			RIM_NO_INLINE data::String toString() const
			{
				data::StringBuffer buffer;
				const Size numRows = storage->numRows;
				const Size numColumns = storage->numColumns;
				const T* elements = storage->getElements();
				
				for ( Index i = 0; i < numRows; i++ )
				{
					buffer << "[ ";
					
					for ( Index j = 0; j < numColumns; j++ )
					{
						if ( j != numColumns - 1 )
							buffer << elements[i + j*numRows] << ", ";
						else
							buffer << elements[i + j*numRows] << ' ';
					}
					
					if ( i != numRows - 1 )
						buffer << "]\n";
					else
						buffer << ']';
				}
				
				return buffer.toString();
			}
			
			
			
			
			/// Convert this matrix into a human-readable string representation.
			RIM_FORCE_INLINE operator data::String () const
			{
				return this->toString();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Matrix Creation Methods
			
			
			
			
			/// Return the square identity matrix for the specified matrix size.
			static Matrix getIdentity( Size size )
			{
				Storage* storage = allocateStorage( size, size );
				T* element = storage->getElements();
				
				for ( Index i = 0; i < size; i++ )
				{
					for ( Index j = 0; j < size; j++, element++ )
					{
						if ( i == j )
							*element = T(1);
						else
							*element = T(0);
					}
				}
				
				return Matrix( storage );
			}
			
			
			
			
			/// Return an uninitialized matrix of the specified size.
			/**
			  * The contents of the matrix elements are undefined.
			  */
			static Matrix getUninitialized( Size numRows, Size numColumns )
			{
				Storage* storage = allocateStorage( numRows, numColumns );
				
				return Matrix( storage );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which stores information about this matrix and its element data.
			class Storage
			{
				public:
					
					/// Create a new storage object with the specified number of rows and columns and reference count of 1.
					RIM_INLINE Storage( Size newNumRows, Size newNumColumns )
						:	numRows( newNumRows ),
							numColumns( newNumColumns ),
							referenceCount( 1 )
					{
					}
					
					
					/// Return a pointer to the storage for the elements of this matrix.
					/**
					  * Elements are stored in column-major order.
					  */
					RIM_INLINE T* getElements()
					{
						return (T*)((UByte*)this + sizeof(Storage));
					}
					
					/// Return a const pointer to the storage for the elements of this matrix.
					/**
					  * Elements are stored in column-major order.
					  */
					RIM_INLINE const T* getElements() const
					{
						return (const T*)((const UByte*)this + sizeof(Storage));
					}
					
					
					/// Return the total number of elements that are part of this storage.
					RIM_INLINE Size getSize() const
					{
						return numRows*numColumns;
					}
					
					
					/// The number of rows that are part of this matrix storage.
					Size numRows;
					
					
					/// The number of columns that are part of this matrix storage.
					Size numColumns;
					
					
					/// The number of matrices that reference this storage object.
					Size referenceCount;
					
					
					/// An array to pad the storage buffer to a 16-byte boundary.
					Size padding;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructor
			
			
			
			
			/// Create a new matrix which uses the specified storage object.
			/**
			  * The new matrix does not increment the storage's reference count.
			  */
			RIM_INLINE Matrix( Storage* newStorage )
				:	storage( newStorage )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Storage Helper Methods
			
			
			
			
			/// Allocate a storage object with the specified number of rows and columns.
			static Storage* allocateStorage( Size numRows, Size numColumns )
			{
				Size storageSize = sizeof(Storage) + sizeof(T)*numRows*numColumns;
				UByte* storageBytes = util::allocate<UByte>( storageSize );
				
				new ( storageBytes ) Storage( numRows, numColumns );
				
				return (Storage*)storageBytes;
			}
			
			
			
			
			/// Deallocate the specified storage object.
			static void deallocateStorage( Storage* storage )
			{
				if ( --storage->referenceCount == Size(0) )
					util::deallocate( (UByte*)storage );
			}
			
			
			
			
			/// Set all elements of the specified storage object to the given value.
			static void setStorage( Storage* storage, const T& value )
			{
				util::set( storage->getElements(), value, storage->getSize() );
			}
			
			
			
			
			// If this matrix's storage is not unique, copy it so that the matrix has its own storage.
			RIM_NO_INLINE void makeUnique()
			{
				Size numRows = storage->numRows;
				Size numColumns = storage->numColumns;
				Storage* oldStorage = storage;
				
				// Create new storage and copy the elements.
				storage = allocateStorage( numRows, numColumns );
				util::copy( storage->getElements(), oldStorage->getElements(), numRows*numColumns );
				
				// Clean up the old storage.
				deallocateStorage( oldStorage );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the reference-counted storage for this matrix.
			/**
			  * The matrix employs copy-on-write semantics.
			  */
			Storage* storage;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Class
			
			
			
			
			template < typename U >
			friend class Matrix;
			
			
			
			
			template < typename U >
			friend Matrix<U> qr( const Matrix<U>& );
			
			template < typename U >
			friend Matrix<U> qr( const Matrix<U>&, Matrix<U>& );
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Reverse Matrix Arithmetic Operators
//############		
//##########################################################################################
//##########################################################################################




/// Add a scalar to a matrix's elements and return the resulting matrix
template < typename T >
RIM_FORCE_INLINE Matrix<T> operator + ( const T& c, const Matrix<T>& matrix ) 
{
	return matrix + c;
}




/// Subtract a matrix's elements from a scalar and return the resulting matrix
template < typename T >
RIM_FORCE_INLINE Matrix<T> operator - ( const T& c, const Matrix<T>& matrix ) 
{
	return -matrix + c;
}




/// Multiply a matrix's elements by a scalar and return the resulting matrix
template < typename T >
RIM_FORCE_INLINE Matrix<T> operator * ( const T& c, const Matrix<T>& matrix ) 
{
	return matrix * c;
}




//##########################################################################################
//##########################################################################################
//############		
//############		QR Factorization Methods
//############		
//##########################################################################################
//##########################################################################################


#if 0

/// Do a QR factorization of the specified matrix, returning the R matrix.
/**
  * R is an upper-triangular matrix. The Q matrix is not computed.
  */
template < typename T >
RIM_NO_INLINE Matrix<T> qr( const Matrix<T>& matrix )
{
	Size numRows = matrix.getRowCount();
	Size numColumns = matrix.getColumnCount();
	typename Matrix<T>::Storage* rStorage = Matrix<T>::allocateStorage( numRows, numColumns );
	
	for ( Index k = 0; k < numColumns; k++ )
	{
		
	}
	
	return Matrix<T>( rStorage );
}




/// Do a QR factorization of the specified matrix, returning the R matrix and the Q matrix in the output parameter.
/**
  * R is an upper-triangular matrix, Q is an orthonormal (unitary) matrix.
  */
template < typename T >
RIM_NO_INLINE Matrix<T> qr( const Matrix<T>& matrix, Matrix<T>& q )
{
	
}

#endif


//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_MATRIX_H
