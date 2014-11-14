/*
 *  rimSoundConvolutionFilter.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 4/1/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_CONVOLUTION_FILTER_H
#define INCLUDE_RIM_SOUND_CONVOLUTION_FILTER_H


#include "rimSoundFiltersConfig.h"


#include "rimSoundFilter.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that convolves a stream of audio with an impulse response with no latency.
class ConvolutionFilter : public SoundFilter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new convolution filter with no impulse response.
			ConvolutionFilter();
			
			
			
			
			/// Create a new convolution filter that is an exact copy of another.
			ConvolutionFilter( const ConvolutionFilter& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this convolution filter, releasing all internal resources.
			~ConvolutionFilter();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of another convolution filter to this one.
			ConvolutionFilter& operator = ( const ConvolutionFilter& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Impulse Response Accessor Methods
			
			
			
			
			/// Replace the current impulse response with a new one, reseting the audio processing.
			Bool setImpulseResponse( const SoundBuffer& newImpulseResponse );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Attribute Accessor Methods
			
			
			
			
			/// Return a human-readable name for this convolution filter.
			/**
			  * The method returns the string "Convolution Filter".
			  */
			virtual UTF8String getName() const;
			
			
			
			
			/// Return the manufacturer name of this convolution filter.
			/**
			  * The method returns the string "Headspace Sound".
			  */
			virtual UTF8String getManufacturer() const;
			
			
			
			
			/// Return an object representing the version of this convolution filter.
			virtual SoundFilterVersion getVersion() const;
			
			
			
			
			/// Return an object which describes the category of effect that this filter implements.
			/**
			  * This method returns the value SoundFilterCategory::PITCH.
			  */
			virtual SoundFilterCategory getCategory() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Parameter Accessor Methods
			
			
			
			
			/// Return the total number of generic accessible parameters this filter has.
			virtual Size getParameterCount() const;
			
			
			
			
			/// Get information about the filter parameter at the specified index.
			virtual Bool getParameterInfo( Index parameterIndex, FilterParameterInfo& info ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Property Objects
			
			
			
			
			/// A string indicating the human-readable name of this convolution filter.
			static const UTF8String NAME;
			
			
			
			
			/// A string indicating the manufacturer name of this convolution filter.
			static const UTF8String MANUFACTURER;
			
			
			
			
			/// An object indicating the version of this convolution filter.
			static const SoundFilterVersion VERSION;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Parameter Value Accessor Methods
			
			
			
			
			/// Place the value of the parameter at the specified index in the output parameter.
			virtual Bool getParameterValue( Index parameterIndex, FilterParameter& value ) const;
			
			
			
			
			/// Attempt to set the parameter value at the specified index.
			virtual Bool setParameterValue( Index parameterIndex, const FilterParameter& value );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Stream Reset Method
			
			
			
			
			/// A method which is called whenever the filter's stream of audio is being reset.
			/**
			  * This method allows the filter to reset all parameter interpolation
			  * and processing to its initial state to avoid coloration from previous
			  * audio or parameter values.
			  */
			virtual void resetStream();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Filter Processing Methods
			
			
			
			
			/// Multiply the samples in the input frame by this convolution filter's gain factor and place them in the output frame.
			virtual SoundFilterResult processFrame( const SoundFilterFrame& inputFrame,
													SoundFilterFrame& outputFrame, Size numSamples );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Data Class Declaration
			
			
			
			typedef math::Complex<Float> ComplexSample;
			
			typedef Array< ComplexSample > ComplexChannel;
			
			
			
			typedef math::SIMDFloat SIMDFloat;
			
			
			
			/// A class that encapsulates a partitioned IR stored in frequency domain.
			class FrequencyDomainIR;
			
			
			
			
			/// A class representing a single partition of an FDL.
			class FDLPartition;
			
			
			
			
			/// A class holding the master state for an FDL.
			class FDLState;
			
			
			
			
			/// A class representing a Frequency-domain Delay Line for a particular FFT window size.
			class FDL;
			
			
			
			
			/// A class representing a deadline when one or more FDLs may have output due.
			class FDLDeadline;
			
			
			
			
			/// A class holding the entire state for one convolution instance.
			class ConvolutionState;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			void updateStateIR( ConvolutionState& convolutionState, const SoundBuffer& newIR );
			
			
			
			
			Size initializeFDLs( Size irLength, Size& paddedIRLength );
			
			
			
			
			void renderConvolution( const SoundBuffer& inputBuffer, SoundBuffer& outputBuffer, Size numSamples );
			
			
			
			
			/// A method that runs on a separate thread, processing the FDL with the specified index on demand.
			void processFDLThread( Index fdlIndex );
			
			
			
			
			void renderFDL( Index fdlIndex );
			
			
			
			
			void processFFTFrame( Size numDeadlines );
			
			
			
			
			void processDirectConvolution( Size inputSize );
			
			
			
			
			Index getNextDeadlineForFDL( Index fdlIndex );
			
			
			
			
			RIM_FORCE_INLINE static void complexMultiplyAdd( const ComplexSample* input, const ComplexSample* filter,
															ComplexSample* output, Size number );
			
			
			
			
			RIM_FORCE_INLINE static void complexMultiplySet( const ComplexSample* input, const ComplexSample* filter,
															ComplexSample* output, Size number );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Convolution Paramter Data Members
			
			
			
			
			/// The default number of partitions to use for each FDL.
			static const Size DEFAULT_PARTITIONS_PER_FDL = 4;
			
			
			
			
			/// The maximum number of FDLs there can be.
			static const Size DEFAULT_MAX_FDL_COUNT = 8;
			
			
			
		
			/// The default number of samples for the first IR partition that uses direct convolution.
			static const Size DEFAULT_DIRECT_PARTITION_LENGTH = 32;
			
			
			
			
			/// The default number of samples for the first FDL partition.
			static const Size DEFAULT_MIN_FDL_SIZE = 1024;
			
			
			
			
			/// The default maximum number of samples for an FDL partition.
			static const Size DEFAULT_MAX_FDL_SIZE = 32768;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An array of convolution rendering states for this convolution filter.
			Array<ConvolutionState> states;
			
			
			
			
			/// An array of the master FDL state objects for this renderer.
			ArrayList<FDLState*> fdls;
			
			
			
			
			/// An array of the deadlines, one for each # of FDLs that can finish in a frame (1, 2, ...).
			ArrayList<FDLDeadline*> deadlines;
			
			
			
			
			/// The maximum number of FDLs that are allowed for this convolution renderer.
			Size maxFDLCount;
			
			
			
			
			/// The minimum number of samples allowed for an FDL partition.
			Size minFDLSize;
			
			
			
			
			/// The maximum number of samples allowed for an FDL partition.
			Size maxFDLSize;
			
			
			
			
			/// The number of partitions to use for each FDL.
			Size partitionsPerFDL;
			
			
			
			
			/// A buffer of samples that contains the first partition of the IR in time-domain for direct convolution.
			SoundBuffer directPartition;
			
			
			
			
			/// The length in samples of the initial direct convolution filter.
			Size directPartitionLength;
			
			
			
			
			/// The sample rate of the last sample buffer processed.
			/**
			  * This value is used to detect when the sample rate of the audio stream has changed,
			  * and thus reinitialize the filter processing.
			  */
			SampleRate lastSampleRate;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_CONVOLUTION_FILTER_H
