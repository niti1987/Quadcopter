/*
 *  rimCopy.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 12/5/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_COPY_H
#define INCLUDE_RIM_COPY_H


#include "rimUtilitiesConfig.h"


#include "../math/rimSIMD.h"


//##########################################################################################
//***************************  Start Rim Utilities Namespace  ******************************
RIM_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


//##########################################################################################
//##########################################################################################
//############		
//############		Primary Copy Method For Complex Types
//############		
//##########################################################################################
//##########################################################################################




/// Copy the specified number of objects from the source pointer to the destination pointer.
/**
  * This method does not check the validity of the arguments in order to not
  * impose unnecessary overhead on this low-level method.
  */
template < typename T >
RIM_INLINE void copy( T* destination, const T* source, Size number )
{
	const T* const sourceEnd = source + number;
	
	while ( source < sourceEnd )
	{
		*destination = *source;
		
		destination++;
		source++;
	}
}




template <>
RIM_FORCE_INLINE void copy( unsigned char* destination, const unsigned char* source, Size number )
{
	std::memcpy( (void*)destination, (void*)source, number*sizeof(unsigned char) );
}




template <>
RIM_FORCE_INLINE void copy( char* destination, const char* source, Size number )
{
	std::memcpy( (void*)destination, (void*)source, number*sizeof(char) );
}




template <>
RIM_FORCE_INLINE void copy( unsigned short* destination, const unsigned short* source, Size number )
{
	std::memcpy( (void*)destination, (void*)source, number*sizeof(unsigned short) );
}




template <>
RIM_FORCE_INLINE void copy( short* destination, const short* source, Size number )
{
	std::memcpy( (void*)destination, (void*)source, number*sizeof(short) );
}




template <>
RIM_FORCE_INLINE void copy( unsigned int* destination, const unsigned int* source, Size number )
{
	std::memcpy( (void*)destination, (void*)source, number*sizeof(unsigned int) );
}




template <>
RIM_FORCE_INLINE void copy( int* destination, const int* source, Size number )
{
	std::memcpy( (void*)destination, (void*)source, number*sizeof(int) );
}




template <>
RIM_FORCE_INLINE void copy( unsigned long* destination, const unsigned long* source, Size number )
{
	std::memcpy( (void*)destination, (void*)source, number*sizeof(unsigned long) );
}




template <>
RIM_FORCE_INLINE void copy( long* destination, const long* source, Size number )
{
	std::memcpy( (void*)destination, (void*)source, number*sizeof(long) );
}




template <>
RIM_FORCE_INLINE void copy( unsigned long long* destination, const unsigned long long* source, Size number )
{
	std::memcpy( (void*)destination, (void*)source, number*sizeof(unsigned long long) );
}




template <>
RIM_FORCE_INLINE void copy( long long* destination, const long long* source, Size number )
{
	std::memcpy( (void*)destination, (void*)source, number*sizeof(long long) );
}




template <>
RIM_FORCE_INLINE void copy( float* destination, const float* source, Size number )
{
	std::memcpy( (void*)destination, (void*)source, number*sizeof(float) );
}




template <>
RIM_FORCE_INLINE void copy( double* destination, const double* source, Size number )
{
	std::memcpy( (void*)destination, (void*)source, number*sizeof(double) );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Primary Convert Method For Complex Types
//############		
//##########################################################################################
//##########################################################################################




/// Copy the specified number of objects from the source pointer to the destination pointer, converting object type.
/**
  * This method does not check the validity of the arguments in order to not
  * impose unnecessary overhead on this low-level method.
  */
template < typename T, typename U >
RIM_INLINE void convert( T* destination, const U* source, Size number )
{
	const U* const sourceEnd = source + number;
	
	while ( source < sourceEnd )
	{
		*destination = *source;
		
		destination++;
		source++;
	}
}




//##########################################################################################
//##########################################################################################
//############		
//############		Memory Set Methods
//############		
//##########################################################################################
//##########################################################################################




/// Set the specified number of objects at the destination pointer to the given value.
/**
  * This method does not check the validity of the arguments in order to not
  * impose unnecessary overhead on this low-level method.
  */
template < typename T >
RIM_INLINE void set( T* destination, T value, Size number )
{
	const T* const destinationEnd = destination + number;
	
	while ( destination < destinationEnd )
	{
		*destination = value;
		destination++;
	}
}




template <>
RIM_INLINE void set( unsigned char* destination, unsigned char value, Size number )
{
	std::memset( destination, value, number );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Memory Zero Methods
//############		
//##########################################################################################
//##########################################################################################




/// Set the specified number of objects at the destination pointer to zero.
/**
  * This method does not check the validity of the arguments in order to not
  * impose unnecessary overhead on this low-level method.
  */
template < typename T >
RIM_INLINE void zero( T* destination, Size number )
{
	const T* const destinationEnd = destination + number;
	
	while ( destination < destinationEnd )
	{
		*destination = T();
		destination++;
	}
}




template <>
RIM_FORCE_INLINE void zero( unsigned char* destination, Size number )
{
	std::memset( (unsigned char*)destination, 0, number*sizeof(unsigned char) );
}




template <>
RIM_FORCE_INLINE void zero( char* destination, Size number )
{
	std::memset( (unsigned char*)destination, 0, number*sizeof(char) );
}




template <>
RIM_FORCE_INLINE void zero( unsigned short* destination, Size number )
{
	std::memset( (unsigned char*)destination, 0, number*sizeof(unsigned short) );
}




template <>
RIM_FORCE_INLINE void zero( short* destination, Size number )
{
	std::memset( (unsigned char*)destination, 0, number*sizeof(short) );
}




template <>
RIM_FORCE_INLINE void zero( unsigned int* destination, Size number )
{
	std::memset( (unsigned char*)destination, 0, number*sizeof(unsigned int) );
}




template <>
RIM_FORCE_INLINE void zero( int* destination, Size number )
{
	std::memset( (unsigned char*)destination, 0, number*sizeof(int) );
}




template <>
RIM_FORCE_INLINE void zero( unsigned long* destination, Size number )
{
	std::memset( (unsigned char*)destination, 0, number*sizeof(unsigned long) );
}




template <>
RIM_FORCE_INLINE void zero( long* destination, Size number )
{
	std::memset( (unsigned char*)destination, 0, number*sizeof(long) );
}




template <>
RIM_FORCE_INLINE void zero( unsigned long long* destination, Size number )
{
	std::memset( (unsigned char*)destination, 0, number*sizeof(unsigned long long) );
}




template <>
RIM_FORCE_INLINE void zero( long long* destination, Size number )
{
	std::memset( (unsigned char*)destination, 0, number*sizeof(long long) );
}




template <>
RIM_FORCE_INLINE void zero( float* destination, Size number )
{
	std::memset( (unsigned char*)destination, 0, number*sizeof(float) );
}




template <>
RIM_FORCE_INLINE void zero( double* destination, Size number )
{
	std::memset( (unsigned char*)destination, 0, number*sizeof(double) );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Memory Add Methods
//############		
//##########################################################################################
//##########################################################################################




/// Add the specified number of objects from the destination pointer to the source pointer.
/**
  * This method does not check the validity of the arguments in order to not
  * impose unnecessary overhead on this low-level method.
  */
template < typename T >
RIM_INLINE void add( T* destination, const T* source, Size number )
{
	const T* const sourceEnd = source + number;
	
	while ( source < sourceEnd )
	{
		*destination += *source;
		
		destination++;
		source++;
	}
}




//##########################################################################################
//***************************  End Rim Utilities Namespace  ********************************
RIM_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_COPY_H
