/*
 *  rimThreadsConfig.h
 *  Rim Threads
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_THREADS_CONFIG_H
#define INCLUDE_RIM_THREADS_CONFIG_H


#include "../rimConfig.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




/// Define the name of the thread library namespace.
#ifndef RIM_THREADS_NAMESPACE
	#define RIM_THREADS_NAMESPACE threads
#endif




#ifndef RIM_THREADS_NAMESPACE_START
	#define RIM_THREADS_NAMESPACE_START		RIM_NAMESPACE_START namespace RIM_THREADS_NAMESPACE {
#endif




#ifndef RIM_THREADS_NAMESPACE_END
	#define RIM_THREADS_NAMESPACE_END		}; RIM_NAMESPACE_END
#endif




RIM_NAMESPACE_START
/// A namespace containing classes which provide ways to create, manage, and synchronize threads.
namespace RIM_THREADS_NAMESPACE {
};
RIM_NAMESPACE_END




//##########################################################################################
//***************************  Start Rim Threads Namespace  ********************************
RIM_THREADS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//##########################################################################################
//***************************  End Rim Threads Namespace  **********************************
RIM_THREADS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################



#endif // INCLUDE_RIM_THREADS_CONFIG_H
