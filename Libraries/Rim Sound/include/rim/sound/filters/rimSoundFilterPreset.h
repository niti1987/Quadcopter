/*
 *  rimSoundFilterPreset.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 6/4/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_FILTER_PRESET_H
#define INCLUDE_RIM_SOUND_FILTER_PRESET_H


#include "rimSoundFiltersConfig.h"


#include "rimSoundFilterState.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a preset configuration for a SoundFilter.
/**
  * A sound filter preset contains a SoundFilterState object which stores the
  * preset configuration, as well as a human-readable name associated with the preset.
  */
class SoundFilterPreset
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new sound filter preset with no name or data stored.
			RIM_INLINE SoundFilterPreset()
				:	state(),
					name()
			{
			}
			
			
			
			
			/// Create a new sound filter preset with the specified name and no data stored.
			RIM_INLINE SoundFilterPreset( const UTF8String& newName )
				:	state(),
					name( newName )
			{
			}
			
			
			
			
			/// Create a new sound filter preset with the specified name and filter state structure.
			RIM_INLINE SoundFilterPreset( const UTF8String& newName, const SoundFilterState& newState )
				:	state( newState ),
					name( newName )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	State Accessor Methods
			
			
			
			
			/// Return a reference to the SoundFilterState object that contains the information for this preset.
			RIM_INLINE SoundFilterState& getState()
			{
				return state;
			}
			
			
			
			
			/// Return a reference to the SoundFilterState object that contains the information for this preset.
			RIM_INLINE const SoundFilterState& getState() const
			{
				return state;
			}
			
			
			
			
			/// Set the SoundFilterState object that contains the information for this preset.
			RIM_INLINE void setState( const SoundFilterState& newState )
			{
				state = newState;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return the human-readable name of this filter preset.
			RIM_INLINE const UTF8String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set the human-readable name of this filter preset.
			RIM_INLINE void setName( const UTF8String& newName )
			{
				name = newName;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object which stores the filter state associated with this preset.
			SoundFilterState state;
			
			
			
			
			/// The name associated with this preset.
			UTF8String name;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_FILTER_PRESET_H
