/*
 *  rimAtomics.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 4/1/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ATOMICS_H
#define INCLUDE_RIM_ATOMICS_H


#include "rimThreadsConfig.h"


//##########################################################################################
//***************************  Start Rim Threads Namespace  ********************************
RIM_THREADS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




namespace atomic
{


//##########################################################################################
//##########################################################################################
//############		
//############		Operate-Then-Read Method Declarations
//############		
//##########################################################################################
//##########################################################################################





template < typename T >
T addAndRead( T& operand, T value );




template < typename T >
T incrementAndRead( T& operand );




template < typename T >
T subAndRead( T& operand, T value );




template < typename T >
T decrementAndRead( T& operand );




template < typename T >
T orAndRead( T& operand, T value );




template < typename T >
T andAndRead( T& operand, T value );




template < typename T >
T xorAndRead( T& operand, T value );




template < typename T >
T nandAndRead( T& operand, T value );




//##########################################################################################
//##########################################################################################
//############		
//############		Read-Then-Operate Method Declarations
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
T readAndIncrement( T& operand );




template < typename T >
T readAndDecrement( T& operand );




template < typename T >
T readAndAdd( T& operand, T value );




template < typename T >
T readAndSub( T& operand, T value );




template < typename T >
T readAndOr( T& operand, T value );




template < typename T >
T readAndAnd( T& operand, T value );




template < typename T >
T readAndXor( T& operand, T value );




template < typename T >
T readAndNand( T& operand, T value );




//##########################################################################################
//##########################################################################################
//############		
//############		Operate-Then-Read Methods (GCC)
//############		
//##########################################################################################
//##########################################################################################


#if defined(RIM_COMPILER_GCC)


template < typename T >
RIM_INLINE T addAndRead( T& operand, T value )
{
	return __sync_add_and_fetch( &operand, value );
}




template < typename T >
RIM_INLINE T incrementAndRead( T& operand )
{
	return __sync_add_and_fetch( &operand, T(1) );
}




template < typename T >
RIM_INLINE T subAndRead( T& operand, T value )
{
	return __sync_sub_and_fetch( &operand, value );
}




template < typename T >
RIM_INLINE T decrementAndRead( T& operand )
{
	return __sync_sub_and_fetch( &operand, T(1) );
}




template < typename T >
RIM_INLINE T orAndRead( T& operand, T value )
{
	return __sync_or_and_fetch( &operand, value );
}




template < typename T >
RIM_INLINE T andAndRead( T& operand, T value )
{
	return __sync_and_and_fetch( &operand, value );
}




template < typename T >
RIM_INLINE T xorAndRead( T& operand, T value )
{
	return __sync_xor_and_fetch( &operand, value );
}




template < typename T >
RIM_INLINE T nandAndRead( T& operand, T value )
{
	return __sync_nand_and_fetch( &operand, value );
}



#elif defined(RIM_COMPILER_MSVC)



template < typename T >
RIM_INLINE T subAndRead( T& operand, T value )
{
	return addAndRead( operand, -value );
}



#endif




//##########################################################################################
//##########################################################################################
//############		
//############		Operate-Then-Read Methods (GCC)
//############		
//##########################################################################################
//##########################################################################################


#if defined(RIM_COMPILER_GCC)


template < typename T >
RIM_INLINE T readAndIncrement( T& operand )
{
	return __sync_fetch_and_add( &operand, T(1) );
}




template < typename T >
RIM_INLINE T readAndAdd( T& operand, T value )
{
	return __sync_fetch_and_add( &operand, value );
}




template < typename T >
RIM_INLINE T readAndSub( T& operand, T value )
{
	return __sync_fetch_and_sub( &operand, value );
}




template < typename T >
RIM_INLINE T readAndDecrement( T& operand )
{
	return __sync_fetch_and_sub( &operand, T(1) );
}




template < typename T >
RIM_INLINE T readAndOr( T& operand, T value )
{
	return __sync_fetch_and_or( &operand, value );
}




template < typename T >
RIM_INLINE T readAndAnd( T& operand, T value )
{
	return __sync_fetch_and_and( &operand, value );
}




template < typename T >
RIM_INLINE T readAndXor( T& operand, T value )
{
	return __sync_fetch_and_xor( &operand, value );
}




template < typename T >
RIM_INLINE T readAndNand( T& operand, T value )
{
	return __sync_fetch_and_nand( &operand, value );
}



#elif defined(RIM_COMPILER_MSVC)



template < typename T >
RIM_INLINE T readAndSub( T& operand, T value )
{
	return readAndAdd( operand, -value );
}



#endif




//##########################################################################################
//##########################################################################################
//############		
//############		Atomic Class Declaration
//############		
//##########################################################################################
//##########################################################################################




/// A class that wraps a primitive-type value in atomic operations.
template < typename T >
class Atomic
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new atomic variable with the default initial value.
			RIM_FORCE_INLINE Atomic()
				:	value()
			{
			}
			
			
			
			
			/// Create a new atomic variable with the specified initial value.
			RIM_FORCE_INLINE Atomic( T newValue )
				:	value( newValue )
			{
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Conversion Operators
			
			
			
			
			/// Get the currently stored atomic value.
			RIM_FORCE_INLINE operator T () const
			{
				return value;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Increment Operators
			
			
			
			
			/// Prefix increment operator.
			RIM_INLINE T operator ++ ()
			{
				return incrementAndRead( value );
			}
			
			
			
			
			/// Postfix increment operator.
			RIM_INLINE T operator ++ ( int )
			{
				return readAndIncrement( value );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Decrement Operators
			
			
			
			
			/// Prefix increment operator.
			RIM_INLINE T operator -- ()
			{
				return decrementAndRead( value );
			}
			
			
			
			
			/// Postfix increment operator.
			RIM_INLINE T operator -- ( int )
			{
				return readAndDecrement( value );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Add and Subtract Operators
			
			
			
			
			/// Add the specified value to this atomic value, returning the result.
			RIM_INLINE T operator += ( T a )
			{
				return addAndRead( value, a );
			}
			
			
			
			
			/// Subtract the specified value from this atomic value, returning the result.
			RIM_INLINE T operator -= ( T a )
			{
				return subAndRead( value, a );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bitwise Operators
			
			
			
			
			/// Bitwise AND the specified value and this atomic value, returning the result.
			RIM_INLINE T operator &= ( T a )
			{
				return andAndRead( value, a );
			}
			
			
			
			
			/// Bitwise OR the specified value and this atomic value, returning the result.
			RIM_INLINE T operator |= ( T a )
			{
				return orAndRead( value, a );
			}
			
			
			
			
			/// Bitwise XOR the specified value and this atomic value, returning the result.
			RIM_INLINE T operator ^= ( T a )
			{
				return orAndRead( value, a );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			/// The primitive-typed value stored by this atomic object.
			T value;
			
			
};




};



//##########################################################################################
//***************************  End Rim Threads Namespace  **********************************
RIM_THREADS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ATOMICS_H
