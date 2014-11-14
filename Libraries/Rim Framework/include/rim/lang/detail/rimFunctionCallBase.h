/*
 *  rimFunctionCallBase.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 6/7/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_FUNCTION_CALL_BASE_H
#define INCLUDE_RIM_FUNCTION_CALL_BASE_H


#include "../rimLanguageConfig.h"


#include "../rimFunction.h"


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
class FunctionCallBase
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Type Definitions
			
			
			
			
			typedef FunctionCallBase<R,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10> ThisType;
			typedef Function<R ( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 )> FunctionType;
			
			typedef R ReturnType;
			
			typedef T1 ParameterType1;
			typedef T2 ParameterType2;
			typedef T3 ParameterType3;
			typedef T4 ParameterType4;
			typedef T5 ParameterType5;
			typedef T6 ParameterType6;
			typedef T7 ParameterType7;
			typedef T8 ParameterType8;
			typedef T9 ParameterType9;
			typedef T10 ParameterType10;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Call Execute Method
			
			
			
			
			RIM_INLINE R operator () ()
			{
				return function( arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10 );
			}
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Constructor
			
			
			
			
			RIM_INLINE FunctionCallBase( const FunctionType& f,
										T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10 )
				:	function( f ),
					arg1( a1 ), arg2( a2 ), arg3( a3 ), arg4( a4 ), arg5( a5 ), arg6( a6 ), arg7( a7 ), arg8( a8 ), arg9( a9 ), arg10( a10 )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Data Members
			
			
			FunctionType function;
			
			
			T1 arg1;
			T2 arg2;
			T3 arg3;
			T4 arg4;
			T5 arg5;
			T6 arg6;
			T7 arg7;
			T8 arg8;
			T9 arg9;
			T10 arg10;
			
};




template < typename R >
struct FunctionCallBase< R, 
						NullType, NullType, NullType, NullType, NullType, NullType, NullType, NullType, NullType, NullType >
{
	protected:
		
		typedef FunctionCallBase<R> ThisType;
		typedef Function<R ()> FunctionType;
		
		typedef R ReturnType;
		
	public:
		
		RIM_INLINE R execute()
		{
			return function();
		}
		
		
		RIM_INLINE R operator () ()
		{
			return function();
		}
		
		
		RIM_INLINE FunctionCallBase( const FunctionType& f )
			:	function( f )
		{
		}
		
		
		
	protected:
		
		
		
		
		FunctionType function;
		
		
};




template < typename R, typename T1 >
struct FunctionCallBase< R, 
						T1, 
						NullType, NullType, NullType, NullType, NullType, NullType, NullType, NullType, NullType >
{
	protected:
		
		typedef FunctionCallBase<R,T1> ThisType;
		typedef Function<R ( T1 )> FunctionType;
		
		typedef R ReturnType;
		
		typedef T1 ParameterType1;
		
		
	public:
		
		RIM_INLINE R execute()
		{
			return function( arg1 );
		}
		
		
		RIM_INLINE R operator () ()
		{
			return function( arg1 );
		}
		
		
		RIM_INLINE FunctionCallBase( const FunctionType& f, T1 a1 )
			:	function( f ),
				arg1( a1 )
		{
		}
		
		
		
	protected:
		
		
		FunctionType function;
		
		
		T1 arg1;
		
};




template < typename R, typename T1, typename T2 >
struct FunctionCallBase< R, 
						T1, 
						T2, 
						NullType, NullType, NullType, NullType, NullType, NullType, NullType, NullType >
{
	public:
		
		typedef FunctionCallBase<R,T1,T2> ThisType;
		typedef Function<R ( T1, T2 )> FunctionType;
		
		typedef R ReturnType;
		
		typedef T1 ParameterType1;
		typedef T2 ParameterType2;
		
		
	public:
		
		RIM_INLINE R execute()
		{
			return function( arg1, arg2 );
		}
		
		RIM_INLINE R operator () ()
		{
			return function( arg1, arg2 );
		}
		
		
		RIM_INLINE FunctionCallBase( const FunctionType& f, T1 a1, T2 a2 )
			:	function( f ),
				arg1( a1 ),
				arg2( a2 )
		{
		}
		
		
		
	protected:
		
		
		FunctionType function;
		
		
		T1 arg1;
		T2 arg2;
		
};




template < typename R, typename T1, typename T2, typename T3 >
struct FunctionCallBase< R, 
						T1, 
						T2, 
						T3, 
						NullType, NullType, NullType, NullType, NullType, NullType, NullType >
{
	public:
		
		typedef FunctionCallBase<R,T1,T2,T3> ThisType;
		typedef Function<R ( T1, T2, T3 )> FunctionType;
		
		typedef R ReturnType;
		
		typedef T1 ParameterType1;
		typedef T2 ParameterType2;
		typedef T3 ParameterType3;
		
		
	public:
		
		RIM_INLINE R execute()
		{
			return function( arg1, arg2, arg3 );
		}
		
		RIM_INLINE R operator () ()
		{
			return function( arg1, arg2, arg3 );
		}
		
		
		RIM_INLINE FunctionCallBase( const FunctionType& f, T1 a1, T2 a2, T3 a3 )
			:	function( f ),
				arg1( a1 ),
				arg2( a2 ),
				arg3( a3 )
		{
		}
		
		
		
	protected:
		
		
		FunctionType function;
		
		
		T1 arg1;
		T2 arg2;
		T3 arg3;
		
};




template < typename R, typename T1, typename T2, typename T3, typename T4 >
struct FunctionCallBase< R, 
						T1, 
						T2, 
						T3, 
						T4, 
						NullType, NullType, NullType, NullType, NullType, NullType >
{
	public:
		
		typedef FunctionCallBase<R,T1,T2,T3,T4> ThisType;
		typedef Function<R ( T1, T2, T3, T4 )> FunctionType;
		
		typedef R ReturnType;
		
		typedef T1 ParameterType1;
		typedef T2 ParameterType2;
		typedef T3 ParameterType3;
		typedef T4 ParameterType4;
		
		
	public:
		
		RIM_INLINE R execute()
		{
			return function( arg1, arg2, arg3, arg4 );
		}
		
		RIM_INLINE R operator () ()
		{
			return function( arg1, arg2, arg3, arg4 );
		}
		
		
		RIM_INLINE FunctionCallBase( const FunctionType& f, T1 a1, T2 a2, T3 a3, T4 a4 )
			:	function( f ),
				arg1( a1 ),
				arg2( a2 ),
				arg3( a3 ),
				arg4( a4 )
		{
		}
		
		
		
	protected:
		
		
		FunctionType function;
		
		
		T1 arg1;
		T2 arg2;
		T3 arg3;
		T4 arg4;
		
};




template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5 >
struct FunctionCallBase< R, 
						T1, 
						T2, 
						T3, 
						T4, 
						T5, 
						NullType, NullType, NullType, NullType, NullType >
{
	public:
		
		typedef FunctionCallBase<R,T1,T2,T3,T4,T5> ThisType;
		typedef Function<R ( T1, T2, T3, T4, T5 )> FunctionType;
		
		typedef R ReturnType;
		
		typedef T1 ParameterType1;
		typedef T2 ParameterType2;
		typedef T3 ParameterType3;
		typedef T4 ParameterType4;
		typedef T5 ParameterType5;
		
		
	public:
		
		RIM_INLINE R execute()
		{
			return function( arg1, arg2, arg3, arg4, arg5 );
		}
		
		RIM_INLINE R operator () ()
		{
			return function( arg1, arg2, arg3, arg4, arg5 );
		}
		
		
		RIM_INLINE FunctionCallBase( const FunctionType& f,
									T1 a1, T2 a2, T3 a3, T4 a4, T5 a5 )
			:	function( f ),
				arg1( a1 ), arg2( a2 ), arg3( a3 ), arg4( a4 ), arg5( a5 )
		{
		}
		
		
		
	protected:
		
		
		FunctionType function;
		
		
		T1 arg1;
		T2 arg2;
		T3 arg3;
		T4 arg4;
		T5 arg5;
		
};




template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
struct FunctionCallBase< R, 
						T1, 
						T2, 
						T3, 
						T4, 
						T5, 
						T6, 
						NullType, NullType, NullType, NullType >
{
	public:
		
		typedef FunctionCallBase<R,T1,T2,T3,T4,T5,T6> ThisType;
		typedef Function<R ( T1, T2, T3, T4, T5, T6 )> FunctionType;
		
		typedef R ReturnType;
		
		typedef T1 ParameterType1;
		typedef T2 ParameterType2;
		typedef T3 ParameterType3;
		typedef T4 ParameterType4;
		typedef T5 ParameterType5;
		typedef T6 ParameterType6;
		
		
	public:
		
		RIM_INLINE R execute()
		{
			return function( arg1, arg2, arg3, arg4, arg5, arg6 );
		}
		
		
		RIM_INLINE R operator () ()
		{
			return function( arg1, arg2, arg3, arg4, arg5, arg6 );
		}
		
		
		
		RIM_INLINE FunctionCallBase( const FunctionType& f, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6 )
			:	function( f ),
				arg1( a1 ), arg2( a2 ), arg3( a3 ), arg4( a4 ), arg5( a5 ), arg6( a6 )
		{
		}
		
		
		
	protected:
		
		
		FunctionType function;
		
		
		T1 arg1;
		T2 arg2;
		T3 arg3;
		T4 arg4;
		T5 arg5;
		T6 arg6;
		
};




template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
struct FunctionCallBase< R, 
						T1, 
						T2, 
						T3, 
						T4, 
						T5, 
						T6, 
						T7,
						NullType, NullType, NullType >
{
	public:
		
		typedef FunctionCallBase<R,T1,T2,T3,T4,T5,T6,T7> ThisType;
		typedef Function<R ( T1, T2, T3, T4, T5, T6, T7 )> FunctionType;
		
		typedef R ReturnType;
		
		typedef T1 ParameterType1;
		typedef T2 ParameterType2;
		typedef T3 ParameterType3;
		typedef T4 ParameterType4;
		typedef T5 ParameterType5;
		typedef T6 ParameterType6;
		typedef T7 ParameterType7;
		
		
	public:
		
		RIM_INLINE R execute()
		{
			return function( arg1, arg2, arg3, arg4, arg5, arg6, arg7 );
		}
		
		
		RIM_INLINE R operator () ()
		{
			return function( arg1, arg2, arg3, arg4, arg5, arg6, arg7 );
		}
		
		
		
		RIM_INLINE FunctionCallBase( const FunctionType& f,
									T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7 )
			:	function( f ),
				arg1( a1 ), arg2( a2 ), arg3( a3 ), arg4( a4 ), arg5( a5 ), arg6( a6 ), arg7( a7 )
		{
		}
		
		
		
	protected:
		
		
		FunctionType function;
		
		
		T1 arg1;
		T2 arg2;
		T3 arg3;
		T4 arg4;
		T5 arg5;
		T6 arg6;
		T7 arg7;
		
};




template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
struct FunctionCallBase< R, 
						T1, 
						T2, 
						T3, 
						T4, 
						T5, 
						T6, 
						T7,
						T8,
						NullType, NullType >
{
	public:
		
		typedef FunctionCallBase<R,T1,T2,T3,T4,T5,T6,T7,T8> ThisType;
		typedef Function<R ( T1, T2, T3, T4, T5, T6, T7, T8 )> FunctionType;
		
		typedef R ReturnType;
		
		typedef T1 ParameterType1;
		typedef T2 ParameterType2;
		typedef T3 ParameterType3;
		typedef T4 ParameterType4;
		typedef T5 ParameterType5;
		typedef T6 ParameterType6;
		typedef T7 ParameterType7;
		typedef T8 ParameterType8;
		
		
	public:
		
		RIM_INLINE R execute()
		{
			return function( arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 );
		}
		
		
		RIM_INLINE R operator () ()
		{
			return function( arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 );
		}
		
		
		
		RIM_INLINE FunctionCallBase( const FunctionType& f,
									T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8 )
			:	function( f ),
				arg1( a1 ), arg2( a2 ), arg3( a3 ), arg4( a4 ), arg5( a5 ), arg6( a6 ), arg7( a7 ), arg8( a8 )
		{
		}
		
		
		
	protected:
		
		
		FunctionType function;
		
		
		T1 arg1;
		T2 arg2;
		T3 arg3;
		T4 arg4;
		T5 arg5;
		T6 arg6;
		T7 arg7;
		T8 arg8;
		
};




template < typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
struct FunctionCallBase< R, 
						T1, 
						T2, 
						T3, 
						T4, 
						T5, 
						T6, 
						T7,
						T8,
						T9,
						NullType >
{
	public:
		
		typedef FunctionCallBase<R,T1,T2,T3,T4,T5,T6,T7,T8,T9> ThisType;
		typedef Function<R ( T1, T2, T3, T4, T5, T6, T7, T8, T9 )> FunctionType;
		
		typedef R ReturnType;
		
		typedef T1 ParameterType1;
		typedef T2 ParameterType2;
		typedef T3 ParameterType3;
		typedef T4 ParameterType4;
		typedef T5 ParameterType5;
		typedef T6 ParameterType6;
		typedef T7 ParameterType7;
		typedef T8 ParameterType8;
		
		
	public:
		
		RIM_INLINE R execute()
		{
			return function( arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9 );
		}
		
		
		RIM_INLINE R operator () ()
		{
			return function( arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9 );
		}
		
		
		
		RIM_INLINE FunctionCallBase( const FunctionType& f,
									T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9 )
			:	function( f ),
				arg1( a1 ), arg2( a2 ), arg3( a3 ), arg4( a4 ), arg5( a5 ), arg6( a6 ), arg7( a7 ), arg8( a8 ), arg9( a9 )
		{
		}
		
		
		
	protected:
		
		
		FunctionType function;
		
		
		T1 arg1;
		T2 arg2;
		T3 arg3;
		T4 arg4;
		T5 arg5;
		T6 arg6;
		T7 arg7;
		T8 arg8;
		T9 arg9;
		
};




//##########################################################################################
//***********************  End Rim Language Internal Namespace  ****************************
RIM_LANGUAGE_INTERNAL_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_FUNCTION_CALL_BASE_H
