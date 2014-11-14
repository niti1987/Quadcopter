/*
 *  rimGUIOpenDialog.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/29/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_OPEN_DIALOG_H
#define INCLUDE_RIM_GUI_OPEN_DIALOG_H


#include "rimGUIConfig.h"


#include "rimGUIElement.h"
#include "rimGUIOpenDialogDelegate.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a user dialog for saving files.
class OpenDialog : public GUIElement
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an open dialog with the default starting path, the root directory of the system drive.
			OpenDialog();
			
			
			
			
			/// Create an open dialog with the specified starting path.
			OpenDialog( const UTF8String& startingPath );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy an open dialog, closing it if is visible and releasing all resources used.
			~OpenDialog();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate (Event Handler) Accessor Methods
			
			
			
			
			/// Block the calling thread until the user selects a file to open.
			/**
			  * The selected file path is sent to the delegate for the dialog.
			  * The method returns whether or not the file was successfully
			  * opened by the delegate.
			  *
			  * If the method returns TRUE, the path of the file can be accessed
			  * by calling getPath().
			  */
			Bool run();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Path Accessor Methods
			
			
			
			
			/// Return the current user-selected open file path.
			Path getPath() const;
			
			
			
			
			/// Return a path representing the current directory of the open dialog.
			/**
			  * This path is the parent of the file that the user has
			  * selected to be opend.
			  */
			Path getSearchPath() const;
			
			
			
			
			/// Set the path for the current directory of the open dialog.
			/**
			  * The method returns whether or not the path was able to be set.
			  */
			Bool setSearchPath( const Path& newPath );
			
			
			
			
			/// Set the path for the current directory of the open dialog.
			/**
			  * The method returns whether or not the path was able to be set.
			  */
			RIM_INLINE Bool setSearchPath( const UTF8String& newPath )
			{
				return this->setSearchPath( Path( newPath ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	File Type Accessor Methods
			
			
			
			
			/// Return the number of allowed file types for this open dialog.
			/**
			  * If there are no types specified, any file type is allowed.
			  */
			Size getTypeCount() const;
			
			
			
			
			/// Return the file type string for the type at the specified index in this dialog.
			const UTF8String& getType( Index typeIndex ) const;
			
			
			
			
			/// Add a new file type string to this open dialog.
			/**
			  * The method returns whether or not the new type was able to be added.
			  */
			Bool addType( const UTF8String& newType );
			
			
			
			
			/// Remove the specified file type string from this open dialog.
			/**
			  * The method returns whether or not the new type was able to be removed.
			  */
			Bool removeType( const UTF8String& type );
			
			
			
			
			/// Remove all file types from this open dialog.
			/**
			  * After this operation, any file type is allowed.
			  */
			Bool clearTypes();
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Title Accessor Methods
			
			
			
			
			/// Return the title string for this open dialog.
			/**
			  * On most platforms, this string will be placed at the top of the window in
			  * a title bar.
			  */
			UTF8String getTitle() const;
			
			
			
			
			/// Set the title string for this open dialog.
			/**
			  * The method returns whether or not the title change operation was successful.
			  */
			Bool setTitle( const UTF8String& newTitle );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Hidden File Accessor Methods
			
			
			
			
			/// Return whether or not this open dialog can see hidden files.
			Bool getHiddenFiles() const;
			
			
			
			
			/// Set whether or not this open dialog can see hidden files.
			Bool setHiddenFiles( Bool newHiddenFiles );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate (Event Handler) Accessor Methods
			
			
			
			
			/// Get a reference to the delegate object associated with this open dialog.
			const OpenDialogDelegate& getDelegate() const;
			
			
			
			
			/// Set the delegate object to which this open dialog sends events.
			void setDelegate( const OpenDialogDelegate& delegate );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Platform-Specific Pointer Accessor Method
			
			
			
			
			/// Get a pointer to this open dialog's platform-specific internal representation.
			/**
			  * On Mac OS X, this method returns a pointer to a subclass of NSOpenPanel
			  * which represents the open dialog.
			  *
			  * On Windows, this method returns an HWND indicating a handle to the open dialog window.
			  */
			virtual void* getInternalPointer() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Shared Construction Methods
			
			
			
			
			/// Create a shared-pointer open dialog object, calling the constructor with the same arguments.
			RIM_INLINE static Pointer<OpenDialog> construct()
			{
				return Pointer<OpenDialog>( util::construct<OpenDialog>() );
			}
			
			
			
			
			/// Create a shared-pointer open dialog object, calling the constructor with the same arguments.
			RIM_INLINE static Pointer<OpenDialog> construct( const UTF8String& startingPath )
			{
				return Pointer<OpenDialog>( util::construct<OpenDialog>( startingPath ) );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Open Dialog Wrapper Class Declaration
			
			
			
			
			/// A class which encapsulates internal platform-specific state.
			class Wrapper;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to internal implementation-specific data.
			Wrapper* wrapper;
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_OPEN_DIALOG_H
