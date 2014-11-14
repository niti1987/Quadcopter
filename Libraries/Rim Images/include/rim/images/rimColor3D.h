/*
 *  rimImagesColor3D.h
 *  Rim Images
 *
 *  Created by Carl Schissler on 9/17/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_IMAGES_COLOR_3D_H
#define INCLUDE_RIM_IMAGES_COLOR_3D_H


#include "rimImagesConfig.h"


//##########################################################################################
//****************************  Start Rim Images Namespace  ********************************
RIM_IMAGES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A template class representing a 3-component color.
template < typename T >
class Color3D
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new 3D color with all elements equal to zero.
			RIM_INLINE Color3D<T>()
				:	r( T(0) ),
					g( T(0) ),
					b( T(0) )
			{
			}
			
			
			
			
			/// Create a new 3D color with all elements equal to a single value.
			/** 
			  * This constructor creates a uniform 3D color with all elements
			  * equal to each other and equal to the single constructor parameter
			  * value.
			  * 
			  * @param value - The value to set all elements of the color to.
			  */
			explicit RIM_INLINE Color3D<T>( T value )
				:	r( value ),
					g( value ),
					b( value )
			{
			}
			
			
			
			
			/// Create a new 3D color by specifying it's x, y, and z values.
			/** 
			  * This constructor sets each of the color's x, y, and z component
			  * values to be the 1st, 2nd, and 3rd parameters of the constructor,
			  * respectively.
			  * 
			  * @param newX - The X component of the new color.
			  * @param newY - The Y component of the new color.
			  * @param newZ - The Z component of the new color.
			  */
			RIM_INLINE Color3D<T>( T newR, T newG, T newB )
				:	r( newR ),
					g( newG ),
					b( newB )
			{
			}
			
			
			
			
			/// Create a new 3D color from an existing color (copy it).
			/** 
			  * This constructor takes the x, y, and z values of the
			  * color parameter and sets the components of this color
			  * to be the same.
			  * 
			  * @param color - The color to be copied.
			  */
			RIM_INLINE Color3D<T>( const Color3D<T>& color )
				:	r( color.r ),
					g( color.g ),
					b( color.b )
			{
			}
			
			
			
			
			/// Create a new 3D color from an existing 3D vector (copy it).
			/** 
			  * This constructor takes the x, y, and z values of the
			  * vector parameter and sets the components of this color
			  * to be the same.
			  * 
			  * @param vector - The vector to be copied.
			  */
			RIM_INLINE Color3D<T>( const math::Vector3D<T>& vector )
				:	r( vector.r ),
					g( vector.g ),
					b( vector.b )
			{
			}
			
			
			
			
			/// Create a new 3D color from an existing color (copy it), templatized version.
			/** 
			  * This constructor takes the x, y, and z values of the
			  * color parameter and sets the components of this color
			  * to be the same. This is a templatized version of the above copy constructor.
			  * 
			  * @param color - The color to be copied.
			  */
			template < typename U >
			RIM_INLINE Color3D<T>( const Color3D<U>& color )
				:	r( color.r ),
					g( color.g ),
					b( color.b )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Element Accessor Methods
			
			
			
			
			/// Get a shallow array representation of this color.
			/** 
			  * This method returns a pointer to the address of the red component
			  * of the color and does not do any copying of the elements.
			  * Therefore, this method should only be used where one needs
			  * an array representation of a color without having to 
			  * allocate more memory and copy the color.
			  * 
			  * @return A pointer to a shallow array copy of this color.
			  */
			RIM_INLINE const T* toArray() const
			{
				return &r;
			}
			
			
			
			
			/// Get the X component of this color.
			RIM_INLINE T getRed() const
			{
				return r;
			}
			
			
			
			
			/// Get the Y component of this color.
			RIM_INLINE T getGreen() const
			{
				return g;
			}
			
			
			
			
			/// Get the Z component of this color.
			RIM_INLINE T getBlue() const
			{
				return b;
			}
			
			
			
			
			/// Set the red component of the color to the specified value.
			RIM_INLINE void setRed( T newRed )
			{
				r = newRed;
			}
			
			
			
			
			/// Set the green component of the color to the specified value.
			RIM_INLINE void setGreen( T newGreen )
			{
				g = newGreen;
			}
			
			
			
			
			/// Set the blue component of the color to the specified value.
			RIM_INLINE void setBlue( T newBlue )
			{
				b = newBlue;
			}
			
			
			
			
			/// Set the red, green, and blue components of the color to the specified values.
			/** 
			  * This method takes 3 parameter representing the 3 components of this
			  * color and sets this color's components to have those values.
			  * 
			  * @param newR - The new red component of the color.
			  * @param newG - The new green component of the color.
			  * @param newB - The new blue component of the color.
			  */
			RIM_INLINE void set( T newR, T newG, T newB )
			{
				r = newR;
				g = newG;
				b = newB;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Casting Operators
			
			
			
			
			/// This operator casts this color to another with different template paramter.
			/** 
			  * This method provides an operator for the casting of this
			  * color to another color with a potentially different template
			  * paramter.
			  * 
			  * @return the cast version of this color.
			  */
			template < typename U >
			RIM_INLINE operator Color3D<U>()
			{
				return Color3D<U>( (U)r, (U)g, (U)b );
			}
			
			
			
			
			/// This operator casts this color to another with different template paramter.
			/** 
			  * This method provides an operator for the casting of this
			  * color to another color with a potentially different template
			  * paramter. This is the const version of this operator.
			  * 
			  * @return the cast version of this color.
			  */
			template < typename U >
			RIM_INLINE operator Color3D<U>() const
			{
				return Color3D<U>( (U)r, (U)g, (U)b );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Compare two colors component-wise for equality
			RIM_INLINE bool operator == ( const Color3D<T>& v ) const
			{
				return r == v.r && g == v.g && b == v.b;
			}
			
			
			
			
			
			/// Compare two colors component-wise for inequality
			RIM_INLINE bool operator != ( const Color3D<T>& v ) const
			{
				return r != v.r || g != v.g || b != v.b;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmatic Operators
			
			
			
			
			/// Add this color to another and return the result.
			/** 
			  * This method adds another color to this one, component-wise,
			  * and returns this addition. It does not modify either of the original
			  * colors.
			  * 
			  * @param color - The color to add to this one.
			  * @return The addition of this color and the parameter.
			  */
			RIM_INLINE Color3D<T> operator + ( const Color3D<T>& color ) const
			{
				return Color3D<T>( r + color.r, g + color.g, b + color.b );
			}
			
			
			
			
			/// Add a value to every component of this color.
			/** 
			  * This method adds the value parameter to every component
			  * of the color, and returns a color representing this result.
			  * It does not modifiy the original color.
			  * 
			  * @param value - The value to add to all components of this color.
			  * @return The resulting color of this addition.
			  */
			RIM_INLINE Color3D<T> operator + ( const T& value ) const
			{
				return Color3D<T>( r + value, g + value, b + value );
			}
			
			
			
			
			/// Subtract a color from this color component-wise and return the result.
			/** 
			  * This method subtracts another color from this one, component-wise,
			  * and returns this subtraction. It does not modify either of the original
			  * colors.
			  * 
			  * @param color - The color to subtract from this one.
			  * @return The subtraction of the the parameter from this color.
			  */
			RIM_INLINE Color3D<T> operator - ( const Color3D<T>& color ) const
			{
				return Color3D<T>( r - color.r, g - color.g, b - color.b );
			}
			
			
			
			
			/// Subtract a value from every component of this color.
			/** 
			  * This method subtracts the value parameter from every component
			  * of the color, and returns a color representing this result.
			  * It does not modifiy the original color.
			  * 
			  * @param value - The value to subtract from all components of this color.
			  * @return The resulting color of this subtraction.
			  */
			RIM_INLINE Color3D<T> operator - ( const T& value ) const
			{
				return Color3D<T>( r - value, g - value, b - value );
			}
			
			
			
			
			/// Multiply component-wise this color and another color.
			/** 
			  * This operator multiplies each component of this color
			  * by the corresponding component of the other color and
			  * returns a color representing this result. It does not modify
			  * either original color.
			  * 
			  * @param color - The color to multiply this color by.
			  * @return The result of the multiplication.
			  */
			RIM_INLINE Color3D<T> operator * ( const Color3D<T>& color ) const
			{
				return Color3D<T>( r*color.r, g*color.g, b*color.b );
			}
			
			
			
			
			/// Multiply every component of this color by a value and return the result.
			/** 
			  * This method multiplies the value parameter with every component
			  * of the color, and returns a color representing this result.
			  * It does not modifiy the original color.
			  * 
			  * @param value - The value to multiplly with all components of this color.
			  * @return The resulting color of this multiplication.
			  */
			RIM_INLINE Color3D<T> operator * ( const T& value ) const
			{
				return Color3D<T>( r*value, g*value, b*value );
			}
			
			
			
			
			/// Divide every component of this color by a value and return the result.
			/** 
			  * This method Divides every component of the color by the value parameter, 
			  * and returns a color representing this result.
			  * It does not modifiy the original color.
			  * 
			  * @param value - The value to divide all components of this color by.
			  * @return The resulting color of this division.
			  */
			RIM_INLINE Color3D<T> operator / ( const T& value ) const
			{
				T inverseValue = T(1) / value;
				
				return Color3D<T>( r*inverseValue, g*inverseValue, b*inverseValue );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmatic Assignment Operators with Colors
			
			
			
			
			/// Add a color to this color, modifying this original color.
			/**
			  * This method adds another color to this color, component-wise,
			  * and sets this color to have the result of this addition.
			  * 
			  * @param color - The color to add to this color.
			  * @return A reference to this modified color.
			  */
			RIM_INLINE Color3D<T>& operator += ( const Color3D<T>& color )
			{
				r += color.r;
				g += color.g;
				b += color.b;
				
				return *this;
			}
			
			
			
			/// Subtract a color from this color, modifying this original color.
			/**
			  * This method subtracts another color from this color, component-wise,
			  * and sets this color to have the result of this subtraction.
			  * 
			  * @param color - The color to subtract from this color.
			  * @return A reference to this modified color.
			  */
			RIM_INLINE Color3D<T>& operator -= ( const Color3D<T>& color )
			{
				r -= color.r;
				g -= color.g;
				b -= color.b;
				
				return *this;
			}
			
			
			
			
			/// Multiply component-wise this color and another color and modify this color.
			/** 
			  * This operator multiplies each component of this color
			  * by the corresponding component of the other color and
			  * modifies this color to contain the result.
			  * 
			  * @param color - The color to multiply this color by.
			  * @return A reference to this modified color.
			  */
			RIM_INLINE Color3D<T>& operator *= ( const Color3D<T>& color )
			{
				r *= color.r;
				g *= color.g;
				b *= color.b;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmatic Assignment Operators with Values
			
			
			
			
			/// Add a value to each component of this color, modifying it.
			/**
			  * This operator adds a value to each component of this color
			  * and modifies this color to store the result.
			  * 
			  * @param value - The value to add to every component of this color.
			  * @return A reference to this modified color.
			  */
			RIM_INLINE Color3D<T>& operator += ( const T& value )
			{
				r += value;
				g += value;
				b += value;
				
				return *this;
			}
			
			
			
			
			/// Subtract a value from each component of this color, modifying it.
			/**
			  * This operator subtracts a value from each component of this color
			  * and modifies this color to store the result.
			  * 
			  * @param value - The value to subtract from every component of this color.
			  * @return A reference to this modified color.
			  */
			RIM_INLINE Color3D<T>& operator -= ( const T& value )
			{
				r -= value;
				g -= value;
				b -= value;
				
				return *this;
			}
			
			
			
			
			/// Multiply a value with each component of this color, modifying it.
			/**
			  * This operator multiplies a value with each component of this color
			  * and modifies this color to store the result.
			  * 
			  * @param value - The value to multiply with every component of this color.
			  * @return A reference to this modified color.
			  */
			RIM_INLINE Color3D<T>& operator *= ( const T& value )
			{
				r *= value;
				g *= value;
				b *= value;
				
				return *this;
			}
			
			
			
			
			/// Divide each component of this color by a value, modifying it.
			/**
			  * This operator Divides each component of this color by value
			  * and modifies this color to store the result.
			  * 
			  * @param value - The value to multiply with every component of this color.
			  * @return A reference to this modified color.
			  */
			RIM_INLINE Color3D<T>& operator /= ( const T& value )
			{
				T inverseValue = T(1) / value;
				
				r *= inverseValue;
				g *= inverseValue;
				b *= inverseValue;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Conversion Methods
			
			
			
			
			/// Convert this color into a human-readable string representation.
			RIM_NO_INLINE data::String toString() const
			{
				data::StringBuffer buffer;
				
				buffer << "( " << r << ", " << g << ", " << b << " )";
				
				return buffer.toString();
			}
			
			
			
			
			/// Convert this color into a human-readable string representation.
			RIM_FORCE_INLINE operator data::String () const
			{
				return this->toString();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The red component of a 3D color.
			T r;
			
			
			
			/// The green component of a 3D color.
			T g;
			
			
			
			/// The blue component of a 3D color.
			T b;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// A constant color with all elements equal to zero.
			static const Color3D<T> ZERO;
			
			
			
			
			/// A constant color with all elements equal to zero.
			static const Color3D<T> BLACK;
			
			
			
			
			/// A constant color with all elements equal to one.
			static const Color3D<T> WHITE;
			
			
			
			
};




template <typename T>
const Color3D<T> Color3D<T>:: ZERO( 0, 0, 0 );




template <typename T>
const Color3D<T> Color3D<T>:: BLACK( 0, 0, 0 );




template <typename T>
const Color3D<T> Color3D<T>:: WHITE( 1, 1, 1 );




//##########################################################################################
//##########################################################################################
//############		
//############		Commutative Arithmatic Operators
//############		
//##########################################################################################
//##########################################################################################




/// Add a value to every component of the color.
/** 
  * This operator adds the value parameter to every component
  * of the color, and returns a color representing this result.
  * It does not modifiy the original color.
  * 
  * @param value - The value to add to all components of the color.
  * @param color - The color to be added to.
  * @return The resulting color of this addition.
  */
template < typename T >
RIM_INLINE Color3D<T> operator + ( const T& value, const Color3D<T>& color )
{
    return Color3D<T>( color.r + value, color.g + value, color.b + value );
}




/// Subtract every component of the color from the value, returning a color result.
/** 
  * This operator subtracts every component of the 2nd paramter, a color,
  * from the 1st paramter, a value, and then returns a color containing the
  * resulting coloral components. This operator does not modify the orignal color.
  * 
  * @param value - The value to subtract all components of the color from.
  * @param color - The color to be subtracted.
  * @return The resulting color of this subtraction.
  */
template < typename T >
RIM_INLINE Color3D<T> operator - ( const T& value, const Color3D<T>& color )
{
	return Color3D<T>( value - color.r, value - color.g, value - color.b );
}




/// Multiply every component of the color with the value, returning a color result.
/** 
  * This operator multiplies every component of the 2nd paramter, a color,
  * from the 1st paramter, a value, and then returns a color containing the
  * resulting coloral components. This operator does not modify the orignal color.
  * 
  * @param value - The value to multiply with all components of the color.
  * @param color - The color to be multiplied with.
  * @return The resulting color of this multiplication.
  */
template < typename T >
RIM_INLINE Color3D<T> operator * ( const T& value, const Color3D<T>& color ) 
{
	return Color3D<T>( color.r*value, color.g*value,  color.b*value );
}




/// Divide a value by every component of the color, returning a color result.
/** 
  * This operator divides the provided value by every component of
  * the color, returning a color representing the component-wise division.
  * The operator does not modify the original color.
  * 
  * @param value - The value to be divided by all components of the color.
  * @param color - The color to be divided by.
  * @return The resulting color of this division.
  */
template < typename T >
RIM_INLINE Color3D<T> operator / ( const T& value, const Color3D<T>& color ) 
{
	return Color3D<T>( value/color.r, value/color.g,  value/color.b );
}




typedef Color3D<Int> Color3i;
typedef Color3D<UByte> Color3b;
typedef Color3D<Float> Color3f;
typedef Color3D<Double> Color3d;



//##########################################################################################
//****************************  End Rim Images Namespace  **********************************
RIM_IMAGES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_IMAGES_COLOR_3D_H