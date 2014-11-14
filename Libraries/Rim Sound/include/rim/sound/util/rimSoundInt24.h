/*
 *  rimSoundInt24.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_INT_24_H
#define INCLUDE_RIM_SOUND_INT_24_H


#include "rimSoundUtilitiesConfig.h"


//##########################################################################################
//***********************  Start Rim Sound Utilities Namespace  ****************************
RIM_SOUND_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class used to represent a 24-bit integer number.
/**
  * This class helps facilitate operations on 24-bit sound samples
  * by providing methods which pack and unpack a 24-bit sound sample
  * from/to a 32-bit integer sound sample. This class should be exactly
  * 24 bits wide, allowing its use in arrays of samples.
  */
class Int24
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a 24-bit sample equal to 0.
			RIM_FORCE_INLINE Int24()
			{
				data[0] = data[1] = data[2] = 0;
			}
			
			
			
			
			/// Create a 24-bit sample from the specified 32-bit integer sample, discarding the lower bits.
			RIM_FORCE_INLINE Int24( Int32 value )
			{
				pack( value );
			}
			
			
			
			
			/// Cast this 24-bit sample to a 32-bit integer sample.
			RIM_FORCE_INLINE operator Int32 () const
			{
				return unpack();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Unpack this 24-bit sample into a 32-bit integer sample.
			RIM_INLINE Int32 unpack() const
			{
				return Int32(data[0] << 24) | Int32(data[1] << 16) | Int32(data[2] << 8);
			}
			
			
			
			
			/// Pack the specified 32-bit integer sample into this 24-bit sample, discarding the lower bits.
			RIM_INLINE void pack( Int32 value )
			{
				value = math::clamp( value, -Int32(1 << 23), Int32(1 << 23) - 1 );
				
				data[0] = (UInt8)((value & 0xFF000000) >> 24);
				data[1] = (UInt8)((value & 0x00FF0000) >> 16);
				data[2] = (UInt8)((value & 0x0000FF00) >> 8);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An array of 3 bytes representing the 3 bytes of a 24-bit word.
			UInt8 data[3];
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Sound Utilities Namespace  ******************************
RIM_SOUND_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_INT_24_H
