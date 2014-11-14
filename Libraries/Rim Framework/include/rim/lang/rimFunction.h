/*
 *  rimFunction.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 6/22/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_FUNCTION_H
#define INCLUDE_RIM_FUNCTION_H


#include "rimLanguageConfig.h"


#include "detail/rimFunctionDefinition.h"
#include "detail/rimMemberFunction.h"


//##########################################################################################
//***************************  Start Rim Language Namespace  *******************************
RIM_LANGUAGE_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




/// Prototype for the function object template class.
template < typename Signature >
class Function;




//##########################################################################################
//##########################################################################################
//############		
//############		Function Object With 0 Parameters Class Definition
//############		
//##########################################################################################
//##########################################################################################




/// Specialization of the function template class for a method with 0 parameters.
template < typename R >
class Function< R () >
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			/// The return type of this function object.
			typedef R ReturnType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default function object with a NULL function pointer.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE Function()
				:	staticFunctionPointer( NULL ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified non-member function pointer.
			RIM_INLINE Function( R (*functionPointer)() )
				:	staticFunctionPointer( functionPointer ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)(),
								ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and const member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)() const,
								const ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a copy of the specified function object.
			RIM_INLINE Function( const Function& other )
				:	isMember( other.isMember )
			{
				if ( other.isMember )
					memberFunction = other.memberFunction->clone();
				else
					staticFunctionPointer = other.staticFunctionPointer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this function object, releasing all internal state.
			RIM_INLINE ~Function()
			{
				if ( isMember )
					util::destruct( memberFunction );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of one function object to another.
			RIM_INLINE Function& operator = ( const Function& other )
			{
				if ( this != &other )
				{
					// Clean up the old member function if there was one.
					if ( isMember )
						util::destruct( memberFunction );
					
					// Copy the other function pointer.
					if ( isMember = other.isMember )
						memberFunction = other.memberFunction->clone();
					else
						staticFunctionPointer = other.staticFunctionPointer;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Call Method
			
			
			
			
			/// Call this function and return its return value.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE ReturnType operator () () const
			{
				if ( isMember )
					return (*memberFunction)();
				else
				{
					RIM_DEBUG_ASSERT_MESSAGE( staticFunctionPointer == NULL, "Cannot call NULL function object." );
					
					return staticFunctionPointer();
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function references the same function as another function object.
			RIM_INLINE Bool operator == ( const Function& other ) const
			{
				if ( isMember )
					return other.isMember && memberFunction->equals( *other.memberFunction );
				else
					return !other.isMember && staticFunctionPointer == other.staticFunctionPointer;
			}
			
			
			
			
			/// Return whether or not this function references a different function as onother function object.
			RIM_INLINE Bool operator != ( const Function& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is NULL.
			/**
			  * If this method returns TRUE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isNull() const
			{
				return !isMember && staticFunctionPointer == NULL;
			}
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is not NULL.
			/**
			  * If this method returns FALSE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isSet() const
			{
				return isMember || staticFunctionPointer != NULL;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < typename SignatureType, typename ObjectType >
			RIM_INLINE void constructMemberFunction( SignatureType functionPointer, ObjectType* object )
			{
				if ( object == NULL || functionPointer == NULL )
				{
					staticFunctionPointer = NULL;
					isMember = false;
				}
				else
				{
					memberFunction = util::construct<internal::MemberFunction<
									ObjectType, SignatureType, R> >( functionPointer, object );
					isMember = true;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A union which saves space when storing the static and member function pointers.
			union
			{
				/// A non-member function pointer to use when the function object represents a non-member function.
				R (*staticFunctionPointer)();
				
				
				/// A pointer to an object which wraps a member function when this function is a member function.
				internal::FunctionDefinition<R>* memberFunction;
			};
			
			
			
			
			/// A boolean value indicating whether or not this function object is a member function.
			Bool isMember;
			
			
			
};




template < typename R >
RIM_INLINE Function<R ()> bind( R (*functionPointer)() )
{
	return Function<R ()>( functionPointer );
}




template < typename ObjectType, typename ObjectType2, typename R >
RIM_INLINE Function<R ()> bind( R (ObjectType2::*functionPointer)(),
								ObjectType* objectPointer )
{
	return Function<R ()>( functionPointer, objectPointer );
}




template < typename ObjectType, typename ObjectType2, typename R >
RIM_INLINE Function<R ()> bind( R (ObjectType2::*functionPointer)() const,
								const ObjectType* objectPointer )
{
	return Function<R ()>( functionPointer, objectPointer );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Function Object With 1 Parameter Class Definition
//############		
//##########################################################################################
//##########################################################################################




/// Specialization of the function template class for a method with 1 parameter.
template < typename R, typename T1 >
class Function< R ( T1 ) >
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			/// The return type of this function object.
			typedef R ReturnType;
			
			
			/// The type of the first parameter of this function object.
			typedef T1 ParameterType1;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default function object with a NULL function pointer.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE Function()
				:	staticFunctionPointer( NULL ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified non-member function pointer.
			RIM_INLINE Function( R (*functionPointer)( T1 ) )
				:	staticFunctionPointer( functionPointer ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1 ),
								ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and const member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1 ) const,
								const ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a copy of the specified function object.
			RIM_INLINE Function( const Function& other )
				:	isMember( other.isMember )
			{
				if ( other.isMember )
					memberFunction = other.memberFunction->clone();
				else
					staticFunctionPointer = other.staticFunctionPointer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this function object, releasing all internal state.
			RIM_INLINE ~Function()
			{
				if ( isMember )
					util::destruct( memberFunction );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of one function object to another.
			RIM_INLINE Function& operator = ( const Function& other )
			{
				if ( this != &other )
				{
					// Clean up the old member function if there was one.
					if ( isMember )
						util::destruct( memberFunction );
					
					// Copy the other function pointer.
					if ( isMember = other.isMember )
						memberFunction = other.memberFunction->clone();
					else
						staticFunctionPointer = other.staticFunctionPointer;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Call Method
			
			
			
			
			/// Call this function and return its return value.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE ReturnType operator () ( T1 p1 ) const
			{
				if ( isMember )
					return (*memberFunction)( p1 );
				else
				{
					RIM_DEBUG_ASSERT_MESSAGE( staticFunctionPointer == NULL, "Cannot call NULL function object." );
					
					return staticFunctionPointer( p1 );
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function references the same function as another function object.
			RIM_INLINE Bool operator == ( const Function& other ) const
			{
				if ( isMember )
					return other.isMember && memberFunction->equals( *other.memberFunction );
				else
					return !other.isMember && staticFunctionPointer == other.staticFunctionPointer;
			}
			
			
			
			
			/// Return whether or not this function references a different function as onother function object.
			RIM_INLINE Bool operator != ( const Function& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is NULL.
			/**
			  * If this method returns TRUE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isNull() const
			{
				return !isMember && staticFunctionPointer == NULL;
			}
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is not NULL.
			/**
			  * If this method returns FALSE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isSet() const
			{
				return isMember || staticFunctionPointer != NULL;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < typename SignatureType, typename ObjectType >
			RIM_INLINE void constructMemberFunction( SignatureType functionPointer, ObjectType* object )
			{
				if ( object == NULL || functionPointer == NULL )
				{
					staticFunctionPointer = NULL;
					isMember = false;
				}
				else
				{
					memberFunction = util::construct<internal::MemberFunction<
									ObjectType, SignatureType, R, T1> >( functionPointer, object );
					isMember = true;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A union which saves space when storing the static and member function pointers.
			union
			{
				/// A non-member function pointer to use when the function object represents a non-member function.
				R (*staticFunctionPointer)( T1 );
				
				
				/// A pointer to an object which wraps a member function when this function is a member function.
				internal::FunctionDefinition<R,T1>* memberFunction;
			};
			
			
			
			
			/// A boolean value indicating whether or not this function object is a member function.
			Bool isMember;
			
			
			
};




template < typename R, typename T1 >
RIM_INLINE Function<R ( T1 )> bind( R (*functionPointer)( T1 ) )
{
	return Function<R ( T1 )>( functionPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1 >
RIM_INLINE Function<R ( T1 )> bind( R (ObjectType2::*functionPointer)( T1 ),
								ObjectType* objectPointer )
{
	return Function<R ( T1 )>( functionPointer, objectPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1 >
RIM_INLINE Function<R ( T1 )> bind( R (ObjectType2::*functionPointer)( T1 ) const,
								const ObjectType* objectPointer )
{
	return Function<R ( T1 )>( functionPointer, objectPointer );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Function Object With 2 Parameters Class Definition
//############		
//##########################################################################################
//##########################################################################################




/// Specialization of the function template class for a method with 2 parameters.
template < typename R, typename T1, typename T2 >
class Function< R ( T1, T2 ) >
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			/// The return type of this function object.
			typedef R ReturnType;
			
			
			/// The type of the first parameter of this function object.
			typedef T1 ParameterType1;
			
			
			/// The type of the second parameter of this function object.
			typedef T2 ParameterType2;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default function object with a NULL function pointer.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE Function()
				:	staticFunctionPointer( NULL ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified non-member function pointer.
			RIM_INLINE Function( R (*functionPointer)( T1, T2 ) )
				:	staticFunctionPointer( functionPointer ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2 ),
								ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and const member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2 ) const,
								const ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a copy of the specified function object.
			RIM_INLINE Function( const Function& other )
				:	isMember( other.isMember )
			{
				if ( other.isMember )
					memberFunction = other.memberFunction->clone();
				else
					staticFunctionPointer = other.staticFunctionPointer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this function object, releasing all internal state.
			RIM_INLINE ~Function()
			{
				if ( isMember )
					util::destruct( memberFunction );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of one function object to another.
			RIM_INLINE Function& operator = ( const Function& other )
			{
				if ( this != &other )
				{
					// Clean up the old member function if there was one.
					if ( isMember )
						util::destruct( memberFunction );
					
					// Copy the other function pointer.
					if ( isMember = other.isMember )
						memberFunction = other.memberFunction->clone();
					else
						staticFunctionPointer = other.staticFunctionPointer;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Call Method
			
			
			
			
			/// Call this function and return its return value.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE ReturnType operator () ( T1 p1, T2 p2 ) const
			{
				if ( isMember )
					return (*memberFunction)( p1, p2 );
				else
				{
					RIM_DEBUG_ASSERT_MESSAGE( staticFunctionPointer == NULL, "Cannot call NULL function object." );
					
					return staticFunctionPointer( p1, p2 );
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function references the same function as another function object.
			RIM_INLINE Bool operator == ( const Function& other ) const
			{
				if ( isMember )
					return other.isMember && memberFunction->equals( *other.memberFunction );
				else
					return !other.isMember && staticFunctionPointer == other.staticFunctionPointer;
			}
			
			
			
			
			/// Return whether or not this function references a different function as onother function object.
			RIM_INLINE Bool operator != ( const Function& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is NULL.
			/**
			  * If this method returns TRUE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isNull() const
			{
				return !isMember && staticFunctionPointer == NULL;
			}
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is not NULL.
			/**
			  * If this method returns FALSE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isSet() const
			{
				return isMember || staticFunctionPointer != NULL;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < typename SignatureType, typename ObjectType >
			RIM_INLINE void constructMemberFunction( SignatureType functionPointer, ObjectType* object )
			{
				if ( object == NULL || functionPointer == NULL )
				{
					staticFunctionPointer = NULL;
					isMember = false;
				}
				else
				{
					memberFunction = util::construct<internal::MemberFunction<
									ObjectType, SignatureType, R, T1, T2> >( functionPointer, object );
					isMember = true;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A union which saves space when storing the static and member function pointers.
			union
			{
				/// A non-member function pointer to use when the function object represents a non-member function.
				R (*staticFunctionPointer)( T1, T2 );
				
				
				/// A pointer to an object which wraps a member function when this function is a member function.
				internal::FunctionDefinition<R,T1,T2>* memberFunction;
			};
			
			
			
			
			/// A boolean value indicating whether or not this function object is a member function.
			Bool isMember;
			
			
			
};




template < typename R, typename T1, typename T2 >
RIM_INLINE Function<R ( T1, T2 )> bind( R (*functionPointer)( T1, T2 ) )
{
	return Function<R ( T1, T2 )>( functionPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2 >
RIM_INLINE Function<R ( T1, T2 )> bind( R (ObjectType2::*functionPointer)( T1, T2 ),
															ObjectType* objectPointer )
{
	return Function<R ( T1, T2 )>( functionPointer, objectPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2 >
RIM_INLINE Function<R ( T1, T2 )> bind( R (ObjectType2::*functionPointer)( T1, T2 ) const,
															const ObjectType* objectPointer )
{
	return Function<R ( T1, T2 )>( functionPointer, objectPointer );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Function Object With 3 Parameters Class Definition
//############		
//##########################################################################################
//##########################################################################################




/// Specialization of the function template class for a method with 3 parameters.
template < typename R, typename T1, typename T2, typename T3 >
class Function< R ( T1, T2, T3 ) >
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			/// The return type of this function object.
			typedef R ReturnType;
			
			
			/// The type of the first parameter of this function object.
			typedef T1 ParameterType1;
			
			
			/// The type of the second parameter of this function object.
			typedef T2 ParameterType2;
			
			
			/// The type of the third parameter of this function object.
			typedef T3 ParameterType3;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default function object with a NULL function pointer.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE Function()
				:	staticFunctionPointer( NULL ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified non-member function pointer.
			RIM_INLINE Function( R (*functionPointer)( T1, T2, T3 ) )
				:	staticFunctionPointer( functionPointer ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2, T3 ),
								ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and const member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2, T3 ) const,
								const ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a copy of the specified function object.
			RIM_INLINE Function( const Function& other )
				:	isMember( other.isMember )
			{
				if ( other.isMember )
					memberFunction = other.memberFunction->clone();
				else
					staticFunctionPointer = other.staticFunctionPointer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this function object, releasing all internal state.
			RIM_INLINE ~Function()
			{
				if ( isMember )
					util::destruct( memberFunction );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of one function object to another.
			RIM_INLINE Function& operator = ( const Function& other )
			{
				if ( this != &other )
				{
					// Clean up the old member function if there was one.
					if ( isMember )
						util::destruct( memberFunction );
					
					// Copy the other function pointer.
					if ( isMember = other.isMember )
						memberFunction = other.memberFunction->clone();
					else
						staticFunctionPointer = other.staticFunctionPointer;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Call Method
			
			
			
			
			/// Call this function and return its return value.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE ReturnType operator () ( T1 p1, T2 p2, T3 p3 ) const
			{
				if ( isMember )
					return (*memberFunction)( p1, p2, p3 );
				else
				{
					RIM_DEBUG_ASSERT_MESSAGE( staticFunctionPointer == NULL, "Cannot call NULL function object." );
					
					return staticFunctionPointer( p1, p2, p3 );
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function references the same function as another function object.
			RIM_INLINE Bool operator == ( const Function& other ) const
			{
				if ( isMember )
					return other.isMember && memberFunction->equals( *other.memberFunction );
				else
					return !other.isMember && staticFunctionPointer == other.staticFunctionPointer;
			}
			
			
			
			
			/// Return whether or not this function references a different function as onother function object.
			RIM_INLINE Bool operator != ( const Function& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is NULL.
			/**
			  * If this method returns TRUE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isNull() const
			{
				return !isMember && staticFunctionPointer == NULL;
			}
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is not NULL.
			/**
			  * If this method returns FALSE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isSet() const
			{
				return isMember || staticFunctionPointer != NULL;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < typename SignatureType, typename ObjectType >
			RIM_INLINE void constructMemberFunction( SignatureType functionPointer, ObjectType* object )
			{
				if ( object == NULL || functionPointer == NULL )
				{
					staticFunctionPointer = NULL;
					isMember = false;
				}
				else
				{
					memberFunction = util::construct<internal::MemberFunction<
									ObjectType, SignatureType, R, T1, T2, T3> >( functionPointer, object );
					isMember = true;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A union which saves space when storing the static and member function pointers.
			union
			{
				/// A non-member function pointer to use when the function object represents a non-member function.
				R (*staticFunctionPointer)( T1, T2, T3 );
				
				
				/// A pointer to an object which wraps a member function when this function is a member function.
				internal::FunctionDefinition<R,T1,T2,T3>* memberFunction;
			};
			
			
			
			
			/// A boolean value indicating whether or not this function object is a member function.
			Bool isMember;
			
			
			
};




template < typename R, typename T1, typename T2, typename T3 >
RIM_INLINE Function<R ( T1, T2, T3 )> bind( R (*functionPointer)( T1, T2, T3 ) )
{
	return Function<R ( T1, T2, T3 )>( functionPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2, typename T3 >
RIM_INLINE Function<R ( T1, T2, T3 )> bind( R (ObjectType2::*functionPointer)( T1, T2, T3 ),
															ObjectType* objectPointer )
{
	return Function<R ( T1, T2, T3 )>( functionPointer, objectPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2, typename T3 >
RIM_INLINE Function<R ( T1, T2, T3 )> bind( R (ObjectType2::*functionPointer)( T1, T2, T3 ) const,
															const ObjectType* objectPointer )
{
	return Function<R ( T1, T2, T3 )>( functionPointer, objectPointer );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Function Object With 4 Parameters Class Definition
//############		
//##########################################################################################
//##########################################################################################




/// Specialization of the function template class for a method with 4 parameters.
template < typename R, typename T1, typename T2, typename T3, typename T4 >
class Function< R ( T1, T2, T3, T4 ) >
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			/// The return type of this function object.
			typedef R ReturnType;
			
			
			/// The type of the first parameter of this function object.
			typedef T1 ParameterType1;
			
			
			/// The type of the second parameter of this function object.
			typedef T2 ParameterType2;
			
			
			/// The type of the third parameter of this function object.
			typedef T3 ParameterType3;
			
			
			/// The type of the fourth parameter of this function object.
			typedef T4 ParameterType4;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default function object with a NULL function pointer.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE Function()
				:	staticFunctionPointer( NULL ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified non-member function pointer.
			RIM_INLINE Function( R (*functionPointer)( T1, T2, T3, T4 ) )
				:	staticFunctionPointer( functionPointer ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2, T3, T4 ),
								ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and const member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2, T3, T4 ) const,
								const ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a copy of the specified function object.
			RIM_INLINE Function( const Function& other )
				:	isMember( other.isMember )
			{
				if ( other.isMember )
					memberFunction = other.memberFunction->clone();
				else
					staticFunctionPointer = other.staticFunctionPointer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this function object, releasing all internal state.
			RIM_INLINE ~Function()
			{
				if ( isMember )
					util::destruct( memberFunction );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of one function object to another.
			RIM_INLINE Function& operator = ( const Function& other )
			{
				if ( this != &other )
				{
					// Clean up the old member function if there was one.
					if ( isMember )
						util::destruct( memberFunction );
					
					// Copy the other function pointer.
					if ( isMember = other.isMember )
						memberFunction = other.memberFunction->clone();
					else
						staticFunctionPointer = other.staticFunctionPointer;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Call Method
			
			
			
			
			/// Call this function and return its return value.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE ReturnType operator () ( T1 p1, T2 p2, T3 p3, T4 p4 ) const
			{
				if ( isMember )
					return (*memberFunction)( p1, p2, p3, p4 );
				else
				{
					RIM_DEBUG_ASSERT_MESSAGE( staticFunctionPointer == NULL, "Cannot call NULL function object." );
					
					return staticFunctionPointer( p1, p2, p3, p4 );
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function references the same function as another function object.
			RIM_INLINE Bool operator == ( const Function& other ) const
			{
				if ( isMember )
					return other.isMember && memberFunction->equals( *other.memberFunction );
				else
					return !other.isMember && staticFunctionPointer == other.staticFunctionPointer;
			}
			
			
			
			
			/// Return whether or not this function references a different function as onother function object.
			RIM_INLINE Bool operator != ( const Function& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is NULL.
			/**
			  * If this method returns TRUE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isNull() const
			{
				return !isMember && staticFunctionPointer == NULL;
			}
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is not NULL.
			/**
			  * If this method returns FALSE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isSet() const
			{
				return isMember || staticFunctionPointer != NULL;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < typename SignatureType, typename ObjectType >
			RIM_INLINE void constructMemberFunction( SignatureType functionPointer, ObjectType* object )
			{
				if ( object == NULL || functionPointer == NULL )
				{
					staticFunctionPointer = NULL;
					isMember = false;
				}
				else
				{
					memberFunction = util::construct<internal::MemberFunction<
									ObjectType, SignatureType, R, T1, T2, T3, T4> >( functionPointer, object );
					isMember = true;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A union which saves space when storing the static and member function pointers.
			union
			{
				/// A non-member function pointer to use when the function object represents a non-member function.
				R (*staticFunctionPointer)( T1, T2, T3, T4 );
				
				
				/// A pointer to an object which wraps a member function when this function is a member function.
				internal::FunctionDefinition<R,T1,T2,T3,T4>* memberFunction;
			};
			
			
			
			
			/// A boolean value indicating whether or not this function object is a member function.
			Bool isMember;
			
			
			
};




template < typename R, typename T1, typename T2, typename T3, typename T4 >
RIM_INLINE Function<R ( T1, T2, T3, T4 )> bind( R (*functionPointer)( T1, T2, T3, T4 ) )
{
	return Function<R ( T1, T2, T3, T4 )>( functionPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2, typename T3, typename T4 >
RIM_INLINE Function<R ( T1, T2, T3, T4 )> bind( R (ObjectType2::*functionPointer)( T1, T2, T3, T4 ),
															ObjectType* objectPointer )
{
	return Function<R ( T1, T2, T3, T4 )>( functionPointer, objectPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2, typename T3, typename T4 >
RIM_INLINE Function<R ( T1, T2, T3, T4 )> bind( R (ObjectType2::*functionPointer)( T1, T2, T3, T4 ) const,
															const ObjectType* objectPointer )
{
	return Function<R ( T1, T2, T3, T4 )>( functionPointer, objectPointer );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Function Object With 5 Parameters Class Definition
//############		
//##########################################################################################
//##########################################################################################




/// Specialization of the function template class for a method with 5 parameters.
template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5 >
class Function< R ( T1, T2, T3, T4, T5 ) >
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			/// The return type of this function object.
			typedef R ReturnType;
			
			
			/// The type of the first parameter of this function object.
			typedef T1 ParameterType1;
			
			
			/// The type of the second parameter of this function object.
			typedef T2 ParameterType2;
			
			
			/// The type of the third parameter of this function object.
			typedef T3 ParameterType3;
			
			
			/// The type of the fourth parameter of this function object.
			typedef T4 ParameterType4;
			
			
			/// The type of the fifth parameter of this function object.
			typedef T5 ParameterType5;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default function object with a NULL function pointer.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE Function()
				:	staticFunctionPointer( NULL ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified non-member function pointer.
			RIM_INLINE Function( R (*functionPointer)( T1, T2, T3, T4, T5 ) )
				:	staticFunctionPointer( functionPointer ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5 ),
								ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and const member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5 ) const,
								const ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a copy of the specified function object.
			RIM_INLINE Function( const Function& other )
				:	isMember( other.isMember )
			{
				if ( other.isMember )
					memberFunction = other.memberFunction->clone();
				else
					staticFunctionPointer = other.staticFunctionPointer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this function object, releasing all internal state.
			RIM_INLINE ~Function()
			{
				if ( isMember )
					util::destruct( memberFunction );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of one function object to another.
			RIM_INLINE Function& operator = ( const Function& other )
			{
				if ( this != &other )
				{
					// Clean up the old member function if there was one.
					if ( isMember )
						util::destruct( memberFunction );
					
					// Copy the other function pointer.
					if ( isMember = other.isMember )
						memberFunction = other.memberFunction->clone();
					else
						staticFunctionPointer = other.staticFunctionPointer;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Call Method
			
			
			
			
			/// Call this function and return its return value.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE ReturnType operator () ( T1 p1, T2 p2, T3 p3, T4 p4, T5 p5 ) const
			{
				if ( isMember )
					return (*memberFunction)( p1, p2, p3, p4, p5 );
				else
				{
					RIM_DEBUG_ASSERT_MESSAGE( staticFunctionPointer == NULL, "Cannot call NULL function object." );
					
					return staticFunctionPointer( p1, p2, p3, p4, p5 );
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function references the same function as another function object.
			RIM_INLINE Bool operator == ( const Function& other ) const
			{
				if ( isMember )
					return other.isMember && memberFunction->equals( *other.memberFunction );
				else
					return !other.isMember && staticFunctionPointer == other.staticFunctionPointer;
			}
			
			
			
			
			/// Return whether or not this function references a different function as onother function object.
			RIM_INLINE Bool operator != ( const Function& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is NULL.
			/**
			  * If this method returns TRUE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isNull() const
			{
				return !isMember && staticFunctionPointer == NULL;
			}
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is not NULL.
			/**
			  * If this method returns FALSE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isSet() const
			{
				return isMember || staticFunctionPointer != NULL;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < typename SignatureType, typename ObjectType >
			RIM_INLINE void constructMemberFunction( SignatureType functionPointer, ObjectType* object )
			{
				if ( object == NULL || functionPointer == NULL )
				{
					staticFunctionPointer = NULL;
					isMember = false;
				}
				else
				{
					memberFunction = util::construct<internal::MemberFunction<
									ObjectType, SignatureType, R, T1, T2, T3, T4, T5> >( functionPointer, object );
					isMember = true;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A union which saves space when storing the static and member function pointers.
			union
			{
				/// A non-member function pointer to use when the function object represents a non-member function.
				R (*staticFunctionPointer)( T1, T2, T3, T4, T5 );
				
				
				/// A pointer to an object which wraps a member function when this function is a member function.
				internal::FunctionDefinition<R,T1,T2,T3,T4,T5>* memberFunction;
			};
			
			
			
			
			/// A boolean value indicating whether or not this function object is a member function.
			Bool isMember;
			
			
			
};




template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5 )> bind( R (*functionPointer)( T1, T2, T3, T4, T5 ) )
{
	return Function<R ( T1, T2, T3, T4, T5 )>( functionPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5 )> bind( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5 ),
															ObjectType* objectPointer )
{
	return Function<R ( T1, T2, T3, T4, T5 )>( functionPointer, objectPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5 )> bind( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5 ) const,
															const ObjectType* objectPointer )
{
	return Function<R ( T1, T2, T3, T4, T5 )>( functionPointer, objectPointer );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Function Object With 6 Parameters Class Definition
//############		
//##########################################################################################
//##########################################################################################




/// Specialization of the function template class for a method with 6 parameters.
template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
class Function< R ( T1, T2, T3, T4, T5, T6 ) >
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			/// The return type of this function object.
			typedef R ReturnType;
			
			
			/// The type of the first parameter of this function object.
			typedef T1 ParameterType1;
			
			
			/// The type of the second parameter of this function object.
			typedef T2 ParameterType2;
			
			
			/// The type of the third parameter of this function object.
			typedef T3 ParameterType3;
			
			
			/// The type of the fourth parameter of this function object.
			typedef T4 ParameterType4;
			
			
			/// The type of the fifth parameter of this function object.
			typedef T5 ParameterType5;
			
			
			/// The type of the sixth parameter of this function object.
			typedef T6 ParameterType6;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default function object with a NULL function pointer.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE Function()
				:	staticFunctionPointer( NULL ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified non-member function pointer.
			RIM_INLINE Function( R (*functionPointer)( T1, T2, T3, T4, T5, T6 ) )
				:	staticFunctionPointer( functionPointer ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6 ),
								ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and const member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6 ) const,
								const ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a copy of the specified function object.
			RIM_INLINE Function( const Function& other )
				:	isMember( other.isMember )
			{
				if ( other.isMember )
					memberFunction = other.memberFunction->clone();
				else
					staticFunctionPointer = other.staticFunctionPointer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this function object, releasing all internal state.
			RIM_INLINE ~Function()
			{
				if ( isMember )
					util::destruct( memberFunction );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of one function object to another.
			RIM_INLINE Function& operator = ( const Function& other )
			{
				if ( this != &other )
				{
					// Clean up the old member function if there was one.
					if ( isMember )
						util::destruct( memberFunction );
					
					// Copy the other function pointer.
					if ( isMember = other.isMember )
						memberFunction = other.memberFunction->clone();
					else
						staticFunctionPointer = other.staticFunctionPointer;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Call Method
			
			
			
			
			/// Call this function and return its return value.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE ReturnType operator () ( T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6 ) const
			{
				if ( isMember )
					return (*memberFunction)( p1, p2, p3, p4, p5, p6 );
				else
				{
					RIM_DEBUG_ASSERT_MESSAGE( staticFunctionPointer == NULL, "Cannot call NULL function object." );
					
					return staticFunctionPointer( p1, p2, p3, p4, p5, p6 );
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function references the same function as another function object.
			RIM_INLINE Bool operator == ( const Function& other ) const
			{
				if ( isMember )
					return other.isMember && memberFunction->equals( *other.memberFunction );
				else
					return !other.isMember && staticFunctionPointer == other.staticFunctionPointer;
			}
			
			
			
			
			/// Return whether or not this function references a different function as onother function object.
			RIM_INLINE Bool operator != ( const Function& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is NULL.
			/**
			  * If this method returns TRUE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isNull() const
			{
				return !isMember && staticFunctionPointer == NULL;
			}
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is not NULL.
			/**
			  * If this method returns FALSE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isSet() const
			{
				return isMember || staticFunctionPointer != NULL;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < typename SignatureType, typename ObjectType >
			RIM_INLINE void constructMemberFunction( SignatureType functionPointer, ObjectType* object )
			{
				if ( object == NULL || functionPointer == NULL )
				{
					staticFunctionPointer = NULL;
					isMember = false;
				}
				else
				{
					memberFunction = util::construct<internal::MemberFunction<
									ObjectType, SignatureType, R, T1, T2, T3, T4, T5, T6> >( functionPointer, object );
					isMember = true;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A union which saves space when storing the static and member function pointers.
			union
			{
				/// A non-member function pointer to use when the function object represents a non-member function.
				R (*staticFunctionPointer)( T1, T2, T3, T4, T5, T6 );
				
				
				/// A pointer to an object which wraps a member function when this function is a member function.
				internal::FunctionDefinition<R,T1,T2,T3,T4,T5,T6>* memberFunction;
			};
			
			
			
			
			/// A boolean value indicating whether or not this function object is a member function.
			Bool isMember;
			
			
			
};




template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5, T6 )> bind( R (*functionPointer)( T1, T2, T3, T4, T5, T6 ) )
{
	return Function<R ( T1, T2, T3, T4, T5, T6 )>( functionPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5, T6 )> bind( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6 ),
															ObjectType* objectPointer )
{
	return Function<R ( T1, T2, T3, T4, T5, T6 )>( functionPointer, objectPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5, T6 )> bind( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6 ) const,
															const ObjectType* objectPointer )
{
	return Function<R ( T1, T2, T3, T4, T5, T6 )>( functionPointer, objectPointer );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Function Object With 7 Parameters Class Definition
//############		
//##########################################################################################
//##########################################################################################




/// Specialization of the function template class for a method with 7 parameters.
template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
class Function< R ( T1, T2, T3, T4, T5, T6, T7 ) >
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			/// The return type of this function object.
			typedef R ReturnType;
			
			
			/// The type of the first parameter of this function object.
			typedef T1 ParameterType1;
			
			
			/// The type of the second parameter of this function object.
			typedef T2 ParameterType2;
			
			
			/// The type of the third parameter of this function object.
			typedef T3 ParameterType3;
			
			
			/// The type of the fourth parameter of this function object.
			typedef T4 ParameterType4;
			
			
			/// The type of the fifth parameter of this function object.
			typedef T5 ParameterType5;
			
			
			/// The type of the sixth parameter of this function object.
			typedef T6 ParameterType6;
			
			
			/// The type of the seventh parameter of this function object.
			typedef T7 ParameterType7;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default function object with a NULL function pointer.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE Function()
				:	staticFunctionPointer( NULL ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified non-member function pointer.
			RIM_INLINE Function( R (*functionPointer)( T1, T2, T3, T4, T5, T6, T7 ) )
				:	staticFunctionPointer( functionPointer ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6, T7 ),
								ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and const member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6, T7 ) const,
								const ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a copy of the specified function object.
			RIM_INLINE Function( const Function& other )
				:	isMember( other.isMember )
			{
				if ( other.isMember )
					memberFunction = other.memberFunction->clone();
				else
					staticFunctionPointer = other.staticFunctionPointer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this function object, releasing all internal state.
			RIM_INLINE ~Function()
			{
				if ( isMember )
					util::destruct( memberFunction );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of one function object to another.
			RIM_INLINE Function& operator = ( const Function& other )
			{
				if ( this != &other )
				{
					// Clean up the old member function if there was one.
					if ( isMember )
						util::destruct( memberFunction );
					
					// Copy the other function pointer.
					if ( isMember = other.isMember )
						memberFunction = other.memberFunction->clone();
					else
						staticFunctionPointer = other.staticFunctionPointer;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Call Method
			
			
			
			
			/// Call this function and return its return value.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE ReturnType operator () ( T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7 )
			{
				if ( isMember )
					return (*memberFunction)( p1, p2, p3, p4, p5, p6, p7 );
				else
				{
					RIM_DEBUG_ASSERT_MESSAGE( staticFunctionPointer == NULL, "Cannot call NULL function object." );
					
					return staticFunctionPointer( p1, p2, p3, p4, p5, p6, p7 );
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function references the same function as another function object.
			RIM_INLINE Bool operator == ( const Function& other ) const
			{
				if ( isMember )
					return other.isMember && memberFunction->equals( *other.memberFunction );
				else
					return !other.isMember && staticFunctionPointer == other.staticFunctionPointer;
			}
			
			
			
			
			/// Return whether or not this function references a different function as onother function object.
			RIM_INLINE Bool operator != ( const Function& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is NULL.
			/**
			  * If this method returns TRUE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isNull() const
			{
				return !isMember && staticFunctionPointer == NULL;
			}
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is not NULL.
			/**
			  * If this method returns FALSE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isSet() const
			{
				return isMember || staticFunctionPointer != NULL;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < typename SignatureType, typename ObjectType >
			RIM_INLINE void constructMemberFunction( SignatureType functionPointer, ObjectType* object )
			{
				if ( object == NULL || functionPointer == NULL )
				{
					staticFunctionPointer = NULL;
					isMember = false;
				}
				else
				{
					memberFunction = util::construct<internal::MemberFunction<
									ObjectType, SignatureType, R, T1, T2, T3, T4, T5, T6, T7> >( functionPointer, object );
					isMember = true;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A union which saves space when storing the static and member function pointers.
			union
			{
				/// A non-member function pointer to use when the function object represents a non-member function.
				R (*staticFunctionPointer)( T1, T2, T3, T4, T5, T6, T7 );
				
				
				/// A pointer to an object which wraps a member function when this function is a member function.
				internal::FunctionDefinition<R,T1,T2,T3,T4,T5,T6,T7>* memberFunction;
			};
			
			
			
			
			/// A boolean value indicating whether or not this function object is a member function.
			Bool isMember;
			
			
			
};




template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5, T6, T7 )> bind( R (*functionPointer)( T1, T2, T3, T4, T5, T6, T7 ) )
{
	return Function<R ( T1, T2, T3, T4, T5, T6, T7 )>( functionPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5, T6, T7 )> bind( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6, T7 ),
															ObjectType* objectPointer )
{
	return Function<R ( T1, T2, T3, T4, T5, T6, T7 )>( functionPointer, objectPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5, T6, T7 )> bind( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6, T7 ) const,
															const ObjectType* objectPointer )
{
	return Function<R ( T1, T2, T3, T4, T5, T6, T7 )>( functionPointer, objectPointer );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Function Object With 8 Parameters Class Definition
//############		
//##########################################################################################
//##########################################################################################




/// Specialization of the function template class for a method with 8 parameters.
template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
class Function< R ( T1, T2, T3, T4, T5, T6, T7, T8 ) >
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			/// The return type of this function object.
			typedef R ReturnType;
			
			
			/// The type of the first parameter of this function object.
			typedef T1 ParameterType1;
			
			
			/// The type of the second parameter of this function object.
			typedef T2 ParameterType2;
			
			
			/// The type of the third parameter of this function object.
			typedef T3 ParameterType3;
			
			
			/// The type of the fourth parameter of this function object.
			typedef T4 ParameterType4;
			
			
			/// The type of the fifth parameter of this function object.
			typedef T5 ParameterType5;
			
			
			/// The type of the sixth parameter of this function object.
			typedef T6 ParameterType6;
			
			
			/// The type of the seventh parameter of this function object.
			typedef T7 ParameterType7;
			
			
			/// The type of the seventh parameter of this function object.
			typedef T8 ParameterType8;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default function object with a NULL function pointer.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE Function()
				:	staticFunctionPointer( NULL ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified non-member function pointer.
			RIM_INLINE Function( R (*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8 ) )
				:	staticFunctionPointer( functionPointer ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8 ),
								ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and const member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8 ) const,
								const ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a copy of the specified function object.
			RIM_INLINE Function( const Function& other )
				:	isMember( other.isMember )
			{
				if ( other.isMember )
					memberFunction = other.memberFunction->clone();
				else
					staticFunctionPointer = other.staticFunctionPointer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this function object, releasing all internal state.
			RIM_INLINE ~Function()
			{
				if ( isMember )
					util::destruct( memberFunction );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of one function object to another.
			RIM_INLINE Function& operator = ( const Function& other )
			{
				if ( this != &other )
				{
					// Clean up the old member function if there was one.
					if ( isMember )
						util::destruct( memberFunction );
					
					// Copy the other function pointer.
					if ( isMember = other.isMember )
						memberFunction = other.memberFunction->clone();
					else
						staticFunctionPointer = other.staticFunctionPointer;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Call Method
			
			
			
			
			/// Call this function and return its return value.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE ReturnType operator () ( T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8 )
			{
				if ( isMember )
					return (*memberFunction)( p1, p2, p3, p4, p5, p6, p7, p8 );
				else
				{
					RIM_DEBUG_ASSERT_MESSAGE( staticFunctionPointer == NULL, "Cannot call NULL function object." );
					
					return staticFunctionPointer( p1, p2, p3, p4, p5, p6, p7, p8 );
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function references the same function as another function object.
			RIM_INLINE Bool operator == ( const Function& other ) const
			{
				if ( isMember )
					return other.isMember && memberFunction->equals( *other.memberFunction );
				else
					return !other.isMember && staticFunctionPointer == other.staticFunctionPointer;
			}
			
			
			
			
			/// Return whether or not this function references a different function as onother function object.
			RIM_INLINE Bool operator != ( const Function& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is NULL.
			/**
			  * If this method returns TRUE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isNull() const
			{
				return !isMember && staticFunctionPointer == NULL;
			}
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is not NULL.
			/**
			  * If this method returns FALSE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isSet() const
			{
				return isMember || staticFunctionPointer != NULL;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < typename SignatureType, typename ObjectType >
			RIM_INLINE void constructMemberFunction( SignatureType functionPointer, ObjectType* object )
			{
				if ( object == NULL || functionPointer == NULL )
				{
					staticFunctionPointer = NULL;
					isMember = false;
				}
				else
				{
					memberFunction = util::construct<internal::MemberFunction<
									ObjectType, SignatureType, R, T1, T2, T3, T4, T5, T6, T7, T8> >( functionPointer, object );
					isMember = true;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A union which saves space when storing the static and member function pointers.
			union
			{
				/// A non-member function pointer to use when the function object represents a non-member function.
				R (*staticFunctionPointer)( T1, T2, T3, T4, T5, T6, T7, T8 );
				
				
				/// A pointer to an object which wraps a member function when this function is a member function.
				internal::FunctionDefinition<R,T1,T2,T3,T4,T5,T6,T7,T8>* memberFunction;
			};
			
			
			
			
			/// A boolean value indicating whether or not this function object is a member function.
			Bool isMember;
			
			
			
};




template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5, T6, T7, T8 )> bind( R (*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8 ) )
{
	return Function<R ( T1, T2, T3, T4, T5, T6, T7, T8 )>( functionPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7, typename T8 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5, T6, T7, T8 )> bind( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8 ),
															ObjectType* objectPointer )
{
	return Function<R ( T1, T2, T3, T4, T5, T6, T7, T8 )>( functionPointer, objectPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7, typename T8 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5, T6, T7, T8 )> bind( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8 ) const,
															const ObjectType* objectPointer )
{
	return Function<R ( T1, T2, T3, T4, T5, T6, T7, T8 )>( functionPointer, objectPointer );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Function Object With 9 Parameters Class Definition
//############		
//##########################################################################################
//##########################################################################################




/// Specialization of the function template class for a method with 8 parameters.
template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
class Function< R ( T1, T2, T3, T4, T5, T6, T7, T8, T9 ) >
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			/// The return type of this function object.
			typedef R ReturnType;
			
			
			/// The type of the first parameter of this function object.
			typedef T1 ParameterType1;
			
			
			/// The type of the second parameter of this function object.
			typedef T2 ParameterType2;
			
			
			/// The type of the third parameter of this function object.
			typedef T3 ParameterType3;
			
			
			/// The type of the fourth parameter of this function object.
			typedef T4 ParameterType4;
			
			
			/// The type of the fifth parameter of this function object.
			typedef T5 ParameterType5;
			
			
			/// The type of the sixth parameter of this function object.
			typedef T6 ParameterType6;
			
			
			/// The type of the seventh parameter of this function object.
			typedef T7 ParameterType7;
			
			
			/// The type of the eighth parameter of this function object.
			typedef T8 ParameterType8;
			
			
			/// The type of the nineth parameter of this function object.
			typedef T9 ParameterType9;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default function object with a NULL function pointer.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE Function()
				:	staticFunctionPointer( NULL ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified non-member function pointer.
			RIM_INLINE Function( R (*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8, T9 ) )
				:	staticFunctionPointer( functionPointer ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8, T9 ),
								ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and const member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8, T9 ) const,
								const ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a copy of the specified function object.
			RIM_INLINE Function( const Function& other )
				:	isMember( other.isMember )
			{
				if ( other.isMember )
					memberFunction = other.memberFunction->clone();
				else
					staticFunctionPointer = other.staticFunctionPointer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this function object, releasing all internal state.
			RIM_INLINE ~Function()
			{
				if ( isMember )
					util::destruct( memberFunction );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of one function object to another.
			RIM_INLINE Function& operator = ( const Function& other )
			{
				if ( this != &other )
				{
					// Clean up the old member function if there was one.
					if ( isMember )
						util::destruct( memberFunction );
					
					// Copy the other function pointer.
					if ( isMember = other.isMember )
						memberFunction = other.memberFunction->clone();
					else
						staticFunctionPointer = other.staticFunctionPointer;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Call Method
			
			
			
			
			/// Call this function and return its return value.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE ReturnType operator () ( T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9 )
			{
				if ( isMember )
					return (*memberFunction)( p1, p2, p3, p4, p5, p6, p7, p8, p9 );
				else
				{
					RIM_DEBUG_ASSERT_MESSAGE( staticFunctionPointer == NULL, "Cannot call NULL function object." );
					
					return staticFunctionPointer( p1, p2, p3, p4, p5, p6, p7, p8, p9 );
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function references the same function as another function object.
			RIM_INLINE Bool operator == ( const Function& other ) const
			{
				if ( isMember )
					return other.isMember && memberFunction->equals( *other.memberFunction );
				else
					return !other.isMember && staticFunctionPointer == other.staticFunctionPointer;
			}
			
			
			
			
			/// Return whether or not this function references a different function as onother function object.
			RIM_INLINE Bool operator != ( const Function& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is NULL.
			/**
			  * If this method returns TRUE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isNull() const
			{
				return !isMember && staticFunctionPointer == NULL;
			}
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is not NULL.
			/**
			  * If this method returns FALSE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isSet() const
			{
				return isMember || staticFunctionPointer != NULL;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < typename SignatureType, typename ObjectType >
			RIM_INLINE void constructMemberFunction( SignatureType functionPointer, ObjectType* object )
			{
				if ( object == NULL || functionPointer == NULL )
				{
					staticFunctionPointer = NULL;
					isMember = false;
				}
				else
				{
					memberFunction = util::construct<internal::MemberFunction<
									ObjectType, SignatureType, R, T1, T2, T3, T4, T5, T6, T7, T8, T9> >( functionPointer, object );
					isMember = true;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A union which saves space when storing the static and member function pointers.
			union
			{
				/// A non-member function pointer to use when the function object represents a non-member function.
				R (*staticFunctionPointer)( T1, T2, T3, T4, T5, T6, T7, T8, T9 );
				
				
				/// A pointer to an object which wraps a member function when this function is a member function.
				internal::FunctionDefinition<R,T1,T2,T3,T4,T5,T6,T7,T8,T9>* memberFunction;
			};
			
			
			
			
			/// A boolean value indicating whether or not this function object is a member function.
			Bool isMember;
			
			
			
};




template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5,
						typename T6, typename T7, typename T8, typename T9 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5, T6, T7, T8, T9 )> bind( R (*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8, T9 ) )
{
	return Function<R ( T1, T2, T3, T4, T5, T6, T7, T8, T9 )>( functionPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7, typename T8, typename T9 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5, T6, T7, T8, T9 )> bind( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8, T9 ),
															ObjectType* objectPointer )
{
	return Function<R ( T1, T2, T3, T4, T5, T6, T7, T8, T9 )>( functionPointer, objectPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7, typename T8, typename T9 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5, T6, T7, T8, T9 )> bind( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8, T9 ) const,
															const ObjectType* objectPointer )
{
	return Function<R ( T1, T2, T3, T4, T5, T6, T7, T8, T9 )>( functionPointer, objectPointer );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Function Object With 10 Parameters Class Definition
//############		
//##########################################################################################
//##########################################################################################




/// Specialization of the function template class for a method with 10 parameters.
template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10 >
class Function< R ( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 ) >
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			/// The return type of this function object.
			typedef R ReturnType;
			
			
			/// The type of the first parameter of this function object.
			typedef T1 ParameterType1;
			
			
			/// The type of the second parameter of this function object.
			typedef T2 ParameterType2;
			
			
			/// The type of the third parameter of this function object.
			typedef T3 ParameterType3;
			
			
			/// The type of the fourth parameter of this function object.
			typedef T4 ParameterType4;
			
			
			/// The type of the fifth parameter of this function object.
			typedef T5 ParameterType5;
			
			
			/// The type of the sixth parameter of this function object.
			typedef T6 ParameterType6;
			
			
			/// The type of the seventh parameter of this function object.
			typedef T7 ParameterType7;
			
			
			/// The type of the eighth parameter of this function object.
			typedef T8 ParameterType8;
			
			
			/// The type of the nineth parameter of this function object.
			typedef T9 ParameterType9;
			
			
			/// The type of the tenth parameter of this function object.
			typedef T10 ParameterType10;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default function object with a NULL function pointer.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE Function()
				:	staticFunctionPointer( NULL ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified non-member function pointer.
			RIM_INLINE Function( R (*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 ) )
				:	staticFunctionPointer( functionPointer ),
					isMember( false )
			{
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 ),
								ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a new function object which wraps the specified object and const member function pointer.
			template < typename ObjectType, typename ObjectType2 >
			RIM_INLINE Function( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 ) const,
								const ObjectType* objectPointer )
			{
				constructMemberFunction( functionPointer, objectPointer );
			}
			
			
			
			
			/// Create a copy of the specified function object.
			RIM_INLINE Function( const Function& other )
				:	isMember( other.isMember )
			{
				if ( other.isMember )
					memberFunction = other.memberFunction->clone();
				else
					staticFunctionPointer = other.staticFunctionPointer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this function object, releasing all internal state.
			RIM_INLINE ~Function()
			{
				if ( isMember )
					util::destruct( memberFunction );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of one function object to another.
			RIM_INLINE Function& operator = ( const Function& other )
			{
				if ( this != &other )
				{
					// Clean up the old member function if there was one.
					if ( isMember )
						util::destruct( memberFunction );
					
					// Copy the other function pointer.
					if ( isMember = other.isMember )
						memberFunction = other.memberFunction->clone();
					else
						staticFunctionPointer = other.staticFunctionPointer;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Call Method
			
			
			
			
			/// Call this function and return its return value.
			/**
			  * Calling a NULL function object will cause an assertion to be raised.
			  * One should always check to see if the function is NULL by calling the
			  * isNull() method before calling it.
			  */
			RIM_INLINE ReturnType operator () ( T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9, T10 p10 )
			{
				if ( isMember )
					return (*memberFunction)( p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 );
				else
				{
					RIM_DEBUG_ASSERT_MESSAGE( staticFunctionPointer == NULL, "Cannot call NULL function object." );
					
					return staticFunctionPointer( p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 );
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function references the same function as another function object.
			RIM_INLINE Bool operator == ( const Function& other ) const
			{
				if ( isMember )
					return other.isMember && memberFunction->equals( *other.memberFunction );
				else
					return !other.isMember && staticFunctionPointer == other.staticFunctionPointer;
			}
			
			
			
			
			/// Return whether or not this function references a different function as onother function object.
			RIM_INLINE Bool operator != ( const Function& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Equality Comparison Operators
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is NULL.
			/**
			  * If this method returns TRUE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isNull() const
			{
				return !isMember && staticFunctionPointer == NULL;
			}
			
			
			
			
			/// Return whether or not this function object has a function/object pointer that is not NULL.
			/**
			  * If this method returns FALSE, calling the function will result in
			  * an assertion being raised.
			  */
			RIM_INLINE Bool isSet() const
			{
				return isMember || staticFunctionPointer != NULL;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			template < typename SignatureType, typename ObjectType >
			RIM_INLINE void constructMemberFunction( SignatureType functionPointer, ObjectType* object )
			{
				if ( object == NULL || functionPointer == NULL )
				{
					staticFunctionPointer = NULL;
					isMember = false;
				}
				else
				{
					memberFunction = util::construct<internal::MemberFunction<
									ObjectType, SignatureType, R, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> >( functionPointer, object );
					isMember = true;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A union which saves space when storing the static and member function pointers.
			union
			{
				/// A non-member function pointer to use when the function object represents a non-member function.
				R (*staticFunctionPointer)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 );
				
				
				/// A pointer to an object which wraps a member function when this function is a member function.
				internal::FunctionDefinition<R,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10>* memberFunction;
			};
			
			
			
			
			/// A boolean value indicating whether or not this function object is a member function.
			Bool isMember;
			
			
			
};




template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 )> bind( R (*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 ) )
{
	return Function<R ( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 )>( functionPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7, typename T8, typename T9, typename T10 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 )> bind( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 ),
															ObjectType* objectPointer )
{
	return Function<R ( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 )>( functionPointer, objectPointer );
}




template < typename ObjectType, typename ObjectType2, typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7, typename T8, typename T9, typename T10 >
RIM_INLINE Function<R ( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 )> bind( R (ObjectType2::*functionPointer)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 ) const,
															const ObjectType* objectPointer )
{
	return Function<R ( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 )>( functionPointer, objectPointer );
}




//##########################################################################################
//***************************  End Rim Language Namespace  *********************************
RIM_LANGUAGE_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_FUNCTION_H
