/*
 *  rimBasicStringIterator.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 7/17/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_BASIC_STRING_ITERATOR_H
#define INCLUDE_RIM_BASIC_STRING_ITERATOR_H


#include "rimDataConfig.h"


#include "rimBasicString.h"


//##########################################################################################
//*******************************   Start Data Namespace   *********************************
RIM_DATA_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




/// Declaration for a string iterator which iterates over strings with the specified character type.
template < typename CharType >
class BasicStringIterator;




//##########################################################################################
//##########################################################################################
//############		
//############		ASCII Basic String Iterator Specialization
//############		
//##########################################################################################
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which iterates over ASCII character strings.
template <>
class BasicStringIterator<Char>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a string iterator that iterates over the specified NULL-terminated string.
			RIM_INLINE BasicStringIterator( const Char* string )
				:	current( string ),
					start( string ),
					end( NULL )
			{
				RIM_DEBUG_ASSERT_MESSAGE( string != NULL, "Cannot iterate over NULL string" );
			}
			
			
			
			
			/// Create a string iterator that iterates over the specified string.
			RIM_INLINE BasicStringIterator( const Char* string, Size length )
				:	current( string ),
					start( string ),
					end( string + length )
			{
				RIM_DEBUG_ASSERT_MESSAGE( string != NULL, "Cannot iterate over NULL string" );
			}
			
			
			
			
			/// Create a string iterator that iterates over the specified string object.
			RIM_INLINE BasicStringIterator( const BasicString<Char>& string )
				:	current( string.getCString() ),
					start( string.getCString() )
			{
				end = start + string.getLength();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Increment Methods
			
			
			
			
			/// Increment the iterator to the next character in the string.
			RIM_INLINE void operator ++ ()
			{
				current++;
			}
			
			
			
			
			/// Increment the iterator to the next character in the string.
			RIM_INLINE void operator ++ ( int )
			{
				current++;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Iterator State Accessor Method
			
			
			
			
			/// Return whether or not the end of the string has been reached.
			RIM_INLINE operator Bool () const
			{
				if ( end )
					return current != end;
				else
					return *current != '\0';
			}
			
			
			
			
			/// Return the current code point index within the string being iterated over.
			RIM_INLINE Index getIndex() const
			{
				return current - start;
			}
			
			
			
			
			/// Return the index of the next character in the string.
			RIM_INLINE Index getCharacterIndex() const
			{
				return current - start;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Current Character Accessor Method
			
			
			
			
			/// Return the current character of the iterator.
			RIM_INLINE Char operator * () const
			{
				return *current;
			}
			
			
			
			
			/// Return a pointer to the current character of the iterator.
			RIM_INLINE operator const Char* () const
			{
				return current;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Iterator Reset Method
			
			
			
			
			/// Reset the iterator to the first character in the string it is iterating over.
			RIM_INLINE void reset()
			{
				current = start;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the current character of the string iterator.
			const Char* current;
			
			
			
			
			/// A pointer to the first character of the string being iterated over.
			const Char* start;
			
			
			
			
			/// A pointer to just past the last character of the string being iterated over.
			const Char* end;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		UTF-8 Basic String Iterator Specialization
//############		
//##########################################################################################
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which iterates over UTF-8 encoded character strings.
template <>
class BasicStringIterator<UTF8Char>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a string iterator that iterates over the specified NULL-terminated string.
			RIM_INLINE BasicStringIterator( const UTF8Char* string )
				:	current( string ),
					start( string ),
					end( NULL ),
					characterIndex( 0 )
			{
				RIM_DEBUG_ASSERT_MESSAGE( string != NULL, "Cannot iterate over NULL string" );
			}
			
			
			
			
			/// Create a string iterator that iterates over the specified string.
			RIM_INLINE BasicStringIterator( const UTF8Char* string, Size length )
				:	current( string ),
					start( string ),
					end( string + length ),
					characterIndex( 0 )
			{
				RIM_DEBUG_ASSERT_MESSAGE( string != NULL, "Cannot iterate over NULL string" );
			}
			
			
			
			
			/// Create a string iterator that iterates over the specified string object.
			RIM_INLINE BasicStringIterator( const BasicString<UTF8Char>& string )
				:	current( string.getCString() ),
					start( string.getCString() ),
					characterIndex( 0 )
			{
				end = start + string.getLength();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Increment Methods
			
			
			
			
			/// Increment the iterator to the next character in the string.
			RIM_INLINE void operator ++ ()
			{
				(*this)++;
			}
			
			
			
			
			/// Increment the iterator to the next character in the string.
			RIM_INLINE void operator ++ ( int )
			{
				if ( *current < 0x80 )
				{
					// This is a single-byte UTF-8 character, skip one byte.
					current++;
				}
				else
					this->advanceMultiByteCharacter();
				
				characterIndex++;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Iterator State Accessor Method
			
			
			
			
			/// Return whether or not the end of the string has been reached.
			RIM_INLINE operator Bool () const
			{
				if ( end )
					return current != end;
				else
					return *current != '\0';
			}
			
			
			
			
			/// Return the current code point index within the string being iterated over.
			RIM_INLINE Index getIndex() const
			{
				return current - start;
			}
			
			
			
			
			/// Return the index of the next character in the string.
			/**
			  * This is not the same as the code point index because there may be
			  * characters which use more than one code point in their representation. 
			  */
			RIM_INLINE Index getCharacterIndex() const
			{
				return characterIndex;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Current Character Accessor Method
			
			
			
			
			/// Return the current character of the iterator.
			RIM_INLINE UTF32Char operator * () const
			{
				if ( *current < 0x80 )
				{
					// This is a single-byte UTF-8 character.
					return UTF32Char(*current);
				}
				else
					return this->getMultiByteCharacter();
			}
			
			
			
			
			/// Return a pointer to the current character of the iterator.
			RIM_INLINE operator const UTF8Char* () const
			{
				return current;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Iterator Reset Method
			
			
			
			
			/// Reset the iterator to the first character in the string it is iterating over.
			RIM_INLINE void reset()
			{
				current = start;
				characterIndex = 0;
			}
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Return a UTF-32 character when the current character describes the start of multibyte character.
			UTF32Char getMultiByteCharacter() const;
			
			
			
			
			/// Advance to the next character if it the current character is a multibyte character.
			void advanceMultiByteCharacter();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the current character of the string iterator.
			const UTF8Char* current;
			
			
			
			
			/// A pointer to the first character of the string being iterated over.
			const UTF8Char* start;
			
			
			
			
			/// A pointer to just past the last character of the string being iterated over.
			const UTF8Char* end;
			
			
			
			
			/// The index of the next character in the string, independent of the code point index.
			Index characterIndex;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		UTF-16 Basic String Iterator Specialization
//############		
//##########################################################################################
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which iterates over UTF-16 encoded character strings.
template <>
class BasicStringIterator<UTF16Char>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a string iterator that iterates over the specified NULL-terminated string.
			RIM_INLINE BasicStringIterator( const UTF16Char* string )
				:	current( string ),
					start( string ),
					end( NULL ),
					characterIndex( 0 )
			{
				RIM_DEBUG_ASSERT_MESSAGE( string != NULL, "Cannot iterate over NULL string" );
			}
			
			
			
			
			/// Create a string iterator that iterates over the specified NULL-terminated string.
			RIM_INLINE BasicStringIterator( const UTF16Char* string, Size length )
				:	current( string ),
					start( string ),
					end( string + length ),
					characterIndex( 0 )
			{
				RIM_DEBUG_ASSERT_MESSAGE( string != NULL, "Cannot iterate over NULL string" );
			}
			
			
			
			
			/// Create a string iterator that iterates over the specified string object.
			RIM_INLINE BasicStringIterator( const BasicString<UTF16Char>& string )
				:	current( string.getCString() ),
					start( string.getCString() ),
					characterIndex( 0 )
			{
				end = start + string.getLength();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Increment Methods
			
			
			
			
			/// Increment the iterator to the next character in the string.
			RIM_INLINE void operator ++ ()
			{
				(*this)++;
			}
			
			
			
			
			/// Increment the iterator to the next character in the string.
			RIM_INLINE void operator ++ ( int )
			{
				if ( *current >= 0xD800 && *current <= 0xDBFF )
				{
					// This is two-point UTF-16 character. Skip two points.
					current += 2;
				}
				else
				{
					// This is either a malformed character or a single point character. Skip one.
					current++;
				}
				
				characterIndex++;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Iterator State Accessor Method
			
			
			
			
			/// Return whether or not the end of the string has been reached.
			RIM_INLINE operator Bool () const
			{
				if ( end )
					return current != end;
				else
					return *current != '\0';
			}
			
			
			
			
			/// Return the current code point index within the string being iterated over.
			RIM_INLINE Index getIndex() const
			{
				return current - start;
			}
			
			
			
			
			/// Return the index of the next character in the string.
			/**
			  * This is not the same as the code point index because there may be
			  * characters which use more than one code point in their representation. 
			  */
			RIM_INLINE Index getCharacterIndex() const
			{
				return characterIndex;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Current Character Accessor Method
			
			
			
			
			/// Return the current character of the iterator.
			UTF32Char operator * () const;
			
			
			
			
			/// Return a pointer to the current character of the iterator.
			RIM_INLINE operator const UTF16Char* () const
			{
				return current;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Iterator Reset Method
			
			
			
			
			/// Reset the iterator to the first character in the string it is iterating over.
			RIM_INLINE void reset()
			{
				current = start;
				characterIndex = 0;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the current character of the string iterator.
			const UTF16Char* current;
			
			
			
			
			/// A pointer to the first character of the string being iterated over.
			const UTF16Char* start;
			
			
			
			
			/// A pointer to just past the last character of the string being iterated over.
			const UTF16Char* end;
			
			
			
			
			/// The index of the next character in the string, independent of the code point index.
			Index characterIndex;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		UTF-32 Basic String Iterator Specialization
//############		
//##########################################################################################
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which iterates over UTF-32 encoded character strings.
template <>
class BasicStringIterator<UTF32Char>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a string iterator that iterates over the specified NULL-terminated string.
			RIM_INLINE BasicStringIterator( const UTF32Char* string )
				:	current( string ),
					start( string ),
					end( NULL )
			{
				RIM_DEBUG_ASSERT_MESSAGE( string != NULL, "Cannot iterate over NULL string" );
			}
			
			
			
			
			/// Create a string iterator that iterates over the specified string.
			RIM_INLINE BasicStringIterator( const UTF32Char* string, Size length )
				:	current( string ),
					start( string ),
					end( string + length )
			{
				RIM_DEBUG_ASSERT_MESSAGE( string != NULL, "Cannot iterate over NULL string" );
			}
			
			
			
			
			/// Create a string iterator that iterates over the specified string object.
			RIM_INLINE BasicStringIterator( const BasicString<UTF32Char>& string )
				:	current( string.getCString() ),
					start( string.getCString() )
			{
				end = start + string.getLength();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Increment Methods
			
			
			
			
			/// Increment the iterator to the next character in the string.
			RIM_INLINE void operator ++ ()
			{
				current++;
			}
			
			
			
			
			/// Increment the iterator to the next character in the string.
			RIM_INLINE void operator ++ ( int )
			{
				current++;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Iterator State Accessor Method
			
			
			
			
			/// Return whether or not the end of the string has been reached.
			RIM_INLINE operator Bool () const
			{
				if ( end )
					return current != end;
				else
					return *current != '\0';
			}
			
			
			
			
			/// Return the current code point index within the string being iterated over.
			RIM_INLINE Index getIndex() const
			{
				return current - start;
			}
			
			
			
			
			/// Return the character index within the string being iterated over.
			RIM_INLINE Index getCharacterIndex() const
			{
				return current - start;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Current Character Accessor Method
			
			
			
			
			/// Return the current character of the iterator.
			RIM_INLINE UTF32Char operator * () const
			{
				return *current;
			}
			
			
			
			
			/// Return a pointer to the current character of the iterator.
			RIM_INLINE operator const UTF32Char* () const
			{
				return current;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Iterator Reset Method
			
			
			
			
			/// Reset the iterator to the first character in the string it is iterating over.
			RIM_INLINE void reset()
			{
				current = start;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the current character of the string iterator.
			const UTF32Char* current;
			
			
			
			
			/// A pointer to the first character of the string being iterated over.
			const UTF32Char* start;
			
			
			
			
			/// A pointer to just past the last character of the string being iterated over.
			const UTF32Char* end;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		String Iterator Type Definitions
//############		
//##########################################################################################
//##########################################################################################




/// A class which iterates over ASCII encoded character strings.
typedef BasicStringIterator<Char> StringIterator;




/// A class which iterates over UTF-8 encoded character strings.
typedef BasicStringIterator<UTF8Char> UTF8StringIterator;




/// A class which iterates over UTF-16 encoded character strings.
typedef BasicStringIterator<UTF16Char> UTF16StringIterator;




/// A class which iterates over UTF-32 encoded character strings.
typedef BasicStringIterator<UTF32Char> UTF32StringIterator;




//##########################################################################################
//*******************************   End Data Namespace   ***********************************
RIM_DATA_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_BASIC_STRING_ITERATOR_H
