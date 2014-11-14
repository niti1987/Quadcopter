/*
 *  rimArrayMath.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 9/19/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ARRAY_MATH_H
#define INCLUDE_RIM_ARRAY_MATH_H


#include "rimMathConfig.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


//##########################################################################################
//##########################################################################################
//############		
//############		Array Add Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
void add( T* destination, T b, Size number );


template < typename T >
void add( T* destination, const T* b, Size number );


template < typename T >
void add( T* destination, const T* a, const T* b, Size number );


template < typename T >
void add( T* destination, const T* a, T b, Size number );




//##########################################################################################
//##########################################################################################
//############		
//############		Array Subtract Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
void negate( T* destination, Size number );


template < typename T >
void negate( T* destination, const T* a, Size number );


template < typename T >
void subtract( T* destination, T b, Size number );


template < typename T >
void subtract( T* destination, const T* b, Size number );


template < typename T >
void subtract( T* destination, const T* a, const T* b, Size number );


template < typename T >
void subtract( T* destination, const T* a, T b, Size number );




//##########################################################################################
//##########################################################################################
//############		
//############		Array Multiply Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
void multiply( T* destination, T b, Size number );


template < typename T >
void multiply( T* destination, const T* b, Size number );


template < typename T >
void multiply( T* destination, const T* a, const T* b, Size number );


template < typename T >
void multiply( T* destination, const T* a, T b, Size number );




//##########################################################################################
//##########################################################################################
//############		
//############		Array Multiply-Add Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
void multiplyAdd( T* destination, T b, Size number );


template < typename T >
void multiplyAdd( T* destination, const T* b, Size number );


template < typename T >
void multiplyAdd( T* destination, const T* a, const T* b, Size number );


template < typename T >
void multiplyAdd( T* destination, const T* a, T b, Size number );




//##########################################################################################
//##########################################################################################
//############		
//############		Array Multiply-Subtract Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
void multiplySubtract( T* destination, T b, Size number );


template < typename T >
void multiplySubtract( T* destination, const T* b, Size number );


template < typename T >
void multiplySubtract( T* destination, const T* a, const T* b, Size number );


template < typename T >
void multiplySubtract( T* destination, const T* a, T b, Size number );




//##########################################################################################
//##########################################################################################
//############		
//############		Array Divide Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
void divide( T* destination, T b, Size number );


template < typename T >
void divide( T* destination, const T* b, Size number );


template < typename T >
void divide( T* destination, const T* a, const T* b, Size number );


template < typename T >
void divide( T* destination, const T* a, T b, Size number );




//##########################################################################################
//##########################################################################################
//############		
//############		Array Divide-Add Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
void divideAdd( T* destination, T b, Size number );


template < typename T >
void divideAdd( T* destination, const T* b, Size number );


template < typename T >
void divideAdd( T* destination, const T* a, const T* b, Size number );


template < typename T >
void divideAdd( T* destination, const T* a, T b, Size number );




//##########################################################################################
//##########################################################################################
//############		
//############		Array Divide-Subtract Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
void divideSubtract( T* destination, T b, Size number );


template < typename T >
void divideSubtract( T* destination, const T* b, Size number );


template < typename T >
void divideSubtract( T* destination, const T* a, const T* b, Size number );


template < typename T >
void divideSubtract( T* destination, const T* a, T b, Size number );




//##########################################################################################
//##########################################################################################
//############		
//############		Array Function Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
void abs( T* destination, Size number );


template < typename T >
void abs( T* destination, const T* a, Size number );




template < typename T >
void sqrt( T* destination, Size number );


template < typename T >
void sqrt( T* destination, const T* a, Size number );




template < typename T >
void floor( T* destination, Size number );


template < typename T >
void floor( T* destination, const T* a, Size number );




template < typename T >
void ceiling( T* destination, Size number );


template < typename T >
void ceiling( T* destination, const T* a, Size number );




template < typename T >
void min( T* destination, const T* a, const T* b, Size number );




template < typename T >
void max( T* destination, const T* a, const T* b, Size number );




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_ARRAY_MATH_H
