/*
 *  rimExponentialDistribution.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 5/8/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_EXPONENTIAL_DISTRIBUTION_H
#define INCLUDE_RIM_EXPONENTIAL_DISTRIBUTION_H


#include "rimMathConfig.h"


#include "rimRandomVariable.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




template < typename T >
class ExponentialDistribution;




/// A class which represents an exponential distribution.
template <>
class ExponentialDistribution<float>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an exponential distribution with lambda equal to 1.
			RIM_INLINE ExponentialDistribution()
				:	lambda( 1.0f ),
					randomVariable()
			{
			}
			
			
			
			
			/// Create an exponential distribution with lambda equal to 1.
			/**
			  * The created exponential distribution will produce samples using the
			  * specified random variable.
			  */
			RIM_INLINE ExponentialDistribution( const RandomVariable<float>& newRandomVariable )
				:	lambda( 1.0f ),
					randomVariable( newRandomVariable )
			{
			}
			
			
			
			
			/// Create an exponential distribution with lambda equal to the specified value.
			RIM_INLINE ExponentialDistribution( float newLambda )
				:	lambda( math::max( newLambda, 0.0f ) ),
					randomVariable()
			{
			}
			
			
			
			
			/// Create an exponential distribution with lambda equal to the specified value.
			/**
			  * The created exponential distribution will produce samples using the
			  * specified random variable.
			  */
			RIM_INLINE ExponentialDistribution( float newLambda, const RandomVariable<float>& newRandomVariable )
				:	lambda( math::max( newLambda, 0.0f ) ),
					randomVariable( newRandomVariable )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distribution Sample Generation Method
			
			
			
			
			/// Generate a sample from the exponential distribution.
			RIM_INLINE float sample()
			{
				return -math::ln( randomVariable.sample( 0.0f, 1.0f ) )/lambda;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Lambda Parameter Accessor Methods
			
			
			
			
			/// Get the lambda parameter of this exponential distribution.
			RIM_INLINE float getLambda() const
			{
				return lambda;
			}
			
			
			
			
			/// Set the lambda parameter of this exponential distribution.
			RIM_INLINE void setLambda( float newLambda )
			{
				lambda = newLambda;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Random Variable Accessor Methods
			
			
			
			
			/// Get the random variable used to generate samples for this distribution.
			RIM_INLINE RandomVariable<float>& getRandomVariable()
			{
				return randomVariable;
			}
			
			
			
			
			/// Get the random variable used to generate samples for this distribution.
			RIM_INLINE const RandomVariable<float>& getRandomVariable() const
			{
				return randomVariable;
			}
			
			
			
			
			/// Set the random variable used to generate samples for this distribution.
			RIM_INLINE void getRandomVariable( const RandomVariable<float>& newRandomVariable )
			{
				randomVariable = newRandomVariable;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The lambda parameter of the exponential distribution.
			float lambda;
			
			
			
			
			/// The random variable that the exponential distribution uses to generate samples.
			RandomVariable<float> randomVariable;
			
			
			
			
};




/// A class which represents an exponential distribution.
template <>
class ExponentialDistribution<double>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an exponential distribution with lambda equal to 1.
			RIM_INLINE ExponentialDistribution()
				:	lambda( 1.0 ),
					randomVariable()
			{
			}
			
			
			
			
			/// Create an exponential distribution with lambda equal to the specified value.
			RIM_INLINE ExponentialDistribution( double newLambda )
				:	lambda( math::max( newLambda, 0.0 ) ),
					randomVariable()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distribution Sample Generation Method
			
			
			
			
			/// Generate a sample from the exponential distribution.
			RIM_INLINE double sample()
			{
				return -math::ln( randomVariable.sample( 0.0, 1.0 ) )/lambda;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Lambda Parameter Accessor Methods
			
			
			
			
			/// Get the lambda parameter of this exponential distribution.
			RIM_INLINE double getLambda() const
			{
				return lambda;
			}
			
			
			
			
			/// Set the lambda parameter of this exponential distribution.
			RIM_INLINE void setLambda( double newLambda )
			{
				lambda = newLambda;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Random Variable Accessor Methods
			
			
			
			
			/// Get the random variable used to generate samples for this distribution.
			RIM_INLINE RandomVariable<double>& getRandomVariable()
			{
				return randomVariable;
			}
			
			
			
			
			/// Get the random variable used to generate samples for this distribution.
			RIM_INLINE const RandomVariable<double>& getRandomVariable() const
			{
				return randomVariable;
			}
			
			
			
			
			/// Set the random variable used to generate samples for this distribution.
			RIM_INLINE void getRandomVariable( const RandomVariable<double>& newRandomVariable )
			{
				randomVariable = newRandomVariable;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The lambda parameter of the exponential distribution.
			double lambda;
			
			
			
			
			/// The random variable that the exponential distribution uses to generate samples.
			RandomVariable<double> randomVariable;
			
			
			
			
};




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_EXPONENTIAL_DISTRIBUTION_H
