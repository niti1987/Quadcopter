/*
 *  rimMonth.h
 *  Rim Time
 *
 *  Created by Carl Schissler on 11/2/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_MONTH_H
#define INCLUDE_RIM_MONTH_H


#include "rimTimeConfig.h"


//##########################################################################################
//*******************************   Start Time Namespace   *********************************
RIM_TIME_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a particular month in the modern calendar.
class Month
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a Month object representing the first month of the year.
			RIM_INLINE Month()
				:	number( 1 )
			{
			}
			
			
			
			
			/// Create a Month object with the specified index within the year, starting at 1.
			RIM_INLINE Month( Index newNumber )
				:	number( newNumber )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Get the standard name for the month with this index.
			/**
			  * If the month does not have a standard name, the empty string is returned.
			  */
			RIM_INLINE data::String getName() const
			{
				if ( !hasInitializedStandardNames )
					initializeStandardNames();
				
				const data::String* name;
				
				if ( names.find( Hash(number), number, name ) )
					return *name;
				else
					return data::String();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Number Accessor Methods
			
			
			
			
			/// Get the index of the month within the year, starting at 1.
			RIM_INLINE Index getNumber() const
			{
				return number;
			}
			
			
			
			
			/// Set the index of the month within the year, starting at 1.
			RIM_INLINE void setNumber( Index newNumber )
			{
				number = newNumber;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Methods
			
			
			
			
			/// Initialize the standard month names.
			static void initializeStandardNames();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Member
			
			
			
			
			/// The number of the month within the year, starting at 1.
			Index number;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// Standard names for months with standard indices.
			static util::HashMap<Index,data::String> names;
			
			
			
			
			/// Whether or not the standard month names have been initialized.
			static Bool hasInitializedStandardNames;
			
			
			
			
};




//##########################################################################################
//*******************************   End Time Namespace   ***********************************
RIM_TIME_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_MONTH_H
