/*
 *  rimAssetsConfig.h
 *  Rim Assets
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ASSETS_CONFIG_H
#define INCLUDE_RIM_ASSETS_CONFIG_H


#include "../rimMath.h"
#include "../rimData.h"
#include "../rimUtilities.h"
#include "../rimResources.h"
#include "../rimFileSystem.h"
#include "../rimIO.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_ASSETS_NAMESPACE_START
	#define RIM_ASSETS_NAMESPACE_START		RIM_NAMESPACE_START namespace assets {
#endif




#ifndef RIM_ASSETS_NAMESPACE_END
	#define RIM_ASSETS_NAMESPACE_END		}; RIM_NAMESPACE_END
#endif



//##########################################################################################
//****************************  Start Rim Assets Namespace  ********************************
RIM_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


using rim::lang::Pointer;
using rim::data::String;
using rim::data::UTF8String;
using rim::data::UTF8StringBuffer;
using rim::util::HashMap;
using rim::util::ArrayList;
using rim::util::ShortArrayList;
using rim::resources::ResourceID;
using rim::resources::ResourceLocalID;
using rim::resources::Resource;
using rim::resources::ResourceManager;


//##########################################################################################
//****************************  End Rim Assets Namespace  **********************************
RIM_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ASSETS_CONFIG_H
