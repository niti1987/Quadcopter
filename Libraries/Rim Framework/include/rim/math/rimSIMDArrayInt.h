/*
 * Project:     Rim Framework
 * 
 * File:        rim/math/SIMDScalarIntN.h
 * 
 * Version:     1.0.0
 * 
 * Contents:    rim::math::SIMDScalar class specialization for an N-integer SIMD data type.
 * 
 * License:
 * 
 *     Copyright (C) 2010-12 Carl Schissler.
 *     All rights reserved.
 * 
 * 
 * Contact Information:
 *     
 *     Please send all bug reports and other contact to:
 *     Carl Schissler
 *     carl.schissler@gmail.com
 * 
 */


#ifndef INCLUDE_RIM_SIMD_ARRAY_INT_H
#define INCLUDE_RIM_SIMD_ARRAY_INT_H


#include "rimMathConfig.h"


#include "rimSIMDConfig.h"
#include "rimSIMDScalar.h"
#include "rimSIMDScalarInt4.h"
#include "rimSIMDArray.h"
#include "rimSIMDArrayBool.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class representing an N-component 32-bit signed-integer SIMD scalar.
/**
  * This specialization of the SIMDScalar class uses one or more 4-component
  * SIMD values to simulate an N-wide SIMD register.
  */
template < Size width >
class RIM_ALIGN(16) SIMDArray<Int32,width>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new SIMD scalar with all elements left uninitialized.
			RIM_FORCE_INLINE SIMDArray()
			{
			}
			
			
			
			
			/// Create a new SIMD scalar with all elements equal to the specified value.
			RIM_FORCE_INLINE SIMDArray( Int32 value )
			{
				SIMDBaseType simdValue( value );
				
				for ( Index i = 0; i < numIterations; i++ )
					v[i] = simdValue;
			}
			
			
			
			
			/// Create a new SIMD scalar from the first N values stored at specified pointer's location.
			RIM_FORCE_INLINE SIMDArray( const Int32* array )
			{
				for ( Index i = 0; i < numIterations; i++ )
				{
					v[i] = SIMDBaseType( array );
					array += SIMD_WIDTH;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Load Methods
			
			
			
			
			/// Load a SIMD array from the specified aligned pointer to values.
			RIM_FORCE_INLINE static SIMDArray load( const Int32* array )
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
				{
					result.v[i] = SIMDBaseType::load( array );
					array += SIMD_WIDTH;
				}
				
				return result;
			}
			
			
			
			
			/// Load a SIMD array from the specified unaligned pointer to values.
			RIM_FORCE_INLINE static SIMDArray loadUnaligned( const Int32* array )
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
				{
					result.v[i] = SIMDBaseType::loadUnaligned( array );
					array += SIMD_WIDTH;
				}
				
				return result;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Store Method
			
			
			
			
			/// Store this SIMD scalar starting at the specified destination pointer.
			RIM_FORCE_INLINE void store( Int32* destination ) const
			{
				for ( Index i = 0; i < numIterations; i++ )
				{
					v[i].store( destination );
					destination += SIMD_WIDTH;
				}
			}
			
			
			
			
			/// Store this SIMD scalar starting at the specified unaligned destination pointer.
			RIM_FORCE_INLINE void storeUnaligned( Int32* destination ) const
			{
				for ( Index i = 0; i < numIterations; i++ )
				{
					v[i].storeUnaligned( destination );
					destination += SIMD_WIDTH;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Accessor Methods
			
			
			
			
			/// Get a reference to the value stored at the specified component index in this scalar.
			RIM_FORCE_INLINE Int32& operator [] ( Index i )
			{
				return ((Int32*)v)[i];
			}
			
			
			
			
			/// Get the value stored at the specified component index in this scalar.
			RIM_FORCE_INLINE Int32 operator [] ( Index i ) const
			{
				return ((const Int32*)v)[i];
			}
			
			
			
			
			/// Get a pointer to the first element in this scalar.
			/**
			  * The remaining values are in the next 3 locations after the
			  * first element.
			  */
			RIM_FORCE_INLINE const Int32* toArray() const
			{
				return (const Float32*)v;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Logical Operators
			
			
			
			
			/// Return the bitwise NOT of this 4D SIMD vector.
			RIM_FORCE_INLINE SIMDArray operator ~ () const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = ~v[i];
				
				return result;
			}
			
			
			
			
			/// Compute the bitwise AND of this 4D SIMD vector with another and return the result.
			RIM_FORCE_INLINE SIMDArray operator & ( const SIMDArray& scalar ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] & scalar.v[i];
				
				return result;
			}
			
			
			
			
			/// Compute the bitwise AND of this 4D SIMD vector with a mask and return the result.
			RIM_FORCE_INLINE SIMDArray operator & ( const SIMDArray<Bool,width>& scalar ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] & scalar.v[i];
				
				return result;
			}
			
			
			
			
			/// Compute the bitwise OR of this 4D SIMD vector with another and return the result.
			RIM_FORCE_INLINE SIMDArray operator | ( const SIMDArray& scalar ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] | scalar.v[i];
				
				return result;
			}
			
			
			
			
			/// Compute the bitwise AND of this 4D SIMD vector with a mask and return the result.
			RIM_FORCE_INLINE SIMDArray operator | ( const SIMDArray<Bool,width>& scalar ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] | scalar.v[i];
				
				return result;
			}
			
			
			
			
			/// Compute the bitwise XOR of this 4D SIMD vector with another and return the result.
			RIM_FORCE_INLINE SIMDArray operator ^ ( const SIMDArray& scalar ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] ^ scalar.v[i];
				
				return result;
			}
			
			
			
			
			/// Compute the bitwise AND of this 4D SIMD vector with a mask and return the result.
			RIM_FORCE_INLINE SIMDArray operator ^ ( const SIMDArray<Bool,width>& scalar ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] ^ scalar.v[i];
				
				return result;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Logical Assignment Operators
			
			
			
			
			/// Compute the logical AND of this 4D SIMD vector with another and assign it to this vector.
			RIM_FORCE_INLINE SIMDArray& operator &= ( const SIMDArray& scalar )
			{
				for ( Index i = 0; i < numIterations; i++ )
					v[i] &= scalar.v[i];
				
				return *this;
			}
			
			
			
			
			/// Compute the logical OR of this 4D SIMD vector with another and assign it to this vector.
			RIM_FORCE_INLINE SIMDArray& operator |= ( const SIMDArray& scalar )
			{
				for ( Index i = 0; i < numIterations; i++ )
					v[i] |= scalar.v[i];
				
				return *this;
			}
			
			
			
			
			/// Compute the bitwise XOR of this 4D SIMD vector with another and assign it to this vector.
			RIM_FORCE_INLINE SIMDArray& operator ^= ( const SIMDArray& scalar )
			{
				for ( Index i = 0; i < numIterations; i++ )
					v[i] ^= scalar.v[i];
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Compare two 4D SIMD scalars component-wise for equality.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * If each corresponding pair of components is equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDArray<Bool,width> operator == ( const SIMDArray& scalar ) const
			{
				SIMDArray<Bool,width> result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] == scalar.v[i];
				
				return result;
			}
			
			
			
			
			/// Compare this scalar to a single value for equality.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components is equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDArray<Bool,width> operator == ( const Int32 value ) const
			{
				SIMDArray<Bool,width> result;
				SIMDBaseType simdValue( value );
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] == simdValue;
				
				return result;
			}
			
			
			
			
			
			/// Compare two 4D SIMD scalars component-wise for inequality
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * If each corresponding pair of components is not equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDArray<Bool,width> operator != ( const SIMDArray& scalar ) const
			{
				SIMDArray<Bool,width> result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] != scalar.v[i];
				
				return result;
			}
			
			
			
			
			/// Compare this scalar to a single floating point value for inequality.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components is not equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDArray<Bool,width> operator != ( const Int32 value ) const
			{
				SIMDArray<Bool,width> result;
				SIMDBaseType simdValue( value );
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] != simdValue;
				
				return result;
			}
			
			
			
			
			/// Perform a component-wise less-than comparison between this an another 4D SIMD scalar.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component less than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDArray<Bool,width> operator < ( const SIMDArray& scalar ) const
			{
				SIMDArray<Bool,width> result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] < scalar.v[i];
				
				return result;
			}
			
			
			
			
			/// Perform a component-wise less-than comparison between this 4D SIMD scalar and an expanded scalar.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component less than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDArray<Bool,width> operator < ( const Int32 value ) const
			{
				SIMDArray<Bool,width> result;
				SIMDBaseType simdValue( value );
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] < simdValue;
				
				return result;
			}
			
			
			
			
			/// Perform a component-wise greater-than comparison between this an another 4D SIMD scalar.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDArray<Bool,width> operator > ( const SIMDArray& scalar ) const
			{
				SIMDArray<Bool,width> result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] > scalar.v[i];
				
				return result;
			}
			
			
			
			
			/// Perform a component-wise greater-than comparison between this 4D SIMD scalar and an expanded scalar.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDArray<Bool,width> operator > ( const Int32 value ) const
			{
				SIMDArray<Bool,width> result;
				SIMDBaseType simdValue( value );
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] > simdValue;
				
				return result;
			}
			
			
			
			
			/// Perform a component-wise less-than-or-equal-to comparison between this an another 4D SIMD scalar.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component less than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDArray<Bool,width> operator <= ( const SIMDArray& scalar ) const
			{
				SIMDArray<Bool,width> result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] <= scalar.v[i];
				
				return result;
			}
			
			
			
			
			/// Perform a component-wise less-than-or-equal-to comparison between this 4D SIMD scalar and an expanded scalar.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component less than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDArray<Bool,width> operator <= ( const Int32 value ) const
			{
				SIMDArray<Bool,width> result;
				SIMDBaseType simdValue( value );
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] <= simdValue;
				
				return result;
			}
			
			
			
			
			
			/// Perform a component-wise greater-than-or-equal-to comparison between this an another 4D SIMD scalar.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDArray<Bool,width> operator >= ( const SIMDArray& scalar ) const
			{
				SIMDArray<Bool,width> result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] >= scalar.v[i];
				
				return result;
			}
			
			
			
			
			/// Perform a component-wise greater-than-or-equal-to comparison between this 4D SIMD scalar and an expanded scalar.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components has this scalar's component greater than 
			  * or equal to the other scalar's component, the corresponding result component is non-zero.
			  * Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDArray<Bool,width> operator >= ( const Int32 value ) const
			{
				SIMDArray<Bool,width> result;
				SIMDBaseType simdValue( value );
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] >= simdValue;
				
				return result;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shifting Operators
			
			
			
			
			/// Shift each component of the SIMD scalar to the left by the specified amount of bits.
			/**
			  * This method shifts the contents of each component to the left by the specified
			  * amount of bits and inserts zeros.
			  * 
			  * @param bitShift - the number of bits to shift this SIMD scalar by.
			  * @return the shifted SIMD scalar.
			  */
			RIM_FORCE_INLINE SIMDArray operator << ( Int bitShift ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] << bitShift;
				
				return result;
			}
			
			
			
			
			/// Shift each component of the SIMD scalar to the right by the specified amount of bits.
			/**
			  * This method shifts the contents of each component to the right by the specified
			  * amount of bits and sign extends the original values..
			  * 
			  * @param bitShift - the number of bits to shift this SIMD scalar by.
			  * @return the shifted SIMD scalar.
			  */
			RIM_FORCE_INLINE SIMDArray operator >> ( Int bitShift ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] >> bitShift;
				
				return result;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Negation/Positivation Operators
			
			
			
			
			/// Negate a scalar.
			/** 
			  * This method negates every component of this 4D SIMD scalar
			  * and returns the result, leaving this scalar unmodified.
			  * 
			  * @return the negation of the original scalar.
			  */
			RIM_FORCE_INLINE SIMDArray operator - () const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = -v[i];
				
				return result;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Operators
			
			
			
			
			
			/// Add this scalar to another and return the result.
			/** 
			  * This method adds another scalar to this one, component-wise,
			  * and returns this addition. It does not modify either of the original
			  * scalars.
			  * 
			  * @param scalar - The scalar to add to this one.
			  * @return The addition of this scalar and the parameter.
			  */
			RIM_FORCE_INLINE SIMDArray operator + ( const SIMDArray& scalar ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] + scalar.v[i];
				
				return result;
			}
			
			
			
			
			/// Add a value to every component of this scalar.
			/** 
			  * This method adds the value parameter to every component
			  * of the scalar, and returns a scalar representing this result.
			  * It does not modifiy the original scalar.
			  * 
			  * @param value - The value to add to all components of this scalar.
			  * @return The resulting scalar of this addition.
			  */
			RIM_FORCE_INLINE SIMDArray operator + ( const Int32 value ) const
			{
				SIMDArray result;
				SIMDBaseType simdValue( value );
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] + simdValue;
				
				return result;
			}
			
			
			
			
			/// Subtract a scalar from this scalar component-wise and return the result.
			/** 
			  * This method subtracts another scalar from this one, component-wise,
			  * and returns this subtraction. It does not modify either of the original
			  * scalars.
			  * 
			  * @param scalar - The scalar to subtract from this one.
			  * @return The subtraction of the the parameter from this scalar.
			  */
			RIM_FORCE_INLINE SIMDArray operator - ( const SIMDArray& scalar ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] - scalar.v[i];
				
				return result;
			}
			
			
			
			
			/// Subtract a value from every component of this scalar.
			/** 
			  * This method subtracts the value parameter from every component
			  * of the scalar, and returns a scalar representing this result.
			  * It does not modifiy the original scalar.
			  * 
			  * @param value - The value to subtract from all components of this scalar.
			  * @return The resulting scalar of this subtraction.
			  */
			RIM_FORCE_INLINE SIMDArray operator - ( const Int32 value ) const
			{
				SIMDArray result;
				SIMDBaseType simdValue( value );
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] - simdValue;
				
				return result;
			}
			
			
			
			
			/// Multiply component-wise this scalar and another scalar.
			/** 
			  * This operator multiplies each component of this scalar
			  * by the corresponding component of the other scalar and
			  * returns a scalar representing this result. It does not modify
			  * either original scalar.
			  * 
			  * @param scalar - The scalar to multiply this scalar by.
			  * @return The result of the multiplication.
			  */
			RIM_FORCE_INLINE SIMDArray operator * ( const SIMDArray& scalar ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] * scalar.v[i];
				
				return result;
			}
			
			
			
			
			/// Multiply every component of this scalar by a value and return the result.
			/** 
			  * This method multiplies the value parameter with every component
			  * of the scalar, and returns a scalar representing this result.
			  * It does not modifiy the original scalar.
			  * 
			  * @param value - The value to multiplly with all components of this scalar.
			  * @return The resulting scalar of this multiplication.
			  */
			RIM_FORCE_INLINE SIMDArray operator * ( const Int32 value ) const
			{
				SIMDArray result;
				SIMDBaseType simdValue( value );
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] * simdValue;
				
				return result;
			}
			
			
			
			
			/// Divide this scalar by another scalar component-wise.
			/** 
			  * This operator divides each component of this scalar
			  * by the corresponding component of the other scalar and
			  * returns a scalar representing this result. It does not modify
			  * either original scalar.
			  * 
			  * @param scalar - The scalar to multiply this scalar by.
			  * @return The result of the division.
			  */
			RIM_FORCE_INLINE SIMDArray operator / ( const SIMDArray& scalar ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] / scalar.v[i];
				
				return result;
			}
			
			
			
			
			/// Divide every component of this scalar by a value and return the result.
			/** 
			  * This method Divides every component of the scalar by the value parameter, 
			  * and returns a scalar representing this result.
			  * It does not modifiy the original scalar.
			  * 
			  * @param value - The value to divide all components of this scalar by.
			  * @return The resulting scalar of this division.
			  */
			RIM_FORCE_INLINE SIMDArray operator / ( const Int32 value ) const
			{
				SIMDArray result;
				SIMDBaseType simdValue( value );
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] / simdValue;
				
				return result;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Arithmetic Assignment Operators
			
			
			
			
			/// Add a scalar to this scalar, modifying this original scalar.
			/**
			  * This method adds another scalar to this scalar, component-wise,
			  * and sets this scalar to have the result of this addition.
			  * 
			  * @param scalar - The scalar to add to this scalar.
			  * @return A reference to this modified scalar.
			  */
			RIM_FORCE_INLINE SIMDArray& operator += ( const SIMDArray& scalar )
			{
				for ( Index i = 0; i < numIterations; i++ )
					v[i] += scalar.v[i];
				
				return *this;
			}
			
			
			
			/// Subtract a scalar from this scalar, modifying this original scalar.
			/**
			  * This method subtracts another scalar from this scalar, component-wise,
			  * and sets this scalar to have the result of this subtraction.
			  * 
			  * @param scalar - The scalar to subtract from this scalar.
			  * @return A reference to this modified scalar.
			  */
			RIM_FORCE_INLINE SIMDArray& operator -= ( const SIMDArray& scalar )
			{
				for ( Index i = 0; i < numIterations; i++ )
					v[i] -= scalar.v[i];
				
				return *this;
			}
			
			
			
			
			/// Multiply component-wise this scalar and another scalar and modify this scalar.
			/** 
			  * This operator multiplies each component of this scalar
			  * by the corresponding component of the other scalar and
			  * modifies this scalar to contain the result.
			  * 
			  * @param scalar - The scalar to multiply this scalar by.
			  * @return A reference to this modified scalar.
			  */
			RIM_FORCE_INLINE SIMDArray& operator *= ( const SIMDArray& scalar )
			{
				for ( Index i = 0; i < numIterations; i++ )
					v[i] *= scalar.v[i];
				
				return *this;
			}
			
			
			
			
			/// Divide this scalar by another scalar component-wise and modify this scalar.
			/** 
			  * This operator divides each component of this scalar
			  * by the corresponding component of the other scalar and
			  * modifies this scalar to contain the result.
			  * 
			  * @param scalar - The scalar to divide this scalar by.
			  * @return A reference to this modified scalar.
			  */
			RIM_FORCE_INLINE SIMDArray& operator /= ( const SIMDArray& scalar )
			{
				for ( Index i = 0; i < numIterations; i++ )
					v[i] /= scalar.v[i];
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Required Alignment Accessor Methods
			
			
			
			
			/// Return the alignment required for objects of this type.
			/**
			  * For most SIMD types this value will be 16 bytes. If there is
			  * no alignment required, 0 is returned.
			  */
			RIM_FORCE_INLINE static Size getRequiredAlignment()
			{
				return 16;
			}
			
			
			
			
			/// Get the width of this scalar (number of components it has).
			RIM_FORCE_INLINE static Size getWidth()
			{
				return width;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The width of the underlying SIMD type used.
			static const Size SIMD_WIDTH = SIMD<Int32>::MAX_WIDTH;
			
			
			
			
			/// The underlying SIMD type used to implement this class.
			typedef SIMDScalar<Int32,SIMD_WIDTH> SIMDBaseType;
			
			
			
			
			/// The number of SIMD processing iterations that must occur.
			static const Size numIterations = SIMD_WIDTH*(width / SIMD_WIDTH) == width ? 
												width / SIMD_WIDTH : width / SIMD_WIDTH + 1;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An array of SIMD values that simulate an N-wide SIMD register.
			SIMDBaseType v[numIterations];
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Declarations
			
			
			
			
			template < typename T, Size dimension >
			friend class SIMDArray3D;
			
			
			template < Size width2 >
			friend RIM_FORCE_INLINE SIMDArray<Int32,width2> abs( const SIMDArray<Int32,width2>& scalar );
			
			template < Size width2 >
			friend RIM_FORCE_INLINE SIMDArray<Int32,width2> sqrt( const SIMDArray<Int32,width2>& scalar );
			
			template < Size width2 >
			friend RIM_FORCE_INLINE SIMDArray<Int32,width2> min( const SIMDArray<Int32,width2>& scalar1, const SIMDArray<Int32,width2>& scalar2 );
			
			template < Size width2 >
			friend RIM_FORCE_INLINE SIMDArray<Int32,width2> max( const SIMDArray<Int32,width2>& scalar1, const SIMDArray<Int32,width2>& scalar2 );
			
			template < Size width2 >
			friend RIM_FORCE_INLINE SIMDArray<Int32,width2> select( const SIMDArray<Bool,width2>& selector,
															const SIMDArray<Int32,width2>& scalar1, const SIMDArray<Int32,width2>& scalar2 );
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Associative SIMD Scalar Operators
//############		
//##########################################################################################
//##########################################################################################




/// Add a scalar value to each component of this scalar and return the resulting scalar.
template < Size width >
RIM_FORCE_INLINE SIMDArray<Int32,width> operator + ( const Int32 value, const SIMDArray<Int32,width>& scalar )
{
	return SIMDArray<Int32,width>(value) + scalar;
}




/// Subtract a scalar value from each component of this scalar and return the resulting scalar.
template < Size width >
RIM_FORCE_INLINE SIMDArray<Int32,width> operator - ( const Int32 value, const SIMDArray<Int32,width>& scalar )
{
	return SIMDArray<Int32,width>(value) - scalar;
}




/// Multiply a scalar value by each component of this scalar and return the resulting scalar.
template < Size width >
RIM_FORCE_INLINE SIMDArray<Int32,width> operator * ( const Int32 value, const SIMDArray<Int32,width>& scalar )
{
	return SIMDArray<Int32,width>(value) * scalar;
}




/// Divide each component of this scalar by a scalar value and return the resulting scalar.
template < Size width >
RIM_FORCE_INLINE SIMDArray<Int32,width> operator / ( const Int32 value, const SIMDArray<Int32,width>& scalar )
{
	return SIMDArray<Int32,width>(value) / scalar;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Free Vector Functions
//############		
//##########################################################################################
//##########################################################################################




/// Compute the absolute value of each component of the specified SIMD scalar and return the result.
template < Size width >
RIM_FORCE_INLINE SIMDArray<Int32,width> abs( const SIMDArray<Int32,width>& scalar )
{
	SIMDArray<Int32,width> result;
	
	for ( Index i = 0; i < SIMDArray<Int32,width>::numIterations; i++ )
		result.v[i] = math::abs( scalar.v[i] );
	
	return result;
}




/// Compute the square root of each component of the specified SIMD scalar and return the result.
template < Size width >
RIM_FORCE_INLINE SIMDArray<Int32,width> sqrt( const SIMDArray<Int32,width>& scalar )
{
	SIMDArray<Int32,width> result;
	
	for ( Index i = 0; i < SIMDArray<Int32,width>::numIterations; i++ )
		result.v[i] = math::sqrt( scalar.v[i] );
	
	return result;
}




/// Compute the minimum of each component of the specified SIMD scalars and return the result.
template < Size width >
RIM_FORCE_INLINE SIMDArray<Int32,width> min( const SIMDArray<Int32,width>& scalar1, const SIMDArray<Int32,width>& scalar2 )
{
	SIMDArray<Int32,width> result;
	
	for ( Index i = 0; i < SIMDArray<Int32,width>::numIterations; i++ )
		result.v[i] = math::min( scalar1.v[i], scalar2.v[i] );
	
	return result;
}




/// Compute the maximum of each component of the specified SIMD scalars and return the result.
template < Size width >
RIM_FORCE_INLINE SIMDArray<Int32,width> max( const SIMDArray<Int32,width>& scalar1, const SIMDArray<Int32,width>& scalar2 )
{
	SIMDArray<Int32,width> result;
	
	for ( Index i = 0; i < SIMDArray<Int32,width>::numIterations; i++ )
		result.v[i] = math::max( scalar1.v[i], scalar2.v[i] );
	
	return result;
}




/// Select elements from the first SIMD scalar if the selector is TRUE, otherwise from the second.
template < Size width >
RIM_FORCE_INLINE SIMDArray<Int32,width> select( const SIMDArray<Bool,width>& selector,
												const SIMDArray<Int32,width>& scalar1, const SIMDArray<Int32,width>& scalar2 )
{
	SIMDArray<Int32,width> result;
	
	for ( Index i = 0; i < SIMDArray<Int32,width>::numIterations; i++ )
		result.v[i] = math::select( selector.v[i], scalar1.v[i], scalar2.v[i] );
	
	return result;
}




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SIMD_ARRAY_INT_H
