/*
 *  rimConvolution.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 4/1/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_CONVOLUTION_H
#define INCLUDE_RIM_CONVOLUTION_H


#include "rimMathConfig.h"


#include "rimComplex.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


//##########################################################################################
//##########################################################################################
//############		
//############		1D Convolution Methods
//############		
//##########################################################################################
//##########################################################################################




/// Convolve the specified input signal with the given filter kernel.
/**
  * The results of the transform are stored in the output data array which must
  * have space for (inputSize + fiterSize - 1) elements.
  *
  * This is a direct convolution algorithm and should realistically only be
  * used for offline computation or for short filter lengths.
  *
  * The method returns whether or not the convolution was successfully performed.
  * The method may fail if any pointer is NULL or if the filter size is 0.
  */
template < typename T >
Bool convolve( const T* input, Size inputSize, const T* filter, Size filterSize, T* output );




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_CONVOLUTION_H
