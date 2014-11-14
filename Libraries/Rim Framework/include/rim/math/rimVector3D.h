/*
 *  rimVector3D.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 10/16/07.
 *  Copyright 2007 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_VECTOR_3D_H
#define INCLUDE_RIM_VECTOR_3D_H


#include "rimMathConfig.h"


#include "../data/rimBasicString.h"
#include "../data/rimBasicStringBuffer.h"
#include "rimVector2D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a 3-dimensional point or vector.
template < typename T >
class Vector3D
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new 3D vector with all elements equal to zero.
			RIM_FORCE_INLINE Vector3D()
				:	x( T(0) ),
					y( T(0) ),
					z( T(0) )
			{
			}
			
			
			
			
			/// Create a new 3D vector with all elements equal to a single value.
			/** 
			  * This constructor creates a uniform 3D vector with all elements
			  * equal to each other and equal to the single constructor parameter
			  * value.
			  * 
			  * @param value - The value to set all elements of the vector to.
			  */
			RIM_FORCE_INLINE explicit Vector3D( T value )
				:	x( value ),
					y( value ),
					z( value )
			{
			}
			
			
			
			
			/// Create a new 3D vector from a pointer to a 3 element array.
			/** 
			  * This constructor takes a pointer to an array of 3 values 
			  * and sets it's x, y, and z coordinates to be the 0th, 1th,
			  * and 2th indexed values in the array. No error checking is
			  * performed, so make sure to pass in a correct array of values
			  * or expect the worst.
			  * 
			  * @param array - An indexed array of 3 values for the vector's coordinates.
			  */
			RIM_FORCE_INLINE explicit Vector3D( const T* array )
				:	x( array[0] ),
					y( array[1] ),
					z( array[2] )
			{
			}
			
			
			
			
			/// Create a new 3D vector by specifying it's x, y, and z values.
			/** 
			  * This constructor sets each of the vector's x, y, and z coordinate
			  * values to be the 1st, 2nd, and 3rd parameters of the constructor,
			  * respectively.
			  * 
			  * @param newX - The X coordinate of the new vector.
			  * @param newY - The Y coordinate of the new vector.
			  * @param newZ - The Z coordinate of the new vector.
			  */
			RIM_FORCE_INLINE Vector3D( T newX, T newY, T newZ )
				:	x( newX ),
					y( newY ),
					z( newZ )
			{
			}
			
			
			
			
			/// Create a new 3D vector from a 2D vector and a value for the Z coordinate.
			/** 
			  * This constructor takes the x and y coordinates of the first parameter,
			  * a 2D vector, and sets the x and y coordinates of this vector to be
			  * the same. It then takes the 2nd paramter, a value, and sets the z
			  * coordinate of this vector to be that value.
			  * 
			  * @param vector - A 2D vector for the x and y coordinates of this vector.
			  * @param newZ - The value for the Z coordinate of this vector.
			  */
			RIM_FORCE_INLINE Vector3D( const Vector2D<T>& vector, T newZ )
				:	x( vector.x ),
					y( vector.y ),
					z( newZ )
			{
			}
			
			
			
			
			/// Create a new 3D vector from a value for the X coordinate and a 2D vector.
			/** 
			  * This constructor sets the x coordinate of this vector to be the
			  * same as the value of the first parameter, and then sets the 
			  * y and z coordinates of this vector to be the x and y coordinates of 
			  * the 2nd parameter, a 2D vector.
			  * 
			  * @param newX - The value for the x coordinate of this vector.
			  * @param vector - A 2D vector for the y and z coordinates of this vector.
			  */
			RIM_FORCE_INLINE Vector3D( T newX, const Vector2D<T>& vector )
				:	x( newX ),
					y( vector.x ),
					z( vector.y )
			{
			}
			
			
			
			
			/// Create a new 3D vector from an existing vector (copy it), templatized version.
			/** 
			  * This constructor takes the x, y, and z values of the
			  * vector parameter and sets the coordinates of this vector
			  * to be the same. This is a templatized version of the above copy constructor.
			  * 
			  * @param vector - The vector to be copied.
			  */
			template < typename U >
			RIM_FORCE_INLINE Vector3D( const Vector3D<U>& vector )
				:	x( (T)vector.x ),
					y( (T)vector.y ),
					z( (T)vector.z )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Magnitude Methods
			
			
			
			
			/// Get the magnitude of this vector (the length).
			/** 
			  * This method finds the magnitude of this vector
			  * using the formula: magnitude = sqrt( x*x + y*y + z*z ).
			  * It's value is always positive.
			  * 
			  * @return the magnitude of the vector.
			  */
			RIM_FORCE_INLINE T getMagnitude() const
			{
				return math::sqrt( x*x + y*y + z*z );
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
				return x*x + y*y + z*z;
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
			RIM_FORCE_INLINE Vector3D<T> normalize() const
			{
				T inverseMagnitude = T(1)/math::sqrt( x*x + y*y + z*z );
				
				return Vector3D<T>( x*inverseMagnitude,
									y*inverseMagnitude,
									z*inverseMagnitude );
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
			RIM_FORCE_INLINE Vector3D<T> normalize( T& magnitude ) const
			{
				magnitude = math::sqrt( x*x + y*y + z*z );
				T inverseMagnitude = T(1)/magnitude;
				
				return Vector3D<T>( x*inverseMagnitude,
									y*inverseMagnitude,
									z*inverseMagnitude );
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
			RIM_FORCE_INLINE Vector3D<T> projectOn( const Vector3D<T>& vector ) const
			{
				Vector3D<T> norm = vector.normalize();
				
				return (x*norm.x + y*norm.y + z*norm.z)*norm;
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
			RIM_FORCE_INLINE Vector3D<T> projectOnNormalized( const Vector3D<T>& vector ) const
			{
				return (x*vector.x + y*vector.y + z*vector.z)*vector;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distance Methods
			
			
			
			
			/// Get the distance from this vector to another in 3D space.
			/** 
			  * This method essentially computes the magnitude of
			  * the subtraction of this vector minus the parameter vector.
			  * This treats each vector as a point in 3D space.
			  * 
			  * @param vector - the vector to query the distance to.
			  * @return the distance to the parameter vector.
			  */
			RIM_FORCE_INLINE T getDistanceTo( const Vector3D<T>& vector ) const
			{
				T minusX = vector.x - x;
				T minusY = vector.y - y;
				T minusZ = vector.z - z;
				
				return math::sqrt( minusX*minusX + minusY*minusY + minusZ*minusZ );
			}
			
			
			
			
			/// Get the square of the distance from this vector to another in 3D space.
			/** 
			  * This method essentially computes the magnitude squared of
			  * the subtraction of this vector minus the parameter vector.
			  * This treats each vector as a point in 3D space. This function
			  * can be used for faster distance comparisions because it avoids
			  * the square root operation of the getDistanceTo() method.
			  * 
			  * @param vector - the vector to query the distance to.
			  * @return the distance to the parameter vector.
			  */
			RIM_FORCE_INLINE T getDistanceToSquared( const Vector3D<T>& vector ) const
			{
				T minusX = vector.x - x;
				T minusY = vector.y - y;
				T minusZ = vector.z - z;
				
				return minusX*minusX + minusY*minusY + minusZ*minusZ;
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
			
			
			
			
			/// Return the Z coordinate of this vector.
			RIM_FORCE_INLINE T getZ() const
			{
				return z;
			}
			
			
			
			
			/// Return a 2D vector containing the X and Y elements of this 3D vector.
			RIM_FORCE_INLINE Vector2D<T> getXY() const
			{
				return Vector2D<T>( x, y );
			}
			
			
			
			
			/// Return a 2D vector containing the X and Z elements of this 3D vector.
			RIM_FORCE_INLINE Vector2D<T> getXZ() const
			{
				return Vector2D<T>( x, z );
			}
			
			
			
			
			/// Return a 2D vector containing the Y and Z elements of this 3D vector.
			RIM_FORCE_INLINE Vector2D<T> getYZ() const
			{
				return Vector2D<T>( y, z );
			}
			
			
			
			
			/// Return the minimum component of this vector.
			RIM_FORCE_INLINE T getMin() const
			{
				return math::min( math::min( x, y ), z );
			}
			
			
			
			
			/// Return the maximum component of this vector.
			RIM_FORCE_INLINE T getMax() const
			{
				return math::max( math::max( x, y ), z );
			}
			
			
			
			
			/// Get an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0, 1, or 2, and returns the X, Y, or Z
			  * coordinate of this vector, respectively. There is
			  * no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y, 2 = Z.
			  * @return the value of the vector associated with the given index.
			  */
			RIM_FORCE_INLINE T& get( Index index )
			{
				RIM_DEBUG_ASSERT( index < 3 );
				
				return (&x)[index];
			}
			
			
			
			
			/// Get an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0, 1, or 2, and returns the X, Y, or Z
			  * coordinate of this vector, respectively. There is
			  * no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y, 2 = Z.
			  * @return the value of the vector associated with the given index.
			  */
			RIM_FORCE_INLINE const T& get( Index index ) const
			{
				RIM_DEBUG_ASSERT( index < 3 );
				
				return (&x)[index];
			}
			
			
			
			
			/// Get an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0, 1, or 2, and returns the X, Y, or Z
			  * coordinate of this vector, respectively. There is
			  * no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y, 2 = Z.
			  * @return the value of the vector associated with the given index.
			  */
			RIM_FORCE_INLINE T& operator () ( Index index )
			{
				RIM_DEBUG_ASSERT( index < 3 );
				
				return (&x)[index];
			}
			
			
			
			
			/// Get an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0, 1, or 2, and returns the X, Y, or Z
			  * coordinate of this vector, respectively. There is
			  * no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y, 2 = Z.
			  * @return the value of the vector associated with the given index.
			  */
			RIM_FORCE_INLINE const T& operator () ( Index index ) const
			{
				RIM_DEBUG_ASSERT( index < 3 );
				
				return (&x)[index];
			}
			
			
			
			
			/// Get an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0, 1, or 2, and returns the X, Y, or Z
			  * coordinate of this vector, respectively. There is
			  * no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y, 2 = Z.
			  * @return the value of the vector associated with the given index.
			  */
			RIM_FORCE_INLINE T& operator [] ( Index index )
			{
				RIM_DEBUG_ASSERT( index < 3 );
				
				return (&x)[index];
			}
			
			
			
			
			/// Get an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0, 1, or 2, and returns the X, Y, or Z
			  * coordinate of this vector, respectively. There is
			  * no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y, 2 = Z.
			  * @return the value of the vector associated with the given index.
			  */
			RIM_FORCE_INLINE const T& operator [] ( Index index ) const
			{
				RIM_DEBUG_ASSERT( index < 3 );
				
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
			
			
			
			
				/// Set the Z coordinate of the vector to the specified value.
			RIM_FORCE_INLINE void setZ( T newZ )
			{
				z = newZ;
			}
			
			
			
			
			/// Set the X, Y, and Z coordinates of the vector to the specified values.
			/** 
			  * This method takes 3 parameter representing the 3 coordinates of this
			  * vector and sets this vector's coordinates to have those values.
			  * 
			  * @param newX - The new X coordinate of the vector.
			  * @param newY - The new Y coordinate of the vector.
			  * @param newZ - The new Z coordinate of the vector.
			  */
			RIM_FORCE_INLINE void setAll( T newX, T newY, T newZ )
			{
				x = newX;
				y = newY;
				z = newZ;
			}
			
			
			
			
			/// Set an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0, 1, or 2, and sets the X, Y, or Z
			  * coordinate of this vector to be the new value, respectively.
			  * There is no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y, 2 = Z.
			  * @param newValue - The new value of the coordinate with the given index.
			  */
			RIM_FORCE_INLINE void set( Index index, T newValue )
			{
				RIM_DEBUG_ASSERT( index < 3 );
				
				(&x)[index] = newValue;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Compare two vectors component-wise for equality
			RIM_FORCE_INLINE bool operator == ( const Vector3D<T>& v ) const
			{
				return x == v.x && y == v.y && z == v.z;
			}
			
			
			
			
			
			/// Compare two vectors component-wise for inequality
			RIM_FORCE_INLINE bool operator != ( const Vector3D<T>& v ) const
			{
				return x != v.x || y != v.y || z != v.z;
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
			RIM_FORCE_INLINE Vector3D<T> operator - () const
			{
				return Vector3D<T>( -x, -y, -z );
			}
			
			
			
			
			/// Postive a vector, returning a copy of it. Operator does nothing.
			/**
			  * This operator doesn't do anything but return the original
			  * value of the vector that it affects.
			  * 
			  * @return the same vector as the orignal vector.
			  */
			RIM_FORCE_INLINE Vector3D<T> operator + () const
			{
				return Vector3D<T>( x, y, z );
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
			RIM_FORCE_INLINE Vector3D<T> operator + ( const Vector3D<T>& vector ) const
			{
				return Vector3D<T>( x + vector.x, y + vector.y, z + vector.z );
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
			RIM_FORCE_INLINE Vector3D<T> operator + ( const T& value ) const
			{
				return Vector3D<T>( x + value, y + value, z + value );
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
			RIM_FORCE_INLINE Vector3D<T> operator - ( const Vector3D<T>& vector ) const
			{
				return Vector3D<T>( x - vector.x, y - vector.y, z - vector.z );
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
			RIM_FORCE_INLINE Vector3D<T> operator - ( const T& value ) const
			{
				return Vector3D<T>( x - value, y - value, z - value );
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
			RIM_FORCE_INLINE Vector3D<T> operator * ( const Vector3D<T>& vector ) const
			{
				return Vector3D<T>( x*vector.x, y*vector.y, z*vector.z );
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
			RIM_FORCE_INLINE Vector3D<T> operator * ( const T& value ) const
			{
				return Vector3D<T>( x*value, y*value, z*value );
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
			RIM_FORCE_INLINE Vector3D<T> operator / ( const Vector3D<T>& vector ) const
			{
				return Vector3D<T>( x/vector.x, y/vector.y, z/vector.z );
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
			RIM_FORCE_INLINE Vector3D<T> operator / ( const T& value ) const
			{
				T inverseValue = T(1) / value;
				
				return Vector3D<T>( x*inverseValue, y*inverseValue, z*inverseValue );
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
			RIM_FORCE_INLINE Vector3D<T>& operator += ( const Vector3D<T>& vector )
			{
				x += vector.x;
				y += vector.y;
				z += vector.z;
				
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
			RIM_FORCE_INLINE Vector3D<T>& operator -= ( const Vector3D<T>& vector )
			{
				x -= vector.x;
				y -= vector.y;
				z -= vector.z;
				
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
			RIM_FORCE_INLINE Vector3D<T>& operator *= ( const Vector3D<T>& vector )
			{
				x *= vector.x;
				y *= vector.y;
				z *= vector.z;
				
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
			RIM_FORCE_INLINE Vector3D<T>& operator /= ( const Vector3D<T>& vector )
			{
				x /= vector.x;
				y /= vector.y;
				z /= vector.z;
				
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
			RIM_FORCE_INLINE Vector3D<T>& operator += ( const T& value )
			{
				x += value;
				y += value;
				z += value;
				
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
			RIM_FORCE_INLINE Vector3D<T>& operator -= ( const T& value )
			{
				x -= value;
				y -= value;
				z -= value;
				
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
			RIM_FORCE_INLINE Vector3D<T>& operator *= ( const T& value )
			{
				x *= value;
				y *= value;
				z *= value;
				
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
			RIM_FORCE_INLINE Vector3D<T>& operator /= ( const T& value )
			{
				T inverseValue = T(1) / value;
				
				x *= inverseValue;
				y *= inverseValue;
				z *= inverseValue;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Conversion Methods
			
			
			
			
			/// Convert this 3D vector into a human-readable string representation.
			RIM_NO_INLINE data::String toString() const
			{
				data::StringBuffer buffer;
				
				buffer << "< " << x << ", " << y << ", " << z << " >";
				
				return buffer.toString();
			}
			
			
			
			
			/// Convert this 3D vector into a human-readable string representation.
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
					/// The red component of a 3-component color.
					T r;
					
					/// The green component of a 3-component color.
					T g;
					
					/// The blue component of a 3-component color.
					T b;
				};
				
				struct
				{
					/// The X coordinate of a 3D vector.
					T x;
					
					/// The Y coordinate of a 3D vector.
					T y;
					
					/// The Z coordinate of a 3D vector.
					T z;
				};
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// A constant vector with all elements equal to zero
			static const Vector3D<T> ZERO;
			
			
			
			
};



template <typename T>
const Vector3D<T> Vector3D<T>:: ZERO;



//##########################################################################################
//##########################################################################################
//############		
//############		Commutative Arithmetic Operators
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
RIM_FORCE_INLINE Vector3D<T> operator + ( const T& value, const Vector3D<T>& vector )
{
    return Vector3D<T>( vector.x + value, vector.y + value, vector.z + value );
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
RIM_FORCE_INLINE Vector3D<T> operator - ( const T& value, const Vector3D<T>& vector )
{
	return Vector3D<T>( value - vector.x, value - vector.y, value - vector.z );
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
RIM_FORCE_INLINE Vector3D<T> operator * ( const T& value, const Vector3D<T>& vector ) 
{
	return Vector3D<T>( vector.x*value, vector.y*value,  vector.z*value );
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
RIM_FORCE_INLINE Vector3D<T> operator / ( const T& value, const Vector3D<T>& vector ) 
{
	return Vector3D<T>( value/vector.x, value/vector.y,  value/vector.z );
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
RIM_FORCE_INLINE T dot( const Vector3D<T>& vector1, const Vector3D<T>& vector2 )
{
	return vector1.x*vector2.x + vector1.y*vector2.y + vector1.z*vector2.z;
}




/// Compute and return the cross product of two vectors.
/** 
  * This method computes and returns a vector representing
  * the cross product of the two parameter vectors. This vector
  * should be perpendicular to both of the original vectors. It does
  * not modify either of the original vectors.
  * 
  * @param vector1 - The first vector of the cross product.
  * @param vector2 - The second vector of the cross product.
  * @return The cross product vector of the two vector parameters.
  */
template < typename T >
RIM_FORCE_INLINE Vector3D<T> cross( const Vector3D<T>& vector1, const Vector3D<T>& vector2 )
{
	return Vector3D<T>( vector1.y*vector2.z - vector1.z*vector2.y,
						vector1.z*vector2.x - vector1.x*vector2.z,
						vector1.x*vector2.y - vector1.y*vector2.x );
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
RIM_FORCE_INLINE Vector3D<T> midpoint( const Vector3D<T>& vector1, const Vector3D<T>& vector2 )
{
	return Vector3D<T>(	(vector1.x + vector2.x)*T(0.5), 
						(vector1.y + vector2.y)*T(0.5),
						(vector1.z + vector2.z)*T(0.5) );
}




/// Return the absolute value of the specified vector, such that the every component is positive.
template < typename T >
RIM_FORCE_INLINE Vector3D<T> abs( const Vector3D<T>& vector )
{
	return Vector3D<T>( math::abs(vector.x), math::abs(vector.y), math::abs(vector.z) );
}




/// Compute the component-wise minimum of two vectors.
template < typename T >
RIM_FORCE_INLINE Vector3D<T> min( const Vector3D<T>& vector1, const Vector3D<T>& vector2 )
{
	return Vector3D<T>(	math::min( vector1.x, vector2.x ),
						math::min( vector1.y, vector2.y ),
						math::min( vector1.z, vector2.z ) );
}




/// Compute the component-wise minimum of two vectors.
template < typename T >
RIM_FORCE_INLINE Vector3D<T> max( const Vector3D<T>& vector1, const Vector3D<T>& vector2 )
{
	return Vector3D<T>(	math::max( vector1.x, vector2.x ),
						math::max( vector1.y, vector2.y ),
						math::max( vector1.z, vector2.z ) );
}




/// Return the floor of the specified vector, rounding each component down to the nearest integer.
template < typename T >
RIM_FORCE_INLINE Vector3D<T> floor( const Vector3D<T>& vector )
{
	return Vector3D<T>( math::floor(vector.x), math::floor(vector.y), math::floor(vector.z) );
}




/// Return the floor of the specified vector, rounding each component up to the nearest integer.
template < typename T >
RIM_FORCE_INLINE Vector3D<T> ceiling( const Vector3D<T>& vector )
{
	return Vector3D<T>( math::ceiling(vector.x), math::ceiling(vector.y), math::ceiling(vector.z) );
}




/// Return the component-wise modulus of the specified vector.
template < typename T >
RIM_FORCE_INLINE Vector3D<T> mod( const Vector3D<T>& vector, const T& modulus )
{
	return Vector3D<T>( math::mod(vector.x, modulus), math::mod(vector.y, modulus), math::mod(vector.z, modulus) );
}




/// Return the component-wise modulus of the specified vector.
template < typename T >
RIM_FORCE_INLINE Vector3D<T> mod( const Vector3D<T>& vector, const Vector3D<T>& modulus )
{
	return Vector3D<T>( math::mod(vector.x, modulus.x), math::mod(vector.y, modulus.y), math::mod(vector.z, modulus.z) );
}




/// Return whether or not any component of this vector is Not-A-Number.
template < typename T >
RIM_FORCE_INLINE Bool isNAN( const Vector3D<T>& vector)
{
	return math::isNAN(vector.x) || math::isNAN(vector.y) || math::isNAN(vector.z);
}




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_VECTOR_3D_H
