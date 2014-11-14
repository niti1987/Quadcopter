/*
 *  rimEngineConfig.h
 *  Rim Engine
 *
 *  Created by Carl Schissler on 5/13/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ENGINE_CONFIG_H
#define INCLUDE_RIM_ENGINE_CONFIG_H


#include "rim/rimFramework.h"
#include "rim/rimImages.h"
#include "rim/rimGUI.h"
#include "rim/rimBVH.h"
#include "rim/rimGraphics.h"
#include "rim/rimGraphicsGUI.h"
#include "rim/rimPhysics.h"
#include "rim/rimSound.h"
#include "rim/rimEntities.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_ENGINE_NAMESPACE_START
	#define RIM_ENGINE_NAMESPACE_START		RIM_NAMESPACE_START namespace engine {
#endif




#ifndef RIM_ENGINE_NAMESPACE_END
	#define RIM_ENGINE_NAMESPACE_END		}; RIM_NAMESPACE_END
#endif




//##########################################################################################
//***************************  Start Rim Engine Namespace  *********************************
RIM_ENGINE_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




using namespace rim::gui;
using namespace rim::gui::system;
using namespace rim::graphics;
using namespace rim::graphics;
using namespace rim::physics;
using namespace rim::entities;




//##########################################################################################
//***************************  End Rim Engine Namespace  ***********************************
RIM_ENGINE_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ENGINE_CONFIG_H
