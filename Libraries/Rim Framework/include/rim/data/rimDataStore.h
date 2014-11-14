/*
 *  rimDataStore.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 6/4/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_DATA_STORE_H
#define INCLUDE_RIM_DATA_STORE_H


#include "rimDataConfig.h"


#include "rimData.h"
#include "rimBasicString.h"
#include "../util/rimHashMap.h"


//##########################################################################################
//*******************************   Start Data Namespace   *********************************
RIM_DATA_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A HashMap-based data structure which associates string keys with values of different types.
/**
  * This class can be used to store arbitrary data in a dictionary format where
  * data values are stored and accessed using a string key. This can be used to
  * easily serialize an object's state to an intermediate format (the DataStore),
  * which can then be easily written to disc in an automated process.
  */
class DataStore
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new empty data store.
			DataStore();
			
			
			
			
			/// Create a copy of the specified data store, copying all of its internal data.
			DataStore( const DataStore& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy the data store object, releasing all internal resources.
			/**
			  * This destructor invalidates all iterators and pointers to internal
			  * data.
			  */
			~DataStore();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of another data store object to this one, replacing all previous contents.
			/**
			  * The contents of the other data store are deep-copied to this data store.
			  * This operator invalidates all iterators and pointers to internal data.
			  */
			DataStore& operator = ( const DataStore& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return the total number of key-value pairs that are stored in this DataStore.
			RIM_INLINE Size getSize() const
			{
				return entries.getSize();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Entry Get Methods
			
			
			
			
			/// Return a pointer to the value stored in this data store associated with the given key.
			/**
			  * This method attempts to access the value for the given key and template data
			  * type. If the key does not have an associated value, or if the requested template
			  * return type is not compatible with the stored value, the method returns a
			  * NULL pointer. Otherwise, if the return value is non-NULL, the method succeeds.
			  */
			template < typename T >
			T* get( const String& key );
			
			
			
			
			/// Return a const pointer to the value stored in this data store associated with the given key.
			/**
			  * This method attempts to access the value for the given key and template data
			  * type. If the key does not have an associated value, or if the requested template
			  * return type is not compatible with the stored value, the method returns a
			  * NULL pointer. Otherwise, if the return value is non-NULL, the method succeeds.
			  */
			template < typename T >
			const T* get( const String& key ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Entry Set Methods
			
			
			
			
			/// Store the specified boolean value, associating it with the key string.
			Bool set( const String& key, Bool value );
			
			
			
			
			/// Store the specified signed 32-bit integer, associating it with the key string.
			Bool set( const String& key, Int32 value );
			
			
			
			
			/// Store the specified unsigned 32-bit integer, associating it with the key string.
			Bool set( const String& key, UInt32 value );
			
			
			
			
			/// Store the specified signed 64-bit integer, associating it with the key string.
			Bool set( const String& key, Int64 value );
			
			
			
			
			/// Store the specified unsigned 64-bit integer, associating it with the key string.
			Bool set( const String& key, UInt64 value );
			
			
			
			
			/// Store the specified 32-bit floating point value, associating it with the key string.
			Bool set( const String& key, Float32 value );
			
			
			
			
			/// Store the specified 64-bit floating point value, associating it with the key string.
			Bool set( const String& key, Float64 value );
			
			
			
			
			/// Store the specified UTF-8 encoded string, associating it with the key string.
			Bool set( const String& key, const UTF8String& string );
			
			
			
			
			/// Store the specified data object, associating it with the key string.
			Bool set( const String& key, const Data& data );
			
			
			
			
			/// Store the specified array of bytes, associating it with the key string.
			/**
			  * The specified number of bytes are copied from of the byte pointer and stored
			  * internally. The method returns whether or not the operation was successful.
			  * The method can fail if the byte pointer is NULL or if the number of bytes to 
			  * store is 0.
			  */
			Bool set( const String& key, const UByte* bytes, Size numBytes );
			
			
			
			
			/// Store the specified DataStore object, associating it with the key string.
			/**
			  * This method copies the specified DataStore object and all of its contents
			  * to an internal location. This allows hierarchical structures to be created
			  * using DataStore objects that can contain other DataStore objects. The method
			  * returns whether or not the operation was successful.
			  */
			Bool set( const String& key, const DataStore& dataStore );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Entry Remove Methods
			
			
			
			
			/// Remove any data stored that is associated with the specified string key.
			/**
			  * The method returns whether or not any stored entry for that key was removed successfully.
			  */
			Bool remove( const String& key );
			
			
			
			
			/// Clear all of the previously stored contents from this data store.
			void clear();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Entry Class Declaration
			
			
			
			
			/// A class used to hold a single entry in a DataStore.
			class Entry;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Return a pointer to the entry associated with the specified key string, or NULL if there was none.
			Entry* getEntry( const String& key );
			
			
			
			
			/// Return a const pointer to the entry associated with the specified key string, or NULL if there was none.
			const Entry* getEntry( const String& key ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A hash map which is used to store the entries of this data store.
			util::HashMap<String,Entry> entries;
			
			
			
			
};




//##########################################################################################
//*******************************   End Data Namespace   ***********************************
RIM_DATA_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_DATA_STORE_H
