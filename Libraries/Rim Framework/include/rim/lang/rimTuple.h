/*
 *  rimTuple.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 7/2/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_TUPLE_H
#define INCLUDE_RIM_TUPLE_H


#include "rimLanguageConfig.h"


#include "detail/rimNullType.h"


//##########################################################################################
//***************************  Start Rim Language Namespace  *******************************
RIM_LANGUAGE_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//##########################################################################################
//##########################################################################################
//############		
//############		0-Element Tuple Class
//############		
//##########################################################################################
//##########################################################################################




template < typename T1 = internal::NullType,
			typename T2 = internal::NullType,
			typename T3 = internal::NullType,
			typename T4 = internal::NullType,
			typename T5 = internal::NullType,
			typename T6 = internal::NullType,
			typename T7 = internal::NullType >
class Tuple
{
	public:
		
		
		RIM_INLINE Tuple( const T1& v1, const T2& v2, const T3& v3, const T4& v4,
						const T5& v5, const T6& v6, const T7& v7 )
			:	value1( v1 ),
				value2( v2 ),
				value3( v3 ),
				value4( v4 ),
				value5( v5 ),
				value6( v6 ),
				value7( v7 )
		{
		}
		
		T1 value1;
		T2 value2;
		T3 value3;
		T4 value4;
		T5 value5;
		T6 value6;
		T7 value7;
		
};




//##########################################################################################
//##########################################################################################
//############		
//############		1-Element Tuple Class
//############		
//##########################################################################################
//##########################################################################################




template < typename T1 >
class Tuple<T1,
			internal::NullType,
			internal::NullType,
			internal::NullType,
			internal::NullType,
			internal::NullType,
			internal::NullType>
{
	public:
		
		
		RIM_INLINE Tuple( const T1& v1 )
			:	value1( v1 )
		{
		}
		
		T1 value1;
		
};




//##########################################################################################
//##########################################################################################
//############		
//############		2-Element Tuple Class
//############		
//##########################################################################################
//##########################################################################################





template < typename T1, typename T2 >
class Tuple<T1,
			T2,
			internal::NullType,
			internal::NullType,
			internal::NullType,
			internal::NullType,
			internal::NullType>
{
	public:
		
		
		RIM_INLINE Tuple( const T1& v1, const T2& v2 )
			:	value1( v1 ),
				value2( v2 )
		{
		}
		
		T1 value1;
		T2 value2;
		
		
};



//##########################################################################################
//##########################################################################################
//############		
//############		3-Element Tuple Class
//############		
//##########################################################################################
//##########################################################################################




template < typename T1, typename T2, typename T3 >
class Tuple<T1,
			T2,
			T3,
			internal::NullType,
			internal::NullType,
			internal::NullType,
			internal::NullType>
{
	public:
		
		
		RIM_INLINE Tuple( const T1& v1, const T2& v2, const T3& v3 )
			:	value1( v1 ),
				value2( v2 ),
				value3( v3 )
		{
		}
		
		T1 value1;
		T2 value2;
		T3 value3;
		
};




//##########################################################################################
//##########################################################################################
//############		
//############		4-Element Tuple Class
//############		
//##########################################################################################
//##########################################################################################




template < typename T1, typename T2, typename T3, typename T4 >
class Tuple<T1,
			T2,
			T3,
			T4,
			internal::NullType,
			internal::NullType,
			internal::NullType>
{
	public:
		
		
		RIM_INLINE Tuple( const T1& v1, const T2& v2, const T3& v3, const T4& v4 )
			:	value1( v1 ),
				value2( v2 ),
				value3( v3 ),
				value4( v4 )
		{
		}
		
		T1 value1;
		T2 value2;
		T3 value3;
		T4 value4;
		
};




//##########################################################################################
//##########################################################################################
//############		
//############		5-Element Tuple Class
//############		
//##########################################################################################
//##########################################################################################




template < typename T1, typename T2, typename T3, typename T4, typename T5 >
class Tuple<T1,
			T2,
			T3,
			T4,
			T5,
			internal::NullType,
			internal::NullType>
{
	public:
		
		
		RIM_INLINE Tuple( const T1& v1, const T2& v2, const T3& v3, const T4& v4,
						const T5& v5 )
			:	value1( v1 ),
				value2( v2 ),
				value3( v3 ),
				value4( v4 ),
				value5( v5 )
		{
		}
		
		T1 value1;
		T2 value2;
		T3 value3;
		T4 value4;
		T5 value5;
		
};




//##########################################################################################
//##########################################################################################
//############		
//############		6-Element Tuple Class
//############		
//##########################################################################################
//##########################################################################################




template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
class Tuple<T1,
			T2,
			T3,
			T4,
			T5,
			T6,
			internal::NullType>
{
	public:
		
		
		RIM_INLINE Tuple( const T1& v1, const T2& v2, const T3& v3, const T4& v4,
						const T5& v5, const T6& v6 )
			:	value1( v1 ),
				value2( v2 ),
				value3( v3 ),
				value4( v4 ),
				value5( v5 ),
				value6( v6 )
		{
		}
		
		T1 value1;
		T2 value2;
		T3 value3;
		T4 value4;
		T5 value5;
		T6 value6;
		
};



//##########################################################################################
//***************************  End Rim Language Namespace  *********************************
RIM_LANGUAGE_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_TUPLE_H
