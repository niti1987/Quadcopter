/*
 *  rimAny.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 1/22/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ANY_H
#define INCLUDE_RIM_ANY_H


#include "rimLanguageConfig.h"


//##########################################################################################
//***************************  Start Rim Language Namespace  *******************************
RIM_LANGUAGE_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which is able to store and retrieve a value of any arbitrary type in an opaque manner.
class Any
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create an Any object which has a NULL value.
			RIM_INLINE Any()
				:	value( NULL )
			{
			}
			
			
			
			
			/// Create an Any object which stores a copy of the specified templated type.
			template < typename T >
			RIM_INLINE Any( const T& value )
				:	value( util::construct<Storage<T> >( value ) )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Copy Constructors
			
			
			
			
			/// Make a deep copy of the specified Any object, copying its internal value.
			RIM_INLINE Any( const Any& other )
				:	value( other.value ? other.value->copy() : NULL )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operators
			
			
			
			
			/// Copy the value from another Any object into this Any, replacing the current value.
			RIM_INLINE Any& operator = ( const Any& other )
			{
				if ( this != &other )
				{
					if ( value != NULL )
						util::destruct( value );
					
					other.value ? other.value->copy() : NULL;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			/// Destroy an Any object and deallocate its internal storage.
			RIM_INLINE ~Any()
			{
				if ( value )
					util::destruct( value );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value Accessor Methods
			
			
			
			
			/// Access this Any's value and place it in the output parameter.
			/**
			  * If the Any object has a NULL value, or if the value's type does not
			  * match that of the output parameter, FALSE is returned and no value is
			  * retrieved. Otherwise, the method succeeds and TRUE is returned.
			  */
			template < typename T >
			RIM_INLINE Bool getValue( T& output ) const
			{
				const T* pointer;
				
				if ( !value || !(pointer = value->getValue<T>()) )
					return false;
				
				output = *pointer;
				return true;
			}
			
			
			
			
			/// Set this Any object to have a new value.
			template < typename T >
			RIM_INLINE void setValue( const T& newValue )
			{
				if ( value )
					util::destruct( value );
				
				value = util::construct< Storage<T> >( newValue );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value Pointer Accessor Methods
			
			
			
			
			/// Return a pointer to the value stored by this Any object.
			/**
			  * If the specified template type is not the same as the stored value,
			  * NULL is returned.
			  */
			template < typename T >
			RIM_INLINE T* getPointer()
			{
				return value ? value->getValue<T>() : NULL;
			}
			
			
			
			
			/// Return a const pointer to the value stored by this Any object.
			/**
			  * If the specified template type is not the same as the stored value,
			  * NULL is returned.
			  */
			template < typename T >
			RIM_INLINE const T* getPointer() const
			{
				return value ? value->getValue<T>() : NULL;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Equality Operators
			
			
			
			
			/// Compare this array to another array for equality.
			/**
			  * If this array has the same size as the other array and
			  * has the same elements, the arrays are equal and TRUE is
			  * returned. Otherwise, the arrays are not equal and FALSE is returned.
			  */
			RIM_INLINE Bool operator == ( const Any& other ) const
			{
				// Catch NULL values or copies that shouldn't happen.
				if ( value == other.value )
					return true;
				
				return value->equals( *other.value );
			}
			
			
			
			
			/// Compare this array to another array for inequality.
			/**
			  * If this array has a different size than the other array or
			  * has different elements, the arrays are not equal and TRUE is
			  * returned. Otherwise, the arrays are equal and FALSE is returned.
			  */
			RIM_INLINE Bool operator != ( const Any& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Any Status Accessor Methods
			
			
			
			
			/// Return whether or not this Any object's internal array is NULL.
			RIM_INLINE Bool isNull() const
			{
				return value == NULL;
			}
			
			
			
			
			/// Get whether or not this Any object's internal array is not NULL.
			RIM_INLINE Bool isSet() const
			{
				return value != NULL;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// The base class for classes that store objects of an arbitrary type.
			class StorageBase
			{
				public:
					
					virtual ~StorageBase()
					{
					}
					
					
					/// Construct and return a copy of this storage object, creating a new value.
					virtual StorageBase* copy() const = 0;
					
					
					/// Return whether or not this object's value is equal to another.
					virtual Bool equals( const StorageBase& other ) const = 0;
					
					
					template < typename T >
					RIM_INLINE T* getValue();
					
					
					template < typename T >
					RIM_INLINE const T* getValue() const;
					
					
			};
			
			
			
			
			/// A class which is used to store arbitrarily-typed values in an opaque manner.
			template < typename T >
			class Storage : public StorageBase
			{
				public:
					
					/// Create a new storage object which copies the specified value.
					RIM_FORCE_INLINE Storage( const T& newValue )
						:	value( newValue )
					{
					}
					
					
					/// Destroy this storage object.
					RIM_INLINE ~Storage()
					{
					}
					
					
					/// Construct and return a copy of this storage object, creating a new value.
					virtual StorageBase* copy() const
					{
						return util::construct< Storage<T> >( value );
					}
					
					
					/// Return whether or not this object's value is equal to another.
					virtual Bool equals( const StorageBase& other ) const
					{
						const Storage<T>* concreteObject = dynamic_cast<const Storage<T>*>( &other );
						
						if ( concreteObject )
							return value == concreteObject->value;
						else
							return false;
					}
					
					
					/// The actual object which is stored by an Any object.
					T value;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the object which stores this Any's value.
			StorageBase* value;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Storage Value Accessor Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
T* Any::StorageBase:: getValue()
{
	Storage<T>* derived = dynamic_cast<Storage<T>*>( this );
	
	if ( derived )
		return &derived->value;
	else
		return NULL;
}




template < typename T >
const T* Any::StorageBase:: getValue() const
{
	const Storage<T>* derived = dynamic_cast<const Storage<T>*>( this );
	
	if ( derived )
		return &derived->value;
	else
		return NULL;
}




//##########################################################################################
//***************************  End Rim Language Namespace  *********************************
RIM_LANGUAGE_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ANY_H
