/*
 *  rimGraphicsAnimationController.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/24/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_ANIMATION_CONTROLLER_H
#define INCLUDE_RIM_GRAPHICS_ANIMATION_CONTROLLER_H


#include "rimGraphicsAnimationConfig.h"


#include "rimGraphicsAnimationTarget.h"
#include "rimGraphicsAnimationTrack.h"
#include "rimGraphicsAnimationSampler.h"


//##########################################################################################
//**********************  Start Rim Graphics Animation Namespace  **************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that controls the animation of a set of animation targets.
/**
  * An animation controller manages a set of named animations that are bound
  * to targets. Multiple animations may affect the same target simultaneously,
  * and can be weighted differently with smooth transitions.
  *
  * The class allows smooth playback control of all animations that are bound to a
  * controller, and automatically handles all animation interpolation.
  */
class AnimationController
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new animation controller with no animation bindings.
			AnimationController();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Animation Update Method
			
			
			
			
			/// Update the animation state for the targets in this controller, advancing by the specified time interval.
			void update( const Time& dt );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Animation Accessor Methods
			
			
			
			
			/// Return the number of animations there are in this controller.
			RIM_INLINE Size getAnimationCount() const
			{
				return animations.getSize();
			}
			
			
			
			
			/// Remove the animation with the specified name from this controller.
			/**
			  * The method returns whether or not the given animation was successfully removed.
			  * In order to have fluid motion when removing an animation, it is recommended
			  * to stop it playing before removing.
			  */
			Bool removeAnimation( const String& animationName );
			
			
			
			
			/// Remove all animation and target bindings from this controller.
			void clearAnimations();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Animation State Accessor Methods
			
			
			
			
			/// Return whether or not the animation with the specified name is playing in this controller.
			Bool isPlaying( const String& animationName ) const;
			
			
			
			
			/// Start playing the animation with the given name and attributes.
			/**
			  * The method returns whether or not the animation was able to be started.
			  */
			Bool play( const String& animationName, Float weight = Float(1), Time fadeInTime = 0,
						Bool looping = false, Float speed = Float(1) );
			
			
			
			
			/// Pause the animation with the specified name, fading out its weight over the given time.
			Bool pause( const String& animationName, Time pauseTime = 0 );
			
			
			
			
			/// Resume the animation with the specified name at its previous time, fading in its weight over the given time.
			Bool resume( const String& animationName, Time resumeTime = 0 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Animation Weight Accessor Methods
			
			
			
			
			/// Return the weight for the animation with the specified name.
			/**
			  * If there is no animation for that name, the method returns a weight of 0.
			  */
			Float getWeight( const String& animationName ) const;
			
			
			
			
			/// Set the weight of the animation with the specified name.
			/**
			  * This method causes the animation to interpolate to the given weight
			  * over the specified interpolation time. This enables smooth transitions
			  * between animations.
			  *
			  * The method returns whether or not the weight was able to be changed.
			  * The method can fail if there is no animation with that name.
			  */
			Bool setWeight( const String& animationName, Float weight, Time interpolationTime = 0 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Target Accessor Methods
			
			
			
			
			/// Return the number of animation targets there are for this controller.
			RIM_INLINE Size getTargetCount() const
			{
				return targets.getSize();
			}
			
			
			
			
			/// Bind the specified target to the given animation track and animation name.
			/**
			  * The method returns whether or not the target and track were able to be
			  * bound. The method can fail if the target or track is NULL, or if they
			  * have different attribute types.
			  */
			Bool bindTarget( const Pointer<AnimationTarget>& target,
							const Pointer<AnimationTrack>& track, const String& animationName );
			
			
			
			
			/// Unbind all tracks from the specified target.
			/**
			  * The method returns whether or not the target was able to be unbound
			  * from this controller.
			  */
			Bool unbindTarget( const Pointer<AnimationTarget>& target );
			
			
			
			
			// Unbind the specified target from the given animation.
			Bool unbindTarget( const Pointer<AnimationTarget>& target, const String& animationName );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations
			
			
			
			
			class AnimationInfo;
			
			
			class AnimationTargetInfo;
			
			
			
			
			/// A class that stores information about a track-to-target binding for an animation.
			class AnimationTrackInfo
			{
				public:
					
					RIM_INLINE AnimationTrackInfo( const Pointer<AnimationTargetInfo>& newTarget,
													const Pointer<AnimationTrack>& newTrack,
													AnimationInfo* newAnimation )
						:	target( newTarget ),
							sampler( newTrack ),
							animation( newAnimation )
					{
					}
					
					
					/// A pointer to the target info for this track.
					Pointer<AnimationTargetInfo> target;
					
					/// A pointer to the animation info that this track info belongs to.
					AnimationInfo* animation;
					
					/// An animation sampler that handles this track's interpolation.
					AnimationSampler sampler;
					
					
			};
			
			
			
			
			/// A class that stores information about a named animation.
			class AnimationInfo
			{
				public:
					
					/// Create a new animation information object with the specified name.
					RIM_INLINE AnimationInfo( const String& newName )
						:	name( newName ),
							currentTime( 0 ),
							length( 0 ),
							speed( 1 ),
							weight( 0 ),
							targetWeight( 0 ),
							weightInterpolationTime( 0 ),
							playbackWeight( 0 ),
							targetPlaybackWeight( 0 ),
							playbackWeightInterpolationTime( 0 ),
							timestamp( 0 ),
							playing( false ),
							looping( false )
					{
					}
					
					
					/// A string that stores the name for this animation.
					String name;
					
					
					/// A list of the tracks and track targets for this animation.
					ArrayList< Pointer<AnimationTrackInfo> > tracks;
					
					
					/// The current playback time in the animation, relative to its start.
					Time currentTime;
					
					
					/// The maximum length of any of this animation's tracks.
					Time length;
					
					
					/// The playback speed multiplier for this animation.
					Float speed;
					
					
					/// The weight given to this animation for its targets.
					Float weight;
					
					
					/// The target weight for this animation that it is interpolating to.
					Float targetWeight;
					
					
					/// The time that the interpolation to the target weight should take.
					Time weightInterpolationTime;
					
					
					/// The playback weight given to this animation for its targets.
					Float playbackWeight;
					
					
					/// The target playback weight for this animation that it is interpolating to.
					Float targetPlaybackWeight;
					
					
					/// The time that the interpolation to the target playback weight should take.
					Time playbackWeightInterpolationTime;
					
					
					/// An integer indicating the current update index.
					Index timestamp;
					
					
					/// A boolean value indicating whether or not this animation is currently playing.
					Bool playing;
					
					
					/// A boolean value indicating whether or not this animation should loop.
					Bool looping;
					
			};
			
			
			
			
			/// A class that stores information about a single animation target.
			class AnimationTargetInfo
			{
				public:
					
					RIM_INLINE AnimationTargetInfo( const Pointer<AnimationTarget>& newTarget )
						:	target( newTarget )
					{
					}
					
					RIM_INLINE Bool removeTrack( const Pointer<AnimationTrackInfo>& track )
					{
						return tracks.removeUnordered( track );
					}
					
					
					/// A pointer to the animation target.
					Pointer<AnimationTarget> target;
					
					/// A list pointers to the tracks that are affecting this target.
					ArrayList< Pointer<AnimationTrackInfo> > tracks;
					
			};
			
			
			
			
			/// A class that enables comparison of animation targets.
			class AnimationTargetComparator
			{
				public:
					
					RIM_INLINE AnimationTargetComparator( const AnimationTarget* newTarget )
						:	target( newTarget )
					{
					}
					
					RIM_INLINE Bool operator == ( const AnimationTargetComparator& other ) const
					{
						return *target == *other.target;
					}
					
					RIM_INLINE Hash getHashCode() const
					{
						return (Hash)PointerInt( target );
					}
					
					const AnimationTarget* target;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < typename T >
			RIM_FORCE_INLINE static void multiplyAdd( T* destination, const T* source, T multiplicand, Size numComponents );
			
			
			
			
			RIM_FORCE_INLINE static void multiplyAdd( AttributeValue& destination, const AttributeValue& source, Float multiplicand );
			
			
			
			
			template < typename T >
			RIM_FORCE_INLINE static void multiply( T* destination, T multiplicand, Size numComponents );
			
			
			
			
			RIM_FORCE_INLINE static void multiply( AttributeValue& destination, Float multiplicand );
			
			
			
			
			template < typename T >
			RIM_FORCE_INLINE static void divide( T* destination, T divisor, Size numComponents );
			
			
			
			
			RIM_FORCE_INLINE static void divide( AttributeValue& destination, Float divisor );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A map containing the animation targets for this controller.
			HashMap< AnimationTargetComparator, Pointer<AnimationTargetInfo> > targets;
			
			
			
			
			/// A map from animation name to animations for this controller.
			HashMap< String, Pointer<AnimationInfo> > animations;
			
			
			
			
			/// An attribute value that is used to accumulate weighted attribute values.
			AttributeValue accumulator;
			
			
			
			
			/// An attribute value that is used to temporarily hold track attribute values.
			AttributeValue tempValue;
			
			
			
			
			/// The global update timestamp for this animation controller.
			Index timestamp;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Animation Namespace  ****************************
RIM_GRAPHICS_ANIMATION_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_ANIMATION_CONTROLLER_H
