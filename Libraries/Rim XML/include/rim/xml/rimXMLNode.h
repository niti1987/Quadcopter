/*
 *  rimXMLNode.h
 *  Rim XML
 *
 *  Created by Carl Schissler on 9/18/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_XML_NODE_H
#define INCLUDE_RIM_XML_NODE_H


#include "rimXMLConfig.h"


#include "rimXMLAttribute.h"


//##########################################################################################
//******************************  Start Rim XML Namespace  *********************************
RIM_XML_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which stores a hierarchical representation of an XML node.
/**
  * Each XML node has an associated value which has a meaning that depends on
  * the type of the node. A node with type XMLNode::ELEMENT can have a
  * list of attribute name-value pairs for that element, and can have
  * a list of child nodes.
  */
class XMLNode
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Node Type Enum Declaration
			
			
			
			
			typedef enum Type
			{
				/// A node type where the node represents the root node of a document.
				ROOT,
				
				/// A node type where the node represents a normal XML element.
				ELEMENT,
				
				/// A node type where the node corresponds to text data contained within another element.
				TEXT,
				
				/// A node type where the node represents an XML comment.
				COMMENT
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new XML node with no children, no attributes, and the specified node type.
			XMLNode( Type newType );
			
			
			
			
			/// Create a new XML node with no children, no attributes, and the specified type and value string.
			XMLNode( Type newType, const UTF8String& newValue );
			
			
			
			
			XMLNode( const XMLNode& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this XML node and release all resources that it contains.
			virtual ~XMLNode();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Node Type Accessor Methods
			
			
			
			
			/// Return an enum value representing the type of this node.
			RIM_INLINE Type getType() const
			{
				return type;
			}
			
			
			
			
			/// Set an enum value representing the type of this node.
			RIM_INLINE void setType( Type newType )
			{
				type = newType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Node Value Accessor Methods
			
			
			
			
			/// Return a string representing the value for this node.
			/**
			  * The purpose of this string depends on the node type:
			  * - ROOT: this value is unused.
			  * - ELEMENT: this value represents the element's tag.
			  * - TEXT: this value represents the node's text string.
			  * - COMMENT: this value represents the comment string.
			  */
			RIM_INLINE const UTF8String& getValue() const
			{
				return value;
			}
			
			
			
			
			/// Set a string representing the value for this node.
			/**
			  * The purpose of this string depends on the node type:
			  * - ROOT: this value is unused.
			  * - ELEMENT: this value represents the element's tag.
			  * - TEXT: this value represents the node's text string.
			  * - COMMENT: this value represents the comment string.
			  */
			RIM_INLINE void setValue( const UTF8String& newValue )
			{
				value = newValue;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Node Attribute Accessor Methods
			
			
			
			
			/// Return the total number of attributes that this XML node has.
			RIM_INLINE Size getAttributeCount() const
			{
				return attributes.getSize();
			}
			
			
			
			
			/// Return a reference to the XML attribute at the specified index in this node.
			RIM_INLINE XMLAttribute& getAttribute( Index index )
			{
				return attributes[index];
			}
			
			
			
			
			/// Return a const reference to the XML attribute at the specified index in this node.
			RIM_INLINE const XMLAttribute& getAttribute( Index index ) const
			{
				return attributes[index];
			}
			
			
			
			
			/// Return a pointer to the XML attribute with the specified name in this node.
			/**
			  * The method returns NULL if there is no attribute with that name in this node.
			  */
			XMLAttribute* getAttribute( const UTF8String& name );
			
			
			
			
			/// Return a const pointer to the XML attribute with the specified name in this node.
			/**
			  * The method returns NULL if there is no attribute with that name in this node.
			  */
			const XMLAttribute* getAttribute( const UTF8String& name ) const;
			
			
			
			
			/// Get the value of the specified attribute in the output parameter.
			/**
			  * The method returns whether or not there was an attribute with that name.
			  * If there is no attribute with that name, the value reference is not changed.
			  */
			Bool getAttribute( const UTF8String& name, UTF8String& value ) const;
			
			
			
			
			/// Get an boolean value for the specified attribute in the output parameter.
			/**
			  * The method returns whether or not the attribute was able to be accessed and
			  * then successfully converted to the output value parameter's type.
			  * If the method fails, the value reference is not changed.
			  */
			Bool getAttribute( const UTF8String& name, Bool& value ) const;
			
			
			
			
			/// Get a 32-bit integer value for the specified attribute in the output parameter.
			/**
			  * The method returns whether or not the attribute was able to be accessed and
			  * then successfully converted to the output value parameter's type.
			  * If the method fails, the value reference is not changed.
			  */
			Bool getAttribute( const UTF8String& name, Int32& value ) const;
			
			
			
			
			/// Get an unsigned 32-bit integer value for the specified attribute in the output parameter.
			/**
			  * The method returns whether or not the attribute was able to be accessed and
			  * then successfully converted to the output value parameter's type.
			  * If the method fails, the value reference is not changed.
			  */
			Bool getAttribute( const UTF8String& name, UInt32& value ) const;
			
			
			
			
			/// Get a 64-bit integer value for the specified attribute in the output parameter.
			/**
			  * The method returns whether or not the attribute was able to be accessed and
			  * then successfully converted to the output value parameter's type.
			  * If the method fails, the value reference is not changed.
			  */
			Bool getAttribute( const UTF8String& name, Int64& value ) const;
			
			
			
			
			/// Get an unsigned 64-bit integer value for the specified attribute in the output parameter.
			/**
			  * The method returns whether or not the attribute was able to be accessed and
			  * then successfully converted to the output value parameter's type.
			  * If the method fails, the value reference is not changed.
			  */
			Bool getAttribute( const UTF8String& name, UInt64& value ) const;
			
			
			
			
			/// Get a float value for the specified attribute in the output parameter.
			/**
			  * The method returns whether or not the attribute was able to be accessed and
			  * then successfully converted to the output value parameter's type.
			  * If the method fails, the value reference is not changed.
			  */
			Bool getAttribute( const UTF8String& name, Float& value ) const;
			
			
			
			
			/// Get a double value for the specified attribute in the output parameter.
			/**
			  * The method returns whether or not the attribute was able to be accessed and
			  * then successfully converted to the output value parameter's type.
			  * If the method fails, the value reference is not changed.
			  */
			Bool getAttribute( const UTF8String& name, Double& value ) const;
			
			
			
			
			/// Add an attribute with the specified name and value to this XML node.
			void addAttribute( const UTF8String& name, const UTF8String& value );
			
			
			
			
			/// Add an attribute with the specified name and templated-type value to this XML node.
			/**
			  * The template type must have an operator which allows conversion to a UTF8String.
			  */
			template < typename T >
			RIM_INLINE void addAttribute( const UTF8String& name, const T& value )
			{
				this->addAttribute( name, (UTF8String)value );
			}
			
			
			
			
			/// Set the value of the attribute with the specified name in this XML node
			/**
			  * If the attribute was not already part of the node, a new attribute with that
			  * name and value is added to the node.
			  */
			void setAttribute( const UTF8String& name, const UTF8String& value );
			
			
			
			
			/// Set the value of the attribute with the specified name in this XML node
			/**
			  * If the attribute was not already part of the node, a new attribute with that
			  * name and value is added to the node.
			  *
			  * The template type must have an operator which allows conversion to a UTF8String.
			  */
			template < typename T >
			RIM_INLINE void setAttribute( const UTF8String& name, const T& value )
			{
				this->setAttribute( name, (UTF8String)value );
			}
			
			
			
			
			/// Remove the attribute with the specified name from this XML node.
			/**
			  * The method returns whether or not there was an attribute with that
			  * name that was removed successfully.
			  */
			Bool removeAttribute( const UTF8String& name );
			
			
			
			
			/// Remove all attributes from this XML node.
			void clearAttributes();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Child Node Accessor Methods
			
			
			
			
			/// Return the number of child nodes there are for this XML node.
			RIM_INLINE Size getChildCount() const
			{
				return children.getSize();
			}
			
			
			
			
			/// Return a pointer to the child node of this node at the specified index in this node.
			RIM_INLINE const Pointer<XMLNode>& getChild( Index childIndex ) const
			{
				return children[childIndex];
			}
			
			
			
			
			/// Return a pointer to the first child node of this node which has the specified node tag.
			/**
			  * If there is no child with that tag, a NULL pointer is returned.
			  * This method ignores any child nodes that don't have the node type ELEMENT.
			  */
			Pointer<XMLNode> getFirstChildWithTag( const UTF8String& tag ) const;
			
			
			
			
			/// Get a list of all of the children of this node that have the specified node tag.
			/**
			  * The method places all of the children which have the specified tag into the
			  * given output list. The method returns whether or not any children with
			  * matching tags were found. This method ignores any child nodes
			  * that don't have the node type ELEMENT.
			  */
			Bool getChildrenWithTag( const UTF8String& tag, ArrayList<Pointer<XMLNode> >& nodes ) const;
			
			
			
			
			/// Return a pointer to the first child node of this node which has the specified node type.
			/**
			  * If there is no child with that node type, a NULL pointer is returned.
			  */
			Pointer<XMLNode> getFirstChildWithType( XMLNode::Type type ) const;
			
			
			
			
			/// Get a list of all of the children of this node that have the specified node type.
			/**
			  * The method places all of the children which have the specified type into the
			  * given output list. The method returns whether or not any children with
			  * matching types were found.
			  */
			Bool getChildrenWithType( XMLNode::Type type, ArrayList<Pointer<XMLNode> >& nodes ) const;
			
			
			
			
			/// Add the specified node to the end of this node's list of children.
			/**
			  * If the new child node pointer is NULL, the operation fails and FALSE
			  * is returned. Otherwise, TRUE is returned.
			  */
			Bool addChild( const Pointer<XMLNode>& newNode );
			
			
			
			
			/// Insert the specified node into the specified index in this node's list of children.
			/**
			  * If the new child node pointer is NULL or the insertion index is not in the range [0,n], where
			  * n is the previous number of children, the operation fails and FALSE
			  * is returned. Otherwise, TRUE is returned.
			  */
			Bool insertChild( Index insertionIndex, const Pointer<XMLNode>& newNode );
			
			
			
			
			/// Remove the child node at the specified index in this node's list of children.
			/**
			  * If the specified index is invalid, the method fails and FALSE is returned.
			  * Otherwise, the child is removed at that index and TRUE is returned.
			  * This method ignores any child nodes that don't have the node type ELEMENT.
			  */
			Bool removeChild( Index childIndex );
			
			
			
			
			/// Remove all children from this XML node that have the specified node tag.
			/**
			  * The method returns the number of children that were removed from the node.
			  */
			Size removeChildrenWithTag( const UTF8String& tag );
			
			
			
			
			/// Remove all child nodes from this node.
			void clearChildren();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value indicating the type of this node.
			Type type;
			
			
			
			
			/// A string representing the value for this node.
			/**
			  * The purpose of this string depends on the node type:
			  * - ROOT: this value is unused.
			  * - ELEMENT: this value represents the element's tag.
			  * - TEXT: this value represents the node's text string.
			  * - COMMENT: this value represents the comment string.
			  */
			UTF8String value;
			
			
			
			
			/// A list of pointers to the child nodes of this XML node.
			ArrayList< Pointer<XMLNode> > children;
			
			
			
			
			/// A list of the attributes for this node.
			ArrayList<XMLAttribute> attributes;
			
			
			
};




//##########################################################################################
//******************************  End Rim XML Namespace  ***********************************
RIM_XML_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_XML_NODE_H
