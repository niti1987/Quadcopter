/*
 *  rimGUIConfig.h
 *  Rim Application
 *
 *  Created by Carl Schissler on 10/28/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_CONFIG_H
#define INCLUDE_RIM_GUI_CONFIG_H


#include "rim/rimFramework.h"
#include "rim/rimImages.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GUI_NAMESPACE
	#define RIM_GUI_NAMESPACE gui
#endif




#ifndef RIM_GUI_NAMESPACE_START
	#define RIM_GUI_NAMESPACE_START		RIM_NAMESPACE_START namespace RIM_GUI_NAMESPACE {
#endif




#ifndef RIM_GUI_NAMESPACE_END
	#define RIM_GUI_NAMESPACE_END		}; RIM_NAMESPACE_END
#endif




RIM_NAMESPACE_START
/// The enclosing namespace for the GUI library.
namespace RIM_GUI_NAMESPACE {
};
RIM_NAMESPACE_END




//##########################################################################################
//##########################################################################################
//############		
//############		Other Library Configuration
//############		
//##########################################################################################
//##########################################################################################




// Define the types of user-defined windows events, where 0x8000 corresponds to the value of WM_APP.
#if defined(RIM_PLATFORM_WINDOWS)
	
	/// Define the windows message number to use for a Window class creation event.
	#define RIM_WM_WINDOW_WANTS_CREATION	(0x8000 + 0x1000)
	
	/// Define the windows message number to use for an OpenGLView class creation event.
	#define RIM_WM_RENDER_VIEW_WANTS_CREATION	(0x8000 + 0x1001)
	
	/// Define the windows message number to use for a Button class creation event.
	#define RIM_WM_BUTTON_WANTS_CREATION	(0x8000 + 0x1002)
	
	/// Define the windows message number to use for a TextField class creation event.
	#define RIM_WM_TEXT_FIELD_WANTS_CREATION	(0x8000 + 0x1003)
	
	/// Define the windows message number to use when showing the mouse cursor.
	#define RIM_WM_SHOW_CURSOR	(0x8000 + 0x1004)
	
	/// Define the windows message number to use when showing the mouse cursor.
	#define RIM_WM_HIDE_CURSOR	(0x8000 + 0x1005)
	
#endif




//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




using namespace rim::threads;
using rim::math::Vector2i;
using rim::math::Vector2f;
typedef rim::math::Vector2D<Size> Size2D;


using rim::images::Image;



//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################



#endif // INCLUDE_RIM_GUI_CONFIG_H
