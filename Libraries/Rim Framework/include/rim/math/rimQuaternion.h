/*
 *  rimQuaternion.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 1/24/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_QUATERNION_H
#define INCLUDE_RIM_QUATERNION_H


#include "rimMathConfig.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A templatized math class representing a 4-dimensional quaternion.
template < typename T >
class Quaternion
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new quaternion corresponding to no rotation about the X axis.
			RIM_FORCE_INLINE Quaternion()
				:	a( T(1) ),
					b( T(0) ),
					c( T(0) ),
					d( T(0) )
			{
			}
			
			
			
			
			/// Create a new quaternion by specifying it's 4 component values.
			RIM_FORCE_INLINE Quaternion( T newA, T newB, T newC, T newD )
				:	a( newA ),
					b( newB ),
					c( newC ),
					d( newD )
			{
			}
			
			
			
			
			/// Create a new quaternion from a pointer to a 4 element array specifying its components.
			RIM_FORCE_INLINE Quaternion( const T* array )
				:	a( array[0] ),
					b( array[1] ),
					c( array[2] ),
					d( array[3] )
			{
			}
			
			
			
			
			/// Create a new quaternion from a 3x3 orthonormal rotation matrix.
			RIM_FORCE_INLINE Quaternion( const Matrix3D<T>& m )
			{
				// Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
				// article "Quaternion Calculus and Fast Animation".
				T fTrace = m.x.x + m.y.y + m.z.z;
				
				if ( fTrace > T(0) )
				{
					// |w| > 1/2, may as well choose w > 1/2
					T fRoot = math::sqrt(fTrace + 1.0f);  // 2w
					a = 0.5f*fRoot;
					fRoot = 0.5f/fRoot;  // 1/(4w)
					
					b = (m.y.z - m.z.y)*fRoot;
					c = (m.z.x - m.x.z)*fRoot;
					d = (m.x.y - m.y.x)*fRoot;
				}
				else
				{
					// |w| <= 1/2
					Index nextIndex[3] = { 1, 2, 0 };
					Index i = 0;
					
					if ( m.y.y > m.x.x )
						i = 1;
					
					if ( m.z.z > m[i][i] )
						i = 2;
					
					Index j = nextIndex[i];
					Index k = nextIndex[j];
					
					T fRoot = math::sqrt( m[i][i] - m[j][j] - m[k][k] + T(1) );
					
					T* apkQuat[3] = { &b, &c, &d };
					*apkQuat[i] = T(0.5)*fRoot;
					
					fRoot = T(0.5)/fRoot;
					
					a = (m[j][k] - m[k][j])*fRoot;
					*apkQuat[j] = (m[i][j] + m[j][i])*fRoot;
					*apkQuat[k] = (m[i][k] + m[k][i])*fRoot;
				}
			}
			
			
			
			
			/// Create a new quaternion from an existing quaternion with different template type.
			/** 
			  * This constructor takes the x, y, z, and w values of the
			  * quaternion parameter and sets the coordinates of this quaternion
			  * to be the same. This is a templatized version of the copy constructor.
			  * 
			  * @param quaternion - The quaternion to be copied.
			  */
			template < typename U >
			RIM_FORCE_INLINE Quaternion<T>( const Quaternion<U>& quaternion )
				:	a( (T)quaternion.a ),
					b( (T)quaternion.b ),
					c( (T)quaternion.c ),
					d( (T)quaternion.d )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Magnitude Methods
			
			
			
			
			/// Return the magnitude (norm) of this quaternion.
			RIM_FORCE_INLINE T getMagnitude() const
			{
				return math::sqrt( a*a + b*b + c*c + d*d );
			}
			
			
			
			
			/// Return the magnitude (norm) of this quaternion.
			RIM_FORCE_INLINE T getNorm() const
			{
				return this->getMagnitude();
			}
			
			
			
			
			/// Return the squared magnitude (norm) of this quaternion.
			RIM_FORCE_INLINE T getMagnitudeSquared() const
			{
				return a*a + b*b + c*c + d*d;
			}
			
			
			
			
			/// Return a normalized version of this quaternion.
			/**
			  * This method normalizes this quaternion by dividing
			  * each component by the quaternion's magnitude and
			  * returning the result. This method does not modify
			  * the original quaternion.
			  * 
			  * @return a normalized version of this quaternion.
			  */
			RIM_FORCE_INLINE Quaternion<T> normalize() const
			{
				T inverseMagnitude = T(1)/this->getMagnitude();
				
				return Quaternion<T>( a*inverseMagnitude,
									b*inverseMagnitude,
									c*inverseMagnitude,
									d*inverseMagnitude );
			}
			
			
			
			
			/// Return a normalized version of this quaternion, placing the quaternion's magnitude in the output parameter.
			/**
			  * This method normalizes this quaternion by dividing
			  * each component by the quaternion's magnitude and
			  * returning the result. This method does not modify
			  * the original quaternion. The magnitude of the original quaternion is
			  * returned in the output parameter.
			  * 
			  * @return a normalized version of this quaternion.
			  */
			RIM_FORCE_INLINE Quaternion<T> normalize( T& magnitude ) const
			{
				magnitude = this->getMagnitude();
				T inverseMagnitude = T(1)/magnitude;
				
				return Quaternion<T>( a*inverseMagnitude,
									b*inverseMagnitude,
									c*inverseMagnitude,
									d*inverseMagnitude );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Inversion Methods
			
			
			
			
			/// Return the inverse of this quaternion.
			/**
			  * This method makes no assumptions about the quaternion's magnitude.
			  * If inverting a unit-length quaternion, use invertNormalized() instead
			  * because it is significantly fast.
			  */
			RIM_FORCE_INLINE Quaternion<T> invert() const
			{
				T magnitudeSquared = this->getMagnitudeSquared();
				T inverseMagnitudeSquared = T(1)/magnitudeSquared;
				
				return Quaternion( a*inverseMagnitudeSquared,
								-b*inverseMagnitudeSquared,
								-c*inverseMagnitudeSquared,
								-d*inverseMagnitudeSquared );
			}
			
			
			
			
			/// Return the inverse of this normalized quaternion.
			/**
			  * This method assumes that the quaternion is of unit length. This
			  * greatly simplifies the calculations needed to invert the quaternion.
			  */
			RIM_FORCE_INLINE Quaternion<T> invertNormalized() const
			{
				return Quaternion( a, -b, -c, -d );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Matrix Conversion Methods
			
			
			
			
			/// Return the inverse of this quaternion.
			/**
			  * This method makes no assumptions about the quaternion's magnitude.
			  * If converting a unit-length quaternion, use toMatrixNormalized() instead
			  * because it is significantly faster.
			  */
			RIM_FORCE_INLINE Matrix3D<T> toMatrix() const
			{
				T aa = a*a;
				T bb = b*b;
				T cc = c*c;
				T dd = d*d;
				
				T ab = a*b;
				T ac = a*c;
				T ad = a*d;
				T bc = b*c;
				T bd = b*d;
				T cd = c*d;
				
				return Matrix3D<T>(
					aa + bb - cc - dd,
					T(2)*(bc - ad),
					T(2)*(bd + ac),
					T(2)*(bc + ad),
					aa - bb + cc - dd,
					T(2)*(cd - ab),
					T(2)*(bd - ac),
					T(2)*(cd + ab),
					aa - bb - cc + dd );
			}
			
			
			
			
			/// Return the inverse of this normalized quaternion.
			/**
			  * This method assumes that the quaternion is of unit length. This
			  * greatly simplifies the calculations needed to convert the quaternion
			  * to a matrix.
			  */
			RIM_FORCE_INLINE Matrix3D<T> toMatrixNormalized() const
			{
				T temp_b  = b + b;
				T temp_c  = c + c;
				T temp_d  = d + d;
				T temp_ab = temp_b*a;
				T temp_ac = temp_c*a;
				T temp_ad = temp_d*a;
				T temp_bb = temp_b*b;
				T temp_bc = temp_c*b;
				T temp_bd = temp_d*b;
				T temp_cc = temp_c*c;
				T temp_cd = temp_d*c;
				T temp_dd = temp_d*d;
				
				return Matrix3D<T>(
					T(1) - (temp_cc + temp_dd),
					temp_bc - temp_ad,
					temp_bd + temp_ac,
					temp_bc + temp_ad,
					T(1) - (temp_bb + temp_dd),
					temp_cd - temp_ab,
					temp_bd - temp_ac,
					temp_cd + temp_ab,
					T(1) - (temp_bb + temp_cc) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Element Accessor Methods
			
			
			
			
			/// Get a shallow array representation of this quaternion.
			/** 
			  * This method returns a pointer to the address of the X coordinate
			  * of the quaternion and does not do any copying of the elements.
			  * Therefore, this method should only be used where one needs
			  * an array representation of a quaternion without having to 
			  * allocate more memory and copy the quaternion.
			  * 
			  * @return A pointer to a shallow array copy of this quaternion.
			  */
			RIM_FORCE_INLINE const T* toArray() const
			{
				return &a;
			}
			
			
			
			
			/// Return the A coordinate of this quaternion.
			RIM_FORCE_INLINE T getA() const
			{
				return a;
			}
			
			
			
			
			/// Return the B coordinate of this quaternion.
			RIM_FORCE_INLINE T getB() const
			{
				return b;
			}
			
			
			
			
			/// Return the C coordinate of this quaternion.
			RIM_FORCE_INLINE T getC() const
			{
				return c;
			}
			
			
			
			
			/// Return the D coordinate of this quaternion.
			RIM_FORCE_INLINE T getD() const
			{
				return d;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Compare two quaternions component-wise for equality
			RIM_FORCE_INLINE Bool operator == ( const Quaternion<T>& q ) const
			{
				return a == q.a && b == q.b && c == q.c && d == q.d;
			}
			
			
			
			
			
			/// Compare two quaternions component-wise for inequality
			RIM_FORCE_INLINE Bool operator != ( const Quaternion<T>& q ) const
			{
				return a != q.a || b != q.b || c != q.c || d != q.d;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Operators
			
			
			
			
			/// Add this quaternion to another and return the result.
			/** 
			  * This method adds another quaternion to this one, component-wise,
			  * and returns this addition. It does not modify either of the original
			  * quaternions.
			  * 
			  * @param quaternion - The quaternion to add to this one.
			  * @return The addition of this quaternion and the parameter.
			  */
			RIM_FORCE_INLINE Quaternion<T> operator + ( const Quaternion<T>& quaternion ) const
			{
				return Quaternion<T>( a + quaternion.a, b + quaternion.b, c + quaternion.c, d + quaternion.d );
			}
			
			
			
			
			/// Subtract a quaternion from this quaternion component-wise and return the result.
			/** 
			  * This method subtracts another quaternion from this one, component-wise,
			  * and returns this subtraction. It does not modify either of the original
			  * quaternions.
			  * 
			  * @param quaternion - The quaternion to subtract from this one.
			  * @return The subtraction of the the parameter from this quaternion.
			  */
			RIM_FORCE_INLINE Quaternion<T> operator - ( const Quaternion<T>& quaternion ) const
			{
				return Quaternion<T>( a - quaternion.a, b - quaternion.b, c - quaternion.c, d - quaternion.d );
			}
			
			
			
			
			/// Multiply this quaternion and another quaternion.
			/** 
			  * This operation, like matrix multiplication, is not commutative.
			  */
			RIM_FORCE_INLINE Quaternion<T> operator * ( const Quaternion<T>& q ) const
			{
				return Quaternion<T>(  a*q.a - b*q.b - c*q.c - d*q.d,
									a*q.b + b*q.a + c*q.d - d*q.c,
									a*q.c - b*q.d + c*q.a + d*q.b,
									a*q.d + b*q.c - c*q.b + d*q.a );
			}
			
			
			
			
			/// Multiply every component of this quaternion by a value and return the result.
			/** 
			  * This method multiplies the value parameter with every component
			  * of the quaternion, and returns a quaternion representing this result.
			  * It does not modifiy the original quaternion.
			  * 
			  * @param value - The value to multiplly with all components of this quaternion.
			  * @return The resulting quaternion of this multiplication.
			  */
			RIM_FORCE_INLINE Quaternion<T> operator * ( const T& value ) const
			{
				return Quaternion<T>( a*value, b*value, c*value, d*value );
			}
			
			
			
			
			/// Divide every component of this quaternion by a value and return the result.
			/** 
			  * This method divides every component of the quaternion by the value parameter, 
			  * and returns a quaternion representing this result.
			  * It does not modifiy the original quaternion.
			  * 
			  * @param value - The value to divide all components of this quaternion by.
			  * @return The resulting quaternion of this division.
			  */
			RIM_FORCE_INLINE Quaternion<T> operator / ( const T& value ) const
			{
				T inverseValue = T(1) / value;
				
				return Quaternion<T>( a*inverseValue, b*inverseValue, c*inverseValue, d*inverseValue );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmatic Assignment Operators with Vectors
			
			
			
			
			/// Add a quaternion to this quaternion, modifying this original quaternion.
			/**
			  * This method adds another quaternion to this quaternion, component-wise,
			  * and sets this quaternion to have the result of this addition.
			  * 
			  * @param quaternion - The quaternion to add to this quaternion.
			  * @return A reference to this modified quaternion.
			  */
			RIM_FORCE_INLINE Quaternion<T>& operator += ( const Quaternion<T>& quaternion )
			{
				a += quaternion.a;
				b += quaternion.b;
				c += quaternion.c;
				d += quaternion.d;
				
				return *this;
			}
			
			
			
			/// Subtract a quaternion from this quaternion, modifying this original quaternion.
			/**
			  * This method subtracts another quaternion from this quaternion, component-wise,
			  * and sets this quaternion to have the result of this subtraction.
			  * 
			  * @param quaternion - The quaternion to subtract from this quaternion.
			  * @return A reference to this modified quaternion.
			  */
			RIM_FORCE_INLINE Quaternion<T>& operator -= ( const Quaternion<T>& quaternion )
			{
				a -= quaternion.a;
				b -= quaternion.b;
				c -= quaternion.c;
				d -= quaternion.d;
				
				return *this;
			}
			
			
			
			
			/// Multiply component-wise this quaternion and another quaternion and modify this quaternion.
			/** 
			  * This operator multiplies each component of this quaternion
			  * by the corresponding component of the other quaternion and
			  * modifies this quaternion to contain the result.
			  * 
			  * @param quaternion - The quaternion to multiply this quaternion by.
			  * @return A reference to this modified quaternion.
			  */
			RIM_FORCE_INLINE Quaternion<T>& operator *= ( const Quaternion<T>& q )
			{
				T tempA = a*q.a - b*q.b - c*q.c - d*q.d;
				T tempB = a*q.b + b*q.a + c*q.d - d*q.c;
				T tempC = a*q.c - b*q.d + c*q.a + d*q.b;
				T tempD = a*q.d + b*q.c - c*q.b + d*q.a;
				a = tempA;
				b = tempB;
				c = tempC;
				d = tempD;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmatic Assignment Operators with Values
			
			
			
			
			/// Multiply a value with each component of this quaternion, modifying it.
			/**
			  * This operator multiplies a value with each component of this quaternion
			  * and modifies this quaternion to store the result.
			  * 
			  * @param value - The value to multiply with every component of this quaternion.
			  * @return A reference to this modified quaternion.
			  */
			RIM_FORCE_INLINE Quaternion<T>& operator *= ( const T& value )
			{
				a *= value;
				b *= value;
				c *= value;
				d *= value;
				
				return *this;
			}
			
			
			
			
			/// Divide each component of this quaternion by a value, modifying it.
			/**
			  * This operator Divides each component of this quaternion by value
			  * and modifies this quaternion to store the result.
			  * 
			  * @param value - The value to multiply with every component of this quaternion.
			  * @return A reference to this modified quaternion.
			  */
			RIM_FORCE_INLINE Quaternion<T>& operator /= ( const T& value )
			{
				T inverseValue = T(1) / value;
				
				a *= inverseValue;
				b *= inverseValue;
				c *= inverseValue;
				d *= inverseValue;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Conversion Methods
			
			
			
			
			/// Convert this quaternion into a human-readable string representation.
			RIM_NO_INLINE data::String toString() const
			{
				data::StringBuffer buffer;
				
				buffer << "( " << a << ", " << b << ", " << c << ", " << d << " )";
				
				return buffer.toString();
			}
			
			
			
			
			/// Convert this quaternion into a human-readable string representation.
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
					/// The A coordinate of a quaternion.
					T a;
					
					/// The B coordinate of a quaternion.
					T b;
					
					/// The C coordinate of a quaternion.
					T c;
					
					/// The D coordinate of a quaternion.
					T d;
				};
				/*
				struct
				{
					/// The W coordinate of a quaternion.
					T w;
					
					/// The X coordinate of a quaternion.
					T x;
					
					/// The Y coordinate of a quaternion.
					T y;
					
					/// The Z coordinate of a quaternion.
					T z;
				};*/
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// A constant quaternion with all elements equal to zero
			static const Quaternion<T> ZERO;
			
			
			
			
			/// A constant quaternion representing no rotation.
			static const Quaternion<T> IDENTITY;
			
			
			
			
};




template <typename T>
const Quaternion<T> Quaternion<T>:: ZERO( 0, 0, 0, 0 );




template <typename T>
const Quaternion<T> Quaternion<T>:: IDENTITY( 1, 0, 0, 0 );




//##########################################################################################
//##########################################################################################
//############		
//############		Commutative Arithmatic Operators
//############		
//##########################################################################################
//##########################################################################################




/// Multiply every component of the quaternion with the value, returning a quaternion result.
/** 
  * This operator multiplies every component of the 2nd paramter, a quaternion,
  * from the 1st paramter, a value, and then returns a quaternion containing the
  * resulting quaternional components. This operator does not modify the orignal quaternion.
  * 
  * @param value - The value to multiply with all components of the quaternion.
  * @param quaternion - The quaternion to be multiplied with.
  * @return The resulting quaternion of this multiplication.
  */
template < typename T >
RIM_FORCE_INLINE Quaternion<T> operator * ( const T& value, const Quaternion<T>& quaternion ) 
{
	return Quaternion<T>( quaternion.x*value, quaternion.y*value, quaternion.z*value, quaternion.w*value );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Other Vector Functions
//############		
//##########################################################################################
//##########################################################################################




/// Compute and return the dot product of two quaternions.
/** 
  * This method adds all components of the component-wise multiplication
  * of the two quaternions together and returns the scalar result. It does
  * not modify either of the original quaternions. If the dot product is
  * zero, then the two quaternions are perpendicular.
  * 
  * @param quaternion1 - The first quaternion of the dot product.
  * @param quaternion2 - The second quaternion of the dot product.
  * @return The dot product of the two quaternion parameters.
  */
template < typename T >
RIM_FORCE_INLINE T dot( const Quaternion<T>& q1, const Quaternion<T>& q2 )
{
	return q1.a*q2.a + q1.b*q2.b + q1.c*q2.c + q1.d*q2.d;
}




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_QUATERNION_H
