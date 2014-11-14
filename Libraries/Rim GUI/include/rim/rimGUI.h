/*
 *  rimGUI.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 10/28/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_H
#define INCLUDE_RIM_GUI_H



#include "gui/rimGUIConfig.h"


// Input Namespace.
#include "gui/rimGUIInput.h"


// System Namespace.
#include "gui/rimGUISystem.h"


// Application
#include "gui/rimGUIApplication.h"


// Window Elements
#include "gui/rimGUIWindow.h"
#include "gui/rimGUIWindowDelegate.h"
#include "gui/rimGUIWindowElement.h"


// View Elements
#include "gui/rimGUIView.h"
#include "gui/rimGUIRenderView.h"
#include "gui/rimGUIRenderViewDelegate.h"


// Text Elements
#include "gui/rimGUITextField.h"
#include "gui/rimGUITextFieldDelegate.h"


// Button Elements
#include "gui/rimGUIButton.h"
#include "gui/rimGUIButtonDelegate.h"


// Menu Elements
#include "gui/rimGUIMenuItem.h"
#include "gui/rimGUIMenuItemDelegate.h"
#include "gui/rimGUIMenu.h"
#include "gui/rimGUIMenuDelegate.h"


// Dialogs
#include "gui/rimGUISaveDialog.h"
#include "gui/rimGUIOpenDialog.h"



//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




using namespace rim::gui::input;




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################




#ifdef RIM_GUI_NAMESPACE_START
	#undef RIM_GUI_NAMESPACE_START
#endif




#ifdef RIM_GUI_NAMESPACE_END
	#undef RIM_GUI_NAMESPACE_END
#endif



#endif // INCLUDE_RIM_GUI_H
