/*
 *  rimFileSystemNode.h
 *  Rim IO
 *
 *  Created by Carl Schissler on 5/22/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_FILE_SYSTEM_NODE_H
#define INCLUDE_RIM_FILE_SYSTEM_NODE_H


#include "rimFileSystemConfig.h"


#include "rimPath.h"


//##########################################################################################
//*************************  Start Rim File System Namespace  ******************************
RIM_FILE_SYSTEM_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the interface for a node within the global file system.
/**
  * A file system node can be either a file or a directory. The file system node allows
  * the user to query basic properties of the node (size, path, name, type) and to
  * create and remove the referenced file system node.
  */
class FileSystemNode
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a file system node object.
			virtual ~FileSystemNode()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Path Accessor Methods
			
			
			
			
			/// Return the name of the file system node, the last component of its path.
			RIM_INLINE UTF8String getName() const
			{
				return path.getName();
			}
			
			
			
			
			/// Set the name of the file system node, the last component of its path.
			virtual Bool setName( const UTF8String& newName ) = 0;
			
			
			
			
			/// Return a string representing the extension of this node's file name.
			/**
			  * The extension is defined as the characters after the last period '.'
			  * in the node's file name.
			  */
			RIM_INLINE UTF8String getExtension() const
			{
				return path.getExtension();
			}
			
			
			
			
			/// Return a path object representing the path to this file system node.
			RIM_INLINE const Path& getPath() const
			{
				return path;
			}
			
			
			
			
			/// Return a string representing the path to the file system node.
			RIM_INLINE const UTF8String& getPathString() const
			{
				return path.toString();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Node Attribute Accessor Methods
			
			
			
			
			/// Return whether or not the file system node is a file.
			virtual Bool isAFile() const = 0;
			
			
			
			
			/// Return whether or not the file system node is a directory.
			virtual Bool isADirectory() const = 0;
			
			
			
			
			/// Return whether or not the file system node is at the root level of the file system.
			RIM_INLINE Bool isAtRootLevel() const
			{
				return path.isAtRootLevel();
			}
			
			
			
			
			/// Return whether or not this file system node exists.
			virtual Bool exists() const = 0;
			
			
			
			
			/// Get the total size of the file system node.
			/**
			  * For files, this is the total size of the file. For directories,
			  * this is the total size of all child file system nodes.
			  */
			virtual LargeSize getSize() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Node Modification Methods
			
			
			
			
			/// Create this file system node if it doesn't exist.
			/**
			  * If the file system node already exists, no operation is performed
			  * and FALSE is returned. If the creation operation was not successful,
			  * FALSE is returned. Otherwise, TRUE is returned and the node is created.
			  */
			virtual Bool create() = 0;
			
			
			
			
			/// Remove this file system node and all children (if it is a directory).
			virtual Bool remove() = 0;
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Constructor
			
			
			
			
			/// Create a file system node which is represented by the specified path string.
			RIM_INLINE FileSystemNode( const UTF8String& newPathString )
				:	path( newPathString )
			{
			}
			
			
			
			
			/// Create a file system node which is represented by the specified path.
			RIM_INLINE FileSystemNode( const Path& newPath )
				:	path( newPath )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The path to this file system node.
			Path path;
			
			
			
};




//##########################################################################################
//*************************  End Rim File System Namespace  ********************************
RIM_FILE_SYSTEM_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_FILE_SYSTEM_NODE_H
