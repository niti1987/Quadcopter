/*
 *  rimGUIApplication.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 2/28/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_APPLICATION_H
#define INCLUDE_RIM_GUI_APPLICATION_H


#include "rimGUIConfig.h"


#include "rimGUIApplicationDelegate.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that serves as an interface to the main application launcher.
class Application
{
	public:
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy an application, stopping it if it is not already stopped.
			virtual ~Application();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Factory/Run Methods
			
			
			
			
			/// Run an application with the supplied entry point.
			static void start( const Function<void ( Application& )>& entryPoint );
			
			
			
			
			/// Run an application with the supplied event delegate.
			static void start( const ApplicationDelegate& delegate );
			
			
			
			/// Return a reference to the currently running application.
			static Application& getCurrent();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Run Methods
			
			
			
			
			/// Run the application and start the main thread on a new thread separate from the GUI thread.
			void start();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stop Method
			
			
			
			
			/// Signal to the application that it should terminate its event loop.
			/**
			  * After terminating the event loop, the application waits for the
			  * main thread (called when starting an application) to complete,
			  * afterwhich the application stops.
			  */
			void stop();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Is Running Accessor
			
			
			
			
			/// Return whether or not this application is currently running
			Bool isRunning() const;
			
			
			
			/// Get a string representing the name of the currently running application.
			UTF8String getName() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return a const reference to the object to which application events are being delegated.
			const ApplicationDelegate& getDelegate() const;
			
			
			
			
			/// Set the object to which application events should be delegated.
			void setDelegate( const ApplicationDelegate& newDelegate );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Event Thread ID Accessor Method
			
			
			
			
#if defined(RIM_PLATFORM_WINDOWS)
			/// Get the thread ID for the internal thread that handles GUI events.
			UInt getEventThreadID() const;
#endif
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Application Wrapper Type Declaration
			
			
			
			
#if defined(RIM_PLATFORM_WINDOWS)
			/// A class which wraps internal platform-specific state.
			class Wrapper;
#endif
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructors
			
			
			
			
			/// Create an application.
			Application();
			
			
			
			
			/// Create an application which uses the specified event delegate.
			Application( const ApplicationDelegate& newDelegate );
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A static pointer to a wrapper for platform specific application state.
#if defined(RIM_PLATFORM_WINDOWS)
			Wrapper* wrapper;
#endif
			
			
			
			/// An object which contain function objects that respond to this application's events.
			ApplicationDelegate delegate;
			
			
			
			
			/// A boolean value indicating whether or not this application is currently running.
			Bool running;
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// A pointer to the currently running global application.
			static Application* current;
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_APPLICATION_H
