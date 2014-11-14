/*
 *  rimSoundSample.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 3/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_SAMPLE_H
#define INCLUDE_RIM_SOUND_SAMPLE_H


#include "rimSoundUtilitiesConfig.h"


#include "rimSoundGain.h"
#include "rimSoundInt24.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a template primitive-typed sound sample.
/**
  * This class provides a wrapper for basic primitive types which provides
  * automatic sample saturation and proper conversion between different sample
  * types using standard arithmetic and cast operators.
  *
  * Floating-point template instantiations do not do saturating sample arithmetic
  * because of their much greater dynamic range.
  */
template < typename T >
class Sample
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			/// The underlying type used to represent this sample.
			typedef T BaseType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new Sample with value equal to 0.
			RIM_FORCE_INLINE Sample()
				:	sample( 0 )
			{
			}
			
			
			
			
			/// Create a new Sample with the specified value.
			RIM_FORCE_INLINE Sample( const T& newSample )
				:	sample( newSample )
			{
			}
			
			
			
			
			/// Convert a sample of another templated type to this sample type.
			/**
			  * This method applies the best conversion from the specified sample type
			  * to this sample type. For conversions to the 8-bit sample type, a simple
			  * dither is performed to improve the audio quality. One might want to implement
			  * a higher quality dither for these conversions, depending on the application.
			  */
			template < typename U >
			RIM_FORCE_INLINE Sample( const Sample<U>& other )
				:	sample( other.sample )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Cast Operators
			
			
			
			
			/// Return a const reference to this Sample's value.
			RIM_FORCE_INLINE operator const T& () const
			{
				return sample;
			}
			
			
			
			
			/// Cast this sample object to a sample object of another type.
			template < typename U >
			RIM_FORCE_INLINE operator Sample<U> () const
			{
				return Sample<U>( *this );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mixing (Addition) Operators
			
			
			
			
			/// Mix this sample with another and return the result.
			RIM_FORCE_INLINE Sample operator + ( const Sample& other ) const
			{
				return Sample( sample + other.sample );
			}
			
			
			
			
			/// Mix another sample with this sample and overwrite this sample.
			RIM_FORCE_INLINE Sample& operator += ( const Sample& other )
			{
				sample += other.sample;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Subtraction Operators
			
			
			
			
			/// Subtract another sample from this sample and return the result.
			RIM_FORCE_INLINE Sample operator - ( const Sample& other ) const
			{
				return Sample( sample - other.sample );
			}
			
			
			
			
			/// Subtract another sample from this sample and overwrite this sample.
			RIM_FORCE_INLINE Sample& operator -= ( const Sample& other )
			{
				sample -= other.sample;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Gain Scaling Operators
			
			
			
			
			/// Scale this sample by a linear gain factor and return the result.
			RIM_FORCE_INLINE Sample operator * ( Float gain ) const
			{
				return Sample( sample*gain );
			}
			
			
			
			
			/// Scale this sample by a linear gain factor and return the result.
			RIM_FORCE_INLINE Sample operator * ( Double gain ) const
			{
				return Sample( sample*gain );
			}
			
			
			
			
			/// Scale this sample by a linear gain factor and overwite this sample.
			RIM_FORCE_INLINE Sample& operator *= ( Float gain )
			{
				sample *= gain;
				
				return sample;
			}
			
			
			
			
			/// Scale this sample by a linear gain factor and overwite this sample.
			RIM_FORCE_INLINE Sample& operator *= ( Double gain )
			{
				sample *= gain;
				
				return sample;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The data member which represents this sample's value.
			T sample;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Class Declaration
			
			
			
			
			/// Declare other types of sample objects to be friend classes.
			template < typename U >
			friend class Sample;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Sample to Sample8 Conversion Methods
//############		
//##########################################################################################
//##########################################################################################




template <> template <>
RIM_FORCE_INLINE Sample<Int8>:: Sample( const Sample<Int16>& other )
	:	sample( Int8(other.sample >> 8) )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int8>:: Sample( const Sample<Int24>& other )
	:	sample( Int8(other.sample >> 16) )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int8>:: Sample( const Sample<Int32>& other )
	:	sample( Int8(other.sample >> 24) )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int8>:: Sample( const Sample<Int64>& other )
	:	sample( Int8(other.sample >> 56) )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int8>:: Sample( const Sample<Float32>& other )
	:	sample( Int8(math::round( math::clamp( other.sample + math::random(-0.5f / 128, 0.5f / 127),
												Float32(-1), Float32(1) )*math::max<Int8>() )) )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int8>:: Sample( const Sample<Float64>& other )
	:	sample( Int8(math::round( math::clamp( other.sample + math::random(-0.5 / 128, 0.5 / 127),
												Float64(-1), Float64(1) )*math::max<Int8>() )) )
{
}




//##########################################################################################
//##########################################################################################
//############		
//############		Sample to Sample16 Conversion Methods
//############		
//##########################################################################################
//##########################################################################################




template <> template <>
RIM_FORCE_INLINE Sample<Int16>:: Sample( const Sample<Int8>& other )
	:	sample( Int16(other.sample) << 8 )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int16>:: Sample( const Sample<Int24>& other )
	:	sample( Int16(other.sample >> 8) )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int16>:: Sample( const Sample<Int32>& other )
	:	sample( Int16(other.sample >> 16) )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int16>:: Sample( const Sample<Int64>& other )
	:	sample( Int16(other.sample >> 48) )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int16>:: Sample( const Sample<Float32>& other )
	:	sample( Int16(math::round( math::clamp( other.sample + math::random(-0.5f / 32768, 0.5f / 32767),
												Float32(-1), Float32(1) )*math::max<Int16>() )) )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int16>:: Sample( const Sample<Float64>& other )
	:	sample( Int16(math::round( math::clamp( other.sample + math::random(-0.5 / 32768, 0.5 / 32767),
												Float64(-1), Float64(1) )*math::max<Int16>() )) )
{
}




//##########################################################################################
//##########################################################################################
//############		
//############		Sample to Sample24 Conversion Methods
//############		
//##########################################################################################
//##########################################################################################




template <> template <>
RIM_FORCE_INLINE Sample<Int24>:: Sample( const Sample<Int8>& other )
	:	sample( Int24(other.sample) << 16 )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int24>:: Sample( const Sample<Int16>& other )
	:	sample( Int24(other.sample) << 8 )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int24>:: Sample( const Sample<Int32>& other )
	:	sample( Int24(other.sample >> 8) )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int24>:: Sample( const Sample<Int64>& other )
	:	sample( Int24(Int32(other.sample >> 40)) )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int24>:: Sample( const Sample<Float32>& other )
	:	sample( Int24( Int32(math::clamp( other.sample, Float32(-1), Float32(1) )*8388607.0f ) ) )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int24>:: Sample( const Sample<Float64>& other )
	:	sample( Int24( Int32(math::clamp( other.sample, Float64(-1), Float64(1) )*8388607.0f ) ) )
{
}




//##########################################################################################
//##########################################################################################
//############		
//############		Sample to Sample32 Conversion Methods
//############		
//##########################################################################################
//##########################################################################################




template <> template <>
RIM_FORCE_INLINE Sample<Int32>:: Sample( const Sample<Int8>& other )
	:	sample( Int32(other.sample) << 24 )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int32>:: Sample( const Sample<Int16>& other )
	:	sample( Int32(other.sample) << 16 )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int32>:: Sample( const Sample<Int24>& other )
	:	sample( Int32(other.sample) << 8 )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int32>:: Sample( const Sample<Int64>& other )
	:	sample( Int32(other.sample >> 32) )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int32>:: Sample( const Sample<Float32>& other )
	:	sample( Int32(math::clamp( other.sample, Float32(-1), Float32(1) )*math::max<Int32>()) )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int32>:: Sample( const Sample<Float64>& other )
	:	sample( Int32(math::clamp( other.sample, Float64(-1), Float64(1) )*math::max<Int32>()) )
{
}




//##########################################################################################
//##########################################################################################
//############		
//############		Sample to Sample64 Conversion Methods
//############		
//##########################################################################################
//##########################################################################################




template <> template <>
RIM_FORCE_INLINE Sample<Int64>:: Sample( const Sample<Int8>& other )
	:	sample( Int64(other.sample) << 56 )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int64>:: Sample( const Sample<Int16>& other )
	:	sample( Int64(other.sample) << 48 )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int64>:: Sample( const Sample<Int24>& other )
	:	sample( Int64(other.sample) << 40 )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int64>:: Sample( const Sample<Int32>& other )
	:	sample( Int64(other.sample) << 32 )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int64>:: Sample( const Sample<Float32>& other )
	:	sample( Int64(math::clamp( other.sample, Float32(-1), Float32(1) )*Float32(math::max<Int64>())) )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Int64>:: Sample( const Sample<Float64>& other )
	:	sample( Int64(math::clamp( other.sample, Float64(-1), Float64(1) )*math::max<Int64>()) )
{
}




//##########################################################################################
//##########################################################################################
//############		
//############		Sample to Sample32f Conversion Methods
//############		
//##########################################################################################
//##########################################################################################




template <> template <>
RIM_FORCE_INLINE Sample<Float32>:: Sample( const Sample<Int8>& other )
	:	sample( other.sample < 0 ? 
				(Float32)other.sample / -(Float32)math::min<Int8>() : 
				(Float32)other.sample / (Float32)math::max<Int8>() )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Float32>:: Sample( const Sample<Int16>& other )
	:	sample( other.sample < 0 ? 
				(Float32)other.sample / -(Float32)math::min<Int16>() : 
				(Float32)other.sample / (Float32)math::max<Int16>() )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Float32>:: Sample( const Sample<Int24>& other )
	:	sample( other.sample < 0 ? 
				(Float32)other.sample / Float32(8388608) : 
				(Float32)other.sample / Float32(8388607) )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Float32>:: Sample( const Sample<Int32>& other )
	:	sample( other.sample < 0 ? 
				(Float32)other.sample / -(Float32)math::min<Int32>() : 
				(Float32)other.sample / (Float32)math::max<Int32>() )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Float32>:: Sample( const Sample<Int64>& other )
	:	sample( other.sample < 0 ? 
				(Float32)other.sample / -(Float32)math::min<Int64>() : 
				(Float32)other.sample / (Float32)math::max<Int64>() )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Float32>:: Sample( const Sample<Float64>& other )
	:	sample( (Float32)other.sample )
{
}




//##########################################################################################
//##########################################################################################
//############		
//############		Sample to Sample32f Conversion Methods
//############		
//##########################################################################################
//##########################################################################################




template <> template <>
RIM_FORCE_INLINE Sample<Float64>:: Sample( const Sample<Int8>& other )
	:	sample( other.sample < 0 ? 
				(Float64)other.sample / -(Float64)math::min<Int8>() : 
				(Float64)other.sample / (Float64)math::max<Int8>() )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Float64>:: Sample( const Sample<Int16>& other )
	:	sample( other.sample < 0 ? 
				(Float64)other.sample / -(Float64)math::min<Int16>() : 
				(Float64)other.sample / (Float64)math::max<Int16>() )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Float64>:: Sample( const Sample<Int24>& other )
	:	sample( other.sample < 0 ? 
				(Float64)other.sample / Float64(8388608) : 
				(Float64)other.sample / Float64(8388607) )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Float64>:: Sample( const Sample<Int32>& other )
	:	sample( other.sample < 0 ? 
				(Float64)other.sample / -(Float64)math::min<Int32>() : 
				(Float64)other.sample / (Float64)math::max<Int32>() )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Float64>:: Sample( const Sample<Int64>& other )
	:	sample( other.sample < 0 ? 
				(Float64)other.sample / -(Float64)math::min<Int64>() : 
				(Float64)other.sample / (Float64)math::max<Int64>() )
{
}




template <> template <>
RIM_FORCE_INLINE Sample<Float64>:: Sample( const Sample<Float32>& other )
	:	sample( other.sample )
{
}




//##########################################################################################
//##########################################################################################
//############		
//############		Commutative Sample Operators
//############		
//##########################################################################################
//##########################################################################################




/// Multiply a sample by a linear gain factor and return the resulting sample.
template < typename T >
RIM_FORCE_INLINE Sample<T> operator * ( const Float& gain, const Sample<T>& sample )
{
	return sample*gain;
}




/// Multiply a sample by a linear gain factor and return the resulting sample.
template < typename T >
RIM_FORCE_INLINE Sample<T> operator * ( const Double& gain, const Sample<T>& sample )
{
	return sample*gain;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Integer Sample Mixing Operations
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_FORCE_INLINE Sample<Int8> Sample<Int8>:: operator + ( const Sample<Int8>& other ) const
{
	return Sample<Int8>( (Int8)math::clamp( (Int32)sample + (Int32)other.sample,
											(Int32)math::min<Int8>(), (Int32)math::max<Int8>() ) );
}




template <>
RIM_FORCE_INLINE Sample<Int16> Sample<Int16>:: operator + ( const Sample<Int16>& other ) const
{
	return Sample<Int16>( (Int16)math::clamp( (Int32)sample + (Int32)other.sample,
												(Int32)math::min<Int16>(), (Int32)math::max<Int16>() ) );
}




template <>
RIM_FORCE_INLINE Sample<Int24> Sample<Int24>:: operator + ( const Sample<Int24>& other ) const
{
	return Sample<Int24>( math::clamp( sample + other.sample,
										Int32(-8388608), Int32(8388607) ) );
}




template <>
RIM_FORCE_INLINE Sample<Int32> Sample<Int32>:: operator + ( const Sample<Int32>& other ) const
{
	return Sample<Int32>( (Int32)math::clamp( (Int64)sample + (Int64)other.sample,
											(Int64)math::min<Int32>(), (Int64)math::max<Int32>() ) );
}




template <>
RIM_FORCE_INLINE Sample<Int64> Sample<Int64>:: operator + ( const Sample<Int64>& other ) const
{
	return Sample<Int64>( (Int64)math::clamp( (Double)sample + (Double)other.sample,
											(Double)math::min<Int64>(), (Double)math::max<Int64>() ) );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Integer Sample Subtraction Operations
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_FORCE_INLINE Sample<Int8> Sample<Int8>:: operator - ( const Sample<Int8>& other ) const
{
	return Sample<Int8>( (Int8)math::clamp( (Int32)sample - (Int32)other.sample,
											(Int32)math::min<Int8>(), (Int32)math::max<Int8>() ) );
}




template <>
RIM_FORCE_INLINE Sample<Int16> Sample<Int16>:: operator - ( const Sample<Int16>& other ) const
{
	return Sample<Int16>( (Int16)math::clamp( (Int32)sample - (Int32)other.sample,
											(Int32)math::min<Int16>(), (Int32)math::max<Int16>() ) );
}




template <>
RIM_FORCE_INLINE Sample<Int24> Sample<Int24>:: operator - ( const Sample<Int24>& other ) const
{
	return Sample<Int24>( math::clamp( sample - other.sample,
										Int32(-8388608), Int32(8388607) ) );
}




template <>
RIM_FORCE_INLINE Sample<Int32> Sample<Int32>:: operator - ( const Sample<Int32>& other ) const
{
	return Sample<Int32>( (Int32)math::clamp( (Int64)sample - (Int64)other.sample,
											(Int64)math::min<Int32>(), (Int64)math::max<Int32>() ) );
}




template <>
RIM_FORCE_INLINE Sample<Int64> Sample<Int64>:: operator - ( const Sample<Int64>& other ) const
{
	return Sample<Int64>( (Int64)math::clamp( (Double)sample - (Double)other.sample,
											(Double)math::min<Int64>(), (Double)math::max<Int64>() ) );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Integer Sample Scaling Operations
//############		
//##########################################################################################
//##########################################################################################




template <>
RIM_FORCE_INLINE Sample<Int8> Sample<Int8>:: operator * ( Gain gain ) const
{
	return Sample<Int8>( (Int8)math::clamp( Float32(sample)*gain,
											(Float32)math::min<Int8>(), (Float32)math::max<Int8>() ) );
}




template <>
RIM_FORCE_INLINE Sample<Int16> Sample<Int16>:: operator * ( Gain gain ) const
{
	return Sample<Int16>( (Int16)math::clamp( Float32(sample)*gain,
											(Float32)math::min<Int16>(), (Float32)math::max<Int16>() ) );
}




template <>
RIM_FORCE_INLINE Sample<Int24> Sample<Int24>:: operator * ( Gain gain ) const
{
	return Sample<Int24>( (Int32)math::clamp( Float32(sample)*gain,
											Float32(-8388608.0f), Float32(8388607.0f) ) );
}




template <>
RIM_FORCE_INLINE Sample<Int32> Sample<Int32>:: operator * ( Gain gain ) const
{
	return Sample<Int32>( (Int32)math::clamp( Float64(sample)*gain,
											(Float64)math::min<Int32>(), (Float64)math::max<Int32>() ) );
}




template <>
RIM_FORCE_INLINE Sample<Int64> Sample<Int64>:: operator * ( Gain gain ) const
{
	return Sample<Int64>( (Int64)math::clamp( Float64(sample)*gain,
											(Float64)math::min<Int64>(), (Float64)math::max<Int64>() ) );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Sample Typedefs
//############		
//##########################################################################################
//##########################################################################################




/// Define the type of a integral sample which uses a signed 8-bit representation.
typedef Sample<Int8> Sample8;




/// Define the type of a integral sample which uses a signed 16-bit representation.
typedef Sample<Int16> Sample16;




/// Define the type of a integral sample which uses a signed 24-bit representation.
typedef Sample<Int24> Sample24;




/// Define the type of a integral sample which uses a signed 32-bit representation.
typedef Sample<Int32> Sample32;




/// Define the type of a integral sample which uses a signed 64-bit representation.
typedef Sample<Int64> Sample64;




/// Define the type of a floating-point sample which uses a 32-bit representation.
typedef Sample<Float32> Sample32f;




/// Define the type of a floating-point sample which uses a 64-bit representation.
typedef Sample<Float64> Sample64f;




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_SAMPLE_H
