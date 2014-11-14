/*
 *  rimPoissonDistribution.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 5/8/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_POISSON_DISTRIBUTION_H
#define INCLUDE_RIM_POISSON_DISTRIBUTION_H


#include "rimMathConfig.h"


#include "rimRandomVariable.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




/// A class which represents a Poisson distribution.
template < typename T >
class PoissonDistribution
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a poisson distribution with parameter lambda equal to 1.
			RIM_INLINE PoissonDistribution()
				:	lambda( 1.0 ),
					lambdaExp( math::exp(-1.0) ),
					randomVariable()
			{
			}
			
			
			
			
			/// Create a poisson distribution with parameter lambda equal to 1.
			/**
			  * The created Poisson distribution will produce samples using the
			  * specified random variable.
			  */
			RIM_INLINE PoissonDistribution( const RandomVariable<double>& newRandomVariable )
				:	lambda( 1.0 ),
					lambdaExp( math::exp(-1.0) ),
					randomVariable( newRandomVariable )
			{
			}
			
			
			
			
			/// Create a poisson distribution with the specified parameter lambda.
			RIM_INLINE PoissonDistribution( double newLambda )
				:	lambda( newLambda ),
					lambdaExp( math::exp(-newLambda) ),
					randomVariable()
			{
			}
			
			
			
			
			/// Create a poisson distribution with the specified parameter lambda.
			/**
			  * The created Poisson distribution will produce samples using the
			  * specified random variable.
			  */
			RIM_INLINE PoissonDistribution( double newLambda, const RandomVariable<double>& newRandomVariable )
				:	lambda( newLambda ),
					lambdaExp( math::exp(-newLambda) ),
					randomVariable( newRandomVariable )
			{
			}
			
			
			
			
			/// Create a poisson distribution which approximates a binomial distribution.
			/**
			  * When the parameter n is large and p is small, the Poisson distribution
			  * created will approximate the behavior of a binomial distribution with the
			  * parameters n and p. This can approximate the number of successes in a 
			  * series of n independent yes/no experiments where the probability of a 
			  * success is p.
			  */
			RIM_INLINE PoissonDistribution( double n, double p )
				:	lambda( n*p ),
					lambdaExp( math::exp(-n*p) ),
					randomVariable()
			{
			}
			
			
			
			
			/// Create a poisson distribution which approximates a binomial distribution.
			/**
			  * When the parameter n is large and p is small, the Poisson distribution
			  * created will approximate the behavior of a binomial distribution with the
			  * parameters n and p. This can approximate the number of successes in a 
			  * series of n independent yes/no experiments where the probability of a 
			  * success is p. The created Poisson distribution will produce samples
			  * using the specified random variable.
			  */
			RIM_INLINE PoissonDistribution( double n, double p, const RandomVariable<double>& newRandomVariable )
				:	lambda( n*p ),
					lambdaExp( math::exp(-n*p) ),
					randomVariable( newRandomVariable )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distribution Sample Generation Method
			
			
			
			
			/// Generate a sample from the Poisson distribution.
			RIM_INLINE T sample()
			{
				T k = 0;
				double p = 1.0;
				
				do
				{
					k++;
					p *= randomVariable.sample( 0.0, 1.0 );
				}
				while ( p >= lambdaExp );
				
				return T(k - 1);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Lambda Parameter Accessor Methods
			
			
			
			
			/// Get the lambda parameter of this Poisson distribution.
			RIM_INLINE double getLambda() const
			{
				return lambda;
			}
			
			
			
			
			/// Set the lambda parameter of this Poisson distribution.
			RIM_INLINE void setLambda( double newLambda )
			{
				lambda = newLambda;
				lambdaExp = math::exp(-lambda);
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
			
			
			
			
			/// The lambda parameter of the Poisson distribution.
			double lambda;
			
			
			
			
			/// e to the power of the lambda parameter of the Poisson distribution.
			double lambdaExp;
			
			
			
			
			/// The random variable that the Poisson distribution uses to generate samples.
			RandomVariable<double> randomVariable;
			
			
			
			
};




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_POISSON_DISTRIBUTION_H
