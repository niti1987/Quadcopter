/*
 *  rimGUIInputConfig.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 10/28/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_SYSTEM_CONFIG_H
#define INCLUDE_RIM_GUI_SYSTEM_CONFIG_H


#include "../rimGUIConfig.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_GUI_SYSTEM_NAMESPACE_START
	#define RIM_GUI_SYSTEM_NAMESPACE_START		RIM_GUI_NAMESPACE_START namespace system {
#endif




#ifndef RIM_GUI_SYSTEM_NAMESPACE_END
	#define RIM_GUI_SYSTEM_NAMESPACE_END		}; RIM_GUI_NAMESPACE_END
#endif




//##########################################################################################
//************************     Start Rim GUI System Namespace     **************************
RIM_GUI_SYSTEM_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//##########################################################################################
//************************     End Rim GUI System Namespace     ****************************
RIM_GUI_SYSTEM_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GUI_SYSTEM_CONFIG_H
