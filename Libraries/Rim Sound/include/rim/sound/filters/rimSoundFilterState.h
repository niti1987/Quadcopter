/*
 *  rimSoundFilterState.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 6/4/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_FILTER_STATE_H
#define INCLUDE_RIM_SOUND_FILTER_STATE_H


#include "rimSoundFiltersConfig.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the entire serialized state of a SoundFilter instance.
/**
  * This class is a thin wrapper of a rim::data::DataStore object and is used
  * as a dictionary to store common types of filter data (numbers, strings, bytes,
  * and other DataStore objects).
  */
class SoundFilterState
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new sound filter state object with no data stored in it.
			RIM_INLINE SoundFilterState()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Data Accessor Methods
			
			
			
			
			/// Return the total number of key-value pairs that are stored in this filter state.
			RIM_INLINE Size getSize() const
			{
				return state.getSize();
			}
			
			
			
			
			/// Get a pointer to the value stored for the specified key string.
			/**
			  * The types of allowed values are: Bool, Int32, UInt32, Int64, UInt64, Float32, Float64,
			  * UTF8String, Data, and DataStore. This method is a thin wrapper around the
			  * DataStore::get() family of methods. See that class's documentation for more info.
			  * The method returns NULL if there is no value for the given key, or if
			  * the stored value has an incompatible type with the requested template type.
			  */
			template < typename V, typename K >
			RIM_INLINE V* get( const K& key )
			{
				return state.get<V>( String(key) );
			}
			
			
			
			
			/// Get a const pointer to the value stored for the specified key string.
			/**
			  * The types of allowed values are: Int32, UInt32, Int64, UInt64, Float32, Float64,
			  * UTF8String, Data, and DataStore. This method is a thin wrapper around the
			  * DataStore::get() family of methods. See that class's documentation for more info.
			  * The method returns NULL if there is no value for the given key, or if
			  * the stored value has an incompatible type with the requested template type.
			  */
			template < typename V, typename K >
			RIM_INLINE const V* get( const K& key ) const
			{
				return state.get<V>( String(key) );
			}
			
			
			
			
			/// Set the filter state to have a mapping from the specified key string to a template data value.
			/**
			  * The types of allowed values are: Int32, UInt32, Int64, UInt64, Float32, Float64,
			  * UTF8String, Data, and DataStore. This method is a thin wrapper around the
			  * DataStore::set() family of methods. See that class's documentation for more info.
			  * The method returns whether or not the operation was successful.
			  */
			template < typename K, typename V >
			RIM_INLINE Bool set( const K& key, const V& value )
			{
				return state.set( String(key), value );
			}
			
			
			
			
			/// Remove the entry with the specified string key and return whether or not anything was removed.
			template < typename K >
			RIM_INLINE Bool remove( const K& key )
			{
				return state.remove( String(key) );
			}
			
			
			
			
			/// Clear all stored data from this filter state, resulting in an empty state object.
			RIM_INLINE void clear()
			{
				state.clear();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Data Store Accessor Methods
			
			
			
			
			/// Return a reference to the DataStore object which contains this state's data entries.
			RIM_INLINE const DataStore& getDataStore() const
			{
				return state;
			}
			
			
			
			
			/// Replace this filter state's internal data store with the specified data store, copying all entries.
			RIM_INLINE void setDataStore( const DataStore& dataStore )
			{
				state = dataStore;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A DataStore object which stores the entire state of a SoundFilter instance.
			DataStore state;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_FILTER_STATE_H
