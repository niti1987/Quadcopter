/*
 *  rimFFT.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 4/4/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_FFT_H
#define INCLUDE_RIM_FFT_H


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
//############		1D Fourier Transform Methods
//############		
//##########################################################################################
//##########################################################################################




/// Compute the forward Fourier transform in-place on the specified array of complex numbers.
/**
  * The results of the transform are stored in the input data array.
  *
  * The method returns whether or not the FFT was successfully performed on the input data.
  * The method may fail if the data pointer is NULL or if the requested FFT size is not
  * a power of two.
  */
template < typename T >
Bool fft( Complex<T>* data, Size size );




/// Compute the inverse Fourier transform in-place on the specified array of complex numbers.
/**
  * The results of the transform are stored in the input data array.
  *
  * The method returns whether or not the iFFT was successfully performed on the input data.
  * The method may fail if the data pointer is NULL or if the requested FFT size is not
  * a power of two.
  */
template < typename T >
Bool ifft( Complex<T>* data, Size size );




/// Shift the zero-frequency components of the specified array to the center of the array.
/**
  * This can be useful when visualizing the output of an FFT.
  *
  * The method return whether or not the operation was successful. It may fail if the
  * data pointer is NULL or if the size is not divisible by 2.
  */
template < typename T >
Bool fftShift( Complex<T>* data, Size size );




//##########################################################################################
//##########################################################################################
//############		
//############		2D Fourier Transform Methods
//############		
//##########################################################################################
//##########################################################################################




/// Compute the forward 2D Fourier transform in-place on the specified array of complex numbers.
/**
  * The input data should be stored in a row-major format, with each row representing a
  * contiguous block of complex numbers. The results of the transform are stored in the input data array.
  *
  * The method returns whether or not the FFT was successfully performed on the input data.
  * The method may fail if the data pointer is NULL or if the requested FFT width or height is not
  * a power of two.
  */
template < typename T >
Bool fft2D( Complex<T>* data, Size width, Size height );




/// Compute the inverse 2D Fourier transform in-place on the specified array of complex numbers.
/**
  * The input data should be stored in a row-major format, with each row representing a
  * contiguous block of complex numbers. The results of the transform are stored in the input data array.
  *
  * The method returns whether or not the FFT was successfully performed on the input data.
  * The method may fail if the data pointer is NULL or if the requested FFT width or height is not
  * a power of two.
  */
template < typename T >
Bool ifft2D( Complex<T>* data, Size width, Size height );




/// Shift the zero-frequency components of the specified 2D matrix to the center of the matrix.
/**
  * This can be useful when visualizing the output of an FFT.
  *
  * The method return whether or not the operation was successful. It may fail if the
  * data pointer is NULL or if the width or height are not divisible by 2.
  */
template < typename T >
Bool fftShift2D( Complex<T>* data, Size width, Size height );




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_FFT_H
