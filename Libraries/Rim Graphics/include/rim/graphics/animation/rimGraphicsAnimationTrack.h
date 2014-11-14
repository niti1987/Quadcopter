/*
 *  rimGraphicsAnimationTrack.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/24/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_ANIMATION_TRACK_H
#define INCLUDE_RIM_GRAPHICS_ANIMATION_TRACK_H


#include "rimGraphicsAnimationConfig.h"


#include "rimGraphicsInterpolationType.h"
#include "rimGraphicsAnimationTrackUsage.h"


//##########################################################################################
//**********************  Start Rim Graphics Animation Namespace  **************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that contains a sequence of animation samples.
class AnimationTrack
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an empty animation track.
			AnimationTrack();
			
			
			
			
			/// Create an animation track with the specified buffers, interpolation type, and usage.
			/**
			  * The times and values buffers should be the same length and the time buffer should
			  * be a floating point scalar format.
			  */
			AnimationTrack( const Pointer<GenericBuffer>& newTimes, const Pointer<GenericBuffer>& newValues,
							const InterpolationType& newInterpolationType = InterpolationType::LINEAR,
							const AnimationTrackUsage& newUsage = AnimationTrackUsage::UNDEFINED );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Track Length Accessor Methods
			
			
			
			
			/// Return the length of this animation track in seconds.
			/**
			  * The length is determined by the time value of the last sample point
			  * in the track.
			  */
			Time getLength() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Accessor Methods
			
			
			
			
			/// Return the number of valid samples there are in this animation track.
			/**
			  * The returned value is the minimum size of either the time value
			  * buffer or the animated value buffer.
			  */
			RIM_INLINE Size getSampleCount() const
			{
				return math::min( times.isSet() ? times->getSize() : Size(0),
								values.isSet() ? values->getSize() : Size(0) );
			}
			
			
			
			
			/// Return the time value at the specified sample index in this track.
			/**
			  * The time is returned in the output parameter.
			  * The method returns whether or not the time access operation was successful.
			  * The method can fail if the sample index is invalid or if the time buffer is
			  * not valid.
			  */
			Bool getTime( Index sampleIndex, Time& time ) const;
			
			
			
			
			/// Get the animation value at the specified index in this track.
			/**
			  * The animated value is returned in the output parameter.
			  * The method returns whether or not the value access operation was successful.
			  * The method can fail if the sample index is invalid or if the value buffer is
			  * not valid.
			  */
			Bool getValue( Index sampleIndex, AttributeValue& value ) const;
			
			
			
			
			/// Get the sample at the specified index in this track.
			/**
			  * The time value and animated value are returned in the output parameters.
			  * The method returns whether or not the sample access operation was successful.
			  * The method can fail if the sample index is invalid or if the track buffers are
			  * not valid.
			  */
			Bool getSample( Index sampleIndex, Time& time, AttributeValue& value ) const;
			
			
			
			
			/// Add a new sample to the end of this animation track.
			/**
			  * In order for animation to work correctly, time values must be monotonically
			  * increasing. If this is not the case, the user should call sortSamples() to
			  * sort the samples after the track is finished.
			  *
			  * The new sample is added at the first unused index in the internal time and value buffers.
			  * If one buffer is shorter than the other, the new sample is added at the first
			  * unfilled index in either buffer. If either buffer is NULL, new buffers are created
			  * to hold the sample data of the same type as the specified value.
			  *
			  * The method returns whether or not the sample add operation was successful.
			  * The method can fail if the specified value does not have the same type as
			  * this track.
			  */
			Bool addSample( const Time& time, const AttributeValue& value );
			
			
			
			
			/// Add a new sample to the end of this animation track.
			/**
			  * In order for animation to work correctly, time values must be monotonically
			  * increasing. If this is not the case, the user should call sortSamples() to
			  * sort the samples after the track is finished.
			  *
			  * The new sample is added at the first unused index in the internal time and value buffers.
			  * If one buffer is shorter than the other, the new sample is added at the first
			  * unfilled index in either buffer. If either buffer is NULL, new buffers are created
			  * to hold the sample data of the same type as the specified value.
			  *
			  * The method returns whether or not the sample add operation was successful.
			  * The method can fail if the specified value does not have the same type as
			  * this track.
			  */
			template < typename ValueType >
			RIM_NO_INLINE Bool addSample( const Time& time, const ValueType& value )
			{
				AttributeType::check<ValueType>();
				
				// Create a new value buffer if necessary.
				if ( values.isNull() )
					values = Pointer<GenericBuffer>::construct( AttributeType::get<ValueType>(), 8 );
				else if ( values->getAttributeType() != AttributeType::get<ValueType>() )
					return false;
				
				// Create a new time buffer if necessary.
				if ( times.isNull() )
					times = Pointer<GenericBuffer>::construct( AttributeType::get<Float>(), 8 );
				
				// Determine the index where the new sample should be placed.
				const Size index = this->getSampleCount();
				
				// Add the time value.
				if ( times->getSize() == index )
					times->add( Float(time) );
				else
					times->set( index, Float(time) );
				
				// Add the animated value.
				if ( values->getSize() == index )
					values->add( value );
				else
					values->set( index, value );
				
				return true;
			}
			
			
			
			
			/// Remove the sample at the specified index in this animation track.
			/**
			  * This method copies all samples after that index to the previous
			  * index. The method returns whether or not the sample at that index was able to
			  * be removed.
			  */
			Bool removeSample( Index sampleIndex );
			
			
			
			
			/// Clear all samples from this animation track's buffers.
			void clearSamples();
			
			
			
			
			/// Ensure that the samples are sorted by increasing time value if they are not already.
			void sortSamples();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Usage Accessor Methods
			
			
			
			
			/// Return an object that indicates the semantic usage of this animation track.
			RIM_INLINE const AnimationTrackUsage& getUsage() const
			{
				return usage;
			}
			
			
			
			
			/// Set the semantic usage of this animation track.
			RIM_INLINE void setUsage( const AnimationTrackUsage& newUsage )
			{
				usage = newUsage;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Interpolation Type Accessor Methods
			
			
			
			
			/// Return an object that indicates the interpolation type of this animation track.
			RIM_INLINE const InterpolationType& getInterpolationType() const
			{
				return interpolationType;
			}
			
			
			
			
			/// Set the interpolation type of this animation track.
			RIM_INLINE void setInterpolationType( const InterpolationType& newInterpolationType )
			{
				interpolationType = newInterpolationType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Type Accessor Methods
			
			
			
			
			/// Return an object that indicates the type of attributes that this track contains.
			RIM_INLINE const AttributeType& getAttributeType() const
			{
				return values.isSet() ? values->getAttributeType() : AttributeType::UNDEFINED;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return the name of this animation track.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set the name of this animation track.
			RIM_INLINE void setName( const String& newName )
			{
				name = newName;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Track Status Accessor Methods
			
			
			
			
			/// Return whether or not this animation track has a valid state.
			/**
			  * In order for a track to be valid, it must have sequences
			  * of times and values, where the time values are scalar and have
			  * a 1 to 1 correspondence with the animated values.
			  */
			Bool isValid() const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < typename TimeType >
			void sortBuffers();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A string representing the human-readable name of this animation track.
			String name;
			
			
			
			
			/// An enum object indicating the semantic usage of this animation track.
			AnimationTrackUsage usage;
			
			
			
			
			/// An enum object indicating how this track should be interpolated.
			InterpolationType interpolationType;
			
			
			
			
			/// A pointer to a buffer of time samples for this animation track.
			Pointer<GenericBuffer> times;
			
			
			
			
			/// A pointer to a buffer of animated values for this track.
			Pointer<GenericBuffer> values;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Animation Namespace  ****************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_ANIMATION_TRACK_H
