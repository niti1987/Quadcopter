/*
 *  rimTime.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 8/16/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_TIME_H
#define INCLUDE_RIM_TIME_H


#include "rimTimeConfig.h"


//##########################################################################################
//*******************************   Start Time Namespace   *********************************
RIM_TIME_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a high-resolution interval of time.
/**
  * The time interval is represented internally in high precision nanosecond
  * resolution. The time interval representation is signed and so can be negative.
  */
class Time
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a Time object that represents a time interval of 0 seconds.
			RIM_INLINE Time()
				:	nanoseconds( 0 )
			{
			}
			
			
			
			
			/// Create a Time object that represents the specified interval of time in nanoseconds.
			/**
			  * This overload is provided to allow initialization with 0, which might cause ambiguities.
			  */
			RIM_INLINE Time( int newNanoseconds )
				:	nanoseconds( newNanoseconds )
			{
			}
			
			
			
			
			/// Create a Time object that represents the specified interval of time in nanoseconds.
			RIM_INLINE Time( Int64 newNanoseconds )
				:	nanoseconds( newNanoseconds )
			{
			}
			
			
			
			
			/// Create a Time object that represents the specified interval of time in seconds.
			/**
			  * The time is specified by a single floating-point value that gives
			  * the number of seconds in the time interval.
			  */
			RIM_INLINE Time( Double newSeconds )
			{
				Double seconds = math::floor( newSeconds );
				Double secondsFraction = newSeconds - seconds;
				
				nanoseconds = Int64(seconds)*Int64(1000000000) + Int64(secondsFraction*Double(1.0e9));
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Seconds Accessor Methods
			
			
			
			
			/// Return the number of seconds that this Time object represents.
			RIM_INLINE Double getSeconds() const
			{
				return Double(nanoseconds) / Double(1.0e9);
			}
			
			
			
			
			/// Return the number of nanoseconds that this Time object represents.
			RIM_INLINE Int64 getNanoseconds() const
			{
				return nanoseconds;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Time Cast Operators
			
			
			
			
			/// Convert this Time object into a floating point representation.
			/**
			  * Doing this may reduce the accuracy of the time interval due to the
			  * inaccuracies of floating-point formats.
			  */
			/*RIM_INLINE operator Float () const
			{
				return Float(nanoseconds) / Float(1.0e9);
			}*/
			
			
			
			
			/// Convert this Time object into a double floating point representation.
			/**
			  * Doing this may reduce the accuracy of the time interval due to the
			  * inaccuracies of floating-point formats.
			  */
			RIM_INLINE operator Double () const
			{
				return this->getSeconds();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Time Comparison Operators
			
			
			
			
			/// Return whether or not this Time object represents the same time as another.
			RIM_INLINE Bool operator == ( const Time& other ) const
			{
				return nanoseconds == other.nanoseconds;
			}
			
			
			
			
			/// Return whether or not this Time object represents a different time than another.
			RIM_INLINE Bool operator != ( const Time& other ) const
			{
				return nanoseconds != other.nanoseconds;
			}
			
			
			
			
			/// Return whether or not this Time object represents an earlier time than another.
			RIM_INLINE Bool operator < ( const Time& other ) const
			{
				return nanoseconds < other.nanoseconds;
			}
			
			
			
			
			/// Return whether or not this Time object represents a later time than another.
			RIM_INLINE Bool operator > ( const Time& other ) const
			{
				return nanoseconds > other.nanoseconds;
			}
			
			
			
			
			/// Return whether or not this Time object represents an earlier or equal time than another.
			RIM_INLINE Bool operator <= ( const Time& other ) const
			{
				return nanoseconds < other.nanoseconds;
			}
			
			
			
			
			/// Return whether or not this Time object represents a later or equal time than another.
			RIM_INLINE Bool operator >= ( const Time& other ) const
			{
				return nanoseconds > other.nanoseconds;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Time Arithmetic Operators
			
			
			
			
			/// Return the time interval represented by the sum of this time interval and another.
			RIM_INLINE Time operator + ( const Time& other ) const
			{
				return Time( nanoseconds + other.nanoseconds );
			}
			
			
			
			
			/// Add the specified time interval to this time interval, modifying it.
			RIM_INLINE Time& operator += ( const Time& other )
			{
				nanoseconds += other.nanoseconds;
				
				return *this;
			}
			
			
			
			
			/// Return the time interval represented by the difference between this time interval and another.
			RIM_INLINE Time operator - ( const Time& other ) const
			{
				return Time( nanoseconds - other.nanoseconds );
			}
			
			
			
			
			/// Subtract the specified time interval from this time interval, modifying it.
			RIM_INLINE Time& operator -= ( const Time& other )
			{
				nanoseconds -= other.nanoseconds;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Conversion Methods
			
			
			
			
			/// Return a string representation of this time object.
			RIM_INLINE data::String toString() const
			{
				return data::String( this->getSeconds() );
			}
			
			
			
			
			/// Convert this time object to a string representation.
			RIM_INLINE operator data::String () const
			{
				return this->toString();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Current Time Accessor Method
			
			
			
			
			/// Create a time object that represents the current system time.
			/**
			  * The time is represented as the time that has passed since the Epoch,
			  * 1970-01-01 00:00:00 +0000 (UTC).
			  */
			RIM_INLINE static Time getCurrent()
			{
				Int64 nanoseconds = 0;
				
				getCurrentTime( nanoseconds );
				
				return Time( nanoseconds );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Method
			
			
			
			
			/// Get the current system time as the number of nanoseconds since the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
			/**
			  * The method returns whether or not the current time was successfully queried.
			  */
			static Bool getCurrentTime( Int64& nanoseconds );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The number of nanoseconds that this time interval represents.
			Int64 nanoseconds;
			
			
			
};




//##########################################################################################
//*******************************   End Time Namespace   ***********************************
RIM_TIME_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_TIME_H
