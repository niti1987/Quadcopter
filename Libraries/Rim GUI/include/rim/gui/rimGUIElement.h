/*
 *  rimGUIElement.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 5/25/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_ELEMENT_H
#define INCLUDE_RIM_GUI_ELEMENT_H


#include "rimGUIConfig.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which serves as the superclass for all OS-specific GUI elements.
/**
  * It defines a basic interface that all of these classes should adhere to. It
  * allows other GUI elements to access platform-specific data through a generic
  * pointer interface.
  */
class GUIElement
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a GUI element and release all resources associated with it.
			virtual ~GUIElement();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Platform-Specific Element Pointer Accessor Method
			
			
			
			
			/// Return a pointer to the OS-specific object which represents this element.
			/**
			  * If there is no such object, NULL may be returned.
			  */
			virtual void* getInternalPointer() const = 0;
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Event Thread Accessor Method
			
			
			
			
#if defined(RIM_PLATFORM_WINDOWS)
			/// Return an integer which inidicates the ID of the thread which is handling this GUI element's events.
			UInt getEventThreadID() const;
#endif
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_ELEMENT_H
