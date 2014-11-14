/*
 *  rimDataOutputStream.h
 *  Rim IO
 *
 *  Created by Carl Schissler on 10/29/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_DATA_OUTPUT_STREAM_H
#define INCLUDE_RIM_DATA_OUTPUT_STREAM_H


#include "rimIOConfig.h"


//##########################################################################################
//******************************  Start Rim IO Namespace  **********************************
RIM_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class/interface which represents an abstract write-only stream of data.
class DataOutputStream
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a DataOutputStream with the native output endianness.
			RIM_INLINE DataOutputStream()
			{
			}
			
			
			
			
			/// Create a DataOutputStream with the specified output endianness.
			RIM_INLINE DataOutputStream( data::Endianness newEndianness )
				:	endianness( newEndianness )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy an output stream and free all of its resources (close it).
			virtual ~DataOutputStream()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Primitive Type Write Methods
			
			
			
			
			/// Write the specified signed 8-bit integer value to the data output stream.
			/**
			  * The method returns TRUE if the value was successfully written. Otherwise,
			  * the method returns FALSE and nothing is written to the stream.
			  */
			RIM_INLINE Bool write( Int8 value )
			{
				return writeData( (const UByte*)&value, sizeof(Int8) ) == sizeof(Int8);
			}
			
			
			
			
			/// Write the specified unsigned 8-bit integer value to the data output stream.
			/**
			  * The method returns TRUE if the value was successfully written. Otherwise,
			  * the method returns FALSE and nothing is written to the stream.
			  */
			RIM_INLINE Bool write( UInt8 value )
			{
				return writeData( (const UByte*)&value, sizeof(UInt8) ) == sizeof(UInt8);
			}
			
			
			
			
			/// Write the specified signed 16-bit integer value to the data output stream.
			/**
			  * The method returns TRUE if the value was successfully written. Otherwise,
			  * the method returns FALSE and nothing is written to the stream.
			  */
			RIM_INLINE Bool write( Int16 value )
			{
				Int16 temp = endianness.convertFromNative( value );
				return writeData( (const UByte*)&temp, sizeof(Int16) ) == sizeof(Int16);
			}
			
			
			
			
			/// Write the specified unsigned 16-bit integer value to the data output stream.
			/**
			  * The method returns TRUE if the value was successfully written. Otherwise,
			  * the method returns FALSE and nothing is written to the stream.
			  */
			RIM_INLINE Bool write( UInt16 value )
			{
				UInt16 temp = endianness.convertFromNative( value );
				return writeData( (const UByte*)&temp, sizeof(UInt16) ) == sizeof(UInt16);
			}
			
			
			
			
			/// Write the specified signed 32-bit integer value to the data output stream.
			/**
			  * The method returns TRUE if the value was successfully written. Otherwise,
			  * the method returns FALSE and nothing is written to the stream.
			  */
			RIM_INLINE Bool write( Int32 value )
			{
				Int32 temp = endianness.convertFromNative( value );
				return writeData( (const UByte*)&temp, sizeof(Int32) ) == sizeof(Int32);
			}
			
			
			
			
			/// Write the specified unsigned 32-bit integer value to the data output stream.
			/**
			  * The method returns TRUE if the value was successfully written. Otherwise,
			  * the method returns FALSE and nothing is written to the stream.
			  */
			RIM_INLINE Bool write( UInt32 value )
			{
				UInt32 temp = endianness.convertFromNative( value );
				return writeData( (const UByte*)&temp, sizeof(UInt32) ) == sizeof(UInt32);
			}
			
			
			
			
			/// Write the specified signed 64-bit integer value to the data output stream.
			/**
			  * The method returns TRUE if the value was successfully written. Otherwise,
			  * the method returns FALSE and nothing is written to the stream.
			  */
			RIM_INLINE Bool write( Int64 value )
			{
				Int64 temp = endianness.convertFromNative( value );
				return writeData( (const UByte*)&temp, sizeof(Int64) ) == sizeof(Int64);
			}
			
			
			
			
			/// Write the specified unsigned 64-bit integer value to the data output stream.
			/**
			  * The method returns TRUE if the value was successfully written. Otherwise,
			  * the method returns FALSE and nothing is written to the stream.
			  */
			RIM_INLINE Bool write( UInt64 value )
			{
				UInt64 temp = endianness.convertFromNative( value );
				return writeData( (const UByte*)&temp, sizeof(UInt64) ) == sizeof(UInt64);
			}
			
			
			
			
			/// Write the specified 32-bit floating-point value to the data output stream.
			/**
			  * The method returns TRUE if the value was successfully written. Otherwise,
			  * the method returns FALSE and nothing is written to the stream.
			  */
			RIM_INLINE Bool write( Float32 value )
			{
				Float32 temp = endianness.convertFromNative( value );
				return writeData( (const UByte*)&temp, sizeof(Float32) ) == sizeof(Float32);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Data Write Methods
			
			
			
			
			/// Write as much of the specified data array to the stream and return the number of bytes written.
			RIM_INLINE Size write( const data::Data& data )
			{
				return writeData( data.getPointer(), data.getSize() );
			}
			
			
			
			
			/// Write as much of the specified data array to the stream and return the number of bytes written.
			RIM_INLINE Size write( const data::DataBuffer& dataBuffer )
			{
				return writeData( dataBuffer.getPointer(), dataBuffer.getSize() );
			}
			
			
			
			
			/// Write as many bytes as possible from the specified data pointer and return the number written.
			RIM_INLINE Size write( const UByte* data, Size number )
			{
				if ( data == NULL )
					return 0;
				
				return writeData( data, number );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flush Method
			
			
			
			
			/// Flush the output stream, sending all internally buffered output to it's destination.
			/** 
			  * This method causes all currently pending output data to be sent to it's
			  * final destination. This method ensures that this is done and that all internal
			  * data buffers are emptied if they have any contents.
			  */
			virtual void flush() = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Seeking Methods
			
			
			
			
			/// Return whether or not this type of stream allows seeking.
			/**
			  * Some types of IO (like files) allow seeking, but others, especially those
			  * over networks don't allow streaming. This method allows the user to detect
			  * that situation.
			  */
			virtual Bool canSeek() const = 0;
			
			
			
			
			/// Return whether or not this stream can seek by the specified amount in bytes.
			/**
			  * Since some streams may not support rewinding, this method can be used
			  * to determine if a given seek operation can succeed. The method can also
			  * be used to determine if the end of a stream has been reached, a seek past
			  * the end of a file will fail.
			  */
			virtual Bool canSeek( Int64 relativeOffset ) const = 0;
			
			
			
			
			/// Move the current position in the stream by the specified relative signed offset in bytes.
			/**
			  * The method attempts to seek in the stream by the specified amount and
			  * returns the signed amount that the position in the stream was changed by
			  * in bytes. A negative offset indicates that the position should be moved in
			  * reverse and a positive offset indicates that the position should be moved
			  * forwards.
			  */
			virtual Int64 seek( Int64 relativeOffset ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Endian-ness Accessor Methods
			
			
			
			
			/// Get the current endianness of the data being written to the stream.
			RIM_INLINE data::Endianness getEndianness() const
			{
				return endianness;
			}
			
			
			
			
			/// Set the stream to write data in the specified endian format.
			RIM_INLINE void setEndianness( data::Endianness newEndianness )
			{
				endianness = newEndianness;
			}
			
			
			
			
	protected:
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Data Write Methods
			
			
			
			
			/// Write the specified number of bytes of data from the buffer to the stream.
			virtual Size writeData( const UByte* data, Size number ) = 0;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The endianness with which the data output to the stream is being written in.
			data::Endianness endianness;
			
			
			
};




//##########################################################################################
//******************************  End Rim IO Namespace  ************************************
RIM_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_DATA_OUTPUT_STREAM_H
