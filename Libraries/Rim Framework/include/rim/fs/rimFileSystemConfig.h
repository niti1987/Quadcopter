/*
 *  rimFileSystemConfig.h
 *  Rim IO
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_FILE_SYSTEM_CONFIG_H
#define INCLUDE_RIM_FILE_SYSTEM_CONFIG_H


#include "../rimConfig.h"


#include "../rimUtilities.h"
#include "../rimData.h"
#include "../rimExceptions.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




/// Define the name of the file system library namespace.
#ifndef RIM_FILE_SYSTEM_NAMESPACE
	#define RIM_FILE_SYSTEM_NAMESPACE fs
#endif




#ifndef RIM_FILE_SYSTEM_NAMESPACE_START
	#define RIM_FILE_SYSTEM_NAMESPACE_START		RIM_NAMESPACE_START namespace RIM_FILE_SYSTEM_NAMESPACE {
#endif




#ifndef RIM_FILE_SYSTEM_NAMESPACE_END
	#define RIM_FILE_SYSTEM_NAMESPACE_END		}; RIM_NAMESPACE_END
#endif




RIM_NAMESPACE_START
/// A namespace containing classes which provide ways to access and manipulate file systems.
namespace RIM_FILE_SYSTEM_NAMESPACE {
};
RIM_NAMESPACE_END




//##########################################################################################
//*************************  Start Rim File System Namespace  ******************************
RIM_FILE_SYSTEM_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




using rim::data::String;
using rim::data::UTF8String;
using rim::util::ArrayList;
using rim::exceptions::IOException;



//##########################################################################################
//*************************  End Rim File System Namespace  ********************************
RIM_FILE_SYSTEM_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_FILE_SYSTEM_CONFIG_H
