/*
 *  rimSoundChannelMixMatrix.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 12/13/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_CHANNEL_MIX_MATRIX_H
#define INCLUDE_RIM_SOUND_CHANNEL_MIX_MATRIX_H


#include "rimSoundUtilitiesConfig.h"


#include "rimSoundGain.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which holds a matrix of gain coefficients mapping from one channel configuration to another.
/**
  * This class is used to represent the mapping from one channel configuration to another,
  * where the input configuration with N channels is mapped to the output configuration with
  * M channels using an NxM matrix of linear gain coefficients.
  */
class ChannelMixMatrix
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new channel mix matrix with 0 input and output channels.
			RIM_INLINE ChannelMixMatrix()
				:	gains( NULL ),
					numInputChannels( 0 ),
					numOutputChannels( 0 ),
					gainCapacity( 0 )
			{
			}
			
			
			
			
			/// Create a new channel mix matrix with the specified number of input and output channels.
			RIM_INLINE ChannelMixMatrix( Size newNumInputChannels, Size newNumOutputChannels )
				:	gains( NULL ),
					gainCapacity( 0 )
			{
				this->initializeMatrix( newNumInputChannels, newNumOutputChannels );
			}
			
			
			
			
			/// Create a copy of the specified channel mix matrix object.
			ChannelMixMatrix( const ChannelMixMatrix& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this channel mix matrix object and release its resources.
			RIM_INLINE ~ChannelMixMatrix()
			{
				if ( gains != NULL )
					rim::util::deallocate( gains );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of the specified channel mix matrix to this mix matrix.
			ChannelMixMatrix& operator = ( const ChannelMixMatrix& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Channel Count Accessor Methods
			
			
			
			
			/// Return the current number of input channels for this channel mix matrix.
			RIM_INLINE Size getInputCount() const
			{
				return numInputChannels;
			}
			
			
			
			
			/// Set the number of input channels that this channel mix matrix should have.
			/**
			  * This method reallocates the internal gain matrix if necessary
			  * and causes the values of all previously stored gain values to become
			  * undefined.
			  */
			RIM_INLINE void setInputCount( Size newNumInputChannels )
			{
				this->resizeMatrix( newNumInputChannels, numOutputChannels );
			}
			
			
			
			
			/// Return the current number of output channels for this channel mix matrix.
			RIM_INLINE Size getOutputCount() const
			{
				return numOutputChannels;
			}
			
			
			
			
			/// Set the number of output channels that this channel mix matrix should have.
			/**
			  * This method reallocates the internal gain matrix if necessary
			  * and causes the values of all previously stored gain values to become
			  * undefined.
			  */
			RIM_INLINE void setOutputCount( Size newNumOutputChannels )
			{
				this->resizeMatrix( numInputChannels, newNumOutputChannels );
			}
			
			
			
			
			/// Set the number of input and output channels that this channel mix matrix should have.
			/**
			  * This method reallocates the internal gain matrix if necessary
			  * and causes the values of all previously stored gain values to become
			  * undefined.
			  */
			RIM_INLINE void setSize( Size newNumInputChannels, Size newNumOutputChannels )
			{
				this->resizeMatrix( newNumInputChannels, newNumOutputChannels );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Gain Accessor Methods
			
			
			
			
			/// Return the linear gain associated with the input and output channels at the specified indices.
			RIM_INLINE Gain getGain( Index inputChannelIndex, Index outputChannelIndex ) const
			{
				return gains[inputChannelIndex*numOutputChannels + outputChannelIndex];
			}
			
			
			
			
			/// Set the linear gain associated with the input and output channels at the specified indices.
			RIM_INLINE void setGain( Index inputChannelIndex, Index outputChannelIndex, Gain newGain )
			{
				gains[inputChannelIndex*numOutputChannels + outputChannelIndex] = newGain;
			}
			
			
			
			
			/// Set every input-to-output channel pair to have the specified linear gain value.
			RIM_INLINE void setAllGains( Gain newGain )
			{
				Gain* currentGain = gains;
				const Gain* const gainsEnd = gains + numInputChannels*numOutputChannels;
				
				while ( currentGain != gainsEnd )
				{
					*currentGain = newGain;
					currentGain++;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Helper Methods
			
			
			
			
			/// Set every gain in the channel mix matrix to be 0.
			RIM_INLINE void zero()
			{
				Gain* currentGain = gains;
				const Gain* const gainsEnd = gains + numInputChannels*numOutputChannels;
				
				while ( currentGain != gainsEnd )
				{
					*currentGain = Gain(0);
					currentGain++;
				}
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Initialize the channel mix matrix using the specified number of input and output channels.
			void initializeMatrix( Size newNumInputChannels, Size newNumOutputChannels );
			
			
			
			
			/// Resize the channel mix matrix to the specified number of input and output channels.
			void resizeMatrix( Size newNumInputChannels, Size newNumOutputChannels );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer which points to a 2D matrix of gain values stored in a 1D array.
			Gain* gains;
			
			
			
			
			/// The number of input channels that this channel mix matrix has.
			Size numInputChannels;
			
			
			
			
			/// The number of output channels that this channel mix matrix has.
			Size numOutputChannels;
			
			
			
			
			/// The total size of the allocated gain array.
			Size gainCapacity;
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_CHANNEL_MIX_MATRIX_H
