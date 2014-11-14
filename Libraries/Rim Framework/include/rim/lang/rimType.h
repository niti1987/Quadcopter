/*
 *  rimType.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 10/31/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_TYPE_H
#define INCLUDE_RIM_TYPE_H


#include <typeinfo>


#include "rimLanguageConfig.h"


#include "../data/rimBasicString.h"


//##########################################################################################
//***************************  Start Rim Language Namespace  *******************************
RIM_LANGUAGE_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


using rim::data::String;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a C++ type.
/**
  * The class consists of a string uniquely identifying the type
  * it represents. This string is retrieved from a C++ type_info
  * object. This allows a C++ type to be used as a first-class object.
  * Type objects can be created from both a statically defined type
  * via the templatized method Type::of<>() or from the dynamic type
  * of an object via a constructor or the Type::of() method. In order
  * for the dynamic type of an object to be determined, at least one class
  * in its inheritance hierarchy must have a virtual method.
  */
class Type
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new empty type object.
			RIM_INLINE Type()
				:	typeString()
			{
			}
			
			
			
			
			/// Create a type object from the type of the parameter.
			template < typename T >
			RIM_INLINE Type( const T& object )
				:	typeString( unmangle( typeid(object).name() ) )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Factory Methods
			
			
			
			
			/// Get a type object representing the templatized type of this method.
			template < typename T >
			RIM_INLINE static Type of()
			{
				return Type( typeid(T).name() );
			}
			
			
			
			
			/// Get a type object representing the type of the parameter.
			template < typename T >
			RIM_INLINE static Type of( const T& object )
			{
				return Type( object );
			}
			
			
			
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Type String Accessor Methods
			
			
			
			
			/// Return a string representing the unique name of this type.
			RIM_INLINE operator const String& () const
			{
				return typeString;
			}
			
			
			
			
			/// Return a string representing the unique name of this type.
			RIM_INLINE const String& toString() const
			{
				return typeString;
			}
			
			
			
			
			/// Return a string representing the unique name of this type.
			RIM_INLINE const String& getName() const
			{
				return typeString;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	ID Accessor Methods
			
			
			
			
			/// Return an unsigned integer for this type. Different types may have the same ID.
			RIM_INLINE Hash getID() const
			{
				return typeString.getHashCode();
			}
			
			
			
			
			/// Return an integer hash code for this type.
			RIM_INLINE Hash getHashCode() const
			{
				return typeString.getHashCode();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Equality Comparison Operators
			
			
			
			
			/// Return whether or not this type is equal to another.
			RIM_INLINE Bool operator == ( const Type& type ) const
			{
				return typeString == type.typeString;
			}
			
			
			
			
			/// Return whether or not this type is not equal to another.
			RIM_INLINE Bool operator != ( const Type& type ) const
			{
				return typeString != type.typeString;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructor
			
			
			
			
			/// Create a new type object from a type string and boolean attributes.
			RIM_INLINE Type( const char* newTypeString )
				:	typeString( unmangle( newTypeString ) )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Unmangle the specified raw type name.
			/**
			  * If the method fails, the original string may be returned.
			  */
			static String unmangle( const char* mangledName );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A string representing the type, implementation defined.
			String typeString;
			
			
			
};




//##########################################################################################
//***************************  End Rim Language Namespace  *********************************
RIM_LANGUAGE_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_TYPE_H
