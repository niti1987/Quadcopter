/*
 *  rimGraphicsGUIConfig.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_CONFIG_H
#define INCLUDE_RIM_GRAPHICS_GUI_CONFIG_H


#include "rim/rimFramework.h"
#include "rim/rimImages.h"
#include "rim/rimBVH.h"
#include "rim/rimGraphics.h"
#include "rim/rimGUI.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GRAPHICS_GUI_NAMESPACE_START
	#define RIM_GRAPHICS_GUI_NAMESPACE_START		RIM_GRAPHICS_NAMESPACE_START namespace gui {
#endif




#ifndef RIM_GRAPHICS_GUI_NAMESPACE_END
	#define RIM_GRAPHICS_GUI_NAMESPACE_END		}; RIM_GRAPHICS_NAMESPACE_END
#endif




//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




using rim::gui::input::KeyboardEvent;
using rim::gui::input::MouseButtonEvent;
using rim::gui::input::MouseMotionEvent;
using rim::gui::input::MouseWheelEvent;
using rim::gui::input::MouseButton;
using rim::gui::input::Key;
using rim::gui::input::KeyboardShortcut;


class GUIRenderer;



//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_CONFIG_H
