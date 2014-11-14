/*
 *  rimBasicStringBuffer.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 11/26/07.
 *  Copyright 2007 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_BASIC_STRING_BUFFER_H
#define INCLUDE_RIM_BASIC_STRING_BUFFER_H


#include "rimDataConfig.h"


#include "../util/rimArray.h"


#include "rimBasicString.h"



// Forward-declare the StringInputStream class so that we can mark it as a friend.
namespace rim { namespace io { class StringInputStream; }; };


//##########################################################################################
//*******************************   Start Data Namespace   *********************************
RIM_DATA_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains a buffer of characters of templated type.
/** 
  * This class allows the user to accumulate characters in a resizing buffer,
  * then convert the buffer's internal array to a string for other uses.
  */
template < typename CharType >
class BasicStringBuffer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an empty buffer with the default initial capacity.
			BasicStringBuffer();
			
			
			
			
			/// Create an empty buffer with the specified initial capacity and resize factor.
			BasicStringBuffer( Size initialCapacity, Float newResizeFactor = DEFAULT_RESIZE_FACTOR );
			
			
			
			
			/// Create an identical copy of the specified buffer.
			BasicStringBuffer( const BasicStringBuffer& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a buffer, deallocating all resources used.
			RIM_INLINE ~BasicStringBuffer()
			{
				util::deallocate( buffer );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of one string buffer to another, performing a deep copy.
			BasicStringBuffer& operator = ( const BasicStringBuffer& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Append Methods
			
			
			
			
			/// Append an element to the end of this buffer.
			BasicStringBuffer& append( const CharType& character );
			
			
			
			
			/// Append all characters from the given NULL-terminated string.
			BasicStringBuffer& append( const CharType* source );
			
			
			
			
			/// Append the specified number of elements from the given string.
			BasicStringBuffer& append( const CharType* source, Size numElements );
			
			
			
			
			/// Append a string to this string buffer.
			RIM_INLINE BasicStringBuffer& append( const BasicString<CharType>& string )
			{
				return append( string.getCString(), string.getLength() );
			}
			
			
			
			
			template < typename OtherCharType >
			RIM_INLINE BasicStringBuffer& append( const BasicString<OtherCharType>& string )
			{
				return append( BasicString<CharType>(string) );
			}
			
			
			
			
			/// Append all elements from the specified character array to the end of the buffer.
			RIM_INLINE BasicStringBuffer& append( const util::Array<CharType>& array )
			{
				return append( array.getPointer(), array.getSize() );
			}
			
			
			
			
			/// Append a certain number of elements from the specified array to the end of the buffer.
			RIM_INLINE BasicStringBuffer& append( const util::Array<CharType>& array, Size number )
			{
				return append( array.getPointer(), math::min( number, array.getSize() ) );
			}
			
			
			
			
			/// Append all data from the specified buffer.
			RIM_INLINE BasicStringBuffer& append( const BasicStringBuffer& aBuffer )
			{
				return append( aBuffer.buffer, aBuffer.getSize() );
			}
			
			
			
			
			/// Convert the object of templated type to a string and append it to the buffer.
			template < typename T >
			RIM_INLINE BasicStringBuffer& append( const T& object )
			{
				return append( (BasicString<CharType>)object );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Append Operators
			
			
			
			
			/// Append a character to the end of this string buffer.
			RIM_INLINE BasicStringBuffer& operator << ( const CharType& character )
			{
				return append( character );
			}
			
			
			
			
			/// Append a NULL-terminated character string to the end of this buffer.
			RIM_INLINE BasicStringBuffer& operator << ( const CharType* character )
			{
				return append( character );
			}
			
			
			
			
			/// Append a string to the end of this buffer.
			RIM_INLINE BasicStringBuffer& operator << ( const BasicString<CharType>& string )
			{
				return append( string );
			}
			
			
			
			
			/// Append a string to the end of this buffer.
			template < typename OtherCharType >
			RIM_INLINE BasicStringBuffer& operator << ( const BasicString<OtherCharType>& string )
			{
				return append( BasicString<CharType>(string) );
			}
			
			
			
			
			/// Append all elements from the specified character array to the end of the string buffer.
			RIM_INLINE BasicStringBuffer& operator << ( const util::Array<CharType>& array )
			{
				return append( array );
			}
			
			
			
			
			/// Append all characters from the specified buffer to this buffer.
			RIM_INLINE BasicStringBuffer& operator << ( const BasicStringBuffer& aBuffer )
			{
				return append( aBuffer );
			}
			
			
			
			
			/// Convert the object of templated type to a string and append it to the buffer.
			template < typename T >
			RIM_INLINE BasicStringBuffer& operator << ( const T& object )
			{
				return append( (BasicString<CharType>)object );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Remove Methods
			
			
			
			
			/// Remove the specified number of code points from the end of this string buffer.
			/**
			  * The method returns the number of character code points that were removed.
			  */
			Size remove( Size numCharacters )
			{
				// Don't remove more characters than are in the buffer.
				numCharacters = math::min( numCharacters, Size(nextElement - buffer) );
				
				// Rewind the next element pointer.
				nextElement -= numCharacters;
				
				// Make the string NULL-terminated.
				*nextElement = '\0';
				
				return numCharacters;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Clear Method
			
			
			
			
			/// Clear the contents of the buffer, keeping its capacity intact.
			RIM_INLINE void clear()
			{
				nextElement = buffer;
				*nextElement = '\0';
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content Accessor Methods
			
			
			
			
			/// Convert the contents of this buffer to a string object.
			RIM_INLINE BasicString<CharType> toString() const
			{
				return BasicString<CharType>( buffer, nextElement - buffer );
			}
			
			
			
			
			/// Convert the contents of this buffer to a string object.
			RIM_INLINE operator BasicString<CharType> ()
			{
				return BasicString<CharType>( buffer, nextElement - buffer );
			}
			
			
			
			
			/// Get a pointer pointing to the buffer's internal array.
			RIM_INLINE const CharType* getPointer() const
			{
				return buffer;
			}
			
			
			
			
			/// Get a pointer pointing to the buffer's internal array.
			RIM_INLINE const CharType* getCString() const
			{
				return buffer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Get the number of characters in the buffer, excluding the NULL terminator.
			RIM_INLINE Size getSize() const
			{
				return nextElement - buffer;
			}
			
			
			
			
			/// Get the number of characters in the buffer, excluding the NULL terminator.
			RIM_INLINE Size getLength() const
			{
				return nextElement - buffer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Capacity Accessor Methods
			
			
			
			
			
			/// Get the number of elements the buffer can hold without resizing.
			RIM_INLINE Size getCapacity() const
			{
				return capacity;
			}
			
			
			
			
			/// Set the number of elements the buffer can hold.
			RIM_INLINE Bool setCapacity( Size newCapacity )
			{
				if ( newCapacity < getSize() )
					return false;
				else
				{
					resize( newCapacity );
					return true;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resize Factor Accessor Methods
			
			
			
			
			/// Get the resize factor for this buffer.
			RIM_INLINE Float getResizeFactor() const
			{
				return resizeFactor;
			}
			
			
			
			
			/// Set the resize factor for this buffer, clamped to [1.1, 10.0]
			RIM_INLINE void setResizeFactor( Float newResizeFactor )
			{
				resizeFactor = math::clamp( newResizeFactor, 1.1f, 10.0f );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Methods
			
			
			
			
			/// Increase the capacity to at least the specified amount using the resize factor.
			RIM_INLINE void increaseCapacity( Size minimumCapacity )
			{
				resize( math::max( minimumCapacity, Size(Float(capacity)*resizeFactor) ) );
			}
			
			
			
			
			/// Increase the capacity to be the current factor multiplied by the resize factor.
			RIM_INLINE void increaseCapacity()
			{
				resize( Size(Float(capacity)*resizeFactor) );
			}
			
			
			
			
			/// Resize the internal buffer to be the specified length.
			void resize( Size newCapacity );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An array of elements which is the buffer.
			CharType* buffer;
			
			
			
			
			/// A pointer to the location in the buffer where the next element should be inserted.
			CharType* nextElement;
			
			
			
			
			/// A pointer to the first element past the end of the buffer.
			const CharType* bufferEnd;
			
			
			
			
			/// The number of elements that the buffer can hold.
			Size capacity;
			
			
			
			
			/// How much the buffer's capacity increases when it needs to.
			Float resizeFactor;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The default capacity for a buffer if it is not specified.
			static const Size DEFAULT_CAPACITY = 32;
			
			
			
			
			/// The default factor by which the buffer resizes.
			static const Float DEFAULT_RESIZE_FACTOR;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Friend Class Declarations
			
			
			
			
			/// Mark the StringInputStream class as a friend so that it can modify a buffer's internals.
			friend class rim::io::StringInputStream;
			
			
			
};




template < typename CharType >
const Float		BasicStringBuffer<CharType>::	DEFAULT_RESIZE_FACTOR = 2.0f;




//##########################################################################################
//##########################################################################################
//############		
//############		String Buffer Type Definitions
//############		
//##########################################################################################
//##########################################################################################




/// A class which represents a buffer of ASCII encoded characters.
typedef BasicStringBuffer<Char> StringBuffer;




/// A class which represents a buffer of UTF-8 encoded characters.
typedef BasicStringBuffer<UTF8Char> UTF8StringBuffer;




/// A class which represents a buffer of UTF-16 encoded characters.
typedef BasicStringBuffer<UTF16Char> UTF16StringBuffer;




/// A class which represents a buffer of UTF-32 encoded characters.
typedef BasicStringBuffer<UTF32Char> UTF32StringBuffer;




//##########################################################################################
//*******************************   End Data Namespace   ***********************************
RIM_DATA_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_BASIC_STRING_BUFFER_H
