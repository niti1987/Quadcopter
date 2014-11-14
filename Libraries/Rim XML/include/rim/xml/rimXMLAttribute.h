/*
 *  rimXMLAttribute.h
 *  Rim XML
 *
 *  Created by Carl Schissler on 9/23/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_XML_ATTRIBUTE_H
#define INCLUDE_RIM_XML_ATTRIBUTE_H


#include "rimXMLConfig.h"


//##########################################################################################
//******************************  Start Rim XML Namespace  *********************************
RIM_XML_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a name-value pair of data for an XML element.
class XMLAttribute
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new XML node attribute with the specified name and value strings.
			RIM_INLINE XMLAttribute( const UTF8String& newName, const UTF8String& newValue )
				:	name( newName ),
					value( newValue )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Value Accessor Methods
			
			
			
			
			/// Return a string representing the name of this XML node attribute.
			RIM_INLINE const UTF8String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set a string representing the name of this XML node attribute.
			RIM_INLINE void setName( const UTF8String& newName )
			{
				name = newName;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Value Accessor Methods
			
			
			
			
			/// Return a string representing the value of this XML node attribute.
			RIM_INLINE const UTF8String& getValue() const
			{
				return value;
			}
			
			
			
			
			/// Set a string representing the value of this XML node attribute.
			RIM_INLINE void setValue( const UTF8String& newValue )
			{
				value = newValue;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A string representing the name of this XML node attribute.
			UTF8String name;
			
			
			
			
			/// A string representing the value of this XML node attribute.
			UTF8String value;
			
			
			
};




//##########################################################################################
//******************************  End Rim XML Namespace  ***********************************
RIM_XML_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_XML_ATTRIBUTE_H
