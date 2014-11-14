/*
 *  rimSoundFilterSeries.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_FILTER_SERIES_H
#define INCLUDE_RIM_SOUND_FILTER_SERIES_H


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
/// A class which wraps a set of series-connected sound filters.
/**
  * This class is a convenience class which allows the user to quickly connect
  * a series of sound filters. This class is analogous to a 'channel strip' in
  * most digital audio workstations.
  *
  * Note that this class does not own any of the filters that it connects. It merely
  * provides an easy way to process them in series. One should store the filter
  * objects at some other location and pass pointers to this class. The behavior
  * is undefined if any filter is destroyed while a filter series still has a reference
  * to it.
  *
  * For filters that have multiple inputs or outputs, the filter series uses a 1 to 1
  * matching for filter inputs/outputs. For instance, if a 2 output filter is followed by
  * a 4-input filter, the two outputs of the first filter are sent to the first
  * two inputs of the second filter. Any non-overlapping inputs or outputs are simply ignored.
  * Use FilterGraph instead if you need complex routing capabilities.
  */
class FilterSeries : public SoundFilter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default sound filter series with no connected sound filters.
			FilterSeries();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Accessor Methods
			
			
			
			
			/// Return the total number of sound filters that are a part of this filter series.
			RIM_INLINE Size getFilterCount() const
			{
				return filters.getSize();
			}
			
			
			
			
			/// Return a pointer to the sound filter at the specified index within this filter series.
			/**
			  * If the specified filter index is not valid, NULL is returned.
			  */
			SoundFilter* getFilter( Index filterIndex );
			
			
			
			
			/// Replace the filter in this filter series at the specified index.
			/**
			  * If the specified filter index is invalid or the new filter pointer is NULL,
			  * FALSE is returned and the filter series is unchanged. Otherwise, the new
			  * filter replaces the old one and TRUE is returned.
			  */
			Bool setFilter( Index filterIndex, SoundFilter* newFilter );
			
			
			
			
			/// Add a new filter to the end of this sound filter series.
			/**
			  * If the new filter pointer is NULL, the method fails and returns
			  * FALSE. Otherwise, the method adds the new filter to the end of the
			  * filter series and returns TRUE.
			  */
			Bool addFilter( SoundFilter* newFilter );
			
			
			
			
			/// Insert the specified filter at the given index in this filter series.
			/**
			  * If the new filter pointer is NULL, the method fails and returns FALSE.
			  * Otherwise, the filter is inserted in the filter series at the specified
			  * index and TRUE is returned.
			  */
			Bool insertFilter( Index filterIndex, SoundFilter* newFilter );
			
			
			
			
			/// Remove the filter at the specified index from this filter series.
			/**
			  * If the specified index is invalid, the method doesn't modify the
			  * filter series and returns FALSE. Otherwise, the filter at that index
			  * is removed and TRUE is returned.
			  *
			  * Removing a filter at any given index causes the index of all filters
			  * with larger indices to be shifted back an index.
			  */
			Bool removeFilter( Index filterIndex );
			
			
			
			
			/// Remove all filters from this sound filter series.
			void clearFilters();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Input and Output Accessor Methods
			
			
			
			
			/// Return a human-readable name of the sound filter series input at the specified index.
			/**
			  * This method returns the name of the input at the specified index in the first
			  * filter in the series.
			  */
			virtual UTF8String getInputName( Index inputIndex ) const;
			
			
			
			
			/// Return a human-readable name of the sound filter series output at the specified index.
			/**
			  * This method returns the name of the output at the specified index in the last
			  * filter in the series.
			  */
			virtual UTF8String getOutputName( Index outputIndex ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Attribute Accessor Methods
			
			
			
			
			/// Return a human-readable name for this sound filter series.
			/**
			  * The method returns the string "Sound Filter Series".
			  */
			virtual UTF8String getName() const;
			
			
			
			
			/// Return the manufacturer name of this sound filter series.
			/**
			  * The method returns the string "Headspace Sound".
			  */
			virtual UTF8String getManufacturer() const;
			
			
			
			
			/// Return an object representing the version of this sound filter series.
			virtual SoundFilterVersion getVersion() const;
			
			
			
			
			/// Return an object which describes the category of effect that this filter implements.
			/**
			  * This method returns the value SoundFilterCategory::ROUTING.
			  */
			virtual SoundFilterCategory getCategory() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Property Objects
			
			
			
			
			/// A string indicating the human-readable name of this sound filter series.
			static const UTF8String NAME;
			
			
			
			
			/// A string indicating the manufacturer name of this sound filter series.
			static const UTF8String MANUFACTURER;
			
			
			
			
			/// An object indicating the version of this sound filter series.
			static const SoundFilterVersion VERSION;
			
			
			
			
	private:
		
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
		//******	Private Filter Processing Method
			
			
			
			
			/// Process each filter in the series, passing audio data from one filter to the next.
			virtual SoundFilterResult processFrame( const SoundFilterFrame& inputFrame,
													SoundFilterFrame& outputFrame, Size numSamples );
			
			
			
			
			
			/// Get another temporary buffer from the global pool, save the handle, and return a pointer to the buffer.
			RIM_INLINE SoundBuffer* getTempBuffer( Size numChannels, Size numSamples, SampleRate sampleRate )
			{
				tempBuffers.add( SharedBufferPool::getGlobalBuffer( numChannels, numSamples, sampleRate ) );
				
				return &tempBuffers.getLast().getBuffer();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the filters that make up this series connection of filters.
			ArrayList<SoundFilter*> filters;
			
			
			
			
			/// A list of the current set of shared temporary sound buffers in use by this filter series.
			ArrayList<SharedSoundBuffer> tempBuffers;
			
			
			
			
			/// A persistent (to avoid buffer array reallocations) filter frame for intermediate sound data.
			SoundFilterFrame tempFrame1;
			
			
			
			
			/// A second persistent (to avoid buffer array reallocations) filter frame for intermediate sound data.
			SoundFilterFrame tempFrame2;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_FILTER_SERIES_H
