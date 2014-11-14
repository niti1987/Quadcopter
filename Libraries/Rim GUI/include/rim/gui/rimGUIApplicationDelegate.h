/*
 *  rimGUIApplicationDelegate.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 6/7/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_APPLICATION_DELEGATE_H
#define INCLUDE_RIM_GUI_APPLICATION_DELEGATE_H


#include "rimGUIConfig.h"


#include "rimGUIInput.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Application;



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains function objects that recieve application events.
/**
  * Any application-related event that might be processed has an appropriate callback
  * function object. Each callback function is called by the GUI event thread 
  * whenever such an event is received. If a callback function in the delegate
  * is not initialized, an application simply ignores it.
  * 
  * It must be noted that the callback functions are asynchronous and
  * not thread-safe. Thus, it is necessary to perform any additional synchronization
  * externally.
  */
class ApplicationDelegate
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Application Event Callback Functions
			
			
			
			
			/// A function object which is called whenever an attached application is lauched.
			/**
			  * This callback serves as the main entry point for the application's non-GUI code.
			  * It is called on its own thread and thus the function need not return until the
			  * application should close. When this function returns , the 'shouldStop' delegate method
			  * will be called to determine if the application's GUI event thread should terminate.
			  * If the delegate signals that it should, then the application will stop.
			  *		If this method is never set, the application ignores it and continues to
			  * run the GUI event thread until it is told to stop.
			  */
			Function<void ( Application& )> start;
			
			
			
			
			/// A function object which is called whenever a file should be opened by an application.
			/**
			  * For instance, this method is invoked whenever a file is dragged onto an application's
			  * icon, telling it to open the specified file. The method is given a string which
			  * represents the path to the file to be opened. The method should return TRUE if
			  * the file was opened successfully or FALSE if it was not.
			  */
			Function<Bool ( Application&, const File& )> openFile;
			
			
			
			
			/// A function object which is called whenever multiple files should be opened by an application.
			/**
			  * For instance, this method is invoked whenever several files are dragged
			  * onto an application's icon, telling it to open the specified files. The method
			  * is given an array list of strings which represent paths to the files to be opened.
			  *		The method should return TRUE if at least one of the files was opened successfully,
			  * or FALSE otherwise.
			  */
			Function<Bool ( Application&, const ArrayList<File>& )> openFiles;
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	User Input Callback Functions
			
			
			
			
			/// A function object called whenever an attached application receives a keyboard event.
			Function<void ( Application&, const input::KeyboardEvent& )> keyEvent;
			
			
			
			
			/// A function object called whenever an attached application receives a mouse-motion event.
			Function<void ( Application&, const input::MouseMotionEvent& )> mouseMotionEvent;
			
			
			
			
			/// A function object called whenever an attached application receives a mouse-button event.
			Function<void ( Application&, const input::MouseButtonEvent& )> mouseButtonEvent;
			
			
			
			
			/// A function object called whenever an attached application receives a mouse-wheel event.
			Function<void ( Application&, const input::MouseWheelEvent& )> mouseWheelEvent;
			
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_APPLICATION_DELEGATE_H
