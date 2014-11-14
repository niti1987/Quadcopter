/*
 *  rimGraphicsAnimationSampler.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/24/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_ANIMATION_SAMPLER_H
#define INCLUDE_RIM_GRAPHICS_ANIMATION_SAMPLER_H


#include "rimGraphicsAnimationConfig.h"


#include "rimGraphicsAnimationTrack.h"


//##########################################################################################
//**********************  Start Rim Graphics Animation Namespace  **************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that interpolates a sampled animation track based on its interpolation type.
/**
  * The sampler supports random-access sampling of an animation track and also
  * uses caching of previous samples to efficiently interpolate a stream of sample points.
  */
class AnimationSampler
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default animation sampler with no animation track to interpolate.
			AnimationSampler();
			
			
			
			
			/// Create an animation sampler for the specified animation track.
			AnimationSampler( const Pointer<AnimationTrack>& newTrack );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Track Accessor Methods
			
			
			
			
			/// Return a pointer to the animation track that this sampler is interpolating.
			RIM_INLINE const Pointer<AnimationTrack>& getTrack() const
			{
				return track;
			}
			
			
			
			
			/// Set a pointer to the animation track that this sampler is interpolating.
			RIM_INLINE void setTrack( const Pointer<AnimationTrack>& newTrack )
			{
				track = newTrack;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sampling Methods
			
			
			
			
			/// Sample the animation track at the specified time offset from the beginning the animation track.
			/**
			  * If supported, the animation track is interpolated using its declared
			  * interpolation type. If the interpolation type is undefined or not supported
			  * by the sampler, InterpolationType::LINEAR interpolation is used as a fallback.
			  *
			  * The method returns whether or not the animation sampling operation was successful.
			  */
			Bool sample( const Time& time, AttributeValue& value );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Linear Interpolation Methods
			
			
			
			
			/// Interpolate the specified generic type components using linear interpolation.
			template < typename T >
			RIM_FORCE_INLINE static void interpolateLinearComponents( Size numComponents, Float a,
																		const T* v1, const T* v2, T* v );
			
			
			
			
			/// Interpolate the specified samples using linear interpolation to compute the output value.
			static Bool interpolateLinear( const Time& t1, const AttributeValue& v1,
											const Time& t2, const AttributeValue& v2,
											const Time& t, AttributeValue& v );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the animation track that this sampler is sampling.
			Pointer<AnimationTrack> track;
			
			
			
			
			/// The index of the previously queried sample point for this animation.
			/**
			  * This allows the animation sampler to cache intermediate interpolation data
			  * and improve the interpolation speed.
			  */
			Index lastSampleIndex;
			
			
			
			
			/// The time value of the last sample.
			Time lastSampleTime;
			
			
			
			
			// The time value of the next sample after the last sample that is before the requested time.
			Time nextSampleTime;
			
			
			
			
			/// The animated value of the last sample.
			AttributeValue lastSampleValue;
			
			
			
			
			/// The animated value of the next sample.
			AttributeValue nextSampleValue;
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Animation Namespace  ****************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_ANIMATION_SAMPLER_H
