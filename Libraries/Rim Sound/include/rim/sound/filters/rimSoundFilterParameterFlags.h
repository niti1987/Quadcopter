/*
 *  rimSoundFilterParameterFlags.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 8/21/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_FILTER_PARAMETER_FLAGS_H
#define INCLUDE_RIM_SOUND_FILTER_PARAMETER_FLAGS_H


#include "rimSoundFiltersConfig.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates the different flags that a sound filter parameter can have.
/**
  * These flags provide boolean information about a certain filter parameter.
  * For example, flags can indicate the read/write status of a parameter. Flags
  * are indicated by setting a single bit of a 32-bit unsigned integer to 1.
  *
  * Enum values for the different flags are defined as members of the class. Typically,
  * the user would bitwise-OR the flag enum values together to produce a final set
  * of set flags.
  */
class FilterParameterFlags
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parameter Type Enum Declaration
			
			
			
			
			/// An enum which specifies the different filter parameter flags.
			typedef enum Enum
			{
				/// A flag set when a parameter's value can be read.
				READ_ACCESS = 1 << 0,
				
				/// A flag set when a parameter's value can be changed.
				WRITE_ACCESS = 1 << 1,
				
				/// A flag set when some of a parameter's values may have special names associated with them.
				NAMED_VALUES = 1 << 2,
				
				/// The flag value when all flags are not set.
				UNDEFINED = 0
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new filter parameter flags object with no flags set.
			RIM_INLINE FilterParameterFlags()
				:	flags( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new filter parameter flags object with the specified flags value.
			RIM_INLINE FilterParameterFlags( UInt32 newFlags )
				:	flags( newFlags )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Integer Cast Operator
			
			
			
			
			/// Convert this filter parameter flags object to an integer value.
			/**
			  * This operator is provided so that the FilterParameterFlags object
			  * can be used as an integer value for bitwise logical operations.
			  */
			RIM_INLINE operator UInt32 () const
			{
				return flags;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Read Status Accessor Methods
			
			
			
			
			/// Return whether or not these parameter flags indicate that read access is enabled.
			RIM_INLINE Bool getIsReadable() const
			{
				return (flags & READ_ACCESS) != UNDEFINED;
			}
			
			
			
			
			/// Set whether or not these parameter flags indicate that read access is enabled.
			RIM_INLINE void setIsReadable( Bool newIsReadable )
			{
				if ( newIsReadable )
					flags |= READ_ACCESS;
				else
					flags &= ~READ_ACCESS;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Write Status Accessor Methods
			
			
			
			
			/// Return whether or not these parameter flags indicate that write access is enabled.
			RIM_INLINE Bool getIsWriteable() const
			{
				return (flags & WRITE_ACCESS) != UNDEFINED;
			}
			
			
			
			
			/// Set whether or not these parameter flags indicate that write access is enabled.
			RIM_INLINE void setIsWriteable( Bool newIsWritable )
			{
				if ( newIsWritable )
					flags |= WRITE_ACCESS;
				else
					flags &= ~WRITE_ACCESS;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Value Status Accessor Methods
			
			
			
			
			/// Return whether or not these parameter flags indicate the parameter has any specially named values.
			RIM_INLINE Bool getHasNamedValues() const
			{
				return (flags & NAMED_VALUES) != UNDEFINED;
			}
			
			
			
			
			/// Set whether or not these parameter flags indicate the parameter has any specially named values.
			RIM_INLINE void setHasNamedValues( Bool newHasNamedValues )
			{
				if ( newHasNamedValues )
					flags |= NAMED_VALUES;
				else
					flags &= ~NAMED_VALUES;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A value indicating the flags that are set for this filter parameter.
			UInt32 flags;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_FILTER_PARAMETER_FLAGS_H
