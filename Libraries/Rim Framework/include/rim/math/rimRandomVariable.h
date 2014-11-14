/*
 *  rimRandomVariable.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 5/8/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_RANDOM_VARIABLE_H
#define INCLUDE_RIM_RANDOM_VARIABLE_H


#include "rimMathConfig.h"


#include "../time/rimTime.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################





template < typename T >
class RandomVariable;




//##########################################################################################
//##########################################################################################
//############		
//############		Random Variable Class for the 'char' type
//############		
//##########################################################################################
//##########################################################################################




/// Random variable class for the char data type.
template <>
class RandomVariable<char>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Seed Type Declaration
			
			
			
			
			/// The underlying type used to represent the random seed.
			typedef unsigned char SeedType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a random variable with a default initial seed value.
			RIM_INLINE RandomVariable()
				:	seed( (SeedType)time::Time::getCurrent().getNanoseconds() )
			{
			}
			
			
			
			
			/// Create a random variable with the specified initial seed value.
			RIM_INLINE RandomVariable( SeedType newSeed )
				:	seed( newSeed )
			{
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Methods
			
			
			
			
			/// Generate a sample from the random variable and return the result.
			/**
			  * The value returned may have any numerical value representable by the
			  * random variable's data type. The pseudorandom values returned over
			  * successive calls to this function will lie in a uniform distribution.
			  */
			RIM_INLINE char sample()
			{
				advanceSeed();
				
				return seed;
			}
			
			
			
			
			/// Generate a sample from the random variable in the specified range.
			/**
			  * The value returned can have any numerical value between and including
			  * the minimum and maximum values specified. The pseudorandom values
			  * returned over successive calls to this function will lie in a uniform
			  * distribution.
			  */
			RIM_INLINE char sample( char min, char max )
			{
				advanceSeed();
				
				unsigned char uMin = *((unsigned char*)&min) + math::min<char>();
				unsigned char uMax = *((unsigned char*)&max) - math::min<char>();
				
				unsigned char a = (seed % (uMax - uMin + 1)) + *((unsigned char*)&min);
				
				return *((char*)&a);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Random Seed Accessor Methods
			
			
			
			
			/// Set the seed for the random variable.
			/**
			  * After setting the seed for the random variable, calls to the sample()
			  * methods will produce the same sequence of values for equal initial seed
			  * values.
			  */
			RIM_INLINE void setSeed( SeedType newSeed )
			{
				seed = newSeed;
			}
			
			
			
			
			/// Get the current state of the random variable.
			RIM_INLINE SeedType getSeed() const
			{
				return seed;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Seed Advance Method
			
			
			
			
			/// Advance the random variable's seed to its next value.
			RIM_INLINE void advanceSeed()
			{
				seed = (1664525*seed + 1013904223);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Member
			
			
			
			
			/// The current state of the random variable.
			SeedType seed;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Random Variable Class for the 'unsigned char' type
//############		
//##########################################################################################
//##########################################################################################




/// Random variable class for the unsigned char data type.
template <>
class RandomVariable<unsigned char>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Seed Type Declaration
			
			
			
			
			/// The underlying type used to represent the random seed.
			typedef unsigned char SeedType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a random variable with a default initial seed value.
			RIM_INLINE RandomVariable()
				:	seed( (SeedType)time::Time::getCurrent().getNanoseconds() )
			{
			}
			
			
			
			
			/// Create a random variable with the specified initial seed value.
			RIM_INLINE RandomVariable( SeedType newSeed )
				:	seed( newSeed )
			{
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Methods
			
			
			
			
			/// Generate a sample from the random variable and return the result.
			/**
			  * The value returned may have any numerical value representable by the
			  * random variable's data type. The pseudorandom values returned over
			  * successive calls to this function will lie in a uniform distribution.
			  */
			RIM_INLINE unsigned char sample()
			{
				advanceSeed();
				
				return seed;
			}
			
			
			
			
			/// Generate a sample from the random variable in the specified range.
			/**
			  * The value returned can have any numerical value between and including
			  * the minimum and maximum values specified. The pseudorandom values
			  * returned over successive calls to this function will lie in a uniform
			  * distribution.
			  */
			RIM_INLINE unsigned char sample( unsigned char min, unsigned char max )
			{
				advanceSeed();
				
				return (seed % (max - min + 1)) + min;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Random Seed Accessor Methods
			
			
			
			
			/// Set the seed for the random variable.
			/**
			  * After setting the seed for the random variable, calls to the sample()
			  * methods will produce the same sequence of values for equal initial seed
			  * values.
			  */
			RIM_INLINE void setSeed( SeedType newSeed )
			{
				seed = newSeed;
			}
			
			
			
			
			/// Get the current state of the random variable.
			RIM_INLINE SeedType getSeed() const
			{
				return seed;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Seed Advance Method
			
			
			
			
			/// Advance the random variable's seed to its next value.
			RIM_INLINE void advanceSeed()
			{
				seed = (1664525*seed + 1013904223);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Member
			
			
			
			
			/// The current state of the random variable.
			SeedType seed;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Random Variable Class for the 'short' type
//############		
//##########################################################################################
//##########################################################################################




/// Random variable class for the short data type.
template <>
class RandomVariable<short>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Seed Type Declaration
			
			
			
			
			/// The underlying type used to represent the random seed.
			typedef unsigned short SeedType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a random variable with a default initial seed value.
			RIM_INLINE RandomVariable()
				:	seed( (SeedType)time::Time::getCurrent().getNanoseconds() )
			{
			}
			
			
			
			
			/// Create a random variable with the specified initial seed value.
			RIM_INLINE RandomVariable( SeedType newSeed )
				:	seed( newSeed )
			{
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Methods
			
			
			
			
			/// Generate a sample from the random variable and return the result.
			/**
			  * The value returned may have any numerical value representable by the
			  * random variable's data type. The pseudorandom values returned over
			  * successive calls to this function will lie in a uniform distribution.
			  */
			RIM_INLINE short sample()
			{
				advanceSeed();
				
				return seed;
			}
			
			
			
			
			/// Generate a sample from the random variable in the specified range.
			/**
			  * The value returned can have any numerical value between and including
			  * the minimum and maximum values specified. The pseudorandom values
			  * returned over successive calls to this function will lie in a uniform
			  * distribution.
			  */
			RIM_INLINE short sample( short min, short max )
			{
				advanceSeed();
				
				unsigned short uMin = *((unsigned short*)&min) + math::min<short>();
				unsigned short uMax = *((unsigned short*)&max) - math::min<short>();
				
				unsigned short a = (seed % (uMax - uMin + 1)) + *((unsigned short*)&min);
				
				return *((short*)&a);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Random Seed Accessor Methods
			
			
			
			
			/// Set the seed for the random variable.
			/**
			  * After setting the seed for the random variable, calls to the sample()
			  * methods will produce the same sequence of values for equal initial seed
			  * values.
			  */
			RIM_INLINE void setSeed( SeedType newSeed )
			{
				seed = newSeed;
			}
			
			
			
			
			/// Get the current state of the random variable.
			RIM_INLINE SeedType getSeed() const
			{
				return seed;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Seed Advance Method
			
			
			
			
			/// Advance the random variable's seed to its next value.
			RIM_INLINE void advanceSeed()
			{
				seed = (1664525*seed + 1013904223);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Member
			
			
			
			
			/// The current state of the random variable.
			SeedType seed;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Random Variable Class for the 'unsigned short' type
//############		
//##########################################################################################
//##########################################################################################




/// Random variable class for the unsigned short data type.
template <>
class RandomVariable<unsigned short>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Seed Type Declaration
			
			
			
			
			/// The underlying type used to represent the random seed.
			typedef unsigned short SeedType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a random variable with a default initial seed value.
			RIM_INLINE RandomVariable()
				:	seed( (SeedType)time::Time::getCurrent().getNanoseconds() )
			{
			}
			
			
			
			
			/// Create a random variable with the specified initial seed value.
			RIM_INLINE RandomVariable( SeedType newSeed )
				:	seed( newSeed )
			{
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Methods
			
			
			
			
			/// Generate a sample from the random variable and return the result.
			/**
			  * The value returned may have any numerical value representable by the
			  * random variable's data type. The pseudorandom values returned over
			  * successive calls to this function will lie in a uniform distribution.
			  */
			RIM_INLINE unsigned short sample()
			{
				advanceSeed();
				
				return seed;
			}
			
			
			
			
			/// Generate a sample from the random variable in the specified range.
			/**
			  * The value returned can have any numerical value between and including
			  * the minimum and maximum values specified. The pseudorandom values
			  * returned over successive calls to this function will lie in a uniform
			  * distribution.
			  */
			RIM_INLINE unsigned short sample( unsigned short min, unsigned short max )
			{
				advanceSeed();
				
				return (seed % (max - min + 1)) + min;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Random Seed Accessor Methods
			
			
			
			
			/// Set the seed for the random variable.
			/**
			  * After setting the seed for the random variable, calls to the sample()
			  * methods will produce the same sequence of values for equal initial seed
			  * values.
			  */
			RIM_INLINE void setSeed( SeedType newSeed )
			{
				seed = newSeed;
			}
			
			
			
			
			/// Get the current state of the random variable.
			RIM_INLINE SeedType getSeed() const
			{
				return seed;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Seed Advance Method
			
			
			
			
			/// Advance the random variable's seed to its next value.
			RIM_INLINE void advanceSeed()
			{
				seed = (1664525*seed + 1013904223);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Member
			
			
			
			
			/// The current state of the random variable.
			SeedType seed;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Random Variable Class for the 'int' type
//############		
//##########################################################################################
//##########################################################################################





/// Random variable class for the int data type.
template <>
class RandomVariable<int>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Seed Type Declaration
			
			
			
			
			/// The underlying type used to represent the random seed.
			typedef unsigned int SeedType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a random variable with a default initial seed value.
			RIM_INLINE RandomVariable()
				:	seed( (SeedType)time::Time::getCurrent().getNanoseconds() )
			{
			}
			
			
			
			
			/// Create a random variable with the specified initial seed value.
			RIM_INLINE RandomVariable( SeedType newSeed )
				:	seed( newSeed )
			{
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Methods
			
			
			
			
			/// Generate a sample from the random variable and return the result.
			/**
			  * The value returned may have any numerical value representable by the
			  * random variable's data type. The pseudorandom values returned over
			  * successive calls to this function will lie in a uniform distribution.
			  */
			RIM_INLINE int sample()
			{
				advanceSeed();
				
				return seed;
			}
			
			
			
			
			/// Generate a sample from the random variable in the specified range.
			/**
			  * The value returned can have any numerical value between and including
			  * the minimum and maximum values specified. The pseudorandom values
			  * returned over successive calls to this function will lie in a uniform
			  * distribution.
			  */
			RIM_INLINE int sample( int min, int max )
			{
				advanceSeed();
				
				unsigned int uMin = *((unsigned int*)&min) + math::min<int>();
				unsigned int uMax = *((unsigned int*)&max) - math::min<int>();
				
				unsigned int a = (seed % (uMax - uMin + 1)) + *((unsigned int*)&min);
				
				return *((int*)&a);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Random Seed Accessor Methods
			
			
			
			
			/// Set the seed for the random variable.
			/**
			  * After setting the seed for the random variable, calls to the sample()
			  * methods will produce the same sequence of values for equal initial seed
			  * values.
			  */
			RIM_INLINE void setSeed( SeedType newSeed )
			{
				seed = newSeed;
			}
			
			
			
			
			/// Get the current state of the random variable.
			RIM_INLINE SeedType getSeed() const
			{
				return seed;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Seed Advance Method
			
			
			
			
			/// Advance the random variable's seed to its next value.
			RIM_INLINE void advanceSeed()
			{
				seed = (1664525*seed + 1013904223);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Member
			
			
			
			
			/// The current state of the random variable.
			SeedType seed;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Random Variable Class for the 'unsigned int' type
//############		
//##########################################################################################
//##########################################################################################




/// Random variable class for the unsigned int data type.
template <>
class RandomVariable<unsigned int>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Seed Type Declaration
			
			
			
			
			/// The underlying type used to represent the random seed.
			typedef unsigned int SeedType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a random variable with a default initial seed value.
			RIM_INLINE RandomVariable()
				:	seed( (SeedType)time::Time::getCurrent().getNanoseconds() )
			{
			}
			
			
			
			
			/// Create a random variable with the specified initial seed value.
			RIM_INLINE RandomVariable( SeedType newSeed )
				:	seed( newSeed )
			{
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Methods
			
			
			
			
			/// Generate a sample from the random variable and return the result.
			/**
			  * The value returned may have any numerical value representable by the
			  * random variable's data type. The pseudorandom values returned over
			  * successive calls to this function will lie in a uniform distribution.
			  */
			RIM_INLINE unsigned int sample()
			{
				advanceSeed();
				
				return seed;
			}
			
			
			
			
			/// Generate a sample from the random variable in the specified range.
			/**
			  * The value returned can have any numerical value between and including
			  * the minimum and maximum values specified. The pseudorandom values
			  * returned over successive calls to this function will lie in a uniform
			  * distribution.
			  */
			RIM_INLINE unsigned int sample( unsigned int min, unsigned int max )
			{
				advanceSeed();
				
				return (seed % (max - min + 1)) + min;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Random Seed Accessor Methods
			
			
			
			
			/// Set the seed for the random variable.
			/**
			  * After setting the seed for the random variable, calls to the sample()
			  * methods will produce the same sequence of values for equal initial seed
			  * values.
			  */
			RIM_INLINE void setSeed( SeedType newSeed )
			{
				seed = newSeed;
			}
			
			
			
			
			/// Get the current state of the random variable.
			RIM_INLINE SeedType getSeed() const
			{
				return seed;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Seed Advance Method
			
			
			
			
			/// Advance the random variable's seed to its next value.
			RIM_INLINE void advanceSeed()
			{
				seed = (1664525*seed + 1013904223);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Member
			
			
			
			
			/// The current state of the random variable.
			SeedType seed;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Random Variable Class for the 'long' type
//############		
//##########################################################################################
//##########################################################################################




/// Random variable class for the long data type.
template <>
class RandomVariable<long>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Seed Type Declaration
			
			
			
			
			/// The underlying type used to represent the random seed.
			typedef unsigned long SeedType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a random variable with a default initial seed value.
			RIM_INLINE RandomVariable()
				:	seed( (SeedType)time::Time::getCurrent().getNanoseconds() )
			{
			}
			
			
			
			
			/// Create a random variable with the specified initial seed value.
			RIM_INLINE RandomVariable( SeedType newSeed )
				:	seed( newSeed )
			{
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Methods
			
			
			
			
			/// Generate a sample from the random variable and return the result.
			/**
			  * The value returned may have any numerical value representable by the
			  * random variable's data type. The pseudorandom values returned over
			  * successive calls to this function will lie in a uniform distribution.
			  */
			RIM_INLINE long sample()
			{
				advanceSeed();
				
				return seed;
			}
			
			
			
			
			/// Generate a sample from the random variable in the specified range.
			/**
			  * The value returned can have any numerical value between and including
			  * the minimum and maximum values specified. The pseudorandom values
			  * returned over successive calls to this function will lie in a uniform
			  * distribution.
			  */
			RIM_INLINE long sample( long min, long max )
			{
				advanceSeed();
				
				unsigned long uMin = *((unsigned long*)&min) + math::min<long>();
				unsigned long uMax = *((unsigned long*)&max) - math::min<long>();
				
				unsigned long a = (seed % (uMax - uMin + 1)) + *((unsigned long*)&min);
				
				return *((long*)&a);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Random Seed Accessor Methods
			
			
			
			
			/// Set the seed for the random variable.
			/**
			  * After setting the seed for the random variable, calls to the sample()
			  * methods will produce the same sequence of values for equal initial seed
			  * values.
			  */
			RIM_INLINE void setSeed( SeedType newSeed )
			{
				seed = newSeed;
			}
			
			
			
			
			/// Get the current state of the random variable.
			RIM_INLINE SeedType getSeed() const
			{
				return seed;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Seed Advance Method
			
			
			
			
			/// Advance the random variable's seed to its next value.
			RIM_INLINE void advanceSeed()
			{
				seed = (1664525*seed + 1013904223);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Member
			
			
			
			
			/// The current state of the random variable.
			SeedType seed;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Random Variable Class for the 'unsigned long' type
//############		
//##########################################################################################
//##########################################################################################




/// Random variable class for the unsigned long data type.
template <>
class RandomVariable<unsigned long>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Seed Type Declaration
			
			
			
			
			/// The underlying type used to represent the random seed.
			typedef unsigned long SeedType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a random variable with a default initial seed value.
			RIM_INLINE RandomVariable()
				:	seed( (SeedType)time::Time::getCurrent().getNanoseconds() )
			{
			}
			
			
			
			
			/// Create a random variable with the specified initial seed value.
			RIM_INLINE RandomVariable( SeedType newSeed )
				:	seed( newSeed )
			{
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Methods
			
			
			
			
			/// Generate a sample from the random variable and return the result.
			/**
			  * The value returned may have any numerical value representable by the
			  * random variable's data type. The pseudorandom values returned over
			  * successive calls to this function will lie in a uniform distribution.
			  */
			RIM_INLINE unsigned long sample()
			{
				advanceSeed();
				
				return seed;
			}
			
			
			
			
			/// Generate a sample from the random variable in the specified range.
			/**
			  * The value returned can have any numerical value between and including
			  * the minimum and maximum values specified. The pseudorandom values
			  * returned over successive calls to this function will lie in a uniform
			  * distribution.
			  */
			RIM_INLINE unsigned long sample( unsigned long min, unsigned long max )
			{
				advanceSeed();
				
				return (seed % (max - min + 1)) + min;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Random Seed Accessor Methods
			
			
			
			
			/// Set the seed for the random variable.
			/**
			  * After setting the seed for the random variable, calls to the sample()
			  * methods will produce the same sequence of values for equal initial seed
			  * values.
			  */
			RIM_INLINE void setSeed( SeedType newSeed )
			{
				seed = newSeed;
			}
			
			
			
			
			/// Get the current state of the random variable.
			RIM_INLINE SeedType getSeed() const
			{
				return seed;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Seed Advance Method
			
			
			
			
			/// Advance the random variable's seed to its next value.
			RIM_INLINE void advanceSeed()
			{
				seed = (1664525*seed + 1013904223);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Member
			
			
			
			
			/// The current state of the random variable.
			SeedType seed;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Random Variable Class for the 'long long' type
//############		
//##########################################################################################
//##########################################################################################




/// Random variable class for the long long data type.
template <>
class RandomVariable<long long>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Seed Type Declaration
			
			
			
			
			/// The underlying type used to represent the random seed.
			typedef unsigned long long SeedType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a random variable with a default initial seed value.
			RIM_INLINE RandomVariable()
				:	seed( (SeedType)time::Time::getCurrent().getNanoseconds() )
			{
			}
			
			
			
			
			/// Create a random variable with the specified initial seed value.
			RIM_INLINE RandomVariable( SeedType newSeed )
				:	seed( newSeed )
			{
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Methods
			
			
			
			
			/// Generate a sample from the random variable and return the result.
			/**
			  * The value returned may have any numerical value representable by the
			  * random variable's data type. The pseudorandom values returned over
			  * successive calls to this function will lie in a uniform distribution.
			  */
			RIM_INLINE long long sample()
			{
				advanceSeed();
				
				return seed;
			}
			
			
			
			
			/// Generate a sample from the random variable in the specified range.
			/**
			  * The value returned can have any numerical value between and including
			  * the minimum and maximum values specified. The pseudorandom values
			  * returned over successive calls to this function will lie in a uniform
			  * distribution.
			  */
			RIM_INLINE long long sample( long long min, long long max )
			{
				advanceSeed();
				
				unsigned long long uMin = *((unsigned long long*)&min) + math::min<long long>();
				unsigned long long uMax = *((unsigned long long*)&max) - math::min<long long>();
				
				unsigned long long a = (seed % (uMax - uMin + 1)) + *((unsigned long long*)&min);
				
				return *((long long*)&a);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Random Seed Accessor Methods
			
			
			
			
			/// Set the seed for the random variable.
			/**
			  * After setting the seed for the random variable, calls to the sample()
			  * methods will produce the same sequence of values for equal initial seed
			  * values.
			  */
			RIM_INLINE void setSeed( SeedType newSeed )
			{
				seed = newSeed;
			}
			
			
			
			
			/// Get the current state of the random variable.
			RIM_INLINE SeedType getSeed() const
			{
				return seed;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Seed Advance Method
			
			
			
			
			/// Advance the random variable's seed to its next value.
			RIM_INLINE void advanceSeed()
			{
				seed = (1664525*seed + 1013904223);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Member
			
			
			
			
			/// The current state of the random variable.
			SeedType seed;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Random Variable Class for the 'unsigned long long' type
//############		
//##########################################################################################
//##########################################################################################




/// Random variable class for the unsigned long long data type.
template <>
class RandomVariable<unsigned long long>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Seed Type Declaration
			
			
			
			
			/// The underlying type used to represent the random seed.
			typedef unsigned long long SeedType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a random variable with a default initial seed value.
			RIM_INLINE RandomVariable()
				:	seed( (SeedType)time::Time::getCurrent().getNanoseconds() )
			{
			}
			
			
			
			
			/// Create a random variable with the specified initial seed value.
			RIM_INLINE RandomVariable( SeedType newSeed )
				:	seed( newSeed )
			{
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Methods
			
			
			
			
			/// Generate a sample from the random variable and return the result.
			/**
			  * The value returned may have any numerical value representable by the
			  * random variable's data type. The pseudorandom values returned over
			  * successive calls to this function will lie in a uniform distribution.
			  */
			RIM_INLINE unsigned long long sample()
			{
				advanceSeed();
				
				return seed;
			}
			
			
			
			
			/// Generate a sample from the random variable in the specified range.
			/**
			  * The value returned can have any numerical value between and including
			  * the minimum and maximum values specified. The pseudorandom values
			  * returned over successive calls to this function will lie in a uniform
			  * distribution.
			  */
			RIM_INLINE unsigned long long sample( unsigned long long min, unsigned long long max )
			{
				advanceSeed();
				
				return (seed % (max - min + 1)) + min;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Random Seed Accessor Methods
			
			
			
			
			/// Set the seed for the random variable.
			/**
			  * After setting the seed for the random variable, calls to the sample()
			  * methods will produce the same sequence of values for equal initial seed
			  * values.
			  */
			RIM_INLINE void setSeed( SeedType newSeed )
			{
				seed = newSeed;
			}
			
			
			
			
			/// Get the current state of the random variable.
			RIM_INLINE SeedType getSeed() const
			{
				return seed;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Seed Advance Method
			
			
			
			
			/// Advance the random variable's seed to its next value.
			RIM_INLINE void advanceSeed()
			{
				seed = (1664525*seed + 1013904223);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Member
			
			
			
			
			/// The current state of the random variable.
			SeedType seed;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Random Variable Class for the 'float' type
//############		
//##########################################################################################
//##########################################################################################





/// Random variable class for the float data type.
template <>
class RandomVariable<float>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Seed Type Declaration
			
			
			
			
			/// The underlying type used to represent the random seed.
			typedef UInt32 SeedType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a random variable with a default initial seed value.
			RIM_INLINE RandomVariable()
				:	seed( (SeedType)time::Time::getCurrent().getNanoseconds() )
			{
			}
			
			
			
			
			/// Create a random variable with the specified initial seed value.
			RIM_INLINE RandomVariable( SeedType newSeed )
				:	seed( newSeed )
			{
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Methods
			
			
			
			
			/// Generate a sample from the random variable and return the result.
			/**
			  * The value returned may have any numerical value representable by the
			  * random variable's data type. The pseudorandom values returned over
			  * successive calls to this function will lie in a uniform distribution.
			  */
			RIM_INLINE float sample()
			{
				advanceSeed();
				
				UInt32 a = (seed & UInt32(0x007FFFFF)) | UInt32(0x3F800000);
				
				return (*((float*)&a) - 1.5f)*2.0f*math::max<float>();
			}
			
			
			
			
			/// Generate a sample from the random variable in the specified range.
			/**
			  * The value returned can have any numerical value between and including
			  * the minimum and maximum values specified. The pseudorandom values
			  * returned over successive calls to this function will lie in a uniform
			  * distribution.
			  */
			RIM_INLINE float sample( float min, float max )
			{
				advanceSeed();
				
				UInt32 a = (seed & UInt32(0x007FFFFF)) | UInt32(0x3F800000);
				
				return (*((float*)&a) - 1.0f)*(max - min) + min;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Random Seed Accessor Methods
			
			
			
			
			/// Set the seed for the random variable.
			/**
			  * After setting the seed for the random variable, calls to the sample()
			  * methods will produce the same sequence of values for equal initial seed
			  * values.
			  */
			RIM_INLINE void setSeed( SeedType newSeed )
			{
				seed = newSeed;
			}
			
			
			
			
			/// Get the current state of the random variable.
			RIM_INLINE SeedType getSeed() const
			{
				return seed;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Seed Advance Method
			
			
			
			
			/// Advance the random variable's seed to its next value.
			RIM_INLINE void advanceSeed()
			{
				seed = SeedType(1664525)*seed + SeedType(1013904223);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Member
			
			
			
			
			/// The current state of the random variable.
			SeedType seed;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Random Variable Class for the 'double' type
//############		
//##########################################################################################
//##########################################################################################




/// Random variable class for the double data type.
template <>
class RandomVariable<double>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Seed Type Declaration
			
			
			
			
			/// The underlying type used to represent the random seed.
			typedef UInt64 SeedType;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a random variable with a default initial seed value.
			RIM_INLINE RandomVariable()
				:	seed( (SeedType)time::Time::getCurrent().getNanoseconds() )
			{
			}
			
			
			
			
			/// Create a random variable with the specified initial seed value.
			RIM_INLINE RandomVariable( SeedType newSeed )
				:	seed( newSeed )
			{
			}
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sample Methods
			
			
			
			
			/// Generate a sample from the random variable and return the result.
			/**
			  * The value returned may have any numerical value representable by the
			  * random variable's data type. The pseudorandom values returned over
			  * successive calls to this function will lie in a uniform distribution.
			  */
			RIM_INLINE double sample()
			{
				advanceSeed();
				
				UInt64 a = (seed & UInt64(0x000FFFFFFFFFFFFFull)) | UInt64(0x3FF0000000000000ull);
				
				return (*((double*)&a) - 1.5)*2.0*math::max<double>();
			}
			
			
			
			
			/// Generate a sample from the random variable in the specified range.
			/**
			  * The value returned can have any numerical value between and including
			  * the minimum and maximum values specified. The pseudorandom values
			  * returned over successive calls to this function will lie in a uniform
			  * distribution.
			  */
			RIM_INLINE double sample( double min, double max )
			{
				advanceSeed();
				
				UInt64 a = (seed & UInt64(0x000FFFFFFFFFFFFFull)) | UInt64(0x3FF0000000000000ull);
				
				return (*((double*)&a) - 1.0)*(max - min) + min;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Random Seed Accessor Methods
			
			
			
			
			/// Set the seed for the random variable.
			/**
			  * After setting the seed for the random variable, calls to the sample()
			  * methods will produce the same sequence of values for equal initial seed
			  * values.
			  */
			RIM_INLINE void setSeed( SeedType newSeed )
			{
				seed = newSeed;
			}
			
			
			
			
			/// Get the current state of the random variable.
			RIM_INLINE SeedType getSeed() const
			{
				return seed;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Seed Advance Method
			
			
			
			
			/// Advance the random variable's seed to its next value.
			RIM_INLINE void advanceSeed()
			{
				seed = SeedType(1664525)*seed + SeedType(1013904223);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Member
			
			
			
			
			/// The current state of the random variable.
			SeedType seed;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Global Random Number Generation Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
RIM_INLINE static RandomVariable<T>& getGlobalRandomVariable()
{
	static RandomVariable<T> randomVariable;
	
	return randomVariable;
}




template < typename T >
RIM_INLINE T random()
{
	return getGlobalRandomVariable<T>().sample();
}




template < typename T >
RIM_INLINE T random( T min, T max )
{
	return getGlobalRandomVariable<T>().sample( min, max );
}




template < typename T >
RIM_INLINE void setRandomSeed( T newSeed )
{
	getGlobalRandomVariable<T>().setSeed( *(typename RandomVariable<T>::SeedType*)(&newSeed) );
}




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_RANDOM_VARIABLE_H
