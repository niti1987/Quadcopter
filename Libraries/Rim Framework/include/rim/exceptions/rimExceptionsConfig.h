/*
 *  rimExceptionsConfig.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_EXCEPTIONS_CONFIG_H
#define INCLUDE_RIM_EXCEPTIONS_CONFIG_H


#include "../rimConfig.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




/// Define the name of the exception library namespace.
#ifndef RIM_EXCEPTIONS_NAMESPACE
	#define RIM_EXCEPTIONS_NAMESPACE exceptions
#endif




#ifndef RIM_EXCEPTIONS_NAMESPACE_START
	#define RIM_EXCEPTIONS_NAMESPACE_START		RIM_NAMESPACE_START namespace RIM_EXCEPTIONS_NAMESPACE {
#endif




#ifndef RIM_EXCEPTIONS_NAMESPACE_END
	#define RIM_EXCEPTIONS_NAMESPACE_END		}; RIM_NAMESPACE_END
#endif




RIM_NAMESPACE_START
/// A namespace containing various types of commonly used exception classes.
namespace RIM_EXCEPTIONS_NAMESPACE {
};
RIM_NAMESPACE_END




namespace rim
{
	namespace data
	{
		template <typename CharType> class BasicString;
		typedef BasicString<Char> String;
		typedef BasicString<UTF8Char> UTF8String;
		typedef BasicString<UTF16Char> UTF16String;
		typedef BasicString<UTF32Char> UTF32String;
	};
};




//##########################################################################################
//***************************  Start Rim Exceptions Namespace  *****************************
RIM_EXCEPTIONS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




using rim::data::String;




//##########################################################################################
//***************************  End Rim Exceptions Namespace  *******************************
RIM_EXCEPTIONS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_EXCEPTIONS_CONFIG_H
