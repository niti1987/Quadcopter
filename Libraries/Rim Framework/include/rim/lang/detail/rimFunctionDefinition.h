/*
 *  rimFunctionBase.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 6/22/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_FUNCTION_DEFINITION_H
#define INCLUDE_RIM_FUNCTION_DEFINITION_H


#include "../rimLanguageConfig.h"


#include "rimNullType.h"


//##########################################################################################
//***********************  Start Rim Language Internal Namespace  **************************
RIM_LANGUAGE_INTERNAL_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




template <	typename R, 
			typename T1 = NullType, 
			typename T2 = NullType, 
			typename T3 = NullType, 
			typename T4 = NullType, 
			typename T5 = NullType, 
			typename T6 = NullType, 
			typename T7 = NullType, 
			typename T8 = NullType, 
			typename T9 = NullType, 
			typename T10 = NullType >
class FunctionDefinition
{
	public:
		
		typedef FunctionDefinition<R,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10> ThisType;
		
		
		virtual ~FunctionDefinition() {}
		
		virtual void operator () ( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 ) const = 0;
		
		virtual Bool equals( const ThisType& other ) const = 0;
		
		virtual ThisType* clone() const = 0;
		
};




template < typename R >
class FunctionDefinition< R, NullType, NullType, NullType, NullType, NullType, NullType, NullType, NullType, NullType, NullType >
{
	public:
		
		typedef FunctionDefinition<R> ThisType;
		
		
		virtual ~FunctionDefinition() {}
		
		virtual R operator () () const = 0;
		
		virtual Bool equals( const ThisType& other ) const = 0;
		
		virtual ThisType* clone() const = 0;
		
};




template < typename R, typename T1 >
class FunctionDefinition< R, T1, NullType, NullType, NullType, NullType, NullType, NullType, NullType, NullType, NullType >
{
	public:
		
		typedef FunctionDefinition<R,T1> ThisType;
		
		
		virtual ~FunctionDefinition() {}
		
		virtual R operator () ( T1 ) const = 0;
		
		virtual Bool equals( const ThisType& other ) const = 0;
		
		virtual ThisType* clone() const = 0;
		
};




template < typename R, typename T1, typename T2 >
class FunctionDefinition< R, T1, T2, NullType, NullType, NullType, NullType, NullType, NullType, NullType, NullType >
{
	public:
		
		typedef FunctionDefinition<R,T1,T2> ThisType;
		
		
		virtual ~FunctionDefinition() {}
		
		virtual R operator () ( T1, T2 ) const = 0;
		
		virtual Bool equals( const ThisType& other ) const = 0;
		
		virtual ThisType* clone() const = 0;
		
};




template < typename R, typename T1, typename T2, typename T3 >
class FunctionDefinition< R, T1, T2, T3, NullType, NullType, NullType, NullType, NullType, NullType, NullType >
{
	public:
		
		typedef FunctionDefinition<R,T1,T2,T3> ThisType;
		
		
		virtual ~FunctionDefinition() {}
		
		virtual R operator () ( T1, T2, T3 ) const = 0;
		
		virtual Bool equals( const ThisType& other ) const = 0;
		
		virtual ThisType* clone() const = 0;
		
};




template < typename R, typename T1, typename T2, typename T3, typename T4 >
class FunctionDefinition< R, T1, T2, T3, T4, NullType, NullType, NullType, NullType, NullType, NullType >
{
	public:
		
		typedef FunctionDefinition<R,T1,T2,T3,T4> ThisType;
		
		
		virtual ~FunctionDefinition() {}
		
		virtual R operator () ( T1, T2, T3, T4 ) const = 0;
		
		virtual Bool equals( const ThisType& other ) const = 0;
		
		virtual ThisType* clone() const = 0;
		
};




template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5 >
class FunctionDefinition< R, T1, T2, T3, T4, T5, NullType, NullType, NullType, NullType, NullType >
{
	public:
		
		typedef FunctionDefinition<R,T1,T2,T3,T4,T5> ThisType;
		
		
		virtual ~FunctionDefinition() {}
		
		virtual R operator () ( T1, T2, T3, T4, T5 ) const = 0;
		
		virtual Bool equals( const ThisType& other ) const = 0;
		
		virtual ThisType* clone() const = 0;
		
};




template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
class FunctionDefinition< R, T1, T2, T3, T4, T5, T6, NullType, NullType, NullType, NullType >
{
	public:
		
		typedef FunctionDefinition<R,T1,T2,T3,T4,T5,T6> ThisType;
		
		
		virtual ~FunctionDefinition() {}
		
		virtual R operator () ( T1, T2, T3, T4, T5, T6 ) const = 0;
		
		virtual Bool equals( const ThisType& other ) const = 0;
		
		virtual ThisType* clone() const = 0;
		
};




template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
class FunctionDefinition< R, T1, T2, T3, T4, T5, T6, T7, NullType, NullType, NullType >
{
	public:
		
		typedef FunctionDefinition<R,T1,T2,T3,T4,T5,T6,T7> ThisType;
		
		
		virtual ~FunctionDefinition() {}
		
		virtual R operator () ( T1, T2, T3, T4, T5, T6, T7 ) const = 0;
		
		virtual Bool equals( const ThisType& other ) const = 0;
		
		virtual ThisType* clone() const = 0;
		
};




template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
class FunctionDefinition< R, T1, T2, T3, T4, T5, T6, T7, T8, NullType, NullType >
{
	public:
		
		typedef FunctionDefinition<R,T1,T2,T3,T4,T5,T6,T7,T8> ThisType;
		
		
		virtual ~FunctionDefinition() {}
		
		virtual R operator () ( T1, T2, T3, T4, T5, T6, T7, T8 ) const = 0;
		
		virtual Bool equals( const ThisType& other ) const = 0;
		
		virtual ThisType* clone() const = 0;
		
};




template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
class FunctionDefinition< R, T1, T2, T3, T4, T5, T6, T7, T8, T9, NullType >
{
	public:
		
		typedef FunctionDefinition<R,T1,T2,T3,T4,T5,T6,T7,T8,T9> ThisType;
		
		
		virtual ~FunctionDefinition() {}
		
		virtual R operator () ( T1, T2, T3, T4, T5, T6, T7, T8, T9 ) const = 0;
		
		virtual Bool equals( const ThisType& other ) const = 0;
		
		virtual ThisType* clone() const = 0;
		
};




//##########################################################################################
//***********************  End Rim Language Internal Namespace  ****************************
RIM_LANGUAGE_INTERNAL_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_FUNCTION_DEFINITION_H
