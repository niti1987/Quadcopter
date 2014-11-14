/*
 *  rimVector4D.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 1/22/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_VECTOR_4D_H
#define INCLUDE_RIM_VECTOR_4D_H


#include "rimMathConfig.h"


#include "../data/rimBasicString.h"
#include "../data/rimBasicStringBuffer.h"
#include "rimVector2D.h"
#include "rimVector3D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A templatized math class representing a 4-dimensional vector.
template < typename T >
class Vector4D
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new 4D vector with all elements equal to zero.
			RIM_FORCE_INLINE Vector4D()
				:	x( T(0) ),
					y( T(0) ),
					z( T(0) ),
					w( T(0) )
			{
			}
			
			
			
			
			/// Create a new 4D vector with all elements equal to a single value.
			/** 
			  * This constructor creates a uniform 4D vector with all elements
			  * equal to each other and equal to the single constructor parameter
			  * value.
			  * 
			  * @param value - The value to set all elements of the vector to.
			  */
			RIM_FORCE_INLINE explicit Vector4D( T value )
				:	x( value ),
					y( value ),
					z( value ),
					w( value )
			{
			}
			
			
			
			
			/// Create a new 4D vector from a pointer to a 4 element array.
			/** 
			  * This constructor takes a pointer to an array of 4 values 
			  * and sets it's x, y, z, and w coordinates to be the 0th, 1th,
			  * 2th, and 3th indexed values in the array. No error checking is
			  * performed, so make sure to pass in a correct array of values
			  * or expect the worst.
			  * 
			  * @param array - An indexed array of 4 values for the vector's coordinates.
			  */
			RIM_FORCE_INLINE explicit Vector4D( const T* array )
				:	x( array[0] ),
					y( array[1] ),
					z( array[2] ),
					w( array[3] )
			{
			}
			
			
			
			
			/// Create a new 4D vector by specifying it's x, y, z, and w values.
			/** 
			  * This constructor sets each of the vector's x, y, z, and w coordinate
			  * values to be the 1st, 2nd, 3rd, and 4th parameters of the constructor,
			  * respectively.
			  * 
			  * @param newX - The X coordinate of the new vector.
			  * @param newY - The Y coordinate of the new vector.
			  * @param newZ - The Z coordinate of the new vector.
			  * @param newW - The W coordinate of the new vector.
			  */
			RIM_FORCE_INLINE Vector4D( T newX, T newY, T newZ, T newW )
				:	x( newX ),
					y( newY ),
					z( newZ ),
					w( newW )
			{
			}
			
			
			
			
			/// Create a new 4D vector from an existing vector (copy it), templatized version.
			/** 
			  * This constructor takes the x, y, z, and w values of the
			  * vector parameter and sets the coordinates of this vector
			  * to be the same. This is a templatized version of the above copy constructor.
			  * 
			  * @param vector - The vector to be copied.
			  */
			template < typename U >
			RIM_FORCE_INLINE Vector4D( const Vector4D<U>& vector )
				:	x( (T)vector.x ),
					y( (T)vector.y ),
					z( (T)vector.z ),
					w( (T)vector.w )
			{
			}
			
			
			
			
			/// Create a new 4D vector from a 2D vector and 2 values for the Z and W coordinates.
			/** 
			  * This constructor takes the x and y coordinates of the first parameter,
			  * a 2D vector, and sets the x and y coordinates of this vector to be
			  * the same. It then takes the 2nd and 3rd paramter, scalars, and sets the z and w
			  * coordinates of this vector to be those values.
			  * 
			  * @param vector - A 2D vector for the X and Y coordinates of this vector.
			  * @param newZ - The value for the Z coordinate of this vector.
			  * @param newW - The value for the W coordinate of this vector.
			  */
			RIM_FORCE_INLINE Vector4D( const Vector2D<T>& vector, T newZ, T newW )
				:	x( vector.x ),
					y( vector.y ),
					z( newZ ),
					w( newW )
			{
			}
			
			
			
			
			/// Create a new 4D vector from a scalar, a 2D vector and another scalar.
			/** 
			  * This constructor takes the first parameter, a scalar, and sets the
			  * X coordinate of this vector to have that value. It then takes the X and Y
			  * coordinates of the second parameter and sets the Y and Z values of this
			  * vector to have those values, respectively. Finally, the 3rd parameter is
			  * used as the W coordinate of this vector.
			  * 
			  * @param newX - The value for the X coordinate of this vector.
			  * @param vector - A 2D vector for the Y and Z coordinates of this vector.
			  * @param newW - The value for the W coordinate of this vector.
			  */
			RIM_FORCE_INLINE Vector4D( T newX, const Vector2D<T>& vector, T newW )
				:	x( newX ),
					y( vector.x ),
					z( vector.y ),
					w( newW )
			{
			}
			
			
			
			
			/// Create a new 4D vector from two scalars for the X, Y coordinates and a 2D vector.
			/** 
			  * This constructor sets the X and Y coordinates of this vector to have
			  * the same value as the first two parameters of this constructor, respectively.
			  * It then uses the X and Y values of the 3rd parameter, a vector, as the
			  * Z and W values of this vector.
			  * 
			  * @param newX - The value for the X coordinate of this vector.
			  * @param newY - The value for the Y coordinate of this vector.
			  * @param vector - A 2D vector for the Z and W coordinates of this vector.
			  */
			RIM_FORCE_INLINE Vector4D( T newX, T newY, const Vector2D<T>& vector )
				:	x( newX ),
					y( newY ),
					z( vector.x ),
					w( vector.y )
			{
			}
			
			
			
			
			/// Create a new 4D vector from a 3D vector and a value for the W coordinate.
			/** 
			  * This constructor takes the X, Y, and Z coordinates of the first parameter,
			  * a 2D vector, and sets the X, Y, and Z coordinates of this vector to be
			  * the same. It then takes the 2nd paramter, a value, and sets the W
			  * coordinate of this vector to be that value.
			  * 
			  * @param vector - A 3D vector for the X, Y, and Z coordinates of this vector.
			  * @param newZ - The value for the W coordinate of this vector.
			  */
			RIM_FORCE_INLINE Vector4D( const Vector3D<T>& vector, T newW )
				:	x( vector.x ),
					y( vector.y ),
					z( vector.z ),
					w( newW )
			{
			}
			
			
			
			
			/// Create a new 4D vector from a value for the X coordinate and a 3D vector.
			/** 
			  * This constructor sets the X coordinate of this vector to be the
			  * same as the value of the first parameter, and then sets the 
			  * Y, Z, and W coordinates of this vector to be the X, Y, and Z coordinates of 
			  * the 2nd parameter, a 3D vector.
			  * 
			  * @param newX - The value for the X coordinate of this vector.
			  * @param vector - A 3D vector for the Y, Z, and W coordinates of this vector.
			  */
			RIM_FORCE_INLINE Vector4D( T newX, const Vector3D<T>& vector )
				:	x( newX ),
					y( vector.x ),
					z( vector.y ),
					w( vector.w )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Magnitude Methods
			
			
			
			
			/// Get the magnitude of this vector (the length).
			/** 
			  * This Method finds the magnitude of this vector
			  * using the formula: magnitude = sqrt( x*x + y*y + z*z + w*w ).
			  * It's value is always positive.
			  * 
			  * @return the magnitude of the vector.
			  */
			RIM_FORCE_INLINE T getMagnitude() const
			{
				return math::sqrt( x*x + y*y + z*z + w*w );
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
				return x*x + y*y + z*z + w*w;
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
			RIM_FORCE_INLINE Vector4D<T> normalize() const
			{
				T inverseMagnitude = T(1)/math::sqrt( x*x + y*y + z*z + w*w );
				
				return Vector4D<T>( x*inverseMagnitude,
									y*inverseMagnitude,
									z*inverseMagnitude,
									w*inverseMagnitude );
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
			RIM_FORCE_INLINE Vector4D<T> normalize( T& magnitude ) const
			{
				magnitude = math::sqrt( x*x + y*y + z*z + w*w );
				T inverseMagnitude = T(1)/magnitude;
				
				return Vector4D<T>( x*inverseMagnitude,
									y*inverseMagnitude,
									z*inverseMagnitude,
									w*inverseMagnitude );
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
			RIM_FORCE_INLINE Vector4D<T> projectOn( const Vector4D<T>& vector ) const
			{
				Vector4D<T> norm = vector.normalize();
				
				return ( x*norm.x + y*norm.y + z*norm.z + w*norm.w )*norm;
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
			RIM_FORCE_INLINE Vector4D<T> projectOnNormalized( const Vector4D<T>& vector ) const
			{
				return ( x*vector.x + y*vector.y + z*vector.z + w*vector.w )*vector;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distance Methods
			
			
			
			
			/// Get the distance from this vector to another in 4D space.
			/** 
			  * This method essentially computes the magnitude of
			  * the subtraction of this vector minus the parameter vector.
			  * This treats each vector as a point in 4D space.
			  * 
			  * @param vector - the vector to query the distance to.
			  * @return the distance to the parameter vector.
			  */
			RIM_FORCE_INLINE T getDistanceTo( const Vector4D<T>& vector ) const
			{
				T minusX = vector.x - x;
				T minusY = vector.y - y;
				T minusZ = vector.z - z;
				T minusW = vector.w - w;
				
				return math::sqrt( minusX*minusX + minusY*minusY + minusZ*minusZ + minusW*minusW );
			}
			
			
			
			
			/// Get the square of the distance from this vector to another in 4D space.
			/** 
			  * This method essentially computes the magnitude squared of
			  * the subtraction of this vector minus the parameter vector.
			  * This treats each vector as a point in 4D space. This function
			  * can be used for faster distance comparisions because it avoids
			  * the square root operation of the getDistanceTo() method.
			  * 
			  * @param vector - the vector to query the distance to.
			  * @return the distance to the parameter vector.
			  */
			RIM_FORCE_INLINE T getDistanceToSquared( const Vector4D<T>& vector ) const
			{
				T minusX = vector.x - x;
				T minusY = vector.y - y;
				T minusZ = vector.z - z;
				T minusW = vector.w - w;
				
				return minusX*minusX + minusY*minusY + minusZ*minusZ + minusW*minusW;
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
			
			
			
			
			/// Return the W coordinate of this vector.
			RIM_FORCE_INLINE T getW() const
			{
				return w;
			}
			
			
			
			
			/// Return a 2D vector containing the X and Y elements of this 4D vector.
			RIM_FORCE_INLINE Vector2D<T> getXY() const
			{
				return Vector2D<T>( x, y );
			}
			
			
			
			
			/// Return a 2D vector containing the X and Z elements of this 4D vector.
			RIM_FORCE_INLINE Vector2D<T> getXZ() const
			{
				return Vector2D<T>( x, z );
			}
			
			
			
			
			/// Return a 2D vector containing the X and W elements of this 4D vector.
			RIM_FORCE_INLINE Vector2D<T> getXW() const
			{
				return Vector2D<T>( x, w );
			}
			
			
			
			
			/// Return a 2D vector containing the Y and Z elements of this 4D vector.
			RIM_FORCE_INLINE Vector2D<T> getYZ() const
			{
				return Vector2D<T>( y, z );
			}
			
			
			
			
			/// Return a 2D vector containing the Y and W elements of this 4D vector.
			RIM_FORCE_INLINE Vector2D<T> getYW() const
			{
				return Vector2D<T>( y, w );
			}
			
			
			
			
			/// Return a 3D vector containing the X, Y and Z elements of this 4D vector.
			RIM_FORCE_INLINE Vector3D<T> getXYZ() const
			{
				return Vector3D<T>( x, y, z );
			}
			
			
			
			
			/// Return a 3D vector containing the X, Y and W elements of this 4D vector.
			RIM_FORCE_INLINE Vector3D<T> getXYW() const
			{
				return Vector3D<T>( x, y, w );
			}
			
			
			
			
			/// Return a 3D vector containing the X, Z and W elements of this 4D vector.
			RIM_FORCE_INLINE Vector3D<T> getXZW() const
			{
				return Vector3D<T>( x, z, w );
			}
			
			
			
			
			/// Return a 3D vector containing the Y, Z and W elements of this 4D vector.
			RIM_FORCE_INLINE Vector3D<T> getYZW() const
			{
				return Vector3D<T>( y, z, w );
			}
			
			
			
			
			/// Return the minimum component of this vector.
			RIM_FORCE_INLINE T getMin() const
			{
				return math::min( math::min( x, y ), math::min( z, w ) );
			}
			
			
			
			
			/// Return the maximum component of this vector.
			RIM_FORCE_INLINE T getMax() const
			{
				return math::max( math::max( x, y ), math::max( z, w ) );
			}
			
			
			
			
			/// Get an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0 through 3 and returns the X, Y, Z, or W
			  * coordinate of this vector, respectively. There is
			  * no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y, 2 = Z, 3 = W
			  * @return the value of the vector associated with the given index.
			  */
			RIM_FORCE_INLINE T get( Index index ) const
			{
				RIM_DEBUG_ASSERT( index < 4 );
				
				return (&x)[index];
			}
			
			
			
			
			/// Get an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0 through 3 and returns the X, Y, Z, or W
			  * coordinate of this vector, respectively. There is
			  * no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y, 2 = Z, 3 = W
			  * @return the value of the vector associated with the given index.
			  */
			RIM_FORCE_INLINE T& operator () ( Index index )
			{
				RIM_DEBUG_ASSERT( index < 4 );
				
				return (&x)[index];
			}
			
			
			
			
			/// Get an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0 through 3 and returns the X, Y, Z, or W
			  * coordinate of this vector, respectively. There is
			  * no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y, 2 = Z, 3 = W
			  * @return the value of the vector associated with the given index.
			  */
			RIM_FORCE_INLINE const T& operator () ( Index index ) const
			{
				RIM_DEBUG_ASSERT( index < 4 );
				
				return (&x)[index];
			}
			
			
			
			
			/// Get an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0 through 3 and returns the X, Y, Z, or W
			  * coordinate of this vector, respectively. There is
			  * no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y, 2 = Z, 3 = W
			  * @return the value of the vector associated with the given index.
			  */
			RIM_FORCE_INLINE T& operator [] ( Index index )
			{
				RIM_DEBUG_ASSERT( index < 4 );
				
				return (&x)[index];
			}
			
			
			
			
			/// Get an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0 through 3 and returns the X, Y, Z, or W
			  * coordinate of this vector, respectively. There is
			  * no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y, 2 = Z, 3 = W
			  * @return the value of the vector associated with the given index.
			  */
			RIM_FORCE_INLINE const T& operator [] ( Index index ) const
			{
				RIM_DEBUG_ASSERT( index < 4 );
				
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
			
			
			
			
				/// Set the W coordinate of the vector to the specified value.
			RIM_FORCE_INLINE void setW( T newW )
			{
				w = newW;
			}
			
			
			
			
			/// Set the X, Y, Z, and W coordinates of the vector to the specified values.
			/** 
			  * This method takes 4 parameter representing the 4 coordinates of this
			  * vector and sets this vector's coordinates to have those values.
			  * 
			  * @param newX - The new X coordinate of the vector.
			  * @param newY - The new Y coordinate of the vector.
			  * @param newZ - The new Z coordinate of the vector.
			  * @param newW - The new W coordinate of the vector.
			  */
			RIM_FORCE_INLINE void setAll( T newX, T newY, T newZ, T newW )
			{
				x = newX;
				y = newY;
				z = newZ;
				w = newW;
			}
			
			
			
			
			/// Set an indexed coordinate of this vector.
			/**
			  * This method takes an index with the possible
			  * values 0, 1, 2, or 3, and sets the X, Y, Z, or W
			  * coordinate of this vector to be the new value, respectively.
			  * There is no error checking performed (for speed), so make
			  * sure that the index is in the valid bounds mentioned
			  * above, or else bad things could happen.
			  * 
			  * @param index - An index into the vector with 0 = X, 1 = Y, 2 = Z, 3 = W.
			  * @param newValue - The new value of the coordinate with the given index.
			  */
			RIM_FORCE_INLINE void set( Index index, T newValue )
			{
				RIM_DEBUG_ASSERT( index < 4 );
				
				(&x)[index] = newValue;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Compare two vectors component-wise for equality
			RIM_FORCE_INLINE bool operator == ( const Vector4D<T>& v ) const
			{
				return x == v.x && y == v.y && z == v.z && w == v.w;
			}
			
			
			
			
			
			/// Compare two vectors component-wise for inequality
			RIM_FORCE_INLINE bool operator != ( const Vector4D<T>& v ) const
			{
				return x != v.x || y != v.y || z != v.z || w != v.w;
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
			RIM_FORCE_INLINE Vector4D<T> operator - () const
			{
				return Vector4D<T>( -x, -y, -z, -w );
			}
			
			
			
			
			/// Postive a vector, returning a copy of it. Operator does nothing.
			/**
			  * This operator doesn't do anything but return the original
			  * value of the vector that it affects.
			  * 
			  * @return the same vector as the orignal vector.
			  */
			RIM_FORCE_INLINE Vector4D<T> operator + () const
			{
				return Vector4D<T>( x, y, z, w );
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
			RIM_FORCE_INLINE Vector4D<T> operator + ( const Vector4D<T>& vector ) const
			{
				return Vector4D<T>( x + vector.x, y + vector.y, z + vector.z, w + vector.w );
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
			RIM_FORCE_INLINE Vector4D<T> operator + ( const T& value ) const
			{
				return Vector4D<T>( x + value, y + value, z + value, w + value );
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
			RIM_FORCE_INLINE Vector4D<T> operator - ( const Vector4D<T>& vector ) const
			{
				return Vector4D<T>( x - vector.x, y - vector.y, z - vector.z, w - vector.w );
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
			RIM_FORCE_INLINE Vector4D<T> operator - ( const T& value ) const
			{
				return Vector4D<T>( x - value, y - value, z - value, w - value );
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
			RIM_FORCE_INLINE Vector4D<T> operator * ( const Vector4D<T>& vector ) const
			{
				return Vector4D<T>( x*vector.x, y*vector.y, z*vector.z, w*vector.w );
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
			RIM_FORCE_INLINE Vector4D<T> operator * ( const T& value ) const
			{
				return Vector4D<T>( x*value, y*value, z*value, w*value );
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
			RIM_FORCE_INLINE Vector4D<T> operator / ( const Vector4D<T>& vector ) const
			{
				return Vector4D<T>( x/vector.x, y/vector.y, z/vector.z, w/vector.w );
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
			RIM_FORCE_INLINE Vector4D<T> operator / ( const T& value ) const
			{
				T inverseValue = T(1) / value;
				
				return Vector4D<T>( x*inverseValue, y*inverseValue, z*inverseValue, w*inverseValue );
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
			RIM_FORCE_INLINE Vector4D<T>& operator += ( const Vector4D<T>& vector )
			{
				x += vector.x;
				y += vector.y;
				z += vector.z;
				w += vector.w;
				
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
			RIM_FORCE_INLINE Vector4D<T>& operator -= ( const Vector4D<T>& vector )
			{
				x -= vector.x;
				y -= vector.y;
				z -= vector.z;
				w -= vector.w;
				
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
			RIM_FORCE_INLINE Vector4D<T>& operator *= ( const Vector4D<T>& vector )
			{
				x *= vector.x;
				y *= vector.y;
				z *= vector.z;
				w *= vector.w;
				
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
			RIM_FORCE_INLINE Vector4D<T>& operator /= ( const Vector4D<T>& vector )
			{
				x /= vector.x;
				y /= vector.y;
				z /= vector.z;
				w /= vector.w;
				
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
			RIM_FORCE_INLINE Vector4D<T>& operator += ( const T& value )
			{
				x += value;
				y += value;
				z += value;
				w += value;
				
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
			RIM_FORCE_INLINE Vector4D<T>& operator -= ( const T& value )
			{
				x -= value;
				y -= value;
				z -= value;
				w -= value;
				
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
			RIM_FORCE_INLINE Vector4D<T>& operator *= ( const T& value )
			{
				x *= value;
				y *= value;
				z *= value;
				w *= value;
				
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
			RIM_FORCE_INLINE Vector4D<T>& operator /= ( const T& value )
			{
				T inverseValue = T(1) / value;
				
				x *= inverseValue;
				y *= inverseValue;
				z *= inverseValue;
				w *= inverseValue;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Conversion Methods
			
			
			
			
			/// Convert this 4D vector into a human-readable string representation.
			RIM_NO_INLINE data::String toString() const
			{
				data::StringBuffer buffer;
				
				buffer << "< " << x << ", " << y << ", " << z << ", " << w << " >";
				
				return buffer.toString();
			}
			
			
			
			
			/// Convert this 4D vector into a human-readable string representation.
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
					/// The red component of a 4-component color.
					T r;
					
					/// The green component of a 4-component color.
					T g;
					
					/// The blue component of a 4-component color.
					T b;
					
					/// The alpha component of a 4-component color.
					T a;
				};
				
				struct
				{
					/// The X coordinate of a 4D vector.
					T x;
					
					/// The Y coordinate of a 4D vector.
					T y;
					
					/// The Z coordinate of a 4D vector.
					T z;
					
					/// The W coordinate of a 4D vector.
					T w;
				};
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// A constant vector with all elements equal to zero
			static const Vector4D<T> ZERO;
			
			
			
			
};




template <typename T>
const Vector4D<T> Vector4D<T>:: ZERO;




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
RIM_FORCE_INLINE Vector4D<T> operator + ( const T& value, const Vector4D<T>& vector )
{
    return Vector4D<T>( vector.x + value, vector.y + value, vector.z + value, vector.w + value );
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
RIM_FORCE_INLINE Vector4D<T> operator - ( const T& value, const Vector4D<T>& vector )
{
	return Vector4D<T>( value - vector.x, value - vector.y, value - vector.z, value - vector.w );
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
RIM_FORCE_INLINE Vector4D<T> operator * ( const T& value, const Vector4D<T>& vector ) 
{
	return Vector4D<T>( vector.x*value, vector.y*value, vector.z*value, vector.w*value );
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
RIM_FORCE_INLINE Vector4D<T> operator / ( const T& value, const Vector4D<T>& vector ) 
{
	return Vector4D<T>( value/vector.x, value/vector.y, value/vector.z, value/vector.w );
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
RIM_FORCE_INLINE T dot( const Vector4D<T>& vector1, const Vector4D<T>& vector2 )
{
	return vector1.x*vector2.x + vector1.y*vector2.y + vector1.z*vector2.z + vector1.w*vector2.w;
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
RIM_FORCE_INLINE Vector4D<T> midpoint( const Vector4D<T>& vector1, const Vector4D<T>& vector2 )
{
	return Vector4D<T>(	(vector1.x + vector2.x)*T(0.5), 
							(vector1.y + vector2.y)*T(0.5),
							(vector1.z + vector2.z)*T(0.5),
							(vector1.w + vector2.w)*T(0.5) );
}




/// Return the absolute value of the specified vector, such that the every component is positive.
template < typename T >
RIM_FORCE_INLINE Vector4D<T> abs( const Vector4D<T>& vector )
{
	return Vector4D<T>( math::abs(vector.x), math::abs(vector.y), math::abs(vector.z), math::abs(vector.w) );
}




/// Compute the component-wise minimum of two vectors.
template < typename T >
RIM_FORCE_INLINE Vector4D<T> min( const Vector4D<T>& vector1, const Vector4D<T>& vector2 )
{
	return Vector4D<T>(	math::min( vector1.x, vector2.x ),
						math::min( vector1.y, vector2.y ),
						math::min( vector1.z, vector2.z ),
						math::min( vector1.w, vector2.w ) );
}




/// Compute the component-wise maximum of two vectors.
template < typename T >
RIM_FORCE_INLINE Vector4D<T> max( const Vector4D<T>& vector1, const Vector4D<T>& vector2 )
{
	return Vector4D<T>(	math::max( vector1.x, vector2.x ),
						math::max( vector1.y, vector2.y ),
						math::max( vector1.z, vector2.z ),
						math::max( vector1.w, vector2.w ) );
}




/// Return the floor of the specified vector, rounding each component down to the nearest integer.
template < typename T >
RIM_FORCE_INLINE Vector4D<T> floor( const Vector4D<T>& vector )
{
	return Vector4D<T>( math::floor(vector.x), math::floor(vector.y), math::floor(vector.z), math::floor(vector.w) );
}




/// Return the floor of the specified vector, rounding each component up to the nearest integer.
template < typename T >
RIM_FORCE_INLINE Vector4D<T> ceiling( const Vector4D<T>& vector )
{
	return Vector4D<T>( math::ceiling(vector.x), math::ceiling(vector.y), math::ceiling(vector.z), math::ceiling(vector.w) );
}




/// Return the component-wise modulus of the specified vector.
template < typename T >
RIM_FORCE_INLINE Vector4D<T> mod( const Vector4D<T>& vector, const T& modulus )
{
	return Vector4D<T>( math::mod(vector.x, modulus), math::mod(vector.y, modulus),
						math::mod(vector.z, modulus), math::mod(vector.w, modulus) );
}




/// Return the component-wise modulus of the specified vector.
template < typename T >
RIM_FORCE_INLINE Vector4D<T> mod( const Vector4D<T>& vector, const Vector4D<T>& modulus )
{
	return Vector4D<T>( math::mod(vector.x, modulus.x), math::mod(vector.y, modulus.y),
						math::mod(vector.z, modulus.z), math::mod(vector.w, modulus.w) );
}




/// Return whether or not any component of this vector is Not-A-Number.
template < typename T >
RIM_FORCE_INLINE Bool isNAN( const Vector4D<T>& vector)
{
	return math::isNAN(vector.x) || math::isNAN(vector.y) || math::isNAN(vector.z) || math::isNAN(vector.w);
}




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_VECTOR_4D_H
