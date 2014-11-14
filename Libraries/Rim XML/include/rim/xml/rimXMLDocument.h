/*
 *  rimXMLDocument.h
 *  Rim XML
 *
 *  Created by Carl Schissler on 4/28/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_XML_DOCUMENT_H
#define INCLUDE_RIM_XML_DOCUMENT_H


#include "rimXMLConfig.h"


#include "rimXMLNode.h"


//##########################################################################################
//******************************  Start Rim XML Namespace  *********************************
RIM_XML_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




class XMLDocument
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new XML document which uses the specified node as its root node.
			XMLDocument( const Pointer<XMLNode>& newRoot );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Root Node Accessor Methods
			
			
			
			
			/// Return a pointer to the root node for this document.
			RIM_INLINE const Pointer<XMLNode>& getRoot() const
			{
				return root;
			}
			
			
			
			
			/// Set the root node for this XML document.
			/**
			  * This method completely replaces the current contents of the document with
			  * the XML node hierarchy specified by the given root node.
			  */
			RIM_INLINE void setRoot( const Pointer<XMLNode>& newRoot )
			{
				root = newRoot;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Conversion Method
			
			
			
			
			/// Convert this XML document to a valid XML document string.
			UTF8String toString() const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the root node of the XML document.
			Pointer<XMLNode> root;
			
			
			
};




//##########################################################################################
//******************************  End Rim XML Namespace  ***********************************
RIM_XML_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_XML_DOCUMENT_H
