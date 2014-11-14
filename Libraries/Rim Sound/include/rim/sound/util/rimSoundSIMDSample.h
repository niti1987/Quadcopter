/*
 *  rimSoundSIMDSample.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 6/1/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_SIMD_SAMPLE_H
#define INCLUDE_RIM_SOUND_SIMD_SAMPLE_H


#include "rimSoundUtilitiesConfig.h"


#include "rimSoundSample.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a SIMD-vector of template primitive-typed sound samples.
template < typename T >
class RIM_ALIGN(16) SIMDSample
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			/// The underlying type used to represent this sample.
			typedef T BaseType;
			
			
			
			
			/// The underlying SIMDScalar type used to represent this SIMD sample.
			typedef math::SIMDScalar<T,math::SIMDType<T>::MAX_WIDTH> SIMDType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new SIMD sample with all component values equal to 0.
			RIM_FORCE_INLINE SIMDSample()
				:	sample()
			{
			}
			
			
			
			
			/// Create a new SIMD sample with the specified value for all components.
			RIM_FORCE_INLINE SIMDSample( const T& newSample )
				:	sample( newSample )
			{
			}
			
			
			
			
			/// Create a new SIMD sample with the SIMD sample values for its components.
			RIM_FORCE_INLINE SIMDSample( const SIMDType& newSample )
				:	sample( newSample )
			{
			}
			
			
			
			
			/// Create a new SIMD sample with the specified sample value for all components.
			RIM_FORCE_INLINE SIMDSample( const Sample<T>& newSample )
				:	sample( newSample )
			{
			}
			
			
			
			
			/// Create a new SIMD sample with its components initialized with data from the specified pointer.
			/**
			  * The pointer must have the correct alignment for the SIMD type.
			  */
			RIM_FORCE_INLINE SIMDSample( const T* newSample )
				:	sample( newSample )
			{
			}
			
			
			
			
			/// Create a new SIMD sample with its components initialized with data from the specified pointer.
			/**
			  * The pointer must have the correct alignment for the SIMD type.
			  */
			RIM_FORCE_INLINE SIMDSample( const Sample<T>* newSample )
				:	sample( (T*)newSample )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Store Methods
			
			
			
			
			/// Store the components of this SIMD sample to the specified pointer.
			/**
			  * The pointer must have the correct alignment for the SIMD type.
			  */
			RIM_FORCE_INLINE void store( T* pointer )
			{
				sample.store( pointer );
			}
			
			
			
			
			/// Store the components of this SIMD sample to the specified pointer.
			/**
			  * The pointer must have the correct alignment for the SIMD type.
			  */
			RIM_FORCE_INLINE void store( Sample<T>* pointer )
			{
				sample.store( (T*)pointer );
			}
			
			
			
			
			/// Store the components of this SIMD sample to the specified pointer.
			/**
			  * The pointer must have the correct alignment for the SIMD type.
			  */
			RIM_FORCE_INLINE void storeUnaligned( T* pointer )
			{
				sample.storeUnaligned( pointer );
			}
			
			
			
			
			/// Store the components of this SIMD sample to the specified pointer.
			/**
			  * The pointer must have the correct alignment for the SIMD type.
			  */
			RIM_FORCE_INLINE void storeUnaligned( Sample<T>* pointer )
			{
				sample.storeUnaligned( (T*)pointer );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Cast Operators
			
			
			
			
			/// Return a const reference to this Sample's value.
			RIM_FORCE_INLINE operator const SIMDType& () const
			{
				return sample;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Width and Alignment Accessor Methods
			
			
			
			
			/// Return the number of vector components that this SIMD sample type has.
			RIM_FORCE_INLINE static Size getWidth()
			{
				return SIMDType::getWidth();
			}
			
			
			
			
			/// Return the required byte alignment for SIMD samples with this type.
			RIM_FORCE_INLINE static Size getRequiredAlignment()
			{
				return SIMDType::getRequiredAlignment();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Horizontal Mixing Method
			
			
			
			
			/// Horizontally mix the components of this SIMD sample and return the resulting scalar.
			RIM_FORCE_INLINE Sample<T> mix() const
			{
				return sample.sum();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mixing (Addition) Operators
			
			
			
			
			/// Mix this sample with another and return the result.
			RIM_FORCE_INLINE SIMDSample operator + ( const SIMDSample& other ) const
			{
				return SIMDSample( sample + other.sample );
			}
			
			
			
			
			/// Mix another sample with this sample and overwrite this sample.
			RIM_FORCE_INLINE SIMDSample& operator += ( const SIMDSample& other )
			{
				sample += other.sample;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Subtraction Operators
			
			
			
			
			/// Subtract another sample from this sample and return the result.
			RIM_FORCE_INLINE SIMDSample operator - ( const SIMDSample& other ) const
			{
				return SIMDSample( sample - other.sample );
			}
			
			
			
			
			/// Subtract another sample from this sample and overwrite this sample.
			RIM_FORCE_INLINE SIMDSample& operator -= ( const SIMDSample& other )
			{
				sample -= other.sample;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Gain Scaling Operators
			
			
			
			
			/// Scale this sample by a linear gain factor and return the result.
			RIM_FORCE_INLINE SIMDSample operator * ( T gain ) const
			{
				return SIMDSample( sample*gain );
			}
			
			
			
			
			/// Scale this sample by a linear gain factor and overwite this sample.
			RIM_FORCE_INLINE SIMDSample& operator *= ( T gain )
			{
				sample *= gain;
				
				return *this;
			}
			
			
			
			
			/// Scale this sample by a SIMD linear gain factor and return the result.
			RIM_FORCE_INLINE SIMDSample operator * ( const SIMDType& gain ) const
			{
				return SIMDSample( sample*gain );
			}
			
			
			
			
			/// Scale this sample by a SIMD linear gain factor and overwite this sample.
			RIM_FORCE_INLINE SIMDSample& operator *= ( const SIMDType& gain )
			{
				sample *= gain;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Polarity Inversion
			
			
			
			
			/// Return the result when this sample's polarity is inverted.
			RIM_FORCE_INLINE SIMDSample operator - () const
			{
				return SIMDSample(-sample);
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The data member which represents this sample's value.
			SIMDType sample;
			
			
			
};




/// Define the type of a floating-point sample which uses a 4x32-bit SIMD representation.
typedef SIMDSample<Float32> SIMDSample32f;
typedef SIMDSample32f::SIMDType SIMDGain32f;



/// Define the type of a floating-point sample which uses a 2x64-bit SIMD representation.
typedef SIMDSample<Float64> SIMDSample64f;
typedef SIMDSample64f::SIMDType SIMDGain64f;




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_SIMD_SAMPLE_H
