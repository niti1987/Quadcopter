/*
 *  rimLog.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 8/23/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_LOG_H
#define INCLUDE_RIM_LOG_H


#include "rimIOConfig.h"


#include "rimStringOutputStream.h"
#include "rimPrintStream.h"


#include "../exceptions/rimException.h"
#include "../lang/rimPointer.h"
#include "../util/rimArray.h"
#include "../util/rimStaticArray.h"


//##########################################################################################
//******************************  Start Rim IO Namespace  **********************************
RIM_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that allows the user to print messages to an abstract string output stream.
class Log
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a Log which prints its output to standard output.
			Log();
			
			
			
			
			/// Create a Log which sends its output to the specified StringOutputStream.
			Log( const lang::Pointer<StringOutputStream>& newStream );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stream Accessor Methods
			
			
			
			
			/// Return a pointer to the StringOutputStream which this log is outputing to.
			RIM_INLINE const lang::Pointer<StringOutputStream>& getStream() const
			{
				return stream;
			}
			
			
			
			
			/// Set the StringOutputStream which this log should output to.
			RIM_INLINE void setStream( const lang::Pointer<StringOutputStream>& newStream )
			{
				stream = newStream;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Single Character Buffer Output Operators
			
			
			
			
			RIM_INLINE Log& operator < ( Char character )
			{
				if ( stream.isSet() )
					stream->writeASCII( character );
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Null-Terminated Character Buffer Output Operators
			
			
			
			
			RIM_INLINE Log& operator < ( const Char* characters )
			{
				if ( stream.isSet() )
					stream->writeASCII( characters );
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Output Operators
			
			
			
			
			RIM_INLINE Log& operator < ( const data::String& string )
			{
				if ( stream.isSet() )
					stream->writeASCII( string );
				
				return *this;
			}
			
			
			
			
			RIM_INLINE Log& operator < ( const data::UTF8String& string )
			{
				if ( stream.isSet() )
					stream->writeUTF8( string );
				
				return *this;
			}
			
			
			
			
			RIM_INLINE Log& operator < ( const data::UTF16String& string )
			{
				if ( stream.isSet() )
					stream->writeUTF8( data::UTF8String(string) );
				
				return *this;
			}
			
			
			
			
			RIM_INLINE Log& operator < ( const data::UTF32String& string )
			{
				if ( stream.isSet() )
					stream->writeUTF8( data::UTF8String(string) );
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Primitive Type Output Operators
			
			
			
			
			/// Write the specified boolean value to this output log.
			RIM_INLINE Log& operator < ( Bool value )
			{
				if ( stream.isSet() )
					stream->writeASCII( data::String(value) );
				
				return *this;
			}
			
			
			
			
			/// Write the specified short integer value to this output log.
			RIM_INLINE Log& operator < ( Short value )
			{
				if ( stream.isSet() )
					stream->writeASCII( data::String(value) );
				
				return *this;
			}
			
			
			
			
			/// Write the specified unsigned short integer value to this output log.
			RIM_INLINE Log& operator < ( UShort value )
			{
				if ( stream.isSet() )
					stream->writeASCII( data::String(value) );
				
				return *this;
			}
			
			
			
			
			/// Write the specified integer value to this output log.
			RIM_INLINE Log& operator < ( Int value )
			{
				if ( stream.isSet() )
					stream->writeASCII( data::String(value) );
				
				return *this;
			}
			
			
			
			
			/// Write the specified unsigned integer value to this output log.
			RIM_INLINE Log& operator < ( UInt value )
			{
				if ( stream.isSet() )
					stream->writeASCII( data::String(value) );
				
				return *this;
			}
			
			
			
			
			/// Write the specified long integer value to this output log.
			RIM_INLINE Log& operator < ( Long value )
			{
				if ( stream.isSet() )
					stream->writeASCII( data::String(value) );
				
				return *this;
			}
			
			
			
			
			/// Write the specified unsigned long integer value to this output log.
			RIM_INLINE Log& operator < ( ULong value )
			{
				if ( stream.isSet() )
					stream->writeASCII( data::String(value) );
				
				return *this;
			}
			
			
			
			
			/// Write the specified long long integer value to this output log.
			RIM_INLINE Log& operator < ( LongLong value )
			{
				if ( stream.isSet() )
					stream->writeASCII( data::String(value) );
				
				return *this;
			}
			
			
			
			
			/// Write the specified unsigned long long integer value to this output log.
			RIM_INLINE Log& operator < ( ULongLong value )
			{
				if ( stream.isSet() )
					stream->writeASCII( data::String(value) );
				
				return *this;
			}
			
			
			
			
			/// Write the specified floating point value to this output log.
			RIM_INLINE Log& operator < ( Float value )
			{
				if ( stream.isSet() )
					stream->writeASCII( data::String(value) );
				
				return *this;
			}
			
			
			
			
			/// Write the specified double floating point value to this output log.
			RIM_INLINE Log& operator < ( Double value )
			{
				if ( stream.isSet() )
					stream->writeASCII( data::String(value) );
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Pointer Type Output Operators
			
			
			
			
			/// Write the specified pointer to this output log.
			/**
			  * The basic implementation for this method writes either 'NULL'
			  * if the pointer is NULL, or converts the pointer to a hexadecimal
			  * integer representation and writes that.
			  */
			template < typename T >
			RIM_INLINE Log& operator < ( T* pointer )
			{
				if ( stream.isNull() )
					return *this;
				
				if ( pointer == NULL )
					stream->writeASCII( "NULL" );
				else
					stream->writeASCII( data::String( PointerInt(pointer), 16 ) );
				
				return *this;
			}
			
			
			
			
			/// Write the specified pointer to this output log.
			/**
			  * The basic implementation for this method writes either 'NULL'
			  * if the pointer is NULL, or converts the pointer to a hexadecimal
			  * integer representation and writes that.
			  */
			template < typename T >
			RIM_INLINE Log& operator < ( const typename lang::Pointer<T>& pointer )
			{
				if ( stream.isNull() )
					return *this;
				
				if ( pointer.isNull() )
					stream->writeASCII( "NULL" );
				else
					stream->writeASCII( data::String( PointerInt(pointer.getPointer()), 16 ) );
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Array Type Output Operators
			
			
			
			
			/// Write the specified array to this output log.
			/**
			  * The basic implementation for this method writes either '[NULL]'
			  * if the array is NULL, or writes an array representation of every element
			  * in the array.
			  */
			template < typename T >
			RIM_NO_INLINE Log& operator < ( const typename util::Array<T>& array )
			{
				if ( stream.isNull() )
					return *this;
				
				if ( array.isNull() )
					stream->writeASCII( "[NULL]" );
				else
				{
					stream->writeASCII( "[ " );
					
					Index lastIndex = array.getSize() - 1;
					
					for ( Index i = 0; i < array.getSize(); i++ )
					{
						*this < array[i];
						
						if ( i != lastIndex )
							stream->writeASCII( ", " );
					}
					
					stream->writeASCII( " ]" );
				}
				
				return *this;
			}
			
			
			
			
			/// Write the specified static array to this output log.
			/**
			  * The basic implementation for this method writes either '[NULL]'
			  * if the array is NULL, or writes an array representation of every element
			  * in the array.
			  */
			template < typename T, Size size >
			RIM_NO_INLINE Log& operator < ( const typename util::StaticArray<T,size>& array )
			{
				if ( stream.isNull() )
					return *this;
				
				stream->writeASCII( "[ " );
				
				Index lastIndex = size - 1;
				
				for ( Index i = 0; i < size; i++ )
				{
					*this < array[i];
					
					if ( i != lastIndex )
						stream->writeASCII( ", " );
				}
				
				stream->writeASCII( " ]" );
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Exception Output Operators
			
			
			
			
			/// Write the specified exeception object to this output log.
			/**
			  * This method prints the exception in the form 'exception_type: exception_message'.
			  */
			Log& operator < ( const exceptions::Exception& exception );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Other Type Output Operators
			
			
			
			
			/// Convert the specified templated object to a string and write it to the output log.
			/**
			  * This method uses the specified object's string cast operator to convert it
			  * to a string.
			  */
			template < typename T >
			RIM_INLINE Log& operator < ( const T& object )
			{
				if ( stream.isSet() )
					stream->writeASCII( object.operator data::String() );
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	New Line Output Operator
			
			
			
			
			/// Write a new line character and then log the specified object, using one of the standard '<' operators.
			template < typename T >
			RIM_INLINE Log& operator << ( const T& object )
			{
				*this < '\n' < object;
				
				return *this;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the StringOutputStream object which is being logged to.
			lang::Pointer<StringOutputStream> stream;
			
			
			
};




/// The standard output log object, connected to standard output.
extern Log Console;




//##########################################################################################
//******************************  End Rim IO Namespace  ************************************
RIM_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_LOG_H
