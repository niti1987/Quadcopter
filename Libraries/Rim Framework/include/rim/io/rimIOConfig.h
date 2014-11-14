/*
 *  rimIOConfig.h
 *  Rim IO
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_IO_CONFIG_H
#define INCLUDE_RIM_IO_CONFIG_H


#include "../rimConfig.h"


#include "../rimFileSystem.h"
#include "../rimData.h"


#include "../exceptions/rimIOException.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




/// Define the name of the IO library namespace.
#ifndef RIM_IO_NAMESPACE
	#define RIM_IO_NAMESPACE io
#endif




#ifndef RIM_IO_NAMESPACE_START
	#define RIM_IO_NAMESPACE_START		RIM_NAMESPACE_START namespace RIM_IO_NAMESPACE {
#endif




#ifndef RIM_IO_NAMESPACE_END
	#define RIM_IO_NAMESPACE_END		}; RIM_NAMESPACE_END
#endif




RIM_NAMESPACE_START
/// A namespace containing classes which provide advanced ways to do streaming data input and output.
namespace RIM_IO_NAMESPACE {
};
RIM_NAMESPACE_END




//##########################################################################################
//******************************  Start Rim IO Namespace  **********************************
RIM_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




using rim::exceptions::IOException;




//##########################################################################################
//******************************  End Rim IO Namespace  ************************************
RIM_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_IO_CONFIG_H
