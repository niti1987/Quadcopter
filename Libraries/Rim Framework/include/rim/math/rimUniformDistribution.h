/*
 *  rimUniformDistribution.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 5/8/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_UNIFORM_DISTRIBUTION_H
#define INCLUDE_RIM_UNIFORM_DISTRIBUTION_H


#include "rimMathConfig.h"


#include "rimRandomVariable.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a uniform distribution of numbers of a certain type.
template < typename T >
class UniformDistribution
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a uniform distribution on the interval [0,1].
			RIM_INLINE UniformDistribution()
				:	minimum( 0 ),
					maximum( 1 ),
					randomVariable()
			{
			}
			
			
			
			
			/// Create a uniform distribution on the interval [0,1] with the specified random variable.
			/**
			  * The created uniform distribution will produce samples using the
			  * specified random variable.
			  */
			RIM_INLINE UniformDistribution( const RandomVariable<T>& newRandomVariable )
				:	minimum( 0 ),
					maximum( 1 ),
					randomVariable( newRandomVariable )
			{
			}
			
			
			
			
			/// Create a uniform distribution on the interval [ min, max ].
			RIM_INLINE UniformDistribution( T min, T max )
				:	minimum( min ),
					maximum( max ),
					randomVariable()
			{
			}
			
			
			
			
			/// Create a uniform distribution on the interval [ min, max ] using the specified random variable.
			/**
			  * The created uniform distribution will produce samples using the
			  * specified random variable.
			  */
			RIM_INLINE UniformDistribution( T min, T max, const RandomVariable<T>& newRandomVariable )
				:	minimum( min ),
					maximum( max ),
					randomVariable( newRandomVariable )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distribution Sample Generation Method
			
			
			
			
			/// Generate a sample from the uniform distribution.
			RIM_INLINE T sample()
			{
				return randomVariable.sample( minimum, maximum );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distribution Minimum Accessor Methods
			
			
			
			
			/// Get the minimum value that the uniform distribution can generate.
			RIM_INLINE T getMinimum() const
			{
				return minimum;
			}
			
			
			
			
			/// Set the minimum value that the uniform distribution can generate.
			RIM_INLINE void setMinimum( T min )
			{
				minimum = min;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distribution Maximum Accessor Methods
			
			
			
			
			/// Get the maximum value that the uniform distribution can generate.
			RIM_INLINE T getMaximum() const
			{
				return maximum;
			}
			
			
			
			
			/// Set the maximum value that the uniform distribution can generate.
			RIM_INLINE void setMaximum( T max )
			{
				maximum = max;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Random Variable Accessor Methods
			
			
			
			
			/// Get the random variable used to generate samples for this distribution.
			RIM_INLINE RandomVariable<T>& getRandomVariable()
			{
				return randomVariable;
			}
			
			
			
			
			/// Get the random variable used to generate samples for this distribution.
			RIM_INLINE const RandomVariable<T>& getRandomVariable() const
			{
				return randomVariable;
			}
			
			
			
			
			/// Set the random variable used to generate samples for this distribution.
			RIM_INLINE void getRandomVariable( const RandomVariable<T>& newRandomVariable )
			{
				randomVariable = newRandomVariable;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The minimum value that can be generated by the distribution.
			T minimum;
			
			
			
			
			/// The maximum value that can be generated by the distribution.
			T maximum;
			
			
			
			
			/// The random variable that the uniform distribution uses to generate samples.
			RandomVariable<T> randomVariable;
			
			
			
			
};




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_NORMAL_DISTRIBUTION_H
