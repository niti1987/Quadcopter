/*
 *  rimMatrixND.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 10/22/07.
 *  Copyright 2007 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_MATRIX_ND_H
#define INCLUDE_RIM_MATRIX_ND_H


#include "rimMathConfig.h"


#include "../data/rimBasicString.h"
#include "../data/rimBasicStringBuffer.h"
#include "rimVectorND.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a matrix of a fixed arbitrary number of rows and columns.
template < typename T, Size numRows, Size numColumns >
class MatrixND
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a matrix with its elements all equal to zero.
			RIM_FORCE_INLINE MatrixND()
				:	column()
			{
			}
			
			
			
			
			/// Create a matrix from a pointer to an array with elements specified in column-major order.
			RIM_FORCE_INLINE MatrixND( const T* array )
			{
				for ( Index i = 0; i < numColumns; i++ )
					for ( Index j = 0; j < numRows; j++ )
						column[i][j] = array[i*numRows + j];
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
				return (T*)&column[0];
			}
			
			
			
			
			/// Return a pointer to the matrix's elements in colunn-major order.
			/**
			  * Since matrix elements are stored in column-major order,
			  * no allocation is performed and the elements are accessed directly.
			  */
			RIM_FORCE_INLINE const T* toArrayColumnMajor() const
			{
				return (T*)&column[0];
			}
			
			
			
			
			/// Return a reference to the column at the specified index in the matrix.
			RIM_FORCE_INLINE VectorND<T,numRows>& getColumn( Index columnIndex )
			{
				RIM_DEBUG_ASSERT( columnIndex < numColumns );
				
				return column[columnIndex];
			}
			
			
			
			
			/// Return a const reference to the column at the specified index in the matrix.
			RIM_FORCE_INLINE const VectorND<T,numRows>& getColumn( Index columnIndex ) const
			{
				RIM_DEBUG_ASSERT( columnIndex < numColumns );
				
				return column[columnIndex];
			}
			
			
			
			
			/// Return a reference to the column at the specified index in the matrix.
			RIM_FORCE_INLINE VectorND<T,numRows>& operator () ( Index columnIndex )
			{
				RIM_DEBUG_ASSERT( columnIndex < numColumns );
				
				return column[columnIndex];
			}
			
			
			
			
			/// Return a const reference to the column at the specified index in the matrix.
			RIM_FORCE_INLINE const VectorND<T,numRows>& operator () ( Index columnIndex ) const
			{
				RIM_DEBUG_ASSERT( columnIndex < numColumns );
				
				return column[columnIndex];
			}
			
			
			
			
			/// Return a reference the column at the specified index in the matrix.
			RIM_FORCE_INLINE VectorND<T,numRows>& operator [] ( Index columnIndex )
			{
				RIM_DEBUG_ASSERT( columnIndex < numColumns );
				
				return column[columnIndex];
			}
			
			
			
			
			/// Return a const reference to the column at the specified index in the matrix.
			RIM_FORCE_INLINE const VectorND<T,numRows>& operator [] ( Index columnIndex ) const
			{
				RIM_DEBUG_ASSERT( columnIndex < numColumns );
				
				return column[columnIndex];
			}
			
			
			
			
			/// Return the row at the specified index in the matrix.
			RIM_FORCE_INLINE VectorND<T,numColumns> getRow( Index rowIndex ) const
			{
				RIM_DEBUG_ASSERT( rowIndex < numRows );
				
				VectorND<T,numColumns> result;
				
				for ( Index i = 0; i < numColumns; i++ )
					result.set( i, column[i][rowIndex] );
				
				return result;
			}
			
			
			
			
			/// Return the element at the specified (row, column) in the matrix.
			RIM_FORCE_INLINE T& get( Index rowIndex, Index columnIndex )
			{
				RIM_DEBUG_ASSERT( rowIndex < numRows );
				RIM_DEBUG_ASSERT( columnIndex < numColumns );
				
				return column[columnIndex][rowIndex];
			}
			
			
			
			
			/// Return the element at the specified (row, column) in the matrix.
			RIM_FORCE_INLINE const T& get( Index rowIndex, Index columnIndex ) const
			{
				RIM_DEBUG_ASSERT( rowIndex < numRows );
				RIM_DEBUG_ASSERT( columnIndex < numColumns );
				
				return column[columnIndex][rowIndex];
			}
			
			
			
			
			/// Return the element at the specified (row, column) in the matrix.
			RIM_FORCE_INLINE T& operator () ( Index rowIndex, Index columnIndex )
			{
				RIM_DEBUG_ASSERT( rowIndex < numRows );
				RIM_DEBUG_ASSERT( columnIndex < numColumns );
				
				return column[columnIndex][rowIndex];
			}
			
			
			
			
			/// Return the element at the specified (row, column) in the matrix.
			RIM_FORCE_INLINE const T& operator () ( Index rowIndex, Index columnIndex ) const
			{
				RIM_DEBUG_ASSERT( rowIndex < numRows );
				RIM_DEBUG_ASSERT( columnIndex < numColumns );
				
				return column[columnIndex][rowIndex];
			}
			
			
			
			
			/// Set the column vector at the specified index in the matrix.
			RIM_FORCE_INLINE void setColumn( Index columnIndex, const VectorND<T,numRows>& newColumn )
			{
				RIM_DEBUG_ASSERT( columnIndex < numColumns );
				
				column[columnIndex] = newColumn;
			}
			
			
			
			
			/// Set the row vector at the specified index in the matrix.
			RIM_FORCE_INLINE void setRow( Index rowIndex, const VectorND<T,numColumns>& newRow )
			{
				RIM_DEBUG_ASSERT( rowIndex < numRows );
				
				for ( Index i = 0; i < numColumns; i++ )
					column[i].set( rowIndex, newRow[i] );
			}
			
			
			
			
			/// Get the element at the specified (row, column) in the matrix.
			RIM_FORCE_INLINE void set( Index rowIndex, Index columnIndex, T value )
			{
				RIM_DEBUG_ASSERT( rowIndex < numRows );
				RIM_DEBUG_ASSERT( columnIndex < numColumns );
				
				column[columnIndex].set( rowIndex, value );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	MatrixND Operations
			
			
			
			
			/// Get the determinant of the matrix.
			RIM_FORCE_INLINE T getDeterminant() const
			{
			}
			
			
			
			
			/// Get the inverse of the matrix if it has one.
			RIM_FORCE_INLINE MatrixND invert() const
			{
			}
			
			
			
			
			/// Return the orthonormalization of this matrix.
			RIM_FORCE_INLINE MatrixND orthonormalize() const
			{
				MatrixND<T,numRows,numColumns> result;
				
				for ( Index i = 0; i < numColumns; i++ )
				{
					VectorND<T,numRows> newColumn = getColumn(i);
					
					for ( Index j = 0; j < i; j++ )
						newColumn -= getColumn(i).projectOn( result.getColumn(j) );
					
					result.setColumn( i, newColumn.normalize() );
				}
				
				return result;
			}
			
			
			
			
			/// Return the transpose of this matrix.
			RIM_FORCE_INLINE MatrixND<T,numColumns,numRows> transpose() const
			{
				MatrixND<T,numColumns,numRows> result;
				
				for ( Index i = 0; i < numRows; i++ )
					result.setColumn( i, getRow(i) );
				
				return result;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not every component in this matrix is equal to that in another matrix.
			RIM_FORCE_INLINE Bool operator == ( const MatrixND<T,numRows,numColumns> &matrix ) const
			{
				Bool result = true;
				
				for ( Index i = 0; i < numColumns; i++ )
					result &= (column[i] == matrix.getColumn(i));
				
				return result;
			}
			
			
			
			
			/// Return whether or not some component in this matrix is not equal to that in another matrix.
			RIM_FORCE_INLINE Bool operator != ( const MatrixND<T,numRows,numColumns>& matrix ) const
			{
				return !(operator==( matrix ));
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	MatrixND Negation/Positivation Operators
			
			
			
			
			/// Negate every element of this matrix and return the resulting matrix.
			RIM_FORCE_INLINE MatrixND operator - () const
			{
				MatrixND result;
				
				for ( Index i = 0; i < numColumns; i++ )
					result.column[i] = -column[i];
				
				return result;
			}
			
			
			
			
			/// 'Positivate' every element of this matrix, returning a copy of the original matrix.
			RIM_FORCE_INLINE MatrixND operator + () const
			{
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Operators
			
			
			
			
			/// Add this matrix to another and return the resulting matrix.
			RIM_FORCE_INLINE MatrixND operator + ( const MatrixND<T,numRows,numColumns>& matrix ) const
			{
				MatrixND result;
				
				for ( Index i = 0; i < numColumns; i++ )
					result.column[i] = column[i] + matrix.column[i];
				
				return result;
			}
			
			
			
			
			/// Add a scalar to the elements of this matrix and return the resulting matrix.
			RIM_FORCE_INLINE MatrixND operator + ( const T& value ) const
			{
				MatrixND result;
				
				for ( Index i = 0; i < numColumns; i++ )
					result.column[i] = column[i] + value;
				
				return result;
			}
			
			
			
			
			/// Add this matrix to another and return the resulting matrix.
			RIM_FORCE_INLINE MatrixND operator - ( const MatrixND<T,numRows,numColumns>& matrix ) const
			{
				MatrixND result;
				
				for ( Index i = 0; i < numColumns; i++ )
					result.column[i] = column[i] - matrix.column[i];
				
				return result;
			}
			
			
			
			
			/// Subtract a scalar from the elements of this matrix and return the resulting matrix.
			RIM_FORCE_INLINE MatrixND operator - ( const T& value ) const
			{
				MatrixND result;
				
				for ( Index i = 0; i < numColumns; i++ )
					result.column[i] = column[i] - value;
				
				return result;
			}
			
			
			
			
			/// Multiply a matrix by this matrix and return the result.
			template < Size otherColumnDimension >
			RIM_FORCE_INLINE MatrixND<T,numRows,otherColumnDimension> operator * ( const MatrixND<T,numColumns,otherColumnDimension>& matrix )
			{
				MatrixND<T,numRows,otherColumnDimension> result;
				
				for ( Index i = 0; i < numRows; i++ )
				{
					for ( Index j = 0; j < otherColumnDimension; j++ )
					{
						T dot = T(0);
						
						for ( Index k = 0; k < numColumns; k++ )
							dot += column[k][i] * matrix.column[j][k];
						
						result.column[j][i] = dot;
					}
				}
				
				return result;
			}
			
			
			
			
			/// Multiply a vector/point by this matrix and return the result.
			RIM_FORCE_INLINE VectorND<T,numRows> operator * ( const VectorND<T,numColumns>& vector )
			{
				VectorND<T,numRows> result;
				
				for ( Index i = 0; i < numRows; i++ )
				{
					T dot = T(0);
					
					for ( Index j = 0; j < numColumns; j++ )
						dot += column[j][i] * vector[j];
					
					result[i] = dot;
				}
				
				return result;
			}
			
			
			
			
			/// Multiply the elements of this matrix by a scalar and return the resulting matrix.
			RIM_FORCE_INLINE MatrixND operator * ( const T& value ) const
			{
				MatrixND result;
				
				for ( Index i = 0; i < numColumns; i++ )
					result.column[i] = column[i] * value;
				
				return result;
			}
			
			
			
			
			/// Divide the elements of this matrix by a scalar and return the resulting matrix.
			RIM_FORCE_INLINE MatrixND operator / ( const T& value ) const
			{
				MatrixND result;
				T inverseValue = T(1)/value;
				
				for ( Index i = 0; i < numColumns; i++ )
					result.column[i] = column[i] * inverseValue;
				
				return result;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	MatrixND Operators
			
			
			
			
			/// Add the elements of another matrix to this matrix.
			RIM_FORCE_INLINE MatrixND& operator += ( const MatrixND<T,numRows,numColumns>& matrix )
			{
				for ( Index i = 0; i < numColumns; i++ )
					column[i] += matrix.column[i];
				
				return *this;
			}
			
			
			
			
			/// Add a scalar value to the elements of this matrix.
			RIM_FORCE_INLINE MatrixND& operator += ( const T& value )
			{
				for ( Index i = 0; i < numColumns; i++ )
					column[i] += value;
				
				return *this;
			}
			
			
			
			
			/// Subtract the elements of another matrix from this matrix.
			RIM_FORCE_INLINE MatrixND& operator -= ( const MatrixND<T,numRows,numColumns>& matrix )
			{
				for ( Index i = 0; i < numColumns; i++ )
					column[i] -= matrix.column[i];
				
				return *this;
			}
			
			
			
			
			/// Subtract a scalar value from the elements of this matrix.
			RIM_FORCE_INLINE MatrixND& operator -= ( const T& value )
			{
				for ( Index i = 0; i < numColumns; i++ )
					column[i] -= value;
				
				return *this;
			}
			
			
			
			
			/// Multiply the elements of this matrix by a scalar value.
			RIM_FORCE_INLINE MatrixND& operator *= ( const T& value )
			{
				for ( Index i = 0; i < numColumns; i++ )
					column[i] *= value;
				
				return *this;
			}
			
			
			
			
			/// Divide the elements of this matrix by a scalar value.
			RIM_FORCE_INLINE MatrixND& operator /= ( const T& value )
			{
				T inverseValue = T(1)/value;
				
				for ( Index i = 0; i < numColumns; i++ )
					column[i] *= inverseValue;
				
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
				
				for ( Index i = 0; i < numRows; i++ )
				{
					buffer << "[ ";
					
					for ( Index j = 0; j < numColumns; j++ )
					{
						if ( j != numColumns - 1 )
							buffer << column[i][j] << ", ";
						else
							buffer << column[i][j] << ' ';
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
		//******	Public Static Data Members
			
			
			
			
			/// Constant matrix with all elements equal to zero.
			static const MatrixND ZERO;
			
			
			
			
			/// Constant matrix which is the identity matrix.
			static const MatrixND IDENTITY;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Return the identity matrix for this matrix size.
			static MatrixND getIdentity()
			{
				MatrixND result;
				Size minDimension = math::min( numRows, numColumns );
				
				for ( Index i = 0; i < minDimension; i++ )
					result[i][i] = T(1);
				
				return result;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An array of column vectors for this matrix.
			VectorND<T,numRows> column[numColumns];
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Class
			
			
			
			
			template < typename U, Size r, Size c >
			friend class MatrixND;
			
			
			
};




template < typename T, Size numRows, Size numColumns >
const MatrixND<T,numRows,numColumns> MatrixND<T,numRows,numColumns>:: ZERO;




template < typename T, Size numRows, Size numColumns >
const MatrixND<T,numRows,numColumns> MatrixND<T,numRows,numColumns>:: IDENTITY = MatrixND<T,numRows,numColumns>::getIdentity();




//##########################################################################################
//##########################################################################################
//############		
//############		Reverse Matrix Arithmetic Operators
//############		
//##########################################################################################
//##########################################################################################




/// Multiply a matrix's elements by a scalar and return the resulting matrix
template <typename T, Size numRows, Size numColumns>
RIM_FORCE_INLINE MatrixND<T,numRows,numColumns> operator + ( const T& c, const MatrixND<T,numRows,numColumns>& matrix ) 
{
	MatrixND<T,numRows,numColumns> result;
	
	for ( Index i = 0; i < numColumns; i++ )
		result.setColumn( i, matrix.getColumn(i) * c );
	
	return result;
}




/// 'Reverse' multiply a vector/point by matrix: multiply it by the matrix's transpose.
template <typename T, Size numRows, Size numColumns>
RIM_FORCE_INLINE VectorND<T,numColumns> operator * ( const VectorND<T,numRows>& vector, const MatrixND<T,numRows,numColumns>& matrix ) 
{
	VectorND<T,numColumns> result;
	
	for ( Index i = 0; i < numColumns; i++ )
	{
		T dot = T(0);
		
		for ( Index j = 0; j < numRows; j++ )
			dot += matrix[i][j] * vector[j];
		
		result[i] = dot;
	}
	
	return result;
}




/// Multiply a matrix's elements by a scalar and return the resulting matrix
template <typename T, Size numRows, Size numColumns>
RIM_FORCE_INLINE MatrixND<T,numRows,numColumns> operator * ( const T& c, const MatrixND<T,numRows,numColumns>& matrix ) 
{
	MatrixND<T,numRows,numColumns> result;
	
	for ( int i = 0; i < numColumns; i++ )
		result.setColumn( i, matrix.getColumn(i) * c );
	
	return result;
}




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_MATRIX_ND_H
