/*
 *  rimVectorND.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 10/16/07.
 *  Copyright 2007 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_VECTOR_ND_H
#define INCLUDE_RIM_VECTOR_ND_H


#include "rimMathConfig.h"


#include "../data/rimBasicString.h"
#include "../data/rimBasicStringBuffer.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a vector of a fixed arbitrary number of components.
template < typename T, Size dimension >
class VectorND
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			/// Create a vector with all of its elements equal to zero
			RIM_FORCE_INLINE VectorND()
			{
				for ( Index i = 0; i < dimension; i++ )
					x[i] = T(0);
			}
			
			
			
			
			/// Create a vector with elements from the specified array.
			/**
			  * The array must be of length greater than or equal to the
			  * dimension of the vector.
			  */
			RIM_FORCE_INLINE VectorND( const T* array )
			{
				for ( Index i = 0; i < dimension; i++ )
					x[i] = array[i];
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	VectorND Operations
			
			
			
			
			/// Get the magnitude of the vector.
			RIM_FORCE_INLINE T getMagnitude() const
			{
				return math::sqrt( getMagnitudeSquared() );
			}
			
			
			
			
			/// Get the squared magnitude of the vector.
			RIM_FORCE_INLINE T getMagnitudeSquared() const
			{
				T sum = T(0);
				
				for ( unsigned int i = 0; i < dimension; i++ )
					sum += x[i]*x[i];
				
				return sum;
			}
			
			
			
			
			/// Return a a normalized version of this vector.
			RIM_FORCE_INLINE VectorND normalize() const
			{
				T mag = getMagnitude();
				
				if ( mag == T(0) )
					return VectorND::ZERO;
				
				T invMag = T(1)/mag;
				
				VectorND result;
				
				for ( Index i = 0; i < dimension; i++ )
					result.x[i] = x[i]*invMag;
				
				return result;
			}
			
			
			
			
			/// Project this vector onto another vector
			RIM_FORCE_INLINE VectorND projectOn( const VectorND& v ) const
			{
				// compute this dot v:
				T result = T(0);
				
				for ( Index i = 0; i < dimension; i++ )
					result += x[i]*v.x[i];
				
				return result * v.normalize();
			}
			
			
			
			
			/// Get the distance between the this vector and another.
			RIM_FORCE_INLINE T getDistanceTo( const VectorND& v ) const
			{
				return math::sqrt( distanceToSquared(v) );
			}
			
			
			
			
			/// Get the squared distance between the this vector and another.
			RIM_FORCE_INLINE T getDistanceToSquared( const VectorND& v ) const
			{
				return ((*this) - v).getMagnitudeSquared();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Accessor Methods
			
			
			
			
			/// Return an array representation of this vector.
			RIM_FORCE_INLINE const T* toArray() const
			{
				return x;
			}
			
			
			
			
			/// Return a reference to the element at the specified index in the vector.
			RIM_FORCE_INLINE T& get( Index i )
			{
				RIM_DEBUG_ASSERT( i < dimension );
				
				return x[i];
			}
			
			
			
			
			/// Return a const reference to the element at the specified index in the vector.
			RIM_FORCE_INLINE const T& get( Index i ) const
			{
				RIM_DEBUG_ASSERT( i < dimension );
				
				return x[i];
			}
			
			
			
			
			/// Return a reference to the element at the specified index in the vector.
			RIM_FORCE_INLINE T& operator () ( Index i )
			{
				RIM_DEBUG_ASSERT( i < dimension );
				
				return x[i];
			}
			
			
			
			
			/// Return const a reference to the element at the specified index in the vector.
			RIM_FORCE_INLINE const T& operator () ( Index i ) const
			{
				RIM_DEBUG_ASSERT( i < dimension );
				
				return x[i];
			}
			
			
			
			
			/// Return a reference to the element at the specified index in the vector.
			RIM_FORCE_INLINE T& operator [] ( Index i )
			{
				RIM_DEBUG_ASSERT( i < dimension );
				
				return x[i];
			}
			
			
			
			
			/// Return a const reference to the element at the specified index in the vector.
			RIM_FORCE_INLINE const T& operator [] ( Index i ) const
			{
				RIM_DEBUG_ASSERT( i < dimension );
				
				return x[i];
			}
			
			
			
			
			/// Return the dimension of this vector (number of components it has).
			RIM_FORCE_INLINE Size getSize() const
			{
				return dimension;
			}
			
			
			
			
			/// Return the dimension of this vector (number of components it has).
			RIM_FORCE_INLINE Size getDimension() const
			{
				return dimension;
			}
			
			
			
			
			/// Set the element at the specified index in the vector.
			RIM_FORCE_INLINE void set( Index i, T newX )
			{
				RIM_DEBUG_ASSERT( i < dimension );
				
				x[i] = newX;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Negation/Positivation Operators
			
			
			
			
			/// Negate every component of this vector and return the result.
			RIM_FORCE_INLINE VectorND operator - () const
			{
				VectorND result;
				
				for ( Index i = 0; i < dimension; i++ )
					result.x[i] = -x[i];
				
				return result;
			}
			
			
			
			
			/// 'Positivate' every component of this vector, effectively returning a copy.
			RIM_FORCE_INLINE VectorND operator + () const
			{
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Operators
			
			
			
			
			/// Add a vector to this vector and return the resulting vector.
			RIM_FORCE_INLINE VectorND operator + ( const VectorND& vector ) const
			{
				VectorND result;
				
				for ( Index i = 0; i < dimension; i++ )
					result.x[i] = x[i] + vector.x[i];
				
				return result;
			}
			
			
			
			
			/// Add a scalar value to each component of this vector and return the resulting vector.
			RIM_FORCE_INLINE VectorND operator + ( T value ) const
			{
				VectorND result;
				
				for ( Index i = 0; i < dimension; i++ )
					result.x[i] = x[i] + value;
				
				return result;
			}
			
			
			
			
			/// Subtract a vector from this vector and return the resulting vector.
			RIM_FORCE_INLINE VectorND operator - ( const VectorND& vector ) const
			{
				VectorND result;
				
				for ( Index i = 0; i < dimension; i++ )
					result.x[i] = x[i] - vector.x[i];
				
				return result;
			}
			
			
			
			
			/// Subtract a scalar value from each component of this vector and return the resulting vector.
			RIM_FORCE_INLINE VectorND operator - ( T value ) const
			{
				VectorND result;
				
				for ( Index i = 0; i < dimension; i++ )
					result.x[i] = x[i] - value;
				
				return result;
			}
			
			
			
			
			/// Return the result of a component-wise vector multiplication with this vector.
			RIM_FORCE_INLINE VectorND operator * ( const VectorND& vector ) const
			{
				VectorND result;
				
				for ( Index i = 0; i < dimension; i++ )
					result.x[i] = x[i]*vector.x[i];
				
				return result;
			}
			
			
			
			
			/// Multiply a scalar value by each component of this vector and return the resulting vector.
			RIM_FORCE_INLINE VectorND operator * ( T value ) const
			{
				VectorND result;
				
				for ( Index i = 0; i < dimension; i++ )
					result.x[i] = x[i]*value;
				
				return result;
			}
			
			
			
			
			/// Divide each component of this vector by a scalar value and return the resulting vector.
			RIM_FORCE_INLINE VectorND operator / ( T value ) const
			{
				VectorND result;
				
				for ( Index i = 0; i < dimension; i++ )
					result.x[i] = x[i]/value;
				
				return result;
			}			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Assignment Operators
			
			
			
			
			RIM_FORCE_INLINE VectorND& operator += ( const VectorND& v2 )
			{
				for ( Index i = 0; i < dimension; i++ )
					x[i] += v2.x[i];
				
				return *this;
			}
			
			
			
			
			RIM_FORCE_INLINE VectorND& operator -= ( const VectorND& v2 )
			{
				for ( Index i = 0; i < dimension; i++ )
					x[i] -= v2.x[i];
				
				return *this;
			}
			
			
			
			
			RIM_FORCE_INLINE VectorND& operator += ( const T value )
			{
				for ( Index i = 0; i < dimension; i++ )
					x[i] += value;
				
				return *this;
			}
			
			
			
			
			RIM_FORCE_INLINE VectorND& operator -= ( const T value )
			{
				for ( Index i = 0; i < dimension; i++ )
					x[i] -= value;
				
				return *this;
			}
			
			
			
			
			RIM_FORCE_INLINE VectorND& operator *= ( const T value )
			{
				for ( Index i = 0; i < dimension; i++ )
					x[i] *= value;
				
				return *this;
			}
			
			
			
			
			RIM_FORCE_INLINE VectorND& operator /= ( const T value )
			{
				for ( Index i = 0; i < dimension; i++ )
					x[i] /= value;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Conversion Methods
			
			
			
			
			/// Convert this vector into a human-readable string representation.
			RIM_NO_INLINE data::String toString() const
			{
				data::StringBuffer buffer;
				
				buffer << "< ";
				
				for ( Index i = 0; i < dimension; i++ )
				{
					if ( i != dimension - 1 )
						buffer << x[i] << ", ";
					else
						buffer << x[i];
				}
				
				buffer << " >";
				
				return buffer.toString();
			}
			
			
			
			
			/// Convert this vector into a human-readable string representation.
			RIM_FORCE_INLINE operator data::String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The components of this vector.
			T x[dimension];
			
			
			
			
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// A constant vector with every component equal to zero.
			static const VectorND ZERO;
			
			
			
			
};




template < typename T, Size dimension >
const VectorND<T,dimension> VectorND<T,dimension>:: ZERO;




//##########################################################################################
//##########################################################################################
//############		
//############		Reverse Arithmetic Operators
//############		
//##########################################################################################
//##########################################################################################




/// Multiply every component of a vector by a scalar value and return the resulting vector.
template < typename T, Size dimension >
RIM_FORCE_INLINE VectorND<T,dimension> operator * ( const T& c, const VectorND<T,dimension>& vector ) 
{
	VectorND<T,dimension> result;
	
	for ( Index i = 0; i < dimension; i++ )
		result.set( i, vector.get(i) * c );
	
	return result;
}




/// Multiply every component of a vector by a scalar value and return the resulting vector.
template < typename T, Size dimension >
RIM_FORCE_INLINE VectorND<T,dimension> operator + ( const T& c, const VectorND<T,dimension>& vector ) 
{
	VectorND<T,dimension> result;
	
	for ( Index i = 0; i < dimension; i++ )
		result.set( i, vector.get(i) + c );
	
	return result;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Standalone Functions
//############		
//##########################################################################################
//##########################################################################################




/// Return the dot product of two vectors.
template < typename T, Size dimension >
RIM_FORCE_INLINE T dot( const VectorND<T,dimension>& v1, const VectorND<T,dimension>& v2 )
{
	T result(0);
	
	for ( Index i = 0; i < dimension; i++ )
		result += v1[i]*v2[i];
	
	return result;
}




/// Return the cross product of two 3-dimensional vectors.
template <typename T>
RIM_FORCE_INLINE VectorND<T,3> cross( const VectorND<T,3>& v1, const VectorND<T,3>& v2 )
{
	VectorND<T,3> result;
	
	result[0] = v1[1]*v2[2] - v1[2]*v2[1];
	result[1] = v1[2]*v2[0] - v1[0]*v2[2];
	result[2] = v1[0]*v2[1] - v1[1]*v2[0];
	
	return result;
}




/// Return the midpoint of two vectors.
template < typename T, Size dimension >
RIM_FORCE_INLINE VectorND<T,dimension> midpoint( const VectorND<T,dimension>& v1, const VectorND<T,dimension>& v2 )
{
	VectorND<T,dimension> result;
	
	for ( Index i = 0; i < dimension; i++ )
		result[i] = (v1[i] + v2[i])*T(0.5);
	
	return result;
}




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_VECTOR_ND_H
