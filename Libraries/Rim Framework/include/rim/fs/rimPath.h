/*
 *  rimPath.h
 *  Rim IO
 *
 *  Created by Carl Schissler on 10/30/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PATH_H
#define INCLUDE_RIM_PATH_H


#include "rimFileSystemConfig.h"


//##########################################################################################
//*************************  Start Rim File System Namespace  ******************************
RIM_FILE_SYSTEM_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class representing a path to a file or directory in the local file system (not networked, etc).
class Path
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a path corresponding to the root directory
			Path();
			
			
			
			
			/// Create a path from the specified NULL-terminated path string.
			/**
			  * This path string is parsed into a sequence of path elements for easier manipulation.
			  */
			Path( const Char* newPathString );
			
			
			
			
			/// Create a path from the specified path string.
			/**
			  * This path string is parsed into a sequence of path elements for easier manipulation.
			  */
			Path( const UTF8String& newPathString );
			
			
			
			
			/// Create a path from an existing path plus the child path specified in the second parameter.
			/**
			  * This creates a new path which consists of all path components from the first path
			  * plus any additional path components specified by the second path parameter.
			  */
			Path( const Path& path, const Path& children );
			
			
			
			
			/// Create a path from an existing path plus the child path string specified in the second parameter.
			/**
			  * This creates a new path which consists of all path components from the first path
			  * plus any additional path components specified by the second path parameter.
			  */
			Path( const Path& path, const UTF8String& children );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Path Equality Comparison Operators
			
			
			
			
			/// Return whether or not this path is equal to another.
			RIM_INLINE Bool operator == ( const Path& other ) const
			{
				return pathString == other.pathString;
			}
			
			
			
			
			/// Return whether or not this path is not equal to another.
			RIM_INLINE Bool operator != ( const Path& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Path String Accessor Methods
			
			
			
			
			/// Return the full string representing this path.
			RIM_INLINE const UTF8String& toString() const
			{
				return pathString;
			}
			
			
			
			
			/// Return the full string representing this path.
			RIM_INLINE const UTF8String& getString() const
			{
				return pathString;
			}
			
			
			
			
			/// Convert this path to a string object.
			RIM_INLINE operator const UTF8String& () const
			{
				return this->toString();
			}
			
			
			
			
			/// Convert this path to an ASCII string object.
			/**
			  * This conversion may result in corruption of the path string if
			  * any unicode characters are present in the string
			  */
			RIM_INLINE operator String () const
			{
				return String(this->toString());
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Path Name Accessor Methods
			
			
			
			
			/// Return the name of the file or directory specified by this path.
			/**
			  * This name is last component of the path string.
			  */
			RIM_INLINE UTF8String getName() const
			{
				if ( this->isRoot() )
					return UTF8String("/");
				else
				{
					const PathComponent& component = components.getLast();
					return UTF8String( pathString.getPointer() + component.startIndex, component.numCharacters );
				}
			}
			
			
			
			
			/// Return the base name of the file or directory specified by this path before any file extension.
			/**
			  * The returned string is the same as if the extension (if it exists) had been removed from
			  * the output of getName().
			  */
			UTF8String getBaseName() const;
			
			
			
			
			/// Return a string representing the extension of this paths's file name.
			/**
			  * The extension is defined as the characters after the last period '.'
			  * in the last component of the path string, if present. If there is no
			  * extension, the empty string is returned.
			  */
			UTF8String getExtension() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Path Component Accessor Methods
			
			
			
			
			/// Return the number of components that make up this path.
			RIM_INLINE Size getComponentCount() const
			{
				return components.getSize();
			}
			
			
			
			
			/// Return the name of path component at the specified depth in the path heirarchy.
			/**
			  * If a depth of 0 is specified, the name of the path's last component is returned.
			  * A depth of 1 returns the name of the parent component of the last component and so on.
			  */
			RIM_INLINE UTF8String getComponentAtDepth( Index depth ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( depth < components.getSize(), "Cannot access path component at invalid depth." );
				
				const PathComponent& component = components[components.getSize() - depth - 1];
				return UTF8String( pathString.getPointer() + component.startIndex, component.numCharacters );
			}
			
			
			
			
			/// Return a path object that is the parent of this path object in the file system hierarchy.
			/**
			  * If the path represents a file system node at root level or is the root directory, the
			  * root path is returned.
			  */
			Path getParent() const;
			
			
			
			
			/// Return a path object that is the ancestor of this path object in the file system at the specified age.
			/**
			  * A depth of 0 returns a copy of this path object. A depth of 1 returns the parent directory of this
			  * path and so on. If the requested depth is greater than the depth of the path's hierarchy,
			  * the root path is returned.
			  */
			Path getParentAtDepth( Index depth ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Path Component Add Methods
			
			
			
			
			/// Add all of the path components from the specified path as children of this path.
			void addChildren( const Path& path );
			
			
			
			
			/// Add all of the path components from the specified path string as children of this path.
			void addChildren( const UTF8String& pathString );
			
			
			
			
			/// Add all of the path components from the specified path as children of this path.
			RIM_INLINE Path& operator += ( const Path& path )
			{
				this->addChildren( path );
				return *this;
			}
			
			
			
			
			/// Add all of the path components from the specified path string as children of this path.
			RIM_INLINE Path& operator += ( const UTF8String& pathString )
			{
				this->addChildren( pathString );
				return *this;
			}
			
			
			
			
			/// Add all of the path components from the specified path string as children of this path.
			RIM_INLINE Path& operator += ( const Char* pathString )
			{
				this->addChildren( UTF8String(pathString) );
				return *this;
			}
			
			
			
			
			/// Return a new path as the concatenation of the path components from this and another path.
			RIM_INLINE Path operator + ( const Path& path ) const
			{
				return Path( *this, path );
			}
			
			
			
			
			/// Return a new path as the concatenation of the path components from this and another path string.
			RIM_INLINE Path operator + ( const UTF8String& pathString ) const
			{
				return Path( *this, pathString );
			}
			
			
			
			
			/// Return a new path as the concatenation of the path components from this and another path string.
			RIM_INLINE Path operator + ( const Char* pathString ) const
			{
				return Path( *this, UTF8String( pathString ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Path Component Remove Methods
			
			
			
			
			/// Remove the last path component from this path, resulting in the path representing its parent.
			void removeLastComponent();
			
			
			
			
			/// Remove the specified number of path components from the path.
			/**
			  * Starting with the last path component, this method removes as many path components
			  * as possible from the path until either the specified number is removed or the
			  * root directory is reached.
			  */
			void removeLastComponents( Size number );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Path Attribute Accessor Methods
			
			
			
			
			/// Return whether or not this path is relative to the current working directory.
			RIM_INLINE Bool isRelative() const
			{
				return pathIsRelative;
			}
			
			
			
			
			/// Return whether or not this path specifies a file or directory at root level.
			RIM_INLINE Bool isAtRootLevel() const
			{
				return components.getSize() == 1 && !pathIsRelative;
			}
			
			
			
			
			/// Return whether or not this path specifies the root system directory.
			RIM_INLINE Bool isRoot() const
			{
				return (components.getSize() == 0) && !pathIsRelative;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Path Component Class Definition
			
			
			
			
			/// A class representing a section of a path string which is a component of the path.
			class PathComponent
			{
				public:
					
					RIM_INLINE PathComponent( Index newStartIndex, Size newNumCharacters )
						:	startIndex( newStartIndex ),
							numCharacters( newNumCharacters )
					{
					}
					
					
					/// The index of the first character within the path string where this component starts.
					Index startIndex;
					
					
					
					/// The number of characters in this path component's name.
					Size numCharacters;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Methods
			
			
			
			
			static void sanitizePathString( const UTF8String& pathString, ArrayList<PathComponent>& components,
											Bool pathIsRelative, UTF8String& outputString );
			
			
			
			
			/// Return whether or not the specified character is a path separator.
			RIM_FORCE_INLINE static Bool isAPathSeparator( UTF8Char character );
			
			
			
			
			static void parsePathAndAddComponents( const UTF8String& pathString, ArrayList<PathComponent>& components,
													Bool& pathIsRelative );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A string representing the entire path.
			UTF8String pathString;
			
			
			
			
			/// A list of the components of this Path.
			ArrayList<PathComponent> components;
			
			
			
			
			/// Whether or not the Path is relative to the current working directory.
			Bool pathIsRelative;
			
			
			
			
};




//##########################################################################################
//*************************  End Rim File System Namespace  ********************************
RIM_FILE_SYSTEM_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PATH_H
