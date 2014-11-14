/*
 *  rimDirectory.h
 *  Rim IO
 *
 *  Created by Carl Schissler on 5/22/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_DIRECTORY_H
#define INCLUDE_RIM_DIRECTORY_H


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
/// A class which represents a directory within the global file system.
/**
  * A directory is a collection of file system nodes (files or directories) that is
  * also a file system node. The directory class allows the user to query a directory's
  * size, name, path, and children, as well as create and destory directories.
  */
class Directory : public FileSystemNode
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a directory object representing the root directory.
			Directory();
			
			
			
			
			/// Create a directory object for the specified path string.
			Directory( const UTF8String& newPathString );
			
			
			
			
			/// Create a directory object for the specified path.
			Directory( const Path& newPath );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	File Attribute Accessor Methods
			
			
			
			
			/// Return whether or not the file system node is a file.
			RIM_INLINE virtual Bool isAFile() const
			{
				return false;
			}
			
			
			
			
			/// Return whether or not the file system node is a directory.
			RIM_INLINE virtual Bool isADirectory() const
			{
				return true;
			}
			
			
			
			
			/// Return whether or not this directory exists.
			virtual Bool exists() const;
			
			
			
			
			/// Get the total size of the directory.
			/**
			  * This is the total size of all child file system nodes.
			  */
			virtual LargeSize getSize() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Directory Modification Methods
			
			
			
			
			/// Set the name of the directory, the last component of its path.
			virtual Bool setName( const UTF8String& newName );
			
			
			
			
			/// Create this directory if it doesn't exist.
			/**
			  * If the directory already exists, no operation is performed
			  * and TRUE is returned. If the creation operation was not successful,
			  * FALSE is returned. Otherwise, TRUE is returned and the node is created.
			  */
			virtual Bool create();
			
			
			
			
			/// Remove this directory and all children.
			virtual Bool remove();
			
			
			
			
			/// Erase this directory or create it if it doesn't exist.
			/**
			  * If there was an error during creation, FALSE is returned.
			  * Otherwise, TRUE is returned and the file is erased.
			  */
			Bool erase();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Child Accessor Methods
			
			
			
			
			/// Get the number of child file system nodes this Directory has.
			RIM_INLINE Size getChildCount() const
			{
				if ( !hasCachedChildren )
					const_cast<Directory*>(this)->cacheChildren();
				
				return children.getSize();
			}
			
			
			
			
			/// Get the name of the directory's child at the specified index.
			RIM_INLINE const UTF8String& getChildName( Index index ) const
			{
				if ( !hasCachedChildren )
					const_cast<Directory*>(this)->cacheChildren();
				
				RIM_DEBUG_ASSERT_MESSAGE( index < children.getSize(), "Cannot access directory child at invalid index." );
				
				return children[index].name;
			}
			
			
			
			
			/// Get the path to the directory child at the specified index.
			RIM_INLINE Path getChildPath( Index index ) const
			{
				if ( !hasCachedChildren )
					const_cast<Directory*>(this)->cacheChildren();
				
				RIM_DEBUG_ASSERT_MESSAGE( index < children.getSize(), "Cannot access directory child at invalid index." );
				
				return Path( this->getPath(), children[index].name );
			}
			
			
			
			
			/// Return whether or not the directory's child at the specified index is a file.
			RIM_INLINE Bool childIsAFile( Index index ) const
			{
				if ( !hasCachedChildren )
					const_cast<Directory*>(this)->cacheChildren();
				
				RIM_DEBUG_ASSERT_MESSAGE( index < children.getSize(), "Cannot access directory child at invalid index." );
				
				return children[index].isAFile;
			}
			
			
			
			
			/// Return whether or not the directory's child at the specified index is a directory.
			RIM_INLINE Bool childIsADirectory( Index index ) const
			{
				if ( !hasCachedChildren )
					const_cast<Directory*>(this)->cacheChildren();
				
				RIM_DEBUG_ASSERT_MESSAGE( index < children.getSize(), "Cannot access directory child at invalid index." );
				
				return !children[index].isAFile;
			}
			
			
			
			
			/// Return whether or not the directory has a child with the specified name.
			Bool hasChild( const UTF8String& name ) const;
			
			
			
			
			/// Refresh the directory's cache of child file system nodes.
			RIM_INLINE void refreshChildren()
			{
				hasCachedChildren = false;
				children.clear();
				cacheChildren();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Current Working Directory Accessor Methods
			
			
			
			
			/// Get the absolute path of the current working directory.
			static Path getCurrent();
			
			
			
			
			/// Set the path of the current working directory.
			/**
			  * If the attempt to set the current working directory to the specified
			  * path fails, FALSE is returned and the current working directory is not
			  * changed. Otherwise, if the attempt succeeds, TRUE is returned and the
			  * current working directory is set to the specified path.
			  */
			static Bool setCurrent( const Path& path );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Important Directory Accessor Methods
			
			
			
			
			/// Return the path to the directory which contains this application's executable.
			static Path getExecutable();
			
			
			
			
			/// Return the path to the system's applications directory.
			/**
			  * On Mac OS X, this is the /Applications/ directory. On Windows
			  * this is the C:\Program Files\ directory.
			  */
			static Path getApplications();
			
			
			
			
			/// Return the path to the system user's home folder.
			static Path getUser();
			
			
			
			
			/// Return the path to the system user's documents directory.
			static Path getDocuments();
			
			
			
			
			/// Return the path to the system user's desktop directory.
			static Path getDesktop();
			
			
			
			
			/// Return the path to the system user's preferences directory.
			static Path getPreferences();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Child Info
			
			
			
			
			/// A class which contains information about a child file system node of this directory.
			class ChildInfo
			{
				public:
					
					RIM_INLINE ChildInfo( const UTF8String& newName, Bool newIsAFile )
						:	name( newName ),
							isAFile( newIsAFile )
					{
					}
					
					
					UTF8String name;
					Bool isAFile;
					
					
			};
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Cache the children of this directory if they haven't been cached yet.
			void cacheChildren();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the names of the child file system nodes of this directory.
			ArrayList<ChildInfo> children;
			
			
			
			
			/// Whether or not the children of this directory have been 
			Bool hasCachedChildren;
			
			
			
};




//##########################################################################################
//*************************  End Rim File System Namespace  ********************************
RIM_FILE_SYSTEM_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_DIRECTORY_H
