/*
 *  rimOptional.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 6/7/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_OPTIONAL_H
#define INCLUDE_RIM_OPTIONAL_H


#include "rimLanguageConfig.h"


//##########################################################################################
//***************************  Start Rim Language Namespace  *******************************
RIM_LANGUAGE_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which is used to store a value which may or may not be set.
/**
  * The Optional class is implemented using a pointer to a value which can be
  * optionally NULL. When setting the value of an Optional object, the provided
  * value is copy-constructed and stored internally. Accessing the contents of an
  * Optional object which does not have a value will result in an assertion being raised.
  */
template < typename T >
class Optional
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an optional object whose value is not set.
			RIM_INLINE Optional()
				:	value( NULL )
			{
			}
			
			
			
			
			/// Create an optional object with the specified value.
			/**
			  * @param newValue - the value to use for this Optional object.
			  */
			RIM_INLINE Optional( const T& newValue )
				:	value( util::construct<T>( newValue ) )
			{
			}
			
			
			
			
			/// Create a copy of another Optional object.
			RIM_INLINE Optional( const Optional& other )
			{
				if ( other.value != NULL )
					value = util::construct<T>( *other.value );
				else
					value = NULL;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy an Optional object, destroying any value stored within.
			RIM_INLINE ~Optional()
			{
				if ( value != NULL )
					util::destruct( value );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the value of another Optional object to this object.
			/**
			  * This method creates a copy of the value stored in the other object.
			  * 
			  * @param other - the Optional object whose value should be copied.
			  * @return a reference to this Optional object to allow assignment chaining.
			  */
			RIM_INLINE Optional& operator = ( const Optional& other )
			{
				if ( this != &other )
				{
					if ( value != NULL )
						util::destruct( value );
					
					if ( other.value != NULL )
						value = util::construct<T>( *other.value );
					else
						value = NULL;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Cast Operators
			
			
			
			
			/// Get a reference to the value contained by this Optional object.
			/**
			  * If the value is not set, a debug assertion is raised.
			  * 
			  * @return a reference to the value contained by this Optional object.
			  */
			RIM_INLINE operator T& ()
			{
				RIM_DEBUG_ASSERT_MESSAGE( value != NULL, "Cannot retrieve optional value which is not set." );
				
				return *value;
			}
			
			
			
			
			/// Get a const reference to the value contained by this Optional object.
			/**
			  * If the value is not set, a debug assertion is raised.
			  * 
			  * @return a const reference to the value contained by this Optional object.
			  */
			RIM_INLINE operator const T& () const
			{
				RIM_DEBUG_ASSERT_MESSAGE( value != NULL, "Cannot retrieve optional value which is not set." );
				
				return *value;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value Accessor Methods
			
			
			
			
			/// Get a reference to the value contained by this Optional object.
			/**
			  * If the value is not set, a debug assertion is raised.
			  * 
			  * @return a reference to the value contained by this Optional object.
			  */
			RIM_INLINE T& get()
			{
				RIM_DEBUG_ASSERT_MESSAGE( value != NULL, "Cannot retrieve optional value which is not set." );
				
				return *value;
			}
			
			
			
			
			/// Get a const reference to the value contained by this Optional object.
			/**
			  * If the value is not set, a debug assertion is raised.
			  * 
			  * @return a const reference to the value contained by this Optional object.
			  */
			RIM_INLINE const T& get() const
			{
				RIM_DEBUG_ASSERT_MESSAGE( value != NULL, "Cannot retrieve optional value which is not set." );
				
				return *value;
			}
			
			
			
			
			/// Set the value contained by this Optional object.
			/**
			  * This method replaces any existing value with the new value. isSet() will
			  * always return TRUE after this method exits.
			  * 
			  * @param newValue - the value to which the Optional should be set.
			  */
			RIM_INLINE void set( const T& newValue )
			{
				if ( value != NULL )
					util::destruct( value );
				
				value = util::construct<T>( newValue );
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value-Is-Set State Accessor Method
			
			
			
			
			/// Return whether or not the optional value is set.
			/**
			  * If the value is set, TRUE is returned. Otherwise FALSE
			  * is returned.
			  * 
			  * @return whether or not the optional value is set.
			  */
			RIM_INLINE Bool isSet() const
			{
				return value != NULL;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the optional value. NULL if the value is not set.
			T* value;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Optional Class Void Specialization
//############		
//##########################################################################################
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A 'void' specialization for the Optional class which is provided so that the class works for void types.
template <>
class Optional<void>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create an Optional object which stores a 'void' type.
			RIM_INLINE Optional()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Cast Operators
			
			
			
			
			/// Cast this 'void' Optional object to a void type.
			RIM_INLINE operator void ()
			{
			}
			
			
			
			
			/// Cast this 'void' Optional object to a void type.
			RIM_INLINE operator void () const
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value Accessor Methods
			
			
			
			
			/// Get the 'void' value stored in this Optional object.
			RIM_INLINE void get()
			{
			}
			
			
			
			
			/// Get the 'void' value stored in this Optional object.
			RIM_INLINE void get() const
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value-Is-Set State Accessor Method
			
			
			
			
			/// Return whether or not the 'void' value in this Optional object is set.
			/**
			  * This method always returns TRUE.
			  */
			RIM_INLINE Bool isSet() const
			{
				return true;
			}
			
			
			
			
};




//##########################################################################################
//***************************  End Rim Language Namespace  *********************************
RIM_LANGUAGE_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_OPTIONAL_H
