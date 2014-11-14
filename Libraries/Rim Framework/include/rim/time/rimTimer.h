/*
 *  rimTimer.h
 *  Rim Time
 *
 *  Created by Carl Schissler on 11/9/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_TIMER_H
#define INCLUDE_RIM_TIMER_H


#include "rimTimeConfig.h"


#include "rimTime.h"


//##########################################################################################
//*******************************   Start Time Namespace   *********************************
RIM_TIME_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A timer class which behaves like a stopwatch.
/**
  * This class serves to provide a way for the user to mark
  * times and to measure the intervals between them. This can
  * be used to do application profiling/timing, to provide a 
  * frame time interval counter for games, etc. It uses the highest
  * performance timers availible on the system it is compiled under,
  * and therefore should have sub-millisecond accuracy. The timer
  * is also able to be paused, such that it then behaves as if it
  * was stuck in that instance in which it was paused. It can later
  * be resumed and carry on as if it had never been paused, reflecting
  * this in it's attributes accordingly.
  */
class Timer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new timer and start it's first interval (by calling update()).
			/** 
			  * This constructor creates a new timer, and then
			  * initializes the timer by starting it's first time interval,
			  * done by calling the timer's update() function internally.
			  */
			Timer();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stopwatch Timing Methods
			
			
			
			
			/// Update the timer to the current time, store the interval between updates.
			/**
			  * This method updates the timer, and calculates and
			  * stores the time between the last update and this update
			  * internally, so that it can be accessed using the
			  * getElapsedTime() method. If the timer is paused
			  * when this function is called, then the method does nothing.
			  */
			void update();
			
			
			
			
			/// Get the time interval of the last update
			/**
			  * This method retrieves the time interval (in seconds)
			  * of the elapsed time between the last call to the update()
			  * method and the second to last call to the update() method.
			  * 
			  * @return the time interval between the last two timer updates
			  */
			RIM_INLINE const Time& getLastInterval() const
			{
				return lastInterval;
			}
			
			
			
			
			/// Get the time interval since the last update without updating the timer.
			/**
			  * This method gets the time passed since the last call to the update()
			  * method in seconds. The method does not reset the timer, and therefore
			  * can be used to get a running total of the time since some arbitrary
			  * moment (set by calling the update method). If the timer is paused, 
			  * this method returns the time between the last call to update() and
			  * the time when the timer was paused.
			  * 
			  * @return the time since the last call to update()
			  */
			Time getElapsedTime() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Timer State Methods
			
			
			
			
			/// Get whether or not the timer is currently paused.
			/**
			  * If the timer is paused, then this means that the timer
			  * is no longer keeping track of time, and will behave as if
			  * it is stuck in the instant that it was paused in until it
			  * is unpaused. This can be useful in many situations where
			  * one needs to stop timing and later resume timing as if
			  * the timer has never been stopped.
			  * 
			  * @return whether or not the timer is currently paused.
			  */
			RIM_INLINE Bool getIsPaused() const
			{
				return isPaused;
			}
			
			
			
			
			/// Set whether or not the timer is paused with a boolean flag.
			/**
			  * If the timer is paused, then this means that the timer
			  * is no longer keeping track of time, and will behave as if
			  * it is stuck in the instant that it was paused in until it
			  * is unpaused. This can be useful in many situations where
			  * one needs to stop timing and later resume timing as if
			  * the timer has never been stopped. If this method is called
			  * with a parameter that is equal to the return value of
			  * getIsPaused(), then it does nothing (the timer's state doesn't
			  * need to change).
			  * 
			  * @param newIsPaused - whether or not the timer should be paused.
			  */
			void setIsPaused( Bool newIsPaused );
			
			
			
			
			/// Pause the timer.
			/**
			  * If the timer is already paused, then this method does
			  * nothing (the timer's state doesn't need to change to
			  * reflect the function call).
			  */
			RIM_INLINE void pause()
			{
				this->setIsPaused( true );
			}
			
			
			
			
			/// Resume the timer if it is currently paused.
			/**
			  * If the timer is not paused, then this method does
			  * nothing (the timer's state doesn't need to change to
			  * reflect the function call).
			  */
			RIM_INLINE void resume()
			{
				this->setIsPaused( false );
			}
			
			
			
			
			
	private:
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The second to last time the timer was updated.
			Time oldTime;
			
			
			
			
			/// The last time the timer was updated.
			Time currentTime;
			
			
			
			
			/// The positive time interval between the last and second to last times.
			Time lastInterval;
			
			
			
			
			/// Whether or not the timer is currently paused.
			Bool isPaused;
			
			
			
};




//##########################################################################################
//*******************************   End Time Namespace   ***********************************
RIM_TIME_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_TIMER_H
