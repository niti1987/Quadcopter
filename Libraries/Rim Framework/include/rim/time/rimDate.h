/*
 *  rimDate.h
 *  Rim Time
 *
 *  Created by Carl Schissler on 5/30/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_DATE_H
#define INCLUDE_RIM_DATE_H


#include "rimTimeConfig.h"


#include "rimMonth.h"
#include "rimDay.h"
#include "rimTimeOfDay.h"


//##########################################################################################
//*******************************   Start Time Namespace   *********************************
RIM_TIME_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Time;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents an instant in time within the modern calendar.
class Date
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a date object which represents the current date.
			Date();
			
			
			
			
			/// Create a date corresponding to the specified Time offset since the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
			Date( const Time& time );
			
			
			
			
			/// Create a date corresponding to the specified year, month, and day, at the first instant of the day.
			RIM_INLINE Date( Int64 newYear, const Month& newMonth, const Day& newDay )
				:	year( newYear ),
					month( newMonth ),
					day( newDay )
			{
			}
			
			
			
			
			/// Create a date corresponding to the specified year, month, day, and time of day.
			RIM_INLINE Date( Int64 newYear, const Month& newMonth, const Day& newDay, const TimeOfDay& newTimeOfDay )
				:	year( newYear ),
					month( newMonth ),
					day( newDay ),
					timeOfDay( newTimeOfDay )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Month Accessor Methods
			
			
			
			
			/// Return the year of this date. Values are interpreted as relative to the year 0 AD.
			RIM_INLINE Int64 getYear() const
			{
				return year;
			}
			
			
			
			
			/// Set the year of this date. Values are interpreted as relative to the year 0 AD.
			RIM_INLINE void setYear( Int64 newYear )
			{
				year = newYear;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Month Accessor Methods
			
			
			
			
			/// Return a reference to an object which represents the month of this date.
			RIM_INLINE const Month& getMonth() const
			{
				return month;
			}
			
			
			
			
			/// Set the month of this date.
			RIM_INLINE void setMonth( const Month& newMonth )
			{
				month = newMonth;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Day Accessor Methods
			
			
			
			
			/// Return a reference to an object which represents the day of this date.
			RIM_INLINE const Day& getDay() const
			{
				return day;
			}
			
			
			
			
			/// Set the day of this date.
			RIM_INLINE void setDay( const Day& newDay )
			{
				day = newDay;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Time Of Day Accessor Methods
			
			
			
			
			/// Return a reference to an object which represents the time of day of this date.
			RIM_INLINE const TimeOfDay& getTimeOfDay() const
			{
				return timeOfDay;
			}
			
			
			
			
			/// Set the time of day of this date.
			RIM_INLINE void setTimeOfDay( const TimeOfDay& newTimeOfDay )
			{
				timeOfDay = newTimeOfDay;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Conversion Methods
			
			
			
			
			/// Convert the Date object to a String representation.
			data::String toString() const;
			
			
			
			
			/// Convert the Date object to a String representation.
			RIM_FORCE_INLINE operator data::String() const
			{
				return this->toString();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Time Zone Accessor Methods
			
			
			
			
			/// Get the current time zone that dates are being processed as being in.
			/**
			  * The time zone is specified as the signed offset in hours from GMT.
			  *
			  * The default initial value for the time zone is the local time zone.
			  */
			static Int getTimeZone();
			
			
			
			
			/// Get the local time zone.
			/**
			  * The time zone is specified as the signed offset in hours from GMT.
			  */
			static Int getLocalTimeZone();
			
			
			
			
			/// Set the time zone to use when computing the hour of the day.
			/**
			  * The time zone is specified as the signed offset in hours from GMT.
			  *
			  * The default initial value for the time zone is the local time zone.
			  */
			RIM_INLINE static void setTimeZone( Int newTimeZone )
			{
				timeZone = newTimeZone;
				timeZoneIsInitialized = true;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Helper Methods
			
			
			
			
			/// Get the date for the time specified by the Time object.
			static void getDateForTimeSinceEpoch( const Time& time, Int64& year, Month& month, Day& day, TimeOfDay& timeOfDay );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An integer representing the year of this Date.
			Int64 year;
			
			
			
			
			/// The month of this Date object.
			Month month;
			
			
			
			
			/// The day of this Date object.
			Day day;
			
			
			
			
			/// The time of day of this date.
			TimeOfDay timeOfDay;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			static Int timeZone;
			
			
			
			
			static Bool timeZoneIsInitialized;
			
			
			
};




//##########################################################################################
//*******************************   End Time Namespace   ***********************************
RIM_TIME_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_DATE_H
