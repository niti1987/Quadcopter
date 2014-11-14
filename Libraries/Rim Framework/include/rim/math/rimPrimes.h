/*
 *  rimPrimes.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 4/4/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PRIMES_H
#define INCLUDE_RIM_PRIMES_H


#include "rimMathConfig.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




/// Return a prime number larger than the specified value, but smaller than the next power of two.
template < typename T >
T nextPowerOf2Prime( T value );




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_PRIMES_H
