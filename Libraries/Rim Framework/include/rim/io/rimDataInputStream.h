/*
 *  rimDataInputStream.h
 *  Rim IO
 *
 *  Created by Carl Schissler on 10/29/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_DATA_INPUT_STREAM_H
#define INCLUDE_RIM_DATA_INPUT_STREAM_H


#include "rimIOConfig.h"


//##########################################################################################
//******************************  Start Rim IO Namespace  **********************************
RIM_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class/interface which represents an abstract read-only stream of data.
class DataInputStream
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a DataInputStream with the native endianness.
			RIM_INLINE DataInputStream()
			{
			}
			
			
			
			
			/// Create a DataInputStream with the specified endianness.
			RIM_INLINE DataInputStream( data::Endianness newEndianness )
				:	endianness( newEndianness )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy an input stream and free all of it's resources (close it).
			virtual ~DataInputStream()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Primitive Type Read Methods
			
			
			
			
			/// Read a single signed 8-bit integer into the output parameter.
			/**
			  * If the reading operation succeeds, the 8-bit integer is placed in
			  * the output reference paramter, the stream is advanced by 1 byte,
			  * and TRUE is returned. Otherwise, FALSE is returned, no data is
			  * written to the output parameter, and the position of the stream is
			  * undefined.
			  */
			RIM_INLINE Bool read( Int8& value )
			{
				return this->readData( (UByte*)&value, sizeof(Int8) ) == sizeof(Int8);
			}
			
			
			
			
			RIM_INLINE Size read( Int8* buffer, Size number )
			{
				if ( buffer == NULL )
					return 0;
				
				return this->readData( (UByte*)buffer, number );
			}
			
			
			
			
			/// Read a single unsigned 8-bit integer into the output parameter.
			/**
			  * If the reading operation succeeds, the 8-bit integer is placed in
			  * the output reference paramter, the stream is advanced by 1 byte,
			  * and TRUE is returned. Otherwise, FALSE is returned, no data is
			  * written to the output parameter, and the position of the stream is
			  * undefined.
			  */
			RIM_INLINE Bool read( UInt8& value )
			{
				return this->readData( (UByte*)&value, sizeof(UInt8) ) == sizeof(UInt8);
			}
			
			
			
			
			/// Read a single signed 16-bit integer into the output parameter.
			/**
			  * If the reading operation succeeds, the 64-bit integer is placed in
			  * the output reference paramter, the stream is advanced by 2 bytes,
			  * and TRUE is returned. Otherwise, FALSE is returned, no data is
			  * written to the output parameter, and the position of the stream is
			  * undefined.
			  *
			  * The method converts the value into the native platform endianness,
			  * based on the current endianness of the stream.
			  */
			RIM_INLINE Bool read( Int16& value )
			{
				Bool success = this->readData( (UByte*)&value, sizeof(Int16) ) == sizeof(Int16);
				
				value = endianness.convertToNative( value );
				
				return success;
			}
			
			
			
			
			RIM_INLINE Size read( Int16* buffer, Size number )
			{
				if ( buffer == NULL )
					return 0;
				
				return this->readPrimitives( buffer, number );
			}
			
			
			
			
			/// Read a single unsigned 16-bit integer into the output parameter.
			/**
			  * If the reading operation succeeds, the 16-bit integer is placed in
			  * the output reference paramter, the stream is advanced by 2 bytes,
			  * and TRUE is returned. Otherwise, FALSE is returned, no data is
			  * written to the output parameter, and the position of the stream is
			  * undefined.
			  *
			  * The method converts the value into the native platform endianness,
			  * based on the current endianness of the stream.
			  */
			RIM_INLINE Bool read( UInt16& value )
			{
				Bool success = this->readData( (UByte*)&value, sizeof(UInt16) ) == sizeof(UInt16);
				
				value = endianness.convertToNative( value );
				
				return success;
			}
			
			
			
			
			RIM_INLINE Size read( UInt16* buffer, Size number )
			{
				if ( buffer == NULL )
					return 0;
				
				return this->readPrimitives( buffer, number );
			}
			
			
			
			
			/// Read a single signed 32-bit integer into the output parameter.
			/**
			  * If the reading operation succeeds, the 32-bit integer is placed in
			  * the output reference paramter, the stream is advanced by 4 bytes,
			  * and TRUE is returned. Otherwise, FALSE is returned, no data is
			  * written to the output parameter, and the position of the stream is
			  * undefined.
			  *
			  * The method converts the value into the native platform endianness,
			  * based on the current endianness of the stream.
			  */
			RIM_INLINE Bool read( Int32& value )
			{
				Bool success = this->readData( (UByte*)&value, sizeof(Int32) ) == sizeof(Int32);
				
				value = endianness.convertToNative( value );
				
				return success;
			}
			
			
			
			
			RIM_INLINE Size read( Int32* buffer, Size number )
			{
				if ( buffer == NULL )
					return 0;
				
				return this->readPrimitives( buffer, number );
			}
			
			
			
			
			/// Read a single unsigned 32-bit integer into the output parameter.
			/**
			  * If the reading operation succeeds, the 32-bit integer is placed in
			  * the output reference paramter, the stream is advanced by 4 bytes,
			  * and TRUE is returned. Otherwise, FALSE is returned, no data is
			  * written to the output parameter, and the position of the stream is
			  * undefined.
			  *
			  * The method converts the value into the native platform endianness,
			  * based on the current endianness of the stream.
			  */
			RIM_INLINE Bool read( UInt32& value )
			{
				Bool success = this->readData( (UByte*)&value, sizeof(UInt32) ) == sizeof(UInt32);
				
				value = endianness.convertToNative( value );
				
				return success;
			}
			
			
			
			
			RIM_INLINE Size read( UInt32* buffer, Size number )
			{
				if ( buffer == NULL )
					return 0;
				
				return this->readPrimitives( buffer, number );
			}
			
			
			
			
			/// Read a single signed 64-bit integer into the output parameter.
			/**
			  * If the reading operation succeeds, the 64-bit integer is placed in
			  * the output reference paramter, the stream is advanced by 8 bytes,
			  * and TRUE is returned. Otherwise, FALSE is returned, no data is
			  * written to the output parameter, and the position of the stream is
			  * undefined.
			  *
			  * The method converts the value into the native platform endianness,
			  * based on the current endianness of the stream.
			  */
			RIM_INLINE Bool read( Int64& value )
			{
				Bool success = this->readData( (UByte*)&value, sizeof(Int64) ) == sizeof(Int64);
				
				value = endianness.convertToNative( value );
				
				return success;
			}
			
			
			
			
			RIM_INLINE Size read( Int64* buffer, Size number )
			{
				if ( buffer == NULL )
					return 0;
				
				return this->readPrimitives( buffer, number );
			}
			
			
			
			
			/// Read a single unsigned 64-bit integer into the output parameter.
			/**
			  * If the reading operation succeeds, the 64-bit integer is placed in
			  * the output reference paramter, the stream is advanced by 8 bytes,
			  * and TRUE is returned. Otherwise, FALSE is returned, no data is
			  * written to the output parameter, and the position of the stream is
			  * undefined.
			  *
			  * The method converts the value into the native platform endianness,
			  * based on the current endianness of the stream.
			  */
			RIM_INLINE Bool read( UInt64& value )
			{
				Bool success = this->readData( (UByte*)&value, sizeof(UInt64) ) == sizeof(UInt64);
				
				value = endianness.convertToNative( value );
				
				return success;
			}
			
			
			
			
			RIM_INLINE Size read( UInt64* buffer, Size number )
			{
				if ( buffer == NULL )
					return 0;
				
				return this->readPrimitives( buffer, number );
			}
			
			
			
			
			/// Read a single 32-bit floating-point value into the output parameter.
			/**
			  * If the reading operation succeeds, the 32-bit float is placed in
			  * the output reference paramter, the stream is advanced by 4 bytes,
			  * and TRUE is returned. Otherwise, FALSE is returned, no data is
			  * written to the output parameter, and the position of the stream is
			  * undefined.
			  *
			  * The method converts the value into the native platform endianness,
			  * based on the current endianness of the stream.
			  */
			RIM_INLINE Bool read( Float& value )
			{
				Bool success = this->readData( (UByte*)&value, sizeof(Float) ) == sizeof(Float);
				
				value = endianness.convertToNative( value );
				
				return success;
			}
			
			
			
			
			RIM_INLINE Size read( Float* buffer, Size number )
			{
				if ( buffer == NULL )
					return 0;
				
				return this->readPrimitives( buffer, number );
			}
			
			
			
			
			/// Read a single 64-bit floating-point value into the output parameter.
			/**
			  * If the reading operation succeeds, the 64-bit float is placed in
			  * the output reference paramter, the stream is advanced by 8 bytes,
			  * and TRUE is returned. Otherwise, FALSE is returned, no data is
			  * written to the output parameter, and the position of the stream is
			  * undefined.
			  *
			  * The method converts the value into the native platform endianness,
			  * based on the current endianness of the stream.
			  */
			RIM_INLINE Bool read( Double& value )
			{
				Bool success = this->readData( (UByte*)&value, sizeof(Double) ) == sizeof(Double);
				
				value = endianness.convertToNative( value );
				
				return success;
			}
			
			
			
			
			RIM_INLINE Size read( Double* buffer, Size number )
			{
				if ( buffer == NULL )
					return 0;
				
				return this->readPrimitives( buffer, number );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Data Read Methods
			
			
			
			
			/// Read the specified number of bytes from the stream and place them in the buffer given by a pointer.
			/**
			  * The buffer must be large enough to hold the specified number of bytes. The number
			  * of bytes read can be less than the desired number if an error is encountered or the
			  * end of the stream is reached.
			  *
			  * If the method succeeds, the return value will equal the parameter numBytes and
			  * the stream will be advanced by that many bytes. Otherwise, the return value will
			  * be less than the parameter numBytes, indicating the amount that the stream position
			  * changed.
			  * 
			  * @param buffer - a pointer to a buffer where the read data should be placed.
			  * @param numBytes - the number of bytes of data to read from the stream.
			  * @return the number of bytes that were actually read and placed in the buffer.
			  */
			RIM_INLINE Size read( UByte* buffer, Size numBytes )
			{
				if ( buffer == NULL )
					return 0;
				
				return readData( buffer, numBytes );
			}
			
			
			
			
			/// Read the specified number of bytes from the stream and place them in the specified data buffer.
			Size read( data::DataBuffer& buffer, Size numBytes );
			
			
			
			
			/// Read as many bytes from the stream as possible and return them in a Data object.
			data::Data readAllData();
			
			
			
			
			/// Read as many bytes from the stream as possible and place them in the specified data buffer.
			/**
			  * The method returns the total number of bytes written to the buffer.
			  */
			Size readAllData( data::DataBuffer& buffer );
			
			
			
			
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
		//******	Remaining Data Size Accessor Methods
			
			
			
			
			/// Return whether or not there are bytes remaining in the stream.
			RIM_INLINE Bool hasBytesRemaining() const
			{
				return this->getBytesRemaining() > 0;
			}
			
			
			
			
			/// Return the number of bytes remaining in the stream.
			/**
			  * The value returned must only be a lower bound on the number of bytes
			  * remaining in the stream. If there are bytes remaining, it must return
			  * at least 1.
			  */
			virtual LargeSize getBytesRemaining() const = 0;
			
			
			
			
			/// Return the current byte index within the stream relative to the beginning.
			virtual LargeIndex getPosition() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Endian-ness Accessor Methods
			
			
			
			
			/// Get the current endianness of the data being read from the buffer.
			RIM_INLINE data::Endianness getEndianness() const
			{
				return endianness;
			}
			
			
			
			
			/// Set the buffer to read data in big endian format.
			RIM_INLINE void setEndianness( data::Endianness newEndianness )
			{
				endianness = newEndianness;
			}
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Data Read Method
			
			
			
			
			/// Read the specified number of bytes from the stream and place them in the specified output buffer.
			virtual Size readData( UByte* buffer, Size number ) = 0;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Method
			
			
			
			
			/// Read the specified number of elements of a primitive type, converting endianness.
			template < typename T >
			RIM_NO_INLINE Size readPrimitives( T* buffer, Size number )
			{
				Size numRead = this->readData( (UByte*)buffer, sizeof(T)*number ) / sizeof(T);
				const T* const bufferEnd = buffer + numRead;
				
				for ( ; buffer != bufferEnd; buffer++ )
					*buffer = endianness.convertToNative( *buffer );
				
				return numRead;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The endianness in which the data being read from the stream is assumed to be in.
			/**
			  * Upon reading primitive types from the stream, they are converted to the platform's
			  * native endianness before being returned to the user.
			  */
			data::Endianness endianness;
			
			
			
			
};




//##########################################################################################
//******************************  End Rim IO Namespace  ************************************
RIM_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_DATA_INPUT_STREAM_H
