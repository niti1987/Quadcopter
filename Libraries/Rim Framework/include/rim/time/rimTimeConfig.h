/*
 *  rimTimeConfig.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_TIME_CONFIG_H
#define INCLUDE_RIM_TIME_CONFIG_H


#include "../rimConfig.h"


#include "../rimData.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




/// Define the name of the time library namespace.
#ifndef RIM_TIME_NAMESPACE
	#define RIM_TIME_NAMESPACE time
#endif




#ifndef RIM_TIME_NAMESPACE_START
	#define RIM_TIME_NAMESPACE_START		RIM_NAMESPACE_START namespace RIM_TIME_NAMESPACE {
#endif




#ifndef RIM_TIME_NAMESPACE_END
	#define RIM_TIME_NAMESPACE_END		}; RIM_NAMESPACE_END
#endif




RIM_NAMESPACE_START
/// A namespace containing classes which are related to keeping track of time.
namespace RIM_TIME_NAMESPACE {
};
RIM_NAMESPACE_END




//##########################################################################################
//*******************************   Start Time Namespace   *********************************
RIM_TIME_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//##########################################################################################
//*******************************   End Time Namespace   ***********************************
RIM_TIME_NAMESPACE_END
//******************************************************************************************
//##########################################################################################



#endif // INCLUDE_RIM_TIME_CONFIG_H
