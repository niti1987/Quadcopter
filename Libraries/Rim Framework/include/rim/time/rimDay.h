/*
 *  rimDay.h
 *  Rim Time
 *
 *  Created by Carl Schissler on 11/2/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_DAY_H
#define INCLUDE_RIM_DAY_H


#include "rimTimeConfig.h"


//##########################################################################################
//*******************************   Start Time Namespace   *********************************
RIM_TIME_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a single day within a week, month, and year of the modern calendar.
class Day
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a Day object with the specified day of the week, month, and year indicies, starting at 1.
			RIM_INLINE Day( Index newDayOfTheWeek, Index newDayOfTheMonth, Index newDayOfTheYear )
				:	dayOfTheWeek( newDayOfTheWeek ),
					dayOfTheMonth( newDayOfTheMonth ),
					dayOfTheYear( newDayOfTheYear )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Day of the Week Accessor Methods
			
			
			
			
			/// Get the day of the week index of this Day, starting at 1.
			RIM_INLINE Index getDayOfTheWeek() const
			{
				return dayOfTheWeek;
			}
			
			
			
			
			/// Set the day of the week index of this Day, starting at 1.
			RIM_INLINE void setDayOfTheWeek( Index newDayOfTheWeek ) 
			{
				dayOfTheWeek = newDayOfTheWeek;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Day of the Month Accessor Methods
			
			
			
			
			/// Get the day of the month index of this Day, starting at 1.
			RIM_INLINE Index getDayOfTheMonth() const
			{
				return dayOfTheMonth;
			}
			
			
			
			
			/// Set the day of the month index of this Day, starting at 1.
			RIM_INLINE void setDayOfTheMonth( Index newDayOfTheMonth )
			{
				dayOfTheMonth = newDayOfTheMonth;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Day of the Year Accessor Methods
			
			
			
			
			/// Get the day of the year index of this Day, starting at 1.
			RIM_INLINE Index getDayOfTheYear() const
			{
				return dayOfTheYear;
			}
			
			
			
			
			/// Set the day of the year index of this Day, starting at 1.
			RIM_INLINE void setDayOfTheYear( Index newDayOfTheYear )
			{
				dayOfTheYear = newDayOfTheYear;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Get the standard name for the day with this day of the week index.
			/**
			  * If the day does not have a standard name, the empty string is returned.
			  */
			data::String getName() const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Methods
			
			
			
			
			/// Initialize the standard day of the week names.
			static void initializeStandardNames();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The index of the day of the week, starting at 1.
			Index dayOfTheWeek;
			
			
			
			
			/// The index of the day of the month, starting at 1.
			Index dayOfTheMonth;
			
			
			
			
			/// The index of the day of the year, starting at 1.
			Index dayOfTheYear;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// Standard names for days of the week with standard indices.
			static util::HashMap<Index,data::String> names;
			
			
			
			
			/// Whether or not the standard day names have been initialized.
			static Bool hasInitializedStandardNames;
			
			
			
};




//##########################################################################################
//*******************************   End Time Namespace   ***********************************
RIM_TIME_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_DAY_H
