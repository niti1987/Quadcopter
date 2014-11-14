/*
 *  rimFile.h
 *  Rim IO
 *
 *  Created by Carl Schissler on 5/22/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_FILE_H
#define INCLUDE_RIM_FILE_H


#include "rimFileSystemConfig.h"


#include "rimFileSystemNode.h"


//##########################################################################################
//*************************  Start Rim File System Namespace  ******************************
RIM_FILE_SYSTEM_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a file in the global file system.
/**
  * A File object can represent a local file, network file, or any other type
  * of file resource. This class also allows the user to create and delete files
  * with the given file path and determine other basic information about the file.
  */
class File : public FileSystemNode
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a file object which corresponds to the specified path string.
			File( const UTF8String& newPathString );
			
			
			
			
			/// Create a file object which corresponds to the specified path.
			File( const Path& newPath );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	File Attribute Accessor Methods
			
			
			
			
			/// Return whether or not the file system node is a file.
			RIM_INLINE virtual Bool isAFile() const
			{
				return true;
			}
			
			
			
			
			/// Return whether or not the file system node is a directory.
			RIM_INLINE virtual Bool isADirectory() const
			{
				return false;
			}
			
			
			
			
			/// Return whether or not this file system node exists.
			virtual Bool exists() const;
			
			
			
			
			/// Return the total size of the file system node.
			/**
			  * For files, this is the total size of the file. For directories,
			  * this is the total size of all child file system nodes. If the file
			  * does not exist, the size 0 is returned.
			  */
			virtual LargeSize getSize() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	File Modification Methods
			
			
			
			
			/// Set the name of the file, the last component of its path.
			virtual Bool setName( const UTF8String& newName );
			
			
			
			
			/// Create this file if it doesn't exist.
			/**
			  * If the file system node already exists, no operation is performed
			  * and FALSE is returned. If the creation operation was not successful,
			  * FALSE is returned. Otherwise, TRUE is returned and the node is created.
			  */
			virtual Bool create();
			
			
			
			
			/// Delete this file system node and all children (if it is a directory).
			virtual Bool remove();
			
			
			
			
			/// Erase this file or create it if it doesn't exist.
			/**
			  * If there was an error during creation, FALSE is returned.
			  * Otherwise, TRUE is returned and the file is erased.
			  */
			Bool erase();
			
			
			
};




//##########################################################################################
//*************************  End Rim File System Namespace  ********************************
RIM_FILE_SYSTEM_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_FILE_H
