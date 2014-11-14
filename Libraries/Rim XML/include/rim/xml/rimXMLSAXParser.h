/*
 *  rimXMLSAXParser.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 1/21/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_XML_SAX_PARSER_H
#define INCLUDE_RIM_XML_SAX_PARSER_H


#include "rimXMLConfig.h"


#include "rimXMLNode.h"


//##########################################################################################
//******************************  Start Rim XML Namespace  *********************************
RIM_XML_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which sequentially parses an XML file as a series of document events.
/**
  * This XML parser allows the user to parse large XML files without being
  * required to store the entire documents in memory as with an XMLDOMParser.
  * It uses an event-based interface that uses callback functions to notify
  * the user that document elements have been parsed.
  */
class XMLSAXParser
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Class Declaration
			
			
			
			
			/// A class which contains callback functions that are used to recieve XML data by the user.
			/**
			  * The callback functions may be NULL if the user does not need
			  * access to a specific kind of document data (such as comments or parse errors).
			  */
			class Delegate
			{
				public:
					
					/// Create a new XML parser delegate object.
					RIM_INLINE Delegate()
						:	userData( NULL )
					{
					}
					
					
					/// The delegate callback function for when the start of an XML element is parsed.
					/**
					  * The parser provides the tag string and a list of the attributes
					  * for the element that is starting.
					  */
					Function<void ( const Delegate&,
									const UTF8String&, const ArrayList<XMLAttribute>& )> startElement;
					
					
					/// The delegate callback function for when the end of an XML element is parsed.
					/**
					  * The parser provides the tag string for the element that is ending.
					  */
					Function<void ( const Delegate&, const UTF8String& )> endElement;
					
					
					/// The delegate callback function for when text data between elements is parsed.
					/**
					  * The parser provides a string that contains the text between the
					  * last element and the next.
					  */
					Function<void ( const Delegate&, const UTF8String& )> text;
					
					
					/// The delegate callback function for when a comment is parsed.
					/**
					  * The parser provides the tag string for the element that is ending.
					  */
					Function<void ( const Delegate&, const UTF8String& )> comment;
					
					
					/// The delegate callback function for when a parse error occurs.
					/**
					  * The parser provides a string which describes the error that occurred.
					  */
					Function<void ( const Delegate&, const UTF8String& )> error;
					
					
					/// A pointer to data that can store user-specific information for the delegate.
					void* userData;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new XML parser with the default initial state.
			XMLSAXParser();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Document Input Methods
			
			
			
			
			/// Parse an XML file located at the specified path location in the local file system.
			/**
			  * The parser parses the specified file and sends the file data to the
			  * delegate object's callback functions if they are set.
			  *
			  * If the parsing succeeds, the method returns TRUE. Otherwise, the method returns
			  * FALSE.
			  */
			Bool readFile( const UTF8String& pathToFile, const Delegate& delegate ) const;
			
			
			
			
			/// Parse a memory-resident XML document string.
			/**
			  * The parser parses the specified file and sends the file data to the
			  * delegate object's callback functions if they are set.
			  *
			  * If the parsing succeeds, the method returns TRUE. Otherwise, the method returns
			  * FALSE.
			  */
			Bool readString( const UTF8String& documentString, const Delegate& delegate ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Document Output Methods
			
			
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	XML Input Helper Methods
			
			
			
			
			Bool parseUTF8Document( const UTF8String& documentString, const Delegate& delegate ) const;
			
			
			
			
			Bool parseElement( UTF8StringIterator& iterator, const Delegate& delegate ) const;
			
			
			
			
			Bool parseAttribute( UTF8StringIterator& iterator, UTF8String& name, UTF8String& value ) const;
			
			
			
			
			Bool parseIdentifier( UTF8StringIterator& iterator, UTF8String& identifier ) const;
			
			
			
			
			static Bool parseCharacterEntity( UTF8StringIterator& iterator, UTF32Char& character );
			
			
			
			
			static Bool skipWhitespace( UTF8StringIterator& iterator );
			
			
			
			
			/// Return whether or not the specified character is a word character (letter, number, or underscore).
			RIM_INLINE static Bool isWordCharacter( UTF32Char c )
			{
				return UTF32String::isALetter(c) || UTF32String::isADigit(c) || c == '_';
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A string buffer used to accumulate a series of input characters.
			mutable UTF32StringBuffer buffer;
			
			
			
			
			/// A string buffer used to accumulate a series of output characters.
			mutable UTF8StringBuffer outputBuffer;
			
			
			
			
			/// A stack of the previously parsed element nodes that have not yet been ended.
			mutable ArrayList<UTF8String> elementStack;
			
			
			
			
			/// A list of temporary attributes for the current element that is being parsed.
			mutable ArrayList<XMLAttribute> attributes;
			
			
			
};




//##########################################################################################
//******************************  End Rim XML Namespace  ***********************************
RIM_XML_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_XML_SAX_PARSER_H
