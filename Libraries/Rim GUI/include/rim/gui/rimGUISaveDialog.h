/*
 *  rimGUISaveDialog.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/29/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_SAVE_DIALOG_H
#define INCLUDE_RIM_GUI_SAVE_DIALOG_H


#include "rimGUIConfig.h"


#include "rimGUIElement.h"
#include "rimGUISaveDialogDelegate.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a user dialog for saving files.
class SaveDialog : public GUIElement
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a save dialog with the default starting path, the root directory of the system drive.
			SaveDialog();
			
			
			
			
			/// Create a save dialog with the specified starting path.
			SaveDialog( const UTF8String& startingPath );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a save dialog, closing it if is visible and releasing all resources used.
			~SaveDialog();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate (Event Handler) Accessor Methods
			
			
			
			
			/// Block the calling thread until the user selects a file.
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
			
			
			
			
			/// Return the current user-selected save file path.
			Path getPath() const;
			
			
			
			
			/// Return a path representing the current directory of the save dialog.
			/**
			  * This path is the parent of the file that the user has
			  * selected to be saved.
			  */
			Path getSearchPath() const;
			
			
			
			
			/// Set the path for the current directory of the save dialog.
			/**
			  * The method returns whether or not the path was able to be set.
			  */
			Bool setSearchPath( const Path& newPath );
			
			
			
			
			/// Set the path for the current directory of the save dialog.
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
			
			
			
			
			/// Return the number of allowed file types for this save dialog.
			/**
			  * If there are no types specified, any file type is allowed.
			  */
			Size getTypeCount() const;
			
			
			
			
			/// Return the file type extension string for the type at the specified index in this dialog.
			const UTF8String& getType( Index typeIndex ) const;
			
			
			
			
			/// Return the file type display name for the type at the specified index in this dialog.
			const UTF8String& getTypeName( Index typeIndex ) const;
			
			
			
			
			/// Add a new file type to this save dialog.
			/**
			  * The method returns whether or not the new type was able to be added.
			  */
			Bool addType( const UTF8String& extension );
			
			
			
			
			/// Add a new file type to this save dialog with the specified display name.
			/**
			  * The method returns whether or not the new type was able to be added.
			  */
			Bool addType( const UTF8String& extension, const UTF8String& displayName );
			
			
			
			
			/// Remove the specified file type string from this save dialog.
			/**
			  * The method returns whether or not the new type was able to be removed.
			  */
			Bool removeType( const UTF8String& extension );
			
			
			
			
			/// Remove all file types from this save dialog.
			/**
			  * After this operation, any file type is allowed.
			  */
			Bool clearTypes();
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Title Accessor Methods
			
			
			
			
			/// Return the title string for this save dialog.
			/**
			  * On most platforms, this string will be placed at the top of the window in
			  * a title bar.
			  */
			UTF8String getTitle() const;
			
			
			
			
			/// Set the title string for this save dialog.
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
			
			
			
			
			/// Get a reference to the delegate object associated with this save dialog.
			const SaveDialogDelegate& getDelegate() const;
			
			
			
			
			/// Set the delegate object to which this save dialog sends events.
			void setDelegate( const SaveDialogDelegate& delegate );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Platform-Specific Pointer Accessor Method
			
			
			
			
			/// Get a pointer to this save dialog's platform-specific internal representation.
			/**
			  * On Mac OS X, this method returns a pointer to a subclass of NSSavePanel
			  * which represents the save dialog.
			  *
			  * On Windows, this method returns an HWND indicating a handle to the save dialog window.
			  */
			virtual void* getInternalPointer() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Shared Construction Methods
			
			
			
			
			/// Create a shared-pointer save dialog object, calling the constructor with the same arguments.
			RIM_INLINE static Pointer<SaveDialog> construct()
			{
				return Pointer<SaveDialog>( util::construct<SaveDialog>() );
			}
			
			
			
			
			/// Create a shared-pointer save dialog object, calling the constructor with the same arguments.
			RIM_INLINE static Pointer<SaveDialog> construct( const UTF8String& startingPath )
			{
				return Pointer<SaveDialog>( util::construct<SaveDialog>( startingPath ) );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Save Dialog Wrapper Class Declaration
			
			
			
			
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


#endif	// INCLUDE_RIM_GUI_SAVE_DIALOG_H
