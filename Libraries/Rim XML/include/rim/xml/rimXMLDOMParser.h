/*
 *  rimXMLDOMParser.h
 *  Rim XML
 *
 *  Created by Carl Schissler on 9/18/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_XML_DOM_PARSER_H
#define INCLUDE_RIM_XML_DOM_PARSER_H


#include "rimXMLConfig.h"


#include "rimXMLDocument.h"


//##########################################################################################
//******************************  Start Rim XML Namespace  *********************************
RIM_XML_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which loads an entire XML document into memory and returns a tree of XML nodes.
/**
  * This XML parser is suitable for small-scale XML file parsing or where access
  * to the entire document is necessary by the end user. However, the document
  * returned by this parser may require large amounts of memory if the XML
  * file is large, since each element in the file must have an associated
  * XMLNode object. If an XML file may be large (i.e. > 100MB), consider
  * using the XMLSAXParser which is more memory efficient.
  */
class XMLDOMParser
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Document Input Methods
			
			
			
			
			/// Parse an XML file located at the specified path location in the local file system.
			/**
			  * If the parsing succeeds, the method returns a pointer to an object
			  * representing the XML document. Otherwise, if the parsing fails, a NULL
			  * pointer is returned.
			  */
			Pointer<XMLDocument> readFile( const UTF8String& pathToFile ) const;
			
			
			
			
			/// Parse a memory-resident XML document string.
			/**
			  * If the parsing succeeds, the method returns a pointer to an object
			  * representing the XML document. Otherwise, if the parsing fails, a NULL
			  * pointer is returned.
			  */
			Pointer<XMLDocument> readString( const UTF8String& documentString ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Document Output Methods
			
			
			
			
			/// Write the specified XML document to a file at the specified path in the local file system.
			/**
			  * The method returns whether or not the operation was successful.
			  */
			Bool writeFile( const Pointer<XMLDocument>& document, const UTF8String& pathToFile ) const;
			
			
			
			
			/// Convert the specified XML document to a string, returned in the output parameter.
			/**
			  * The method returns whether or not the operation was successful.
			  */
			Bool writeString( const Pointer<XMLDocument>& document, UTF8String& string ) const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	XML Input Helper Methods
			
			
			
			
			Pointer<XMLDocument> parseUTF8Document( const UTF8String& documentString ) const;
			
			
			
			
			Bool parseElement( UTF8StringIterator& iterator, Pointer<XMLNode>& node ) const;
			
			
			
			
			Bool parseAttribute( UTF8StringIterator& iterator, UTF8String& name, UTF8String& value ) const;
			
			
			
			
			Bool parseIdentifier( UTF8StringIterator& iterator, UTF8String& identifier ) const;
			
			
			
			
			static Bool skipWhitespace( UTF8StringIterator& iterator );
			
			
			
			
			/// Return whether or not the specified character is a whitespace character.
			RIM_INLINE static Bool isWhitespace( UTF32Char c )
			{
				return c == ' ' || c == '\t' || c == '\n' || c == '\r';
			}
			
			
			
			
			/// Return whether or not the specified character is a whitespace character.
			RIM_INLINE static Bool isWordCharacter( UTF32Char c )
			{
				return UTF32String::isALetter(c) || UTF32String::isADigit(c) || c == '_';
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	XML Output Helper Methods
			
			
			
			
			Bool writeDocument( const Pointer<XMLDocument>& document ) const;
			
			
			
			
			Bool writeNode( const Pointer<XMLNode>& node ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A string buffer used to accumulate a series of input characters.
			mutable UTF32StringBuffer buffer;
			
			
			
			
			/// A string buffer used to accumulate a series of output characters.
			mutable UTF8StringBuffer outputBuffer;
			
			
			
};




//##########################################################################################
//******************************  End Rim XML Namespace  ***********************************
RIM_XML_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_XML_DOM_PARSER_H
