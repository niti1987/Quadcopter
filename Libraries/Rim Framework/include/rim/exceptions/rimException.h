/*
 *  rimException.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 1/27/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_EXCEPTION_H
#define INCLUDE_EXCEPTION_H


#include <exception>


#include "rimExceptionsConfig.h"


//##########################################################################################
//***************************  Start Rim Exceptions Namespace  *****************************
RIM_EXCEPTIONS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that provides an exception abstraction.
/**
  * It is meant to be thrown from the location of an error
  * and then to be caught by error correcting code somewhere
  * in the calling stack. Each exception provides a means to 
  * encapsulate a message in the exception, so as to give the 
  * exception catcher a better idea of why the error occurred.
  */
class Exception : public std::exception
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default exception with no message to the catcher.
			Exception();
			
			
			
			
			/// Create an exception with a character array message.
			/**
			  * The message lets the thrower of the exception
			  * tell the catcher the reason for the exception.
			  */
			Exception( const char* newMessage );
			
			
			
			
			/// Create a new exception with a message from a string.
			/**
			  * The message lets the thrower of the exception
			  * tell the catcher the reason for the exception.
			  */
			Exception( const String& newMessage );
			
			
			
			/// Create a copy of an exception (copy constructor).
			/** 
			  * This copy contructor duplicates the message of the 
			  * copied exception by doing a deep copy.
			  */
			Exception( const Exception& exception );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy an exception, deallocating it's message.
			virtual ~Exception() throw();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign one exception to another
			Exception& operator = ( const Exception& exception );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Message Accessors
			
			
			
			
			/// Get the message for the exception.
			/**
			  * The message is determined when the exception is
			  * constructed, and lets the thrower of the exception
			  * tell the catcher the reason for the throw of the
			  * exception.
			  * 
			  * @return the message from the exception's thrower
			  */
			virtual const char* what() const throw();
			
			
			
			
			/// Get the message for the exception.
			/**
			  * The message is determined when the exception is
			  * constructed, and lets the thrower of the exception
			  * tell the catcher the reason for the throw of the
			  * exception.
			  * 
			  * @return the message from the exception's thrower
			  */
			RIM_INLINE const String& getMessage() const
			{
				return *message;
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
		//******	Private Data Members
			
			
			
			
			/// The message for the exception.
			String* message;
			
			
			
			
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


#endif // INCLUDE_EXCEPTION_H
