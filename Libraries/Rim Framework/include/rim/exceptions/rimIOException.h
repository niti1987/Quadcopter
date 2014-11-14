/*
 *  rimIOException.h
 *  Rim IO
 *
 *  Created by Carl Schissler on 3/18/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_IO_EXCEPTION_H
#define INCLUDE_RIM_IO_EXCEPTION_H


#include "rimExceptionsConfig.h"


#include "rimException.h"


//##########################################################################################
//***************************  Start Rim Exceptions Namespace  *****************************
RIM_EXCEPTIONS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An exception to be thrown when an error occurs while reading or writing with a stream.
/**
  * It is meant to be thrown from the location of an error
  * and then to be caught by error correcting code somewhere
  * in the calling stack. Each exception provides a means to 
  * encapsulate a message in the exception, so as to give the 
  * exception catcher a better idea of why the error occurred.
  *
  * This subclass of rimException indicates that an error
  * has occurred while reading or writing with a rimInputStream
  * or rimOutputStream. Check the message for more detail.
  */
class IOException : public Exception
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default IO exception with no message.
			RIM_INLINE IOException()
				:	Exception()
			{
			}
			
			
			
			
			/// Create a IO exception with a character array message.
			/**
			  * The message lets the thrower of the exception
			  * tell the catcher the reason for the throw of the
			  * exception.
			  */
			RIM_INLINE IOException( const char* newMessage )
				:	Exception( newMessage )
			{
			}
			
			
			
			
			/// Create a new IO exception with a message from a string.
			/**
			  * The message lets the thrower of the exception
			  * tell the catcher the reason for the throw of the
			  * exception.
			  */
			RIM_INLINE IOException( const String& newMessage )
				:	Exception( newMessage )
			{
			}
			
			
			
			
			/// Create a copy of an IO exception (copy constructor).
			/** 
			  * This copy contructor duplicates the message of the 
			  * parameter exception by doing a deep copy.
			  */
			RIM_INLINE IOException( const IOException& exception )
				:	Exception( exception )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Type Accessors
			
			
			
			/// Get a string representing the type of this exception
			virtual const String& getType() const
			{
				return *type;
			}
			
			
			
			/// Get a string representing the type of this exception (static version)
			static const String& getStaticType()
			{
				return *type;
			}
			
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
				/// A string representing the type of this exception
			static const String* type;
			
			
			
			
};




//##########################################################################################
//***************************  End Rim Exceptions Namespace  *******************************
RIM_EXCEPTIONS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_IO_EXCEPTION_H
