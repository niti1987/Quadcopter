

#ifndef INCLUDE_RIM_SIMD_ARRAY_BOOL_H
#define INCLUDE_RIM_SIMD_ARRAY_BOOL_H


#include "rimMathConfig.h"


#include "rimSIMDConfig.h"
#include "rimSIMDScalar.h"
#include "rimSIMDScalarBool4.h"
#include "rimSIMDArray.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class representing an N-component pseudo-boolean SIMD vector.
/**
  * This specialization of the SIMDScalar class uses 32-bit integer values
  * which each semantically represent a single boolean value where all 1's is
  * TRUE and all 0's is FALSE.
  */
template < Size width >
class RIM_ALIGN(16) SIMDArray<Bool,width>
{
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new 4D SIMD scalar with all elements left uninitialized.
			RIM_FORCE_INLINE SIMDArray()
			{
			}
			
			
			
			
			/// Create a new 4D SIMD vector with all elements equal to the specified value.
			RIM_FORCE_INLINE SIMDArray( Bool value )
			{
				SIMDBaseType simdValue( value );
				
				for ( Index i = 0; i < numIterations; i++ )
					v[i] = simdValue;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Cast Operator
			
			
			
			
			/// Return a boolean value which indicates whether or not any of the components are true.
			RIM_FORCE_INLINE operator Bool () const
			{
				Bool result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result |= v[i].getMask() != 0;
				
				return result;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Accessor Methods
			
			
			
			
			/// Get the element at the specified index in the vector.
			RIM_FORCE_INLINE Bool operator [] ( Index i ) const
			{
				return (Bool)*((const UInt32*)&v);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Compare two 4D SIMD booleans component-wise for inequality
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * If each corresponding pair of components is equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDArray operator == ( const SIMDArray& scalar ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] == scalar.v[i];
				
				return result;
			}
			
			
			
			
			/// Compare this 4D SIMD boolean to a single boolean value for equality.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components is equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDArray operator == ( const Bool value ) const
			{
				SIMDArray result;
				SIMDBaseType simdValue( value );
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] == simdValue;
				
				return result;
			}
			
			
			
			
			
			/// Compare two 4D SIMD booleans component-wise for inequality
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * If each corresponding pair of components is not equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDArray operator != ( const SIMDArray& scalar ) const
			{
				SIMDArray result;
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] != scalar.v[i];
				
				return result;
			}
			
			
			
			
			/// Compare this 4D SIMD boolean to a single boolean value for inequality.
			/**
			  * Return a 4D scalar of booleans indicating the result of the comparison.
			  * The float value is expanded to a 4-wide SIMD scalar and compared with this scalar.
			  * If each corresponding pair of components is not equal, the corresponding result
			  * component is non-zero. Otherwise, that result component is equal to zero.
			  */
			RIM_FORCE_INLINE SIMDArray operator != ( const Bool value ) const
			{
				SIMDArray result;
				SIMDBaseType simdValue( value );
				
				for ( Index i = 0; i < numIterations; i++ )
					result.v[i] = v[i] != simdValue;
				
				return result;	
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
			
			
			
			
			/// Compute the bitwise OR of this 4D SIMD vector with another and return the result.
			RIM_FORCE_INLINE SIMDArray operator | ( const SIMDArray& scalar ) const
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
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Logical Assignment Operators
			
			
			
			
			/// Compute the logical AND of this 4D SIMD vector with another and assign it to this vector.
			RIM_FORCE_INLINE SIMDArray operator &= ( const SIMDArray& scalar )
			{
				for ( Index i = 0; i < numIterations; i++ )
					v[i] &= scalar.v[i];
				
				return *this;
			}
			
			
			
			
			/// Compute the logical OR of this 4D SIMD vector with another and assign it to this vector.
			RIM_FORCE_INLINE SIMDArray operator |= ( const SIMDArray& scalar )
			{
				for ( Index i = 0; i < numIterations; i++ )
					v[i] |= scalar.v[i];
				
				return *this;
			}
			
			
			
			
			/// Compute the bitwise XOR of this 4D SIMD vector with another and assign it to this vector.
			RIM_FORCE_INLINE SIMDArray operator ^= ( const SIMDArray& scalar )
			{
				for ( Index i = 0; i < numIterations; i++ )
					v[i] ^= scalar.v[i];
				
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
				return SIMDBaseType::getWidth();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The width of the underlying SIMD type used.
			static const Size SIMD_WIDTH = SIMD<Bool>::MAX_WIDTH;
			
			
			
			
			/// The underlying SIMD type used to implement this class.
			typedef SIMDScalar<Bool,SIMD_WIDTH> SIMDBaseType;
			
			
			
			
			/// The number of SIMD processing iterations that must occur.
			static const Size numIterations = SIMD_WIDTH*(width / SIMD_WIDTH) == width ? width / SIMD_WIDTH : width / SIMD_WIDTH + 1;
			
			
			
			
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
			
			
			
			
			/// Declare the floating point version of this class as a friend.
			/**
			  * This is done because the floating-point version needs to access the
			  * private constructor of this class for speed when storing the results
			  * of SIMD comparisons.
			  */
			friend class SIMDArray<Float32,width>;
			
			
			
			
			/// Declare the integer point version of this class as a friend.
			/**
			  * This is done because the integer version needs to access the
			  * private constructor of this class for speed when storing the results
			  * of SIMD comparisons.
			  */
			friend class SIMDArray<Int32,width>;
			
			
			
			
			template < Size width2 >
			friend RIM_FORCE_INLINE SIMDArray<Float32,width2> select( const SIMDArray<Bool,width2>& selector,
											const SIMDArray<Float32,width2>& scalar1, const SIMDArray<Float32,width2>& scalar2 );
			
			
			
			template < Size width2 >
			friend RIM_FORCE_INLINE SIMDArray<Int32,4> select( const SIMDArray<Bool,width2>& selector,
											const SIMDArray<Int32,width2>& scalar1, const SIMDArray<Int32,width2>& scalar2 );
			
			
			
			template < Size width2 >
			friend RIM_FORCE_INLINE SIMDArray<Bool,width2> select( const SIMDArray<Bool,width2>& selector,
											const SIMDArray<Bool,width2>& scalar1, const SIMDArray<Bool,width2>& scalar2 );
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Free Vector Functions
//############		
//##########################################################################################
//##########################################################################################




/// Select elements from the first SIMD scalar if the selector is TRUE, otherwise from the second.
template < Size width >
RIM_FORCE_INLINE SIMDArray<Bool,width> select( const SIMDArray<Bool,width>& selector,
												const SIMDArray<Bool,width>& scalar1, const SIMDArray<Bool,width>& scalar2 )
{
	SIMDArray<Bool,width> result;
	
	for ( Index i = 0; i < SIMDArray<Bool,width>::numIterations; i++ )
		result.v[i] = math::select( selector.v[i], scalar1.v[i], scalar2.v[i] );
	
	return result;
}




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SIMD_ARRAY_BOOL_H
