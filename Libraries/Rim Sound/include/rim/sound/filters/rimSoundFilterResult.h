/*
 *  rimSoundFilterResult.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/10/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_FILTER_RESULT_H
#define INCLUDE_RIM_SOUND_FILTER_RESULT_H


#include "rimSoundFiltersConfig.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the result of a sound filter processing step.
class SoundFilterResult
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Status Enum Declaration
			
			
			
			
			/// An enum type which describes the different allowed SoundFilter result statuses.
			typedef enum Status
			{
				/// A result status indicating that filter processing was successful.
				/**
				  * The number of samples that were successfully processed is stored in the result.
				  */
				SUCCESS,
				
				/// A result status indicating that filter processing was successful and that the result is silence.
				/**
				  * This status means that all outputs of the given filter processing step should
				  * be interpreted as silent for the number of samples given by the result.
				  * This status can be used to ignore filter outputs that produce no sound and thus
				  * don't need to be processed.
				  */
				SILENCE,
				
				/// A result status indicating that there are no more filter samples to process.
				/**
				  * This status is primarily valid when used by a filter that does not depend on
				  * any input (such as a sound player). It indicates that the end of the given sound
				  * source has been reached and will not produce anymore sound. Therefore, this
				  * status could be used to halt usage of a particular output-only filter once
				  * it has produced all sound it can.
				  */
				END,
				
				/// A result status indicating that an error occurred during processing.
				/**
				  * The number of samples that were successfully processed is stored in the result.
				  * Therefore, a filter can indicate if an error occurred while still producing some
				  * audio.
				  */
				ERROR
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create new result with the END status that has 0 valid output samples.
			RIM_INLINE SoundFilterResult()
				:	status( END ),
					numSamples( 0 )
			{
			}
			
			
			
			
			/// Create new result with the SUCCESS status that has the specified number of valid output samples.
			RIM_INLINE SoundFilterResult( Size newNumSamples )
				:	status( SUCCESS ),
					numSamples( newNumSamples )
			{
			}
			
			
			
			
			/// Create new result with the specified status that has 0 valid output samples.
			RIM_INLINE SoundFilterResult( Status newStatus )
				:	status( newStatus ),
					numSamples( 0 )
			{
			}
			
			
			
			
			/// Create new result with the given status that has the specified number of valid output samples.
			RIM_INLINE SoundFilterResult( Status newStatus, Size newNumSamples )
				:	status( newStatus ),
					numSamples( newNumSamples )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Number of Samples Accessor Method
			
			
			
			
			/// Return the total number of samples that were produced as part of this filter result.
			RIM_INLINE Size getSampleCount() const
			{
				return numSamples;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Result Conversion Operators
			
			
			
			
			/// Convert this filter result to an enum value representing its status.
			RIM_INLINE operator Status () const
			{
				return status;
			}
			
			
			
			
			/// Convert this filter result to a boolean value indicating if the result is a successful one.
			/**
			  * The result statuses that indicate a successful result are SUCCESS and SILENCE.
			  */
			RIM_INLINE operator Bool () const
			{
				return status == SUCCESS || status == SILENCE;
			}
			
			
			
			
			/// Convert this filter result into an integer representing the number of samples that were processed.
			RIM_INLINE operator Size () const
			{
				return numSamples;
			}
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value indicating the type of filter result that this is.
			Status status;
			
			
			
			
			/// The number of valid samples that were processed by the filter.
			Size numSamples;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_FILTER_RESULT_H
