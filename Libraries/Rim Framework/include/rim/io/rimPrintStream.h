/*
 *  rimPrintStream.h
 *  Rim IO
 *
 *  Created by Carl Schissler on 3/18/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PRINT_STREAM_H
#define INCLUDE_RIM_PRINT_STREAM_H


#include "rimIOConfig.h"


#include "rimStringOutputStream.h"


//##########################################################################################
//******************************  Start Rim IO Namespace  **********************************
RIM_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that allows the user to print messages/data to standard output.
/** 
  * It is essentially a wrapper for C standard output (to the console)
  * that implements the OutputStream interface, allowing it to be used in
  * applications that are not standard out specific. For instance, 
  * a class such as Log outputs messages to a OutputStream. If one
  * wanted to print out messages to standard output, they would have
  * the log use a PrintStream (the default), or possibly a FileWriter.
  * both classes implement OutputStream's pure virtual methods and allow
  * Log to dump to a file or to standard output.
  */
class PrintStream : public StringOutputStream
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a print stream to standard ouput.
			RIM_INLINE PrintStream()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flush Method
			
			
			
			
			/// Flush the print stream, sending all internally buffered output to standard output.
			/** 
			  * This method causes all currently pending output data to be sent to
			  * C standard output. This method ensures that this is done and that all internal
			  * data buffers are emptied if they have any contents.
			  */
			virtual void flush();
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected String Write Methods
			
			
			
			
			/// Write the specified number of characters from the character buffer and return the number written.
			virtual Size writeChars( const Char* characters, Size number );
			
			
			
			
			/// Write the specified number of UTF-8 characters from the character buffer and return the number written.
			virtual Size writeUTF8Chars( const UTF8Char* characters, Size number );
			
			
			
			
			/// Write the specified number of UTF-16 characters from the character buffer and return the number written.
			virtual Size writeUTF16Chars( const UTF16Char* characters, Size number );
			
			
			
			
			/// Write the specified number of UTF-32 characters from the character buffer and return the number written.
			virtual Size writeUTF32Chars( const UTF32Char* characters, Size number );
			
			
			
};




//##########################################################################################
//******************************  End Rim IO Namespace  ************************************
RIM_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PRINT_STREAM_H
