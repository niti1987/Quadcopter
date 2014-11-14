/*
 *  rimVector2D.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 10/16/07.
 *  Copyright 2007 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_VECTOR_2D_H
#define INCLUDE_RIM_VECTOR_2D_H


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
/// A class which represents a 2-dimensional point or vector.
template < typename T >
class Vector2D
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new 2D vector with all elements equal to zero.
			RIM_FORCE_INLINE Vector2D()
				:	x( T(0) ),
					y( T(0) )
			{
			}
			
			
			
			
			/// Create a new 2D vector with all elements equal to a single value.
			/** 
			  * This constructor creates a uniform 2D vector with all elements
			  * equal to each other and equal to the single constructor parameter
			  * value.
			  * 
			  * @param value - The value to set all elements of the vector to.
			  */
			RIM_FORCE_INLINE explicit Vector2D( T value )
				:	x( value ),
					y( value )
			{
			}
			
			
			
			
			/// Create a new 2D vector from a pointer to a 2 element array.
			/** 
			  * This constructor takes a pointer to an array of 2 values 
			  * and sets it's x and y coordinates to be the 0th, 1th,
			  * indexed values in the array. No error checking is
			  * performed, so make sure to pass in a correct array of values
			  * or expect the worst.
			  * 
			  * @param array - An indexed array of 2 values for the vector's coordinates.
			  */
			RIM_FORCE_INLINE explicit Vector2D( const T* array )
				:	x( array[0] ),
					y( array[1] )
			{
			}
			
			
			
			
			/// Create a new 2D vector by specifying it's x and y values.
			/** 
			  * This constructor sets each of the vector's x, and y components
			  * values to be the 1st, and 2nd parameters of the constructor,
			  * respectively.
			  * 
			  * @param newX - The X coordinate of the new vector.
			  * @param newY - The Y coordinate of the new vector.
			  */
			RIM_FORCE_INLINE Vector2D( T newX, T newY )
				:	x( newX ),
					y( newY )
			{
			}
			
			
			
			/// Create a new 2D vector from an existing vector (copy it), templatized version.
			/** 
			  * This constructor takes the x and y components of the
			  * vector parameter and sets the components of this vector
			  * to be the same. This is a templatized version of the above copy constructor.
			  * 
			  * @param vector - The vector to be copied.
			  */
			template < typename U >
			RIM_FORCE_INLINE Vector2D( const Vector2D<U>& vector )
				:	x( (T)vector.x ),
					y( (T)vector.y )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Magnitude Methods
			
			
			
			
			/// Get the magnitude of this vector (the length).
			/** 
			  * This Method finds the magnitude of this vector
			  * using the formula: magnitude = sqrt( x*x + y*y ).
			  * It's value is always positive.
			  * 
			  * @return the magnitude of the vector.
			  */
			RIM_FORCE_INLINE T getMagnitude() const
			{
				return math::sqrt( x*x + y*y );
			}
			
			
			
			
			/// Get the square of the magnitude of this vector.
			/** 
			  * This method is provided in addition to the above
			  * getMagnitude() method in order to provide a faster
			  * alternate way of computing a magnitude-like quantity
			  * for the vector. For instance, when computing whether
			  * or not the magnitude of a vector is greater than some value,
			  * one can instead compare the square of the magnitude to the
			  * square of the value (avoiding the square root operation),
			  * with the same result.
			  * 
			  * @return the square of the magnitude of this vector.
			  */
			RIM_FORCE_INLINE T getMagnitudeSquared() const
			{
				return x*x + y*y;
			}
			
			
			
			
			/// Return a normalized version of this vector.
			/**
			  * This method normalizes this vector by dividing
			  * each component by the vector's magnitude and
			  * returning the result. This method does not modify
			  * the original vector.
			  * 
			  * @return a normalized version of this vector.
			  */
			RIM_FORCE_INLINE Vector2D<T> normalize() const
			{
				T inverseMagnitude = T(1)/math::sqrt( x*x + y*y );
				
				return Vector2D<T>( x*inverseMagnitude,
									y*inverseMagnitude );
			}
			
			
			
			
			/// Return a normalized version of this vector, placing the vector's magnitude in the output parameter.
			/**
			  * This method normalizes this vector by dividing
			  * each component by the vector's magnitude and
			  * returning the result. This method does not modify
			  * the original vector. The magnitude of the original vector is
			  * returned in the output parameter.
			  * 
			  * @return a normalized version of this vector.
			  */
			RIM_FORCE_INLINE Vector2D<T> normalize( T& magnitude ) const
			{
				magnitude = math::sqrt( x*x + y*y );
				T inverseMagnitude = T(1)/magnitude;
				
				return Vector2D<T>( x*inverseMagnitude,
									y*inverseMagnitude );
			}
			
			
			
			
			/// Project this vector on another vector and return the projected vector.
			/** 
			  * This method computes the vectoral projection of this vector
			  * onto another, and returns the resulting vector. This result should
			  * be parallel (within the precision of the vectors) to the original
			  * parameter vector. This method does not modify either original vector.
			  * 
			  * @param vector - The vector to project this vector on.
			  * @return the vectoral projection onto the parameter vector of this vector.
			  */
			RIM_FORCE_INLINE Vector2D<T> projectOn( const Vector2D<T>& vector ) const
			{
				Vector2D<T> norm = vector.normalize();
				
				return ( x*norm.x + y*norm.y )*norm;
			}
			
			
			
			
			/// Project this vector on a normalized vector and return the projected vector.
			/** 
			  * This method computes the vectoral projection of this vector
			  * onto another, and returns the resulting vector. This result should
			  * be parallel (within the precision of the vectors) to the original
			  * parameter vector. This method does not modify either original vector.
			  * The result of this operation is only correct if the projected-on vector
			  * is of unit length, though it is roughly 3 times faster than doing a standard
			  * projection.
			  * 
			  * @param vector - The vector to project this vector on.
			  * @return the vectoral projection onto the parameter vector of this vector.
			  */
			RIM_FORCE_INLINE Vector2D<T> projectOnNormalized( const Vector2D<T>& vector ) const
			{
				return ( x*vector.x + y*vector.y )*vector;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distance Methods
			
			
			
			
			/// Get the distance from this vector to another in 2D space.
			/** 
			  * This method essentially computes the magnitude of
			  * the subtraction of this vector minus the parameter vector.
			  * This treats each vector as a point in 2D space.
			  * 
			  * @param vector - the vector to query the distance to.
			  * @return the distance to the parameter vector.
			  */
			RIM_FORCE_INLINE T getDistanceTo( const Vector2D<T>& vector ) const
			{
				T minusX = vector.x - x;
				T minusY = vector.y - y;
				
				return math::sqrt( minusX*minusX + minusY*minusY );
			}
			
			
			
			
			/// Get the square of the distance from this vector to another in 2D space.
			/** 
			  * This method essentially computes the magnitude squared of
			  * the subtraction of this vector minus the parameter vector.
			  * This treats each vector as a point in 2D space. This function
			  * can be used for faster distance comparisions because it avoids
			  * the square root operation of the getDistanceTo() method.
			  * 
			  * @param vector - the vector to query the distance to.
			  * @return the distance to the parameter vector.
			  */
			RIM_FORCE_INLINE T getDistanceToSquared( const Vector2D<T>& vector ) const
			{
				T minusX = vector.x - x;
				T minusY = vector.y - y;
				
				return minusX*minusX + minusY*minusY;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Element Accessor Methods
			
			
			
			
			/// Return a shallow array representation of this vector.
			/** 
			  * This method returns a pointer to the address of the X coordinate
			  * of the vector and does not do any copying of the elements.
			  * Therefore, this method should only be used where one needs
			  * an array representation of a vector without having to 
			  * allocate more memory and copy the vector.
			  * 
			  * @return A pointer to a shallow array copy of this vector.
			  */
			RIM_FORCE_INLINE T* toArray()
			{
				return &x;
			}
			
			
			
			
			/// Get a shallow array representation of this vector.
			/** 
			  * This method returns a pointer to the address of the X coordinate
			  * of the vector and does not do any copying of the elements.
			  * Therefore, this method should only be used where one needs
			  * an array representation of a vector without having to 
			  * allocate more memory and copy the vector.
			  * 
			  * @return A pointer to a shallow array copy of this vector.
			  */
			RIM_FORCE_INLINE const T* toArray() const
			{
				return &x;
			}
			
			
			
			
			/// Return the X coordinate of this vector.
			RIM_FORCE_INLINE T getX() const
			{
				return x;
			}
			
			
			
			
			/// Return the Y coordinate of this vector.
			RIM_FORCE_INLINE T getY() const
			{
				return y;
			}
			
			
			
			
			/// Return the minimum coordinate of this vector.
			RIM_FORCE_INLINE T getMin() const
			{
				return math::min( x, y );
			}
			
			
			
			
			/// Return the maximum coordinate of this vector.
			RIM_FORCE_INLINE T getMax() const
			{
				return math::max( x, y );
			}
			
			
			
			
			/// Return an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0 or 1 and returns the X or Y
			  * coordinate of this vector, respectively. There is
			  * no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y.
			  * @return the value of the vector associated with the given index.
			  */
			RIM_FORCE_INLINE T& get( Index index )
			{
				RIM_DEBUG_ASSERT( index < 2 );
				
				return (&x)[index];
			}
			
			
			
			
			/// Return an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0 or 1 and returns the X or Y
			  * coordinate of this vector, respectively. There is
			  * no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y.
			  * @return the value of the vector associated with the given index.
			  */
			RIM_FORCE_INLINE const T& get( Index index ) const
			{
				RIM_DEBUG_ASSERT( index < 2 );
				
				return (&x)[index];
			}
			
			
			
			
			/// Return an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0 or 1 and returns the X or Y
			  * coordinate of this vector, respectively. There is
			  * no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y.
			  * @return the value of the vector associated with the given index.
			  */
			RIM_FORCE_INLINE T& operator () ( Index index )
			{
				RIM_DEBUG_ASSERT( index < 2 );
				
				return (&x)[index];
			}
			
			
			
			
			/// Return an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0 or 1 and returns the X or Y
			  * coordinate of this vector, respectively. There is
			  * no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y.
			  * @return the value of the vector associated with the given index.
			  */
			RIM_FORCE_INLINE const T& operator () ( Index index ) const
			{
				RIM_DEBUG_ASSERT( index < 2 );
				
				return (&x)[index];
			}
			
			
			
			
			/// Return an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0 or 1 and returns the X or Y
			  * coordinate of this vector, respectively. There is
			  * no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y.
			  * @return the value of the vector associated with the given index.
			  */
			RIM_FORCE_INLINE T& operator [] ( Index index )
			{
				RIM_DEBUG_ASSERT( index < 2 );
				
				return (&x)[index];
			}
			
			
			
			
			/// Return an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0 or 1 and returns the X or Y
			  * coordinate of this vector, respectively. There is
			  * no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y.
			  * @return the value of the vector associated with the given index.
			  */
			RIM_FORCE_INLINE const T& operator [] ( Index index ) const
			{
				RIM_DEBUG_ASSERT( index < 2 );
				
				return (&x)[index];
			}
			
			
			
			
			/// Set the X coordinate of the vector to the specified value.
			RIM_FORCE_INLINE void setX( T newX )
			{
				x = newX;
			}
			
			
			
			
			/// Set the Y coordinate of the vector to the specified value.
			RIM_FORCE_INLINE void setY( T newY )
			{
				y = newY;
			}
			
			
			
			
			/// Set the X and Y coordinates of the vector to the specified values.
			/** 
			  * This method takes 2 parameters representing the 2 coordinates of this
			  * vector and sets this vector's coordinates to have those values.
			  * 
			  * @param newX - The new X coordinate of the vector.
			  * @param newY - The new Y coordinate of the vector.
			  */
			RIM_FORCE_INLINE void setAll( T newX, T newY )
			{
				x = newX;
				y = newY;
			}
			
			
			
			
			/// Set an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0 or 1, and sets the X or Y
			  * coordinate of this vector to be the new value, respectively.
			  * There is no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y.
			  * @param newValue - The new value of the coordinate with the given index.
			  */
			RIM_FORCE_INLINE void set( Index index, T newValue )
			{
				RIM_DEBUG_ASSERT( index < 2 );
				
				(&x)[index] = newValue;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Compare two vectors component-wise for equality
			RIM_FORCE_INLINE bool operator == ( const Vector2D<T>& v ) const
			{
				return x == v.x && y == v.y;
			}
			
			
			
			
			
			/// Compare two vectors component-wise for inequality
			RIM_FORCE_INLINE bool operator != ( const Vector2D<T>& v ) const
			{
				return x != v.x || y != v.y;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Negation/Positivation Operators
			
			
			
			
			/// Negate a vector.
			/** 
			  * This method returns the negation of a vector, making
			  * it point in the opposite direction. It does not modify the
			  * original vector.
			  * 
			  * @return the negation of the original vector.
			  */
			RIM_FORCE_INLINE Vector2D<T> operator - () const
			{
				return Vector2D<T>( -x, -y );
			}
			
			
			
			
			/// Postive a vector, returning a copy of it. Operator does nothing.
			/**
			  * This operator doesn't do anything but return the original
			  * value of the vector that it affects.
			  * 
			  * @return the same vector as the orignal vector.
			  */
			RIM_FORCE_INLINE Vector2D<T> operator + () const
			{
				return Vector2D<T>( x, y );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmatic Operators
			
			
			
			
			/// Add this vector to another and return the result.
			/** 
			  * This method adds another vector to this one, component-wise,
			  * and returns this addition. It does not modify either of the original
			  * vectors.
			  * 
			  * @param vector - The vector to add to this one.
			  * @return The addition of this vector and the parameter.
			  */
			RIM_FORCE_INLINE Vector2D<T> operator + ( const Vector2D<T>& vector ) const
			{
				return Vector2D<T>( x + vector.x, y + vector.y );
			}
			
			
			
			
			/// Add a value to every component of this vector.
			/** 
			  * This method adds the value parameter to every component
			  * of the vector, and returns a vector representing this result.
			  * It does not modifiy the original vector.
			  * 
			  * @param value - The value to add to all components of this vector.
			  * @return The resulting vector of this addition.
			  */
			RIM_FORCE_INLINE Vector2D<T> operator + ( const T& value ) const
			{
				return Vector2D<T>( x + value, y + value );
			}
			
			
			
			
			/// Subtract a vector from this vector component-wise and return the result.
			/** 
			  * This method subtracts another vector from this one, component-wise,
			  * and returns this subtraction. It does not modify either of the original
			  * vectors.
			  * 
			  * @param vector - The vector to subtract from this one.
			  * @return The subtraction of the the parameter from this vector.
			  */
			RIM_FORCE_INLINE Vector2D<T> operator - ( const Vector2D<T>& vector ) const
			{
				return Vector2D<T>( x - vector.x, y - vector.y );
			}
			
			
			
			
			/// Subtract a value from every component of this vector.
			/** 
			  * This method subtracts the value parameter from every component
			  * of the vector, and returns a vector representing this result.
			  * It does not modifiy the original vector.
			  * 
			  * @param value - The value to subtract from all components of this vector.
			  * @return The resulting vector of this subtraction.
			  */
			RIM_FORCE_INLINE Vector2D<T> operator - ( const T& value ) const
			{
				return Vector2D<T>( x - value, y - value );
			}
			
			
			
			
			/// Multiply component-wise this vector and another vector.
			/** 
			  * This operator multiplies each component of this vector
			  * by the corresponding component of the other vector and
			  * returns a vector representing this result. It does not modify
			  * either original vector.
			  * 
			  * @param vector - The vector to multiply this vector by.
			  * @return The result of the multiplication.
			  */
			RIM_FORCE_INLINE Vector2D<T> operator * ( const Vector2D<T>& vector ) const
			{
				return Vector2D<T>( x*vector.x, y*vector.y );
			}
			
			
			
			
			/// Multiply every component of this vector by a value and return the result.
			/** 
			  * This method multiplies the value parameter with every component
			  * of the vector, and returns a vector representing this result.
			  * It does not modifiy the original vector.
			  * 
			  * @param value - The value to multiplly with all components of this vector.
			  * @return The resulting vector of this multiplication.
			  */
			RIM_FORCE_INLINE Vector2D<T> operator * ( const T& value ) const
			{
				return Vector2D<T>( x*value, y*value );
			}
			
			
			
			
			/// Multiply component-wise this vector and another vector.
			/** 
			  * This operator multiplies each component of this vector
			  * by the corresponding component of the other vector and
			  * returns a vector representing this result. It does not modify
			  * either original vector.
			  * 
			  * @param vector - The vector to multiply this vector by.
			  * @return The result of the multiplication.
			  */
			RIM_FORCE_INLINE Vector2D<T> operator / ( const Vector2D<T>& vector ) const
			{
				return Vector2D<T>( x/vector.x, y/vector.y );
			}
			
			
			
			
			/// Divide every component of this vector by a value and return the result.
			/** 
			  * This method Divides every component of the vector by the value parameter, 
			  * and returns a vector representing this result.
			  * It does not modifiy the original vector.
			  * 
			  * @param value - The value to divide all components of this vector by.
			  * @return The resulting vector of this division.
			  */
			RIM_FORCE_INLINE Vector2D<T> operator / ( const T& value ) const
			{
				T inverseValue = T(1) / value;
				
				return Vector2D<T>( x*inverseValue, y*inverseValue );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmatic Assignment Operators with Vectors
			
			
			
			
			/// Add a vector to this vector, modifying this original vector.
			/**
			  * This method adds another vector to this vector, component-wise,
			  * and sets this vector to have the result of this addition.
			  * 
			  * @param vector - The vector to add to this vector.
			  * @return A reference to this modified vector.
			  */
			RIM_FORCE_INLINE Vector2D<T>& operator += ( const Vector2D<T>& vector )
			{
				x += vector.x;
				y += vector.y;
				
				return *this;
			}
			
			
			
			/// Subtract a vector from this vector, modifying this original vector.
			/**
			  * This method subtracts another vector from this vector, component-wise,
			  * and sets this vector to have the result of this subtraction.
			  * 
			  * @param vector - The vector to subtract from this vector.
			  * @return A reference to this modified vector.
			  */
			RIM_FORCE_INLINE Vector2D<T>& operator -= ( const Vector2D<T>& vector )
			{
				x -= vector.x;
				y -= vector.y;
				
				return *this;
			}
			
			
			
			
			/// Multiply component-wise this vector and another vector and modify this vector.
			/** 
			  * This operator multiplies each component of this vector
			  * by the corresponding component of the other vector and
			  * modifies this vector to contain the result.
			  * 
			  * @param vector - The vector to multiply this vector by.
			  * @return A reference to this modified vector.
			  */
			RIM_FORCE_INLINE Vector2D<T>& operator *= ( const Vector2D<T>& vector )
			{
				x *= vector.x;
				y *= vector.y;
				
				return *this;
			}
			
			
			
			
			/// Divide component-wise this vector by another vector and modify this vector.
			/** 
			  * This operator divides each component of this vector
			  * by the corresponding component of the other vector and
			  * modifies this vector to contain the result.
			  * 
			  * @param vector - The vector to divide this vector by.
			  * @return A reference to this modified vector.
			  */
			RIM_FORCE_INLINE Vector2D<T>& operator /= ( const Vector2D<T>& vector )
			{
				x /= vector.x;
				y /= vector.y;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmatic Assignment Operators with Values
			
			
			
			
			/// Add a value to each component of this vector, modifying it.
			/**
			  * This operator adds a value to each component of this vector
			  * and modifies this vector to store the result.
			  * 
			  * @param value - The value to add to every component of this vector.
			  * @return A reference to this modified vector.
			  */
			RIM_FORCE_INLINE Vector2D<T>& operator += ( const T& value )
			{
				x += value;
				y += value;
				
				return *this;
			}
			
			
			
			
			/// Subtract a value from each component of this vector, modifying it.
			/**
			  * This operator subtracts a value from each component of this vector
			  * and modifies this vector to store the result.
			  * 
			  * @param value - The value to subtract from every component of this vector.
			  * @return A reference to this modified vector.
			  */
			RIM_FORCE_INLINE Vector2D<T>& operator -= ( const T& value )
			{
				x -= value;
				y -= value;
				
				return *this;
			}
			
			
			
			
			/// Multiply a value with each component of this vector, modifying it.
			/**
			  * This operator multiplies a value with each component of this vector
			  * and modifies this vector to store the result.
			  * 
			  * @param value - The value to multiply with every component of this vector.
			  * @return A reference to this modified vector.
			  */
			RIM_FORCE_INLINE Vector2D<T>& operator *= ( const T& value )
			{
				x *= value;
				y *= value;
				
				return *this;
			}
			
			
			
			
			/// Divide each component of this vector by a value, modifying it.
			/**
			  * This operator Divides each component of this vector by value
			  * and modifies this vector to store the result.
			  * 
			  * @param value - The value to multiply with every component of this vector.
			  * @return A reference to this modified vector.
			  */
			RIM_FORCE_INLINE Vector2D<T>& operator /= ( const T& value )
			{
				T inverseValue = T(1) / value;
				
				x *= inverseValue;
				y *= inverseValue;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Conversion Methods
			
			
			
			
			/// Convert this 2D vector into a human-readable string representation.
			RIM_NO_INLINE data::String toString() const
			{
				data::StringBuffer buffer;
				
				buffer << "< " << x << ", " << y << " >";
				
				return buffer.toString();
			}
			
			
			
			
			/// Convert this 2D vector into a human-readable string representation.
			RIM_FORCE_INLINE operator data::String () const
			{
				return this->toString();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			union
			{
				struct
				{
					/// The red component of a 2-component color.
					T r;
					
					/// The green component of a 2-component color.
					T g;
				};
				
				struct
				{
					/// The X coordinate of a 3D vector.
					T x;
					
					/// The Y coordinate of a 3D vector.
					T y;
				};
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// A constant vector with all elements equal to zero
			static const Vector2D<T> ZERO;
			
			
			
			
};



template <typename T>
const Vector2D<T> Vector2D<T>:: ZERO;



//##########################################################################################
//##########################################################################################
//############		
//############		Commutative Arithmatic Operators
//############		
//##########################################################################################
//##########################################################################################




/// Add a value to every component of the vector.
/** 
  * This operator adds the value parameter to every component
  * of the vector, and returns a vector representing this result.
  * It does not modifiy the original vector.
  * 
  * @param value - The value to add to all components of the vector.
  * @param vector - The vector to be added to.
  * @return The resulting vector of this addition.
  */
template < typename T >
RIM_FORCE_INLINE Vector2D<T> operator + ( const T& value, const Vector2D<T>& vector )
{
    return Vector2D<T>( vector.x + value, vector.y + value );
}




/// Subtract every component of the vector from the value, returning a vector result.
/** 
  * This operator subtracts every component of the 2nd paramter, a vector,
  * from the 1st paramter, a value, and then returns a vector containing the
  * resulting vectoral components. This operator does not modify the orignal vector.
  * 
  * @param value - The value to subtract all components of the vector from.
  * @param vector - The vector to be subtracted.
  * @return The resulting vector of this subtraction.
  */
template < typename T >
RIM_FORCE_INLINE Vector2D<T> operator - ( const T& value, const Vector2D<T>& vector )
{
	return Vector2D<T>( value - vector.x, value - vector.y );
}




/// Multiply every component of the vector with the value, returning a vector result.
/** 
  * This operator multiplies every component of the 2nd paramter, a vector,
  * from the 1st paramter, a value, and then returns a vector containing the
  * resulting vectoral components. This operator does not modify the orignal vector.
  * 
  * @param value - The value to multiply with all components of the vector.
  * @param vector - The vector to be multiplied with.
  * @return The resulting vector of this multiplication.
  */
template < typename T >
RIM_FORCE_INLINE Vector2D<T> operator * ( const T& value, const Vector2D<T>& vector ) 
{
	return Vector2D<T>( vector.x*value, vector.y*value );
}




/// Divide a value by every component of the vector, returning a vector result.
/** 
  * This operator divides the provided value by every component of
  * the vector, returning a vector representing the component-wise division.
  * The operator does not modify the original vector.
  * 
  * @param value - The value to be divided by all components of the vector.
  * @param vector - The vector to be divided by.
  * @return The resulting vector of this division.
  */
template < typename T >
RIM_FORCE_INLINE Vector2D<T> operator / ( const T& value, const Vector2D<T>& vector ) 
{
	return Vector2D<T>( value/vector.x, value/vector.y );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Other Vector Functions
//############		
//##########################################################################################
//##########################################################################################




/// Compute and return the dot product of two vectors.
/** 
  * This method adds all components of the component-wise multiplication
  * of the two vectors together and returns the scalar result. It does
  * not modify either of the original vectors. If the dot product is
  * zero, then the two vectors are perpendicular.
  * 
  * @param vector1 - The first vector of the dot product.
  * @param vector2 - The second vector of the dot product.
  * @return The dot product of the two vector parameters.
  */
template < typename T >
RIM_FORCE_INLINE T dot( const Vector2D<T>& vector1, const Vector2D<T>& vector2 )
{
	return vector1.x*vector2.x + vector1.y*vector2.y;
}




/// Compute and return the perp product of one vector.
/** 
  * This method computes and returns a vector representing
  * the perp product of the parameter vector. This vector
  * should be perpendicular to the original vector and have 
  * the same magnitude. It does not modify the original vector.
  * 
  * @param vector - The vector to be rotated 90 degrees.
  * @return The perp product vector of the vector parameter.
  */
template < typename T >
RIM_FORCE_INLINE Vector2D<T> perp( const Vector2D<T>& vector )
{
	return Vector2D<T>(	-vector.y, vector.x );
}




/// Compute the midpoint of two vectors.
/**
  * This method adds the two vector parameters together
  * component-wise and then multiplies by 1/2, resulting
  * in a point in 3D space at the midpoint between the two vectors.
  * The midpoint is essentially the component-wise average of two vectors.
  * Both original vectors are not modified.
  * 
  * @param vector1 - The first vector of the midpoint calculation.
  * @param vector2 - The second vector of the midpoint calculation.
  * @return The midpoint of the two vector parameters.
  */
template < typename T >
RIM_FORCE_INLINE Vector2D<T> midpoint( const Vector2D<T>& vector1, const Vector2D<T>& vector2 )
{
	return Vector2D<T>(	(vector1.x + vector2.x)*T(0.5), 
						(vector1.y + vector2.y)*T(0.5) );
}




/// Return the absolute value of the specified vector, such that the every component is positive.
template < typename T >
RIM_FORCE_INLINE Vector2D<T> abs( const Vector2D<T>& vector )
{
	return Vector2D<T>( math::abs(vector.x), math::abs(vector.y) );
}




/// Compute the component-wise minimum of two vectors.
template < typename T >
RIM_FORCE_INLINE Vector2D<T> min( const Vector2D<T>& vector1, const Vector2D<T>& vector2 )
{
	return Vector2D<T>(	math::min( vector1.x, vector2.x ),
						math::min( vector1.y, vector2.y ) );
}




/// Compute the component-wise minimum of two vectors.
template < typename T >
RIM_FORCE_INLINE Vector2D<T> max( const Vector2D<T>& vector1, const Vector2D<T>& vector2 )
{
	return Vector2D<T>(	math::max( vector1.x, vector2.x ),
						math::max( vector1.y, vector2.y ) );
}




/// Return the floor of the specified vector, rounding each component down to the nearest integer.
template < typename T >
RIM_FORCE_INLINE Vector2D<T> floor( const Vector2D<T>& vector )
{
	return Vector2D<T>( math::floor(vector.x), math::floor(vector.y) );
}




/// Return the floor of the specified vector, rounding each component up to the nearest integer.
template < typename T >
RIM_FORCE_INLINE Vector2D<T> ceiling( const Vector2D<T>& vector )
{
	return Vector2D<T>( math::ceiling(vector.x), math::ceiling(vector.y) );
}




/// Return the component-wise modulus of the specified vector.
template < typename T >
RIM_FORCE_INLINE Vector2D<T> mod( const Vector2D<T>& vector, const T& modulus )
{
	return Vector2D<T>( math::mod(vector.x, modulus), math::mod(vector.y, modulus) );
}




/// Return the component-wise modulus of the specified vector.
template < typename T >
RIM_FORCE_INLINE Vector2D<T> mod( const Vector2D<T>& vector, const Vector2D<T>& modulus )
{
	return Vector2D<T>( math::mod(vector.x, modulus.x), math::mod(vector.y, modulus.y) );
}




/// Return whether or not any component of this vector is Not-A-Number.
template < typename T >
RIM_FORCE_INLINE Bool isNAN( const Vector2D<T>& vector)
{
	return math::isNAN(vector.x) || math::isNAN(vector.y);
}




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_VECTOR_2D_H
