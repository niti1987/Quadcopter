/*
 *  rimBasicString.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 7/13/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_BASIC_STRING_H
#define INCLUDE_RIM_BASIC_STRING_H


#include "rimDataConfig.h"


#include "rimHashCode.h"


//##########################################################################################
//*******************************   Start Data Namespace   *********************************
RIM_DATA_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


template < typename CharType >
class BasicStringBuffer;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A string class supporting unicode and ASCII character sets.
/**
  * The BasicString class is a template class which allows the user to use any of
  * four different specializations: Char for ASCII strings, UTF8Char for UTF-8 strings,
  * UTF16Char for UTF-16 strings, and UTF32Char for UTF-32 strings. In addition to this
  * functionality, it provides comprehensive number-to-string and string-to-number conversion
  * using constructors and cast operators. All strings are immutable after creation.
  * Use the BasicStringBuffer class to efficiently compose strings.
  *
  * Strings are reference-counted, so the overhead of copying a string object
  * is very small.
  */
template < typename CharType >
class BasicString
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an empty string.
			RIM_INLINE BasicString()
				:	shared( nullString )
			{
				shared->referenceCount++;
				string = shared->getCharacters();
			}
			
			
			
			
			/// Create a string consisting of a single character.
			RIM_INLINE BasicString( Char character )
				:	shared( allocateString( 2 ) )
			{
				string = shared->getCharacters();
				string[0] = character;
				string[1] = '\0';
			}
			
			
			
			
			/// Create a string from a NULL-terminated character array.
			BasicString( const Char* array );
			
			
			
			
			/// Create a string from a NULL-terminated character array.
			BasicString( const UTF8Char* array );
			
			
			
			
			/// Create a string from a NULL-terminated character array.
			BasicString( const UTF16Char* array );
			
			
			
			
			/// Create a string from a NULL-terminated character array.
			BasicString( const UTF32Char* array );
			
			
			
			
			/// Create a string from a character array with the specified length.
			BasicString( const Char* array, Size length );
			
			
			
			
			/// Create a string from a character array with the specified length.
			BasicString( const UTF8Char* array, Size length );
			
			
			
			
			/// Create a string from a character array with the specified length.
			BasicString( const UTF16Char* array, Size length );
			
			
			
			
			/// Create a string from a character array with the specified length.
			BasicString( const UTF32Char* array, Size length );
			
			
			
			
			/// Create a copy of the specified other string.
			RIM_INLINE BasicString( const BasicString& other )
				:	shared( other.shared ),
					string( other.string )
			{
				shared->referenceCount++;
			}
			
			
			
			
			/// Create a copy of the specified other string with a different character type.
			template < typename OtherCharType >
			explicit BasicString( const BasicString<OtherCharType>& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Number-To-String Conversion Constructors
			
			
			
			
			/// Create a new boolean literal string for the specified value.
			RIM_INLINE explicit BasicString( Bool boolean )
				:	shared( boolean ? trueString : falseString )
			{
				shared->referenceCount++;
				string = shared->getCharacters();
			}
			
			
			
			
			/// Create a string which represents the specified integer number in the given base system.
			RIM_INLINE explicit BasicString( Short number, Size base = 10 )
				:	shared( fromIntegerType( (Int32)number, base ) )
			{
				string = shared->getCharacters();
			}
			
			
			
			
			/// Create a string which represents the specified integer number in the given base system.
			RIM_INLINE explicit BasicString( UShort number, Size base = 10 )
				:	shared( fromIntegerType( (UInt32)number, base ) )
			{
				string = shared->getCharacters();
			}
			
			
			
			
			/// Create a string which represents the specified integer number in the given base system.
			RIM_INLINE explicit BasicString( Int number, Size base = 10 )
				:	shared( fromIntegerType( (Int32)number, base ) )
			{
				string = shared->getCharacters();
			}
			
			
			
			
			/// Create a string which represents the specified integer number in the given base system.
			RIM_INLINE explicit BasicString( UInt number, Size base = 10 )
				:	shared( fromIntegerType( (UInt32)number, base ) )
			{
				string = shared->getCharacters();
			}
			
			
			
			
			/// Create a string which represents the specified integer number in the given base system.
			RIM_INLINE explicit BasicString( Long number, Size base = 10 )
				:	shared( fromIntegerType( (Int32)number, base ) )
			{
				string = shared->getCharacters();
			}
			
			
			
			
			/// Create a string which represents the specified integer number in the given base system.
			RIM_INLINE explicit BasicString( ULong number, Size base = 10 )
				:	shared( fromIntegerType( (UInt32)number, base ) )
			{
				string = shared->getCharacters();
			}
			
			
			
			
			/// Create a string which represents the specified integer number in the given base system.
			RIM_INLINE explicit BasicString( LongLong number, Size base = 10 )
				:	shared( fromIntegerType( (Int64)number, base ) )
			{
				string = shared->getCharacters();
			}
			
			
			
			
			/// Create a string which represents the specified integer number in the given base system.
			RIM_INLINE explicit BasicString( ULongLong number, Size base = 10 )
				:	shared( fromIntegerType( (UInt64)number, base ) )
			{
				string = shared->getCharacters();
			}
			
			
			
			
			/// Create a string which represents the specified floating-point number with default formating.
			/**
			  * The number is displayed with the maximum precision for its type in base 10,
			  * and scientific notation is automatically used when necessary.
			  */
			RIM_INLINE explicit BasicString( Float number )
				:	shared( fromFloatType( number, 6, 10, true ) )
			{
				string = shared->getCharacters();
			}
			
			
			
			
			/// Create a string which represents the specified floating-point number in the given base system.
			/**
			  * This method allows the user to determine the number of decimal places to display,
			  * the base system, and whether or not the allow scientific notation.
			  */
			RIM_INLINE explicit BasicString( Float number, Size numDecimalPlaces, Size base = 10, Bool allowScientific = true )
				:	shared( fromFloatType( number, numDecimalPlaces, base, allowScientific ) )
			{
				string = shared->getCharacters();
			}
			
			
			
			
			/// Create a string which represents the specified double floating-point number with default formating.
			/**
			  * The number is displayed with the maximum precision for its type in base 10,
			  * and scientific notation is automatically used when necessary.
			  */
			RIM_INLINE explicit BasicString( Double number )
				:	shared( fromFloatType( number, 15, 10, true ) )
			{
				string = shared->getCharacters();
			}
			
			
			
			
			/// Create a string which represents the specified double floating-point number in the given base system.
			/**
			  * This method allows the user to determine the number of decimal places to display,
			  * the base system, and whether or not the allow scientific notation.
			  */
			RIM_INLINE explicit BasicString( Double number, Size numDecimalPlaces, Size base = 10, Bool allowScientific = true )
				:	shared( fromFloatType( number, numDecimalPlaces, base, allowScientific ) )
			{
				string = shared->getCharacters();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this string, releasing its internal character buffer if the reference count is 0.
			RIM_INLINE ~BasicString()
			{
				deallocateString( shared );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of another string to this string.
			/**
			  * The reference count of the other string is increased by one
			  * and it replaces the current string of this object, deallocating
			  * the previous string if its reference count reaches 0.
			  */
			RIM_INLINE BasicString& operator = ( const BasicString& other )
			{
				if ( shared != other.shared )
				{
					deallocateString( shared );
					
					shared = other.shared;
					shared->referenceCount++;
					string = shared->getCharacters();
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Equality Comparison Methods
			
			
			
			
			/// Return whether or not this string is exactly equal to another.
			RIM_INLINE Bool equals( const BasicString& other ) const
			{
				if ( shared->length == other.shared->length )
					return BasicString::equals( string, other.string );
				else
					return false;
			}
			
			
			
			
			/// Return whether or not this string is equal to another if letter case is ignored.
			RIM_INLINE Bool equalsIgnoreCase( const BasicString& other ) const
			{
				if ( shared->length == other.shared->length )
					return BasicString::equalsIgnoreCase( string, other.string );
				else
					return false;
			}
			
			
			
			
			/// Return whether or not this string is exactly equal to a NULL-terminated character string.
			RIM_INLINE Bool equals( const CharType* characters ) const
			{
				return BasicString::equals( string, characters );
			}
			
			
			
			
			/// Return whether or not this string is equal to a NULL-terminated character string if letter case is ignored.
			RIM_INLINE Bool equalsIgnoreCase( const CharType* characters ) const
			{
				return BasicString::equalsIgnoreCase( string, characters );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Equality Comparison Operators
			
			
			
			
			/// Return whether or not this string is exactly equal to another.
			RIM_INLINE Bool operator == ( const BasicString& other ) const
			{
				return BasicString::equals( string, other.string );
			}
			
			
			
			
			/// Return whether or not this string is not equal to another.
			RIM_INLINE Bool operator != ( const BasicString& other ) const
			{
				return !BasicString::equals( string, other.string );
			}
			
			
			
			
			/// Return whether or not this string is exactly equal to a NULL-terminated character string.
			RIM_INLINE Bool operator == ( const CharType* other ) const
			{
				return BasicString::equals( string, string );
			}
			
			
			
			
			/// Return whether or not this string is not equal to a NULL-terminated character string.
			RIM_INLINE Bool operator != ( const CharType* other ) const
			{
				return !BasicString::equals( string, string );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Sorting Comparison Methods
			
			
			
			
			/// Return an integer indicating the lexical order of this string when compared to another.
			/**
			  * If this string should come before the other, -1 is returned.
			  * If this string is equal to the other, 0 is returned.
			  * If this string should come after the other, 1 is returned.
			  */
			RIM_INLINE Int compareTo( const BasicString& other ) const
			{
				return BasicString::compare( string, other.string );
			}
			
			
			
			
			/// Return an integer indicating the lexical order of this string when compared to another, ignoring letter case.
			/**
			  * If this string should come before the other, -1 is returned.
			  * If this string is equal to the other, 0 is returned.
			  * If this string should come after the other, 1 is returned.
			  */
			RIM_INLINE Int compareToIgnoreCase( const BasicString& other ) const
			{
				return BasicString::compareIgnoreCase( string, other.string );
			}
			
			
			
			
			/// Return an integer indicating the lexical order of this string when compared to a C-string.
			/**
			  * If this string should come before the other, -1 is returned.
			  * If this string is equal to the other, 0 is returned.
			  * If this string should come after the other, 1 is returned.
			  */
			RIM_INLINE Int compareTo( const CharType* characters ) const
			{
				return BasicString::compare( string, characters );
			}
			
			
			
			
			/// Return an integer indicating the lexical order of this string when compared to a C-string, ignoring letter case.
			/**
			  * If this string should come before the other, -1 is returned.
			  * If this string is equal to the other, 0 is returned.
			  * If this string should come after the other, 1 is returned.
			  */
			RIM_INLINE Int compareToIgnoreCase( const CharType* characters ) const
			{
				return BasicString::compareIgnoreCase( string, characters );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Sorting Operators
			
			
			
			
			/// Return whether or not this string comes before another one in the lexical order.
			RIM_INLINE Bool operator < ( const BasicString& other ) const
			{
				return BasicString::compare( string, string.string ) == -1;
			}
			
			
			
			
			/// Return whether or not this string comes after another one in the lexical order.
			RIM_INLINE Bool operator > ( const BasicString& other ) const
			{
				return BasicString::compare( string, string.string ) == 1;
			}
			
			
			
			
			/// Return whether or not this string comes before or is the same as another one in the lexical order.
			RIM_INLINE Bool operator <= ( const BasicString& other ) const
			{
				return BasicString::compare( string, string.string ) <= 0;
			}
			
			
			
			
			/// Return whether or not this string comes after or is the same as another one in the lexical order.
			RIM_INLINE Bool operator >= ( const BasicString& other ) const
			{
				return BasicString::compare( string, string.string ) >= 0;
			}
			
			
			
			
			/// Return whether or not this string comes before a C-string in the lexical order.
			RIM_INLINE Bool operator < ( const CharType* characters ) const
			{
				return BasicString::compare( string, characters ) == -1;
			}
			
			
			
			
			/// Return whether or not this string comes after a C-string in the lexical order.
			RIM_INLINE Bool operator > ( const CharType* characters ) const
			{
				return BasicString::compare( string, characters ) == 1;
			}
			
			
			
			
			/// Return whether or not this string comes before or is the same as a C-string in the lexical order.
			RIM_INLINE Bool operator <= ( const CharType* characters ) const
			{
				return BasicString::compare( string, characters ) < 1;
			}
			
			
			
			
			/// Return whether or not this string comes after or is the same as a C-string in the lexical order.
			RIM_INLINE Bool operator >= ( const CharType* characters ) const
			{
				return BasicString::compare( string, characters ) > -1;
			}
			
			
			
			
			/// Return whether or not this string comes before another one in the lexical order, ignoring letter case.
			RIM_INLINE Bool operator << ( const BasicString& other ) const
			{
				return BasicString::compareIgnoreCase( string, string.string ) == -1;
			}
			
			
			
			
			/// Return whether or not this string comes after another one in the lexical order, ignoring letter case.
			RIM_INLINE Bool operator >> ( const BasicString& other ) const
			{
				return BasicString::compareIgnoreCase( string, string.string ) == 1;
			}
			
			
			
			
			/// Return whether or not this string comes before or is the same as another one in the lexical order, ignoring letter case.
			RIM_INLINE Bool operator <<= ( const BasicString& other ) const
			{
				return BasicString::compareIgnoreCase( string, string.string ) < 1;
			}
			
			
			
			
			/// Return whether or not this string comes after or is the same as another one in the lexical order, ignoring letter case.
			RIM_INLINE Bool operator >>= ( const BasicString& other ) const
			{
				return BasicString::compareIgnoreCase( string, string.string ) > -1;
			}
			
			
			
			
			/// Return whether or not this string comes before a C-string in the lexical order, ignoring letter case.
			RIM_INLINE Bool operator << ( const CharType* characters ) const
			{
				return BasicString::compareIgnoreCase( string, characters ) == -1;
			}
			
			
			
			
			/// Return whether or not this string comes before a C-string in the lexical order, ignoring letter case.
			RIM_INLINE Bool operator >> ( const CharType* characters ) const
			{
				return BasicString::compareIgnoreCase( string, characters ) == 1;
			}
			
			
			
			
			/// Return whether or not this string comes before or is the same as a C-string in the lexical order, ignoring letter case.
			RIM_INLINE Bool operator <<= ( const CharType* characters ) const
			{
				return BasicString::compareIgnoreCase( string, characters ) < 1;
			}
			
			
			
			
			/// Return whether or not this string comes after or is the same as a C-string in the lexical order, ignoring letter case.
			RIM_INLINE Bool operator >>= ( const CharType* characters ) const
			{
				return BasicString::compareIgnoreCase( string, characters ) > -1;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Concatenation Operators
			
			
			
			
			BasicString operator + ( const BasicString& other ) const;
			
			
			
			
			RIM_INLINE BasicString operator + ( const Char* characters ) const
			{
				return (*this) + BasicString(characters);
			}
			
			
			
			
			RIM_INLINE BasicString operator + ( Char character ) const
			{
				return (*this) + BasicString(character);
			}
			
			
			
			
			RIM_INLINE BasicString operator + ( Short value ) const
			{
				return (*this) + BasicString(value);
			}
			
			
			
			
			RIM_INLINE BasicString operator + ( UShort value ) const
			{
				return (*this) + BasicString(value);
			}
			
			
			
			
			RIM_INLINE BasicString operator + ( Int value ) const
			{
				return (*this) + BasicString(value);
			}
			
			
			
			
			RIM_INLINE BasicString operator + ( UInt value ) const
			{
				return (*this) + BasicString(value);
			}
			
			
			
			
			RIM_INLINE BasicString operator + ( Long value ) const
			{
				return (*this) + BasicString(value);
			}
			
			
			
			
			RIM_INLINE BasicString operator + ( ULong value ) const
			{
				return (*this) + BasicString(value);
			}
			
			
			
			
			RIM_INLINE BasicString operator + ( LongLong value ) const
			{
				return (*this) + BasicString(value);
			}
			
			
			
			
			RIM_INLINE BasicString operator + ( ULongLong value ) const
			{
				return (*this) + BasicString(value);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String to Number Conversion Operators
			
			
			
			
			/// Cast this string to an integer, returning math::nan<Int32>() if the conversion fails.
			RIM_INLINE operator Int () const
			{
				return (Long)*this;
			}
			
			
			
			
			/// Cast this string to an integer, returning math::nan<UInt32>() if the conversion fails.
			RIM_INLINE operator UInt () const
			{
				return (ULong)*this;
			}
			
			
			
			
			/// Cast this string to an integer, returning math::nan<Int32>() if the conversion fails.
			RIM_INLINE operator Long () const
			{
				Int32 value;
				if ( this->toInt32( value ) )
					return value;
				else
					return math::nan<Int32>();
			}
			
			
			
			
			/// Cast this string to an integer, returning math::nan<UInt32>() if the conversion fails.
			RIM_INLINE operator ULong () const
			{
				UInt32 value;
				if ( this->toUInt32( value ) )
					return value;
				else
					return math::nan<UInt32>();
			}
			
			
			
			
			/// Cast this string to an integer, returning math::nan<Int64>() if the conversion fails.
			RIM_INLINE operator LongLong () const
			{
				Int64 value;
				if ( this->toInt64( value ) )
					return value;
				else
					return math::nan<Int64>();
			}
			
			
			
			
			/// Cast this string to an integer, returning math::nan<UInt64>() if the conversion fails.
			RIM_INLINE operator ULongLong () const
			{
				UInt64 value;
				if ( this->toUInt64( value ) )
					return value;
				else
					return math::nan<UInt64>();
			}
			
			
			
			
			/// Cast this string to a floating-point number, returning math::nan<Float>() if the conversion fails.
			RIM_INLINE operator Float () const
			{
				Float value;
				if ( this->toFloat( value ) )
					return value;
				else
					return math::nan<Float>();
			}
			
			
			
			
			/// Cast this string to a double floating-point number, returning math::nan<Double>() if the conversion fails.
			RIM_INLINE operator Double () const
			{
				Double value;
				if ( this->toDouble( value ) )
					return value;
				else
					return math::nan<Double>();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String to Number Conversion Methods
			
			
			
			
			/// Convert this string to a boolean value, returning whether or not the conversion was successful.
			/**
			  * If the conversion is successful, the converted value is placed in the output parameter.
			  */
			Bool toBool( Bool& value ) const;
			
			
			
			
			/// Convert this string to a float value, returning whether or not the conversion was successful.
			/**
			  * If the conversion is successful, the converted value is placed in the output parameter.
			  */
			Bool toFloat( Float& value ) const;
			
			
			
			
			/// Convert this string to a double value, returning whether or not the conversion was successful.
			/**
			  * If the conversion is successful, the converted value is placed in the output parameter.
			  */
			Bool toDouble( Double& value ) const;
			
			
			
			
			/// Convert this string to an integer value, returning whether or not the conversion was successful.
			/**
			  * If the conversion is successful, the converted value is placed in the output parameter.
			  */
			RIM_INLINE Bool toInt( Int& value ) const
			{
				Double d;
				
				if ( this->toDouble( d ) )
				{
					value = safeTypeConversion<Int>( d );
					return true;
				}
				
				return false;
			}
			
			
			
			
			/// Convert this string to an unsigned integer value, returning TRUE if the conversion was successful.
			/**
			  * If the conversion is successful, the converted value is placed in the output parameter.
			  */
			Bool toUInt( UInt32& value ) const
			{
				Double d;
				
				if ( this->toDouble( d ) )
				{
					value = safeTypeConversion<UInt>( d );
					return true;
				}
				
				return false;
			}
			
			
			
			
			/// Convert this string to a 32-bit integer value, returning whether or not the conversion was successful.
			/**
			  * If the conversion is successful, the converted value is placed in the output parameter.
			  */
			RIM_INLINE Bool toInt32( Int32& value ) const
			{
				Double d;
				
				if ( this->toDouble( d ) )
				{
					value = safeTypeConversion<Int32>( d );
					return true;
				}
				
				return false;
			}
			
			
			
			
			/// Convert this string to a 32-bit unsigned integer value, returning TRUE if the conversion was successful.
			/**
			  * If the conversion is successful, the converted value is placed in the output parameter.
			  */
			RIM_INLINE Bool toUInt32( UInt32& value ) const
			{
				Double d;
				
				if ( this->toDouble( d ) )
				{
					value = safeTypeConversion<UInt32>( d );
					return true;
				}
				
				return false;
			}
			
			
			
			
			/// Convert this string to a 64-bit integer value, returning whether or not the conversion was successful.
			/**
			  * If the conversion is successful, the converted value is placed in the output parameter.
			  */
			RIM_INLINE Bool toInt64( Int64& value ) const
			{
				Double d;
				
				if ( this->toDouble( d ) )
				{
					value = safeTypeConversion<Int64>( d );
					return true;
				}
				
				return false;
			}
			
			
			
			
			/// Convert this string to a 64-bit unsigned integer value, returning TRUE if the conversion was successful.
			/**
			  * If the conversion is successful, the converted value is placed in the output parameter.
			  */
			RIM_INLINE Bool toUInt64( UInt64& value ) const
			{
				Double d;
				
				if ( this->toDouble( d ) )
				{
					value = safeTypeConversion<UInt64>( d );
					return true;
				}
				
				return false;
			}
			
			
			
			
			/// Convert this string to a templated number value, returning TRUE if the conversion was successful.
			/**
			  * If the conversion is successful, the converted value is placed in the output parameter.
			  * This method will not compile for non-primitive types.
			  */
			template < typename T >
			RIM_INLINE Bool toNumber( T& value ) const
			{
				Double d;
				
				if ( this->toDouble( d ) )
				{
					value = safeTypeConversion<T>( d );
					return true;
				}
				
				return false;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static String to Number Conversion Methods
			
			
			
			
			/// Convert a string specified by starting and ending pointers to a boolean value.
			/**
			  * The method returns whether or not the conversion was successful.
			  */
			static Bool convertToBool( const CharType* stringStart, const CharType* stringEnd,
										Bool& result )
			{
				if ( !stringStart || stringStart >= stringEnd )
					return false;
				
				return convertStringToBoolean( stringStart, stringEnd, result );
			}
			
			
			
			
			/// Convert a string specified by starting and ending pointers to an integer value.
			/**
			  * The method returns whether or not the conversion was successful.
			  */
			static Bool convertToInt( const CharType* stringStart, const CharType* stringEnd,
										Int& result )
			{
				if ( !stringStart || stringStart >= stringEnd )
					return false;
				
				Double d;
				
				if ( convertStringToNumber( stringStart, stringEnd, d ) )
				{
					result = safeTypeConversion<Int>( d );
					return true;
				}
				
				return false;
			}
			
			
			
			
			/// Convert a string specified by starting and ending pointers to an integer value.
			/**
			  * The method returns whether or not the conversion was successful.
			  */
			static Bool convertToInt32( const CharType* stringStart, const CharType* stringEnd,
										Int32& result )
			{
				if ( !stringStart || stringStart >= stringEnd )
					return false;
				
				Double d;
				
				if ( convertStringToNumber( stringStart, stringEnd, d ) )
				{
					result = safeTypeConversion<Int32>( d );
					return true;
				}
				
				return false;
			}
			
			
			
			
			/// Convert a string specified by starting and ending pointers to an integer value.
			/**
			  * The method returns whether or not the conversion was successful.
			  */
			static Bool convertToUInt32( const CharType* stringStart, const CharType* stringEnd,
										UInt32& result )
			{
				if ( !stringStart || stringStart >= stringEnd )
					return false;
				
				Double d;
				
				if ( convertStringToNumber( stringStart, stringEnd, d ) )
				{
					result = safeTypeConversion<UInt32>( d );
					return true;
				}
				
				return false;
			}
			
			
			
			
			/// Convert a string specified by starting and ending pointers to an integer value.
			/**
			  * The method returns whether or not the conversion was successful.
			  */
			static Bool convertToInt64( const CharType* stringStart, const CharType* stringEnd,
										Int64& result )
			{
				if ( !stringStart || stringStart >= stringEnd )
					return false;
				
				Double d;
				
				if ( convertStringToNumber( stringStart, stringEnd, d ) )
				{
					result = safeTypeConversion<Int64>( d );
					return true;
				}
				
				return false;
			}
			
			
			
			
			/// Convert a string specified by starting and ending pointers to an integer value.
			/**
			  * The method returns whether or not the conversion was successful.
			  */
			static Bool convertToUInt64( const CharType* stringStart, const CharType* stringEnd,
										UInt64& result )
			{
				if ( !stringStart || stringStart >= stringEnd )
					return false;
				
				Double d;
				
				if ( convertStringToNumber( stringStart, stringEnd, d ) )
				{
					result = safeTypeConversion<UInt64>( d );
					return true;
				}
				
				return false;
			}
			
			
			
			
			/// Convert a string specified by starting and ending pointers to a float value.
			/**
			  * The method returns whether or not the conversion was successful.
			  */
			static Bool convertToFloat( const CharType* stringStart, const CharType* stringEnd,
										Float& result )
			{
				if ( !stringStart || stringStart >= stringEnd )
					return false;
				
				return convertStringToNumber( stringStart, stringEnd, result );
			}
			
			
			
			
			/// Convert a string specified by starting and ending pointers to a float value.
			/**
			  * The method returns whether or not the conversion was successful.
			  */
			static Bool convertToDouble( const CharType* stringStart, const CharType* stringEnd,
										Double& result )
			{
				if ( !stringStart || stringStart >= stringEnd )
					return false;
				
				return convertStringToNumber( stringStart, stringEnd, result );
			}
			
			
			
			
			/// Convert a string specified by starting and ending pointers to a number value.
			/**
			  * The method returns whether or not the conversion was successful.
			  */
			template < typename T >
			static Bool convertToNumber( const CharType* stringStart, const CharType* stringEnd,
										T& result )
			{
				if ( !stringStart || stringStart >= stringEnd )
					return false;
				
				Double d;
				
				if ( convertStringToNumber( stringStart, stringEnd, d ) )
				{
					result = safeTypeConversion<T>( d );
					return true;
				}
				
				return false;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String to Number Conversion Test Methods
			
			
			
			
			/// Return whether or not this string represents a valid number.
			RIM_INLINE Bool isANumber() const
			{
				return isANumber( string, shared->length );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Character Accessor Methods
			
			
			
			
			/// Return the character at the specified index in this string.
			/**
			  * A debug assertion is raised if the index is invalid.
			  */
			RIM_INLINE CharType get( Index index ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( index < length - 1, "String index is out-of-bounds" );
				return string[index];
			}
			
			
			
			
			/// Return the character at the specified index in this string.
			/**
			  * A debug assertion is raised if the index is invalid.
			  */
			RIM_INLINE CharType operator [] ( Index index ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( index < length - 1, "String index is out-of-bounds" );
				return string[index];
			}
			
			
			
			
			/// Return the character at the specified index in this string.
			/**
			  * A debug assertion is raised if the index is invalid.
			  */
			RIM_INLINE CharType operator () ( Index index ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( index < length - 1, "String index is out-of-bounds" );
				return string[index];
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Substring Accessor Method
			
			
			
			
			/// Return a sub-string of this string, specified by the start index and number of code points (characters).
			RIM_INLINE BasicString getSubString( Index start, Size number ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( start < length - 1, "Substring start index is out of string bounds" );
				RIM_DEBUG_ASSERT_MESSAGE( start + number < length, "Substring end index is out of string bounds" );
				
				return BasicString( string + start, number );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Character Array Accessor Method
			
			
			
			
			/// Return a pointer to a NULL-terminated character array representing this string.
			RIM_INLINE const CharType* getCString() const
			{
				return string;
			}
			
			
			
			
			/// Return a pointer to a NULL-terminated character array representing this string.
			RIM_INLINE const CharType* getPointer() const
			{
				return string;
			}
			
			
			
			
			/// Return a pointer to a NULL-terminated character array representing this string.
			RIM_INLINE operator const CharType* () const
			{
				return string;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Length Accessor Methods
			
			
			
			
			/// Return the number of character code points that are part of this string, not including the NULL terminator.
			RIM_FORCE_INLINE Size getLength() const
			{
				return shared->length - 1;
			}
			
			
			
			
			/// Return the actual length of this string in characters.
			/**
			  * This method parses the multi-byte encoded string and determines
			  * the actual number of characters that it contains (which will be less
			  * than or equal to the number of code points).
			  */
			Size getLengthInCharacters() const;
			
			
			
			
			/// Return the number of code points that are part of the specified NULL-terminated string.
			/**
			  * The value returned does not include the NULL termination character.
			  */
			static Size getLength( const CharType* characters );
			
			
			
			
			/// Return the number of characters that are part of the specified NULL-terminated string.
			/**
			  * This method parses the multi-byte encoded string and determines
			  * the actual number of characters that it contains (which will be less
			  * than or equal to the number of code points).
			  */
			static Size getLengthInCharacters( const CharType* characters );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Hash Code Accessor Method
			
			
			
			
			/// Return a hash code for this string.
			RIM_INLINE Hash getHashCode() const
			{
				Hash& hash = shared->hashCode;
				
				if ( hash != 0 )
					return hash;
				else
				{
					hash = HashCode( string, shared->length );
					return hash;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Character Trait Accessor Methods
			
			
			
			
			/// Convert this string to lower case.
			BasicString toLowerCase() const;
			
			
			
			
			/// Convert this string to lower case.
			BasicString toUpperCase() const;
			
			
			
			
			// If the specified character is an upper-case character, convert it a lower-case one.
			RIM_INLINE static CharType toLowerCase( CharType character )
			{
				if ( character >= 'A' && character <= 'Z' )
					return character + 32;
				else
					return character;
			}
			
			
			
			
			// If the specified character is a lower-case character, convert it an upper-case one.
			RIM_INLINE static CharType toUpperCase( CharType character )
			{
				if ( character >= 'a' && character <= 'z' )
					return character - 32;
				else
					return character;
			}
			
			
			
			
			/// Return whether or not the specified character is a letter character.
			RIM_INLINE static Bool isALetter( CharType character )
			{
				return	(character >= 'A' && character <= 'Z') || 
						(character >= 'a' && character <= 'z');
			}
			
			
			
			
			/// Return whether or not the specified character is an upper-case character.
			RIM_INLINE static Bool isUpperCase( CharType character )
			{
				return	character >= 'A' && character <= 'Z';
			}
			
			
			
			
			/// Return whether or not the specified character is a lower-case character.
			RIM_INLINE static Bool isLowerCase( CharType character )
			{
				return	character >= 'a' && character <= 'z';
			}
			
			
			
			
			/// Return whether or not the specified character is a decimal digit (0 to 9).
			RIM_INLINE static Bool isADigit( CharType character )
			{
				return character >= '0' && character <= '9';
			}
			
			
			
			
			/// Return whether or not the specified character is an octal digit (0 to 7).
			RIM_INLINE static Bool isAnOctalDigit( CharType character )
			{
				return character >= '0' && character <= '7';
			}
			
			
			
			
			/// Return whether or not the specified character is an binary digit (0 or 1).
			RIM_INLINE static Bool isABinaryDigit( CharType character )
			{
				return character == '0' || character == '1';
			}
			
			
			
			
			/// Return whether or not the specified character is a hexidecimal digit (0 to 9, A to F).
			RIM_INLINE static Bool isAHexDigit( CharType character )
			{
				return	(character >= '0' && character <= '9') ||
						(character >= 'A' && character <= 'F') ||
						(character >= 'a' && character <= 'f');
			}
			
			
			
			
			/// Return whether or not the specified character is a whitespace character (i.e. space, tab, new line, etc).
			RIM_INLINE static Bool isWhitespace( CharType character )
			{
				return character == ' ' || character == '\t' || character == '\n' || character == '\r';
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations
			
			
			
			
			class SharedString
			{
				public:
					
					/// Create a new shared string which uses the specified pointer to a character buffer.
					RIM_INLINE SharedString( Size newLength )
						:	length( newLength ),
							referenceCount( 1 ),
							hashCode( 0 )
					{
					}
					
					
					/// Return a pointer to the characters that are part of this shared string object.
					/**
					  * The characters are allocated contiguously after the end of the object.
					  */
					RIM_INLINE CharType* getCharacters()
					{
						return (CharType*)((UByte*)this + sizeof(SharedString));
					}
					
					
					/// The length in characters (including the NULL terminator) of this string.
					Size length;
					
					/// The number of strings that reference this shared string.
					/**
					  * When this number reaches 0, the string is deallocated.
					  */
					Size referenceCount;
					
					/// A hash code for this string, lazily computed when it is first needed.
					/**
					  * A value of 0 indicates that the hash code has not been computed.
					  */
					Hash hashCode;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructor
			
			
			
			
			/// Create a new string with the specified shared string.
			RIM_INLINE BasicString( SharedString* sharedString )
				:	shared( sharedString )
			{
				string = shared->getCharacters();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Allocation Methods
			
			
			
			
			static SharedString* allocateString( Size length )
			{
				Size sharedStringSize = sizeof(SharedString) + sizeof(CharType)*length;
				UByte* sharedStringBytes = util::allocate<UByte>( sharedStringSize );
				
				new ( sharedStringBytes ) SharedString( length );
				
				return (SharedString*)sharedStringBytes;
			}
			
			
			
			
			static void deallocateString( SharedString* sharedString )
			{
				if ( --sharedString->referenceCount == Size(0) )
					util::deallocate( (UByte*)sharedString );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Unicode Conversion Methods
			
			
			
			
			template < typename CharType2 >
			RIM_INLINE static SharedString* convertUnicode( const CharType2* unicodeString );
			
			
			
			
			template < typename CharType2 >
			RIM_INLINE static SharedString* convertUnicode( const CharType2* unicodeString, const CharType2* unicodeStringEnd );
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static String Concatenation Methods
			
			
			
			
			RIM_INLINE static SharedString* concatenateStrings( const CharType* string1, Size length1,
																const CharType* string2, Size length2 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static String Comparison Methods
			
			
			
			
			static Bool equals( const CharType* string1, const CharType* string2 );
			static Bool equalsIgnoreCase( const CharType* string1, const CharType* string2 );
			
			
			static Int compare( const CharType* string1, const CharType* string2 );
			static Int compareIgnoreCase( const CharType* string1, const CharType* string2 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static String-Number Conversion Methods
			
			
			
			
			static SharedString* fromIntegerType( Int32 value, Size base );
			static SharedString* fromIntegerType( UInt32 value, Size base );
			static SharedString* fromIntegerType( Int64 value, Size base );
			static SharedString* fromIntegerType( UInt64 value, Size base );
			
			
			
			
			template < typename ValueType >
			RIM_INLINE static SharedString* fromSignedIntegerType( ValueType value, Size base );
			
			
			
			template < typename ValueType >
			RIM_INLINE static SharedString* fromUnsignedIntegerType( ValueType value, Size base );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static String-Number Conversion Methods
			
			
			
			
			static SharedString* fromFloatType( Float value, Size numDecimalPlaces, Size base,
												Bool allowScientific );
			static SharedString* fromFloatType( Double value, Size numDecimalPlaces, Size base,
												Bool allowScientific );
			
			
			
			template < typename ValueType >
			RIM_INLINE static SharedString* fromFloatingPointType( ValueType value, Size numDecimalDigits,
																Size precision, Size base, Bool allowScientific );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static String-Number Conversion Methods
			
			
			
			
			template < typename ValueType >
			RIM_NO_INLINE static Bool parseSimpleNumber( const CharType* numberStart, const CharType* numberEnd,
														Size base, ValueType& number );
			
			
			
			template < typename ValueType >
			RIM_NO_INLINE static Bool convertStringToNumber( const CharType* stringStart, const CharType* stringEnd,
															ValueType& result );
			
			
			
			
			RIM_NO_INLINE static Bool convertStringToBoolean( const CharType* stringStart, const CharType* stringEnd,
															Bool& result );
			
			
			
			
			static Bool isANumber( const CharType* string, Size length );
			
			
			
			
			template < typename ValueType, typename FloatType >
			RIM_FORCE_INLINE static ValueType safeTypeConversion( FloatType value )
			{
				if ( value < (FloatType)math::min<ValueType>() )
					return math::min<ValueType>();
				else if ( value > (FloatType)math::max<ValueType>() )
					return math::max<ValueType>();
				else
					return (ValueType)value;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	New Literal String Methods
			
			
			
			
			/// Create and return a new reference counted string which represents a null string.
			static SharedString* newNullString()
			{
				SharedString* string = allocateString( 1 );
				CharType* characters = string->getCharacters();
				*characters = '\0';
				
				return string;
			}
			
			
			
			
			/// Create and return a new reference counted string which represents the 'true' boolean literal.
			static SharedString* newTrueString()
			{
				SharedString* string = allocateString( 5 );
				CharType* characters = string->getCharacters();
				characters[0] = 't';
				characters[1] = 'r';
				characters[2] = 'u';
				characters[3] = 'e';
				characters[4] = '\0';
				
				return string;
			}
			
			
			
			
			/// Create and return a new reference counted string which represents the 'false' boolean literal.
			static SharedString* newFalseString()
			{
				SharedString* string = allocateString( 6 );
				CharType* characters = string->getCharacters();
				characters[0] = 'f';
				characters[1] = 'a';
				characters[2] = 'l';
				characters[3] = 's';
				characters[4] = 'e';
				characters[5] = '\0';
				
				return string;
			}
			
			
			
			
			/// Create and return a new reference counted string which represents the +infinity literal.
			static SharedString* newPositiveInfinityString()
			{
				SharedString* string = allocateString( 9 );
				CharType* characters = string->getCharacters();
				characters[0] = 'I';
				characters[1] = 'n';
				characters[2] = 'f';
				characters[3] = 'i';
				characters[4] = 'n';
				characters[5] = 'i';
				characters[6] = 't';
				characters[7] = 'y';
				characters[8] = '\0';
				
				return string;
			}
			
			
			
			
			/// Create and return a new reference counted string which represents the -infinity literal.
			static SharedString* newNegativeInfinityString()
			{
				SharedString* string = allocateString( 10 );
				CharType* characters = string->getCharacters();
				characters[0] = '-';
				characters[1] = 'I';
				characters[2] = 'n';
				characters[3] = 'f';
				characters[4] = 'i';
				characters[5] = 'n';
				characters[6] = 'i';
				characters[7] = 't';
				characters[8] = 'y';
				characters[9] = '\0';
				
				return string;
			}
			
			
			
			
			/// Create and return a new reference counted string which represents the not-a-number literal.
			static SharedString* newNaNString()
			{
				SharedString* string = allocateString( 4 );
				CharType* characters = string->getCharacters();
				characters[0] = 'N';
				characters[1] = 'a';
				characters[2] = 'N';
				characters[3] = '\0';
				
				return string;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the character buffer for this string.
			CharType* string;
			
			
			
			
			/// A pointer to the shared string object which stores this string's reference-counted characters.
			SharedString* shared;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// A static shared string which represents the null string (that has 0 characters, with a null terminator).
			static SharedString* nullString;
			
			
			
			
			/// A static shared string which represents the boolean 'true' literal string.
			static SharedString* trueString;
			
			
			
			
			/// A static shared string which represents the boolean 'false' literal string.
			static SharedString* falseString;
			
			
			
			
			/// A static shared string which represents the +infinity literal string.
			static SharedString* positiveInfinityString;
			
			
			
			
			/// A static shared string which represents the -infinity literal string.
			static SharedString* negativeInfinityString;
			
			
			
			
			/// A static shared string which represents the not-a-number literal string.
			static SharedString* nanString;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Class Declarations
			
			
			
			
			template < typename OtherCharType >
			friend class BasicString;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Commutative Comparison Operators
//############		
//##########################################################################################
//##########################################################################################




template < typename CharType >
RIM_INLINE BasicString<CharType> operator == ( const CharType* characters, const BasicString<CharType>& string )
{
	return BasicString<CharType>::equals( characters, string );
}




template < typename CharType >
RIM_INLINE BasicString<CharType> operator != ( const CharType* characters, const BasicString<CharType>& string )
{
	return !BasicString<CharType>::equals( characters, string );
}




template < typename CharType >
RIM_INLINE BasicString<CharType> operator < ( const CharType* characters, const BasicString<CharType>& string )
{
	return BasicString<CharType>::compare( characters, string ) == -1;
}




template < typename CharType >
RIM_INLINE BasicString<CharType> operator > ( const CharType* characters, const BasicString<CharType>& string )
{
	return BasicString<CharType>::compare( characters, string ) == 1;
}




template < typename CharType >
RIM_INLINE BasicString<CharType> operator <= ( const CharType* characters, const BasicString<CharType>& string )
{
	return BasicString<CharType>::compare( characters, string ) < 1;
}




template < typename CharType >
RIM_INLINE BasicString<CharType> operator >= ( const CharType* characters, const BasicString<CharType>& string )
{
	return BasicString<CharType>::compare( characters, string ) > -1;
}




template < typename CharType >
RIM_INLINE BasicString<CharType> operator << ( const CharType* characters, const BasicString<CharType>& string )
{
	return BasicString<CharType>::compareIgnoreCase( characters, string ) == -1;
}




template < typename CharType >
RIM_INLINE BasicString<CharType> operator >> ( const CharType* characters, const BasicString<CharType>& string )
{
	return BasicString<CharType>::compareIgnoreCase( characters, string ) == 1;
}




template < typename CharType >
RIM_INLINE BasicString<CharType> operator <<= ( const CharType* characters, const BasicString<CharType>& string )
{
	return BasicString<CharType>::compareIgnoreCase( characters, string ) < 1;
}




template < typename CharType >
RIM_INLINE BasicString<CharType> operator >>= ( const CharType* characters, const BasicString<CharType>& string )
{
	return BasicString<CharType>::compareIgnoreCase( characters, string ) > -1;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Commutative Concatenation Operators
//############		
//##########################################################################################
//##########################################################################################




template < typename CharType >
RIM_INLINE BasicString<CharType> operator + ( const Char* characters, const BasicString<CharType>& string )
{
	return BasicString<CharType>( characters ) + string;
}




template < typename CharType >
RIM_INLINE BasicString<CharType> operator + ( Char character, const BasicString<CharType>& string )
{
	return BasicString<CharType>( character ) + string;
}




template < typename CharType >
RIM_INLINE BasicString<CharType> operator + ( Short value, const BasicString<CharType>& string )
{
	return BasicString<CharType>(value) + string;
}




template < typename CharType >
RIM_INLINE BasicString<CharType> operator + ( UShort value, const BasicString<CharType>& string )
{
	return BasicString<CharType>(value) + string;
}




template < typename CharType >
RIM_INLINE BasicString<CharType> operator + ( Int value, const BasicString<CharType>& string )
{
	return BasicString<CharType>(value) + string;
}




template < typename CharType >
RIM_INLINE BasicString<CharType> operator + ( UInt value, const BasicString<CharType>& string )
{
	return BasicString<CharType>(value) + string;
}




template < typename CharType >
RIM_INLINE BasicString<CharType> operator + ( Long value, const BasicString<CharType>& string )
{
	return BasicString<CharType>(value) + string;
}




template < typename CharType >
RIM_INLINE BasicString<CharType> operator + ( ULong value, const BasicString<CharType>& string )
{
	return BasicString<CharType>(value) + string;
}




template < typename CharType >
RIM_INLINE BasicString<CharType> operator + ( LongLong value, const BasicString<CharType>& string )
{
	return BasicString<CharType>(value) + string;
}





template < typename CharType >
RIM_INLINE BasicString<CharType> operator + ( ULongLong value, const BasicString<CharType>& string )
{
	return BasicString<CharType>(value) + string;
}




//##########################################################################################
//##########################################################################################
//############		
//############		String Type Definitions
//############		
//##########################################################################################
//##########################################################################################




/// A class which represents a standard NULL-terminated ASCII-encoded string of characters.
typedef BasicString<Char> String;




/// A class which represents a NULL-terminated UTF8-encoded string of characters.
typedef BasicString<UTF8Char> UTF8String;




/// A class which represents a NULL-terminated UTF16-encoded string of characters.
typedef BasicString<UTF16Char> UTF16String;




/// A class which represents a NULL-terminated UTF32-encoded string of characters.
typedef BasicString<UTF32Char> UTF32String;




//##########################################################################################
//*******************************   End Data Namespace   ***********************************
RIM_DATA_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_BASIC_STRING_H
