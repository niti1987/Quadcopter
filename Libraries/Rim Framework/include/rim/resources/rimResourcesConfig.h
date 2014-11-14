/*
 *  rimResourcesConfig.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_RESOURCES_CONFIG_H
#define INCLUDE_RIM_RESOURCES_CONFIG_H


#include "../rimConfig.h"


#include "../rimData.h"
#include "../rimFileSystem.h"
#include "../rimUtilities.h"
#include "../rimLanguage.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




/// Define the name of the resource library namespace.
#ifndef RIM_RESOURCES_NAMESPACE
	#define RIM_RESOURCES_NAMESPACE resources
#endif




#ifndef RIM_RESOURCES_NAMESPACE_START
	#define RIM_RESOURCES_NAMESPACE_START		RIM_NAMESPACE_START namespace RIM_RESOURCES_NAMESPACE {
#endif




#ifndef RIM_RESOURCES_NAMESPACE_END
	#define RIM_RESOURCES_NAMESPACE_END		}; RIM_NAMESPACE_END
#endif




RIM_NAMESPACE_START
/// A namespace containing classes that handle pooled generic resource management.
namespace RIM_RESOURCES_NAMESPACE {
};
RIM_NAMESPACE_END




//##########################################################################################
//**************************  Start Rim Resources Namespace  *******************************
RIM_RESOURCES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


//##########################################################################################
//**************************  End Rim Resources Namespace  *********************************
RIM_RESOURCES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_RESOURCES_CONFIG_H
