/*
 *  rimNormalDistribution.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 5/8/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_NORMAL_DISTRIBUTION_H
#define INCLUDE_RIM_NORMAL_DISTRIBUTION_H


#include "rimMathConfig.h"


#include "rimRandomVariable.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




template < typename T >
class NormalDistribution;




/// A class which represents a normal (gaussian) distribution.
template <>
class NormalDistribution<float>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a standard normal distribution with mean of 0 and standard deviation 1.
			RIM_INLINE NormalDistribution()
				:	mean( 0.0f ),
					standardDeviation( 1.0f ),
					randomVariable()
			{
			}
			
			
			
			
			/// Create a standard normal distribution with mean of 0 and standard deviation 1.
			/**
			  * The created normal distribution will produce samples using the
			  * specified random variable.
			  */
			RIM_INLINE NormalDistribution( const RandomVariable<float>& newRandomVariable )
				:	mean( 0.0f ),
					standardDeviation( 1.0f ),
					randomVariable( newRandomVariable )
			{
			}
			
			
			
			/// Create a normal distribution with the specified mean and standard deviation.
			RIM_INLINE NormalDistribution( float newMean, float newStandardDeviation )
				:	mean( newMean ),
					standardDeviation( newStandardDeviation ),
					randomVariable()
			{
			}
			
			
			
			/// Create a normal distribution with the specified mean and standard deviation.
			/**
			  * The created normal distribution will produce samples using the
			  * specified random variable.
			  */
			RIM_INLINE NormalDistribution( float newMean, float newStandardDeviation,
										const RandomVariable<float>& newRandomVariable )
				:	mean( newMean ),
					standardDeviation( newStandardDeviation ),
					randomVariable( newRandomVariable )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distribution Sample Generation Method
			
			
			
			
			/// Generate a sample from the normal distribution.
			RIM_INLINE float sample()
			{
				float a = randomVariable.sample( 0.0f, 1.0f );
				float b = randomVariable.sample( 0.0f, 1.0f );
				
				// standard normal random sample
				float z = math::sqrt( -2.0f*math::ln(a) ) * math::cos( 2.0f*float(math::pi<float>())*b );
				
				// scale and translate the standard normal to match this distribution.
				return z*standardDeviation + mean;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distribution Mean Accessor Methods
			
			
			
			
			/// Get the mean of the normal distribution.
			RIM_INLINE float getMean() const
			{
				return mean;
			}
			
			
			
			
			/// Set the mean of the normal distribution.
			RIM_INLINE void setMean( float newMean )
			{
				mean = newMean;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distribution Standard Deviation Accessor Methods
			
			
			
			
			/// Get the standard deviation of the normal distribution.
			RIM_INLINE float getStandardDeviation() const
			{
				return standardDeviation;
			}
			
			
			
			
			/// Set the standard deviation of the normal distribution.
			RIM_INLINE void setStandardDeviation( float newStandardDeviation )
			{
				standardDeviation = newStandardDeviation;
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
		//******	Private Data Members;
			
			
			
			
			/// The mean, or average, of the normal distribution.
			float mean;
			
			
			
			
			/// The standard deviation of the normal distribution.
			float standardDeviation;
			
			
			
			
			/// The random variable that the normal distribution uses to generate samples.
			RandomVariable<float> randomVariable;
			
			
			
			
};




/// A class which represents a normal (gaussian) distribution.
template <>
class NormalDistribution<double>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a standard normal distribution with mean of 0 and standard deviation 1.
			RIM_INLINE NormalDistribution()
				:	mean( 0.0f ),
					standardDeviation( 1.0f ),
					randomVariable()
			{
			}
			
			
			
			
			/// Create a standard normal distribution with mean of 0 and standard deviation 1.
			/**
			  * The created normal distribution will produce samples using the
			  * specified random variable.
			  */
			RIM_INLINE NormalDistribution( const RandomVariable<double>& newRandomVariable )
				:	mean( 0.0f ),
					standardDeviation( 1.0f ),
					randomVariable( newRandomVariable )
			{
			}
			
			
			
			/// Create a normal distribution with the specified mean and standard deviation.
			RIM_INLINE NormalDistribution( double newMean, double newStandardDeviation )
				:	mean( newMean ),
					standardDeviation( newStandardDeviation ),
					randomVariable()
			{
			}
			
			
			
			/// Create a normal distribution with the specified mean and standard deviation.
			/**
			  * The created normal distribution will produce samples using the
			  * specified random variable.
			  */
			RIM_INLINE NormalDistribution( double newMean, double newStandardDeviation,
										const RandomVariable<double>& newRandomVariable )
				:	mean( newMean ),
					standardDeviation( newStandardDeviation ),
					randomVariable( newRandomVariable )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distribution Sample Generation Method
			
			
			
			
			/// Generate a sample from the normal distribution.
			RIM_INLINE double sample()
			{
				double a = randomVariable.sample( 0.0f, 1.0f );
				double b = randomVariable.sample( 0.0f, 1.0f );
				
				// standard normal random sample
				double z = math::sqrt( -2.0f*math::ln(a) ) * math::cos( 2.0f*math::pi<double>()*b );
				
				// scale and translate the standard normal to match this distribution.
				return z*standardDeviation + mean;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distribution Mean Accessor Methods
			
			
			
			
			/// Get the mean of the normal distribution.
			RIM_INLINE double getMean() const
			{
				return mean;
			}
			
			
			
			
			/// Set the mean of the normal distribution.
			RIM_INLINE void setMean( double newMean )
			{
				mean = newMean;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Distribution Standard Deviation Accessor Methods
			
			
			
			
			/// Get the standard deviation of the normal distribution.
			RIM_INLINE double getStandardDeviation() const
			{
				return standardDeviation;
			}
			
			
			
			
			/// Set the standard deviation of the normal distribution.
			RIM_INLINE void setStandardDeviation( double newStandardDeviation )
			{
				standardDeviation = newStandardDeviation;
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
		//******	Private Data Members;
			
			
			
			
			/// The mean, or average, of the normal distribution.
			double mean;
			
			
			
			
			/// The standard deviation of the normal distribution.
			double standardDeviation;
			
			
			
			
			/// The random variable that the normal distribution uses to generate samples.
			RandomVariable<double> randomVariable;
			
			
			
			
};




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_NORMAL_DISTRIBUTION_H
