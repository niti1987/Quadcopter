/*
 *  rimGUIInputConfig.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 10/28/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_INPUT_CONFIG_H
#define INCLUDE_RIM_GUI_INPUT_CONFIG_H


#include "../rimGUIConfig.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GUI_INPUT_NAMESPACE
	#define RIM_GUI_INPUT_NAMESPACE input
#endif




#ifndef RIM_GUI_INPUT_NAMESPACE_START
	#define RIM_GUI_INPUT_NAMESPACE_START		RIM_GUI_NAMESPACE_START namespace RIM_GUI_INPUT_NAMESPACE {
#endif




#ifndef RIM_GUI_INPUT_NAMESPACE_END
	#define RIM_GUI_INPUT_NAMESPACE_END		}; RIM_GUI_NAMESPACE_END
#endif




RIM_GUI_NAMESPACE_START
/// A namespace containing classes which handle user mouse/keyboard input.
namespace RIM_GUI_INPUT_NAMESPACE {
};
RIM_GUI_NAMESPACE_END




//##########################################################################################
//************************     Start Rim GUI Input Namespace     ***************************
RIM_GUI_INPUT_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//##########################################################################################
//************************     End Rim GUI Input Namespace     *****************************
RIM_GUI_INPUT_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GUI_INPUT_CONFIG_H
